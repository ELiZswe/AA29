// All the original content belonged to the US Army


#include "Weapon_RPK_SAW.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_100_Drum/Ammo_762mm_100_Drum.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_RPK_SAW/PickupW_RPK_SAW.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_RPK_SAW/AttachW_RPK_SAW.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_RPK.h"

AWeapon_RPK_SAW::AWeapon_RPK_SAW()
{
	BaseRecoilModifier   = 0.15;
	ShotsForMaxRecoil    = 16;
	SingleFire           = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Indoorfire.WeaponsOPFOR_RPK_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire    = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Outdoorfire.WeaponsOPFOR_RPK_Outdoorfire"), NULL, LOAD_None, NULL);
	ReloadSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Reload.WeaponsOPFOR_RPK_Reload"), NULL, LOAD_None, NULL);
	ProneReloadSound     = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_Reload.WeaponsOPFOR_RPK_Supported_Reload"), NULL, LOAD_None, NULL);
	FixJamSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_FixJam.WeaponsOPFOR_RPK_FixJam"), NULL, LOAD_None, NULL);
	ProneFixJamSound     = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_FixJam.WeaponsOPFOR_RPK_Supported_FixJam"), NULL, LOAD_None, NULL);
	SupportingSound      = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Supported.WeaponsUS_M249_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound    = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Unsupported.WeaponsUS_M249_Unsupported"), NULL, LOAD_None, NULL);
	ReloadFullSound      = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Reload.WeaponsOPFOR_RPK_Reload"), NULL, LOAD_None, NULL);
	ProneReloadFullSound = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_Reload.WeaponsOPFOR_RPK_Supported_Reload"), NULL, LOAD_None, NULL);
	fRuinedPct           = 0.25;
	OwnerDamageType      = UProjectileDamage762mm_RPK::StaticClass();
	_sMILESBoxScale      = FVector(5, 5, 5);
	_sBlankPlugScale     = FVector(5, 5, 5);
	fpWeaponThreatLevel  = 17;
	AmmoName             = AAmmo_762mm_100_Drum::StaticClass();
	PickupAmmoCount      = 75;
	FireAdjust           = 2.665;
	bCanSupport          = true;
	vZoomAnimOffset      = FVector(0, -17525, -1185);
	fZoomAnimFOV         = 15;
	weaponType           = EWeaponType::WEAPON_SAW;
	eROF                 = RateofFire::ROF_Auto;
	iMisFire             = -13536;
	PickupClass          = APickupW_RPK_SAW::StaticClass();
	fWeight              = 4.6;
	AttachmentClass      = { AAttachW_RPK_SAW::StaticClass() };
	IconMaterial         = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_rpk.hud_wpn_rpk"), NULL, LOAD_None, NULL);
	ItemName             = "RPK";
	Mesh                 = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/rpk_1P.rpk_1P"), NULL, LOAD_None, NULL);
}