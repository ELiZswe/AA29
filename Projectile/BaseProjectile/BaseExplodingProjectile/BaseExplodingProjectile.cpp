// All the original content belonged to the US Army


#include "BaseExplodingProjectile.h"
#include "AA29/DamageType/AGP_DamageType\ExplosionDamage\ExplosionDamage.h"
#include "AA29/DamageType/AGP_DamageType\FragDamage\FragDamage.h"
#include "AA29/DamageType/AGP_DamageType\GrenadeImpact\GrenadeImpact.h"

ABaseExplodingProjectile::ABaseExplodingProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange.Min  = 0.183727f;
	ArmingTimeRange.Max  = 0.498688f;
	ImpactDamage         = 30;
	ImpactDamageType     = UGrenadeImpact::StaticClass();
	FragDamageType       = UFragDamage::StaticClass();
//		ExplosionEmitter = Class'AGP_Effects.em_bt_grenexplosion'

	sWood = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood1.WeaponsUS_Grenades_GrenadeBounceWood1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood2.WeaponsUS_Grenades_GrenadeBounceWood2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood3.WeaponsUS_Grenades_GrenadeBounceWood3"), NULL, LOAD_None, NULL)
	};

	sDirt = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt1.WeaponsUS_Grenades_GrenadeBounceDirt1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt2.WeaponsUS_Grenades_GrenadeBounceDirt2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt3.WeaponsUS_Grenades_GrenadeBounceDirt3"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal1.WeaponsUS_Grenades_GrenadeBounceMetal1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal2.WeaponsUS_Grenades_GrenadeBounceMetal2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal3.WeaponsUS_Grenades_GrenadeBounceMetal3"), NULL, LOAD_None, NULL)
	};
	sMuffled = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled1.WeaponsUS_Grenades_GrenadebounceMuffled1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled2.WeaponsUS_Grenades_GrenadebounceMuffled2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled3.WeaponsUS_Grenades_GrenadebounceMuffled3"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce1.WeaponsUS_Grenades_Grenadebounce1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce2.WeaponsUS_Grenades_Grenadebounce2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce3.WeaponsUS_Grenades_Grenadebounce3"), NULL, LOAD_None, NULL)
	};
	_fAudIntensity        = 1;
	_fEffectDuration      = 10;
	bSetRotation          = true;
	ExplosionSoundRadius  = 1500;
//		\\DamageClasses =
//		AGP = 262.467194
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Explosion1.WeaponsUS_M203_Explosion1"), NULL, LOAD_None, NULL);
	Speed                 = 4000;
	Damage                = 100;
	DamageRadius          = 1049.868774;
	MomentumTransfer      = 20000;
	MyDamageType          = UExplosionDamage::StaticClass();
	ImpactSound           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood1.WeaponsUS_Grenades_GrenadeBounceWood1"), NULL, LOAD_None, NULL);
	//ExplosionDecal = Class'AGP_Effects.de_bt_grenimpact'
	DrawType              = EDrawType::DT_StaticMesh;
	bNetTemporary         = false;
	bAlwaysRelevant       = true;
	//Physics = 2;
	LifeSpan              = 20;
	DrawScale             = 0.5;
	//bUnlit = false;
	CollisionRadius       = 4;
	CollisionHeight       = 3;
	//bProjTarget = true;
	//bBounce = true;
}