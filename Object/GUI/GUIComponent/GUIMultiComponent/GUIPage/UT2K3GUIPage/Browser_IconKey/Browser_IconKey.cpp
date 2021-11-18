// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/Browser_IconKey/Browser_IconKey.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UBrowser_IconKey::UBrowser_IconKey()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.75;
	OkButton->WinLeft = 0.4;
	OkButton->WinWidth = 0.2;
	//OkButton->OnClick=Browser_IconKey.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* DialogBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DialogBackground->StyleName = "ListBox";
	DialogBackground->WinTop = 0.256667;
	DialogBackground->WinLeft = 0.25;
	DialogBackground->WinWidth = 0.5;
	DialogBackground->WinHeight = 0.556251;
	DialogBackground->bBoundToParent = true;
	DialogBackground->bScaleToParent = true;
	DialogBackground->bAcceptsInput = false;
	DialogBackground->bNeverFocus = true;
	//DialogBackground->OnKeyEvent=DialogBackground.InternalOnKeyEvent;
	UGUILabel* DialogText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DialogText->Caption = "Server Icon Key";
	DialogText->TextAlign = ETextAlign::TXTA_Center;
	DialogText->TextColor = FColor(0, 180, 220, 255);
	DialogText->TextFont = "UT2HeaderFont";
	DialogText->WinTop = 0.278334;
	DialogText->WinHeight = 32;
	UGUIImage* Icon1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon1->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon1->WinTop = 0.35;
	Icon1->WinLeft = 0.3;
	Icon1->WinWidth = 16;
	Icon1->WinHeight = 16;
	UGUILabel* Label1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label1->TextColor = FColor(255, 255, 255, 255);
	Label1->StyleName = "TextLabel";
	Label1->WinTop = 0.34;
	Label1->WinLeft = 0.36;
	Label1->WinWidth = 0.35;
	Label1->WinHeight = 32;
	UGUIImage* Icon2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon2->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon2->WinTop = 0.41;
	Icon2->WinLeft = 0.3;
	Icon2->WinWidth = 16;
	Icon2->WinHeight = 16;
	UGUILabel* Label2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label2->TextColor = FColor(255, 255, 255, 255);
	Label2->StyleName = "TextLabel";
	Label2->WinTop = 0.4;
	Label2->WinLeft = 0.36;
	Label2->WinWidth = 0.35;
	Label2->WinHeight = 32;
	UGUIImage* Icon3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon3->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon3->WinTop = 0.47;
	Icon3->WinLeft = 0.3;
	Icon3->WinWidth = 16;
	Icon3->WinHeight = 16;
	UGUILabel* Label3 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label3->TextColor = FColor(255, 255, 255, 255);
	Label3->StyleName = "TextLabel";
	Label3->WinTop = 0.46;
	Label3->WinLeft = 0.36;
	Label3->WinWidth = 0.35;
	Label3->WinHeight = 32;
	UGUIImage* Icon4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon4->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon4->WinTop = 0.53;
	Icon4->WinLeft = 0.3;
	Icon4->WinWidth = 16;
	Icon4->WinHeight = 16;
	UGUILabel* Label4 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label4->TextColor = FColor(255, 255, 255, 255);
	Label4->StyleName = "TextLabel";
	Label4->WinTop = 0.52;
	Label4->WinLeft = 0.36;
	Label4->WinWidth = 0.35;
	Label4->WinHeight = 32;
	UGUIImage* Icon5 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon5->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon5->WinTop = 0.59;
	Icon5->WinLeft = 0.3;
	Icon5->WinWidth = 16;
	Icon5->WinHeight = 16;
	UGUILabel* Label5 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label5->TextColor = FColor(255, 255, 255, 255);
	Label5->StyleName = "TextLabel";
	Label5->WinTop = 0.58;
	Label5->WinLeft = 0.36;
	Label5->WinWidth = 0.35;
	Label5->WinHeight = 32;
	UGUIImage* Icon6 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon6->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon6->WinTop = 0.65;
	Icon6->WinLeft = 0.3;
	Icon6->WinWidth = 16;
	Icon6->WinHeight = 16;
	UGUILabel* Label6 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label6->TextColor = FColor(255, 255, 255, 255);
	Label6->StyleName = "TextLabel";
	Label6->WinTop = 0.64;
	Label6->WinLeft = 0.36;
	Label6->WinWidth = 0.35;
	Label6->WinHeight = 32;
	UGUIImage* Icon7 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Icon7->ImageStyle = EImgStyle::ISTY_Scaled;
	Icon7->WinTop = 0.71;
	Icon7->WinLeft = 0.3;
	Icon7->WinWidth = 16;
	Icon7->WinHeight = 16;
	UGUILabel* Label7 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Label7->TextColor = FColor(255, 255, 255, 255);
	Label7->StyleName = "TextLabel";
	Label7->WinTop = 0.7;
	Label7->WinLeft = 0.36;
	Label7->WinWidth = 0.35;
	Label7->WinHeight = 32;
	bRequire640x480 = false;
	Controls = { DialogBackground,OkButton,DialogText,Icon1,Label1,Icon2,Label2,Icon3,Label3,Icon4,Label4,Icon5,Label5,Icon6,Label6,Icon7,Label7 };
	WinHeight = 1;
}

bool UBrowser_IconKey::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void UBrowser_IconKey::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < 7; i++)
	{
		GUIImage(Controls[(3 + (2 * i))]).Image = class'XInterface.Browser_ServersList'.Default.Icons[i];
		GUILabel(Controls[(4 + (2 * i))]).Caption = class'XInterface.Browser_ServersList'.Default.IconDescriptions[i];
	}
	*/
}
