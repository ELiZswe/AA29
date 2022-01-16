// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAScoreboard_FireTeamList/AAScoreboard_FireTeamList.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

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
	int32 i = 0;
	for (i = 0; i < Buttons.Num(); i++)
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
	int32 i = 0;
	if (Style != nullptr)
	{
		WinHeight = 1 + Style.BorderOffsets[1] + Style.BorderOffsets[3] + ItemHeight * ItemCount;
	}
	else
	{
		WinHeight = 1 + ItemHeight * ItemCount;
	}
	for (i = 0; i < Buttons.Num(); i++)
	{
		Buttons[i].WinHeight = ItemHeight;
	}
	*/
	return true;
}

void UAAScoreboard_FireTeamList::InitList(AAGP_TeamInfo* FTTeam, int32 FTI)
{
	/*
	int32 i = 0;
	Team = FTTeam;
	FTIndex = FTI;
	ItemCount = Team.FTCount[FTIndex];
	for (i = 0; i < ItemCount; i++)
	{
		Buttons[i] = new () UGUIButton::StaticClass();
		Buttons[i].RenderWeight = 4;
		Buttons[i].StyleName = "MainMenuButton";
		Buttons[i].Caption = "";
		Buttons[i].Hint = ButtonHint;
		Buttons[i].WinWidth = 0.04;
		Buttons[i].InitComponent(Controller, Self);
		Buttons[i].Opened(this);
		Buttons[i].__OnClick__Delegate = ButtonClick;
	}
	*/
}

void UAAScoreboard_FireTeamList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	float CellLeft = 0;
	float CellWidth = 0;
	AAA2_PlayerState* PlayerItem = nullptr;
	/*
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
	UMaterialInstance* Icon = nullptr;
	float IH = 0;
	float IconX = 0;
	float IconY = 0;
	AAGP_PlayerStart* PS = nullptr;
	/*
	IH = ItemHeight - 2;
	IconX = CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Icon = GetGroupIcon(PlayerItem);
	if (Icon != nullptr)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
	}
	PS = Team.GetPlayerStart(FTIndex, i);
	if (PS != nullptr)
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
	if (Icon != nullptr)
	{
		Canvas.SetPos(IconX, IconY);
		Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
	}
	*/
}

void UAAScoreboard_FireTeamList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	if (PlayerItem == nullptr)
	{
		return;
	}
	//Style.DrawText(Canvas, GetPlayerState(PlayerItem), CellLeft, Y, CellWidth, ItemHeight, 0, GetPlayerName(PlayerItem), 0);
}

void UAAScoreboard_FireTeamList::UpdateButton(AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	AAA2_PlayerState* OwnerPRI = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	/*
	OwnerPRI = PlayerOwner().PlayerReplicationInfo;
	Buttons[i].WinLeft = 0.885;
	Buttons[i].WinTop = Y;
	if (PlayerItem != nullptr)
	{
		if (PlayerItem == OwnerPRI)
		{
			Buttons[i].bVisible = false;
		}
		else
		{
			if (Team.WantsToSwap(PlayerItem, OwnerPRI))
			{
				Buttons[i].bVisible = true;
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
					Buttons[i].bVisible = true;
					Buttons[i].Caption = "";
					Buttons[i].MenuStateChange(4);
				}
				else
				{
					Buttons[i].bVisible = true;
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
		Buttons[i].bVisible = true;
		if (Buttons[i].Caption != "")
		{
			Buttons[i].Caption = "";
			Buttons[i].MenuStateChange(0);
		}
	}
	PS = Team.GetPlayerStart(FTIndex, i);
	if (PS != nullptr)
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
	int32 i = 0;
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i] != nullptr)
		{
			Buttons[i].Free();
		}
	}
	Free();
	*/
}

