// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7VR_Demolition/Proj_PG7VR_Demolition.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketDemolitionDamage/RocketDemolitionDamage.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/aux_em_PG7Bsmoke/aux_em_PG7Bsmoke.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"

AProj_PG7VR_Demolition::AProj_PG7VR_Demolition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset  = FVector(0, 0, -32);
	JackedPct          = 0.1;
	//ExplosionEmitter = Aem_bt_PG7Bexplosion::StaticClass()
	//cTrailEmitterClass = Aaux_em_PG7Bsmoke::StaticClass()
	MyDamageType       = URocketDemolitionDamage::StaticClass();
	StaticMesh         = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pg7vr_fired_3p.wpn2_pg7vr_fired_3p"), NULL, LOAD_None, NULL);
}
