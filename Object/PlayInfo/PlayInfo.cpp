// All the original content belonged to the US Army

#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"

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
	int32 i = 0;
	/*
	Log("** Dumping settings array for PlayInfo object '" $ Name $ "' **");
	Log("** Classes:" @ InfoClasses.Num());
	for (i = 0; i < InfoClasses.Num(); i++)
	{
		Log("   " $ i $ ")" @ InfoClasses[i].Name);
	}
	Log("");
	Log("** Groups:" @ Groups.Num());
	for (i = 0; i < Groups.Num(); i++)
	{
		Log("   " $ i $ ")" @ Groups[i]);
	}
	Log("");
	Log("** Settings:" @ Settings.Num());
	for (i = 0; i < Settings.Num(); i++)
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

bool UPlayInfo::Init(TArray<AAA2_Info*> Classes, bool bStrict)
{
	int32 i = 0;
	int32 j = 0;
	bool B = false;
	if (Classes.Num() == 0)
	{
		return B;
	}
	B = true;
	Clear();
	/*
	for (i = 0; i < Classes.Num(); i++)
	{
		if (Classes[i] == nullptr)
		{
			Log("Call in PlayInfo.Init() with "None" value for Class array member.  Index:" $ i);
			Classes.RemoveAt(i--, 1);
		}
		else
		{
			Classes[i].FillPlayInfo(this);
		}
	}
	if (bStrict)
	{
		for (i = InfoClasses.Num() - 1; i >= 0; i--)
		{
			for (j = 0; j < Classes.Num(); j++)
			{
				if (InfoClasses[i] == Classes[j])
				{
				}
			}
			if (j < Classes.Num())
			{
			}
			B = B && RemoveClass(InfoClasses[i]);
		}
	}
	*/
	return B;
}

AGameInfo* UPlayInfo::GetGameInfo()
{
	int32 i = 0;
	/*
	for (i = 0; i < InfoClasses.Num(); i++)
	{
		if (class<GameInfo>(InfoClasses[i]) != nullptr)
		{
			return class<GameInfo>(InfoClasses[i]);
		}
	}
	*/
	return nullptr;
}

void UPlayInfo::SplitStringToArray(TArray<FString>& Parts, FString Source, FString Delim)
{
	//Split(Source, Delim, Parts);
}
