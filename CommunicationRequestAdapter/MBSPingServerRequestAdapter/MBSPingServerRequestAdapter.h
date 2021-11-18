// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MBSPingServerRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMBSPingServerRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSPingServerRequestAdapter();

	UPROPERTY()						int32 ServerPort;							//var int ServerPort;
	UPROPERTY()						int32 ServerIP;								//var int ServerIP;
	UPROPERTY()						int32 PingTimeMS;							//var int PingTimeMS;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString IPAddress, int32 QueryPort, int32 aServerPort);
	void AdaptResults();

};
