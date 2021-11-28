// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoard.h"

AScoreBoard::AScoreBoard()
{

}


void AScoreBoard::PostBeginPlay()
{
	/*
	PostBeginPlay();
	InitGRI();
	Init();
	*/
}
void AScoreBoard::GetSmallerFontFor(UCanvas* Canvas, int32 offset)
{
	/*
	local int i;
	i = 0;
	if (i < 8 - offset)
	{
		if (HudClass.Default.FontScreenWidthMedium[i] <= Canvas.ClipX)
		{
			Return HudClass.LoadFontStatic(i + offset);
		}
		i++;
	}
	Return HudClass.LoadFontStatic(8);
	*/
}
bool AScoreBoard::HaveHalfFont(UCanvas* Canvas, int32 offset)
{
	/*
	local int i;
	i = 0;
	if (i < 9 - offset)
	{
		if (HudClass.Default.FontScreenWidthSmall[i] <= Canvas.ClipX)
		{
			Return True;
		}
		i++;
	}
	*/
	return false;
}
void AScoreBoard::GetSmallFontFor(int32 ScreenWidth, int32 offset)
{
	/*
	local int i;
	i = 0;
	if (i < 8 - offset)
	{
		if (HudClass.Default.FontScreenWidthSmall[i] <= ScreenWidth)
		{
			Return HudClass.LoadFontStatic(i + offset);
		}
		i++;
	}
	Return HudClass.LoadFontStatic(8);
	*/
}
void AScoreBoard::InitGRI()
{
	//GRI = PlayerController(Owner).GameReplicationInfo;
}
void AScoreBoard::InitTitle()
{
	//Return Caps(GRI.GameName);
}
void AScoreBoard::Init()
{
}
void AScoreBoard::DrawScoreboard(UCanvas* C)
{
	/*
	UpdateGRI();
	UpdateScoreBoard(C);
	*/
}
bool AScoreBoard::UpdateGRI()
{
	/*
	if (GRI == None)
	{
		InitGRI();
		if (GRI == None)
		{
			Return False;
		}
	}
	SortPRIArray();
	*/
	return true;
}
FString AScoreBoard::FormatTime(int32 Seconds)
{
	FString Time="";

	/*
	local int minutes;
	local int hours;
	
	if (Seconds > 3600)
	{
		hours = Seconds / 3600;
		Seconds -= hours * 3600;
		Time = hours $ ":";
	}
	minutes = Seconds / 60;
	Seconds -= minutes * 60;
	if (minutes >= 10)
	{
		Time = Time $ minutes $ ":";
	}
	else
	{
		Time = Time $ "0" $ minutes $ ":";
	}
	if (Seconds >= 10)
	{
		Time = Time $ Seconds;
	}
	else
	{
		Time = Time $ "0" $ Seconds;
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
			Return True;
		}
		else
		{
			Return False;
		}
	}
	else
	{
		if (P2.bOnlySpectator)
		{
			Return True;
		}
	}
	if (P1.Score_Total < P2.Score_Total)
	{
		Return False;
	}
	if (P1.Score_Total == P2.Score_Total)
	{
		if (P1.Score_Deaths > P2.Score_Deaths)
		{
			Return False;
		}
		if (P1.Score_Deaths == P2.Score_Deaths && PlayerController(P2.Owner) != None && Viewport(PlayerController(P2.Owner).Player) != None)
		{
			Return False;
		}
	}
	*/
	return true;
}
void AScoreBoard::SortPRIArray()
{
	/*
	local int i;
	local int j;
	local PlayerReplicationInfo tmp;
	i = 0;
	if (i < GRI.PRIArray.Length - 1)
	{
		for (j = i + 1; j < GRI.PRIArray.Length; j++)
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
