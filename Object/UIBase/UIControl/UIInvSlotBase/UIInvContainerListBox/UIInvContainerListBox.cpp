// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerListBox/UIInvContainerListBox.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"

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
		return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame->SetMouseOver(this);
	}
	*/
}

bool UUIInvContainerListBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	int32 sel = 0;
	int32 X = 0;
	int32 Y = 0;
	AInventory* Item = nullptr;
	AInventory* held_item = nullptr;
	if (!_bEnabled)
	{
		return false;
	}
	/*
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
				X = cFrame->cMouse->iMouseX - _ScaledPos.X / iScaledItemWidth;
				Y = cFrame->cMouse->iMouseY - _ScaledPos.Y / iScaledItemHeight;
				nButtonDownSlot = X + Y + _iTopLine * iItemsWide;
			}
			if (Action == 3)
			{
				if (bButtonDown == true)
				{
					bButtonDown = false;
					X = cFrame->cMouse->iMouseX - _ScaledPos.X / iScaledItemWidth;
					Y = cFrame->cMouse->iMouseY - _ScaledPos.Y / iScaledItemHeight;
					sel = X + Y + _iTopLine * iItemsWide;
					if (sel != nButtonDownSlot)
					{
						return true;
					}
					held_item = cFrame->GetHeldItem();
					if (_cContainer != nullptr)
					{
						Item = _cContainer.getItemAtIndex(sel);
						if (held_item == nullptr)
						{
							if (Item != nullptr)
							{
								cFrame->SetHeldItem(Item);
								cFrame->SetHeldContainer(_cContainer);
							}
						}
						else
						{
							if (Item == nullptr)
							{
								if (_cContainer.FindInventorySpace(held_item))
								{
									cFrame->GetHeldContainer().DeleteItem(held_item);
									_cContainer.addLastItem(held_item);
									cFrame->SetHeldItem(Item);
									cFrame->SetHeldContainer(_cContainer);
								}
							}
							else
							{
								if (Item == held_item)
								{
									held_item = nullptr;
									cFrame->SetHeldItem(held_item);
								}
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

void UUIInvContainerListBox::Draw(UCanvas* Canvas)
{
	int32 XPos = 0;
	int32 YPos = 0;
	float oldclipx = 0;
	float oldClipY = 0;
	int32 i = 0;
	float max_height = 0;
	AInventory* Item = nullptr;
	int32 Position = 0;
	int32 A = 0;
	UFont* old_font = nullptr;
	int32 oldstyle = 0;
	if (!_bEnabled)
	{
		return;
	}
	/*
	ScaleScrollbars(Canvas);
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " + _Texture);
	}
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	if (_cContainer != nullptr)
	{
		oldstyle = Canvas.Style;
		old_font = Canvas.Font;
		Canvas.Font = cFrame->GetProperSizeFont(Canvas);
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
				if (Item != nullptr)
				{
					if (Item == cFrame->GetHeldItem())
					{
						Canvas.Style = 3;
					}
					else
					{
						Canvas.Style = oldstyle;
					}
					if (Item.IconMaterial != nullptr)
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
					if (Item->IsA(AAmmunition::StaticClass()))
					{
						Canvas.DrawText(Position + A + " " + Ammunition(Item).AmmoAmount);
					}
					if (Item->IsA(AWeapon::StaticClass()))
					{
						if (Cast<AWeapon>(Item).GetCurrentAmmoType() != nullptr)
						{
							Canvas.DrawText(Cast<AWeapon>(Item).GetCurrentAmmoType().AmmoAmount);
						}
					}
					Item = nullptr;
				}
			}
			YPos += iScaledItemHeight;
			i++;
		}
		bFirstTime = false;
		Canvas.SetClip(oldclipx, oldClipY);
		Canvas.Font = old_font;
		Canvas.Style = oldstyle;
	}
	else
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawText("NO CONTAINER");
	}
	if (_BorderTexture != nullptr)
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
		cScrollV.SetParent(this);
	}
	if (Type == 2)
	{
		cScrollH = cScrollbar;
		cScrollH.SetParent(this);
	}
	*/
}

void UUIInvContainerListBox::ScaleScrollbars(UCanvas* Canvas)
{
	int32 iVal = 0;
	float fVal = 0;
	float percentage = 0;
	/*
	if (_cContainer != nullptr)
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
	if (cScrollV != nullptr)
	{
		cScrollV.SizeThumb(percentage);
	}
	if (cScrollH != nullptr)
	}
	{
*/
}

void UUIInvContainerListBox::ChildMessage(float Value)
{
	float fTopLine = 0;
	/*
	if (_cContainer != nullptr)
	{
		fTopLine = _cContainer.getUsedCapacity() - 1 * Value / iItemsWide;
		for (_iTopLine = fTopLine; _iTopLine < fTopLine; _iTopLine++)
		{
		}
	}
	*/
}

int32 UUIInvContainerListBox::GetSelectedIndex()
{
	return nSelection;
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
	int32 vbarwidth;
	ScaleControl(Canvas);
	ScaleScrollbars(Canvas);
	_iTopLine = 0;
	if (cScrollV != nullptr)
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
