// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/MissionResultDisplay/MissionResultDisplay.h"
#include "AA29/Object/Actor/ScoreKeeper/ScoreKeeper.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "Engine/Canvas.h"

UMissionResultDisplay::UMissionResultDisplay()
{
	_iScoreIndex = -1;
}

void UMissionResultDisplay::Start()
{
	SetScoreText();
}

void UMissionResultDisplay::Draw(UCanvas* Canvas)
{
}

void UMissionResultDisplay::SetScoreText()
{
}

int32 UMissionResultDisplay::GetScoreIndex(int32 Score)
{
	int32 Size = 0;
	int32 cur = 0;
	Size = ScoringTable.Num();
	for (cur = 0; cur < Size; cur++)
	{
		if (Score >= ScoringTable[cur].LoRange && Score <= ScoringTable[cur].HiRange)
		{
			return cur;
		}
	}
	return -1;
}

void UMissionResultDisplay::SetScoreKeeper(AScoreKeeper* sk)
{
	_ScoreKeeper = sk;
}
void UMissionResultDisplay::UpdateScore()
{
	if (_ScoreKeeper != nullptr)
	{
		_iHit = _ScoreKeeper->TotalScore.nShot;
		_iMax = _ScoreKeeper->TotalScore.nTotal;
		_iScoreIndex = GetScoreIndex(_iHit);
		if (_iScoreIndex == -1)
		{
			_AwardTexture = nullptr;
		}
		else
		{
			_AwardTexture = ScoringTable[_iScoreIndex].AwardTexture;
		}
	}
}

bool UMissionResultDisplay::PlayerPass()
{
	UpdateScore();
	if (_iScoreIndex != -1)
	{
		return ScoringTable[_iScoreIndex].bPass;
	}
	return 0;    //FAKE   /ELiZ
}

USoundBase* UMissionResultDisplay::GetStatusSound()
{
	USoundBase* Sound = nullptr;
	UE_LOG(LogTemp, Log, TEXT("MissionResultDisplay::GetStatusSound()"));
	DumpScoreTable();
	UpdateScore();
	if (_iScoreIndex != -1)
	{
		//Log("MissionResultDisplay::GetStatusSound() ScoringTable[" + _iScoreIndex + "].AwardSound = " + ScoringTable[_iScoreIndex].AwardSound);
		Sound = ScoringTable[_iScoreIndex].AwardSound;
		//Log("MissionResultDisplay::GetStatusSound() Sound = " + Sound + " " + Sound.Name);
	}
	UE_LOG(LogTemp, Log, TEXT("MissionResultDisplay::GetStatusSound() _iScoreIndex = %d"),_iScoreIndex);
	return Sound;
}

void UMissionResultDisplay::DumpScoreTable()
{
	int32 Size;
	int32 cur;
	Size = ScoringTable.Num();
	for (cur = 0; cur < Size; cur++)
	{
		UE_LOG(LogTemp, Log, TEXT("ScoringTable[%d]"),cur);
		UE_LOG(LogTemp, Log, TEXT("  LoRange      : %d"), ScoringTable[cur].LoRange);
		UE_LOG(LogTemp, Log, TEXT("  HiRange      : %d"), ScoringTable[cur].HiRange);
		UE_LOG(LogTemp, Log, TEXT("  Award        : %s"), *ScoringTable[cur].Award);
		//UE_LOG(LogTemp, Log, TEXT("  AwardTexture : %s"), ScoringTable[cur].AwardTexture);
		//UE_LOG(LogTemp, Log, TEXT("  AwardSound   : %s"), ScoringTable[cur].AwardSound);
		UE_LOG(LogTemp, Log, TEXT("  bPass        : %s"), ScoringTable[cur].bPass ? TEXT("true") : TEXT("false"));
	}
}

void UMissionResultDisplay::ScaleControl(UCanvas* Canvas)
{
	int32 Size = 0;
	int32 cur = 0;
	UFont* temp_font = nullptr;
	float Xsize = 0;
	float Ysize = 0;
	Super::ScaleControl(Canvas);
	Size = ResultText.Num();
	for (cur = 0; cur < Size; cur++)
	{
		ResultText[cur].iScaledX = ResultText[cur].ix * cFrame->fScaleX;
		ResultText[cur].iScaledY = ResultText[cur].iY * cFrame->fScaleY;
	}
	UpdateScore();
	SetScoreText();
	//temp_font = Canvas.Font;
	//Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	//Canvas.TextSize(ScoreText, Xsize, Ysize);
	//ScaledScoreTextPos.X = Canvas.SizeX - Xsize / 2;
	ScaledScoreTextPos.Y = ScoreTextPos.Y * cFrame->fScaleY;
	AwardScaledPos.X = AwardPos.X * cFrame->fScaleX + cFrame->offset.X;
	AwardScaledPos.Y = AwardPos.Y * cFrame->fScaleY + cFrame->offset.Y;
	AwardScaledPos.W = AwardPos.W * cFrame->fScaleX + cFrame->offset.X;
	AwardScaledPos.H = AwardPos.H * cFrame->fScaleY + cFrame->offset.Y;
	RifleScaledPos.X = RiflePos.X * cFrame->fScaleX + cFrame->offset.X;
	RifleScaledPos.Y = RiflePos.Y * cFrame->fScaleY + cFrame->offset.Y;
	RifleScaledPos.W = RiflePos.W * cFrame->fScaleX + cFrame->offset.X;
	RifleScaledPos.H = RiflePos.H * cFrame->fScaleY + cFrame->offset.Y;
	//Canvas.Font = temp_font;
}
