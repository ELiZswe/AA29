// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_MapSelection.generated.h"

class UAAGameMenu_CommandPost;
class UGUIImage;
class UmoComboBox;
class UGUIButton;
class UGUILabel;
class UGUIScrollTextBox;

UCLASS()
class AA29_API UAAGameMenu_CP_MapSelection : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_MapSelection();

	UPROPERTY()								int32						iTimeLeftBeforeSwitch;			//var int iTimeLeftBeforeSwitch;
	UPROPERTY()								UAAGameMenu_CommandPost*	aagpCommandPost;				//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY()								FString						sInstructions;					//var localized string sInstructions;
	UPROPERTY()								bool						bAreMissionsAlphabetized;		//var bool bAreMissionsAlphabetized;
	UPROPERTY()								FString						sBriefingDir;					//var string sBriefingDir;
	UPROPERTY()								int32						iMissionID;						//var int iMissionID;
	UPROPERTY()								int32						iTourID;						//var int iTourID;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulInstructions;				//var() XInterface.GUILabel gulInstructions;
	UPROPERTY(EditAnywhere)					UGUIScrollTextBox*			glblDescription;				//var() XInterface.GUIScrollTextBox glblDescription;
	UPROPERTY(EditAnywhere)					UGUILabel*					glblTour;						//var() XInterface.GUILabel glblTour;
	UPROPERTY(EditAnywhere)					UGUIButton*					gbtnSwitchMaps;					//var() XInterface.GUIButton gbtnSwitchMaps;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbMission;						//var() XInterface.moComboBox mcbMission;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTour;						//var() XInterface.moComboBox mcbTour;
	UPROPERTY(EditAnywhere)					UGUIImage*					gimgTour;						//var() XInterface.GUIImage gimgTour;
	UPROPERTY(EditAnywhere)					UGUIImage*					gimgMap;						//var() XInterface.GUIImage gimgMap;
	UPROPERTY(EditAnywhere)					UGUIImage*					gimgDescriptionPanel;			//var() XInterface.GUIImage gimgDescriptionPanel;
	UPROPERTY(EditAnywhere)					UGUIImage*					gimgTourPanel;					//var() XInterface.GUIImage gimgTourPanel;
	UPROPERTY(EditAnywhere)					UGUIImage*					gimgMapPanel;					//var() XInterface.GUIImage gimgMapPanel;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool IsAdmin();
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadToursAndMissions();
	void ReloadMissions();
	void InternalOnChange(UGUIComponent* Sender);
	void UpdateTourInfo();
	void Timer();
	bool ButtonClick(UGUIComponent* Sender);
	void OnSwitchMaps();
};
