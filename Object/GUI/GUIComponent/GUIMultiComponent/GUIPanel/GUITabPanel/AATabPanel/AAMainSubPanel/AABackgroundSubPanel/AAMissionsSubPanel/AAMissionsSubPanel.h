// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAMissionsSubPanel.generated.h"

class UmoComboBox;
class UGUIImage;
class UGUILabel;
class UGUIScrollTextBox;
class UGUIButton;

UCLASS()
class AA29_API UAAMissionsSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAMissionsSubPanel();

	UPROPERTY(EditAnywhere)			UmoComboBox* co_Filter;				//var() automated XInterface.moComboBox co_Filter;
	UPROPERTY(EditAnywhere)			UmoComboBox* co_Tour;				//var() automated XInterface.moComboBox co_Tour;
	UPROPERTY(EditAnywhere)			UmoComboBox* co_Mission;			//var() automated XInterface.moComboBox co_Mission;
	UPROPERTY(EditAnywhere)			UGUIImage* p_Map;					//var() automated XInterface.GUIImage p_Map;
	UPROPERTY(EditAnywhere)			UGUIImage* p_Tour;					//var() automated XInterface.GUIImage p_Tour;
	UPROPERTY(EditAnywhere)			UGUIImage* p_Description;			//var() automated XInterface.GUIImage p_Description;
	UPROPERTY(EditAnywhere)			UGUIImage* i_Map;					//var() automated XInterface.GUIImage i_Map;
	UPROPERTY(EditAnywhere)			UGUIImage* i_Tour;					//var() automated XInterface.GUIImage i_Tour;
	UPROPERTY(EditAnywhere)			UGUILabel* l_Tour;					//var() automated XInterface.GUILabel l_Tour;
	UPROPERTY(EditAnywhere)			UGUILabel* l_Requirements;			//var() automated XInterface.GUILabel l_Requirements;
	UPROPERTY(EditAnywhere)			UGUILabel* l_Status;				//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox* lb_Description;	//var() automated XInterface.GUIScrollTextBox lb_Description;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Deploy;				//var() automated XInterface.GUIButton b_Deploy;
	UPROPERTY()						FString NotAvailableText;			//var localized FString NotAvailableText;
	UPROPERTY()						FString AvailableText;				//var localized FString AvailableText;
	UPROPERTY()						FString CompletedText;				//var localized FString CompletedText;
	UPROPERTY()						FString TourComboCaption;			//var localized FString TourComboCaption;
	UPROPERTY()						FString MissionComboCaption;		//var localized FString MissionComboCaption;
	UPROPERTY()						TArray<FString> MissionFilters;		//var localized FString MissionFilters[3];
	UPROPERTY()						FColor NotAvailableColor;			//var Color NotAvailableColor;
	UPROPERTY()						FColor AvailableColor;				//var Color AvailableColor;
	UPROPERTY()						FColor CompletedColor;				//var Color CompletedColor;
	UPROPERTY()						FString BriefingDir;				//var FString BriefingDir;
	UPROPERTY()						FString ToursFile;					//var FString ToursFile;
	UPROPERTY()						int32 TourID;						//var int32 TourID;
	UPROPERTY()						int32 MissionID;					//var int32 MissionID;
	UPROPERTY()						bool bAreMissionsAlphabetized;		//var bool bAreMissionsAlphabetized;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeCombos();
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadToursAndMissions();
	void ReloadMissions();
	void InternalOnChange(UGUIComponent* Sender);
	bool UseTraining(int32 Tour);
	bool ShouldDisableSniper();
	bool ShouldDisableLifeFire();
	void SetStatusCaption(int32 Status);
	void Timer();
	void UpdateMissionStatus();
	void CanDeploy();
	bool ButtonClick(UGUIComponent* Sender);
	void UpdateTourInfo();
};
