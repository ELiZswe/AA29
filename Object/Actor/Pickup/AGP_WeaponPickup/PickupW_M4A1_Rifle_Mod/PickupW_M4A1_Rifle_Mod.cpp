// All the original content belonged to the US Army


#include "PickupW_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_AK74su_Rifle/PickupW_AK74su_Rifle.h"

APickupW_M4A1_Rifle_Mod::APickupW_M4A1_Rifle_Mod()
{
	InventoryType		= AWeapon_M4A1_Rifle_Mod::StaticClass();
	PickupMessage		= FString("You found an M4A1 Assault Rifle.");
	EnemyPickupClass	= APickupW_AK74su_Rifle::StaticClass();
	VisibleSkeletalMesh->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m4a1_3P.m4a1_3P"), NULL, LOAD_None, NULL));
}

/*
void StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'skn2_weap_m4a1_sopmod');
	L.AddPrecacheMaterial(Texture'skn2_weap_m16magazine_30rnd');
	L.AddPrecacheMaterial(Shader'skn_wep_m16case');	
	L.AddPrecacheMaterial(FinalBlend'SKN2_us_mods_acog_reflex');
	L.AddPrecacheMaterial(Shader'skn2_us_mods_acog_reflex_lens');
	L.AddPrecacheMaterial(Texture'skn2_us_mods_carryinghandle');
	L.AddPrecacheMaterial(Texture'skn2_us_mods_lg_heatshield');
	L.AddPrecacheMaterial(Texture'fx_flash_m16_base');
	L.AddPrecacheMaterial(Texture'fx_flash_m16_1P');
	StaticPrecache(L);
}
*/