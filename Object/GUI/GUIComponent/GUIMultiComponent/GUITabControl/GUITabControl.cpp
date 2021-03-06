// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIBorder.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/GUITabPanel.h"

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
	int32 i = 0;
	Super::Opened(Sender);
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (TabStack[i] != nullptr)
		{
			TabStack[i].Opened(this);
		}
	}
	if ((((!bInit) && bVisible) && (ActiveTab != nullptr)) && (ActiveTab.MyPanel != nullptr))
	{
		ActivateTab(ActiveTab, true);
	}
	bInit = false;
	*/
}

void UGUITabControl::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	int32 i = 0;
	Super::Closed(Sender, bCancelled);
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (TabStack[i] != nullptr)
		{
			TabStack[i].Closed(Sender, bCancelled);
		}
	}
	*/
}

bool UGUITabControl::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	int32 i = 0;
	int32 aTabIndex = 0;
	int32 StartIndex = 0;
	/*
	if ((FocusedControl != nullptr) || (TabStack.Num() <= 0))
	{
		return false;
	}
	if (ActiveTab == nullptr)
	{
		return false;
	}
	i = 0;
	if (i < TabStack.Num())
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
				aTabIndex = (TabStack.Num() - 1);
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
			if (aTabIndex == TabStack.Num())
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

UGUITabPanel* UGUITabControl::InsertTab(int32 pos, FString Caption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive)
{
	UGUITabPanel* NewPanelClass = nullptr;
	UGUITabPanel* NewTabPanel = nullptr;
	UGUITabButton* NewTabButton = nullptr;
	/*
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
		}
		NewTabPanel.MyButton.Caption = Caption;
		NewTabPanel.MyButton.Hint = InHint;
		NewTabPanel.MyButton.__OnClick__Delegate = InternalTabClick;
		NewTabPanel.MyButton.MyPanel = NewTabPanel;
		NewTabPanel.MyButton.FocusInstead = this;
		NewTabPanel.MyButton.bNeverFocus = true;
		NewTabPanel.InitPanel();
		TabStack.insert(pos, 1);
		TabStack[pos] = NewTabPanel.MyButton;
		if ((TabStack.Num() == 1) || bForceActive)
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
	UGUITabPanel* NewPanelClass = nullptr;
	UGUITabPanel* NewTabPanel = nullptr;
	UGUITabPanel* OldTabPanel = nullptr;
	/*
	if (ExistingPanel == nullptr)
	{
		NewPanelClass = class<GUITabPanel>(Controller.AddComponentClass(PanelClass));
	}
	if ((ExistingPanel != nullptr) || (NewPanelClass != nullptr))
	{
		OldTabPanel = Which.MyPanel;
		if (ExistingPanel == nullptr)
		{
			NewTabPanel = GUITabPanel(AddComponent(PanelClass, true));
		}
		else
		{
			NewTabPanel = GUITabPanel(AppendComponent(ExistingPanel, true));
		}
		if (NewTabPanel == nullptr)
		{
			Log("Could not create panel" @ FString::FromInt(NewPanelClass));
			return nullptr;
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
	int32 i = 0;
	bool bActive = false;
	UGUITabPanel* OldPanel = nullptr;
	/*
	if ((Caption == "") && (Who == nullptr))
	{
		return;
	}
	if (Who == nullptr)
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
	TabStack[i].__OnClick__Delegate = nullptr;
	TabStack[i].Free();
	TabStack.RemoveAt(i, 1);
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
	int32 i = 0;
	if (!Controller.bCurMenuInitialized)
	{
		return false;
	}
	for (i = 0; i < TabStack.Num(); i++)
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
	if (ActiveTab != nullptr)
	{
		ActiveTab.ChangeActiveState(false, false);
	}
	PendingTab = nullptr;
	ActiveTab = Who;
	OnChange(Who);
	*/
}

bool UGUITabControl::ActivateTab(UGUITabButton* Who, bool bFocusPanel)
{
	/*
	if (((Who == nullptr) || (PendingTab != nullptr)) || (!Who.CanShowPanel()))
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
		if ((PendingTab.MyPanel.FadeInTime == 0) || (TabStack.Num() < 2))
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
	PendingTab = nullptr;
	*/
	return false;
}

bool UGUITabControl::ActivateTabByName(FString tabname, bool bFocusPanel)
{
	/*
	int32 i = 0;
	i = TabIndex(tabname);
	if ((i < 0) || (i >= TabStack.Num()))
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
	int32 i = 0;
	if ((Panel == nullptr) || (!Panel.CanShowPanel()))
	{
		return false;
	}
	for (i = 0; i < TabStack.Num(); i++)
	{
		if ((TabStack[i] != nullptr) && (TabStack[i].MyPanel == Panel))
		{
			return ActivateTab(TabStack[i], bFocusPanel);
		}
	}
	*/
	return false;
}

bool UGUITabControl::InternalTabClick(UGUIComponent* Sender)
{
	UGUITabButton* But = nullptr;
	But = Cast<UGUITabButton>(Sender);
	if (But == nullptr)
	{
		return false;
	}
	ActivateTab(But, true);
	return true;
}

bool UGUITabControl::NextPage()
{
	int32 i = 0;
	/*
	if (TabStack.Num() < 2)
	{
		return Super::NextPage();
	}
	if (ActiveTab == nullptr)
	{
		i = 0;
	}
	else
	{
		i = (TabIndex(ActiveTab.Caption) + 1);
		if (i >= TabStack.Num())
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
	int32 i = 0;
	if (TabStack.Num() < 2)
	{
		return Super::PrevPage();
	}
	if (ActiveTab == nullptr)
	{
		i = (TabStack.Num() - 1);
	}
	else
	{
		i = (TabIndex(ActiveTab.Caption) - 1);
		if (i < 0)
		{
			i = (TabStack.Num() - 1);
		}
	}
	return ActivateTab(TabStack[i], true);
	*/
	return false;   //FAKE   /ELiZ
}

bool UGUITabControl::NextControl(UGUIComponent* Sender)
{
	/*
	if (Sender != nullptr)
	{
		SetFocus(nullptr);
		return true;
	}
	else
	{
		if (NextControl(this))
		{
			return true;
		}
		else
		{
			FocusFirst(nullptr);
		}
		return true;
	}
	*/
	return false;
}

bool UGUITabControl::PrevControl(UGUIComponent* Sender)
{
	/*
	if (Sender != nullptr)
	{
		SetFocus(nullptr);
		return true;
	}
	else
	{
		if (PrevControl(this))
		{
			return true;
		}
		else
		{
			FocusLast(nullptr);
		}
	}
	*/
	return false;
}

int32 UGUITabControl::TabIndex(FString tabname)
{
	/*
	int32 i = 0;
	for (i = 0; i < TabStack.Num(); i++)
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
	int32 i = 0;
	if (PanelClass == nullptr)
	{
		return nullptr;
	}
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (((TabStack[i] != nullptr) && (TabStack[i].MyPanel != nullptr)) && ClassIsChildOf(TabStack[i].MyPanel.Class, PanelClass))
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
	int32 i = 0;
	if (Caption == "")
	{
		return nullptr;
	}
	i = TabIndex(Caption);
	if (i < 0)
	{
		return nullptr;
	}
	return TabStack[i].MyPanel;
	*/
	return nullptr;     //FAKE   /ELiZ
}

void UGUITabControl::SetVisibility(bool bIsVisible)
{
	/*
	Super::SetVisibility(bIsVisible);
	if (ActiveTab != nullptr)
	{
		ActiveTab.ChangeActiveState(bIsVisible, false);
	}
	*/
}

void UGUITabControl::InternalOnActivate()
{
	/*
	if (ActiveTab == nullptr)
	{
		LostActiveTab();
	}
	*/
}

bool UGUITabControl::FocusFirst(UGUIComponent* Sender)
{
	/*
	if ((((ActiveTab != nullptr) && (ActiveTab.MyPanel != nullptr)) && ActiveTab.MyPanel.CanAcceptFocus()) && ActiveTab.MyPanel.FocusFirst(None))
	{
		return true;
	}
	else
	{
		if (!Super::FocusFirst(Sender))
		{
			SetFocus(nullptr);
		}
	}
	*/
	return true;
}

bool UGUITabControl::FocusLast(UGUIComponent* Sender)
{
	/*
	if ((((ActiveTab != nullptr) && (ActiveTab.MyPanel != nullptr)) && ActiveTab.MyPanel.CanAcceptFocus()) && ActiveTab.MyPanel.FocusLast(None))
	{
		return true;
	}
	else
	{
		if (!Super::FocusLast(Sender))
		{
			SetFocus(nullptr);
		}
	}
	*/
	return true;
}

void UGUITabControl::CenterMouse()
{
	/*
	if (ActiveTab != nullptr)
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
	int32 i = 0;
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (TabStack[i] != nullptr)
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
	int32 i = 0;
	for (i = 0; i < TabStack.Num(); i++)
	{
		if (TabStack[i] != nullptr)
		{
			TabStack[i].LevelChanged();
		}
	}
	Super::LevelChanged();
	*/
}
