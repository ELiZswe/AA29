// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlot/UIInvSlot.h"

UUIInvSlot::UUIInvSlot()
{

}


void UUIInvSlot::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int item_id;
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
					if (cFrame.GetItemID() == 0)
					{
						if (_InvSlot.iItemID != 0)
						{
							cFrame.SetItem(Self, 0, _InvSlot.iItemID);
							_InvSlot.iItemID = 0;
						}
					}
					else
					{
						if (_InvSlot.iItemID == 0)
						{
							if (CanObjectFitInSlot(cFrame.GetItemSize(), _iSlotSize))
							{
								_InvSlot.iItemID = cFrame.GetItemID();
								cFrame.SetItemID(0);
							}
						}
						else
						{
							if (CanObjectFitInSlot(cFrame.GetItemSize(), _iSlotSize))
							{
								item_id = _InvSlot.iItemID;
								_InvSlot.iItemID = cFrame.GetItemID();
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
void UUIInvSlot::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Canvas.DrawText("ItemID: " $ cFrame.cInvDef.GetItemNameFromID(_InvSlot.iItemID));
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + 12);
	Canvas.DrawText("SlotSize: " $ _iSlotSize);
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Switch(cFrame.cInvDef.GetItemSize(_InvSlot.iItemID))
	{
			case 0:
				Canvas.DrawTile(cFrame.cInvDef.GetItemTexture(_InvSlot.iItemID), 64 * cFrame.fScaleX, 64 * cFrame.fScaleY, 0, 0, 64, 64);
				break;
			case 1:
				Canvas.DrawTile(cFrame.cInvDef.GetItemTexture(_InvSlot.iItemID), 256 * cFrame.fScaleX, 64 * cFrame.fScaleY, 0, 0, 256, 64);
				break;
			case 2:
				Canvas.DrawTile(cFrame.cInvDef.GetItemTexture(_InvSlot.iItemID), 128 * cFrame.fScaleX, 128 * cFrame.fScaleY, 0, 0, 128, 128);
				break;
			default:
	}
	*/
}
void UUIInvSlot::SetItem(int32 Index, int32 Item, int32 Param, int32 Size, float Weight)
{
	/*
	_InvSlot.iItemID = Item;
	_InvSlot.iParam = Param;
	_InvSlot.iSize = Size;
	_InvSlot.fWeight = Weight;
	*/
}
void UUIInvSlot::GetItemID(int32 Index)
{
	//Return _InvSlot.iItemID;
}
void UUIInvSlot::SetItemID(int32 Index, int32 Id)
{
	//_InvSlot.iItemID = Id;
}
void UUIInvSlot::GetItemParam(int32 Index)
{
	//Return _InvSlot.iParam;
}
void UUIInvSlot::SetItemParam(int32 Index, int32 Param)
{
	//_InvSlot.iParam = Param;
}
void UUIInvSlot::GetItemSize(int32 Index)
{
	//Return _InvSlot.iSize;
}
void UUIInvSlot::SetItemSize(int32 Index, int32 Size)
{
	//_InvSlot.iSize = Size;
}
