// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetPassword/AAGetPassword.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGetPassword::UAAGetPassword()
{
	UGUIButton* GetPassFail = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassFail->Caption = "CANCEL";
	GetPassFail->WinTop = 0.547122;
	GetPassFail->WinLeft = 0.586523;
	GetPassFail->WinWidth = 0.1475;
	GetPassFail->WinHeight = 0.045;
	GetPassFail->TabOrder = 2;
	GetPassFail->bBoundToParent = true;
	//GetPassFail->OnClick=AAGetPassword.InternalOnClick;
	//GetPassFail->OnKeyEvent=GetPassFail.InternalOnKeyEvent;
	UGUIButton* GetPassRetry = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassRetry->Caption = "SUBMIT";
	GetPassRetry->WinTop = 0.730455;
	GetPassRetry->WinLeft = 0.320899;
	GetPassRetry->WinWidth = 0.1475;
	GetPassRetry->WinHeight = 0.045;
	GetPassRetry->TabOrder = 1;
	GetPassRetry->bBoundToParent = true;
	//GetPassRetry->OnClick=AAGetPassword.InternalOnClick;
	//GetPassRetry->OnKeyEvent=GetPassRetry.InternalOnKeyEvent;
	UmoEditBox* GetPassPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	GetPassPW->CaptionWidth = 0.4;
	GetPassPW->Caption = "Server Password";
	//GetPassPW->OnCreateComponent=GetPassPW.InternalOnCreateComponent;
	GetPassPW->WinTop = 0.485366;
	GetPassPW->WinLeft = 0.209375;
	GetPassPW->WinWidth = 0.5625;
	GetPassPW->TabOrder = 0;
	UGUILabel* GetPassLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GetPassLabel->Caption = "A password is required to play on this server.";
	GetPassLabel->TextAlign = ETextAlign::TXTA_Center;
	GetPassLabel->FontScale = EFontScale::FNS_Large;
	GetPassLabel->StyleName = "TextLabel";
	GetPassLabel->WinTop = 0.30223;
	GetPassLabel->WinLeft = 0.02793;
	GetPassLabel->WinWidth = 0.94043;
	GetPassLabel->WinHeight = 0.054688;
	GetPassLabel->bBoundToParent = true;
	IncorrectPassword = "Incorrect password specified.  Please try again.";
	b_Cancel = GetPassFail;
	ed_Data = GetPassPW;
	b_OK = GetPassRetry;
	l_Text = GetPassLabel;
	bAllowedAsLast = true;
}

void UAAGetPassword::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	PlayerOwner().ClearProgressMessages();
	ed_Data.MyEditBox.bConvertSpaces = true;
	*/
}

void UAAGetPassword::HandleParameters(FString URL, FString FailCode)
{
	/*
	RetryURL = URL;
	if (FailCode ~= "WRONGPW")
	{
		l_Text.Caption = IncorrectPassword;
	}
	*/
}

bool UAAGetPassword::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_OK)
	{
		RetryPassword();
	}
	else
	{
		if (Sender == b_Cancel)
		{
			Controller.ReplaceMenu(Controller.GetServerBrowserPage());
		}
	}
	*/
	return true;
}

void UAAGetPassword::RetryPassword()
{
	/*
	FString EntryString = "";
	local XInterface.ExtendedConsole MyConsole;
	EntryString = ed_Data.GetText();
	MyConsole = ExtendedConsole(PlayerOwner().Player.Console);
	if ((MyConsole != None) && (EntryString != ""))
	{
		SavePassword(MyConsole, EntryString);
	}
	PlayerOwner().ClientTravel(Eval((EntryString != ""), RetryURL $ "?password=" $ EntryString, RetryURL), 0, false);
	Controller.CloseAll(false, true);
	*/
}

void UAAGetPassword::SavePassword(UExtendedConsole* InConsole, FString InPassword)
{
	/*
	int32 i = 0;
	if (InConsole != None)
	{
		i = 0;
		if (i < InConsole.SavedPasswords.Length)
		{
			if (InConsole.SavedPasswords[i].Server == InConsole.LastConnectedServer)
			{
				InConsole.SavedPasswords[i].Password = InPassword;
			}
			else
			{
				i++;
			}
		}
		if (i == InConsole.SavedPasswords.Length)
		{
			InConsole.SavedPasswords.Length = (InConsole.SavedPasswords.Length + 1);
			InConsole.SavedPasswords[i].Server = InConsole.LastConnectedServer;
			InConsole.SavedPasswords[i].Password = InPassword;
		}
		InConsole.SaveConfig();
	}
	*/
}