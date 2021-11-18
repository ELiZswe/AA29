// All the original content belonged to the US Army


#include "NPC_RealHero_Amerine.h"

ANPC_RealHero_Amerine::ANPC_RealHero_Amerine()
{
	MissionID	= 1;
	CustomMesh	= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesAmerine.RealHeroesAmerine"), NULL, LOAD_None, NULL);
	LoadMesh();
}