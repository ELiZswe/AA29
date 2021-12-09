// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "ImpactSparks.generated.h"

UCLASS()
class AA29_API AImpactSparks : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AImpactSparks();

	UPROPERTY()										bool bSparksActive;				//var bool bSparksActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* ScrapeSound;		//var() Sound ScrapeSound;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		FInterpCurve SparkRate;					//var() Object.InterpCurve SparkRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float SparkRadiusScale;			//var() float SparkRadiusScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float MaxAdditionalVelocity;	//var() float MaxAdditionalVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float AdditionalVelocityScale;	//var() float AdditionalVelocityScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float HorizontalVelocityRange;	//var() float HorizontalVelocityRange;

	void UpdateSparks(float SparkRadius, FVector VehicleVelocity);
};
