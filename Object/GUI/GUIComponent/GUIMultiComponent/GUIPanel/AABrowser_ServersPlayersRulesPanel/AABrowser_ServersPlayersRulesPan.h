// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AABrowser_ServersPlayersRulesPan.generated.h"

class UAABrowser_PlayersList;
class UAABrowser_PlayersListBox;
class UAABrowser_RulesList;
class UAABrowser_RulesListBox;
class UAABrowser_ServersList;
class UAABrowser_ServerListBox;
class UGUISplitter;
class UGUIMultiColumnListBox;

UCLASS(Config = Game)
class AA29_API UAABrowser_ServersPlayersRulesPan : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAABrowser_ServersPlayersRulesPan();

	UPROPERTY(config)					TArray<float>				ServerColumnSizesExpanded;					//var config array<float> ServerColumnSizesExpanded;
	UPROPERTY(config)					TArray<float>				ServerColumnSizesNormal;					//var config array<float> ServerColumnSizesNormal;
	UPROPERTY(config)					TArray<float>				PlayersColumnSizesExpanded;					//var config array<float> PlayersColumnSizesExpanded;
	UPROPERTY(config)					TArray<float>				PlayersColumnSizesNormal;					//var config array<float> PlayersColumnSizesNormal;
	UPROPERTY(config)					TArray<float>				RulesColumnSizesExpanded;					//var config array<float> RulesColumnSizesExpanded;
	UPROPERTY(config)					TArray<float>				RulesColumnSizesNormal;						//var config array<float> RulesColumnSizesNormal;
	UPROPERTY(config)					float						Rules_PlayersSplitterPosition;				//var config float Rules_PlayersSplitterPosition;
	UPROPERTY(config)					float						ServerList_RulesPlayersSplitterPosition;	//var config float ServerList_RulesPlayersSplitterPosition;
	UPROPERTY()							bool						bIsLAN;										//var bool bIsLAN;
	UPROPERTY()							UAABrowser_PlayersList*		PlayersList;								//var AABrowser_PlayersList PlayersList;
	UPROPERTY()							UAABrowser_PlayersListBox*	PlayersListBox;								//var AABrowser_PlayersListBox PlayersListBox;
	UPROPERTY()							UAABrowser_RulesList*		RulesList;									//var AABrowser_RulesList RulesList;
	UPROPERTY()							UAABrowser_RulesListBox*	RulesListBox;								//var AABrowser_RulesListBox RulesListBox;
	UPROPERTY()							UAABrowser_ServersList*		serverList;									//var AABrowser_ServersList serverList;
	UPROPERTY()							UAABrowser_ServerListBox*	ServerListBox;								//var AABrowser_ServerListBox ServerListBox;
	UPROPERTY()							UGUISplitter*				Rules_PlayersSplitter;						//var XInterface.GUISplitter Rules_PlayersSplitter;
	UPROPERTY(EditAnywhere)				UGUISplitter*				ServerList_RulesPlayersSplitter;			//var() XInterface.GUISplitter ServerList_RulesPlayersSplitter;

	void OnUpdateServerList();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void Clear();
	void ReceivedServer(int32 Data);
	void JoinCurrentlySelectedServer();
	void InitServerList();
	void InternalServerListChanged(UGUIComponent* Sender);
	void RefreshServerRulesAndPlayersList(int32 ServerIndex);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	TArray<float> GetColumnSizes(UGUIMultiColumnListBox* ListBox);
	void InternalOnRulesListColumnSized(int32 Column);
	void InternalOnPlayersListColumnSized(int32 Column);
	void InternalOnServerListColumnSized(int32 Column);
	FString InternalOnSaveINI(UGUIComponent* Sender);
	void SetColumnWidths(UGUIMultiColumnListBox* ListBox, TArray<float> ColumnWidthPercentages);
	void InternalOnExpand();
	void InternalOnContract();
	void InternalOnReleaseSplitter(UGUIComponent* Sender, float NewPos);
	bool InternalOnGetServerRules(int32& ItemIndex, FGameSpyServerItem& ServerItem);
	bool InternalOnGetPlayer(FGameSpyPlayerInfo& PlayerInfo, int32 Index);
	void InternalOnUpdateServerList();
	void SelectServerByIP(FString IPAddress, int32 Port);
};
