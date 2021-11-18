// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AdminPlayerList/AdminPlayerList.h"

UAdminPlayerList::UAdminPlayerList()
{
	ColumnHeadings = { "Player Name", "Unique ID", "IP" };
	InitColumnPerc = { 0.3, 0.4, 0.3 };
	SortColumn = -1;
	WinHeight = 1;
}



void UAdminPlayerList::Clear()
{
	/*
	MyPlayers.remove(0, MyPlayers.Length);
	Clear();
	*/
}
void UAdminPlayerList::Add(FString PlayerInfo)
{
	/*
	local string S;
	local int i;
	local int idx;
	idx = MyPlayers.Length;
	MyPlayers.Length = MyPlayers.Length + 1;
	i = InStr(PlayerInfo, Chr(27));
	S = Left(PlayerInfo, i);
	MyPlayers[idx].PlayerName = S;
	PlayerInfo = Right(PlayerInfo, Len(PlayerInfo) - i - 1);
	i = InStr(PlayerInfo, Chr(27));
	S = Left(PlayerInfo, i);
	MyPlayers[idx].PlayerID = S;
	PlayerInfo = Right(PlayerInfo, Len(PlayerInfo) - i - 1);
	MyPlayers[idx].PlayerIP = PlayerInfo;
	ItemCount++;
	AddedItem();
	*/
}
void UAdminPlayerList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	__OnDrawItem__Delegate = MyOnDrawItem;
	__OnKeyEvent__Delegate = InternalOnKeyEvent;
	InitComponent(MyController, MyOwner);
	SelStyle = Controller.GetStyle("SquareButton", FontScale);
	*/
}
void UAdminPlayerList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	if (bSelected)
	{
		Canvas.SetDrawColor(128, 8, 8, 255);
		Canvas.SetPos(X, Y - 2);
		Canvas.DrawTile(Controller.DefaultPens[0], W, H + 2, 0, 0, 1, 1);
		Canvas.SetDrawColor(255, 255, 255, 255);
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, X + CellLeft, Y, CellWidth, H, 0, MyPlayers[i].PlayerName, FontScale);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, X + CellLeft, Y, CellWidth, H, 0, MyPlayers[i].PlayerID, FontScale);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, X + CellLeft, Y, CellWidth, H, 0, MyPlayers[i].PlayerIP, FontScale);
	*/
}