// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "Browser_ServersList.generated.h"

class UGUIStyles;
class UBrowser_PlayersList;
class UBrowser_RulesList;
class UBrowser_ServerListPageBase;
class AServerBrowser;

UCLASS()
class AA29_API UBrowser_ServersList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UBrowser_ServersList();

	UPROPERTY()						TArray<FString> IconDescriptions;						//var() localized array<String> IconDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> Icons;						//var() array<Material> Icons;
	UPROPERTY()						int32 NumPlayers;										//var int NumPlayers;
	UPROPERTY()						int32 NumReceivedPings;									//var int NumReceivedPings;
	UPROPERTY()						int32 PingStart;										//var int PingStart;
	UPROPERTY()						int32 UseSimultaneousPings;								//var int UseSimultaneousPings;
	UPROPERTY()						TArray<int32> OutstandingPings;							//var array<int> OutstandingPings;
	UPROPERTY()						UGUIStyles* SelStyle;									//var GUIStyles SelStyle;
	UPROPERTY()						UBrowser_PlayersList* MyPlayersList;					//var Browser_PlayersList MyPlayersList;
	UPROPERTY()						UBrowser_RulesList* MyRulesList;						//var Browser_RulesList MyRulesList;
	UPROPERTY()						UBrowser_ServerListPageBase* MyPage;					//var Browser_ServerListPageBase MyPage;
	UPROPERTY()						TArray<FServerResponseLine> Servers;					//var() array<GameInfo.ServerResponseLine> Servers;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Clear();
	void CopyServerToClipboard();
	void Connect(bool Spectator);
	void AddFavorite(AServerBrowser* Browser);
	bool MyOnDblClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void MyOnReceivedServer(FServerResponseLine S);
	void MyPingTimeout(int32 ListID, EPingCause PingCause);
	void MyReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void RePingServers();
	void MyQueryFinished(EResponseInfo ResponseInfo, int32 Info);
	void InvalidatePings();
	void AutopingServers();
	void StopPings();
	void Timer();
	void MyOnChange(UGUIComponent* Sender);
	int32 RemoveCurrentServer();
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	FString GetSortString(int32 i);

};
