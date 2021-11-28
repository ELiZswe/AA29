// All the original content belonged to the US Army


#include "PickupW_PG7VR_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_PG7VR_Rocket/Weapon_PG7VR_Rocket.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_BDM_Rocket/PickupW_BDM_Rocket.h"

APickupW_PG7VR_Rocket::APickupW_PG7VR_Rocket()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_PG7VR_Rocket::StaticClass();
	PickupMessage			= FString("You found an RPG7_PG7VR.");
	EnemyPickupClass		= APickupW_BDM_Rocket::StaticClass();
	StaticMeshEmpty			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_up_3p.m2-wpn_rpg7_up_3p"), NULL, LOAD_None, NULL);
	StaticMeshFull			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_pg7vr_up_rocket_3p.m2-wpn_rpg7_pg7vr_up_rocket_3p"), NULL, LOAD_None, NULL);
	DrawType				= EDrawType::DT_StaticMesh;
	Rotation				= FRotator(0, 180, 0);
}


void APickupW_PG7VR_Rocket::BeginPlay()
{
	Super::BeginPlay();
	//SetStaticMesh(StaticMeshFull);
}