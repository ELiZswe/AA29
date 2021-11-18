// All the original content belonged to the US Army

#pragma once


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyStructs.h"
#include "CameraEffect.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCameraEffect : public UObject
{
	GENERATED_BODY()
public:
	UCameraEffect();


	UPROPERTY()					int32								cameraeffect_dummy;					//var int cameraeffect_dummy;
	UPROPERTY()					bool								FinalEffect;						//var bool FinalEffect;
	UPROPERTY()					float								Alpha;								//var float Alpha;
	UPROPERTY()					ECameraEffect_PipelineLocation		WhenToPostRender;					//var CameraEffect_PipelineLocation WhenToPostRender;
};

