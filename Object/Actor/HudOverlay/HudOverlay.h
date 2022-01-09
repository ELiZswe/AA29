// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HudOverlay.generated.h"

UCLASS()
class AHudOverlay : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHudOverlay();

	void Render(UCanvas* C);
	void Destroyed();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
