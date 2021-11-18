// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Game/AAGameMenu_Game.h"

UAAGameMenu_Game::UAAGameMenu_Game()
{
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_Game.MyBackground';
	//b_Settings = GUIButton'AGP_Interface.AAGameMenu_Game.SettingsButton';
	//b_Leave = GUIButton'AGP_Interface.AAGameMenu_Game.LeaveButton';
	//b_Exit = GUIButton'AGP_Interface.AAGameMenu_Game.ExitButton';
	DisconnectCaption = "DISCONNECT";
	DisconnectHint = "Click here to disconnect and return to the main menu.";
}


void UAAGameMenu_Game::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (PlayerOwner().Level.NetMode != 0)
	{
		b_Leave.Caption = DisconnectCaption;
		b_Leave.Hint = DisconnectHint;
	}
	*/
}

bool UAAGameMenu_Game::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_Settings)
	{
		Controller.OpenMenu("AGP_Interface.AAMainMenu", AAGUIController(Controller).GetSettingsPanel());
	}
	else
	{
		if (Sender == b_Leave)
		{
			PlayerOwner().ConsoleCommand("disconnect");
			Controller.CloseMenu();
		}
		else
		{
			if (Sender == b_Exit)
			{
				Controller.OpenMenu("AGP_Interface.AAExitPage");
			}
		}
	}
	*/
	return true;
}