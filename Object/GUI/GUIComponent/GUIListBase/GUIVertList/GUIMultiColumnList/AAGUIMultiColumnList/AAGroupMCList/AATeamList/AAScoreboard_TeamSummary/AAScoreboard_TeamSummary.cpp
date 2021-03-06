// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAScoreboard_TeamSummary/AAScoreboard_TeamSummary.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"

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
	//Team = Cast<AAGP_TeamInfo>(PlayerOwner()->PlayerReplicationInfo->Team);
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
	int32 fPlayerCount = 0;
	int32 fPlayerIndex = 0;
	int32 fTeamCount = 0;
	AAA2_PlayerState* fPlayerInfo = nullptr;
	bInitialized = false;
	/*
	GRI = PlayerOwner().GameReplicationInfo;
	Team = Cast<AAGP_TeamInfo>(PlayerOwner()->PlayerReplicationInfo->Team);
	ItemCount -= ItemCount - mFireTeamSize;
	if (PlayerOwner()->PlayerReplicationInfo->Team->TeamIndex == mTeamId)
	{
		if (Team != nullptr)
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
		mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
		if (GRI == nullptr)
		{
			GRI = PlayerOwner().GameReplicationInfo;
		}
		if (GRI != nullptr)
		{
			fPlayerCount = GRI.PRIArray.Num();
			for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
			{
				fPlayerInfo = GRI.PRIArray[fPlayerIndex];
				if (fPlayerInfo != nullptr && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
				{
					if (fPlayerInfo.Team != nullptr && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || !fPlayerInfo.bIsSpectator || Cast<AHumanController>(PlayerOwner())->TournamentIsTournament())
					{
						fTeamCount++;
						mTeamPRIArray[mTeamPRIArray.Num()] = fPlayerInfo;
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
	OnRendered(Canvas);
	mTeamPRIArray.Empty();
}

void UAAScoreboard_TeamSummary::SetTeamSizeForDisplay()
{
	int32 fTeamCount = 0;
	fTeamCount = GetTeamCount(mTeamId);
	ItemCount = fTeamCount;
}

int32 UAAScoreboard_TeamSummary::GetTeamCount(int32 iTeamID)
{
	int32 fTeamCount=0;
	int32 fPlayerCount = 0;
	int32 fPlayerIndex = 0;
	AAA2_PlayerState* fPlayerInfo = nullptr;
	fTeamCount = 0;
	mTeamPRIArray.Empty();
	/*
	if (GRI == nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI != nullptr)
	{
		fPlayerCount = GRI.PRIArray.Num();
		for (fPlayerIndex = 0; fPlayerIndex < fPlayerCount; fPlayerIndex++)
		{
			fPlayerInfo = GRI.PRIArray[fPlayerIndex];
			if (fPlayerInfo != nullptr && !fPlayerInfo.bPendingDelete && !fPlayerInfo.bDeleteMe)
			{
				if (fPlayerInfo.Team != nullptr && fPlayerInfo.Team.TeamIndex == mTeamId && fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || !fPlayerInfo.bIsSpectator || Cast<AHumanController>(PlayerOwner())->TournamentIsTournament())
				{
					fTeamCount++;
					mTeamPRIArray[mTeamPRIArray.Num()] = fPlayerInfo;
				}
			}
		}
	}
	*/
	return fTeamCount;
}

bool UAAScoreboard_TeamSummary::ShouldDrawItem(AAA2_PlayerState* fPlayerInfo)
{
	if (fPlayerInfo == nullptr)
	{
		return false;
	}
	//return fPlayerInfo.bPlayerAdmin || !fPlayerInfo.bAdmin || Cast<AHumanController>(PlayerOwner())->TournamentIsTournament() || Cast<AHumanController>(PlayerOwner()) != nullptr && Cast<AHumanController>(PlayerOwner())->bTournamentServer;
	return true;      //FAKE   /ELiZ
}

void UAAScoreboard_TeamSummary::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	int32 FTUnitID = 0;
	int32 FTIndex = 0;
	int32 FTUnitID2 = 0;
	int32 FTIndex2 = 0;
	int32 j = 0;
	int32 TempInt = 0;
	float IconX = 0;
	float IconY = 0;
	float CellLeft = 0;
	float CellWidth = 0;
	bool bSpecialColor = false;
	bool mUnassigned = false;
	bool bAssignedSlot = false;
	bool bAssignedSlotFT = false;
	bool bShowUnassigned = false;
	FString tempString = "";
	AAA2_PlayerState* fPlayerInfo = nullptr;
	EMenuState PlayerState = EMenuState::MSAT_Blurry;
	FColor OldColors = FColor(0,0,0,0);
	FColor MyColor = FColor(0,0,0,0);
	AAA2_PlayerState* PRI = nullptr;
	bShowUnassigned = false;
	bAssignedSlot = false;
	bAssignedSlotFT = false;
	fPlayerInfo = nullptr;
	if (i < mFireTeamSize)
	{
		mUnassigned = false;
	}
	/*
	if (!IsSeparator(i))
	{
		tempString = "";
		TempInt = 0;
		bSpecialColor = false;
		if (mTeamPRIArray.Num() == 0)
		{
			return;
		}
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && !PlayerOwner().PlayerReplicationInfo.bIsSpectator)
		{
			for (j = 0; j < mTeamPRIArray.Num(); j++)
			{
				if (mTeamPRIArray[j] == nullptr || mTeamPRIArray[j].bPendingDelete || mTeamPRIArray[j].bDeleteMe)
				{
					mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
					ItemCount = 0;
					return;
				}
				FTUnitID = Cast<AGP_TeamInfo>(mTeamPRIArray[j].Team).GetPlayerUnitID(mTeamPRIArray[j]);
				if (FTUnitID == -1)
				{
					bShowUnassigned = true;
				}
			}
			if (i >= mFireTeamSize)
			{
				if (mTeamPRIArray.Num() <= i - mFireTeamSize)
				{
					mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
					ItemCount = 0;
					return;
				}
				fPlayerInfo = mTeamPRIArray[i - mFireTeamSize];
				if (fPlayerInfo == nullptr || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
					ItemCount = 0;
					return;
				}
				FTUnitID2 = Cast<AGP_TeamInfo>(mTeamPRIArray[i - mFireTeamSize].Team).GetPlayerUnitID(mTeamPRIArray[i - mFireTeamSize]);
				FTIndex2 = Cast<AGP_TeamInfo>(mTeamPRIArray[i - mFireTeamSize].Team).GetPlayerIndex(mTeamPRIArray[i - mFireTeamSize]);
				for (j = 0; j < mFireTeamSize; j++)
				{
					FTUnitID = GetGroup(j);
					FTIndex = GetPositionInGroup(FTUnitID2, j);
					if (FTUnitID2 == FTUnitID && FTIndex2 == FTIndex)
					{
						bAssignedSlot = true;
					}
				}
			}
			else
			{
				FTUnitID2 = GetGroup(i);
				FTIndex2 = GetPositionInGroup(FTUnitID2, i);
				for (j = 0; j < mTeamPRIArray.Num(); j++)
				{
					if (mTeamPRIArray[j] == nullptr || mTeamPRIArray[j].bPendingDelete || mTeamPRIArray[j].bDeleteMe)
					{
						mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
						ItemCount = 0;
						return;
					}
					FTUnitID = Cast<AGP_TeamInfo>(mTeamPRIArray[j].Team).GetPlayerUnitID(mTeamPRIArray[j]);
					FTIndex = Cast<AGP_TeamInfo>(mTeamPRIArray[j].Team).GetPlayerIndex(mTeamPRIArray[j]);
					if (FTUnitID2 == FTUnitID && FTIndex2 == FTIndex)
					{
						fPlayerInfo = mTeamPRIArray[j];
						bAssignedSlotFT = true;
					}
				}
			}
		}
		else
		{
			if (i < mTeamPRIArray.Num())
			{
				fPlayerInfo = mTeamPRIArray[i];
				if (fPlayerInfo == nullptr || fPlayerInfo.bPendingDelete || fPlayerInfo.bDeleteMe)
				{
					mTeamPRIArray.RemoveAt(0, mTeamPRIArray.Num());
					ItemCount = 0;
					return;
				}
			}
		}
		PRI = PlayerOwner().PlayerReplicationInfo;
		if (fPlayerInfo != nullptr)
		{
			PlayerState = GetPlayerState(fPlayerInfo);
			if (PRI != nullptr && fPlayerInfo == PRI)
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
			if (Cast<AHumanController>(PlayerOwner()) != nullptr && Cast<AHumanController>(PlayerOwner())->bTournamentServer)
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
			DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 1, true);
		}
		if (GetGroup(i) == 5 && GetPositionInGroup(GetGroup(i), i) == 0 && bShowUnassigned && PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId)
		{
			GetCellLeftWidth(0, CellLeft, CellWidth);
			Style.DrawText(Canvas, 2, CellLeft, Y, CellWidth, H, 0, Chr(13) + "Unassigned:" + Chr(13), FontScale);
		}
		if (fPlayerInfo != nullptr && ShouldDrawItem(fPlayerInfo) && !bAssignedSlot && !mUnassigned)
		{
			if (i > mFireTeamSize && !mUnassigned && PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == mTeamId && bShowUnassigned)
			{
				GetCellLeftWidth(0, CellLeft, CellWidth);
				mUnassigned = true;
				Y -= ItemHeight;
			}
			GetCellLeftWidth(0, CellLeft, CellWidth);
			if (PlayerOwner().PlayerReplicationInfo != fPlayerInfo)
			{
				if (!bAssignedSlot)
				{
					DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 0, false);
				}
				else
				{
					DrawIcons(Canvas, fPlayerInfo, i, 33, Y, CellLeft + WinWidth * 0.02, CellWidth, 0, true);
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
	UMaterialInstance* Icon = nullptr;
	float IH =0;
	float IconX = 0;
	float IconY = 0;
	int32 FTUnitID = 0;
	int32 FTIndex = 0;
	AAGP_PlayerStart* PS = nullptr;
	/*
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
			FTUnitID = Cast<AGP_TeamInfo>(PlayerItem.Team).GetPlayerUnitID(PlayerItem);
			FTIndex = Cast<AGP_TeamInfo>(PlayerItem.Team).GetPlayerIndex(PlayerItem);
			PS = Cast<AGP_TeamInfo>(PlayerItem.Team).GetPlayerStart(FTUnitID, FTIndex);
		}
		if (PS != nullptr)
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
		if (PlayerItem != nullptr)
		{
			Icon = GetSubClassIcon(PlayerItem);
			if (Icon != nullptr)
			{
				Canvas.SetPos(IconX, IconY);
				Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			}
		}
	}
	IconX += IH + 1;
	if (PlayerItem != nullptr)
	{
		Icon = GetGroupIcon(PlayerItem);
		if (Icon != nullptr)
		{
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		}
	}
	*/
}

bool UAAScoreboard_TeamSummary::PreDrawHint(UCanvas* C)
{
	int32 IconW = 0;
	int32 i = 0;
	float XL = 0;
	float YL = 0;
	float MaxWidth = 0;
	float TotalHeight = 0;
	UGUIStyles* S = nullptr;
	/*
	if (Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip.Style == nullptr)
	{
		return true;
	}
	if (ToolTip.bResetPosition || ToolTip.bTrackMouse)
	{
		S = ToolTip.Style;
		for (i = 0; i < Icons.Num(); i++)
		{
			IconW = Icons[i].MaterialUSize();
			S.TextSize(C, MenuState, IconDescriptions[i], XL, YL, FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			YL = FMath::Max(YL, Icons[i].MaterialVSize());
			TotalHeight += YL;
		}
		TotalHeight += S.BorderOffsets[1] + S.BorderOffsets[3];
		ToolTip.WinWidth = MaxWidth + S.BorderOffsets[0] + S.BorderOffsets[2];
		ToolTip.WinHeight = TotalHeight;
		ToolTip.WinTop = ToolTip.GetTop(C);
		ToolTip.WinLeft = ToolTip.GetLeft(C);
		ToolTip.bResetPosition = false;
	}
	*/
	return true;
}

bool UAAScoreboard_TeamSummary::DrawHint(UCanvas* C)
{
	UGUIStyles* S = nullptr;
	FPlane NormMod = FPlane(0,0,0,0);
	int32 i = 0;
	int32 IconW = 0;
	int32 IconH = 0;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	/*
	if (Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip.Style == nullptr)
	{
		return true;
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
	for (i = 0; i < Icons.Num(); i++)
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

bool UAAScoreboard_TeamSummary::MousingOverIcons()
{
	float IconRight = 0;
	float CellLeft = 0;
	float CellWidth = 0;
	/*
	if (Controller == nullptr)
	{
		return false;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconRight = CellLeft + CellWidth;
	return Controller.MouseX >= CellLeft && Controller.MouseX <= IconRight;
	*/
	return false;    //FAKE  /EliZ
}
