// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleTrigger.generated.h"

UCLASS()
class AVehicleTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AVehicleTrigger();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
