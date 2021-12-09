// All the original content belonged to the US Army


#include "PickupT_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"

APickupT_M83_Smoke::APickupT_M83_Smoke()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m83_smoke_thrown_3p.m-m83_smoke_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_M83_Smoke::StaticClass();
	PickupMessage		= FString("You found an M83 Smoke Grenade.");
	EnemyPickupClass	= APickupT_M83_Smoke::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m83_smoke_3p.m-m83_smoke_3p"), NULL, LOAD_None, NULL));
	PrePivot			= FVector(0, 0, 3);
}