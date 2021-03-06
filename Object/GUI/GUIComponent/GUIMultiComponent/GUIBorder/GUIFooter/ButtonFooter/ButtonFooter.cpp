// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/ButtonFooter.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

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
	if (bBoundToParent && MenuOwner != nullptr)
	{
		WinTop = RelativeTop(MenuOwner.ActualTop() + MenuOwner.ActualHeight() - ActualHeight(), true);
	}
	else
	{
		WinTop = RelativeTop(Controller.ResY - ActualHeight(), true);
	}
	if (ButtonsSized(C))
	{
		if (!bInit)
		{
			ButtonLeft = GetButtonLeft();
			PositionButtons(C);
			__OnPreDraw__Delegate = nullptr;
		}
		bInit = false;
	}
	*/
	return true;
}

void UButtonFooter::ResolutionChanged(int32 ResX, int32 ResY)
{
	SetupButtons("");
}

void UButtonFooter::SetupButtons(FString bPerButtonSizes)
{
	int32 i = 0;
	UGUIButton* B = nullptr;
	/*
	if (bPerButtonSizes != "")
	{
		bFixedWidth = !bPerButtonSizes;
	}
	if (bAutoSize)
	{
		for (i = 0; i < Controls.Num(); i++)
		{
			B = Cast<UGUIButton>(Controls[i]);
			if (B != nullptr)
			{
				B.bAutoSize = true;
				B.AutoSizePadding.HorzPerc = B.RelativeWidth(GetPadding(), true);
			}
		}
	}
	__OnPreDraw__Delegate = InternalOnPreDraw;
	bInit = true;
	*/
}

bool UButtonFooter::ButtonsSized(UCanvas* C)
{
	bool bResult = false;
	int32 i = 0;
	UGUIButton* B = nullptr;
	FString str = "";
	float t = 0;
	float AH = 0;
	float At = 0;
	if (!bPositioned)
	{
		return false;
	}
	bResult = true;
	/*
	str = GetLongestCaption(C);
	AH = ActualHeight();
	At = ActualTop();
	for (i = 0; i < Controls.Num(); i++)
	{
		B = Cast<UGUIButton>(Controls[i]);
		if (B != nullptr)
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
				B.WinHeight = B.RelativeHeight(AH, true);
			}
			else
			{
				B.WinHeight = B.RelativeHeight(ActualHeight(ButtonHeight), true);
			}
			switch(Justification)
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
			B.WinTop = B.RelativeTop(t, true);
		}
	}
	*/
	return bResult;
}

void UButtonFooter::PositionButtons(UCanvas* C)
{
	int32 i = 0;
	UGUIButton* B = nullptr;
	float X = 0;
	/*
	for (i = 0; i < Controls.Num(); i++)
	{
		B = Cast<UGUIButton>(Controls[i]);
		if (B != nullptr && B.bVisible)
		{
			if (X == 0)
			{
				X = ButtonLeft;
			}
			else
			{
				X += GetSpacer();
			}
			B.WinLeft = B.RelativeLeft(X, true);
			X += B.ActualWidth();
		}
	}
	*/
}

FString UButtonFooter::GetLongestCaption(UCanvas* C)
{
	FString str="";
	int32 i = 0;
	float XL = 0;
	float YL = 0;
	float LongestW = 0;
	UGUIButton* B = nullptr;
	if (C == nullptr)
	{
		return "";
	}
	/*
	for (i = 0; i < Controls.Num(); i++)
	{
		B = Cast<UGUIButton>(Controls[i]);
		if (B != nullptr && B.bVisible)
		{
			if (B.Style != nullptr)
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

float UButtonFooter::GetButtonLeft()
{
	int32 i = 0;
	UGUIButton* B = nullptr;
	float TotalWidth = 0;
	float AW = 0;
	float AL = 0;
	float FooterMargin = 0;
	AL = ActualLeft(0,false);
	AW = ActualWidth(0, false);
	FooterMargin = GetMargin();
	for (i = 0; i < Controls.Num(); i++)
	{
		B = Cast<UGUIButton>(Controls[i]);
		if ((B != nullptr) && B->bVisible)
		{
			if (TotalWidth > 0)
			{
				TotalWidth += GetSpacer();
			}
			TotalWidth += B->ActualWidth(0,false);
		}
	}
	if (Alignment == EeTextAlign::TXTA_Center)
	{
		return ((((AL + AW) / 2) - (FooterMargin / 2)) - (TotalWidth / 2));
	}
	if (Alignment == EeTextAlign::TXTA_Right)
	{
		return (((AL + AW) - (FooterMargin / 2)) - TotalWidth);
	}
	return (AL + (FooterMargin / 2));
}

float UButtonFooter::GetMargin()
{
	return ActualWidth(Margin,false);
}

float UButtonFooter::GetPadding()
{
	return ActualWidth(Padding,false);
}

float UButtonFooter::GetSpacer()
{
	return ActualWidth(Spacer,false);
}

void UButtonFooter::Timer()
{
	SetCaption("");
}
