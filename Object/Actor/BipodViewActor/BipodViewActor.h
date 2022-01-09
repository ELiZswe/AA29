// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BipodViewActor.generated.h"

UCLASS()
class ABipodViewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABipodViewActor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
