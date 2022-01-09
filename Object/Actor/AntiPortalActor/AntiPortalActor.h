// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AntiPortalActor.generated.h"

UCLASS()
class AAntiPortalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAntiPortalActor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
