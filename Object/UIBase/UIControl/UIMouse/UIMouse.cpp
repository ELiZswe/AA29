// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"

UUIMouse::UUIMouse()
{
	_bAllowScaling = false;
}

void UUIMouse::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_BusyTexture = nullptr;
}
void UUIMouse::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(_sBitmapName, Class'Texture'));
	}
	if (_BusyTexture == nullptr)
	{
		//_BusyTexture = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_elements3", Class'Texture'));
	}
}
void UUIMouse::SetMouse(int32 mX, int32 mY)
{
	if (mX == iMouseX && mY == iMouseY)
	{
		_bHasMoved = false;
	}
	else
	{
		_bHasMoved = true;
	}
	iMouseX = mX;
	iMouseY = mY;
}

void UUIMouse::Draw(UCanvas* Canvas)
{
	AInventory* held_item = nullptr;
	int32 PosX = 0;
	int32 PosY = 0;
	int32 Width = 0;
	int32 Height = 0;
	int32 oldstyle = 0;
	/*
	Canvas.SetPos(iMouseX, iMouseY);
	if (_bDebug)
	{
		Canvas.DrawText(iMouseX + " " + iMouseY + " " + _Texture);
	}
	if (_Texture != nullptr)
	{
		held_item = cFrame->GetHeldItem();
		if (held_item != nullptr)
		{
			oldstyle = Canvas.Style;
			Canvas.Style = 3;
			Canvas.SetPos(iMouseX, iMouseY);
			if (held_item.isLarge())
			{
				PosX = iMouseX - 128 * cFrame->fScaleX;
				PosY = iMouseY - 32 * cFrame->fScaleY;
				Canvas.SetPos(PosX, PosY);
				Width = 256 * cFrame->fScaleX;
				Height = 64 * cFrame->fScaleY;
				Canvas.DrawTile(held_item.IconMaterial, Width, Height, 0, 0, 256, 64);
				Canvas.SetPos(PosX, PosY);
			}
			else
			{
				PosX = iMouseX - 32 * cFrame->fScaleX;
				PosY = iMouseY - 32 * cFrame->fScaleY;
				Canvas.SetPos(PosX, PosY);
				Width = 64 * cFrame->fScaleX;
				Height = 64 * cFrame->fScaleY;
				Canvas.DrawTile(held_item.IconMaterial, Width, Height, 0, 0, 64, 64);
				Canvas.SetPos(PosX, PosY);
			}
			Canvas.Style = oldstyle;
			if (held_item->IsA(AAmmunition::StaticClass()))
			{
				Canvas.DrawText(Cast<AAmmunition>(held_item).AmmoAmount);
			}
			if (held_item->IsA(AWeapon::StaticClass()))
			{
				if (Cast<AWeapon>(held_item).GetCurrentAmmoType() != nullptr)
				{
					Canvas.DrawText(Cast<AWeapon>(held_item).GetCurrentAmmoType().AmmoAmount);
				}
			}
			Canvas.SetPos(iMouseX, iMouseY);
			Canvas.DrawText("item: " + held_item.ItemName);
		}
		Canvas.SetPos(iMouseX, iMouseY);
		if (_bBusy)
		{
			Canvas.DrawTile(_BusyTexture, _ScaledPos.W, _ScaledPos.H, 48, 16, 32, 32);
			bDrawnBusy = true;
		}
		else
		{
			Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
			bDrawnBusy = false;
		}
		if (cFrame->GetItemID() != 0)
		{
			Canvas.DrawText("InvID: " + cFrame->cInvDef.GetItemNameFromID(cFrame->GetItemID()) + " " + cFrame->cInvDef.GetItemSize(cFrame->GetItemID()));
		}
	}
	else
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIMouse - NO BITMAP " + _sBitmapName);
		}
	}
	*/
}
bool UUIMouse::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUIMouse::SetBitmapString(FString Bitmap)
{
	_sBitmapName = Bitmap;
}
bool UUIMouse::HasMouseMoved()
{
	return _bHasMoved;
}
void UUIMouse::SetBusy(bool busy)
{
	_bBusy = busy;
}
