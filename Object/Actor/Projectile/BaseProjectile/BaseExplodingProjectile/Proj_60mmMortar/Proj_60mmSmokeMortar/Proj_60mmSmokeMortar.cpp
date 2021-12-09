// All the original content belonged to the US Army


#include "Proj_60mmSmokeMortar.h"

AProj_60mmSmokeMortar::AProj_60mmSmokeMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ExplosionSound = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
}