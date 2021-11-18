// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "MissionResultDisplay.generated.h"

class AScoreKeeper;

UCLASS()
class AA29_API UMissionResultDisplay : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UMissionResultDisplay();

	UPROPERTY()										int32 _iMax;											//var int _iMax;
	UPROPERTY()										int32 _iHit;											//var int _iHit;
	UPROPERTY()										int32 _iScoreIndex;										//var int _iScoreIndex;
	UPROPERTY()										FPosition ScaledScoreTextPos;							//var UIBase.Position ScaledScoreTextPos;
	UPROPERTY()										FPosition ScoreTextPos;									//var UIBase.Position ScoreTextPos;
	UPROPERTY()										FString ScoreText;										//var string ScoreText;
	UPROPERTY()										USoundBase* AwardSound;									//var Sound AwardSound;
	UPROPERTY()										FPosition RifleScaledPos;								//var UIBase.Position RifleScaledPos;
	UPROPERTY()										FPosition RiflePos;										//var UIBase.Position RiflePos;
	UPROPERTY()										FPosition AwardScaledPos;								//var UIBase.Position AwardScaledPos;
	UPROPERTY()										FPosition AwardPos;										//var UIBase.Position AwardPos;
	UPROPERTY()										UMaterialInstance* _AwardTexture;						//var Texture _AwardTexture;
	UPROPERTY()										TArray<FScoring> ScoringTable;							//var array<Scoring> ScoringTable;
	UPROPERTY()										TArray<FLine> ResultText;								//var array<Line> ResultText;
	UPROPERTY()										AScoreKeeper* _ScoreKeeper;								//var ScoreKeeper _ScoreKeeper;

	void Start();
	void Draw(UCanvas* Canvas);
	void SetScoreText();
	void GetScoreIndex(int32 Score);
	void SetScoreKeeper(AScoreKeeper* sk);
	void UpdateScore();
	void PlayerPass();
	void GetStatusSound();
	void DumpScoreTable();
	void ScaleControl(UCanvas* Canvas);

};
