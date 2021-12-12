// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugNPCTargetArea.generated.h"

UCLASS()
class AA29_API ADebugNPCTargetArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugNPCTargetArea();

	UPROPERTY()						float					YawRate;						//var float YawRate;

	void PostBeginPlay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
