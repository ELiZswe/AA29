// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_RPK_SAW/Weapon_RPK_SAW.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_100_Drum/Ammo_762mm_100_Drum.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_RPK_SAW/PickupW_RPK_SAW.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_RPK_SAW/AttachW_RPK_SAW.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_RPK.h"

AWeapon_RPK_SAW::AWeapon_RPK_SAW()
{
	BaseRecoilModifier		= 0.15;
	ShotsForMaxRecoil		= 16;
	SingleFire				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Indoorfire_Cue.WeaponsOPFOR_RPK_Indoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Outdoorfire_Cue.WeaponsOPFOR_RPK_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Reload_Cue.WeaponsOPFOR_RPK_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_Reload_Cue.WeaponsOPFOR_RPK_Supported_Reload_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_FixJam_Cue.WeaponsOPFOR_RPK_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_FixJam_Cue.WeaponsOPFOR_RPK_Supported_FixJam_Cue'"), NULL, LOAD_None, NULL);
	SupportingSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Supported_Cue.WeaponsUS_M249_Supported_Cue'"), NULL, LOAD_None, NULL);
	UnSupportingSound		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Unsupported_Cue.WeaponsUS_M249_Unsupported_Cue'"), NULL, LOAD_None, NULL);
	ReloadFullSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Reload_Cue.WeaponsOPFOR_RPK_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadFullSound	= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/RPK/WeaponsOPFOR_RPK_Supported_Reload_Cue.WeaponsOPFOR_RPK_Supported_Reload_Cue'"), NULL, LOAD_None, NULL);
	fRuinedPct				= 0.25;
	OwnerDamageType			= UProjectileDamage762mm_RPK::StaticClass();
	_sMILESBoxScale			= FVector(5, 5, 5);
	_sBlankPlugScale		= FVector(5, 5, 5);
	fpWeaponThreatLevel		= 17;
	AmmoName				= AAmmo_762mm_100_Drum::StaticClass();
	PickupAmmoCount			= 75;
	FireAdjust				= 2.665;
	bCanSupport				= true;
	vZoomAnimOffset			= FVector(0, -17525, -1185);
	fZoomAnimFOV			= 15;
	weaponType				= EWeaponType::WEAPON_SAW;
	eROF					= ERateofFire::ROF_Auto;
	iMisFire				= -13536;
	PickupClass				= APickupW_RPK_SAW::StaticClass();
	fWeight					= 4.6;
	AttachmentClass			= { AAttachW_RPK_SAW::StaticClass() };
	IconMaterial			= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_rpk_Mat.hud_wpn_rpk_Mat'"), NULL, LOAD_None, NULL);
	ItemName				= "RPK";
	Mesh					= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/rpk_1P.rpk_1P'"), NULL, LOAD_None, NULL);
}
