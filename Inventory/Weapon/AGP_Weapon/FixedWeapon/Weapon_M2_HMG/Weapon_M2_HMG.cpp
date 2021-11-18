// All the original content belonged to the US Army


#include "Weapon_M2_HMG.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_200_Mag/Ammo_127mm_200_Mag.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/FixedWeaponAttachment/AttachW_M2_HMG/AttachW_M2_HMG.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
AWeapon_M2_HMG::AWeapon_M2_HMG()
{
	tTurretOverlay			= LoadObject<class UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/hud_overlay_strykergun_FB_Mat.hud_overlay_strykergun_FB_Mat"), NULL, LOAD_None, NULL);
	SingleFire				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Outdoorfire.WeaponsUS_Stryker_Outdoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire		= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Outdoorfire.WeaponsUS_Stryker_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/stryker/WeaponsUS_Stryker_Reload.WeaponsUS_Stryker_Reload"), NULL, LOAD_None, NULL);
	OwnerDamageType			= UProjectileDamageLargeArms::StaticClass();
	_FPMuzzleFlashClass		= AAK47MuzzleFlash_1P::StaticClass();
	AutoPendingShots		= 0;
	fpWeaponThreatLevel		= 15;
	AmmoName				= AAmmo_127mm_200_Mag::StaticClass();
	PickupAmmoCount			= 200;
	FireAdjust				= 0.73;
	WallTraceDist			= 65;
	weaponType				= EWeaponType::WEAPON_HMG;
	eROF					= RateofFire::ROF_Auto;
	AttachmentClass			= {AAttachW_M2_HMG::StaticClass() };
	IconMaterial			= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47.hud_wpn_ak47"), NULL, LOAD_None, NULL);
}