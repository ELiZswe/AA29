// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAWeaponClass_WaitingList/AAWeaponClass_WaitingList.h"

UAAWeaponClass_WaitingList::UAAWeaponClass_WaitingList()
{
	
	ColumnHeadings = { "", "Awaiting Selection", "Honor", "Score", "Time" };
	InitColumnPerc = { 0.05, 0.5, 0.15, 0.15, 0.15 };
	ItemCount = 32;
	//__OnDrawItem__Delegate = "AAWeaponClass_WaitingList.InternalOnDrawItem";
	StyleName = "AAUnitBox";
	RenderWeight = 1;
}

void InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local PlayerReplicationInfo PlayerItem;
	local float IconX;
	local float IconY;
	local Material Icon;
	local GUI.eMenuState PlayerState;
	local AGP_Gameplay.AGP_TeamInfo PlayerTeam;
	local PlayerController PC;
	local float IH;
	PC = PlayerOwner();
	if (PC.PlayerReplicationInfo != None)
	{
		PlayerTeam = AGP_TeamInfo(PC.PlayerReplicationInfo.Team);
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
	IH = ItemHeight - 2;
	IconX = CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Icon = GetGroupIcon(PlayerItem);
	if (Icon != None)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
	}
	PlayerState = GetPlayerState(PlayerItem);
	if (PlayerTeam.GetNoRequestTimer(i) > 0)
	{
		PlayerState = 4;
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
	*/
}