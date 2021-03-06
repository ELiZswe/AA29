// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_AirborneSoldier/NPC_AirborneSoldier.h"

ANPC_AirborneSoldier::ANPC_AirborneSoldier()
{
	bStaticSkinsAndMeshes	= false;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

bool ANPC_AirborneSoldier::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_AirborneSoldier::PostBeginPlay()
{
	Super::PostBeginPlay();
	AddDefaultInventory();
	LoadSkinsAndMeshes();
}

