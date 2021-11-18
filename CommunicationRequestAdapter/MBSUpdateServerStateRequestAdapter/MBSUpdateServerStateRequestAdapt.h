// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MBSUpdateServerStateRequestAdapt.generated.h"

/**
 * 
 */
UCLASS()
//Full name is AMBSUpdateServerStateRequestAdapter
class AA29_API AMBSUpdateServerStateRequestAdapt : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSUpdateServerStateRequestAdapt();
	UPROPERTY()						TArray<FPlayerMBSInfo> PlayerRecords;								//var array<PlayerMBSInfo> PlayerRecords;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, FString IPAddress, int32 HostPort, int32 QueryPort, int32 PlayerCount, int32 MaxPlayers, int32 AveragePlayerPing, TArray<FKeyValuePair> ServerAttributes);
	void AdaptResults();
	void AddPlayer(FString PlayerName, FString IPAddress, int32 Ping, TArray<FKeyValuePair> Attributes);

};
