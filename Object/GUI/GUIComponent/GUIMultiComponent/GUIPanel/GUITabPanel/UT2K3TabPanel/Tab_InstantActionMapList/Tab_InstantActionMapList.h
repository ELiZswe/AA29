// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_InstantActionMapList.generated.h"

class UGUIListBox;

UCLASS()
class AA29_API UTab_InstantActionMapList : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_InstantActionMapList();

	UPROPERTY()					UGUIListBox*	MyFullMapList;				//var GUIListBox MyFullMapList;
	UPROPERTY()					UGUIListBox*	MyCurMapList;				//var GUIListBox MyCurMapList;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();
	void ReadMapList(FString MapPrefix, FString MapListClass);
	bool MapAdd(UGUIComponent* Sender);
	bool MapRemove(UGUIComponent* Sender);
	bool MapAll(UGUIComponent* Sender);
	bool MapClear(UGUIComponent* Sender);
	bool MapUp(UGUIComponent* Sender);
	bool MapDown(UGUIComponent* Sender);


};
