// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/Browser_OpenIP/Browser_OpenIP.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UBrowser_OpenIP::UBrowser_OpenIP()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.75;
	OkButton->WinLeft = 0.125;
	OkButton->WinWidth = 0.2;
	OkButton->bBoundToParent = true;
	//OkButton->OnClick=Browser_OpenIP.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "CANCEL";
	CancelButton->WinTop = 0.75;
	CancelButton->WinLeft = 0.65;
	CancelButton->WinWidth = 0.2;
	CancelButton->bBoundToParent = true;
	//CancelButton->OnClick=Browser_OpenIP.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UmoEditBox* IpEntryBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	IpEntryBox->LabelJustification = EeTextAlign::TXTA_Right;
	IpEntryBox->CaptionWidth = 0.55;
	IpEntryBox->Caption = "IP Address: ";
	IpEntryBox->LabelFont = "UT2SmallFont";
	IpEntryBox->LabelColor = FColor(255, 255, 255, 255);
	//IpEntryBox->OnCreateComponent=IpEntryBox.InternalOnCreateComponent;
	IpEntryBox->WinTop = 0.466667;
	IpEntryBox->WinLeft = 0.16;
	IpEntryBox->WinHeight = 0.05;
	UGUIButton* VidOKBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VidOKBackground->StyleName = "SquareBar";
	VidOKBackground->WinHeight = 1;
	VidOKBackground->bBoundToParent = true;
	VidOKBackground->bScaleToParent = true;
	VidOKBackground->bAcceptsInput = false;
	VidOKBackground->bNeverFocus = true;
	//VidOKBackground->OnKeyEvent=VidOKBackground.InternalOnKeyEvent;
	UGUILabel* OpenIPDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	OpenIPDesc->Caption = "Enter New IP Address";
	OpenIPDesc->TextAlign = ETextAlign::TXTA_Center;
	OpenIPDesc->TextColor = FColor(0, 200, 230, 255);
	OpenIPDesc->TextFont = "UT2HeaderFont";
	OpenIPDesc->WinTop = 0.4;
	OpenIPDesc->WinHeight = 32;
	Controls = { VidOKBackground,IpEntryBox,CancelButton,OpenIPDesc,OkButton };
	WinTop = 0.375;
	WinHeight = 0.25;
}

void UBrowser_OpenIP::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(pMyController, MyOwner);
	MyIpAddress = moEditBox(Controls[1]);
	MyIpAddress.MyEditBox.AllowedCharSet = "0123456789.:";
	*/
}

bool UBrowser_OpenIP::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local GameInfo.ServerResponseLine S;
	FString Address = "";
	FString IPString = "";
	FString portString = "";
	int32 colonPos = 0;
	int32 portNum = 0;
	if (Sender == Controls[4])
	{
		Address = MyIpAddress.GetText();
		if (Address == "")
		{
			return true;
		}
		colonPos = InStr(Address, ":");
		if (colonPos < 0)
		{
			IPString = Address;
			portNum = 7777;
		}
		else
		{
			IPString = Left(Address, colonPos);
			portString = Mid(Address, (colonPos + 1));
			portNum = int(portString);
		}
		S.IP = IPString;
		S.Port = portNum;
		S.QueryPort = (portNum + 1);
		S.ServerName = "Unknown";
		MyFavoritesPage.MyAddFavorite(S);
	}
	Controller.CloseMenu(false);
	*/
	return true;
}