// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2MainMenu/UT2MainMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UUT2MainMenu::UUT2MainMenu()
{
	UGUIButton* QuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitButton->Caption = "QUIT";
	QuitButton->StyleName = "SquareMenuButton";
	QuitButton->Hint = "Exit Unreal Tournament 2003";
	QuitButton->WinTop = 0.905725;
	QuitButton->WinLeft = 0.391602;
	QuitButton->WinWidth = 0.205078;
	QuitButton->WinHeight = 0.042773;
	QuitButton->bFocusOnWatch = true;
	//QuitButton->OnClick=UT2MainMenu.ButtonClick;
	//QuitButton->OnKeyEvent=QuitButton.InternalOnKeyEvent;
	UGUIButton* SettingsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SettingsButton->Caption = "SETTINGS";
	SettingsButton->StyleName = "TextButton";
	SettingsButton->Hint = "Change Your Controls and Settings";
	SettingsButton->WinTop = 0.733595;
	SettingsButton->WinLeft = 0.25;
	SettingsButton->WinWidth = 0.5;
	SettingsButton->WinHeight = 0.075;
	SettingsButton->bFocusOnWatch = true;
	//SettingsButton->OnClick=UT2MainMenu.ButtonClick;
	//SettingsButton->OnKeyEvent=SettingsButton.InternalOnKeyEvent;
	UGUIButton* InstantActionButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	InstantActionButton->Caption = "INSTANT ACTION";
	InstantActionButton->StyleName = "TextButton";
	InstantActionButton->Hint = "Play a Practice Match";
	InstantActionButton->WinTop = 0.658334;
	InstantActionButton->WinLeft = 0.25;
	InstantActionButton->WinWidth = 0.5;
	InstantActionButton->WinHeight = 0.075;
	InstantActionButton->bFocusOnWatch = true;
	//InstantActionButton->OnClick=UT2MainMenu.ButtonClick;
	//InstantActionButton->OnKeyEvent=InstantActionButton.InternalOnKeyEvent;
	UGUIButton* HostButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HostButton->Caption = "HOST MULTIPLAYER GAME";
	HostButton->StyleName = "TextButton";
	HostButton->Hint = "Start a server an invite others to join your game";
	HostButton->WinTop = 0.577866;
	HostButton->WinLeft = 0.25;
	HostButton->WinWidth = 0.5;
	HostButton->WinHeight = 0.075;
	HostButton->bFocusOnWatch = true;
	//HostButton->OnClick=UT2MainMenu.ButtonClick;
	//HostButton->OnKeyEvent=HostButton.InternalOnKeyEvent;
	UGUIButton* MultiplayerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MultiplayerButton->Caption = "PLAY ON-LINE/LAN";
	MultiplayerButton->StyleName = "TextButton";
	MultiplayerButton->Hint = "Play with Human Opponents Over the Lan or the Internet";
	MultiplayerButton->WinTop = 0.506251;
	MultiplayerButton->WinLeft = 0.25;
	MultiplayerButton->WinWidth = 0.5;
	MultiplayerButton->WinHeight = 0.075;
	MultiplayerButton->bFocusOnWatch = true;
	//MultiplayerButton->OnClick=UT2MainMenu.ButtonClick;
	//MultiplayerButton->OnKeyEvent=MultiplayerButton.InternalOnKeyEvent;
	UGUIButton* SinglePlayerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SinglePlayerButton->Caption = "SINGLE PLAYER";
	SinglePlayerButton->StyleName = "TextButton";
	SinglePlayerButton->Hint = "Play through the Tournament";
	SinglePlayerButton->WinTop = 0.438802;
	SinglePlayerButton->WinLeft = 0.25;
	SinglePlayerButton->WinWidth = 0.5;
	SinglePlayerButton->WinHeight = 0.075;
	SinglePlayerButton->bFocusOnWatch = true;
	//SinglePlayerButton->OnClick=UT2MainMenu.ButtonClick;
	//SinglePlayerButton->OnKeyEvent=SinglePlayerButton.InternalOnKeyEvent;
	UGUIImage* ImgUT2Logo = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgUT2Logo->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgUT2Logo->WinTop = -0.033854;
	ImgUT2Logo->WinLeft = 0.1;
	ImgUT2Logo->WinWidth = 0.8;
	ImgUT2Logo->WinHeight = 0.5;
	UGUIImage* ImgUT2Shader = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ImgUT2Shader->ImageStyle = EImgStyle::ISTY_Scaled;
	ImgUT2Shader->WinTop = 0.223958;
	ImgUT2Shader->WinLeft = 0.399414;
	ImgUT2Shader->WinWidth = 0.198242;
	ImgUT2Shader->WinHeight = 0.132813;
	bDisconnectOnOpen = true;
	bAllowedAsLast = true;
	//OnCanClose = UT2MainMenu.CanClose;
	Controls = { ImgUT2Logo,ImgUT2Shader,SinglePlayerButton,MultiplayerButton,HostButton,InstantActionButton,SettingsButton,QuitButton };
	WinHeight = 1;
	//OnKeyEvent = UT2MainMenu.MyKeyEvent;
}

void UUT2MainMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if (PlayerOwner().Level.IsDemoBuild())
	{
		Controls[3].SetFocus(None);
		Controls[2].MenuStateChange(4);
	}
	*/
}

void UUT2MainMenu::OnClose(bool bCanceled)
{
}

bool UUT2MainMenu::MyKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 27) && (State == 1))
	{
		AllowClose = true;
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE    /ELiZ
}

bool UUT2MainMenu::CanClose(bool bCanceled)
{
	/*
	if (AllowClose)
	{
		Controller.OpenMenu("xinterface.UT2QuitPage");
	}
	*/
	return false;
}

bool UUT2MainMenu::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[2])
	{
		Controller.OpenMenu("xinterface.UT2SinglePlayerMain");
	}
	if (Sender == Controls[3])
	{
		Controller.OpenMenu("xinterface.ServerBrowser");
	}
	if (Sender == Controls[4])
	{
		Controller.OpenMenu("xinterface.UT2MultiplayerHostPage");
	}
	if (Sender == Controls[5])
	{
		Controller.OpenMenu("xinterface.UT2InstantActionPage");
	}
	if (Sender == Controls[6])
	{
		Controller.OpenMenu("xinterface.UT2SettingsPage");
	}
	if (Sender == Controls[7])
	{
		Controller.OpenMenu("xinterface.UT2QuitPage");
	}
	*/
	return true;
}