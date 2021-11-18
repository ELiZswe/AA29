// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboboxPlus/moComboboxPlus.h"

UmoComboboxPlus::UmoComboboxPlus()
{
	ExtraCompClass = "XInterface.GUICheckBox";
	bSquare = true;
	//OnPreDraw = moComboboxPlus.InternalOnPreDraw;
}

void UmoComboboxPlus::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	Super::InitComponent(InController, InOwner);
	if (ExtraCompClass != "")
	{
		ExtraComp = AddComponent(ExtraCompClass);
	}
	ExtraComp.bBoundToParent = false;
	ExtraComp.bScaleToParent = false;
	*/
}

void UmoComboboxPlus::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local int32 i;
	if (Sender != None)
	{
		i = MyComboBox.GetIndex();
		if ((i < 0) || (i >= ExtraData.Length))
		{
			return;
		}
		if (Sender == ExtraComp)
		{
			SetExtraValue(i, ExtraData[i]);
		}
		else
		{
			if (Sender == MyComboBox)
			{
				UpdateExtraValue(i);
			}
		}
	}
	*/
}

void UmoComboboxPlus::SetExtraValue(int32 i, FString Data)
{
}

void UmoComboboxPlus::UpdateExtraValue(int32 i)
{
}

void UmoComboboxPlus::addItem(FString Item, UObject* Extra, FString str)
{
	/*
	Super::addItem(Item, Extra, str);
	ExtraData.Length = MyComboBox.ItemCount();
	*/
}

void UmoComboboxPlus::RemoveItem(int32 Item, int32 Count)
{
	/*
	Super::RemoveItem(Item, Count);
	if (Count == 0)
	{
		Count = 1;
	}
	if ((Item >= 0) && (Item <= (ExtraData.Length - Count)))
	{
		ExtraData.remove(Item, Count);
	}
	*/
}

bool UmoComboboxPlus::InternalOnPreDraw(UCanvas* C)
{
	/*
	local float AH;
	local float AW;
	local float NewScale;
	if (ExtraComp == None)
	{
		return false;
	}
	AH = ActualHeight();
	AW = ActualWidth();
	if (bVerticalLayout)
	{
		ExtraComp.WinWidth = AW;
		if (bSquare)
		{
			ExtraComp.WinHeight = AW;
		}
		else
		{
			ExtraComp.WinHeight = ExtraCompSize;
		}
		NewScale = (AH - ExtraComp.ActualHeight());
		(MyLabel.WinHeight *= NewScale);
		(MyComponent.WinHeight *= NewScale);
	}
	else
	{
		ExtraComp.WinHeight = AH;
		if (bSquare)
		{
			ExtraComp.WinWidth = AH;
		}
		else
		{
			ExtraComp.WinWidth = ExtraCompSize;
		}
		NewScale = (AW - ExtraComp.ActualWidth());
		(MyLabel.WinWidth *= NewScale);
		(MyComponent.WinWidth *= NewScale);
	}
	*/
	return false;
}
