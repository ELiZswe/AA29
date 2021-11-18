// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "Browser_BuddyList.generated.h"

class UBrowser_ServerListPageBuddy;
class UGUIStyles;


UCLASS()
class AA29_API UBrowser_BuddyList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UBrowser_BuddyList();

	UPROPERTY()						UGUIStyles* SelStyle;										//var GUIStyles SelStyle;
	UPROPERTY()						UBrowser_ServerListPageBuddy* MyBuddyPage;					//var Browser_ServerListPageBuddy MyBuddyPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void MyOnDrawItem(UCanvas* Canvas, int i32, float X, float Y, float W, float H, bool bSelected, bool bPending);

};
