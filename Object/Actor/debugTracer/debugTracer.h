// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "debugTracer.generated.h"

UCLASS()
class AdebugTracer : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AdebugTracer();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
