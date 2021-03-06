// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAWeaponClass_FireTeamList/AAWeaponClass_FireTeamList.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "Engine/Canvas.h"

UAAWeaponClass_FireTeamList::UAAWeaponClass_FireTeamList()
{
	ButtonHint = "Click here to select this slot";
	SelectCaption = "Select";
	RequestCaption = "Request";
	PendingCaption = "Pending";
	SwapCaption = "Swap";
	SwapRequestCaption = "Requesting";
	AcceptSwapCaption = "Accept Swap";
	ColumnHeadings = { "", "", "" };
	InitColumnPerc = { 0.2, 0.5, 0.3 };
	//__OnDrawItem__Delegate = "AAWeaponClass_FireTeamList.InternalOnDrawItem";
	StyleName = "AAUnitBox";
	RenderWeight = 1;
	bAcceptsInput = false;
	//__OnPreDraw__Delegate = "AAWeaponClass_FireTeamList.InternalOnPreDraw";
}

bool UAAWeaponClass_FireTeamList::ButtonClick(UGUIComponent* Sender)
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

bool UAAWeaponClass_FireTeamList::InternalOnPreDraw(UCanvas* Canvas)
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

void UAAWeaponClass_FireTeamList::InitList(AAGP_TeamInfo* FTTeam, int32 FTI)
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
		Buttons[i].Caption = SelectCaption;
		Buttons[i].Hint = ButtonHint;
		Buttons[i].WinWidth = 0.1;
		Buttons[i].InitComponent(Controller, this);
		Buttons[i].Opened(this);
		Buttons[i].__OnClick__Delegate = ButtonClick;
	}
	*/
}

void UAAWeaponClass_FireTeamList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
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
	UpdateButton(PlayerItem, i, X, Y, CellLeft, CellWidth);
	*/
}

void UAAWeaponClass_FireTeamList::DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
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

void UAAWeaponClass_FireTeamList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	if (PlayerItem == nullptr)
	{
		return;
	}
	Style.DrawText(Canvas, GetPlayerState(PlayerItem), CellLeft, Y, CellWidth, ItemHeight, 0, GetPlayerName(PlayerItem), 0);
	*/
}

void UAAWeaponClass_FireTeamList::UpdateButton(AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	AAA2_PlayerState* OwnerPRI = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	/*
	OwnerPRI = PlayerOwner().PlayerReplicationInfo;
	Buttons[i].WinLeft = 0.38;
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
				Buttons[i].Caption = AcceptSwapCaption;
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
					Buttons[i].Caption = SwapRequestCaption;
					Buttons[i].MenuStateChange(4);
				}
				else
				{
					Buttons[i].bVisible = true;
					Buttons[i].Caption = SwapCaption;
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
		if (Buttons[i].Caption != SelectCaption)
		{
			Buttons[i].Caption = SelectCaption;
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

void UAAWeaponClass_FireTeamList::Free()
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
	Super::Free();
	*/
}
