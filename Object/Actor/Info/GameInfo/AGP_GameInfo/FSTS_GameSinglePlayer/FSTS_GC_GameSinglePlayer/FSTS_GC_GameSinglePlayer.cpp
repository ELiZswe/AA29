// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_GC_GameSinglePlayer/FSTS_GC_GameSinglePlayer.h"

AFSTS_GC_GameSinglePlayer::AFSTS_GC_GameSinglePlayer()
{
	PlayerControllerClassName = "FSTS.GC_PlayerController";
}

APawn* AFSTS_GC_GameSinglePlayer::GetDefaultPlayerClass(AController* C)
{
	//return class<Pawn>(DynamicLoadObject("FSTS.FSTS_GC_Pawn", Class'Class'));
	return nullptr;    //FAKE   /EliZ
}
