// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIProgressBar : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIProgressBar();

	UPROPERTY()				UMaterialInstance*			BarBack;			//var Material BarBack;
	UPROPERTY()				UMaterialInstance*			BarTop;				//var Material BarTop;
	UPROPERTY()				FColor						BarColor;			//var Color BarColor;
	UPROPERTY()				float						Low;				//var float Low;
	UPROPERTY()				float						High;				//var float High;
	UPROPERTY()				float						Value;				//var float Value;
	UPROPERTY()				float						CaptionWidth;		//var float CaptionWidth;
	UPROPERTY()				EeTextAlign					CaptionAlign;		//var GUI.eTextAlign CaptionAlign;
	UPROPERTY()				EeTextAlign					ValueRightAlign;	//var GUI.eTextAlign ValueRightAlign;
	UPROPERTY()				FString						Caption;			//var localized FString Caption;
	UPROPERTY()				FString						FontName;			//var FString FontName;
	UPROPERTY()				FString						ValueFontName;		//var FString ValueFontName;
	UPROPERTY()				float						GraphicMargin;		//var float GraphicMargin;
	UPROPERTY()				float						ValueRightWidth;	//var float ValueRightWidth;
	UPROPERTY()				bool						bShowLow;			//var bool bShowLow;
	UPROPERTY()				bool						bShowHigh;			//var bool bShowHigh;
	UPROPERTY()				bool						bShowValue;			//var bool bShowValue;
	UPROPERTY()				int32						NumDecimals;		//var int32 NumDecimals;
	UPROPERTY()				EeDrawDirection				BarDirection;		//var GUI.eDrawDirection BarDirection;

};
