// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseScope/BaseScope.h"
#include "ScopeW_Javelin.generated.h"

//class AHumanController;

UCLASS()
class AA29_API AScopeW_Javelin : public ABaseScope
{
	GENERATED_BODY()
public:
	AScopeW_Javelin();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float ZoomStartTime;						//var float ZoomStartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* VisualFadeOverlay;				//var Texture VisualFadeOverlay;
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
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AHumanController* Jav_User;					//var AGP.HumanController Jav_User;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		AWEAPON_Javelin* mygun;					//var WEAPON_Javelin mygun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* TrackGate;						//var Texture TrackGate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* CrossHair;						//var Texture CrossHair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* Seek_Overlay;					//var Texture Seek_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* NFOV_Overlay;					//var Texture NFOV_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* WFOV_Overlay;					//var Texture WFOV_Overlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* MBitFailTex;					//var Texture MBitFailTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* TOPTex;							//var Texture TOPTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* DIRTex;							//var Texture DIRTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* SEEKTex;						//var Texture SEEKTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* NFOVTex;						//var Texture NFOVTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* WFOVTex;						//var Texture WFOVTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* DayTex;							//var Texture DayTex;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		ABaseOptics* Boptics;					//var AGP.BaseOptics Boptics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNeedtoSetNightVision;					//var bool bNeedtoSetNightVision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 RandInd;								//var int RandInd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float RandArray;							//var float RandArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* NightVisionTexture;				//var Texture NightVisionTexture;

};
