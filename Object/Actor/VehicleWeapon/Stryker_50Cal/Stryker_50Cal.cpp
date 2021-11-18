// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/Stryker_50Cal/Stryker_50Cal.h"

AStryker_50Cal::AStryker_50Cal()
{
	YawBone = "Yaw";
	PitchBone = "Pitch";
	PitchUpLimit = 8000;
	PitchDownLimit = -8000;
	WeaponFireAttachmentBone = "Muzzle";
	RotationsPerSecond = 0.18;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.Stryker_50Cal';
}



/*
void AStryker_50Cal::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'm2_automated_olive_3p');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_m2_3p');
	L.AddPrecacheMaterial(Texture'skin_veh_stryker_m2_lens_3p');
	StaticPrecache(L);
}
*/

void AStryker_50Cal::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void AStryker_50Cal::UpdatePrecacheMaterials()
{
	//Level.AddPrecacheMaterial(Texture'm2_automated_olive_3p');
	//Level.AddPrecacheMaterial(Texture'skin_veh_stryker_m2_3p');
	//Level.AddPrecacheMaterial(Texture'skin_veh_stryker_m2_lens_3p');
	Super::UpdatePrecacheMaterials();
}