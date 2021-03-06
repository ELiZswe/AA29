// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MBSPingMBSServerRequestAdapter.generated.h"

UCLASS()
class AMBSPingMBSServerRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSPingMBSServerRequestAdapter();
public:
	UPROPERTY(Globalconfig)			int32 PingTimeMS;								//var int PingTimeMS;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString GameServerIPAddress);
	void AdaptResults();

};
