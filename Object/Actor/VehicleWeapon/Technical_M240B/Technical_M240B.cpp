// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/Technical_M240B/Technical_M240B.h"

ATechnical_M240B::ATechnical_M240B()
{
	YawBone = "Yaw_bone";
	YawStartConstraint = -8191;
	YawEndConstraint = 8192;
	PitchBone = "Pitch_bone";
	PitchUpLimit = 5789;
	PitchDownLimit = -728;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	RotationsPerSecond = 0.18;
	bInstantFire = true;
	FireInterval = 0.1;
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamageM240B762mm';
	DamageMin = 75;
	DamageMax = 75;
	TraceRange = 16000;
	ShakeRotMag = FVector(250, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.1;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M240B';
}