// All the original content belonged to the US Army


#include "PickupW_AK74su_Rifle.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M4A1_Rifle_Mod/PickupW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"

APickupW_AK74su_Rifle::APickupW_AK74su_Rifle()
{
	InventoryType		= AWeapon_AK74su_Rifle::StaticClass();
	PickupMessage		= FString("You found an AK-74su.");
	EnemyPickupClass	= APickupW_M4A1_Rifle_Mod::StaticClass();
	VisibleSkeletalMesh->SetSkeletalMesh(LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Weapons3P/aks74u_3P.aks74u_3P"), NULL, LOAD_None, NULL));
}