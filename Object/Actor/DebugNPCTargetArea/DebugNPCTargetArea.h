// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugNPCTargetArea.generated.h"

UCLASS()
class ADebugNPCTargetArea : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADebugNPCTargetArea();

	UPROPERTY()						float					YawRate;						//var float YawRate;

	void PostBeginPlay();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
