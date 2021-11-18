// All the original content belonged to the US Army


#include "AA29/Info/ScoreBoard/AGP_Scoreboard/AGP_Scoreboard.h"

AAGP_Scoreboard::AAGP_Scoreboard()
{
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
	PlayerOwner = PlayerController(Owner);
	*/
}

void AAGP_Scoreboard::DrawHeader(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	local Font CanvasFont;
	Canvas.DrawColor = WhiteColor;
	Canvas.bCenter = true;
	Canvas.StrLen("Test", XL, YL);
	ScoreStart = 0.08 * Canvas.ClipY;
	CanvasFont = Canvas.Font;
	Canvas.bCenter = False;
	Canvas.Font = CanvasFont;
	*/
}

void AAGP_Scoreboard::DrawVictoryConditions(UCanvas* Canvas)
{
}

void AAGP_Scoreboard::TwoDigitString(int32 Num)
{
	/*
	if (Num < 10)
	{
		Return "0" $ Num;
	}
	else
	{
		Return Num;
	}
	*/
}

void AAGP_Scoreboard::DrawTrailer(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	Canvas.bCenter = true;
	Canvas.StrLen("Test", XL, YL);
	Canvas.DrawColor = WhiteColor;
	Canvas.SetPos(0, Canvas.SizeY * 0.91);
	Canvas.DrawText("F1: Show Scores" $ "    " $ "F2: Change Class" $ "    ");
	Canvas.SetPos(0, Canvas.SizeY * 0.91 + YL);
	Canvas.DrawText("F3: Change Team" $ "    " $ "F4: Show Objectives");
	Canvas.bCenter = False;
	*/
}

void AAGP_Scoreboard::DrawCategoryHeaders(UCanvas* Canvas)
{
	/*
	local float offset;
	local float XL;
	local float YL;
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
	if (Level.NetMode != 0)
	{
		Canvas.StrLen(PingString, XL, YL);
		Canvas.SetPos(Canvas.SizeX * PingPos - XL * 0.5, offset);
		Canvas.DrawText(PingString);
	}
	*/
}

FColor AAGP_Scoreboard::DeterminePlayerColor(AAA2_PlayerState* PRI)
{
	/*
	local bool bLocalPlayer;
	bLocalPlayer = PRI == PlayerOwner.PlayerReplicationInfo;
	if (bLocalPlayer)
	{
		Return GoldColor;
	}
	else
	{
		Return CyanColor;
	}
	*/
	return CyanColor;   //FAKE   /ELiZ
}

FString AAGP_Scoreboard::GetPlayerName(AAA2_Playerstate* namePRI, UCanvas* Canvas)
{
	/*
	if (namePRI != None)
	{
		Return Left(namePRI.PlayerName, iMaxNameLen);
	}
	else
	{
		Return "Recruit";
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString AAGP_Scoreboard::VerifyPlayerName(UCanvas* Canvas, FString PlayerName, FString squadtag, float scorewidth)
{
	/*
	local float NameWidth;
	local float YL;
	Canvas.StrLen(squadtag $ PlayerName $ " ", NameWidth, YL);
	if (NameWidth > Canvas.SizeX * TotalPos - PlayerPos - scorewidth * 0.5)
	{
		PlayerName = Locs(PlayerName);
	}
	*/
	return PlayerName;
}

void AAGP_Scoreboard::DrawNameAndPing(UCanvas* Canvas, AAA2_Playerstate* PRI, float XOffset, float YOffset)
{
	/*
	local float XL;
	local float YL;
	local string SquadName;
	local string PlayerName;
	local Object.Color PlayerColor;
	PlayerColor = DeterminePlayerColor(PRI);
	Canvas.DrawColor = PlayerColor;
	Canvas.StrLen(PRI.Score_Total, XL, YL);
	Canvas.SetPos(Canvas.SizeX * TotalPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Total, False);
	SquadName = PRI.GetSquadName();
	PlayerName = VerifyPlayerName(Canvas, GetPlayerName(PRI), SquadName, XL);
	Canvas.DrawColor = WhiteColor;
	Canvas.SetPos(Canvas.SizeX * PlayerPos, YOffset);
	Canvas.DrawText(SquadName, False);
	Canvas.StrLen(SquadName, XL, YL);
	Canvas.DrawColor = PlayerColor;
	Canvas.SetPos(Canvas.SizeX * PlayerPos + XL, YOffset);
	Canvas.DrawText(PlayerName, False);
	Canvas.StrLen(PRI.Score_Kills, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FragsPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Kills, False);
	Canvas.StrLen(PRI.Score_Deaths, XL, YL);
	Canvas.SetPos(Canvas.SizeX * DeathsPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_Deaths, False);
	if (Level.NetMode != 0)
	{
		Canvas.StrLen(PRI.Ping, XL, YL);
		Canvas.SetPos(Canvas.SizeX * PingPos - XL, YOffset);
		Canvas.DrawText(PRI.Ping, False);
	}
	*/
}

int32 AAGP_Scoreboard::CompareScores(AAA2_Playerstate* PRI1, AAA2_Playerstate* PRI2)
{
	/*
	if (PRI1 == PRI2)
	{
		Return 0;
	}
	if (PRI1.PlayerName <= PRI2.PlayerName)
	{
		Return 1;
	}
	else
	{
		Return - 1;
	}
	*/
	return 0;   //FAKE   /ELiZ
}

void AAGP_Scoreboard::SortScores(int32 N)
{
	/*
	local int i;
	local int j;
	local int Max;
	local PlayerReplicationInfo TempPRI;
	i = 0;
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
	local int i;
	local PlayerReplicationInfo PRI;
	if (Level.TimeSeconds - LastPlayerUpdateTime < 0.5)
	{
		Return;
	}
	LastPlayerUpdateTime = Level.TimeSeconds;
	for (i = 0; i < 128; i++)
	{
		Ordered[i] = None;
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
	/*
	local float XL;
	local float YL;
	local float YOffset;
	local float YStart;
	local Font CanvasFont;
	local int i;
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
void AAGP_Scoreboard::GetOrdered(int32 i)
{
	//Return Ordered[i];
}