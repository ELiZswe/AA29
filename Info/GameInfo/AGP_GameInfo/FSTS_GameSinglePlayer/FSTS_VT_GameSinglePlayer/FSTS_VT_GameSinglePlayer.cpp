// All the original content belonged to the US Army


#include "AA29/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_VT_GameSinglePlayer/FSTS_VT_GameSinglePlayer.h"

AFSTS_VT_GameSinglePlayer::AFSTS_VT_GameSinglePlayer()
{
	PlayerControllerClassName = "FSTS.VT_PlayerController";
}


void AFSTS_VT_GameSinglePlayer::GetDefaultPlayerClass(AController* C)
{
	//Return class<Pawn>(DynamicLoadObject("FSTS.FSTS_GC_Pawn", Class'Class'));
}
