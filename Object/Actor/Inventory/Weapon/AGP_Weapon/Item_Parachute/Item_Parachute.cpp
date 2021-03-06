// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"

AItem_Parachute::AItem_Parachute()
{
	RigRotationLimits       = FRotator(69.98291015625, 45, 0);
	DisplayFOV	            = 65;
	bUseInstigatorRotation  = true;
	bDrawOnHUD              = true;
	PlayerViewOffset        = FVector(20, 0, -40);
	AttachmentClass         = { AAttch_Parachute::StaticClass() };
	IconMaterial            = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_parachute_Mat.hud_parachute_Mat'"), NULL, LOAD_None, NULL);
	ItemName                = FString("Parachute");
	Mesh                    = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Parachute_1P.Parachute_1P"), NULL, LOAD_None, NULL);
	DrawScale               = 5;
}

/*
simulated State BusyPulling extends busy
{
	simulated Function AnimEnd(int32 Channel)
	{
		if (IsInExitState())
		{
			GotoState(DesiredState);
		}
	}
}
*/

/*
simulated State BusyForwardIn extends BusyPulling
{
	simulated Function AnimEnd(int32 Channel)
	{
		Super::AnimEnd(Channel);
		GotoState("BusyForward");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullFwIn",1);
		ExitState="BusyForwardOut";
	}
}
*/

/*
simulated State BusyForward extends BusyPulling
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullFwIdle",1,,true);
		ExitState="BusyForwardOut";
	}
}
*/

/*
simulated State BusyForwardOut extends BusyPulling
{
	simulated Function bool IsInExitState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullFwOut",1);
	}
}
*/

/*
simulated State BusyBackwardIn extends BusyPulling
{
	simulated Function AnimEnd(int32 Channel)
	{
		Super::AnimEnd(Channel);
		GotoState("BusyBackward");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullBkIn",1);
		ExitState="BusyBackwardOut";
	}
}
*/

/*
simulated State BusyBackward extends BusyPulling
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullBkIdle",1,,true);
		ExitState="BusyBackwardOut";
	}
}
*/

/*
simulated State BusyBackwardOut extends BusyPulling
{
	simulated Function bool IsInExitState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullBkOut",1);
	}
}
*/

/*
simulated State BusyRightIn extends BusyPulling
{
	simulated Function AnimEnd(int32 Channel)
	{
		Super::AnimEnd(Channel);
		GotoState("BusyRight");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullRtIn",1);
		ExitState="BusyRightOut";
	}
}
*/

/*
simulated State BusyRight extends BusyPulling
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullRtIdle",1,,true);
		ExitState="BusyRightOut";
	}
}
*/

/*
simulated State BusyRightOut extends BusyPulling
{
	simulated Function bool IsInExitState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullRtOut",1);
	}
}
*/

/*
simulated State BusyLeftIn extends BusyPulling
{
	simulated Function AnimEnd(int32 Channel)
	{
		Super::AnimEnd(Channel);
		GotoState("BusyLeft");
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullLtIn",1);
		ExitState="BusyLeftOut";
	}
}
*/

/*
simulated State BusyLeft extends BusyPulling
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullLtIdle",1,,true);
		ExitState="BusyLeftOut";
	}
}
*/

/*
simulated State BusyLeftOut extends BusyPulling
{
	simulated Function bool IsInExitState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Item_Parachute::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		RunAnimation("PullLtOut",1);
	}
}
*/

void AItem_Parachute::Fire(float Value)
{
}
void AItem_Parachute::AltFire(float Value)
{
}
void AItem_Parachute::Reload()
{
}
void AItem_Parachute::FixJam()
{
}
void AItem_Parachute::ChangeFireMode()
{
}
void AItem_Parachute::CycleZoom()
{
}
void AItem_Parachute::ToggleZoom()
{
}
void AItem_Parachute::ForceUnzoom(bool bForce)
{
}
void AItem_Parachute::UnZoom()
{
}
void AItem_Parachute::Zoom()
{
}
void AItem_Parachute::SpawnAndAttachMILESGear()
{
}
bool AItem_Parachute::CanUseWeapon(int32 DesiredAction)
{
	return false;
}
APickup* AItem_Parachute::DropFrom(FVector StartLocation, bool bAttach)
{
	return nullptr;     //FAKE   /EliZ
}
void AItem_Parachute::SetupClientWeapon()
{
	/*
		SetupClientWeapon();
		Cast<AAGP_Pawn>(Instigator).Weapon=Self;
	*/
}
EUpperBodyAnim AItem_Parachute::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_NONE_Empty;
}
FString AItem_Parachute::DisplayDebugMessage()
{
	FString Str;

	switch (Charge) {
	case PARACHUTE_ATTACH_NONE:		Str = "Parachute State: None";		break;
	case PARACHUTE_ATTACH_RIG:		Str = "Parachute State: Rig";		break;
	case PARACHUTE_ATTACH_DEPLOY:	Str = "Parachute State: Deploy";	break;
	case PARACHUTE_ATTACH_IDLE:		Str = "Parachute State: Idle";		break;
	case PARACHUTE_ATTACH_COLLAPSE: Str = "Parachute State: Collapse";	break;
	case PARACHUTE_ATTACH_GROUND:	Str = "Parachute State: Ground";	break;
	case PARACHUTE_ATTACH_FLARE:	Str = "Parachute State: Flare";		break;
	case PARACHUTE_ATTACH_PREMATURE:Str = "Parachute State: Premature"; break;
	default:						Str = "Parachute State: ERROR";		break;
	}

	return Str;
}
void AItem_Parachute::BeginPlay()
{
	/*
		BeginPlay();
		ExitState='Idle';
	*/
}
void AItem_Parachute::AttachToPawn(APawn* p)
{
	/*
		p.FullBodyAnim=3;
		AttachToPawn(p);
	*/
}
void AItem_Parachute::NotifyBaseChange()
{
}
void AItem_Parachute::SetMesh()
{
}
UStaticMesh* AItem_Parachute::GetStaticMesh(bool bFriendly)
{
	return nullptr;    //FAKE   /EliZ
}
void AItem_Parachute::NotifyNewParachuteState(int32 NewState)
{
	/*
		switch(NewState)
		{
			case 1:
			SetupCamera(true);
			RunAnimation('Select',1);
			break;
			case 2:
			SetupCamera(true);
			RunAnimation('Idle',1,,true);
			if (Instigator != nullptr)
			{
				Instigator.fParaDampening=Instigator.Default.fParaDampening;
				if (Instigator.Controller.IsInState('WaitingForPawn'))
				{
					Instigator.SetPhysics(17);
				}
				else
				{
					Instigator.Controller.GotoState('PlayerParachuting');
				}
			}
			GOTO JL01B9;
			case 5:
			if (Charge != 2)
			{
				return;
			}
			SetTimer(1,false);
			if (Instigator != nullptr)
			{
				Instigator.fParaDampening=Instigator.fFlareDampening;
			}
			GOTO JL01B9;
			case 6:
			if (Instigator != nullptr)
			{
				Instigator.fParaDampening=1;
			}
			SetupCamera(false);
			GOTO JL01B9;
			case 3:
			SetupCamera(false);
			GOTO JL01B9;
			case 4:
			CleanupParachute();
			GOTO JL01B9;
			case 7:
			SetupCamera(true);
			RunAnimation('Idle',1,,true);
			GOTO JL01B9;
			default:
			DebugLog(DEBUG_Warn,"Attch_Parachute::NotifyNewParachuteState()	Unknown state " + NewState);
			return;
	JL01B9:
		}
		Charge=NewState;
		Attch_Parachute(ThirdPersonActor).NotifyNewParachuteState(Charge);
	*/
}
void AItem_Parachute::CleanupParachute()
{
	/*
		if (Instigator != nullptr)
		{
			if (Instigator.Weapon == this)
			{
				Instigator._InvHands.DeleteItem(Instigator._InvHands.getFirstItem());
				Instigator.Weapon=nullptr;
			}
		}
		Attch_Parachute(ThirdPersonActor).NotifyNewParachuteState(4);
		ThirdPersonActor=nullptr;
		Destroy();
	*/
}
void AItem_Parachute::Timer()
{
	/*
		if (Instigator != nullptr)
		{
			switch(Charge)
			{
				case 5:
				if (GetNetMode() != ENetMode::NM_Client)
				{
					if (Cast<AAGP_PlayerStart>(Instigator.Controller.StartSpot).bNoPLFDamage)
					{
						DebugLog(DEBUG_Warn,"Item_Parachute::Timer()	We shouldn't have gotten here!");
						return;
					}
					if (Instigator.Physics != 17 || Instigator.FullBodyAnim != 4 || ! Instigator.IsInState('BusyParachuting'))
					{
						return;
					}
					if (FMath::FRand() < 0.3)
					{
						Instigator.UpdateParachute(6);
						break;
					}
					Instigator.UpdateParachute(2);
				}
			}
			default:
		}
	*/
}
void AItem_Parachute::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AHumanController* PC = nullptr;
	FName CurrentState = "";
	bool bUpdateState = false;
	float Forward = 0;
	float Strafe = 0;
	/*
	if (Instigator != nullptr && Instigator.bDecoupleCamera)
	{
		Instigator.rBaseRotation=Instigator.Rotation;
		PC=Cast<AHumanController>(Instigator.Controller);
		if (PC != nullptr)
		{
			if (PC.CurrentForward > 0)
			{
				Forward=1;
			}
			else
			{
				if (PC.CurrentForward < 0)
				{
					Forward=-1;
				}
			}
			if (PC.CurrentStrafe > 0)
			{
				Strafe=1;
			}
			else
			{
				if (PC.CurrentStrafe < 0)
				{
					Strafe=-1;
				}
			}
			if (Forward != LastForward || Strafe != LastStrafe)
			{
				CurrentState=GetStateName();
				if (Strafe > 0)
				{
					if (CurrentState != 'BusyRightIn' || CurrentState != 'BusyRight')
					{
						DesiredState='BusyRightIn';
						bUpdateState=true;
					}
				}
				else
				{
					if (Strafe < 0)
					{
						if (CurrentState != 'BusyLeftIn' || CurrentState != 'BusyLeft')
						{
							DesiredState='BusyLeftIn';
							bUpdateState=true;
						}
					}
					else
					{
						if (Forward > 0)
						{
							if (CurrentState != 'BusyForwardIn' || CurrentState != 'BusyForward')
							{
								DesiredState='BusyForwardIn';
								bUpdateState=true;
							}
						}
						else
						{
							if (Forward < 0)
							{
								if (CurrentState != 'BusyBackwardIn' || CurrentState != 'BusyBackward')
								{
									DesiredState='BusyBackwardIn';
									bUpdateState=true;
								}
							}
							else
							{
								if (CurrentState != 'Idle')
								{
									DesiredState='Idle';
									bUpdateState=true;
								}
							}
						}
					}
				}
				if (bUpdateState)
				{
					if (CurrentState == 'Idle')
					{
						GotoState(DesiredState);
					}
					else
					{
						if (! IsInExitState())
						{
							GotoState(ExitState);
						}
					}
				}
				LastForward=Forward;
				LastStrafe=Strafe;
			}
		}
	}
	*/
}
void AItem_Parachute::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	APlayerController* PlayerOwner = nullptr;
	/*
	if (Instigator != nullptr && Instigator.IsHumanControlled())
	{
		PlayerOwner=Cast<APlayerController>(Instigator.Controller);
	}
	if (PlayerOwner == nullptr || PlayerOwner.bBehindView)
	{
		return;
	}
	if (bWeaponAndAttachmentsOnly == true)
	{
		SetActorLocation(Instigator.CalcDrawOffset(this));
		SetActorRotation(Instigator.Rotation);
		if (Charge == 0 || Charge == 3 || Charge == 4)
		{
			return;
		}
		Canvas.DrawActor(this,false,True,DisplayFOV);
	}
	*/
}

void AItem_Parachute::SetupCamera(bool bOn)
{
	bCameraLocked = bOn;
	/*
	if (Instigator != nullptr)
	{
		Instigator.bDecoupleCamera=bOn;
		Instigator.LimitRotation(bOn);
		if (bOn)
		{
			Instigator.rRotationLimits=RigRotationLimits;
		}
		else
		{
			Instigator.rRotationLimits=Instigator.Default.rRotationLimits;
		}
	}
	*/
}
void AItem_Parachute::NotifyReplicationComplete()
{
	Super::NotifyReplicationComplete();
	/*
	if (bCameraLocked != Instigator.bDecoupleCamera)
	{
		SetupCamera(bCameraLocked);
	}
	*/
}
void AItem_Parachute::PlayIdleAnim()
{
}

bool AItem_Parachute::IsInExitState()
{
	return false;
}

bool AItem_Parachute::ShouldDrawCrosshair()
{
	return false;
}
