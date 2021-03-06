// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "MissionCompleteRequestAdapter.generated.h"

UCLASS()
class AMissionCompleteRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AMissionCompleteRequestAdapter();

	UPROPERTY()						FAuthJacket Jacket;									//var PlayerController.AuthJacket Jacket;
	UPROPERTY()						TArray<FString> ExtraMissionData;					//var TArray<FString> ExtraMissionData;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, int32 Tour, int32 Mission, int32 Marksmanship, bool passFail, TArray<int32> DistributionHistory, FString IPAddress);
	void AdaptResults();
	void AddExtraMissionData(FString Data);
};
