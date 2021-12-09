// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "CommunicationRequestAdapter.generated.h"

UCLASS()
class AA29_API ACommunicationRequestAdapter : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ACommunicationRequestAdapter();

	UPROPERTY()						TArray<FString> ErrorMessages;						//var localized string ErrorMessages;
	UPROPERTY(globalconfig)			bool HighPriority;									//var globalconfig bool HighPriority;
	UPROPERTY(globalconfig)			int32 FailAllAuthRequestsResultCode;				//var globalconfig int FailAllAuthRequestsResultCode;
	UPROPERTY(globalconfig)			bool bFailAllAuthRequests;							//var globalconfig bool bFailAllAuthRequests;
	UPROPERTY()						float fpWaitForCommResponseTime;					//var float fpWaitForCommResponseTime;
	UPROPERTY()						float RetryTimeoutDuration;							//var float RetryTimeoutDuration;
	UPROPERTY()						float RetryTimeout;									//var float RetryTimeout;
	UPROPERTY()						int32 RetryCountMax;								//var int RetryCountMax;
	UPROPERTY()						int32 RetryCount;									//var int RetryCount;
	UPROPERTY()						int32 ResultCode;									//var int ResultCode;
	UPROPERTY()						int32 BytesReceived;								//var const int BytesReceived;
	UPROPERTY()						Fpointer CommunicationRequest;						//var const native transient pointer CommunicationRequest;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RequestConnectionFailed();
	void RequestIsComplete();
	void UpdateBytesReceived();
	void RequestWasSuccessful();
	void AdaptResults();
	void Retry();
	void DestroyRequest();;
	void GetErrorMessage(int32 aResultCode);
	void GetFailureReasons(FString &Reason, FString &ShortReason);
	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void BeginState();


};
