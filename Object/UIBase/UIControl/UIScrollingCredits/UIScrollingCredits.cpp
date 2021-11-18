// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIScrollingCredits/UIScrollingCredits.h"

UUIScrollingCredits::UUIScrollingCredits()
{
	_fLastDrawTime = -10;
	_fScrollRate = 2;
}


void UUIScrollingCredits::Destroyed()
{
	Super::Destroyed();
	_sStringList.SetNum(0);
}

void UUIScrollingCredits::Draw(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	local int XPos;
	local int YPos;
	local float oldclipx;
	local float oldClipY;
	local int i;
	local float fCurrentTime;
	local float fLine;
	fCurrentTime = cFrame.cHUD.Level.RealSeconds;
	if (fCurrentTime - _fLastDrawTime > 5)
	{
		iTopLine = 0;
		_fStartTime = fCurrentTime;
	}
	else
	{
		if (iTopLine > _sStringList.Length)
		{
			iTopLine = 0;
			_fStartTime = fCurrentTime;
		}
	}
	fLine = fCurrentTime - _fStartTime * _fScrollRate;
	iTopLine = fLine;
	_fLastDrawTime = fCurrentTime;
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	Canvas.SetClip(_ScaledPos.W + _ScaledPos.X, _ScaledPos.H + _ScaledPos.Y);
	Canvas.Font = cFrame.Fonts[2];
	YPos = _ScaledPos.Y;
	XPos = _ScaledPos.X;
	Canvas.SetPos(XPos + 100, YPos);
	for (i = 0; i < iNumLines; i++)
	{
		Canvas.TextSize(_sStringList[i + iTopLine], XL, YL);
		Canvas.SetPos(_ScaledPos.X + _ScaledPos.W - XL / 2, _ScaledPos.Y + iTextHeight * i - iTextHeight * fLine - iTopLine);
		if (i + iTopLine < _sStringList.Length && _sStringList[i + iTopLine] != "")
		{
			Canvas.DrawText(_sStringList[i + iTopLine]);
		}
	}
	i = 0;
	*/
}
void UUIScrollingCredits::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local float XL;
	local float YL;
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[2];
	Canvas.TextSize("WjgA", XL, YL);
	iTextHeight = YL;
	iNumLines = _ScaledPos.H / iTextHeight;
	Canvas.Font = temp_font;
	*/
}
void UUIScrollingCredits::AddLine(FString sString)
{
	//_sStringList[_sStringList.Length] = sString;
}
void UUIScrollingCredits::SetTextFile(FString Filename)
{
	/*
	local string Line;
	local int i;
	_sStringList.remove(0, _sStringList.Length);
	if (!FOpen(Filename))
	{
		Log("Failed loading " $ Filename);
		Return;
	}
	i = 0;
	if (FReadLine(Line))
	{
		AddLine(Line);
		i++;
	}
	FClose();
	*/
}

