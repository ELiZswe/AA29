// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NetworkTrigger.generated.h"

UCLASS()
class AA29_API ANetworkTrigger : public AActor
{
	GENERATED_BODY()

	UPROPERTY()				uint8 TriggerCount;				//var uint8 TriggerCount;
	UPROPERTY()				uint8 OldTriggerCount;			//var uint8 OldTriggerCount;
	UPROPERTY()				uint8 ResetCount;				//var uint8 ResetCount;
	UPROPERTY()				uint8 OldResetCount;			//var uint8 OldResetCount;
	UPROPERTY()				bool bNotFirstCall;				//var bool bNotFirstCall;

	void PostNetBeginPlay();
	void UpdateTriggerCount();
	void PostNetReceive();
	void DoClientReset();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Reset();

public:	
	// Sets default values for this actor's properties
	ANetworkTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
