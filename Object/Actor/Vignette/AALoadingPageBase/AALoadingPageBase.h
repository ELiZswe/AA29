// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Vignette/Vignette.h"
#include "AALoadingPageBase.generated.h"

class UDrawOpImage;
class UDrawOpText;
class UDrawOpBase;

UCLASS()
class AAALoadingPageBase : public AVignette
{
	GENERATED_BODY()
public:
	AAALoadingPageBase();
	
	UPROPERTY()		TArray<UDrawOpBase*> Operations;				//var TArray<DrawOpBase> Operations;

	void DrawVignette(UCanvas* C, float Progress);
	UDrawOpImage* AddImage(UMaterialInstance* Image, float Top, float Left, float Height, float Width);
	UDrawOpImage* AddImageStretched(UMaterialInstance* Image, float Top, float Left, float Height, float Width);
	UDrawOpText* AddText(FString Text, float Top, float Left);
	UDrawOpText* AddMultiLineText(FString Text, float Top, float Left, float Height, float Width);
	UDrawOpText* AddJustifiedText(FString Text, uint8 Just, float Top, float Left, float Height, float Width, uint8 VAlign);
	UMaterialInstance* DLOTexture(FString TextureFullName);

};
