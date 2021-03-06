// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AAGUIPanelHideable.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAAGUIPanelHideable::UAAGUIPanelHideable()
{
	UGUIButton* ShowButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ShowButton->Caption = "Show";
	ShowButton->bWrapCaption = true;
	ShowButton->StyleName = "SquareMenuButton";
	ShowButton->Hint = "Show.";
	ShowButton->WinWidth = 0.029441;
	ShowButton->WinHeight = 1;
	ShowButton->RenderWeight = 2;
	ShowButton->TabOrder = 1;
	ShowButton->bBoundToParent = true;
	ShowButton->bScaleToParent = true;
	ShowButton->bVisible = false;
	//ShowButton->OnClick=AAGUIPanelHideable.InternalOnClick;
	//ShowButton->OnKeyEvent=ShowButton.InternalOnKeyEvent;
	UGUIButton* HideButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HideButton->Caption = "Hide";
	HideButton->bWrapCaption = true;
	HideButton->StyleName = "SquareMenuButton";
	HideButton->Hint = "Hide.";
	HideButton->WinWidth = 0.029441;
	HideButton->WinHeight = 1;
	HideButton->RenderWeight = 2;
	HideButton->TabOrder = 1;
	HideButton->bBoundToParent = true;
	HideButton->bScaleToParent = true;
	//HideButton->OnClick=AAGUIPanelHideable.InternalOnClick;
	//HideButton->OnKeyEvent=HideButton.InternalOnKeyEvent;
	b_Hide = HideButton;
	b_Show = ShowButton;
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
	b_Show.SetVisibility(false);
	b_Show.WinHeight = leftside.WinHeight;
	b_Hide.Caption = "<" + Chr(10) + "<" + Chr(10) + "<" + Chr(10) + "<" + Chr(10) + "<";
	b_Show.Caption = ">" + Chr(10) + ">" + Chr(10) + ">" + Chr(10) + ">" + Chr(10) + ">";
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
			leftside.SetVisibility(false);
			b_Hide.SetVisibility(false);
		}
		else
		{
			b_Show.SetVisibility(false);
		}
	}
	*/
}

bool UAAGUIPanelHideable::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_Hide)
	{
		LeftSideHidden = true;
		b_Hide.SetVisibility(false);
		b_Show.SetVisibility(true);
		leftside.SetVisibility(false);
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
			LeftSideHidden = false;
			b_Hide.SetVisibility(true);
			b_Show.SetVisibility(false);
			leftside.SetVisibility(true);
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
