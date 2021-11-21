// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"

UAAGUITabControl::UAAGUITabControl()
{
	BeginOppositeRowIndex = -1;
}

UGUITabPanel* UAAGUITabControl::AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	/*
	local class<XInterface.GUITabPanel>  NewPanelClass;
	local XInterface.GUITabButton NewTabButton;
	local XInterface.GUITabPanel NewTabPanel;
	local int32 i;
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i].Caption ~= InCaption)
		{
			Log("A tab with the caption" @ InCaption @ "already exists.");
			return None;
		}
	}
	if (ExistingPanel == None)
	{
		NewPanelClass = class<GUITabPanel>(Controller.AddComponentClass(PanelClass));
	}
	if ((ExistingPanel != None) || (NewPanelClass != None))
	{
		if (ExistingPanel != None)
		{
			NewTabPanel = GUITabPanel(AppendComponent(ExistingPanel, true));
		}
		else
		{
			if (NewPanelClass != None)
			{
				NewTabPanel = GUITabPanel(AddComponent(PanelClass, true));
			}
		}
		if (NewTabPanel == None)
		{
			Log("Could not create panel for" @ string(NewPanelClass));
			return None;
		}
		if (NewTabPanel.MyButton != None)
		{
			NewTabButton = NewTabPanel.MyButton;
		}
		else
		{
			NewTabButton = new () classClass'XInterface.GUITabButton';
			if (NewTabButton == None)
			{
				Log("Could not create tab for" @ string(NewPanelClass));
				return None;
			}
			NewTabButton.InitComponent(Controller, Self);
			NewTabButton.Opened(Self);
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
			if ((TabStack.Length >= BeginOppositeRowIndex) && (BeginOppositeRowIndex > 0))
			{
				NewTabPanel.MyButton.Style = Controller.GetStyle("FlippedTabButton", NewTabPanel.FontScale);
			}
		}
		NewTabPanel.MyButton.Hint = Eval((InHint != ""), InHint, NewTabPanel.Hint);
		NewTabPanel.MyButton.Caption = Eval((InCaption != ""), InCaption, NewTabPanel.PanelCaption);
		NewTabPanel.MyButton.__OnClick__Delegate = InternalTabClick;
		NewTabPanel.MyButton.MyPanel = NewTabPanel;
		NewTabPanel.MyButton.FocusInstead = Self;
		NewTabPanel.MyButton.bNeverFocus = true;
		NewTabPanel.InitPanel();
		TabStack[TabStack.Length] = NewTabPanel.MyButton;
		if (((TabStack.Length == 1) && bVisible) || bForceActive)
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
