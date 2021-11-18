// All the original content belonged to the US Army


#include "PickupAmmo_Incendiary_1_Gren.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_Incendiary_1_Gren/Ammo_Incendiary_1_Gren.h"

APickupAmmo_Incendiary_1_Gren::APickupAmmo_Incendiary_1_Gren()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_Incendiary_1_Gren::StaticClass();
	PickupMessage  = "You got an incendiary Grenade.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203_pickup.m-m203_pickup"), NULL, LOAD_None, NULL));
}