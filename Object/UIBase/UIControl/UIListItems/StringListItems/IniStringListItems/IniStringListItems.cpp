// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIListItems/StringListItems/IniStringListItems/IniStringListItems.h"

UIniStringListItems::UIniStringListItems()
{

}

void UIniStringListItems::Sort()
{
}
void UIniStringListItems::Draw(UCanvas* Canvas)
{
}
void UIniStringListItems::DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos)
{
	FString sString = "";
	float XL = 0;
	float YL = 0;
	UFont* temp_font = nullptr;
	/*
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
void UIniStringListItems::addItem(UObject* obj)
{
}
void UIniStringListItems::AddString(FString sString, int32 iCount)
{
	//sStringList[sStringList.Num()] = sString;
}
int32 UIniStringListItems::GetNumItems()
{
	return sStringList.Num();
}
int32 UIniStringListItems::GetWidth(int32 Index)
{
	return 0;
}

int32 UIniStringListItems::GetHeight(int32 Index)
{
	return iTextHeight;
}

void UIniStringListItems::ScaleControl(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	float XL = 0;
	float YL = 0;
	/*
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize("WjgA", XL, YL);
	iTextHeight = YL;
	Canvas.Font = temp_font;
	*/
}

void UIniStringListItems::SetIniFile(FString Filename, FString Section)
{
	int32 iLines = 0;
	int32 iCurLine = 0;
	FString sLine = "";
	/*
	iLines = GetPrivateProfileInt(Filename, Section, "Lines");
	Log("IniStringListItems::SetIniFile(" $ Filename $ ", " $ Section $ ") - iLines: " $ iLines);
	for (iCurLine = 0; iCurLine < iLines; iCurLine++)
	{
		sLine = "Line(" $ iCurLine $ ")";
		AddString(GetPrivateProfileString(Filename, Section, sLine), 0);
	}
	*/
}
