// All the original content belonged to the US Army


#include "PickupT_M14_Incendiary.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M14_Incendiary/PickupT_M14_Incendiary.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"

APickupT_M14_Incendiary::APickupT_M14_Incendiary()
{
	liveStaticMesh    = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_thrown_3p.wpn_m14th3_incen_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType     = AThrow_M14_Incendiary::StaticClass();
	PickupMessage     = FString("You found an M14 Incendiary Grenade.");
	EnemyPickupClass  = APickupT_M14_Incendiary::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_3p.wpn_m14th3_incen_3p"), NULL, LOAD_None, NULL));
	PrePivot          = FVector(0, 0, 3);
}