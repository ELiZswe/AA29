// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "HelicopterDustCloudEffect.generated.h"

UCLASS()
class AHelicopterDustCloudEffect : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AHelicopterDustCloudEffect();

	UPROPERTY(EditAnywhere)		bool bAutoDestroyPrepped;	//var bool bAutoDestroyPrepped;
	UPROPERTY(EditAnywhere)		float DustVelThresh;		//var() float DustVelThresh;
	UPROPERTY(EditAnywhere)		int32 MaxMeshPPS;			//var() int MaxMeshPPS;
	UPROPERTY(EditAnywhere)		int32 MaxSpritePPS;			//var() int MaxSpritePPS;

	FEffectMatProps GetEffectProps(UMaterialInstance* M);
	void Timer();
	void Destroyed();
	void SetDirtColor(FColor DirtColor);
	void HideDirt();
	void ShowDirt();
	void UpdateDust(FVector vStartLocation);
	void disableEffect();
};
