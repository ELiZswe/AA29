// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUIVertTabControl/GUIVertTabControl.h"

UGUIVertTabControl::UGUIVertTabControl()
{
	TabWidth = 0.2;
	bDrawTabAbove = false;
	RenderWeight = 0.4;
}

UGUITabPanel* UGUIVertTabControl::AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	/*
	local class<UGUITabPanel*>  NewPanelClass;
	local XInterface.GUITabButton NewTabButton;
	local UGUITabPanel* NewTabPanel;
	int32 i = 0;
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
			NewTabPanel.MyButton.bBoundToParent = false;
			if (ButtonStyleName != "")
			{
				NewTabPanel.MyButton.Style = Controller.GetStyle(ButtonStyleName, NewTabPanel.FontScale);
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
