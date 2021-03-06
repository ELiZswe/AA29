// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/AGP_Player/CinematicPlayer/CinematicPlayer.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AA29/Object/ScriptedAction/ACTION_GotoMenu/ACTION_GotoMenu.h"

ACinematicPlayer::ACinematicPlayer()
{

}

FString ACinematicPlayer::FindMenu()
{
	int32 i = 0;
	AScriptedSequence* SS = nullptr;
	/*
	if (Level.Game.CurrentGameProfile != nullptr)
	{
		return "";
	}
	ForEach AllActors(AScriptedSequence::StaticClass(), SS)
	{
		for (i = 0; i < SS.Actions.Num(); i++)
		{
			if (Cast<UACTION_GotoMenu>(SS.Actions[i]) != nullptr)
			{
				return ACTION_GotoMenu(SS.Actions[i]).GetMenuName();
			}
		}
	}
	return Class'GameEngine'.Default.MainMenuClass;
	*/
	return "FAKE";    //FAKE   /ELIZ
}

void ACinematicPlayer::Fire(float F)
{
	ShowMenu();
}

void ACinematicPlayer::AltFire(float F)
{
	ShowMenu();
}

void ACinematicPlayer::ShowMenu()
{
	GotoMenu(FindMenu());
}

void ACinematicPlayer::GotoMenu(FString MenuName)
{
	if (MenuName != "")
	{
		//Player.GUIController.OpenMenu(MenuName);
	}
	ConsoleCommand("DISCONNECT");
}

