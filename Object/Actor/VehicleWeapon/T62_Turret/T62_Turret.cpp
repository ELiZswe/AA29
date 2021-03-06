// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/T62_Turret/T62_Turret.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_T62_115MM_HE/Proj_T62_115MM_HE.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/T62A_DestroyedTurret/T62A_DestroyedTurret.h"

AT62_Turret::AT62_Turret()
{
	YawBone = "Yaw_Master_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 3277;
	PitchDownLimit = -410;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	RotationsPerSecond = 0.16;
	FireInterval = 6;
	//DestroyedModelClass = AT62A_DestroyedTurret::StaticClass();
	//DestroyedWeaponStaticMesh = StaticMesh'M_AA2_Vehicles.T62.T_62_turret_Static_damage';
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	//EffectEmitterClass = AM2MuzzleFlash::StaticClass();
	//FireSoundClass = Sound'S_AAO_Vehicles.T62Tank.s_vehi_t62_cannon_single_fire';
	FireSoundVolume = 512;
	AmbientSoundScaling = 1.5;
	//RotatingSound = Sound'S_AAO_Vehicles.T62Tank.S_Vehi_T62_turret_rotate_2';
	//ProjectileClass = AProj_T62_115MM_HE::StaticClass();
	NewAimError = FVector(50, 50, 50);
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.T62_Turret';
	//CollisionRadius = 100;
	//CollisionHeight = 100;
}
