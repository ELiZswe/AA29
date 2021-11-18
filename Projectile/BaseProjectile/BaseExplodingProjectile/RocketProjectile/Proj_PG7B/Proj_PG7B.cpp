// All the original content belonged to the US Army


#include "Proj_PG7B.h"
#include "AA29/DamageType/RocketRPGDamage/RocketRPGDamage.h"

AProj_PG7B::AProj_PG7B(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset   = FVector(0, 0, -32);
	JackedPct           = 0.1;
	ImpactDamageType    = URocketRPGDamage::StaticClass();
	FragDamageType      = URocketRPGDamage::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_PG7Bexplosion'
	MyDamageType        = URocketRPGDamage::StaticClass();
	StaticMesh          = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2-wpn_rpg7_projectile_005_3p.m2-wpn_rpg7_projectile_005_3p"), NULL, LOAD_None, NULL);
}