// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Effects.generated.h"

UCLASS()
class AEffects : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEffects();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
