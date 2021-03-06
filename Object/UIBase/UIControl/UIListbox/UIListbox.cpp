// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIListbox/UIListbox.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "Engine/Canvas.h"

UUIListbox::UUIListbox()
{
	sStringList.SetNum(64);
	nSelection = -1;
}

static const int32 kMaxStrings = 64;

void UUIListbox::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_TexSel = nullptr;
	cScrollH = nullptr;
	cScrollV = nullptr;
}

void UUIListbox::AddString(FString sString)
{
	/*
	int32 i = 0;
	if (iNumStrings < 64)
	{
		for (i = 0; i < iNumStrings; i++)
		{
			if (sString == sStringList[i])
			{
				return;
			}
		}
		sStringList[iNumStrings] = sString;
		iNumStrings++;
		bSorted = false;
	}
	*/
}

void UUIListbox::Sort()
{
	/*
	FString sTemp;
	int32 A;
	int32 B;
	for (A = 1; A < iNumStrings; A++)
	{
		for (B = 1; B < iNumStrings; B++)
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

void UUIListbox::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(sTexName, Class'Texture'));
	}
	if (_TexSel == nullptr)
	{
		//_TexSel = Texture(DynamicLoadObject(sTexSelName, Class'Texture'));
	}
}

bool UUIListbox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	int32 sel;
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				sel = cFrame->cMouse->iMouseY - _ScaledPos.Y / fTextHeight + nTopLine;
				if (nSelection == sel)
				{
					cFrame->Notify(_iUIEvent);
				}
				else
				{
					nSelection = sel;
				}
			}
			if (Action == 3)
			{
				_bButtonDown = false;
			}
			return true;
		}
		if (_bButtonDown == true && Action == 3)
		{
			_bButtonDown = false;
			return true;
		}
	}
	*/
	return false;
}

void UUIListbox::Draw(UCanvas* Canvas)
{
	FString sString;
	float XL = 0;
	float YL = 0;
	int32 XPos = 0;
	int32 YPos = 0;
	float oldclipx = 0;
	float oldClipY = 0;
	int32 i = 0;
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " + _Texture);
	}
	if (_Texture != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	else
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIBitmap - NO BITMAP " + sTexName);
		}
	}
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	Canvas.SetClip(_ScaledPos.W + _ScaledPos.X, _ScaledPos.H + _ScaledPos.Y);
	Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	YPos = _ScaledPos.Y;
	XPos = _ScaledPos.X;
	Canvas.SetPos(0, YPos);
	Canvas.TextSize("WjgA", XL, YL);
	fTextHeight = YL;
	i = 0;
	if (YPos < _ScaledPos.Y + _ScaledPos.H && i + nTopLine < iNumStrings)
	{
		sString = sStringList[i + nTopLine];
		Canvas.TextSize(sString, XL, YL);
		if (nSelection == i + nTopLine)
		{
			Canvas.SetPos(XPos, YPos);
			Canvas.DrawTileClipped(_TexSel, XL, YL, 0, 0, _Pos.W, _Pos.H);
		}
		Canvas.SetPos(XPos, YPos);
		Canvas.DrawTextClipped(sString);
		YPos += fTextHeight;
		i++;
	}
	Canvas.SetClip(oldclipx, oldClipY);
	*/
}

void UUIListbox::AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type)
{
	if (Type == 1)
	{
		cScrollV = cScrollbar;
		cScrollV->SetParent(this);
	}
	if (Type == 2)
	{
		cScrollH = cScrollbar;
		cScrollH->SetParent(this);
	}
}

void UUIListbox::ScaleControl(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	float percentage = 0;
	/*
	ScaleControl(Canvas);
	Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	Canvas.TextSize("WjgA", XL, YL);
	percentage = _ScaledPos.H / YL / iNumStrings;
	if (cScrollV != nullptr)
	{
		cScrollV.SizeThumb(percentage);
	}
	if (cScrollH != nullptr)
	}
	{
	nTopLine = 0;
	*/
}

void UUIListbox::ChildMessage(float Value)
{
	nTopLine = iNumStrings * Value;
}

FString UUIListbox::GetSelectedString()
{
	if (nSelection == -1)
	{
		return "";
	}
	else
	{
		return sStringList[nSelection];
	}
}
