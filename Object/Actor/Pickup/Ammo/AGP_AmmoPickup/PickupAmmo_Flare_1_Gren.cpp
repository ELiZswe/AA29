// All the original content belonged to the US Army


#include "PickupAmmo_Flare_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Flare_1_Gren/Ammo_Flare_1_Gren.h"

APickupAmmo_Flare_1_Gren::APickupAmmo_Flare_1_Gren()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_Flare_1_Gren::StaticClass();
	PickupMessage  = "You got a flare Grenade.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203_pickup.m-m203_pickup"), NULL, LOAD_None, NULL));
}