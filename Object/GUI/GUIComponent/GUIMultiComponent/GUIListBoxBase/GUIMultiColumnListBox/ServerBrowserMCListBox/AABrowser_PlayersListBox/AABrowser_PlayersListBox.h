// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AABrowser_PlayersListBox.generated.h"

class UAABrowser_ServerListPageBuddy;
class UGUIContextMenu;

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_PlayersListBox : public UServerBrowserMCListBox
{
	GENERATED_BODY()
public:
	UAABrowser_PlayersListBox();


	UPROPERTY()								TArray<FString>						ContextMenuText;		//var localized string ContextMenuText;
	UPROPERTY()								UAABrowser_ServerListPageBuddy*		tp_Buddy;				//var AABrowser_ServerListPageBuddy tp_Buddy;

	void Opened(UGUIComponent* Sender);
	void InternalOnClick(UGUIContextMenu* Sender, int32 ContextIndex);
	bool IsOnBattleBuddyList(FString PlayerName);
	void OpenFavoritesOperationDialog(FString Action, FString Message);
	void InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message);
	bool InternalOnOpen(UGUIContextMenu* Menu);
	void InternalOnClose(UGUIContextMenu* Sender);

};
