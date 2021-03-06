// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_PlayersListBox/AABrowser_PlayersListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_PlayersList/AABrowser_PlayersList.h"
#include "AA29/Object/Favorites/Favorites.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAABrowser_PlayersListBox::UAABrowser_PlayersListBox()
{
	ContextMenuText.SetNum(2);
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
	int32 ListIndex = 0;
	UAABrowser_PlayersList* L = nullptr;
	FGameSpyPlayerInfo PlayerInfo = FGameSpyPlayerInfo({});
	UFavorites* Favorites = nullptr;
	/*
	Favorites = 'AABrowser_FavoritesPanel'.Default.Favorites;
	L = Cast<UAABrowser_PlayersList>(List);
	if (L != nullptr && Favorites != nullptr)
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
					Favorites.AddBattleBuddy(PlayerInfo.Name, Cast<AHumanController>(PlayerOwner())->UserName, Cast<AHumanController>(PlayerOwner())->UserPassword, PlayerOwner());
				}
				else
				{
					OpenFavoritesOperationDialog("Removing Battle Buddy", PlayerInfo.Name);
					Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
					Favorites.RemoveBattleBuddy(PlayerInfo.Name, Cast<AHumanController>(PlayerOwner())->UserName, Cast<AHumanController>(PlayerOwner())->UserPassword, PlayerOwner());
				}
			}
		}
	}
	*/
}

bool UAABrowser_PlayersListBox::IsOnBattleBuddyList(FString PlayerName)
{
	UFavorites* Favorites = nullptr;
	/*
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
	FGameSpyPlayerInfo PlayerInfo = FGameSpyPlayerInfo({});
	int32 Index = 0;
	FString MenuText = "";
	/*
	if (!AGP_HUD(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser().IsSupportsFavorites())
	{
		return false;
	}
	if (Cast<UAABrowser_PlayersList>(List).bIsExploreTheArmyList)
	{
		return false;
	}
	Index = List.CurrentListId();
	if (Index >= 0)
	{
		if (Cast<UAABrowser_PlayersList>(List).OnGetPlayer(PlayerInfo, Index))
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
			return InternalOnOpen(Menu);
		}
	}
	*/
	return false;
}

bool UAABrowser_PlayersListBox::InternalOnClose(UGUIContextMenu* Sender)
{
	/*
	Sender.ContextItems.RemoveAt(0, Sender.ContextItems.Num());
	return InternalOnClose(Sender);
	*/
	return false;    //FAKE  /ELiZ
}
