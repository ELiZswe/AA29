// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_Effect.generated.h"

UCLASS()
class UAnimNotify_Effect : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Effect();

	UPROPERTY()							AActor*		LastSpawnedEffect;			//var transient Actor LastSpawnedEffect;
	UPROPERTY(EditAnywhere)				FVector		DrawScale3D;				//var() Object.Vector DrawScale3D;
	UPROPERTY(EditAnywhere)				float		DrawScale;					//var() float DrawScale;
	UPROPERTY(EditAnywhere)				FName		Tag;						//var() name Tag;
	UPROPERTY(EditAnywhere)				bool		Attach;						//var() bool Attach;
	UPROPERTY(EditAnywhere)				FRotator	OffsetRotation;				//var() Object.Rotator OffsetRotation;
	UPROPERTY(EditAnywhere)				FVector		OffsetLocation;				//var() Object.Vector OffsetLocation;
	UPROPERTY(EditAnywhere)				FName		Bone;						//var() name Bone;
	UPROPERTY(EditAnywhere)				AActor*		EffectClass;				//var() class<Actor> EffectClass;
};
