// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/BTR60_Turret/BTR60_Turret.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/BTR60_DestroyedTurret/BTR60_DestroyedTurret.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseTracer/GreenTracer.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageBTR60127mm.h"

ABTR60_Turret::ABTR60_Turret()
{
	YawBone = "Yaw_Master_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -10;
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
	//Mesh = SkeletalMesh'A_AGP_Vehicles.BTR60_Turret';
}
