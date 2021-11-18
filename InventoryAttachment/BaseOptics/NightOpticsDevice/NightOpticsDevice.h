// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "NightOpticsDevice.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANightOpticsDevice : public ABaseOptics
{
	GENERATED_BODY()

public:
	ANightOpticsDevice();

	
	UPROPERTY()		UStaticMesh* NVG_Down;				//var StaticMesh NVG_Down;
	UPROPERTY()		UStaticMesh* NVG_Up;				//var StaticMesh NVG_Up;
	UPROPERTY()		bool bDisableNightVision;			//var bool bDisableNightVision;
	UPROPERTY()		int32 RandInd;						//var int RandInd;
	UPROPERTY()		float RandArray;					//var float RandArray;
	UPROPERTY()		UTexture2D* NightVisionOverlay;		//var Texture NightVisionOverlay;
	UPROPERTY()		UTexture2D* NightVisionTexture;		//var Texture NightVisionTexture;
	UPROPERTY()		USoundBase* SwitchOffSound;			//var Sound SwitchOffSound;
	UPROPERTY()		USoundBase* SwitchOnSound;			//var Sound SwitchOnSound;

};
