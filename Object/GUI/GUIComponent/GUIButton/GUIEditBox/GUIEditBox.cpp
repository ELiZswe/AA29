// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIEditBox::UGUIEditBox()
{
	BorderOffsets.SetNum(4);
	MaxWidth = 768;
	LastCaret = -1;
	LastLength = -1;
	StyleName = "EditBox";
	WinHeight = 0.06;
	bCaptureMouse = false;
	bRequiresStyle = true;
	OnClickSound = EClickSound::CS_Edit;
	//__OnActivate__Delegate = "GUIEditBox.InternalActivate"
	//__OnDeActivate__Delegate = "GUIEditBox.InternalDeactivate"
	//__OnKeyType__Delegate = "GUIEditBox.InternalOnKeyType"
	//__OnKeyEvent__Delegate = "GUIEditBox.InternalOnKeyEvent"
}

void UGUIEditBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (bIntOnly || bFloatOnly)
	{
		AllowedCharSet = "0123456789";
		if (bFloatOnly)
		{
			AllowedCharSet += ".";
		}
	}
	bAllSelected = true;
}

void UGUIEditBox::SetText(FString NewText)
{
	bool bChanged = nullptr;
	bChanged = bAlwaysNotify || TextStr != NewText;
	TextStr = NewText;
	CaretPos = TextStr.Len();
	if (bChanged)
	{
		TextChanged();
	}
	bAllSelected = true;
}

void UGUIEditBox::DeleteChar()
{
	if (CaretPos == TextStr.Len())
	{
		return;
	}
	else
	{
		if (CaretPos == TextStr.Len() - 1)
		{
			TextStr = TextStr.Left(CaretPos);
			CaretPos = TextStr.Len();
		}
		else
		{
			TextStr = TextStr.Left(CaretPos) + TextStr.Mid(CaretPos + 1);
		}
	}
	TextChanged();
}

bool UGUIEditBox::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	FString Temp = "";
	FString st = "";
	if (bReadOnly)
	{
		return false;
	}
	if (Unicode != "")
	{
		st = Unicode;
	}
	else
	{
		//st = Chr(Key);
	}
	/*
	if (Key < 32)
	{
		if (!Controller->CtrlPressed || Key == 9)
		{
			return false;
		}
		switch(Key)
		{
				case 3:
					PlayerOwner().CopyToClipboard(TextStr);
					bAllSelected = true;
					break;
				case 22:
					if (TextStr == "" || CaretPos == Len(TextStr))
					{
						if (bAllSelected)
						{
							TextStr = "";
						}
						TextStr = ConvertIllegal(TextStr + PlayerOwner().PasteFromClipboard());
						CaretPos = Len(TextStr);
					}
					else
					{
						Temp = ConvertIllegal(Left(TextStr, CaretPos) + PlayerOwner().PasteFromClipboard() + Mid(TextStr, CaretPos));
						TextStr = Temp;
					}
				case 24:
					PlayerOwner().CopyToClipboard(TextStr);
					TextStr = "";
					CaretPos = 0;
				default:
		}
		TextChanged();
		return true;
	}
	if (bAllSelected)
	{
		TextStr = "";
		CaretPos = 0;
		bAllSelected = false;
	}
	if (AllowedCharSet == "" || bIncludeSign && st == "-" || st == "+" && TextStr == "" || InStr(AllowedCharSet, st) >= 0)
	{
		if (MaxWidth == 0 || Len(TextStr) < MaxWidth)
		{
			if (bConvertSpaces && st == " " || st == "?" || st == "\")
			{
				st = "_";
			}
			if (TextStr == "" || CaretPos == Len(TextStr))
			{
				TextStr = TextStr + st;
					CaretPos = Len(TextStr);
			}
			else
			{
				Temp = Left(TextStr, CaretPos) + st + Mid(TextStr, CaretPos);
				TextStr = Temp;
				CaretPos++;
			}
			TextChanged();
			return true;
		}
	}
	*/
	return false;
}

bool UGUIEditBox::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	if (bReadOnly || State != 1)
	{
		return false;
	}
	if (Key == 8)
	{
		if (CaretPos > 0)
		{
			if (bAllSelected)
			{
				TextStr = "";
				CaretPos = 0;
				bAllSelected = false;
				TextChanged();
			}
			else
			{
				CaretPos--;
				DeleteChar();
			}
		}
		return true;
	}
	if (Key == 46)
	{
		if (bAllSelected)
		{
			TextStr = "";
			CaretPos = 0;
			bAllSelected = false;
			TextChanged();
		}
		else
		{
			DeleteChar();
		}
		return true;
	}
	if (Key == 37)
	{
		if (bAllSelected)
		{
			CaretPos = 0;
			bAllSelected = false;
		}
		else
		{
			if (CaretPos > 0)
			{
				CaretPos--;
			}
		}
		return true;
	}
	if (Key == 39)
	{
		if (bAllSelected)
		{
			CaretPos = TextStr.Len();
			bAllSelected = false;
		}
		else
		{
			if (CaretPos < TextStr.Len())
			{
				CaretPos++;
			}
		}
		return true;
	}
	if (Key == 36)
	{
		CaretPos = 0;
		bAllSelected = false;
		return true;
	}
	if (Key == 35)
	{
		CaretPos = TextStr.Len();
		bAllSelected = false;
		return true;
	}
	if (Key == 65 && Controller->CtrlPressed)
	{
		bAllSelected = true;
		return true;
	}
	return false;
}

FString UGUIEditBox::ConvertIllegal(FString inputstr)
{
	int32 i = 0;
	int32 Max = 0;
	FString retval = "";
	FString C = "";
	i = 0;
	for (Max = inputstr.Len(); i < Max; i++)
	{
		/*
		C = Mid(inputstr, i, 1);
		if (AllowedCharSet != "" && InStr(AllowedCharSet, C) < 0)
		{
			C = "";
		}
		if (bConvertSpaces&& C == " " || C == "?" || C == "\")
		{
			C = "_";
		}
		*/
		retval = retval + C;
	}
	if (MaxWidth > 0)
	{
		return retval.Left(MaxWidth);
	}
	return retval;
}

FString UGUIEditBox::GetText()
{
	return TextStr;
}

void UGUIEditBox::TextChanged()
{
	OnChange(this);
}

void UGUIEditBox::DisableConsoleHotkey()
{
	UConsole* Console = nullptr;
	/*
	ForEach(Class'Console', Console)
	{
		if (Console.ConsoleHotKey != Console.0)
		{
			OriginalConsoleHotKey = Console.ConsoleHotKey;
			Console.ConsoleHotKey = Console.0;
		}
	}
	*/
}

void UGUIEditBox::RestoreConsoleHotkey()
{
	UConsole* Console = nullptr;
	EInputKey InputKeyNone = EInputKey::IK_None;
	InputKeyNone = EInputKey::IK_None;
	if (InputKeyNone != OriginalConsoleHotKey)
	{
		/*
		ForEach(Class'Console', Console)
		{
			Console.ConsoleHotKey = OriginalConsoleHotKey;
		}
		*/
	}
	OriginalConsoleHotKey = InputKeyNone;
}

void UGUIEditBox::LoseFocus(UGUIComponent* Sender)
{
	RestoreConsoleHotkey();
	Super::LoseFocus(Sender);
}

void UGUIEditBox::Free()
{
	RestoreConsoleHotkey();
	Super::Free();
}

void UGUIEditBox::InternalActivate()
{
	DisableConsoleHotkey();
	CaretPos = TextStr.Len();
	bAllSelected = true;
}

void UGUIEditBox::InternalDeactivate()
{
	RestoreConsoleHotkey();
	CaretPos = 0;
	bAllSelected = false;
}
