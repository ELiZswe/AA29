// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIScrollText/GUIScrollText.h"

UGUIScrollTextBox::UGUIScrollTextBox()
{
	CharDelay = 0.25;
	EOLDelay = 0.75;
	RepeatDelay = 3;
	Separator = "|";
	//DefaultListClass = "XInterface.GUIScrollText";
	FontScale = EeFontScale::FNS_Medium;
}

void UGUIScrollTextBox::Created()
{
	//ESC = Chr(3);
	//COMMA = Chr(44);
}

void UGUIScrollTextBox::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UGUIScrollText>(NewComp) != nullptr && Sender == this)
	{
		GUIScrollText(NewComp).bNoTeletype = bNoTeletype;
	}
	InternalOnCreateComponent(NewComp, Sender);
	*/
}

void UGUIScrollTextBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	if (MyScrollText == nullptr || MyScrollText != LocalList && GUIScrollText(LocalList) != nullptr)
	{
		MyScrollText = GUIScrollText(LocalList);
	}
	InitBaseList(LocalList);
	MyScrollText.Separator = Separator;
	MyScrollText.InitialDelay = InitialDelay;
	MyScrollText.CharDelay = CharDelay;
	MyScrollText.EOLDelay = EOLDelay;
	MyScrollText.RepeatDelay = RepeatDelay;
	MyScrollText.TextAlign = TextAlign;
	MyScrollText.bRepeat = bRepeat;
	MyScrollText.bNoTeletype = bNoTeletype;
	MyScrollText.__OnAdjustTop__Delegate = InternalOnAdjustTop;
	*/
}

void UGUIScrollTextBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		MyScrollText = GUIScrollText(AddComponent(DefaultListClass));
		if (MyScrollText == nullptr)
		{
			Log(Class + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
	}
	if (MyScrollText == nullptr)
	{
		Warn("Could not initialize list!");
		return;
	}
	InitBaseList(MyScrollText);
	*/
}

void UGUIScrollTextBox::SetContent(FString NewContent, FString sep)
{
	//MyScrollText.SetContent(NewContent, sep);
}

void UGUIScrollTextBox::Restart()
{
	//MyScrollText.Restart();
}

void UGUIScrollTextBox::Stop()
{
	//MyScrollText.Stop();
}

void UGUIScrollTextBox::InternalOnAdjustTop(UGUIComponent* Sender)
{
	//MyScrollText.EndScrolling();
}

bool UGUIScrollTextBox::IsNumber(FString Num)
{
	/*
	if (Num > Chr(47) && Num < Chr(58))
	{
		return true;
	}
	*/
	return false;
}

FString UGUIScrollTextBox::StripColors(FString MyString)
{
	/*
	int32 EscapePos;
	int32 RemCount;
	int32 LenFromEscape;
	EscapePos = InStr(MyString, ESC);
	if (EscapePos != -1)
	{
		LenFromEscape = Len(MyString) - EscapePos + 1;
		RemCount = 0;
		if (RemCount < LenFromEscape && RemCount < 7)
		{
			if (Mid(MyString, EscapePos + RemCount, 1) == ESC || IsNumber(Mid(MyString, EscapePos + RemCount, 1)) || Mid(MyString, EscapePos + RemCount, 1) == COMMA)
			{
				RemCount++;
			}
			else
			{
			}
			RemCount++;
		}
		MyString = Left(MyString, EscapePos) + Mid(MyString, EscapePos + RemCount);
		EscapePos = InStr(MyString, Chr(3));
	}
	*/
	return MyString;
}

void UGUIScrollTextBox::AddText(FString NewText)
{
	/*
	FString StrippedText;
	if (NewText == "")
	{
		return;
	}
	if (bStripColors)
	{
		StrippedText = StripColors(NewText);
	}
	else
	{
		StrippedText = NewText;
	}
	if (MyScrollText.NewText != "")
	{
		MyScrollText.NewText += MyScrollText.Separator;
	}
	MyScrollText.NewText += StrippedText;
	*/
}
