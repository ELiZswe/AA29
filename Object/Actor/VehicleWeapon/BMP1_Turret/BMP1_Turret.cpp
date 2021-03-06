// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/BMP1_Turret/BMP1_Turret.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_T62_115MM_HE/Proj_BMP_Auto_Cannon/Proj_BMP_Auto_Cannon.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageBTR60127mm.h"

ABMP1_Turret::ABMP1_Turret()
{
	YawBone = "Yaw_Master_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -8000;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	RotationsPerSecond = 0.27;
	bInstantFire = true;
	FireInterval = 0.25;
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	//EffectEmitterClass = AM2MuzzleFlash::StaticClass();
	//FireSoundClass = Sound'S_AAO_Vehicles.BMP1.s_vehi_bmp1_cannon_single_fire';
	FireSoundVolume = 512;
	FireSoundRadius = 1024;
	//DamageType = AProjectileDamageBTR60127mm::StaticClass();
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	//ProjectileClass = AProj_BMP_Auto_Cannon::StaticClass();
	NewAimError = FVector(60, 80, 70);
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.BMP1_Turret';
	//CollisionRadius = 100;
	//CollisionHeight = 100;
}

/*
State InstantFireMode
{
	Function Fire(AController* C)
	{
		if (ShotCount > 10)
		{
			ShotCount=0;
			SetInstantFireMode(false);
			return;
		}
		else
		{
			ShotCount ++;
			Super::Fire(C);
		}
	}
}
*/

/*
State ProjectileFireMode
{
	Function Fire(AController* C)
	{
		if (ShotCount > 0)
		{
			ShotCount=0;
			SetInstantFireMode(true);
			return;
		}
		else
		{
			ShotCount ++;
			Super::Fire(C);
		}
	}
}
*/

/*

State InstantFireMode
{
	Function Fire(Controller C)
	{
		if (ShotCount > 10)
		{
			ShotCount = 0;
			SetInstantFireMode(false);
			return;
		}
		else
		{
			ShotCount++;
			Fire(C);
		}
	}
}
State ProjectileFireMode
{
	Function Fire(Controller C)
	{
		if (ShotCount > 0)
		{
			ShotCount = 0;
			SetInstantFireMode(true);
			return;
		}
		else
		{
			ShotCount++;
			Fire(C);
		}
	}
}
*/
