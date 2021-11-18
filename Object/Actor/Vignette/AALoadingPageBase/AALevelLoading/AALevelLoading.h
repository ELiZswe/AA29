// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Vignette/AALoadingPageBase/AALoadingPageBase.h"
#include "AALevelLoading.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAALevelLoading : public AAALoadingPageBase
{
	GENERATED_BODY()
public:
	AAALevelLoading();

	UPROPERTY()		UMaterialInstance*	MapScreenshot;			//var Material MapScreenshot;
	UPROPERTY()		UMaterialInstance*	ImageFrame;				//var Material ImageFrame;
	UPROPERTY()		FString				LoadingMessage;			//var localized FString LoadingMessage;
	UPROPERTY()		TArray<FString>		Backgrounds;			//var() config TArray<FString> Backgrounds;

	void Init();
	void AddBackground();
	void SetImage();
	FString StripMap(FString S);
	void SetText();

};
