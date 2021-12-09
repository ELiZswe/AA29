// All the original content belonged to the US Army


#include "Weapon_M16A2_Trainer.h"

AWeapon_M16A2_Trainer::AWeapon_M16A2_Trainer()
{
	bInitializeWeaponDown      = true;
	SupportedFireAnims         = { "Fire", "FireB", "FireC" };
	SupportedZoomFireAnims     = { "ZoomFire", "ZoomFireB", "ZoomFireC" };
	AuxSupportedZoomFireAnims  = { "ZoomFire", "ZoomFireB", "ZoomFireC" };
	ProneReloadEmptyAnim       = "Reload";
	ProneReloadFullAnim        = "Reload";
	PickupAmmoCount            = 0;
	bCanSupport                = true;
	WallTraceDist              = 90;
	iMisFire                   = 0;
}

void AWeapon_M16A2_Trainer::AddClip(AAmmunition* AmmoClass)
{
	/*
		local int i;
		DebugLog(DEBUG_Inv,"AGP_Weapon::AddClip()	" $ AmmoClass @ AmmoName @ AuxAmmoName);
		if (AmmoClass == None)
		{
			Return False;
		}
		else
		{
			if (ClassIsChildOf(AmmoClass,AmmoName))
			{
				for (i=0; i<16; i++)
				{
					if (GetClipCount(i) <= 0)
					{
						SetClipCount(i,AmmoClass.Default.AmmoAmount);
						AmmoMagCount ++;
						Return True;
					}
				}
			}
			else
			{
				if (AmmoClass == AuxAmmoName)
				{
					for (i=0; i<16; i++)
					{
						if (GetClipCount(i,True) <= 0)
						{
							SetClipCount(i,AmmoClass.Default.AmmoAmount,True);
							AuxAmmoMagCount ++;
							Return True;
						}
					}
				}
				else
				{
					Return False;
				}
			}
		}
	*/
}
void AWeapon_M16A2_Trainer::FixJam()
{
	bool bPreviouslySupported;
	bPreviouslySupported=bIsSupported;
	if (bIsSupported)
	{
		bIsSupported=false;
	}
	Super::FixJam();
	bIsSupported=bPreviouslySupported;
}
void AWeapon_M16A2_Trainer::SetSupported(bool newSupported)
{
	if (bCanSetSupported)
	{
		bIsSupported=newSupported;
		PlaySupporting();
	}
}
void AWeapon_M16A2_Trainer::PlayChangeFireMode()
{
	/*
		Switch(NewAuxMode)
		{
			case 0:
			if (IsSupported())
			{
				if (ShouldUse3dSights() && IsZoomed())
				{
					if (_Scope != None && _Scope.bAux3dSights)
					{
						RunAnimation(AuxSupportedZoomFireAnims[0],0.5);
						break;
					}
					RunAnimation(SupportedZoomFireAnims[0],0.5);
				}
			}
			else
			{
				if (eROF == 1)
				{
					RunAnimation('ChangeFireMode',1);
				}
				else
				{
					RunAnimation('ChangeFireModeBack',1);
				}
			}
		}
		else
		{
			if (ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope != None && _Scope.bAux3dSights)
				{
					RunAnimation(AuxZoomFireAnims[0],0.5);
				}
				else
				{
					RunAnimation(ZoomFireAnims[0],0.5);
				}
			}
			else
			{
				if (eROF == 1)
				{
					RunAnimation('ChangeFireMode',1);
				}
				else
				{
					RunAnimation('ChangeFireModeBack',1);
				}
			}
		}
		GOTO JL017A;
		case 1:
		SelectAuxFireMode();
		RunAnimation('Swap',1);
		GOTO JL017A;
		case 2:
		SelectNormalMode();
		RunAnimation('Swapback',1);
		GOTO JL017A;
		default:
	JL017A:
		PlayWeaponSound(ChangeFireSound,EnemyWeaponClass.Default.ChangeFireSound);
	*/
}
void AWeapon_M16A2_Trainer::TweenDown()
{
	/*
		local name SeqName;
		local float AnimFrame;
		local float AnimRate;
		GetAnimParams(0,SeqName,AnimFrame,AnimRate);
		if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
		{
			TweenAnim(SeqName,AnimFrame * 0.4);
		}
		else
		{
			if (_bActive)
			{
				if (HasAnim('Drop'))
				{
					RunAnimation('Drop',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
			else
			{
				if (bInitializeWeaponDown)
				{
					bInitializeWeaponDown=False;
				}
				else
				{
					PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				}
				if (SeqName == 'Drop' || SeqName == 'DropStill')
				{
					RunAnimation('LowDown',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
		}
	*/
}
void AWeapon_M16A2_Trainer::SetupClientWeapon()
{
	/*
		Instigator=Pawn(Owner);
		SpawnAndAttachAmmoRounds();
		SpawnAndAttachMILESGear();
		SetWeaponSkins();
		SpawnMuzzleFlash();
		SpawnAndAttachScope();
		UpdateCurrentAmmoRounds();
		BaseWeaponAttachment(ThirdPersonActor).InitializeShellEmitter();
		if (bBusyRaiseWeaponPending)
		{
			GotoState('BusyLoweringWeapon');
			bBusyRaiseWeaponPending=False;
			bBusyLowerWeaponPending=False;
		}
	*/
}
