// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboboxPlus/moComboboxPlus.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "Engine/Canvas.h"

UmoComboboxPlus::UmoComboboxPlus()
{
	ExtraCompClass = "XInterface.GUICheckBox";
	bSquare = true;
	//OnPreDraw = moComboboxPlus.InternalOnPreDraw;
}

void UmoComboboxPlus::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	Super::InitComponent(InController, InOwner);
	if (ExtraCompClass != "")
	{
		ExtraComp = AddComponent(ExtraCompClass,false);
	}
	ExtraComp->bBoundToParent = false;
	ExtraComp->bScaleToParent = false;
}

void UmoComboboxPlus::InternalOnChange(UGUIComponent* Sender)
{
	int32 i = 0;
	if (Sender != nullptr)
	{
		i = MyComboBox->GetIndex();
		if ((i < 0) || (i >= ExtraData.Num()))
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
}

void UmoComboboxPlus::SetExtraValue(int32 i, FString Data)
{
}

void UmoComboboxPlus::UpdateExtraValue(int32 i)
{
}

void UmoComboboxPlus::addItem(FString Item, UObject* Extra, FString str)
{
	Super::addItem(Item, Extra, str);
	//ExtraData.Num() = MyComboBox.ItemCount();
}

void UmoComboboxPlus::RemoveItem(int32 Item, int32 Count)
{
	Super::RemoveItem(Item, Count);
	if (Count == 0)
	{
		Count = 1;
	}
	if ((Item >= 0) && (Item <= (ExtraData.Num() - Count)))
	{
		//ExtraData.RemoveAt(Item, Count);
	}
}

bool UmoComboboxPlus::InternalOnPreDraw(UCanvas* C)
{
	float AH = 0;
	float AW = 0;
	float NewScale = 0;
	if (ExtraComp == nullptr)
	{
		return false;
	}
	AH = ActualHeight(0,false);
	AW = ActualWidth(0,false);
	if (bVerticalLayout)
	{
		ExtraComp->WinWidth = AW;
		if (bSquare)
		{
			ExtraComp->WinHeight = AW;
		}
		else
		{
			ExtraComp->WinHeight = ExtraCompSize;
		}
		NewScale = (AH - ExtraComp->ActualHeight(0,false));
		(MyLabel->WinHeight *= NewScale);
		(MyComponent->WinHeight *= NewScale);
	}
	else
	{
		ExtraComp->WinHeight = AH;
		if (bSquare)
		{
			ExtraComp->WinWidth = AH;
		}
		else
		{
			ExtraComp->WinWidth = ExtraCompSize;
		}
		NewScale = (AW - ExtraComp->ActualWidth(0,false));
		(MyLabel->WinWidth *= NewScale);
		(MyComponent->WinWidth *= NewScale);
	}
	return false;
}
