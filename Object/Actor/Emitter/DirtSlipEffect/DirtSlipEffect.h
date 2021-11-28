// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "DirtSlipEffect.generated.h"

class ASVehicleWheel;

UCLASS()
class AA29_API ADirtSlipEffect : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ADirtSlipEffect();

	UPROPERTY(EditAnywhere)						int32			MaxSpritePPS;					//var() int32 MaxSpritePPS;
	UPROPERTY(EditAnywhere)						int32			MaxMeshPPS;						//var() int32 MaxMeshPPS;
	UPROPERTY(EditAnywhere)						USoundBase*		DirtSlipSound;					//var() Sound DirtSlipSound;

	void SetDirtColor(FColor DirtColor);
	void UpdateDust(ASVehicleWheel* t, float DustSlipRate, float DustSlipThresh);
};
