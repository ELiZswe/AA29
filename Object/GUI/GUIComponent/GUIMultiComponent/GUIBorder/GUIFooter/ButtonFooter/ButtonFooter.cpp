// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/ButtonFooter.h"

UButtonFooter::UButtonFooter()
{
	ButtonHeight = 1;
	Padding = 0.14;
	Margin = 0.005;
	bFixedWidth = true;
	bFullHeight = true;
	bAutoSize = true;
	Alignment = EeTextAlign::TXTA_Right;
	WinHeight = 0.04;
	bNeverFocus = false;
	//__OnPreDraw__Delegate = "ButtonFooter.InternalOnPreDraw";
}


void UButtonFooter::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	//InitComponent(InController, InOwner);
	//SetupButtons();
}

bool UButtonFooter::InternalOnPreDraw(UCanvas* C)
{
	/*
	if (bBoundToParent && MenuOwner != None)
	{
		WinTop = RelativeTop(MenuOwner.ActualTop() + MenuOwner.ActualHeight() - ActualHeight(), True);
	}
	else
	{
		WinTop = RelativeTop(Controller.ResY - ActualHeight(), True);
	}
	if (ButtonsSized(C))
	{
		if (!bInit)
		{
			ButtonLeft = GetButtonLeft();
			PositionButtons(C);
			__OnPreDraw__Delegate = None;
		}
		bInit = False;
	}
	*/
	return true;
}

void UButtonFooter::ResolutionChanged(int32 ResX, int32 ResY)
{
	//SetupButtons();
}

void UButtonFooter::SetupButtons(FString bPerButtonSizes)
{
	/*
	local int i;
	local XInterface.GUIButton B;
	if (bPerButtonSizes != "")
	{
		bFixedWidth = !bPerButtonSizes;
	}
	if (bAutoSize)
	{
		for (i = 0; i < Controls.Length; i++)
		{
			B = GUIButton(Controls[i]);
			if (B != None)
			{
				B.bAutoSize = True;
				B.AutoSizePadding.HorzPerc = B.RelativeWidth(GetPadding(), True);
			}
		}
	}
	__OnPreDraw__Delegate = InternalOnPreDraw;
	bInit = True;
	*/
}

bool UButtonFooter::ButtonsSized(UCanvas* C)
{
	bool bResult = false;
	/*
	local int i;
	local XInterface.GUIButton B;
	
	local string str;
	local float t;
	local float AH;
	local float At;
	if (!bPositioned)
	{
		Return False;
	}
	bResult = True;
	str = GetLongestCaption(C);
	AH = ActualHeight();
	At = ActualTop();
	for (i = 0; i < Controls.Length; i++)
	{
		B = GUIButton(Controls[i]);
		if (B != None)
		{
			if (bAutoSize && bFixedWidth)
			{
				B.SizingCaption = str;
			}
			else
			{
				B.SizingCaption = "";
			}
			bResult = bResult && B.bPositioned;
			if (bFullHeight)
			{
				B.WinHeight = B.RelativeHeight(AH, True);
			}
			else
			{
				B.WinHeight = B.RelativeHeight(ActualHeight(ButtonHeight), True);
			}
			Switch(Justification)
			{
					case 0:
						t = ClientBounds[1];
						break;
					case 1:
						t = At + AH / 2 - B.ActualHeight() / 2;
						break;
					case 2:
						t = ClientBounds[3] - B.ActualHeight();
						break;
					default:
			}
			B.WinTop = B.RelativeTop(t, True);
		}
	}
	*/
	return bResult;
}

void UButtonFooter::PositionButtons(UCanvas* C)
{
	/*
	local int i;
	local XInterface.GUIButton B;
	local float X;
	for (i = 0; i < Controls.Length; i++)
	{
		B = GUIButton(Controls[i]);
		if (B != None && B.bVisible)
		{
			if (X == 0)
			{
				X = ButtonLeft;
			}
			else
			{
				X += GetSpacer();
			}
			B.WinLeft = B.RelativeLeft(X, True);
			X += B.ActualWidth();
		}
	}
	*/
}

FString UButtonFooter::GetLongestCaption(UCanvas* C)
{
	FString str="";
	/*
	local int i;
	local float XL;
	local float YL;
	local float LongestW;
	
	local XInterface.GUIButton B;
	if (C == None)
	{
		Return "";
	}
	for (i = 0; i < Controls.Length; i++)
	{
		B = GUIButton(Controls[i]);
		if (B != None && B.bVisible)
		{
			if (B.Style != None)
			{
				B.Style.TextSize(C, B.MenuState, B.Caption, XL, YL, B.FontScale);
			}
			else
			{
				C.StrLen(B.Caption, XL, YL);
			}
			if (LongestW == 0 || XL > LongestW)
			{
				str = B.Caption;
				LongestW = XL;
			}
		}
	}
	*/
	return str;
}

void UButtonFooter::GetButtonLeft()
{
	/*
	local int i;
	local XInterface.GUIButton B;
	local float TotalWidth;
	local float AW;
	local float AL;
	local float FooterMargin;
	AL = ActualLeft();
	AW = ActualWidth();
	FooterMargin = GetMargin();
	for (i = 0; i < Controls.Length; i++)
	{
		B = GUIButton(Controls[i]);
		if (B != None && B.bVisible)
		{
			if (TotalWidth > 0)
			{
				TotalWidth += GetSpacer();
			}
			TotalWidth += B.ActualWidth();
		}
	}
	if (Alignment == 1)
	{
		Return AL + AW / 2 - FooterMargin / 2 - TotalWidth / 2;
	}
	if (Alignment == 2)
	{
		Return AL + AW - FooterMargin / 2 - TotalWidth;
	}
	Return AL + FooterMargin / 2;
	*/
}

void UButtonFooter::GetMargin()
{
	//Return ActualWidth(Margin);
}

void UButtonFooter::GetPadding()
{
	//Return ActualWidth(Padding);
}

void UButtonFooter::GetSpacer()
{
	//Return ActualWidth(Spacer);
}

void UButtonFooter::Timer()
{
	SetCaption("");
}
