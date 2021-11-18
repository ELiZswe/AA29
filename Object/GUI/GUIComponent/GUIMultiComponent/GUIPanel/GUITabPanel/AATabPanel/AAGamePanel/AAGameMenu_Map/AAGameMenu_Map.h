// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_Map.generated.h"

class UGUIScrollTextBox;
class UGUILabel;
class UGUIImageButton;
class UGUIImage;


UCLASS()
class AA29_API UAAGameMenu_Map : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_Map();

	UPROPERTY()								UMaterialInstance*		RotatingMapImage;			//var TexRotator RotatingMapImage;
	UPROPERTY()								UMaterialInstance*		ScalingMapImage;			//var TexScaler ScalingMapImage;
	UPROPERTY(EditAnywhere)					UGUIScrollTextBox*		sb_ObjectivesList;			//var() XInterface.GUIScrollTextBox sb_ObjectivesList;
	UPROPERTY(EditAnywhere)					UGUILabel*				l_AuthorName;				//var() XInterface.GUILabel l_AuthorName;
	UPROPERTY(EditAnywhere)					UGUILabel*				l_Objectives;				//var() XInterface.GUILabel l_Objectives;
	UPROPERTY(EditAnywhere)					UGUIImageButton*		i_Map;						//var() GUIImageButton i_Map;
	UPROPERTY(EditAnywhere)					UGUIImage*				i_Objectives;				//var() XInterface.GUIImage i_Objectives;
	UPROPERTY(EditAnywhere)					UGUIImage*				i_Background;				//var() XInterface.GUIImage i_Background;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool NotifyLevelChange();
	void InitializeMap();
	void InitializeObjectives();
	bool ObjectivesClick(UGUIComponent* Sender);
	void OnDrawMapGrid(UCanvas* Canvas);
};
