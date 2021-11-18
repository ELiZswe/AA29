// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUILabel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUILabel : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUILabel();

	UPROPERTY()														float HilightOffsetY;					//var() float HilightOffsetY;
	UPROPERTY()														float HilightOffsetX;					//var() float HilightOffsetX;
	UPROPERTY()														FColor HilightColor;					//var() Object.Color HilightColor;
	UPROPERTY()														float ShadowOffsetY;					//var() float ShadowOffsetY;
	UPROPERTY()														float ShadowOffsetX;					//var() float ShadowOffsetX;
	UPROPERTY()														FColor ShadowColor;						//var() Object.Color ShadowColor;
	UPROPERTY()														FColor BackColor;						//var() Object.Color BackColor;
	UPROPERTY()														ETextAlign VertAlign;					//var() GUI.eTextAlign VertAlign;
	UPROPERTY()														bool bMultiLine;						//var() bool bMultiLine;
	UPROPERTY()														bool bTransparent;						//var() bool bTransparent;
	UPROPERTY()														FString TextFont;						//var() string TextFont;
	UPROPERTY()														EMenuRenderStyle TextStyle;				//var() GUI.EMenuRenderStyle TextStyle;
	UPROPERTY()														FColor FocusedTextColor;				//var() Object.Color FocusedTextColor;
	UPROPERTY()														FColor TextColor;						//var() Object.Color TextColor;
	UPROPERTY()														ETextAlign TextAlign;					//var() GUI.eTextAlign TextAlign;
	UPROPERTY()														FString Caption;						//var() localized string Caption;
};
