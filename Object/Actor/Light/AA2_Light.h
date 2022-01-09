// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "AA2_Light.generated.h"

class UBillboardComponent;
class USceneComponent;

UCLASS()
class AAA2_Light : public ALight
{
	GENERATED_BODY()
public:
	AAA2_Light();

	UPROPERTY(EditAnywhere, Category = "Corona")					bool bCorona;								//var(Corona) bool bCorona
	UPROPERTY(EditAnywhere, Category = "Corona")					bool UseOwnFinalBlend;						//var(Corona) bool UseOwnFinalBlend;
	UPROPERTY(EditAnywhere, Category = "Corona")					float CoronaRotationOffset;					//var(Corona) float CoronaRotationOffset;
	UPROPERTY(EditAnywhere, Category = "Corona")					float CoronaRotation;						//var(Corona) float CoronaRotation;
	UPROPERTY(EditAnywhere, Category = "Corona")					float MaxCoronaSize;						//var(Corona) float MaxCoronaSize;
	UPROPERTY(EditAnywhere, Category = "Corona")					float MinCoronaSize;						//var(Corona) float MinCoronaSize;

	//From Actor
	UPROPERTY(EditAnywhere)											uint8 LightType;
	UPROPERTY(EditAnywhere)											uint8 LightEffect;
	UPROPERTY(EditAnywhere)											uint8 LightHue;
	UPROPERTY(EditAnywhere)											uint8 LightSaturation;
	UPROPERTY(EditAnywhere)											uint8 LightBrightness;
	UPROPERTY(EditAnywhere)											int32 LightRadius;
	UPROPERTY(EditAnywhere)											bool bStatic;
	UPROPERTY(EditAnywhere)											bool bNoDelete;
	UPROPERTY(EditAnywhere)											bool bDynamicLight;
	UPROPERTY(EditAnywhere)											float LifeSpan;
	UPROPERTY(EditAnywhere)											int32 LightPeriod;
	UPROPERTY(EditAnywhere)											int32 LightCone;
	UPROPERTY(EditAnywhere)											bool bDirectionalCorona;
	UPROPERTY(EditAnywhere)											bool bDirectional;

	UPROPERTY(EditAnywhere)											bool bLightingVisibility;
	UPROPERTY(EditAnywhere)											float fCoronaClampDistance;
	UPROPERTY(EditAnywhere)											float fCoronaNearClampDistance;




	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;

	void LoadEditorIcon();
};
