// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYMUSIC/Action_PLAYMUSIC.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_PLAYMUSIC::UAction_PLAYMUSIC()
{
	//Transition = 3;
	bAffectAllPlayers = true;
	ActionString = "play song";
}

bool UAction_PLAYMUSIC::InitActionFor(AScriptedController* C)
{
	APlayerController* p = nullptr;
	AController* A = nullptr;
	if (bAffectAllPlayers)
	{
		/*
		for (A = C.Level.ControllerList; A != nullptr; A = A.nextController)
		{
			if (A->IsA(APlayerController::StaticClass()))
			{
				Cast<APlayerController>(A).ClientSetMusic(Song, Transition);
			}
		}
		*/
	}
	else
	{
		/*
		p = PlayerController(C.GetInstigator().Controller);
		if (p == nullptr)
		{
			return false;
		}
		p.ClientSetMusic(Song, Transition);
		*/
	}
	return false;
}
FString UAction_PLAYMUSIC::GetActionString()
{
	//return ActionString @ Song;
	return "";    //FAKE   /ELiZ

}
