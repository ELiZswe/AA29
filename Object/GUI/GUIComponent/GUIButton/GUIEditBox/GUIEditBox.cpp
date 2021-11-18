// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"

UGUIEditBox::UGUIEditBox()
{
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
	/*
	InitComponent(MyController, MyOwner);
	if (bIntOnly || bFloatOnly)
	{
		AllowedCharSet = "0123456789";
		if (bFloatOnly)
		{
			AllowedCharSet $ = ".";
		}
	}
	bAllSelected = true;
	*/
}
void UGUIEditBox::SetText(FString NewText)
{
	/*
	local bool bChanged;
	bChanged = bAlwaysNotify || TextStr != NewText;
	TextStr = NewText;
	CaretPos = Len(TextStr);
	if (bChanged)
	{
		TextChanged();
	}
	bAllSelected = true;
	*/
}
void UGUIEditBox::DeleteChar()
{
	/*
	if (CaretPos == Len(TextStr))
	{
		Return;
	}
	else
	{
		if (CaretPos == Len(TextStr) - 1)
		{
			TextStr = Left(TextStr, CaretPos);
			CaretPos = Len(TextStr);
		}
		else
		{
			TextStr = Left(TextStr, CaretPos) $ Mid(TextStr, CaretPos + 1);
		}
	}
	TextChanged();
	*/
}
void UGUIEditBox::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	/*
	local string Temp;
	local string st;
	if (bReadOnly)
	{
		Return False;
	}
	if (Unicode != "")
	{
		st = Unicode;
	}
	else
	{
		st = Chr(Key);
	}
	if (Key < 32)
	{
		if (!Controller.CtrlPressed || Key == 9)
		{
			Return False;
		}
		Switch(Key)
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
						TextStr = ConvertIllegal(TextStr $ PlayerOwner().PasteFromClipboard());
						CaretPos = Len(TextStr);
					}
					else
					{
						Temp = ConvertIllegal(Left(TextStr, CaretPos) $ PlayerOwner().PasteFromClipboard() $ Mid(TextStr, CaretPos));
						TextStr = Temp;
					}
				case 24:
					PlayerOwner().CopyToClipboard(TextStr);
					TextStr = "";
					CaretPos = 0;
				default:
		}
		TextChanged();
		Return True;
	}
	if (bAllSelected)
	{
		TextStr = "";
		CaretPos = 0;
		bAllSelected = False;
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
				TextStr = TextStr $ st;
					CaretPos = Len(TextStr);
			}
			else
			{
				Temp = Left(TextStr, CaretPos) $ st $ Mid(TextStr, CaretPos);
				TextStr = Temp;
				CaretPos++;
			}
			TextChanged();
			Return True;
		}
	}
	Return False;
	*/
}
void UGUIEditBox::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	/*
	if (bReadOnly || State != 1)
	{
		Return False;
	}
	if (Key == 8)
	{
		if (CaretPos > 0)
		{
			if (bAllSelected)
			{
				TextStr = "";
				CaretPos = 0;
				bAllSelected = False;
				TextChanged();
			}
			else
			{
				CaretPos--;
				DeleteChar();
			}
		}
		Return True;
	}
	if (Key == 46)
	{
		if (bAllSelected)
		{
			TextStr = "";
			CaretPos = 0;
			bAllSelected = False;
			TextChanged();
		}
		else
		{
			DeleteChar();
		}
		Return True;
	}
	if (Key == 37)
	{
		if (bAllSelected)
		{
			CaretPos = 0;
			bAllSelected = False;
		}
		else
		{
			if (CaretPos > 0)
			{
				CaretPos--;
			}
		}
		Return True;
	}
	if (Key == 39)
	{
		if (bAllSelected)
		{
			CaretPos = Len(TextStr);
			bAllSelected = False;
		}
		else
		{
			if (CaretPos < Len(TextStr))
			{
				CaretPos++;
			}
		}
		Return True;
	}
	if (Key == 36)
	{
		CaretPos = 0;
		bAllSelected = False;
		Return True;
	}
	if (Key == 35)
	{
		CaretPos = Len(TextStr);
		bAllSelected = False;
		Return True;
	}
	if (Key == 65 && Controller.CtrlPressed)
	{
		bAllSelected = true;
		Return True;
	}
	Return False;
	*/
}
void UGUIEditBox::ConvertIllegal(FString inputstr)
{
	/*
	local int i;
	local int Max;
	local string retval;
	local string C;
	i = 0;
	for (Max = Len(inputstr); i < Max; i++)
	{
		C = Mid(inputstr, i, 1);
		if (AllowedCharSet != "" && InStr(AllowedCharSet, C) < 0)
		{
			C = "";
		}
		if (bConvertSpaces&& C == " " || C == "?" || C == "\")
		{
			C = "_";
		}
		retval = retval $ C;
	}
	if (MaxWidth > 0)
	{
		Return Left(retval, MaxWidth);
	}
	Return retval;
	*/
}
FString UGUIEditBox::GetText()
{
	return TextStr;
}
void UGUIEditBox::TextChanged()
{
	/*
	OnChange(Self);
	*/
}
void UGUIEditBox::DisableConsoleHotkey()
{
	/*
	local Console Console;
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
	/*
	local Console Console;
	local Interactions.EInputKey InputKeyNone;
	InputKeyNone = 0;
	if (InputKeyNone != OriginalConsoleHotKey)
	{
		ForEach(Class'Console', Console)
		{
			Console.ConsoleHotKey = OriginalConsoleHotKey;
		}
	}
	OriginalConsoleHotKey = InputKeyNone;
	*/
}
void UGUIEditBox::LoseFocus(UGUIComponent* Sender)
{
	/*
	RestoreConsoleHotkey();
	LoseFocus(Sender);
	*/
}
void UGUIEditBox::Free()
{
	/*
	RestoreConsoleHotkey();
	Free();
	*/
}
void UGUIEditBox::InternalActivate()
{
	/*
	DisableConsoleHotkey();
	CaretPos = Len(TextStr);
	bAllSelected = true;
	*/
}
void UGUIEditBox::InternalDeactivate()
{
	/*
	RestoreConsoleHotkey();
	CaretPos = 0;
	bAllSelected = False;
	*/
}