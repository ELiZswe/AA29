// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AAGUIPanelHideable.h"
#include "AABrowser_FilterAndServerlistPan.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_FilterAndServerlistPan : public UAAGUIPanelHideable
{
	GENERATED_BODY()
public:
	UAABrowser_FilterAndServerlistPan();

	void OnUpdateServerList();
	void OnFiltersChanged();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetFilterSet(int32 FilterSetIndex);
	void ClearFilterSet();
	void ClearLists();
	void ShowFilterSummary();
	void ReceivedServer(int32 Data);
	void PutIntoDeploymentMode(FString sDeploymentModeMap);
	void GetGameSpyFilterString();
	void GetDBMBSFilterList();
	void JoinCurrentlySelectedServer();
	void InternalOnUpdateServerList();
	void InternalOnFiltersChanged();
};
