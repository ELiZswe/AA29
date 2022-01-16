// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_GotoMenu/ACTION_GotoMenu.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_GotoMenu::UACTION_GotoMenu()
{
	bDisconnect = true;
}

bool UACTION_GotoMenu::InitActionFor(AScriptedController* C)
{
	APlayerController* CP = nullptr;
	/*
	if (MenuName == "")
	{
		MenuName = Class'GameEngine'.Default.MainMenuClass;
	}
	ForEach C.AllActors(Class'PlayerController', CP)
	{
		CP.ClientOpenMenu(MenuName, bDisconnect);
		return false;
	}
	*/
	return false;
}

FString UACTION_GotoMenu::GetMenuName()
{
	if (MenuName == "")
	{
		//MenuName = Class'GameEngine'.Default.MainMenuClass;
	}
	return MenuName;
}

FString UACTION_GotoMenu::GetActionString()
{
	//return "OpenMenu" @ MenuName;
	return "";    //FAKE   /ELiZ
}
