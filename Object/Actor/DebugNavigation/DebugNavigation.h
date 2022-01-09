// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugNavigation.generated.h"

UCLASS()
class ADebugNavigation : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADebugNavigation();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
