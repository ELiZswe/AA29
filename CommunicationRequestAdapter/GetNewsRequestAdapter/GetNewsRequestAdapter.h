// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "GetNewsRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGetNewsRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AGetNewsRequestAdapter();

	UPROPERTY()						int32 Lines;								//var string Lines;
	UPROPERTY()						int32 NewsVersion;							//var int NewsVersion;




	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, int32 NewsId);
	void AdaptResults();

};
