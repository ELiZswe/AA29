// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUIVertScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIVertScrollZone/GUIVertScrollZone.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIVertScrollButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIVertGripButton/GUIVertGripButton.h"

UGUIVertScrollBar::UGUIVertScrollBar()
{
	UGUIVertScrollZone* ScrollZone = NewObject<UGUIVertScrollZone>(UGUIVertScrollZone::StaticClass());
	//ScrollZone->OnScrollZoneClick = GUIVertScrollBar.ZoneClick;
	//ScrollZone->OnClick=ScrollZone.InternalOnClick;
	UGUIVertScrollButton* DownBut = NewObject<UGUIVertScrollButton>(UGUIVertScrollButton::StaticClass());
	DownBut->bIncreaseButton = true;
	//DownBut->OnClick=GUIVertScrollBar.IncreaseClick;
	//DownBut->OnKeyEvent=DownBut.InternalOnKeyEvent;
	UGUIVertScrollButton* UpBut = NewObject<UGUIVertScrollButton>(UGUIVertScrollButton::StaticClass());
	//UpBut->OnClick=GUIVertScrollBar.DecreaseClick;
	//UpBut->OnKeyEvent=UpBut.InternalOnKeyEvent;
	UGUIVertGripButton* Grip = NewObject<UGUIVertGripButton>(UGUIVertGripButton::StaticClass());
	//Grip->OnMousePressed=GUIVertScrollBar.GripPressed;
	//Grip->OnKeyEvent=Grip.InternalOnKeyEvent;
	MinGripPixels = 12;
	MyScrollZone = ScrollZone;
	MyIncreaseButton = DownBut;
	MyDecreaseButton = UpBut;
	MyGripButton = Grip;
	WinWidth = 0.025;
	bAcceptsInput = true;
	//OnPreDraw = GUIVertScrollBar.GripPreDraw;
}

void UGUIVertScrollBar::GripPressed(UGUIComponent* Sender, bool IsRepeat)
{
	/*
	if (!IsRepeat)
	{
		GrabOffset = (Controller.MouseY - MyGripButton.ActualTop());
	}
	*/
}

bool UGUIVertScrollBar::GripPreDraw(UGUIComponent* Sender)
{
	/*
	float NewPerc = 0;
	if (MyGripButton.MenuState != 3)
	{
		return false;
	}
	NewPerc = FClamp((((Controller.MouseY - GrabOffset) - MyScrollZone.ActualTop()) / (MyScrollZone.ActualHeight() - GripSize)), 0, 1);
	UpdateGripPosition(NewPerc);
	*/
	return true;
}

void UGUIVertScrollBar::ZoneClick(float Delta)
{
	/*
	if (Controller.MouseY < MyGripButton.Bounds[1])
	{
		MoveGripBy((-BigStep));
	}
	else
	{
		if (Controller.MouseY > MyGripButton.Bounds[3])
		{
			MoveGripBy(BigStep);
		}
	}
	*/
}
