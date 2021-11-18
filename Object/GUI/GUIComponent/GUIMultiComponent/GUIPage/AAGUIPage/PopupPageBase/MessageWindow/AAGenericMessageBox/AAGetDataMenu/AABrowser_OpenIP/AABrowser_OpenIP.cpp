// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AABrowser_OpenIP/AABrowser_OpenIP.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAABrowser_OpenIP::UAABrowser_OpenIP()
{
	UmoEditBox* IpEntryBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	IpEntryBox->LabelJustification = EeTextAlign::TXTA_Right;
	IpEntryBox->CaptionWidth = 0.55;
	IpEntryBox->Caption = "IP Address: ";
	//IpEntryBox->OnCreateComponent=IpEntryBox.InternalOnCreateComponent;
	IpEntryBox->WinTop = 0.466667;
	IpEntryBox->WinLeft = 0.16;
	IpEntryBox->WinHeight = 0.04;
	IpEntryBox->TabOrder = 0;
	UGUILabel* IPDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IPDesc->Caption = "Enter New IP Address";
	IPDesc->TextAlign = ETextAlign::TXTA_Center;
	IPDesc->FontScale = EFontScale::FNS_Large;
	IPDesc->StyleName = "TextLabel";
	IPDesc->WinTop = 0.4;
	IPDesc->WinHeight = 32;
	OKButtonHint = "Open a connection to this IP address.";
	CancelButtonHint = "Close this page without connecting to a server.";
	EditBoxHint = "Enter the address for the server you'd like to connect to - separate the IP and port with the  :  symbol";
	ed_Data = IpEntryBox;
	l_Text = IPDesc;
}

void UAABrowser_OpenIP::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(pMyController, MyOwner);
	ed_Data.MyEditBox.__OnKeyEvent__Delegate = InternalOnKeyEvent;
	b_OK.SetHint(OKButtonHint);
	b_Cancel.SetHint(CancelButtonHint);
	ed_Data.SetHint(EditBoxHint);
	*/
}

void UAABrowser_OpenIP::HandleParameters(FString S, FString s2)
{
	/*
	if (S != "")
	{
		ed_Data.SetText(StripProtocol(S));
	}
	*/
}

bool UAABrowser_OpenIP::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_OK)
	{
		Execute();
	}
	else
	{
		Controller.CloseMenu(true);
	}
	*/
	return true;
}

void UAABrowser_OpenIP::Execute()
{
	/*
	FString URL = "";
	URL = ed_Data.GetText();
	if (URL == "")
	{
		return;
	}
	URL = StripProtocol(URL);
	if (InStr(URL, ":") == -1)
	{
		(URL $ = ":7777");
	}
	ApplyURL(URL);
	*/
}

void UAABrowser_OpenIP::ApplyURL(FString URL)
{
	/*
	if ((URL == "") || (Left(URL, 1) == ":"))
	{
		return;
	}
	PlayerOwner().ClientTravel(URL, 0, false);
	Controller.CloseAll(false, true);
	*/
}

bool UAABrowser_OpenIP::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (!Super::InternalOnKeyEvent(Key, State, Delta))
	{
		return ed_Data.MyEditBox.InternalOnKeyEvent(Key, State, Delta);
	}
	*/
	return false;    //FAKE   /ELiZ
}

FString UAABrowser_OpenIP::StripProtocol(FString S)
{
	/*
	FString Protocol = "";
	Protocol = PlayerOwner().GetURLProtocol();
	ReplaceText(S, Protocol $ "://", "");
	ReplaceText(S, Protocol, "");
	*/
	return S;
}