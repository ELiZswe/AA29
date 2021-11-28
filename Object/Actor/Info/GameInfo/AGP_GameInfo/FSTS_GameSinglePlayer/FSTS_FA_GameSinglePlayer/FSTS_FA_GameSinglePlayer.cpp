// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_FA_GameSinglePlayer/FSTS_FA_GameSinglePlayer.h"

AFSTS_FA_GameSinglePlayer::AFSTS_FA_GameSinglePlayer()
{
	HUDType = "FSTS.FA_HUD";
	PlayerControllerClassName = "FSTS.FA_PlayerController";
	GameName = "FSTS Single Player First Aid Training Mission";
}

void AFSTS_FA_GameSinglePlayer::GetDefaultTeamClass()
{
	//Return class<Actor>(DynamicLoadObject("FSTS.FA_ClassRifleman", Class'Class'));
}
void AFSTS_FA_GameSinglePlayer::GetDefaultPlayerClass(AController* C)
{
	//Return class<Pawn>(DynamicLoadObject("FSTS.FSTS_FA_Pawn", Class'Class'));
}