// All the original content belonged to the US Army


#include "AA29/Object/MBSFilters/MBSFilters.h"

UMBSFilters::UMBSFilters()
{
	/*
	Filters(0) = (CategoryName = "MISSIONS", FilterName = "Game Type", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Multiplayer", DBMBSFilters(0) = (Key = "coop", Value = "0"), GameSpyFilter = "(coop = 0)")
		Choices(2) = (Label = "Co-op", DBMBSFilters(0) = (Key = "coop", Value = "1"), GameSpyFilter = "(coop = 1)"), RuntimeChoiceGeneration = False)

	Filters(1) = (CategoryName = "MISSIONS", FilterName = "Tours", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Infantry", DBMBSFilters(0) = (Key = "tourCategory", Value = "Infantry"), GameSpyFilter = "((tour = 1) or (tour = 2) or (tour = 3))")
		Choices(2) = (Label = "Airborne / Ranger", DBMBSFilters(0) = (Key = "tourCategory", Value = "Airborne / Ranger"), GameSpyFilter = "((tour = 6) or (tour = 7) or (tour = 8))")
		Choices(3) = (Label = "Special Forces", DBMBSFilters(0) = (Key = "tourCategory", Value = "Special Forces"), GameSpyFilter = "((tour = 11) or (tour = 12))"), RuntimeChoiceGeneration = False)

	Filters(2) = (CategoryName = "MISSIONS", FilterName = "Maps", \\Choices=, RuntimeChoiceGeneration = True)

	Filters(3) = (CategoryName = "MISSIONS", FilterName = "Depot Official", \\Choices=, RuntimeChoiceGeneration = True)

	Filters(4) = (CategoryName = "MISSIONS", FilterName = "Depot Auth.", \\Choices=, RuntimeChoiceGeneration = True)

	Filters(5) = (CategoryName = "HONOR", FilterName = "Server Mode", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Official Honor Servers", DBMBSFilters(0) = (Key = "official", Value = "1"), GameSpyFilter = "(official = 1)")
		Choices(2) = (Label = "Non-Honor Servers", DBMBSFilters(0) = (Key = "official", Value = "0"), GameSpyFilter = "(official = 0)"), RuntimeChoiceGeneration = False)

	Filters(6) = (CategoryName = "HONOR", FilterName = "Avg. Honor", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "1-9 Retraining", DBMBSFilters(0) = (Key = "averageHonor", Value = ">0")
			DBMBSFilters(1) = (Key = "averageHonor", Value = "<10"), GameSpyFilter = "(average_honor >= 0) AND (average_honor < 10)")
		Choices(2) = (Label = "10-15 Beginner", DBMBSFilters(0) = (Key = "averageHonor", Value = ">9")
			DBMBSFilters(1) = (Key = "averageHonor", Value = "<16"), GameSpyFilter = "(average_honor >= 10) AND (average_honor < 15)")
		Choices(3) = (Label = "15-25 Intermediate", DBMBSFilters(0) = (Key = "averageHonor", Value = ">15")
			DBMBSFilters(1) = (Key = "averageHonor", Value = "<26"), GameSpyFilter = "(average_honor >= 15) AND (average_honor < 25)")
		Choices(4) = (Label = "25-50 Experienced", DBMBSFilters(0) = (Key = "averageHonor", Value = ">24")
			DBMBSFilters(1) = (Key = "averageHonor", Value = "<51"), GameSpyFilter = "(average_honor >= 25) AND (average_honor < 51)")
		Choices(5) = (Label = "50-75 Advanced", DBMBSFilters(0) = (Key = "averageHonor", Value = ">49")
			DBMBSFilters(1) = (Key = "averageHonor", Value = "<76"), GameSpyFilter = "(average_honor >= 50) AND (average_honor < 76)")
		Choices(6) = (Label = "75+ Expert", DBMBSFilters(0) = (Key = "averageHonor", Value = ">74"), GameSpyFilter = "(average_honor >= 75)"), RuntimeChoiceGeneration = False)

	Filters(7) = (CategoryName = "HONOR", FilterName = "Min. Honor", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "1", DBMBSFilters(0) = (Key = "minHonor", Value = ">=1"), GameSpyFilter = "(minHonor >= 1)")
		Choices(2) = (Label = "10", DBMBSFilters(0) = (Key = "minHonor", Value = ">=10"), GameSpyFilter = "(minHonor >= 10)")
		Choices(3) = (Label = "15", DBMBSFilters(0) = (Key = "minHonor", Value = ">=15"), GameSpyFilter = "(minHonor >= 15)")
		Choices(4) = (Label = "25", DBMBSFilters(0) = (Key = "minHonor", Value = ">=25"), GameSpyFilter = "(minHonor >= 25)")
		Choices(5) = (Label = "50", DBMBSFilters(0) = (Key = "minHonor", Value = ">=50"), GameSpyFilter = "(minHonor >= 50)")
		Choices(6) = (Label = "75", DBMBSFilters(0) = (Key = "minHonor", Value = ">=75"), GameSpyFilter = "(minHonor >= 75)"), RuntimeChoiceGeneration = False)

	Filters(8) = (CategoryName = "HONOR", FilterName = "Max. Honor", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "10", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=10"), GameSpyFilter = "(maxHonor <= 10)")
		Choices(2) = (Label = "15", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=15"), GameSpyFilter = "(maxHonor <= 15)")
		Choices(3) = (Label = "25", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=25"), GameSpyFilter = "(maxHonor <= 25)")
		Choices(4) = (Label = "50", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=50"), GameSpyFilter = "(maxHonor <= 50)")
		Choices(5) = (Label = "75", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=75"), GameSpyFilter = "(maxHonor <= 75)")
		Choices(6) = (Label = "100", DBMBSFilters(0) = (Key = "maxHonor", Value = "<=100"), GameSpyFilter = "(maxHonor <= 100)"), RuntimeChoiceGeneration = False)

	Filters(9) = (CategoryName = "SETTINGS", FilterName = "Password", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Open Public Servers", DBMBSFilters(0) = (Key = "requiresPassword", Value = "0"), GameSpyFilter = "(password = 0)")
		Choices(2) = (Label = "Password Protected Servers", DBMBSFilters(0) = (Key = "requiresPassword", Value = "1"), GameSpyFilter = "(password = 1)"), RuntimeChoiceGeneration = False)

	Filters(10) = (CategoryName = "SETTINGS", FilterName = "PunkBuster", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "PB Enabled Servers", DBMBSFilters(0) = (Key = "punkbuster", Value = "1"), GameSpyFilter = "(sv_punkbuster = 1)")
		Choices(2) = (Label = "PB Disabled Servers", DBMBSFilters(0) = (Key = "punkbuster", Value = "0"), GameSpyFilter = "(sv_punkbuster = 0)"), RuntimeChoiceGeneration = False)

	Filters(11) = (CategoryName = "SETTINGS", FilterName = "Tournaments", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Tournament Servers", DBMBSFilters(0) = (Key = "tournament", Value = "1"), GameSpyFilter = "(tournament = 1)")
		Choices(2) = (Label = "Non-Tournament Servers", DBMBSFilters(0) = (Key = "tournament", Value = "0"), GameSpyFilter = "(tournament = 0)"), RuntimeChoiceGeneration = False)

	Filters(12) = (CategoryName = "SETTINGS", FilterName = "Cheats", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Cheats Enabled", DBMBSFilters(0) = (Key = "cheats", Value = "1"), GameSpyFilter = "(cheats = 1)")
		Choices(2) = (Label = "Cheats Disabled", DBMBSFilters(0) = (Key = "cheats", Value = "0"), GameSpyFilter = "(cheats = 0)"), RuntimeChoiceGeneration = False)

	Filters(13) = (CategoryName = "SETTINGS", FilterName = "MILES", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "MILES Servers", DBMBSFilters(0) = (Key = "miles", Value = "1"), GameSpyFilter = "(miles = 1)")
		Choices(2) = (Label = "Live-Fire Servers", DBMBSFilters(0) = (Key = "miles", Value = "0"), GameSpyFilter = "(miles = 0)"), RuntimeChoiceGeneration = False)

	Filters(14) = (CategoryName = "STATUS", FilterName = "Players", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Not Empty and Not Full", DBMBSFilters(0) = (Key = "playerCount", Value = "<maxPlayers")
			DBMBSFilters(1) = (Key = "playerCount", Value = ">0"), GameSpyFilter = "(numplayers != maxplayers) AND (numplayers != 0)")
		Choices(2) = (Label = "Not Empty", DBMBSFilters(0) = (Key = "playerCount", Value = ">0"), GameSpyFilter = "(numplayers != 0)")
		Choices(3) = (Label = "Not Full", DBMBSFilters(0) = (Key = "playerCount", Value = "<maxPlayers"), GameSpyFilter = "(numplayers != maxplayers)"), RuntimeChoiceGeneration = False)

	Filters(15) = (CategoryName = "STATUS", FilterName = "Cur. Round", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "First round of match", DBMBSFilters(0) = (Key = "currentRound", Value = "0"), GameSpyFilter = "(current_round_int = 0)")
		Choices(2) = (Label = "Last round of match.", DBMBSFilters(0) = (Key = "currentRound", Value = "maxRounds"), GameSpyFilter = "(current_round_int = rounds_per_match)"), RuntimeChoiceGeneration = False)

	Filters(16) = (CategoryName = "STATUS", FilterName = "Time Left", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Less than 3 minutes", DBMBSFilters(0) = (Key = "currentRound", Value = "0"), GameSpyFilter = "(mission_time_remaining < 180)")
		Choices(2) = (Label = "3-5 minutes", DBMBSFilters(0) = (Key = "currentRound", Value = "maxRounds"), GameSpyFilter = "(mission_time_remaining >= 180) AND (mission_time_remaining <= 300)")
		Choices(3) = (Label = "More than 5 minutes", DBMBSFilters(0) = (Key = "currentRound", Value = "maxRounds"), GameSpyFilter = "(mission_time_remaining > 300)"), RuntimeChoiceGeneration = False)

	Filters(17) = (CategoryName = "STATUS", FilterName = "Avg. Ping", Choices(0) = (Label = "All", \\DBMBSFilters=, GameSpyFilter = "")
		Choices(1) = (Label = "Less than 50", DBMBSFilters(0) = (Key = "pingRate", Value = "<50"), GameSpyFilter = "")
		Choices(2) = (Label = "Less than 100", DBMBSFilters(0) = (Key = "pingRate", Value = "<100"), GameSpyFilter = "")
		Choices(3) = (Label = "Less than 150", DBMBSFilters(0) = (Key = "pingRate", Value = "<150"), GameSpyFilter = "")
		Choices(4) = (Label = "Less than 200", DBMBSFilters(0) = (Key = "pingRate", Value = "<200"), GameSpyFilter = "")
		Choices(5) = (Label = "Less than 300", DBMBSFilters(0) = (Key = "pingRate", Value = "<300"), GameSpyFilter = ""), RuntimeChoiceGeneration = False)

	Filters(18) = (CategoryName = "STATUS", FilterName = "Location", \\Choices=, RuntimeChoiceGeneration = True)

	*/
}



void UMBSFilters::OnGenerateChoices(FString CategoryName, FString FilterName)
{
}

void UMBSFilters::CreateActiveFilterSets()
{
	/*
	local int32 i;
	ActiveFiltersets = new (None) class'MBSFiltersActiveFiltersets';
	if (ActiveFiltersets != None)
	{
		for (i = 0; i < 5; i++)
		{
			ActiveFiltersets.Set[i] = 'MBSFiltersActiveFiltersets'.Default.Set[i];
		}
	}
	*/
}

void UMBSFilters::NumFilters(FString ServerBrowserType)
{
	/*
	if (ServerBrowserType ~= "GameSpy")
	{
		Return Filters.Length - 2;
	}
	else
	{
		Return Filters.Length;
	}
	*/
}

//native Function GetCategoryName(int32 Index);
void UMBSFilters::GetCategoryName(int32 Index)
{
}

//native Function GetFilterName(int32 Index);
void UMBSFilters::GetFilterName(int32 Index)
{
}

int32 UMBSFilters::NumFilterChoices(int32 Index)
{
	/*
	if (Filters[Index].RuntimeChoiceGeneration)
	{
		Filters[Index].Choices = OnGenerateChoices(Filters[Index].CategoryName, Filters[Index].FilterName);
		Filters[Index].RuntimeChoiceGeneration = False;
	}
	Return Filters[Index].Choices.Length;
	*/
	return -1;    //FAKE   /ELiZ
}

//native Function GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex);
void UMBSFilters::GetFilterChoiceLabel(int32 FilterIndex, int32 ChoiceIndex)
{
}

//native Function IsValidFilter(FActiveFilter filter);
void UMBSFilters::IsValidFilter(FActiveFilter filter)
{
}

void UMBSFilters::ActivateFilter(int32 FilterIndex, int32 ChoiceIndex)
{
	//Return ActivateFilterByName(GetCategoryName(FilterIndex), GetFilterName(FilterIndex), GetFilterChoiceLabel(FilterIndex, ChoiceIndex));
}

void UMBSFilters::DeactivateFilter(int32 FilterIndex, int32 ChoiceIndex)
{
	//Return DeactivateFilterByName(GetCategoryName(FilterIndex), GetFilterName(FilterIndex), GetFilterChoiceLabel(FilterIndex, ChoiceIndex));
}

bool UMBSFilters::ActivateFilterByName(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	/*
	local FActiveFilter filter;
	filter.CategoryName = CategoryName;
	filter.FilterName = FilterName;
	filter.FilterChoiceLabel = FilterChoiceLabel;
	if (IsValidFilter(filter) && !IsFilterActive(CategoryName, FilterName, FilterChoiceLabel))
	{
		HandleConflictingFilters(CategoryName, FilterName, FilterChoiceLabel);
		ActiveFiltersets.Set[CurrentFilterSet].List[ActiveFiltersets.Set[CurrentFilterSet].List.Length] = filter;
		ActiveFiltersets.SaveConfig();
		return true;
	}
	if (!IsValidFilter(filter))
	{
		Log("MBSFilters::ActivateFilter Unknown MBS Filter:" @ CategoryName @ FilterName @ FilterChoiceLabel);
	}
	*/
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
	/*
	local int32 Index;
	Index = GetFilterIndex(CategoryName, FilterName, FilterChoiceLabel);
	if (-1 != Index)
	{
		ActiveFiltersets.Set[CurrentFilterSet].List.remove(Index, 1);
		ActiveFiltersets.SaveConfig();
		return true;
	}
	Log("MBSFilters::DeactivateFilter Unknown MBS Filter:" @ CategoryName @ FilterName @ FilterChoiceLabel);
	*/
	return false;
}

bool UMBSFilters::IsFilterActive(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{
	/*
	if (-1 != GetFilterIndex(CategoryName, FilterName, FilterChoiceLabel))
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

//native Function GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel);
void UMBSFilters::GetFilterIndex(FString CategoryName, FString FilterName, FString FilterChoiceLabel)
{

}

void UMBSFilters::SetFilterSet(int32 FilterSet)
{
	//CurrentFilterSet = FilterSet;
}

void UMBSFilters::ClearFilterSet()
{
	//ActiveFiltersets.Set[CurrentFilterSet].List.Length = 0;
	//ActiveFiltersets.SaveConfig();
}

void UMBSFilters::DumpFilterSets()
{
	/*
	local int32 FilterSetIndex;
	local int32 FilterIndex;
	for (FilterSetIndex = 0; FilterSetIndex < 5; FilterSetIndex++)
	{
		Log("FilterSet" @ FilterSetIndex + 1);
		for (FilterIndex = 0; FilterIndex < ActiveFiltersets.Set[FilterSetIndex].List.Length; FilterIndex++)
		{
			Log("	" @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].CategoryName @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].FilterName @ ActiveFiltersets.Set[FilterSetIndex].List[FilterIndex].FilterChoiceLabel);
		}
	}
	*/
}

//native Function GetFilterAndChoiceIndexFromActiveFilter(out int32 FilterIndex, out int32 ChoiceIndex, int32 ActiveFilterIndex);
void UMBSFilters::GetFilterAndChoiceIndexFromActiveFilter(int32& FilterIndex, int32& ChoiceIndex, int32 ActiveFilterIndex)
{

}

void UMBSFilters::CreateDeploymentModeFilters(FString sDeploymentModeMap)
{
	/*
	local FActiveFilter filter;
	ActiveFiltersets.Set[CurrentFilterSet].List.Length = 9;
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

void UMBSFilters::BuildDBMBSFilterList()
{
	/*
	local array<ServerBrowserBase.FilterItem> FilterList;
	local int32 ActiveFilterIndex;
	local int32 FilterIndex;
	local int32 ChoiceIndex;
	local int32 DBMBSFilterIndex;
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Length; ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			for (DBMBSFilterIndex = 0; DBMBSFilterIndex < Filters[FilterIndex].Choices[ChoiceIndex].DBMBSFilters.Length; DBMBSFilterIndex++)
			{
				FilterList[FilterList.Length] = Filters[FilterIndex].Choices[ChoiceIndex].DBMBSFilters[DBMBSFilterIndex];
			}
		}
	}
	Return FilterList;
	*/
}

FString UMBSFilters::BuildGameSpyFilterString()
{
	FString GameSpyFilterString="";
	/*
	local int32 ActiveFilterIndex;
	local int32 FilterIndex;
	local int32 ChoiceIndex;
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Length; ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			GameSpyFilterString $ = Eval(Len(GameSpyFilterString) > 0, " AND ", "") $ Filters[FilterIndex].Choices[ChoiceIndex].GameSpyFilter;
		}
	}
	*/
	return GameSpyFilterString;
}

TArray<FKeyValuePair> UMBSFilters::BuildFilterDescriptions()
{
	TArray<FKeyValuePair> FilterDescriptions = {};
	/*
	local int32 ActiveFilterIndex;
	local int32 FilterIndex;
	local int32 ChoiceIndex;
	for (ActiveFilterIndex = 0; ActiveFilterIndex < ActiveFiltersets.Set[CurrentFilterSet].List.Length; ActiveFilterIndex++)
	{
		if (GetFilterAndChoiceIndexFromActiveFilter(FilterIndex, ChoiceIndex, ActiveFilterIndex))
		{
			FilterDescriptions.insert(FilterDescriptions.Length, 1);
			FilterDescriptions[FilterDescriptions.Length - 1].Key = Filters[FilterIndex].FilterName;
			FilterDescriptions[FilterDescriptions.Length - 1].Value = Filters[FilterIndex].Choices[ChoiceIndex].Label;
		}
	}
	*/
	return FilterDescriptions;
}