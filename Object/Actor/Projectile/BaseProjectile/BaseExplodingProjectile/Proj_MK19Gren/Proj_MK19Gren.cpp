// All the original content belonged to the US Army


#include "Proj_MK19Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType\ProjectileDamage\ProjectileDamageUS40mmGrenade.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_30Gren\Proj_30Gren.h"

AProj_MK19Gren::AProj_MK19Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange.Min   = 0;
	ArmingTimeRange.Max   = 0.1;
	ImpactDamageType      = UProjectileDamageUS40mmGrenade::StaticClass();
	FragDamageType        = UProjectileDamageUS40mmGrenade::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_mk19grenexplosion'
	EnemyProjectileClass  = AProj_30Gren::StaticClass();
	Speed                 = 8000;
	Damage                = 125;
	DamageRadius          = 720;
	MyDamageType          = UProjectileDamageUS40mmGrenade::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
}