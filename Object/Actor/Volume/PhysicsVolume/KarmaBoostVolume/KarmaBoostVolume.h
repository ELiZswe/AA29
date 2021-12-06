// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "KarmaBoostVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AKarmaBoostVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	AKarmaBoostVolume();

	UPROPERTY(EditAnywhere)			TArray<AActor*>		AffectedClasses;			//var() array<class<Actor> > AffectedClasses;
	UPROPERTY(EditAnywhere)			float				EntryAngleFactor;			//var() float EntryAngleFactor;
	UPROPERTY(EditAnywhere)			float				BoostForce;					//var() float BoostForce;
	UPROPERTY(EditAnywhere)			bool				bBoostRelative;				//var() bool bBoostRelative;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void TryBoost(AActor* Other);
	void ActivateBoost(AActor* Other);
};
