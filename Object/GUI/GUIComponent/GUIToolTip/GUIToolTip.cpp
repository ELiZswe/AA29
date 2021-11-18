// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

UGUIToolTip::UGUIToolTip()
{
	bMultiLine = true;
	bTrackInput = true;
	MaxWidth = 0.3;
	InitialDelay = 0.25;
	ExpirationSeconds = 6;
	StyleName = "MouseOver";
	bVisible = false;
	bRequiresStyle = true;
}

UGUIToolTip* UGUIToolTip::EnterArea()
{
	return InternalEnterArea();
}

UGUIToolTip* UGUIToolTip::InternalEnterArea()
{
	/*
	if (Controller == None)
	{
		if (class'UGUIController*'.Default.bModAuthor)
		{
			Log("ToolTip (" $ string(Self) $ ") not initialized");
		}
		return None;
	}
	StartTime = PlayerOwner().Level.TimeSeconds;
	if ((((Controller != None) && (Controller.MouseOver != None)) && (Controller.MouseOver != Self)) && Controller.MouseOver.bVisible)
	{
		CurrentTime = InitialDelay;
	}
	else
	{
		CurrentTime = 0;
	}
	bResetPosition = true;
	*/
	return this;
}

bool UGUIToolTip::LeaveArea()
{
	return InternalLeaveArea();
}

bool UGUIToolTip::InternalLeaveArea()
{
	/*
	StartTime = -1;
	CurrentTime = -1;
	SetVisibility(false);
	if ((Controller != None) && (Controller.MouseOver == Self))
	{
		Controller.MouseOver = None;
	}
	*/
	return true;
}

void UGUIToolTip::Tick(float RealSeconds)
{
	/*
	(CurrentTime += RealSeconds);
	if (((!bVisible) && (CurrentTime > InitialDelay)) && ((ExpirationSeconds == 0) || (CurrentTime <= ExpirationSeconds)))
	{
		ShowToolTip();
	}
	if ((bVisible && (CurrentTime > ExpirationSeconds)) && (ExpirationSeconds > 0))
	{
		HideToolTip();
	}
	*/
}

void UGUIToolTip::ShowToolTip()
{
	//SetVisibility(true);
}

void UGUIToolTip::HideToolTip()
{
	//SetVisibility(false);
}

void UGUIToolTip::UpdatePosition(UCanvas* C)
{
	/*
	WinWidth = GetWidth(C);
	WinHeight = GetHeight(C);
	WinLeft = GetLeft(C);
	WinTop = GetTop(C);
	bResetPosition = false;
	*/
}

float UGUIToolTip::GetLeft(UCanvas* C)
{
	float X = 0;
	/*
	if (((C == None) || (MenuOwner == None)) || (Style == None))
	{
		return -1;
	}
	X = FMin(Controller.MouseX, Controller.MouseCursorBounds.X1);
	if ((X + WinWidth) > float(C.SizeX))
	{
		(X -= (WinWidth + float(10)));
	}
	*/
	return X;
}

float UGUIToolTip::GetTop(UCanvas* C)
{
	float TargetTop = 0;
	/*
	if (((C == None) || (MenuOwner == None)) || (Style == None))
	{
		return -1;
	}
	if (Controller.MouseY > float((C.SizeY / 8)))
	{
		TargetTop = GetTopAboveCursor(C);
	}
	else
	{
		TargetTop = GetTopBelowCursor(C);
	}
	if (TargetTop < 0)
	{
		TargetTop = GetTopBelowCursor(C);
	}
	*/
	return TargetTop;
}

float UGUIToolTip::GetWidth(UCanvas* C)
{
	/*
	int32 i = 0;
	float MaxLineWidth = 0;
	float XL = 0;
	float YL = 0;
	if ((((C == None) || (Lines.Length == 0)) || (MenuOwner == None)) || (Style == None))
	{
		return 0;
	}
	for (i = 0; i < Lines.Length; i++)
	{
		Style.TextSize(C, MenuOwner.MenuState, Lines[i], XL, YL, FontScale);
		if (XL > MaxLineWidth)
		{
			MaxLineWidth = XL;
		}
	}
	return ((FMin(MaxLineWidth, (MaxWidth * float(C.SizeX))) + float(Style.BorderOffsets[0])) + float(Style.BorderOffsets[2]));
	*/
	return 0;   //FAKE   /ELiZ
}

float UGUIToolTip::GetHeight(UCanvas* C)
{
	/*
	float XL = 0;
	float YL = 0;
	if ((((C == None) || (Lines.Length == 0)) || (MenuOwner == None)) || (Style == None))
	{
		return 0;
	}
	Style.TextSize(C, MenuOwner.MenuState, Lines[0], XL, YL, FontScale);
	return (((YL * float(Lines.Length)) + float(Style.BorderOffsets[1])) + float(Style.BorderOffsets[3]));
	*/
	return 0;   //FAKE   /ELiZ
}

float UGUIToolTip::GetTopAboveCursor(UCanvas* C)
{
	/*
	float TargetY = 0;
	float TempY = 0;
	if (((MenuOwner == None) || (C == None)) || (Controller == None))
	{
		return -1;
	}
	TargetY = (FMin(Controller.MouseCursorBounds.Y1, Controller.MouseY) - (WinHeight + float(10)));
	if (TargetY < 0)
	{
		TempY = GetTopBelowCursor(C);
	}
	return FMax(TempY, TargetY);
	*/
	return 0;   //FAKE   /ELiZ
}

float UGUIToolTip::GetTopBelowCursor(UCanvas* C)
{
	/*
	float TargetY = 0;
	float TempY = 0;
	if (((MenuOwner == None) || (C == None)) || (Controller == None))
	{
		return -1;
	}
	TargetY = (FMax(Controller.MouseCursorBounds.Y2, Controller.MouseY) + float(10));
	if ((TargetY + WinHeight) > float(C.SizeY))
	{
		TempY = GetTopAboveCursor(C);
	}
	return FMax(TargetY, TempY);
	*/
	return 0;   //FAKE   /ELiZ
}

//native final Function SetTip(coerce FString NewTip);
void UGUIToolTip::SetTip(FString NewTip)
{
}
