// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIContentScrollBar/GUIContentScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIVertGripButton/GUIVertGripButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIVertScrollButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIVertScrollZone/GUIVertScrollZone.h"

UGUIContentScrollBar::UGUIContentScrollBar()
{
	UGUIVertGripButton* Grip = NewObject<UGUIVertGripButton>(UGUIVertGripButton::StaticClass());
	//Grip->OnMousePressed=GUIContentScrollBar.GripPressed;
	//Grip->OnKeyEvent=Grip.InternalOnKeyEvent;
	UGUIVertScrollButton* DownBut = NewObject<UGUIVertScrollButton>(UGUIVertScrollButton::StaticClass());
	DownBut->bIncreaseButton = true;
	//DownBut->OnClick=GUIContentScrollBar.IncreaseClick;
	//DownBut->OnKeyEvent=DownBut.InternalOnKeyEvent;
	UGUIVertScrollButton* UpBut = NewObject<UGUIVertScrollButton>(UGUIVertScrollButton::StaticClass());
	//UpBut->OnClick=GUIContentScrollBar.DecreaseClick;
	//UpBut->OnKeyEvent=UpBut.InternalOnKeyEvent;
	UGUIVertScrollZone* ScrollZone = NewObject<UGUIVertScrollZone>(UGUIVertScrollZone::StaticClass());
	//ScrollZone->OnScrollZoneClick = GUIContentScrollBar.ZoneClick;
	//ScrollZone->OnClick=ScrollZone.InternalOnClick;
	StepPct = 0.1;
	BigStepPct = 1;
	MinGripPixels = 12;
	MyScrollZone = ScrollZone;
	MyIncreaseButton = DownBut;
	MyDecreaseButton = UpBut;
	MyGripButton = Grip;
	WinWidth = 0.025;
	bAcceptsInput = true;
	//OnPreDraw = GUIContentScrollBar.GripPreDraw;
}

void UGUIContentScrollBar::SetList(UGUIListBase* List)
{
}

void UGUIContentScrollBar::UpdateGripPosition(float NewPos)
{
	/*
	if (MyPanel != None)
	{
		MyPanel.TopOffset = (NewPos * (MyPanel.PanelSize - (MyPanel.ClientBounds[3] - MyPanel.ClientBounds[1])));
	}
	GripPos = NewPos;
	*/
}

void UGUIContentScrollBar::MovePanelBy(float Pct)
{
	/*
	float GripPosition = 0;
	float GripOffset = 0;
	float NewPos = 0;
	GripPosition = (GripPos * MyPanel.PanelSize);
	GripOffset = (Pct * MyPanel.ActualHeight());
	NewPos = ((GripPosition + GripOffset) / MyPanel.PanelSize);
	NewPos = FClamp(NewPos, 0, 1);
	UpdateGripPosition(NewPos);
	*/
}

void UGUIContentScrollBar::WheelUp()
{
	/*
	if (!Controller.CtrlPressed)
	{
		MovePanelBy((-StepPct));
	}
	else
	{
		MovePanelBy((-BigStepPct));
	}
	*/
}

void UGUIContentScrollBar::WheelDown()
{
	/*
	if (!Controller.CtrlPressed)
	{
		MovePanelBy(StepPct);
	}
	else
	{
		MovePanelBy(BigStepPct);
	}
	*/
}

void UGUIContentScrollBar::AlignThumb()
{
}

void UGUIContentScrollBar::ZoneClick(float Delta)
{
	/*
	if (Controller.MouseY < MyGripButton.Bounds[1])
	{
		MovePanelBy((-BigStepPct));
	}
	else
	{
		if (Controller.MouseY > MyGripButton.Bounds[3])
		{
			MovePanelBy(BigStepPct);
		}
	}
	*/
}

void UGUIContentScrollBar::GripPressed(UGUIComponent* Sender, bool IsRepeat)
{
	/*
	if (!IsRepeat)
	{
		GrabOffset = (Controller.MouseY - MyGripButton.ActualTop());
	}
	*/
}

bool UGUIContentScrollBar::GripPreDraw(UGUIComponent* Sender)
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