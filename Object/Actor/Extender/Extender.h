// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Extender.generated.h"

UCLASS()
class AExtender : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AExtender();

	UPROPERTY()			AExtender* NextE;				//var Extender NextE;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
