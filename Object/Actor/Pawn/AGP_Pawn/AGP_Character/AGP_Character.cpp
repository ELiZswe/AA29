// All the original content belonged to the US Army

#include "AGP_Character.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Controller/AIController/aAIController.h"
#include "AA29/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Controller/AIController/NPCBaseController/NPCBaseController.h"

#include "AA29/AA2_WorldSettings.h"
#include "AA29/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/InventoryAttachment/InventoryAttachment.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaBase.h"
#include "AA29/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"

#include "AA29/Inventory/Inventory.h"
#include "AA29/Inventory/Weapon/Weapon.h"

#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/Weapon_M249_SAW.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"


#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"

#include "AA29/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"

#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"

#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_545mm_30_Mag/Ammo_545mm_30_Mag.h"


#include "AA29/PlayerStart/AGP_PlayerStart/RiflemanPS/RiflemanPS.h"
#include "AA29/PlayerStart/AGP_PlayerStart/AutomaticRiflemanPS/AutomaticRiflemanPS.h"
#include "AA29/PlayerStart/AGP_PlayerStart/GuerrillaAK74suPS/GuerrillaAK74suPS.h"

#include "AA29/DecoMesh/DecoMesh.h"
#include "AA29/AA2_PlayerState.h"

#include "UObject/Class.h"
#include "UObject/ConstructorHelpers.h"

AAGP_Character::AAGP_Character()
{
	ClientSideAttachments   = {
		"AGP_Inventory.Attch_Head", 
		"AGP_Inventory.Attch_Eyes", 
		"AGP_Inventory.Attch_JungleHat", 
		"AGP_Inventory.Attch_MedicRuck"
	};
	WalkingPct					= 0.42;
	MenuName					= "AGP DEFAULT";
	bPhysicsAnimUpdate			= true;
	MovementAnims				= { "RunFwLgFr", "WlkBkLgFr", "RunLtLgFr", "RunRtLgFr" };
	TurnLeftAnim				= "'";
	TurnRightAnim				= "'";
	MovementAnimRate			= { 1,1,1,1 };
	AnimCamRelativeRotation		= FRotator(0, 90, -90);
	CustomMesh					= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_SF_RBA_Rifleman.SoldierM_SF_RBA_Rifleman"), NULL, LOAD_None, NULL);
	DrawScale					= 1.13;
	RotationRate				= FRotator(0, 357.0556640625, 0);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-5.0f, 0.0f, 25 + BaseEyeHeight));
	FirstPersonCameraComponent->SetVisibility(true);

	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	if (Mesh_1P)
	{
		Mesh_1P->SetupAttachment(FirstPersonCameraComponent);
	}
	


	//LoadMesh();

	PrimaryActorTick.bCanEverTick = true;

	SelectedEquipment.SetNum(16);
	OptionalInventory.SetNum(16);
	RequiredInventory.SetNum(16);

}

void AAGP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGP_Character::BeginPlay()
{
	Super::BeginPlay();

	
	//SetPlayerMesh();
	Client_SetPlayerMesh();

	if (GetNetMode() == ENetMode::NM_Client)
	{

	}
}


void AAGP_Character::SetStaticSkinsAndMeshes(bool bEnable)
{
	bStaticSkinsAndMeshes=bEnable;
}
void AAGP_Character::PlayFootStep()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		MakeNoise(0.1);
	}
	else
	{
		FootStepping();
	}
}
void AAGP_Character::DebugDropObjective()
{
	ServerDropObjective();
}
void AAGP_Character::ServerDropObjective()
{
	DropUtilityInventory();
}
void AAGP_Character::FootStepping()
{
	/*
		FVector FloorLocation;
		if (FloorMaterial != nullptr)
		{
			FloorLocation.Z=- CollisionHeight;
			FloorLocation += GetActorLocation();
			FloorMaterial.PlayFootContactSound(this);
			FloorMaterial.PlayFootContactProjector(this,FloorLocation,Floor);
			FloorMaterial.PlayFootContactEmitter(this,FloorLocation,Floor);
		}
	*/
}
void AAGP_Character::PlayLadderFootStep()
{
	/*
		local Sound PlaySound;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			MakeNoise(0.1);
		}
		else
		{
			if (OnLadder != None)
			{
				PlaySound=OnLadder.GetLadderClimbSound();
				PlayOwnedSound(PlaySound,3,0.9,False,150,1,True,False);
			}
		}
	*/
}
void AAGP_Character::CheckLanding()
{
	/*
		if (Physics == 2)
		{
			TweenAnim('Land',9000);
		}
	*/
}
//--------------------
// Animation functions
// -------------------

	/************************/
	/*	PLAYER ANIMATION	*/
	/************************/
// ======================================================================================
// AGP function - PlayFalling
// Event called when pawn starts falling.  Should update the animation so it can
// clear the prone/crouched posture flags and play the correct falling animation.
// last modified by:  superville 04/03/02
// ======================================================================================

void AAGP_Character::PlayFalling()
{
	ChangeAnimation();
	PlayJump();
}

//
// ======================================================================================
// AGP event - PlayJump
// 
// EXAMPLE CODE STILL IN PLACE, FIX
// output:
// last modified by:  ko 12/07/2001
// ======================================================================================
//
void AAGP_Character::PlayJump()
{
	/*
		if (FloorMaterial != None)
		{
			FloorMaterial.PlayFootContactSound(Self);
		}
		PlayJumping();
		CurrentDir=0;
	*/
}

/*
 // ======================================================================================
 // AGP function - PlayLanded
 // Handles landing effects on pawn such as playing a sound
 // input:	float impactVel - falling velocity
 // last modified by:  superville 01/29/02
 // ======================================================================================
*/
void AAGP_Character::PlayLanded(float impactVel)
{
	BaseEyeHeight = GetDefault<AAGP_Character>()->BaseEyeHeight;
	/*
		if (FloorMaterial != None)
		{
			FloorMaterial.PlayFootContactSound(Self);
		}
		if (! bPhysicsAnimUpdate)
		{
			PlayLandingAnimation(impactVel);
		}
	*/
}


//
// ======================================================================================
// AGP event - PlayLandingAnimation
// 
// EXAMPLE CODE STILL IN PLACE, FIX
// output:
// last modified by:  ko 12/07/2001
// ======================================================================================
//


void AAGP_Character::PlayLandingAnimation(float impactVel)
{
	/*
		if (Acceleration.X > 0 || Acceleration.Y > 0)
		{
			PlayLanding();
		}
		else
		{
			PlayLanding();
		}
	*/
}
void AAGP_Character::StopPlayFiring()
{
	if (bSteadyFiring)
	{
		bSteadyFiring=false;
	}
}
void AAGP_Character::PlayWaiting()
{
	/*
		if (isDead())
		{
			if (! IsInState('Dying'))
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_Character::PlayWaiting()	Got here without being in Dying"));
				GotoState('Dying');
			}
		}
		else
		{
			Switch(Physics)
			{
				case 11:
				AnimateStanding();
				break;
				case 17:
				GotoState('BusyParachuting');
				break;
				case 1:
				if (bIsCrouched)
				{
					AnimateCrouching();
				}
				else
				{
					if (bIsProne)
					{
						AnimateProneing();
					}
					else
					{
						AnimateStanding();
					}
				}
				default:
			}
		}
	*/
}

void AAGP_Character::PlayMoving()
{
	/*
		if (isDead())
		{
			AnimateDead();
			Return;
		}
		SetLoopingAnimAction('None');
		Switch(Physics)
		{
			case 17:
				AnimateParachuting();
				SetRates(1);
				break;
			case 11:
				AnimateClimbing();
				SetRates(1.8);
				break;
			case 1:
			case 2:
			if (GetNetMode() == ENetMode::NM_Client)
			{
				if (UpperBodyAnim == 12 || UpperBodyAnim == 9)
				{
					AnimateGrenadeMoving();
				}
				else
				{
					if (UpperBodyAnim == 21 || UpperBodyAnim == 22)
					{
						AnimateBinocularsMoving();
					}
					else
					{
						if (UpperBodyAnim == 67 || UpperBodyAnim == 68 || UpperBodyAnim == 3 && LastUpperBodyAnim == 67 || UpperBodyAnim == 3 && LastUpperBodyAnim == 68)
						{
							AnimateCLUMoving();
						}
						else
						{
							if (UpperBodyAnim == 75)
							{
								AnimateTubeMoving();
							}
							else
							{
								if (UpperBodyAnim == 25 || UpperBodyAnim == 3 && LastUpperBodyAnim == 25 || UpperBodyAnim == 29 || UpperBodyAnim == 3 && LastUpperBodyAnim == 29)
								{
									AnimateRPGMoving();
								}
								else
								{
									if (UpperBodyAnim == 33 || UpperBodyAnim == 3 && LastUpperBodyAnim == 33)
									{
										AnimateAT4Moving();
									}
									else
									{
										if (UpperBodyAnim == 39 || UpperBodyAnim == 3 && LastUpperBodyAnim == 39)
										{
											AnimatePistolMoving();
										}
										else
										{
											if (bIsSprinting)
											{
												AnimateSprinting();
											}
											else
											{
												if (bIsCrouched)
												{
													AnimateCrouchWalking();
												}
												else
												{
													if (bIsProne)
													{
														AnimateProneWalking();
													}
													else
													{
														if (bIsWalking)
														{
															AnimateWalking();
														}
														else
														{
															AnimateRunning();
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else
			{
				if (UpperBodyAnim == 12 || UpperBodyAnim == 9)
				{
					AnimateGrenadeMoving();
				}
				else
				{
					if (UpperBodyAnim == 21 || UpperBodyAnim == 22)
					{
						AnimateBinocularsMoving();
					}
					else
					{
						if (UpperBodyAnim == 67 || UpperBodyAnim == 68)
						{
							AnimateCLUMoving();
						}
						else
						{
							if (UpperBodyAnim == 75)
							{
								AnimateTubeMoving();
							}
							else
							{
								if (UpperBodyAnim == 25 || UpperBodyAnim == 29)
								{
									AnimateRPGMoving();
								}
								else
								{
									if (UpperBodyAnim == 33)
									{
										AnimateAT4Moving();
									}
									else
									{
										if (UpperBodyAnim == 39)
										{
											AnimatePistolMoving();
										}
										else
										{
											if (bIsSprinting)
											{
												AnimateSprinting();
											}
											else
											{
												if (bIsCrouched)
												{
													AnimateCrouchWalking();
												}
												else
												{
													if (bIsProne)
													{
														AnimateProneWalking();
													}
													else
													{
														if (bIsWalking)
														{
															AnimateWalking();
														}
														else
														{
															AnimateRunning();
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			SetAnimRates();
			GOTO JL03EC;
			default:
			GOTO JL03EC;
	JL03EC:
		}
	*/
}
void AAGP_Character::SetRates(float Rate)
{
	MovementAnimRate[0]=Rate;
	MovementAnimRate[1]=Rate;
	MovementAnimRate[2]=Rate;
	MovementAnimRate[3]=Rate;
}
void AAGP_Character::SetRates4(float R0, float r1, float r2, float R3)
{
	MovementAnimRate[0]=R0;
	MovementAnimRate[1]=r1;
	MovementAnimRate[2]=r2;
	MovementAnimRate[3]=R3;
}
void AAGP_Character::SetAnimRates()
{
	/*
		local bool bZoomed;
		if (UpperBodyAnim == 22 || IsZoomed() && bIsWalking)
		{
			bZoomed=True;
		}
		if (UpperBodyAnim == 68 || IsZoomed() && bIsWalking)
		{
			bZoomed=True;
		}
		if (bIsSprinting)
		{
			if (Controller != None && Controller.IsA('NPCBaseController') && NPCBaseController(Controller).fpRunAnimRate != 0)
			{
				SetRates(NPCBaseController(Controller).fpRunAnimRate);
			}
			else
			{
				SetRates(1);
			}
		}
		else
		{
			if (bIsProne)
			{
				if (bZoomed)
				{
					SetRates(0.4);
				}
				else
				{
					if (bIsWalking)
					{
						SetRates(0.8);
					}
					else
					{
						SetRates(1);
					}
				}
			}
			else
			{
				if (bIsCrouched)
				{
					if (bZoomed)
					{
						SetRates(0.22);
					}
					else
					{
						if (bIsWalking)
						{
							SetRates(0.8);
						}
						else
						{
							SetRates(1);
						}
					}
				}
				else
				{
					if (bZoomed)
					{
						SetRates(0.6);
					}
					else
					{
						if (bIsWalking)
						{
							SetRates(1);
						}
						else
						{
							SetRates4(0.9,0.9,0.75,0.9);
						}
					}
				}
			}
		}
	*/
}
void AAGP_Character::AnimateDead()
{
	TurnLeftAnim="None";
	TurnRightAnim="None";
	MovementAnims[0]="None";
	MovementAnims[1]="None";
	MovementAnims[2]="None";
	MovementAnims[3]="None";
}
void AAGP_Character::AnimatePistolMoving()
{
	if (bIsSprinting)
	{
		TurnLeftAnim="StdRotLtSm";
		TurnRightAnim="StdRotRtSm";
		MovementAnims[0]="RunFwSm";
		MovementAnims[1]="WlkFstBkSm";
		MovementAnims[2]="RunLtSm";
		MovementAnims[3]="RunRtSm";
	}
	else
	{
		if (bIsProne)
		{
			TurnLeftAnim="PrnRotLtSm";
			TurnRightAnim="PrnRotRtSm";
			if (bIsWalking)
			{
				MovementAnims[0]="LocrFwSm";
				MovementAnims[1]="LocrBkSm";
				MovementAnims[2]="LocrLtSm";
				MovementAnims[3]="LocrRtSm";
			}
			else
			{
				MovementAnims[0]="HicrFwSm";
				MovementAnims[1]="HicrBkSm";
				MovementAnims[2]="HicrLtSm";
				MovementAnims[3]="HicrRtSm";
			}
		}
		else
		{
			if (bIsCrouched)
			{
				TurnLeftAnim="CrhRotLtSm";
				TurnRightAnim="CrhRotRtSm";
				MovementAnims[0]="CrhFwSm";
				MovementAnims[1]="CrhBkSm";
				MovementAnims[2]="CrhLtSm";
				MovementAnims[3]="CrhRtSm";
			}
			else
			{
				if (bIsWalking)
				{
					TurnLeftAnim="StdRotLtSm";
					TurnRightAnim="StdRotRtSm";
					MovementAnims[0]="WlkFwSm";
					MovementAnims[1]="WlkBkSm";
					MovementAnims[2]="WlkLtSm";
					MovementAnims[3]="WlkRtSm";
				}
				else
				{
					TurnLeftAnim="StdRotLtSm";
					TurnRightAnim="StdRotRtSm";
					MovementAnims[0]="WlkFstFwSm";
					MovementAnims[1]="WlkBkSm";
					MovementAnims[2]="WlkFstLtSm";
					MovementAnims[3]="WlkFstRtSm";
				}
			}
		}
	}
}
void AAGP_Character::AnimateRPGMoving()
{
	if (bIsSprinting)
	{
		if (Controller != NULL && ! Controller->IsA(AaAIController::StaticClass()))
		{
			UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateRPGMoving()	Should not be able to sprint with RPG!"));
		}
		TurnLeftAnim="StdRotLtGnRdy";
		TurnRightAnim="StdRotRtGnRdy";
		MovementAnims[0]="RunFwRPG";
		MovementAnims[1]="WlkBkRPG";
		MovementAnims[2]="RunLtRPG";
		MovementAnims[3]="RunRtRPG";
	}
	else
	{
		if (bIsProne)
		{
			TurnLeftAnim="PrnRotLtRPG";
			TurnRightAnim="PrnRotRtRPG";
			MovementAnims[0]="PrnFwRPG";
			MovementAnims[1]="PrnBkRPG";
			MovementAnims[2]="PrnLtRPG";
			MovementAnims[3]="PrnRtRPG";
		}
		else
		{
			if (bIsCrouched)
			{
				TurnLeftAnim="CrhRotLtRPG";
				TurnRightAnim="CrhRotRtRPG";
				MovementAnims[0]="CrhFwRPG";
				MovementAnims[1]="CrhBkRPG";
				MovementAnims[2]="CrhLtRPG";
				MovementAnims[3]="CrhRtRPG";
			}
			else
			{
				if (bIsWalking)
				{
					TurnLeftAnim="StdRotLtRPG";
					TurnRightAnim="StdRotRtRPG";
					MovementAnims[0]="WlkFwRPG";
					MovementAnims[1]="WlkBkRPG";
					MovementAnims[2]="WlkLtRPG";
					MovementAnims[3]="WlkRtRPG";
				}
				else
				{
					TurnLeftAnim="StdRotLtRPG";
					TurnRightAnim="StdRotRtRPG";
					MovementAnims[0]="RunFwRPG";
					MovementAnims[1]="WlkBkRPG";
					MovementAnims[2]="RunLtRPG";
					MovementAnims[3]="RunRtRPG";
				}
			}
		}
	}

}
void AAGP_Character::AnimateAT4Moving()
{
	
	if (bIsSprinting)
	{
		UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateAT4Moving()	Should not be able to sprint with AT4!"));
		TurnLeftAnim="StdRotLtAT4";
		TurnRightAnim="StdRotRtAT4";
		MovementAnims[0]="RunFwAT4";
		MovementAnims[1]="WlkBkAT4";
		MovementAnims[2]="RunLtAT4";
		MovementAnims[3]="RunRtAT4";
	}
	else
	{
		if (bIsProne)
		{
			TurnLeftAnim="PrnRotLtAT4";
			TurnRightAnim="PrnRotRtAT4";
			MovementAnims[0]="PrnFwAT4";
			MovementAnims[1]="PrnBkAT4";
			MovementAnims[2]="PrnLtAT4";
			MovementAnims[3]="PrnRtAT4";
		}
		else
		{
			if (bIsCrouched)
			{
				TurnLeftAnim="CrhRotLtAT4";
				TurnRightAnim="CrhRotRtAT4";
				MovementAnims[0]="CrhFwAT4";
				MovementAnims[1]="CrhBkAT4";
				MovementAnims[2]="CrhLtAT4";
				MovementAnims[3]="CrhRtAT4";
			}
			else
			{
				if (bIsWalking)
				{
					TurnLeftAnim="StdRotLtAT4";
					TurnRightAnim="StdRotRtAT4";
					MovementAnims[0]="WlkFwAT4";
					MovementAnims[1]="WlkBkAT4";
					MovementAnims[2]="WlkLtAT4";
					MovementAnims[3]="WlkRtAT4";
				}
				else
				{
					TurnLeftAnim="StdRotLtAT4";
					TurnRightAnim="StdRotRtAT4";
					MovementAnims[0]="RunFwAT4";
					MovementAnims[1]="WlkBkAT4";
					MovementAnims[2]="RunLtAT4";
					MovementAnims[3]="RunRtAT4";
				}
			}
		}
	}
}
void AAGP_Character::AnimateTubeMoving()
{
	if (bIsSprinting)
	{
		TurnLeftAnim="stdrotlttube";
		TurnRightAnim="stdrotrttube";
		MovementAnims[0]="sprintfwtube";
		MovementAnims[1]="wlkbktube";
		MovementAnims[2]="sprintlttube";
		MovementAnims[3]="sprintrttube";
	}
	else
	{
		if (bIsProne)
		{
			TurnLeftAnim="prnrotlttube";
			TurnRightAnim="prnrotrttube";
			MovementAnims[0]="prnfwtube";
			MovementAnims[1]="prnbktube";
			MovementAnims[2]="prnlttube";
			MovementAnims[3]="prnrttube";
		}
		else
		{
			if (bIsCrouched)
			{
				TurnLeftAnim="crhrotlttube";
				TurnRightAnim="crhrotrttube";
				MovementAnims[0]="crhfwtube";
				MovementAnims[1]="crhbktube";
				MovementAnims[2]="crhlttube";
				MovementAnims[3]="crhrttube";
			}
			else
			{
				if (bIsWalking)
				{
					TurnLeftAnim="stdrotlttube";
					TurnRightAnim="stdrotrttube";
					MovementAnims[0]="wlkfwtube";
					MovementAnims[1]="wlkbktube";
					MovementAnims[2]="wlklttube";
					MovementAnims[3]="wlkrtTube";
				}
				else
				{
					TurnLeftAnim="stdrotlttube";
					TurnRightAnim="stdrotrttube";
					MovementAnims[0]="runfwtube";
					MovementAnims[1]="wlkbktube";
					MovementAnims[2]="runlttube";
					MovementAnims[3]="runrttube";
				}
			}
		}
	}
}
void AAGP_Character::AnimateGrenadeMoving()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_GREN_Ready)
	{
		if (bIsSprinting)
		{
			TurnLeftAnim="StdRotLtGnRdy";
			TurnRightAnim="StdRotRtGnRdy";
			MovementAnims[0]="SprintFwNo";
			MovementAnims[1]="RunBkGnRdy";
			MovementAnims[2]="SprintLtNo";
			MovementAnims[3]="SprintRtNo";
		}
		else
		{
			if (bIsProne)
			{
				TurnLeftAnim="PrnRotLtGnRdy";
				TurnRightAnim="PrnRotRtGnRdy";
				MovementAnims[0]="HicrFwNo";
				MovementAnims[1]="HicrBkNo";
				MovementAnims[2]="HicrLtNo";
				MovementAnims[3]="HicrRtNo";
			}
			else
			{
				if (bIsCrouched)
				{
					TurnLeftAnim="CrhRotLtGnRdy";
					TurnRightAnim="CrhRotRtGnRdy";
					MovementAnims[0]="CrhFwGnRdy";
					MovementAnims[1]="CrhBkGnRdy";
					MovementAnims[2]="CrhLtGnRdy";
					MovementAnims[3]="CrhRtGnRdy";
				}
				else
				{
					if (bIsWalking)
					{
						TurnLeftAnim="StdRotLtGnRdy";
						TurnRightAnim="StdRotRtGnRdy";
						MovementAnims[0]="WlkFwGnRdy";
						MovementAnims[1]="WlkBkGnRdy";
						MovementAnims[2]="WlkLtGnRdy";
						MovementAnims[3]="WlkRtGnRdy";
					}
					else
					{
						TurnLeftAnim="StdRotLtGnRdy";
						TurnRightAnim="StdRotRtGnRdy";
						MovementAnims[0]="RunFwGnRdy";
						MovementAnims[1]="RunBkGnRdy";
						MovementAnims[2]="RunLtGnRdy";
						MovementAnims[3]="RunRtGnRdy";
					}
				}
			}
		}
	}
	else
	{
		if (UpperBodyAnim == EUpperBodyAnim::UBANIM_GREN_PullingPin)
		{
			if (bIsSprinting)
			{
				if (Controller != NULL && !Controller->IsA(AaAIController::StaticClass()))
				{
					UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateGrenadeMoving()	Should never be sprinting and pulling pin!"));
				}
				TurnLeftAnim="StdRotLtGnRdy";
				TurnRightAnim="StdRotRtGnRdy";
				MovementAnims[0]="SprintFwNo";
				MovementAnims[1]="RunBkGnFr";
				MovementAnims[2]="SprintLtNo";
				MovementAnims[3]="SprintRtNo";
			}
			else
			{
				if (bIsProne)
				{
					TurnLeftAnim="PrnRotLtGnRdy";
					TurnRightAnim="PrnRotRtGnRdy";
					MovementAnims[0]="HicrFwNo";
					MovementAnims[1]="HicrBkNo";
					MovementAnims[2]="HicrLtNo";
					MovementAnims[3]="HicrRtNo";
				}
				else
				{
					if (bIsCrouched)
					{
						TurnLeftAnim="CrhRotLtGnFr";
						TurnRightAnim="CrhRotRtGnFr";
						MovementAnims[0]="CrhFwGnFr";
						MovementAnims[1]="CrhBkGnFr";
						MovementAnims[2]="CrhLtGnFr";
						MovementAnims[3]="CrhRtGnFr";
					}
					else
					{
						if (bIsWalking)
						{
							TurnLeftAnim="StdRotLtGnFr";
							TurnRightAnim="StdRotRtGnFr";
							MovementAnims[0]="WlkFwGnFr";
							MovementAnims[1]="WlkBkGnFr";
							MovementAnims[2]="WlkLtGnFr";
							MovementAnims[3]="WlkRtGnFr";
						}
						else
						{
							TurnLeftAnim="StdRotLtGnFr";
							TurnRightAnim="StdRotRtGnFr";
							MovementAnims[0]="RunFwGnFr";
							MovementAnims[1]="RunBkGnFr";
							MovementAnims[2]="RunLtGnFr";
							MovementAnims[3]="RunRtGnFr";
						}
					}
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateGrenadeMoving()	Reached here with unknown UpperBodyAnim %s"), UpperBodyAnim);
		}
	}
	
}
void AAGP_Character::AnimateBinocularsMoving()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_BINOC_Ready)
	{
		if (bIsSprinting)
		{
			TurnLeftAnim="StdBinocsDn";
			TurnRightAnim="StdBinocsDn";
			MovementAnims[0]="SprintFwNo";
			MovementAnims[1]="RunBkBinocsDn";
			MovementAnims[2]="SprintLtNo";
			MovementAnims[3]="SprintRtNo";
		}
		else
		{
			if (bIsProne)
			{
				TurnLeftAnim="PrnRotLtBinocsDn";
				TurnRightAnim="PrnRotRtBinocsDn";
				MovementAnims[0]="HicrFwBinocsDn";
				MovementAnims[1]="HicrBkBinocsDn";
				MovementAnims[2]="HicrLtBinocsDn";
				MovementAnims[3]="HicrRtBinocsDn";
			}
			else
			{
				if (bIsCrouched)
				{
					TurnLeftAnim="CrhRotLtBinocsDn";
					TurnRightAnim="CrhRotRtBinocsDn";
					MovementAnims[0]="CrhFwBinocsDn";
					MovementAnims[1]="CrhBkBinocsDn";
					MovementAnims[2]="CrhLtBinocsDn";
					MovementAnims[3]="CrhRtBinocsDn";
				}
				else
				{
					if (bIsWalking)
					{
						TurnLeftAnim="StdRotLtBinocsDn";
						TurnRightAnim="StdRotRtBinocsDn";
						MovementAnims[0]="WlkFwBinocsDn";
						MovementAnims[1]="WlkBkBinocsDn";
						MovementAnims[2]="WlkLtBinocsDn";
						MovementAnims[3]="WlkRtBinocsDn";
					}
					else
					{
						TurnLeftAnim="StdRotLtBinocsDn";
						TurnRightAnim="StdRotRtBinocsDn";
						MovementAnims[0]="RunFwBinocsDn";
						MovementAnims[1]="RunBkBinocsDn";
						MovementAnims[2]="RunLtBinocsDn";
						MovementAnims[3]="RunRtBinocsDn";
					}
				}
			}
		}
	}
	else
	{
		if (UpperBodyAnim == EUpperBodyAnim::UBANIM_BINOC_Ready)
		{
			if (bIsProne)
			{
				TurnLeftAnim="PrnRotLtBinocsUp";
				TurnRightAnim="PrnRotRtBinocsUp";
				MovementAnims[0]="HicrFwBinocsUp";
				MovementAnims[1]="HicrBkBinocsUp";
				MovementAnims[2]="HicrLtBinocsUp";
				MovementAnims[3]="HicrRtBinocsUp";
			}
			else
			{
				if (bIsCrouched)
				{
					TurnLeftAnim="CrhRotLtBinocsUp";
					TurnRightAnim="CrhRotRtBinocsUp";
					MovementAnims[0]="CrhFwBinocsUp";
					MovementAnims[1]="CrhBkBinocsUp";
					MovementAnims[2]="CrhLtBinocsUp";
					MovementAnims[3]="CrhRtBinocsUp";
				}
				else
				{
					TurnLeftAnim="StdRotLtBinocsUp";
					TurnRightAnim="StdRotRtBinocsUp";
					MovementAnims[0]="WlkFwBinocsUp";
					MovementAnims[1]="WlkBkBinocsUp";
					MovementAnims[2]="WlkLtBinocsUp";
					MovementAnims[3]="WlkRtBinocsUp";
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateBinocularsMoving()	Reached here with unknown UpperBodyAnim %s"), UpperBodyAnim);
		}
	}
	
}
void AAGP_Character::AnimateCLUMoving()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_Jav_Ready || UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload)
	{
		if (bIsSprinting)
		{
			TurnLeftAnim="stdrotltcludwn";
			TurnRightAnim="stdrotrtcludwn";
			MovementAnims[0]="sprintfwcludwn";
			MovementAnims[1]="wlkbkcludwn";
			MovementAnims[2]="sprintltcludwn";
			MovementAnims[3]="sprintrtcludwn";
		}
		else
		{
			if (bIsProne)
			{
				TurnLeftAnim="prnrotltcludwn";
				TurnRightAnim="prnrotrtcludwn";
				MovementAnims[0]="prnfwcludwn";
				MovementAnims[1]="prnbkcludwn";
				MovementAnims[2]="prnltcludwn";
				MovementAnims[3]="prnrtcludwn";
			}
			else
			{
				if (bIsCrouched)
				{
					TurnLeftAnim="crhrotltcludwn";
					TurnRightAnim="crhrotrtcludwn";
					MovementAnims[0]="crhfwcludwn";
					MovementAnims[1]="crhbkcludwn";
					MovementAnims[2]="crhltcludwn";
					MovementAnims[3]="crhrtcludwn";
				}
				else
				{
					if (bIsWalking)
					{
						TurnLeftAnim="stdrotltcludwn";
						TurnRightAnim="stdrotrtcludwn";
						MovementAnims[0]="wlkfwcludwn";
						MovementAnims[1]="wlkbkcludwn";
						MovementAnims[2]="wlkltcludwn";
						MovementAnims[3]="wlkrtcludwn";
					}
					else
					{
						TurnLeftAnim="stdrotltcludwn";
						TurnRightAnim="stdrotrtcludwn";
						MovementAnims[0]="runfwcludwn";
						MovementAnims[1]="wlkbkcludwn";
						MovementAnims[2]="runltcludwn";
						MovementAnims[3]="runrtcludwn";
					}
				}
			}
		}
	}
	else
	{
		if (UpperBodyAnim == EUpperBodyAnim::UBANIM_Jav_ReadyZoom)
		{
			if (bIsProne)
			{
				TurnLeftAnim="prnrotltcludwn";
				TurnRightAnim="prnrotrtcludwn";
				MovementAnims[0]="prnfwcludwn";
				MovementAnims[1]="prnbkcludwn";
				MovementAnims[2]="prnltcludwn";
				MovementAnims[3]="prnrtcludwn";
			}
			else
			{
				if (bIsCrouched)
				{
					TurnLeftAnim="CrhRotLtCluUp";
					TurnRightAnim="CrhRotRtCluUp";
					MovementAnims[0]="CrhFwCluUp";
					MovementAnims[1]="CrhBkCluUp";
					MovementAnims[2]="CrhLtCluUp";
					MovementAnims[3]="CrhRtCluUp";
				}
				else
				{
					TurnLeftAnim="StdRotLtCluUp";
					TurnRightAnim="StdRotRtCluUp";
					MovementAnims[0]="WlkFwCluUp";
					MovementAnims[1]="WlkBkCluUp";
					MovementAnims[2]="WlkLtCluUp";
					MovementAnims[3]="WlkRtCluUp";
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("AGP_Character::AnimateCLUMoving()	Reached here with unknown UpperBodyAnim %s"),UpperBodyAnim);
		}
	}
}
void AAGP_Character::AnimateRunning()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large || UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload)
	{
		TurnLeftAnim="StdRotLtLgFr";
		TurnRightAnim="StdRotRtLgFr";
		MovementAnims[0]="RunFwLgFr";
		MovementAnims[1]="WlkBkLgFr";
		MovementAnims[2]="RunLtLgFr";
		MovementAnims[3]="RunRtLgFr";
	}
	else
	{
		TurnLeftAnim="StdRotLtNo";
		TurnRightAnim="StdRotRtNo";
		MovementAnims[0]="RunFwNo";
		MovementAnims[1]="RunBkNo";
		MovementAnims[2]="RunLtNo";
		MovementAnims[3]="RunRtNo";
	}
}
void AAGP_Character::AnimateSprinting()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large)
	{
		TurnLeftAnim="StdLgFr";
		TurnRightAnim="StdLgFr";
		MovementAnims[0]="SprintFwLgRlx";
		MovementAnims[1]="WlkBkLgFr";
		MovementAnims[2]="SprintLtLgRlx";
		MovementAnims[3]="SprintRtLgRlx";
	}
	else
	{
		TurnLeftAnim="StdLgFr";
		TurnRightAnim="StdLgFr";
		MovementAnims[0]="SprintFwNo";
		MovementAnims[1]="WlkBkLgFr";
		MovementAnims[2]="SprintLtNo";
		MovementAnims[3]="SprintRtNo";
	}
}
void AAGP_Character::AnimateParachuting()
{
	TurnLeftAnim="ParachuteIdle";
	TurnRightAnim="ParachuteIdle";
	MovementAnims[0]="ParachuteIdle";
	MovementAnims[1]="ParachuteIdle";
	MovementAnims[2]="ParachuteIdle";
	MovementAnims[3]="ParachuteIdle";
}
void AAGP_Character::AnimateCrouchWalking()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large || UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload)
	{
		TurnLeftAnim="CrhRotLtLgFr";
		TurnRightAnim="CrhRotRtLgFr";
		MovementAnims[0]="CrhFwLgFr";
		MovementAnims[1]="CrhBkLgFr";
		MovementAnims[2]="CrhLtLgFr";
		MovementAnims[3]="CrhRtLgFr";
	}
	else
	{
		TurnLeftAnim="CrhRotLtNo";
		TurnRightAnim="CrhRotRtNo";
		MovementAnims[0]="CrhFwNo";
		MovementAnims[1]="CrhBkNo";
		MovementAnims[2]="CrhLtNo";
		MovementAnims[3]="CrhRtNo";
	}
}
void AAGP_Character::AnimateProneWalking()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large || UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload)
	{
		TurnLeftAnim="PrnRotLtLgFr";
		TurnRightAnim="PrnRotRtLgFr";
		if (bIsWalking)
		{
			MovementAnims[0]="LocrFwLg";
			MovementAnims[1]="LocrBkLg";
			MovementAnims[2]="HicrLtLg";
			MovementAnims[3]="'HicrRtLg";
		}
		else
		{
			MovementAnims[0]="HicrFwLg";
			MovementAnims[1]="HicrBkLg";
			MovementAnims[2]="HicrLtLg";
			MovementAnims[3]="HicrRtLg";
		}
	}
	else
	{
		TurnLeftAnim="PrnRotLtGnRdy";
		TurnRightAnim = "PrnRotRtGnRdy";
		MovementAnims[0]="HicrFwNo";
		MovementAnims[1]="HicrBkNo";
		MovementAnims[2]="HicrLtNo";
		MovementAnims[3]="HicrRtNo";
	}
}
void AAGP_Character::AnimateWalking()
{
	if (UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large || UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload)
	{
		TurnLeftAnim="StdRotLtLgFr";
		TurnRightAnim="StdRotRtLgFr";
		MovementAnims[0]="WlkFwLgFr";
		MovementAnims[1]="WlkBkLgFr";
		MovementAnims[2]="WlkLtLgFr";
		MovementAnims[3]="WlkRtLgFr";
	}
	else
	{
		TurnLeftAnim="StdRotLtNo";
		TurnRightAnim="StdRotRtNo";
		MovementAnims[0]="WlkFwNo";
		MovementAnims[1]="WlkBkNo";
		MovementAnims[2]="WlkLtNo";
		MovementAnims[3]="WlkRtNo";
	}
}
void AAGP_Character::AnimateClimbing()
{
	TurnLeftAnim="LadderUp";
	TurnRightAnim="LadderUp";
	MovementAnims[0]="LadderUp";
	MovementAnims[1]="LadderDn";
	MovementAnims[2]="LadderUp";
	MovementAnims[3]="LadderUp";
}
void AAGP_Character::AnimateStoppedOnLadder()
{
	/*
		local name NewAnim;
		if (OnLadder == None || OnLadder.ClimbingAnimation == 'None')
		{
			NewAnim='Ladder_Climb';
		}
		else
		{
			NewAnim=OnLadder.ClimbingAnimation;
		}
		TweenAnim(NewAnim,1);
	*/
}
void AAGP_Character::AnimateStanding()
{
	/*
		if (Mesh == nullptr)
		{
			return;
		}
		if (! IsInState('BusyStanding'))
		{
			GotoState('BusyStanding');
		}
	*/
}
void AAGP_Character::AnimateCrouching()
{
	/*
		if (Mesh == nullptr)
		{
			return;
		}
		if (! IsInState('BusyCrouching'))
		{
			GotoState('BusyCrouching');
		}
	*/
}
void AAGP_Character::AnimateProneing()
{
	/*
		if (Mesh == nullptr)
		{
			Return;
		}
		if (! IsInState('BusyProning') && ! IsInState('BusyDiving'))
		{
			GotoState('BusyProning');
		}
	*/
}
void AAGP_Character::PlayProningSound()
{
	/*
		local FVector HitLocation;
		local FVector HitNormal;
		local Material HitMaterial;
		local Actor HitActor;
		local float Volume;
		HitActor=Trace(HitLocation,HitNormal,Location + vect(0 0 -100),Location,False,vect(0 0 0),HitMaterial);
		if (HitMaterial != None)
		{
			HitMaterial.PlayProneContactSound(Self);
		}
		else
		{
			if (bIsWalking)
			{
				Volume=0.6;
			}
			else
			{
				Volume=1;
			}
			if (bIsCrouched)
			{
				Volume -= 0.3;
			}
			PlayOwnedSound(sStandToProne,3,Volume,False,1000,1,True);
		}
	*/
}

void AAGP_Character::PossessedBy(AController* C)
{
	AAGP_PlayerStart* PS;
	TArray<TSubclassOf<AInventory>> this_inventory;

	Super::PossessedBy(C);
	PS = Cast<AAGP_PlayerStart>(Cast<AHumanController>(C)->StartSpot);
	
	if (PS != NULL)
	{
		if (PS->bGiveParachute)
		{
			bParachuteOutfit = true;
		}
	}
	if (bInventorySet)
	{
		return;
	}

	AAA2_PlayerState* PState = Cast<AAA2_PlayerState>(GetPlayerState());
	if (PState)
	{
		if (PS->IsA(AAutomaticRiflemanPS::StaticClass()))
		{
			this_inventory =
			{
				AWeapon_M249_SAW::StaticClass(),
				AAmmo_556mm_200_Belt::StaticClass(),
				AAmmo_556mm_200_Belt::StaticClass(),
				AAmmo_556mm_200_Belt::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass()
			};
			PState->Set_My_Pawn_Inventory(this_inventory);
			PState->CurrentWeapon = AWeapon_M249_SAW::StaticClass();

			Weapon = NewObject<AWeapon_M249_SAW>(AWeapon_M249_SAW::StaticClass());
			CustomMesh_1P = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P.M249_1P"), NULL, LOAD_None, NULL);
			//Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Select.Select'"), NULL, LOAD_None, NULL);
			Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Still.Still'"), NULL, LOAD_None, NULL);
			
			TSubclassOf <class ASoldierClass>  SC = Cast<AAGP_PlayerStart>(PS)->SpawnClass;
			Client_Set_Weapon(SC);
		}
		if (PS->IsA(ARiflemanPS::StaticClass()))
		{
			this_inventory =
			{
				AWeapon_M16A2_Rifle::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AAmmo_556mm_30_Mag::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M83_Smoke::StaticClass(),
				AThrow_M84_Stun::StaticClass(),
				AThrow_M84_Stun::StaticClass()
			};
			PState->Set_My_Pawn_Inventory(this_inventory);
			PState->CurrentWeapon = AWeapon_M16A2_Rifle::StaticClass();

			UWorld* world = GetWorld();

			Weapon = NewObject<AWeapon_M16A2_Rifle>(AWeapon_M16A2_Rifle::StaticClass());
			CustomMesh_1P = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P.m16a2_1P"), NULL, LOAD_None, NULL);
			//Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P/Select.Select'"), NULL, LOAD_None, NULL);
			Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P/Still.Still'"), NULL, LOAD_None, NULL);

			TSubclassOf <class ASoldierClass>  SC = Cast<AAGP_PlayerStart>(PS)->SpawnClass;
			Client_Set_Weapon(SC);
		}
		if (PS->IsA(AGuerrillaAK74suPS::StaticClass()))
		{
			this_inventory =
			{
				AWeapon_AK74su_Rifle::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AAmmo_545mm_30_Mag::StaticClass(),
				AThrow_M83_Smoke::StaticClass(),
				AThrow_M84_Stun::StaticClass(),
				AThrow_M84_Stun::StaticClass(),
				AThrow_M67_Frag::StaticClass(),
				AThrow_M67_Frag::StaticClass()
			};

			PState->Set_My_Pawn_Inventory(this_inventory);
			PState->CurrentWeapon = AWeapon_AK74su_Rifle::StaticClass();

			UWorld* world = GetWorld();

			Weapon = NewObject<AWeapon_AK74su_Rifle>(AWeapon_AK74su_Rifle::StaticClass());
			CustomMesh_1P = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P.m16a2_1P"), NULL, LOAD_None, NULL);
			//Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P/Select.Select'"), NULL, LOAD_None, NULL);
			Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P/Still.Still'"), NULL, LOAD_None, NULL); 
			TSubclassOf <class ASoldierClass>  SC = Cast<AAGP_PlayerStart>(PS)->SpawnClass;
			Client_Set_Weapon(SC);
		}
	}

	AddDefaultInventory();
	LoadSkinsAndMeshes();
	//UE_LOG(LogTemp, Warning, TEXT("AGP_Character::PossessedBy()	" $ Self @ C @ GetNetMode()));
	if (C != nullptr && Controller->IsA(APlayerController::StaticClass()) && GetNetMode() == ENetMode::NM_Standalone && ! bStaticSkinsAndMeshes)
	{
		SetSkinsAndMeshes();
	}
	bInventorySet=true;
}

void AAGP_Character::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	/*
		if (PlayerReplicationInfo != None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::Died()	" $ PlayerReplicationInfo @ PlayerReplicationInfo.Team));
			DeadBodyFormerTeam=PlayerReplicationInfo.Team;
		}
		Died(Killer,DamageType,HitLocation,HitDir,Bone);
	*/
}

void AAGP_Character::PlayDying(UaDamageType* DamageType, FVector HitLoc, FVector HitDir, FBoneInfo Bone)
{
	/*
		local bool bDieFront;
		local bool bDieBack;
		local bool bDieLeft;
		local bool bDieRight;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local float XDOTDir;
		local float YDOTDir;
		if (Level.GamePlayMode == 1)
		{
			if (Role != 4 || bIsDead)
			{
				PlayDying(DamageType,HitLoc,HitDir,Bone);
				Return;
			}
			GetAxes(Rotation,X,Y,Z);
			XDOTDir=X Dot HitDir;
			YDOTDir=Y Dot HitDir;
			if (XDOTDir <= -0.7071)
			{
				bDieFront=True;
			}
			else
			{
				if (XDOTDir >= 0.7071)
				{
					bDieBack=True;
				}
				else
				{
					if (YDOTDir <= 0)
					{
						bDieRight=True;
					}
					else
					{
						bDieLeft=True;
					}
				}
			}
			if (bNetAlreadyDead || DeathAnim != 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_Character::PlayDying()	Already dead! bNetAlreadyDead(" @ bNetAlreadyDead @ ") DeathAnim(" @ DeathAnim @ ")"));
			}
			else
			{
				if (UseParachuteDeath())
				{
					SetDeathAnim(23);
				}
				else
				{
					if (UseMILESDeath(DamageType))
					{
						PlaySound(Sound'WeaponFX_MILES_Death',0,1,,,,False);
						if (bIsProne)
						{
							SetDeathAnim(1);
						}
						else
						{
							if (bIsCrouched)
							{
								SetDeathAnim(2);
							}
							else
							{
								if (Rand(2) == 0)
								{
									SetDeathAnim(3);
								}
								else
								{
									SetDeathAnim(4);
								}
							}
						}
					}
				}
			}
		}
		PlayDying(DamageType,HitLoc,HitDir,Bone);
	*/
}
bool AAGP_Character::UseParachuteDeath()
{
	//if (Weapon != NULL && Weapon->IsA(AItem_Parachute::StaticClass()) && Physics != 1)
	if (Weapon != nullptr && Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		switch(Cast<AWeapon>(Weapon)->Charge)
		{
			case 0:
			case 1:
			case 2:
			case 5:
			case 6:
			case 7:
				return true;
			case 3:
			case 4:
				return false;
			default:
				//UE_LOG(LogTemp, Warning, TEXT("AGP_Character::UseParachuteDeath() Unexpected Charge " @ Weapon @ Weapon.Charge));
				return false;
				break;
		}
		return false;
	}
	return false;
}
void AAGP_Character::UseMILESDeath(UaDamageType* DamageType)
{
	/*
		if (ClassIsChildOf(DamageType,Class'MilesDamage') || ClassIsChildOf(DamageType,Class'MILESGrenadeDamage'))
		{
			return true;
		}
		else
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES() && DamageType == None || DamageType == Class'Suicided')
			{
				return frue;
			}
			else
			{
				return false;
			}
		}
	*/
}
bool AAGP_Character::UseGuerrillaGroup(bool bFriendly)
{
	/*
		if (PlayerReplicationInfo == None || TeamClass == None)
		{
			return false;
		}
		if (Level.GetMesh(bFriendly) == 6 || Level.GetMesh(bFriendly) == 9 && TeamClass.IsA('ClassGuerrillaBase') || Level.GetMesh(bFriendly) == 6 || Level.GetMesh(bFriendly) == 9 && ! PlayerReplicationInfo.bQualifiedSF)
		{
			return true;
		}
		else
		{
			return false;
		}
	*/

	return false; //FAKE /ELiZ
}
FString AAGP_Character::GetFaceGroup(bool bFriendly)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		return "Inf";
	}
	else
	{
		if (UseGuerrillaGroup(bFriendly))
		{
			return "US_Guerrilla";
		}
		else
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly) == EMesh::MESH_SF_Arctic)
			{
				return "SF";
			}
		}
	}
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkin_Group(bFriendly);
}
FString AAGP_Character::GetSkinGroup(bool bFriendly)
{
	if (UseGuerrillaGroup(bFriendly))
	{
		return "US_Guerrilla";
	}
	else
	{
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkin_Group(bFriendly);
	}
}
FString AAGP_Character::GetSkinOption(bool bFriendly)
{
	if (UseGuerrillaGroup(bFriendly))
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly) == EMesh::MESH_SF_Arctic)
		{
			return "GuerrillaArc";
		}
		else
		{
			return "USGuerrilla";
		}
	}
	else
	{
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkin_Option(bFriendly);
	}
}
void AAGP_Character::LoadSkinsAndMeshes()
{
		FString Package;
		FString ClothingGroup;
		FString FGroup;
		FString Option;
		//int32 i;
		TArray<FString> FriendlySkins;
		TArray<FString> EnemySkins;
		FString faceskin;
		//local Material testface;

		//UE_LOG(LogTemp, Log, TEXT("AGP_Character::LoadSkinsAndMeshes()	" $ Self @ Self.Controller @ GetNetMode()));
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT("%s AGP_Character.LoadSkinsAndMeshes() - entered"), this);
		//UE_LOG(LogTemp, Log, TEXT("AGP_Character.LoadSkinsAndMeshes() - bUpdateSkinsAndMeshes: %s"), bUpdateSkinsAndMeshes);
		//UE_LOG(LogTemp, Log, TEXT(" AGP_Character.LoadSkinsAndMeshes() - bNPCDisableSkinSwapping: %s") ,bNPCDisableSkinSwapping);
		//UE_LOG(LogTemp, Log, TEXT(" AGP_Character.LoadSkinsAndMeshes() - bStaticSkinsAndMeshes: %s") ,bStaticSkinsAndMeshes);


		/*
		if (GetNetMode() != ENetMode::NM_Client && bNPCDisableSkinSwapping && !bStaticSkinsAndMeshes)
		{
			for (i=0; i<Skins.Max; i++)
			{
				//UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.LoadSkinsAndMeshes() - Skin[ " $ i $ "] => " $ Skins[i]));
				FriendlyMaterial[i]=Skins[i];
				EnemyMaterial[i]=FriendlyMaterial[i];
				//UE_LOG(LogTemp, Warning, TEXT("AGP_Character::LoadSkinsAndMeshes()	" @ FriendlySkins[i] @ FriendlyMaterial[i]));
			}
			EnemyMesh=Mesh;
			FriendlyMesh=Mesh;
			//UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.LoadSkinsAndMeshes() - Mesh: " $ Mesh));
			bUpdateSkinsAndMeshes=True;
			bUseSniperAttachments=TeamClass != nullptr && TeamClass.nativeWeapon == 4;
			return;
		}

		if (GetNetMode() != ENetMode::NM_Client && ! bStaticSkinsAndMeshes)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::LoadSkinsAndMeshes() Loading"));
			if (GetMesh(True) == GetSoldierMesh() && Level.GetMesh(True) == 0 || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES() && ! UseGuerrillaGroup(True))
			{
				Package=Level.GetSkin_Package();
				FGroup=GetFaceGroup(True);
				UE_LOG(LogTemp, Warning, TEXT("AGP_Character.LoadSkinsAndMeshes() - Using default Inf ACU mesh's textures except for face"));
				FriendlyMaterial[0]=Texture't_char_inf_acu_vestibamolle1a';
				GetSkin(faceskin,Package,FGroup,"FACE",GetTag_Face(True),GetTag_FaceOption(True));
				testface=Material(DynamicLoadObject(faceskin,Class'Material'));
				if (testface != None)
				{
					FriendlyMaterial[1]=Material(DynamicLoadObject(faceskin,Class'Material'));
				}
			}
			else
			{
				if (GetMesh(True) == GetSFMesh() && Level.GetMesh(True) == 6 && ! UseGuerrillaGroup(True))
				{
					Package=Level.GetSkin_Package();
					FGroup=GetFaceGroup(True);
					UE_LOG(LogTemp, Warning, TEXT("AGP_Character.LoadSkinsAndMeshes() - Using default SF ACU mesh's textures except for face"));
					FriendlyMaterial[0]=Texture't_char_SF_acu_vestCIRAS1a';
					GetSkin(faceskin,Package,FGroup,"FACE",GetTag_Face(True),GetTag_FaceOption(True));
					testface=Material(DynamicLoadObject(faceskin,Class'Material'));
					if (testface != None)
					{
						FriendlyMaterial[1]=Material(DynamicLoadObject(faceskin,Class'Material'));
					}
				}
				else
				{
					Package=Level.GetSkin_Package();
					Option=GetTag_PantsShirtOption(True);
					ClothingGroup=GetSkinGroup(True);
					FGroup=GetFaceGroup(True);
					GetSkin(FriendlySkins[0],Package,ClothingGroup,"PANTS",GetTag_Pants(True),Option);
					GetSkin(FriendlySkins[1],Package,ClothingGroup,"SHIRT",GetTag_Shirt(True),Option,GetTag_ShirtOption(True));
					GetSkin(FriendlySkins[2],Package,ClothingGroup,"HAND",GetTag_Hands(True),GetTag_HandsOption(True));
					if (! MaybeGetSpecialFace(True))
					{
						GetSkin(FriendlySkins[3],Package,FGroup,"FACE",GetTag_Face(True),GetTag_FaceOption(True));
					}
					if (AGP_PlayerStart(Controller.StartSpot) != None && AGP_PlayerStart(Controller.StartSpot).bUserSetSkin)
					{
						FriendlyMaterial[0]=AGP_PlayerStart(Controller.StartSpot).setPants;
						FriendlyMaterial[1]=AGP_PlayerStart(Controller.StartSpot).setShirt;
						FriendlyMaterial[2]=AGP_PlayerStart(Controller.StartSpot).setHands;
						FriendlyMaterial[3]=AGP_PlayerStart(Controller.StartSpot).setFace;
					}
					else
					{
						for (i=0; i<5; i++)
						{
							if (Len(FriendlySkins[i]) > 0)
							{
								FriendlyMaterial[i]=Material(DynamicLoadObject(FriendlySkins[i],Class'Material'));
								UE_LOG(LogTemp, Warning, TEXT("AGP_Character::LoadSkinsAndMeshes()	" @ FriendlySkins[i] @ FriendlyMaterial[i]));
							}
						}
					}
				}
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ "AGP_Character::LoadSkinsAndMeshes()	default mesh: " $ Mesh $ " vs. GetMesh result: " $ GetMesh(True)));
			if (bNPCDisableSkinSwapping)
			{
				FriendlyMesh=Mesh;
			}
			else
			{
				FriendlyMesh=GetMesh(True);
			}
			if (! bNPCDisableSkinSwapping)
			{
				Package=Level.GetSkin_Package();
				Option=GetTag_PantsShirtOption(False);
				ClothingGroup=GetSkinGroup(False);
				FGroup=GetFaceGroup(False);
				GetSkin(EnemySkins[0],Package,ClothingGroup,"PANTS",GetTag_Pants(False),Option);
				GetSkin(EnemySkins[1],Package,ClothingGroup,"SHIRT",GetTag_Shirt(False),Option,GetTag_ShirtOption(False));
				GetSkin(EnemySkins[2],Package,ClothingGroup,"HAND",GetTag_Hands(False),GetTag_HandsOption(False));
				if (! MaybeGetSpecialFace(False))
				{
					GetSkin(EnemySkins[3],Package,FGroup,"FACE",GetTag_Face(False),GetTag_FaceOption(False));
				}
				if (AGP_PlayerStart(Controller.StartSpot) != None && AGP_PlayerStart(Controller.StartSpot).bUserSetSkin)
				{
					EnemyMaterial[0]=AGP_PlayerStart(Controller.StartSpot).setPants;
					EnemyMaterial[1]=AGP_PlayerStart(Controller.StartSpot).setShirt;
					EnemyMaterial[2]=AGP_PlayerStart(Controller.StartSpot).setHands;
					EnemyMaterial[3]=AGP_PlayerStart(Controller.StartSpot).setFace;
					EnemyMesh=FriendlyMesh;
				}
				else
				{
					for (i=0; i<5; i++)
					{
						if (Len(EnemySkins[i]) > 0)
						{
							EnemyMaterial[i]=Material(DynamicLoadObject(EnemySkins[i],Class'Material'));
							UE_LOG(LogTemp, Warning, TEXT("AGP_Character::LoadSkinsAndMeshes()	" @ EnemySkins[i] @ EnemyMaterial[i]));
						}
					}
					EnemyMesh=GetMesh(False);
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_Character.LoadSkinsAndMeshes() - Setting NPC single skin for all players"));
				for (i=0; i<5; i++)
				{
					if (Len(FriendlySkins[i]) > 0)
					{
						EnemySkins[i]=FriendlySkins[i];
						EnemyMaterial[i]=FriendlyMaterial[i];
					}
				}
				EnemyMesh=FriendlyMesh;
			}
			UE_LOG(LogTemp, Warning, TEXT("LoadSkinsAndMeshes() - bUpdateSkinsAndMeshes() flag set for pawn " $ Self));
			bUpdateSkinsAndMeshes=True;
			bUseSniperAttachments=TeamClass != None && TeamClass.nativeWeapon == 4;
			if (AGP_PlayerStart(Controller.StartSpot) != None && AGP_PlayerStart(Controller.StartSpot).bGuerrilla || AGP_PlayerStart(Controller.StartSpot).bSpecialForces && PlayerReplicationInfo == None || ! PlayerReplicationInfo.bQualifiedSF)
			{
				bUseMedicAttachments=False;
			}
			else
			{
				if (PlayerReplicationInfo != None)
				{
					bUseMedicAttachments=PlayerReplicationInfo.bIsMedic;
				}
			}
		}
	*/
}

void AAGP_Character::RemoveParachuteSkins()
{
	
		FString Package;			//What texture package to use
		FString ClothingGroup;		//What group the pants/shirt come from
		FString Option;
		TArray<FString> FriendlySkins;
		//int32 i;
		return;
		/*
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Option=GetTag_PantsShirtOption(True);
			Log(Self $ "RemoveParachuteSkins() - Parachute Option: " $ Option);
			ClothingGroup=Level.GetSkin_Group(True);
			Log(Self $ "RemoveParachuteSkins() - Parachute ClothingGroup: " $ ClothingGroup);
			Package=Level.GetSkin_Package();
			Log(Self $ "RemoveParachuteSkins() - Parachute Package: " $ Package);
			GetSkin(FriendlySkins[0],Package,ClothingGroup,"PANTS",GetTag_Pants(True),Option);
			Log(Self $ "RemoveParachuteSkins() - Parachute pants: " $ FriendlySkins[0]);
			GetSkin(FriendlySkins[1],Package,ClothingGroup,"SHIRT",GetTag_Shirt(True),Option,GetTag_ShirtOption(True));
			Log(Self $ "RemoveParachuteSkins() - Parachute shirt: " $ FriendlySkins[1]);
			for (i=0; i<2; i++)
			{
				FriendlyMaterial[i]=Material(DynamicLoadObject(FriendlySkins[i],Class'Material'));
			}
		}
	*/
}
bool AAGP_Character::MaybeGetSpecialFace(bool bFriend)
{
	return false;
}
FString AAGP_Character::ThisOrThat(FString sthis, FString sthat, float ratio)
{
	
		if (ratio == 0)
		{
			ratio=0.5;
		}
		if (FMath::FRand() < ratio)
		{
			return sthis;
		}
		else
		{
			return sthat;
		}
	
}
FString AAGP_Character::ThisOrThatOrThis(FString st1, FString st2, FString st3, float ratio1, float ratio2)
{
	float fr;
	if (ratio1 == 0)
	{
		ratio1=0.33;
	}
	if (ratio2 == 0)
	{
		ratio2=ratio1 + 0.33;
	}
	fr=FMath::FRand();
	if (fr < ratio1)
	{
		return st1;
	}
	else
	{
		if (fr < ratio2)
		{
			return st2;
		}
		else
		{
			return st3;
		}
	}
}

//Everyone uses their own pants
FString AAGP_Character::GetTag_Pants(bool bFriendly)
{
	if (bParachuteOutfit)
	{
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkin_Option_Parachute(bFriendly);
	}
	else
	{
		return GetSkinOption(bFriendly);
	}
}

//If OpFor uses Urban, make them all urban
FString AAGP_Character::GetTag_PantsShirtOption(bool bFriendly)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		return "!Urban";
	}
	switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
	{
	case ESkinSet::SKINS_OpFor:
	case ESkinSet::SKINS_OpInfantry:
		return ThisOrThat("Urban", "!Urban", 0.33);
	default:
		return "";
	}
}

//Everyone uses their own shirt
FString AAGP_Character::GetTag_Shirt(bool bFriendly)
{
	if (bParachuteOutfit)
	{
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkin_Option_Parachute(bFriendly);
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES() && !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly))
		{
			return "MilesOp";
		}
		else
		{
			return GetSkinOption(bFriendly);
		}
	}
}

// Whether or not to use MILES skins.
// Also, SoldierMesh has special shirts for different weapons
FString AAGP_Character::GetTag_ShirtOption(bool bFriendly)
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		return "Rifleman";
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly) == EMesh::MESH_Soldier)
	{
		switch (GetMainWeaponType())
		{
			case EWeaponType::WEAPON_SAW:
				return "M249";
			case EWeaponType::WEAPON_Sniper:
				return "Marksman";
			case EWeaponType::WEAPON_Gren:
			case EWeaponType::WEAPON_HMG:
			case EWeaponType::WEAPON_Rocket:
			case EWeaponType::WEAPON_Pistol:
			case EWeaponType::WEAPON_Javelin:
			case EWeaponType::WEAPON_Rifle:
				return "Rifleman";
			case EWeaponType::WEAPON_None:
			case EWeaponType::WEAPON_Unknown:
			default:
				return "";
		}
	}
	return "!MilesOp";
}

//US soldiers use skincolor hands, desop use desop hands, opfor wear gloves
FString AAGP_Character::GetTag_Hands(bool bFriendly)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly) == EMesh::MESH_Soldier)
	{
		switch(Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
		{
			case ESkinSet::SKINS_Desert:
				return "Desert_Green_Gloves";
			case ESkinSet::SKINS_Forest:
				return "Forest_Green_Gloves";
			default:
				return "";
		}
	}
	switch(Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Forest:
		case ESkinSet::SKINS_Desert:
		case ESkinSet::SKINS_CivOp:
		case ESkinSet::SKINS_DesOp:
		case ESkinSet::SKINS_IBCT:
		case ESkinSet::SKINS_Training:
		case ESkinSet::SKINS_OpInfantry:
			return GetSkinColor();
		case ESkinSet::SKINS_OpFor:
		case ESkinSet::SKINS_ArcOpFor:
			return "gloves";
		case ESkinSet::SKINS_Arctic:
			return "Arctic_Blk_Gloves";
		case ESkinSet::SKINS_SF_Arctic:
			return "gloves";
		default:
			return "INVALID";			//NOT IMPLEMENTED
	}
}

//Don't allow camo for non-forest levels
FString AAGP_Character::GetTag_HandsOption(bool bFriendly)
{
	switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Training:
		case ESkinSet::SKINS_Desert:
		case ESkinSet::SKINS_SF_Arctic:
		case ESkinSet::SKINS_Arctic:
			return "!camo";
		default:
			return "";
	}
}

//US soldiers get skincolor face. Everyone else gets specific faces
FString AAGP_Character::GetTag_Face(bool bFriendly)
{
	switch(Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
	{
	case ESkinSet::SKINS_Forest:
			return GetSkinColor();
		case ESkinSet::SKINS_Desert:
			return GetSkinColor();
		case ESkinSet::SKINS_DesOp:
			return GetSkinColor();
		case ESkinSet::SKINS_CivOp:
			return GetSkinColor();
		case ESkinSet::SKINS_Arctic:
			return GetSkinColor();
		case ESkinSet::SKINS_SF_Arctic:
			return GetSkinColor();
		case ESkinSet::SKINS_IBCT:
			return GetSkinColor();
		case ESkinSet::SKINS_Training:
			return GetSkinColor();
		case ESkinSet::SKINS_OpInfantry:
			return GetSkinColor();
		case ESkinSet::SKINS_OpFor:
			return "Hood"; 
		case ESkinSet::SKINS_ArcOpFor:
			return "ArcOp";
		default:
			return "INVALID";
	}
}

//agp [cmb] Enemies on SF always wear a mask [9/17/2003]
FString AAGP_Character::GetTag_FaceOption(bool bFriendly)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES() && Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(!bFriendly) == EMesh::MESH_SF)
	{
		return "MASK";
	}
	return "";
}

/* =================================================================================== *
 * AGP function SetSkinColor()
 *	Randomly select a skin color.
 *
 * notes:	Current ratios based (roughly) on ratio of available faces
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Character::SetSkinColor()
{
	float fr;
	AHumanController* HC;
	HC = Cast<AHumanController>(Controller);
	if (HC != NULL)
	{
		switch(HC->SkinPreference)
		{
			case ESkinPreference::SKINPREF_Latino:
				SkinColor= ESkinColor::SKINCOLOR_Latino;
				return;
			case ESkinPreference::SKINPREF_African:
				SkinColor= ESkinColor::SKINCOLOR_African;
				return;
			case ESkinPreference::SKINPREF_Caucasian:
				SkinColor= ESkinColor::SKINCOLOR_Caucasian;
				return;
			default:
				break;
		}
		fr=FMath::FRand();
		if (fr < 0.3)
		{
			SkinColor= ESkinColor::SKINCOLOR_African;
			return;
		}
		if (fr < 0.75)
		{
			SkinColor= ESkinColor::SKINCOLOR_Caucasian;
			return;
		}
		SkinColor= ESkinColor::SKINCOLOR_Latino;
	}
}

/* =================================================================================== *
 * AGP function GetSkinColor()
 *	If the skin color has not been set, set it now.
 *	Return the tag (found in texture names) for the curren skin color.
 *
 * output:	The skin color tag
 * notes:	simulated so the first person weapon can get the skin color
 * last modified by: cmb
 * =================================================================================== */
FString AAGP_Character::GetSkinColor()
{
	if (SkinColor == ESkinColor::SKINCOLOR_NotSet)
	{
		SetSkinColor();
	}
	switch(SkinColor)
	{
		case ESkinColor::SKINCOLOR_African:
			return "Afr";
		case ESkinColor::SKINCOLOR_Caucasian:
			return "Cauc";
		case ESkinColor::SKINCOLOR_Latino:
			return "Latin";
		default:
			//UE_LOG(LogTemp, Warning, TEXT("AGP_Character::GetSkinColor()	Unknown " $ SkinColor));
			return "Cauc";
	}
}

/* =================================================================================== *
 * AGP function GetMesh()
 *	Return the appropriate mesh, asking the Level which enum to use.
 *
 * notes:	Can't get the mesh directly from the level because they don't exist yet in engine
 * last modified by: cmb
 * =================================================================================== */
USkeletalMesh* AAGP_Character::GetMesh(bool bFriendly)
{
	AAGP_PlayerStart* PS;
	AController*		myController;
	//myController = Cast<AHumanController>(GetController());
	myController = GetController();

	if (myController)
	{
		PS = Cast<AAGP_PlayerStart>(myController->StartSpot);
		if (PS)
		{
			//if (AGP_PlayerStart(Controller.StartSpot) != None && AGP_PlayerStart(Controller.StartSpot).bUserSetMesh)
			if (PS != nullptr && PS->bUserSetMesh)
			{
				return PS->SetMesh;
			}
		}
	}
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly))
		{
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Miles_Rifleman.SoldierM_Infantry_Miles_Rifleman'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Miles_Rifleman.SoldierM_Infantry_Miles_Rifleman'"), NULL, LOAD_None, NULL));
		}
		else
		{
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Miles.OpforM_Miles'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Miles.OpforM_Miles'"), NULL, LOAD_None, NULL));
		}
	}

	switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly))
	{
		case EMesh::MESH_Arctic:
			return GetArcticMesh();
		case EMesh::MESH_IBCT:
		case EMesh::MESH_Soldier:
			return GetSoldierMesh();
		case EMesh::MESH_SF:
			return GetSFMesh();
		case EMesh::MESH_SF_Arctic:
			return GetSFArcticMesh();
		case EMesh::MESH_ArcOpFor:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Arctic.OpforM_Arctic'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Arctic.OpforM_Arctic'"), NULL, LOAD_None, NULL));
		case EMesh::MESH_CivOp:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Civ.OpforM_Civ'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_Civ.OpforM_Civ'"), NULL, LOAD_None, NULL));
		case EMesh::MESH_DesOp:
		case EMesh::MESH_OPFOR:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM.OpforM'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM.OpforM'"), NULL, LOAD_None, NULL));
		case EMesh::MESH_OpInfantry:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_InfantryB.OpforM_InfantryB'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_InfantryB.OpforM_InfantryB"), NULL, LOAD_None, NULL));
		default:
			break;
	}

	return nullptr;
}

//agp [cmb] Helper for GetMesh() [4/18/2003]
USkeletalMesh* AAGP_Character::GetSoldierMesh()
{
	switch(GetMainWeaponType())
	{
		case EWeaponType::WEAPON_SAW:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryAutoRiflemanACU.InfantryAutoRiflemanACU'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryAutoRiflemanACU.InfantryAutoRiflemanACU'"), NULL, LOAD_None, NULL));
		case EWeaponType::WEAPON_Sniper:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryAdvMarksmanACU.InfantryAdvMarksmanACU'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryAdvMarksmanACU.InfantryAdvMarksmanACU"), NULL, LOAD_None, NULL));
		case EWeaponType::WEAPON_Gren:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryGrenadierACU.InfantryGrenadierACU'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryGrenadierACU.InfantryGrenadierACU'"), NULL, LOAD_None, NULL));
		case EWeaponType::WEAPON_Rifle:
		case EWeaponType::WEAPON_None:
		case EWeaponType::WEAPON_Unknown:
		default:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryRiflemanACU.InfantryRiflemanACU'")));
			return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryRiflemanACU.InfantryRiflemanACU'"), NULL, LOAD_None, NULL));
	}
}

//agp [cmb] Helper for GetMesh() [4/18/2003]
USkeletalMesh* AAGP_Character::GetSFMesh()
{
	//if (TeamClass != NULL && TeamClass->IsA(AClassGuerrillaBase::StaticClass()) || PlayerReplicationInfo != None && ! PlayerReplicationInfo.bQualifiedSF)
	if (TeamClass != NULL && TeamClass->IsChildOf(AClassGuerrillaBase::StaticClass()))
	{
		bGuerrillaMesh=true;
		//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/GuerrillaM_A.GuerrillaM_A'")));
		return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/GuerrillaM_A.GuerrillaM_A'")));
	}
	else
	{
		switch(GetMainWeaponType())
		{
			case EWeaponType::WEAPON_SAW:
			case EWeaponType::WEAPON_Sniper:
			case EWeaponType::WEAPON_Gren:
			case EWeaponType::WEAPON_HMG:
			case EWeaponType::WEAPON_Rocket:
			case EWeaponType::WEAPON_Javelin:
			case EWeaponType::WEAPON_Pistol:
			case EWeaponType::WEAPON_Rifle:
			case EWeaponType::WEAPON_None:
			case EWeaponType::WEAPON_Unknown:
			default:
				//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SpecialForcesACU.SpecialForcesACU'")));
				return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SpecialForcesACU.SpecialForcesACU'"), NULL, LOAD_None, NULL));
				
		}
	}
}

//agp [cmb] Helper for GetMesh() [4/18/2003]
USkeletalMesh* AAGP_Character::GetArcticMesh()
{
	switch(GetMainWeaponType())
	{
		case EWeaponType::WEAPON_SAW:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Saw.SoldierM_Infantry_Arctic_Saw'")));
 			return LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Saw.SoldierM_Infantry_Arctic_Saw'"), NULL, LOAD_None, NULL);
		case EWeaponType::WEAPON_Sniper:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_AdvMarksman.SoldierM_Infantry_Arctic_AdvMarksman'")));
			return LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_AdvMarksman.SoldierM_Infantry_Arctic_AdvMarksman'"), NULL, LOAD_None, NULL);
		case EWeaponType::WEAPON_Gren:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Grenadier.SoldierM_Infantry_Arctic_Grenadier'")));
			return LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Grenadier.SoldierM_Infantry_Arctic_Grenadier'"), NULL, LOAD_None, NULL);
		case EWeaponType::WEAPON_Rifle:
		case EWeaponType::WEAPON_None:
		case EWeaponType::WEAPON_Unknown:
		default:
			//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman.SoldierM_Infantry_Arctic_Rifleman'")));
			return LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman.SoldierM_Infantry_Arctic_Rifleman'"), NULL, LOAD_None, NULL);
	}
}

//agp [cmb] Helper for GetMesh() [4/18/2003]
//agp [Ramm] Modified to allow for Arctic IF players [4/02/2004]
USkeletalMesh* AAGP_Character::GetSFArcticMesh()
{
	//if (TeamClass->IsA(AClassGuerrillaBase::StaticClass()) || ! PlayerReplicationInfo.bQualifiedSF)
	if (TeamClass->IsChildOf(AClassGuerrillaBase::StaticClass()))
	{
		bGuerrillaMesh=true;
		//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/GuerrillaM_A.GuerrillaM_A'")));
		return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/GuerrillaM_A.GuerrillaM_A'"), NULL, LOAD_None, NULL));
	}
	else
	{
		switch(GetMainWeaponType())
		{
			case EWeaponType::WEAPON_SAW:
			case EWeaponType::WEAPON_Sniper:
			case EWeaponType::WEAPON_Gren:
			case EWeaponType::WEAPON_HMG:
			case EWeaponType::WEAPON_Rocket:
			case EWeaponType::WEAPON_Javelin:
			case EWeaponType::WEAPON_Pistol:
			case EWeaponType::WEAPON_Rifle:
			case EWeaponType::WEAPON_None:
			case EWeaponType::WEAPON_Unknown:
			default:
				//return Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_SF_Arctic_Rifleman.SoldierM_SF_Arctic_Rifleman'")));
				return Cast<USkeletalMesh>(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_SF_Arctic_Rifleman.SoldierM_SF_Arctic_Rifleman'"), NULL, LOAD_None, NULL));
		}
	}
}

/* =================================================================================== *
 * AGP function GetMainWeaponType()
 *	Return the type of the main weapon.
 *	This is normally the weapon in the hands, except when the hands weapon is none or
 *	has a WEAPON_Unknown (paras/grenade) type, then check the shoulder.
 *
 * last modified by: cmb
 * =================================================================================== */
EWeaponType AAGP_Character::GetMainWeaponType()
{
	EWeaponType t;
	TSubclassOf<AWeapon> sw;
	if (Weapon != nullptr)
	{
		t = Cast<AWeapon>(Weapon)->weaponType;
	}
	else
	{
		t = EWeaponType::WEAPON_Unknown;
	}
	if (t == EWeaponType::WEAPON_Unknown)
	{
		//sw= Cast<AWeapon>(getShoulderInventory());
		if (sw != nullptr)
		{
			t= Cast<AWeapon>(sw)->weaponType;
		}
	}
	return t;
}

/* =================================================================================== *
 * AGP function SetSkinsAndMeshes
 *	This event is called when the Proxy Pawn's variables are changed.
 *	When called, set this pawns skins/meshes to either friendly or enemy, depending
 *	on this Pawn's relationship to the client pawn.
 *
 * effects:	Tries to figure out this pawn's relationship to the client. (bClientFriend=true/false)
 *			Then sets this pawn's skins or meshes to be either Enemy or Friendly
 * notes:	Multiplayer implementation still has some bugs.
 *			The PlayerReplicationInfos get spawned _after_ the pawn, so we have to return
 *			out and try again.
 *			This results in the "Jesus" bug if the mesh is changed.
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Character::SetSkinsAndMeshes()
{
	/*
		local Controller C;
		local PlayerReplicationInfo Client;
		local int i;
		UE_LOG(LogTemp, Warning, TEXT(""));
		UE_LOG(LogTemp, Warning, TEXT(""));
		UE_LOG(LogTemp, Warning, TEXT(""));
		UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - entered"));
		UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - bUpdateSkinsAndMeshes: " $ bUpdateSkinsAndMeshes));
		UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - bNPCDisableSkinSwapping: " $ bNPCDisableSkinSwapping));
		UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - bStaticSkinsAndMeshes: " $ bStaticSkinsAndMeshes));
		if (! bUpdateSkinsAndMeshes && Level.GetClient() != None && Level.GetClient().Owner.IsA('PlayerController')))
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - This pawn doesn't need to be updated again "));
			Return;
		}
		bFoundTheClient=False;
		if (! bStaticSkinsAndMeshes)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - Not using static skins"));
			if (bNPCDisableSkinSwapping)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character.SetSkinsAndMeshes() - bNPCDisableSkinSwapping - simulating friend state for skins"));
				bClientFriend=True;
				bFoundTheClient=True;
			}
			else
			{
				if (GetNetMode() == ENetMode::NM_Standalone)
				{
					C=Level.ControllerList;
					if (C != None)
					{
						if (C.IsA('PlayerController'))
						{
							bClientFriend=IsFriend(C.Pawn);
							bFoundTheClient=True;
						}
						else
						{
							C=C.nextController;
						}
					}
				}
				else
				{
					if (Role == 3)
					{
						Level.SetClientController(Controller);
						bFoundTheClient=True;
						bClientFriend=True;
					}
					else
					{
						Client=Level.GetClient();
						if (Client != None)
						{
							UE_LOG(LogTemp, Warning, TEXT("AGP_Character::SetSkinsAndMeshes()	" $ Client @ PlayerReplicationInfo @ DeadBodyFormerTeam));
							if (bNetAlreadyDead)
							{
								bFoundTheClient=True;
								bClientFriend=Client.IsFriend(None,DeadBodyFormerTeam);
							}
							else
							{
								if (PlayerReplicationInfo != None)
								{
									bFoundTheClient=True;
									bClientFriend=Client.IsFriend(PlayerReplicationInfo);
								}
							}
						}
					}
				}
			}
			if (! bFoundTheClient)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Character::SetSkinsAndMeshes()	Couldn't find the client. Going to try again " $ Self @ PlayerReplicationInfo));
				bUpdateSkinsAndMeshes=True;
				Return;
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Pawn::SetSkinsAndMeshes()	Me and my friend " $ Self @ bClientFriend));
			if (bClientFriend)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Pawn::SetSkinsAndMeshes()	- Friendly client - adjusting skins"));
				Skins.Length=0;

				BlackSkins.Length=0;
				for (i=0; i<5; i++)
				{
					if (FriendlyMaterial[i] != None)
					{
						UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Pawn::SetSkinsAndMeshes()	- Assigning material[" $ i $ "]" $ FriendlyMaterial[i]));
						Skins.Length=i;
						Skins[i]=FriendlyMaterial[i];
					}
				}
				UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Pawn::SetSkinsAndMeshes() - Linking friendly mesh"));
				LinkMesh(FriendlyMesh);
			}
			else
			{
				Skins.Length=0;
				AlphaSkins.Length=0;
				BlackSkins.Length=0;
				for (i=0; i<5; i++)
				{
					if (EnemyMaterial[i] != None)
					{
						Skins.Length=i;
						Skins[i]=EnemyMaterial[i];
					}
				}
				LinkMesh(EnemyMesh);
			}
			if (! bAlreadySetSkinsOnce)
			{
				NotifyFoundClient();
				CreateClientSideAttachments();
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ " AGP_Pawn::SetSkinsAndMeshes() - finished update"));
			bUpdateSkinsAndMeshes=False;
			bAlreadySetSkinsOnce=True;
		}
		SetRagDollName();
	*/
}

/* =================================================================================== *
* AGP function SetRagDollName()
*	This function sets the pawn's Ragdoll asset to the correct asset for its mesh
*	style.
*
*	TODO: Add support for guerilla, VIP, and other misc mesh types.
*
* Created by: Ramm 07/09/04
* =================================================================================== */
void AAGP_Character::SetRagDollName()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bClientFriend))
		{
			RagdollOverride = "SoldierM";
		}
		else
		{
			RagdollOverride = "OpforM";
		}
		if (GetNetMode() != ENetMode::NM_Client && Controller != NULL && Controller->IsA(ANPCBaseController::StaticClass()))
		{
			bClientFriend = true;
		}
		switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bClientFriend))
		{
			case EMesh::MESH_Arctic:
				RagdollOverride = "SoldierM";
				break;
			case EMesh::MESH_IBCT:
			case EMesh::MESH_Soldier:
				RagdollOverride = "SoldierM";
				break;
			case EMesh::MESH_SF:
				RagdollOverride = "SoldierM_SF";
				break;
			case EMesh::MESH_SF_Arctic:
				RagdollOverride = "SoldierM_SF";
				break;
			case EMesh::MESH_ArcOpFor:
				RagdollOverride = "OpforM";
				break;
			case EMesh::MESH_CivOp:
				RagdollOverride = "OpforM";
				break;
			case EMesh::MESH_DesOp:
			case EMesh::MESH_OPFOR:
				RagdollOverride = "OpforM";
				break;
			case EMesh::MESH_OpInfantry:
				RagdollOverride = "OpforM";
				break;
			default:
				break;
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("SetRagDollName() - Mesh: " $ Mesh $ " ragdoll override set: " $ RagdollOverride));
}

void AAGP_Character::Destroyed()
{
	int32 i;
	for (i=0; i< IA.Num(); i++)
	{
		if (IA[i] != NULL)
		{
			Cast<AItemAttachment>(IA[i])->Destroy();
		}
	}
	Super::Destroyed();
}

void AAGP_Character::CreateClientSideAttachments()
{
	/*
		local class<ItemAttachment>  IAClass;
		local int i;
		local Object.Rotator R;
		local int Index;
		local array<String> AttachmentName;
		R=MakeRot(0,32768,16384);
		UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateClientSideAttachments()	Trying to create!",False,True));
		if (bUseSniperAttachments)
		{
			AttachmentName[0]=ClientSideSniperAttachments;
		}
		else
		{
			for (i=0; i<ClientSideAttachments.Length; i++)
			{
				AttachmentName[i]=ClientSideAttachments[i];
			}
		}
		if (bUseMedicAttachments)
		{
			AttachmentName[AttachmentName.Length]=ClientSideMedicAttachments;
		}
		for (i=0; i<AttachmentName.Length; i++)
		{
			if (AttachmentName[i] != "" && AttachmentName[i] != "None")
			{
				IAClass=class<ItemAttachment>(DynamicLoadObject(AttachmentName[i],Class'Class'));
				if (IAClass != None)
				{
					Index=IA.Length;
					IA[Index]=Spawn(IAClass,Self);
					if (IA[Index] != None)
					{
						AttachToBone(IA[Index],IA[Index].Default.AttachBone);
						RegisterAttachment(IA[Index]);
					}
				}
			}
		}
	*/
}

/* =================================================================================== *
 * AGP function RegisterAttachment
 *	Add an atttachment to the AttachmentList, and if necessary, notify it.
 *
 * input:	att	- The attachment to be notified
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Character::RegisterAttachment(AInventoryAttachment* att)
{
	/*
		local int Empty;
		local int i;
		if (att == None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::RegisterAttachment()	Got none! (" @ att @ ")"));
			Return;
		}
		Empty=-1;
		for (i=0; i<AttachmentList.Length; i++)
		{
			if (AttachmentList[i] == None)
			{
				Empty=i;
			}
			else
			{
				if (AttachmentList[i] == att)
				{
					Return;
				}
			}
		}
		if (Empty != -1)
		{
			AttachmentList[Empty]=att;
		}
		else
		{
			AttachmentList[AttachmentList.Length]=att;
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_Character::RegisterAttachment()	" $ bFoundTheClient));
		if (bFoundTheClient)
		{
			att.NotifyFoundClient();
		}
	*/
}

void AAGP_Character::NotifyFoundClient()
{
	int32 i;
	UE_LOG(LogTemp, Log, TEXT("AGP_Character::NotifyFoundClient()	"));
	for (i=0; i<AttachmentList.Max(); i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AGP_Character::NotifyFoundClient()	Notifying " $ AttachmentList[i]));
		Cast<AInventoryAttachment>(AttachmentList[i])->NotifyFoundClient();
	}
}

void AAGP_Character::IsInLoadout(AInventory* InventoryClass)
{
/*
	int32 i;
	FString invstring;

	// FIXME - for now, pretend all non-weapons are in loadout
	if (class<Weapon>(InventoryClass) == None)
		return true;

	invstring = string(InventoryClass);

	for (i = 0; i < 16; i++)
	{
		if (RequiredInventory[i] == InventoryClass)
			return true;
		else if (RequiredInventory[i] == None)
			break;
	}

	for (i = 0; i < 16; i++)
	{
		if (OptionalInventory[i] == InventoryClass)
			return true;
		else if (OptionalInventory[i] == None)
			break;
	}

	if (TeamClass.IsInLoadout(InventoryClass))
	{
		return true;
	}

	return false;
*/

}
void AAGP_Character::AddDefaultInventory()
{
	int32 i;
	if (Controller != NULL && Controller->IsA(AaAIController::StaticClass()) && ! Controller->IsA(ADSController::StaticClass()))
	{
		return;
	}
	/*
	UWorld* const World = GetWorld();
	FVector myLocation = FVector(1900, -282, 262);
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		AActor* const SpawningObject = World->SpawnActor<AActor>(AAutomaticRiflemanPS::StaticClass(), myLocation, FRotator::ZeroRotator, SpawnParams);

	}
	*/


	if (TeamClass != NULL)
	{
		Cast<ASoldierClass>(TeamClass)->addTeamInventory();
		Cast<ASoldierClass>(TeamClass)->addClassInventory(true);
		Cast<ASoldierClass>(TeamClass)->addPSInventory();
	}
	for (i=0; i<16; i++)
	{
		CreateInventory(RequiredInventory[i],true, false);
		if (SelectedEquipment[i] == 1)
		{
			CreateInventory(OptionalInventory[i],true, false);
		}
	}
	if (TeamClass != NULL && Controller != NULL)
	{
		Cast<AHumanController>(Controller)->SwitchToBestWeapon();
	}
}
void AAGP_Character::CreateInventoryFromName(FString InventoryClassName, bool bIndigenous)
{
	/*
		local class<Inventory>  InventoryClass;
		local Inventory Item;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".CreateInventoryFromName() entered for """ $ InventoryClassName $ """"));
		if (Len(InventoryClassName) == 0 || InventoryClassName == "" || InventoryClassName == "None")
		{
			Return None;
		}
		InventoryClass=class<Inventory>(DynamicLoadObject(InventoryClassName,Class'Class'));
		UE_LOG(LogTemp, Warning, TEXT("Created class: " $ InventoryClass $ " from class name """ $ InventoryClassName $ """"));
		if (InventoryClass == None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateInventoryFromName failed to create Inventory object" @ InventoryClassName));
		}
		else
		{
			if (bIndigenous == false)
			{
				Item=CreateInventory(InventoryClass);
			}
			else
			{
				Item=CreateInventory(InventoryClass,,True);
			}
		}
		Return Item;
	*/
}

void AAGP_Character::CreateInventory(AInventory* InventoryClass, bool bRealInventory, bool bIndigenous)
{
	/*
		local bool bValid;
		local class<Inventory>  AltClass;
		local Inventory Inv;
		if (InventoryClass == None)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".CreateInventory - Invalid class: " $ InventoryClass));
			Return None;
		}
		if (AGP_GameInfo(Level.Game).bNoInventory)
		{
			Return None;
		}
		if (InventoryClass != None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateInventory()	" $ Self @ InventoryClass));
			bValid=IsValidInventory(InventoryClass,AltClass);
			if (! bValid && AltClass != None)
			{
				InventoryClass=AltClass;
				bValid=True;
			}
			if (bValid)
			{
				if (InventoryClass.Default.bVirtualInventory && ! bRealInventory)
				{
					CreateVirtualInventory(InventoryClass);
				}
				else
				{
					Inv=Spawn(InventoryClass);
					if (Inv != None)
					{
						Inv.GiveTo(Self);
						Inv.PickupFunction(Self);
						if (Inv.IsA('Weapon') && bIndigenous == true)
						{
							Weapon(Inv).SetGuerrillaWeapon(True);
							BaseWeaponAttachment(Inv.ThirdPersonActor).AdjustAttachmentFor(Inv);
						}
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateInventory()  Unable to spawn inventory!"));
					}
				}
			}
		}
		Return Inv;
	*/
}

void AAGP_Character::IsValidInventory(AInventory* InventoryClass, AInventory* out_AltClass)
{
	/*
		local class<AGP.AGP_Weapon>  WeapClass;
		if (ClassIsChildOf(InventoryClass,Class'ThrowWeapon'))
		{
			Switch(class<ThrowWeapon>(InventoryClass).Default.InvGrenadeIndex)
			{
				case 0:
					if (Level.Game.GameReplicationInfo.DisableFragGrenades())
					{
						Log("Blocking frags");
						Return False;
					}
					break;
				case 1:
					if (Level.Game.GameReplicationInfo.DisableSmokeGrenades())
					{
						Log("Blocking smokes");
						Return False;
					}
					break;
				case 2:
					if (Level.Game.GameReplicationInfo.DisableFlashbangs())
					{
						Log("Blocking flashbangs");
						Return False;
					}
					break;
				case 3:
					if (Level.Game.GameReplicationInfo.DisableThermiteGrenades())
					{
						Log("Blocking thermites");
						Return False;
					}
					break;
				default:
			}
		}
		if (ClassIsChildOf(InventoryClass,Class'Ammunition'))
		{
			if (InventoryClass ~= "AGP_Inventory.Ammo_40mm_1_Gren" || InventoryClass ~= "AGP_Inventory.Ammo_30mm_1_Gren")
			{
				if (Level.Game.GameReplicationInfo.Disable203Grenades())
				{
					Log("Blocking 203 reloads");
					Return False;
				}
			}
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
		{
			WeapClass=class<AGP_Weapon>(InventoryClass);
			if (WeapClass != None && ! WeapClass.Default._bCanBeMiles)
			{
				out_AltClass=WeapClass.Default._cMILESAltClass;
				Return False;
			}
		}
		Return True;
	*/
}
void AAGP_Character::CreateVirtualInventory(AInventory* InventoryClass)
{
	/*
		local byte Index;
		local AGP.AGP_Weapon weap;
		local class<Ammunition>  ammo_class;
		if (ClassIsChildOf(InventoryClass,Class'ThrowWeapon'))
		{
			Index=class<ThrowWeapon>(InventoryClass).Default.InvGrenadeIndex;
			UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory()	" $ InventoryClass @ class<ThrowWeapon>(InventoryClass) @ class<ThrowWeapon>(InventoryClass).Default.InvGrenadeIndex @ Index));
			if (Index < 7)
			{
				_InvGrenades[Index] ++;
				Return;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory()	Unknown ThrowWeapon " $ InventoryClass));
			}
		}
		else
		{
			if (ClassIsChildOf(InventoryClass,Class'Ammunition'))
			{
				ammo_class=class<Ammunition>(InventoryClass);
				weap=AGP_Weapon(Weapon);
				if (weap != None)
				{
					if (weap.AddClip(ammo_class))
					{
						Return;
					}
				}
				weap=AGP_Weapon(getShoulderInventory());
				if (weap != None)
				{
					if (weap.AddClip(ammo_class))
					{
						Return;
					}
				}
				weap=AGP_Weapon(getHolsterInventory());
				if (weap != None)
				{
					if (weap.AddClip(ammo_class))
					{
						Return;
					}
				}
			}
			else
			{
				if (ClassIsChildOf(InventoryClass,Class'Item_Binoculars'))
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory() Testing Binoc rules"));
					if (TeamClass != None && TeamClass.IsA('ClassGuerrillaBase'))
					{
						Return;
					}
					if (Controller != None && ! Controller.IsA('AIController') && AGP_PlayerStart(Controller.StartSpot) != None && AGP_PlayerStart(Controller.StartSpot).bSpecialForces && PlayerReplicationInfo != None && ! PlayerReplicationInfo.bQualifiedSF)
					{
						Return;
					}
					Index=class<Item_Binoculars>(InventoryClass).Default.InvBinocularsIndex;
					UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory() Binoc index: " $ Index $ " for class " $ InventoryClass));
					if (Index < 6)
					{
						if (_InvBinoculars == 0)
						{
							_InvBinoculars=Index;
							Return;
						}
						else
						{
							UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory() Already have binoculars (" $ _InvBinoculars $ ") can't take (" $ Index $ ")"));
							Return;
						}
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory()	Invalid binoculars index! " $ Index));
					}
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_Character::CreateVirtualInventory()	Unknown Virtual Inventory " $ InventoryClass));
	*/
}

void AAGP_Character::UpdateEyeHeight(float DeltaTime)
{
	/*
		local float deltaZ;
		local float smooth;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector Ret;
		local FVector LeanOffset;
		local FVector LeanComponent;
		local float FallForce;
		GetAxes(Rotation,X,Y,Z);
		if (LeanParam != 0)
		{
			if (LeanParam < 0)
			{
				LeanOffset=LeanOffsetLeft;
			}
			else
			{
				LeanOffset=LeanOffsetRight;
			}
			LeanOffset *= LeanParam;
			LeanComponent=X * LeanOffset.X + Y * LeanOffset.Y + Z * LeanOffset.Z;
		}
		Ret=GetBoneCoords('CameraBone').Origin + LeanComponent + X * AnimCamRelativeLocation.X + Y * AnimCamRelativeLocation.Y + Z * AnimCamRelativeLocation.Z;
		NewEyePosition=Ret + WalkBob;
		if (isDead())
		{
			NewEyePosition += vect(0 0 20);
		}
		if (Controller == None)
		{
			Return;
		}
		if (! bJustLanded)
		{
			smooth=FMin(0.9,10 * DeltaTime / Level.TimeDilation);
			LandBob *= 1 - smooth;
		}
		else
		{
			if (bLandRecovery)
			{
				smooth=FMin(0.9,10 * DeltaTime);
				LandBob *= 1 - smooth;
				if (LandBob >= -0.01)
				{
					bJustLanded=False;
					bLandRecovery=False;
					LandBob=0;
				}
			}
			else
			{
				smooth=FMin(1.35,40 * DeltaTime);
				FallForce=0.2 * SavedFallSpeed / 35;
				if (FallForce > -3)
				{
					LandBob += -1 * smooth / 3;
					FallForce += 1;
				}
				else
				{
					if (FallForce > -4)
					{
						LandBob += -1 * smooth / 1.4;
						FallForce += 0.5;
					}
					else
					{
						if (FallForce > -5)
						{
							LandBob += -1 * smooth / 1.2;
						}
						else
						{
							LandBob += -1.2 * smooth;
						}
					}
				}
				if (LandBob < FallForce)
				{
					bLandRecovery=True;
				}
			}
		}
		NewEyePosition.Z += LandBob * 2;
		if (Controller.WantsSmoothedView())
		{
			if (Abs(NewEyePosition.Z - OldEyePosition.Z) > 0.1)
			{
				deltaZ=NewEyePosition.Z - OldEyePosition.Z;
				if (Abs(deltaZ) > 2 && Abs(deltaZ) < 24)
				{
					NewEyePosition.Z=OldEyePosition.Z + deltaZ * 0.25;
				}
			}
		}
		Controller.AdjustView(DeltaTime);
		OldEyePosition=NewEyePosition;
	*/
}
FVector AAGP_Character::EyePosition()
{
	if (Controller != NULL && Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return EyePosition();
	}
	return NewEyePosition;
}
void AAGP_Character::EyeRotation()
{
	/*
		Return GetBoneRotation('CameraBone') + AnimCamRelativeRotation;
	*/
}
void AAGP_Character::DoAnimLoop()
{
	/*
		if (AnimSequence != 'None' && AnimSequence != 'None')
		{
			LoopAnim(AnimSequence,AnimRate,AnimTime,AnimChannel);
		}
	*/
}


void AAGP_Character::SetPlayerMesh()
{
	ENetRole ThisRole = GetLocalRole();

	/*
	if (ThisRole == ROLE_Authority)
	{
		Server_SetPlayerMesh();
	}
	else
	{
		Client_SetPlayerMesh();
	}
	*/
}

bool AAGP_Character::Server_SetPlayerMesh_Validate()
{
	return true;
}

void AAGP_Character::Client_SetPlayerMesh()
{
	//Do Client Stuff
	USkeletalMesh* TestMesh;
	
	if (Team ==0)
	{
		TestMesh = GetMesh(false);
	}
	else
	{
		TestMesh = GetMesh(false);
	}
	
	if (TestMesh)
	{
		//CustomMesh = TestMesh;
		Mesh_3P->SetSkeletalMesh(TestMesh);
	}

	/*
	Mesh_3P->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> FoundAnimBP(TEXT("/Game/AmericasArmy/Blueprints/Anim/SoldierM_AnimBlueprint.SoldierM_AnimBlueprint"));
	UAnimBlueprintGeneratedClass* PreviewBP = FoundAnimBP.Object->GetAnimBlueprintGeneratedClass();
	Mesh_3P->SetAnimInstanceClass(PreviewBP);
	*/

	/*
	USkeletalMesh* TestMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_AdvMarksman.SoldierM_Infantry_Arctic_AdvMarksman'"), NULL, LOAD_None, NULL);
	if (TestMesh)
	{
		CustomMesh = TestMesh;
		Mesh_3P->SetSkeletalMesh(CustomMesh);
		//Mesh_3P->SetSkeletalMesh(TestMesh);
	}
	*/
}





void AAGP_Character::Server_SetPlayerMesh_Implementation()
{
	//Do Server Stuff
	USkeletalMesh* TestMesh = GetMesh(true);
	if (TestMesh)
	{
		//CustomMesh = TestMesh;
		Mesh_3P->SetSkeletalMesh(TestMesh);
	}

	/*
	Mesh_3P->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> FoundAnimBP(TEXT("/Game/AmericasArmy/Blueprints/Anim/SoldierM_AnimBlueprint.SoldierM_AnimBlueprint"));
	UAnimBlueprintGeneratedClass* PreviewBP = FoundAnimBP.Object->GetAnimBlueprintGeneratedClass();
	Mesh_3P->SetAnimInstanceClass(PreviewBP);
	*/

	/*
	USkeletalMesh* TestMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_AdvMarksman.SoldierM_Infantry_Arctic_AdvMarksman'"), NULL, LOAD_None, NULL);
	if (TestMesh)
	{
		CustomMesh = TestMesh;
		Mesh_3P->SetSkeletalMesh(CustomMesh);
		//Mesh_3P->SetSkeletalMesh(TestMesh);
	}
	*/
}

void AAGP_Character::Interact()
{
	FHitResult OutHit;
	FCollisionQueryParams CollisionParams;
	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 370.0f;
	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, 1, 0, 1);
	CollisionParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			AActor* Actor = OutHit.GetActor();

			if (Actor)
			{
				if (Cast<ADecoMesh>(Actor))
				{	
//					if (GEngine)
//					{
//						DrawDebugSphere(GetWorld(), FVector(OutHit.ImpactPoint), 5, 16, FColor::Red, true, -1, -1, 1);
//					}
					
					Server_Interact();
				}
				if (Cast<AMover>(Actor))
				{

					if (GEngine)
					{
						bool Side_A = true;
						AActor* A = Actor;
						AActor* B = this;
						FVector aPosRelativeToB = B->GetActorTransform().InverseTransformPosition(A->GetActorLocation());

						if (aPosRelativeToB.Y < 0)
						{
							Side_A = true;
						}
						else
						{
							Side_A = false;
						}


						/*
						if (Side_A)
						{
							DrawDebugSphere(GetWorld(), FVector(OutHit.ImpactPoint), 5, 16, FColor::Red, true, -1, -1, 1);
						}
						else
						{
							DrawDebugSphere(GetWorld(), FVector(OutHit.ImpactPoint), 5, 16, FColor::Blue, true, -1, -1, 1);
						}
						*/
					}


					Server_Interact();
				}
			}
		}
	}
	
}

// Called to bind functionality to input
void AAGP_Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	InputComponent->BindAxis("MoveForward", this, &AAGP_Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AAGP_Character::MoveRight);
	InputComponent->BindAxis("Turn", this, &AAGP_Character::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AAGP_Character::AddControllerPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AAGP_Character::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AAGP_Character::OnStopJump);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AAGP_Character::Server_OnFire);

	InputComponent->BindAction("Action", IE_Pressed, this, &AAGP_Character::Interact);

	InputComponent->BindAction("Prone", IE_Pressed, this, &AAGP_Character::Prone);
	InputComponent->BindAction("Crouch", IE_Pressed, this, &AAGP_Character::Crouch2);

	InputComponent->BindAction("ShowMenu", IE_Pressed, this, &AAGP_Character::ShowMenu);
}

void AAGP_Character::ShowMenu()
{
	Cast<AHumanController>(GetController())->ShowMenu();
}

bool AAGP_Character::Server_Interact_Validate()
{
	return true;
}
void AAGP_Character::Server_Interact_Implementation()
{
	
	if (GetLocalRole() == ROLE_Authority)
	{
		FHitResult OutHit;
		FCollisionQueryParams CollisionParams;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 370.0f;

		CollisionParams.AddIgnoredActor(this);
		if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, CollisionParams))
		{
			if (OutHit.bBlockingHit)
			{
				if (AActor* Actor = OutHit.GetActor())
				{
					if (Cast<ADecoMesh>(Actor))
					{

					}
					if (Cast<AMover>(Actor))
					{
						Cast<AMover>(Actor)->SetInstigator(this);
						Cast<AMover>(Actor)->ToggleDoor();
					}
				}
			}
		}
	}
	
}

void AAGP_Character::MoveForward(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Moving forward: %f"), AxisValue));
		AddMovementInput(Direction, AxisValue);
	}
}

void AAGP_Character::MoveRight(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
	}
}

void AAGP_Character::OnStartJump()
{
	bPressedJump = true;
}
void AAGP_Character::OnStopJump()
{
	bPressedJump = false;
}


void AAGP_Character::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		// Get the camera transform
		FVector CameraLoc;
		FRotator CameraRot;
		GetActorEyesViewPoint(CameraLoc, CameraRot);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the camera to find the final muzzle position
		FVector const MuzzleLocation = CameraLoc + FTransform(CameraRot).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRot;
		MuzzleRotation.Pitch += 10.0f;          // skew the aim upwards a bit
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			// spawn the projectile at the muzzle
			AProjectile* const Projectile = World->SpawnActor<AProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// find launch direction
				FVector const LaunchDir = MuzzleRotation.Vector();
				Projectile->InitVelocity(LaunchDir);
			}
		}
	}
}

bool AAGP_Character::Server_OnFire_Validate()
{
	return true;
}

void AAGP_Character::Server_OnFire_Implementation()
{
	//Do Server Stuff
	OnFire();
}




////   PRONE  ////
void AAGP_Character::Prone()
{
	Server_Prone();
}
bool AAGP_Character::Server_Prone_Validate()
{
	return true;
}
void AAGP_Character::Server_Prone_Implementation()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		if (bIsProne == false)
		{
			bIsProne = true;
		}
		else
		{
			bIsProne = false;
		}
		bIsCrouched2 = false;
	}
}

////   CROUCH  ////
void AAGP_Character::Crouch2()
{
	Server_Crouch();
}
bool AAGP_Character::Server_Crouch_Validate()
{
	return true;
}
void AAGP_Character::Server_Crouch_Implementation()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		if (bIsCrouched2 == false)
		{
			bIsCrouched2 = true;
		}
		else
		{
			bIsCrouched2 = false;
		}
		bIsProne = false;
	}
}


