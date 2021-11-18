// All the original content belonged to the US Army


#include "Weapon_BDM_Rocket.h"
#include "AA29/BaseScope/ScopeW_BDM_Rocket.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_BDM_Rocket/Ammo_BDM_Rocket.h"
#include "AA29/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_BDM_Rocket/PickupW_BDM_Rocket.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_BDM_Rocket/AttachW_BDM_Rocket.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/BackBlastDamage/BackBlastDamage.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/BDMMuzzleFlash_1P/BDMMuzzleFlash_1P.h"

AWeapon_BDM_Rocket::AWeapon_BDM_Rocket()
{
	bSingleShot							= true;
	_RecoilDirInfo.MeanDirection		= FVector( 0, 0, 0);
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
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/AT4/WeaponsUS_AT4_Fire.WeaponsUS_AT4_Fire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/AT4/WeaponsUS_AT4_Fire.WeaponsUS_AT4_Fire"), NULL, LOAD_None, NULL);
	ChangeFireSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_ChangeFireMode.WeaponsOPFOR_AK47_ChangeFireMode"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/AT4/WeaponsUS_AT4_SelectNew.WeaponsUS_AT4_SelectNew"), NULL, LOAD_None, NULL);
	ZoomFireAnims						= { "zoomfirea", "ZoomFireB","ZoomFireC", "zoomfired", "zoomfiree" };
	ZoomIdleAnim						= { "zoomstilla","zoomstillb", "zoomstillc", "zoomstilld", "zoomstille" };
	bCanUse3dSights						= true;
	_cScopeClass						= AScopeW_BDM_Rocket::StaticClass();
	OwnerDamageType						= UProjectileDamageLargeArms::StaticClass();
	RadiusDamageType					= UBackBlastDamage::StaticClass();
	special_tag							= "_new";
	_FPMuzzleFlashClass					= ABDMMuzzleFlash_1P::StaticClass();
	SingleFiringRate					= 0.66;
//		\\Elevation =
//		\\AGP =
//		AGP_Inventory = 25
	AmmoName							= AAmmo_BDM_Rocket::StaticClass();
	PickupAmmoCount						= 1;
	bLongTargetTrace					= true;
	BackBlastRadius						= 990;
	BackBlastCone						= 0.85;
	BackBlastDamage						= 140;
	BackFireOffset						= FVector(-27, 0, 0);
	bHasBackBlast						= true;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/AT4/WeaponsUS_AT4_Down.WeaponsUS_AT4_Down"), NULL, LOAD_None, NULL);
	DisplayFOV							= 50;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 1.75;
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
	vZoomAnimOffset						= FVector(0, 0, 0);
	fZoomAnimFOV						= 30;
	fZoomAnimTime						= 0.16;
	WallTraceDist						= 77;
	weaponType							= EWeaponType::WEAPON_Rocket;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 1.5;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 1.5;
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
	PickupClass							= APickupW_BDM_Rocket::StaticClass();
	fWeight								= 5.4;
	PlayerViewOffset					= FVector(0, 0, 0);
	AttachmentClass						= { AAttachW_BDM_Rocket::StaticClass() };
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_bdm.hud_wpn_bdm"), NULL, LOAD_None, NULL);
	ItemName							= "BDM";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/BDM_1P.BDM_1P"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}


EUpperBodyAnim AWeapon_BDM_Rocket::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_BDM_LowerBDM;
}
EUpperBodyAnim AWeapon_BDM_Rocket::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_BDM_RaiseBDM;
}
EUpperBodyAnim AWeapon_BDM_Rocket::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_AT4_Ready;
}