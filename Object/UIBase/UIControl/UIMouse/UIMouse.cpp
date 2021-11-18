// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

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
	/*
	if (mX == iMouseX && mY == iMouseY)
	{
		_bHasMoved = False;
	}
	else
	{
		_bHasMoved = true;
	}
	iMouseX = mX;
	iMouseY = mY;
	*/
}
void UUIMouse::Draw(UCanvas* Canvas)
{
	/*
	local Inventory held_item;
	local int PosX;
	local int PosY;
	local int Width;
	local int Height;
	local int oldstyle;
	Canvas.SetPos(iMouseX, iMouseY);
	if (_bDebug)
	{
		Canvas.DrawText(iMouseX $ " " $ iMouseY $ " " $ _Texture);
	}
	if (_Texture != None)
	{
		held_item = cFrame.GetHeldItem();
		if (held_item != None)
		{
			oldstyle = Canvas.Style;
			Canvas.Style = 3;
			Canvas.SetPos(iMouseX, iMouseY);
			if (held_item.isLarge())
			{
				PosX = iMouseX - 128 * cFrame.fScaleX;
				PosY = iMouseY - 32 * cFrame.fScaleY;
				Canvas.SetPos(PosX, PosY);
				Width = 256 * cFrame.fScaleX;
				Height = 64 * cFrame.fScaleY;
				Canvas.DrawTile(held_item.IconMaterial, Width, Height, 0, 0, 256, 64);
				Canvas.SetPos(PosX, PosY);
			}
			else
			{
				PosX = iMouseX - 32 * cFrame.fScaleX;
				PosY = iMouseY - 32 * cFrame.fScaleY;
				Canvas.SetPos(PosX, PosY);
				Width = 64 * cFrame.fScaleX;
				Height = 64 * cFrame.fScaleY;
				Canvas.DrawTile(held_item.IconMaterial, Width, Height, 0, 0, 64, 64);
				Canvas.SetPos(PosX, PosY);
			}
			Canvas.Style = oldstyle;
			if (held_item.IsA('Ammunition'))
			{
				Canvas.DrawText(Ammunition(held_item).AmmoAmount);
			}
			if (held_item.IsA('Weapon'))
			{
				if (Weapon(held_item).GetCurrentAmmoType() != None)
				{
					Canvas.DrawText(Weapon(held_item).GetCurrentAmmoType().AmmoAmount);
				}
			}
			Canvas.SetPos(iMouseX, iMouseY);
			Canvas.DrawText("item: " $ held_item.ItemName);
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
			bDrawnBusy = False;
		}
		if (cFrame.GetItemID() != 0)
		{
			Canvas.DrawText("InvID: " $ cFrame.cInvDef.GetItemNameFromID(cFrame.GetItemID()) $ " " $ cFrame.cInvDef.GetItemSize(cFrame.GetItemID()));
		}
	}
	else
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIMouse - NO BITMAP " $ _sBitmapName);
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