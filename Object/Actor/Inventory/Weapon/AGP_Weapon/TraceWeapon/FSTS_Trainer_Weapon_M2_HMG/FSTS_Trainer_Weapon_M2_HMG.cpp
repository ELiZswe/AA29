// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/FSTS_Trainer_Weapon_M2_HMG/FSTS_Trainer_Weapon_M2_HMG.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M2_HMG/PickupW_FSTS_Trainer_M2_HMG.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M4A1_Rifle_Mod/AttachW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

AFSTS_Trainer_Weapon_M2_HMG::AFSTS_Trainer_Weapon_M2_HMG()
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
	SingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Indoorfire_Cue.WeaponsUS_M16A2_Indoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Outdoorfire_Cue.WeaponsUS_M16A2_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	SuppressedSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_IndoorFire_Cue.WeaponsUS_M4A1_Suppressed_IndoorFire_Cue'"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_OutdoorFire_Cue.WeaponsUS_M4A1_Suppressed_OutdoorFire_Cue'"), NULL, LOAD_None, NULL);
	AuxSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire_Cue.WeaponsUS_M203_Fire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty_Cue.WeaponsUS_M4A1_ReloadEmpty_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty_Cue.WeaponsUS_M4A1_ReloadEmpty_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam_Cue.WeaponsUS_M4A1_Fixjam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam_Cue.WeaponsUS_M4A1_Fixjam_Cue'"), NULL, LOAD_None, NULL);
	ChangeFireSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Changefiremode_Cue.WeaponsUS_M16A2_Changefiremode_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Selectnew_Cue.WeaponsUS_M4A1_Selectnew_Cue'"), NULL, LOAD_None, NULL);
	SupportingSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Supported_Cue.WeaponsUS_M4A1_Supported_Cue'"), NULL, LOAD_None, NULL);
	UnSupportingSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_UnSupported_Cue.WeaponsUS_M4A1_UnSupported_Cue'"), NULL, LOAD_None, NULL);
	ReloadFullSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull_Cue.WeaponsUS_M4A1_ReloadFull_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadFullSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull_Cue.WeaponsUS_M4A1_ReloadFull_Cue'"), NULL, LOAD_None, NULL);
	AltReloadSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload_Cue.WeaponsUS_M203_Reload_Cue'"), NULL, LOAD_None, NULL);
	SuppressorOnSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOn_Cue.WeaponsUS_M4A1_SuppressorOn_Cue'"), NULL, LOAD_None, NULL);
	SuppressorOffSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOff_Cue.WeaponsUS_M4A1_SuppressorOff_Cue'"), NULL, LOAD_None, NULL);
	ZoomFireAnims							= { "Fire","FireB" };
	SupportedZoomFireAnims					= { "Fire","FireB" };
	ReloadEmptyAnim							= "ReloadFull";
	ReloadFullAnim							= "ReloadFull";
	ProneReloadEmptyAnim					= "ReloadFull";
	ProneReloadFullAnim						= "ReloadFull";
	ZoomIdleAnim							= { "Idle" };
	SupportedZoomIdleAnim					= "Idle";
	bCanUse3dSights							= true;
	_FPMuzzleFlashClass						= AM16A2MuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashClass			= ASuppressorMuzzleFlash_1P::StaticClass();
	_FPSuppressedMuzzleFlashOffset.VOffset	= FVector(0,0,10);
	_FPSuppressedMuzzleFlashOffset.ROffset	= FRotator(0, 179.901123046875,0);
	_FPSuppressedMuzzleFlashOffset.nBone	= "Muzzle";
	NumAmmoRounds							= 2;
	AutoFiringRate							= 0.088;
	SingleFiringRate						= 0.1;
	AmmoName								= AAmmo_556mm_200_Belt::StaticClass();
	PickupAmmoCount							= 200;
	TraceDist								= 21000;
	SelectSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select_Cue.WeaponsUS_General_Select_Cue'"), NULL, LOAD_None, NULL);
	DisplayFOV								= 50;
	MuzzleScale								= 1;
	vZoomAnimOffset							= FVector(0, 0, 0);
	fZoomAnimFOV							= 25;
	WallTraceDist							= 55;
	eROF									= ERateofFire::ROF_Auto;
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
	bMisFire								= false;
	PickupClass								= APickupW_FSTS_Trainer_M2_HMG::StaticClass();
	PlayerViewOffset						= FVector(0, 0, 0);
	AttachmentClass							= { AAttachW_M4A1_Rifle_Mod::StaticClass() };
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m4a1_mod_Mat.hud_wpn_m4a1_mod_Mat'"), NULL, LOAD_None, NULL);
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M2_w-tripod.M2_w-tripod'"), NULL, LOAD_None, NULL);
}

void AFSTS_Trainer_Weapon_M2_HMG::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	GiveTo(Other, Pickup);
	_bActive = true;
	GotoState('Idle');
	bInZoom = true;
	bZoomDir = true;
	Instigator.SetZoomed(bInZoom);
	*/
}
