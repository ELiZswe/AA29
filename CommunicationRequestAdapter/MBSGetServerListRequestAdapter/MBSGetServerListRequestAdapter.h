// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MBSGetServerListRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMBSGetServerListRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMBSGetServerListRequestAdapter();

	UPROPERTY()						TArray<FGameSpyServerItem> serverList;			//var array<ServerBrowserBase.GameSpyServerItem> serverList;
	UPROPERTY()						TArray<FKeyValuePair> FilterList;				//var array<GameInfo.KeyValuePair> FilterList;
	UPROPERTY(Globalconfig)			FString version;								//var globalconfig string version;



	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void SetFilterList(TArray<FFilterItem> List);
	void Request();
	void AdaptResults();
	void GetRequestedServerAttributes(TArray<FString> &RequestedAttributes);


};
