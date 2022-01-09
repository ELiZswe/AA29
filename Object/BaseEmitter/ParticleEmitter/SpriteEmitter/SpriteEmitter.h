// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/AA2_ParticleEmitter.h"
#include "SpriteEmitter.generated.h"

UCLASS()
class USpriteEmitter : public UAA2_ParticleEmitter
{
	GENERATED_BODY()
public:
	USpriteEmitter();

	UPROPERTY(EditAnywhere, Category = "Sprite")		EParticleDirectionUsage UseDirectionAs;				//var(Sprite) Enum EParticleDirectionUsage UseDirectionAs;
	UPROPERTY(EditAnywhere, Category = "Sprite")		FVector ProjectionNormal;							//var(Sprite) Vector ProjectionNormal;
	UPROPERTY()											FVector RealProjectionNormal;						//var transient Vector RealProjectionNormal;
	UPROPERTY()											bool bDisableRendering;								//var bool bDisableRendering;
	UPROPERTY()											bool bCanJavelinSeeThrough;							//var bool bCanJavelinSeeThrough;
};
