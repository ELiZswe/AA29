// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIScrollingText.generated.h"

UCLASS()
class UGUIScrollingText : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIScrollingText();

	UPROPERTY(EditAnywhere, Category = "Menu")		FString				Caption;				//var(Menu) localized FString Caption;
	UPROPERTY(EditAnywhere, Category = "Menu")		EeTextAlign			TextAlign;				//var(Menu) GUI.eTextAlign TextAlign;
	UPROPERTY(EditAnywhere, Category = "Menu")		FColor				TextColor;				//var(Menu) Color TextColor;
	UPROPERTY(EditAnywhere, Category = "Menu")		FColor				FocusedTextColor;		//var(Menu) Color FocusedTextColor;
	UPROPERTY(EditAnywhere, Category = "Menu")		EMenuRenderStyle	TextStyle;				//var(Menu) GUI.EMenuRenderStyle TextStyle;
	UPROPERTY(EditAnywhere, Category = "Menu")		FString				TextFont;				//var(Menu) FString TextFont;
	UPROPERTY(EditAnywhere, Category = "Menu")		bool				bTransparent;			//var(Menu) bool bTransparent;
	UPROPERTY(EditAnywhere, Category = "Menu")		bool				bMultiLine;				//var(Menu) bool bMultiLine;
	UPROPERTY(EditAnywhere, Category = "Menu")		FColor				BackColor;				//var(Menu) Color BackColor;
	UPROPERTY()										TArray<FString>		Content;				//var localized TArray<FString> Content;
	UPROPERTY()										float				ScrollRate;				//var float ScrollRate;
	UPROPERTY()										float				LastDrawTime;			//var float LastDrawTime;
	UPROPERTY()										float				StartTime;				//var float StartTime;
	UPROPERTY()										int32				TopLine;				//var int32 TopLine;

	void AddLine(FString sString);
	void LoadTextFromFile(FString Filename);
};
