// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AAGUIPanelHideable.h"
#include "AABrowser_FavoritesAndServerList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_FavoritesAndServerList : public UAAGUIPanelHideable
{
	GENERATED_BODY()
public:
	UAABrowser_FavoritesAndServerList();

	void OnUpdateServerList();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ClearLists();
	void AddBattleBuddy(FString Buddy);
	void AddFavoriteServer(FString Server);
	void RemoveSelected();
	void ReceivedServer(int32 Data);
	void IsValidDBMBSFilterList();
	void GetDBMBSFilterList();
	void JoinCurrentlySelectedServer();
	void InternalOnUpdateServerList();
	void InternalOnFavoriteServerSelectionChanged(FFavoriteServer Server);
	void InternalOnBuddySelectionChanged(FString Buddy);
};
