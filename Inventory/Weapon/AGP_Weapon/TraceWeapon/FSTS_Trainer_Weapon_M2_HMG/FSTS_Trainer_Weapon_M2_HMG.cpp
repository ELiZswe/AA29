// All the original content belonged to the US Army


#include "FSTS_Trainer_Weapon_M2_HMG.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M2_HMG/PickupW_FSTS_Trainer_M2_HMG.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M4A1_Rifle_Mod/AttachW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash_1P/SuppressorMuzzleFlash_1P.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"


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
	SingleFire								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Indoorfire.WeaponsUS_M16A2_Indoorfire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Outdoorfire.WeaponsUS_M16A2_Outdoorfire"), NULL, LOAD_None, NULL);
	SuppressedSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_IndoorFire.WeaponsUS_M4A1_Suppressed_IndoorFire"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Suppressed_OutdoorFire.WeaponsUS_M4A1_Suppressed_OutdoorFire"), NULL, LOAD_None, NULL);
	AuxSingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Fire.WeaponsUS_M203_Fire"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadEmpty.WeaponsUS_M4A1_ReloadEmpty"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Fixjam.WeaponsUS_M4A1_Fixjam"), NULL, LOAD_None, NULL);
	ChangeFireSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Changefiremode.WeaponsUS_M16A2_Changefiremode"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Selectnew.WeaponsUS_M4A1_Selectnew"), NULL, LOAD_None, NULL);
	SupportingSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_Supported.WeaponsUS_M4A1_Supported"), NULL, LOAD_None, NULL);
	UnSupportingSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_UnSupported.WeaponsUS_M4A1_UnSupported"), NULL, LOAD_None, NULL);
	ReloadFullSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull.WeaponsUS_M4A1_ReloadFull"), NULL, LOAD_None, NULL);
	ProneReloadFullSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_ReloadFull.WeaponsUS_M4A1_ReloadFull"), NULL, LOAD_None, NULL);
	AltReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Reload.WeaponsUS_M203_Reload"), NULL, LOAD_None, NULL);
	SuppressorOnSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOn.WeaponsUS_M4A1_SuppressorOn"), NULL, LOAD_None, NULL);
	SuppressorOffSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/m4a1/WeaponsUS_M4A1_SuppressorOff.WeaponsUS_M4A1_SuppressorOff"), NULL, LOAD_None, NULL);
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
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	DisplayFOV								= 50;
	MuzzleScale								= 1;
	vZoomAnimOffset							= FVector(0, 0, 0);
	fZoomAnimFOV							= 25;
	WallTraceDist							= 55;
	eROF									= RateofFire::ROF_Auto;
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
	IconMaterial							= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m4a1_mod.hud_wpn_m4a1_mod"), NULL, LOAD_None, NULL);
	Mesh									= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M2_w-tripod.M2_w-tripod"), NULL, LOAD_None, NULL);
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