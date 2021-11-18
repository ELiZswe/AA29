// All the original content belonged to the US Army


#include "Weapon_M249_SAW.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M249_SAW/AttachW_M249_SAW.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_M249_SAW/PickupW_M249_SAW.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"
#include "AA29/BaseScope/ScopeW_M249_SAW.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm_SAW.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"

AWeapon_M249_SAW::AWeapon_M249_SAW()
	{
	FireAnimsLowAmmo						= { "Fire04-01","Fire04-01","Fire04-01","Fire04-01","Fire05","Fire06","Fire07","Fire08","Fire09","Fire10" };
	StillLowAmmo							= {"Still04-01","Still04-01","Still04-01","Still04-01","Still05","Still06","Still07","Still08","Still09","Still10" };
	SupportedFireAnimsLowAmmo				= {"SupportedFire04-01","SupportedFire04-01","SupportedFire04-01","SupportedFire04-01","SupportedFire05","SupportedFire06","SupportedFire07","SupportedFire08","SupportedFire09","SupportedFire10" };
	SupportedStillLowAmmo					= {"SupportedStill04-01","SupportedStill04-01","SupportedStill04-01","SupportedStill04-01","SupportedStill05","SupportedStill06","SupportedStill07","SupportedStill08","SupportedStill09","SupportedStill10" };
	BaseRecoilModifier						= 0.15;
	RapidFireShots							= -1;
	RapidFireShotsNeeded					= 4;
	RapidMisFirePct							= 0.5;
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 1;
	_RecoilDirInfo.PitchMaxDeviation		= 0.65;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.6;
	_RecoilDirInfo.YawMaxDeviation			= 0.55;
	_RecoilDirInfo.YawFalloff				= 1;
	_RecoilDirInfo.bRoll					= 0;
	_RecoilDirInfo.RollMean					= 0;
	_RecoilDirInfo.RollMaxDeviation			= 0;
	_RecoilDirInfo.RollFalloff				= 0;
	_RecoilDirInfo.SpeedMean				= 0;
	_RecoilDirInfo.SpeedMaxDeviation		= 0;
	_RecoilDirInfo.SpeedFalloff				= 0;
	_RecoilDirInfo.Base						= FRotator(0, 0, 0);
	bUseAutoRecoil							= true;
	_AutoRecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AutoRecoilDirInfo.bPitch				= 1;
	_AutoRecoilDirInfo.PitchMean			= 1.3;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 0.9;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.6;
	_AutoRecoilDirInfo.YawMaxDeviation		= 0.7;
	_AutoRecoilDirInfo.YawFalloff			= 1;
	_AutoRecoilDirInfo.bRoll				= 0;
	_AutoRecoilDirInfo.RollMean				= 0;
	_AutoRecoilDirInfo.RollMaxDeviation		= 0;
	_AutoRecoilDirInfo.RollFalloff			= 0;
	_AutoRecoilDirInfo.SpeedMean			= 0;
	_AutoRecoilDirInfo.SpeedMaxDeviation	= 0;
	_AutoRecoilDirInfo.SpeedFalloff			= 0;
	_AutoRecoilDirInfo.Base					= FRotator(0, 0, 0);
	ShotsToStartRecoilBlend					= 1;
	ShotsForMaxRecoil						= 20;
	SingleFire								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Indoorfire.WeaponsUS_M249_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Outdoorfire.WeaponsUS_M249_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Reload.WeaponsUS_M249_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Pronereload.WeaponsUS_M249_Pronereload"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Fixjam.WeaponsUS_M249_Fixjam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Pronefixjam.WeaponsUS_M249_Pronefixjam"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Selectnew.WeaponsUS_M249_Selectnew"), NULL, LOAD_None, NULL);
	SupportingSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Supported.WeaponsUS_M249_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Unsupported.WeaponsUS_M249_Unsupported"), NULL, LOAD_None, NULL);
	ReloadFullSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Reloadfull.WeaponsUS_M249_Reloadfull"), NULL, LOAD_None, NULL);
	ProneReloadFullSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Pronereloadfull.WeaponsUS_M249_Pronereloadfull"), NULL, LOAD_None, NULL);
	_cScopeClass							= AScopeW_M249_SAW::StaticClass();
	fRuinedPct								= 0.25;
	OwnerDamageType							= UProjectileDamage556mm_SAW::StaticClass();
	_FPMuzzleFlashClass						= AM16A2MuzzleFlash_1P::StaticClass();
	_FPMuzzleFlashOffset.VOffset			= FVector(45, -35, -55);
	_FPMuzzleFlashOffset.ROffset			= FRotator(0, 179.901123046875, 0);
	_FPMuzzleFlashOffset.nBone				= "Muzzle";
	_sMILESBoxScale							= FVector(5, 5, 5);
	_sBlankPlugScale						= FVector(5, 5, 5);
	bAllowsPlusOneLoading					= false;
	fpWeaponThreatLevel						= 16;
	AmmoName								= AAmmo_556mm_200_Belt::StaticClass();
	PickupAmmoCount							= 200;
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	FireAdjust								= 2.7;
	bCanSupport								= true;
	vZoomAnimOffset							= FVector(-15, -2, -2);
	fZoomAnimFOV							= 15;
	WallTraceDist							= 60;
	weaponType								= EWeaponType::WEAPON_SAW;
	eROF									= RateofFire::ROF_Auto;
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 3.05;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 3.05;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	iMisFire								= -13536;
	PickupClass								= APickupW_M249_SAW::StaticClass();
	fWeight									= 6.85;
	PlayerViewOffset						= FVector(3, 0, -3);
	AttachmentClass							= { AAttachW_M249_SAW::StaticClass() };
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m249.hud_wpn_m249"), NULL, LOAD_None, NULL);
	ItemName								= FString("M249");
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P.M249_1P"), NULL, LOAD_None, NULL);
}




void AWeapon_M249_SAW::DoChangeFireMode()
{
}
void AWeapon_M249_SAW::ChangeFireMode()
{
}
void AWeapon_M249_SAW::PlayReloading()
{
	/*
		local float fpReloadRate;
		fpReloadRate=1.4;
		if (IsSupported())
		{
			if (GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation('SupportedReloadFull',fpReloadRate);
				PlayOwnedSound(ProneReloadFullSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ProneReloadFullSound,idTeamOwner);
			}
			else
			{
				RunAnimation('SupportedReload',fpReloadRate);
				PlayOwnedSound(ProneReloadSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ProneReloadSound,idTeamOwner);
			}
		}
		else
		{
			if (GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation('ReloadFull',fpReloadRate);
				PlayOwnedSound(ReloadFullSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ReloadFullSound,idTeamOwner);
			}
			else
			{
				RunAnimation('Reload',fpReloadRate);
				PlayOwnedSound(ReloadSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.ReloadSound,idTeamOwner);
			}
		}
	*/
}
void AWeapon_M249_SAW::GetSpecialFireAnim(FName SpecialAnimName)
{
	/*
		if (GetCurrentAmmoType().AmmoAmount <= 10)
		{
			if (IsSupported())
			{
				SpecialAnimName=SupportedFireAnimsLowAmmo[Clamp(GetCurrentAmmoType().AmmoAmount,0,9)];
			}
			else
			{
				SpecialAnimName=FireAnimsLowAmmo[Clamp(GetCurrentAmmoType().AmmoAmount,0,9)];
			}
			Return True;
		}
		Return False;
	*/
}
void AWeapon_M249_SAW::PlayIdleAnim()
{
	/*
		if (IsSupported())
		{
			if (GetCurrentAmmoType().AmmoAmount <= 10)
			{
				RunAnimation(SupportedStillLowAmmo[Clamp(GetCurrentAmmoType().AmmoAmount,0,9)],1,0.05,True);
			}
			else
			{
				RunAnimation('SupportedStill',1,0.05,True);
			}
		}
		else
		{
			if (GetCurrentAmmoType().AmmoAmount <= 10)
			{
				RunAnimation(StillLowAmmo[Clamp(GetCurrentAmmoType().AmmoAmount,0,9)],1,0.05,True);
			}
			else
			{
				RunAnimation('Still',1,0,True);
			}
		}
	*/
}
void AWeapon_M249_SAW::PlaySelect()
{
	/*
		local float initradius;
		if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
		{
			if (_bActive)
			{
				if (HasAnim('Raise'))
				{
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('RaiseEmpty',1);
					}
					else
					{
						RunAnimation('Raise',1);
					}
				}
				else
				{
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('SelectEmpty',1);
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
			}
			else
			{
				if (! _bCharged && HasAnim('SelectNew'))
				{
					_bCharged=True;
					RunAnimation('SelectNew',1);
					if (GetNetMode() == ENetMode::NM_Client)
					{
						initradius=1000000;
					}
					else
					{
						initradius=60;
					}
					PlayOwnedSound(SelectChargeSound,1,0.5,False,initradius,,True,False,EnemyWeaponClass.Default.SelectChargeSound,idTeamOwner);
				}
				else
				{
					if (GetCurrentAmmoType().AmmoAmount == 0)
					{
						RunAnimation('SelectEmpty',1);
					}
					else
					{
						RunAnimation('Select',1);
					}
					PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.SelectSound,idTeamOwner);
				}
			}
		}
	*/
}
void AWeapon_M249_SAW::TweenDown()
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
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('DropEmpty',1);
					}
					else
					{
						RunAnimation('Drop',1);
					}
				}
				else
				{
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('DownEmpty',1);
					}
					else
					{
						RunAnimation('Down',1);
					}
				}
			}
			else
			{
				if (SeqName == 'Drop' || SeqName == 'DropStill')
				{
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('LowDownEmpty',1);
					}
					else
					{
						RunAnimation('LowDown',1);
					}
					PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.SelectSound,idTeamOwner);
				}
				else
				{
					if (GetCurrentAmmoType().AmmoAmount < 10)
					{
						RunAnimation('DownEmpty',1);
					}
					else
					{
						RunAnimation('Down',1);
					}
					PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.SelectSound,idTeamOwner);
				}
			}
		}
	*/
}
void AWeapon_M249_SAW::PlaySupporting()
{
	/*
		DoSupported();
		if (IsSupported())
		{
			if (GetCurrentAmmoType().AmmoAmount == 0)
			{
				RunAnimation('SupportedEmpty',1,0.05);
			}
			else
			{
				RunAnimation('Supported',1,0.05);
			}
			PlayOwnedSound(SupportingSound,0,0.5,False,60,,True,False,EnemyWeaponClass.Default.SupportingSound,idTeamOwner);
		}
		else
		{
			if (GetCurrentAmmoType().AmmoAmount == 0)
			{
				RunAnimation('UnsupportedEmpty',1,0.05);
			}
			else
			{
				RunAnimation('Unsupported',1,0.05);
			}
			PlayOwnedSound(UnSupportingSound,0,0.5,False,60,,True,False,EnemyWeaponClass.Default.UnSupportingSound,idTeamOwner);
		}
	*/
}
void AWeapon_M249_SAW::PlayHighCrawlIn()
{
	/*
		if (GetCurrentAmmoType().AmmoAmount == 0)
		{
			RunAnimation('HighCrawlInEmpty',1);
		}
		else
		{
			PlayHighCrawlIn();
		}
	*/
}
void AWeapon_M249_SAW::PlayCrawl()
{
	/*
		if (Instigator != None && Instigator.bIsWalking)
		{
			GotoState('OutCrawling');
		}
		else
		{
			if (GetCurrentAmmoType().AmmoAmount == 0)
			{
				RunAnimation('HighCrawlEmpty',1,0.05,True);
			}
			else
			{
				PlayCrawl();
			}
		}
	*/
}
void AWeapon_M249_SAW::PlayHighCrawlOut()
{
	/*
		if (GetCurrentAmmoType().AmmoAmount == 0)
		{
			RunAnimation('HighCrawlOutEmpty',1);
		}
		else
		{
			PlayHighCrawlOut();
		}
	*/
}
void AWeapon_M249_SAW::HandleMisFire()
{
	/*
		if (GetCurrentAmmoType().AmmoAmount >= 10)
		{
			HandleMisFire();
		}
	*/
}
void AWeapon_M249_SAW::FixJam()
{
	/*
		if (GetCurrentAmmoType().AmmoAmount >= 10)
		{
			FixJam();
		}
	*/
}
int32 AWeapon_M249_SAW::GetPendingShots()
{
	float fr;
	fr = FMath::FRand();
	if (fr < 0.1)
	{
		return 0;				//10% chance fire 1 shot
	}
	else
	{
		if (fr < 0.3)
		{
			return 1;			//20% chance fire 2 shots
		}
		else
		{
			if (fr < 0.9)
			{
				return 2;		//60% chance fire 3 shots
			}
			else
			{
				return 3;		//10% chance fire 4 shots
			}
		}
	}
}
