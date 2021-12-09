// All the original content belonged to the US Army


#include "Proj_PG7VR_Demolition.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketDemolitionDamage/RocketDemolitionDamage.h"

AProj_PG7VR_Demolition::AProj_PG7VR_Demolition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	RocketTrailOffset  = FVector(0, 0, -32);
	JackedPct          = 0.1;
	//ExplosionEmitter = Class'AGP_Effects.em_bt_PG7Bexplosion'
	//cTrailEmitterClass = Class'AGP_Effects.aux_em_PG7Bsmoke'
	MyDamageType       = URocketDemolitionDamage::StaticClass();
	StaticMesh         = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pg7vr_fired_3p.wpn2_pg7vr_fired_3p"), NULL, LOAD_None, NULL);
}