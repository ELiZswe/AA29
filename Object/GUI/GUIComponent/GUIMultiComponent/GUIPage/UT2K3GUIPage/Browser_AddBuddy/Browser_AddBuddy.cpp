// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/Browser_AddBuddy/Browser_AddBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UBrowser_AddBuddy::UBrowser_AddBuddy()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.75;
	OkButton->WinLeft = 0.125;
	OkButton->WinWidth = 0.2;
	OkButton->bBoundToParent = true;
	//OkButton->OnClick=Browser_AddBuddy.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "CANCEL";
	CancelButton->WinTop = 0.75;
	CancelButton->WinLeft = 0.65;
	CancelButton->WinWidth = 0.2;
	CancelButton->bBoundToParent = true;
	//CancelButton->OnClick=Browser_AddBuddy.InternalOnClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UmoEditBox* BuddyEntryBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	BuddyEntryBox->LabelJustification = EeTextAlign::TXTA_Right;
	BuddyEntryBox->CaptionWidth = 0.55;
	BuddyEntryBox->Caption = "Buddy Name: ";
	BuddyEntryBox->LabelFont = "UT2SmallFont";
	BuddyEntryBox->LabelColor = FColor(255, 255, 255, 255);
	//BuddyEntryBox->OnCreateComponent=BuddyEntryBox.InternalOnCreateComponent;
	BuddyEntryBox->WinTop = 0.466667;
	BuddyEntryBox->WinLeft = 0.16;
	BuddyEntryBox->WinHeight = 0.05;
	UGUIButton* VidOKBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VidOKBackground->StyleName = "SquareBar";
	VidOKBackground->WinHeight = 1;
	VidOKBackground->bBoundToParent = true;
	VidOKBackground->bScaleToParent = true;
	VidOKBackground->bAcceptsInput = false;
	VidOKBackground->bNeverFocus = true;
	//VidOKBackground->OnKeyEvent=VidOKBackground.InternalOnKeyEvent;
	UGUILabel* AddBuddyDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AddBuddyDesc->Caption = "Add Buddy";
	AddBuddyDesc->TextAlign = ETextAlign::TXTA_Center;
	AddBuddyDesc->TextColor = FColor(0, 200, 230, 255);
	AddBuddyDesc->TextFont = "UT2HeaderFont";
	AddBuddyDesc->WinTop = 0.4;
	AddBuddyDesc->WinHeight = 32;
	Controls = { VidOKBackground,BuddyEntryBox,CancelButton,AddBuddyDesc,OkButton };
	WinTop = 0.375;
	WinHeight = 0.25;
}

void UBrowser_AddBuddy::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(pMyController, MyOwner);
	//MyNewBuddy = moEditBox(Controls[1]);
}

bool UBrowser_AddBuddy::InternalOnClick(UGUIComponent* Sender)
{
	/*
	FString buddyName = "";
	if (Sender == Controls[4])
	{
		buddyName = MyNewBuddy.GetText();
		if (buddyName == "")
		{
			return true;
		}
		MyBuddyPage.Buddies.Length = (MyBuddyPage.Buddies.Length + 1);
		MyBuddyPage.Buddies[(MyBuddyPage.Buddies.Length - 1)] = buddyName;
		MyBuddyPage.MyBuddyList.ItemCount = MyBuddyPage.Buddies.Length;
		MyBuddyPage.SaveConfig();
	}
	Controller.CloseMenu(false);
	*/
	return true;
}