// All the original content belonged to the US Army


#include "Proj_BS1_30Gren.h"
#include "AA29/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_40Gren\Proj_40Gren.h"

AProj_BS1_30Gren::AProj_BS1_30Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsOPFOR/GP30/WeaponsOPFOR_GP30_Explode.WeaponsOPFOR_GP30_Explode"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_40Gren::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_bs1_nade.wpn2_ammo1p_bs1_nade"), NULL, LOAD_None, NULL);
}