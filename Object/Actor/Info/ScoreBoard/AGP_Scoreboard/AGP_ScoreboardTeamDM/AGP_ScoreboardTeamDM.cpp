// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ScoreBoard/AGP_Scoreboard/AGP_ScoreboardTeamDM/AGP_ScoreboardTeamDM.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "Engine/Canvas.h"

AAGP_ScoreboardTeamDM::AAGP_ScoreboardTeamDM()
{
	_tTrust.SetNum(4);
	teamstring = "Team";
	teampos = 0.5;
	FFPos = 0.8;
	_t2D = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_2d_Mat.hud_2d_Mat'"), NULL, LOAD_None, NULL);
	_tTrust = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_score_bad_Mat.hud_score_bad_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_score_good_Mat.hud_score_good_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_score_better_Mat.hud_score_better_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_score_best_Mat.hud_score_best_Mat'"), NULL, LOAD_None, NULL)
	};
	_tGroup.SetNum(25);
	_tGroup[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_dev_Mat.hud_group_dev_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_dev_Mat.hud_group_army_dev_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_homelan_Mat.hud_group_homelan_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_beta_Mat.hud_group_beta_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[5] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_active_Mat.hud_group_army_active_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[6] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_reserve_Mat.hud_group_army_reserve_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[7] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_supercomputer_Mat.hud_group_supercomputer_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[8] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_Mat.hud_group_army_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[9] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_navy_Mat.hud_group_navy_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[10] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_airforce_Mat.hud_group_airforce_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[11] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_marine_Mat.hud_group_marine_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[12] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_army_retired_Mat.hud_group_army_retired_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[23] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_aacm_Mat.hud_group_aacm_Mat'"), NULL, LOAD_None, NULL);
	_tGroup[24] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_volunteer_Mat.hud_group_volunteer_Mat'"), NULL, LOAD_None, NULL);
	_tRanger = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_score_better_Mat.hud_score_better_Mat'"), NULL, LOAD_None, NULL);
	tArmyBox = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_border_nofill_Mat.ui_hud_border_nofill_Mat'"), NULL, LOAD_None, NULL);
	tBoxFill = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill_Mat.hud_goal_fill_Mat'"), NULL, LOAD_None, NULL);
	ArmyTeamColor = FColor(195, 107, 0, 255);
	ArmyLeaderColor = FColor(255, 159, 91, 255);
	OpforTeamColor = FColor(16, 0, 245, 255);
	OpforLeaderColor = FColor(67, 0, 187, 255);
	DeadColor = FColor(125, 125, 125, 255);
	FFString = "ROE";
}

int32 AAGP_ScoreboardTeamDM::GetTeamOrVirtualTeam()
{
	int32 TeamNum=0;
	/*
	TeamNum = PlayerOwner->PlayerReplicationInfo->Team->TeamIndex;
	if (TeamNum == 255)
	{
		TeamNum = PlayerOwner->PlayerReplicationInfo->DesiredTeam;
		if (TeamNum == 255)
		{
			TeamNum = 0;
		}
	}
	*/
	return TeamNum;
}

bool AAGP_ScoreboardTeamDM::NoRealTeam()
{
	/*
	if (PlayerOwner.PlayerReplicationInfo.Team.TeamIndex == 255 && PlayerOwner.PlayerReplicationInfo.DesiredTeam == 255)
	{
		return true;
	}
	*/
	return false;
}

void AAGP_ScoreboardTeamDM::DrawHeader(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	FString teamstr = "";
	AGameReplicationInfo* OwnerInfo = nullptr;
	int32 thescore = 0;
	int32 TeamNum = 0;
	/*
	DrawHeader(Canvas);
	OwnerInfo = PlayerOwner.GameReplicationInfo;
	TeamNum = GetTeamOrVirtualTeam();
	if (Cast<AAGP_TeamInfo>(OwnerInfo.Teams[TeamNum]) != nullptr)
	{
		thescore = Cast<AGP_TeamInfo>(OwnerInfo.Teams[TeamNum]).teamScore;
	}
	else
	{
		thescore = OwnerInfo.Teams[TeamNum].Score;
	}
	teamstr = Level.TeamName[TeamNum] + ":" @ thescore;
	if (OwnerInfo.RoundsPerMatch > 0)
	{
		teamstr = teamstr + "/" + OwnerInfo.RoundsPerMatch;
	}
	Canvas.StrLen(teamstr, XL, YL);
	Canvas.SetPos(Canvas.SizeX * 0.1 + 8, 0.1 * Canvas.SizeY + YL / 2);
	Canvas.DrawColor = ArmyTeamColor;
	Canvas.DrawText(teamstr);
	if (TeamNum == 0)
	{
		TeamNum = 1;
	}
	else
	{
		TeamNum = 0;
	}
	if (Cast<AAGP_TeamInfo>(OwnerInfo.Teams[TeamNum]) != nullptr)
	{
		thescore = Cast<AGP_TeamInfo>(OwnerInfo.Teams[TeamNum]).teamScore;
	}
	else
	{
		thescore = OwnerInfo.Teams[TeamNum].Score;
	}
	teamstr = Level.TeamName[TeamNum] + ":" @ thescore;
	if (OwnerInfo.RoundsPerMatch > 0)
	{
		teamstr = teamstr + "/" + OwnerInfo.RoundsPerMatch;
	}
	Canvas.StrLen(teamstr, XL, YL);
	Canvas.SetPos(Canvas.SizeX * 0.1 + 8, 0.5 * Canvas.SizeY + YL / 2);
	Canvas.DrawColor = OpforTeamColor;
	Canvas.DrawText(teamstr);
	*/
}
void AAGP_ScoreboardTeamDM::DrawCategoryHeaders(UCanvas* Canvas)
{
	float offset = 0;
	float XL = 0;
	float YL = 0;
	/*
	offset = Canvas.CurY;
	DrawCategoryHeaders(Canvas);
	Canvas.StrLen(FFString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FFPos - XL / 2, offset);
	Canvas.DrawText(FFString);
	*/
}

FColor AAGP_ScoreboardTeamDM::DeterminePlayerColor(AAA2_PlayerState* PRI)
{
	bool bLocalPlayer = false;
	int32 TeamOwner = 0;
	TeamOwner = GetTeamOrVirtualTeam();
	/*
	bLocalPlayer = PRI == PlayerOwner.PlayerReplicationInfo;
	*/
	if (bLocalPlayer)
	{
		return GoldColor;
	}
	if (PRI->Team->TeamIndex == TeamOwner)
	{
		if (!PRI->isDead() || NoRealTeam())
		{
			return ArmyTeamColor;
		}
		else
		{
			return DeadColor;
		}
	}
	else
	{
		return OpforTeamColor;
	}
	return LightCyanColor;
}

void AAGP_ScoreboardTeamDM::DrawBox(UCanvas* Canvas, float StartX, float StartY, float boxw, float boxh)
{
	int32 oldstyle = 0;
	float gstartx = 0;
	/*
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	gstartx = Canvas.SizeX - boxw / 2;
	Canvas.SetPos(gstartx, StartY);
	Canvas.DrawTile(Texture'Fade', boxw, boxh, 200, 0, 1, 1);
	Canvas.DrawColor = OwnerHUD.HUDColor;
	Cast<AAGP_HUD>(OwnerHUD).DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.Style = oldstyle;
	*/
}

void AAGP_ScoreboardTeamDM::DrawLine(UCanvas* Canvas, float StartX, float StartY, float boxw)
{
	int32 oldstyle = 0;
	/*
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	Canvas.DrawColor = OwnerHUD.HUDColor;
	Cast<AAGP_HUD>(OwnerHUD).DrawArmyLine(Canvas, StartX, StartY, boxw);
	Canvas.Style = oldstyle;
	*/
}

void AAGP_ScoreboardTeamDM::ShowScores(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	float YOffset = 0;
	float YStart = 0;
	UFont* CanvasFont = nullptr;
	int32 i = 0;
	uint8 lastTeam = 0;
	float StartX = 0;
	float StartY = 0;
	float boxw = 0;
	float boxh = 0;
	float halfy = 0;
	int32 iNumPlayersVisible = 0;
	int32 iPlayerCount = 0;
	/*
	_fFont = Cast<AAGP_HUD>(OwnerHUD).mmFrame.GetProperSizeFontPrivate(Canvas);
	if (_fFont == nullptr)
	{
		_fFont = OwnerHUD.SmallFont;
	}
	Canvas.Font = _fFont;
	Canvas.StrLen("TEST", XL, YL);
	StartX = Canvas.SizeX * 0.1;
	StartY = Canvas.SizeY * 0.1;
	boxw = Canvas.SizeX * 0.8;
	boxh = Canvas.SizeY * 0.8;
	halfy = Canvas.SizeY * 0.5;
	DrawBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.Style = 1;
	Canvas.SetPos(StartX, StartY - YL);
	Canvas.DrawText(PlayerOwner.GameReplicationInfo.ServerName @ "-" @ Level.GetAddressURL() @ "- Round " + PlayerOwner.GameReplicationInfo.RoundsPerMatch - PlayerOwner.GameReplicationInfo.RemainingRounds + "/" + PlayerOwner.GameReplicationInfo.RoundsPerMatch);
	Canvas.SetPos(0, 0);
	DrawHeader(Canvas);
	UpdatePlayerList();
	CanvasFont = Canvas.Font;
	Canvas.SetPos(0, StartY + YL / 2);
	DrawCategoryHeaders(Canvas);
	DrawLine(Canvas, StartX, StartY + YL * 2, boxw);
	DrawLine(Canvas, StartX, halfy, boxw);
	Canvas.SetPos(0, halfy + YL / 2);
	DrawCategoryHeaders(Canvas);
	DrawLine(Canvas, StartX, halfy + YL * 2, boxw);
	YStart = Canvas.CurY;
	YOffset = YStart;
	Canvas.SetPos(0, 0);
	lastTeam = GetTeamOrVirtualTeam();
	YOffset = StartY + YL * 3;
	iNumPlayersVisible = halfy - StartY + YL * 2 - YL * 2 / YL;
	iPlayerCount = 0;
	for (i = 0; i < PlayerCount; i++)
	{
		if (Ordered[i].Team.TeamIndex == 255)
		{
		}
		if (lastTeam != Ordered[i].Team.TeamIndex)
		{
			YOffset = halfy + YL * 3;
			iPlayerCount = 0;
		}
		if (iPlayerCount < iNumPlayersVisible)
		{
			if (Ordered[i].bReadyToPlay && !Ordered[i].isSpectator())
			{
				lastTeam = Ordered[i].Team.TeamIndex;
				DrawNameAndPing(Canvas, Ordered[i], 0, YOffset);
				YOffset += YL;
				iPlayerCount++;
			}
		}
	}
	Canvas.DrawColor = WhiteColor;
	Canvas.Font = CanvasFont;
	DrawTrailer(Canvas);
	Canvas.DrawColor = WhiteColor;
	Canvas.Font = CanvasFont;
	*/
}

void AAGP_ScoreboardTeamDM::DrawNameAndPing(UCanvas* Canvas, AAA2_PlayerState* PRI, float XOffset, float YOffset)
{
	float XL = 0;
	float YL = 0;
	int32 oldstyle = 0;
	FColor PlayerColor = FColor(0,0,0,0);
	int32 DrawGroup = 0;
	UMaterialInstance* DrawRank = nullptr;
	UUIHUDCompass* Compass = nullptr;
	/*
	DrawNameAndPing(Canvas, PRI, XOffset, YOffset);
	Canvas.DrawColor = DeterminePlayerColor(PRI);
	Canvas.TextSize(PRI.Score_ROE, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FFPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_ROE, false);
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	if (PRI.HasGroupIcon())
	{
		DrawGroup = PRI.GetGroup();
		PlayerColor = Canvas.DrawColor;
		Canvas.DrawColor = WhiteColor;
		Canvas.SetPos(Canvas.ClipX * 0.11, YOffset + YL * 0.05);
		Canvas.DrawTile(_tGroup[DrawGroup], YL * 0.9, YL * 0.9, 0, 0, 32, 32);
		Canvas.DrawColor = PlayerColor;
	}
	Cast<AAGP_HUD>(OwnerHUD).SetHUDActor();
	Compass = UIHUDCompass(Cast<AAGP_HUD>(OwnerHUD).GetHUDControl(5));
	Cast<AAGP_HUD>(OwnerHUD).FreeHUDActor();
	if (PRI.Team == PlayerOwner.PlayerReplicationInfo.Team)
	{
		if (PRI.FT != 255)
		{
			Canvas.SetPos(Canvas.ClipX * 0.17, YOffset + YL / 4);
			Canvas.DrawTile(Compass._tFT[PRI.FT], YL * 0.5, YL * 0.5, 0, 0, 32, 32);
		}
		if (PRI.IsSquadLeader())
		{
			DrawRank = Compass._tTeamSSG;
		}
		else
		{
			if (PRI.isTeamLeader())
			{
				DrawRank = Compass._tTeamSGT;
			}
			else
			{
				DrawRank = Compass._tTeamPVT;
			}
		}
		Canvas.SetPos(Canvas.ClipX * 0.18, YOffset + YL * 0.05);
		Canvas.DrawTile(DrawRank, YL * 0.9, YL * 0.9, 0, 0, 64, 64);
	}
	if (PRI.GetHonor() > 0)
	{
		Canvas.TextSize(PRI.GetHonor(), XL, YL);
		Canvas.SetPos(Canvas.ClipX * 0.14 - XL / 2, YOffset);
		Canvas.DrawText(PRI.GetHonor());
	}
	Canvas.Style = oldstyle;
	*/
}

int32 AAGP_ScoreboardTeamDM::CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2)
{
	AAA2_PlayerState* TempPRI = nullptr;
	int32 TeamOwner = 0;
	TeamOwner = GetTeamOrVirtualTeam();
	if (PRI1 == PRI2)
	{
		return 0;
	}
	if (PRI1->Team->TeamIndex != 255 && PRI2->Team->TeamIndex == 255)
	{
		return 1;
	}
	if (PRI1->Team->TeamIndex == 255 && PRI2->Team->TeamIndex != 255)
	{
		return - 1;
	}
	if (PRI1->Team->TeamIndex == TeamOwner && PRI2->Team->TeamIndex != TeamOwner)
	{
		return 1;
	}
	if (PRI1->Team->TeamIndex != TeamOwner && PRI2->Team->TeamIndex == TeamOwner)
	{
		return - 1;
	}
	TempPRI = PRI1->GetSquadLeader();
	if (PRI1 == TempPRI)
	{
		return 1;
	}
	if (PRI2 == TempPRI)
	{
		return - 1;
	}
	if (PRI1->isTeamLeader() && !PRI2->isTeamLeader())
	{
		return 1;
	}
	if (!PRI1->isTeamLeader() && PRI2->isTeamLeader())
	{
		return - 1;
	}
	if (PRI1->Score_Total != PRI2->Score_Total)
	{
		return PRI1->Score_Total - PRI2->Score_Total;
	}
	if (PRI1->PlayerName <= PRI2->PlayerName)
	{
		return 1;
	}
	else
	{
		return - 1;
	}
}
