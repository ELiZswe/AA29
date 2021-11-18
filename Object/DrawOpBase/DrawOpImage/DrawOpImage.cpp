// All the original content belonged to the US Army


#include "AA29/Object/DrawOpBase/DrawOpImage/DrawOpImage.h"

UDrawOpImage::UDrawOpImage()
{
	SubX = -1;
	SubY = -1;
	SubXL = -1;
	SubYL = -1;
}

void UDrawOpImage::Draw(UCanvas* Canvas)
{
	/*
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	float U = 0;
	float V = 0;
	float UL = 0;
	float VL = 0;
	if (Image == None)
	{
		return;
	}
	Canvas.Style = RenderStyle;
	Canvas.DrawColor = DrawColor;
	X = (Lft * float(Canvas.SizeX));
	Y = (Top * float(Canvas.SizeY));
	if (Width < 0)
	{
		XL = float(Image.MaterialUSize());
	}
	else
	{
		XL = (Width * float(Canvas.SizeX));
	}
	if (Height < 0)
	{
		YL = float(Image.MaterialVSize());
	}
	else
	{
		YL = (Height * float(Canvas.SizeY));
	}
	U = FMax(0, SubX);
	V = FMax(0, SubY);
	if (SubXL < 0)
	{
		UL = float(Image.MaterialUSize());
	}
	else
	{
		UL = SubXL;
	}
	if (SubYL < 0)
	{
		VL = float(Image.MaterialVSize());
	}
	else
	{
		VL = SubYL;
	}
	if (Justification == 1)
	{
		(X -= (XL / 2));
		(Y -= (YL / 2));
	}
	else
	{
		if (Justification == 2)
		{
			(X -= XL);
			(Y -= YL);
		}
	}
	Canvas.SetPos(X, Y);
	switch (ImageStyle)
	{
	case 0:
		Canvas.DrawTile(Image, XL, YL, U, V, UL, VL);
		break;
	case 1:
		Canvas.DrawTileStretched(Image, XL, YL);
		break;
	case 2:
		Canvas.DrawTileClipped(Image, XL, YL, U, V, UL, VL);
		break;
	default:
	}
	*/
}
