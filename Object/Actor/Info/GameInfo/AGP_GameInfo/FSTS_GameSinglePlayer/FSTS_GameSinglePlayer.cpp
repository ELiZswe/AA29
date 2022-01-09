// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_GameSinglePlayer.h"

AFSTS_GameSinglePlayer::AFSTS_GameSinglePlayer()
{
	HUDType = "FSTS.FSTS_Base_HUD";
	PlayerControllerClassName = "FSTS.FSTS_PlayerController";
	GameName = "FSTS Single Player Mission";
}

AActor* AFSTS_GameSinglePlayer::GetDefaultTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRecruit", Class'Class'));
	return nullptr;    //FAKE   /EliZ
}

APawn* AFSTS_GameSinglePlayer::GetDefaultPlayerClass(AController* C)
{
	//return class<Pawn>(DynamicLoadObject("FSTS.FSTS_Pawn", Class'Class'));
	return nullptr;    //FAKE   /EliZ
}
