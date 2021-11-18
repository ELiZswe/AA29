// All the original content belonged to the US Army


#include "AA29/Object/DrawOpBase/DrawOpText/DrawOpText.h"

UDrawOpText::UDrawOpText()
{
	FontName = "XInterface.UT2DefaultFont";
	MaxLines = 99;
	bWrapText = true;

}

void UDrawOpText::Draw(UCanvas* Canvas)
{
	/*
	local Font fnt;
	int32 i = 0;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	float textheight = 0;
	float StrHeight = 0;
	float StrWidth = 0;
	local TArray<FString> Lines;
	Super::Draw(Canvas);
	if (FontName != "")
	{
		fnt = GetFont(FontName, float(Canvas.SizeX));
		if (fnt != None)
		{
			Canvas.Font = fnt;
		}
	}
	Canvas.FontScaleX = 0.9;
	Canvas.FontScaleY = 0.9;
	X = (Lft * float(Canvas.SizeX));
	Y = (Top * float(Canvas.SizeY));
	XL = (Width * float(Canvas.SizeX));
	YL = (Height * float(Canvas.SizeY));
	Canvas.StrLen(Text, StrWidth, StrHeight);
	if (bWrapText)
	{
		Canvas.WrapStringToArray(Text, Lines, XL, "|");
	}
	else
	{
		Lines[0] = Text;
	}
	textheight = (StrHeight * float(Lines.Length));
	switch (VertAlign)
	{
	case 1:
		Y = (Y + ((YL - textheight) / 2));
		break;
	case 2:
		Y = ((Y + YL) - textheight);
		break;
	default:
	}
	for (i = 0; i < Lines.Length; i++)
	{
		Canvas.StrLen(Lines[i], StrWidth, StrHeight);
		switch (Justification)
		{
		case 0:
			Canvas.SetPos(X, Y);
			break;
		case 1:
			Canvas.SetPos((X + ((XL - StrWidth) / 2)), Y);
			break;
		case 2:
			Canvas.SetPos(((X + XL) - StrWidth), Y);
			break;
		default:
		}
		Canvas.DrawText(Lines[i]);
		Y += StrHeight;
	}
	*/
}
