// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "GetRecordBriefRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGetRecordBriefRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AGetRecordBriefRequestAdapter();

	UPROPERTY()						FRecordBriefStruct RecordBrief;						//var const RecordBriefStruct RecordBrief;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, FString IPAddress, TArray<int32> DistributionHistory);
	void AdaptResults();
	void dOnGetRecordBriefComplete(int32 aResultCode, FRecordBriefStruct aRecordBrief);

};
