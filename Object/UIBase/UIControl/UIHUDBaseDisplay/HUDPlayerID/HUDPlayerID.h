// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDPlayerID.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDPlayerID : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDPlayerID();

	UPROPERTY()										UMaterialInstance* _tHealing;		//var Texture _tHealing;
	UPROPERTY()										UMaterialInstance* _tHealed;		//var Texture _tHealed;
	UPROPERTY()										UMaterialInstance* _tBleeding;		//var Material _tBleeding;
	UPROPERTY()										TArray<FString> FTName;				//var string FTName;
	UPROPERTY()										TArray<FString> FTLetter;			//var string FTLetter;
	UPROPERTY()										TArray<UMaterialInstance*> tFT;		//var Texture tFT;
	UPROPERTY()										UMaterialInstance* tSFTeamLeader;	//var Texture tSFTeamLeader;
	UPROPERTY()										UMaterialInstance* tVIP;			//var Texture tVIP;
	UPROPERTY()										UMaterialInstance* tSFCaptain;		//var Texture tSFCaptain;
	UPROPERTY()										UMaterialInstance* tIndigenous;		//var Texture tIndigenous;
	UPROPERTY()										UMaterialInstance* tTeamMember;		//var Texture tTeamMember;
	UPROPERTY()										UMaterialInstance* tTeamLeader;		//var Texture tTeamLeader;
	UPROPERTY()										UMaterialInstance* tSquadLeader;	//var Texture tSquadLeader;
	UPROPERTY()										float LostTargetTime;				//var float LostTargetTime;
	UPROPERTY()										EDisplayType DisplayType;			//var EDisplayType DisplayType;
	UPROPERTY()										AAA2_PlayerState* _TargetPRI;		//var PlayerReplicationInfo _TargetPRI;
	UPROPERTY()										int32 ColorId;						//var int ColorId;
	UPROPERTY()										bool bDeepTrace;					//var bool bDeepTrace;


	void Destroyed();
	void SetTarget(AAA2_PlayerState* new_target, int32 new_color_id, bool new_deep_trace);
	void NoTarget();
	void ClearTarget();
	void Draw(UCanvas* Canvas);
	void GetFadeValue();
	void DrawPlayerID(UCanvas* Canvas);
	void DrawPlayerRank(UCanvas* Canvas);
	void DrawMedicalID(UCanvas* Canvas);
};
