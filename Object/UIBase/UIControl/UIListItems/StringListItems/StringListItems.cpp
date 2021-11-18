// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIListItems/StringListItems/StringListItems.h"

UStringListItems::UStringListItems()
{

}



void UStringListItems::AddString(FString sString, int32 iPos)
{
	/*
	local int i;
	if (sString == "")
	{
		Return;
	}
	for (i = 0; i < sStringList.Length; i++)
	{
		if (sString == sStringList[i])
		{
			Return;
		}
	}
	sStringList[sStringList.Length] = sString;
	*/
	bSorted = false;
}
void UStringListItems::Sort()
{
	/*
	local string sTemp;
	local int A;
	local int B;
	for (A = 1; A < sStringList.Length; A++)
	{
		for (B = 1; B < sStringList.Length; B++)
		{
			if (Caps(sStringList[B]) < Caps(sStringList[B - 1]))
			{
				sTemp = sStringList[B];
				sStringList[B] = sStringList[B - 1];
				sStringList[B - 1] = sTemp;
			}
		}
	}
	bSorted = true;
	*/
}
void UStringListItems::Draw(UCanvas* Canvas)
{
}
void addItem(UObject* obj)
{
}
int32 UStringListItems::GetNumItems()
{
	if (bSorted == false)
	{
		return 0;
	}
	return sStringList.Num();
}
void UStringListItems::DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos)
{
	/*
	local string sString;
	local float XL;
	local float YL;
	local Font temp_font;
	if (bSorted == False)
	{
		Return;
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.SetPos(x_pos, y_pos);
	sString = sStringList[Position];
	Canvas.TextSize(sString, XL, YL);
	Canvas.SetPos(x_pos, y_pos);
	Canvas.DrawTextClipped(sString);
	Canvas.Font = temp_font;
	*/
}
int32 UStringListItems::GetWidth(int32 Index)
{
	return 0;
}
int32 UStringListItems::GetHeight(int32 Index)
{
	if (bSorted == false)
	{
		return 0;
	}
	else
	{
		return iTextHeight;
	}
}
void UStringListItems::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local float XL;
	local float YL;
	if (bSorted == False)
	{
		Return;
	}
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize("WjgA", XL, YL);
	iTextHeight = YL;
	Canvas.Font = temp_font;
	*/
}
FString UStringListItems::GetString(int32 Index)
{
	return sStringList[Index];
}
