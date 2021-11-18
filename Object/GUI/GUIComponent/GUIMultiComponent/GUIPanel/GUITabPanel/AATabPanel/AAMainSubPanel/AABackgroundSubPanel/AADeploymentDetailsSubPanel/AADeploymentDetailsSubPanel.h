// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploymentDetailsSubPanel.generated.h"

class UGUIContentBox;
class UmoComboBox;
class UNMLContent;
class UGUIButton;

/**
 * 
 */
UCLASS()
class AA29_API UAADeploymentDetailsSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploymentDetailsSubPanel();



	UPROPERTY(EditAnywhere)			UGUIContentBox* guicbPanel;			//var() automated GUIContentBox guicbPanel;
	UPROPERTY()						UNMLContent* MyNML;					//var NMLContent MyNML;
	UPROPERTY()						FString MissionsFile;				//var FString MissionsFile;
	UPROPERTY()						FString MissionsSection;			//var FString MissionsSection;
	UPROPERTY()						FString ComboBoxDefaultText;		//var FString ComboBoxDefaultText;
	UPROPERTY()						FString DefaultPage;				//var FString DefaultPage;
	UPROPERTY()						FString CurrentPage;				//var FString CurrentPage;
	UPROPERTY()						bool bComboBoxInitialized;			//var bool bComboBoxInitialized;
	UPROPERTY(EditAnywhere)			UmoComboBox* co_Tour;				//var() automated XInterface.moComboBox co_Tour;
	UPROPERTY(EditAnywhere)			UGUIButton* bDeploy;				//var() automated XInterface.GUIButton bDeploy;
	UPROPERTY(EditAnywhere)			UGUIButton* bExploreMap;			//var() automated XInterface.GUIButton bExploreMap;
	UPROPERTY(EditAnywhere)			UGUIButton* bBack;					//var() automated XInterface.GUIButton bBack;
	UPROPERTY()						FString ToursFile;					//var FString ToursFile;
	UPROPERTY()						TArray<int32> ValidTours;			//var TArray<int32> ValidTours;
	UPROPERTY()						bool bUserHasThisMap;				//var bool bUserHasThisMap;

	void InternalOnShow();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool DoesUserHaveMap(FString MapFilename);
	void NMLPreParser(FString& TrainingNML);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void PopulateComboBox();
	bool UseTraining(int32 Tour);
	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);
	void SetDeployButtonToDCDS();
	void SetDeployButtonToDeploy();
};
