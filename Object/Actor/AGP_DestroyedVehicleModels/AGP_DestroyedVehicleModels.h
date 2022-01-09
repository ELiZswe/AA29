// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_DestroyedVehicleModels.generated.h"

UCLASS()
class AAGP_DestroyedVehicleModels : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_DestroyedVehicleModels();

	void MatchEnding();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
