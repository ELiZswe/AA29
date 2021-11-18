// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AABrowser_FilterSetPanel.generated.h"

class UGUIButton;
class UmoComboBox;
class UGUIImage;

UCLASS()
class AA29_API UAABrowser_FilterSetPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAABrowser_FilterSetPanel();

	UPROPERTY(EditAnywhere)							UGUIButton* ShowFilters;							//var() XInterface.GUIButton ShowFilters;
	UPROPERTY(EditAnywhere)							UGUIButton* ClearFilters;							//var() XInterface.GUIButton ClearFilters;
	UPROPERTY(EditAnywhere)							UmoComboBox* FilterSet;								//var() XInterface.moComboBox FilterSet;
	UPROPERTY(EditAnywhere)							UGUIImage* BackgroundBorder;						//var() XInterface.GUIImage BackgroundBorder;

	void OnFilterSetChanged(int32 NewFilterSet);
	void OnClearFilters();
	void OnShowFilters();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnChange(UGUIComponent* Sender);
	void InternalOnClick(UGUIComponent* Sender);
	void testonly_SetFilterSetIndex(int32 NewIndex);
	void testonly_ClearFiltersPress();
	void testonly_ShowFiltersPress();
};
