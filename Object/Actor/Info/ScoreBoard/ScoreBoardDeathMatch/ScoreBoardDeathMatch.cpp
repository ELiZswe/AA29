// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoardDeathMatch/ScoreBoardDeathMatch.h"

AScoreBoardDeathMatch::AScoreBoardDeathMatch()
{
	RankText = "RANK";
	PlayerText = "PLAYER";
	PointsText = "SCORE";
	TimeText = "TIME:";
	PingText = "PING:";
	PLText = "P/L:";
	DeathsText = "DEATHS";
	AdminText = "ADMIN";
	NetText = "NET";
	FooterText = "Elapsed Time:";
	MatchIDText = "UT2004 Stats Match ID";
	OutText = "OUT";
	OutFireText = "   You are OUT. Fire to view other players.";
	ReadyText = "READY";
	NotReadyText = "NOT RDY";
	SkillLevel = { "NOVICE","AVERAGE", "EXPERIENCED", "SKILLED", "ADEPT", "MASTERFUL", "INHUMAN", "GODLIKE" };
	MaxLives = "MAX LIVES:";
	FragLimit = "FRAG LIMIT:";
	FPH = "PPH";
	GameType = "GAME";
	MapName = " in ";
	Restart = "   You were killed. Press Fire to respawn!";
	Continue = " Press [Fire] to continue!";
	Ended = "The match has ended.";
	TimeLimit = "REMAINING TIME:";
	Spacer = " ";
	//HudClass = class'XInterface.HudBase';
}


//const MaxPlayers = 32;



void AScoreBoardDeathMatch::UpdatePrecacheMaterials()
{
	UpdatePrecacheFonts();
}
void AScoreBoardDeathMatch::UpdatePrecacheFonts()
{
}

void AScoreBoardDeathMatch::DrawTitle(UCanvas* Canvas, float HeaderOffsetY, float PlayerAreaY, float PlayerBoxSizeY)
{
}

FString AScoreBoardDeathMatch::GetTitleString()
{
	FString titlestring="";
	/*
	if (Level.NetMode == 0)
	{
		if (Level.Game.CurrentGameProfile != None)
		{
			titlestring = SkillLevel[Clamp(Level.Game.CurrentGameProfile.BaseDifficulty, 0, 7)];
		}
		else
		{
			titlestring = SkillLevel[Clamp(Level.Game.GameDifficulty, 0, 7)];
		}
	}
	else
	{
		if (GRI != None && GRI.BotDifficulty >= 0)
		{
			titlestring = SkillLevel[Clamp(GRI.BotDifficulty, 0, 7)];
		}
	}
	Return titlestring @ GRI.GameName $ MapName $ Level.Title;
	*/
	return "FAKE";     //FAKE   /ELiZ
}

FString AScoreBoardDeathMatch::GetRestartString()
{
	FString RestartString="";
	RestartString = Restart;
	/*
	if (PlayerController(Owner).PlayerReplicationInfo.bOutOfLives)
	{
		RestartString = OutFireText;
	}
	*/
	return RestartString;
}

FString AScoreBoardDeathMatch::GetDefaultScoreInfoString()
{
	FString ScoreInfoString="";
	/*
	if (GRI == None)
	{
		Return "";
	}
	if (GRI.MaxLives != 0)
	{
		ScoreInfoString = MaxLives @ GRI.MaxLives;
	}
	else
	{
		if (GRI.GoalScore != 0)
		{
			ScoreInfoString = FragLimit @ GRI.GoalScore;
		}
	}
	if (GRI.TimeLimit != 0)
	{
		ScoreInfoString = ScoreInfoString @ Spacer @ TimeLimit $ FormatTime(GRI.RemainingTime);
	}
	else
	{
		ScoreInfoString = ScoreInfoString @ Spacer @ FooterText @ FormatTime(GRI.ElapsedTime);
	}
	*/
	return ScoreInfoString;
}

void AScoreBoardDeathMatch::ExtraMarking(UCanvas* Canvas, int32 PlayerCount, int32 OwnerOffset, int32 XPos, int32 YPos, int32 YOffset)
{
}

void AScoreBoardDeathMatch::UpdateScoreBoard(UCanvas* Canvas)
{
	/*
	local PlayerReplicationInfo PRI;
	local PlayerReplicationInfo OwnerPRI;
	local int i;
	local int FontReduction;
	local int OwnerPos;
	local int NetXPos;
	local int PlayerCount;
	local int HeaderOffsetY;
	local int HeadFoot;
	local int MessageFoot;
	local int PlayerBoxSizeY;
	local int BoxSpaceY;
	local int NameXPos;
	local int BoxTextOffsetY;
	local int OwnerOffset;
	local int ScoreXPos;
	local int DeathsXPos;
	local int BoxXPos;
	local int TitleYPos;
	local int BoxWidth;
	local float XL;
	local float YL;
	local float MaxScaling;
	local float deathsXL;
	local float scoreXL;
	local float netXL;
	local float MaxNamePos;
	local float LongestNameLength;
	local string PlayerName;
	local string LongestName;
	local bool bNameFontReduction;
	local Font ReducedFont;
	OwnerPRI = PlayerController(Owner).PlayerReplicationInfo;
	for (i = 0; i < GRI.PRIArray.Length; i++)
	{
		PRI = GRI.PRIArray[i];
		if (!PRI.bOnlySpectator && !PRI.bIsSpectator || PRI.bWaitingPlayer)
		{
			if (PRI == OwnerPRI)
			{
				OwnerOffset = i;
			}
			PlayerCount++;
		}
	}
	PlayerCount = Min(PlayerCount, 32);
	Canvas.Font = HudClass.GetMediumFontFor(Canvas);
	Canvas.StrLen("Test", XL, YL);
	BoxSpaceY = 0.25 * YL;
	PlayerBoxSizeY = 1.5 * YL;
	HeadFoot = 5 * YL;
	MessageFoot = 1.5 * HeadFoot;
	if (PlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
	{
		BoxSpaceY = 0.125 * YL;
		PlayerBoxSizeY = 1.25 * YL;
		if (PlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
		{
			if (PlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
			{
				PlayerBoxSizeY = 1.125 * YL;
			}
			if (PlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
			{
				FontReduction++;
				Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
				Canvas.StrLen("Test", XL, YL);
				BoxSpaceY = 0.125 * YL;
				PlayerBoxSizeY = 1.125 * YL;
				HeadFoot = 5 * YL;
				if (PlayerCount > Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY)
				{
					FontReduction++;
					Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
					Canvas.StrLen("Test", XL, YL);
					BoxSpaceY = 0.125 * YL;
					PlayerBoxSizeY = 1.125 * YL;
					HeadFoot = 5 * YL;
					if (Canvas.ClipY >= 768 && PlayerCount > Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY)
					{
						FontReduction++;
						Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
						Canvas.StrLen("Test", XL, YL);
						BoxSpaceY = 0.125 * YL;
						PlayerBoxSizeY = 1.125 * YL;
						HeadFoot = 5 * YL;
					}
				}
			}
		}
	}
	if (Canvas.ClipX < 512)
	{
		PlayerCount = Min(PlayerCount, 1 + Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY);
	}
	else
	{
		PlayerCount = Min(PlayerCount, Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY);
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerCount -= 1;
	}
	if (FontReduction > 2)
	{
		MaxScaling = 3;
	}
	else
	{
		MaxScaling = 2.125;
	}
	PlayerBoxSizeY = FClamp(1 + Canvas.ClipY - 0.67 * MessageFoot / PlayerCount - BoxSpaceY, PlayerBoxSizeY, MaxScaling * YL);
	bDisplayMessages = PlayerCount <= Canvas.ClipY - MessageFoot / PlayerBoxSizeY + BoxSpaceY;
	HeaderOffsetY = 3 * YL;
	BoxWidth = 0.9375 * Canvas.ClipX;
	BoxXPos = 0.5 * Canvas.ClipX - BoxWidth;
	BoxWidth = Canvas.ClipX - 2 * BoxXPos;
	NameXPos = BoxXPos + 0.0625 * BoxWidth;
	ScoreXPos = BoxXPos + 0.5 * BoxWidth;
	DeathsXPos = BoxXPos + 0.6875 * BoxWidth;
	NetXPos = BoxXPos + 0.8125 * BoxWidth;
	Canvas.Style = 6;
	Canvas.DrawColor = HudClass.Default.WhiteColor * 0.5;
	for (i = 0; i < PlayerCount; i++)
	{
		Canvas.SetPos(BoxXPos, HeaderOffsetY + PlayerBoxSizeY + BoxSpaceY * i);
		Canvas.DrawTileStretched(BoxMaterial, BoxWidth, PlayerBoxSizeY);
	}
	Canvas.Style = 3;
	Canvas.Style = 1;
	DrawTitle(Canvas, HeaderOffsetY, PlayerCount + 1 * PlayerBoxSizeY + BoxSpaceY, PlayerBoxSizeY);
	TitleYPos = HeaderOffsetY - 1.25 * YL;
	Canvas.StrLen(PointsText, scoreXL, YL);
	Canvas.StrLen(DeathsText, deathsXL, YL);
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	Canvas.SetPos(NameXPos, TitleYPos);
	Canvas.DrawText(PlayerText, True);
	Canvas.SetPos(ScoreXPos - 0.5 * scoreXL, TitleYPos);
	Canvas.DrawText(PointsText, True);
	Canvas.SetPos(DeathsXPos - 0.5 * deathsXL, TitleYPos);
	Canvas.DrawText(DeathsText, True);
	if (PlayerCount <= 0)
	{
		Return;
	}
	MaxNamePos = 0.9 * ScoreXPos - NameXPos;
	for (i = 0; i < PlayerCount; i++)
	{
		PlayerName[i] = GRI.PRIArray[i].PlayerName;
		Canvas.StrLen(PlayerName[i], XL, YL);
		if (XL > FMax(LongestNameLength, MaxNamePos))
		{
			LongestName = PlayerName[i];
			LongestNameLength = XL;
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerName[OwnerOffset] = GRI.PRIArray[OwnerOffset].PlayerName;
		Canvas.StrLen(PlayerName[OwnerOffset], XL, YL);
		if (XL > FMax(LongestNameLength, MaxNamePos))
		{
			LongestName = PlayerName[i];
			LongestNameLength = XL;
		}
	}
	if (LongestNameLength > 0)
	{
		bNameFontReduction = true;
		Canvas.Font = GetSmallerFontFor(Canvas, FontReduction + 1);
		Canvas.StrLen(LongestName, XL, YL);
		if (XL > MaxNamePos)
		{
			Canvas.Font = GetSmallerFontFor(Canvas, FontReduction + 2);
			Canvas.StrLen(LongestName, XL, YL);
			if (XL > MaxNamePos)
			{
				Canvas.Font = GetSmallerFontFor(Canvas, FontReduction + 3);
			}
		}
		ReducedFont = Canvas.Font;
	}
	for (i = 0; i < PlayerCount; i++)
	{
		PlayerName[i] = GRI.PRIArray[i].PlayerName;
		Canvas.StrLen(PlayerName[i], XL, YL);
		if (XL > MaxNamePos)
		{
			PlayerName[i] = Left(PlayerName[i], MaxNamePos / XL * Len(PlayerName[i]));
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerName[OwnerOffset] = GRI.PRIArray[OwnerOffset].PlayerName;
		Canvas.StrLen(PlayerName[OwnerOffset], XL, YL);
		if (XL > MaxNamePos)
		{
			PlayerName[OwnerOffset] = Left(PlayerName[OwnerOffset], MaxNamePos / XL * Len(PlayerName[OwnerOffset]));
		}
	}
	Canvas.Style = 1;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	Canvas.SetPos(0.5 * Canvas.ClipX, HeaderOffsetY + 4);
	BoxTextOffsetY = HeaderOffsetY + 0.5 * PlayerBoxSizeY - YL;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	for (i = 0; i < PlayerCount; i++)
	{
		if (i != OwnerOffset)
		{
			Canvas.SetPos(NameXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
			Canvas.DrawText(PlayerName[i], True);
		}
	}
	if (bNameFontReduction)
	{
		Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
	}
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	for (i = 0; i < PlayerCount; i++)
	{
		if (i != OwnerOffset)
		{
			Canvas.SetPos(ScoreXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
			if (GRI.PRIArray[i].bOutOfLives)
			{
				Canvas.DrawText(OutText, True);
			}
		}
	}
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	for (i = 0; i < PlayerCount; i++)
	{
		if (i != OwnerOffset)
		{
			Canvas.SetPos(DeathsXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		OwnerPos = PlayerBoxSizeY + BoxSpaceY * PlayerCount + BoxTextOffsetY;
		Canvas.Style = 6;
		Canvas.DrawColor = HudClass.Default.TurqColor * 0.5;
		Canvas.SetPos(BoxXPos, HeaderOffsetY + PlayerBoxSizeY + BoxSpaceY * PlayerCount);
		Canvas.DrawTileStretched(BoxMaterial, BoxWidth, PlayerBoxSizeY);
		Canvas.Style = 1;
	}
	else
	{
		OwnerPos = PlayerBoxSizeY + BoxSpaceY * OwnerOffset + BoxTextOffsetY;
	}
	Canvas.DrawColor = HudClass.Default.GoldColor;
	Canvas.SetPos(NameXPos, OwnerPos);
	if (bNameFontReduction)
	{
		Canvas.Font = ReducedFont;
	}
	Canvas.DrawText(PlayerName[OwnerOffset], True);
	if (bNameFontReduction)
	{
		Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
	}
	Canvas.SetPos(ScoreXPos, OwnerPos);
	if (GRI.PRIArray[OwnerOffset].bOutOfLives)
	{
		Canvas.DrawText(OutText, True);
	}
	Canvas.SetPos(DeathsXPos, OwnerPos);
	ExtraMarking(Canvas, PlayerCount, OwnerOffset, NameXPos, PlayerBoxSizeY + BoxSpaceY, BoxTextOffsetY);
	if (Level.NetMode == 0)
	{
		Return;
	}
	Canvas.StrLen(NetText, netXL, YL);
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	Canvas.SetPos(NetXPos + 0.5 * netXL, TitleYPos);
	Canvas.DrawText(NetText, True);
	for (i = 0; i < GRI.PRIArray.Length; i++)
	{
		PRIArray[i] = GRI.PRIArray[i];
	}
	DrawNetInfo(Canvas, FontReduction, HeaderOffsetY, PlayerBoxSizeY, BoxSpaceY, BoxTextOffsetY, OwnerOffset, PlayerCount, NetXPos);
	DrawMatchID(Canvas, FontReduction);
	*/
}

void AScoreBoardDeathMatch::DrawMatchID(UCanvas* Canvas, int32 FontReduction)
{
	/*
	local float XL;
	local float YL;
	if (GRI.MatchID != 0)
	{
		Canvas.Font = GetSmallFontFor(1.5 * Canvas.ClipX, FontReduction + 1);
		Canvas.StrLen(MatchIDText @ GRI.MatchID, XL, YL);
		Canvas.SetPos(Canvas.ClipX - XL - 4, 4);
		Canvas.DrawText(MatchIDText @ GRI.MatchID, True);
	}
	*/
}

void AScoreBoardDeathMatch::DrawNetInfo(UCanvas* Canvas, int32 FontReduction, int32 HeaderOffsetY, int32 PlayerBoxSizeY, int32 BoxSpaceY, int32 BoxTextOffsetY, int32 OwnerOffset, int32 PlayerCount, int32 NetXPos)
{
	/*
	local float XL;
	local float YL;
	local int i;
	local bool bHaveHalfFont;
	local bool bDrawFPH;
	local bool bDrawPL;
	if (GRI.bMatchHasBegun)
	{
		Canvas.DrawColor = HudClass.Default.RedColor;
		for (i = 0; i < PlayerCount; i++)
		{
			if (PRIArray[i].bAdmin)
			{
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
				Canvas.DrawText(AdminText, True);
			}
		}
		if (OwnerOffset >= PlayerCount && PRIArray[OwnerOffset].bAdmin)
		{
			Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * PlayerCount + BoxTextOffsetY);
			Canvas.DrawText(AdminText, True);
		}
	}
	Canvas.DrawColor = HudClass.Default.CyanColor;
	Canvas.Font = GetSmallFontFor(Canvas.ClipX, FontReduction);
	Canvas.StrLen("Test", XL, YL);
	BoxTextOffsetY = HeaderOffsetY + 0.5 * PlayerBoxSizeY;
	bHaveHalfFont = YL < 0.5 * PlayerBoxSizeY;
	if (!GRI.bMatchHasBegun)
	{
		bDrawPL = PlayerBoxSizeY > 3 * YL;
		for (i = 0; i < PlayerCount; i++)
		{
			if (bDrawPL)
			{
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 1.5 * YL);
				Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
				Canvas.DrawText(PLText @ PRIArray[i].PacketLoss, True);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + 0.5 * YL);
			}
			else
			{
				if (bHaveHalfFont)
				{
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - YL);
					Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
				}
				else
				{
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
				}
			}
			if (PRIArray[i].bReadyToPlay)
			{
				Canvas.DrawText(ReadyText, True);
			}
			else
			{
				Canvas.DrawText(NotReadyText, True);
			}
		}
		Return;
	}
	if (Canvas.ClipX < 512)
	{
		PingText = "";
	}
	else
	{
		PingText = Default.PingText;
		bDrawFPH = PlayerBoxSizeY > 3 * YL;
		bDrawPL = PlayerBoxSizeY > 4 * YL;
	}
	for (i = 0; i < PlayerCount; i++)
	{
		if (!PRIArray[i].bAdmin && !PRIArray[i].bOutOfLives)
		{
			if (bDrawPL)
			{
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 1.9 * YL);
				Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.9 * YL);
				Canvas.DrawText(PLText @ PRIArray[i].PacketLoss, True);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + 0.1 * YL);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + 1.1 * YL);
				Canvas.DrawText(FormatTime(Max(0, FPHTime - PRIArray[i].StartTime)), True);
			}
			else
			{
				if (bDrawFPH)
				{
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 1.5 * YL);
					Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
					Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + 0.5 * YL);
					Canvas.DrawText(FormatTime(Max(0, FPHTime - PRIArray[i].StartTime)), True);
				}
				else
				{
					if (bHaveHalfFont)
					{
						Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - YL);
						Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
						Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
						Canvas.DrawText(FormatTime(Max(0, FPHTime - PRIArray[i].StartTime)), True);
					}
					else
					{
						Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
						Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[i].Ping), True);
					}
				}
			}
		}
	}
	if (OwnerOffset >= PlayerCount && !PRIArray[OwnerOffset].bAdmin && !PRIArray[OwnerOffset].bOutOfLives)
	{
		if (bDrawFPH)
		{
			Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 1.5 * YL);
			Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[OwnerOffset].Ping), True);
			Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
			Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + 0.5 * YL);
			Canvas.DrawText(FormatTime(Max(0, FPHTime - PRIArray[OwnerOffset].StartTime)), True);
		}
		else
		{
			if (bHaveHalfFont)
			{
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - YL);
				Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[OwnerOffset].Ping), True);
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
				Canvas.DrawText(FormatTime(Max(0, FPHTime - PRIArray[OwnerOffset].StartTime)), True);
			}
			else
			{
				Canvas.SetPos(NetXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL);
				Canvas.DrawText(PingText @ Min(999, 4 * PRIArray[OwnerOffset].Ping), True);
			}
		}
	}
	*/
}
