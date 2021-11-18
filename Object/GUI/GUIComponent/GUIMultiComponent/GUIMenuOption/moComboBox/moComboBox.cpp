// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UmoComboBox::UmoComboBox()
{
	//ComponentClassName = "XInterface.GUIComboBox";
}

void UmoComboBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyComboBox = GUIComboBox(MyComponent);
	MyComboBox.Edit.bAlwaysNotify = bAlwaysNotify;
	SetReadOnly(bValueReadOnly);
	ReadOnly(bReadOnly);
	*/
}

void UmoComboBox::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	local int32 i;
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
	//return MyComboBox->ItemCount();
	return -1;    //FAKE   /ELiZ
}

void UmoComboBox::SetIndex(int32 i)
{
	//MyComboBox.SetIndex(i);
}

void UmoComboBox::SilentSetIndex(int32 i)
{
	/*
	bIgnoreChange = true;
	MyComboBox.SetIndex(i);
	bIgnoreChange = false;
	*/
}

int32 UmoComboBox::GetIndex()
{
	//return MyComboBox->GetIndex();
	return -1;    //FAKE   /ELiZ
}

int32 UmoComboBox::FindIndex(FString Test, bool bExact, bool bExtra, UObject* obj)
{
	//return MyComboBox->FindIndex(Test, bExact, bExtra, obj);
	return -1;    //FAKE   /ELiZ
}

FString UmoComboBox::Find(FString Test, bool bExact, bool bExtra)
{
	//return MyComboBox->Find(Test, bExact, bExtra);
	return "FAKE";    //FAKE   /ELiZ
}

int32 UmoComboBox::FindExtra(FString Test, bool bExact)
{
	//return MyComboBox->FindExtra(Test, bExact);
	return -1;    //FAKE   /ELiZ
}

void UmoComboBox::addItem(FString Item, UObject* Extra, FString str)
{
	//MyComboBox->addItem(Item, Extra, str);
}

void UmoComboBox::RemoveItem(int32 Item, int32 Count)
{
	//MyComboBox->RemoveItem(Item, Count);
}

FString UmoComboBox::GetItem(int32 Index)
{
	//return MyComboBox->GetItem(Index);
	return "FAKE";    //FAKE   /ELiZ
}

UObject* UmoComboBox::GetItemObject(int32 Index)
{
	//return MyComboBox->GetItemObject(Index);
	return nullptr;    //FAKE   /ELiZ
}

FString UmoComboBox::GetText()
{
	//return MyComboBox->Get();
	return "FAKE";    //FAKE   /ELiZ
}

UObject* UmoComboBox::GetObject()
{
	//return MyComboBox->GetObject();
	return nullptr;    //FAKE   /ELiZ
}

FString UmoComboBox::GetExtra()
{
	//return MyComboBox->GetExtra();
	return "FAKE";    //FAKE   /ELiZ
}

void UmoComboBox::SetText(FString NewText, bool bListItemsOnly)
{
	//MyComboBox.SetText(NewText, bListItemsOnly);
}

void UmoComboBox::SetExtra(FString NewExtra, bool bListItemsOnly)
{
	//MyComboBox.SetExtra(NewExtra, bListItemsOnly);
}

void UmoComboBox::ReadOnly(bool B)
{
	//MyComboBox.ReadOnly(B);
}

void UmoComboBox::SetReadOnly(bool B)
{
	/*
	Super::SetReadOnly(B);
	MyComboBox.bValueReadOnly = B;
	*/
}

void UmoComboBox::ResetComponent()
{
	/*
	local bool bTemp;
	bTemp = bIgnoreChange;
	bIgnoreChange = true;
	MyComboBox.List.Clear();
	bIgnoreChange = bTemp;
	*/
}

bool UmoComboBox::FocusFirst(UGUIComponent* Sender)
{
	bool bResult=false;
	/*
	bResult = Super::FocusFirst(Sender);
	if (bResult && (MyComboBox != None))
	{
		MyComboBox.HideListBox();
	}
	*/
	return bResult;
}

void UmoComboBox::Sort()
{
	//MyComboBox.List.Sort();
}
