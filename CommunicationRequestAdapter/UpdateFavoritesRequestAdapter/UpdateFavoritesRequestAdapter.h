// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "UpdateFavoritesRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AUpdateFavoritesRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AUpdateFavoritesRequestAdapter();

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void AddBuddy(FString UserName, FString Password, FString Buddy);
	void RemoveBuddy(FString UserName, FString Password, FString Buddy);
	void AddServer(FString UserName, FString Password, FString Server);
	void RemoveServer(FString UserName, FString Password, FString Server);
	void AdaptResults();
	void dOnUpdateFavoritesRequestComplete(int32 aResultCode);

};
