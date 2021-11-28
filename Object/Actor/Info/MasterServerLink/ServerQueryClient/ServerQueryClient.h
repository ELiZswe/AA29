// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/MasterServerLink/MasterServerLink.h"
#include "ServerQueryClient.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AServerQueryClient : public AMasterServerLink
{
	GENERATED_BODY()
public:
	AServerQueryClient();

	UPROPERTY()					bool bLANQuery;												//var bool bLANQuery;

	void OnReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void OnPingTimeout(int32 ListID, EPingCause PingCause);
	void PingServer(int32 ListID, EPingCause PingCause, FString IP, int32 Port, EQueryInterfaceCommand Command, FServerResponseLine CurrentState);
	void CancelPings();
	bool NetworkError();
	void BroadcastPingRequest();
	
};
