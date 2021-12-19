// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Vignette/Vignette.h"
#include "AA29/MyEnums.h"
#include "TestVignette.generated.h"

class UFont;

UCLASS()
class AA29_API ATestVignette : public AVignette
{
	GENERATED_BODY()
public:
	ATestVignette();

	UPROPERTY(EditAnywhere)		TArray<FString>		Backgrounds;			//var() config TArray<FString> Backgrounds;
	UPROPERTY(EditAnywhere)		UMaterialInstance*	Background;				//var() transient Texture Background;
	UPROPERTY(EditAnywhere)		UMaterialInstance*	Logo;					//var() Texture Logo;
	UPROPERTY(EditAnywhere)		float				LogoPosX;				//var() float LogoPosX;
	UPROPERTY(EditAnywhere)		float				LogoPosY;				//var() float LogoPosY;
	UPROPERTY(EditAnywhere)		float				LogoScaleX;				//var() float LogoScaleX;
	UPROPERTY(EditAnywhere)		float				LogoScaleY;				//var() float LogoScaleY;
	UPROPERTY(EditAnywhere)		FString				LoadingFontName;		//var() localized FString LoadingFontName;
	UPROPERTY(EditAnywhere)		UFont*				LoadingFontFont;		//var() Font LoadingFontFont;
	UPROPERTY(EditAnywhere)		FString				LoadingString;			//var() localized FString LoadingString;
	UPROPERTY(EditAnywhere)		float				LoadingPosX;			//var() float LoadingPosX;
	UPROPERTY(EditAnywhere)		float				LoadingPosY;			//var() float LoadingPosY;
	UPROPERTY(EditAnywhere)		float				MapPosY;				//var() float MapPosY;
	UPROPERTY(EditAnywhere)		EDrawPivot			LoadingPivot;			//var() Object.EDrawPivot LoadingPivot;
	UPROPERTY(EditAnywhere)		FColor				LoadingColor;			//var() Color LoadingColor;

	void Init();
	void ScreenText(UCanvas* C, FString Text, float PosX, float PosY, float ScaleX, float ScaleY);
	UFont* LoadLoadingFont();
	void DrawVignette(UCanvas* C, float Progress);
};
