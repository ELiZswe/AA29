// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/AGP_Player/CinematicPlayer/CinematicPlayer.h"

ACinematicPlayer::ACinematicPlayer()
{

}

FString ACinematicPlayer::FindMenu()
{
	int32 i = 0;
	/*
	local ScriptedSequence SS;
	if (Level.Game.CurrentGameProfile != nullptr)
	{
		return "";
	}
	ForEach AllActors(Class'Gameplay.ScriptedSequence', SS)
	{
		for (i = 0; i < SS.Actions.Num(); i++)
		{
			if (ACTION_GotoMenu(SS.Actions[i]) != nullptr)
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

