// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_RGD5_Frag/Throw_RGD5_Frag.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_RGD5_Frag/PickupT_RGD5_Frag.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_RGD5_Frag/AttachT_RGD5_Frag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosionB/em_bt_grenexplosionB.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
AThrow_RGD5_Frag::AThrow_RGD5_Frag()
{
	_fDamage		= 100;
	_fDamageRadius		= 1574.803101;
	_fKillRadius		= 262.467194;
	_fMomentum			= 20000;
	FragDamageType		= UFragDamage::StaticClass();
	MyDamageType		= UGrenadeExplosionDamage::StaticClass();
	DamageClasses		= {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass()
	};
	BoomSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M67explosion1_Cue.WeaponsUS_Grenades_M67explosion1_Cue'"), NULL, LOAD_None, NULL);
	//cExplosionEmitter	= Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex		= 0;
	OwnerDamageType		= UGrenadeExplosionDamage::StaticClass();
	PickupClass			= APickupT_RGD5_Frag::StaticClass();
	AttachmentClass		= { AAttachT_RGD5_Frag::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_frag_01_Mat.hud_gren_frag_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "RGD5 Grenade";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m67_1P.m67_1P'"), NULL, LOAD_None, NULL);
}
