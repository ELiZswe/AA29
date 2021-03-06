// All the original content belonged to the US Army

#include "AA29/Object/MBSFilters/MBSFilters.h"
#include "AA29/Object/MBSFiltersActiveFiltersets/MBSFiltersActiveFiltersets.h"

UMBSFilters::UMBSFilters()
{
	/*
	Filters(0) = ({ "MISSIONS","Game Type",({"All",""})
		Choices(1),False })
	Filters(1) = ({ "MISSIONS","Tours",({"All",""})
		Choices(1),False })
	Filters(2) = ({ "MISSIONS","Maps",True })
	Filters(3) = ({ "MISSIONS","Depot Official",True })
	Filters(4) = ({ "MISSIONS","Depot Auth.",True })
	Filters(5) = ({ "HONOR","Server Mode",({"All",""})
		Choices(1),False })
	Filters(6) = ({ "HONOR","Avg. Honor",({"All",""})
		Choices(1),False })
	Filters(7) = ({ "HONOR","Min. Honor",({"All",""})
		Choices(1),False })
	Filters(8) = ({ "HONOR","Max. Honor",({"All",""})
		Choices(1),False })
	Filters(9) = ({ "SETTINGS","Password",({"All",""})
		Choices(1),False })
	Filters(10) = ({ "SETTINGS","PunkBuster",({"All",""})
		Choices(1),False })
	Filters(11) = ({ "SETTINGS","Tournaments",({"All",""})
		Choices(1),False })
	Filters(12) = ({ "SETTINGS","Cheats",({"All",""})
		Choices(1),False })
	Filters(13) = ({ "SETTINGS","MILES",({"All",""})
		Choices(1),False })
	Filters(14) = ({ "STATUS","Players",({"All",""})
		Choices(1),False })
	Filters(15) = ({ "STATUS","Cur. Round",({"All",""})
		Choices(1),False })
	Filters(16) = ({ "STATUS","Time Left",({"All",""})
		Choices(1),False })
	Filters(17) = ({ "STATUS","Avg. Ping",({"All",""})
		Choices(1),False })
	Filters(18) = ({ "STATUS","Location",True });
	*/
}

void UMBSFilters::OnGenerateChoices(FString CategoryName, FString FilterName)
{
}

void UMBSFilters::CreateActiveFilterSets()
{
	int32 i = 0;
	/*
	ActiveFiltersets = new (None) UMBSFiltersActiveFiltersets::StaticClass();
	if (ActiveFiltersets != nullptr)
	{
		for (i = 0; i < 5; i++)
		{
			ActiveFiltersets.Set[i] = 'MBSFiltersActiveFiltersets'.Default.Set[i];
		}
	}
	*/
}

int32 UMBSFilters::NumFilters(FString ServerBrowserType)
{
	if (ServerBrowserType.Compare("GameSpy", ESearchCase::IgnoreCase))
	{
		return Filters.Num() - 2;
	}
	else
	{
		return Filters.Num();
	}
}

//native Function GetCategoryName(int32 Index);
FString UMBSFilters::GetCategoryName(int32 Index)
{
	return "";     //FAKE   /ELiZ
}

//native Function GetFilterName(int32 Index);
FString UMBSFilters::GetFilterName(int32 Index)
{
	return "";     //FAKE   /ELiZ
}

int32 UMBSFilters::NumFilterChoices(int32 Index)
{
	if (Filters[Index].RuntimeChoiceGeneration)
	{
		//Filters[Index].Choices = OnGenerateChoices(Filters[Index].CategoryName, Filters[Index].FilterName);
		Filters[Index].RuntimeChoiceGeneration = false;
	}
	return Filters[Index].Choices.Num();
}

//native Function GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex);
FString UMBSFilters::GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex)
{
	return "";    //FAKE   /ELiZ
}

//native Function IsValidFilter(FActiveFilter filter);
bool UMBSFilters::IsValidFilter(FActiveFilter filter)
{
	return false;    //FAKE   /ELiZ
}

bool UMBSFilters::ActivateFilter(int32 FilterIndex, int32 ChoiceIndex)
{
	return ActivateFilterByName(GetCategoryName(FilterIndex), GetFilterName(FilterIndex), GetFilterChoiceLabel(FilterIndex, ChoiceIndex));
}

bool UMBSFilters::DeactivateFilter(int32 FilterIndex, int32 ChoiceIndex)
{
	return DeactivateFilterByName(GetCategoryName(FilterIndex), GetFilterName(FilterIndex), GetFilterChoiceLabel(FilterIndex, ChoiceIndex));
}

bool UMBSFilters::ActivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	FActiveFilter filter = FActiveFilter({});
	filter.CategoryName = CategoryName;
	filter.FilterName = FilterName;
	filter.FilterChoiceLabel = FilterChoiceLabel;
	if (IsValidFilter(filter) && !IsFilterActive(CategoryName, FilterName, FilterChoiceLabel))
	{
		HandleConflictingFilters(CategoryName, FilterName, FilterChoiceLabel);
		//ActiveFiltersets->Set[CurrentFilterSet]->List[ActiveFiltersets->Set[CurrentFilterSet]->List.Num()] = filter;
		ActiveFiltersets->SaveConfig();
		return true;
	}
	if (!IsValidFilter(filter))
	{
		//Log("MBSFilters::ActivateFilter Unknown MBS Filter:" @ CategoryName @ FilterName @ FilterChoiceLabel);
	}
	return false;
}

void UMBSFilters::HandleConflictingFilters(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	/*
	if (CategoryName ~= "Missions")
	{
		if (FilterName ~= "Maps")
		{
			if (IsFilterActive("Missions", "Depot Auth.", ""))
			{
				DeactivateFilterByName("Missions", "Depot Auth.", "");
			}
			if (IsFilterActive("Missions", "Depot Official", ""))
			{
				DeactivateFilterByName("Missions", "Depot Official", "");
			}
		}
		else
		{
			if (FilterName ~= "Depot Auth.")
			{
				if (IsFilterActive("Missions", "Maps", ""))
				{
					DeactivateFilterByName("Missions", "Maps", "");
				}
				if (IsFilterActive("Missions", "Depot Official", ""))
				{
					DeactivateFilterByName("Missions", "Depot Official", "");
				}
			}
			else
			{
				if (FilterName ~= "Depot Official")
				{
					if (IsFilterActive("Missions", "Depot Auth.", ""))
					{
						DeactivateFilterByName("Missions", "Depot Auth.", "");
					}
					if (IsFilterActive("Missions", "Maps", ""))
					{
						DeactivateFilterByName("Missions", "Maps", "");
					}
				}
			}
		}
	}
	*/
}

void UMBSFilters::ClearDependentFilters(FString CategoryName, FString FilterName)
{
	/*
	if (CategoryName ~= "Missions")
	{
		if (FilterName ~= "Maps" || FilterName ~= "Depot Official" || FilterName ~= "Depot Auth.")
		{
			if (IsFilterActive("Missions", "Maps", ""))
			{
				DeactivateFilterByName("Missions", "Maps", "");
			}
			if (IsFilterActive("Missions", "Depot Official", ""))
			{
				DeactivateFilterByName("Missions", "Depot Official", "");
			}
			if (IsFilterActive("Missions", "Depot Auth.", ""))
			{
				DeactivateFilterByName("Missions", "Depot Auth.", "");
			}
		}
	}
	*/
}

bool UMBSFilters::DeactivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	int32 Index = 0;
	/*
	Index = GetFilterIndex(CategoryName, FilterName, FilterChoiceLabel);
	if (-1 != Index)
	{
		ActiveFiltersets.Set[CurrentFilterSet].List.RemoveAt(Index, 1);
		ActiveFiltersets.SaveConfig();
		return true;
	}
	Log("MBSFilters::DeactivateFilter Unknown MBS Filter:" @ CategoryName @ FilterName @ FilterChoiceLabel);
	*/
	return false;
}

bool UMBSFilters::IsFilterActive(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	if ( GetFilterIndex(CategoryName, FilterName, FilterChoiceLabel) != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//native Function GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
int32 UMBSFilters::GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	return 0;    //FAKE   /ELiZ
}

void UMBSFilters::SetFilterSet(int32 FilterSet)
{
	//CurrentFilterSet = FilterSet;
}

void UMBSFilters::ClearFilterSet()
{
	//ActiveFiltersets.Set[CurrentFilterSet].List.Num() = 0;
	//ActiveFiltersets.SaveConfig();
}

void UMBSFilters::DumpFilterSets()
{
	int32 FilterSetIndex = 0;
	int32 FilterIndex = 0;
	/*
	for (FilterSetIndex = 0; FilterSetIndex < 5; FilterSetIndex++)
	{
		Log("FilterSet" @ FilterSetIndex + 1);
		for (FilterIndex = 0; FilterIndex < ActiveFiltersets.Set[FilterSetIndex].List.Num(); FilterIndex++)
		{
			Log("	" @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].CategoryName @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].FilterName @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].FilterChoiceLabel);
		}
	}
	*/
}

//native Function GetFilterAndChoiceIndexFromActiveFilter(out int32 FilterIndex, out int32 ChoiceIndex, int32 ActiveFilterIndex);
bool UMBSFilters::GetFilterAndChoiceIndexFromActiveFilter(int32& FilterIndex, int32& ChoiceIndex, int32 ActiveFilterIndex)
{
	return false;    //FAKE  /EliZ
}

void UMBSFilters::CreateDeploymentModeFilters(FString sDeploymentModeMap)
{
	FActiveFilter filter = FActiveFilter({});
	/*
	ActiveFiltersets.Set[CurrentFilterSet].List.Num() = 9;
	filter.CategoryName = "MISSIONS";
	filter.FilterName = "Maps";
	filter.FilterChoiceLabel = sDeploymentModeMap;
	ActiveFiltersets.Set[CurrentFilterSet].List[0] = filter;
	filter.CategoryName = "MISSIONS";
	filter.FilterName = "Depot Official";
	filter.FilterChoiceLabel = "Depot Official";
	ActiveFiltersets.Set[CurrentFilterSet].List[1] = filter;
	filter.CategoryName = "MISSIONS";
	filter.FilterName = "Depot Auth.";
	filter.FilterChoiceLabel = "Depot Auth.";
	ActiveFiltersets.Set[CurrentFilterSet].List[2] = filter;
	filter.CategoryName = "HONOR";
	filter.FilterName = "Server Mode";
	filter.FilterChoiceLabel = "Official Honor Servers";
	ActiveFiltersets.Set[CurrentFilterSet].List[3] = filter;
	filter.CategoryName = "STATUS";
	filter.FilterName = "Players";
	filter.FilterChoiceLabel = "Not Full";
	ActiveFiltersets.Set[CurrentFilterSet].List[4] = filter;
	filter.CategoryName = "SETTINGS";
	filter.FilterName = "Tournaments";
	filter.FilterChoiceLabel = "Non-Tournament Servers";
	ActiveFiltersets.Set[CurrentFilterSet].List[5] = filter;
	filter.CategoryName = "SETTINGS";
	filter.FilterName = "PunkBuster";
	filter.FilterChoiceLabel = "PB Enabled Servers";
	ActiveFiltersets.Set[CurrentFilterSet].List[6] = filter;
	filter.CategoryName = "SETTINGS";
	filter.FilterName = "Cheats";
	filter.FilterChoiceLabel = "Cheats Disabled";
	ActiveFiltersets.Set[CurrentFilterSet].List[7] = filter;
	filter.CategoryName = "SETTINGS";
	filter.FilterName = "MILES";
	filter.FilterChoiceLabel = "Live-Fire Servers";
	ActiveFiltersets.Set[CurrentFilterSet].List[8] = filter;
	*/
}

TArray<FFilterItem> UMBSFilters::BuildDBMBSFilterList()
{
	TArray<FFilterItem> FilterList = {};
	int32 ActiveFilterIndex = 0;
	int32 FilterIndex = 0;
	int32 ChoiceIndex = 0;
	int32 DBMBSFilterIndex = 0;
	/*
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Num(); ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			for (DBMBSFilterIndex = 0; DBMBSFilterIndex < Filters[FilterIndex].Choices[ChoiceIndex].DBMBSFilters.Num(); DBMBSFilterIndex++)
			{
				FilterList[FilterList.Num()] = Filters[FilterIndex].Choices[ChoiceIndex].DBMBSFilters[DBMBSFilterIndex];
			}
		}
	}
	*/
	return FilterList;
}

FString UMBSFilters::BuildGameSpyFilterString()
{
	FString GameSpyFilterString="";
	int32 ActiveFilterIndex = 0;
	int32 FilterIndex = 0;
	int32 ChoiceIndex = 0;
	/*
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Num(); ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			GameSpyFilterString += Eval(Len(GameSpyFilterString) > 0, " AND ", "") + Filters[FilterIndex].Choices[ChoiceIndex].GameSpyFilter;
		}
	}
	*/
	return GameSpyFilterString;
}

TArray<FKeyValuePair> UMBSFilters::BuildFilterDescriptions()
{
	TArray<FKeyValuePair> FilterDescriptions = {};
	int32 ActiveFilterIndex = 0;
	int32 FilterIndex = 0;
	int32 ChoiceIndex = 0;
	/*
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Num(); ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			FilterDescriptions.insert(FilterDescriptions.Num(), 1);
			FilterDescriptions[FilterDescriptions.Num() - 1].Key = Filters[FilterIndex].FilterName;
			FilterDescriptions[FilterDescriptions.Num() - 1].Value = Filters[FilterIndex].Choices[ChoiceIndex].Label;
		}
	}
	*/
	return FilterDescriptions;
}
