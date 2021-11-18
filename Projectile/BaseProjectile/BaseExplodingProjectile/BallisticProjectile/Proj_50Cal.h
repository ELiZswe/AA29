// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/BallisticProjectile.h"
#include "Proj_50Cal.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AProj_50Cal : public ABallisticProjectile
{
	GENERATED_BODY()
public:
	AProj_50Cal(const FObjectInitializer& ObjectInitializer);

	//var Emitter TracerEmitter;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* TracerEmitter;

	//var class<Emitter> cTracerClass;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* cTracerClass;

	//var class<Emitter> MetalImpactEmitter;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* MetalImpactEmitter;

};
