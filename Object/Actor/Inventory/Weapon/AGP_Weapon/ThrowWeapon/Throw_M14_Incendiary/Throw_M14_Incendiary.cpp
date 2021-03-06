// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M14_Incendiary/AttachT_M14_Incendiary.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M14_Incendiary/PickupT_M14_Incendiary.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/IncendiaryDamage/IncendiaryDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/ExplosionDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/fx_exp_incendiaryfire/fx_exp_incendiaryfire.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"

AThrow_M14_Incendiary::AThrow_M14_Incendiary()
{
	_fDamage           = 100;
	_fDamageRadius     = 312.335938;
	_fKillRadius       = 62.467182;
	_fMomentum         = 20000;
	FragDamageType     = UFragDamage::StaticClass();
	MyDamageType       = UIncendiaryDamage::StaticClass();
	DamageClasses = {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass(),
	};

	sDamageHeight		= 60;
	sDamageRadius		= 80;
	sDamageAtCenter		= 40;
	sDamageAtEdge		= 10;
	sDamagePerTime		= 0.1;
	_fMaxVisIntensity	= 0.5;
	_fEffectDuration	= 5;
	BoomSound			= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M14TH3explosion.WeaponsUS_Grenades_M14TH3explosion"), NULL, LOAD_None, NULL);
	//cSmokeEmitter = Afx_exp_incendiaryfire::StaticClass();
	InvGrenadeIndex		= 3;
	OwnerDamageType		= UExplosionDamage::StaticClass();
	PickupClass			= APickupT_M14_Incendiary::StaticClass();
	AttachmentClass		= { AAttachT_M14_Incendiary::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_incendiary_01_Mat.hud_gren_incendiary_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "M14 Incendiary Grenade";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M14th3_1P.M14th3_1P'"), NULL, LOAD_None, NULL);
}

