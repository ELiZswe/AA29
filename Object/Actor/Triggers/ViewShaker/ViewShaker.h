// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "ViewShaker.generated.h"

UCLASS()
class AViewShaker : public ATriggers
{
	GENERATED_BODY()
public:
	AViewShaker();

	UPROPERTY(EditAnywhere)			float		ShakeRadius;				//var() float ShakeRadius;
	UPROPERTY(EditAnywhere)			FVector		RotMag;						//var() Vector RotMag;
	UPROPERTY(EditAnywhere)			FVector		RotRate;					//var() Vector RotRate;
	UPROPERTY(EditAnywhere)			float		RotTime;					//var() float RotTime;
	UPROPERTY(EditAnywhere)			FVector		OffsetMag;					//var() Vector OffsetMag;
	UPROPERTY(EditAnywhere)			FVector		OffsetRate;					//var() Vector OffsetRate;
	UPROPERTY(EditAnywhere)			float		OffsetTime;					//var() float OffsetTime;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
