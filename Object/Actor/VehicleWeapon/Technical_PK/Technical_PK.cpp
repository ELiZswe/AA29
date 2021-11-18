// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/Technical_PK/Technical_PK.h"

ATechnical_PK::ATechnical_PK()
{
	YawBone = "Yaw_bone";
	YawStartConstraint = -9102;
	YawEndConstraint = 9102;
	PitchBone = "Pitch_bone";
	PitchUpLimit = 5789;
	PitchDownLimit = -728;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	ShellEjectionBone = "emitter_shells";
	RotationsPerSecond = 0.4;
	bInstantFire = true;
	FireInterval = 0.1;
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//TracerClass = Class'AGP.GreenTracer';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M16A2.WeaponsUS_M16A2_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamagePKS762mm';
	DamageMin = 50;
	DamageMax = 50;
	ShakeRotMag = FVector(150, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.1;
	//WeaponAimAnims(0) = "PKS_Down_2_UP_Left";
	//WeaponAimAnims(1) = "PKS_Down_2_UP_MID_Left";
	//WeaponAimAnims(2) = "PKS_Down_2_UP_middle";
	//WeaponAimAnims(3) = "PKS_Down_2_UP_MID_right";
	//WeaponAimAnims(4) = "PKS_Down_2_UP_right";
	numWeaponAimAnims = 5;
	PitchAnimOffset = 2530;
	PitchAnimScale = 6517;
	YawAnimOffset = 9102;
	YawAnimScale = 18204;
	//	\\AIInfo =;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.PKS';
}


/*
void ATechnical_PK::StaticPrecache(LevelInfo L)
{
	//L.AddPrecacheMaterial(Texture'PSK');
	//L.AddPrecacheMaterial(Texture'PSK_ammo');
	//L.AddPrecacheMaterial(Texture'DS1_PSK');
	Super::StaticPrecache(L);
}
*/

void ATechnical_PK::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ATechnical_PK::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'PSK');
	//Level.AddPrecacheMaterial(Texture'PSK_ammo');
	//Level.AddPrecacheMaterial(Texture'DS1_PSK');
	Super::UpdatePrecacheMaterials();
}