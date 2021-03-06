// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/MissionResultDisplay/Mission2ResultDisplay/Mission2ResultDisplay.h"

UMission2ResultDisplay::UMission2ResultDisplay()
{
	ResultText = { FLine({"Mission 2 Results",312,118,0,0}) };
	AwardPos = FPosition({ 360, 293, 80, 75 });
	RiflePos = FPosition({ 358, 333, 80, 75 });
	ScoreTextPos = FPosition({ 250, 234, 0, 0 });
}

static const int32 kM2_ExpertMarksman = 3;
static const int32 kM2_Sharpshooter = 2;
static const int32 kM2_Pass = 1;
static const int32 kM2_Fail = 0;

void UMission2ResultDisplay::Draw(UCanvas* Canvas)
{
}

void UMission2ResultDisplay::SetScoreText()
{
	//ScoreText = "You hit " + FString::FromInt(_iHit) + " out of " + FString::FromInt(_iMax) + " targets.";
}
