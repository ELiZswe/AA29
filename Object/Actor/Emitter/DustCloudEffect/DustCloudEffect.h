// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "DustCloudEffect.generated.h"

class ASVehicleWheel;

/**
 * 
 */
UCLASS()
class AA29_API ADustCloudEffect : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ADustCloudEffect();

	UPROPERTY(EditAnywhere)				int32			MaxSpritePPS;				//var() int32 MaxSpritePPS;
	UPROPERTY(EditAnywhere)				int32			MaxMeshPPS;					//var() int32 MaxMeshPPS;
	UPROPERTY(EditAnywhere)				float			DustVelThresh;				//var() float DustVelThresh;

	FEffectMatProps GetEffectProps(UMaterialInstance* M);
	void SetDirtColor(FColor DirtColor);
	void UpdateDust(ASVehicleWheel* vw, FCoords WheelCoords, float VehicleVel);
	void disableEffect();
};
