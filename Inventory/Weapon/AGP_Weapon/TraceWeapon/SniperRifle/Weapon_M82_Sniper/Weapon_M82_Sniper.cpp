// All the original content belonged to the US Army


#include "Weapon_M82_Sniper.h"
#include "AA29/BaseScope/ScopeW_M82_Sniper.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M82_Sniper/AttachW_M82_Sniper.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_M82_Sniper/PickupW_M82_Sniper.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/M82MuzzleFlash_1P/M82MuzzleFlash_1P.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage127Sniper.h"
AWeapon_M82_Sniper::AWeapon_M82_Sniper()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 25;
	_RecoilDirInfo.PitchMaxDeviation	= 20;
	_RecoilDirInfo.PitchFalloff			= 0.5;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 20;
	_RecoilDirInfo.YawMaxDeviation		= 20;
	_RecoilDirInfo.YawFalloff			= 0.5;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_Indoorfire.WeaponsUS_M82_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_Outdoorfire.WeaponsUS_M82_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_Reload.WeaponsUS_M82_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_ProneReload.WeaponsUS_M82_ProneReload"), NULL, LOAD_None, NULL);
	FixJamSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_FixJam.WeaponsUS_M82_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_ProneFixJam.WeaponsUS_M82_ProneFixJam"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_SelectNew.WeaponsUS_M82_SelectNew"), NULL, LOAD_None, NULL);
	SupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_Supported.WeaponsUS_M82_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_Unsupported.WeaponsUS_M82_Unsupported"), NULL, LOAD_None, NULL);
	ProneReloadFullSound				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m82/WeaponsUS_M82_ProneReload.WeaponsUS_M82_ProneReload"), NULL, LOAD_None, NULL);
	_cScopeClass						= AScopeW_M82_Sniper::StaticClass();
	fRuinedPct							= 0.005;
	OwnerDamageType						= UProjectileDamage127Sniper::StaticClass();
	_FPMuzzleFlashClass					= AM82MuzzleFlash_1P::StaticClass();
	_FPMuzzleFlashOffset.VOffset		= FVector(0, 0, 0);
	_FPMuzzleFlashOffset.ROffset		= FRotator(0, 90, 179.901123046875);
	_FPMuzzleFlashOffset.nBone			= "Muzzle";
	fpWeaponThreatLevel					= 18;
	AmmoName							= AAmmo_127mm_10_Mag::StaticClass();
	PickupAmmoCount						= 10;
	TraceDist							= 50000;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	FireAdjust							= 2;
	bCanSupport							= true;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 4.5;
	_ZoomDirInfo.PitchFalloff			= 1;
	_ZoomDirInfo.bYaw					= 1;
	_ZoomDirInfo.YawMean				= 0;
	_ZoomDirInfo.YawMaxDeviation		= 7;
	_ZoomDirInfo.YawFalloff				= 1;
	_ZoomDirInfo.bRoll					= 0;
	_ZoomDirInfo.RollMean				= 0;
	_ZoomDirInfo.RollMaxDeviation		= 0;
	_ZoomDirInfo.RollFalloff			= 0;
	_ZoomDirInfo.SpeedMean				= 0;
	_ZoomDirInfo.SpeedMaxDeviation		= 0;
	_ZoomDirInfo.SpeedFalloff			= 0;
	_ZoomDirInfo.Base					= FRotator(0, 0, 0);
	vZoomAnimOffset						= FVector(-4, -43, -37);
	fZoomAnimFOV						= 30;
	WallTraceDist						= 85;
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
	iMisFire							= 40;
	PickupClass							= APickupW_M82_Sniper::StaticClass();
	fWeight								= 12.9;
	PlayerViewOffset					= FVector(6, 15, -61);
	AttachmentClass						= { AAttachW_M82_Sniper::StaticClass() };
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m82a1.hud_wpn_m82a1"), NULL, LOAD_None, NULL);
	ItemName							= "M82 Barrett";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M82_1P.M82_1P"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}


void AWeapon_M82_Sniper::PlayFiring()
{
	/*
	UnZoom();
	bInZoom = False;
	DisplayFOV = Default.DisplayFOV;
	PlayerViewOffset = Default.PlayerViewOffset;
	PlayFiring();
	*/
}

