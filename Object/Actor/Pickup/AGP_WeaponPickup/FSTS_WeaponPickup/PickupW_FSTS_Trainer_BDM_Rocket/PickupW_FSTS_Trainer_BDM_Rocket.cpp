// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_BDM_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_BDM_Rocket/Weapon_BDM_Rocket.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_PG7VR_Rocket/PickupW_PG7VR_Rocket.h"

APickupW_FSTS_Trainer_BDM_Rocket::APickupW_FSTS_Trainer_BDM_Rocket()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_BDM_Rocket::StaticClass();
	PickupMessage			= FString("You found a BDM.");
	EnemyPickupClass		= APickupW_PG7VR_Rocket::StaticClass();
	StaticMeshEmpty			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/M141_BDM_9.M141_BDM_9"), NULL, LOAD_None, NULL);
	StaticMeshFull			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/M141_BDM_9.M141_BDM_9"), NULL, LOAD_None, NULL);
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/M141_BDM_9.M141_BDM_9"), NULL, LOAD_None, NULL));
	Rotation				= FRotator(0, 180, 0);
}