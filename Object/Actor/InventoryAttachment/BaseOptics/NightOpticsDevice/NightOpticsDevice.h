// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "NightOpticsDevice.generated.h"

UCLASS()
class ANightOpticsDevice : public ABaseOptics
{
	GENERATED_BODY()

public:
	ANightOpticsDevice();
	
	UPROPERTY()		UStaticMesh*		NVG_Down;				//var StaticMesh NVG_Down;
	UPROPERTY()		UStaticMesh*		NVG_Up;					//var StaticMesh NVG_Up;
	UPROPERTY()		bool				bDisableNightVision;	//var bool bDisableNightVision;
	UPROPERTY()		int32				RandInd;				//var int RandInd;
	UPROPERTY()		TArray<float>		RandArray;				//var float RandArray;
	UPROPERTY()		UMaterialInstance*	NightVisionOverlay;		//var Texture NightVisionOverlay;
	UPROPERTY()		UMaterialInstance*	NightVisionTexture;		//var Texture NightVisionTexture;
	UPROPERTY()		USoundBase*			SwitchOffSound;			//var Sound SwitchOffSound;
	UPROPERTY()		USoundBase*			SwitchOnSound;			//var Sound SwitchOnSound;

	void BeginPlay();
	void StatusChanged();
	void CleanUp();
	void ServerSetAnimation(uint8 NewState);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	void DoAttachStuffWhichShouldBeDoneInInventory();
	void AttachmentAnimation();
	void NotifyBRoll(bool bRoll);
};
