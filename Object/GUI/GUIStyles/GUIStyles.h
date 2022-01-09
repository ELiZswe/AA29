// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUI.h"
#include "AA29/MyEnums.h"
#include "GUIStyles.generated.h"

class UGUIFont;

UCLASS()
class UGUIStyles : public UGUI
{
	GENERATED_BODY()
public:
	UGUIStyles();

	UPROPERTY(EditAnywhere, Category = "Style")											bool bTemporary;								//var(Style) bool bTemporary;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<int32> BorderOffsets;					//var(Style) int BorderOffsets;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<float> ImgHeights;						//var(Style) float ImgHeights;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<float> ImgWidths;						//var(Style) float ImgWidths;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<EImgStyle> ImgStyle;						//var(Style) GUI.eImgStyle ImgStyle;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<UMaterialInstance*> Images;				//var(Style) Material Images;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<EMenuRenderStyle> RStyles;				//var(Style) GUI.EMenuRenderStyle RStyles;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<FColor> ImgColors;						//var(Style) Object.Color ImgColors;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<FColor> FontBKColors;					//var(Style) Object.Color FontBKColors;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<FColor> FontColors;						//var(Style) Object.Color FontColors;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<UGUIFont*> Fonts;						//var(Style) GUIFont Fonts;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<FString> FontNames;						//var(Style) string FontNames;
	UPROPERTY(EditAnywhere, Category = "Style")											TArray<FString> AlternateKeyName;				//var(Style) const string AlternateKeyName;
	UPROPERTY(EditAnywhere, Category = "Style")											FString KeyName;								//var(Style) const string KeyName;

	void OnDraw(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height);
	void OnDrawText(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height, ETextAlign Align, FString Text, EFontScale FontScale);
	void Draw(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height);
	void DrawText(UCanvas* Canvas, EMenuState MenuState, float Left, float Top, float Width, float Height, ETextAlign Align, FString Text, EFontScale FontScale);
	void TextSize(UCanvas* Canvas, EMenuState MenuState, FString Text, float& XL, float& YL, EFontScale FontScale);
	void Initialize();
};
