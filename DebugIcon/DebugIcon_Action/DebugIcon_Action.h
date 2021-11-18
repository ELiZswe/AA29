// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DebugIcon/DebugIcon.h"
#include "DebugIcon_Action.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADebugIcon_Action : public ADebugIcon
{
	GENERATED_BODY()
public:
	ADebugIcon_Action();


	UPROPERTY()				UMaterialInstance*			Action_DoNothing_Tex;									//var Texture Action_DoNothing_Tex;
	UPROPERTY()				UMaterialInstance*			Action_RunFromGrenade_Tex;								//var Texture Action_RunFromGrenade_Tex;
	UPROPERTY()				UMaterialInstance*			Action_ResumePatrol_Tex;								//var Texture Action_ResumePatrol_Tex;
	UPROPERTY()				UMaterialInstance*			Action_ThrowSmoke_Tex;									//var Texture Action_ThrowSmoke_Tex;
	UPROPERTY()				UMaterialInstance*			Action_ThrowFrag_Tex;									//var Texture Action_ThrowFrag_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Taunt_Tex;										//var Texture Action_Taunt_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Switch_Tex;										//var Texture Action_Switch_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Surrender_Tex;									//var Texture Action_Surrender_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Suppress_Tex;									//var Texture Action_Suppress_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Shift_Tex;										//var Texture Action_Shift_Tex;
	UPROPERTY()				UMaterialInstance*			Action_SeekCover_Tex;									//var Texture Action_SeekCover_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Scan_Tex;										//var Texture Action_Scan_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Rush_Tex;										//var Texture Action_Rush_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Reload_Tex;										//var Texture Action_Reload_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Pursue_Tex;										//var Texture Action_Pursue_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Ivan_Tex;										//var Texture Action_Ivan_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Flank_Tex;										//var Texture Action_Flank_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Fireblind_Tex;									//var Texture Action_Fireblind_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Fallback_Tex;									//var Texture Action_Fallback_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Engage_Tex;										//var Texture Action_Engage_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Duck_Tex;										//var Texture Action_Duck_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Cower_Tex;										//var Texture Action_Cower_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Collapse_Tex;									//var Texture Action_Collapse_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Breakout_Tex;									//var Texture Action_Breakout_Tex;
	UPROPERTY()				UMaterialInstance*			Action_Advance_Tex;										//var Texture Action_Advance_Tex;

	void UpdateAction(FString NewAction);
};
