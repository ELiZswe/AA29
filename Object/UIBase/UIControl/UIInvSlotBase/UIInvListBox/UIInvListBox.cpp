// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvListBox/UIInvListBox.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvList/UIInvList.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "Engine/Canvas.h"

UUIInvListBox::UUIInvListBox()
{
	nSelection = -1;
	bFirstTime = true;
}

void UUIInvListBox::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_TexSel = nullptr;
	cScrollH = nullptr;
	cScrollV = nullptr;
	cInvList = nullptr;
}

void UUIInvListBox::CreateTexture()
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

bool UUIInvListBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	int32 sel;
	int32 item_id;
	int32 X;
	int32 Y;
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
				X = cFrame->cMouse->iMouseX - _ScaledPos.X / cInvList.GetWidth(0);
				Y = cFrame->cMouse->iMouseY - _ScaledPos.Y / cInvList.GetHeight(0);
				nButtonDownSlot = X + Y + nTopLine * cInvList.iItemsWidth;
			}
			if (Action == 3)
			{
				if (bButtonDown == true)
				{
					bButtonDown = false;
					X = cFrame->cMouse->iMouseX - _ScaledPos.X / cInvList.GetWidth(0);
					Y = cFrame->cMouse->iMouseY - _ScaledPos.Y / cInvList.GetHeight(0);
					sel = X + Y + nTopLine * cInvList.iItemsWidth;
					if (sel != nButtonDownSlot)
					{
						return true;
					}
					item_id = cInvList.GetItemID(sel);
					if (cFrame->GetItemID() == 0)
					{
						if (item_id != 0)
						{
							cFrame->SetItem(cInvList, sel, item_id);
							cInvList.SetItemID(sel, 0);
						}
					}
					else
					{
						if (item_id == 0)
						{
							if (CanObjectFitInSlot(cFrame->GetItemSize(), _iSlotSize))
							{
								cInvList.SetItemID(sel, cFrame->GetItemID());
								cFrame->SetItemID(0);
							}
						}
						else
						{
							if (CanObjectFitInSlot(cFrame->GetItemSize(), _iSlotSize))
							{
								cInvList.SetItemID(sel, cFrame->GetItemID());
								cFrame->SetItemID(item_id);
							}
						}
					}
				}
			}
			return true;
		}
		if (bButtonDown == true && Action == 3)
		{
			bButtonDown = false;
			return true;
		}
	}
	*/
	return false;
}

void UUIInvListBox::Draw(UCanvas* Canvas)
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
	else
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIBitmap - NO BITMAP " + sTexName);
		}
	}
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	if (cInvList != nullptr)
	{
		iItemHeight = cInvList.GetHeight(0);
		Canvas.Font = cFrame->GetProperSizeFont(Canvas);
		XPos = _ScaledPos.X;
		YPos = _ScaledPos.Y;
		max_height = _ScaledPos.Y + _ScaledPos.H;
		Canvas.SetClip(_ScaledPos.W + _ScaledPos.X, _ScaledPos.H + _ScaledPos.Y);
		i = 0;
		if (YPos < max_height && i + nTopLine < cInvList.GetNumItems())
		{
			if (bFirstTime)
		}
		{
			if (nSelection == i + nTopLine)
			{
				Canvas.SetPos(XPos, YPos);
				Canvas.DrawTile(_TexSel, _ScaledPos.W, iItemHeight, 0, 0, _Pos.W, _Pos.H);
			}
			cInvList.DrawItem(Canvas, i + nTopLine, XPos, YPos);
			YPos += iItemHeight;
			i++;
		}
		bFirstTime = false;
		Canvas.SetClip(oldclipx, oldClipY);
	}
	*/
}

void UUIInvListBox::AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type)
{
	/*
	if (Type == 1)
	{
		cScrollV = cScrollbar;
		cScrollV.SetParent(this);
	}
	if (Type == 2)
	{
		cScrollH = cScrollbar;
		cScrollH.SetParent(this);
	}
	*/
}

void UUIInvListBox::ScaleControl(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	float percentage = 0;
	/*
	ScaleControl(Canvas);
	Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	Canvas.TextSize("WjgA", XL, YL);
	if (cInvList != nullptr)
	{
		cInvList.ScaleControl(Canvas);
		YL = cInvList.GetHeight(0);
	}
	percentage = _ScaledPos.H / YL / cInvList.GetNumItems();
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

void UUIInvListBox::ChildMessage(float Value)
{
	/*
	if (cInvList != nullptr)
	{
		nTopLine = cInvList.GetNumItems() * Value;
	}
	*/
}

int32 UUIInvListBox::GetSelectedIndex()
{
	return nSelection;
}
void UUIInvListBox::SetList(UUIInvList* pInvList)
{
	cInvList = pInvList;
}
