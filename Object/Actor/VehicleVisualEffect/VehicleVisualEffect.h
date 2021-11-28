// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleVisualEffect.generated.h"

class AEmitter;

UCLASS()
class AA29_API AVehicleVisualEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleVisualEffect();

	UPROPERTY()				AEmitter* EffectEmitter;									//var Emitter EffectEmitter;

	void StartEmitter(AEmitter* Emitter, AActor* AttachActor, FName AttachBone);
	void StopEmitter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
