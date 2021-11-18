// All the original content belonged to the US Army


#include "AGP_Character_NPC.h"
AAGP_Character_NPC::AAGP_Character_NPC()
{
	fCrouchSpeed		= 170;
	fFastCrouchSpeed	= 180;
	fHCrawlSpeed		= 90;
	fLCrawlSpeed		= 70;
	SoundRadius			= 160;
	CustomMesh			= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void AAGP_Character_NPC::PossessedBy(AController* C)
{

}
void AAGP_Character_NPC::BeginPlay()
{

}