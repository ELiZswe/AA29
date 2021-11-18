// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAGameMenu_DCDS_Complete/AAGameMenu_DCDS_Complete.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAGameMenu_DCDS_Complete::UAAGameMenu_DCDS_Complete()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.85;
	OkButton->WinLeft = 0.375;
	OkButton->WinWidth = 0.25;
	OkButton->WinHeight = 0.1;
	OkButton->TabOrder = 1;
	OkButton->bBoundToParent = true;
	OkButton->bScaleToParent = true;
	//OkButton->OnClick=AAGameMenu_DCDS_Complete.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UAAGUILabel* HeadingLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	HeadingLabel->Caption = "DCDS Download";
	HeadingLabel->TextAlign = ETextAlign::TXTA_Center;
	HeadingLabel->TextColor = FColor(200, 200, 200, 255);
	HeadingLabel->TextFont = "AAFontLarge";
	HeadingLabel->StyleName = "LargeText";
	HeadingLabel->WinTop = 0.1;
	HeadingLabel->WinLeft = 0.04;
	HeadingLabel->WinWidth = 0.96;
	HeadingLabel->WinHeight = 0.1;
	HeadingLabel->RenderWeight = 0.3;
	HeadingLabel->bBoundToParent = true;
	HeadingLabel->bScaleToParent = true;
	UAAGUILabel* CaptionLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	CaptionLabel->TextAlign = ETextAlign::TXTA_Center;
	CaptionLabel->TextColor = FColor(200, 200, 200, 255);
	CaptionLabel->TextFont = "AAFontMedium";
	CaptionLabel->bMultiLine = true;
	CaptionLabel->StyleName = "MediumText";
	CaptionLabel->WinTop = 0.3;
	CaptionLabel->WinLeft = 0.04;
	CaptionLabel->WinWidth = 0.96;
	CaptionLabel->WinHeight = 0.1;
	CaptionLabel->RenderWeight = 0.3;
	CaptionLabel->bBoundToParent = true;
	CaptionLabel->bScaleToParent = true;
	l_Heading = HeadingLabel;
	l_Caption = CaptionLabel;
	b_OK = OkButton;
	WinTop = 0.225;
	WinLeft = 0.25;
	WinWidth = 0.55;
	WinHeight = 0.5;
}

void UAAGameMenu_DCDS_Complete::HandleParameters(FString Param1, FString Param2)
{
	/*
	Super::HandleParameters(Param1, Param2);
	l_Caption.Caption = Param2;
	*/
}

bool UAAGameMenu_DCDS_Complete::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_OK:
		Controller.CloseMenu();
		return true;
	default:
	}
	*/
	return false;     //FAKE   /ELIZ
}