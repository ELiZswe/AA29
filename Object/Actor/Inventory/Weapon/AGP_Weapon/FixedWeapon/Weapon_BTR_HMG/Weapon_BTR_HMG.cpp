// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/Weapon_BTR_HMG/Weapon_BTR_HMG.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/FixedWeaponAttachment/AttachW_BTR_HMG/AttachW_BTR_HMG.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_200_Mag/Ammo_127mm_200_Mag.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
AWeapon_BTR_HMG::AWeapon_BTR_HMG()
{
	SingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Outdoorfire_Cue.WeaponsUS_Stryker_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Outdoorfire_Cue.WeaponsUS_Stryker_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Reload_Cue.WeaponsUS_Stryker_Reload_Cue'"), NULL, LOAD_None, NULL);
	OwnerDamageType		= UProjectileDamageLargeArms::StaticClass();
	_FPMuzzleFlashClass	= AAK47MuzzleFlash_1P::StaticClass();
	bWeaponIsOpFor		= true;
	AutoPendingShots	= 0;
	AmmoName           = AAmmo_127mm_200_Mag::StaticClass();
	PickupAmmoCount    = 200;
	FireAdjust         = 0.66;
	WallTraceDist      = 65;
	weaponType         = EWeaponType::WEAPON_HMG;
	eROF               = ERateofFire::ROF_Auto;
	AttachmentClass    = {AAttachW_BTR_HMG::StaticClass()};
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47_Mat.hud_wpn_ak47_Mat'"), NULL, LOAD_None, NULL);

}
