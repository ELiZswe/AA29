// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "GUIVertTabControl.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIVertTabControl : public UGUITabControl
{
	GENERATED_BODY()
public:
	UGUIVertTabControl();


	UPROPERTY(EditAnywhere)									float		TabWidth;						//var() float TabWidth;
	UPROPERTY(EditAnywhere)									float		TabSpacing;						//var() float TabSpacing;
	UPROPERTY(EditAnywhere)									FString		ButtonStyleName;				//var() FString ButtonStyleName;

	UGUITabPanel* AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive);
};
