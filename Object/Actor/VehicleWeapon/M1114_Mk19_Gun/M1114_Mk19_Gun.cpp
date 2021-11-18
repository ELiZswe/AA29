// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/M1114_Mk19_Gun/M1114_Mk19_Gun.h"

AM1114_Mk19_Gun::AM1114_Mk19_Gun()
{
	YawBone = "Yaw_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -8000;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	GunnerAttachmentBone = "player_attach_bone";
	RotationsPerSecond = 0.18;
	FireInterval = 0.2;
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamage556mm';
	DamageMin = 50;
	DamageMax = 150;
	//ProjectileClass = Class'AGP_Inventory.Proj_MK19Gren';
	ShakeRotMag = FVector(250, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.2;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.MK19';
}

/*
void AM1114_Mk19_Gun::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'humvee_body2');
	L.AddPrecacheMaterial(Texture'mk19_1');
	L.AddPrecacheMaterial(Texture'40mm_1');
	StaticPrecache(L);
}
*/

void AM1114_Mk19_Gun::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AM1114_Mk19_Gun::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'humvee_body2');
	//Level.AddPrecacheMaterial(Texture'mk19_1');
	//Level.AddPrecacheMaterial(Texture'40mm_1');
	Super::UpdatePrecacheMaterials();
}