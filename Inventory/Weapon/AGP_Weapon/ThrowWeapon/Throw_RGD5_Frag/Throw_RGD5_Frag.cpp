// All the original content belonged to the US Army


#include "Throw_RGD5_Frag.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_RGD5_Frag/PickupT_RGD5_Frag.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_RGD5_Frag/AttachT_RGD5_Frag.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"
#include "AA29/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
AThrow_RGD5_Frag::AThrow_RGD5_Frag()
{
	_fDamage         = 100;
	_fDamageRadius   = 1574.803101;
	_fKillRadius     = 262.467194;
	_fMomentum       = 20000;
	FragDamageType   = UFragDamage::StaticClass();
	MyDamageType     = UGrenadeExplosionDamage::StaticClass();
		//		\\DamageClasses =
		//		AGP_Inventory = Sound'S_AA2_WeaponsUS.Grenades.WeaponsUS_Grenades_M67explosion1'
	//cExplosionEmitter = Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex  = 0;
	OwnerDamageType  = UGrenadeExplosionDamage::StaticClass();
	PickupClass      = APickupT_RGD5_Frag::StaticClass();
	AttachmentClass  = { AAttachT_RGD5_Frag::StaticClass() };
	IconMaterial     = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_frag_01.hud_gren_frag_01"), NULL, LOAD_None, NULL);
	ItemName         = "RGD5 Grenade";
	Mesh             = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m67_1P.m67_1P"), NULL, LOAD_None, NULL);
}