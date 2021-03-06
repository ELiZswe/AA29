// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_Tube/Pickup_Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

APickup_Javelin_Tube::APickup_Javelin_Tube()
{
	InventoryType			= AJavelin_Tube::StaticClass();
	PickupMessage			= FString("You found a Javelin tube.");
	EnemyPickupClass		= APickup_Javelin_Tube::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3P.Tube3P"), NULL, LOAD_None, NULL));
	LandedRotationOffset	= FRotator(0, 0, 0);
	bShouldFallOnSide		= false;
	DrawScale				= 1.13;
}

void APickup_Javelin_Tube::StaticPrecache(ALevelInfo* L)
{
	//L.AddPrecacheStaticMesh(StaticMesh'M_AAO_Armory.Javelin.Tube_OnBack');
	//L.AddPrecacheStaticMesh(StaticMesh'M_AAO_Armory.Javelin.Tube3PIH');
	//Super::StaticPrecache(L);
}
