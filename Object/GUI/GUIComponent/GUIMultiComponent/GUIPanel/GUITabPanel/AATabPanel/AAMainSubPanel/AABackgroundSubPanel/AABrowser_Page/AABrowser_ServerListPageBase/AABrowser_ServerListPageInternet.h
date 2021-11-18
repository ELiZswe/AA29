// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageMS.h"
#include "AABrowser_ServerListPageInternet.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_ServerListPageInternet : public UAABrowser_ServerListPageMS
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListPageInternet();

	UPROPERTY()								FString						FilterString;			//var FString FilterString;
	UPROPERTY()								TArray<FFilterItem>			FilterList;				//var TArray<ServerBrowserBase.FilterItem> FilterList;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void ClearAllLists();
	void GameTypeChanged(UAABrowser_ServersList* NewList);
	void FilterClicked();
	void FiltersClosed(bool bCancelled);
	void Refresh();
	void RefreshList();
	void MyOnGameSpyStatusDone();
	void RefreshSBList();
	void SetSBFilter(FString S);
	void SetServerBrowserFilterList(TArray<FFilterItem> List);
	FString BuildInitialFilter();
	int32 GetTourIndexByName(FString TourName);
	void BuildInitialFilterList();
	FString NeedAnd(FString sFilter);

};
