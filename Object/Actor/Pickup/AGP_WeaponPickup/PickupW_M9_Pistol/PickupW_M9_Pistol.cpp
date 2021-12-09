// All the original content belonged to the US Army


#include "PickupW_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"

APickupW_M9_Pistol::APickupW_M9_Pistol()
{
	InventoryType		= AWeapon_M9_Pistol::StaticClass();
	PickupMessage		= FString("You found an M9 Pistol.");
	EnemyPickupClass	= APickupW_M9_Pistol::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_m9_beretta_3p.wpn2_m9_beretta_3p"), NULL, LOAD_None, NULL));
}