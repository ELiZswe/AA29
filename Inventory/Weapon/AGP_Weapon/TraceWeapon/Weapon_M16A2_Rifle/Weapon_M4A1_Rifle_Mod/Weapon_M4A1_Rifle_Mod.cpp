// All the original content belonged to the US Army


#include "Weapon_M4A1_Rifle_Mod.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M4A1_Rifle_Mod/AttachW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"
#include "AA29/BaseAmmoRound/AmmoRound_556_Bullet.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M4A1_Rifle_Mod/PickupW_M4A1_Rifle_Mod.h"

AWeapon_M4A1_Rifle_Mod::AWeapon_M4A1_Rifle_Mod()
{
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 0.9;
	_RecoilDirInfo.PitchMaxDeviation		= 0.65;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.6;
	_RecoilDirInfo.YawMaxDeviation			= 0.55;
	_RecoilDirInfo.YawFalloff				= 1;
	_RecoilDirInfo.bRoll					= 0;
	_RecoilDirInfo.RollMean					= 0;
	_RecoilDirInfo.RollMaxDeviation			= 0;
	_RecoilDirInfo.RollFalloff				= 0;
	_RecoilDirInfo.SpeedMean				= 0;
	_RecoilDirInfo.SpeedMaxDeviation		= 0;
	_RecoilDirInfo.SpeedFalloff				= 0;
	_RecoilDirInfo.Base						= FRotator(0, 0, 0);
	bUseAutoRecoil							= true;
	_AutoRecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AutoRecoilDirInfo.bPitch				= 1;
	_AutoRecoilDirInfo.PitchMean			= 1.2;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 0.9;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.6;
	_AutoRecoilDirInfo.YawMaxDeviation		= 0.7;
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
	SuppressedSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_IndoorFire.WeaponsUS_M4A1_Suppressed_IndoorFire"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_OutdoorFire.WeaponsUS_M4A1_Suppressed_OutdoorFire"), NULL, LOAD_None, NULL);
	AuxSingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Selectnew.WeaponsUS_M4A1_Selectnew"), NULL, LOAD_None, NULL);
	SupportingSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Supported.WeaponsUS_M4A1_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_UnSupported.WeaponsUS_M4A1_UnSupported"), NULL, LOAD_None, NULL);
	ReloadFullSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull.WeaponsUS_M4A1_ReloadFull"), NULL, LOAD_None, NULL);
	ProneReloadFullSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull.WeaponsUS_M4A1_ReloadFull"), NULL, LOAD_None, NULL);
	AltReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload.WeaponsUS_M203_Reload"), NULL, LOAD_None, NULL);
	SuppressorOnSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOn.WeaponsUS_M4A1_SuppressorOn"), NULL, LOAD_None, NULL);
	SuppressorOffSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOff.WeaponsUS_M4A1_SuppressorOff"), NULL, LOAD_None, NULL);
	ReloadEmptyAnim							= FName("ReloadEmpty");
	ReloadFullAnim							= FName("ReloadFull");
	ProneReloadEmptyAnim					= FName("SupportedReloadEmpty");
	ProneReloadFullAnim						= FName("SupportedReloadFull");
	bCanUse3dSights							= true;
		//_cScopeClass = class'None'
	_cScopeClass							= NULL;
	special_tag								= "_new";
	_FPSuppressedMuzzleFlashClass			= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashOffset.VOffset	= FVector(0,0,10);
	_FPSuppressedMuzzleFlashOffset.ROffset	= FRotator(0, 179.901123046875,0);
	_FPSuppressedMuzzleFlashOffset.nBone	= "Muzzle";
	AmmoRoundClass							= AAmmoRound_556_Bullet::StaticClass();
	NumAmmoRounds							= 2;
	WM_Default								= { "AGP_Inventory.WeaponMod_Ironsight", "AGP_Inventory.WeaponMod_Heatshield", "AGP_Inventory.WeaponMod_Heatshield", "AGP_Inventory.WeaponMod_Heatshield",  "AGP_Inventory.WeaponMod_Heatshield", "AGP_Inventory.WeaponMod_Virtual_Cone_Suppressor" };
		//LegalModList =
		//StaticMesh = 0.088;
	SingleFiringRate						= 0.1;
	WeaponImage								= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_main1a.m4mod_main1a"), NULL, LOAD_None, NULL);
	fpWeaponThreatLevel						= 14;
	TraceDist								= 21000;
	DisplayFOV								= 50;
	MuzzleScale								= 1;
	FireAdjust								= 1;
	vZoomAnimOffset							= FVector(-10, -4185, 12);
	WallTraceDist							= 55;
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
	PickupClass								= APickupW_M4A1_Rifle_Mod::StaticClass();
	PlayerViewOffset						= FVector(0, -1, -1);
	AttachmentClass							= { AAttachW_M4A1_Rifle_Mod::StaticClass() };
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m4a1_mod.hud_wpn_m4a1_mod"), NULL, LOAD_None, NULL);
	ItemName								= FString("M4A1");
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m4a1_20_1P.m4a1_20_1P"), NULL, LOAD_None, NULL);
}




void AWeapon_M4A1_Rifle_Mod::SetClipCount(uint8 clip, int32 Count, bool bAuxAmmo)
{
	/*
	if (bAuxAmmo || GetCurrentAmmoType() == AuxAmmoType && Count == 0)
	{
		_AuxAmmoClips[clip] = Count;
	}
	else
	{
		_AmmoClips[clip] = Count;
	}
	*/
}
void AWeapon_M4A1_Rifle_Mod::DoChangeFireMode()
{
	switch (eROF)
	{
	case RateofFire::ROF_Single:
		eROF = RateofFire::ROF_Auto;
		break;
	case RateofFire::ROF_Auto:
		eROF = RateofFire::ROF_Single;
		break;
	default:
		eROF = RateofFire::ROF_Single;		
		break;
	}
}
bool AWeapon_M4A1_Rifle_Mod::ShouldDoDelayedEject()
{
	return eROF == RateofFire::ROF_SingleGren;
}
void AWeapon_M4A1_Rifle_Mod::DiscardShell()
{
	/*
	FlashCount = 255;
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).FiringMode = 'ROF_SingleGren';
		BaseWeaponAttachment(ThirdPersonActor).FlashCount = FlashCount;
		BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
	}
	*/
}


