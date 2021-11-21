// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AABrowser_FavoritesAndServerListPanel/AABrowser_FavoritesAndServerList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_ServersPlayersRulesPanel/AABrowser_ServersPlayersRulesPan.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FavoritesPanel/AABrowser_FavoritesPanel.h"

UAABrowser_FavoritesAndServerList::UAABrowser_FavoritesAndServerList()
{
	UAABrowser_ServersPlayersRulesPan* ServersPlayersRulesPanel = NewObject<UAABrowser_ServersPlayersRulesPan>(UAABrowser_ServersPlayersRulesPan::StaticClass());
	//ServersPlayersRulesPanel->OnUpdateServerList = AABrowser_FavoritesAndServerListPanel.InternalOnUpdateServerList;
	ServersPlayersRulesPanel->WinLeft = 0.33;
	ServersPlayersRulesPanel->WinWidth = 0.666667;
	ServersPlayersRulesPanel->WinHeight = 1;
	//ServersPlayersRulesPanel->OnSaveINI=ServersPlayersRulesPanel.InternalOnSaveINI;
	UAABrowser_FavoritesPanel* FilterBox = NewObject<UAABrowser_FavoritesPanel>(UAABrowser_FavoritesPanel::StaticClass());
	//FilterBox->OnUpdateServerList = AABrowser_FavoritesAndServerListPanel.InternalOnUpdateServerList;
	//FilterBox->OnFavoriteServerSelectionChanged = AABrowser_FavoritesAndServerListPanel.InternalOnFavoriteServerSelectionChanged;
	//FilterBox->OnBuddySelectionChanged = AABrowser_FavoritesAndServerListPanel.InternalOnBuddySelectionChanged;
	FilterBox->WinWidth = 0.333333;
	FilterBox->WinHeight = 1;
	leftside = FilterBox;
	rightside = ServersPlayersRulesPanel;
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