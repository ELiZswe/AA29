// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "TriggerHide.generated.h"

UCLASS()
class ATriggerHide : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ATriggerHide();

	UPROPERTY()									AActor* A;					//var Actor A;
	UPROPERTY(EditAnywhere)						FName HideTag;				//var() name HideTag;


	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);

};
