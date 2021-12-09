// All the original content belonged to the US Army


#include "PickupW_Vintorez_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_Vintorez_Sniper/Weapon_Vintorez_Sniper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_SPR_Sniper/PickupW_SPR_Sniper.h"

APickupW_Vintorez_Sniper::APickupW_Vintorez_Sniper()
{
	InventoryType     = AWeapon_Vintorez_Sniper::StaticClass();
	PickupMessage     = FString("You found a Vintorez");
	EnemyPickupClass  = APickupW_SPR_Sniper::StaticClass();
	VisibleSkeletalMesh->SetSkeletalMesh(LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/vss_3P.vss_3P"), NULL, LOAD_None, NULL));
}