// All the original content belonged to the US Army


#include "Pickup_Javelin_Tube.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"

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