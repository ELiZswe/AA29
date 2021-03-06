// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "BaseTracer.generated.h"

class AEmitter;

UCLASS()
class ABaseTracer : public ABaseProjectile
{
	GENERATED_BODY()
public:
	ABaseTracer(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)		AEmitter* EmitterFX;					//var Emitter EmitterFX;
	UPROPERTY(EditAnywhere)		AEmitter* cEnemyEmitterFXClass;			//var class<Emitter> cEnemyEmitterFXClass;
	UPROPERTY(EditAnywhere)		AEmitter* cEmitterFXClass;				//var class<Emitter> cEmitterFXClass;

	void Destroyed();
	void PostNetBeginPlay();
	void Collision(AActor* Other, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
};
