// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Jav_Target.generated.h"

UCLASS()
class AJav_Target : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AJav_Target();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
