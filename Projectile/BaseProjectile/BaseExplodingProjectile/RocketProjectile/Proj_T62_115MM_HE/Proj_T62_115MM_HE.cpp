// All the original content belonged to the US Army


#include "Proj_T62_115MM_HE.h"
#include "AA29/DamageType/AGP_DamageType\ProjectileDamage\ProjectileDamageT62A115mmHE.h"

AProj_T62_115MM_HE::AProj_T62_115MM_HE(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset  = FVector(0, 0, -315);
	InitialSpeed       = 7600;
	ArmingTimeRange.Min = 0.0f;
	ArmingTimeRange.Max = 0.0f;
	ImpactDamageType   = UProjectileDamageT62A115mmHE::StaticClass();
	FragDamageType     = UProjectileDamageT62A115mmHE::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_PG7Bexplosion'
	Speed              = 7600;
	MaxSpeed           = 7600;
	Damage             = 40000;
	DamageRadius       = 328;
	MomentumTransfer   = 75000;
	MyDamageType       = UProjectileDamageT62A115mmHE::StaticClass();
	StaticMesh         = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_at4_projectile_3p.wpn2_at4_projectile_3p"), NULL, LOAD_None, NULL);
}