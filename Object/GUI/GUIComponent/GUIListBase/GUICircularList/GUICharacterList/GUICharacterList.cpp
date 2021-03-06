// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUICharacterList::UGUICharacterList()
{

}

void UGUICharacterList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	InitList();
}

void UGUICharacterList::InitList()
{
}

FString UGUICharacterList::SelectedText()
{
	return "";
}

bool UGUICharacterList::ValidIndex(int32 i)
{
	return i >= 0;
}

void UGUICharacterList::Add(FString NewItem, UObject* obj)
{
	return;
}

void UGUICharacterList::Remove(int32 i, int32 Count)
{
	return;
}

void UGUICharacterList::Clear()
{
	return;
}

void UGUICharacterList::Find(FString Text, bool bExact)
{
}

UMaterialInstance* UGUICharacterList::GetPortrait()
{
	return nullptr;
}

UMaterialInstance* UGUICharacterList::GetPortraitAt(int32 i)
{
	return nullptr;
}

FString UGUICharacterList::GetName()
{
	return "";
}

FString UGUICharacterList::GetNameAt(int32 i)
{
	return "";
}

FString UGUICharacterList::GetGender()
{
	return "";
}

FString UGUICharacterList::GetGenderAt(int32 i)
{
	return "";
}

FString UGUICharacterList::GetDecoText()
{
	return GetDecoTextAt(Index);
}

FString UGUICharacterList::GetDecoTextAt(int32 AtIndex)
{
	FString S="";
	return S;
}

USoundBase* UGUICharacterList::GetSound()
{
	USoundBase* NameSound=nullptr;
	return NameSound;
}

USoundBase* UGUICharacterList::GetSoundAt(int32 i)
{
	USoundBase* NameSound=nullptr;
	return NameSound;
}

void UGUICharacterList::ScrollRight()
{
	MoveRight();
}

void UGUICharacterList::ScrollLeft()
{
	MoveLeft();
}

bool UGUICharacterList::MoveLeft()
{
	if (bLocked)
	{
		if (Index > 0)
		{
			Index--;
			OnChange(this);
		}
		return true;
	}
	else
	{
		return Super::MoveLeft();
	}
}

bool UGUICharacterList::MoveRight()
{
	if (bLocked)
	{
		if (Index < ItemsPerPage - 1)
		{
			Index++;
			OnChange(this);
		}
		return true;
	}
	else
	{
		return Super::MoveRight();
	}
}

void UGUICharacterList::End()
{
	if (bLocked)
	{
		Index = ItemsPerPage - 1;
		OnChange(this);
	}
	else
	{
		End();
	}
}

void UGUICharacterList::ClearPendingElements()
{
	Super::ClearPendingElements();
}

bool UGUICharacterList::InternalOnBeginDrag(UGUIComponent* Sender)
{
	if (Super::InternalOnBeginDrag(Sender))
	{
		return true;
	}
	return false;
}
void UGUICharacterList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	if (bAccepted && Accepting != nullptr)
	{
		bRepeatClick = false;
	}
	if (Accepting == nullptr)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

bool UGUICharacterList::InternalOnDragDrop(UGUIComponent* Sender)
{
	InternalOnMouseRelease(Sender);
	return false;
}
