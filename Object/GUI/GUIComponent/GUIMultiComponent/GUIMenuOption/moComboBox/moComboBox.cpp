// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"

UmoComboBox::UmoComboBox()
{
	//ComponentClassName = "XInterface.GUIComboBox";
}

void UmoComboBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	MyComboBox = Cast<UGUIComboBox>(MyComponent);
	MyComboBox->Edit->bAlwaysNotify = bAlwaysNotify;
	SetReadOnly(bValueReadOnly);
	ReadOnly(bReadOnly);
}

void UmoComboBox::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	int32 i = 0;
	i = FindIndex(NewValue, , true);
	if (i != -1)
	{
		if (bNoChange)
		{
			bIgnoreChange = true;
		}
		SetIndex(i);
		bIgnoreChange = false;
	}
	*/
}

FString UmoComboBox::GetComponentValue()
{
	return GetExtra();
}

int32 UmoComboBox::ItemCount()
{
	return MyComboBox->ItemCount();
}

void UmoComboBox::SetIndex(int32 i)
{
	MyComboBox->SetIndex(i);
}

void UmoComboBox::SilentSetIndex(int32 i)
{
	bIgnoreChange = true;
	MyComboBox->SetIndex(i);
	bIgnoreChange = false;
}

int32 UmoComboBox::GetIndex()
{
	return MyComboBox->GetIndex();
}

int32 UmoComboBox::FindIndex(FString Test, bool bExact, bool bExtra, UObject* obj)
{
	return MyComboBox->FindIndex(Test, bExact, bExtra, obj);
}

FString UmoComboBox::Find(FString Test, bool bExact, bool bExtra)
{
	return MyComboBox->Find(Test, bExact, bExtra);
}

int32 UmoComboBox::FindExtra(FString Test, bool bExact)
{
	return MyComboBox->FindExtra(Test, bExact);
}

void UmoComboBox::addItem(FString Item, UObject* Extra, FString str)
{
	MyComboBox->addItem(Item, Extra, str);
}

void UmoComboBox::RemoveItem(int32 Item, int32 Count)
{
	MyComboBox->RemoveItem(Item, Count);
}

FString UmoComboBox::GetItem(int32 Index)
{
	return MyComboBox->GetItem(Index);
}

UObject* UmoComboBox::GetItemObject(int32 Index)
{
	return MyComboBox->GetItemObject(Index);
}

FString UmoComboBox::GetText()
{
	return MyComboBox->Get();
}

UObject* UmoComboBox::GetObject()
{
	return MyComboBox->GetObject();
}

FString UmoComboBox::GetExtra()
{
	return MyComboBox->GetExtra();
}

void UmoComboBox::SetText(FString NewText, bool bListItemsOnly)
{
	MyComboBox->SetText(NewText, bListItemsOnly);
}

void UmoComboBox::SetExtra(FString NewExtra, bool bListItemsOnly)
{
	MyComboBox->SetExtra(NewExtra, bListItemsOnly);
}

void UmoComboBox::ReadOnly(bool B)
{
	MyComboBox->ReadOnly(B);
}

void UmoComboBox::SetReadOnly(bool B)
{
	Super::SetReadOnly(B);
	MyComboBox->bValueReadOnly = B;
}

void UmoComboBox::ResetComponent()
{
	bool bTemp = false;
	bTemp = bIgnoreChange;
	bIgnoreChange = true;
	MyComboBox->List->Clear();
	bIgnoreChange = bTemp;
}

bool UmoComboBox::FocusFirst(UGUIComponent* Sender)
{
	bool bResult=false;
	bResult = Super::FocusFirst(Sender);
	if (bResult && (MyComboBox != nullptr))
	{
		MyComboBox->HideListBox();
	}
	return bResult;
}

void UmoComboBox::Sort()
{
	MyComboBox->List->Sort();
}
