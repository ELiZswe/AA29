// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnassignedTeamList/AAUnassignedTeamList.h"

UAAUnassignedTeamList::UAAUnassignedTeamList()
{
	MaxVisibleTeamEntries = 16;
	ColumnHeadings = { "", "Unassigned", "Honor", "Score", "Time", "" };
	InitColumnPerc = { 0.2, 0.32, 0.15, 0.18, 0.12, 0.05 };
	SortColumn = -1;
	bVisibleWhenEmpty = true;
	//__OnDrawItem__Delegate = "AAUnassignedTeamList.InternalOnDrawItem";
	StyleName = "AAUnitBox";
	RenderWeight = 1;
}


void UAAUnassignedTeamList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//InitComponent(MyController, MyOwner);
	//GRI = PlayerOwner().GameReplicationInfo;
}

bool UAAUnassignedTeamList::InternalOnPreDraw(UCanvas* Canvas)
{
	//ItemCount = Team.MaxSize;
	return true;
}

void UAAUnassignedTeamList::InternalGetItemHeight(UCanvas* C)
{
	/*
	MaxVisibleTeamEntries = ItemCount + 1;
	if (MaxVisibleTeamEntries < 13)
	{
		MaxVisibleTeamEntries = 13;
	}
	Return InternalGetItemHeight(C);
	*/
}

void UAAUnassignedTeamList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local int j;
	local float CellLeft;
	local float CellWidth;
	local AAA2_PlayerState* PlayerItem;
	local GUI.eMenuState PlayerState;
	local Object.Color OldColors;
	local Object.Color MyColor;
	local bool bSpecialColor;
	local AGP_Gameplay.AGP_TeamInfo PlayerTeam;
	local PlayerController PC;
	local AAA2_PlayerState* PRI;
	PC = PlayerOwner();
	bSpecialColor = False;
	PlayerTeam = Team;
	if (PlayerTeam == None)
	{
		if (PC.PlayerReplicationInfo != None)
		{
			PlayerTeam = AGP_TeamInfo(PC.PlayerReplicationInfo.Team);
		}
	}
	if (PC.PlayerReplicationInfo != None)
	{
		PRI = PC.PlayerReplicationInfo;
	}
	if (PlayerTeam == None)
	{
		Return;
	}
	PlayerItem = PlayerTeam.GetNoRequest(i);
	if (PlayerItem == None)
	{
		Return;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	DrawIcons(Canvas, PlayerItem, X, Y, CellLeft, CellWidth);
	PlayerState = GetPlayerState(PlayerItem);
	if (PlayerTeam.GetNoRequestTimer(i) > 0)
	{
		PlayerState = 4;
	}
	if (PRI != None && PlayerItem != None && PlayerItem == PRI)
	{
		if (PlayerState == 4)
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
		if (PlayerItem.bAdmin)
		{
			MyColor.R = 255;
			MyColor.G = 0;
			MyColor.B = 0;
			MyColor.A = 255;
			bSpecialColor = True;
		}
		else
		{
			if (PlayerItem.bTournamentTeamCaptain)
			{
				if (PlayerState == 4)
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
	if (bSpecialColor)
	{
		for (j = 0; j < 5; j++)
		{
			OldColors[j] = Style.FontColors[j];
			Style.FontColors[j] = MyColor;
		}
	}
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 0, GetPlayerName(PlayerItem), 0);
	if (PlayerItem.GetHonor() > 0)
	{
		GetCellLeftWidth(2, CellLeft, CellWidth);
		Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 1, PlayerItem.GetHonor(), 0);
	}
	GetCellLeftWidth(3, CellLeft, CellWidth);
	Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 1, PlayerItem.Score_Total, 0);
	GetCellLeftWidth(4, CellLeft, CellWidth);
	Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, H, 1, PlayerTeam.GetNoRequestTimer(i), 0);
	if (bSpecialColor)
	{
		for (j = 0; j < 5; j++)
		{
			Style.FontColors[j] = OldColors[j];
		}
	}
	*/
}

void UAAUnassignedTeamList::DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	local Material Icon;
	local float IH;
	local float IconX;
	local float IconY;
	local AGP.AGP_PlayerStart PS;
	IH = ItemHeight;
	IconX = X + CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Icon = GetGroupIcon(PlayerItem);
	if (Icon != None)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		IconX += 4;
	}
	PS = GetPlayerStart(PlayerItem);
	if (PS != None)
	{
		if (!PS.bSpecialForces && !PS.bGuerrilla && !PS.bIFVIP)
		{
			IconX += IH + 1;
			Icon = GetRankIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			IconX += IH + 1;
			Icon = GetClassIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		}
		else
		{
			IconX += IH + 1;
			Icon = GetSFIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		}
	}
	IconX += IH + 1;
	Icon = GetSubClassIcon(PlayerItem);
	if (Icon != None)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
	}
	*/
}

void UAAUnassignedTeamList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
}

void UAAUnassignedTeamList::DrawScores(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
}