// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjAttach_RocketTrail.generated.h"

UCLASS()
class AProjAttach_RocketTrail : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AProjAttach_RocketTrail();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
