// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCTeamDeathMatch/HudCTeamDeathMatch.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "Engine/Canvas.h"

AHudCTeamDeathMatch::AHudCTeamDeathMatch(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	TeamSymbols.SetNum(2);
	TeamScoreBackGroundDisc.SetNum(2);
	TeamScoreBackGround.SetNum(2);
	ScoreTeam.SetNum(2);
	CarrierTextColor1 = FColor(0, 255, 255, 255);
	CarrierTextColor2 = FColor(0, 255, 0, 255);
	CarrierTextColor3 = FColor(200, 200, 200, 255);
	CNPosX = 0.01;
	CNPosY = 0.01;
	LinkEstablishedMessage = "LINK ESTABLISHED";
}

void AHudCTeamDeathMatch::DrawSpectatingHud(UCanvas* C)
{
	/*
	Super::DrawSpectatingHud(C);
	if (((PlayerOwner == nullptr) || (PlayerOwner.PlayerReplicationInfo == nullptr)) || (!PlayerOwner.PlayerReplicationInfo.bOnlySpectator))
	{
		return;
	}
	UpdateRankAndSpread(C);
	ShowTeamScorePassA(C);
	ShowTeamScorePassC(C);
	UpdateTeamHud();
	*/
}

void AHudCTeamDeathMatch::Tick(float DeltaTime)
{
	/*
	Super::Tick(DeltaTime);
	if (Links > 0)
	{
		TeamLinked = true;
	}
	else
	{
		TeamLinked = false;
	}
	*/
}

void AHudCTeamDeathMatch::showLinks()
{
}

void AHudCTeamDeathMatch::drawLinkText(UCanvas* C)
{
	/*
	Text = LinkEstablishedMessage;
	C.Font = LoadLevelActionFont();
	C.DrawColor = LevelActionFontColor;
	C.DrawColor = LevelActionFontColor;
	C.Style = 6;
	C.DrawScreenText(Text, 1, 0.81, 4);
	*/
}

void AHudCTeamDeathMatch::UpdateRankAndSpread(UCanvas* C)
{
}

void AHudCTeamDeathMatch::DrawTeamOverlay(UCanvas* C)
{
}

void AHudCTeamDeathMatch::DrawMyScore(UCanvas* C)
{
}

void AHudCTeamDeathMatch::DrawHudPassA(UCanvas* C)
{
	/*
	Super::DrawHudPassA(C);
	UpdateRankAndSpread(C);
	ShowTeamScorePassA(C);
	if (Links > 0)
	{
		DrawSpriteWidget(C, LinkIcon);
		DrawNumericWidget(C, totalLinks, DigitsBigPulse);
	}
	totalLinks.Value = Links;
	*/
}

void AHudCTeamDeathMatch::ShowTeamScorePassA(UCanvas* C)
{
	/*
	if (bShowPoints)
	{
		DrawSpriteWidget(C, TeamScoreBackGround[0]);
		DrawSpriteWidget(C, TeamScoreBackGround[1]);
		DrawSpriteWidget(C, TeamScoreBackGroundDisc[0]);
		DrawSpriteWidget(C, TeamScoreBackGroundDisc[1]);
		TeamScoreBackGround[0].Tints[TeamIndex] = HudColorBlack;
		TeamScoreBackGround[0].Tints[TeamIndex].A = 150;
		TeamScoreBackGround[1].Tints[TeamIndex] = HudColorBlack;
		TeamScoreBackGround[1].Tints[TeamIndex].A = 150;
		if (TeamSymbols[0].WidgetTexture != nullptr)
		{
			DrawSpriteWidget(C, TeamSymbols[0]);
		}
		if (TeamSymbols[1].WidgetTexture != nullptr)
		{
			DrawSpriteWidget(C, TeamSymbols[1]);
		}
		ShowVersusIcon(C);
		DrawNumericWidget(C, ScoreTeam[0], DigitsBig);
		DrawNumericWidget(C, ScoreTeam[1], DigitsBig);
	}
	*/
}

void AHudCTeamDeathMatch::ShowVersusIcon(UCanvas* C)
{
	//DrawSpriteWidget(C, VersusSymbol);
}

void AHudCTeamDeathMatch::ShowTeamScorePassC(UCanvas* C)
{
}

void AHudCTeamDeathMatch::TeamScoreOffset()
{
}

void AHudCTeamDeathMatch::DrawHudPassC(UCanvas* C)
{
	//Super::DrawHudPassC(C);
	ShowTeamScorePassC(C);
}

void AHudCTeamDeathMatch::UpdateTeamHud()
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	int32 i = 0;
	GRI = PlayerOwner.GameReplicationInfo;
	if (GRI == nullptr)
	{
		return;
	}
	for (i = 0; i < 2; i++)
	{
		if (GRI.Teams[i] == nullptr)
		{
		}
		TeamSymbols[i].Tints[i] = HudColorTeam[i];
		ScoreTeam[i].Value = FMath::Min(int(GRI.Teams[i].Score), 999);
		if (GRI.TeamSymbols[i] != nullptr)
		{
			TeamSymbols[i].WidgetTexture = GRI.TeamSymbols[i];
		}
	}
	*/
}

void AHudCTeamDeathMatch::UpdateHUD()
{
	UpdateTeamHud();
	showLinks();
	//Super::UpdateHUD();
}

bool AHudCTeamDeathMatch::CustomHUDColorAllowed()
{
	return false;
}
