// All the original content belonged to the US Army


#include "Proj_30Gren.h"
#include "AA29/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_40Gren\Proj_40Gren.h"

AProj_30Gren::AProj_30Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cTrailEmitterClass = Class'AGP_Effects.aux_em_gp30smoke'
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/GP30/WeaponsOPFOR_GP30_Explode.WeaponsOPFOR_GP30_Explode"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_40Gren::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-gp30.m-gp30"), NULL, LOAD_None, NULL);
}
