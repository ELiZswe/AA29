// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/CROWS_Hud/CROWS_Hud.h"
#include "FSTS_CROWS_HUD.generated.h"

class AScoreKeeper;

UCLASS()
class AFSTS_CROWS_HUD : public ACROWS_Hud
{
	GENERATED_BODY()
public:
	AFSTS_CROWS_HUD(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()			FString			HudMessage;		//var FString HudMessage;
	UPROPERTY()			float			PosX;			//var float PosX;
	UPROPERTY()			float			PosY;			//var float PosY;
	UPROPERTY()			bool			bShowMessage;	//var bool bShowMessage;
	UPROPERTY()			bool			bShowScore;		//var bool bShowScore;
	UPROPERTY()			AScoreKeeper*	ScoreKeeper;	//var ScoreKeeper ScoreKeeper;
	UPROPERTY()			int32			MaxTargets;		//var int32 MaxTargets;

	void SetMessage(FString Message);
	void SetScore(AScoreKeeper* keeper, int32 totalTargets);
	void SetCoords(UCanvas* C);
	void DrawMessage(UCanvas* C);
	void DrawScore(UCanvas* C);
	void PostRender_Stage2(UCanvas* Canvas);
};
