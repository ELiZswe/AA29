// All the original content belonged to the US Army


#include "PickupW_M16A2_Rifle.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_AK47_Rifle/PickupW_AK47_Rifle.h"

APickupW_M16A2_Rifle::APickupW_M16A2_Rifle()
{
	InventoryType		= AWeapon_M16A2_Rifle::StaticClass();
	PickupMessage		= FString("You found an M16A2 Assault Rifle.");
	EnemyPickupClass	= APickupW_AK47_Rifle::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m16a2_3p.m-m16a2_3p"), NULL, LOAD_None, NULL));
}

/*
void StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Shader'skn_weap_m16a2');
	L.AddPrecacheMaterial(Shader'skn_weap_m16a2_mag');
	L.AddPrecacheMaterial(Shader'skn_wep_m16bullet');
	L.AddPrecacheMaterial(Texture'fx_flash_m16_base');
	StaticPrecache(L);
}
*/