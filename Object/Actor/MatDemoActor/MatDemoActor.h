// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MatDemoActor.generated.h"

UCLASS()
class AMatDemoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMatDemoActor();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
