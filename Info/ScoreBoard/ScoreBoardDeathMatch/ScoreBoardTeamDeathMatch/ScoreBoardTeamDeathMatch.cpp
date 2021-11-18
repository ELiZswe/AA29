// All the original content belonged to the US Army


#include "AA29/Info/ScoreBoard/ScoreBoardDeathMatch/ScoreBoardTeamDeathMatch/ScoreBoardTeamDeathMatch.h"

AScoreBoardTeamDeathMatch::AScoreBoardTeamDeathMatch()
{
	TeamColors.SetNum(2);
	TeamColors[0] = FColor(0, 0, 255, 255);
	TeamColors[1] = FColor(255, 0, 0, 255);
	FragLimit = "SCORE LIMIT:";
}

void AScoreBoardTeamDeathMatch::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}

void AScoreBoardTeamDeathMatch::UpdateScoreBoard(UCanvas* Canvas)
{
	/*
	local PlayerReplicationInfo PRI;
	local PlayerReplicationInfo OwnerPRI;
	local int i;
	local int FontReduction;
	local int HeaderOffsetY;
	local int HeadFoot;
	local int PlayerBoxSizeY;
	local int BoxSpaceY;
	local float XL;
	local float YL;
	local float IconSize;
	local float MaxScaling;
	local float MessageFoot;
	local int BluePlayerCount;
	local int RedPlayerCount;
	local int RedOwnerOffset;
	local int BlueOwnerOffset;
	local int MaxPlayerCount;
	local PlayerReplicationInfo RedPRI;
	local PlayerReplicationInfo BluePRI;
	local Font MainFont;
	OwnerPRI = PlayerController(Owner).PlayerReplicationInfo;
	RedOwnerOffset = -1;
	BlueOwnerOffset = -1;
	for (i = 0; i < GRI.PRIArray.Length; i++)
	{
		PRI = GRI.PRIArray[i];
		if (PRI.Team != None && !PRI.bIsSpectator || PRI.bWaitingPlayer)
		{
			if (PRI.Team.TeamIndex == 0)
			{
				if (RedPlayerCount < 32)
				{
					RedPRI[RedPlayerCount] = PRI;
					if (PRI == OwnerPRI)
					{
						RedOwnerOffset = RedPlayerCount;
					}
					RedPlayerCount++;
				}
			}
			else
			{
				if (BluePlayerCount < 32)
				{
					BluePRI[BluePlayerCount] = PRI;
					if (PRI == OwnerPRI)
					{
						BlueOwnerOffset = BluePlayerCount;
					}
					BluePlayerCount++;
				}
			}
		}
	}
	MaxPlayerCount = Max(RedPlayerCount, BluePlayerCount);
	Canvas.Font = HudClass.GetMediumFontFor(Canvas);
	Canvas.StrLen("Test", XL, YL);
	IconSize = FMax(2 * YL, 64 * Canvas.ClipX / 1024);
	BoxSpaceY = 0.25 * YL;
	if (HaveHalfFont(Canvas, FontReduction))
	{
		PlayerBoxSizeY = 2.125 * YL;
	}
	else
	{
		PlayerBoxSizeY = 1.75 * YL;
	}
	HeadFoot = 4 * YL + IconSize;
	MessageFoot = 1.5 * HeadFoot;
	if (MaxPlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
	{
		BoxSpaceY = 0.125 * YL;
		if (MaxPlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
		{
			if (MaxPlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
			{
				FontReduction++;
				Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
				Canvas.StrLen("Test", XL, YL);
				BoxSpaceY = 0.125 * YL;
				if (HaveHalfFont(Canvas, FontReduction))
				{
					PlayerBoxSizeY = 2.125 * YL;
				}
				else
				{
					PlayerBoxSizeY = 1.75 * YL;
				}
				HeadFoot = 4 * YL + IconSize;
				if (MaxPlayerCount > Canvas.ClipY - 1.5 * HeadFoot / PlayerBoxSizeY + BoxSpaceY)
				{
					FontReduction++;
					Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
					Canvas.StrLen("Test", XL, YL);
					BoxSpaceY = 0.125 * YL;
					if (HaveHalfFont(Canvas, FontReduction))
					{
						PlayerBoxSizeY = 2.125 * YL;
					}
					else
					{
						PlayerBoxSizeY = 1.75 * YL;
					}
					HeadFoot = 4 * YL + IconSize;
					if (Canvas.ClipY >= 600 && MaxPlayerCount > Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY)
					{
						FontReduction++;
						Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
						Canvas.StrLen("Test", XL, YL);
						BoxSpaceY = 0.125 * YL;
						if (HaveHalfFont(Canvas, FontReduction))
						{
							PlayerBoxSizeY = 2.125 * YL;
						}
						else
						{
							PlayerBoxSizeY = 1.75 * YL;
						}
						HeadFoot = 4 * YL + IconSize;
						if (MaxPlayerCount > Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY)
						{
							FontReduction++;
							Canvas.Font = GetSmallerFontFor(Canvas, FontReduction);
							Canvas.StrLen("Test", XL, YL);
							BoxSpaceY = 0.125 * YL;
							if (HaveHalfFont(Canvas, FontReduction))
							{
								PlayerBoxSizeY = 2.125 * YL;
							}
							else
							{
								PlayerBoxSizeY = 1.75 * YL;
							}
							HeadFoot = 4 * YL + IconSize;
						}
					}
				}
			}
		}
	}
	MaxPlayerCount = Min(MaxPlayerCount, 1 + Canvas.ClipY - HeadFoot / PlayerBoxSizeY + BoxSpaceY);
	if (FontReduction > 2)
	{
		MaxScaling = 3;
	}
	else
	{
		MaxScaling = 2.125;
	}
	PlayerBoxSizeY = FClamp(1 + Canvas.ClipY - 0.67 * MessageFoot / MaxPlayerCount - BoxSpaceY, PlayerBoxSizeY, MaxScaling * YL);
	bDisplayMessages = MaxPlayerCount < Canvas.ClipY - MessageFoot / PlayerBoxSizeY + BoxSpaceY;
	RedPlayerCount = Min(RedPlayerCount, MaxPlayerCount);
	BluePlayerCount = Min(BluePlayerCount, MaxPlayerCount);
	if (RedOwnerOffset >= RedPlayerCount)
	{
		RedPlayerCount -= 1;
	}
	if (BlueOwnerOffset >= BluePlayerCount)
	{
		BluePlayerCount -= 1;
	}
	HeaderOffsetY = 1.5 * YL + IconSize;
	Canvas.Style = 1;
	DrawTitle(Canvas, HeaderOffsetY, MaxPlayerCount + 1 * PlayerBoxSizeY + BoxSpaceY, PlayerBoxSizeY);
	if (GRI != None)
	{
		MainFont = Canvas.Font;
		for (i = 0; i < 32; i++)
		{
			PRIArray[i] = RedPRI[i];
		}
		DrawTeam(0, RedPlayerCount, RedOwnerOffset, Canvas, FontReduction, BoxSpaceY, PlayerBoxSizeY, HeaderOffsetY);
		Canvas.Font = MainFont;
		for (i = 0; i < 32; i++)
		{
			PRIArray[i] = BluePRI[i];
		}
		DrawTeam(1, BluePlayerCount, BlueOwnerOffset, Canvas, FontReduction, BoxSpaceY, PlayerBoxSizeY, HeaderOffsetY);
	}
	if (Level.NetMode != 0)
	{
		DrawMatchID(Canvas, FontReduction);
	}
	*/
}

void AScoreBoardTeamDeathMatch::DrawTeam(int32 TeamNum, int32 PlayerCount, int32 OwnerOffset, UCanvas* Canvas, int32 FontReduction, int32 BoxSpaceY, int32 PlayerBoxSizeY, int32 HeaderOffsetY)
{
	/*
	local int i;
	local int OwnerPos;
	local int NetXPos;
	local int NameXPos;
	local int BoxTextOffsetY;
	local int ScoreXPos;
	local int ScoreYPos;
	local int BoxXPos;
	local int BoxWidth;
	local int LineCount;
	local int NameY;
	local float XL;
	local float YL;
	local float IconScale;
	local float ScoreBackScale;
	local float ScoreYL;
	local float MaxNamePos;
	local float LongestNameLength;
	local string PlayerName;
	local string LongestName;
	local Font MainFont;
	local Font ReducedFont;
	local bool bHaveHalfFont;
	local bool bNameFontReduction;
	local int SymbolUSize;
	local int SymbolVSize;
	local int otherTeam;
	local int LastLine;
	BoxWidth = 0.47 * Canvas.ClipX;
	BoxXPos = 0.5 * 0.5 * Canvas.ClipX - BoxWidth;
	BoxWidth = 0.5 * Canvas.ClipX - 2 * BoxXPos;
	BoxXPos = BoxXPos + TeamNum * 0.5 * Canvas.ClipX;
	NameXPos = BoxXPos + 0.05 * BoxWidth;
	ScoreXPos = BoxXPos + 0.55 * BoxWidth;
	NetXPos = BoxXPos + 0.76 * BoxWidth;
	bHaveHalfFont = HaveHalfFont(Canvas, FontReduction);
	Canvas.Style = 6;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	Canvas.SetPos(BoxXPos, HeaderOffsetY);
	Canvas.DrawTileStretched(TeamBoxMaterial[TeamNum], BoxWidth, PlayerCount * PlayerBoxSizeY + BoxSpaceY);
	IconScale = Canvas.ClipX / 4096;
	ScoreBackScale = Canvas.ClipX / 1024;
	if (GRI.TeamSymbols[TeamNum] != None)
	{
		SymbolUSize = GRI.TeamSymbols[TeamNum].USize;
		SymbolVSize = GRI.TeamSymbols[TeamNum].VSize;
	}
	else
	{
		SymbolUSize = 256;
		SymbolVSize = 256;
	}
	ScoreYPos = HeaderOffsetY - SymbolVSize * IconScale - BoxSpaceY;
	Canvas.DrawColor = 0.75 * HudClass.Default.WhiteColor;
	Canvas.SetPos(BoxXPos, ScoreYPos - BoxSpaceY);
	Canvas.Style = 1;
	Canvas.DrawColor = TeamColors[TeamNum];
	Canvas.SetPos(0.25 + 0.5 * TeamNum * Canvas.ClipX - SymbolUSize + 32 * IconScale, ScoreYPos);
	if (GRI.TeamSymbols[TeamNum] != None)
	{
		Canvas.DrawIcon(GRI.TeamSymbols[TeamNum], IconScale);
	}
	MainFont = Canvas.Font;
	Canvas.Font = HudClass.LargerFontThan(MainFont);
	Canvas.StrLen("TEST", XL, ScoreYL);
	if (ScoreYPos == 0)
	{
		ScoreYPos = HeaderOffsetY - ScoreYL;
	}
	else
	{
		ScoreYPos = ScoreYPos + 0.5 * SymbolVSize * IconScale - 0.5 * ScoreYL;
	}
	Canvas.SetPos(0.25 + 0.5 * TeamNum * Canvas.ClipX + 32 * IconScale, ScoreYPos);
	Canvas.Font = MainFont;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	IconScale = Canvas.ClipX / 1024;
	if (PlayerCount <= 0)
	{
		Return;
	}
	if (TeamNum == 0)
	{
		Canvas.DrawColor = HudClass.Default.RedColor;
	}
	else
	{
		Canvas.DrawColor = HudClass.Default.BlueColor;
	}
	if (OwnerOffset >= PlayerCount)
	{
		LastLine = PlayerCount + 1;
	}
	else
	{
		LastLine = PlayerCount;
	}
	for (i = 1; i < LastLine; i++)
	{
		Canvas.SetPos(NameXPos, HeaderOffsetY + PlayerBoxSizeY + BoxSpaceY * i - 0.5 * BoxSpaceY);
	}
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	MaxNamePos = 0.95 * ScoreXPos - NameXPos;
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
		PlayerName[i] = PRIArray[i].PlayerName;
		Canvas.StrLen(PlayerName[i], XL, YL);
		if (XL > MaxNamePos)
		{
			PlayerName[i] = Left(PlayerName[i], MaxNamePos / XL * Len(PlayerName[i]));
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerName[OwnerOffset] = PRIArray[OwnerOffset].PlayerName;
		Canvas.StrLen(PlayerName[OwnerOffset], XL, YL);
		if (XL > MaxNamePos)
		{
			PlayerName[OwnerOffset] = Left(PlayerName[OwnerOffset], MaxNamePos / XL * Len(PlayerName[OwnerOffset]));
		}
	}
	if (Canvas.ClipX < 512)
	{
		NameY = 0.5 * YL;
	}
	else
	{
		if (!bHaveHalfFont)
		{
			NameY = 0.125 * YL;
		}
	}
	Canvas.Style = 1;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	Canvas.SetPos(0.5 * Canvas.ClipX, HeaderOffsetY + 4);
	BoxTextOffsetY = HeaderOffsetY + 0.5 * PlayerBoxSizeY - 0.5 * YL;
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	if (OwnerOffset == -1)
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if (i != OwnerOffset)
			{
				Canvas.SetPos(NameXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
				Canvas.DrawText(PlayerName[i], True);
			}
		}
	}
	else
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if (i != OwnerOffset)
			{
				Canvas.SetPos(NameXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 0.5 * YL + NameY);
				Canvas.DrawText(PlayerName[i], True);
			}
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
			if (PRIArray[i].bOutOfLives)
			{
				Canvas.DrawText(OutText, True);
			}
		}
	}
	if (OwnerOffset >= 0)
	{
		if (OwnerOffset >= PlayerCount)
		{
			OwnerPos = PlayerBoxSizeY + BoxSpaceY * PlayerCount + BoxTextOffsetY;
			Canvas.Style = 6;
			Canvas.SetPos(BoxXPos, HeaderOffsetY + PlayerBoxSizeY + BoxSpaceY * PlayerCount);
			Canvas.DrawTileStretched(TeamBoxMaterial[TeamNum], BoxWidth, PlayerBoxSizeY);
			Canvas.Style = 1;
			if (PRIArray[OwnerOffset].HasFlag != None)
			{
				Canvas.DrawColor = HudClass.Default.WhiteColor;
				Canvas.SetPos(NameXPos - 48 * IconScale, OwnerPos - 16 * IconScale);
				Canvas.DrawTile(FlagIcon, 64 * IconScale, 32 * IconScale, 0, 0, 256, 128);
			}
		}
		else
		{
			OwnerPos = PlayerBoxSizeY + BoxSpaceY * OwnerOffset + BoxTextOffsetY;
		}
		Canvas.DrawColor = HudClass.Default.GoldColor;
		Canvas.SetPos(NameXPos, OwnerPos - 0.5 * YL + NameY);
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
		if (PRIArray[OwnerOffset].bOutOfLives)
		{
			Canvas.DrawText(OutText, True);
		}
	}
	Canvas.DrawColor = HudClass.Default.WhiteColor;
	if (TeamNum == 0)
	{
		otherTeam = 1;
	}
	if (GRI.FlagState[otherTeam] != 0 && GRI.FlagState[otherTeam] != 3)
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if (PRIArray[i].HasFlag != None || PRIArray[i] == GRI.FlagHolder[TeamNum])
			{
				Canvas.SetPos(NameXPos - 48 * IconScale, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY - 16 * IconScale);
				Canvas.DrawTile(FlagIcon, 64 * IconScale, 32 * IconScale, 0, 0, 256, 128);
			}
		}
	}
	if (OwnerOffset >= 0 && Canvas.ClipX >= 512)
	{
		BoxTextOffsetY = HeaderOffsetY + 0.5 * PlayerBoxSizeY + NameY;
		Canvas.DrawColor = HudClass.Default.CyanColor;
		if (FontReduction > 3)
		{
			bHaveHalfFont = False;
		}
		if (Canvas.ClipX >= 1280)
		{
			Canvas.Font = GetSmallFontFor(Canvas.ClipX, FontReduction + 2);
		}
		else
		{
			Canvas.Font = GetSmallFontFor(Canvas.ClipX, FontReduction + 1);
		}
		Canvas.StrLen("Test", XL, YL);
		for (i = 0; i < PlayerCount; i++)
		{
			LineCount = 0;
			if (bHaveHalfFont || !PRIArray[i].bBot)
			{
				Canvas.SetPos(NameXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY + LineCount * YL);
				Canvas.DrawText(PRIArray[i].GetLocationName(), True);
			}
		}
		if (OwnerOffset >= PlayerCount)
		{
			Canvas.SetPos(NameXPos, PlayerBoxSizeY + BoxSpaceY * i + BoxTextOffsetY);
			Canvas.DrawText(PRIArray[OwnerOffset].GetLocationName(), True);
		}
	}
	if (Level.NetMode == 0)
	{
		Return;
	}
	Canvas.Font = MainFont;
	Canvas.StrLen("Test", XL, YL);
	BoxTextOffsetY = HeaderOffsetY + 0.5 * PlayerBoxSizeY - 0.5 * YL;
	DrawNetInfo(Canvas, FontReduction, HeaderOffsetY, PlayerBoxSizeY, BoxSpaceY, BoxTextOffsetY, OwnerOffset, PlayerCount, NetXPos);
	*/
}