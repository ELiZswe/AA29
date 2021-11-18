// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "HUDFrame.generated.h"

class UHUDTaskDisplay;
class AAA2_Playerstate;

UCLASS()
class AA29_API UHUDFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UHUDFrame();

	/*
	const SID_HUD = 0;
	const HID_Rack0 = 0;
	const HID_Rack1 = 1;
	const HID_Rack2 = 2;
	const HID_Rack3 = 3;
	const HID_Border = 4;
	const HID_Compass = 5;
	const HID_Item0 = 6;
	const HID_Task = 7;
	const HID_BodyInfo = 8;
	const HID_SupportBox = 9;
	const HID_Crosshair = 10;
	const HID_AlphaBar = 11;
	const HID_ChatBox = 12;
	const HID_CommoInfo = 13;
	const HID_RoleInfo = 14;
	const HID_CombatEffect = 15;
	const HID_PlayerID = 16;
	const HID_WeaponTarget = 17;
	const HID_ObjectiveBar = 20;
	const HID_HealingBar = 21;
	const HID_TurretReloadBar = 22;
	const HID_ObjectiveGiveBar = 23;
	const HID_Radar = 24;
	const HID_Driver = 25;
	*/

	UPROPERTY()										AAA2_PlayerState* PlayerOwner;					//var PlayerController PlayerOwner;
	UPROPERTY()										bool bFrameInitialized;							//var bool bFrameInitialized;
	UPROPERTY()										UMaterialInstance* _compassBracketTexture;		//var Texture _compassBracketTexture;
	UPROPERTY()										UMaterialInstance* _compassTexture;				//var Texture _compassTexture;
	UPROPERTY()										UHUDTaskDisplay* _cHUDTaskDisplay;				//var HUDTaskDisplay _cHUDTaskDisplay;
	UPROPERTY()										bool _bShowRackItems;							//var bool _bShowRackItems;
	UPROPERTY()										bool _bContainersSet;							//var bool _bContainersSet;


	void Destroyed();
	void SetHUDActor();
	void FreeHUDActor();
	void GetControl(int32 Id);
	void Draw(UCanvas* Canvas);
	void CreateHUDFrame(AHUD* pHUD, AAA2_Playerstate* pcPlayerController);
	void SetTask(int32 task);
	void ShowRackItems(bool Status);
	void ClearRackItems();
	
};
