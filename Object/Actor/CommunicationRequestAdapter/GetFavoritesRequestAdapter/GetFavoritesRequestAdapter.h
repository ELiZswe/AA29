// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "GetFavoritesRequestAdapter.generated.h"

UCLASS()
class AGetFavoritesRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AGetFavoritesRequestAdapter();

	UPROPERTY()						TArray<FString> serverList;								//var TArray<FString> serverList;
	UPROPERTY()						TArray<FString> BuddyList;								//var TArray<FString> BuddyList;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password);
	void AdaptResults();
	void dOnGetFavoritesRequestComplete(int32 aResultCode, TArray<FString> aBuddyList, TArray<FString> aserverList);
};
