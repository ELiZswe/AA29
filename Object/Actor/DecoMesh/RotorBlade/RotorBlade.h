// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "RotorBlade.generated.h"

UCLASS()
class ARotorBlade : public ADecoMesh
{
	GENERATED_BODY()
public:
	ARotorBlade();

	UPROPERTY()																			float RotationTimer;								//var float RotationTimer;
	UPROPERTY(EditAnywhere)											float FullRotationTime;								//var() float FullRotationTime;
	UPROPERTY()																			USoundBase* SoundSpinning;							//var Sound SoundSpinning;
	UPROPERTY(EditAnywhere)											FRotator RDRotationRate;							//var() Object.Rotator RDRotationRate;

	virtual void BeginPlay() override;

	void Reset();
	void PreBeginPlay();
	void Timer();
	void Trigger(AActor* Other, APawn* EventInstigator);
};
