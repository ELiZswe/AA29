// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIImageStateButton/GUIImageStateButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUIImageStateButton::UGUIImageStateButton()
{
	UGUIGFXButton* MyImage = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	MyImage->Position = EIconPosition::ICP_Scaled;
	MyImage->bClientBound = true;
	MyImage->WinHeight = 1;
	//MyImage->OnClick=GUIImageStateButton.ButtonClick;
	//MyImage->OnKeyEvent=MyImage.InternalOnKeyEvent;
	UGUILabel* MyLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyLabel->Caption = "My text";
	MyLabel->StyleName = "TextLabel";
	MyLabel->WinHeight = 1;
	LabelStyleName = "TextLabel";
	LabelSelStyleName = "TextLabel";
	ImageStyleName = "ImageBorder";
	ImageSelStyleName = "ImageBorderSelected";
	LabelHeight = 0.020833;
	ImageButton = MyImage;
	Label = MyLabel;
	//OnPreDraw = GUIImageStateButton.InternalOnPreDraw;
}

void UGUIImageStateButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	Label.Caption = Caption;
	Label.Style = Controller.GetStyle(LabelStyleName, FontScale);
	Label.MenuState = ImageButton.MenuState;
	ImageButton.SetFriendlyLabel(Label);
	ImageButton.Graphic = Image;
	ImageButton.Style = Controller.GetStyle(ImageStyleName, FontScale);
	*/
}

void UGUIImageStateButton::SetSelected(bool bSelected)
{
	/*
	if (bSelected)
	{
		Label.Style = Controller.GetStyle(LabelSelStyleName, FontScale);
		ImageButton.Style = Controller.GetStyle(ImageSelStyleName, FontScale);
	}
	else
	{
		Label.Style = Controller.GetStyle(LabelStyleName, FontScale);
		ImageButton.Style = Controller.GetStyle(ImageStyleName, FontScale);
	}
	*/
}

bool UGUIImageStateButton::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	local float ALabelHeight;
	Label.Caption = Caption;
	ImageButton.Graphic = Image;
	if (LabelHeight < 2)
	{
		ALabelHeight = LabelHeight * Controller.ResY;
	}
	else
	{
		ALabelHeight = LabelHeight;
	}
	Label.WinLeft = ClientBounds[0];
	Label.WinTop = ClientBounds[1];
	Label.WinWidth = ClientBounds[2] - ClientBounds[0];
	Label.WinHeight = ALabelHeight;
	ImageButton.WinLeft = ClientBounds[0];
	ImageButton.WinTop = ClientBounds[1] + ALabelHeight;
	ImageButton.WinWidth = ClientBounds[2] - ClientBounds[0];
	ImageButton.WinHeight = ClientBounds[3] - ClientBounds[1] - ALabelHeight;
	*/
	return false;
}

bool UGUIImageStateButton::ButtonClick(UGUIComponent* Sender)
{
	//OnClick(Self);
	return true;
}