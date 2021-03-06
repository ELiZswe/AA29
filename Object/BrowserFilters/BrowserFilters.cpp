// All the original content belonged to the US Army

#include "AA29/Object/BrowserFilters/BrowserFilters.h"
#include "AA29/Object/CustomFilter/CustomFilter.h"

UBrowserFilters::UBrowserFilters()
{
	CustomFilterClass = "AGP_Interface.CustomFilter";
}

void UBrowserFilters::InitCustomFilters()
{
	int32 i = 0;
	UCustomFilter* Temp = nullptr;
	TArray<FString> CustomFilterNames = {};
	/*
	if (AllFilters.Num() > 0)
	{
		AllFilters.RemoveAt(0, AllFilters.Num());
	}
	if (FilterClass == nullptr)
	{
		FilterClass = class<CustomFilter>(DynamicLoadObject(CustomFilterClass, Class'Class'));
	}
	if (FilterClass == nullptr)
	{
		Warn("Invalid custom filter class specified:" @ CustomFilterClass);
		bInvalidFilterClass = true;
		return;
	}
	for (i = 0; i < Deleted.Num(); i++)
	{
		Deleted[i].Save(true);
	}
	if (Deleted.Num() > 0)
	{
		Deleted.RemoveAt(0, Deleted.Num());
	}
	CustomFilterNames = GetPerObjectNames("ServerFilters", GetItemName(CustomFilterClass));
	i = 0;
	if (i < CustomFilterNames.Num() && i < 1000)
	{
		Temp = CreateFilter(CustomFilterNames[i]);
		AllFilters[AllFilters.Num()] = Temp;
		i++;
	}
	*/
}

void UBrowserFilters::CreateFilter(FString FilterName)
{
	/*
	if (!ValidName(FilterName))
	{
		return nullptr;
	}
	return new (NoneRepl(FilterName, " ", Chr(27))) classFilterClass;
	*/
}

bool UBrowserFilters::AddCustomFilter(FString &NewFilterName)
{
	int32 i = 0;
	FString str = "";
	UCustomFilter* NewFilter = nullptr;
	/*
	if (!ValidName(NewFilterName))
	{
		return false;
	}
	str = NewFilterName;
	if (HasFilterNamed(NewFilterName))
	{
		NewFilterName = str + i++;
	}
	NewFilter = CreateFilter(NewFilterName);
	if (NewFilter == nullptr)
	{
		return false;
	}
	NewFilter.SetTitle(NewFilterName);
	AllFilters[AllFilters.Num()] = NewFilter;
	*/
	return true;
}

bool UBrowserFilters::CopyFilter(int32 Index, FString &NewFilterName)
{
	int32 i = 0;
	/*
	if (ValidIndex(Index) && AddCustomFilter(NewFilterName))
	{
		i = FindFilterIndex(NewFilterName);
		AllFilters[i].ImportFilter(AllFilters[Index]);
		AllFilters[i].SetTitle(NewFilterName);
		return true;
	}
	*/
	return false;
}

bool UBrowserFilters::RemoveFilter(FString FilterName)
{
	int32 i = 0;
	/*
	if (!ValidName(FilterName))
	{
		return false;
	}
	i = FindFilterIndex(FilterName);
	if (i < 0)
	{
		return false;
	}
	return RemoveFilterAt(i);
	*/
	return false;    //FAKE  /ELiZ
}

bool UBrowserFilters::RemoveFilterAt(int32 Index)
{
	/*
	Deleted[Deleted.Num()] = AllFilters[Index];
	AllFilters[Index].ClearConfig();
	AllFilters.RemoveAt(Index, 1);
	*/
	return true;
}

void UBrowserFilters::SaveFilters()
{
	int32 i = 0;
	/*
	if (Deleted.Num() > 0)
	{
		Deleted.RemoveAt(0, Deleted.Num());
	}
	for (i = 0; i < AllFilters.Num(); i++)
	{
		AllFilters[i].Save();
	}
	*/
}
void UBrowserFilters::ResetFilters()
{
	//InitCustomFilters();
}
bool UBrowserFilters::RenameFilter(int32 Index, FString NewName)
{
	FString str = "";
	UCustomFilter* NewFilter = nullptr;
	int32 i = 0;
	/*
	if (!ValidIndex(Index) || !ValidName(NewName))
	{
		return false;
	}
	str = NewName;
	if (HasFilterNamed(NewName))
	{
		NewName = str + i++;
	}
	NewFilter = CreateFilter(NewName);
	if (NewFilter == nullptr)
	{
		return false;
	}
	NewFilter.ImportFilter(AllFilters[Index]);
	NewFilter.SetTitle(NewName);
	RemoveFilterAt(Index);
	AllFilters.insert(Index, 1);
	AllFilters[Index] = NewFilter;
	*/
	return true;
}

bool UBrowserFilters::ActivateFilter(int32 Index, bool Enable)
{
	/*
	if (!ValidIndex(Index))
	{
		return false;
	}
	if (IsActive(AllFilters[Index]) == Enable)
	{
		return false;
	}
	return AllFilters[Index].SetActive(Enable);
	*/
	return false;    //FAKE   /ELiZ
}

bool UBrowserFilters::IsActive(UCustomFilter* Test)
{
	if (Test == nullptr)
	{
		return false;
	}
	return Test->IsActive();
}

bool UBrowserFilters::IsActiveAt(int32 Index)
{
	if (!ValidIndex(Index))
	{
		return false;
	}
	return AllFilters[Index]->IsActive();
}

void UBrowserFilters::LoadSettings(int32 FilterIndex)
{
}

FString UBrowserFilters::GetFilterName(int32 Index)
{
	if (!ValidIndex(Index))
	{
		return "";
	}
	return AllFilters[Index]->GetTitle();
}

TArray<FAFilterRule> UBrowserFilters::GetFilterRules(int32 Index)
{
	TArray<FAFilterRule> FilterRules = {};
	if (ValidIndex(Index))
	{
		AllFilters[Index]->GetQueryRules(FilterRules);
	}
	return FilterRules;
}

TArray<FCurrentFilter> UBrowserFilters::GetFilterARules(int32 Index)
{
	TArray<FCurrentFilter> FilterRules =  {};
	if (ValidIndex(Index))
	{
		//AllFilters[Index]->GetRules(FilterRules);
	}
	return FilterRules;
}

void UBrowserFilters::PostEdit(int32 Index, FString NewTitle, TArray<FAFilterRule> NewRules)
{
	if (ValidIndex(Index))
	{
		AllFilters[Index]->PostEdit(NewTitle, NewRules);
	}
}

TArray<FString> UBrowserFilters::GetFilterNames(bool bActiveOnly)
{
	int32 i = 0;
	TArray<FString> FilterNames = {};
	/*
	for (i = 0; i < AllFilters.Num(); i++)
	{
		if (bActiveOnly && !AllFilters[i].IsActive())
		{
		}
		FilterNames[i] = AllFilters[i].GetTitle();
	}
	*/
	return FilterNames;
}
void UBrowserFilters::SetRule(int32 FilterIndex, int32 RuleIndex, FString RuleTag, FString RuleItem, FString RuleValue, FString DataType, FString QueryType, FString ExtraData)
{
}

int32 UBrowserFilters::AddFilter(UCustomFilter* filter)
{
	int32 i = 0;
	if (filter == nullptr)
	{
		return - 1;
	}
	/*
	i = FindFilterIndex(filter.GetTitle());
	if (i == -1)
	{
		AllFilters[AllFilters.Num()] = filter;
	}
	*/
	return i;
}

bool UBrowserFilters::HasFilterNamed(FString FilterName)
{
	return FindFilterIndex(FilterName) != -1;
}

int32 UBrowserFilters::FindFilterIndex(FString FilterName)
{
	int32 i = 0;
	/*
	for (i = 0; i < AllFilters.Num(); i++)
	{
		if (AllFilters[i].GetTitle() ~= FilterName)
		{
			return i;
		}
	}
	*/
	return - 1;
}

bool UBrowserFilters::ValidIndex(int32 Index)
{
	return Index >= 0 && Index < AllFilters.Num() && !bInvalidFilterClass;
}

bool UBrowserFilters::ValidName(FString Test)
{
	return Test != "" && Test.Len() < 1024 && !bInvalidFilterClass;
}

int32 UBrowserFilters::Count()
{
	return AllFilters.Num();
}
