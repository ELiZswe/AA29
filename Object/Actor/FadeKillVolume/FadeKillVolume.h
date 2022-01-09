// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FadeKillVolume.generated.h"

UCLASS()
class AFadeKillVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AFadeKillVolume();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
