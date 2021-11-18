// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenerateKeyModalDialog/AAGenerateKeyModalDialog.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/KeyGenerator/KeyGenerator.h"

UAAGenerateKeyModalDialog::UAAGenerateKeyModalDialog()
{
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
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
	//OnOpen = AAGenerateKeyModalDialog.InternalOnOpen;
	//OnClose = AAGenerateKeyModalDialog.InternalOnClose;
	//OnCanClose = AAGenerateKeyModalDialog.InternalOnCanClose;
	//OnTimer = AAGenerateKeyModalDialog.InternalOnTimer;
	//OnKeyEvent = AAGenerateKeyModalDialog.InternalOnKeyEvent;
}

void UAAGenerateKeyModalDialog::HandleParameters(FString Param1, FString Param2)
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

void UAAGenerateKeyModalDialog::InternalOnOpen()
{
	/*
	KeyGenerator = new () classClass'DBAuth.KeyGenerator';
	KeyGenerator.BeginKeyGeneration();
	SetTimer(0.1, true);
	*/
}

void UAAGenerateKeyModalDialog::InternalOnTimer(UGUIComponent* Sender)
{
	//Controller.CloseMenu();
}

bool UAAGenerateKeyModalDialog::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	return true;
}

bool UAAGenerateKeyModalDialog::InternalOnCanClose(bool bCancelled)
{
	return KeyGenerator->IsKeyGenerationComplete();
}

void UAAGenerateKeyModalDialog::InternalOnClose(bool bCancelled)
{
}