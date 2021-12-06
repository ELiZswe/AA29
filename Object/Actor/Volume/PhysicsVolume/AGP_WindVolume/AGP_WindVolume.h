// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "AGP_WindVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_WindVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	AAGP_WindVolume();

	UPROPERTY()						FRotator rBase;						//var transient Object.Rotator rBase;
	UPROPERTY()						FVector vWind;						//var transient FVector vWind;
	UPROPERTY(EditAnywhere)			bool bRandVariance;					//var() bool bRandVariance;
	UPROPERTY(EditAnywhere)			float fBaseVarianceTime;			//var() float fBaseVarianceTime;
	UPROPERTY(EditAnywhere)			float fVarianceTime;				//var() float fVarianceTime;
	UPROPERTY(EditAnywhere)			float fSpeedMean;					//var() float fSpeedMean;
	UPROPERTY(EditAnywhere)			float fSpeedFalloff;				//var() float fSpeedFalloff;
	UPROPERTY(EditAnywhere)			float fSpeedMaxDev;					//var() float fSpeedMaxDev;
	UPROPERTY(EditAnywhere)			float fYawMean;						//var() float fYawMean;
	UPROPERTY(EditAnywhere)			float fYawFalloff;					//var() float fYawFalloff;
	UPROPERTY(EditAnywhere)			float fYawMaxDev;					//var() float fYawMaxDev;
	UPROPERTY(EditAnywhere)			float fPitchMean;					//var() float fPitchMean;
	UPROPERTY(EditAnywhere)			float fPitchFalloff;				//var() float fPitchFalloff;
	UPROPERTY(EditAnywhere)			float fPitchMaxDev;					//var() float fPitchMaxDev;
	UPROPERTY(EditAnywhere)			FVector vMeanWind;					//var() FVector vMeanWind;
	UPROPERTY(EditAnywhere)			bool bUpdateSystem;					//var() bool bUpdateSystem;
	UPROPERTY(EditAnywhere)			bool bMoveAGPParticles;				//var() bool bMoveAGPParticles;
	UPROPERTY(EditAnywhere)			bool bMoveAGPProjectiles;			//var() bool bMoveAGPProjectiles;
	/*
	replication
	{
		reliable if((Role == ROLE_Authority))
			vWind;
	}
	*/

	void BeginPlay();
	void ActorEnteredVolume(AActor* Other);
	void ActorLeavingVolume(AActor* Other);
	void Timer();
	void UpdateWind();
	FVector CalcWind();
};
