// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AAGUITabControl.generated.h"

class UGUITabPanel;

UCLASS()
class AA29_API UAAGUITabControl : public UGUITabControl
{
	GENERATED_BODY()
public:
	UAAGUITabControl();


	UPROPERTY(EditAnywhere)									FString		ButtonStyleName;					//var() FString ButtonStyleName;
	UPROPERTY(EditAnywhere)									float		TabHSpacing;						//var() float TabHSpacing;
	UPROPERTY(EditAnywhere)									float		TabVSpacing;						//var() float TabVSpacing;
	UPROPERTY(EditAnywhere)									float		UniformTabWidth;					//var() float UniformTabWidth;
	UPROPERTY(EditAnywhere)									float		TabIndent;							//var() float TabIndent;
	UPROPERTY()												int32		BeginOppositeRowIndex;				//var int32 BeginOppositeRowIndex;

	UGUITabPanel* AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive);
};
