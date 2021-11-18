// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_UAVNavigationMap.generated.h"

class UGUIImage;
class UGUIImageButton;
class UGUILabel;
class UUmoEditBox;
class UGUIButton;
//class UUAVFlightPlannerWaypoint;
class UmoEditBox;

UCLASS()
class AA29_API UAAGameMenu_UAVNavigationMap : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_UAVNavigationMap();

	UPROPERTY(EditAnywhere)			UMaterialInstance*					texWaypointMarker;			//var Texture texWaypointMarker;
	UPROPERTY(EditAnywhere)			UGUIImage*							i_Background;				//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImageButton*					i_Map;						//var() automated GUIImageButton i_Map;
	UPROPERTY(EditAnywhere)			UGUILabel*							guilTitle;					//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)			UGUILabel*							guilDebug;					//var() automated XInterface.GUILabel guilDebug;
	UPROPERTY(EditAnywhere)			UmoEditBox*							mebWaypointAltitude;		//var() automated XInterface.moEditBox mebWaypointAltitude;
	UPROPERTY(EditAnywhere)			UmoEditBox*							mebWaypointSpeed;			//var() automated XInterface.moEditBox mebWaypointSpeed;
	UPROPERTY(EditAnywhere)			UGUIButton*							guibSaveFlightPlan;			//var() automated XInterface.GUIButton guibSaveFlightPlan;
	UPROPERTY(EditAnywhere)			UGUIButton*							guibDeleteWaypoint;			//var() automated XInterface.GUIButton guibDeleteWaypoint;
	UPROPERTY(EditAnywhere)			UGUIButton*							guibClearAllWaypoints;		//var() automated XInterface.GUIButton guibClearAllWaypoints;
	UPROPERTY(EditAnywhere)			UGUIButton*							guibDiscardChanges;			//var() automated XInterface.GUIButton guibDiscardChanges;
	UPROPERTY()						UMaterialInstance*					ScalingMapImage;			//var TexScaler ScalingMapImage;
	UPROPERTY()						UMaterialInstance*					RotatingMapImage;			//var TexRotator RotatingMapImage;
	UPROPERTY()						float								fpMapScaleX;				//var float fpMapScaleX;
	UPROPERTY()						float								fpMapScaleY;				//var float fpMapScaleY;
	UPROPERTY()						float								fpMapStartX;				//var float fpMapStartX;
	UPROPERTY()						float								fpMapStartY;				//var float fpMapStartY;
	UPROPERTY()						float								fpMapHeight;				//var float fpMapHeight;
	UPROPERTY()						float								fpMapWidth;					//var float fpMapWidth;
	UPROPERTY()						float								fpWidthHeightRatio;			//var float fpWidthHeightRatio;
	//UPROPERTY()						TArray<UUAVFlightPlannerWaypoint*>	awpWaypoints;				//var TArray<UAVFlightPlannerWaypoint> awpWaypoints;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool NotifyLevelChange();
	void InitializeMap();
	FVector ConvertWorldToRotatedMapCoordinates(FVector vWorld);
	void OnDrawMapGrid(UCanvas* Canvas);
	FVector WorldToMap(FVector vWorldLoc);
	float MapToWorldLocX(float fpX);
	float MapToWorldLocY(float fpY);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool OnMapClick(UGUIComponent* Sender);

};
