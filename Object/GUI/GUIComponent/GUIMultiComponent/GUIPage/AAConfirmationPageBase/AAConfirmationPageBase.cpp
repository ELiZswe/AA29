// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAConfirmationPageBase/AAConfirmationPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAConfirmationPageBase::UAAConfirmationPageBase()
{
	UGUIButton* NoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NoButton->StyleName="AASquareMenuButton";
	//NoButton->OnClick=AAConfirmationPageBase.ClickNo;
	//NoButton->OnKeyEvent=NoButton.InternalOnKeyEvent;
	UGUIButton* YesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	YesButton->StyleName="AASquareMenuButton";
	//YesButton->OnClick=AAConfirmationPageBase.ClickYes;
	//YesButton->OnKeyEvent=YesButton.InternalOnKeyEvent;
	UGUIButton* QuitBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitBackground->StyleName="AABackBox";
	QuitBackground->bAcceptsInput=false;
	QuitBackground->bNeverFocus=true;
	//QuitBackground->OnKeyEvent=QuitBackground.InternalOnKeyEvent;
	UGUILabel* QuitDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	QuitDesc->TextAlign = ETextAlign::TXTA_Center;
	QuitDesc->TextColor=FColor(0, 180, 220, 255);
	QuitDesc->TextFont="AAFontHeader";
	QuitDesc->bMultiLine=true;

	ConfirmCaption = "YES";
	DenyCaption = "NO";
	DescriptionCaption = "Confirm your choice";
	Controls = { QuitBackground,  YesButton, NoButton, QuitDesc };
	WinHeight = 200;
}

//const BACKGRND = 0;
//const BUTTN_YES = 1;
//const BUTTN_NO = 2;
//const TEXT_LABEL = 3;
//const GUTTER_WIDTH = 170;
//const MIN_WIDTH = 400;
//const BUTTN_WIDTH = 160;
//const BUTTN_HEIGHT = 28;
//const BUTTN_SPACE = 30;
//const TEXT_HEIGHT = 50;
//const TOP_SPACE = 40;
//const BTM_SPACE = 40;

void UAAConfirmationPageBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 i;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].bScaleToParent = true;
		Controls[i].bBoundToParent = true;
	}
	GUILabel(Controls[3]).Caption = DescriptionCaption;
	GUIButton(Controls[1]).Caption = ConfirmCaption;
	GUIButton(Controls[2]).Caption = DenyCaption;
	if (bConfirmOnly)
	{
		Controls[2].bVisible = false;
	}
	else
	{
		if (bDenyOnly)
		{
			Controls[1].bVisible = false;
		}
	}
	*/
}

void UAAConfirmationPageBase::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 == "")
	{
		leftSpace = 170;
	}
	else
	{
		leftSpace = float(Param1);
	}
	Super::HandleParameters(Param1, Param2);
	*/
}

bool UAAConfirmationPageBase::ClickYes(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

bool UAAConfirmationPageBase::ClickNo(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}