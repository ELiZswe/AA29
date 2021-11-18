// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA2_Emitter/AA2_Emitter.h"
#include "HelicopterDustCloudEffect.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHelicopterDustCloudEffect : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AHelicopterDustCloudEffect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAutoDestroyPrepped;	//var bool bAutoDestroyPrepped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DustVelThresh;		//var() float DustVelThresh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MaxMeshPPS;			//var() int MaxMeshPPS;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MaxSpritePPS;			//var() int MaxSpritePPS;
};
