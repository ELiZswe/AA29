// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_BuddyList/AABrowser_BuddyList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_BuddyListBox/AABrowser_BuddyListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAABrowser_ServerListPageBuddy::UAABrowser_ServerListPageBuddy()
{
	UGUISplitter* HorzSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	HorzSplitter->SplitOrientation = EGUISplitterType::SPLIT_Horizontal;
	HorzSplitter->DefaultPanels = {
		"AGP_Interface.AABrowser_BuddyListBox",
		"XInterface.GUISplitter"
	};
	//HorzSplitter->OnReleaseSplitter = AABrowser_ServerListPageBuddy.InternalReleaseSplitter;
	//HorzSplitter->OnCreateComponent=AABrowser_ServerListPageBuddy.InternalOnCreateComponent;
	HorzSplitter->IniOption = "@Internal";
	HorzSplitter->WinHeight = 1;
	HorzSplitter->RenderWeight = 1;
	HorzSplitter->bBoundToParent = true;
	HorzSplitter->bScaleToParent = true;
	//HorzSplitter->OnLoadINI=AABrowser_ServerListPageBuddy.InternalOnLoadINI;
	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	RCMenu->ContextItems = { "Add Buddy","Remove Buddy" };
	//RCMenu->OnSelect=AABrowser_ServerListPageBuddy.ContextSelect;
	BuddySplitterPosition = 0.597582;
	BuddyListBoxClass = "AGP_Interface.AABrowser_BuddyListBox";
	AddBuddyCaption = "ADD BUDDY";
	AddBuddyLabel = "Add Buddy";
	RemoveBuddyCaption = "REMOVE BUDDY";
	BuddyNameCaption = "Buddy Name: ";
	sp_Main = HorzSplitter;
	MainSplitterPosition = 0.184326;
	DetailSplitterPosition = 0.319135;
	HeaderColumnSizes2512 = {{ { 0.096562,0.493471,0.206944,0.102535,0.15 } },{ { 0.498144,0.5 } }, { { 0.473428,0.185665,0.226824,0.22 } }};
	PanelCaption = "Buddy Browser";
	ContextMenu = RCMenu;
}

void UAABrowser_ServerListPageBuddy::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	li_Buddy = AABrowser_BuddyList(lb_Buddy.List);
	li_Buddy.__OnChange__Delegate = BuddyListChanged;
	li_Buddy.__OnRightClick__Delegate = InternalOnRightClick;
	lb_Buddy.TabOrder = 0;
	lb_Server.TabOrder = 1;
	lb_Rules.TabOrder = 2;
	lb_Players.TabOrder = 3;
	for (i = 0; i < Buddies.Num(); i++)
	{
		li_Buddy.AddedItem();
	}
	*/
}

void UAABrowser_ServerListPageBuddy::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	Controller.__AddBuddy__Delegate = AddBuddy;
	*/
}

void UAABrowser_ServerListPageBuddy::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow && bInit)
	{
		sp_Buddy.SplitterUpdatePositions();
		bInit = false;
	}
	*/
}

void UAABrowser_ServerListPageBuddy::Refresh()
{
	/*
	int32 i = 0;
	Super::Refresh();
	for (i = 0; i < Buddies.Num(); i++)
	{
		AddQueryTerm("buddy", Buddies[i], 0);
	}
	Browser.Uplink().StartQuery(0);
	SetFooterCaption(StartQueryString);
	KillTimer();
	*/
}

void UAABrowser_ServerListPageBuddy::BuddyListChanged(UGUIComponent* Sender)
{
}

void UAABrowser_ServerListPageBuddy::AddBuddy(FString NewBuddy)
{
	/*
	if (Controller.OpenMenu(Controller.RequestDataMenu, AddBuddyLabel, BuddyNameCaption))
	{
		Controller.ActivePage.SetDataString(NewBuddy);
		Controller.ActivePage.__OnClose__Delegate = BuddyPageClosed;
	}
	*/
}

void UAABrowser_ServerListPageBuddy::BuddyPageClosed(bool bCancelled)
{
	FString S = "";
	if (bCancelled)
	{
		return;
	}
	/*
	S = Controller.ActivePage.GetDataString();
	if (S != "")
	{
		if (FindBuddyIndex(S) != -1)
		{
			return;
		}
		Buddies[Buddies.Num()] = S;
		li_Buddy.AddedItem();
		SaveConfig();
	}
	*/
}

void UAABrowser_ServerListPageBuddy::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UGUISplitter>(NewComp) != nullptr)
	{
		if (Cast<UGUISplitter>(Sender).Panels[0] != nullptr)
		{
			if (Cast<UAABrowser_ServerListPageBuddy>(Sender.MenuOwner) != nullptr)
			{
				sp_Buddy = Cast<UGUISplitter>(NewComp);
				sp_Buddy.DefaultPanels[0] = "AGP_Interface.AABrowser_ServerListBox";
				sp_Buddy.DefaultPanels[1] = "XInterface.GUISplitter";
				sp_Buddy.WinTop = 0;
				sp_Buddy.WinLeft = 0;
				sp_Buddy.WinWidth = 1;
				sp_Buddy.WinHeight = 1;
				sp_Buddy.bNeverFocus = true;
				sp_Buddy.bAcceptsInput = true;
				sp_Buddy.RenderWeight = 0;
				sp_Buddy.__OnCreateComponent__Delegate = InternalOnCreateComponent;
				sp_Buddy.__OnLoadINI__Delegate = InternalOnLoadINI;
				sp_Buddy.__OnReleaseSplitter__Delegate = InternalReleaseSplitter;
				sp_Buddy.SplitOrientation = 0;
			}
			else
			{
				Super::InternalOnCreateComponent(NewComp, Sender);
			}
		}
		else
		{
			Super::InternalOnCreateComponent(NewComp, Sender);
		}
	}
	else
	{
		if (Cast<UAABrowser_BuddyListBox>(NewComp) != nullptr)
		{
			lb_Buddy = AABrowser_BuddyListBox(NewComp);
		}
		else
		{
			Super::InternalOnCreateComponent(NewComp, Sender);
		}
	}
	*/
}

void UAABrowser_ServerListPageBuddy::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == sp_Buddy)
	{
		sp_Buddy.SplitPosition = BuddySplitterPosition;
	}
	else
	{
		Super::InternalOnLoadINI(Sender, S);
	}
	*/
}

void UAABrowser_ServerListPageBuddy::InternalReleaseSplitter(UGUIComponent* Sender, float NewPos)
{
	/*
	if (Sender == sp_Buddy)
	{
		BuddySplitterPosition = NewPos;
		SaveConfig();
	}
	else
	{
		Super::InternalReleaseSplitter(Sender, NewPos);
	}
	*/
}

int32 UAABrowser_ServerListPageBuddy::FindBuddyIndex(FString buddyName)
{
	/*
	int32 i = 0;
	for (i = 0; i < Buddies.Num(); i++)
	{
		if (Buddies[i] ~= buddyName)
		{
			return i;
		}
	}
	*/
	return -1;
}

void UAABrowser_ServerListPageBuddy::ContextSelect(UGUIContextMenu* Sender, int32 aIndex)
{
	/*
	if (!NotifyContextSelect(Sender, aIndex))
	{
		switch (aIndex)
		{
		case 0:
			AddBuddy();
			break;
		case 1:
			if (li_Buddy.IsValid())
			{
				Buddies.RemoveAt(li_Buddy.Index, 1);
				li_Buddy.RemovedCurrent();
				SaveConfig();
			}
			break;
		default:
		}
	}
	*/
}
