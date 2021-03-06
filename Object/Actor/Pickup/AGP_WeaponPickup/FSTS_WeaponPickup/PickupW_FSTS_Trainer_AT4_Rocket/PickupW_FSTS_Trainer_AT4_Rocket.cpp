// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_AT4_Rocket/PickupW_FSTS_Trainer_AT4_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_AT4_Rocket/Weapon_AT4_Rocket.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_RPG7_Rocket/PickupW_RPG7_Rocket.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

APickupW_FSTS_Trainer_AT4_Rocket::APickupW_FSTS_Trainer_AT4_Rocket()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_AT4_Rocket::StaticClass();
	PickupMessage			= FString("You found an AT4.");
	EnemyPickupClass		= APickupW_RPG7_Rocket::StaticClass();
	StaticMeshEmpty			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_3p_up_at4.wpn2_3p_up_at4"), NULL, LOAD_None, NULL);
	StaticMeshFull			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_3p_up_at4.wpn2_3p_up_at4"), NULL, LOAD_None, NULL);
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_3p_up_at4.wpn2_3p_up_at4"), NULL, LOAD_None, NULL));
	Rotation				= FRotator(0, 180, 0);
}

void APickupW_FSTS_Trainer_AT4_Rocket::StaticPrecache(ALevelInfo* L)
{
	/*
	L->AddPrecacheMaterial(Texture'Skn2_weap_AT4');
	L->AddPrecacheMaterial(Texture'Skn2_weap_AT4_sights');
	L->AddPrecacheMaterial(Texture'skn2_weap_at4_projectile');
	L->AddPrecacheMaterial(Texture'fx_cor_red');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet01');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet02');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet03');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet04');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet05');
	L->AddPrecacheMaterial(Texture'FX2_ANIM_Jet06');
	L->AddPrecacheMaterial(Texture'fx_decal_explosion');
	L.AddPrecacheStaticMesh(StaticMesh'wpn2_at4_projectile_3p');
	L.AddPrecacheStaticMesh(StaticMesh'fx2_misc_rockettrail');
	Super::StaticPrecache(L);
	*/
}
