// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUICustomPropertyPage.h"

UGUICustomPropertyPage::UGUICustomPropertyPage()
{

}

void UGUICustomPropertyPage::SetOwner(UGUIComponent* NewOwner)
{
	Owner = NewOwner;
}

UGUIComponent* UGUICustomPropertyPage::GetOwner()
{
	return Owner;
}

void UGUICustomPropertyPage::SetReadOnly(bool bValue)
{
}

bool UGUICustomPropertyPage::GetReadOnly()
{
	return false;
}

void UGUICustomPropertyPage::strip(FString& Source, FString Char)
{
	/*
	if ((Source != "") && (Char != ""))
	{
		if (Left(Source, Len(Char)) == Char)
		{
			Source = Mid(Source, Len(Char));
		}
		if (Right(Source, Len(Char)) == Char)
		{
			Source = Left(Source, (Len(Source) - Len(Char)));
		}
	}
	*/
}

bool UGUICustomPropertyPage::GrabOption(FString Delim, FString& Options, FString& Result)
{
	/*
	FString S = "";
	S = Options;
	if (Left(Options, 1) == Delim)
	{
		Result = Mid(Options, 1);
	}
	if (!Divide(S, Delim, Result, Options))
	{
		Result = S;
	}
	*/
	return (Result != "");
}

void UGUICustomPropertyPage::GetKeyValue(FString Pair, FString& Key, FString& Value)
{
	/*
	if (!Divide(Pair, "=", Key, Value))
	{
		Key = Pair;
	}
	*/
}

FString UGUICustomPropertyPage::ParseOption(FString Options, FString Delim, FString InKey)
{
	/*
	FString Pair = "";
	FString Key = "";
	FString Value = "";
	if (GrabOption(Delim, Options, Pair))
	{
		GetKeyValue(Pair, Key, Value);
		if (Key ~= InKey)
		{
			return Value;
		}
	}
	*/
	return "";
}
