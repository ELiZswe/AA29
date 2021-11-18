// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_SpotterMap.generated.h"

class UGUIImage;
class UGUIImageButton;
class UmoNumericEdit;
class UGUIButton;
class UmoComboBox;
class UGUIButton;
/**
 * 
 */
UCLASS()
class AA29_API UAAGameMenu_SpotterMap : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_SpotterMap();

	UPROPERTY(EditAnywhere)			UGUIImage* i_Background;						//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImageButton* i_Map;							//var() automated GUIImageButton i_Map;
	UPROPERTY(EditAnywhere)			UGUILabel* guilTitle;							//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)			UGUILabel* guilDebug;							//var() automated XInterface.GUILabel guilDebug;
	UPROPERTY(EditAnywhere)			UmoNumericEdit* mneGridX;						//var() automated XInterface.moNumericEdit mneGridX;
	UPROPERTY(EditAnywhere)			UmoNumericEdit* mneGridY;						//var() automated XInterface.moNumericEdit mneGridY;
	UPROPERTY(EditAnywhere)			UGUIButton* guibGridFireMission;				//var() automated XInterface.GUIButton guibGridFireMission;
	UPROPERTY(EditAnywhere)			UmoComboBox* mcbMissionType;					//var() automated XInterface.moComboBox mcbMissionType;
	UPROPERTY(EditAnywhere)			UmoComboBox* mcbTargetType;						//var() automated XInterface.moComboBox mcbTargetType;
	UPROPERTY()						UMaterialInstance* ScalingMapImage;				//var TexScaler ScalingMapImage;
	UPROPERTY()						UGUIButton* RotatingMapImage;					//var TexRotator RotatingMapImage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool NotifyLevelChange();
	void InitializeMap();
	FVector ConvertWorldToRotatedMapCoordinates(FVector vWorld);
	void OnDrawMapGrid(UCanvas* Canvas);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
};
