// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoardDeathMatch/ScoreBoardTeamDeathMatch/ScoreBoardTeamDeathMatch.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/AA2_PlayerState.h"

AScoreBoardTeamDeathMatch::AScoreBoardTeamDeathMatch()
{
	TeamBoxMaterial.SetNum(2);
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
	AAA2_PlayerState* PRI = nullptr;
	AAA2_PlayerState* OwnerPRI = nullptr;
	int32 i = 0;
	int32 FontReduction = 0;
	int32 HeaderOffsetY = 0;
	int32 HeadFoot = 0;
	int32 PlayerBoxSizeY = 0;
	int32 BoxSpaceY = 0;
	float XL = 0;
	float YL = 0;
	float IconSize = 0;
	float MaxScaling = 0;
	float MessageFoot = 0;
	int32 BluePlayerCount = 0;
	int32 RedPlayerCount = 0;
	int32 RedOwnerOffset = 0;
	int32 BlueOwnerOffset = 0;
	int32 MaxPlayerCount = 0;
	TArray<AAA2_PlayerState*> RedPRI = {};
	TArray<AAA2_PlayerState*> BluePRI = {};
	RedPRI.SetNum(32);
	BluePRI.SetNum(32);
	UFont* MainFont = nullptr;
	//OwnerPRI = Cast<APlayerController>(GetOwner())->PlayerReplicationInfo;
	RedOwnerOffset = -1;
	BlueOwnerOffset = -1;
	for (i = 0; i < GRI->PRIArray.Num(); i++)
	{
		PRI = GRI->PRIArray[i];
		if ((PRI->Team != nullptr) && ((!PRI->IsSpectator()) || PRI->bWaitingPlayer))
		{
			if (PRI->Team->TeamIndex == 0)
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
	MaxPlayerCount = FMath::Max(RedPlayerCount, BluePlayerCount);
	//Canvas->Font = HudClass.GetMediumFontFor(Canvas);
	//Canvas->StrLen("Test", XL, YL);
	IconSize = FMath::Max((2.0f * YL), ((64 * Canvas->ClipX) / float(1024)));
	BoxSpaceY = int((0.25 * YL));
	if (HaveHalfFont(Canvas, FontReduction))
	{
		PlayerBoxSizeY = int((2.125 * YL));
	}
	else
	{
		PlayerBoxSizeY = int((1.75 * YL));
	}
	HeadFoot = int(((4 * YL) + IconSize));
	MessageFoot = (1.5 * float(HeadFoot));
	/*
	if (float(MaxPlayerCount) > ((Canvas->ClipY - (1.5 * float(HeadFoot))) / float((PlayerBoxSizeY + BoxSpaceY))))
	{
		BoxSpaceY = int((0.125 * YL));
		if (float(MaxPlayerCount) > ((Canvas->ClipY - (1.5 * float(HeadFoot))) / float((PlayerBoxSizeY + BoxSpaceY))))
		{
			if (float(MaxPlayerCount) > ((Canvas->ClipY - (1.5 * float(HeadFoot))) / float((PlayerBoxSizeY + BoxSpaceY))))
			{
				FontReduction++;
				//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
				//Canvas->StrLen("Test", XL, YL);
				BoxSpaceY = int((0.125 * YL));
				if (HaveHalfFont(Canvas, FontReduction))
				{
					PlayerBoxSizeY = int((2.125 * YL));
				}
				else
				{
					PlayerBoxSizeY = int((1.75 * YL));
				}
				HeadFoot = int(((4 * YL) + IconSize));
				if (float(MaxPlayerCount) > ((Canvas->ClipY - (1.5 * float(HeadFoot))) / float((PlayerBoxSizeY + BoxSpaceY))))
				{
					FontReduction++;
					//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
					//Canvas->StrLen("Test", XL, YL);
					BoxSpaceY = int((0.125 * YL));
					if (HaveHalfFont(Canvas, FontReduction))
					{
						PlayerBoxSizeY = int((2.125 * YL));
					}
					else
					{
						PlayerBoxSizeY = int((1.75 * YL));
					}
					HeadFoot = int(((4 * YL) + IconSize));
					if ((Canvas->ClipY >= float(600)) && (float(MaxPlayerCount) > ((Canvas->ClipY - float(HeadFoot)) / float((PlayerBoxSizeY + BoxSpaceY)))))
					{
						FontReduction++;
						//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
						//Canvas->StrLen("Test", XL, YL);
						BoxSpaceY = int((0.125 * YL));
						if (HaveHalfFont(Canvas, FontReduction))
						{
							PlayerBoxSizeY = int((2.125 * YL));
						}
						else
						{
							PlayerBoxSizeY = int((1.75 * YL));
						}
						HeadFoot = int(((4 * YL) + IconSize));
						if (float(MaxPlayerCount) > ((Canvas->ClipY - float(HeadFoot)) / float((PlayerBoxSizeY + BoxSpaceY))))
						{
							FontReduction++;
							//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
							//Canvas->StrLen("Test", XL, YL);
							BoxSpaceY = int((0.125 * YL));
							if (HaveHalfFont(Canvas, FontReduction))
							{
								PlayerBoxSizeY = int((2.125 * YL));
							}
							else
							{
								PlayerBoxSizeY = int((1.75 * YL));
							}
							HeadFoot = int(((4 * YL) + IconSize));
						}
					}
				}
			}
		}
	}
	*/
	//MaxPlayerCount = FMath::Min(MaxPlayerCount, int((1 + ((Canvas->ClipY - float(HeadFoot)) / float((PlayerBoxSizeY + BoxSpaceY))))));
	if (FontReduction > 2)
	{
		MaxScaling = 3;
	}
	else
	{
		MaxScaling = 2.125;
	}
	//PlayerBoxSizeY = int(FClamp((((1 + (Canvas->ClipY - (0.67 * MessageFoot))) / float(MaxPlayerCount)) - float(BoxSpaceY)), float(PlayerBoxSizeY), (MaxScaling * YL)));
	//bDisplayMessages = (float(MaxPlayerCount) < ((Canvas->ClipY - MessageFoot) / float((PlayerBoxSizeY + BoxSpaceY))));
	RedPlayerCount = FMath::Min(RedPlayerCount, MaxPlayerCount);
	BluePlayerCount = FMath::Min(BluePlayerCount, MaxPlayerCount);
	if (RedOwnerOffset >= RedPlayerCount)
	{
		RedPlayerCount -= 1;
	}
	if (BlueOwnerOffset >= BluePlayerCount)
	{
		BluePlayerCount -= 1;
	}
	HeaderOffsetY = int(((1.5 * YL) + IconSize));
	//Canvas->Style = ERenderStyle.STY_Normal;
	DrawTitle(Canvas, float(HeaderOffsetY), (float((MaxPlayerCount + 1)) * float((PlayerBoxSizeY + BoxSpaceY))), float(PlayerBoxSizeY));
	if (GRI != nullptr)
	{
		//MainFont = Canvas->Font;
		for (i = 0; i < 32; i++)
		{
			PRIArray[i] = RedPRI[i];
		}
		DrawTeam(0, RedPlayerCount, RedOwnerOffset, Canvas, FontReduction, BoxSpaceY, PlayerBoxSizeY, HeaderOffsetY);
		//Canvas->Font = MainFont;
		for (i = 0; i < 32; i++)
		{
			PRIArray[i] = BluePRI[i];
		}
		DrawTeam(1, BluePlayerCount, BlueOwnerOffset, Canvas, FontReduction, BoxSpaceY, PlayerBoxSizeY, HeaderOffsetY);
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		DrawMatchID(Canvas, FontReduction);
	}
}

void AScoreBoardTeamDeathMatch::DrawTeam(int32 TeamNum, int32 PlayerCount, int32 OwnerOffset, UCanvas* Canvas, int32 FontReduction, int32 BoxSpaceY, int32 PlayerBoxSizeY, int32 HeaderOffsetY)
{
	int32 i = 0;
	int32 OwnerPos = 0;
	int32 NetXPos = 0;
	int32 NameXPos = 0;
	int32 BoxTextOffsetY = 0;
	int32 ScoreXPos = 0;
	int32 ScoreYPos = 0;
	int32 BoxXPos = 0;
	int32 BoxWidth = 0;
	int32 LineCount = 0;
	int32 NameY = 0;
	float XL = 0;
	float YL = 0;
	float IconScale = 0;
	float ScoreBackScale = 0;
	float ScoreYL = 0;
	float MaxNamePos = 0;
	float LongestNameLength = 0;
	TArray<FString> PlayerName = {};
	PlayerName.SetNum(32);
	FString LongestName = "";
	UFont* MainFont = nullptr;
	UFont* ReducedFont = nullptr;
	bool bHaveHalfFont = false;
	bool bNameFontReduction = false;
	int32 SymbolUSize = 0;
	int32 SymbolVSize = 0;
	int32 otherTeam = 0;
	int32 LastLine = 0;
	BoxWidth = int((0.47 * Canvas->ClipX));
	BoxXPos = int((0.5 * ((0.5 * Canvas->ClipX) - float(BoxWidth))));
	BoxWidth = int(((0.5 * Canvas->ClipX) - float((2 * BoxXPos))));
	BoxXPos = int((float(BoxXPos) + ((float(TeamNum) * 0.5) * Canvas->ClipX)));
	NameXPos = int((float(BoxXPos) + (0.05 * float(BoxWidth))));
	ScoreXPos = int((float(BoxXPos) + (0.55 * float(BoxWidth))));
	NetXPos = int((float(BoxXPos) + (0.76 * float(BoxWidth))));
	bHaveHalfFont = HaveHalfFont(Canvas, FontReduction);
	//Canvas->Style = ERenderStyle.STY_Alpha;
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	//Canvas->SetPos(float(BoxXPos), float(HeaderOffsetY));
	//Canvas->DrawTileStretched(TeamBoxMaterial[TeamNum], float(BoxWidth), float((PlayerCount * (PlayerBoxSizeY + BoxSpaceY))));
	IconScale = (Canvas->ClipX / float(4096));
	ScoreBackScale = (Canvas->ClipX / float(1024));
	if (GRI->TeamSymbols[TeamNum] != nullptr)
	{
		//SymbolUSize = GRI->TeamSymbols[TeamNum].USize;
		//SymbolVSize = GRI->TeamSymbols[TeamNum].VSize;
	}
	else
	{
		SymbolUSize = 256;
		SymbolVSize = 256;
	}
	ScoreYPos = int(((float(HeaderOffsetY) - (float(SymbolVSize) * IconScale)) - float(BoxSpaceY)));
	//Canvas->DrawColor = (0.75 * HudClass.Default.WhiteColor);
	//Canvas->SetPos(float(BoxXPos), float((ScoreYPos - BoxSpaceY)));
	//Canvas->Style = ERenderStyle.STY_Normal;
	Canvas->DrawColor = TeamColors[TeamNum];
	//Canvas->SetPos((((0.25 + (0.5 * float(TeamNum))) * Canvas->ClipX) - (float((SymbolUSize + 32)) * IconScale)), float(ScoreYPos));
	if (GRI->TeamSymbols[TeamNum] != nullptr)
	{
		//Canvas->DrawIcon(GRI->TeamSymbols[TeamNum], IconScale);
	}
	//MainFont = Canvas->Font;
	//Canvas->Font = HudClass.LargerFontThan(MainFont);
	//Canvas->StrLen("TEST", XL, ScoreYL);
	if (ScoreYPos == 0)
	{
		ScoreYPos = int((float(HeaderOffsetY) - ScoreYL));
	}
	else
	{
		ScoreYPos = int(((float(ScoreYPos) + ((0.5 * float(SymbolVSize)) * IconScale)) - (0.5 * ScoreYL)));
	}
	//Canvas->SetPos((((0.25 + (0.5 * float(TeamNum))) * Canvas->ClipX) + (float(32) * IconScale)), float(ScoreYPos));
	//Canvas->Font = MainFont;
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	IconScale = (Canvas->ClipX / float(1024));
	if (PlayerCount <= 0)
	{
		return;
	}
	if (TeamNum == 0)
	{
		//Canvas->DrawColor = HudClass.Default.RedColor;
	}
	else
	{
		//Canvas->DrawColor = HudClass.Default.BlueColor;
	}
	if (OwnerOffset >= PlayerCount)
	{
		LastLine = (PlayerCount + 1);
	}
	else
	{
		LastLine = PlayerCount;
	}
	for (i = 1; i < LastLine; i++)
	{
		//Canvas->SetPos(float(NameXPos), (float((HeaderOffsetY + ((PlayerBoxSizeY + BoxSpaceY) * i))) - (0.5 * float(BoxSpaceY))));
	}
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	MaxNamePos = (0.95 * float((ScoreXPos - NameXPos)));
	for (i = 0; i < PlayerCount; i++)
	{
		PlayerName[i] = GRI->PRIArray[i]->PlayerName;
		//Canvas->StrLen(PlayerName[i], XL, YL);
		if (XL > FMath::Max(LongestNameLength, MaxNamePos))
		{
			LongestName = PlayerName[i];
			LongestNameLength = XL;
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerName[OwnerOffset] = GRI->PRIArray[OwnerOffset]->PlayerName;
		//Canvas->StrLen(PlayerName[OwnerOffset], XL, YL);
		if (XL > FMath::Max(LongestNameLength, MaxNamePos))
		{
			LongestName = PlayerName[i];
			LongestNameLength = XL;
		}
	}
	if (LongestNameLength > 0)
	{
		bNameFontReduction = true;
		//Canvas->Font = GetSmallerFontFor(Canvas, (FontReduction + 1));
		//Canvas->StrLen(LongestName, XL, YL);
		if (XL > MaxNamePos)
		{
			//Canvas->Font = GetSmallerFontFor(Canvas, (FontReduction + 2));
			//Canvas->StrLen(LongestName, XL, YL);
			if (XL > MaxNamePos)
			{
				//Canvas->Font = GetSmallerFontFor(Canvas, (FontReduction + 3));
			}
		}
		//ReducedFont = Canvas->Font;
	}
	for (i = 0; i < PlayerCount; i++)
	{
		PlayerName[i] = PRIArray[i]->PlayerName;
		//Canvas->StrLen(PlayerName[i], XL, YL);
		if (XL > MaxNamePos)
		{
			//PlayerName[i] = PlayerName[i].Left(int(((MaxNamePos / XL) * float(PlayerName[i].Len()))));
		}
	}
	if (OwnerOffset >= PlayerCount)
	{
		PlayerName[OwnerOffset] = PRIArray[OwnerOffset]->PlayerName;
		//Canvas->StrLen(PlayerName[OwnerOffset], XL, YL);
		if (XL > MaxNamePos)
		{
			//PlayerName[OwnerOffset] = PlayerName[OwnerOffset].Left(int(((MaxNamePos / XL) * float(PlayerName[OwnerOffset].Len()))));
		}
	}
	if (Canvas->ClipX < float(512))
	{
		NameY = int((0.5 * YL));
	}
	else
	{
		if (!bHaveHalfFont)
		{
			NameY = int((0.125 * YL));
		}
	}
	//Canvas->Style = ERenderStyle.STY_Normal;
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	//Canvas->SetPos((0.5 * Canvas->ClipX), float((HeaderOffsetY + 4)));
	BoxTextOffsetY = int(((float(HeaderOffsetY) + (0.5 * float(PlayerBoxSizeY))) - (0.5 * YL)));
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	if (OwnerOffset == -1)
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if (i != OwnerOffset)
			{
				//Canvas->SetPos(float(NameXPos), ((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)));
				//Canvas->DrawText(PlayerName[i], true);
			}
		}
	}
	else
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if (i != OwnerOffset)
			{
				//Canvas->SetPos(float(NameXPos), ((((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)) - (0.5 * YL)) + float(NameY)));
				//Canvas->DrawText(PlayerName[i], true);
			}
		}
	}
	if (bNameFontReduction)
	{
		//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
	}
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	for (i = 0; i < PlayerCount; i++)
	{
		if (i != OwnerOffset)
		{
			//Canvas->SetPos(float(ScoreXPos), ((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)));
			if (PRIArray[i]->bOutOfLives)
			{
				//Canvas->DrawText(OutText, true);
			}
		}
	}
	if (OwnerOffset >= 0)
	{
		if (OwnerOffset >= PlayerCount)
		{
			OwnerPos = (((PlayerBoxSizeY + BoxSpaceY) * PlayerCount) + BoxTextOffsetY);
			//Canvas->Style = ERenderStyle.STY_Alpha;
			//Canvas->SetPos(float(BoxXPos), float((HeaderOffsetY + ((PlayerBoxSizeY + BoxSpaceY) * PlayerCount))));
			//Canvas->DrawTileStretched(TeamBoxMaterial[TeamNum], float(BoxWidth), float(PlayerBoxSizeY));
			//Canvas->Style = ERenderStyle.STY_Normal;
			if (PRIArray[OwnerOffset]->HasFlag != nullptr)
			{
				//Canvas->DrawColor = HudClass.Default.WhiteColor;
				//Canvas->SetPos((float(NameXPos) - (float(48) * IconScale)), (float(OwnerPos) - (float(16) * IconScale)));
				//Canvas->DrawTile(FlagIcon, (64 * IconScale), (32 * IconScale), 0, 0, 256, 128);
			}
		}
		else
		{
			OwnerPos = (((PlayerBoxSizeY + BoxSpaceY) * OwnerOffset) + BoxTextOffsetY);
		}
		//Canvas->DrawColor = HudClass.Default.GoldColor;
		//Canvas->SetPos(float(NameXPos), ((float(OwnerPos) - (0.5 * YL)) + float(NameY)));
		if (bNameFontReduction)
		{
			//Canvas->Font = ReducedFont;
		}
		//Canvas->DrawText(PlayerName[OwnerOffset], true);
		if (bNameFontReduction)
		{
			//Canvas->Font = GetSmallerFontFor(Canvas, FontReduction);
		}
		//Canvas->SetPos(float(ScoreXPos), float(OwnerPos));
		if (PRIArray[OwnerOffset]->bOutOfLives)
		{
			//Canvas->DrawText(OutText, true);
		}
	}
	//Canvas->DrawColor = HudClass.Default.WhiteColor;
	if (TeamNum == 0)
	{
		otherTeam = 1;
	}
	/*
	if ((GRI->FlagState[otherTeam] != 0) && (GRI->FlagState[otherTeam] != 3))
	{
		for (i = 0; i < PlayerCount; i++)
		{
			if ((PRIArray[i]->HasFlag != nullptr) || (PRIArray[i] == GRI->FlagHolder[TeamNum]))
			{
				//Canvas->SetPos((float(NameXPos) - (float(48) * IconScale)), (((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)) - (float(16) * IconScale)));
				//Canvas->DrawTile(FlagIcon, (64 * IconScale), (32 * IconScale), 0, 0, 256, 128);
			}
		}
	}
	*/
	if ((OwnerOffset >= 0) && (Canvas->ClipX >= float(512)))
	{
		BoxTextOffsetY = int(((float(HeaderOffsetY) + (0.5 * float(PlayerBoxSizeY))) + float(NameY)));
		//Canvas->DrawColor = HudClass.Default.CyanColor;
		if (FontReduction > 3)
		{
			bHaveHalfFont = false;
		}
		if (Canvas->ClipX >= float(1280))
		{
			//Canvas->Font = GetSmallFontFor(int(Canvas->ClipX), (FontReduction + 2));
		}
		else
		{
			//Canvas->Font = GetSmallFontFor(int(Canvas->ClipX), (FontReduction + 1));
		}
		//Canvas->StrLen("Test", XL, YL);
		for (i = 0; i < PlayerCount; i++)
		{
			LineCount = 0;
			if (bHaveHalfFont || (!PRIArray[i]->bBot))
			{
				//Canvas->SetPos(float(NameXPos), (((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)) + (float(LineCount) * YL)));
				//Canvas->DrawText(PRIArray[i].GetLocationName(), true);
			}
		}
		if (OwnerOffset >= PlayerCount)
		{
			//Canvas->SetPos(float(NameXPos), ((float((PlayerBoxSizeY + BoxSpaceY)) * float(i)) + float(BoxTextOffsetY)));
			//Canvas->DrawText(PRIArray[OwnerOffset].GetLocationName(), true);
		}
	}
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		return;
	}
	//Canvas->Font = MainFont;
	//Canvas->StrLen("Test", XL, YL);
	BoxTextOffsetY = int(((float(HeaderOffsetY) + (0.5 * float(PlayerBoxSizeY))) - (0.5 * YL)));
	DrawNetInfo(Canvas, FontReduction, HeaderOffsetY, PlayerBoxSizeY, BoxSpaceY, BoxTextOffsetY, OwnerOffset, PlayerCount, NetXPos);
}
