// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AABrowser_OpenIP/EditFavoritePage/EditFavoritePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UEditFavoritePage::UEditFavoritePage()
{
	UmoEditBox* IpEntryBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	IpEntryBox->ComponentJustification = EeTextAlign::TXTA_Left;
	IpEntryBox->CaptionWidth = 0.35;
	IpEntryBox->Caption = "IP Address: ";
	//IpEntryBox->OnCreateComponent=IpEntryBox.InternalOnCreateComponent;
	IpEntryBox->WinTop = 0.4875;
	IpEntryBox->WinLeft = 0.192383;
	IpEntryBox->WinWidth = 0.59082;
	IpEntryBox->TabOrder = 0;
	UGUILabel* ServerName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerName->TextAlign = ETextAlign::TXTA_Center;
	ServerName->StyleName = "TextLabel";
	ServerName->WinTop = 0.299479;
	ServerName->WinLeft = 0.070313;
	ServerName->WinWidth = 0.854492;
	ServerName->WinHeight = 0.05;
	l_name = ServerName;
	UnknownText = "Unknown Server";
	OKButtonHint = "Close the page and save the new IP to your favorites list.";
	CancelButtonHint = "Close the page and discard any changes.";
	EditBoxHint = "Enter the URL for this favorite - separate IP and port with the   :   symbol";
	ed_Data = IpEntryBox;
}


void UEditFavoritePage::HandleParameters(FString ServerIP, FString ServerName)
{
	/*
	if (ServerIP != "")
	{
		ed_Data.SetText(StripProtocol(ServerIP));
	}
	if (ServerName == "")
	{
		ServerName = UnknownText;
	}
	l_name.Caption = ServerName;
	*/
}

void UEditFavoritePage::ApplyURL(FString URL)
{
	/*
	FString IP = "";
	FString Port = "";
	if (URL == "")
	{
		return;
	}
	URL = StripProtocol(URL);
	if (!Divide(URL, ":", IP, Port))
	{
		IP = URL;
		Port = "7777";
	}
	Server.IP = IP;
	Server.Port = int(Port);
	Server.QueryPort = (Server.Port + 1);
	Server.ServerName = l_name.Caption;
	Controller.CloseMenu(false);
	*/
}