// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_TeamSummary.h"

UAAScoreboard_TeamSummary::UAAScoreboard_TeamSummary()
{
	mTeamId = 255;
	TeamIndex = 255;
	bScores = true;
	MaxVisibleTeamEntries = 13;
	ColumnHeadings = { "Class", "Honor", "Player Name", "Score", "Goals", "Leader", "Enemy", "KIA", "ROE", "Ping" };
	InitColumnPerc = { 0.17, 0.07, 0.23, 0.09, 0.09, 0.1, 0.08, 0.05, 0.05, 0.07 };
	SortColumn = -1;
	bVisibleWhenEmpty = true;
	//__OnDrawItem__Delegate = "AAScoreboard_TeamSummary.InternalOnDrawItem";
	StyleName = "ListBox";
	RenderWeight = 1;
	bAcceptsInput = false;
	bNeverFocus = true;
	//__OnPreDraw__Delegate = "AAScoreboard_TeamSummary.InternalOnPreDraw";
	//__OnRendered__Delegate = "AAScoreboard_TeamSummary.InternalOnRendered";
}


void UAAScoreboard_TeamSummary::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	//GRI = PlayerOwner().GameReplicationInfo;
	//Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	SetTeamSizeForDisplay();
}

void UAAScoreboard_TeamSummary::Initialize()
{
	if (bInitialized)
	{
		return;
	}
	Super::Initialize();
}

bool UAAScoreboard_TeamSummary::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	local int32 fPlayerCount;
	local int32 fPlayerIndex;
	local int32 fTeamCount;
	local AAA2_PlayerState* fPlayerInfo;
	bInitialized = False;
	GRI = PlayerOwner().GameReplicationInfo;
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	ItemCount -= ItemCount - mFireTeamSize;
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)
	{
		if (Team != None)
		{
			if (TeamIndex != Team.TeamIndex)
			{
				TeamIndex = Team.TeamIndex;
				SetGroupSize(0, Team.FTCount[0]);
				SetGroupSize(1, Team.FTCount[1]);
				SetGroupSize(2, Team.FTCount[2]);
				SetGroupSize(3, Team.FTCount[3]);
				SetGroupSize(4, Team.FTCount[4]);
				SetGroupSize(5, 1);
			}
		}
		mFireTeamSize = ItemCount;
		fTeamCount = 0;
		mTeamPRIArray.remove(0, mTeamPRIArray.Length);
		if (GRI == None)
		{
			GRI = PlayerOwner().GameReplicationInfo;
		}
		if (GRI != None)
		{
			fPlayerCount = GRI.PRIArray.Length;
			for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
			{
				fPlayerInfo = GRI.PRIArray[fPlayerIndex];
				if (fPlayerInfo != None && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
				{
					if (fPlayerInfo.Team != None && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || !fPlayerInfo.bIsSpectator || HumanController(PlayerOwner()).TournamentIsTournament())
					{
						fTeamCount++;
						mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
					}
				}
			}
		}
		ItemCount += fTeamCount;
	}
	else
	{
		SetTeamSizeForDisplay();
	}
	*/
	return true;
}

void UAAScoreboard_TeamSummary::InternalOnRendered(UCanvas* Canvas)
{
	/*
	OnRendered(Canvas);
	mTeamPRIArray.remove(0, mTeamPRIArray.Length);
	*/
}

void UAAScoreboard_TeamSummary::SetTeamSizeForDisplay()
{
	/*
	local int32 fTeamCount;
	fTeamCount = GetTeamCount(mTeamId);
	ItemCount = fTeamCount;
	*/
}

float UAAScoreboard_TeamSummary::GetTeamCount(int32 iTeamID)
{
	int32 fTeamCount=0;
	/*
	local int32 fPlayerCount;
	local int32 fPlayerIndex;
	
	local AAA2_PlayerState* fPlayerInfo;
	fTeamCount = 0;
	mTeamPRIArray.remove(0, mTeamPRIArray.Length);
	if (GRI == None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI != None)
	{
		fPlayerCount = GRI.PRIArray.Length;
		for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
		{
			fPlayerInfo = GRI.PRIArray[fPlayerIndex];
			if (fPlayerInfo != None && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
			{
				if (fPlayerInfo.Team != None && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || !fPlayerInfo.bIsSpectator || HumanController(PlayerOwner()).TournamentIsTournament())
				{
					fTeamCount++;
					mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
				}
			}
		}
	}
	*/
	return fTeamCount;
}

bool UAAScoreboard_TeamSummary::ShouldDrawItem(AAA2_PlayerState* fPlayerInfo)
{
	/*
	if (fPlayerInfo == None)
	{
		Return False;
	}
	Return fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || HumanController(PlayerOwner()).TournamentIsTournament() || HumanController(PlayerOwner()) != None && HumanController(PlayerOwner()).bTournamentServer;
	*/
	return true;      //FAKE   /ELiZ
}

void UAAScoreboard_TeamSummary::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local int32 FTUnitID;
	local int32 FTIndex;
	local int32 FTUnitID2;
	local int32 FTIndex2;
	local int32 j;
	local int32 TempInt;
	local float IconX;
	local float IconY;
	local float CellLeft;
	local float CellWidth;
	local bool bSpecialColor;
	local bool mUnassigned;
	local bool bAssignedSlot;
	local bool bAssignedSlotFT;
	local bool bShowUnassigned;
	local string tempString;
	local AAA2_PlayerState* fPlayerInfo;
	local GUI.eMenuState PlayerState;
	local Object.Color OldColors;
	local Object.Color MyColor;
	local AAA2_PlayerState* PRI;
	bShowUnassigned = False;
	bAssignedSlot = False;
	bAssignedSlotFT = False;
	fPlayerInfo = None;
	if (i < mFireTeamSize)
	{
		mUnassigned = False;
	}
	if (!IsSeparator(i))
	{
		tempString = "";
		TempInt = 0;
		bSpecialColor = False;
		if (mTeamPRIArray.Length == 0)
		{
			Return;
		}
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && !PlayerOwner().PlayerReplicationInfo.bIsSpectator)
		{
			for (j = 0; j < mTeamPRIArray.Length; j++)
			{
				if (mTeamPRIArray[j] == None || mTeamPRIArray[j].bPendingDelete || mTeamPRIArray[j].bDeleteMe)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					Return;
				}
				FTUnitID = AGP_TeamInfo(mTeamPRIArray[j].Team).GetPlayerUnitID(mTeamPRIArray[j]);
				if (FTUnitID == -1)
				{
					bShowUnassigned = True;
				}
			}
			if (i >= mFireTeamSize)
			{
				if (mTeamPRIArray.Length <= i - mFireTeamSize)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					Return;
				}
				fPlayerInfo = mTeamPRIArray[i - mFireTeamSize];
				if (fPlayerInfo == None || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					Return;
				}
				FTUnitID2 = AGP_TeamInfo(mTeamPRIArray[i - mFireTeamSize].Team).GetPlayerUnitID(mTeamPRIArray[i - mFireTeamSize]);
				FTIndex2 = AGP_TeamInfo(mTeamPRIArray[i - mFireTeamSize].Team).GetPlayerIndex(mTeamPRIArray[i - mFireTeamSize]);
				for (j = 0; j < mFireTeamSize; j++)
				{
					FTUnitID = GetGroup(j);
					FTIndex = GetPositionInGroup(FTUnitID2, j);
					if (FTUnitID2 == FTUnitID && FTIndex2 == FTIndex)
					{
						bAssignedSlot = True;
					}
				}
			}
			else
			{
				FTUnitID2 = GetGroup(i);
				FTIndex2 = GetPositionInGroup(FTUnitID2, i);
				for (j = 0; j < mTeamPRIArray.Length; j++)
				{
					if (mTeamPRIArray[j] == None || mTeamPRIArray[j].bPendingDelete || mTeamPRIArray[j].bDeleteMe)
					{
						mTeamPRIArray.remove(0, mTeamPRIArray.Length);
						ItemCount = 0;
						Return;
					}
					FTUnitID = AGP_TeamInfo(mTeamPRIArray[j].Team).GetPlayerUnitID(mTeamPRIArray[j]);
					FTIndex = AGP_TeamInfo(mTeamPRIArray[j].Team).GetPlayerIndex(mTeamPRIArray[j]);
					if (FTUnitID2 == FTUnitID && FTIndex2 == FTIndex)
					{
						fPlayerInfo = mTeamPRIArray[j];
						bAssignedSlotFT = True;
					}
				}
			}
		}
		else
		{
			if (i < mTeamPRIArray.Length)
			{
				fPlayerInfo = mTeamPRIArray[i];
				if (fPlayerInfo == None || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					Return;
				}
			}
		}
		PRI = PlayerOwner().PlayerReplicationInfo;
		if (fPlayerInfo != None)
		{
			PlayerState = GetPlayerState(fPlayerInfo);
			if (PRI != None && fPlayerInfo == PRI)
			{
				if (PRI.isDead())
				{
					MyColor.R = 149;
					MyColor.G = 135;
					MyColor.B = 83;
					MyColor.A = 255;
					bSpecialColor = True;
				}
				else
				{
					MyColor.R = 240;
					MyColor.G = 196;
					MyColor.B = 27;
					MyColor.A = 255;
					bSpecialColor = True;
				}
			}
			else
			{
				if (!PRI.isDead())
				{
					MyColor.R = 166;
					MyColor.G = 202;
					MyColor.B = 156;
					MyColor.A = 255;
					bSpecialColor = True;
				}
			}
			if (HumanController(PlayerOwner()) != None && HumanController(PlayerOwner()).bTournamentServer)
			{
				if (fPlayerInfo.bAdmin)
				{
					MyColor.R = 255;
					MyColor.G = 0;
					MyColor.B = 0;
					MyColor.A = 255;
					bSpecialColor = True;
				}
				else
				{
					if (fPlayerInfo.bTournamentTeamCaptain)
					{
						if (PRI.isDead())
						{
							MyColor.R = 56;
							MyColor.G = 56;
							MyColor.B = 99;
							MyColor.A = 255;
							bSpecialColor = True;
						}
						else
						{
							MyColor.R = 82;
							MyColor.G = 82;
							MyColor.B = 159;
							MyColor.A = 255;
							bSpecialColor = True;
						}
					}
				}
			}
		}
		if (bSpecialColor)
		{
			for (j = 0; j < 5; j++)
			{
				OldColors[j] = Style.FontColors[j];
				Style.FontColors[j] = MyColor;
			}
		}
		IconX = X + CellLeft;
		IconY = Y + ItemHeight - ItemHeight / 2;
		Canvas.SetPos(IconX, IconY);
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && i < mFireTeamSize && GetGroup(i) != 5 && !PlayerOwner().PlayerReplicationInfo.bIsSpectator)
		{
			if (GetPositionInGroup(GetGroup(i), i) == 0 || mFireTeamId != GetGroup(i))
			{
				Canvas.SetDrawColor(255, 255, 255, 50);
				Canvas.Style = 6;
				if (GetGroup(i) - 1 >= 0)
				{
					Canvas.DrawTile(tFT[GetGroup(i) - 1], ItemHeight * 2, ItemHeight * 2, 0, 0, 32, 32);
				}
				Canvas.SetDrawColor(251, 248, 229, 255);
				mFireTeamId = GetGroup(i);
			}
			GetCellLeftWidth(0, CellLeft, CellWidth);
			DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 1, True);
		}
		if (GetGroup(i) == 5 && GetPositionInGroup(GetGroup(i), i) == 0 && bShowUnassigned && PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)
		{
			GetCellLeftWidth(0, CellLeft, CellWidth);
			Style.DrawText(Canvas, 2, CellLeft, Y, CellWidth, H, 0, Chr(13) $ "Unassigned:" $ Chr(13), FontScale);
		}
		if (fPlayerInfo != None && ShouldDrawItem(fPlayerInfo) && !bAssignedSlot && !mUnassigned)
		{
			if (i > mFireTeamSize && !mUnassigned && PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && bShowUnassigned)
			{
				GetCellLeftWidth(0, CellLeft, CellWidth);
				mUnassigned = True;
				Y -= ItemHeight;
			}
			GetCellLeftWidth(0, CellLeft, CellWidth);
			if (PlayerOwner().PlayerReplicationInfo != fPlayerInfo)
			{
				if (!bAssignedSlot)
				{
					DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 0, False);
				}
				else
				{
					DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 0, True);
				}
			}
			GetCellLeftWidth(1, CellLeft, CellWidth);
			TempInt = fPlayerInfo.GetHonor();
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(2, CellLeft, CellWidth);
			tempString = Left(fPlayerInfo.PlayerName, 24);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(3, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Total;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(4, CellLeft, CellWidth);
			TempInt = fPlayerInfo.GetGoalScore();
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(5, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Leadership;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(6, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Kills;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(7, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Deaths;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(8, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_ROE;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(9, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Ping;
			tempString = TempInt;
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
		}
		if (bSpecialColor)
		{
			for (j = 0; j < 5; j++)
			{
				Style.FontColors[j] = OldColors[j];
			}
		}
	}
	*/
}

void UAAScoreboard_TeamSummary::DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth, EListMode SelectList, bool IsAssigned)
{
	/*
	local Material Icon;
	local float IH;
	local float IconX;
	local float IconY;
	local int32 FTUnitID;
	local int32 FTIndex;
	local AGP.AGP_PlayerStart PS;
	IH = ItemHeight;
	IconX = X + CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Canvas.DrawColor.R = 255;
	Canvas.DrawColor.G = 255;
	Canvas.DrawColor.B = 255;
	Canvas.DrawColor.A = 255;
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && IsAssigned)
	{
		if (SelectList == 1)
		{
			FTUnitID = GetGroup(i);
			FTIndex = GetPositionInGroup(FTUnitID, i);
			PS = Team.GetPlayerStart(FTUnitID, FTIndex);
		}
		else
		{
			FTUnitID = AGP_TeamInfo(PlayerItem.Team).GetPlayerUnitID(PlayerItem);
			FTIndex = AGP_TeamInfo(PlayerItem.Team).GetPlayerIndex(PlayerItem);
			PS = AGP_TeamInfo(PlayerItem.Team).GetPlayerStart(FTUnitID, FTIndex);
		}
		if (PS != None)
		{
			if (!PS.bSpecialForces && !PS.bGuerrilla && !PS.bIFVIP)
			{
				Icon = GetRankIcon(PS);
				Canvas.SetPos(IconX, IconY);
				Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
				IconX += IH + 1;
				Icon = GetClassIcon(PS);
				Canvas.SetPos(IconX, IconY);
				Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
				IconX += IH + 1;
			}
			else
			{
				Icon = GetSFIcon(PS);
				Canvas.SetPos(IconX, IconY);
				Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
				IconX += IH + 1;
				IconX += IH + 1;
			}
		}
	}
	else
	{
		IconX += IH + 1;
		IconX += IH + 1;
	}
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && IsAssigned)
	{
		if (PlayerItem != None)
		{
			Icon = GetSubClassIcon(PlayerItem);
			if (Icon != None)
			{
				Canvas.SetPos(IconX, IconY);
				Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			}
		}
	}
	IconX += IH + 1;
	if (PlayerItem != None)
	{
		Icon = GetGroupIcon(PlayerItem);
		if (Icon != None)
		{
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		}
	}
	*/
}

bool UAAScoreboard_TeamSummary::PreDrawHint(UCanvas* C)
{
	/*
	local int32 IconW;
	local int32 i;
	local float XL;
	local float YL;
	local float MaxWidth;
	local float TotalHeight;
	local XInterface.GUIStyles S;
	if (Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
	{
		Return True;
	}
	if (ToolTip.bResetPosition || ToolTip.bTrackMouse)
	{
		S = ToolTip.Style;
		for (i = 0; i < Icons.Length; i++)
		{
			IconW = Icons[i].MaterialUSize();
			S.TextSize(C, MenuState, IconDescriptions[i], XL, YL, FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			YL = Max(YL, Icons[i].MaterialVSize());
			TotalHeight += YL;
		}
		TotalHeight += S.BorderOffsets[1] + S.BorderOffsets[3];
		ToolTip.WinWidth = MaxWidth + S.BorderOffsets[0] + S.BorderOffsets[2];
		ToolTip.WinHeight = TotalHeight;
		ToolTip.WinTop = ToolTip.GetTop(C);
		ToolTip.WinLeft = ToolTip.GetLeft(C);
		ToolTip.bResetPosition = False;
	}
	*/
	return true;
}

bool UAAScoreboard_TeamSummary::DrawHint(UCanvas* C)
{
	/*
	local XInterface.GUIStyles S;
	local Object.Plane NormMod;
	local int32 i;
	local int32 IconW;
	local int32 IconH;
	local float X;
	local float Y;
	local float XL;
	local float YL;
	if (Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
	{
		Return True;
	}
	S = ToolTip.Style;
	C.DrawColor.R = 127;
	C.DrawColor.G = 127;
	C.DrawColor.B = 127;
	C.DrawColor.A = 255;
	X = ToolTip.WinLeft;
	Y = ToolTip.WinTop;
	XL = ToolTip.WinWidth;
	YL = ToolTip.WinHeight;
	NormMod = C.ColorModulate;
	C.ColorModulate.W = 0.3;
	C.ColorModulate.X = 0.2;
	C.ColorModulate.Y = 0.2;
	C.ColorModulate.Z = 0.2;
	S.Draw(C, 0, X + 2, Y + 2, XL, YL);
	C.ColorModulate = NormMod;
	S.Draw(C, 0, X, Y, XL, YL);
	X += S.BorderOffsets[0];
	Y += S.BorderOffsets[1];
	for (i = 0; i < Icons.Length; i++)
	{
		IconW = Icons[i].MaterialUSize();
		IconH = Icons[i].MaterialVSize();
		S.TextSize(C, MenuState, IconDescriptions[i], XL, YL, FontScale);
		YL = FMax(YL, IconH);
		C.SetPos(X, Y);
		C.DrawTile(Icons[i], IconW, YL, 0, 0, IconW, IconH);
		S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, IconDescriptions[i], FontScale);
		Y += YL;
	}
	*/
	return true;
}

void UAAScoreboard_TeamSummary::MousingOverIcons()
{
	/*
	local float IconRight;
	local float CellLeft;
	local float CellWidth;
	if (Controller == None)
	{
		Return False;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconRight = CellLeft + CellWidth;
	Return Controller.MouseX >= CellLeft && Controller.MouseX <= IconRight;
	*/
}