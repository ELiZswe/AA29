// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/GUITabPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"

UAAGUITabControl::UAAGUITabControl()
{
	BeginOppositeRowIndex = -1;
}

UGUITabPanel* UAAGUITabControl::AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	UGUITabPanel* NewPanelClass = nullptr;
	UGUITabButton* NewTabButton = nullptr;
	UGUITabPanel* NewTabPanel = nullptr;
	int32 i = 0;
	/*
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (TabStack[i].Caption ~= InCaption)
		{
			Log("A tab with the caption" @ InCaption @ "already exists.");
			return nullptr;
		}
	}
	if (ExistingPanel == nullptr)
	{
		NewPanelClass = class<GUITabPanel>(Controller.AddComponentClass(PanelClass));
	}
	if ((ExistingPanel != nullptr) || (NewPanelClass != nullptr))
	{
		if (ExistingPanel != nullptr)
		{
			NewTabPanel = GUITabPanel(AppendComponent(ExistingPanel, true));
		}
		else
		{
			if (NewPanelClass != nullptr)
			{
				NewTabPanel = GUITabPanel(AddComponent(PanelClass, true));
			}
		}
		if (NewTabPanel == nullptr)
		{
			Log("Could not create panel for" @ FString::FromInt(NewPanelClass));
			return nullptr;
		}
		if (NewTabPanel.MyButton != nullptr)
		{
			NewTabButton = NewTabPanel.MyButton;
		}
		else
		{
			NewTabButton = new () UGUITabButton::StaticClass();
			if (NewTabButton == nullptr)
			{
				Log("Could not create tab for" @ FString::FromInt(NewPanelClass));
				return nullptr;
			}
			NewTabButton.InitComponent(Controller, this);
			NewTabButton.Opened(this);
			NewTabPanel.MyButton = NewTabButton;
			if (ButtonStyleName != "")
			{
				NewTabPanel.MyButton.Style = Controller.GetStyle(ButtonStyleName, NewTabPanel.FontScale);
			}
			else
			{
				if (!bDrawTabAbove)
				{
					NewTabPanel.MyButton.bBoundToParent = false;
					NewTabPanel.MyButton.Style = Controller.GetStyle("FlippedTabButton", NewTabPanel.FontScale);
				}
			}
			if ((TabStack.Num() >= BeginOppositeRowIndex) && (BeginOppositeRowIndex > 0))
			{
				NewTabPanel.MyButton.Style = Controller.GetStyle("FlippedTabButton", NewTabPanel.FontScale);
			}
		}
		NewTabPanel.MyButton.Hint = Eval((InHint != ""), InHint, NewTabPanel.Hint);
		NewTabPanel.MyButton.Caption = Eval((InCaption != ""), InCaption, NewTabPanel.PanelCaption);
		NewTabPanel.MyButton.__OnClick__Delegate = InternalTabClick;
		NewTabPanel.MyButton.MyPanel = NewTabPanel;
		NewTabPanel.MyButton.FocusInstead = this;
		NewTabPanel.MyButton.bNeverFocus = true;
		NewTabPanel.InitPanel();
		TabStack[TabStack.Num()] = NewTabPanel.MyButton;
		if (((TabStack.Num() == 1) && bVisible) || bForceActive)
		{
			ActivateTab(NewTabPanel.MyButton, true);
		}
		else
		{
			NewTabPanel.Hide();
		}
		return NewTabPanel;
	}
	*/
	return nullptr;
}
