// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_MissileExplosion/em_bt_MaverickMissileExplosion/em_bt_MaverickMissileExplosion.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLightB/aux_light_ExpLightB.h"

Aem_bt_MaverickMissileExplosion::Aem_bt_MaverickMissileExplosion()
{

}

void Aem_bt_MaverickMissileExplosion::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_MaverickMissileExplosion::SpawnLight()
{
	//Spawn(Aaux_light_ExpLightB::StaticClass());
}
