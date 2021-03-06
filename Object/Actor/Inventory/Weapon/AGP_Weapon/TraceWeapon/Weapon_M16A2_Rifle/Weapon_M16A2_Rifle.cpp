// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_M16A2_Rifle/AttachW_M16A2_Rifle.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M16A2_Rifle/PickupW_M16A2_Rifle.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M16A2MuzzleFlash_1P/M16A2MuzzleFlash_1P.h"

AWeapon_M16A2_Rifle::AWeapon_M16A2_Rifle()
{
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 0.85;
	_RecoilDirInfo.PitchMaxDeviation	= 0.6;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 0.6;
	_RecoilDirInfo.YawMaxDeviation		= 0.55;
	_RecoilDirInfo.YawFalloff			= 1;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	ShotsToStartRecoilBlend				= 1;
	SingleFire							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Indoorfire_Cue.WeaponsUS_M16A2_Indoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Outdoorfire_Cue.WeaponsUS_M16A2_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Reload_Cue.WeaponsUS_M16A2_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Reload_Cue.WeaponsUS_M16A2_Reload_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Fixjam_Cue.WeaponsUS_M16A2_Fixjam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Fixjam_Cue.WeaponsUS_M16A2_Fixjam_Cue'"), NULL, LOAD_None, NULL);
	ChangeFireSound						= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Changefiremode_Cue.WeaponsUS_M16A2_Changefiremode_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M16A2/WeaponsUS_M16A2_Selectnew_Cue.WeaponsUS_M16A2_Selectnew_Cue'"), NULL, LOAD_None, NULL);
	fRuinedPct							= 0.05;
	OwnerDamageType						= UProjectileDamage556mm::StaticClass();
	_FPMuzzleFlashClass					= AM16A2MuzzleFlash_1P::StaticClass();
	fpWeaponThreatLevel					= 10;
	AmmoName							= AAmmo_556mm_30_Mag::StaticClass();
	PickupAmmoCount						= 30;
	TraceDist							= 31500;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_Select.WeaponsUS_General_Select"), NULL, LOAD_None, NULL);
	DisplayFOV							= 47;
	FireAdjust							= 3.5;
	vZoomAnimOffset						= FVector(-4, -3525, -281);
	fZoomAnimFOV						= 25;
	WallTraceDist						= 65;
	weaponType							= EWeaponType::WEAPON_Rifle;
	_AccuracyDirInfo.MeanDirection		= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch				= 1;
	_AccuracyDirInfo.PitchMean			= 0;
	_AccuracyDirInfo.PitchMaxDeviation	= 2.25;
	_AccuracyDirInfo.PitchFalloff		= 1;
	_AccuracyDirInfo.bYaw				= 1;
	_AccuracyDirInfo.YawMean			= 0;
	_AccuracyDirInfo.YawMaxDeviation	= 2.25;
	_AccuracyDirInfo.YawFalloff			= 1;
	_AccuracyDirInfo.bRoll				= 0;
	_AccuracyDirInfo.RollMean			= 0;
	_AccuracyDirInfo.RollMaxDeviation	= 0;
	_AccuracyDirInfo.RollFalloff		= 0;
	_AccuracyDirInfo.SpeedMean			= 0;
	_AccuracyDirInfo.SpeedMaxDeviation	= 0;
	_AccuracyDirInfo.SpeedFalloff		= 0;
	_AccuracyDirInfo.Base				= FRotator(0, 0, 0);
	iMisFire							= 1500;
	PickupClass							= APickupW_M16A2_Rifle::StaticClass();
	fWeight								= 3.4;
	PlayerViewOffset					= FVector(10, 0, -615);
	AttachmentClass						= { AAttachW_M16A2_Rifle::StaticClass() };
	IconMaterial						= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_m16a2_Mat.hud_wpn_m16a2_Mat'"), NULL, LOAD_None, NULL);
	ItemName							= "M16A2";
	Mesh								= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m16a2_1P.m16a2_1P'"), NULL, LOAD_None, NULL);
	DrawScale							= 1;
}

void AWeapon_M16A2_Rifle::BeginPlay()
{
	Super::BeginPlay();
}

void AWeapon_M16A2_Rifle::DoChangeFireMode()
{
	switch (eROF) 
	{
	case ERateofFire::ROF_Single:
		eROF = ERateofFire::ROF_Burst;
		break;
	case ERateofFire::ROF_Burst:
		eROF = ERateofFire::ROF_Single;
		break;
	default:
		// note, if it's not burst or single, here's our chance to catch it!
		eROF = ERateofFire::ROF_Single;
		break;
	}
}
void AWeapon_M16A2_Rifle::PlayIdleAnim()
{
	if (eROF== ERateofFire::ROF_Burst)
	{
		//RunAnimation('Still2FM', 1, 0.05, true);
	}
	else
	{
		//PlayIdleAnim();
	}
}

