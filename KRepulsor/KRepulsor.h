// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KRepulsor.generated.h"

UCLASS()
class AA29_API AKRepulsor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
