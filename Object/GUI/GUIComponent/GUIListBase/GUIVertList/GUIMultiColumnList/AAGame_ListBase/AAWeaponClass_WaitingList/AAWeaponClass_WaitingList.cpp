// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGame_ListBase/AAWeaponClass_WaitingList/AAWeaponClass_WaitingList.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/MyEnums.h"
#include "Engine/Canvas.h"

UAAWeaponClass_WaitingList::UAAWeaponClass_WaitingList()
{
	
	ColumnHeadings = { "", "Awaiting Selection", "Honor", "Score", "Time" };
	InitColumnPerc = { 0.05, 0.5, 0.15, 0.15, 0.15 };
	ItemCount = 32;
	//__OnDrawItem__Delegate = "AAWeaponClass_WaitingList.InternalOnDrawItem";
	StyleName = "AAUnitBox";
	RenderWeight = 1;
}

void UAAWeaponClass_WaitingList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	float CellLeft = 0;
	float CellWidth = 0;
	AAA2_PlayerState* PlayerItem = nullptr;
	float IconX = 0;
	float IconY = 0;
	UMaterialInstance* Icon = nullptr;
	EMenuState PlayerState = EMenuState::MSAT_Blurry ;
	AAGP_TeamInfo* PlayerTeam = nullptr;
	APlayerController* PC = nullptr;
	float IH = 0;
	PC = PlayerOwner();
	/*
	if (PC.PlayerReplicationInfo != nullptr)
	{
		PlayerTeam = Cast<AGP_TeamInfo>(PC.PlayerReplicationInfo.Team);
	}
	if (PlayerTeam == nullptr)
	{
		return;
	}
	PlayerItem = PlayerTeam.GetNoRequest(i);
	if (PlayerItem == nullptr)
	{
		return;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IH = ItemHeight - 2;
	IconX = CellLeft;
	IconY = Y + ItemHeight - IH / 2;
	Icon = GetGroupIcon(PlayerItem);
	if (Icon != nullptr)
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
