// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Effects/Effects.h"
#include "Fragment.generated.h"

UCLASS()
class AFragment : public AEffects
{
	GENERATED_BODY()
public:
	AFragment();

	UPROPERTY(EditAnywhere)			TArray<UStaticMesh*>	Fragments;					//var() Mesh Fragments[11];
	UPROPERTY()						int32					numFragmentTypes;			//var int32 numFragmentTypes;
	UPROPERTY()						bool					bFirstHit;					//var bool bFirstHit;
	UPROPERTY(EditAnywhere)			USoundBase*				ImpactSound;				//var() Sound ImpactSound;
	UPROPERTY(EditAnywhere)			USoundBase*				AltImpactSound;				//var() Sound AltImpactSound;
	UPROPERTY(EditAnywhere)			float					SplashTime;					//var() float SplashTime;

	bool CanSplash();
	void CalcVelocity(FVector Momentum);
	void HitWall(FVector HitNormal, AActor* HitWall);
	void RandSpin(float spinRate);
};
