// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "ImpactSparks.generated.h"

UCLASS()
class AImpactSparks : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AImpactSparks();

	UPROPERTY()										bool bSparksActive;				//var bool bSparksActive;
	UPROPERTY(EditAnywhere)		USoundBase* ScrapeSound;		//var() Sound ScrapeSound;
	UPROPERTY(EditAnywhere)		FAA2_InterpCurve SparkRate;					//var() Object.InterpCurve SparkRate;
	UPROPERTY(EditAnywhere)		float SparkRadiusScale;			//var() float SparkRadiusScale;
	UPROPERTY(EditAnywhere)		float MaxAdditionalVelocity;	//var() float MaxAdditionalVelocity;
	UPROPERTY(EditAnywhere)		float AdditionalVelocityScale;	//var() float AdditionalVelocityScale;
	UPROPERTY(EditAnywhere)		float HorizontalVelocityRange;	//var() float HorizontalVelocityRange;

	void UpdateSparks(float SparkRadius, FVector VehicleVelocity);
};
