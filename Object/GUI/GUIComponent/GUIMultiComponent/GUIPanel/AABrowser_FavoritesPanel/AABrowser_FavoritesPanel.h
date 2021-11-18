// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AABrowser_FavoritesPanel.generated.h"

class UFavorites;
class UGUIContextMenu;
class UGUIMultiColumnList;
class UServerBrowserMCListBox;
class UGUIButton;

UCLASS()
class AA29_API UAABrowser_FavoritesPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAABrowser_FavoritesPanel();

	UPROPERTY()											UFavorites* Favorites;								//var DBAuth.Favorites Favorites;
	UPROPERTY()											UGUIContextMenu* FavoritesContextMenu;				//var XInterface.GUIContextMenu FavoritesContextMenu;
	UPROPERTY()											EFavoritesDisplayMode DisplayMode;					//var EFavoritesDisplayMode DisplayMode;
	UPROPERTY()											TArray<FString> ListHeadings;						//var localized string ListHeadings;
	UPROPERTY()											UGUIMultiColumnList* FavoritesList;					//var XInterface.GUIMultiColumnList FavoritesList;
	UPROPERTY(EditAnywhere)								UServerBrowserMCListBox* FavoritesListBox;			//var() ServerBrowserMCListBox FavoritesListBox;
	UPROPERTY(EditAnywhere)								UGUIButton* BuddiesButton;							//var() XInterface.GUIButton BuddiesButton;
	UPROPERTY(EditAnywhere)								UGUIButton* ServersButton;							//var() XInterface.GUIButton ServersButton;

	void OnUpdateServerList();
	void OnFavoriteServerSelectionChanged(FFavoriteServer Server);
	void OnBuddySelectionChanged(FString Buddy);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetVisibility(bool bIsVisible);
	void InternalFavoritesListSelectionChanged(UGUIComponent* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void AddFavoriteServer(FString IPAddress);
	void AddBattleBuddy(FString Buddy);
	void RemoveSelected();
	void RemoveFavorite(EFavoritesDisplayMode FavoritesType, int32 Choice);
	bool IsValidDBMBSFilterList();
	void GetDBMBSFilterList();
	void OpenDialog(FString Action, FString Message);
	void InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message);
	void InternalOnOpenContextMenu(UGUIContextMenu* Sender);
	void InternalOnClickContextMenu(UGUIContextMenu* Sender, int32 Index);
	void AddFavoriteServerClosed(bool bCancelled);
	void AddBuddyClosed(bool bCancelled);
	void UpdateList();
	bool InternalOnClick(UGUIComponent* Sender);
	FString GetItemToDraw(int32 Index);
	void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	
};
