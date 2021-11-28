// All the original content belonged to the US Army


#include "FSTS_Trainer_Weapon_MK19_AGL.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_MK19_AGL/PickupW_FSTS_Trainer_MK19_AGL.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_MK19_Grenade/Ammo_MK19_Grenade.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"

AFSTS_Trainer_Weapon_MK19_AGL::AFSTS_Trainer_Weapon_MK19_AGL()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 0.7;
	_RecoilDirInfo.PitchMaxDeviation	= 0.6;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 0.5;
	_RecoilDirInfo.YawMaxDeviation		= 0.45;
	_RecoilDirInfo.YawFalloff			= 1;
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
	FireAnims							= { "Fire","Fire","Fire" };
	SupportedFireAnims					= { "Fire","Fire","Fire" };
	ZoomFireAnims						= { "Fire" };
	ProneReloadEmptyAnim				= "Reload";
	ProneReloadFullAnim					= "Reload";
	ZoomIdleAnim						= { "Idle" };
	bCanUse3dSights						= true;
	OwnerDamageType						= UProjectileDamageLargeArms::StaticClass();
	special_tag							= "_new";
	_FPMuzzleFlashClass					= AM16A2MuzzleFlash_1P::StaticClass();
	AutoFiringRate						= 0.333;
	SingleFiringRate					= 1;
	AmmoName							= AAmmo_MK19_Grenade::StaticClass();
	PickupAmmoCount						= 32;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/AT4/WeaponsUS_AT4_Down.WeaponsUS_AT4_Down"), NULL, LOAD_None, NULL);
	DisplayFOV							= 50;
	vZoomAnimOffset						= FVector(0, 0, 0);
	fZoomAnimFOV						= 30;
	fZoomAnimTime						= 0.16;
	WallTraceDist						= 77;
	weaponType							= EWeaponType::WEAPON_HMG;
	eROF								= RateofFire::ROF_Auto;
	_AccuracyDirInfo.MeanDirection		= FVector( 0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 2.4;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 2.4;
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
	PickupClass							= APickupW_FSTS_Trainer_MK19_AGL::StaticClass();
	fWeight								= 5.4;
	PlayerViewOffset					= FVector(5, 0, -7);
	ItemName							= "MK-19";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/MK19_w-tripod.MK19_w-tripod"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}


void AFSTS_Trainer_Weapon_MK19_AGL::GiveTo(APawn* Other, APickup* Pickup)
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