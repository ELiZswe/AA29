// All the original content belonged to the US Army


#include "Throw_M14_Incendiary.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_M14_Incendiary/AttachT_M14_Incendiary.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M14_Incendiary/PickupT_M14_Incendiary.h"
#include "AA29/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/IncendiaryDamage/IncendiaryDamage.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/ExplosionDamage.h"

AThrow_M14_Incendiary::AThrow_M14_Incendiary()
{
	_fDamage           = 100;
	_fDamageRadius     = 312.335938;
	_fKillRadius       = 62.467182;
	_fMomentum         = 20000;
	FragDamageType     = UFragDamage::StaticClass();
	MyDamageType       = UIncendiaryDamage::StaticClass();
		//		\\DamageClasses =
		//Mesh = Class'AGP_Gameplay.IncendiaryBurnDamage'
	sDamageHeight      = 60;
	sDamageRadius      = 80;
	sDamageAtCenter    = 40;
	sDamageAtEdge      = 10;
	sDamagePerTime     = 0.1;
	_fMaxVisIntensity  = 0.5;
	_fEffectDuration   = 5;
	BoomSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M14TH3explosion.WeaponsUS_Grenades_M14TH3explosion"), NULL, LOAD_None, NULL);
	//cSmokeEmitter = Afx_exp_incendiaryfire::StaticClass();
	InvGrenadeIndex    = 3;
	OwnerDamageType    = UExplosionDamage::StaticClass();
	PickupClass        = APickupT_M14_Incendiary::StaticClass();
	AttachmentClass    = { AAttachT_M14_Incendiary::StaticClass() };
	IconMaterial       = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_incendiary_01.hud_gren_incendiary_01"), NULL, LOAD_None, NULL);
	ItemName           = "M14 Incendiary Grenade";
	Mesh               = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M14th3_1P.M14th3_1P"), NULL, LOAD_None, NULL);
}

