// All the original content belonged to the US Army


#include "PickupW_BDM_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_BDM_Rocket/Weapon_BDM_Rocket.h"
#include "AA29\Pickup\AGP_WeaponPickup\RocketWeaponPickup\PickupW_PG7VR_Rocket\PickupW_PG7VR_Rocket.h"

APickupW_BDM_Rocket::APickupW_BDM_Rocket()
{
	CollisionHeightDropped  = 4;
	InventoryType           = AWeapon_BDM_Rocket::StaticClass();
	PickupMessage           = FString("You found a BDM.");
	EnemyPickupClass        = APickupW_PG7VR_Rocket::StaticClass();
	StaticMeshEmpty         = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_3p_up_at4.wpn2_3p_up_at4"), NULL, LOAD_None, NULL);
	StaticMeshFull          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_3p_up_at4.wpn2_3p_up_at4"), NULL, LOAD_None, NULL);
	DrawType                = EDrawType::DT_StaticMesh;
	Rotation                = FRotator(0, 180, 0);
}

void APickupW_BDM_Rocket::BeginPlay()
{
	Super::BeginPlay();
	//SetStaticMesh(StaticMeshFull);
}