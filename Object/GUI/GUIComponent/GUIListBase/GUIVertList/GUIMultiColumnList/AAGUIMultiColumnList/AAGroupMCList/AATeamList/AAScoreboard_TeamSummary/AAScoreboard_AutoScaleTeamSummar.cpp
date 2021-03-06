// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_AutoScaleTeamSummar.h"

UAAScoreboard_AutoScaleTeamSummar::UAAScoreboard_AutoScaleTeamSummar()
{
	shadedEntry = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL);
	//OnDraw = AAScoreboard_AutoScaleTeamSummary.InternalOnDraw;
}

bool UAAScoreboard_AutoScaleTeamSummar::InternalOnPreDraw(UCanvas* Canvas)
{
	bInitialized = false;
	/*
	GRI = PlayerOwner().GameReplicationInfo;
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	(ItemCount -= (ItemCount - mFireTeamSize));
	lastFireTeam = 0;
	bToggleShading = false;
	if ((PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId) && (!bIsSpectatorPanel))
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
	}*/
	return true;
}

void UAAScoreboard_AutoScaleTeamSummar::SetSpectatorTeamSizeForDisplay()
{
	int32 fPlayerCount = 0;
	int32 fPlayerIndex = 0;
	int32 totalTeamCount = 0;
	AAA2_PlayerState* fPlayerInfo = nullptr;
	totalTeamCount = 0;
	mTeamPRIArray.Empty();
	/*
	if (GRI == nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI != nullptr)
	{
		fPlayerCount = GRI.PRIArray.Length;
		for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
		{
			fPlayerInfo = GRI.PRIArray[fPlayerIndex];
			if (((fPlayerInfo != nullptr) && (!fPlayerInfo.bPendingDelete)) && (!fPlayerInfo.bDeleteMe))
			{
				if (((fPlayerInfo.Team != nullptr) && (fPlayerInfo.Team.TeamIndex == mTeamId)) && ((fPlayerInfo.bPlayerAdmin || (!fPlayerInfo.bAdmin)) || HumanController(PlayerOwner()).TournamentIsTournament()))
				{
					if (fPlayerInfo.bIsSpectator || (fPlayerInfo.Team.TeamIndex == 255))
					{
						totalTeamCount++;
						mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
					}
				}
			}
		}
	}
	*/
	ItemCount = totalTeamCount;
}

void UAAScoreboard_AutoScaleTeamSummar::SetScalableTeamSizeForDisplay()
{
	int32 fPlayerCount = 0;
	int32 fPlayerIndex = 0;
	int32 totalTeamCount = 0;
	int32 fTeamCount = 0;
	int32 i = 0;
	int32 j = 0;
	AAA2_PlayerState* fPlayerInfo = nullptr;
	totalTeamCount = 0;
	ItemCount = 0;
	fTeamCount = 0;
	mTeamPRIArray.Empty();
	/*
	if (GRI == nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	numUnassigned = 0;
	mFireTeamSize = 0;
	if (GRI != nullptr)
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
					if ((AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) == i) && (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerIndex(fPlayerInfo) == j))
					{
						if (((fPlayerInfo != nullptr) && (!fPlayerInfo.bPendingDelete)) && (!fPlayerInfo.bDeleteMe))
						{
							if (((fPlayerInfo.Team != nullptr) && (fPlayerInfo.Team.TeamIndex == mTeamId)) && (((fPlayerInfo.bPlayerAdmin || (!fPlayerInfo.bAdmin)) || (!fPlayerInfo.bIsSpectator)) || HumanController(PlayerOwner()).TournamentIsTournament()))
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
		if (((AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) == -1) && (mTeamId == AGP_TeamInfo(fPlayerInfo.Team).TeamIndex)) && (!fPlayerInfo.bIsSpectator))
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
			if (((fPlayerInfo != nullptr) && (!fPlayerInfo.bPendingDelete)) && (!fPlayerInfo.bDeleteMe))
			{
				if (((fPlayerInfo.Team != nullptr) && (fPlayerInfo.Team.TeamIndex == mTeamId)) && ((fPlayerInfo.bPlayerAdmin || (!fPlayerInfo.bAdmin)) || HumanController(PlayerOwner()).TournamentIsTournament()))
				{
					numUnassigned++;
					totalTeamCount++;
					mTeamPRIArray[mTeamPRIArray.Length] = fPlayerInfo;
				}
			}
		}
	}
	*/
	ItemCount = totalTeamCount;
}

void UAAScoreboard_AutoScaleTeamSummar::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	int32 TempInt = 0;
	int32 j = 0;
	float CellLeft = 0;
	float CellWidth = 0;
	float IconX = 0;
	float IconY = 0;
	bool bSpecialColor = false;
	bool mUnassigned = false;
	bool bShowUnassigned = false;
	bool bDrawInfo = false;
	bool bDrawFireTeamIcon = false;
	FString tempString = "";
	AAA2_PlayerState* fPlayerInfo = nullptr;
	/*
	local GUI.eMenuState PlayerState;
	FColor OldColors[5] = FColor(0, 0, 0, 0);
	FColor MyColor = FColor(0, 0, 0, 0);
	AAA2_PlayerState* PRI = nullptr;
	bShowUnassigned = false;
	bDrawFireTeamIcon = false;
	if (i < mFireTeamSize)
	{
		mUnassigned = false;
	}
	if (IsSeparator(i))
	{
		return;
	}
	bSpecialColor = false;
	bShowUnassigned = false;
	bDrawInfo = true;
	fPlayerInfo = nullptr;
	if (mTeamPRIArray.Length == 0)
	{
		return;
	}
	if ((numUnassigned == 0) && (mTeamPRIArray[i] != nullptr))
	{
		fPlayerInfo = mTeamPRIArray[i];
		if (((fPlayerInfo == nullptr) || fPlayerInfo.bPendingDelete) || fPlayerInfo.bDeleteMe)
		{
			mTeamPRIArray.remove(0, mTeamPRIArray.Length);
			ItemCount = 0;
			return;
		}
	}
	else
	{
		if (float(i) >= (float(mFireTeamSize) + mUnassignedMargin))
		{
			if (float(mTeamPRIArray.Length) <= (float(mFireTeamSize) + (float(i) - (float(mFireTeamSize) + mUnassignedMargin))))
			{
				mTeamPRIArray.remove(0, mTeamPRIArray.Length);
				ItemCount = 0;
				return;
			}
			fPlayerInfo = mTeamPRIArray[int((float(mFireTeamSize) + (float(i) - (float(mFireTeamSize) + mUnassignedMargin))))];
			if (((fPlayerInfo == nullptr) || fPlayerInfo.bPendingDelete) || fPlayerInfo.bDeleteMe)
			{
				mTeamPRIArray.remove(0, mTeamPRIArray.Length);
				ItemCount = 0;
				return;
			}
		}
		else
		{
			if (i < mFireTeamSize)
			{
				fPlayerInfo = mTeamPRIArray[i];
				if (((fPlayerInfo == nullptr) || fPlayerInfo.bPendingDelete) || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.remove(0, mTeamPRIArray.Length);
					ItemCount = 0;
					return;
				}
			}
			else
			{
				bDrawInfo = false;
				fPlayerInfo = nullptr;
			}
		}
		if (((numUnassigned > 0) && (mFireTeamSize == 0)) && (i == 0))
		{
			bShowUnassigned = true;
		}
		else
		{
			if (((numUnassigned > 0) && (mFireTeamSize > 0)) && (i == (mFireTeamSize + 1)))
			{
				bShowUnassigned = true;
			}
		}
	}
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)
	{
		if (fPlayerInfo != nullptr)
		{
			if (lastFireTeam != AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo))
			{
				lastFireTeam = AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo);
				bToggleShading = (!bToggleShading);
				bDrawFireTeamIcon = true;
				Canvas.SetDrawColor(251, 248, 229, 255);
			}
			if (bToggleShading && (!fPlayerInfo.bIsSpectator))
			{
				IconX = X;
				IconY = Y;
				Canvas.SetPos(IconX, IconY);
				Canvas.Style = ERenderStyle.STY_Alpha;
				Canvas.SetDrawColor(255, 255, 255, 200);
				Canvas.DrawRect(shadedEntry, (ActualWidth() - (ActualWidth() * 0.005)), ItemHeight);
			}
			if (bDrawFireTeamIcon)
			{
				IconX = (X + CellLeft);
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
				Canvas.Style = ERenderStyle.STY_Alpha;
				if ((AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) - 1) >= 0)
				{
					Canvas.DrawTile(tFT[(AGP_TeamInfo(fPlayerInfo.Team).GetPlayerUnitID(fPlayerInfo) - 1)], ItemHeight, ItemHeight, 0, 0, 32, 32);
				}
			}
		}
	}
	PRI = PlayerOwner().PlayerReplicationInfo;
	if (fPlayerInfo != nullptr)
	{
		PlayerState = GetPlayerState(fPlayerInfo);
		if ((PRI != nullptr) && (fPlayerInfo == PRI))
		{
			if (PRI.isDead())
			{
				MyColor.R = 149;
				MyColor.G = 135;
				MyColor.B = 83;
				MyColor.A = 255;
				bSpecialColor = true;
			}
			else
			{
				MyColor.R = 240;
				MyColor.G = 196;
				MyColor.B = 27;
				MyColor.A = 255;
				bSpecialColor = true;
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
				bSpecialColor = true;
			}
		}
		if ((HumanController(PlayerOwner()) != nullptr) && HumanController(PlayerOwner()).bTournamentServer)
		{
			if (fPlayerInfo.bAdmin)
			{
				MyColor.R = 255;
				MyColor.G = 0;
				MyColor.B = 0;
				MyColor.A = 255;
				bSpecialColor = true;
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
						bSpecialColor = true;
					}
					else
					{
						MyColor.R = 82;
						MyColor.G = 82;
						MyColor.B = 159;
						MyColor.A = 255;
						bSpecialColor = true;
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
	if ((bShowUnassigned && (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)) && (!bIsSpectatorPanel))
	{
		GetCellLeftWidth(0, CellLeft, CellWidth);
		Style.DrawText(Canvas, 2, CellLeft, Y, CellWidth, H, 0, Chr(13) $ "Unassigned:" $ Chr(13), FontScale);
	}
	else
	{
		if (ShouldDrawItem(fPlayerInfo) && (fPlayerInfo != nullptr))
		{
			if (AGP_TeamInfo(fPlayerInfo.Team).GetPlayerIndex(fPlayerInfo) >= 0)
			{
				GetCellLeftWidth(0, CellLeft, CellWidth);
				DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft, CellWidth, 0, true);
			}
			GetCellLeftWidth(1, CellLeft, CellWidth);
			TempInt = fPlayerInfo.GetHonor();
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(2, CellLeft, CellWidth);
			tempString = Left(fPlayerInfo.PlayerName, 24);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(3, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Total;
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(4, CellLeft, CellWidth);
			TempInt = fPlayerInfo.GetGoalScore();
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(5, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Leadership;
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(6, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Kills;
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(7, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_Deaths;
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(8, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Score_ROE;
			tempString = string(TempInt);
			Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, tempString, FontScale);
			GetCellLeftWidth(9, CellLeft, CellWidth);
			TempInt = fPlayerInfo.Ping;
			tempString = string(TempInt);
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

float UAAScoreboard_AutoScaleTeamSummar::InternalGetItemHeight(UCanvas* C)
{
	if (!bFullSpectatorPanel)
	{
		return (float(C->SizeY) * 0.018);
	}
	return Super::InternalGetItemHeight(C);
}

bool UAAScoreboard_AutoScaleTeamSummar::InternalOnDraw(UCanvas* C)
{
	if (!bFullSpectatorPanel)
	{
		if (renderCounter < 1)
		{
			renderCounter++;
		}
		else
		{
			return true;
		}
	}
	return OnDraw(C);
}
