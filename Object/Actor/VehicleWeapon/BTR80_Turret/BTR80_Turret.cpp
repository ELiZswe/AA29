// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/BTR80_Turret/BTR80_Turret.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/BTR60_DestroyedTurret/BTR60_DestroyedTurret.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseTracer/GreenTracer.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageBTR60127mm.h"

ABTR80_Turret::ABTR80_Turret()
{
	YawBone = "Yaw_Master_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -1820;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	RotationsPerSecond = 0.25;
	bInstantFire = true;
	Spread = 350;
	FireInterval = 0.2;
	//DestroyedModelClass = ABTR60_DestroyedTurret::StaticClass();
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	//EffectEmitterClass = AM2MuzzleFlash::StaticClass();
	//TracerClass = AGreenTracer::StaticClass();
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = AProjectileDamageBTR60127mm::StaticClass();
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	//	\\AIInfo = ;
	WeaponBoneHack = true;
	//Mesh = SkeletalMesh'A_AAO_Vehicles.BTR80_Turret';
}

void ABTR80_Turret::InitEffects()
{
	/*
	if (GetWorld()->GetNetMode() == 1)
	{
		return;
	}
	if (FlashEmitterClass != nullptr && FlashEmitter == nullptr || FlashEmitter.bDeleteMe)
	{
		FlashEmitter = Spawn(FlashEmitterClass, this);
		if (FlashEmitter != nullptr)
		{
			FlashEmitter.SetDrawScale(DrawScale);
			if (WeaponFireAttachmentBone == "None")
			{
				FlashEmitter.SetBase(GetOwner());
			}
			else
			{
				AttachToBone(FlashEmitter, WeaponFireAttachmentBone);
				FlashEmitter.SetRelativeRotation(FRotator(0 0 0));
			}
		}
	}
	if (ShellEjectionEmitterClass != nullptr && ShellEjectionEmitter == nullptr || ShellEjectionEmitter.bDeleteMe && ShellEjectionBone != "None")
	{
		ShellEjectionEmitter = Spawn(ShellEjectionEmitterClass, this);
		ShellEjectionEmitter.Initialize(ShellEjectionRandomizer, Shell1p, shell3p);
		ShellEjectionEmitter.SetLocation(Self.Location + FVector(0 0 30));
		AttachToBone(ShellEjectionEmitter, ShellEjectionBone);
	}
	*/
}
