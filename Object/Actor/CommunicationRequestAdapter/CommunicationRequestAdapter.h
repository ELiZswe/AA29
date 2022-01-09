// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "CommunicationRequestAdapter.generated.h"

UCLASS()
class ACommunicationRequestAdapter : public AActor
{
	GENERATED_BODY()
public:	
	
	ACommunicationRequestAdapter();

	UPROPERTY()						TArray<FString>	ErrorMessages;						//var localized string ErrorMessages;
	UPROPERTY(globalconfig)			bool			HighPriority;						//var globalconfig bool HighPriority;
	UPROPERTY(globalconfig)			int32			FailAllAuthRequestsResultCode;		//var globalconfig int FailAllAuthRequestsResultCode;
	UPROPERTY(globalconfig)			bool			bFailAllAuthRequests;				//var globalconfig bool bFailAllAuthRequests;
	UPROPERTY()						float			fpWaitForCommResponseTime;			//var float fpWaitForCommResponseTime;
	UPROPERTY()						float			RetryTimeoutDuration;				//var float RetryTimeoutDuration;
	UPROPERTY()						float			RetryTimeout;						//var float RetryTimeout;
	UPROPERTY()						int32			RetryCountMax;						//var int RetryCountMax;
	UPROPERTY()						int32			RetryCount;							//var int RetryCount;
	UPROPERTY()						int32			ResultCode;							//var int ResultCode;
	UPROPERTY()						int32			BytesReceived;						//var const int BytesReceived;
	UPROPERTY()						Fpointer		CommunicationRequest;				//var const native transient pointer CommunicationRequest;

	bool RequestConnectionFailed();
	bool RequestIsComplete();
	void UpdateBytesReceived();
	bool RequestWasSuccessful();
	void AdaptResults();
	void Retry();
	void DestroyRequest();;
	FString GetErrorMessage(int32 aResultCode);
	void GetFailureReasons(FString& Reason, FString& ShortReason);
	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void BeginState();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
};
