// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AABrowser_FavoritesAndServerListPanel/AABrowser_FavoritesAndServerList.h"

UAABrowser_FavoritesAndServerList::UAABrowser_FavoritesAndServerList()
{
	//leftside = AABrowser_FavoritesPanel'AGP_Interface.AABrowser_FavoritesAndServerListPanel.FilterBox';
	//rightside = AABrowser_ServersPlayersRulesPanel'AGP_Interface.AABrowser_FavoritesAndServerListPanel.ServersPlayersRulesPanel';
}

void UAABrowser_FavoritesAndServerList::OnUpdateServerList()
{
}

void UAABrowser_FavoritesAndServerList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Suer::InitComponent(MyController, MyOwner);
	//__OnExpand__Delegate = AABrowser_ServersPlayersRulesPanel(rightside).InternalOnExpand;
	//__OnContract__Delegate = AABrowser_ServersPlayersRulesPanel(rightside).InternalOnContract;
}

void UAABrowser_FavoritesAndServerList::ClearLists()
{
	//AABrowser_ServersPlayersRulesPanel(rightside).Clear();
}

void UAABrowser_FavoritesAndServerList::AddBattleBuddy(FString Buddy)
{
	//AABrowser_FavoritesPanel(leftside).AddBattleBuddy(Buddy);
}

void UAABrowser_FavoritesAndServerList::AddFavoriteServer(FString Server)
{
	//AABrowser_FavoritesPanel(leftside).AddFavoriteServer(Server);
}

void UAABrowser_FavoritesAndServerList::RemoveSelected()
{
	//AABrowser_FavoritesPanel(leftside).RemoveSelected();
}

void UAABrowser_FavoritesAndServerList::ReceivedServer(int32 Data)
{
	//AABrowser_ServersPlayersRulesPanel(rightside).ReceivedServer(Data);
}

void UAABrowser_FavoritesAndServerList::IsValidDBMBSFilterList()
{
	//Return AABrowser_FavoritesPanel(leftside).IsValidDBMBSFilterList();
}

void UAABrowser_FavoritesAndServerList::GetDBMBSFilterList()
{
	//Return AABrowser_FavoritesPanel(leftside).GetDBMBSFilterList();
}

void UAABrowser_FavoritesAndServerList::JoinCurrentlySelectedServer()
{
	//AABrowser_ServersPlayersRulesPanel(rightside).JoinCurrentlySelectedServer();
}

void UAABrowser_FavoritesAndServerList::InternalOnUpdateServerList()
{
	//OnUpdateServerList();
}

void UAABrowser_FavoritesAndServerList::InternalOnFavoriteServerSelectionChanged(FFavoriteServer Server)
{
	/*
	Log("SJJ:" @ Self @ "OnFavoriteServerSelectionChanged" @ Server.IPAddress $ ":" $ Server.Port);
	AABrowser_ServersPlayersRulesPanel(rightside).SelectServerByIP(Server.IPAddress, Server.Port);
	*/
}

void UAABrowser_FavoritesAndServerList::InternalOnBuddySelectionChanged(FString Buddy)
{
}