// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_BHPilot/NPC_BHCrewChief/NPC_BHCrewChief.h"

ANPC_BHCrewChief::ANPC_BHCrewChief()
{
	AnimSequence	= "BH_CrewIdle";
	CustomMesh		= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void ANPC_BHCrewChief::PostBeginPlay()
{
	Super::PostBeginPlay();
	//SetDrawScale((1 - (float(Rand(5)) * 0.01)));
}
