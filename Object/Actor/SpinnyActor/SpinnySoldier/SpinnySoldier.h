// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SpinnyActor/SpinnyActor.h"
#include "SpinnySoldier.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASpinnySoldier : public ASpinnyActor
{
	GENERATED_BODY()
public:
	ASpinnySoldier();



	UPROPERTY(EditAnywhere)								bool bPlayRandomAnims;					//var() bool bPlayRandomAnims;
	UPROPERTY(EditAnywhere)								bool bPlayCrouches;						//var() bool bPlayCrouches;
	UPROPERTY(EditAnywhere)								float AnimChangeInterval;				//var() float AnimChangeInterval;
	UPROPERTY(EditAnywhere)								TArray<FName> AnimNames;				//var() TArray<FName> AnimNames;
	UPROPERTY()											int32 NextAnimTime;						//var float NextAnimTime;

	void PostBeginPlay();
	void Tick(float Delta);
	void AnimEnd(int32 Channel);
	void PlayNextAnim();

};
