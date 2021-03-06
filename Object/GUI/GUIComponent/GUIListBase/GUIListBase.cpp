// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

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
	FontScale = EeFontScale::FNS_Small;
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
	if (IsValid())
	{
		EnableLinkedObjects();
	}
	else
	{
		DisableLinkedObjects();
	}
}

void UGUIListBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (SectionStyleName != "" && SectionStyle == nullptr)
	{
		SectionStyle = MyController->GetStyle(SectionStyleName, FontScale);
	}
	if (SelectedStyleName != "" && SelectedStyle == nullptr)
	{
		SelectedStyle = MyController->GetStyle(SelectedStyleName, FontScale);
	}
	if (OutlineStyleName != "" && OutlineStyle == nullptr)
	{
		OutlineStyle = MyController->GetStyle(OutlineStyleName, FontScale);
	}
}

void UGUIListBase::Sort()
{
}

int32 UGUIListBase::SilentSetIndex(int32 NewIndex)
{
	int32 i = 0;
	bNotify = false;
	i = SetIndex(NewIndex);
	bNotify = true;
	return i;
}

int32 UGUIListBase::CalculateIndex(bool bRequireValidIndex)
{
	return - 1;
}

int32 UGUIListBase::SetIndex(int32 NewIndex)
{
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
					CheckLinkedObjects(this);
				}
			}
		}
	}
	else
	{
		if (bNotify)
		{
			CheckLinkedObjects(this);
		}
		if (Top >= ItemCount)
		{
			home();
		}
	}
	IndexChanged(this);
	return Index;
}

void UGUIListBase::IndexChanged(UGUIComponent* Sender)
{
	if (bNotify)
	{
		OnChange(Sender);
	}
	LastSelected = Index;
}

void UGUIListBase::ClearPendingElements()
{
	if (bRepeatClick)
	{
		bRepeatClick = false;
		return;
	}
	SelectedItems.RemoveAt(0, SelectedItems.Num());
	DropIndex = -1;
}

void UGUIListBase::Clear()
{
	Top = 0;
	ItemCount = 0;
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIListBase::MakeVisible(float Perc)
{
	SetTopItem(ItemCount - ItemsPerPage * Perc);
}

void UGUIListBase::SetTopItem(int32 Item)
{
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
		CheckLinkedObjects(this);
	}
	OnAdjustTop(this);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

int32 UGUIListBase::AddLinkObject(UGUIComponent* NewObj, bool bNoCheck)
{
	int32 i = 0;
	if (NewObj != nullptr)
	{
		if (!bNoCheck)
		{
			for (i = 0; i < LinkedObjects.Num(); i++)
			{
				if (LinkedObjects[i] == NewObj)
				{
					return i;
				}
			}
		}
		i = LinkedObjects.Num();
		LinkedObjects[i] = NewObj;
		return i;
	}
	return - 1;
}

void UGUIListBase::InitLinkObjects(TArray<UGUIComponent*> NewObj, bool bNoCheck)
{
	int32 i = 0;
	if (!bNoCheck)
	{
		for (i = NewObj.Num() - 1; i >= 0; i--)
		{
			if (NewObj[i] == nullptr)
			{
				NewObj.RemoveAt(i, 1);
			}
		}
	}
	LinkedObjects = NewObj;
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

void UGUIListBase::EnableLinkedObjects()
{
	int32 i = 0;
	for (i = 0; i < LinkedObjects.Num(); i++)
	{
		if (LinkedObjects[i] != nullptr)
		{
			EnableComponent(LinkedObjects[i]);
		}
	}
}

void UGUIListBase::DisableLinkedObjects()
{
	int32 i = 0;
	for (i = 0; i < LinkedObjects.Num(); i++)
	{
		if (LinkedObjects[i] != nullptr)
		{
			DisableComponent(LinkedObjects[i]);
		}
	}
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

TArray<FString> UGUIListBase::GetPendingItems(bool bGuarantee)
{
	int32 i = 0;
	TArray<FString> items = {};
	if (DropState == EDropState::DRP_Source && Controller->DropSource == this || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				items[items.Num()] = getItemAtIndex(SelectedItems[i]);
			}
		}
		if (items.Num() == 0 && IsValid())
		{
			items[0] = getItemAtIndex(Index);
		}
	}
	return items;
}

bool UGUIListBase::InternalOnKeyEvent(EInputKey& Key, uint8 &KeyState, float Delta)
{
	int32 i = 0;
	EInputKey iKey = EInputKey::IK_None;
	if (ItemsPerPage == 0 || ItemsPerPage == 0)
	{
		return false;
	}
	iKey = Key;
	if (KeyState == 3 && iKey == EInputKey::IK_MouseWheelUp)
	{
		WheelUp();
		return true;
	}
	if (KeyState == 3 && iKey == EInputKey::IK_MouseWheelDown)
	{
		WheelDown();
		return true;
	}
	if (KeyState != 1)
	{
		return false;
	}
	switch(iKey)
	{
	case EInputKey::IK_Up:
			if (Up())
			{
				return true;
			}
			break;
		case EInputKey::IK_Down:
			if (!Controller->ShiftPressed && Down())
			{
				return true;
			}
			break;
		case EInputKey::IK_Left:
			if (MoveLeft())
			{
				return true;
			}
			break;
		case EInputKey::IK_Right:
			if (MoveRight())
			{
				return true;
			}
			break;
		case EInputKey::IK_Home:
			home();
			return true;
		case EInputKey::IK_End:
			End();
			return true;
		case EInputKey::IK_PageUp:
			PgUp();
			return true;
		case EInputKey::IK_PageDown:
			PgDn();
			return true;
		case EInputKey::IK_A:
			if (Controller->CtrlPressed && bMultiSelect)
			{
				SelectedItems.SetNum(ItemCount);
				for (i = 0; i < ItemCount; i++)
				{
					SelectedItems[i] = i;
				}
				return true;
			}
		default:
			break;
	}
	return false;
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
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	int32 NewIndex = 0;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return;
	}
	if (!IsRepeat && ItemCount > 0)
	{
		NewIndex = CalculateIndex(true);
		if (NewIndex == -1)
		{
			return;
		}
		LastPressX = Controller->MouseX;
		LastPressY = Controller->MouseY;
		if (Controller->CtrlPressed && bMultiSelect && SelectedItems.Num() == 0 && NewIndex != Index)
		{
			SelectedItems[SelectedItems.Num()] = Index;
		}
		if (Controller->ShiftPressed && IsMultiSelect())
		{
			if (LastSelected == -1)
			{
				LastSelected = 0;
			}
			if (!Controller->CtrlPressed)
			{
				for (j = SelectedItems.Num() - 1; j >= 0; j--)
				{
					if (SelectedItems[j] != Index)
					{
						SelectedItems.RemoveAt(j, 1);
					}
				}
			}
			for (j = FMath::Min(LastSelected, NewIndex); j <= FMath::Max(LastSelected, NewIndex); j++)
			{
				k = 0;
				if (k < SelectedItems.Num())
				{
					if (j == SelectedItems[k])
					{
					}
					if (j < SelectedItems[k])
					{
						//SelectedItems.insert(k, 1);
						SelectedItems[k] = j;
					}
					else
					{
						k++;
					}
				}
				if (k == SelectedItems.Num())
				{
					SelectedItems[k] = j;
				}
			}
			return;
		}
		else
		{
			LastSelected = NewIndex;
			if (IsMultiSelect())
			{
				Index = NewIndex;
			}
		}
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (SelectedItems[i] == NewIndex)
			{
			}
		}
		if (i < SelectedItems.Num())
		{
			MightRemove = i;
		}
		else
		{
			if (Controller->CtrlPressed && bMultiSelect)
			{
				i = 0;
				if (i < SelectedItems.Num())
				{
					if (NewIndex < SelectedItems[i])
					{
						//SelectedItems.insert(i, 1);
						SelectedItems[i] = NewIndex;
					}
					else
					{
						i++;
					}
				}
				if (i == SelectedItems.Num())
				{
					SelectedItems[i] = NewIndex;
				}
			}
			else
			{
				if (SelectedItems.Num() > 0 && MightRemove == -1)
				{
					SelectedItems.RemoveAt(0, SelectedItems.Num());
				}
			}
		}
	}
}

void UGUIListBase::InternalOnMouseRelease(UGUIComponent* Sender)
{
	/*
	if (MightRemove >= 0 && MightRemove < SelectedItems.Num())
	{
		SelectedItems.RemoveAt(MightRemove, 1);
	}
	MightRemove = -1;
	if (!IsMultiSelect())
	{
		ClearPendingElements();
	}
	*/
}
bool UGUIListBase::InternalOnBeginDrag(UGUIComponent* Sender)
{
	/*
	if (Controller == nullptr)
	{
		return false;
	}
	if (FMath::Abs(LastPressX - Controller->MouseX) < 3 && Abs(LastPressY - Controller->MouseY) < 3)
	{
		return false;
	}
	MightRemove = -1;
	if (SelectedItems.Num() == 0)
	{
		CheckDragSelect();
	}
	UpdateOffset(ClientBounds[0], ClientBounds[1], ClientBounds[2], ClientBounds[3]);
	SetOutlineAlpha(128);
	*/
	return true;
}
void UGUIListBase::CheckDragSelect()
{
	/*
	int32 i = 0;
	i = CalculateIndex(true);
	if (i < 0)
	{
		return;
	}
	SetIndex(i);
	SelectedItems[SelectedItems.Num()] = i;
	*/
}

bool UGUIListBase::InternalOnRightClick(UGUIComponent* Sender)
{
	/*
	if (bDropSource && bMultiSelect && SelectedItems.Num() > 0)
	{
		Controller->bIgnoreNextRelease = true;
	}
	*/
	return true;
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
	int32 NewIndex = 0;
	if (Controller == nullptr)
	{
		return;
	}
	if (Controller->DropTarget == this)
	{
		NewIndex = CalculateIndex(true);
		if (NewIndex == -1)
		{
			DropIndex = -1;
			return;
		}
		if (Controller->DropSource != this && SelectedItems.Num() > 0)
		{
			SelectedItems.RemoveAt(0, SelectedItems.Num());
		}
		DropIndex = NewIndex;
	}
}

void UGUIListBase::InternalOnDragEnter(UGUIComponent* Sender)
{
	SetOutlineAlpha(255);
}

void UGUIListBase::InternalOnDragLeave(UGUIComponent* Sender)
{
	SetOutlineAlpha(128);
	if (DropIndex >= 0)
	{
		DropIndex = -1;
	}
}

bool UGUIListBase::IsMultiSelect()
{
	if (Controller == nullptr)
	{
		return false;
	}
	return ((((bDropSource && bMultiSelect) && (DropState != EDropState::DRP_Source)) && (Controller->CtrlPressed || Controller->ShiftPressed)) && OnMultiSelect(this));
}

void UGUIListBase::SetOutlineAlpha(int32 NewAlpha)
{
	int32 i = 0;
	if (OutlineStyle == nullptr)
	{
		return;
	}
	for (i = 0; i < 5; i++)
	{
		OutlineStyle->ImgColors[i].A = NewAlpha;
	}
}
