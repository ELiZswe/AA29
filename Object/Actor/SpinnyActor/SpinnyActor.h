// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinnyActor.generated.h"

UCLASS()
class AA29_API ASpinnyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinnyActor();

	UPROPERTY(EditAnywhere)								int32 spinRate;						//var() int32 spinRate;
	UPROPERTY()											float CurrentTime;					//var float CurrentTime;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
