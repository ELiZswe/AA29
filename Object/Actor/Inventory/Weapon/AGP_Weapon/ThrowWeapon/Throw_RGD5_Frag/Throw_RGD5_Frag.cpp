// All the original content belonged to the US Army

#include "Throw_RGD5_Frag.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_RGD5_Frag/PickupT_RGD5_Frag.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_RGD5_Frag/AttachT_RGD5_Frag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
AThrow_RGD5_Frag::AThrow_RGD5_Frag()
{
	_fDamage		= 100;
	_fDamageRadius		= 1574.803101;
	_fKillRadius		= 262.467194;
	_fMomentum			= 20000;
	FragDamageType		= UFragDamage::StaticClass();
	MyDamageType		= UGrenadeExplosionDamage::StaticClass();
	DamageClasses		= {
		//Class'Engine.DecoMesh',
		//Class'Engine.Pawn',
		//Class'Engine.BaseProjectile',
		//Class'AGP.ThrowWeaponPickup',
		//Class'Engine.Triggers',
		//Class'AGP.BodyPanel'
	};
	BoomSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M67explosion1_Que.WeaponsUS_Grenades_M67explosion1_Que'"), NULL, LOAD_None, NULL);
	//cExplosionEmitter	= Aem_bt_grenexplosionB::StaticClass();
	InvGrenadeIndex		= 0;
	OwnerDamageType		= UGrenadeExplosionDamage::StaticClass();
	PickupClass			= APickupT_RGD5_Frag::StaticClass();
	AttachmentClass		= { AAttachT_RGD5_Frag::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_frag_01_Mat.hud_gren_frag_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "RGD5 Grenade";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/m67_1P.m67_1P'"), NULL, LOAD_None, NULL);
}
