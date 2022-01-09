// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDTaskDisplay.generated.h"

class AInventory;
class ACallForSupport;
class UFont;

UCLASS()
class UHUDTaskDisplay : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDTaskDisplay();

	UPROPERTY()										int32 iLaserRange;							//var int iLaserRange;
	UPROPERTY()										float fpTimeLastLaserUse;					//var float fpTimeLastLaserUse;
	UPROPERTY()										FString sAdjustFireDirection;				//var string sAdjustFireDirection;
	UPROPERTY()										int32 iAdjustFireAdjustment;				//var int iAdjustFireAdjustment;
	UPROPERTY()										float fpTimeSinceLastMenuIconClicked;		//var float fpTimeSinceLastMenuIconClicked;
	UPROPERTY()										bool bRadarIsVisibleLastFrame;				//var bool bRadarIsVisibleLastFrame;
	UPROPERTY()										UMaterialInstance* tInvObjective;			//var Texture tInvObjective;
	UPROPERTY()										UMaterialInstance* tBreacher;				//var Texture tBreacher;
	UPROPERTY()										UMaterialInstance* tFirstAidKit;			//var Texture tFirstAidKit;
	UPROPERTY()										UMaterialInstance* tMedPack;				//var Texture tMedPack;
	UPROPERTY()										UMaterialInstance* tCLU;					//var Texture tCLU;
	UPROPERTY()										TArray<UMaterialInstance*> tSupport;		//var Texture tSupport;
	UPROPERTY()										TArray<UMaterialInstance*> tBinoc;			//var Texture tBinoc;
	UPROPERTY()										TArray<UMaterialInstance*> tFT;				//var Texture tFT;
	UPROPERTY()										UMaterialInstance* tSFTeamLeader;			//var Texture tSFTeamLeader;
	UPROPERTY()										UMaterialInstance* tVIP;					//var Texture tVIP;
	UPROPERTY()										UMaterialInstance* tSFCaptain;				//var Texture tSFCaptain;
	UPROPERTY()										UMaterialInstance* tIndigenous;				//var Texture tIndigenous;
	UPROPERTY()										UMaterialInstance* tTeamMember;				//var Texture tTeamMember;
	UPROPERTY()										UMaterialInstance* tTeamLeader;				//var Texture tTeamLeader;
	UPROPERTY()										UMaterialInstance* tSquadLeader;			//var Texture tSquadLeader;
	UPROPERTY()										UMaterialInstance* tJav_Tube;				//var Texture tJav_Tube;
	UPROPERTY()										UMaterialInstance* tJav_TooClose;			//var Texture tJav_TooClose;
	UPROPERTY()										UMaterialInstance* tJav_LockedOn;			//var Texture tJav_LockedOn;
	UPROPERTY()										UMaterialInstance* tJav_Targeting;			//var Texture tJav_Targeting;
	UPROPERTY()										UMaterialInstance* tROF_Grenade;			//var Texture tROF_Grenade;
	UPROPERTY()										UMaterialInstance* tROF_Auto;				//var Texture tROF_Auto;
	UPROPERTY()										UMaterialInstance* tROF_Burst;				//var Texture tROF_Burst;
	UPROPERTY()										UMaterialInstance* tROF_Single;				//var Texture tROF_Single;
	UPROPERTY()										UMaterialInstance* tSupported;				//var Texture tSupported;
	UPROPERTY()										UMaterialInstance* tLiveGrenade;			//var Texture tLiveGrenade;
	UPROPERTY()										UMaterialInstance* tJammed;					//var Texture tJammed;
	UPROPERTY()										UMaterialInstance* tRoll;					//var Texture tRoll;
	UPROPERTY()										UMaterialInstance* tRecharge;				//var Texture tRecharge;
	UPROPERTY()										UMaterialInstance* tReload;					//var Texture tReload;
	UPROPERTY()										UMaterialInstance* tDiscard;				//var Texture tDiscard;
	UPROPERTY()										UMaterialInstance* textSpotterOverlayMenu;	//var Texture textSpotterOverlayMenu;
	UPROPERTY()										TArray<FString> GrenadeClassName;					//var string GrenadeClassName;
	UPROPERTY()										AInventory* GrenadeClassGreenSmoke;			//var class<Inventory> GrenadeClassGreenSmoke;
	UPROPERTY()										AInventory* GrenadeClass;					//var class<Inventory> GrenadeClass;
	UPROPERTY()										FString Breachername;						//var string Breachername;
	UPROPERTY()										AInventory* DoorBreacher;					//var class<Inventory> DoorBreacher;
	UPROPERTY()										bool bInitializedSupport;					//var bool bInitializedSupport;
	UPROPERTY()										ACallForSupport* Support;					//var CallForSupport Support;
	UPROPERTY()										bool bWeaponMsgFlashing;					//var bool bWeaponMsgFlashing;
	UPROPERTY()										float fLastFlashTime;						//var float fLastFlashTime;
	UPROPERTY()										bool _bAlpha;								//var bool _bAlpha;
	UPROPERTY()										int32 _iCurrentTask;						//var int _iCurrentTask;
	UPROPERTY()										int32 Grenades_yposn;						//var int Grenades_yposn;
	UPROPERTY()										int32 Grenades_xposn;						//var int Grenades_xposn;
	UPROPERTY()										int32 Grenades_xspace;						//var int Grenades_xspace;
	UPROPERTY()										int32 Grenades_ysize;						//var int Grenades_ysize;
	UPROPERTY()										int32 Grenades_xsize;						//var int Grenades_xsize;

	void Destroyed();
	void ProcessParams();
	void ScaleControl(UCanvas* Canvas);
	void Draw(UCanvas* Canvas);
	void DrawInventoryObjectives(UCanvas* Canvas);
	void DrawOptics(UCanvas* Canvas);
	void DrawHolster(UCanvas* Canvas);
	void DrawTime(UCanvas* Canvas);
	FString TwoDigitString(int32 Num);
	void DrawRank(UCanvas* Canvas);
	void DrawMedical(UCanvas* Canvas);
	void DrawBreacher(UCanvas* Canvas);
	void DrawGrenades(UCanvas* Canvas);
	UFont* GetStatusFont(UCanvas* Canvas);
	void DrawAmmo(UCanvas* Canvas);
	void DrawObjectives(UCanvas* Canvas);
	void DrawCompass(UCanvas* Canvas);
	void DrawRadar(UCanvas* Canvas);
	void InitializeSupport();
	void DrawSupport(UCanvas* Canvas);
	bool CheckFlashTime();
	void SetCurrentTask(int32 task);
	int32 GetCurrentTask();
	bool ProcessSpotterMenu(APlayerController* PC, int32 iMenuX, int32 iMenuY);
	void LaserSpotterRange(APlayerController* PC);
	bool ProcessSpotterMenuNumpad(APlayerController* PC, int32 iMenuX, int32 iMenuY);


};
