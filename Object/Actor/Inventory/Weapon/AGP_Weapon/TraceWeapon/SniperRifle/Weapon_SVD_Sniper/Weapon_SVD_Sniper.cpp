// All the original content belonged to the US Army


#include "Weapon_SVD_Sniper.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_SVD_Sniper/ScopeW_SVD_Sniper.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_SVD_Sniper/AttachW_SVD_Sniper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_SVD_Sniper/PickupW_SVD_Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage127Sniper.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"

AWeapon_SVD_Sniper::AWeapon_SVD_Sniper()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 22;
	_RecoilDirInfo.PitchMaxDeviation	= 17;
	_RecoilDirInfo.PitchFalloff			= 0.5;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 18;
	_RecoilDirInfo.YawMaxDeviation		= 18;
	_RecoilDirInfo.YawFalloff			= 0.5;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Indoorfire.WeaponsOPFOR_AK47_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Outdoorfire.WeaponsOPFOR_AK47_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload.WeaponsOPFOR_AK47_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload.WeaponsOPFOR_AK47_Reload"), NULL, LOAD_None, NULL);
	FixJamSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam.WeaponsOPFOR_AK47_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam.WeaponsOPFOR_AK47_FixJam"), NULL, LOAD_None, NULL);
	ChangeFireSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_ChangeFireMode.WeaponsOPFOR_AK47_ChangeFireMode"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_SelectNew.WeaponsOPFOR_AK47_SelectNew"), NULL, LOAD_None, NULL);
	_cScopeClass						= AScopeW_SVD_Sniper::StaticClass();
	fRuinedPct							= 0.005;
	OwnerDamageType						= UProjectileDamage127Sniper::StaticClass();
	_FPMuzzleFlashClass					= AAK47MuzzleFlash_1P::StaticClass();
	bWeaponIsOpFor						= true;
	fpWeaponThreatLevel					= 11;
	AmmoName							= AAmmo_127mm_10_Mag::StaticClass();
	PickupAmmoCount						= 10;
	TraceDist							= 40000;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Down.WeaponsOPFOR_AK47_Down"), NULL, LOAD_None, NULL);
	DisplayFOV							= 50;
	FireAdjust							= 1.5;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 2.4;
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
	vZoomAnimOffset						= FVector( -4, -429, -4);
	fZoomAnimFOV						= 45;
	weaponType							= EWeaponType::WEAPON_Sniper;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 3.15;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 3.15;
	_AccuracyDirInfo.YawFalloff			= 1;
	_AccuracyDirInfo.bRoll				= 0;
	_AccuracyDirInfo.RollMean			= 0;
	_AccuracyDirInfo.RollMaxDeviation	= 0;
	_AccuracyDirInfo.RollFalloff		= 0;
	_AccuracyDirInfo.SpeedMean			= 0;
	_AccuracyDirInfo.SpeedMaxDeviation	= 0;
	_AccuracyDirInfo.SpeedFalloff		= 0;
	_AccuracyDirInfo.Base				= FRotator(0, 0, 0);
	iMisFire							= 4000;
	PickupClass							= APickupW_SVD_Sniper::StaticClass();
	fWeight								= 12.9;
	PlayerViewOffset					= FVector(6, 0, -61);
	AttachmentClass						= { AAttachW_SVD_Sniper::StaticClass() };
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_dragunov.hud_wpn_dragunov"), NULL, LOAD_None, NULL);
	ItemName							= "SVD";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/svd_1P.svd_1P"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}