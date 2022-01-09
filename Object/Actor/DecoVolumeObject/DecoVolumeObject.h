// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecoVolumeObject.generated.h"

UCLASS()
class ADecoVolumeObject : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADecoVolumeObject();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
