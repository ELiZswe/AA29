// All the original content belonged to the US Army


#include "Weapon_AK47_Rifle.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_30_Mag/Ammo_762mm_30_Mag.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_AK47_Rifle/AttachW_AK47_Rifle.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_AK47_Rifle/PickupW_AK47_Rifle.h"
#include "AA29/BaseScope/ScopeW_AK47_Rifle.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"

AWeapon_AK47_Rifle::AWeapon_AK47_Rifle()
{
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 1.3;
	_RecoilDirInfo.PitchMaxDeviation		= 0.8;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.7;
	_RecoilDirInfo.YawMaxDeviation			= 0.8;
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
	_AutoRecoilDirInfo.PitchMean			= 1.7;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 1;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.8;
	_AutoRecoilDirInfo.YawMaxDeviation		= 0.9;
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
	ShotsForMaxRecoil						= 10;
	SingleFire								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Indoorfire.WeaponsOPFOR_AK47_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Outdoorfire.WeaponsOPFOR_AK47_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload.WeaponsOPFOR_AK47_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload.WeaponsOPFOR_AK47_Reload"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam.WeaponsOPFOR_AK47_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam.WeaponsOPFOR_AK47_FixJam"), NULL, LOAD_None, NULL);
	ChangeFireSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_ChangeFireMode.WeaponsOPFOR_AK47_ChangeFireMode"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_SelectNew.WeaponsOPFOR_AK47_SelectNew"), NULL, LOAD_None, NULL);
	_cScopeClass							= AScopeW_AK47_Rifle::StaticClass();
	OwnerDamageType							= UProjectileDamage762mm::StaticClass();
	_FPMuzzleFlashClass						= AAK47MuzzleFlash_1P::StaticClass();
	bWeaponIsOpFor							= true;
	fpWeaponThreatLevel						= 11;
	AmmoName								= AAmmo_762mm_30_Mag::StaticClass();
	PickupAmmoCount							= 30;
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Down.WeaponsOPFOR_AK47_Down"), NULL, LOAD_None, NULL);
	DisplayFOV								= 50;
	FireAdjust								= 2.5;
	vZoomAnimOffset							= FVector(10, -175, -1195);
	fZoomAnimFOV							= 12;
	WallTraceDist							= 60;
	weaponType								= EWeaponType::WEAPON_Rifle;
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 2.55;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 2.55;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	iMisFire								= 4000;
	PickupClass								= APickupW_AK47_Rifle::StaticClass();
	fWeight									= 4.87;
	PlayerViewOffset						= FVector(3, 0, -29);
	AttachmentClass							= { AAttachW_AK47_Rifle::StaticClass() };
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47.hud_wpn_ak47"), NULL, LOAD_None, NULL);
	ItemName								= "AK-47";
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/ak47_1P.ak47_1P"), NULL, LOAD_None, NULL);
}


void AWeapon_AK47_Rifle::DoChangeFireMode()
{
	switch (eROF) 
	{
		case RateofFire::ROF_Single:
			eROF = RateofFire::ROF_Auto;
			break;
		case RateofFire::ROF_Auto:
			eROF = RateofFire::ROF_Single;
			break;
		default:
			// note, if it's not burst or single, here's our chance to catch it!
			eROF = RateofFire::ROF_Single;
			break;
	}
}