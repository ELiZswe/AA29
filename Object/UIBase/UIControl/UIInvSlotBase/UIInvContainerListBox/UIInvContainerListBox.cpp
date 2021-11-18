// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerListBox/UIInvContainerListBox.h"

UUIInvContainerListBox::UUIInvContainerListBox()
{
	nSelection = -1;
	bFirstTime = true;
}


void UUIInvContainerListBox::Destroyed()
{
	Super::Destroyed();
	cScrollH = nullptr;
	cScrollV = nullptr;
	_BorderTexture = nullptr;
}
void UUIInvContainerListBox::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame.SetMouseOver(Self);
	}
	*/
}
void UUIInvContainerListBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int sel;
	local int X;
	local int Y;
	local Inventory Item;
	local Inventory held_item;
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
				X = cFrame.cMouse.iMouseX - _ScaledPos.X / iScaledItemWidth;
				Y = cFrame.cMouse.iMouseY - _ScaledPos.Y / iScaledItemHeight;
				nButtonDownSlot = X + Y + _iTopLine * iItemsWide;
			}
			if (Action == 3)
			{
				if (bButtonDown == True)
				{
					bButtonDown = False;
					X = cFrame.cMouse.iMouseX - _ScaledPos.X / iScaledItemWidth;
					Y = cFrame.cMouse.iMouseY - _ScaledPos.Y / iScaledItemHeight;
					sel = X + Y + _iTopLine * iItemsWide;
					if (sel != nButtonDownSlot)
					{
						Return True;
					}
					held_item = cFrame.GetHeldItem();
					if (_cContainer != None)
					{
						Item = _cContainer.getItemAtIndex(sel);
						if (held_item == None)
						{
							if (Item != None)
							{
								cFrame.SetHeldItem(Item);
								cFrame.SetHeldContainer(_cContainer);
							}
						}
						else
						{
							if (Item == None)
							{
								if (_cContainer.FindInventorySpace(held_item))
								{
									cFrame.GetHeldContainer().DeleteItem(held_item);
									_cContainer.addLastItem(held_item);
									cFrame.SetHeldItem(Item);
									cFrame.SetHeldContainer(_cContainer);
								}
							}
							else
							{
								if (Item == held_item)
								{
									held_item = None;
									cFrame.SetHeldItem(held_item);
								}
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
void UUIInvContainerListBox::Draw(UCanvas* Canvas)
{
	/*
	local int XPos;
	local int YPos;
	local float oldclipx;
	local float oldClipY;
	local int i;
	local float max_height;
	local Inventory Item;
	local int Position;
	local int A;
	local Font old_font;
	local int oldstyle;
	if (!_bEnabled)
	{
		Return;
	}
	ScaleScrollbars(Canvas);
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	if (_cContainer != None)
	{
		oldstyle = Canvas.Style;
		old_font = Canvas.Font;
		Canvas.Font = cFrame.GetProperSizeFont(Canvas);
		XPos = _ScaledPos.X;
		YPos = _ScaledPos.Y;
		max_height = _ScaledPos.Y + _ScaledPos.H;
		Canvas.SetClip(_ScaledPos.W + _ScaledPos.X, _ScaledPos.H + _ScaledPos.Y);
		i = 0;
		if (YPos < max_height && i + _iTopLine * iItemsWide < _cContainer.getUsedCapacity())
		{
			if (bFirstTime)
		}
		{
			if (nSelection == i + _iTopLine)
			{
				Canvas.SetPos(XPos, YPos);
				Canvas.DrawTile(_TexSel, iScaledItemWidth, iScaledItemHeight, 0, 0, _Pos.W, _Pos.H);
			}
			Position = i + _iTopLine * iItemsWide;
			for (A = 0; A < iItemsWide; A++)
			{
				Item = _cContainer.getItemAtIndex(Position + A);
				if (Item != None)
				{
					if (Item == cFrame.GetHeldItem())
					{
						Canvas.Style = 3;
					}
					else
					{
						Canvas.Style = oldstyle;
					}
					if (Item.IconMaterial != None)
					{
						Canvas.SetPos(XPos + A * iScaledItemWidth, YPos);
						if (_bLarge)
						{
							Canvas.DrawTile(Item.IconMaterial, iScaledItemWidth, iScaledItemHeight, 0, 0, 256, 64);
						}
						else
						{
							Canvas.DrawTile(Item.IconMaterial, iScaledItemWidth, iScaledItemHeight, 0, 0, 64, 64);
						}
					}
					Canvas.SetPos(XPos + A * iScaledItemWidth, YPos);
					if (Item.IsA('Ammunition'))
					{
						Canvas.DrawText(Position + A $ " " $ Ammunition(Item).AmmoAmount);
					}
					if (Item.IsA('Weapon'))
					{
						if (Weapon(Item).GetCurrentAmmoType() != None)
						{
							Canvas.DrawText(Weapon(Item).GetCurrentAmmoType().AmmoAmount);
						}
					}
					Item = None;
				}
			}
			YPos += iScaledItemHeight;
			i++;
		}
		bFirstTime = False;
		Canvas.SetClip(oldclipx, oldClipY);
		Canvas.Font = old_font;
		Canvas.Style = oldstyle;
	}
	else
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawText("NO CONTAINER");
	}
	if (_BorderTexture != None)
	{
		Canvas.SetPos(_BorderLeft.X, _BorderLeft.Y);
		Canvas.DrawTile(_BorderTexture, _BorderLeft.W, _BorderLeft.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderRight.X, _BorderRight.Y);
		Canvas.DrawTile(_BorderTexture, _BorderRight.W, _BorderRight.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderTop.X, _BorderTop.Y);
		Canvas.DrawTile(_BorderTexture, _BorderTop.W, _BorderTop.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderBottom.X, _BorderBottom.Y);
		Canvas.DrawTile(_BorderTexture, _BorderBottom.W, _BorderBottom.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	*/
}
void UUIInvContainerListBox::AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type)
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
void UUIInvContainerListBox::ScaleScrollbars(UCanvas* Canvas)
{
	/*
	local int iVal;
	local float fVal;
	local float percentage;
	if (_cContainer != None)
	{
		fVal = _cContainer.getUsedCapacity() / iItemsWide;
		iVal = fVal;
		if (fVal - iVal > 0)
		{
			iVal = iVal + 1;
		}
		else
		{
			if (!_cContainer.IsFull())
			{
				iVal = iVal + 1;
			}
		}
		percentage = iItemsHigh / iVal;
	}
	if (cScrollV != None)
	{
		cScrollV.SizeThumb(percentage);
	}
	if (cScrollH != None)
	}
	{
*/
}
void UUIInvContainerListBox::ChildMessage(float Value)
{
	/*
	local float fTopLine;
	if (_cContainer != None)
	{
		fTopLine = _cContainer.getUsedCapacity() - 1 * Value / iItemsWide;
		for (_iTopLine = fTopLine; _iTopLine < fTopLine; _iTopLine++)
		{
		}
	}
	*/
}
void UUIInvContainerListBox::GetSelectedIndex()
{
	//Return nSelection;
}
void UUIInvContainerListBox::SetBorderTexture(UMaterialInstance* Tex)
{
	_BorderTexture = Tex;
}
void UUIInvContainerListBox::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIInvContainerListBox::ScaleControl(UCanvas* Canvas)
{
	/*
	local int vbarwidth;
	ScaleControl(Canvas);
	ScaleScrollbars(Canvas);
	_iTopLine = 0;
	if (cScrollV != None)
	{
		cScrollV.ScaleControl(Canvas);
		vbarwidth = cScrollV._ScaledPos.W;
	}
	else
	{
		vbarwidth = 0;
	}
	_BorderLeft.X = _ScaledPos.X;
	_BorderLeft.Y = _ScaledPos.Y;
	_BorderLeft.W = 1;
	_BorderLeft.H = _ScaledPos.H;
	_BorderRight.X = _ScaledPos.X + _ScaledPos.W - 1 + vbarwidth;
	_BorderRight.Y = _ScaledPos.Y;
	_BorderRight.W = 1;
	_BorderRight.H = _ScaledPos.H;
	_BorderTop.X = _ScaledPos.X;
	_BorderTop.Y = _ScaledPos.Y;
	_BorderTop.W = _ScaledPos.W + vbarwidth;
	_BorderTop.H = 1;
	_BorderBottom.X = _ScaledPos.X;
	_BorderBottom.Y = _ScaledPos.Y + _ScaledPos.H - 1;
	_BorderBottom.W = _ScaledPos.W + vbarwidth;
	_BorderBottom.H = 1;
	_BorderLeft.X--;
	_BorderLeft.Y--;
	_BorderLeft.H += 2;
	_BorderRight.X++;
	_BorderRight.Y--;
	_BorderRight.H += 2;
	_BorderTop.X--;
	_BorderTop.Y--;
	_BorderTop.W += 2;
	_BorderBottom.X--;
	_BorderBottom.Y++;
	_BorderBottom.W += 2;
	*/
}