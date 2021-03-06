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
	float XL = 0;
	float YL = 0;
	int32 XPos = 0;
	int32 YPos = 0;
	float oldclipx = 0;
	float oldClipY = 0;
	int32 i = 0;
	float fCurrentTime = 0;
	float fLine = 0;
	/*
	fCurrentTime = cFrame->cHUD.Level.RealSeconds;
	if (fCurrentTime - _fLastDrawTime > 5)
	{
		iTopLine = 0;
		_fStartTime = fCurrentTime;
	}
	else
	{
		if (iTopLine > _sStringList.Num())
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
	Canvas.Font = cFrame->Fonts[2];
	YPos = _ScaledPos.Y;
	XPos = _ScaledPos.X;
	Canvas.SetPos(XPos + 100, YPos);
	for (i = 0; i < iNumLines; i++)
	{
		Canvas.TextSize(_sStringList[i + iTopLine], XL, YL);
		Canvas.SetPos(_ScaledPos.X + _ScaledPos.W - XL / 2, _ScaledPos.Y + iTextHeight * i - iTextHeight * fLine - iTopLine);
		if (i + iTopLine < _sStringList.Num() && _sStringList[i + iTopLine] != "")
		{
			Canvas.DrawText(_sStringList[i + iTopLine]);
		}
	}
	i = 0;
	*/
}

void UUIScrollingCredits::ScaleControl(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	float XL = 0;
	float YL = 0;
	Super::ScaleControl(Canvas);
	/*
	temp_font = Canvas.Font;
	Canvas.Font = cFrame->Fonts[2];
	Canvas.TextSize("WjgA", XL, YL);
	iTextHeight = YL;
	iNumLines = _ScaledPos.H / iTextHeight;
	Canvas.Font = temp_font;
	*/
}

void UUIScrollingCredits::AddLine(FString sString)
{
	//_sStringList[_sStringList.Num()] = sString;
}

void UUIScrollingCredits::SetTextFile(FString Filename)
{
	FString Line = "";
	int32 i = 0;
	/*
	_sStringList.RemoveAt(0, _sStringList.Num());
	if (!FOpen(Filename))
	{
		Log("Failed loading " + Filename);
		return;
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

