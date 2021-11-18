// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"

UGUITabControl::UGUITabControl()
{
	bDrawTabAbove = true;
	TabHeight = 0.08;
	//OnActivate = GUITabControl.InternalOnActivate;
}

void UGUITabControl::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if (BackgroundStyleName != "")
	{
		BackgroundStyle = Controller.GetStyle(BackgroundStyleName, FontScale);
	}
	__OnKeyEvent__Delegate = InternalOnKeyEvent;
	*/
}

void UGUITabControl::Opened(UGUIComponent* Sender)
{
	/*
	local int32 i;
	Super::Opened(Sender);
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i] != None)
		{
			TabStack[i].Opened(Self);
		}
	}
	if ((((!bInit) && bVisible) && (ActiveTab != None)) && (ActiveTab.MyPanel != None))
	{
		ActivateTab(ActiveTab, true);
	}
	bInit = false;
	*/
}

void UGUITabControl::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	local int32 i;
	Super::Closed(Sender, bCancelled);
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i] != None)
		{
			TabStack[i].Closed(Sender, bCancelled);
		}
	}
	*/
}

bool UGUITabControl::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	local int32 i;
	local int32 aTabIndex;
	local int32 StartIndex;
	if ((FocusedControl != None) || (TabStack.Length <= 0))
	{
		return false;
	}
	if (ActiveTab == None)
	{
		return false;
	}
	i = 0;
	if (i < TabStack.Length)
	{
		if (TabStack[i] == ActiveTab)
		{
			aTabIndex = i;
		}
		else
		{
			i++;
		}
	}
	if ((Key == 37) && (State == 1))
	{
		StartIndex = aTabIndex;
		if (true)
		{
			if (aTabIndex == 0)
			{
				aTabIndex = (TabStack.Length - 1);
			}
			else
			{
				(aTabIndex);
			}
			if ((aTabIndex == StartIndex) || ActivateTab(TabStack[aTabIndex], false))
			{
			}
		}
		return true;
	}
	if ((Key == 39) && (State == 1))
	{
		StartIndex = aTabIndex;
		if (true)
		{
			aTabIndex++;
			if (aTabIndex == TabStack.Length)
			{
				aTabIndex = 0;
			}
			if ((StartIndex == aTabIndex) || ActivateTab(TabStack[aTabIndex], false))
			{
			}
		}
		return true;
	}
	*/
	return false;
}

UGUITabPanel* UGUITabControl::AddTabItem(FGUITabItem Item)
{
	//return AddTab(Item.Caption, Item.ClassName, , Item.Hint);
	return false;   //FAKE   /ELiZ
}

UGUITabPanel* UGUITabControl::AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	/*
	local class<GUITabPanel>  NewPanelClass;
	local GUITabButton NewTabButton;
	local GUITabPanel NewTabPanel;
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
			NewTabButton = new () class'XInterface.GUITabButton';
			if (NewTabButton == None)
			{
				Log("Could not create tab for" @ string(NewPanelClass));
				return None;
			}
			NewTabButton.InitComponent(Controller, Self);
			NewTabButton.Opened(Self);
			NewTabPanel.MyButton = NewTabButton;
			if (!bDrawTabAbove)
			{
				NewTabPanel.MyButton.bBoundToParent = false;
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

UGUITabPanel* UGUITabControl::InsertTab(int32 pos, FString Caption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	/*
	local class<GUITabPanel>  NewPanelClass;
	local GUITabPanel NewTabPanel;
	local GUITabButton NewTabButton;
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
			NewTabButton = new () class'XInterface.GUITabButton';
			if (NewTabButton == None)
			{
				Log("Could not create tab for" @ string(NewPanelClass));
				return None;
			}
			NewTabButton.InitComponent(Controller, Self);
			NewTabButton.Opened(Self);
			NewTabPanel.MyButton = NewTabButton;
		}
		NewTabPanel.MyButton.Caption = Caption;
		NewTabPanel.MyButton.Hint = InHint;
		NewTabPanel.MyButton.__OnClick__Delegate = InternalTabClick;
		NewTabPanel.MyButton.MyPanel = NewTabPanel;
		NewTabPanel.MyButton.FocusInstead = Self;
		NewTabPanel.MyButton.bNeverFocus = true;
		NewTabPanel.InitPanel();
		TabStack.insert(pos, 1);
		TabStack[pos] = NewTabPanel.MyButton;
		if ((TabStack.Length == 1) || bForceActive)
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

UGUITabPanel* UGUITabControl::ReplaceTab(UGUITabButton* Which, FString Caption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	/*
	local class<GUITabPanel>  NewPanelClass;
	local GUITabPanel NewTabPanel;
	local GUITabPanel OldTabPanel;
	if (ExistingPanel == None)
	{
		NewPanelClass = class<GUITabPanel>(Controller.AddComponentClass(PanelClass));
	}
	if ((ExistingPanel != None) || (NewPanelClass != None))
	{
		OldTabPanel = Which.MyPanel;
		if (ExistingPanel == None)
		{
			NewTabPanel = GUITabPanel(AddComponent(PanelClass, true));
		}
		else
		{
			NewTabPanel = GUITabPanel(AppendComponent(ExistingPanel, true));
		}
		if (NewTabPanel == None)
		{
			Log("Could not create panel" @ string(NewPanelClass));
			return None;
		}
		Which.Caption = Caption;
		Which.Hint = InHint;
		Which.MyPanel = NewTabPanel;
		NewTabPanel.MyButton = Which;
		NewTabPanel.InitPanel();
		if (bForceActive)
		{
			ActivateTab(NewTabPanel.MyButton, true);
		}
		else
		{
			NewTabPanel.Hide();
		}
		RemoveComponent(OldTabPanel);
		OldTabPanel.Free();
		return NewTabPanel;
	}
	*/
	return nullptr;
}

void UGUITabControl::RemoveTab(FString Caption, UGUITabButton* Who)
{
	/*
	local int32 i;
	local bool bActive;
	local GUITabPanel OldPanel;
	if ((Caption == "") && (Who == None))
	{
		return;
	}
	if (Who == None)
	{
		i = TabIndex(Caption);
	}
	else
	{
		i = TabIndex(Who.Caption);
	}
	if (i < 0)
	{
		return;
	}
	OldPanel = TabStack[i].MyPanel;
	bActive = (TabStack[i] == ActiveTab);
	TabStack[i].__OnClick__Delegate = None;
	TabStack[i].Free();
	TabStack.remove(i, 1);
	RemoveComponent(OldPanel, true);
	OldPanel.Free();
	if (bActive)
	{
		LostActiveTab();
	}
	*/
}

bool UGUITabControl::LostActiveTab()
{
	/*
	local int32 i;
	if (!Controller.bCurMenuInitialized)
	{
		return false;
	}
	for (i = 0; i < TabStack.Length; i++)
	{
		if (ActivateTab(TabStack[i], true))
		{
			return true;
		}
	}
	*/
	return false;
}

void UGUITabControl::MakeTabActive(UGUITabButton* Who)
{
	/*
	if (ActiveTab != None)
	{
		ActiveTab.ChangeActiveState(false, false);
	}
	PendingTab = None;
	ActiveTab = Who;
	OnChange(Who);
	*/
}

bool UGUITabControl::ActivateTab(UGUITabButton* Who, bool bFocusPanel)
{
	/*
	if (((Who == None) || (PendingTab != None)) || (!Who.CanShowPanel()))
	{
		return false;
	}
	Who.bForceFlash = false;
	if (Who == ActiveTab)
	{
		if (ActiveTab.ChangeActiveState(true, bFocusPanel))
		{
			return true;
		}
		return false;
	}
	PendingTab = Who;
	if (PendingTab.ChangeActiveState(true, bFocusPanel))
	{
		if ((PendingTab.MyPanel.FadeInTime == 0) || (TabStack.Length < 2))
		{
			MakeTabActive(Who);
		}
		else
		{
			FadeInTime = PendingTab.MyPanel.FadeInTime;
			if (!Controller.bQuietMenu)
			{
				PlayerOwner().PlayOwnedSound(Controller.FadeSound, 6, 1);
			}
		}
		return true;
	}
	PendingTab = None;
	*/
	return false;
}

bool UGUITabControl::ActivateTabByName(FString tabname, bool bFocusPanel)
{
	/*
	local int32 i;
	i = TabIndex(tabname);
	if ((i < 0) || (i >= TabStack.Length))
	{
		return false;
	}
	return ActivateTab(TabStack[i], bFocusPanel);
	*/
		return false;   //FAKE   /ELiZ
}

bool UGUITabControl::ActivateTabByPanel(UGUITabPanel* Panel, bool bFocusPanel)
{
	/*
	local int32 i;
	if ((Panel == None) || (!Panel.CanShowPanel()))
	{
		return false;
	}
	for (i = 0; i < TabStack.Length; i++)
	{
		if ((TabStack[i] != None) && (TabStack[i].MyPanel == Panel))
		{
			return ActivateTab(TabStack[i], bFocusPanel);
		}
	}
	*/
	return false;
}

bool UGUITabControl::InternalTabClick(UGUIComponent* Sender)
{
	/*
	local GUITabButton But;
	But = GUITabButton(Sender);
	if (But == None)
	{
		return false;
	}
	ActivateTab(But, true);
	*/
	return true;
}

bool UGUITabControl::NextPage()
{
	/*
	local int32 i;
	if (TabStack.Length < 2)
	{
		return Super::NextPage();
	}
	if (ActiveTab == None)
	{
		i = 0;
	}
	else
	{
		i = (TabIndex(ActiveTab.Caption) + 1);
		if (i >= TabStack.Length)
		{
			i = 0;
		}
	}
	return ActivateTab(TabStack[i], true);
	*/
	return false;   //FAKE   /ELiZ
}

bool UGUITabControl::PrevPage()
{
	/*
	local int32 i;
	if (TabStack.Length < 2)
	{
		return Super::PrevPage();
	}
	if (ActiveTab == None)
	{
		i = (TabStack.Length - 1);
	}
	else
	{
		i = (TabIndex(ActiveTab.Caption) - 1);
		if (i < 0)
		{
			i = (TabStack.Length - 1);
		}
	}
	return ActivateTab(TabStack[i], true);
	*/
	return false;   //FAKE   /ELiZ
}

bool UGUITabControl::NextControl(UGUIComponent* Sender)
{
	/*
	if (Sender != None)
	{
		SetFocus(None);
		return true;
	}
	else
	{
		if (NextControl(Self))
		{
			return true;
		}
		else
		{
			FocusFirst(None);
		}
		return true;
	}
	*/
	return false;
}

bool UGUITabControl::PrevControl(UGUIComponent* Sender)
{
	/*
	if (Sender != None)
	{
		SetFocus(None);
		return true;
	}
	else
	{
		if (PrevControl(Self))
		{
			return true;
		}
		else
		{
			FocusLast(None);
		}
	}
	*/
	return false;
}

int32 UGUITabControl::TabIndex(FString tabname)
{
	/*
	local int32 i;
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i].Caption ~= tabname)
		{
			return i;
		}
	}
	*/
	return -1;
}

UGUITabPanel* UGUITabControl::FindPanelClass(UGUITabPanel* PanelClass)
{
	/*
	local int32 i;
	if (PanelClass == None)
	{
		return None;
	}
	for (i = 0; i < TabStack.Length; i++)
	{
		if (((TabStack[i] != None) && (TabStack[i].MyPanel != None)) && ClassIsChildOf(TabStack[i].MyPanel.Class, PanelClass))
		{
			return TabStack[i].MyPanel;
		}
	}
	*/
	return nullptr;
}

UGUITabPanel* UGUITabControl::BorrowPanel(FString Caption)
{
	/*
	local int32 i;
	if (Caption == "")
	{
		return None;
	}
	i = TabIndex(Caption);
	if (i < 0)
	{
		return None;
	}
	return TabStack[i].MyPanel;
	*/
	return nullptr;     //FAKE   /ELiZ
}

void UGUITabControl::SetVisibility(bool bIsVisible)
{
	/*
	Super::SetVisibility(bIsVisible);
	if (ActiveTab != None)
	{
		ActiveTab.ChangeActiveState(bIsVisible, false);
	}
	*/
}

void UGUITabControl::InternalOnActivate()
{
	/*
	if (ActiveTab == None)
	{
		LostActiveTab();
	}
	*/
}

bool UGUITabControl::FocusFirst(UGUIComponent* Sender)
{
	/*
	if ((((ActiveTab != None) && (ActiveTab.MyPanel != None)) && ActiveTab.MyPanel.CanAcceptFocus()) && ActiveTab.MyPanel.FocusFirst(None))
	{
		return true;
	}
	else
	{
		if (!Super::FocusFirst(Sender))
		{
			SetFocus(None);
		}
	}
	*/
	return true;
}

bool UGUITabControl::FocusLast(UGUIComponent* Sender)
{
	/*
	if ((((ActiveTab != None) && (ActiveTab.MyPanel != None)) && ActiveTab.MyPanel.CanAcceptFocus()) && ActiveTab.MyPanel.FocusLast(None))
	{
		return true;
	}
	else
	{
		if (!Super::FocusLast(Sender))
		{
			SetFocus(None);
		}
	}
	*/
	return true;
}

void UGUITabControl::CenterMouse()
{
	/*
	if (ActiveTab != None)
	{
		ActiveTab.CenterMouse();
	}
	else
	{
		Super::CenterMouse();
	}
	*/
}

void UGUITabControl::Free()
{
	/*
	local int32 i;
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i] != None)
		{
			TabStack[i].Free();
		}
	}
	Super::Free();
	*/
}

void UGUITabControl::LevelChanged()
{
	/*
	local int32 i;
	for (i = 0; i < TabStack.Length; i++)
	{
		if (TabStack[i] != None)
		{
			TabStack[i].LevelChanged();
		}
	}
	Super::LevelChanged();
	*/
}
