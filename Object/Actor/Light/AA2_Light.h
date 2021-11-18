// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "AA2_Light.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAA2_Light : public ALight
{
	GENERATED_BODY()
public:
	AAA2_Light();

	UPROPERTY(EditAnywhere, Category = "Corona")										bool bCorona;								//var(Corona) bool bCorona
	UPROPERTY(EditAnywhere, Category = "Corona")										bool UseOwnFinalBlend;						//var(Corona) bool UseOwnFinalBlend;
	UPROPERTY(EditAnywhere, Category = "Corona")										float CoronaRotationOffset;					//var(Corona) float CoronaRotationOffset;
	UPROPERTY(EditAnywhere, Category = "Corona")										float CoronaRotation;						//var(Corona) float CoronaRotation;
	UPROPERTY(EditAnywhere, Category = "Corona")										float MaxCoronaSize;						//var(Corona) float MaxCoronaSize;
	UPROPERTY(EditAnywhere, Category = "Corona")										float MinCoronaSize;						//var(Corona) float MinCoronaSize;



	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;


	void LoadEditorIcon();
};
