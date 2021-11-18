// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AATraining_Details.generated.h"

class UGUIContentBox;
class UNMLContent;
class UmoComboBox;
class UGUIButton;

UCLASS()
class AA29_API UAATraining_Details : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAATraining_Details();

	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;					//var() automated GUIContentBox guicbPanel;
	UPROPERTY(EditAnywhere)			UNMLContent*		MyNML;						//var NMLContent MyNML;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Tour;					//var() automated XInterface.moComboBox co_Tour;
	UPROPERTY(EditAnywhere)			UGUIButton*			bDeploy;					//var() automated XInterface.GUIButton bDeploy;
	UPROPERTY(EditAnywhere)			UGUIButton*			bBack;						//var() automated XInterface.GUIButton bBack;
	UPROPERTY()						FString				ToursFile;					//var FString ToursFile;
	UPROPERTY()						FString				DefaultPage;				//var FString DefaultPage;
	UPROPERTY()						bool				bIsFirstLoad;				//var bool bIsFirstLoad;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void PopulateComboBox();
	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
};
