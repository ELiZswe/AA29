// All the original content belonged to the US Army


#include "PickupAmmo_BS1_30mm_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_BS1_30mm_1_Gren/Ammo_BS1_30mm_1_Gren.h"

APickupAmmo_BS1_30mm_1_Gren::APickupAmmo_BS1_30mm_1_Gren()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_BS1_30mm_1_Gren::StaticClass();
	PickupMessage  = "You got an 30mm VOG-T Grenade.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_bs1_nade.wpn2_ammo1p_bs1_nade"), NULL, LOAD_None, NULL));
}