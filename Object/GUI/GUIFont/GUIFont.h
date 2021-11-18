// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUI.h"
#include "AA29/AA29.h"
#include "GUIFont.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIFont : public UGUI
{
	GENERATED_BODY()
public:
	UGUIFont();

	//UPROPERTY(EditAnywhere, Category = "Menu")					TArray<AFont*> FontArrayFonts;					//var(Menu) array<Font> FontArrayFonts;
	UPROPERTY(EditAnywhere, Category = "Menu")					TArray<FString> FontArrayNames;						//var(Menu) localized array<String> FontArrayNames;
	UPROPERTY(EditAnywhere, Category = "Menu")					int32 FallBackRes;									//var(Menu) int FallBackRes;
	UPROPERTY(EditAnywhere, Category = "Menu")					int32 NormalXRes;									//var(Menu) int NormalXRes;
	UPROPERTY(EditAnywhere, Category = "Menu")					bool bScaled;										//var(Menu) bool bScaled;
	UPROPERTY(EditAnywhere, Category = "Menu")					bool bFixedSize;									//var(Menu) bool bFixedSize;
	UPROPERTY(EditAnywhere, Category = "Menu")					FString KeyName;									//var(Menu) string KeyName;

	//From GUIComponent... confusing
	UPROPERTY(EditAnywhere, Category = "Menu")					bool bBoundToParent;								//var(Menu) bool bBoundToParent;
	UPROPERTY(EditAnywhere)										FString IniOption;									//var() string IniOption;
	UPROPERTY(EditAnywhere)										FString Hint;										//var() localized string Hint;
	UPROPERTY(EditAnywhere, Category = "Menu")					float WinHeight;									//var(Menu) float WinHeight;
	UPROPERTY(EditAnywhere, Category = "Menu")					float WinWidth;										//var(Menu) float WinWidth;
	UPROPERTY(EditAnywhere, Category = "Menu")					float WinLeft;										//var(Menu) float WinLeft;
	UPROPERTY(EditAnywhere, Category = "Menu")					float WinTop;										//var(Menu) float WinTop;
	UPROPERTY(EditAnywhere, Category = "Style")					FString StyleName;									//var(Style) string StyleName;


	UPROPERTY(EditAnywhere, Category = "State")					EMenuState LastMenuState;							//var(State) editconst GUI.eMenuState LastMenuState;
	UPROPERTY(EditAnywhere, Category = "State")					EMenuState MenuState;								//var(State) GUI.eMenuState MenuState;

	UPROPERTY(EditAnywhere)										float RenderWeight;									//var() float RenderWeight;

	UPROPERTY(EditAnywhere, Category = "Menu")					bool bScaleToParent;								//var(Menu) bool bScaleToParent;
	UPROPERTY(EditAnywhere, Category = "Menu")					int32 TabOrder;										//var(Menu) int TabOrder;

	UPROPERTY()													FString Caption;
	UPROPERTY()													float CaptionWidth;
	UPROPERTY()													float CharDelay;
	
	UPROPERTY()													int32 Position;
	UPROPERTY()													int32 MinValue;
	UPROPERTY()													int32 MaxValue;
	UPROPERTY()													int32 TextAlign;
	UPROPERTY()													bool bAutoShrink;
	UPROPERTY()													bool bStandardized;
	UPROPERTY()													bool bRepeatClick;
	UPROPERTY()													bool bVisible;

	//AFont* GetFont(int XRes);
	void LoadFontStatic(int32 i);
	void LoadFont(int32 i);
};
