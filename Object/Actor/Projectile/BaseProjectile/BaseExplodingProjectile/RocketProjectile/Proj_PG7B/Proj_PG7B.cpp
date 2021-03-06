// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7B/Proj_PG7B.h"
#include "AA29/Object/DamageType/RocketRPGDamage/RocketRPGDamage.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"

AProj_PG7B::AProj_PG7B(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset   = FVector(0, 0, -32);
	JackedPct           = 0.1;
	ImpactDamageType    = URocketRPGDamage::StaticClass();
	FragDamageType      = URocketRPGDamage::StaticClass();
	//ExplosionEmitter = Aem_bt_PG7Bexplosion::StaticClass()
	MyDamageType        = URocketRPGDamage::StaticClass();
	StaticMesh          = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_projectile_005_3p.m2-wpn_rpg7_projectile_005_3p"), NULL, LOAD_None, NULL);
}
