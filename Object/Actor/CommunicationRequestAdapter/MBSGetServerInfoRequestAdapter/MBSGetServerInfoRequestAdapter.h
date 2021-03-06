// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "MBSGetServerInfoRequestAdapter.generated.h"

UCLASS()
class AMBSGetServerInfoRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSGetServerInfoRequestAdapter();

	UPROPERTY()						TArray<FGameSpyPlayerInfo> PlayerList;						//var array<ServerBrowserBase.GameSpyPlayerInfo> PlayerList;
	UPROPERTY()						FGameSpyServerItem ServerItem;						//var FGameSpyServerItem ServerItem;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString IPAddress, int32 QueryPort);
	void AdaptResults();
};
