// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "RelayTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARelayTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ARelayTrigger();

	UPROPERTY(EditAnywhere)								TArray<FName> Events;						//var() array<name> Events;
	UPROPERTY(EditAnywhere)								float Delay;								//var() float Delay;
	UPROPERTY(EditAnywhere)								bool bRandomRelay;							//var() bool bRandomRelay;
	UPROPERTY(EditAnywhere, Category = "aaHelp")		TArray<FString> RelayTriggerHelp;			//var(aaHelp) const editconst string RelayTriggerHelp;


	void Trigger(AActor* Other, APawn* EventInsigator);
	void Timer();
	void RandomRelay();
	void StandardRelay();

};
