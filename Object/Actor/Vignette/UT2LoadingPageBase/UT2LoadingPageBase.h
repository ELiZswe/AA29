// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Vignette/Vignette.h"
#include "UT2LoadingPageBase.generated.h"

class UDrawOpBase;
class UDrawOpImage;
class UDrawOpText;

/**
 * 
 */
UCLASS()
class AA29_API AUT2LoadingPageBase : public AVignette
{
	GENERATED_BODY()
public:
	AUT2LoadingPageBase();

	UPROPERTY(EditAnywhere)		TArray<UDrawOpBase*>				Operations;			//var TArray<DrawOpBase> Operations;

	void DrawVignette(UCanvas* C, float Progress);
	UDrawOpImage* AddImage(UMaterialInstance* Image, float Top, float Left, float Height, float Width);
	UDrawOpImage* AddImageStretched(UMaterialInstance* Image, float Top, float Left, float Height, float Width);
	UDrawOpText* AddText(FString Text, float Top, float Left);
	UDrawOpText* AddMultiLineText(FString Text, float Top, float Left, float Height, float Width);
	UDrawOpText* AddJustifiedText(FString Text, uint8 Just, float Top, float Left, float Height, float Width, uint8 VAlign);
	UMaterialInstance* DLOTexture(FString TextureFullName);
};
