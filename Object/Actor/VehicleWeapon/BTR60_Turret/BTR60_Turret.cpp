// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/BTR60_Turret/BTR60_Turret.h"

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
	//DestroyedModelClass = class'AGP_Vehicles.BTR60_DestroyedTurret';
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//TracerClass = Class'AGP.GreenTracer';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamageBTR60127mm';
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.BTR60_Turret';
}