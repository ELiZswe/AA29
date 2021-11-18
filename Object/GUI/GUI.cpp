// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUI.h"

UGUI::UGUI()
{

}

// GUI-wide utility functions
bool UGUI::IsDigit(FString Test, bool bAllowDecimal)
{
	FString Digits = "0123456789";

	while (Test != "")
	{
		if (!Digits.Contains(Test.Left(1)))
		{
			return false;
		}
		
		if (!(bAllowDecimal && Test.Left(1) == "."))
		{
			return false;
		}
		
		Test = Test.Mid(1);
	}
	return true;
}

// Join together array elements into a single string
FString UGUI::JoinArray(TArray<FString> StringArray, FString Delim, bool bIgnoreBlanks)
{
	int32 i;
	FString S;

	if (Delim == "")
	{
		Delim = ",";
	}

	for (i = 0; i < StringArray.Max(); i++)
	{
		if (StringArray[i] != "" || !bIgnoreBlanks)
		{
			if (S != "")
			{
				S += Delim;
			}
			S += StringArray[i];
		}
	}
	return S;
}
//native Function Profile(string ProfileName);
void UGUI::Profile(FString ProfileName)
{

}

//native Function GetModList(out array<String> ModDirs, out array<String> ModTitles);
void UGUI::GetModList(TArray<FString>& ModDirs, TArray<FString>& ModTitles)
{

}

//native Function GetModValue(string ModDir, string ModKey);
void UGUI::GetModValue(FString ModDir, FString ModKey)
{

}

//native Function GetModLogo(string ModDir);
void UGUI::GetModLogo(FString ModDir)
{

}
