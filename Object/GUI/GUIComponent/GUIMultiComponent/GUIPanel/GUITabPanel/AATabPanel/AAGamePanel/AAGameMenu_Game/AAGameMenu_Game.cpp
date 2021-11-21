// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Game/AAGameMenu_Game.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_Game::UAAGameMenu_Game()
{
	UGUIButton* ExitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ExitButton->Caption = "EXIT GAME";
	ExitButton->StyleName = "SquareMenuButton";
	ExitButton->Hint = "Click here to exit the game.";
	ExitButton->WinTop = 0.3;
	ExitButton->WinLeft = 0.1;
	ExitButton->WinWidth = 0.15;
	ExitButton->WinHeight = 0.06;
	//ExitButton->OnClick=AAGameMenu_Game.ButtonClick;
	//ExitButton->OnKeyEvent=ExitButton.InternalOnKeyEvent;
	UGUIButton* LeaveButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LeaveButton->Caption = "LEAVE MISSION";
	LeaveButton->StyleName = "SquareMenuButton";
	LeaveButton->Hint = "Click here to return to the main menu.";
	LeaveButton->WinTop = 0.2;
	LeaveButton->WinLeft = 0.1;
	LeaveButton->WinWidth = 0.15;
	LeaveButton->WinHeight = 0.06;
	//LeaveButton->OnClick=AAGameMenu_Game.ButtonClick;
	//LeaveButton->OnKeyEvent=LeaveButton.InternalOnKeyEvent;
	UGUIButton* SettingsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SettingsButton->Caption = "SETTINGS";
	SettingsButton->StyleName = "SquareMenuButton";
	SettingsButton->Hint = "Click here to adjust game settings.";
	SettingsButton->WinTop = 0.1;
	SettingsButton->WinLeft = 0.1;
	SettingsButton->WinWidth = 0.15;
	SettingsButton->WinHeight = 0.06;
	//SettingsButton->OnClick=AAGameMenu_Game.ButtonClick;
	//SettingsButton->OnKeyEvent=SettingsButton.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	i_Background = MyBackground;
	b_Settings = SettingsButton;
	b_Leave = LeaveButton;
	b_Exit = ExitButton;

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