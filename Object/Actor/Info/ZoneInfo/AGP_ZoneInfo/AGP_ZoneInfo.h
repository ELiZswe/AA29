// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AGP_ZoneInfo.generated.h"

UCLASS()
class AAGP_ZoneInfo : public AZoneInfo
{
	GENERATED_BODY()
public:
	AAGP_ZoneInfo();
	
	UPROPERTY(EditAnywhere)			bool				bMoveAGPProjectiles;		//var() bool bMoveAGPProjectiles;
	UPROPERTY(EditAnywhere)			bool				bMoveAGPParticles;			//var() bool bMoveAGPParticles;
	UPROPERTY(EditAnywhere)			bool				bUpdateSystem;				//var() bool bUpdateSystem;
	UPROPERTY(EditAnywhere)			FVector				vMeanWind;					//var() Vector vMeanWind;
	UPROPERTY(EditAnywhere)			float				fPitchMaxDev;				//var() float fPitchMaxDev;
	UPROPERTY(EditAnywhere)			float				fPitchFalloff;				//var() float fPitchFalloff;
	UPROPERTY(EditAnywhere)			float				fPitchMean;					//var() float fPitchMean;
	UPROPERTY(EditAnywhere)			float				fYawMaxDev;					//var() float fYawMaxDev;
	UPROPERTY(EditAnywhere)			float				fYawFalloff;				//var() float fYawFalloff;
	UPROPERTY(EditAnywhere)			float				fYawMean;					//var() float fYawMean;
	UPROPERTY(EditAnywhere)			float				fSpeedMaxDev;				//var() float fSpeedMaxDev;
	UPROPERTY(EditAnywhere)			float				fSpeedFalloff;				//var() float fSpeedFalloff;
	UPROPERTY(EditAnywhere)			float				fSpeedMean;					//var() float fSpeedMean;
	UPROPERTY(EditAnywhere)			float				fVarianceTime;				//var() float fVarianceTime;
	UPROPERTY(EditAnywhere)			float				fBaseVarianceTime;			//var() float fBaseVarianceTime;
	UPROPERTY(EditAnywhere)			bool				bRandVariance;				//var() bool bRandVariance;
	UPROPERTY()						FVector				vWind;						//var transient Vector vWind;
	UPROPERTY()						FRotator			rBase;						//var transient Rotator rBase;

	void BeginPlay();
	void ActorEntered(AActor* Other);
	void ActorLeaving(AActor* Other);
	void Timer();
	void UpdateWind();
	FVector CalcWind();
};
