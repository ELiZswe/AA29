// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterList.h"

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
void UGUICharacterList::MoveLeft()
{
	/*
	if (bLocked)
	{
		if (Index > 0)
		{
			Index--;
			OnChange(Self);
		}
		Return True;
	}
	else
	{
		Return MoveLeft();
	}
	*/
}
void UGUICharacterList::MoveRight()
{
	/*
	if (bLocked)
	{
		if (Index < ItemsPerPage - 1)
		{
			Index++;
			OnChange(Self);
		}
		Return True;
	}
	else
	{
		Return MoveRight();
	}
	*/
}
void UGUICharacterList::End()
{
	/*
	if (bLocked)
	{
		Index = ItemsPerPage - 1;
		OnChange(Self);
	}
	else
	{
		End();
	}
	*/
}
void UGUICharacterList::ClearPendingElements()
{
	Super::ClearPendingElements();
}
void UGUICharacterList::InternalOnBeginDrag(UGUIComponent* Sender)
{
	/*
	if (InternalOnBeginDrag(Sender))
	{
		Return True;
	}
	Return False;
	*/
}
void UGUICharacterList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	if (bAccepted && Accepting != None)
	{
		bRepeatClick = False;
	}
	if (Accepting == None)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}
void UGUICharacterList::InternalOnDragDrop(UGUIComponent* Sender)
{
	/*
	InternalOnMouseRelease(Sender);
	Return False;
	*/
}
