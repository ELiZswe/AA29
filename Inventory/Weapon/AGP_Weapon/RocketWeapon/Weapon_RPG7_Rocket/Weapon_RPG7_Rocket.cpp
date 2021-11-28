// All the original content belonged to the US Army


#include "Weapon_RPG7_Rocket.h"
#include "AA29/BaseScope/ScopeW_RPG7_Rocket.h"
#include "AA29/BaseAmmoRound/AmmoRound_RPG7_Rocket.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_RPG7_PG7B/Ammo_RPG7_PG7B.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_RPG7_Rocket/PickupW_RPG7_Rocket.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_RPG7_Rocket.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/BackBlastDamage/BackBlastDamage.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/RPG7MuzzleFlash_1P/RPG7MuzzleFlash_1P.h"
AWeapon_RPG7_Rocket::AWeapon_RPG7_Rocket()
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
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_Fire.WeaponsOPFOR_RPG7_Fire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_Fire.WeaponsOPFOR_RPG7_Fire"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_Reload.WeaponsOPFOR_RPG7_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_SelectLoad.WeaponsOPFOR_RPG7_SelectLoad"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_SelectNew.WeaponsOPFOR_RPG7_SelectNew"), NULL, LOAD_None, NULL);
	ZoomFireAnims						= { "zoomfirea","ZoomFireB","ZoomFireC","zoomfired","zoomfiree" };
	ZoomIdleAnim						= { "zoomstilla","zoomstillb","zoomstillc","zoomstilld","zoomstille" };
	bCanUse3dSights						= true;
	_cScopeClass						= AScopeW_RPG7_Rocket::StaticClass();
	OwnerDamageType						= UProjectileDamageLargeArms::StaticClass();
	RadiusDamageType					= UBackBlastDamage::StaticClass();
	special_tag							= "_new";
	_FPMuzzleFlashClass					= ARPG7MuzzleFlash_1P::StaticClass();
	AmmoRoundClass						= AAmmoRound_RPG7_Rocket::StaticClass();
	NumAmmoRounds						= 1;
	bWeaponIsOpFor						= true;
	SingleFiringRate   = 0.68;
//		\\Elevation =
//		\\AGP =
//		AGP_Inventory = 20
	AmmoName							= AAmmo_RPG7_PG7B::StaticClass();
	PickupAmmoCount						= 1;
	BackBlastRadius						= 650;
	BackBlastCone						= 0.85;
	BackBlastDamage						= 125;
	BackFireOffset						= FVector(-27, 0, 0);
	bHasBackBlast						= true;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPG7/WeaponsOPFOR_RPG7_Select.WeaponsOPFOR_RPG7_Select"), NULL, LOAD_None, NULL);
	DisplayFOV							= 40;
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
	fZoomAnimFOV						= 25;
	fZoomAnimTime						= 0.16;
	WallTraceDist						= 77;
	weaponType							= EWeaponType::WEAPON_Rocket;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 1.75;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 1.75;
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
	PickupClass							= APickupW_RPG7_Rocket::StaticClass();
	fWeight								= 5.4;
	PlayerViewOffset					= FVector(0, 0, 0);
	AttachmentClass						= { AAttachW_RPG7_Rocket::StaticClass() };
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_rpg7.hud_wpn_rpg7"), NULL, LOAD_None, NULL);
	ItemName							= "RPG7";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/RPG7_1P.RPG7_1P"), NULL, LOAD_None, NULL);
}

EUpperBodyAnim AWeapon_RPG7_Rocket::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_LowerRPG;
}
EUpperBodyAnim AWeapon_RPG7_Rocket::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_RaiseRPG;
}
EUpperBodyAnim AWeapon_RPG7_Rocket::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_Ready;
}
