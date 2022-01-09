// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehiclePart.generated.h"

UCLASS()
class AVehiclePart : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AVehiclePart();

	UPROPERTY()				bool bUpdating;				//var bool bUpdating;

	void update(float DeltaTime);
	void Activate(bool bActive);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
