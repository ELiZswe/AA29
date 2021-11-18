// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_Favorites.generated.h"

class UAABrowser_FavoritesAndServerList;
class UAABrowser_UpdateJoinAndPBPanel;
class UGUIImage;
class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAADeploy_Favorites : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Favorites();

	UPROPERTY(EditAnywhere)			UAABrowser_FavoritesAndServerList* FavoritesAndServerListPanel;			//var() automated AABrowser_FavoritesAndServerListPanel FavoritesAndServerListPanel;
	UPROPERTY(EditAnywhere)			UAABrowser_UpdateJoinAndPBPanel* UpdateJoinAndPBPanel;					//var() automated AABrowser_UpdateJoinAndPBPanel UpdateJoinAndPBPanel;
	UPROPERTY(EditAnywhere)			UGUIImage* LowerBackgroundBorder;										//var() automated XInterface.GUIImage LowerBackgroundBorder;
	UPROPERTY(EditAnywhere)			UGUIButton* AddFavoriteServer;											//var() automated XInterface.GUIButton AddFavoriteServer;
	UPROPERTY(EditAnywhere)			UGUIButton* AddBuddy;													//var() automated XInterface.GUIButton AddBuddy;
	UPROPERTY(EditAnywhere)			UGUIButton* RemoveSelected;												//var() automated XInterface.GUIButton RemoveSelected;
	UPROPERTY(EditAnywhere)			UGUILabel* ServerCount;													//var() automated XInterface.GUILabel ServerCount;

	void ShowPanel(bool bShow);
	void InternalOnPunkBusterChanged(bool PunkBusterEnabled);
	void InternalOnUpdateServerList();
	void InternalOnJoinServer();
	void CloseEnumerationDialog();
	void InternalOnUpdateServerListFailed(FString Reason);
	void InternalOnReceivedServer(int32 Index);
	void UpdateServerList(TArray<FFilterItem> FilterList);
	bool InternalOnClick(UGUIComponent* Sender);
	void AddFavoriteServerClosed(bool bCancelled);
	void AddBuddyClosed(bool bCancelled);

};
