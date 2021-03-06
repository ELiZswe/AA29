// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M870_Shotgun/PickupW_M870_Shotgun.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M870_Shotgun/Weapon_M870_Shotgun.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

APickupW_M870_Shotgun::APickupW_M870_Shotgun()
{
	InventoryType		= AWeapon_M870_Shotgun::StaticClass();
	PickupMessage		= FString("You found an M870 Shotgun.");
	EnemyPickupClass	= APickupW_M870_Shotgun::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m870_shorty_3p.m870_shorty_3p"), NULL, LOAD_None, NULL));
}

void APickupW_M870_Shotgun::StaticPrecache(ALevelInfo* L)
{
	//L->AddPrecacheMaterial(Texture'skn2_weap_m870_shorty');
	//L->AddPrecacheMaterial(Texture'skn2_Weap_shotgun_shell');
	//Super::StaticPrecache(L);
}
