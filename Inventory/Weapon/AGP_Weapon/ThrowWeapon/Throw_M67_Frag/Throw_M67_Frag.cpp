// All the original content belonged to the US Army


#include "Throw_M67_Frag.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M67_Frag/PickupT_M67_Frag.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M67_Frag/AttachT_M67_Frag.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeM67Damage/GrenadeM67Damage.h"

AThrow_M67_Frag::AThrow_M67_Frag()
{
	_fDamage             = 100;
	_fDamageRadius       = 1312.335938;
	_fKillRadius         = 262.467194;
	_fMomentum           = 20000;
	FragDamageType       = UGrenadeM67Damage::StaticClass();
	MyDamageType         = UGrenadeM67Damage::StaticClass();
	//\\DamageClasses =
	//	System = 1
	_fEffectDuration     = 10;
	BoomSound            = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M67explosion1.WeaponsUS_Grenades_M67explosion1"), NULL, LOAD_None, NULL);
	//cExplosionEmitter  = Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex      = 0;
	_cMILESAltClass      = AThrow_MILES_Grenade::StaticClass();
	OwnerDamageType      = UGrenadeM67Damage::StaticClass();
	fpWeaponThreatLevel  = 13;
	PickupClass          = APickupT_M67_Frag::StaticClass();
	AttachmentClass      = { AAttachT_M67_Frag::StaticClass() };
	IconMaterial         = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_frag_01.hud_gren_frag_01"), NULL, LOAD_None, NULL);
	ItemName             = "M67 Fragmentation Grenade";
	Mesh                 = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m67_1P.m67_1P"), NULL, LOAD_None, NULL);
}

void AThrow_M67_Frag::PlayFiring()
{
	/*
	PlayFiring();
	if (Role == 4 && Instigator != None && Instigator.Controller != None)
	{
		if (!Instigator.bIsWalking && !IsTossNotThrow())
		{
			HumanController(Instigator.Controller).CommoSend(Class'CommoShout', 27);
		}
	}
	*/
}