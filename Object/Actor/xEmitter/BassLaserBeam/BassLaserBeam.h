// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/xEmitter/xEmitter.h"
#include "BassLaserBeam.generated.h"

class ABass;

UCLASS()
class ABassLaserBeam : public AxEmitter
{
	GENERATED_BODY()
public:
	ABassLaserBeam();
	UPROPERTY()								ABass* IlltemperedSeaBass;								//var Bass IlltemperedSeaBass;

	//Mine
	//UPROPERTY()					USceneComponent* Root;

	void SetBeamLocation();
	FVector SetBeamRotation();
	void Tick(float dt);
};
