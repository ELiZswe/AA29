// All the original content belonged to the US Army


#include "Proj_60mmTrainingMortar.h"

AProj_60mmTrainingMortar::AProj_60mmTrainingMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//ExplosionEmitter = Class'AGP_Effects.em_bt_flashbang'
	fKillRadius           = 0;
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_60mmTrainingMortar::StaticClass();
	Damage                = 50;
	DamageRadius          = 50;
}