// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBuddy.h"

UAABrowser_ServerListPageBuddy::UAABrowser_ServerListPageBuddy()
{
	/*
	Begin Object Class=GUISplitter Name=HorzSplitter
		SplitOrientation=1
		DefaultPanels="AGP_Interface.AABrowser_BuddyListBox"
		DefaultPanels="XInterface.GUISplitter"
		OnReleaseSplitter=AABrowser_ServerListPageBuddy.InternalReleaseSplitter
		OnCreateComponent=AABrowser_ServerListPageBuddy.InternalOnCreateComponent
		IniOption="@Internal"
		WinHeight=1
		RenderWeight=1
		bBoundToParent=True
		bScaleToParent=True
		OnLoadINI=AABrowser_ServerListPageBuddy.InternalOnLoadINI
	End Object
	Begin Object Class=GUIContextMenu Name=RCMenu
		ContextItems(0)="Add Buddy"
		ContextItems(1)="Remove Buddy"
		OnSelect=AABrowser_ServerListPageBuddy.ContextSelect
	End Object
	*/
	BuddySplitterPosition = 0.597582;
	//BuddyListBoxClass = "AGP_Interface.AABrowser_BuddyListBox";
	AddBuddyCaption = "ADD BUDDY";
	AddBuddyLabel = "Add Buddy";
	RemoveBuddyCaption = "REMOVE BUDDY";
	BuddyNameCaption = "Buddy Name: ";
	//sp_Main = GUISplitter'AGP_Interface.AABrowser_ServerListPageBuddy.HorzSplitter';
	MainSplitterPosition = 0.184326;
	DetailSplitterPosition = 0.319135;

	/*
		HeaderColumnSizes2512(0) = (ColumnSizes(0) = 0.096562
			ColumnSizes(1) = 0.493471
			ColumnSizes(2) = 0.206944
			ColumnSizes(3) = 0.102535
			ColumnSizes(4) = 0.15)
		HeaderColumnSizes2512(1) = (ColumnSizes(0) = 0.498144
			ColumnSizes(1) = 0.5)
		HeaderColumnSizes2512(2) = (ColumnSizes(0) = 0.473428
			ColumnSizes(1) = 0.185665
			ColumnSizes(2) = 0.226824
			ColumnSizes(3) = 0.22)
	*/
	PanelCaption = "Buddy Browser";
	//ContextMenu = GUIContextMenu'AGP_Interface.AABrowser_ServerListPageBuddy.RCMenu';
}

void UAABrowser_ServerListPageBuddy::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 i;
	Super::InitComponent(MyController, MyOwner);
	li_Buddy = AABrowser_BuddyList(lb_Buddy.List);
	li_Buddy.__OnChange__Delegate = BuddyListChanged;
	li_Buddy.__OnRightClick__Delegate = InternalOnRightClick;
	lb_Buddy.TabOrder = 0;
	lb_Server.TabOrder = 1;
	lb_Rules.TabOrder = 2;
	lb_Players.TabOrder = 3;
	for (i = 0; i < Buddies.Length; i++)
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
	local int32 i;
	Super::Refresh();
	for (i = 0; i < Buddies.Length; i++)
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
	/*
	local FString S;
	if (bCancelled)
	{
		return;
	}
	S = Controller.ActivePage.GetDataString();
	if (S != "")
	{
		if (FindBuddyIndex(S) != -1)
		{
			return;
		}
		Buddies[Buddies.Length] = S;
		li_Buddy.AddedItem();
		SaveConfig();
	}
	*/
}

void UAABrowser_ServerListPageBuddy::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (GUISplitter(NewComp) != None)
	{
		if (GUISplitter(Sender).Panels[0] != None)
		{
			if (AABrowser_ServerListPageBuddy(Sender.MenuOwner) != None)
			{
				sp_Buddy = GUISplitter(NewComp);
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
		if (AABrowser_BuddyListBox(NewComp) != None)
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
	local int32 i;
	for (i = 0; i < Buddies.Length; i++)
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
				Buddies.remove(li_Buddy.Index, 1);
				li_Buddy.RemovedCurrent();
				SaveConfig();
			}
			break;
		default:
		}
	}
	*/
}
