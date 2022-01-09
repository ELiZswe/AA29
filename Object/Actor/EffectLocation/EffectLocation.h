// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectLocation.generated.h"

UCLASS()
class AEffectLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEffectLocation();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
