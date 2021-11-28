// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HudOverlay.generated.h"

UCLASS()
class AA29_API AHudOverlay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHudOverlay();

	void Render(UCanvas* C);
	void Destroyed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
