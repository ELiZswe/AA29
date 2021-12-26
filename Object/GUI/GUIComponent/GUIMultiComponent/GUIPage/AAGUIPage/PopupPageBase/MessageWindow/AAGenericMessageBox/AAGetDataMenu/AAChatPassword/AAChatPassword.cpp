// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAChatPassword/AAChatPassword.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAChatPassword::UAAChatPassword()
{
	UGUIButton* GetPassFail = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassFail->Caption = "CANCEL";
	GetPassFail->WinTop = 0.561667;
	GetPassFail->WinLeft = 0.586523;
	GetPassFail->WinWidth = 0.1475;
	GetPassFail->WinHeight = 0.045;
	GetPassFail->TabOrder = 2;
	GetPassFail->bBoundToParent = true;
	//GetPassFail->OnClick=AAChatPassword.InternalOnClick;
	//GetPassFail->OnKeyEvent=GetPassFail.InternalOnKeyEvent;
	UGUIButton* GetPassRetry = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetPassRetry->Caption = "RETRY";
	GetPassRetry->WinTop = 0.561667;
	GetPassRetry->WinLeft = 0.346289;
	GetPassRetry->WinWidth = 0.131641;
	GetPassRetry->TabOrder = 1;
	GetPassRetry->bBoundToParent = true;
	//GetPassRetry->OnClick=AAChatPassword.InternalOnClick;
	//GetPassRetry->OnKeyEvent=GetPassRetry.InternalOnKeyEvent;
	UmoEditBox* GetPassPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	GetPassPW->CaptionWidth = 0.4;
	GetPassPW->Caption = "Chat Room Password";
	//GetPassPW->OnCreateComponent=GetPassPW.InternalOnCreateComponent;
	GetPassPW->WinTop = 0.49745;
	GetPassPW->WinLeft = 0.2125;
	GetPassPW->WinWidth = 0.643751;
	GetPassPW->WinHeight = 0.047305;
	GetPassPW->TabOrder = 0;
	UGUILabel* GetPassLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GetPassLabel->Caption = "A password is required to join this chat room";
	GetPassLabel->TextAlign = ETextAlign::TXTA_Center;
	GetPassLabel->bMultiLine = true;
	GetPassLabel->FontScale = EFontScale::FNS_Large;
	GetPassLabel->StyleName = "TextLabel";
	GetPassLabel->WinTop = 0.318897;
	GetPassLabel->WinLeft = 0.010742;
	GetPassLabel->WinWidth = 0.995117;
	GetPassLabel->WinHeight = 0.054688;
	GetPassLabel->bBoundToParent = true;
	IncorrectPassword = "Incorrect password specified for channel '%ChatRoom%' .";
	b_Cancel = GetPassFail;
	ed_Data = GetPassPW;
	b_OK = GetPassRetry;
	l_Text = GetPassLabel;
	bAllowedAsLast = true;
}

void UAAChatPassword::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	PlayerOwner().ClearProgressMessages();
	ed_Data.MyEditBox.bConvertSpaces = true;
	ed_Data.MaskText(true);
	*/
}

void UAAChatPassword::HandleParameters(FString Title, FString FailCode)
{
	/*
	ChatRoomTitle = Title;
	if (FailCode ~= "WRONGPW")
	{
		l_Text.Caption = Repl(IncorrectPassword, "%ChatRoom%", ChatRoomTitle);
	}
	*/
}

bool UAAChatPassword::InternalOnClick(UGUIComponent* Sender)
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
			Controller.CloseMenu(true);
		}
	}
	*/
	return true;
}

void UAAChatPassword::RetryPassword()
{
	/*
	FString Password = "";
	local PlayerController PC;
	Password = GetDataString();
	PC = PlayerOwner();
	if ((Password == "") || (PC == nullptr))
	{
		return;
	}
	Controller.CloseAll(false, true);
	PC.Join(ChatRoomTitle, Password);
	*/
}