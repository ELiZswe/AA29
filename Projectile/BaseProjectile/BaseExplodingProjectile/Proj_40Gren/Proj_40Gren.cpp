// All the original content belonged to the US Army


#include "Proj_40Gren.h"
#include "AA29/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_30Gren\Proj_30Gren.h"
#include "AA29/DamageType/AGP_DamageType\GrenadeImpact\SpecialGrenadeImpact.h"
AProj_40Gren::AProj_40Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamageType      = USpecialGrenadeImpact::StaticClass();
	EnemyProjectileClass  = AProj_30Gren::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
}
