// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_RealHero/NPC_RealHero_Amerine/NPC_RealHero_Amerine.h"

ANPC_RealHero_Amerine::ANPC_RealHero_Amerine()
{
	MissionID	= 1;
	CustomMesh	= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/RealHeroesAmerine.RealHeroesAmerine"), NULL, LOAD_None, NULL);
	LoadMesh();
}
