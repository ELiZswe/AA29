// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/ServerBrowserMCList.h"
#include "AABrowser_BuddyList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_BuddyList : public UServerBrowserMCList
{
	GENERATED_BODY()
public:
	UAABrowser_BuddyList();

	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	FString GetSortString(int32 i);

};
