// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_PlayersList/AABrowser_PlayersList.h"
#include "AA29/Object/Favorites/Favorites.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

UAABrowser_PlayersList::UAABrowser_PlayersList()
{
	ColumnHeadings = { "Honor",  "Name", "Score", "Ping" };
	InitColumnPerc = { 0.22, 0.34, 0.22, 0.22 };
	ExpandLastColumn = true;
}

void UAABrowser_PlayersList::OnGetPlayer(FGameSpyPlayerInfo& PlayerInfo, int32 aIndex)
{
}

FString UAABrowser_PlayersList::GetSortString(int32 aIndex)
{
	FString SortString = "";
	FGameSpyPlayerInfo PlayerInfo = FGameSpyPlayerInfo({});
	/*
	if (OnGetPlayer(PlayerInfo, aIndex))
	{
		switch(SortColumn)
		{
				case 0:
					SortString = PlayerInfo.Honor;
					PadLeft(SortString, 3, "0");
					break;
				case 1:
					SortString = PlayerInfo.Name;
					break;
				case 2:
					SortString = PlayerInfo.Score_Total;
					PadLeft(SortString, 5, "0");
					break;
				case 3:
					SortString = PlayerInfo.Ping;
					PadLeft(SortString, 5, "0");
					break;
				default:
		}
	}
	*/
	return SortString;
}

void UAABrowser_PlayersList::SetPlayerCount(int32 Count)
{
	/*
	int32 ItemIndex;
	Clear();
	for (ItemIndex = 0; ItemIndex < Count; ItemIndex++)
	{
		AddedItem();
	}
	*/
}

void UAABrowser_PlayersList::InternalOnReceivedPlayerList(int32 ListLength)
{
	//SetPlayerCount(ListLength);
}

bool UAABrowser_PlayersList::IsOnBattleBuddyList(FString PlayerName)
{
	UFavorites* aFavorites = nullptr;
	/*
	aFavorites = 'AABrowser_FavoritesPanel'.Default.Favorites;
	if (-1 == aFavorites.GetIndexOfBattleBuddy(PlayerName))
	{
		return false;
	}
	*/
	return true;
}

void UAABrowser_PlayersList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	float CellLeft = 0;
	float CellWidth = 0;
	UGUIStyles* DrawStyle = nullptr;
	FColor TempColor = FColor(0,0,0);
	FGameSpyPlayerInfo PlayerInfo = FGameSpyPlayerInfo({});
	/*
	if (bSelected)
	{
		DrawStyle = SelectedStyle;
		DrawStyle.Draw(Canvas, 3, X, Y - 2, W, H + 2);
	}
	else
	{
		DrawStyle = Style;
	}
	TempColor = DrawStyle.FontColors[MenuState];
	if (!OnGetPlayer(PlayerInfo, SortData[i].SortItem))
	{
		return;
	}
	if (Len(PlayerInfo.Name) == 0)
	{
		return;
	}
	if (IsOnBattleBuddyList(PlayerInfo.Name))
	{
		FavoritesStyle.Draw(Canvas, MenuState, X, Y - 2, W, H + 2);
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, PlayerInfo.Honor, FontScale);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, PlayerInfo.Name, FontScale);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, PlayerInfo.Score_Total, FontScale);
	GetCellLeftWidth(3, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, PlayerInfo.Ping, FontScale);
	DrawStyle.FontColors[MenuState] = TempColor;
	*/
}
