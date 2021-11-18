// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/MasterServerLink/MasterServerLink.h"
#include "AA29/AA29.h"
#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "MasterServerUplink.generated.h"

class AMasterServerGameStats;

UCLASS(Config = Game)
class AA29_API AMasterServerUplink : public AMasterServerLink
{
	GENERATED_BODY()
public:
	AMasterServerUplink();

	UPROPERTY()					TArray<FString> MSUPropDesc;										//var localized string MSUPropDesc;
	UPROPERTY()					TArray<FString> MSUPropText;										//var localized string MSUPropText;
	UPROPERTY(Globalconfig)		bool DoLANBroadcast;												//var globalconfig bool DoLANBroadcast;
	UPROPERTY(Globalconfig)		bool ServerBehindNAT;												//var globalconfig bool ServerBehindNAT;
	UPROPERTY(Globalconfig)		bool SendStats;														//var globalconfig bool SendStats;
	UPROPERTY(Globalconfig)		bool UplinkToGamespy;												//var globalconfig bool UplinkToGamespy;
	UPROPERTY()					bool DoUplink;														//var globalconfig bool DoUplink;
	UPROPERTY()					bool bReconnectPending;												//var bool bReconnectPending;
	UPROPERTY()					float ReconnectTime;												//var float ReconnectTime;
	UPROPERTY()					int32 MatchID;														//var const int MatchID;
	//UPROPERTY()					AUdpLink* GamespyQueryLink;											//var UdpLink GamespyQueryLink;
	UPROPERTY()					AMasterServerGameStats* GameStats;									//var MasterServerGameStats GameStats;
	UPROPERTY()					int32 CachePlayerCount;												//var int CachePlayerCount;
	UPROPERTY()					float CacheRefreshTime;												//var float CacheRefreshTime;
	UPROPERTY()					FServerResponseLine CachedServerState;								//var GameInfo.ServerResponseLine CachedServerState;
	UPROPERTY()					FServerResponseLine FullCachedServerState;							//var GameInfo.ServerResponseLine FullCachedServerState;
	UPROPERTY()					FServerResponseLine ServerState;									//var GameInfo.ServerResponseLine ServerState;
	UPROPERTY()					bool bInitialStateCached;											//var bool bInitialStateCached;

	void Reconnect();
	void BeginPlay();
	void ConnectionFailed(bool bShouldReconnect);
	void Refresh();
	bool LogStatLine(FString StatLine);
	void Tick(float DeltaTime);
	void FillPlayInfo(UPlayInfo* PlayInfo);
	FString GetDescriptionText(FString PropName);

};
