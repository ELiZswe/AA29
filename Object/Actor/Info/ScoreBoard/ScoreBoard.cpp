// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoard.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "Engine/Canvas.h"

AScoreBoard::AScoreBoard()
{

}

void AScoreBoard::PostBeginPlay()
{
	//Super::PostBeginPlay();
	InitGRI();
	Init();
}

UFont* AScoreBoard::GetSmallerFontFor(UCanvas* Canvas, int32 offset)
{
	/*
	int32 i = 0;
	i = 0;
	if (i < 8 - offset)
	{
		if (HudClass.Default.FontScreenWidthMedium[i] <= Canvas.ClipX)
		{
			return HudClass.LoadFontStatic(i + offset);
		}
		i++;
	}
	return HudClass.LoadFontStatic(8);
	*/
	return nullptr;    //FAKE   /EliZ
}

bool AScoreBoard::HaveHalfFont(UCanvas* Canvas, int32 offset)
{
	/*
	int32 i = 0;
	i = 0;
	if (i < 9 - offset)
	{
		if (HudClass.Default.FontScreenWidthSmall[i] <= Canvas.ClipX)
		{
			return true;
		}
		i++;
	}
	*/
	return false;
}

UFont* AScoreBoard::GetSmallFontFor(int32 ScreenWidth, int32 offset)
{
	/*
	int32 i = 0;
	i = 0;
	if (i < 8 - offset)
	{
		if (HudClass.Default.FontScreenWidthSmall[i] <= ScreenWidth)
		{
			return HudClass.LoadFontStatic(i + offset);
		}
		i++;
	}
	return HudClass.LoadFontStatic(8);
	*/
	return nullptr;    //FAKE   /EliZ
}

void AScoreBoard::InitGRI()
{
	//GRI = Cast<APlayerController>(GetOwner())->GameReplicationInfo;
}

FString AScoreBoard::InitTitle()
{
	//return Caps(GRI.GameName);
	return "FAKE";    //FAKE   /ELiZ
}

void AScoreBoard::Init()
{
}

void AScoreBoard::DrawScoreboard(UCanvas* C)
{
	UpdateGRI();
	UpdateScoreBoard(C);
}

bool AScoreBoard::UpdateGRI()
{
	if (GRI == nullptr)
	{
		InitGRI();
		if (GRI == nullptr)
		{
			return false;
		}
	}
	SortPRIArray();
	return true;
}

FString AScoreBoard::FormatTime(int32 Seconds)
{
	FString Time="";

	/*
	int32 minutes;
	int32 hours;
	
	if (Seconds > 3600)
	{
		hours = Seconds / 3600;
		Seconds -= hours * 3600;
		Time = hours + ":";
	}
	minutes = Seconds / 60;
	Seconds -= minutes * 60;
	if (minutes >= 10)
	{
		Time = Time + minutes + ":";
	}
	else
	{
		Time = Time + "0" + minutes + ":";
	}
	if (Seconds >= 10)
	{
		Time = Time + Seconds;
	}
	else
	{
		Time = Time + "0" + Seconds;
	}
	*/
	return Time;
}

void AScoreBoard::UpdateScoreBoard(UCanvas* Canvas)
{
}

bool AScoreBoard::InOrder(AAA2_PlayerState* P1, AAA2_PlayerState* P2)
{
	/*
	if (P1.bOnlySpectator)
	{
		if (P2.bOnlySpectator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (P2.bOnlySpectator)
		{
			return true;
		}
	}
	if (P1.Score_Total < P2.Score_Total)
	{
		return false;
	}
	if (P1.Score_Total == P2.Score_Total)
	{
		if (P1.Score_Deaths > P2.Score_Deaths)
		{
			return false;
		}
		if (P1.Score_Deaths == P2.Score_Deaths && PlayerController(P2.Owner) != nullptr && Viewport(Cast<APlayerController>(P2.Owner).Player) != nullptr)
		{
			return false;
		}
	}
	*/
	return true;
}

void AScoreBoard::SortPRIArray()
{
	/*
	int32 i = 0;
	int32 j = 0;
	AAA2_PlayerState* tmp;
	i = 0;
	if (i < GRI.PRIArray.Num() - 1)
	{
		for (j = i + 1; j < GRI.PRIArray.Num(); j++)
		{
			if (!InOrder(GRI.PRIArray[i], GRI.PRIArray[j]))
			{
				tmp = GRI.PRIArray[i];
				GRI.PRIArray[i] = GRI.PRIArray[j];
				GRI.PRIArray[j] = tmp;
			}
		}
		i++;
	}
	*/
}

void AScoreBoard::ShowScores(UCanvas* Canvas)
{
}

void AScoreBoard::PreBeginPlay()
{
}

void AScoreBoard::NextStats()
{
}
