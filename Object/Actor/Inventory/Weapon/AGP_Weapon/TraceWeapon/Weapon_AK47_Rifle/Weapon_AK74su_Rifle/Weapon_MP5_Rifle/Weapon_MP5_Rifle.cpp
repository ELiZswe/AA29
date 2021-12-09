// All the original content belonged to the US Army


#include "Weapon_MP5_Rifle.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_MP5_Rifle/AttachW_MP5_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_30_Mag/Ammo_9x19mm_30_Mag.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_9mm_Bullet.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage9x19mm.h"

AWeapon_MP5_Rifle::AWeapon_MP5_Rifle()
{
	SingleFire                   = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedIndoor.WeaponsOPFOR_AKS74U_SuppressedIndoor"), NULL, LOAD_None, NULL);
	OutdoorSingleFire            = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedIndoor.WeaponsOPFOR_AKS74U_SuppressedIndoor"), NULL, LOAD_None, NULL);
	SuppressedSingleFire         = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedIndoor.WeaponsOPFOR_AKS74U_SuppressedIndoor"), NULL, LOAD_None, NULL);
	SuppressedOutdoorSingleFire  = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/aks74u/WeaponsOPFOR_AKS74U_SuppressedOutdoorFire.WeaponsOPFOR_AKS74U_SuppressedOutdoorFire"), NULL, LOAD_None, NULL);
	OwnerDamageType              = UProjectileDamage9x19mm::StaticClass();
	AmmoRoundClass               = AAmmoRound_9mm_Bullet::StaticClass();
	bSuppressorOn                = true;
	AmmoName                     = AAmmo_9x19mm_30_Mag::StaticClass();
	FireAdjust                   = 1.23;
	AttachmentClass              = { AAttachW_MP5_Rifle::StaticClass() };
	ItemName                     = "MP5";
}


bool AWeapon_MP5_Rifle::ShouldDoDelayedEject()
{
	return eROF == RateofFire::ROF_SingleGren;
}
void AWeapon_MP5_Rifle::DiscardShell()
{
	/*
	FlashCount = 255;
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).FiringMode = 'ROF_SingleGren';
		BaseWeaponAttachment(ThirdPersonActor).FlashCount = FlashCount;
		BaseWeaponAttachment(ThirdPersonActor).ThirdPersonEffects();
	}
	*/
}