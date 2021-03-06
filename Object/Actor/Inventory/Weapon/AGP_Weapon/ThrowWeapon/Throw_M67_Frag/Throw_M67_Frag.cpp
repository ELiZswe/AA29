// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M67_Frag/PickupT_M67_Frag.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M67_Frag/AttachT_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeM67Damage/GrenadeM67Damage.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoShout/CommoShout.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosionB/em_bt_grenexplosionB.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_MILES_Grenade/Throw_MILES_Grenade.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"

AThrow_M67_Frag::AThrow_M67_Frag()
{
	_fDamage			= 100;
	_fDamageRadius		= 1312.335938;
	_fKillRadius		= 262.467194;
	_fMomentum			= 20000;
	FragDamageType		= UGrenadeM67Damage::StaticClass();
	MyDamageType		= UGrenadeM67Damage::StaticClass();
	DamageClasses = {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass(),
	};
	_fEffectDuration     = 10;
	BoomSound            = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M67explosion1.WeaponsUS_Grenades_M67explosion1"), NULL, LOAD_None, NULL);
	//cExplosionEmitter  = Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex      = 0;
	_cMILESAltClass      = AThrow_MILES_Grenade::StaticClass();
	OwnerDamageType      = UGrenadeM67Damage::StaticClass();
	fpWeaponThreatLevel  = 13;
	PickupClass          = APickupT_M67_Frag::StaticClass();
	AttachmentClass      = { AAttachT_M67_Frag::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_frag_01_Mat.hud_gren_frag_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "M67 Fragmentation Grenade";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m67_1P.m67_1P'"), NULL, LOAD_None, NULL);
}

void AThrow_M67_Frag::PlayFiring()
{
	/*
	PlayFiring();
	if (Role == 4 && Instigator != nullptr && Instigator.Controller != nullptr)
	{
		if (!Instigator.bIsWalking && !IsTossNotThrow())
		{
			Cast<AHumanController>(Instigator.Controller).CommoSend(ACommoShout::StaticClass(), 27);
		}
	}
	*/
}
