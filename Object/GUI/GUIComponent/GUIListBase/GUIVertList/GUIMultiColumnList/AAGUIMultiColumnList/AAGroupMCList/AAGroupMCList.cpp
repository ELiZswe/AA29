// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AAGroupMCList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "Engine/Canvas.h"

UAAGroupMCList::UAAGroupMCList()
{
	MaxVisibleTeamEntries = 26;
	//__GetItemHeight__Delegate = "AAGroupMCList.InternalGetItemHeight";
}

float UAAGroupMCList::InternalGetItemHeight(UCanvas* C)
{
	if (WinHeight >= 1)
	{
		return FMath::RoundHalfFromZero(WinHeight / MaxVisibleTeamEntries);
	}
	else
	{
		return FMath::RoundHalfFromZero((WinHeight * C->SizeY) / MaxVisibleTeamEntries);
	}
	return 0;    //FAKE   /EliZ
}

void UAAGroupMCList::Initialize()
{
	bInitialized = true;
}
void UAAGroupMCList::ReInitialize()
{
	bInitialized = false;
	Initialize();
}

void UAAGroupMCList::SetGroupSize(int32 Group, int32 Size)
{
	int32 i = 0;
	int32 j = 0;
	bool bIsLastNonEmptyGroup = false;
	/*
	if (Groups.Num() <= Group)
	{
		Groups.Num() = Group + 1;
	}
	Groups[Group] = Size;
	ItemCount = 0;
	if (Separators.Num() > 0)
	{
		Separators.RemoveAt(0, Separators.Num());
	}
	for (i = 0; i < Groups.Num(); i++)
	{
		ItemCount += Groups[i];
		if (i != Groups.Num())
		{
			if (Groups[i] != 0)
			{
				bIsLastNonEmptyGroup = true;
				for (j = i + 1; j < Groups.Num(); j++)
				{
					if (Groups[j] != 0)
					{
						bIsLastNonEmptyGroup = false;
					}
				}
				if (!bIsLastNonEmptyGroup)
				{
					Separators[Separators.Num()] = ItemCount;
					ItemCount += 1;
				}
			}
		}
	}
	*/
}

int32 UAAGroupMCList::GetGroupSize(int32 Group)
{
	if (Group >= 0 || Group < Groups.Num())
	{
		return Groups[Group];
	}
	return 0;
}

bool UAAGroupMCList::IsSeparator(int32 ItemNum)
{
	int32 i = 0;
	for (i = 0; i < Separators.Num(); i++)
	{
		if (Separators[i] == ItemNum)
		{
			return true;
		}
	}
	return false;
}

void UAAGroupMCList::DrawSeparator(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
}

void UAAGroupMCList::DrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
}

void UAAGroupMCList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	if (IsSeparator(i))
	{
		DrawSeparator(Canvas, i, X, Y, W, H, bSelected, bPending);
	}
	else
	{
		DrawItem(Canvas, i, X, Y, W, H, bSelected, bPending);
	}
}

bool UAAGroupMCList::InternalOnClick(UGUIComponent* Sender)
{
	int32 NewIndex = 0;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex(true);
	SetIndex(NewIndex);
	return true;
}
