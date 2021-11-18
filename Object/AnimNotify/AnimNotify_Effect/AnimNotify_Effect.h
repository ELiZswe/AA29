// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_Effect.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_Effect : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Effect();


	UPROPERTY()													AActor* LastSpawnedEffect;					//var transient Actor LastSpawnedEffect;
	UPROPERTY()													FVector DrawScale3D;						//var() Object.Vector DrawScale3D;
	UPROPERTY()													float DrawScale;							//var() float DrawScale;
	UPROPERTY()													FName Tag;									//var() name Tag;
	UPROPERTY()													bool Attach;								//var() bool Attach;
	UPROPERTY()													FRotator OffsetRotation;					//var() Object.Rotator OffsetRotation;
	UPROPERTY()													FVector OffsetLocation;						//var() Object.Vector OffsetLocation;
	UPROPERTY()													FName Bone;									//var() name Bone;
	UPROPERTY()													AActor* EffectClass;						//var() class<Actor> EffectClass;

};
