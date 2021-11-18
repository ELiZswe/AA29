// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AAGUIPanelHideable.h"

UAAGUIPanelHideable::UAAGUIPanelHideable()
{
	//b_Hide = GUIButton'AGP_Interface.AAGUIPanelHideable.HideButton';
	//b_Show = GUIButton'AGP_Interface.AAGUIPanelHideable.ShowButton';
}

void UAAGUIPanelHideable::OnHide()
{
}

void UAAGUIPanelHideable::OnExpand()
{
}

void UAAGUIPanelHideable::OnShow()
{
}

void UAAGUIPanelHideable::OnContract()
{
}

void UAAGUIPanelHideable::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	leftside.WinWidth = leftside.WinWidth - b_Hide.WinWidth / 2;
	rightside.WinWidth = rightside.WinWidth - b_Hide.WinWidth / 2;
	rightside.WinLeft = leftside.WinWidth + b_Hide.WinWidth;
	b_Hide.WinLeft = leftside.WinLeft + leftside.WinWidth;
	b_Hide.WinTop = leftside.WinTop;
	b_Hide.WinHeight = leftside.WinHeight;
	b_Show.SetVisibility(False);
	b_Show.WinHeight = leftside.WinHeight;
	b_Hide.Caption = "<" $ Chr(10) $ "<" $ Chr(10) $ "<" $ Chr(10) $ "<" $ Chr(10) $ "<";
	b_Show.Caption = ">" $ Chr(10) $ ">" $ Chr(10) $ ">" $ Chr(10) $ ">" $ Chr(10) $ ">";
	*/
}

void UAAGUIPanelHideable::SetVisibility(bool bIsVisible)
{
	/*
	SetVisibility(bIsVisible);
	if (bIsVisible)
	{
		if (LeftSideHidden)
		{
			leftside.SetVisibility(False);
			b_Hide.SetVisibility(False);
		}
		else
		{
			b_Show.SetVisibility(False);
		}
	}
	*/
}

bool UAAGUIPanelHideable::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_Hide)
	{
		LeftSideHidden = True;
		b_Hide.SetVisibility(False);
		b_Show.SetVisibility(True);
		leftside.SetVisibility(False);
		rightside.WinLeft = b_Show.WinLeft + b_Show.WinWidth;
		rightside.WinWidth = 1 - rightside.WinLeft;
		OnHide();
		OnExpand();
		return true;
	}
	else
	{
		if (Sender == b_Show)
		{
			LeftSideHidden = False;
			b_Hide.SetVisibility(True);
			b_Show.SetVisibility(False);
			leftside.SetVisibility(True);
			rightside.WinLeft = leftside.WinWidth + b_Hide.WinWidth;
			rightside.WinWidth = 1 - rightside.WinLeft;
			OnShow();
			OnContract();
			return true;
		}
	}
	*/
	return false;
}