// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAScoreboard_FireTeamList/AAScoreboard_FireTeamList.h"

UAAScoreboard_FireTeamList::UAAScoreboard_FireTeamList()
{
	ButtonHint = "Click here to select this slot";
	
	ColumnHeadings = { "", "Class", "Player Name", "Score", "Goals", "Leader", "Enemy", "KIA", "ROE", "Ping", "", "" };
	//\\ColumnWidths = ;
	//WinHeight = "AAScoreboard_FireTeamList.InternalOnDrawItem";
	StyleName = "AAUnitBox";
	RenderWeight = 1;
	bAcceptsInput = false;
	//__OnPreDraw__Delegate = "AAScoreboard_FireTeamList.InternalOnPreDraw";

}

bool UAAScoreboard_FireTeamList::ButtonClick(UGUIComponent* Sender)
{
	/*
	local int32 i;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Sender == Buttons[i])
		{
			PlayerOwner().PlayerReplicationInfo.SubmitPlayerRequest(FTIndex, i);
		}
	}
	*/
	return true;
}

bool UAAScoreboard_FireTeamList::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	local int32 i;
	if (Style != None)
	{
		WinHeight = 1 + Style.BorderOffsets[1] + Style.BorderOffsets[3] + ItemHeight * ItemCount;
	}
	else
	{
		WinHeight = 1 + ItemHeight * ItemCount;
	}
	for (i = 0; i < Buttons.Length; i++)
	{
		Buttons[i].WinHeight = ItemHeight;
	}
	*/
	return true;
}

void UAAScoreboard_FireTeamList::InitList(AAGP_TeamInfo* FTTeam, int32 FTI)
{
	/*
	local int32 i;
	Team = FTTeam;
	FTIndex = FTI;
	ItemCount = Team.FTCount[FTIndex];
	for (i = 0; i < ItemCount; i++)
	{
		Buttons[i] = new () classClass'GUIButton';
		Buttons[i].RenderWeight = 4;
		Buttons[i].StyleName = "MainMenuButton";
		Buttons[i].Caption = "";
		Buttons[i].Hint = ButtonHint;
		Buttons[i].WinWidth = 0.04;
		Buttons[i].InitComponent(Controller, Self);
		Buttons[i].Opened(Self);
		Buttons[i].__OnClick__Delegate = ButtonClick;
	}
	*/
}

void UAAScoreboard_FireTeamList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local AAA2_PlayerState* PlayerItem;
	PlayerItem = Team.GetPlayerRequest(FTIndex, i);
	GetCellLeftWidth(0, CellLeft, CellWidth);
	DrawIcons(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	DrawPlayer(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	DrawPlayer(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	GetCellLeftWidth(10, CellLeft, CellWidth);
	UpdateButton(PlayerItem, i, X, Y, CellLeft, CellWidth);
	*/
}

void UAAScoreboard_FireTeamList::DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	local Material Icon;
	local float IH;
	local float IconX;
	local float IconY;
	local AGP.AGP_PlayerStart PS;
	IH = ItemHeight - 2;
	IconX = CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Icon = GetGroupIcon(PlayerItem);
	if (Icon != None)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
	}
	PS = Team.GetPlayerStart(FTIndex, i);
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

void UAAScoreboard_FireTeamList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	if (PlayerItem == None)
	{
		Return;
	}
	Style.DrawText(Canvas, GetPlayerState(PlayerItem), CellLeft, Y, CellWidth, ItemHeight, 0, GetPlayerName(PlayerItem), 0);
	*/
}

void UAAScoreboard_FireTeamList::UpdateButton(AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	local AAA2_PlayerState* OwnerPRI;
	local AGP.AGP_PlayerStart PS;
	OwnerPRI = PlayerOwner().PlayerReplicationInfo;
	Buttons[i].WinLeft = 0.885;
	Buttons[i].WinTop = Y;
	if (PlayerItem != None)
	{
		if (PlayerItem == OwnerPRI)
		{
			Buttons[i].bVisible = False;
		}
		else
		{
			if (Team.WantsToSwap(PlayerItem, OwnerPRI))
			{
				Buttons[i].bVisible = True;
				Buttons[i].Caption = "";
				if (MenuState == 4)
				{
					Buttons[i].MenuStateChange(0);
				}
			}
			else
			{
				if (Team.WantsToSwap(OwnerPRI, PlayerItem))
				{
					Buttons[i].bVisible = True;
					Buttons[i].Caption = "";
					Buttons[i].MenuStateChange(4);
				}
				else
				{
					Buttons[i].bVisible = True;
					Buttons[i].Caption = "";
					if (MenuState == 4)
					{
						Buttons[i].MenuStateChange(0);
					}
				}
			}
		}
	}
	else
	{
		Buttons[i].bVisible = True;
		if (Buttons[i].Caption != "")
		{
			Buttons[i].Caption = "";
			Buttons[i].MenuStateChange(0);
		}
	}
	PS = Team.GetPlayerStart(FTIndex, i);
	if (PS != None)
	{
		if (PS.bSpecialForces)
		{
			if (!OwnerPRI.bQualifiedSF)
			{
				Buttons[i].MenuStateChange(4);
			}
		}
		if (PS.GetSpawnClass().Default.nativeWeapon == 4)
		{
			if (!OwnerPRI.bQualifiedSniper)
			{
				Buttons[i].MenuStateChange(4);
			}
		}
		if (PS.GetSpawnClass().Default.nativeWeapon == 8)
		{
			if (!OwnerPRI.bQualifiedJavelin)
			{
				Buttons[i].MenuStateChange(4);
			}
		}
	}
	*/
}

void UAAScoreboard_FireTeamList::Free()
{
	/*
	local int32 i;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Buttons[i] != None)
		{
			Buttons[i].Free();
		}
	}
	Free();
	*/
}

