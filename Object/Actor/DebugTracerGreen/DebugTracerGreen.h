// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugTracerGreen.generated.h"

UCLASS()
class ADebugTracerGreen : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADebugTracerGreen();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
