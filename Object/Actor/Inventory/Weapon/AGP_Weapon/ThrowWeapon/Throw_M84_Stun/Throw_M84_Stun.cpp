// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M84_Stun/AttachT_M84_Stun.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M84_Stun/PickupT_M84_Stun.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_flashbang/em_bt_flashbang.h"
AThrow_M84_Stun::AThrow_M84_Stun()
{
	_fMinFuseTime        = 1.5;
	_fAddFuseTime        = 0;
	_fDamage             = 10;
	_fDamageRadius       = 1000;
	_fKillRadius         = 150;
	_fMomentum           = 20000;
	FragDamageType       = UFragDamage::StaticClass();
	MyDamageType         = UFragDamage::StaticClass();
	DamageClasses = {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn'
	};
	_fMaxVisIntensity		= 1;
	_fEffectDuration		= 12;
	BoomSound				= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_FlashBangPow.WeaponsUS_Grenades_FlashBangPow"), NULL, LOAD_None, NULL);
	//cExplosionEmitter		= Aem_bt_flashbang::StaticClass();
	InvGrenadeIndex			= 2;
	OwnerDamageType			= UGrenadeExplosionDamage::StaticClass();
	fpWeaponThreatLevel		= 5;
	PickupClass				= APickupT_M84_Stun::StaticClass();
	AttachmentClass			= { AAttachT_M84_Stun::StaticClass() };
	IconMaterial			= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_flash_01_Mat.hud_gren_flash_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName				= "Flashbang";
	Mesh					= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/FlashBang_1P.FlashBang_1P'"), NULL, LOAD_None, NULL);
}
