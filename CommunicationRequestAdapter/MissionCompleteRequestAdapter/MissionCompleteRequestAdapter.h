// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MissionCompleteRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMissionCompleteRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMissionCompleteRequestAdapter();

	UPROPERTY()						FAuthJacket Jacket;									//var PlayerController.AuthJacket Jacket;
	UPROPERTY()						TArray<FString> ExtraMissionData;					//var array<String> ExtraMissionData;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, int32 Tour, int32 Mission, int32 Marksmanship, bool passFail, TArray<int32> DistributionHistory, FString IPAddress);
	void AdaptResults();
	void AddExtraMissionData(FString Data);
};
