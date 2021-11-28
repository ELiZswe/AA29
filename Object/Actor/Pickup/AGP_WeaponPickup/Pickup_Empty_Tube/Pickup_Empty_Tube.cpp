// All the original content belonged to the US Army


#include "Pickup_Empty_Tube.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Empty_Tube/Javelin_Empty_Tube.h"

APickup_Empty_Tube::APickup_Empty_Tube()
{
	InventoryType			= AJavelin_Empty_Tube::StaticClass();
	PickupMessage			= "You found a Javelin.";
	EnemyPickupClass		= APickup_Empty_Tube::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PSpent.Tube3PSpent"), NULL, LOAD_None, NULL));
	LifeSpan				= 20;
	LandedRotationOffset	= FRotator(0, 0, 0);
	bShouldFallOnSide		= false;
	DrawScale				= 1.13;
}