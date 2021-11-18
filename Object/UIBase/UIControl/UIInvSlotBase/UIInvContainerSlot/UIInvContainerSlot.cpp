// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerSlot/UIInvContainerSlot.h"

UUIInvContainerSlot::UUIInvContainerSlot()
{

}

void UUIInvContainerSlot::Destroyed()
{
	Super::Destroyed();
	_BorderTexture = nullptr;
}
void UUIInvContainerSlot::MouseMove(int32 mX, int32 mY)
{
	/*
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame.SetMouseOver(Self);
	}
	*/
}
void UUIInvContainerSlot::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int sel;
	local Inventory Item;
	local Inventory held_item;
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
			}
			if (Action == 3)
			{
				if (bButtonDown == True)
				{
					bButtonDown = False;
					if (_cContainer != None)
					{
						Item = _cContainer.getItemAtIndex(sel);
						held_item = cFrame.GetHeldItem();
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
									_cContainer.addItem(held_item);
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
void UUIInvContainerSlot::Draw(UCanvas* Canvas)
{
	/*
	local Inventory Item;
	local int Width;
	local int Height;
	local int oldstyle;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_cContainer != None)
	{
		oldstyle = Canvas.Style;
		Item = _cContainer.getItemAtIndex(0);
		if (Item != None)
		{
			if (Item == cFrame.GetHeldItem())
			{
				Canvas.Style = 3;
			}
			if (Item.IconMaterial != None)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (Item.isLarge())
				{
					Width = 256 * cFrame.fScaleX;
					Height = 64 * cFrame.fScaleY;
					Canvas.DrawTile(Item.IconMaterial, Width, Height, 0, 0, 256, 64);
				}
				else
				{
					Width = 64 * cFrame.fScaleX;
					Height = 64 * cFrame.fScaleY;
					Canvas.DrawTile(Item.IconMaterial, Width, Height, 0, 0, 64, 64);
				}
			}
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			if (Item.IsA('Ammunition'))
			{
				Canvas.DrawText(Ammunition(Item).AmmoAmount);
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
void UUIInvContainerSlot::SetBorderTexture(UMaterialInstance* Tex)
{
	_BorderTexture = Tex;
}
void UUIInvContainerSlot::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIInvContainerSlot::ScaleControl(UCanvas* Canvas)
{
	Super::ScaleControl(Canvas);
	/*
	_BorderLeft.X = _ScaledPos.X;
	_BorderLeft.Y = _ScaledPos.Y;
	_BorderLeft.W = 1;
	_BorderLeft.H = _ScaledPos.H;
	_BorderRight.X = _ScaledPos.X + _ScaledPos.W - 1;
	_BorderRight.Y = _ScaledPos.Y;
	_BorderRight.W = 1;
	_BorderRight.H = _ScaledPos.H;
	_BorderTop.X = _ScaledPos.X;
	_BorderTop.Y = _ScaledPos.Y;
	_BorderTop.W = _ScaledPos.W;
	_BorderTop.H = 1;
	_BorderBottom.X = _ScaledPos.X;
	_BorderBottom.Y = _ScaledPos.Y + _ScaledPos.H - 1;
	_BorderBottom.W = _ScaledPos.W;
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