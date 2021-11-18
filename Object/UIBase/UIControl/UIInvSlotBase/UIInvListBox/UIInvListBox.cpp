// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvListBox/UIInvListBox.h"

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
void UUIInvListBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int sel;
	local int item_id;
	local int X;
	local int Y;
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
				X = cFrame.cMouse.iMouseX - _ScaledPos.X / cInvList.GetWidth(0);
				Y = cFrame.cMouse.iMouseY - _ScaledPos.Y / cInvList.GetHeight(0);
				nButtonDownSlot = X + Y + nTopLine * cInvList.iItemsWidth;
			}
			if (Action == 3)
			{
				if (bButtonDown == True)
				{
					bButtonDown = False;
					X = cFrame.cMouse.iMouseX - _ScaledPos.X / cInvList.GetWidth(0);
					Y = cFrame.cMouse.iMouseY - _ScaledPos.Y / cInvList.GetHeight(0);
					sel = X + Y + nTopLine * cInvList.iItemsWidth;
					if (sel != nButtonDownSlot)
					{
						Return True;
					}
					item_id = cInvList.GetItemID(sel);
					if (cFrame.GetItemID() == 0)
					{
						if (item_id != 0)
						{
							cFrame.SetItem(cInvList, sel, item_id);
							cInvList.SetItemID(sel, 0);
						}
					}
					else
					{
						if (item_id == 0)
						{
							if (CanObjectFitInSlot(cFrame.GetItemSize(), _iSlotSize))
							{
								cInvList.SetItemID(sel, cFrame.GetItemID());
								cFrame.SetItemID(0);
							}
						}
						else
						{
							if (CanObjectFitInSlot(cFrame.GetItemSize(), _iSlotSize))
							{
								cInvList.SetItemID(sel, cFrame.GetItemID());
								cFrame.SetItemID(item_id);
							}
						}
					}
				}
			}
			Return True;
		}
		if (bButtonDown == True && Action == 3)
		{
			bButtonDown = False;
			Return True;
		}
	}
	Return False;
	*/
}
void UUIInvListBox::Draw(UCanvas* Canvas)
{
	/*
	local int XPos;
	local int YPos;
	local float oldclipx;
	local float oldClipY;
	local int i;
	local float max_height;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	else
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIBitmap - NO BITMAP " $ sTexName);
		}
	}
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	if (cInvList != None)
	{
		iItemHeight = cInvList.GetHeight(0);
		Canvas.Font = cFrame.GetProperSizeFont(Canvas);
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
		bFirstTime = False;
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
		cScrollV.SetParent(Self);
	}
	if (Type == 2)
	{
		cScrollH = cScrollbar;
		cScrollH.SetParent(Self);
	}
	*/
}
void UUIInvListBox::ScaleControl(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	local float percentage;
	ScaleControl(Canvas);
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize("WjgA", XL, YL);
	if (cInvList != None)
	{
		cInvList.ScaleControl(Canvas);
		YL = cInvList.GetHeight(0);
	}
	percentage = _ScaledPos.H / YL / cInvList.GetNumItems();
	if (cScrollV != None)
	{
		cScrollV.SizeThumb(percentage);
	}
	if (cScrollH != None)
	}
	{
	nTopLine = 0;
	*/
}
void UUIInvListBox::ChildMessage(float Value)
{
	/*
	if (cInvList != None)
	{
		nTopLine = cInvList.GetNumItems() * Value;
	}
	*/
}
void UUIInvListBox::GetSelectedIndex()
{
	//Return nSelection;
}
void UUIInvListBox::SetList(UUIInvList* pInvList)
{
	cInvList = pInvList;
}
