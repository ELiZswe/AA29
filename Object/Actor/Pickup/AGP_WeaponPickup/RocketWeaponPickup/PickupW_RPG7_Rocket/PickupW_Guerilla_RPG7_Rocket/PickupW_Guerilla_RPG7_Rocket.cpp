// All the original content belonged to the US Army


#include "PickupW_Guerilla_RPG7_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_Guerilla_RPG7_Rocket/Weapon_Guerilla_RPG7_Rocket.h"

APickupW_Guerilla_RPG7_Rocket::APickupW_Guerilla_RPG7_Rocket()
{
	InventoryType		= AWeapon_Guerilla_RPG7_Rocket::StaticClass();
	EnemyPickupClass	= APickupW_Guerilla_RPG7_Rocket::StaticClass();
}

void APickupW_Guerilla_RPG7_Rocket::BeginPlay()
{
	Super::BeginPlay();
	//SetStaticMesh(StaticMeshFull);
}