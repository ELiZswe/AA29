// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_PlayersList/Browser_PlayersList.h"

UBrowser_PlayersList::UBrowser_PlayersList()
{
	ColumnHeadings = {"Player Name", "Score", "Stats ID", "Ping"};
	InitColumnPerc = { 0.17, 0.11, 0.11, 0.11 };
}

void UBrowser_PlayersList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//__OnDrawItem__Delegate = MyOnDrawItem;
	//__OnKeyEvent__Delegate = InternalOnKeyEvent;
	//InitComponent(MyController, MyOwner);
}

void UBrowser_PlayersList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	GetCellLeftWidth(0, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyServersList.Servers[listitem].PlayerInfo[i].PlayerName, FontScale);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyServersList.Servers[listitem].PlayerInfo[i].Score, FontScale);
	if (MyServersList.Servers[listitem].PlayerInfo[i].StatsID != 0)
	{
		GetCellLeftWidth(2, CellLeft, CellWidth);
		Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyServersList.Servers[listitem].PlayerInfo[i].StatsID, FontScale);
	}
	GetCellLeftWidth(3, CellLeft, CellWidth);
	Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, H, 0, MyServersList.Servers[listitem].PlayerInfo[i].Ping, FontScale);
	*/
}

bool UBrowser_PlayersList::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	/*
	if (InternalOnKeyEvent(Key, State, Delta))
	{
		Return True;
	}
	if (State == 1)
	{
		Switch(Key)
		{
				case 13:
					MyServersList.Connect(False);
					Return True;
					break;
				case 116:
					MyPage.RefreshList();
					Return True;
					break;
				default:
		}
	}
	*/
	return false;

}