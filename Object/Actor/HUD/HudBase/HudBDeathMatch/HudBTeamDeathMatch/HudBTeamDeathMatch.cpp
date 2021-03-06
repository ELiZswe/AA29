// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBTeamDeathMatch/HudBTeamDeathMatch.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "Engine/Canvas.h"

AHudBTeamDeathMatch::AHudBTeamDeathMatch(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	TeamSymbols.SetNum(2);
	RTeamHud.SetNum(3);
	LTeamHud.SetNum(3);
	ScoreTeam.SetNum(2);
	CarrierTextColor1 = FColor(0, 255, 255, 255);
	CarrierTextColor2 = FColor(0, 255, 0, 255);
	CarrierTextColor3 = FColor(200, 200, 200, 255);
	CNPosX = 0.01;
	CNPosY = 0.01;
	LinkEstablishedMessage = "LINK ESTABLISHED";
}

void AHudBTeamDeathMatch::DrawSpectatingHud(UCanvas* C)
{
	/*
	Super::DrawSpectatingHud(C);
	if (((PlayerOwner == nullptr) || (PlayerOwner.PlayerReplicationInfo == nullptr)) || (!PlayerOwner.PlayerReplicationInfo.bOnlySpectator))
	{
		return;
	}
	*/
	UpdateRankAndSpread(C);
	ShowTeamScorePassA(C);
	ShowTeamScorePassC(C);
	UpdateTeamHud();
}

void AHudBTeamDeathMatch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Links > 0)
	{
		//TeamLinked = true;
		//pulseWidget(DeltaTime, 255, 0, RHud2[3], TeamIndex, 1, 2000);
	}
	else
	{
		//TeamLinked = false;
		//RHud2[3].Tints[TeamIndex].A = 255;
	}
}

void AHudBTeamDeathMatch::showLinks()
{
}

void AHudBTeamDeathMatch::drawLinkText(UCanvas* C)
{
	Text = LinkEstablishedMessage;
	/*
	C.Font = LoadLevelActionFont();
	C.DrawColor = LevelActionFontColor;
	C.DrawColor = LevelActionFontColor;
	C.Style = 6;
	C.DrawScreenText(Text, 1, 0.81, 4);
	*/
}

void AHudBTeamDeathMatch::UpdateRankAndSpread(UCanvas* C)
{
}

void AHudBTeamDeathMatch::DrawHudPassA(UCanvas* C)
{
	//Super::DrawHudPassA(C);
	UpdateRankAndSpread(C);
	ShowTeamScorePassA(C);
	if (bShowWeaponInfo)
	{
		if (Links > 0)
		{
			//DrawNumericWidget(C, totalLinks, DigitsBig);
		}
		totalLinks.Value = Links;
	}
}

void AHudBTeamDeathMatch::ShowTeamScorePassA(UCanvas* C)
{
	if (bShowPoints)
	{
		/*
		DrawSpriteWidget(C, LTeamHud[2]);
		DrawSpriteWidget(C, LTeamHud[1]);
		DrawSpriteWidget(C, LTeamHud[0]);
		DrawSpriteWidget(C, RTeamHud[2]);
		DrawSpriteWidget(C, RTeamHud[1]);
		DrawSpriteWidget(C, RTeamHud[0]);
		*/
	}
}

void AHudBTeamDeathMatch::ShowTeamScorePassC(UCanvas* C)
{
	if (bShowPoints)
	{
		/*
		if (TeamSymbols[0].WidgetTexture != nullptr)
		{
			DrawSpriteWidget(C, TeamSymbols[0]);
		}
		if (TeamSymbols[1].WidgetTexture != nullptr)
		{
			DrawSpriteWidget(C, TeamSymbols[1]);
		}
		TeamScoreOffset();
		DrawNumericWidget(C, ScoreTeam[0], DigitsBig);
		DrawNumericWidget(C, ScoreTeam[1], DigitsBig);
		*/
	}
}

void AHudBTeamDeathMatch::TeamScoreOffset()
{
	ScoreTeam[1].OffsetX = 80;
	if (ScoreTeam[1].Value < 0)
	{
		(ScoreTeam[1].OffsetX += 90);
	}
	/*
	if (FMath::Abs(float(ScoreTeam[1].Value)) > 9)
	{
		(ScoreTeam[1].OffsetX += 90);
	}
	*/
}

void AHudBTeamDeathMatch::ShowPersonalScore(UCanvas* C)
{
	//DrawNumericWidget(C, Score, DigitsBig);
}

void AHudBTeamDeathMatch::DrawHudPassC(UCanvas* C)
{
	//Super::DrawHudPassC(C);
	if (Links > 0)
	{
		drawLinkText(C);
	}
	if (bShowPoints)
	{
		ShowPersonalScore(C);
	}
	ShowTeamScorePassC(C);
}

void AHudBTeamDeathMatch::UpdateTeamHud()
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	int32 i = 0;
	Score.Value = FMath::Min(CurScore, 999);
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
		ScoreTeam[i].Value = FMath::Min(int(GRI.Teams[i].Score), 999);
		if (GRI.TeamSymbols[i] != nullptr)
		{
			TeamSymbols[i].WidgetTexture = GRI.TeamSymbols[i];
		}
	}
	*/
}

void AHudBTeamDeathMatch::UpdateHUD()
{
	UpdateTeamHud();
	showLinks();
	//Super::UpdateHUD();
}
