// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "NetworkEmitter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANetworkEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ANetworkEmitter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNotFirstCall;			//var bool bNotFirstCall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 OldResetCount;		//var byte OldResetCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 ResetCount;			//var byte ResetCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 OldTriggerCount;		//var byte OldTriggerCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 TriggerCount;			//var byte TriggerCount

};
