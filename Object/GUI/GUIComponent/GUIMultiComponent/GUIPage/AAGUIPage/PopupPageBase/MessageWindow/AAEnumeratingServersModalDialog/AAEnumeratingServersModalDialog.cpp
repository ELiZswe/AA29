// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAEnumeratingServersModalDialog/AAEnumeratingServersModalDialog.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAEnumeratingServersModalDialog::UAAEnumeratingServersModalDialog()
{
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "Obtaining list of Internet Servers.";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->VertAlign = ETextAlign::TXTA_Center;
	DialogText->FontScale = EFontScale::FNS_Large;
	DialogText->StyleName = "TextButton";
	DialogText->WinTop = 0.389843;
	DialogText->WinLeft = 0.056771;
	DialogText->WinWidth = 0.884722;
	DialogText->WinHeight = 0.042149;
	UGUILabel* DialogText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText2->TextAlign = ETextAlign::TXTA_Center;
	DialogText2->bMultiLine = true;
	DialogText2->StyleName = "TextLabel";
	DialogText2->WinTop = 0.431249;
	DialogText2->WinLeft = 0.04375;
	DialogText2->WinWidth = 0.9125;
	DialogText2->WinHeight = 0.126524;
	l_Text = DialogText;
	l_Text2 = DialogText2;
	UpdateMessage = "%BYTES% bytes received.";
	//OnOpen = AAEnumeratingServersModalDialog.InternalOnOpen;
	//OnTimer = AAEnumeratingServersModalDialog.InternalOnTimer;
	//OnKeyEvent = AAEnumeratingServersModalDialog.InternalOnKeyEvent;
}

void UAAEnumeratingServersModalDialog::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 != "")
	{
		l_Text.Caption = Param1;
	}
	if (Param2 != "")
	{
		l_Text2.Caption = Param2;
	}
	*/
}

void UAAEnumeratingServersModalDialog::InternalOnOpen()
{
	//SetTimer(0.1, true);
}

void UAAEnumeratingServersModalDialog::InternalOnTimer(UGUIComponent* Sender)
{
	/*
	local DBAuth.ServerBrowserDBMBS ServerBrowser;
	int32 BytesRecieved = 0;
	ServerBrowser = ServerBrowserDBMBS(AGP_HUD(PlayerOwner().myHUD).GetCurrentServerBrowser());
	if (None != ServerBrowser)
	{
		BytesRecieved = ServerBrowser.GetUpdateServerListProgressAsByteCount();
		l_Text2.Caption = Repl(UpdateMessage, "%BYTES%", string(BytesRecieved));
	}
	*/
}

bool UAAEnumeratingServersModalDialog::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	return true;
}