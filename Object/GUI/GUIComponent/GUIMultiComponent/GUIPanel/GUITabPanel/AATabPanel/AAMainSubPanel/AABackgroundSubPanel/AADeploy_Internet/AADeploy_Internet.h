// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_Internet.generated.h"

class UAABrowser_PlayerServerSearchPane;
class UAABrowser_FilterAndServerlistPan;
class UAABrowser_FilterSetPanel;
class UAABrowser_UpdateJoinAndPBPanel;
class UGUILabel;

UCLASS()
class AA29_API UAADeploy_Internet : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Internet();

	UPROPERTY(EditAnywhere)			UAABrowser_FilterAndServerlistPan* FilterAndServerListPanel;			//var() automated AABrowser_FilterAndServerlistPanel FilterAndServerListPanel;
	UPROPERTY(EditAnywhere)			UAABrowser_FilterSetPanel* FilterSetPanel;								//var() automated AABrowser_FilterSetPanel FilterSetPanel;
	UPROPERTY(EditAnywhere)			UAABrowser_PlayerServerSearchPane* PlayerServerSearchPanel;				//var() automated AABrowser_PlayerServerSearchPanel PlayerServerSearchPanel;
	UPROPERTY(EditAnywhere)			UAABrowser_UpdateJoinAndPBPanel* UpdateJoinAndPBPanel;					//var() automated AABrowser_UpdateJoinAndPBPanel UpdateJoinAndPBPanel;
	UPROPERTY()						bool bUseDeploymentModeOnNextShowPanel;									//var bool bUseDeploymentModeOnNextShowPanel;
	UPROPERTY()						bool bShowOnlyExploreTheArmyServers;									//var bool bShowOnlyExploreTheArmyServers;
	UPROPERTY()						int32 ShowCount;														//var int32 ShowCount;
	UPROPERTY()						FString sDeploymentModeMap;												//var FString sDeploymentModeMap;
	UPROPERTY()						FString PanelCaptionBase;												//var localized FString PanelCaptionBase;
	UPROPERTY(EditAnywhere)			UGUILabel* ServerCount;													//var() automated XInterface.GUILabel ServerCount;

	void ShowPanel(bool bShow);
	void SetExploreTheArmyMode(bool bExploreTheArmy);
	void SetDeploymentModeOnNextShowPanel(FString MapToFilter);
	void RefreshServerList();
	void InternalOnFilterSetChanged(int32 NewIndex);
	void InternalOnClearFilters();
	void InternalOnShowFilters();
	void InternalOnFiltersChanged();
	void InternalOnSearch(FFilterItem filter);
	void InternalOnPunkBusterChanged(bool PunkBusterEnabled);
	void InternalOnUpdateServerList();
	void InternalOnJoinServer();
	void CloseEnumerationDialog();
	void InternalOnUpdateServerListFailed(FString Reason);
	void InternalOnReceivedServer(int32 Index);
	void UpdateServerList(FString GameSpyFilterString, TArray<FFilterItem> FilterList);

};
