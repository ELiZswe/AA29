// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvContainerSlot/UIInvContainerSlot.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"

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
		cFrame->SetMouseOver(this);
	}
	*/
}

bool UUIInvContainerSlot::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	int32 sel = 0;
	AInventory* Item = nullptr;
	AInventory* held_item = nullptr;
	/*
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
			}
			if (Action == 3)
			{
				if (bButtonDown == true)
				{
					bButtonDown = false;
					if (_cContainer != nullptr)
					{
						Item = _cContainer.getItemAtIndex(sel);
						held_item = cFrame->GetHeldItem();
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
									_cContainer.addItem(held_item);
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

void UUIInvContainerSlot::Draw(UCanvas* Canvas)
{
	AInventory* Item = nullptr;
	int32 Width = 0;
	int32 Height = 0;
	int32 oldstyle = 0;
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " + _Texture);
	}
	if (_cContainer != nullptr)
	{
		oldstyle = Canvas.Style;
		Item = _cContainer.getItemAtIndex(0);
		if (Item != nullptr)
		{
			if (Item == cFrame->GetHeldItem())
			{
				Canvas.Style = 3;
			}
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
