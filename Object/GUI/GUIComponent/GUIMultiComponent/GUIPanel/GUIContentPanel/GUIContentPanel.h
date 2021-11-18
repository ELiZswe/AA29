// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "GUIContentPanel.generated.h"

class UGUIScrollBarBase;
class UGUIComponent;

/**
 * 
 */
UCLASS()
class AA29_API UGUIContentPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UGUIContentPanel();

	UPROPERTY()								bool						bInitialPredraw;				//var bool bInitialPredraw;
	UPROPERTY()								bool						bScaleHeightToContents;			//var bool bScaleHeightToContents;
	UPROPERTY()								float						PanelSize;						//var const float PanelSize;
	UPROPERTY()								float						TopOffset;						//var float TopOffset;
	UPROPERTY(EditAnywhere)					bool						bScaleItemsToWidth;				//var() bool bScaleItemsToWidth;
	UPROPERTY(EditAnywhere)					bool						bCenterItems;					//var() bool bCenterItems;
	UPROPERTY(EditAnywhere)					float						ItemSpacing;					//var() float ItemSpacing;
	UPROPERTY(EditAnywhere)					TArray<UGUIComponent*>		Elements;						//var() array<GUIComponent> Elements;
	UPROPERTY(EditAnywhere)					UGUIScrollBarBase*			MyScrollBar;					//var() XInterface.GUIScrollBarBase MyScrollBar;

	void ScrollAlignThumb();
	UGUIComponent* AppendComponent(UGUIComponent* NewComp, bool SkipRemap);
	UGUIComponent* InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap);
	bool RemoveComponent(UGUIComponent* Comp, bool SkipRemap);
	bool ValidIndex(int32 idx);
	void GetComponent(int32 idx);
	int32 FindComponent(UGUIComponent* Component);


};
