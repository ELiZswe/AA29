// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Projectile/BaseProjectile/BaseProjectile.h"
#include "BaseTracer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABaseTracer : public ABaseProjectile
{
	GENERATED_BODY()
public:
	ABaseTracer(const FObjectInitializer& ObjectInitializer);

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* EmitterFX;				//var Emitter EmitterFX;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* cEnemyEmitterFXClass;				//var class<Emitter> cEnemyEmitterFXClass;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AEmitter* cEmitterFXClass;				//var class<Emitter> cEmitterFXClass;
};
