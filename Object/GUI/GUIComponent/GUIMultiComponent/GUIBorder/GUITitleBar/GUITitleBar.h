// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIBorder.h"
#include "GUITitleBar.generated.h"

class UGUITabControl;

UCLASS()
class AA29_API UGUITitleBar : public UGUIBorder
{
	GENERATED_BODY()
public:
	UGUITitleBar();

	UPROPERTY()						UMaterialInstance*		Effect;						//var const Material Effect;
	UPROPERTY(EditAnywhere)			bool					bDockTop;					//var() bool bDockTop;
	UPROPERTY(EditAnywhere)			bool					bUseTextHeight;				//var() bool bUseTextHeight;
	UPROPERTY(EditAnywhere)			EePageAlign				DockAlign;					//var() GUI.ePageAlign DockAlign;
	UPROPERTY()						UGUITabControl*			DockedTabs;					//var GUITabControl DockedTabs;

};
