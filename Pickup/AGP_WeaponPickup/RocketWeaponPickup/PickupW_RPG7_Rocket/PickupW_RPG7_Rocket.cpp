// All the original content belonged to the US Army


#include "PickupW_RPG7_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_RPG7_Rocket.h"
#include "AA29/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_AT4_Rocket/PickupW_AT4_Rocket.h"

APickupW_RPG7_Rocket::APickupW_RPG7_Rocket()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_RPG7_Rocket::StaticClass();
	PickupMessage			= FString("You found an RPG7.");
	EnemyPickupClass		= APickupW_AT4_Rocket::StaticClass();
	StaticMeshEmpty			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_up_3p.m2-wpn_rpg7_up_3p"), NULL, LOAD_None, NULL);
	StaticMeshFull			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_up_rocket_3p.m2-wpn_rpg7_up_rocket_3p"), NULL, LOAD_None, NULL);
	DrawType				= EDrawType::DT_StaticMesh;
	Rotation				= FRotator(0, 180, 0);
}

void APickupW_RPG7_Rocket::BeginPlay()
{
	Super::BeginPlay();
	//SetStaticMesh(StaticMeshFull);
}