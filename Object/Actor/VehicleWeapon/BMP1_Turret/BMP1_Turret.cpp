// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/BMP1_Turret/BMP1_Turret.h"

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
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//FireSoundClass = Sound'S_AAO_Vehicles.BMP1.s_vehi_bmp1_cannon_single_fire';
	FireSoundVolume = 512;
	FireSoundRadius = 1024;
	//DamageType = Class'AGP_Inventory.ProjectileDamageBTR60127mm';
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	//ProjectileClass = class'AGP_Vehicles.Proj_BMP_Auto_Cannon';
	NewAimError = FVector(60, 80, 70);
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.BMP1_Turret';
	//CollisionRadius = 100;
	//CollisionHeight = 100;
}

/*

State InstantFireMode
{
	Function Fire(Controller C)
	{
		if (ShotCount > 10)
		{
			ShotCount = 0;
			SetInstantFireMode(False);
			Return;
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
			SetInstantFireMode(True);
			Return;
		}
		else
		{
			ShotCount++;
			Fire(C);
		}
	}
}
*/
