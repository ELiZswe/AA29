// All the original content belonged to the US Army


#include "Weapon_SPR_Sniper.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_556_Bullet.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_20_Mag_SPR/Ammo_556mm_20_Mag_SPR.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_SPR_Sniper/PickupW_SPR_Sniper.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_SPR_Sniper/AttachW_SPR_Sniper.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm_SPR.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"

AWeapon_SPR_Sniper::AWeapon_SPR_Sniper()
{
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 0.7;
	_RecoilDirInfo.PitchMaxDeviation		= 0.6;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.5;
	_RecoilDirInfo.YawMaxDeviation			= 0.45;
	_RecoilDirInfo.YawFalloff				= 1;
	_RecoilDirInfo.bRoll					= 0;
	_RecoilDirInfo.RollMean					= 0;
	_RecoilDirInfo.RollMaxDeviation			= 0;
	_RecoilDirInfo.RollFalloff				= 0;
	_RecoilDirInfo.SpeedMean				= 0;
	_RecoilDirInfo.SpeedMaxDeviation		= 0;
	_RecoilDirInfo.SpeedFalloff				= 0;
	_RecoilDirInfo.Base						= FRotator(0, 0, 0);
	SingleFire								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Indoorfire.WeaponsUS_M16A2_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Outdoorfire.WeaponsUS_M16A2_Outdoorfire"), NULL, LOAD_None, NULL);
	SuppressedSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/spr/WeaponsUS_SPR_SuppressedIndoorFire.WeaponsUS_SPR_SuppressedIndoorFire"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/spr/WeaponsUS_SPR_SuppressedOutdoorFire.WeaponsUS_SPR_SuppressedOutdoorFire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	ChangeFireSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Changefiremode.WeaponsUS_M16A2_Changefiremode"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Selectnew.WeaponsUS_M4A1_Selectnew"), NULL, LOAD_None, NULL);
	SupportingSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Supported.WeaponsUS_M4A1_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_UnSupported.WeaponsUS_M4A1_UnSupported"), NULL, LOAD_None, NULL);
	ReloadFullSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull.WeaponsUS_M4A1_ReloadFull"), NULL, LOAD_None, NULL);
	ProneReloadFullSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	SuppressorOnSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/spr/WeaponsUS_SPR_SuppressorOn.WeaponsUS_SPR_SuppressorOn"), NULL, LOAD_None, NULL);
	SuppressorOffSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/spr/WeaponsUS_SPR_SuppressorOff.WeaponsUS_SPR_SuppressorOff"), NULL, LOAD_None, NULL);
	ReloadEmptyAnim							= "ReloadEmpty";
	ReloadFullAnim							= "ReloadFull";
	ProneReloadEmptyAnim					= "SupportedReloadEmpty";
	ProneReloadFullAnim						= "SupportedReloadFull";
	OwnerDamageType							= UProjectileDamage556mm_SPR::StaticClass();
	special_tag								= "_new";
	_FPMuzzleFlashClass						= AM16A2MuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashClass			= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashOffset.VOffset	= FVector(0, 179.901123046875, 0);
	_FPSuppressedMuzzleFlashOffset.ROffset	= FRotator(0, 0, 0);
	_FPSuppressedMuzzleFlashOffset.nBone	= "Muzzle";
	AmmoRoundClass							= AAmmoRound_556_Bullet::StaticClass();
	NumAmmoRounds							= 3;
	WM_Default								= {
									"WeaponMod_VariX_Scope",
									"none",
									"none",
									"none",
									"WeaponMod_Harris_Bipod",
									"WeaponMod_SPR_Suppressor"
								};
//		\\LegalModList =
//		AGP_Inventory = 12
	AmmoName								= AAmmo_556mm_20_Mag_SPR::StaticClass();
	PickupAmmoCount							= 20;
	TraceDist								= 40000;
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	DisplayFOV								= 50;
	MuzzleScale								= 1;
	_ZoomDirInfo.MeanDirection				= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch						= 1;
	_ZoomDirInfo.PitchMean					= 0;
	_ZoomDirInfo.PitchMaxDeviation			= 2;
	_ZoomDirInfo.PitchFalloff				= 1;
	_ZoomDirInfo.bYaw						= 1;
	_ZoomDirInfo.YawMean					= 0;
	_ZoomDirInfo.YawMaxDeviation			= 5;
	_ZoomDirInfo.YawFalloff					= 1;
	_ZoomDirInfo.bRoll						= 0;
	_ZoomDirInfo.RollMean					= 0;
	_ZoomDirInfo.RollMaxDeviation			= 0;
	_ZoomDirInfo.RollFalloff				= 0;
	_ZoomDirInfo.SpeedMean					= 0;
	_ZoomDirInfo.SpeedMaxDeviation			= 0;
	_ZoomDirInfo.SpeedFalloff				= 0;
	_ZoomDirInfo.Base						= FRotator(0, 0, 0);
	vZoomAnimOffset							= FVector(-5, -5, 1);
	fZoomAnimFOV							= 15;
	WallTraceDist							= 55;
	weaponType								= EWeaponType::WEAPON_Sniper;
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 2.4;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 2.4;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	iMisFire								= 1500;
	PickupClass								= APickupW_SPR_Sniper::StaticClass();
	fWeight									= 4;
	PlayerViewOffset						= FVector(0, 0, -1);
	AttachmentClass							= { AAttachW_SPR_Sniper::StaticClass() };
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_spr.hud_wpn_spr"), NULL, LOAD_None, NULL);
	ItemName								= "SPR";
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/SPR_1P.SPR_1P"), NULL, LOAD_None, NULL);
	DrawScale								= 1;
}