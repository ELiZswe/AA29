// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "HUDFrame.generated.h"

class UHUDTaskDisplay;
class AAA2_Playerstate;
class AAA2_HUD;
class UUIControl;

UCLASS()
class UHUDFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UHUDFrame();

	UPROPERTY()			APlayerController*		PlayerOwner;				//var PlayerController PlayerOwner;
	UPROPERTY()			bool					bFrameInitialized;			//var bool bFrameInitialized;
	UPROPERTY()			UMaterialInstance*		_compassBracketTexture;		//var Texture _compassBracketTexture;
	UPROPERTY()			UMaterialInstance*		_compassTexture;			//var Texture _compassTexture;
	UPROPERTY()			UHUDTaskDisplay*		_cHUDTaskDisplay;			//var HUDTaskDisplay _cHUDTaskDisplay;
	UPROPERTY()			bool					_bShowRackItems;			//var bool _bShowRackItems;
	UPROPERTY()			bool					_bContainersSet;			//var bool _bContainersSet;

	void Destroyed();
	void SetHUDActor();
	void FreeHUDActor();
	UUIControl* GetControl(int32 Id);
	void Draw(UCanvas* Canvas);
	void CreateHUDFrame(AAA2_HUD* pHUD, APlayerController* pcPlayerController);
	void SetTask(int32 task);
	void ShowRackItems(bool Status);
	void ClearRackItems();
};
