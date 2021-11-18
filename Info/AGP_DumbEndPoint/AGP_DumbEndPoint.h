// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AGP_DumbEndPoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_DumbEndPoint : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAGP_DumbEndPoint();


	void Timer();
	void UpdateSystem();
	void LoadEditorIcon();

	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;

};
