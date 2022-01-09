// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI_Primitive.generated.h"

UCLASS()
class AAI_Primitive : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAI_Primitive();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
