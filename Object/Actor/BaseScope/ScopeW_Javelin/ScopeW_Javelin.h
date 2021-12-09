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

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ZoomStartTime;						//var float ZoomStartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* VisualFadeOverlay;				//var Texture VisualFadeOverlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float VisualFadeInTime;						//var float VisualFadeInTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bUpdateTrackGateSize;					//var bool bUpdateTrackGateSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bUseOldTrackGate;						//var bool bUseOldTrackGate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 DrawTrackGateY;						//var int DrawTrackGateY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 DrawTrackGateX;						//var int DrawTrackGateX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateY;							//var int TrackGateY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateX;							//var int TrackGateX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateDownSize;					//var int TrackGateDownSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateUpSize;						//var int TrackGateUpSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateRightSize;					//var int TrackGateRightSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 TrackGateLeftSize;					//var int TrackGateLeftSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AHumanController* Jav_User;					//var AGP.HumanController Jav_User;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AWEAPON_Javelin* mygun;						//var WEAPON_Javelin mygun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* TrackGate;						//var Texture TrackGate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* CrossHair;						//var Texture CrossHair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* Seek_Overlay;					//var Texture Seek_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* NFOV_Overlay;					//var Texture NFOV_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* WFOV_Overlay;					//var Texture WFOV_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* MBitFailTex;					//var Texture MBitFailTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* TOPTex;							//var Texture TOPTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* DIRTex;							//var Texture DIRTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* SEEKTex;						//var Texture SEEKTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* NFOVTex;						//var Texture NFOVTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* WFOVTex;						//var Texture WFOVTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* DayTex;							//var Texture DayTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ABaseOptics* Boptics;						//var AGP.BaseOptics Boptics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNeedtoSetNightVision;					//var bool bNeedtoSetNightVision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandInd;								//var int RandInd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float RandArray;							//var float RandArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UMaterialInstance* NightVisionTexture;				//var Texture NightVisionTexture;

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
