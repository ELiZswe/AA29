// All the original content belonged to the US Army

#include "AA29/Object/BrowserFilters/BrowserFilters.h"

UBrowserFilters::UBrowserFilters()
{
	CustomFilterClass = "AGP_Interface.CustomFilter";
}

void UBrowserFilters::InitCustomFilters()
{
	/*
	local int i;
	local CustomFilter Temp;
	local array<String> CustomFilterNames;
	if (AllFilters.Length > 0)
	{
		AllFilters.remove(0, AllFilters.Length);
	}
	if (FilterClass == None)
	{
		FilterClass = class<CustomFilter>(DynamicLoadObject(CustomFilterClass, Class'Class'));
	}
	if (FilterClass == None)
	{
		Warn("Invalid custom filter class specified:" @ CustomFilterClass);
		bInvalidFilterClass = true;
		Return;
	}
	for (i = 0; i < Deleted.Length; i++)
	{
		Deleted[i].Save(True);
	}
	if (Deleted.Length > 0)
	{
		Deleted.remove(0, Deleted.Length);
	}
	CustomFilterNames = GetPerObjectNames("ServerFilters", GetItemName(CustomFilterClass));
	i = 0;
	if (i < CustomFilterNames.Length && i < 1000)
	{
		Temp = CreateFilter(CustomFilterNames[i]);
		AllFilters[AllFilters.Length] = Temp;
		i++;
	}
	*/
}
void UBrowserFilters::CreateFilter(FString FilterName)
{
	/*
	if (!ValidName(FilterName))
	{
		return None;
	}
	return new (NoneRepl(FilterName, " ", Chr(27))) classFilterClass;
	*/
}
bool UBrowserFilters::AddCustomFilter(FString &NewFilterName)
{
	/*
	local int i;
	local string str;
	local CustomFilter NewFilter;
	if (!ValidName(NewFilterName))
	{
		return false;
	}
	str = NewFilterName;
	if (HasFilterNamed(NewFilterName))
	{
		NewFilterName = str $ i++;
	}
	NewFilter = CreateFilter(NewFilterName);
	if (NewFilter == None)
	{
		return false;
	}
	NewFilter.SetTitle(NewFilterName);
	AllFilters[AllFilters.Length] = NewFilter;
	*/
	return true;
}

bool UBrowserFilters::CopyFilter(int32 Index, FString &NewFilterName)
{
	/*
	local int i;
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

void UBrowserFilters::RemoveFilter(FString FilterName)
{
	/*
	local int i;
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
}
bool UBrowserFilters::RemoveFilterAt(int32 Index)
{
	/*
	Deleted[Deleted.Length] = AllFilters[Index];
	AllFilters[Index].ClearConfig();
	AllFilters.remove(Index, 1);
	*/
	return true;
}

void UBrowserFilters::SaveFilters()
{
	/*
	local int i;
	if (Deleted.Length > 0)
	{
		Deleted.remove(0, Deleted.Length);
	}
	for (i = 0; i < AllFilters.Length; i++)
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
	/*
	local string str;
	local CustomFilter NewFilter;
	local int i;
	if (!ValidIndex(Index) || !ValidName(NewName))
	{
		return false;
	}
	str = NewName;
	if (HasFilterNamed(NewName))
	{
		NewName = str $ i++;
	}
	NewFilter = CreateFilter(NewName);
	if (NewFilter == None)
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
void UBrowserFilters::ActivateFilter(int32 Index, bool Enable)
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
}
/*
void UBrowserFilters::IsActive(ACustomFilter* Test)
{
	if (Test == None)
	{
		return false;
	}
	return Test.IsActive();
}
*/
void UBrowserFilters::IsActiveAt(int32 Index)
{
	/*
	if (!ValidIndex(Index))
	{
		return false;
	}
	return AllFilters[Index].IsActive();
	*/
}
void UBrowserFilters::LoadSettings(int32 FilterIndex)
{
}
void UBrowserFilters::GetFilterName(int32 Index)
{
	/*
	if (!ValidIndex(Index))
	{
		return "";
	}
	return AllFilters[Index].GetTitle();
	*/
}
void UBrowserFilters::GetFilterRules(int32 Index)
{
	/*
	local array<AFilterRule> FilterRules;
	if (ValidIndex(Index))
	{
		AllFilters[Index].GetQueryRules(FilterRules);
	}
	return FilterRules;
	*/
}
void UBrowserFilters::GetFilterARules(int32 Index)
{
	/*
	local array<CurrentFilter> FilterRules;
	if (ValidIndex(Index))
	{
		AllFilters[Index].GetRules(FilterRules);
	}
	return FilterRules;
	*/
}
/*
void UBrowserFilters::PostEdit(int32 Index, FString NewTitle, array<AFilterRule> NewRules)
{
	if (ValidIndex(Index))
	{
		AllFilters[Index].PostEdit(NewTitle, NewRules);
	}
}
*/
void UBrowserFilters::GetFilterNames(bool bActiveOnly)
{
	/*
	local int i;
	local array<String> FilterNames;
	for (i = 0; i < AllFilters.Length; i++)
	{
		if (bActiveOnly && !AllFilters[i].IsActive())
		{
		}
		FilterNames[i] = AllFilters[i].GetTitle();
	}
	return FilterNames;
	*/
}
void UBrowserFilters::SetRule(int32 FilterIndex, int32 RuleIndex, FString RuleTag, FString RuleItem, FString RuleValue, FString DataType, FString QueryType, FString ExtraData)
{
}
/*
void UBrowserFilters::AddFilter(ACustomFilter* filter)
{
	
	local int i;
	if (filter == None)
	{
		return - 1;
	}
	i = FindFilterIndex(filter.GetTitle());
	if (i == -1)
	{
		AllFilters[AllFilters.Length] = filter;
	}
	return i;
}
*/
void UBrowserFilters::HasFilterNamed(FString FilterName)
{
	//Return FindFilterIndex(FilterName) != -1;
}
void UBrowserFilters::FindFilterIndex(FString FilterName)
{
	/*
	local int i;
	for (i = 0; i < AllFilters.Length; i++)
	{
		if (AllFilters[i].GetTitle() ~= FilterName)
		{
			return i;
		}
	}
	return - 1;
	*/
}
void UBrowserFilters::ValidIndex(int32 Index)
{
	//Return Index >= 0 && Index < AllFilters.Length && !bInvalidFilterClass;
}
void UBrowserFilters::ValidName(FString Test)
{
	//Return Test != "" && Len(Test) < 1024 && !bInvalidFilterClass;
}
void UBrowserFilters::Count()
{
	//Return AllFilters.Length;
}
