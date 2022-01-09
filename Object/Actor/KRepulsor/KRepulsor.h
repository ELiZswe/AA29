// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "KRepulsor.generated.h"

UCLASS()
class AKRepulsor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AKRepulsor();

	UPROPERTY()										Fpointer KContact;				//var const transient pointer KContact;
	UPROPERTY(EditAnywhere)							float PenOffset; 				//var() float PenOffset;
	UPROPERTY(EditAnywhere)							float PenScale; 				//var() float PenScale;
	UPROPERTY(EditAnywhere)							float Softness; 				//var() float Softness;
	UPROPERTY(EditAnywhere)							float CheckDist; 				//var() float CheckDist;
	UPROPERTY(EditAnywhere)							FVector CheckDir; 				//var() Object.Vector CheckDir;
	UPROPERTY()										bool bRepulsorOnWater;			//var bool bRepulsorOnWater;
	UPROPERTY()										bool bRepulsorInContact; 		//var bool bRepulsorInContact;
	UPROPERTY(EditAnywhere)							bool bRepulseWater; 			//var() bool bRepulseWater;
	UPROPERTY(EditAnywhere)							bool bEnableRepulsion; 			//var() bool bEnableRepulsion;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
