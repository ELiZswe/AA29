// All the original content belonged to the US Army


#include "PickupW_RPK_SAW.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_RPK_SAW/Weapon_RPK_SAW.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M249_SAW/PickupW_M249_SAW.h"

APickupW_RPK_SAW::APickupW_RPK_SAW()
{
	InventoryType     = AWeapon_RPK_SAW::StaticClass();
	PickupMessage     = FString("You found a RPK.");
	EnemyPickupClass  = APickupW_M249_SAW::StaticClass();
	DrawType          = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-rpk_3p.m-rpk_3p"), NULL, LOAD_None, NULL));
}