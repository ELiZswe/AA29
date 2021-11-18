// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDWeaponTarget.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDWeaponTarget : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDWeaponTarget();


	UPROPERTY()										EDisplayType DisplayType;							//var EDisplayType DisplayType;
	UPROPERTY()										float LostTargetTime;								//var float LostTargetTime;
	UPROPERTY()										bool bRecentTarget;									//var bool bRecentTarget;
	UPROPERTY()										FString CaptionText;								//var string CaptionText;
	UPROPERTY()										UMaterialInstance* IconImage;						//var Material IconImage;
	UPROPERTY()										UMaterialInstance* _tESSObjective;					//var Texture _tESSObjective;
	UPROPERTY()										UMaterialInstance* _tObjectiveTarget;				//var Texture _tObjectiveTarget;
	UPROPERTY()										UMaterialInstance* _tObjectiveInactiveTarget;		//var Texture _tObjectiveInactiveTarget;
	UPROPERTY()										UMaterialInstance* _tObjectiveActiveTarget;			//var Texture _tObjectiveActiveTarget;
	UPROPERTY()										UMaterialInstance* _tDemolitionTarget;				//var Texture _tDemolitionTarget;
	UPROPERTY()										UMaterialInstance* _tJavelinTarget;					//var Texture _tJavelinTarget;
	UPROPERTY()										UMaterialInstance* _tBreacherTarget;				//var Texture _tBreacherTarget;


	void Destroyed();
	void SetTarget();
	void NoTarget();
	void Draw(UCanvas* Canvas);
	void GetFadeValue();
	void DrawTargetIcons(UCanvas* Canvas);
};
