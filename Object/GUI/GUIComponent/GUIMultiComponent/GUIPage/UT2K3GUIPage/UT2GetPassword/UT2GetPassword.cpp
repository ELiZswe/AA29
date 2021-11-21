// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2GetPassword/UT2GetPassword.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2GetPassword::UUT2GetPassword()
{
	UGUIButton* GetPassFail = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassFail->Caption = "Cancel";
	GetPassFail->StyleName = "MidGameButton";
	GetPassFail->WinTop = 0.941666;
	GetPassFail->WinLeft = 0.65;
	GetPassFail->WinWidth = 0.25;
	GetPassFail->WinHeight = 0.05;
	GetPassFail->bBoundToParent = true;
	//GetPassFail->OnClick=UT2GetPassword.InternalOnClick;
	//GetPassFail->OnKeyEvent=GetPassFail.InternalOnKeyEvent;
	UGUIButton* GetPassRetry = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassRetry->Caption = "Retry";
	GetPassRetry->StyleName = "MidGameButton";
	GetPassRetry->WinTop = 0.941666;
	GetPassRetry->WinLeft = 0.4;
	GetPassRetry->WinWidth = 0.25;
	GetPassRetry->WinHeight = 0.05;
	GetPassRetry->bBoundToParent = true;
	//GetPassRetry->OnClick=UT2GetPassword.InternalOnClick;
	//GetPassRetry->OnKeyEvent=GetPassRetry.InternalOnKeyEvent;
	UmoEditBox* GetPassPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	GetPassPW->CaptionWidth = 0.4;
	GetPassPW->Caption = "Server Password";
	//GetPassPW->OnCreateComponent=GetPassPW.InternalOnCreateComponent;
	GetPassPW->WinTop = 0.508594;
	GetPassPW->WinLeft = 0.25;
	GetPassPW->WinHeight = 0.06;
	UGUIButton* GetPassBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassBackground->StyleName = "RoundButton";
	GetPassBackground->WinTop = 0.375;
	GetPassBackground->WinLeft = 0.0875;
	GetPassBackground->WinWidth = 0.831251;
	GetPassBackground->WinHeight = 0.30625;
	GetPassBackground->bAcceptsInput = false;
	GetPassBackground->bNeverFocus = true;
	//GetPassBackground->OnKeyEvent=GetPassBackground.InternalOnKeyEvent;
	UGUILabel* GetPassLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GetPassLabel->Caption = "A password is required to play on this server.";
	GetPassLabel->TextAlign = ETextAlign::TXTA_Center;
	GetPassLabel->TextColor = FColor(255, 255, 255, 255);
	GetPassLabel->TextFont = "UT2HeaderFont";
	GetPassLabel->bMultiLine = true;
	GetPassLabel->WinTop = 0.125;
	GetPassLabel->WinHeight = 0.5;
	GetPassLabel->bBoundToParent = true;
	bIgnoreEsc = true;
	bAllowedAsLast = true;
	Controls = { GetPassBackground,GetPassPW,GetPassRetry,GetPassFail,GetPassLabel };
	WinTop = 0.375;
	WinHeight = 0.25;
}

void UUT2GetPassword::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	PlayerOwner().ClearProgressMessages();
	moEditBox(Controls[1]).MyEditBox.bConvertSpaces = true;
	*/
}

void UUT2GetPassword::HandleParameters(FString URL, FString Unused)
{
	RetryURL = URL;
}

bool UUT2GetPassword::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local ExtendedConsole MyConsole;
	if ((Sender == Controls[2]) && (Len(moEditBox(Controls[1]).GetText()) > 0))
	{
		MyConsole = ExtendedConsole(PlayerOwner().Player.Console);
		if (MyConsole != None)
		{
			MyConsole.SavedPasswords.Length = (MyConsole.SavedPasswords.Length + 1);
			MyConsole.SavedPasswords[(MyConsole.SavedPasswords.Length - 1)].Server = MyConsole.LastConnectedServer;
			MyConsole.SavedPasswords[(MyConsole.SavedPasswords.Length - 1)].Password = moEditBox(Controls[1]).GetText();
			MyConsole.SaveConfig();
		}
		PlayerOwner().ClientTravel(RetryURL $ "?password=" $ moEditBox(Controls[1]).GetText(), 0, false);
		Controller.CloseAll(false);
	}
	if (Sender == Controls[3])
	{
		Controller.ReplaceMenu("xinterface.UT2MainMenu");
	}
	*/
	return true;
}
