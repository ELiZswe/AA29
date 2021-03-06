// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIHUDRackItem/UIHUDRackItem.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"

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
	AInventory* Item = nullptr;
	int32 Width = 0;
	int32 Height = 0;
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " + _Texture);
	}
	_cContainer = nullptr;
	if (cFrame->cActor != nullptr)
	{
		_cContainer = Cast<APawn>(cFrame->cActor).GetRackContainer(_iRackIndex);
	}
	if (_cContainer != nullptr)
	{
		Item = _cContainer.getItemAtIndex(0);
		if (Item != nullptr)
		{
			if (Item.IconMaterial != nullptr)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (Item.isLarge())
				{
					Width = 256 * cFrame->fScaleX;
					Height = 64 * cFrame->fScaleY;
					Canvas.DrawTile(Item.IconMaterial, Width, Height, 0, 0, 256, 64);
				}
				else
				{
					Width = 64 * cFrame->fScaleX;
					Height = 64 * cFrame->fScaleY;
					Canvas.DrawTile(Item.IconMaterial, Width, Height, 0, 0, 64, 64);
				}
			}
			else
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				Canvas.DrawText("!ICON");
			}
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			if (Item->IsA(AAmmunition::StaticClass()))
			{
				Canvas.DrawText(Cast<AAmmunition>(Item).AmmoAmount);
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
