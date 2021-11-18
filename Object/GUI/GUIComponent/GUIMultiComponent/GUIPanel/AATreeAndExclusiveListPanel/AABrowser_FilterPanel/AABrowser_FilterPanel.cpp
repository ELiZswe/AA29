// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AATreeAndExclusiveListPanel/AABrowser_FilterPanel/AABrowser_FilterPanel.h"

UAABrowser_FilterPanel::UAABrowser_FilterPanel()
{

}

void UAABrowser_FilterPanel::OnFiltersChanged()
{
}

void UAABrowser_FilterPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	SetTreeHeader("CATEGORIES");
	SetExclusiveListHeader("FILTERS");
	Filters = new (None) class'MBSFilters';
	if (Filters != None)
	{
		Filters.__OnGenerateChoices__Delegate = InternalOnGenerateChoices;
		Filters.CreateActiveFilterSets();
	}
	*/
}

void UAABrowser_FilterPanel::SetFilterSet(int32 FilterSetIndex)
{
	/*
	Filters.SetFilterSet(FilterSetIndex);
	RebuildExclusiveList();
	*/
}

void UAABrowser_FilterPanel::ClearFilterSet()
{
	/*
	Filters.ClearFilterSet();
	RebuildExclusiveList();
	*/
}
void UAABrowser_FilterPanel::ShowFilterSummary()
{
	/*
	if (Controller.OpenMenu("AGP_Interface.AAShowFiltersDialog"))
	{
		AAShowFiltersDialog(Controller.ActivePage).SetFilterDescriptions(Filters.BuildFilterDescriptions());
	}
	*/
}

void UAABrowser_FilterPanel::PutIntoDeploymentMode(FString sDeploymentModeMap)
{
	//Filters.CreateDeploymentModeFilters(sDeploymentModeMap);
	//RebuildExclusiveList();
}

void UAABrowser_FilterPanel::GetGameSpyFilterString()
{
	//Return Filters.BuildGameSpyFilterString();
}

void UAABrowser_FilterPanel::GetDBMBSFilterList()
{
	//Return Filters.BuildDBMBSFilterList();
}

void UAABrowser_FilterPanel::NumItemsInTree()
{
	//Return Filters.NumFilters(Class'AGP_HUD'.Default.ServerBrowser);
}

bool UAABrowser_FilterPanel::GetItemForTreeAtIndex(UGUITreeNode*& TreeNode, int32 Index)
{
	/*
	TreeNode.ParentCaption = Filters.GetCategoryName(Index);
	TreeNode.Caption = Filters.GetFilterName(Index);
	*/
	return true;
}

void UAABrowser_FilterPanel::NumItemsInExclusiveList(int32 TreeIndex)
{
	//Return Filters.NumFilterChoices(TreeIndex);
}

bool UAABrowser_FilterPanel::GetItemForExclusiveList(FString& Label, int32 TreeIndex, int32 Index)
{
	//Label = Filters.GetFilterChoiceLabel(TreeIndex, Index);
	return true;
}

void UAABrowser_FilterPanel::IsExclusiveListChoice(int32 TreeIndex, int32 ChoiceIndex)
{
	//Return Filters.IsFilterActive(Filters.GetCategoryName(TreeIndex), Filters.GetFilterName(TreeIndex), Filters.GetFilterChoiceLabel(TreeIndex, ChoiceIndex));
}

void UAABrowser_FilterPanel::InternalOnExclusiveItemSelection(int32 TreeIndex, int32 ChoiceIndex)
{
	/*
	Log(Self $ "InternalOnExclusiveItemSelection() ");
	Filters.ActivateFilter(TreeIndex, ChoiceIndex);
	if (ChoiceIndex == 0)
	{
		Filters.ClearDependentFilters(Filters.GetCategoryName(TreeIndex), Filters.GetFilterName(TreeIndex));
	}
	OnFiltersChanged();
	*/
}

void UAABrowser_FilterPanel::InternalOnExclusiveItemDeselection(int32 TreeIndex, int32 ChoiceIndex)
{
	/*
	if (ChoiceIndex != 0)
	{
		Filters.DeactivateFilter(TreeIndex, ChoiceIndex);
	}
	OnFiltersChanged();
	*/
}

TArray<FString> UAABrowser_FilterPanel::GetMapNames(TArray<int32> SelectedTours)
{
	TArray<FString> MapNames = {};
	/*
	local int32 NumTours;
	local int32 TourIndex;
	local int32 NumMissions;
	local int32 MissionIndex;
	local int32 MapNameIndex;
	local FString TourFilename;
	local FString MissionName;
	local Actor anActor;
	local LevelInfo Level;
	local bool bFoundMatch;
	local int32 i;
	ForEach(Class'Actor', anActor)
	{
		GOTO JL0013;
	JL0013:
	}
	Level = anActor.Level;
	TourFilename = GetBaseDir() $ "Tours.ini";
	NumTours = GetPrivateProfileInt(TourFilename, "Tours", "NumTours");
	for (TourIndex = 0; TourIndex < NumTours; TourIndex++)
	{
		if (SelectedTours.Length > 0)
		{
			bFoundMatch = False;
			i = 0;
			if (i < SelectedTours.Length)
			{
				if (SelectedTours[i] == TourIndex)
				{
					bFoundMatch = True;
				}
				else
				{
					i++;
				}
			}
			if (!bFoundMatch)
			{
			}
		}
		else
		{
			if (!Level.GetTourIsTraining(TourIndex))
			{
				NumMissions = Level.GetTourMissions(TourIndex);
				for (MissionIndex = 0; MissionIndex < NumMissions; MissionIndex++)
				{
					MissionName = Level.GetTourMissionMBSTitle(TourIndex, MissionIndex);
					MapNameIndex = 0;
					if (MapNameIndex < MapNames.Length)
					{
						if (MissionName <= MapNames[MapNameIndex])
						{
						}
						else
						{
							if (MapNameIndex + 1 < MapNames.Length && MissionName <= MapNames[MapNameIndex + 1])
							{
								MapNameIndex++;
							}
						}
					else
					{
						++MapNameIndex;
					}
					}
					if (MapNameIndex < MapNames.Length)
					{
						MapNames.insert(MapNameIndex, 1);
					}
					MapNames[MapNameIndex] = MissionName;
				}
			}
		}
	}
	*/
	return MapNames;
}

TArray<FFilterChoice> UAABrowser_FilterPanel::InternalOnGenerateChoices(FString CategoryName, FString FilterName)
{
	TArray<FFilterChoice> Choices = {};
	/*
	local int32 Count;
	local int32 Index;
	local array<String> MapNames;
	local array<int> ValidTours;
	local int32 i;
	local int32 ChoiceOffset;
	Choices.Length = 1;
	Choices[0].Label = "All";
	if (CategoryName ~= "Missions" && FilterName ~= "Maps" || FilterName ~= "Depot Official" || FilterName ~= "Depot Auth.")
	{
		if (FilterName == "Depot Official")
		{
			ValidTours[0] = 15;
			ValidTours[1] = 16;
			Choices.Length = 3;
			Choices[0].Label @ = "Maps";
			Choices[1].Label = "All Depot Official Non-SF Maps";
			Choices[1].DBMBSFilters.Length = 1;
			Choices[1].DBMBSFilters[0].Key = "tour";
			Choices[1].DBMBSFilters[0].Value = "15";
			Choices[1].GameSpyFilter = "(tour = 15)";
			Choices[2].Label = "All Depot Official SF Maps";
			Choices[2].DBMBSFilters.Length = 1;
			Choices[2].DBMBSFilters[0].Key = "tour";
			Choices[2].DBMBSFilters[0].Value = "16";
			Choices[2].GameSpyFilter = "(tour = 16)";
		}
		else
		{
			if (FilterName == "Depot Auth.")
			{
				ValidTours[0] = 30;
				Choices.Length = 2;
				Choices[0].Label @ = "Maps";
				Choices[1].Label = "All Depot Auth. Maps";
				Choices[1].DBMBSFilters.Length = 1;
				Choices[1].DBMBSFilters[0].Key = "tour";
				Choices[1].DBMBSFilters[0].Value = "30";
				Choices[1].GameSpyFilter = "(tour = 30)";
			}
			else
			{
				for (i = 0; i <= 14; i++)
				{
					ValidTours[i] = i;
				}
				Choices[0].Label @ = "Maps";
			}
		}
		MapNames = GetMapNames(ValidTours);
		Count = MapNames.Length;
		ChoiceOffset = Choices.Length;
		Choices.insert(ChoiceOffset + 1, Count);
		for (Index = 0; Index < Count; Index++)
		{
			Choices[Index + ChoiceOffset].Label = MapNames[Index];
			Choices[Index + ChoiceOffset].GameSpyFilter = "(mapname = '" $ MapNames[Index] $ "')";
			Choices[Index + ChoiceOffset].DBMBSFilters.Length = 1;
			Choices[Index + ChoiceOffset].DBMBSFilters[0].Key = "mapName";
			Choices[Index + ChoiceOffset].DBMBSFilters[0].Value = MapNames[Index];
		}
	}
	else
	{
		if (CategoryName ~= "Status" && FilterName ~= "Location")
		{
			Count = 'AAFilterPage'.Default.Countries.Length;
			Choices.insert(1, Count);
			for (Index = 1; Index <= Count; Index++)
			{
				Choices[Index].Label = 'AAFilterPage'.Default.Countries[Index - 1];
				Choices[Index].DBMBSFilters.Length = 1;
				Choices[Index].DBMBSFilters[0].Key = "locale";
				Choices[Index].DBMBSFilters[0].Value = 'AAFilterPage'.Default.Countries[Index - 1];
			}
		}
	}
	*/
	return Choices;
}

