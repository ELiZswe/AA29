// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_AT4_Explosive/Proj_AT4_Explosive.h"
#include "AA29/Object/DamageType/RocketAT4Damage/RocketAT4Damage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\RocketProjectile\Proj_PG7B\Proj_PG7B.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7B/Proj_PG7B.h"

AProj_AT4_Explosive::AProj_AT4_Explosive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset     = FVector(0, 0, -315);
	ImpactDamageType      = URocketAT4Damage::StaticClass();
	FragDamageType        = URocketAT4Damage::StaticClass();
	//ExplosionEmitter = Aem_bt_PG7Bexplosion::StaticClass()
	EnemyProjectileClass  = AProj_PG7B::StaticClass();
	MyDamageType          = URocketAT4Damage::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_at4_projectile_3p.wpn2_at4_projectile_3p"), NULL, LOAD_None, NULL);
}
