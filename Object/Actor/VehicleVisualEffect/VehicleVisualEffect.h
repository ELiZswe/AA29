// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleVisualEffect.generated.h"

class AEmitter;

UCLASS()
class AVehicleVisualEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AVehicleVisualEffect();

	UPROPERTY()				AEmitter* EffectEmitter;									//var Emitter EffectEmitter;

	void StartEmitter(AEmitter* Emitter, AActor* AttachActor, FName AttachBone);
	void StopEmitter();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
