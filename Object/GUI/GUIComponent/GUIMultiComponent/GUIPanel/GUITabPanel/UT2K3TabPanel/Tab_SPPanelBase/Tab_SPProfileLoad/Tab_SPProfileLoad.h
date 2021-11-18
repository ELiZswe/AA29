// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "Tab_SPProfileLoad.generated.h"

class UGUIButton;
class UGUIImage;
class UmoEditBox;
class UGUIListBox;

UCLASS()
class AA29_API UTab_SPProfileLoad : public UTab_SPPanelBase
{
	GENERATED_BODY()
public:
	UTab_SPProfileLoad();

	UPROPERTY()			UGUIListBox*	lbProfiles;				//var GUIListBox lbProfiles;
	UPROPERTY()			UmoEditBox*		ebPlayerName;			//var moEditBox ebPlayerName;
	UPROPERTY()			UmoEditBox*		ebTeamName;				//var moEditBox ebTeamName;
	UPROPERTY()			UmoEditBox*		ebDifficulty;			//var moEditBox ebDifficulty;
	UPROPERTY()			UmoEditBox*		ebKills;				//var moEditBox ebKills;
	UPROPERTY()			UmoEditBox*		ebDeaths;				//var moEditBox ebDeaths;
	UPROPERTY()			UmoEditBox*		ebGoals;				//var moEditBox ebGoals;
	UPROPERTY()			UmoEditBox*		ebWins;					//var moEditBox ebWins;
	UPROPERTY()			UmoEditBox*		ebMatches;				//var moEditBox ebMatches;
	UPROPERTY()			UGUIImage*		imgPlayerSkin;			//var GUIImage imgPlayerSkin;
	UPROPERTY()			UGUIImage*		imgTeamSymbol;			//var GUIImage imgTeamSymbol;
	UPROPERTY()			UGUIButton*		butNew;					//var GUIButton butNew;
	UPROPERTY()			TArray<FString>	Difficulties;			//var localized FString Difficulties[8];
	UPROPERTY()			int32			NumDifficulties;		//var int32 NumDifficulties;
	UPROPERTY()			FString			DeleteMessage;			//var localized FString DeleteMessage;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	void InitPanel();
	void OnProfileUpdated();
	void UpdateList();
	void UpdateStats();
	bool LoadClick(UGUIComponent* Sender);
	void DeleteConfirm(uint8 bButton);
	bool DeleteClick(UGUIComponent* Sender);
	bool NewProfileClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool DoubleClickList(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
};
