// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIListItemBox/UIListItemBox.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "AA29/Object/UIBase/UIControl/UIListItems/UIListItems.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "Engine/Canvas.h"

UUIListItemBox::UUIListItemBox()
{
	nSelection = -1;
	bFirstTime = true;
}

void UUIListItemBox::Destroyed()
{
	Super::Destroyed();
	cListItems = nullptr;
	_Texture = nullptr;
	_Texture2 = nullptr;
	cScrollH = nullptr;
	cScrollV = nullptr;
}

void UUIListItemBox::MouseMove(int32 mX, int32 mY)
{
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame->SetMouseOver(this);
	}
	else
	{
		_bButtonDown = false;
	}
}

void UUIListItemBox::SetListItems(UUIListItems* pListItems)
{
	cListItems = pListItems;
}

bool UUIListItemBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
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
			}
			if (Action == 3)
			{
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
					sel = cFrame->cMouse->iMouseY - _ScaledPos.Y / iItemHeight + nTopLine;
					if (nSelection == sel)
					{
						cFrame->Notify(_iUIEvent);
					}
					else
					{
						nSelection = sel;
					}
				}
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

void UUIListItemBox::Draw(UCanvas* Canvas)
{
	int32 XPos = 0;
	int32 YPos = 0;
	float oldclipx = 0;
	float oldClipY = 0;
	int32 i = 0;
	float max_height = 0;
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
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	if (cListItems != nullptr)
	{
		iItemHeight = cListItems.GetHeight(0);
		Canvas.Font = cFrame->GetProperSizeFont(Canvas);
		XPos = _ScaledPos.X;
		YPos = _ScaledPos.Y;
		max_height = _ScaledPos.Y + _ScaledPos.H;
		Canvas.SetClip(_ScaledPos.W + _ScaledPos.X, _ScaledPos.H + _ScaledPos.Y);
		i = 0;
		if (YPos < max_height && i + nTopLine < cListItems.GetNumItems())
		{
			if (bFirstTime)
		}
		{
			if (nSelection == i + nTopLine)
			{
				Canvas.SetPos(XPos, YPos);
				Canvas.DrawTile(_Texture2, _ScaledPos.W, iItemHeight, 0, 0, _Pos.W, _Pos.H);
			}
			cListItems.DrawItem(Canvas, i + nTopLine, XPos, YPos);
			YPos += iItemHeight;
			i++;
		}
		bFirstTime = false;
		Canvas.SetClip(oldclipx, oldClipY);
	}
	*/
}

void UUIListItemBox::AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type)
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

void UUIListItemBox::ScaleControl(UCanvas* Canvas)
{
	float YL = 0;
	float percentage = 0;
	/*
	ScaleControl(Canvas);
	if (cListItems != nullptr)
	{
		cListItems.ScaleControl(Canvas);
		YL = cListItems.GetHeight(0);
		percentage = _ScaledPos.H / YL / cListItems.GetNumItems();
		if (cScrollV != nullptr)
		{
			cScrollV.SizeThumb(percentage);
		}
		if (cScrollH != nullptr)
	}
	}
	{
	nTopLine = 0;
	*/
}

void UUIListItemBox::ChildMessage(float Value)
{
	if (cListItems != nullptr)
	{
		nTopLine = cListItems->GetNumItems() * Value;
	}
}

int32 UUIListItemBox::GetSelectedIndex()
{
	return nSelection;
}

void UUIListItemBox::SetItems(UUIListItems* pListItems)
{
	cListItems = pListItems;
}

void UUIListItemBox::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}

void UUIListItemBox::SetTexture2(UMaterialInstance* Tex)
{
	_Texture2 = Tex;
}
