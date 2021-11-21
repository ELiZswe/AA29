// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIHorzScrollBar/GUIHorzScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIHorzGripButton/GUIHorzGripButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIHorzScrollButton/GUIHorzScrollButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIHorzScrollZone/GUIHorzScrollZone.h"

UGUIHorzScrollBar::UGUIHorzScrollBar()
{
	UGUIHorzGripButton* HGrip = NewObject<UGUIHorzGripButton>(UGUIHorzGripButton::StaticClass());
	//HGrip->OnMousePressed=GUIHorzScrollBar.GripPressed;
	//HGrip->OnKeyEvent=HGrip.InternalOnKeyEvent;
	UGUIHorzScrollButton* HRightBut = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	HRightBut->bIncreaseButton = true;
	//HRightBut->OnClick=GUIHorzScrollBar.IncreaseClick;
	//HRightBut->OnKeyEvent=HRightBut.InternalOnKeyEvent;
	UGUIHorzScrollButton* HLeftBut = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	//HLeftBut->OnClick=GUIHorzScrollBar.DecreaseClick;
	//HLeftBut->OnKeyEvent=HLeftBut.InternalOnKeyEvent;
	UGUIHorzScrollZone* HScrollZone = NewObject<UGUIHorzScrollZone>(UGUIHorzScrollZone::StaticClass());
	//HScrollZone->OnScrollZoneClick = GUIHorzScrollBar.ZoneClick;
	//HScrollZone->OnClick=HScrollZone.InternalOnClick;
	Orientation = EAA2Orientation::ORIENT_Horizontal;
	MinGripPixels = 12;
	MyScrollZone = HScrollZone;
	MyIncreaseButton = HRightBut;
	MyDecreaseButton = HLeftBut;
	MyGripButton = HGrip;
	WinWidth = 0.0375;
	bAcceptsInput = true;
	//OnPreDraw = GUIHorzScrollBar.GripPreDraw;
}

void UGUIHorzScrollBar::GripPressed(UGUIComponent* Sender, bool IsRepeat)
{
	/*
	if (!IsRepeat)
	{
		GrabOffset = (Controller.MouseX - MyGripButton.ActualLeft());
	}
	*/
}

bool UGUIHorzScrollBar::GripPreDraw(UGUIComponent* Sender)
{
	/*
	float NewPerc = 0;
	if (MyGripButton.MenuState != 3)
	{
		return false;
	}
	NewPerc = FClamp((((Controller.MouseX - GrabOffset) - MyScrollZone.ActualLeft()) / (MyScrollZone.ActualWidth() - GripSize)), 0, 1);
	UpdateGripPosition(NewPerc);
	*/
	return false;
}

void UGUIHorzScrollBar::ZoneClick(float Delta)
{

	/*
	if (Controller.MouseX < MyGripButton.Bounds[0])
	{
		MoveGripBy((-BigStep));
	}
	else
	{
		if (Controller.MouseX > MyGripButton.Bounds[2])
		{
			MoveGripBy(BigStep);
		}
	}
	*/
}
