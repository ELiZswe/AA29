// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDCrosshair.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDCrosshair : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDCrosshair();


	UPROPERTY()										UMaterialInstance* ActionIcon;				//var Texture ActionIcon;
	UPROPERTY()										FString ActionText;							//var string ActionText;
	UPROPERTY()										int32 ColorId;								//var int ColorId;
	UPROPERTY()										TArray<UMaterialInstance*> _tCrosshair;		//var Texture _tCrosshair;
	UPROPERTY()										int32 iCrosshairIndex;						//var int iCrosshairIndex;


	void SetCrossHairColor(int32 NewColorID);
	void Destroyed();
	void Draw(UCanvas* Canvas);
	void SetColorID(int32 i);
	void SetCrosshair(int32 C);
	void NextCrosshair();



};
