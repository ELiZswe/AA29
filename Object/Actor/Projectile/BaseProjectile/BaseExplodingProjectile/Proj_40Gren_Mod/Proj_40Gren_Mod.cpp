// All the original content belonged to the US Army


#include "Proj_40Gren_Mod.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_BS1_30Gren\Proj_BS1_30Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType\GrenadeImpact\SpecialGrenadeImpact.h"

AProj_40Gren_Mod::AProj_40Gren_Mod(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamageType      = USpecialGrenadeImpact::StaticClass();
	EnemyProjectileClass  = AProj_BS1_30Gren::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
}