// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "PlayInfo.generated.h"

class AGameInfo;
class AAA2_Info;

UCLASS()
class UPlayInfo : public UObject
{
	GENERATED_BODY()

public:
	UPlayInfo();

	UPROPERTY()				FString					LastError;			//var const string LastError;
	UPROPERTY()				TArray<FString>			Groups;				//var const TArray<FString> Groups;
	UPROPERTY()				TArray<int32>			ClassStack;			//var const array<int> ClassStack;
	UPROPERTY()				TArray<AAA2_Info*>		InfoClasses;		//var const array<class<Info> > InfoClasses;
	UPROPERTY()				TArray<FPlayInfoData>	Settings;			//var const array<PlayInfoData> Settings;

	void Clear();
	void AddClass(AAA2_Info*  AddingClass);
	void RemoveClass(AAA2_Info*  RemovingClass);
	void PopClass();
	void AddSetting(FString Group, FString PropertyName, FString Description, uint8 SecLevel, uint8 Weight, FString RenderType, FString Extras, FString ExtraPrivs, bool bMultiPlayerOnly, bool bAdvanced);
	void SaveSettings();
	void StoreSetting(int32 Index, FString NewVal, FString RangeData);
	void GetSettings(FString GroupName, TArray<FPlayInfoData> GroupSettings);
	void FindIndex(FString SettingName);
	void Sort(uint8 SortingMethod);
	void Dump(FString Group);
	bool Init(TArray<AAA2_Info*> Classes, bool bStrict);
	AGameInfo* GetGameInfo();
	void SplitStringToArray(TArray<FString>& Parts, FString Source, FString Delim);
};
