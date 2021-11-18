// All the original content belonged to the US Army


#include "AA29/Object/PlayInfo/PlayInfo.h"

UPlayInfo::UPlayInfo()
{
}

void UPlayInfo::Clear()
{
}
void UPlayInfo::AddClass(AAA2_Info* AddingClass)
{
}
void UPlayInfo::RemoveClass(AAA2_Info* RemovingClass)
{
}
void UPlayInfo::PopClass()
{
}
void UPlayInfo::AddSetting(FString Group, FString PropertyName, FString Description, uint8 SecLevel, uint8 Weight, FString RenderType, FString Extras, FString ExtraPrivs, bool bMultiPlayerOnly, bool bAdvanced)
{
}
void UPlayInfo::SaveSettings()
{
}
void UPlayInfo::StoreSetting(int32 Index, FString NewVal, FString RangeData)
{
}
void UPlayInfo::GetSettings(FString GroupName, TArray<FPlayInfoData> GroupSettings)
{
}
void UPlayInfo::FindIndex(FString SettingName)
{
}
void UPlayInfo::Sort(uint8 SortingMethod)
{
}
void UPlayInfo::Dump(FString Group)
{
	/*
	local int i;
	Log("** Dumping settings array for PlayInfo object '" $ Name $ "' **");
	Log("** Classes:" @ InfoClasses.Length);
	for (i = 0; i < InfoClasses.Length; i++)
	{
		Log("   " $ i $ ")" @ InfoClasses[i].Name);
	}
	Log("");
	Log("** Groups:" @ Groups.Length);
	for (i = 0; i < Groups.Length; i++)
	{
		Log("   " $ i $ ")" @ Groups[i]);
	}
	Log("");
	Log("** Settings:" @ Settings.Length);
	for (i = 0; i < Settings.Length; i++)
	{
		if (Group == "" || Group ~= Settings[i].Grouping)
		{
			Log(i $ ")" @ Settings[i].SettingName);
			Log("            DisplayName:" @ Settings[i].DisplayName);
			Log("              ClassFrom:" @ Settings[i].ClassFrom);
			Log("                  Group:" @ Settings[i].Grouping);
			Log("                  Value:" @ Settings[i].Value);
			Log("                   Data:" @ Settings[i].Data);
			Log("                 Weight:" @ Settings[i].Weight);
			Log("                 Struct:" @ Settings[i].bStruct);
			Log("                 Global:" @ Settings[i].bGlobal);
			Log("                 MPOnly:" @ Settings[i].bMPOnly);
			Log("               SecLevel:" @ Settings[i].SecLevel);
			Log("               ArrayDim:" @ Settings[i].ArrayDim);
			Log("              bAdvanced:" @ Settings[i].bAdvanced);
			Log("              ExtraPriv:" @ Settings[i].ExtraPriv);
			Log("             RenderType:" @ GetEnum(Enum'EPlayInfoType', Settings[i].RenderType));
			Log("");
		}
	}
	*/
}
void UPlayInfo::Init(TArray<AAA2_Info*> Classes, bool bStrict)
{
	/*
	local int i;
	local int j;
	local bool B;
	if (Classes.Length == 0)
	{
		Return B;
	}
	B = true;
	Clear();
	for (i = 0; i < Classes.Length; i++)
	{
		if (Classes[i] == None)
		{
			Log("Call in PlayInfo.Init() with 'None' value for Class array member.  Index:" $ i);
			Classes.remove(i--, 1);
		}
		else
		{
			Classes[i].FillPlayInfo(Self);
		}
	}
	if (bStrict)
	{
		for (i = InfoClasses.Length - 1; i >= 0; i--)
		{
			for (j = 0; j < Classes.Length; j++)
			{
				if (InfoClasses[i] == Classes[j])
				{
				}
			}
			if (j < Classes.Length)
			{
			}
			B = B && RemoveClass(InfoClasses[i]);
		}
	}
	Return B;
	*/
}
void UPlayInfo::GetGameInfo()
{
	/*
	local int i;
	for (i = 0; i < InfoClasses.Length; i++)
	{
		if (class<GameInfo>(InfoClasses[i]) != None)
		{
			Return class<GameInfo>(InfoClasses[i]);
		}
	}
	Return None;
	*/
}
void UPlayInfo::SplitStringToArray(TArray<FString> Parts, FString Source, FString Delim)
{
	/*
	Split(Source, Delim, Parts);
	*/
}