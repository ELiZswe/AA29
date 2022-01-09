// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpriteSlave.generated.h"

UCLASS()
class ASpriteSlave : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASpriteSlave();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
