// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_GotoMenu/ACTION_GotoMenu.h"

UACTION_GotoMenu::UACTION_GotoMenu()
{
	bDisconnect = true;
}

bool UACTION_GotoMenu::InitActionFor(UScriptedController* C)
{
	/*
	local PlayerController CP;
	if (MenuName == "")
	{
		MenuName = Class'GameEngine'.Default.MainMenuClass;
	}
	ForEach C.AllActors(Class'PlayerController', CP)
	{
		CP.ClientOpenMenu(MenuName, bDisconnect);
		Return False;
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
	//Return "OpenMenu" @ MenuName;
	return "";    //FAKE   /ELiZ
}