// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/M1114_50Cal/M1114_50Cal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageUS50cal.h"

AM1114_50Cal::AM1114_50Cal()
{
	YawBone = "Yaw_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -8000;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	GunnerAttachmentBone = "player_attach_bone";
	RotationsPerSecond = 0.18;
	bInstantFire = true;
	FireInterval = 0.1;
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	//EffectEmitterClass = AM2MuzzleFlash::StaticClass();
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = AProjectileDamageUS50cal::StaticClass();
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	ShakeRotMag = FVector(250, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.05;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M1114_50Cal';
}

/*
void AM1114_50Cal::StaticPrecache(LevelInfo L)
{
	L->AddPrecacheMaterial(Texture'm2_3p');
	StaticPrecache(L);
}
*/

void AM1114_50Cal::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1114_50Cal::UpdatePrecacheMaterials()
{
	//LeveL->AddPrecacheMaterial(Texture'm2_3p');
	Super::UpdatePrecacheMaterials();
}
