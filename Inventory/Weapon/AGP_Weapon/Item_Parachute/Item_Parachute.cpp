// All the original content belonged to the US Army


#include "Item_Parachute.h"
#include "AA29/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"

AItem_Parachute::AItem_Parachute()
{
	RigRotationLimits       = FRotator(69.98291015625, 45, 0);
	DisplayFOV	            = 65;
	bUseInstigatorRotation  = true;
	bDrawOnHUD              = true;
	PlayerViewOffset        = FVector(20, 0, -40);
	AttachmentClass         = { AAttch_Parachute::StaticClass() };
	IconMaterial            = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_parachute.hud_parachute"), NULL, LOAD_None, NULL);
	ItemName                = FString("Parachute");
	Mesh                    = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Parachute_1P.Parachute_1P"), NULL, LOAD_None, NULL);
	DrawScale               = 5;
}


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
void AItem_Parachute::DropFrom(FVector StartLocation, bool bAttach)
{
}
void AItem_Parachute::SetupClientWeapon()
{
	/*
		SetupClientWeapon();
		AGP_Pawn(Instigator).Weapon=Self;
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
void AItem_Parachute::GetStaticMesh(bool bFriendly)
{
}
void AItem_Parachute::NotifyNewParachuteState(int32 NewState)
{
	/*
		Switch(NewState)
		{
			case 1:
			SetupCamera(True);
			RunAnimation('Select',1);
			break;
			case 2:
			SetupCamera(True);
			RunAnimation('Idle',1,,True);
			if (Instigator != None)
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
				Return;
			}
			SetTimer(1,False);
			if (Instigator != None)
			{
				Instigator.fParaDampening=Instigator.fFlareDampening;
			}
			GOTO JL01B9;
			case 6:
			if (Instigator != None)
			{
				Instigator.fParaDampening=1;
			}
			SetupCamera(False);
			GOTO JL01B9;
			case 3:
			SetupCamera(False);
			GOTO JL01B9;
			case 4:
			CleanupParachute();
			GOTO JL01B9;
			case 7:
			SetupCamera(True);
			RunAnimation('Idle',1,,True);
			GOTO JL01B9;
			default:
			DebugLog(DEBUG_Warn,"Attch_Parachute::NotifyNewParachuteState()	Unknown state " $ NewState);
			Return;
	JL01B9:
		}
		Charge=NewState;
		Attch_Parachute(ThirdPersonActor).NotifyNewParachuteState(Charge);
	*/
}
void AItem_Parachute::CleanupParachute()
{
	/*
		if (Instigator != None)
		{
			if (Instigator.Weapon == Self)
			{
				Instigator._InvHands.DeleteItem(Instigator._InvHands.getFirstItem());
				Instigator.Weapon=None;
			}
		}
		Attch_Parachute(ThirdPersonActor).NotifyNewParachuteState(4);
		ThirdPersonActor=None;
		Destroy();
	*/
}
void AItem_Parachute::Timer()
{
	/*
		if (Instigator != None)
		{
			Switch(Charge)
			{
				case 5:
				if (GetNetMode() != ENetMode::NM_Client)
				{
					if (AGP_PlayerStart(Instigator.Controller.StartSpot).bNoPLFDamage)
					{
						DebugLog(DEBUG_Warn,"Item_Parachute::Timer()	We shouldn't have gotten here!");
						Return;
					}
					if (Instigator.Physics != 17 || Instigator.FullBodyAnim != 4 || ! Instigator.IsInState('BusyParachuting'))
					{
						Return;
					}
					if (FRand() < 0.3)
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
	/*
		local AGP.HumanController PC;
		local name CurrentState;
		local bool bUpdateState;
		local float Forward;
		local float Strafe;
		Tick(DeltaTime);
		if (Instigator != None && Instigator.bDecoupleCamera)
		{
			Instigator.rBaseRotation=Instigator.Rotation;
			PC=HumanController(Instigator.Controller);
			if (PC != None)
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
							bUpdateState=True;
						}
					}
					else
					{
						if (Strafe < 0)
						{
							if (CurrentState != 'BusyLeftIn' || CurrentState != 'BusyLeft')
							{
								DesiredState='BusyLeftIn';
								bUpdateState=True;
							}
						}
						else
						{
							if (Forward > 0)
							{
								if (CurrentState != 'BusyForwardIn' || CurrentState != 'BusyForward')
								{
									DesiredState='BusyForwardIn';
									bUpdateState=True;
								}
							}
							else
							{
								if (Forward < 0)
								{
									if (CurrentState != 'BusyBackwardIn' || CurrentState != 'BusyBackward')
									{
										DesiredState='BusyBackwardIn';
										bUpdateState=True;
									}
								}
								else
								{
									if (CurrentState != 'Idle')
									{
										DesiredState='Idle';
										bUpdateState=True;
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
	/*
		local PlayerController PlayerOwner;
		if (Instigator != None && Instigator.IsHumanControlled())
		{
			PlayerOwner=PlayerController(Instigator.Controller);
		}
		if (PlayerOwner == None || PlayerOwner.bBehindView)
		{
			Return;
		}
		if (bWeaponAndAttachmentsOnly == true)
		{
			SetLocation(Instigator.CalcDrawOffset(Self));
			SetRotation(Instigator.Rotation);
			if (Charge == 0 || Charge == 3 || Charge == 4)
			{
				Return;
			}
			Canvas.DrawActor(Self,False,True,DisplayFOV);
		}
	*/
}
void AItem_Parachute::SetupCamera(bool bOn)
{
	/*
		bCameraLocked=bOn;
		if (Instigator != None)
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
	/*
		NotifyReplicationComplete();
		if (bCameraLocked != Instigator.bDecoupleCamera)
		{
			SetupCamera(bCameraLocked);
		}
	*/
}
void AItem_Parachute::PlayIdleAnim()
{
}
void AItem_Parachute::IsInExitState()
{
	//Return False;
}
void AItem_Parachute::ShouldDrawCrosshair()
{
	//Return False;
}
