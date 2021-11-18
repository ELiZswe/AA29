// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_PlayersListBox/AABrowser_PlayersListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"

UAABrowser_PlayersListBox::UAABrowser_PlayersListBox()
{
	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	//RCMenu->OnOpen = AABrowser_PlayersListBox.InternalOnOpen;
	//RCMenu->OnClose = AABrowser_PlayersListBox.InternalOnClose;
	//RCMenu->OnSelect = AABrowser_PlayersListBox.InternalOnClick;
	ContextMenuText = { "Add %s to Battle Buddy list", "Remove %s from Battle Buddy list" };
	//DefaultListClass = "AGP_Interface.AABrowser_PlayersList";
	ContextMenu = RCMenu;
}

void UAABrowser_PlayersListBox::Opened(UGUIComponent* Sender)
{
	//Opened(Sender);
}

void UAABrowser_PlayersListBox::InternalOnClick(UGUIContextMenu* Sender, int32 ContextIndex)
{
	/*
	local int ListIndex;
	local AABrowser_PlayersList L;
	local ServerBrowserBase.GameSpyPlayerInfo PlayerInfo;
	local DBAuth.Favorites Favorites;
	Favorites = 'AABrowser_FavoritesPanel'.Default.Favorites;
	L = AABrowser_PlayersList(List);
	if (L != None && Favorites != None)
	{
		ListIndex = L.CurrentListId();
		if (L.OnGetPlayer(PlayerInfo, ListIndex))
		{
			if (!NotifyContextSelect(Sender, ContextIndex))
			{
				if (!IsOnBattleBuddyList(PlayerInfo.Name))
				{
					OpenFavoritesOperationDialog("Adding Battle Buddy", PlayerInfo.Name);
					Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
					Favorites.AddBattleBuddy(PlayerInfo.Name, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				}
				else
				{
					OpenFavoritesOperationDialog("Removing Battle Buddy", PlayerInfo.Name);
					Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
					Favorites.RemoveBattleBuddy(PlayerInfo.Name, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				}
			}
		}
	}
	*/
}

bool UAABrowser_PlayersListBox::IsOnBattleBuddyList(FString PlayerName)
{
	/*
	local DBAuth.Favorites Favorites;
	Favorites = 'AABrowser_FavoritesPanel'.Default.Favorites;
	if (-1 == Favorites.GetIndexOfBattleBuddy(PlayerName))
	{
		return false;
	}
	*/
	return true;
}

void UAABrowser_PlayersListBox::OpenFavoritesOperationDialog(FString Action, FString Message)
{
	/*
	if (None == AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.OpenMenu("AGP_Interface.AAFavoritesOperationModalDialog", Action, Message);
	}
	*/
}

void UAABrowser_PlayersListBox::InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message)
{
	/*
	if (None != AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.CloseMenu(1 != ResultCode);
	}
	if (1 != ResultCode)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Favorites Update Failed", Message);
	}
	*/
}

bool UAABrowser_PlayersListBox::InternalOnOpen(UGUIContextMenu* Menu)
{
	/*
	local ServerBrowserBase.GameSpyPlayerInfo PlayerInfo;
	local int Index;
	local string MenuText;
	if (!AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser().IsSupportsFavorites())
	{
		return false;
	}
	if (AABrowser_PlayersList(List).bIsExploreTheArmyList)
	{
		return false;
	}
	Index = List.CurrentListId();
	if (Index >= 0)
	{
		if (AABrowser_PlayersList(List).OnGetPlayer(PlayerInfo, Index))
		{
			if (!IsOnBattleBuddyList(PlayerInfo.Name))
			{
				MenuText = ContextMenuText[0];
			}
			else
			{
				MenuText = ContextMenuText[1];
			}
			ReplaceText(MenuText, "%s", PlayerInfo.Name);
			Menu.addItem(MenuText);
			Return InternalOnOpen(Menu);
		}
	}
	*/
	return false;
}

void UAABrowser_PlayersListBox::InternalOnClose(UGUIContextMenu* Sender)
{
	/*
	Sender.ContextItems.remove(0, Sender.ContextItems.Length);
	Return InternalOnClose(Sender);
	*/
}