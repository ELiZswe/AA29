// All the original content belonged to the US Army


#include "PickupAmmo_RPG7_PG7b.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_RPG7_PG7B/Ammo_RPG7_PG7B.h"

APickupAmmo_RPG7_PG7b::APickupAmmo_RPG7_PG7b()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_RPG7_PG7B::StaticClass();
	PickupMessage  = "You found a PG7B round for the RPG7.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_projectile_003_3p.m2-wpn_rpg7_projectile_003_3p"), NULL, LOAD_None, NULL));
}