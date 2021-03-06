// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/AGP_Scoreboard/AGP_Scoreboard.h"
#include "AA29/AA2_PlayerState.h"

AAGP_Scoreboard::AAGP_Scoreboard()
{
	Ordered.SetNum(128);
	MapTitle = "in";
	Author = "by";
	Restart = "You are dead.  Hit [Fire] to respawn or enter Spectator mode!";
	Continue = " Hit [Fire] to continue!";
	Ended = "The match has ended.";
	ElapsedTime = "Elapsed Time: ";
	RemainingTime = "Remaining Time: ";
	FragGoal = "Frag Limit:";
	TimeLimit = "Time Limit:";
	PlayerString = "Player";
	TotalString = "Score";
	FragsString = "Enemy";
	DeathsString = "KIA";
	PingString = "Ping";
	IconPos = 0.1;
	PlayerPos = 0.2;
	TotalPos = 0.5;
	FragsPos = 0.6;
	DeathsPos = 0.7;
	PingPos = 0.88;
	TimeString = "Time";
	LossString = "Loss";
	FPHString = "FPH";
	GreenColor = FColor(0, 255, 0, 255);
	WhiteColor = FColor(255, 255, 255, 255);
	GoldColor = FColor(0, 255, 255, 255);
	LightCyanColor = FColor(255, 255, 128, 255);
	CyanColor = FColor(255, 128, 0, 255);
	PurpleColor = FColor(255, 0, 255, 255);
	iMaxNameLen = 24;
	PostGameEndMessage = " wins the round!";
	LastPlayerUpdateTime = -1;
	PlayerHeaderPos = 0.3;
}

void AAGP_Scoreboard::Destroyed()
{
	//Super::Destroyed();
}

void AAGP_Scoreboard::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	PlayerOwner = Cast<APlayerController>(GetOwner());
	*/
}

void AAGP_Scoreboard::DrawHeader(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	UFont* CanvasFont = nullptr;
	/*
	Canvas.DrawColor = WhiteColor;
	Canvas.bCenter = true;
	Canvas.StrLen("Test", XL, YL);
	ScoreStart = 0.08 * Canvas.ClipY;
	CanvasFont = Canvas.Font;
	Canvas.bCenter = false;
	Canvas.Font = CanvasFont;
	*/
}

void AAGP_Scoreboard::DrawVictoryConditions(UCanvas* Canvas)
{
}

FString AAGP_Scoreboard::TwoDigitString(int32 Num)
{
	/*
	if (Num < 10)
	{
		return "0" + Num;
	}
	else
	{
		return Num;
	}
	*/
	return "00";    //FAKE  /ELiZ
}

void AAGP_Scoreboard::DrawTrailer(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	/*
	Canvas.bCenter = true;
	Canvas.StrLen("Test", XL, YL);
	Canvas.DrawColor = WhiteColor;
	Canvas.SetPos(0, Canvas.SizeY * 0.91);
	Canvas.DrawText("F1: Show Scores" + "    " + "F2: Change Class" + "    ");
	Canvas.SetPos(0, Canvas.SizeY * 0.91 + YL);
	Canvas.DrawText("F3: Change Team" + "    " + "F4: Show Objectives");
	Canvas.bCenter = false;
	*/
}

void AAGP_Scoreboard::DrawCategoryHeaders(UCanvas* Canvas)
{
	float offset = 0;
	float XL = 0;
	float YL = 0;
	/*
	offset = Canvas.CurY;
	Canvas.DrawColor = WhiteColor;
	Canvas.SetPos(Canvas.SizeX * PlayerHeaderPos, offset);
	Canvas.DrawText(PlayerString);
	Canvas.StrLen(TotalString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * TotalPos - XL * 0.5, offset);
	Canvas.DrawText(TotalString);
	Canvas.StrLen(FragsString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FragsPos - XL * 0.5, offset);
	Canvas.DrawText(FragsString);
	Canvas.StrLen(DeathsString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * DeathsPos - XL * 0.5, offset);
	Canvas.DrawText(DeathsString);
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Canvas.StrLen(PingString, XL, YL);
		Canvas.SetPos(Canvas.SizeX * PingPos - XL * 0.5, offset);
		Canvas.DrawText(PingString);
	}
	*/
}

FColor AAGP_Scoreboard::DeterminePlayerColor(AAA2_PlayerState* PRI)
{
	bool bLocalPlayer = false;
	/*
	bLocalPlayer = PRI == PlayerOwner.PlayerReplicationInfo;
	if (bLocalPlayer)
	{
		return GoldColor;
	}
	else
	{
		return CyanColor;
	}
	*/
	return CyanColor;   //FAKE   /ELiZ
}

FString AAGP_Scoreboard::GetPlayerName(AAA2_PlayerState* namePRI, UCanvas* Canvas)
{
	/*
	if (namePRI != nullptr)
	{
		return Left(namePRI.PlayerName, iMaxNameLen);
	}
	else
	{
		return "Recruit";
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString AAGP_Scoreboard::VerifyPlayerName(UCanvas* Canvas, FString PlayerName, FString squadtag, float scorewidth)
{
	float NameWidth = 0;
	float YL = 0;
	/*
	Canvas.StrLen(squadtag + PlayerName + " ", NameWidth, YL);
	if (NameWidth > Canvas.SizeX * TotalPos - PlayerPos - scorewidth * 0.5)
	{
		PlayerName = Locs(PlayerName);
	}
	*/
	return PlayerName;
}

void AAGP_Scoreboard::DrawNameAndPing(UCanvas* Canvas, AAA2_PlayerState* PRI, float XOffset, float YOffset)
{
	float XL = 0;
	float YL = 0;
	FString SquadName = "";
	FString PlayerName = "";
	FColor PlayerColor = FColor(0,0,0);
	/*
	PlayerColor = DeterminePlayerColor(PRI);
	Canvas.DrawColor = PlayerColor;
	Canvas.StrLen(PRI.Score_Total, XL, YL);
	Canvas.SetPos(Canvas.SizeX * TotalPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Total, false);
	SquadName = PRI.GetSquadName();
	PlayerName = VerifyPlayerName(Canvas, GetPlayerName(PRI), SquadName, XL);
	Canvas.DrawColor = WhiteColor;
	Canvas.SetPos(Canvas.SizeX * PlayerPos, YOffset);
	Canvas.DrawText(SquadName, false);
	Canvas.StrLen(SquadName, XL, YL);
	Canvas.DrawColor = PlayerColor;
	Canvas.SetPos(Canvas.SizeX * PlayerPos + XL, YOffset);
	Canvas.DrawText(PlayerName, false);
	Canvas.StrLen(PRI.Score_Kills, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FragsPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Kills, false);
	Canvas.StrLen(PRI.Score_Deaths, XL, YL);
	Canvas.SetPos(Canvas.SizeX * DeathsPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Deaths, false);
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Canvas.StrLen(PRI.Ping, XL, YL);
		Canvas.SetPos(Canvas.SizeX * PingPos - XL, YOffset);
		Canvas.DrawText(PRI.Ping, false);
	}
	*/
}

int32 AAGP_Scoreboard::CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2)
{
	if (PRI1 == PRI2)
	{
		return 0;
	}
	if (PRI1->PlayerName <= PRI2->PlayerName)
	{
		return 1;
	}
	else
	{
		return - 1;
	}

	return 0;   //FAKE   /ELiZ
}

void AAGP_Scoreboard::SortScores(int32 N)
{
	int32 i = 0;
	int32 j = 0;
	int32 Max = 0;
	AAA2_PlayerState* TempPRI = nullptr;
	i = 0;
	/*
	if (i < N - 1)
	{
		Max = i;
		for (j = i + 1; j < N; j++)
		{
			if (CompareScores(Ordered[j], Ordered[Max]) > 0)
			{
				Max = j;
			}
		}
		TempPRI = Ordered[Max];
		Ordered[Max] = Ordered[i];
		Ordered[i] = TempPRI;
		i++;
	}
	*/
}

void AAGP_Scoreboard::UpdatePlayerList()
{
	/*
	int32 i = 0;
	AAA2_PlayerState* PRI;
	if (GetWorld()->GetTimeSeconds() - LastPlayerUpdateTime < 0.5)
	{
		return;
	}
	LastPlayerUpdateTime = GetWorld()->GetTimeSeconds();
	for (i = 0; i < 128; i++)
	{
		Ordered[i] = nullptr;
	}
	PlayerCount = 0;
	ForEach AllActors('PlayerReplicationInfo', PRI)
	{
		if (PRI.bAdmin && PRI.SuperUser())
		{
		}
		else
		{
			if (!PRI.bIsSpectator || PRI.bWaitingPlayer)
			{
				Ordered[PlayerCount] = PRI;
				PlayerCount++;
				if (PlayerCount == 128)
				{
				}
			}
			else
			{
			}
		}
	}
	SortScores(PlayerCount);
	*/
}

void AAGP_Scoreboard::ShowScores(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	float YOffset = 0;
	float YStart = 0;
	UFont* CanvasFont = nullptr;
	int32 i = 0;
	/*
	Canvas.Style = 1;
	Canvas.SetPos(0, 0);
	DrawHeader(Canvas);
	UpdatePlayerList();
	CanvasFont = Canvas.Font;
	Canvas.SetPos(0, 160 / 768 * Canvas.ClipY);
	DrawCategoryHeaders(Canvas);
	Canvas.StrLen("TEST", XL, YL);
	YStart = Canvas.CurY;
	YOffset = YStart;
	Canvas.SetPos(0, 0);
	for (i = 0; i < PlayerCount; i++)
	{
		YOffset = YStart + i * YL;
		DrawNameAndPing(Canvas, Ordered[i], 0, YOffset);
	}
	Canvas.DrawColor = WhiteColor;
	Canvas.Font = CanvasFont;
	DrawTrailer(Canvas);
	Canvas.DrawColor = WhiteColor;
	Canvas.Font = CanvasFont;
	*/
}
void AAGP_Scoreboard::UseSmallFont(UCanvas* Canvas)
{
	/*
	if (Canvas.ClipX <= 640)
	{
		Canvas.Font = SmallFont;
	}
	else
	{
		Canvas.Font = MedFont;
	}
	*/
}
void AAGP_Scoreboard::UseMediumFont(UCanvas* Canvas)
{
	/*
	if (Canvas.ClipX <= 640)
	{
		Canvas.Font = MedFont;
	}
	else
	{
		Canvas.Font = BigFont;
	}
	*/
}
void AAGP_Scoreboard::UseLargeFont(UCanvas* Canvas)
{
	/*
	if (Canvas.ClipX <= 640)
	{
		Canvas.Font = BigFont;
	}
	else
	{
		Canvas.Font = LargeFont;
	}
	*/
}

void AAGP_Scoreboard::UseHugeFont(UCanvas* Canvas)
{
	//Canvas.Font = LargeFont;
}

AAA2_PlayerState* AAGP_Scoreboard::GetOrdered(int32 i)
{
	return Ordered[i];
}
