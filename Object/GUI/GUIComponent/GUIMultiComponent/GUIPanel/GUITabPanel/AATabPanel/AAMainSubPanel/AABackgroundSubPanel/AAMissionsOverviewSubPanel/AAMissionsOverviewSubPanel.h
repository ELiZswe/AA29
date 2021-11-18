// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAMissionsOverviewSubPanel.generated.h"

class UmoComboBox;
class UGUIImage;
class UGUILabel;
class UGUIButton;
/**
 * 
 */
UCLASS()
class AA29_API UAAMissionsOverviewSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAMissionsOverviewSubPanel();

	UPROPERTY(EditAnywhere)			UmoComboBox*	co_Tour;				//var() automated XInterface.moComboBox co_Tour;
	UPROPERTY(EditAnywhere)			UGUIImage*		i_Tour;					//var() automated XInterface.GUIImage i_Tour;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Tour;					//var() automated XInterface.GUILabel l_Tour;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Requirements;			//var() automated XInterface.GUILabel l_Requirements;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Status;				//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Details;				//var() automated XInterface.GUIButton b_Details;
	UPROPERTY()						FString			NotAvailableText;		//var localized FString NotAvailableText;
	UPROPERTY()						FString			AvailableText;			//var localized FString AvailableText;
	UPROPERTY()						FString			CompletedText;			//var localized FString CompletedText;
	UPROPERTY()						FString			TourComboCaption;		//var localized FString TourComboCaption;
	UPROPERTY()						FColor			NotAvailableColor;		//var Color NotAvailableColor;
	UPROPERTY()						FColor			AvailableColor;			//var Color AvailableColor;
	UPROPERTY()						FColor			CompletedColor;			//var Color CompletedColor;
	UPROPERTY()						FString			BriefingDir;			//var FString BriefingDir;
	UPROPERTY()						FString			ToursFile;						//var FString ToursFile;
	UPROPERTY()						int32			TourID;					//var int32 TourID;
	UPROPERTY()						FString			DetailsPanelName;		//var FString DetailsPanelName;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadToursAndMissions();
	void ReloadMissions();
	void InternalOnChange(UGUIComponent* Sender);
	bool UseTraining(int32 Tour);
	bool ShouldDisableSniper();
	bool ShouldDisableLifeFire();
	void SetStatusCaption(int32 Status);
	void UpdateTourStatus();
	bool ButtonClick(UGUIComponent* Sender);
	void UpdateTourInfo();
	
};
