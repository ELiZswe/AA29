// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAHelpList/AAHelpList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

UAAHelpList::UAAHelpList()
{
	TeamIndex = 255;
	MinVisibleTeamEntries = 9;
	
	ColumnHeadings = { "", "", "", "" };
	InitColumnPerc = { 0.32, 0.18, 0.18, 0.32 };
	SortColumn = -1;
	//__OnDrawItem__Delegate = "AAHelpList.InternalOnDrawItem";
	RenderWeight = 0.0001;
	bAcceptsInput = false;
	bNeverFocus = true;
	//__OnPreDraw__Delegate = "AAHelpList.InternalOnPreDraw";
}

void UAAHelpList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	ItemCount = 8;
	MaxVisibleTeamEntries = 8;
}

void UAAHelpList::Initialize()
{
	if (bInitialized)
	{
		return;
	}
	Super::Initialize();
}

void UAAHelpList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	if (!IsSeparator(i))
	{
		DrawItem(Canvas, i, X, Y, W, H, false, bPending);
	}
}

void UAAHelpList::DrawItem(UCanvas* C, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	int32 IconW = 0;
	int32 IconH = 0;
	int32 indexC1 = 0;
	int32 indexC2 = 0;
	float CellLeft = 0;
	float CellWidth = 0;
	float LocalItemHeight = 0;
	if (i < 2)
	{
		return;
	}
	/*
	LocalItemHeight = ItemHeight / 2 + ItemHeight / 4;
	indexC1 = i - 2;
	indexC2 = indexC1 + 6;
	C.Style = 6;
	C.SetDrawColor(255, 255, 255, 200);
	C.DrawColor.R = 127;
	C.DrawColor.G = 127;
	C.DrawColor.B = 127;
	C.DrawColor.A = 255;
	if (indexC1 < Icons.Num())
	{
		IconW = Icons[indexC1].MaterialUSize();
		IconH = Icons[indexC1].MaterialVSize();
		GetCellLeftWidth(1, CellLeft, CellWidth);
		C.SetPos(CellLeft, Y);
		C.DrawTile(Icons[indexC1], LocalItemHeight, LocalItemHeight, 0, 0, IconW, IconH);
		Style.DrawText(C, MenuState, CellLeft + LocalItemHeight + 0.2 * LocalItemHeight, Y, CellWidth, H, 0, IconDescriptions[indexC1], FontScale);
	}
	if (indexC2 < Icons.Num())
	{
		IconW = Icons[indexC2].MaterialUSize();
		IconH = Icons[indexC2].MaterialVSize();
		GetCellLeftWidth(2, CellLeft, CellWidth);
		C.SetPos(CellLeft, Y);
		C.DrawTile(Icons[indexC2], LocalItemHeight, LocalItemHeight, 0, 0, IconW, IconH);
		Style.DrawText(C, MenuState, CellLeft + LocalItemHeight + 0.2 * LocalItemHeight, Y, CellWidth, H, 0, IconDescriptions[indexC2], FontScale);
	}
	return;
	*/
}

float UAAHelpList::InternalGetItemHeight(UCanvas* C)
{
	MaxVisibleTeamEntries = ItemCount + 1;
	if (MaxVisibleTeamEntries < MinVisibleTeamEntries)
	{
		MaxVisibleTeamEntries = MinVisibleTeamEntries;
	}
	return Super::InternalGetItemHeight(C);
}
