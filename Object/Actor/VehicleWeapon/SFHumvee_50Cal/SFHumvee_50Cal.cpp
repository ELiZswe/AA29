// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/SFHumvee_50Cal/SFHumvee_50Cal.h"

ASFHumvee_50Cal::ASFHumvee_50Cal()
{
	YawBone = "Yaw_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 7464;
	PitchDownLimit = -4187;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	GunnerAttachmentBone = "player_attach_bone";
	ShellEjectionBone = "emitter_Shells_bone";
	RotationsPerSecond = 0.18;
	bInstantFire = true;
	FireInterval = 0.1;
	//DestroyedModelClass = class'AGP_Vehicles.SFHumvee_DestroyedTurret';
	//DestroyedWeaponStaticMesh = StaticMesh'M_AA2_Vehicles.SF_Humvee.50_cal_damage';
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//TracerClass = Class'AGP.BaseTracer';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.stryker.WeaponsUS_Stryker_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamageUS50cal';
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	ShakeRotMag = FVector(175, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.1;
	//WeaponAimAnims(0) = "SF_Humvee_50Cal_Down_Up";
	//WeaponAimAnims(1) = "SF_Humvee_50Cal_Down_Up";
	numWeaponAimAnims = 1;
	PitchAnimOffset = 4187;
	PitchAnimScale = 11651;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.SFHumvee_50Cal'
}



/*
void ASFHumvee_50Cal::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'm2_3p');
	StaticPrecache(L);
}
*/

void ASFHumvee_50Cal::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ASFHumvee_50Cal::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'm2_3p');
	Super::UpdatePrecacheMaterials();
}