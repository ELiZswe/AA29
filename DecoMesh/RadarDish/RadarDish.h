// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DecoMesh/DecoMesh.h"
#include "RadarDish.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARadarDish : public ADecoMesh
{
	GENERATED_BODY()
public:
	ARadarDish();


	UPROPERTY()											USoundBase* SoundSpinning;								//var Sound SoundSpinning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)			FRotator RDRotationRate;								//var() Object.Rotator RDRotationRate

	void Reset();
	void PreBeginPlay();
	virtual void BeginPlay() override;
	void Trigger(AActor* Other, APawn* EventInstigator);

};
