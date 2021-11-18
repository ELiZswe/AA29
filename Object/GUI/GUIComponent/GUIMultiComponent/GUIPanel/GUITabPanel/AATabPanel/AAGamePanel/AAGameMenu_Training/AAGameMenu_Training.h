// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_Training.generated.h"

class UGUIScrollTextBox;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_Training : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_Training();



	UPROPERTY(EditAnywhere)			UGUIImage* i_Background;				//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImage* l_Tour;						//var() automated XInterface.GUILabel l_Tour;
	UPROPERTY(EditAnywhere)			UGUIImage* l_Mission;					//var() automated XInterface.GUILabel l_Mission;
	UPROPERTY(EditAnywhere)			UGUIImage* i_MapBG;						//var() automated XInterface.GUIImage i_MapBG;
	UPROPERTY(EditAnywhere)			UGUIImage* i_TourBG;					//var() automated XInterface.GUIImage i_TourBG;
	UPROPERTY(EditAnywhere)			UGUIImage* i_DescriptionBG;				//var() automated XInterface.GUIImage i_DescriptionBG;
	UPROPERTY(EditAnywhere)			UGUIImage* i_Map;						//var() automated XInterface.GUIImage i_Map;
	UPROPERTY(EditAnywhere)			UGUIImage* i_Tour;						//var() automated XInterface.GUIImage i_Tour;
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox* lb_Description;		//var() automated XInterface.GUIScrollTextBox lb_Description;
	UPROPERTY()						int32 TourID;							//var int32 TourID;
	UPROPERTY()						int32 MissionID;						//var int32 MissionID;
	UPROPERTY()						FString BriefingDir;					//var FString BriefingDir;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void UpdateMissionStatus();
	void UpdateTourInfo();
	FString BuildMissionBriefing();
};
