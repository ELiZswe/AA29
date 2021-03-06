// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIListItems/StringListItems/StringListItems.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UStringListItems::UStringListItems()
{

}

void UStringListItems::AddString(FString sString, int32 iPos)
{
	int32 i = 0;
	if (sString == "")
	{
		return;
	}
	for (i = 0; i < sStringList.Num(); i++)
	{
		if (sString == sStringList[i])
		{
			return;
		}
	}
	sStringList[sStringList.Num()] = sString;
	bSorted = false;
}

void UStringListItems::Sort()
{
	FString sTemp = "";
	int32 A = 0;
	int32 B = 0;
	for (A = 1; A < sStringList.Num(); A++)
	{
		for (B = 1; B < sStringList.Num(); B++)
		{
			/*
			if (Caps(sStringList[B]) < Caps(sStringList[B - 1]))
			{
				sTemp = sStringList[B];
				sStringList[B] = sStringList[B - 1];
				sStringList[B - 1] = sTemp;
			}
			*/
		}
	}
	bSorted = true;
}

void UStringListItems::Draw(UCanvas* Canvas)
{
}

void UStringListItems::addItem(UObject* obj)
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
	FString sString = "";
	float XL = 0;
	float YL = 0;
	UFont* temp_font = nullptr;
	if (bSorted == false)
	{
		return;
	}
	//temp_font = Canvas.Font;
	//Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	//Canvas.SetPos(x_pos, y_pos);
	sString = sStringList[Position];
	//Canvas.TextSize(sString, XL, YL);
	//Canvas.SetPos(x_pos, y_pos);
	//Canvas.DrawTextClipped(sString);
	//Canvas.Font = temp_font;
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
	UFont* temp_font = nullptr;
	float XL = 0;
	float YL = 0;
	if (bSorted == false)
	{
		return;
	}
	Super::ScaleControl(Canvas);
	//temp_font = Canvas.Font;
	//Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	//Canvas.TextSize("WjgA", XL, YL);
	iTextHeight = YL;
	//Canvas.Font = temp_font;
}

FString UStringListItems::GetString(int32 Index)
{
	return sStringList[Index];
}
