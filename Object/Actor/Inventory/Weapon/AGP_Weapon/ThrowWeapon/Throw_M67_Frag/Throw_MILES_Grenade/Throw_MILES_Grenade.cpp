// All the original content belonged to the US Army


#include "Throw_MILES_Grenade.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M67_Frag/AttachT_MILES_Grenade/AttachT_MILES_Grenade.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M67_Frag/PickupT_MILES_Grenade/PickupT_MILES_Grenade.h"
#include "AA29/Object/DamageType/AGP_DamageType/MILESGrenadeDamage/MILESGrenadeDamage.h"
AThrow_MILES_Grenade::AThrow_MILES_Grenade()
{
	_fDamage          = 150;
	_fDamageRadius    = 1049.868774;
	_fMomentum        = 0;
	FragDamageType    = UMILESGrenadeDamage::StaticClass();
	MyDamageType      = UMILESGrenadeDamage::StaticClass();
		//		\\DamageClasses =
		//		AGP_Inventory = Sound'S_AA2_WeaponsUS.Grenades.WeaponsUS_Grenades_FlashBangPow'

	//cExplosionEmitter = Aem_bt_flashbang::StaticClass();
	//cExplosionDecal = class'None'
	_bCanBeMiles      = true;
	OwnerDamageType   = UMILESGrenadeDamage::StaticClass();
	PickupClass       = APickupT_MILES_Grenade::StaticClass();
	AttachmentClass   = { AAttachT_MILES_Grenade::StaticClass() };
	ItemName          = "MILES Simulation Grenade";
	Mesh              = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Miles_Grenade_1P.Miles_Grenade_1P"), NULL, LOAD_None, NULL);
}