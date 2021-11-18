// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_AdminPlayerList.generated.h"

class UAdminPlayerList;
class UGUIMultiColumnListBox;

UCLASS()
class AA29_API UTab_AdminPlayerList : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_AdminPlayerList();

	UPROPERTY()			UAdminPlayerList*			MyPlayerList;				//var AdminPlayerList MyPlayerList;
	UPROPERTY()			UGUIMultiColumnListBox*		MyListBox;					//var GUIMultiColumnListBox MyListBox;
	UPROPERTY()			bool						bAdvancedAdmin;				//var bool bAdvancedAdmin;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ProcessRule(FString NewRule);
	void ReloadList();
	bool KickClicked(UGUIComponent* Sender);
	bool BanClicked(UGUIComponent* Sender);
};
