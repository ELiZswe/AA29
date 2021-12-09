// All the original content belonged to the US Army


#include "PickupW_SPR_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SPR_Sniper/Weapon_SPR_Sniper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_Vintorez_Sniper/PickupW_Vintorez_Sniper.h"

APickupW_SPR_Sniper::APickupW_SPR_Sniper()
{
	InventoryType     = AWeapon_SPR_Sniper::StaticClass();
	PickupMessage     = FString("You found an SPR Special Purpose Rifle");
	EnemyPickupClass  = APickupW_Vintorez_Sniper::StaticClass();
	VisibleSkeletalMesh->SetSkeletalMesh(LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/spr_3P.spr_3P"), NULL, LOAD_None, NULL));
}