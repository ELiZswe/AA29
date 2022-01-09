// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "ScopeW_Javelin.generated.h"

class AHumanController;
class AWEAPON_Javelin;
class ABaseOptics;

UCLASS()
class AScopeW_Javelin : public ABaseScope
{
	GENERATED_BODY()
public:
	AScopeW_Javelin();
	
	UPROPERTY(EditAnywhere)		float ZoomStartTime;						//var float ZoomStartTime;
	UPROPERTY(EditAnywhere)		UMaterialInstance* VisualFadeOverlay;				//var Texture VisualFadeOverlay;
	UPROPERTY(EditAnywhere)		float VisualFadeInTime;						//var float VisualFadeInTime;
	UPROPERTY(EditAnywhere)		bool bUpdateTrackGateSize;					//var bool bUpdateTrackGateSize;
	UPROPERTY(EditAnywhere)		bool bUseOldTrackGate;						//var bool bUseOldTrackGate;
	UPROPERTY(EditAnywhere)		int32 DrawTrackGateY;						//var int DrawTrackGateY;
	UPROPERTY(EditAnywhere)		int32 DrawTrackGateX;						//var int DrawTrackGateX;
	UPROPERTY(EditAnywhere)		int32 TrackGateY;							//var int TrackGateY;
	UPROPERTY(EditAnywhere)		int32 TrackGateX;							//var int TrackGateX;
	UPROPERTY(EditAnywhere)		int32 TrackGateDownSize;					//var int TrackGateDownSize;
	UPROPERTY(EditAnywhere)		int32 TrackGateUpSize;						//var int TrackGateUpSize;
	UPROPERTY(EditAnywhere)		int32 TrackGateRightSize;					//var int TrackGateRightSize;
	UPROPERTY(EditAnywhere)		int32 TrackGateLeftSize;					//var int TrackGateLeftSize;
	UPROPERTY(EditAnywhere)		AHumanController* Jav_User;					//var AGP.HumanController Jav_User;
	UPROPERTY(EditAnywhere)		AWEAPON_Javelin* mygun;						//var WEAPON_Javelin mygun;
	UPROPERTY(EditAnywhere)		UMaterialInstance* TrackGate;						//var Texture TrackGate;
	UPROPERTY(EditAnywhere)		UMaterialInstance* CrossHair;						//var Texture CrossHair;
	UPROPERTY(EditAnywhere)		UMaterialInstance* Seek_Overlay;					//var Texture Seek_Overlay;
	UPROPERTY(EditAnywhere)		UMaterialInstance* NFOV_Overlay;					//var Texture NFOV_Overlay;
	UPROPERTY(EditAnywhere)		UMaterialInstance* WFOV_Overlay;					//var Texture WFOV_Overlay;
	UPROPERTY(EditAnywhere)		UMaterialInstance* MBitFailTex;					//var Texture MBitFailTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* TOPTex;							//var Texture TOPTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* DIRTex;							//var Texture DIRTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* SEEKTex;						//var Texture SEEKTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* NFOVTex;						//var Texture NFOVTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* WFOVTex;						//var Texture WFOVTex;
	UPROPERTY(EditAnywhere)		UMaterialInstance* DayTex;							//var Texture DayTex;
	UPROPERTY(EditAnywhere)		ABaseOptics* Boptics;						//var AGP.BaseOptics Boptics;
	UPROPERTY(EditAnywhere)		bool bNeedtoSetNightVision;					//var bool bNeedtoSetNightVision;
	UPROPERTY(EditAnywhere)		int32 RandInd;								//var int RandInd;
	UPROPERTY(EditAnywhere)		float RandArray;							//var float RandArray;
	UPROPERTY(EditAnywhere)		UMaterialInstance* NightVisionTexture;				//var Texture NightVisionTexture;

	void BeginPlay();
	void UpdatePrecacheMaterials();
	void UpdateTrackGateSize(UCanvas* C);
	void SetbUpdateTrackGateSize();
	void DrawTrackGate(UCanvas* C);
	UMaterialInstance* GetZoomOverlay();
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	void Zoom(APlayerController* PC);
	float DrawCrosshairX(UCanvas* Canvas);
	float DrawCrosshairY(UCanvas* Canvas);
};
