// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "Browser_PlayersList.generated.h"

class UBrowser_ServersList;
class UBrowser_ServerListPageBase;

UCLASS()
class AA29_API UBrowser_PlayersList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UBrowser_PlayersList();

	UPROPERTY()						int32 listitem;											//var int listitem;
	UPROPERTY()						UBrowser_ServersList* MyServersList;					//var Browser_ServersList MyServersList;
	UPROPERTY()						UBrowser_ServerListPageBase* MyPage;					//var Browser_ServerListPageBase MyPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);

};
