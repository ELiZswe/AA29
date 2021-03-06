// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_AK74su_Rifle/ScopeW_AK74su_Rifle.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_AK74su_Rifle/AttachW_AK74su_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_545mm_30_Mag/Ammo_545mm_30_Mag.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_545x39_Bullet.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_AK74su_Rifle/PickupW_AK74su_Rifle.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage545mm.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

AWeapon_AK74su_Rifle::AWeapon_AK74su_Rifle()
{
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 1.1;
	_RecoilDirInfo.PitchMaxDeviation		= 0.7;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.7;
	_RecoilDirInfo.YawMaxDeviation			= 0.7;
	_RecoilDirInfo.YawFalloff				= 1;
	_RecoilDirInfo.bRoll					= 0;
	_RecoilDirInfo.RollMean					= 0;
	_RecoilDirInfo.RollMaxDeviation			= 0;
	_RecoilDirInfo.RollFalloff				= 0;
	_RecoilDirInfo.SpeedMean				= 0;
	_RecoilDirInfo.SpeedMaxDeviation		= 0;
	_RecoilDirInfo.SpeedFalloff				= 0;
	_RecoilDirInfo.Base						= FRotator(0, 0, 0);
	_AutoRecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AutoRecoilDirInfo.bPitch				= 1;
	_AutoRecoilDirInfo.PitchMean			= 1.5;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 1;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.7;
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
	
	ShotsForMaxRecoil						= 15;
	SuppressedSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedOutdoorFire_Cue.WeaponsOPFOR_AKS74U_SuppressedOutdoorFire_Cue'"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedIndoor_Cue.WeaponsOPFOR_AKS74U_SuppressedIndoor_Cue'"), NULL, LOAD_None, NULL);
	AuxSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Fire_Cue.WeaponsOPFOR_BS1_Fire_Cue'"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Fire_Cue.WeaponsOPFOR_BS1_Fire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadEmpty_Cue.WeaponsOPFOR_AKS74U_ReloadEmpty_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadEmpty_Cue.WeaponsOPFOR_AKS74U_ReloadEmpty_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_FixJam_Cue.WeaponsOPFOR_AKS74U_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_FixJam_Cue.WeaponsOPFOR_AKS74U_FixJam_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SelectNew_Cue.WeaponsOPFOR_AKS74U_SelectNew_Cue'"), NULL, LOAD_None, NULL);
	ReloadFullSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_ReloadFull_Cue.WeaponsOPFOR_AKS74U_ReloadFull_Cue'"), NULL, LOAD_None, NULL);
	AltReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/BS1/WeaponsOPFOR_BS1_Reload_Cue.WeaponsOPFOR_BS1_Reload_Cue'"), NULL, LOAD_None, NULL);
	SuppressorOnSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AK74U_SuppressorOn_Cue.WeaponsOPFOR_AK74U_SuppressorOn_Cue'"), NULL, LOAD_None, NULL);
	SuppressorOffSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AK74U_SuppressorOff_Cue.WeaponsOPFOR_AK74U_SuppressorOff_Cue'"), NULL, LOAD_None, NULL);
	ReloadEmptyAnim							= "ReloadEmpty";
	ReloadFullAnim							= "ReloadFull";
	AuxZoomInAnim							= "ZoomStill";
	AuxZoomOutAnim							= "ZoomStill";
	bCanUse3dSights							= true;
	_cScopeClass							= AScopeW_AK74su_Rifle::StaticClass();
	OwnerDamageType							= UProjectileDamage545mm::StaticClass();
	special_tag								= "_new";
	_FPSuppressedMuzzleFlashClass			= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashOffset.VOffset	= FVector(0,0,10);
	_FPSuppressedMuzzleFlashOffset.ROffset	= FRotator(0, 179.901123046875,0);
	_FPSuppressedMuzzleFlashOffset.nBone	= "Muzzle";
	AmmoRoundClass							= AAmmoRound_545x39_Bullet::StaticClass();
	NumAmmoRounds							= 3;
	WM_Default								= { "AGP_Inventory.WeaponMod_AKs74u_Ironsight", "AGP_Inventory.WeaponMod_Virtual_Heatshield", "AGP_Inventory.WeaponMod_Virtual_Heatshield", "AGP_Inventory.WeaponMod_Virtual_Heatshield", "AGP_Inventory.WeaponMod_Virtual_Heatshield", "AGP_Inventory.WeaponMod_Cone_Suppressor" };
//		\\LegalModList =
//		StaticMesh = 0.1
	SingleFiringRate						= 0.1;
	fpWeaponThreatLevel						= 8;
	AmmoName								= AAmmo_545mm_30_Mag::StaticClass();
	MuzzleScale								= 1;
	FireAdjust								= 1;
	vZoomAnimOffset							= FVector(-10, -4291, 21325);
	fZoomAnimFOV							= 30;
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 2.7;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 2.7;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	
	PickupClass								= APickupW_AK74su_Rifle::StaticClass();
	fWeight									= 3.87;
	PlayerViewOffset						= FVector(0, 0, 0);
	AttachmentClass							= { AAttachW_AK74su_Rifle::StaticClass() };
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak74su_Mat.hud_wpn_ak74su_Mat'"), NULL, LOAD_None, NULL);
	ItemName = "AK-74su";
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/aks74u_1P.aks74u_1P'"), NULL, LOAD_None, NULL);
	DrawScale								= 1;
}

bool AWeapon_AK74su_Rifle::ShouldDoDelayedEject()
{
	return eROF == ERateofFire::ROF_SingleGren;
}
void AWeapon_AK74su_Rifle::DiscardShell()
{
	/*
	FlashCount = 255;
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).FiringMode = 'ROF_SingleGren';
		BaseWeaponAttachment(ThirdPersonActor).FlashCount = FlashCount;
		BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
	}
	*/
}
