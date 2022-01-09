// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPCHelicopterWoundedPassenger.generated.h"

UCLASS()
class ANPCHelicopterWoundedPassenger : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ANPCHelicopterWoundedPassenger();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
