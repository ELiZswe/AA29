// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AAGroupMCList.h"

UAAGroupMCList::UAAGroupMCList()
{
	MaxVisibleTeamEntries = 26;
	//__GetItemHeight__Delegate = "AAGroupMCList.InternalGetItemHeight";
}


void UAAGroupMCList::InternalGetItemHeight(UCanvas* C)
{
	/*
	if (WinHeight >= 1)
	{
		Return Round(WinHeight / MaxVisibleTeamEntries);
	}
	else
	{
		Return Round(WinHeight * C.SizeY / MaxVisibleTeamEntries);
	}
	*/
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
	/*
	local int32 i;
	local int32 j;
	local bool bIsLastNonEmptyGroup;
	if (Groups.Length <= Group)
	{
		Groups.Length = Group + 1;
	}
	Groups[Group] = Size;
	ItemCount = 0;
	if (Separators.Length > 0)
	{
		Separators.remove(0, Separators.Length);
	}
	for (i = 0; i < Groups.Length; i++)
	{
		ItemCount += Groups[i];
		if (i != Groups.Length)
		{
			if (Groups[i] != 0)
			{
				bIsLastNonEmptyGroup = True;
				for (j = i + 1; j < Groups.Length; j++)
				{
					if (Groups[j] != 0)
					{
						bIsLastNonEmptyGroup = False;
					}
				}
				if (!bIsLastNonEmptyGroup)
				{
					Separators[Separators.Length] = ItemCount;
					ItemCount += 1;
				}
			}
		}
	}
	*/
}

int32 UAAGroupMCList::GetGroupSize(int32 Group)
{
	/*
	if (Group >= 0 || Group < Groups.Length)
	{
		Return Groups[Group];
	}
	*/
	return 0;
}

bool UAAGroupMCList::IsSeparator(int32 ItemNum)
{
	/*
	local int32 i;
	for (i = 0; i < Separators.Length; i++)
	{
		if (Separators[i] == ItemNum)
		{
			Return True;
		}
	}
	*/
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
	/*
	local int32 NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		Return False;
	}
	NewIndex = CalculateIndex(True);
	SetIndex(NewIndex);
	*/
	return true;
}