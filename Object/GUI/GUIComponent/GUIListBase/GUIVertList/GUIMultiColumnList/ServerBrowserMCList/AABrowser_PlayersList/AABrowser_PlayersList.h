// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/ServerBrowserMCList.h"
#include "AABrowser_PlayersList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_PlayersList : public UServerBrowserMCList
{
	GENERATED_BODY()
public:
	UAABrowser_PlayersList();

	UPROPERTY()			bool bIsExploreTheArmyList;									//var bool bIsExploreTheArmyList;

	void OnGetPlayer(FGameSpyPlayerInfo& PlayerInfo, int32 Index);
	FString GetSortString(int32 Index);
	void SetPlayerCount(int32 Count);
	void InternalOnReceivedPlayerList(int32 ListLength);
	bool IsOnBattleBuddyList(FString PlayerName);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
};
