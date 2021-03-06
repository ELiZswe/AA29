// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "FadeViewTrigger.generated.h"

UCLASS()
class AFadeViewTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	AFadeViewTrigger();


	UPROPERTY(EditAnywhere, Category = "ZoneLight")		FVector				ViewFlash;				//var(ZoneLight) Vector ViewFlash;
	UPROPERTY(EditAnywhere, Category = "ZoneLight")		FVector				ViewFog;				//var(ZoneLight) Vector ViewFog;
	UPROPERTY(EditAnywhere)								FVector				TargetFlash;			//var() Vector TargetFlash;
	UPROPERTY(EditAnywhere)								bool				bTriggerOnceOnly;		//var() bool bTriggerOnceOnly;
	UPROPERTY(EditAnywhere)								float				FadeSeconds;			//var() float FadeSeconds;
	UPROPERTY()											FVector				OldViewFlash;			//var Vector OldViewFlash;
	UPROPERTY()											bool				bTriggered;				//var bool bTriggered;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
