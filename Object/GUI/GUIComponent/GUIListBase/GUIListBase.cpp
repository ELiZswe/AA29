// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"

UGUIListBase::UGUIListBase()
{
	bHotTrackSound = true;
	bDrawSelectionBorder = true;
	bNotify = true;
	bInitializeList = true;
	bMultiSelect = true;
	SelectedStyleName = "ListSelection";
	SectionStyleName = "ListSection";
	OutlineStyleName = "ItemOutline";
	SelectedBKColor = FColor(200, 255, 255, 255);
	Index = -1;
	LastSelected = -1;
	DropIndex = -1;
	MightRemove = -1;
	FontScale = EFontScale::FNS_Small;
	StyleName = "NoBackground";
	bTabStop = true;
	bAcceptsInput = true;
	//__OnRightClick__Delegate = "GUIListBase.InternalOnRightClick";
	//__OnMousePressed__Delegate = "GUIListBase.InternalOnMousePressed";
	//__OnMouseRelease__Delegate = "GUIListBase.InternalOnMouseRelease";
	//__OnKeyEvent__Delegate = "GUIListBase.InternalOnKeyEvent";
	//__OnBeginDrag__Delegate = "GUIListBase.InternalOnBeginDrag";
	//__OnEndDrag__Delegate = "GUIListBase.InternalOnEndDrag";
	//__OnDragDrop__Delegate = "GUIListBase.InternalOnDragDrop";
	//__OnDragEnter__Delegate = "GUIListBase.InternalOnDragEnter";
	//__OnDragLeave__Delegate = "GUIListBase.InternalOnDragLeave";
	//__OnDragOver__Delegate = "GUIListBase.InternalOnDragOver";
}


void UGUIListBase::OnScrollBy(UGUIComponent* Sender)
{
}
void UGUIListBase::OnDrawItem(UCanvas* Canvas, int32 Item, float X, float Y, float W, float HT, bool bSelected, bool bPending)
{
}
void UGUIListBase::OnAdjustTop(UGUIComponent* Sender)
{
}
void UGUIListBase::OnTrack(UGUIComponent* Sender, int32 LastIndex)
{
}
void UGUIListBase::CheckLinkedObjects(UGUIListBase* List)
{
	/*
	if (IsValid())
	{
		EnableLinkedObjects();
	}
	else
	{
		DisableLinkedObjects();
	}
	*/
}
void UGUIListBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (SectionStyleName != "" && SectionStyle == None)
	{
		SectionStyle = MyController.GetStyle(SectionStyleName, FontScale);
	}
	if (SelectedStyleName != "" && SelectedStyle == None)
	{
		SelectedStyle = MyController.GetStyle(SelectedStyleName, FontScale);
	}
	if (OutlineStyleName != "" && OutlineStyle == None)
	{
		OutlineStyle = MyController.GetStyle(OutlineStyleName, FontScale);
	}
	*/
}
void UGUIListBase::Sort()
{
}
void UGUIListBase::SilentSetIndex(int32 NewIndex)
{
	/*
	local int i;
	bNotify = False;
	i = SetIndex(NewIndex);
	bNotify = true;
	Return i;
	*/
}
int32 UGUIListBase::CalculateIndex(bool bRequireValidIndex)
{
	return - 1;
}
void UGUIListBase::SetIndex(int32 NewIndex)
{
	/*
	if (!IsValidIndex(NewIndex))
	{
		Index = -1;
	}
	else
	{
		Index = NewIndex;
	}
	if (Index >= 0 && ItemsPerPage > 0)
	{
		if (Index < Top)
		{
			SetTopItem(Index);
		}
		else
		{
			if (Index >= Top + ItemsPerPage)
			{
				SetTopItem(Index - ItemsPerPage + 1);
			}
			else
			{
				if (bNotify)
				{
					CheckLinkedObjects(Self);
				}
			}
		}
	}
	else
	{
		if (bNotify)
		{
			CheckLinkedObjects(Self);
		}
		if (Top >= ItemCount)
		{
			home();
		}
	}
	IndexChanged(Self);
	Return Index;
	*/
}
void UGUIListBase::IndexChanged(UGUIComponent* Sender)
{
	/*
	if (bNotify)
	{
		OnChange(Sender);
	}
	LastSelected = Index;
	*/
}
void UGUIListBase::ClearPendingElements()
{
	/*
	if (bRepeatClick)
	{
		bRepeatClick = False;
		return;
	}
	SelectedItems.remove(0, SelectedItems.Length);
	DropIndex = -1;
	*/
}
void UGUIListBase::Clear()
{
	/*
	Top = 0;
	ItemCount = 0;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIListBase::MakeVisible(float Perc)
{
	/*
	SetTopItem(ItemCount - ItemsPerPage * Perc);
	*/
}
void UGUIListBase::SetTopItem(int32 Item)
{
	/*
	Top = Item;
	if (Top + ItemsPerPage >= ItemCount)
	{
		Top = ItemCount - ItemsPerPage;
	}
	if (Top < 0)
	{
		Top = 0;
	}
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	OnAdjustTop(Self);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIListBase::AddLinkObject(UGUIComponent* NewObj, bool bNoCheck)
{
	/*
	local int i;
	if (NewObj != None)
	{
		if (!bNoCheck)
		{
			for (i = 0; i < LinkedObjects.Length; i++)
			{
				if (LinkedObjects[i] == NewObj)
				{
					Return i;
				}
			}
		}
		i = LinkedObjects.Length;
		LinkedObjects[i] = NewObj;
		Return i;
	}
	Return - 1;
	*/
}
void UGUIListBase::InitLinkObjects(TArray<UGUIComponent*> NewObj, bool bNoCheck)
{
	/*
	local int i;
	if (!bNoCheck)
	{
		for (i = NewObj.Length - 1; i >= 0; i--)
		{
			if (NewObj[i] == None)
			{
				NewObj.remove(i, 1);
			}
		}
	}
	LinkedObjects = NewObj;
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}
void UGUIListBase::EnableLinkedObjects()
{
	/*
	local int i;
	for (i = 0; i < LinkedObjects.Length; i++)
	{
		if (LinkedObjects[i] != None)
		{
			EnableComponent(LinkedObjects[i]);
		}
	}
	*/
}
void UGUIListBase::DisableLinkedObjects()
{
	/*
	local int i;
	for (i = 0; i < LinkedObjects.Length; i++)
	{
		if (LinkedObjects[i] != None)
		{
			DisableComponent(LinkedObjects[i]);
		}
	}
	*/
}
bool UGUIListBase::IsValid()
{
	if (Index < 0 || Index >= ItemCount)
	{
		return false;
	}
	return true;
}
bool UGUIListBase::IsValidIndex(int32 i)
{
	if (i < 0 || i >= ItemCount)
	{
		return false;
	}
	return true;
}
FString UGUIListBase::AdditionalDebugString()
{
	return " SelectedItems:" + FString::FromInt(SelectedItems.Max());
}
FString UGUIListBase::getItemAtIndex(int32 idx)
{
	return "";
}
void UGUIListBase::GetPendingItems(bool bGuarantee)
{
	/*
	local int i;
	local array<String> items;
	if (DropState == 1 && Controller.DropSource == Self || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				items[items.Length] = getItemAtIndex(SelectedItems[i]);
			}
		}
		if (items.Length == 0 && IsValid())
		{
			items[0] = getItemAtIndex(Index);
		}
	}
	Return items;
	*/
}
void UGUIListBase::InternalOnKeyEvent(uint8 &Key, uint8 &KeyState, float Delta)
{
	/*
	local int i;
	local Interactions.EInputKey iKey;
	if (ItemsPerPage == 0 || ItemsPerPage == 0)
	{
		Return False;
	}
	iKey = Key;
	if (KeyState == 3 && iKey == 236)
	{
		WheelUp();
		Return True;
	}
	if (KeyState == 3 && iKey == 237)
	{
		WheelDown();
		Return True;
	}
	if (KeyState != 1)
	{
		Return False;
	}
	Switch(iKey)
	{
			case 38:
				if (Up())
				{
					Return True;
				}
				break;
			case 40:
				if (!Controller.ShiftPressed && Down())
				{
					Return True;
				}
				break;
			case 37:
				if (MoveLeft())
				{
					Return True;
				}
				break;
			case 39:
				if (MoveRight())
				{
					Return True;
				}
				break;
			case 36:
				home();
				Return True;
			case 35:
				End();
				Return True;
			case 33:
				PgUp();
				Return True;
			case 34:
				PgDn();
				Return True;
			case 65:
				if (Controller.CtrlPressed && bMultiSelect)
				{
					SelectedItems.Length = ItemCount;
					for (i = 0; i < ItemCount; i++)
					{
						SelectedItems[i] = i;
					}
					Return True;
				}
			default:
	}
	Return False;
	*/
}
bool UGUIListBase::Up()
{
	return false;
}
bool UGUIListBase::Down()
{
	return false;
}
bool UGUIListBase::MoveRight()
{
	return false;
}
bool UGUIListBase::MoveLeft()
{
	return false;
}
void UGUIListBase::WheelUp()
{
}
void UGUIListBase::WheelDown()
{
}
void UGUIListBase::PgUp()
{
}
void UGUIListBase::PgDn()
{
}
void UGUIListBase::home()
{
}
void UGUIListBase::End()
{
}
void UGUIListBase::InternalOnMousePressed(UGUIComponent* Sender, bool IsRepeat)
{
	/*
	local int i;
	local int j;
	local int k;
	local int NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		Return;
	}
	if (!IsRepeat && ItemCount > 0)
	{
		NewIndex = CalculateIndex(True);
		if (NewIndex == -1)
		{
			Return;
		}
		LastPressX = Controller.MouseX;
		LastPressY = Controller.MouseY;
		if (Controller.CtrlPressed && bMultiSelect && SelectedItems.Length == 0 && NewIndex != Index)
		{
			SelectedItems[SelectedItems.Length] = Index;
		}
		if (Controller.ShiftPressed && IsMultiSelect())
		{
			if (LastSelected == -1)
			{
				LastSelected = 0;
			}
			if (!Controller.CtrlPressed)
			{
				for (j = SelectedItems.Length - 1; j >= 0; j--)
				{
					if (SelectedItems[j] != Index)
					{
						SelectedItems.remove(j, 1);
					}
				}
			}
			for (j = Min(LastSelected, NewIndex); j <= Max(LastSelected, NewIndex); j++)
			{
				k = 0;
				if (k < SelectedItems.Length)
				{
					if (j == SelectedItems[k])
					{
					}
					if (j < SelectedItems[k])
					{
						SelectedItems.insert(k, 1);
						SelectedItems[k] = j;
					}
					else
					{
						k++;
					}
				}
				if (k == SelectedItems.Length)
				{
					SelectedItems[k] = j;
				}
			}
			Return;
		}
		else
		{
			LastSelected = NewIndex;
			if (IsMultiSelect())
			{
				Index = NewIndex;
			}
		}
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (SelectedItems[i] == NewIndex)
			{
			}
		}
		if (i < SelectedItems.Length)
		{
			MightRemove = i;
		}
		else
		{
			if (Controller.CtrlPressed && bMultiSelect)
			{
				i = 0;
				if (i < SelectedItems.Length)
				{
					if (NewIndex < SelectedItems[i])
					{
						SelectedItems.insert(i, 1);
						SelectedItems[i] = NewIndex;
					}
					else
					{
						i++;
					}
				}
				if (i == SelectedItems.Length)
				{
					SelectedItems[i] = NewIndex;
				}
			}
			else
			{
				if (SelectedItems.Length > 0 && MightRemove == -1)
				{
					SelectedItems.remove(0, SelectedItems.Length);
				}
			}
		}
	}
	*/
}
void UGUIListBase::InternalOnMouseRelease(UGUIComponent* Sender)
{
	/*
	if (MightRemove >= 0 && MightRemove < SelectedItems.Length)
	{
		SelectedItems.remove(MightRemove, 1);
	}
	MightRemove = -1;
	if (!IsMultiSelect())
	{
		ClearPendingElements();
	}
	*/
}
void UGUIListBase::InternalOnBeginDrag(UGUIComponent* Sender)
{
	/*
	if (Controller == None)
	{
		Return False;
	}
	if (Abs(LastPressX - Controller.MouseX) < 3 && Abs(LastPressY - Controller.MouseY) < 3)
	{
		Return False;
	}
	MightRemove = -1;
	if (SelectedItems.Length == 0)
	{
		CheckDragSelect();
	}
	UpdateOffset(ClientBounds[0], ClientBounds[1], ClientBounds[2], ClientBounds[3]);
	SetOutlineAlpha(128);
	Return True;
	*/
}
void UGUIListBase::CheckDragSelect()
{
	/*
	local int i;
	i = CalculateIndex(True);
	if (i < 0)
	{
		Return;
	}
	SetIndex(i);
	SelectedItems[SelectedItems.Length] = i;
	*/
}
void UGUIListBase::InternalOnRightClick(UGUIComponent* Sender)
{
	/*
	if (bDropSource && bMultiSelect && SelectedItems.Length > 0)
	{
		Controller.bIgnoreNextRelease = true;
	}
	Return True;
	*/
}
void UGUIListBase::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
}
bool UGUIListBase::InternalOnDragDrop(UGUIComponent* Sender)
{
	return false;
}
void UGUIListBase::InternalOnDragOver(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (Controller == None)
	{
		Return;
	}
	if (Controller.DropTarget == Self)
	{
		NewIndex = CalculateIndex(True);
		if (NewIndex == -1)
		{
			DropIndex = -1;
			Return;
		}
		if (Controller.DropSource != Self && SelectedItems.Length > 0)
		{
			SelectedItems.remove(0, SelectedItems.Length);
		}
		DropIndex = NewIndex;
	}
	*/
}
void UGUIListBase::InternalOnDragEnter(UGUIComponent* Sender)
{
	SetOutlineAlpha(255);
}
void UGUIListBase::InternalOnDragLeave(UGUIComponent* Sender)
{
	/*
	SetOutlineAlpha(128);
	if (DropIndex >= 0)
	{
		DropIndex = -1;
	}
	*/
}
bool UGUIListBase::IsMultiSelect()
{
	/*
	if (Controller == None)
	{
		Return False;
	}
	Return bDropSource&& bMultiSelect&& DropState != 1 && Controller.CtrlPressed || Controller.ShiftPressed && OnMultiSelect(Self);
	*/
	return false;			//FAKE   /ELiZ
}
void UGUIListBase::SetOutlineAlpha(int32 NewAlpha)
{
	/*
	local int i;
	if (OutlineStyle == None)
	{
		Return;
	}
	for (i = 0; i < 5; i++)
	{
		OutlineStyle.ImgColors[i].A = NewAlpha;
	}
	*/
}