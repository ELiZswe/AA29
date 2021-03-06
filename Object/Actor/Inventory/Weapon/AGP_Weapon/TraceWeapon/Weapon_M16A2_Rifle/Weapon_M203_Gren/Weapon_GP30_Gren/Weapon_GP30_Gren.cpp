// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_GP30_Gren/Weapon_GP30_Gren.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_AK74su_Rifle/ScopeW_AK74su_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_30_Mag/Ammo_762mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_30mm_1_Gren/Ammo_30mm_1_Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_GP30_Gren/PickupW_GP30_Gren.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_GP30_Gren/AttachW_GP30_Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/AK47MuzzleFlash_1P/AK47MuzzleFlash_1P.h"

AWeapon_GP30_Gren::AWeapon_GP30_Gren()
{
	_RecoilDirInfo.MeanDirection			= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch					= 1;
	_RecoilDirInfo.PitchMean				= 1.3;
	_RecoilDirInfo.PitchMaxDeviation		= 0.8;
	_RecoilDirInfo.PitchFalloff				= 1;
	_RecoilDirInfo.bYaw						= 1;
	_RecoilDirInfo.YawMean					= 0.7;
	_RecoilDirInfo.YawMaxDeviation			= 0.8;
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
	_AutoRecoilDirInfo.PitchMean			= 1.7;
	_AutoRecoilDirInfo.PitchMaxDeviation	= 1;
	_AutoRecoilDirInfo.PitchFalloff			= 1;
	_AutoRecoilDirInfo.bYaw					= 1;
	_AutoRecoilDirInfo.YawMean				= 0.8;
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
	ShotsForMaxRecoil						= 10;
	SingleFire								= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Indoorfire_Cue.WeaponsOPFOR_AK47_Indoorfire_Cue'"), NULL, LOAD_None, NULL);
	OutdoorSingleFire						= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Outdoorfire_Cue.WeaponsOPFOR_AK47_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	AuxSingleFire							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/GP30/WeaponsOPFOR_GP30_Fire_Cue.WeaponsOPFOR_GP30_Fire_Cue'"), NULL, LOAD_None, NULL);
	AuxOutdoorSingleFire					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/GP30/WeaponsOPFOR_GP30_Fire_Cue.WeaponsOPFOR_GP30_Fire_Cue'"), NULL, LOAD_None, NULL);
	ReloadSound								= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload_Cue.WeaponsOPFOR_AK47_Reload_Cue'"), NULL, LOAD_None, NULL);
	ProneReloadSound						= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Reload_Cue.WeaponsOPFOR_AK47_Reload_Cue'"), NULL, LOAD_None, NULL);
	FixJamSound								= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam_Cue.WeaponsOPFOR_AK47_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ProneFixJamSound						= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_FixJam_Cue.WeaponsOPFOR_AK47_FixJam_Cue'"), NULL, LOAD_None, NULL);
	ChangeFireSound							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_ChangeFireMode_Cue.WeaponsOPFOR_AK47_ChangeFireMode_Cue'"), NULL, LOAD_None, NULL);
	SelectChargeSound						= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_SelectNew_Cue.WeaponsOPFOR_AK47_SelectNew_Cue'"), NULL, LOAD_None, NULL);
	AltReloadSound							= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/GP30/WeaponsOPFOR_GP30_Reload_Cue.WeaponsOPFOR_GP30_Reload_Cue'"), NULL, LOAD_None, NULL);
	_cScopeClass							= AScopeW_AK74su_Rifle::StaticClass();
	fRuinedPct								= 0;
	OwnerDamageType							= UProjectileDamage762mm::StaticClass();
	_FPMuzzleFlashClass						= AAK47MuzzleFlash_1P::StaticClass();
	_FPAuxMuzzleFlashOffset.VOffset			= FVector(0, 0, 0);
	_FPAuxMuzzleFlashOffset.ROffset			= FRotator(0, 179.901123046875, 0);
	_FPAuxMuzzleFlashOffset.nBone			= "Muzzle";
	AuxFireMesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/gp30G_1P.gp30G_1P"), NULL, LOAD_None, NULL);
	bWeaponIsOpFor							= true;
	AmmoName								= AAmmo_762mm_30_Mag::StaticClass();
	SelectSound								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/AK47/WeaponsOPFOR_AK47_Down.WeaponsOPFOR_AK47_Down"), NULL, LOAD_None, NULL);
	FireAdjust								= 2.5;
	vZoomAnimOffset							= FVector(-4, -35, -24);
	fZoomAnimFOV							= 10;
	AuxAmmoName								= AAmmo_30mm_1_Gren::StaticClass();
	_AccuracyDirInfo.MeanDirection			= FVector(0, 0, 0);
	_AccuracyDirInfo.bPitch					= 1;
	_AccuracyDirInfo.PitchMean				= 0;
	_AccuracyDirInfo.PitchMaxDeviation		= 2.55;
	_AccuracyDirInfo.PitchFalloff			= 1;
	_AccuracyDirInfo.bYaw					= 1;
	_AccuracyDirInfo.YawMean				= 0;
	_AccuracyDirInfo.YawMaxDeviation		= 2.55;
	_AccuracyDirInfo.YawFalloff				= 1;
	_AccuracyDirInfo.bRoll					= 0;
	_AccuracyDirInfo.RollMean				= 0;
	_AccuracyDirInfo.RollMaxDeviation		= 0;
	_AccuracyDirInfo.RollFalloff			= 0;
	_AccuracyDirInfo.SpeedMean				= 0;
	_AccuracyDirInfo.SpeedMaxDeviation		= 0;
	_AccuracyDirInfo.SpeedFalloff			= 0;
	_AccuracyDirInfo.Base					= FRotator(0, 0, 0);
	iMisFire								= 4000;
	PickupClass								= APickupW_GP30_Gren::StaticClass();
	fWeight									= 5.69;
	AttachmentClass							= { AAttachW_GP30_Gren::StaticClass() };
	IconMaterial							= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47_GP-30_40mm_Mat.hud_wpn_ak47_GP-30_40mm_Mat'"), NULL, LOAD_None, NULL);
	ItemName								= "AK74-GP30";
	Mesh									= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsOPFOR/gp30_1P.gp30_1P'"), NULL, LOAD_None, NULL);
}

void AWeapon_GP30_Gren::DoChangeFireMode()
{
	if (bSwitchToGrenade)
	{
		LastROF = eROF;
		eROF = ERateofFire::ROF_SingleGren;
	}
	else
	{
		switch(eROF)
		{
			case ERateofFire::ROF_Single:
				eROF = ERateofFire::ROF_Auto;
				break;
			case ERateofFire::ROF_Auto:
				eROF = ERateofFire::ROF_Single;
				break;
			case ERateofFire::ROF_SingleGren:
				eROF = LastROF;
				break;
			default:
				eROF = ERateofFire::ROF_Single;
				break;
		}
	}
}
void AWeapon_GP30_Gren::SelectGrenadeMode()
{
	/*
	LinkMesh(AuxFireMesh);
	MFTexture = MuzzleFlashTextureGrenade;
	FireAdjust = 2;
	bMisFire = false;
	if (_FPMuzzleFlashEmitter != nullptr)
	{
		Instigator.AttachToBoneOffset(_FPMuzzleFlashEmitter, _FPAuxMuzzleFlashOffset);
	}
	*/
}
void AWeapon_GP30_Gren::SelectNormalMode()
{
	/*
	LinkMesh(Default.Mesh);
	MFTexture = MuzzleFlashTextureNormal;
	FireAdjust = Default.FireAdjust;
	FireOffset = Default.FireOffset;
	bMisFire = true;
	if (_FPMuzzleFlashEmitter != nullptr)
	{
		Instigator.AttachToBoneOffset(_FPMuzzleFlashEmitter, _FPMuzzleFlashOffset);
	}
	*/
}

