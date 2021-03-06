// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_BDM_Demolition/Proj_BDM_Demolition.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketImpact\BDM_ImpactDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\RocketProjectile\Proj_PG7VR_Demolition\Proj_PG7VR_Demolition.h"
#include "AA29/Object/DamageType/AGP_DamageType\ExplosionDamage\RocketDemolitionDamage/BDMRocketDemolitionDamage/BDMRocketDemolitionDamage.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_BDMexplosion/em_bt_BDMexplosion.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7VR_Demolition/Proj_PG7VR_Demolition.h"

AProj_BDM_Demolition::AProj_BDM_Demolition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset      = FVector(0, 0, -315);
	ImpactDamage           = 250;
	ImpactDamageType       = UBDM_ImpactDamage::StaticClass();
	//ExplosionEmitter = Aem_bt_BDMexplosion::StaticClass()
	EnemyProjectileClass   = AProj_PG7VR_Demolition::StaticClass();
	MyDamageType           = UBDMRocketDemolitionDamage::StaticClass();
	StaticMesh             = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_at4_projectile_3p.wpn2_at4_projectile_3p"), NULL, LOAD_None, NULL);
}
