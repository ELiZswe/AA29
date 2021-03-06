// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "NetworkEmitter.generated.h"

UCLASS()
class ANetworkEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ANetworkEmitter();
	UPROPERTY(EditAnywhere)		bool bNotFirstCall;			//var bool bNotFirstCall;
	UPROPERTY(EditAnywhere)		uint8 OldResetCount;		//var byte OldResetCount;
	UPROPERTY(EditAnywhere)		uint8 ResetCount;			//var byte ResetCount;
	UPROPERTY(EditAnywhere)		uint8 OldTriggerCount;		//var byte OldTriggerCount;
	UPROPERTY(EditAnywhere)		uint8 TriggerCount;			//var byte TriggerCount

	void PostNetBeginPlay();
	void UpdateTriggerCount();
	void PostNetReceive();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Reset();
};
