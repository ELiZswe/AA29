// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/ServerBrowserMCList.h"
#include "AABrowser_ServersList.generated.h"

class UCountryFlags;

UCLASS(Config = Game)
class UAABrowser_ServersList : public UServerBrowserMCList
{
	GENERATED_BODY()
public:
	UAABrowser_ServersList();

	UPROPERTY()										UCountryFlags*				FlagIcons;						//var CountryFlags FlagIcons;
	UPROPERTY(config)								FString						ServerPassword;					//var config string ServerPassword;
	UPROPERTY()										bool						bIsLAN;							//var bool bIsLAN;
	UPROPERTY()										bool						bRetrievalFailed;				//var bool bRetrievalFailed;
	UPROPERTY()										TArray<FReport>				reports;						//var array<Report> reports;
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*>	TourIcons;						//var() array<Material> TourIcons;
	UPROPERTY(EditAnywhere)							TArray<FString>				IconDescriptions;				//var() localized array<String> IconDescriptions;
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*>	Icons;							//var() array<Material> Icons;
	UPROPERTY(EditAnywhere)							bool						bInitialized;					//var() bool bInitialized;
	UPROPERTY(EditAnywhere)							bool						bPresort;						//var() bool bPresort;
	UPROPERTY(EditAnywhere)							int32						RedialId;						//var() int RedialId;
	UPROPERTY(EditAnywhere)							int32						NumPlayers;						//var() int NumPlayers;
	UPROPERTY(EditAnywhere)							int32						NumReceivedPings;				//var() int NumReceivedPings;
	UPROPERTY(EditAnywhere)							int32						PingStart;						//var() int PingStart;
	UPROPERTY(EditAnywhere)							int32						UseSimultaneousPings;			//var() int UseSimultaneousPings;
	UPROPERTY(EditAnywhere)							TArray<int32>				OutstandingPings;				//var() array<int> OutstandingPings;
	UPROPERTY(EditAnywhere)							TArray<FServerResponseLine>	Servers;						//var() array<GameInfo.ServerResponseLine> Servers;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	int32 CurrentListId();
	void AddPingReport(int32 Id, FString S);
	void AddReceiveReport(int32 Id, FString S);
	FString getreportsortstring(int32 idx);
	void logall();
	void Clear();
	void CopyServerToClipboard();
	void Connect(bool Spectator, FString AdminPassword, bool bPlayerAdminPassword);
	bool MyOnDblClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void MyOnReceivedServer(FServerResponseLine S);
	void MyOnReceivedSB(int32 Data);
	void MyOnUpdateServerListFailed(FString Reason);
	void MyPingTimeout(int32 ListID, EPingCause PingCause);
	void MyReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void RePingServers();
	void FakeFinished();
	void MyQueryFinished(EResponseInfo ResponseInfo, int32 Info);
	void InvalidatePings();
	void AutopingServers();
	void StopPings();
	int32 RemoveServerAt(int32 pos);
	int32 RemoveCurrentServer();
	FString GetSortString(int32 i);
	FString Get(bool bGuarantee);
	bool GetCurrent(FServerResponseLine& S);
	int32 FindIndex(FString IP, FString Port);
	bool IsValid();
	bool IsValidIndex(int32 Test);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	FString BuildFlagString(int32 Flags);
	bool CanConnect();
	void InternalOnCloseGetPassword(bool bCancelled);
	void SetServerPassword(FString Password);
	bool IsOnFavoritesList(FGameSpyServerItem ServerItem);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool TestGroups(FString Groups);
	void SBRePingAllServers();
	void OnSortChanged();
};
