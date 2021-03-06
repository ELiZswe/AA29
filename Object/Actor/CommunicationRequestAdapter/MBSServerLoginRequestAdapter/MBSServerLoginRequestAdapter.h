// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MBSServerLoginRequestAdapter.generated.h"

UCLASS()
class AMBSServerLoginRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSServerLoginRequestAdapter();

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, FString IPAddress, int32 HostPort, int32 QueryPort, int32 MaxPlayers);
	void AdaptResults();

};
