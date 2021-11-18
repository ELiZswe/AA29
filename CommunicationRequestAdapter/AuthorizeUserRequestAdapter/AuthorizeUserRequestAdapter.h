// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "AuthorizeUserRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAuthorizeUserRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AAuthorizeUserRequestAdapter();

	UPROPERTY()						FAuthJacket Jacket;									//var PlayerController.AuthJacket Jacket;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, FString IPAddress, TArray<int32> DistributionHistory);
	void AdaptResults();
};
