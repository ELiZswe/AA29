// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinnyActor.generated.h"

UCLASS()
class ASpinnyActor : public AActor
{
	GENERATED_BODY()
public:	
	ASpinnyActor();

	UPROPERTY(EditAnywhere)			int32	spinRate;						//var() int32 spinRate;
	UPROPERTY()						float	CurrentTime;					//var float CurrentTime;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
