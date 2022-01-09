// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WAttch_BlankPlug_1P.generated.h"

UCLASS()
class AWAttch_BlankPlug_1P : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWAttch_BlankPlug_1P();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
