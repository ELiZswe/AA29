// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/BallisticProjectile.h"
#include "Proj_50Cal.generated.h"

class AEmitter;

UCLASS()
class AProj_50Cal : public ABallisticProjectile
{
	GENERATED_BODY()
public:
	AProj_50Cal(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()		AEmitter*	MetalImpactEmitter;		//var class<Emitter> MetalImpactEmitter;
	UPROPERTY()		AEmitter*	TracerEmitter;			//var Emitter TracerEmitter;
	UPROPERTY()		AEmitter*	cTracerClass;			//var class<Emitter> cTracerClass;

	void Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type);
	void EmitterEffects(FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, AActor* HitActor);
};
