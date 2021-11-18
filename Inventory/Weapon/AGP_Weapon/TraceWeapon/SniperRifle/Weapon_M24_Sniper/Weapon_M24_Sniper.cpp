// All the original content belonged to the US Army


#include "Weapon_M24_Sniper.h"
#include "AA29/BaseScope/ScopeW_M24_Sniper.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_M24_Sniper/PickupW_M24_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M24_Sniper/AttachW_M24_Sniper.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
AWeapon_M24_Sniper::AWeapon_M24_Sniper()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 8;
	_RecoilDirInfo.PitchMaxDeviation	= 8;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 5;
	_RecoilDirInfo.YawMaxDeviation		= 5;
	_RecoilDirInfo.YawFalloff			= 0.75;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Indoorfire.WeaponsUS_M24_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Outdoorfire.WeaponsUS_M24_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Reload.WeaponsUS_M24_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Reload.WeaponsUS_M24_Reload"), NULL, LOAD_None, NULL);
	FixJamSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_FixJam.WeaponsUS_M24_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_FixJam.WeaponsUS_M24_FixJam"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_SelectNew.WeaponsUS_M24_SelectNew"), NULL, LOAD_None, NULL);
	SupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Supported.WeaponsUS_M24_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_Unsupported.WeaponsUS_M24_Unsupported"), NULL, LOAD_None, NULL);
	ReloadStartSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_ReloadStart.WeaponsUS_M24_ReloadStart"), NULL, LOAD_None, NULL);
	ReloadEndSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M24/WeaponsUS_M24_ReloadEnd.WeaponsUS_M24_ReloadEnd"), NULL, LOAD_None, NULL);
	_cScopeClass						= AScopeW_M24_Sniper::StaticClass();
	OwnerDamageType						= UProjectileDamage762Sniper::StaticClass();
	_FPMuzzleFlashClass					= AAK47MuzzleFlash_1P::StaticClass();
	bAllowsPlusOneLoading				= false;
	fpWeaponThreatLevel					= 11;
	AmmoName							= AAmmo_762mm_5_Rounds::StaticClass();
	PickupAmmoCount						= 5;
	TraceDist							= 40000;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	DisplayFOV							= 50;
	bCanSupport							= true;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 2;
	_ZoomDirInfo.PitchFalloff			= 1;
	_ZoomDirInfo.bYaw					= 1;
	_ZoomDirInfo.YawMean				= 0;
	_ZoomDirInfo.YawMaxDeviation		= 5;
	_ZoomDirInfo.YawFalloff				= 1;
	_ZoomDirInfo.bRoll					= 0;
	_ZoomDirInfo.RollMean				= 0;
	_ZoomDirInfo.RollMaxDeviation		= 0;
	_ZoomDirInfo.RollFalloff			= 0;
	_ZoomDirInfo.SpeedMean				= 0;
	_ZoomDirInfo.SpeedMaxDeviation		= 0;
	_ZoomDirInfo.SpeedFalloff			= 0;
	_ZoomDirInfo.Base					= FRotator(0, 0, 0);
	vZoomAnimOffset						= FVector(-6, -3, -3);
	fZoomAnimFOV						= 30;
	WallTraceDist						= 77;
	weaponType							= EWeaponType::WEAPON_Sniper;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 3.25;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 3.25;
	_AccuracyDirInfo.YawFalloff			= 1;
	_AccuracyDirInfo.bRoll				= 0;
	_AccuracyDirInfo.RollMean			= 0;
	_AccuracyDirInfo.RollMaxDeviation	= 0;
	_AccuracyDirInfo.RollFalloff		= 0;
	_AccuracyDirInfo.SpeedMean			= 0;
	_AccuracyDirInfo.SpeedMaxDeviation	= 0;
	_AccuracyDirInfo.SpeedFalloff		= 0;
	_AccuracyDirInfo.Base				= FRotator(0, 0, 0);
	bMisFire							= false;
	PickupClass							= APickupW_M24_Sniper::StaticClass();
	fWeight								= 5.4;
	PlayerViewOffset					= FVector(6, 15, -61);
	AttachmentClass						= { AAttachW_M24_Sniper::StaticClass() };
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m24.hud_wpn_m24"), NULL, LOAD_None, NULL);
	ItemName							= "M24";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M24_1P.M24_1P"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}


void AWeapon_M24_Sniper::PlayReloading()
{
}
bool AWeapon_M24_Sniper::IsCharged()
{
	return ! bRequireRecharge;
}
bool AWeapon_M24_Sniper::MustWorkBolt()
{
	return bWorkBolt && AmmoType->AmmoAmount > 0;
}
void AWeapon_M24_Sniper::Fire(float Value)
{
	/*
		if (MustWorkBolt())
		{
			ServerFire();
			if (GetNetMode() == ENetMode::NM_Client)
			{
				GotoState('BusyFiring');
			}
		}
		else
		{
			Fire(Value);
		}
	*/
}
void AWeapon_M24_Sniper::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
		if (MustWorkBolt())
		{
			GotoState('BusyFiring');
		}
		else
		{
			ServerFire(bNoAdjustAim,bRapid,bBreatheBonus);
		}
	*/
}
void AWeapon_M24_Sniper::PlayFiring()
{
	/*
		if (bWorkBolt)
		{
			if (IsZoomed())
			{
				DoZoom(False);
			}
			if (IsSupported())
			{
				RunAnimation('SupportedFixJam',1,0.05);
			}
			else
			{
				RunAnimation('FixJam',1,0.05);
			}
			PlayOwnedSound(FixJamSound,1,0.5,False,60,,True,False,EnemyWeaponClass.Default.FixJamSound,idTeamOwner);
		}
		else
		{
			PlayFiring();
		}
		bWorkBolt=! bWorkBolt;
	*/
}
void AWeapon_M24_Sniper::DiscardShell()
{
	/*
		if (bRequireRecharge || AmmoType.AmmoAmount == 0)
		{
			FlashCount=255;
			if (BaseWeaponAttachment(ThirdPersonActor) != None)
			{
				BaseWeaponAttachment(ThirdPersonActor).FiringMode='ROF_Single';
				BaseWeaponAttachment(ThirdPersonActor).FlashCount=FlashCount;
				BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
			}
		}
	*/
}
void AWeapon_M24_Sniper::ServerStopReload()
{
	//StopReload();
}
void AWeapon_M24_Sniper::StopReload()
{
	//bStopReload=True;
}
int32 AWeapon_M24_Sniper::GetClipCountAllowed(int32 new_clip, AAmmunition* test_ammo)
{
	return new_clip;
}
void AWeapon_M24_Sniper::ReloadBullet()
{
	/*
		if (clientClip < 1 || clientAmmo == AmmoType.Default.AmmoAmount || bStopReload)
		{
			Return False;
		}
		clientAmmo ++;
		clientClip --;
		if (Role == 4)
		{
			AmmoType.AmmoAmount=clientAmmo;
			_AmmoClips[0]=clientClip;
			RecountAmmo();
		}
		else
		{
			AmmoMagCount=clientClip;
		}
		Return True;
	*/
}
bool AWeapon_M24_Sniper::CheckForNoReload()
{
	/*
		if (AmmoType.AmmoAmount == AmmoType.Default.AmmoAmount)
		{
			Return True;
		}
		else
		{
			Return CheckForNoReload();
		}
	*/
	return false;    //FAKE /ELiZ
}
void AWeapon_M24_Sniper::ReloadClip(uint8 newclip)
{
}
int32 AWeapon_M24_Sniper::GetClipCount(uint8 clip, bool bAuxAmmo)
{
	if (clip == 0)
	{
		return _AmmoClips[0];
	}
	else
	{
		//DebugLog(DEBUG_Warn,"M24::GetClipCount()	Weapon has no clips");
		return 0;
	}
}
void AWeapon_M24_Sniper::GetBestClip()
{
	//Return 0;
}
void AWeapon_M24_Sniper::AddClip(AAmmunition* AmmoClass)
{
	/*
		DebugLog(DEBUG_Inv,"AGP_Weapon::AddClip()	" $ AmmoClass @ AmmoName @ AuxAmmoName);
		if (AmmoClass == AmmoName)
		{
			_AmmoClips[0] += AmmoClass.Default.AmmoAmount;
			RecountAmmo();
			Return True;
		}
		Return False;
	*/
}
void AWeapon_M24_Sniper::RecountAmmo()
{
	AmmoMagCount=_AmmoClips[0];
}

