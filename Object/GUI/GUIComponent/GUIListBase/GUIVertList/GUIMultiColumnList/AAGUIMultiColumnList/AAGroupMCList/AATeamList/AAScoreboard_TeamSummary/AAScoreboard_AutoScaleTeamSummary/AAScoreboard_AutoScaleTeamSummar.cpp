// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_AutoScaleTeamSummary/AAScoreboard_AutoScaleTeamSummar.h"

UAAScoreboard_AutoScaleTeamSummar::UAAScoreboard_AutoScaleTeamSummar()
{
	//shadedEntry = Texture'T_AA2_UI.Menu.Section_header';
	//__OnDraw__Delegate = "AAScoreboard_AutoScaleTeamSummary.InternalOnDraw";
}

bool UAAScoreboard_AutoScaleTeamSummar::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	bInitialized = False;
	GRI = PlayerOwner().GameReplicationInfo;
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	ItemCount -= ItemCount - mFireTeamSize;
	lastFireTeam = 0;
	bToggleShading = False;
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && !bIsSpectatorPanel)
	{
		SetScalableTeamSizeForDisplay();
	}
	else
	{
		if (bIsSpectatorPanel)
		{
			SetSpectatorTeamSizeForDisplay();
		}
		else
		{
			SetTeamSizeForDisplay();
		}
	}
	*/
	return true;
}

void UAAScoreboard_AutoScaleTeamSummar::SetSpectatorTeamSizeForDisplay()
{
	/*
	local int fPlayerCount;
	local int fPlayerIndex;
	local int totalTeamCount;
	local PlayerReplicationInfo fPlayerInfo;
	totalTeamCount = 0;
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
				if (fPlayerInfo.Team != None && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || HumanController(PlayerOwner()).TournamentIsTournament())
				{
					if (fPlayerInfo.bIsSpectator || fPlayerInfo.Team.TeamIndex == 255)
					{
						totalTeamCount++;
						mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
					}
				}
			}
		}
	}
	ItemCount = totalTeamCount;
	*/
}

void UAAScoreboard_AutoScaleTeamSummar::SetScalableTeamSizeForDisplay()
{
	/*
	local int fPlayerCount;
	local int fPlayerIndex;
	local int totalTeamCount;
	local int fTeamCount;
	local int i;
	local int j;
	local PlayerReplicationInfo fPlayerInfo;
	totalTeamCount = 0;
	ItemCount = 0;
	fTeamCount = 0;
	mTeamPRIArray.remove(0, mTeamPRIArray.Length);
	if (GRI == None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	numUnassigned = 0;
	mFireTeamSize = 0;
	if (GRI != None)
	{
		fPlayerCount = GRI.PRIArray.Length;
		for (i = 0; i < fPlayerCount; i++)
		{
			fPlayerInfo = GRI.PRIArray[i];
			if (fPlayerInfo.Team.TeamIndex == mTeamId)
			{
				fTeamCount++;
			}
		}
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < Team.FTCount[i]; j++)
			{
				for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
				{
					fPlayerInfo = GRI.PRIArray[fPlayerIndex];
					if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) == i && AGP_TeamInfo(fPlayerInfo.Team).GetPlayerIndex(fPlayerInfo) == j)
					{
						if (fPlayerInfo != None && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
						{
							if (fPlayerInfo.Team != None && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || !fPlayerInfo.bIsSpectator || HumanController(PlayerOwner()).TournamentIsTournament())
							{
								totalTeamCount++;
								mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
							}
						}
					}
				}
			}
		}
	}
	mFireTeamSize = totalTeamCount;
	for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
	{
		fPlayerInfo = GRI.PRIArray[fPlayerIndex];
		if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) == -1 && mTeamId == AGP_TeamInfo(fPlayerInfo.Team).TeamIndex && !fPlayerInfo.bIsSpectator)
		{
			fPlayerIndex = fPlayerCount;
			if (fTeamCount > 1)
			{
				totalTeamCount += 2;
				mUnassignedMargin = 2;
			}
			else
			{
				totalTeamCount += 1;
				mUnassignedMargin = 1;
			}
		}
	}
	numUnassigned = 0;
	for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
	{
		fPlayerInfo = GRI.PRIArray[fPlayerIndex];
		if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) == -1)
		{
			if (fPlayerInfo != None && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
			{
				if (fPlayerInfo.Team != None && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || HumanController(PlayerOwner()).TournamentIsTournament())
				{
					numUnassigned++;
					totalTeamCount++;
					mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
				}
			}
		}
	}
	ItemCount = totalTeamCount;
	*/
}

void UAAScoreboard_AutoScaleTeamSummar::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local int TempInt;
	local int j;
	local float CellLeft;
	local float CellWidth;
	local float IconX;
	local float IconY;
	local bool bSpecialColor;
	local bool mUnassigned;
	local bool bShowUnassigned;
	local bool bDrawInfo;
	local bool bDrawFireTeamIcon;
	local string tempString;
	local PlayerReplicationInfo fPlayerInfo;
	local GUI.eMenuState PlayerState;
	local Object.Color OldColors;
	local Object.Color MyColor;
	local PlayerReplicationInfo PRI;
	bShowUnassigned = False;
	bDrawFireTeamIcon = False;
	if (i < mFireTeamSize)
	{
		mUnassigned = False;
	}
	if (IsSeparator(i))
	{
		Return;
	}
	bSpecialColor = False;
	bShowUnassigned = False;
	bDrawInfo = True;
	fPlayerInfo = None;
	if (mTeamPRIArray.Length == 0)
	{
		Return;
	}
	if (numUnassigned == 0 && mTeamPRIArray[i] != None)
	{
		fPlayerInfo = mTeamPRIArray[i];
		if (fPlayerInfo == None || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
		{
			mTeamPRIArray.remove(0, mTeamPRIArray.Length);
			ItemCount = 0;
			Return;
		}
	}
	else
	{
		if (i >= mFireTeamSize + mUnassignedMargin)
		{
			if (mTeamPRIArray.Length <= mFireTeamSize + i - mFireTeamSize + mUnassignedMargin)
			{
				mTeamPRIArray.remove(0, mTeamPRIArray.Length);
				ItemCount = 0;
				Return;
			}
			fPlayerInfo = mTeamPRIArray[mFireTeamSize + i - mFireTeamSize + mUnassignedMargin];
			if (fPlayerInfo == None || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
			{
				mTeamPRIArray.remove(0, mTeamPRIArray.Length);
				ItemCount = 0;
				Return;
			}
		}
		else
		{
			if (i < mFireTeamSize)
			{
				fPlayerInfo = mTeamPRIArray[i];
				if (fPlayerInfo == None || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					Return;
				}
			}
			else
			{
				bDrawInfo = False;
				fPlayerInfo = None;
			}
		}
		if (numUnassigned > 0 && mFireTeamSize == 0 && i == 0)
		{
			bShowUnassigned = True;
		}
		else
		{
			if (numUnassigned > 0 && mFireTeamSize > 0 && i == mFireTeamSize + 1)
			{
				bShowUnassigned = True;
			}
		}
	}
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)
	{
		if (fPlayerInfo != None)
		{
			if (lastFireTeam != AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo))
			{
				lastFireTeam = AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo);
				bToggleShading = !bToggleShading;
				bDrawFireTeamIcon = True;
				Canvas.SetDrawColor(251, 248, 229, 255);
			}
			if (bToggleShading && !fPlayerInfo.bIsSpectator)
			{
				IconX = X;
				IconY = Y;
				Canvas.SetPos(IconX, IconY);
				Canvas.Style = 6;
				Canvas.SetDrawColor(255, 255, 255, 200);
				Canvas.DrawRect(shadedEntry, ActualWidth() - ActualWidth() * 0.005, ItemHeight);
			}
			if (bDrawFireTeamIcon)
			{
				IconX = X + CellLeft;
				IconY = Y;
				Canvas.SetPos(IconX, IconY);
				if (bToggleShading)
				{
					Canvas.SetDrawColor(83, 85, 83, 255);
				}
				else
				{
					Canvas.SetDrawColor(255, 255, 255, 50);
				}
				Canvas.Style = 6;
				if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) - 1 >= 0)
				{
					Canvas.DrawTile(tFT[AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) - 1], ItemHeight, ItemHeight, 0, 0, 32, 32);
				}
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
	if (bShowUnassigned && PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && !bIsSpectatorPanel)
	{
		GetCellLeftWidth(0, CellLeft, CellWidth);
		Style.DrawText(Canvas, 2, CellLeft, Y, CellWidth, H, 0, Chr(13) $ "Unassigned:" $ Chr(13), FontScale);
	}
	else
	{
		if (ShouldDrawItem(fPlayerInfo) && fPlayerInfo != None)
		{
			if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerIndex(fPlayerInfo) >= 0)
			{
				GetCellLeftWidth(0, CellLeft, CellWidth);
				DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft, CellWidth, 0, True);
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
	}
	if (bSpecialColor)
	{
		for (j = 0; j < 5; j++)
		{
			Style.FontColors[j] = OldColors[j];
		}
	}
	*/
}

void UAAScoreboard_AutoScaleTeamSummar::InternalGetItemHeight(UCanvas* C)
{
	/*
	if (!bFullSpectatorPanel)
	{
		Return C.SizeY * 0.018;
	}
	Return InternalGetItemHeight(C);
	*/
}

void UAAScoreboard_AutoScaleTeamSummar::InternalOnDraw(UCanvas* C)
{
	/*
	if (!bFullSpectatorPanel)
	{
		if (renderCounter < 1)
		{
			renderCounter++;
		}
		else
		{
			Return True;
		}
	}
	Return OnDraw(C);
	*/
}