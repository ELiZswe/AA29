// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AGP_MessageTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_MessageTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	AAGP_MessageTrigger();

	UPROPERTY(EditAnywhere)										FString Line1;							//var() string Line1;
	UPROPERTY(EditAnywhere)										FString Line2;							//var() string Line2;
	UPROPERTY(EditAnywhere)										float FadeTime;							//var() float FadeTime;
	UPROPERTY(EditAnywhere)										bool bRemoveMessageOnUnTouch;			//var() bool bRemoveMessageOnUnTouch;

	void Touch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTouch(AActor* Other);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
};
