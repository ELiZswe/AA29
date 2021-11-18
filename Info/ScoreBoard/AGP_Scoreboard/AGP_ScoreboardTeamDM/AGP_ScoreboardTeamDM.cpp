// All the original content belonged to the US Army


#include "AA29/Info/ScoreBoard/AGP_Scoreboard/AGP_ScoreboardTeamDM/AGP_ScoreboardTeamDM.h"

AAGP_ScoreboardTeamDM::AAGP_ScoreboardTeamDM()
{
	teamstring = "Team";
	teampos = 0.5;
	FFPos = 0.8;
	//_t2D = Texture'T_AA2_UI.HUD.hud_2d'
	//_tTrust(0) = Texture'T_AA2_UI.HUD.hud_score_bad'
	//_tTrust(1) = Texture'T_AA2_UI.HUD.hud_score_good'
	//_tTrust(2) = Texture'T_AA2_UI.HUD.hud_score_better'
	//_tTrust(3) = Texture'T_AA2_UI.HUD.hud_score_best'
	//_tGroup(1) = Texture'T_AA2_UI.HUD.hud_group_dev'
	//_tGroup(2) = Texture'T_AA2_UI.HUD.hud_group_army_dev'
	//_tGroup(3) = Texture'T_AA2_UI.HUD.hud_group_homelan'
	//_tGroup(4) = Texture'T_AA2_UI.HUD.hud_group_beta'
	//_tGroup(5) = Texture'T_AA2_UI.HUD.hud_group_army_active'
	//_tGroup(6) = Texture'T_AA2_UI.HUD.hud_group_army_reserve'
	//_tGroup(7) = Texture'T_AA2_UI.HUD.hud_group_supercomputer'
	//_tGroup(8) = Texture'T_AA2_UI.HUD.hud_group_army'
	//_tGroup(9) = Texture'T_AA2_UI.HUD.hud_group_navy'
	//_tGroup(10) = Texture'T_AA2_UI.HUD.hud_group_airforce'
	//_tGroup(11) = Texture'T_AA2_UI.HUD.hud_group_marine'
	//_tGroup(12) = Texture'T_AA2_UI.HUD.hud_group_army_retired'
	//_tGroup(23) = Texture'T_AA2_UI.HUD.hud_group_aacm'
	//_tGroup(24) = Texture'T_AA2_UI.HUD.hud_group_volunteer'
	//_tRanger = Texture'T_AA2_UI.HUD.hud_score_better'
	//tArmyBox = Texture'T_AA2_UI.HUD.ui_hud_border_nofill'
	//tBoxFill = Texture'T_AA2_UI.HUD.hud_goal_fill'
	ArmyTeamColor = FColor(195, 107, 0, 255);
	ArmyLeaderColor = FColor(255, 159, 91, 255);
	OpforTeamColor = FColor(16, 0, 245, 255);
	OpforLeaderColor = FColor(67, 0, 187, 255);
	DeadColor = FColor(125, 125, 125, 255);
	FFString = "ROE";
}



//const kIconSize = 10;
//const kPosTeam = 0.17;
//const kPosRanger = 0.13;
//const kPosFireTeam = 0.17;
//const kPosRank = 0.18;
//const kPosGroup = 0.11;
//const kPosTrust = 0.14;
//const kPos2D = 0.11;



int32 AAGP_ScoreboardTeamDM::GetTeamOrVirtualTeam()
{
	int32 TeamNum=0;
	/*
	TeamNum = PlayerOwner.PlayerReplicationInfo.Team.TeamIndex;
	if (TeamNum == 255)
	{
		TeamNum = PlayerOwner.PlayerReplicationInfo.DesiredTeam;
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
	/*
	local float XL;
	local float YL;
	local string teamstr;
	local GameReplicationInfo OwnerInfo;
	local int thescore;
	local int TeamNum;
	DrawHeader(Canvas);
	OwnerInfo = PlayerOwner.GameReplicationInfo;
	TeamNum = GetTeamOrVirtualTeam();
	if (AGP_TeamInfo(OwnerInfo.Teams[TeamNum]) != None)
	{
		thescore = AGP_TeamInfo(OwnerInfo.Teams[TeamNum]).teamScore;
	}
	else
	{
		thescore = OwnerInfo.Teams[TeamNum].Score;
	}
	teamstr = Level.TeamName[TeamNum] $ ":" @ thescore;
	if (OwnerInfo.RoundsPerMatch > 0)
	{
		teamstr = teamstr $ "/" $ OwnerInfo.RoundsPerMatch;
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
	if (AGP_TeamInfo(OwnerInfo.Teams[TeamNum]) != None)
	{
		thescore = AGP_TeamInfo(OwnerInfo.Teams[TeamNum]).teamScore;
	}
	else
	{
		thescore = OwnerInfo.Teams[TeamNum].Score;
	}
	teamstr = Level.TeamName[TeamNum] $ ":" @ thescore;
	if (OwnerInfo.RoundsPerMatch > 0)
	{
		teamstr = teamstr $ "/" $ OwnerInfo.RoundsPerMatch;
	}
	Canvas.StrLen(teamstr, XL, YL);
	Canvas.SetPos(Canvas.SizeX * 0.1 + 8, 0.5 * Canvas.SizeY + YL / 2);
	Canvas.DrawColor = OpforTeamColor;
	Canvas.DrawText(teamstr);
	*/
}
void AAGP_ScoreboardTeamDM::DrawCategoryHeaders(UCanvas* Canvas)
{
	/*
	local float offset;
	local float XL;
	local float YL;
	offset = Canvas.CurY;
	DrawCategoryHeaders(Canvas);
	Canvas.StrLen(FFString, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FFPos - XL / 2, offset);
	Canvas.DrawText(FFString);
	*/
}

FColor AAGP_ScoreboardTeamDM::DeterminePlayerColor(AAA2_PlayerState* PRI)
{
	/*
	local bool bLocalPlayer;
	local int TeamOwner;
	TeamOwner = GetTeamOrVirtualTeam();
	bLocalPlayer = PRI == PlayerOwner.PlayerReplicationInfo;
	if (bLocalPlayer)
	{
		Return GoldColor;
	}
	if (PRI.Team.TeamIndex == TeamOwner)
	{
		if (!PRI.isDead() || NoRealTeam())
		{
			Return ArmyTeamColor;
		}
		else
		{
			Return DeadColor;
		}
	}
	else
	{
		Return OpforTeamColor;
	}
	*/
	return LightCyanColor;
}

void AAGP_ScoreboardTeamDM::DrawBox(UCanvas* Canvas, float StartX, float StartY, float boxw, float boxh)
{
	/*
	local int oldstyle;
	local float gstartx;
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	gstartx = Canvas.SizeX - boxw / 2;
	Canvas.SetPos(gstartx, StartY);
	Canvas.DrawTile(Texture'Fade', boxw, boxh, 200, 0, 1, 1);
	Canvas.DrawColor = OwnerHUD.HUDColor;
	AGP_HUD(OwnerHUD).DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.Style = oldstyle;
	*/
}

void AAGP_ScoreboardTeamDM::DrawLine(UCanvas* Canvas, float StartX, float StartY, float boxw)
{
	/*
	local int oldstyle;
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	Canvas.DrawColor = OwnerHUD.HUDColor;
	AGP_HUD(OwnerHUD).DrawArmyLine(Canvas, StartX, StartY, boxw);
	Canvas.Style = oldstyle;
	*/
}

void AAGP_ScoreboardTeamDM::ShowScores(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	local float YOffset;
	local float YStart;
	local Font CanvasFont;
	local int i;
	local byte lastTeam;
	local float StartX;
	local float StartY;
	local float boxw;
	local float boxh;
	local float halfy;
	local int iNumPlayersVisible;
	local int iPlayerCount;
	_fFont = AGP_HUD(OwnerHUD).mmFrame.GetProperSizeFontPrivate(Canvas);
	if (_fFont == None)
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
	Canvas.DrawText(PlayerOwner.GameReplicationInfo.ServerName @ "-" @ Level.GetAddressURL() @ "- Round " $ PlayerOwner.GameReplicationInfo.RoundsPerMatch - PlayerOwner.GameReplicationInfo.RemainingRounds $ "/" $ PlayerOwner.GameReplicationInfo.RoundsPerMatch);
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
	/*
	local float XL;
	local float YL;
	local int oldstyle;
	local Object.Color PlayerColor;
	local int DrawGroup;
	local Texture DrawRank;
	local AGP_UI.UIHUDCompass Compass;
	DrawNameAndPing(Canvas, PRI, XOffset, YOffset);
	Canvas.DrawColor = DeterminePlayerColor(PRI);
	Canvas.TextSize(PRI.Score_ROE, XL, YL);
	Canvas.SetPos(Canvas.SizeX * FFPos - XL, YOffset);
	Canvas.DrawText(PRI.Score_ROE, False);
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
	AGP_HUD(OwnerHUD).SetHUDActor();
	Compass = UIHUDCompass(AGP_HUD(OwnerHUD).GetHUDControl(5));
	AGP_HUD(OwnerHUD).FreeHUDActor();
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
	/*
	local int TeamOwner;
	TeamOwner = GetTeamOrVirtualTeam();
	if (PRI1 == PRI2)
	{
		Return 0;
	}
	if (PRI1.Team.TeamIndex != 255 && PRI2.Team.TeamIndex == 255)
	{
		Return 1;
	}
	if (PRI1.Team.TeamIndex == 255 && PRI2.Team.TeamIndex != 255)
	{
		Return - 1;
	}
	if (PRI1.Team.TeamIndex == TeamOwner && PRI2.Team.TeamIndex != TeamOwner)
	{
		Return 1;
	}
	if (PRI1.Team.TeamIndex != TeamOwner && PRI2.Team.TeamIndex == TeamOwner)
	{
		Return - 1;
	}
	TempPRI = PRI1.GetSquadLeader();
	if (PRI1 == TempPRI)
	{
		Return 1;
	}
	if (PRI2 == TempPRI)
	{
		Return - 1;
	}
	if (PRI1.isTeamLeader() && !PRI2.isTeamLeader())
	{
		Return 1;
	}
	if (!PRI1.isTeamLeader() && PRI2.isTeamLeader())
	{
		Return - 1;
	}
	if (PRI1.Score_Total != PRI2.Score_Total)
	{
		Return PRI1.Score_Total - PRI2.Score_Total;
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
	return 0;    //FAKE   /ELiZ
}