// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIHUDRackItem/UIHUDRackItem.h"

UUIHUDRackItem::UUIHUDRackItem()
{

}

void UUIHUDRackItem::Destroyed()
{
	Super::Destroyed();
	_BorderTexture = nullptr;
}
void UUIHUDRackItem::Draw(UCanvas* Canvas)
{
	/*
	local Inventory Item;
	local int Width;
	local int Height;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	_cContainer = None;
	if (cFrame.cActor != None)
	{
		_cContainer = Pawn(cFrame.cActor).GetRackContainer(_iRackIndex);
	}
	if (_cContainer != None)
	{
		Item = _cContainer.getItemAtIndex(0);
		if (Item != None)
		{
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
			else
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				Canvas.DrawText("!ICON");
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
		else
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("!ITEM");
		}
	}
	else
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawText("!CON");
	}
	*/
}
void UUIHUDRackItem::SetBorderTexture(UMaterialInstance* Tex)
{
	_BorderTexture = Tex;
}
void UUIHUDRackItem::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIHUDRackItem::SetRackIndex(int32 Index)
{
	_iRackIndex = Index;
}
void UUIHUDRackItem::ScaleControl(UCanvas* Canvas)
{
	/*
	Super::ScaleControl(Canvas);
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