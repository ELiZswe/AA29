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
	//Log("** Dumping settings array for PlayInfo object '" + Name + "' **");
	UE_LOG(LogTemp, Log, TEXT("** Classes:%d"),InfoClasses.Num());
	for (i = 0; i < InfoClasses.Num(); i++)
	{
		//UE_LOG(LogTemp, Log, TEXT("   %d) %s"), i,InfoClasses[i].Name);
	}
	UE_LOG(LogTemp, Log, TEXT(""));
	UE_LOG(LogTemp, Log, TEXT("** Groups:%d"), Groups.Num());
	for (i = 0; i < Groups.Num(); i++)
	{
		UE_LOG(LogTemp, Log, TEXT("   %d) %s"),i,*Groups[i]);
	}
	UE_LOG(LogTemp, Log, TEXT(""));
	UE_LOG(LogTemp, Log, TEXT("** Settings:%d"),Settings.Num());
	for (i = 0; i < Settings.Num(); i++)
	{
		if (Group == "" || Group.Compare(Settings[i].Grouping, ESearchCase::IgnoreCase))
		{
			//UE_LOG(LogTemp, Log, TEXT("%d) %s"),i,Settings[i].SettingName);
			UE_LOG(LogTemp, Log, TEXT("            DisplayName: %s"), *Settings[i].DisplayName);
			//UE_LOG(LogTemp, Log, TEXT("              ClassFrom: %s"), *Settings[i].ClassFrom);
			UE_LOG(LogTemp, Log, TEXT("                  Group: %s"), *Settings[i].Grouping);
			UE_LOG(LogTemp, Log, TEXT("                  Value: %s"), *Settings[i].Value);
			UE_LOG(LogTemp, Log, TEXT("                   Data: %s"), *Settings[i].Data);
			UE_LOG(LogTemp, Log, TEXT("                 Weight: %d"), Settings[i].Weight);
			UE_LOG(LogTemp, Log, TEXT("                 Struct: %s"), Settings[i].bStruct ? TEXT("true") : TEXT("false"));
			UE_LOG(LogTemp, Log, TEXT("                 Global: %s"), Settings[i].bGlobal ? TEXT("true") : TEXT("false"));
			UE_LOG(LogTemp, Log, TEXT("                 MPOnly: %s"), Settings[i].bMPOnly ? TEXT("true") : TEXT("false"));
			UE_LOG(LogTemp, Log, TEXT("               SecLevel: %d"), Settings[i].SecLevel);
			UE_LOG(LogTemp, Log, TEXT("               ArrayDim: %d"), Settings[i].ArrayDim);
			UE_LOG(LogTemp, Log, TEXT("              bAdvanced: %s"), Settings[i].bAdvanced ? TEXT("true") : TEXT("false"));
			UE_LOG(LogTemp, Log, TEXT("              ExtraPriv: %s"), *Settings[i].ExtraPriv);
			//UE_LOG(LogTemp, Log, TEXT("             RenderType: %s" @ GetEnum(Enum'EPlayInfoType', Settings[i].RenderType));
			UE_LOG(LogTemp, Log, TEXT(""));
		}
	}
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
	for (i = 0; i < Classes.Num(); i++)
	{
		if (Classes[i] == nullptr)
		{
			//Log("Call in PlayInfo.Init() with "None" value for Class array member.  Index:" + i);
			Classes.RemoveAt(i--, 1);
		}
		else
		{
			//Classes[i]->FillPlayInfo(this);
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
			//B = B && RemoveClass(InfoClasses[i]);
		}
	}
	return B;
}

AGameInfo* UPlayInfo::GetGameInfo()
{
	int32 i = 0;
	for (i = 0; i < InfoClasses.Num(); i++)
	{
		/*
		if (class<GameInfo>(InfoClasses[i]) != nullptr)
		{
			return class<GameInfo>(InfoClasses[i]);
		}
		*/
	}
	return nullptr;
}

void UPlayInfo::SplitStringToArray(TArray<FString>& Parts, FString Source, FString Delim)
{
	//Split(Source, Delim, Parts);
}
