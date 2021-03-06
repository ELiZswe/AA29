// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_ServersPlayersRulesPanel/AABrowser_ServersPlayersRulesPan.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_PlayersList/AABrowser_PlayersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_PlayersListBox/AABrowser_PlayersListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_RulesList/AABrowser_RulesList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_RulesListBox/AABrowser_RulesListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_ServerListBox/AABrowser_ServerListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAABrowser_ServersPlayersRulesPan::UAABrowser_ServersPlayersRulesPan()
{
	UGUISplitter* HorzSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	HorzSplitter->DefaultPanels = {
		"AGP_Interface.AABrowser_ServerListBox",
		"XInterface.GUISplitter"
	};
	HorzSplitter->MaxPercentage = 0.9;
	//HorzSplitter->OnReleaseSplitter = AABrowser_ServersPlayersRulesPanel.InternalOnReleaseSplitter;
	//HorzSplitter->OnCreateComponent=AABrowser_ServersPlayersRulesPanel.InternalOnCreateComponent;
	HorzSplitter->IniOption = "@Internal";
	HorzSplitter->WinHeight = 1;
	HorzSplitter->RenderWeight = 1;
	//HorzSplitter->OnLoadINI=AABrowser_ServersPlayersRulesPanel.InternalOnLoadINI;
	ServerList_RulesPlayersSplitter = HorzSplitter;

	ServerList_RulesPlayersSplitterPosition = 0.467488;
	Rules_PlayersSplitterPosition = 0.485071;
	RulesColumnSizesNormal = { 0.369002, 0.630998 };
	RulesColumnSizesExpanded = { 0.308614, 0.691386 };
	PlayersColumnSizesNormal = { 0.198242, 0.388712, 0.194356, 0.144057 };
	PlayersColumnSizesExpanded = { 0.162222, 0.515086, 0.171695, 0.150997 };
	ServerColumnSizesNormal = { 0.145083, 0.28086, 0.14782, 0.121731, 0.1, 0.166663 };
	ServerColumnSizesExpanded = { 0.1, 0.380345, 0.180629, 0.1, 0.1, 0.113606 };
	IniOption = "@Internal";
	//__OnSaveINI__Delegate = "AABrowser_ServersPlayersRulesPanel.InternalOnSaveINI";
}

void UAABrowser_ServersPlayersRulesPan::OnUpdateServerList()
{
}

void UAABrowser_ServersPlayersRulesPan::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	RulesList = Cast<UAABrowser_RulesList>(RulesListBox->List);
	RulesList->bIsLAN = bIsLAN;
	//RulesList.__OnGetServerRules__Delegate = InternalOnGetServerRules;
	//RulesList.__OnColumnSized__Delegate = InternalOnRulesListColumnSized;
	RulesListBox->HeaderColumnPerc = RulesColumnSizesNormal;
	PlayersList = Cast<UAABrowser_PlayersList>(PlayersListBox->List);
	//PlayersList.__OnGetPlayer__Delegate = InternalOnGetPlayer;
	//PlayersList.__OnColumnSized__Delegate = InternalOnPlayersListColumnSized;
	PlayersListBox->HeaderColumnPerc = PlayersColumnSizesNormal;
	ServerListBox->HeaderColumnPerc = ServerColumnSizesNormal;
}

void UAABrowser_ServersPlayersRulesPan::Opened(UGUIComponent* Sender)
{
	Super::Opened(Sender);
	if (ServerListBox != nullptr && ServerListBox->List == nullptr)
	{
		InitServerList();
	}
	else
	{
		Clear();
	}
}

void UAABrowser_ServersPlayersRulesPan::Clear()
{
	if (serverList != nullptr)
	{
		serverList->Clear();
	}
	if (RulesList != nullptr)
	{
		RulesList->Clear();
	}
	if (PlayersList != nullptr)
	{
		PlayersList->Clear();
	}
}

void UAABrowser_ServersPlayersRulesPan::ReceivedServer(int32 Data)
{
	Cast<UAABrowser_ServersList>(ServerListBox->List)->MyOnReceivedSB(Data);
}

void UAABrowser_ServersPlayersRulesPan::JoinCurrentlySelectedServer()
{
	serverList->Connect(false,"",false);
}

void UAABrowser_ServersPlayersRulesPan::InitServerList()
{
	/*
	serverList = new (None) UAABrowser_ServersList::StaticClass();
	serverList.bIsLAN = bIsLAN;
	serverList.__OnChange__Delegate = InternalServerListChanged;
	serverList.InitColumnPerc = ServerColumnSizesNormal;
	ServerListBox.InitBaseList(serverList);
	ServerListBox.__OnUpdateServerList__Delegate = InternalOnUpdateServerList;
	ServerListBox.__OnUpdateServerRulesAndPlayerList__Delegate = RefreshServerRulesAndPlayersList;
	serverList.__OnColumnSized__Delegate = InternalOnServerListColumnSized;
	SetColumnWidths(ServerListBox, ServerColumnSizesNormal);
	*/
}

void UAABrowser_ServersPlayersRulesPan::InternalServerListChanged(UGUIComponent* Sender)
{
	RefreshServerRulesAndPlayersList(serverList->CurrentListId());
}

void UAABrowser_ServersPlayersRulesPan::RefreshServerRulesAndPlayersList(int32 ServerIndex)
{
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	if (ServerIndex < 0)
	{
		return;
	}
	RulesList->Clear();
	PlayersList->Clear();
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		if (serverList.Index >= 0)
		{
			sbBase.GetSpecificServer(serverList.Index, ServerItem);
			RulesList.ItemCount = 20;
			PlayersList.SetPlayerCount(ServerItem.NumPlayers);
			PlayersList.bIsExploreTheArmyList = 1 == ServerItem.bExploreTheArmy;
			sbBase.RefreshSpecificServer(serverList.Index);
			sbBase.__OnReceivedPlayerList__Delegate = PlayersList.InternalOnReceivedPlayerList;
		}
	}
	*/
}

void UAABrowser_ServersPlayersRulesPan::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	if (Cast<UAABrowser_ServerListBox>(NewComp) != nullptr)
	{
		ServerListBox = Cast<UAABrowser_ServerListBox>(NewComp);
	}
	else
	{
		if (Cast<UAABrowser_RulesListBox>(NewComp) != nullptr)
		{
			RulesListBox = Cast<UAABrowser_RulesListBox>(NewComp);
		}
		else
		{
			if (Cast<UAABrowser_PlayersListBox>(NewComp) != nullptr)
			{
				PlayersListBox = Cast<UAABrowser_PlayersListBox>(NewComp);
			}
			else
			{
				if (Cast<UGUISplitter>(NewComp) != nullptr)
				{
					Rules_PlayersSplitter = Cast<UGUISplitter>(NewComp);
					Rules_PlayersSplitter->DefaultPanels[0] = "AGP_Interface.AABrowser_RulesListBox";
					Rules_PlayersSplitter->DefaultPanels[1] = "AGP_Interface.AABrowser_PlayersListBox";
					Rules_PlayersSplitter->WinTop = 0;
					Rules_PlayersSplitter->WinLeft = 0;
					Rules_PlayersSplitter->WinWidth = 1;
					Rules_PlayersSplitter->WinHeight = 1;
					Rules_PlayersSplitter->MaxPercentage = 0.9;
					Rules_PlayersSplitter->bNeverFocus = true;
					Rules_PlayersSplitter->bAcceptsInput = true;
					Rules_PlayersSplitter->SplitOrientation = EGUISplitterType::SPLIT_Horizontal;
					Rules_PlayersSplitter->IniOption = "@Internal";
					//Rules_PlayersSplitter->__OnCreateComponent__Delegate = InternalOnCreateComponent;
					//Rules_PlayersSplitter->__OnLoadINI__Delegate = InternalOnLoadINI;
					//Rules_PlayersSplitter->__OnReleaseSplitter__Delegate = InternalOnReleaseSplitter;
				}
			}
		}
	}
}

void UAABrowser_ServersPlayersRulesPan::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	if (Sender == ServerList_RulesPlayersSplitter)
	{
		ServerList_RulesPlayersSplitter->SplitPosition = ServerList_RulesPlayersSplitterPosition;
	}
	if (Sender == Rules_PlayersSplitter)
	{
		Rules_PlayersSplitter->SplitPosition = Rules_PlayersSplitterPosition;
	}
}

TArray<float> UAABrowser_ServersPlayersRulesPan::GetColumnSizes(UGUIMultiColumnListBox* ListBox)
{
	TArray<float> ColumnSizes = {};
	int32 Column = 0;
	for (Column = 0; Column < ListBox->List->ColumnWidths.Num(); Column++)
	{
		ColumnSizes[Column] = ListBox->List->ColumnWidths[Column] / ListBox->ActualWidth(0,false);
	}
	return ColumnSizes;
}

void UAABrowser_ServersPlayersRulesPan::InternalOnRulesListColumnSized(int32 Column)
{
	RulesListBox->InternalOnColumnSized(Column);
	if (WinWidth > 0.67)
	{
		RulesColumnSizesExpanded = GetColumnSizes(RulesListBox);
	}
	else
	{
		RulesColumnSizesNormal = GetColumnSizes(RulesListBox);
	}
	SaveConfig();
}

void UAABrowser_ServersPlayersRulesPan::InternalOnPlayersListColumnSized(int32 Column)
{
	PlayersListBox->InternalOnColumnSized(Column);
	if (WinWidth > 0.67)
	{
		PlayersColumnSizesExpanded = GetColumnSizes(PlayersListBox);
	}
	else
	{
		PlayersColumnSizesNormal = GetColumnSizes(PlayersListBox);
	}
	SaveConfig();
}

void UAABrowser_ServersPlayersRulesPan::InternalOnServerListColumnSized(int32 Column)
{
	ServerListBox->InternalOnColumnSized(Column);
	if (bIsLAN)
	{
		return;
	}
	if (WinWidth > 0.67)
	{
		ServerColumnSizesExpanded = GetColumnSizes(ServerListBox);
	}
	else
	{
		ServerColumnSizesNormal = GetColumnSizes(ServerListBox);
	}
	SaveConfig();
}

FString UAABrowser_ServersPlayersRulesPan::InternalOnSaveINI(UGUIComponent* Sender)
{
	SaveConfig();
	return "";
}

void UAABrowser_ServersPlayersRulesPan::SetColumnWidths(UGUIMultiColumnListBox* ListBox, TArray<float> ColumnWidthPercentages)
{
	int32 Column = 0;
	for (Column = 0; Column < ColumnWidthPercentages.Num(); Column++)
	{
		ListBox->List->ColumnWidths[Column] = ColumnWidthPercentages[Column] * ListBox->ActualWidth(0,false);
	}
	if (bIsLAN)
	{
		ListBox->List->ColumnWidths[2] += ListBox->List->ColumnWidths[5];
		//ListBox->List->ColumnWidths.RemoveAt(5, 1);
	}
}

void UAABrowser_ServersPlayersRulesPan::InternalOnExpand()
{
	SetColumnWidths(RulesListBox, RulesColumnSizesExpanded);
	SetColumnWidths(PlayersListBox, PlayersColumnSizesExpanded);
	SetColumnWidths(ServerListBox, ServerColumnSizesExpanded);
}

void UAABrowser_ServersPlayersRulesPan::InternalOnContract()
{
	SetColumnWidths(RulesListBox, RulesColumnSizesNormal);
	SetColumnWidths(PlayersListBox, PlayersColumnSizesNormal);
	SetColumnWidths(ServerListBox, ServerColumnSizesNormal);
}

void UAABrowser_ServersPlayersRulesPan::InternalOnReleaseSplitter(UGUIComponent* Sender, float NewPos)
{
	if (Sender == ServerList_RulesPlayersSplitter)
	{
		ServerList_RulesPlayersSplitterPosition = NewPos;
		SaveConfig();
	}
	if (Sender == Rules_PlayersSplitter)
	{
		Rules_PlayersSplitterPosition = NewPos;
		SaveConfig();
	}
}

bool UAABrowser_ServersPlayersRulesPan::InternalOnGetServerRules(int32& ItemIndex, FGameSpyServerItem& ServerItem)
{
	AServerBrowserBase* sbBase = nullptr;
	/*
	if (serverList.Index < 0)
	{
		return false;
	}
	ItemIndex = serverList.Index;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		sbBase.GetSpecificServer(serverList.Index, ServerItem);
	}
	*/
	return true;
}

bool UAABrowser_ServersPlayersRulesPan::InternalOnGetPlayer(FGameSpyPlayerInfo& PlayerInfo, int32 Index)
{
	AServerBrowserBase* sbBase = nullptr;
	if (serverList->Index < 0)
	{
		return false;
	}
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		sbBase.GetPlayerInfo(serverList.Index, Index, PlayerInfo);
	}
	*/
	return true;
}

void UAABrowser_ServersPlayersRulesPan::InternalOnUpdateServerList()
{
	Clear();
	OnUpdateServerList();
}

void UAABrowser_ServersPlayersRulesPan::SelectServerByIP(FString IPAddress, int32 Port)
{
	int32 NewIndex = 0;
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	FString IP = "";
	/*
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bIsLAN);
	if (sbBase != nullptr)
	{
		for (NewIndex = 0; NewIndex < sbBase.GetNumServers(); NewIndex++)
		{
			sbBase.GetSpecificServer(NewIndex, ServerItem);
			IP = IPAddress + ":" + Port;
			if (IP == sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port))
			{
				serverList.SetIndex(NewIndex);
				return;
			}
		}
	}
	*/
}
