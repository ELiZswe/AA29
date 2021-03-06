// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AATreeAndExclusiveListPanel/AABrowser_FilterPanel/AABrowser_FilterPanel.h"
#include "AA29/Object/MBSFilters/MBSFilters.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"

UAABrowser_FilterPanel::UAABrowser_FilterPanel()
{

}

void UAABrowser_FilterPanel::OnFiltersChanged()
{
}

void UAABrowser_FilterPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	SetTreeHeader("CATEGORIES");
	SetExclusiveListHeader("FILTERS");
	//Filters = new (None) UMBSFilters::StaticClass();
	if (Filters != nullptr)
	{
		//Filters->__OnGenerateChoices__Delegate = InternalOnGenerateChoices;
		Filters->CreateActiveFilterSets();
	}
}

void UAABrowser_FilterPanel::SetFilterSet(int32 FilterSetIndex)
{
	Filters->SetFilterSet(FilterSetIndex);
	RebuildExclusiveList();
}

void UAABrowser_FilterPanel::ClearFilterSet()
{
	Filters->ClearFilterSet();
	RebuildExclusiveList();
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
	Filters->CreateDeploymentModeFilters(sDeploymentModeMap);
	RebuildExclusiveList();
}

FString UAABrowser_FilterPanel::GetGameSpyFilterString()
{
	return Filters->BuildGameSpyFilterString();
}

TArray<FFilterItem> UAABrowser_FilterPanel::GetDBMBSFilterList()
{
	return Filters->BuildDBMBSFilterList();
}

int32 UAABrowser_FilterPanel::NumItemsInTree()
{
	//return Filters->NumFilters(AAGP_HUD::StaticClass().Default.ServerBrowser);
	return 0;    //FAKE    /ELiZ
}

bool UAABrowser_FilterPanel::GetItemForTreeAtIndex(FGUITreeNode& TreeNode, int32 Index)
{
	TreeNode.ParentCaption = Filters->GetCategoryName(Index);
	TreeNode.Caption = Filters->GetFilterName(Index);
	return true;
}

int32 UAABrowser_FilterPanel::NumItemsInExclusiveList(int32 TreeIndex)
{
	return Filters->NumFilterChoices(TreeIndex);
}

bool UAABrowser_FilterPanel::GetItemForExclusiveList(FString& Label, int32 TreeIndex, int32 Index)
{
	Label = Filters->GetFilterChoiceLabel(TreeIndex, Index);
	return true;
}

bool UAABrowser_FilterPanel::IsExclusiveListChoice(int32 TreeIndex, int32 ChoiceIndex)
{
	return Filters->IsFilterActive(Filters->GetCategoryName(TreeIndex), Filters->GetFilterName(TreeIndex), Filters->GetFilterChoiceLabel(TreeIndex, ChoiceIndex));
}

void UAABrowser_FilterPanel::InternalOnExclusiveItemSelection(int32 TreeIndex, int32 ChoiceIndex)
{
	/*
	Log(Self + "InternalOnExclusiveItemSelection() ");
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
	if (ChoiceIndex != 0)
	{
		Filters->DeactivateFilter(TreeIndex, ChoiceIndex);
	}
	OnFiltersChanged();
}

TArray<FString> UAABrowser_FilterPanel::GetMapNames(TArray<int32> SelectedTours)
{
	TArray<FString> MapNames = {};
	int32 NumTours = 0;
	int32 TourIndex = 0;
	int32 NumMissions = 0;
	int32 MissionIndex = 0;
	int32 MapNameIndex = 0;
	FString TourFilename = "";
	FString MissionName = "";
	AActor* anActor = nullptr;
	ALevelInfo* Level = nullptr;
	bool bFoundMatch = false;
	int32 i = 0;
	/*
	ForEach(Class'Actor', anActor)
	{
		GOTO JL0013;
	JL0013:
	}
	Level = anActor.Level;
	TourFilename = GetBaseDir() + "Tours.ini";
	NumTours = GetPrivateProfileInt(TourFilename, "Tours", "NumTours");
	for (TourIndex = 0; TourIndex < NumTours; TourIndex++)
	{
		if (SelectedTours.Num() > 0)
		{
			bFoundMatch = false;
			i = 0;
			if (i < SelectedTours.Num())
			{
				if (SelectedTours[i] == TourIndex)
				{
					bFoundMatch = true;
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
					if (MapNameIndex < MapNames.Num())
					{
						if (MissionName <= MapNames[MapNameIndex])
						{
						}
						else
						{
							if (MapNameIndex + 1 < MapNames.Num() && MissionName <= MapNames[MapNameIndex + 1])
							{
								MapNameIndex++;
							}
						}
					else
					{
						++MapNameIndex;
					}
					}
					if (MapNameIndex < MapNames.Num())
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
	int32 Count = 0;
	int32 Index = 0;
	TArray<FString> MapNames ={};
	TArray<int32> ValidTours = {};
	int32 i = 0;
	int32 ChoiceOffset = 0;
	/*
	Choices.Num() = 1;
	Choices[0].Label = "All";
	if (CategoryName ~= "Missions" && FilterName ~= "Maps" || FilterName ~= "Depot Official" || FilterName ~= "Depot Auth.")
	{
		if (FilterName == "Depot Official")
		{
			ValidTours[0] = 15;
			ValidTours[1] = 16;
			Choices.Num() = 3;
			Choices[0].Label @ = "Maps";
			Choices[1].Label = "All Depot Official Non-SF Maps";
			Choices[1].DBMBSFilters.Num() = 1;
			Choices[1].DBMBSFilters[0].Key = "tour";
			Choices[1].DBMBSFilters[0].Value = "15";
			Choices[1].GameSpyFilter = "(tour = 15)";
			Choices[2].Label = "All Depot Official SF Maps";
			Choices[2].DBMBSFilters.Num() = 1;
			Choices[2].DBMBSFilters[0].Key = "tour";
			Choices[2].DBMBSFilters[0].Value = "16";
			Choices[2].GameSpyFilter = "(tour = 16)";
		}
		else
		{
			if (FilterName == "Depot Auth.")
			{
				ValidTours[0] = 30;
				Choices.Num() = 2;
				Choices[0].Label @ = "Maps";
				Choices[1].Label = "All Depot Auth. Maps";
				Choices[1].DBMBSFilters.Num() = 1;
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
		Count = MapNames.Num();
		ChoiceOffset = Choices.Num();
		Choices.insert(ChoiceOffset + 1, Count);
		for (Index = 0; Index < Count; Index++)
		{
			Choices[Index + ChoiceOffset].Label = MapNames[Index];
			Choices[Index + ChoiceOffset].GameSpyFilter = "(mapname = '" + MapNames[Index] + "')";
			Choices[Index + ChoiceOffset].DBMBSFilters.Num() = 1;
			Choices[Index + ChoiceOffset].DBMBSFilters[0].Key = "mapName";
			Choices[Index + ChoiceOffset].DBMBSFilters[0].Value = MapNames[Index];
		}
	}
	else
	{
		if (CategoryName ~= "Status" && FilterName ~= "Location")
		{
			Count = 'AAFilterPage'.Default.Countries.Num();
			Choices.insert(1, Count);
			for (Index = 1; Index <= Count; Index++)
			{
				Choices[Index].Label = 'AAFilterPage'.Default.Countries[Index - 1];
				Choices[Index].DBMBSFilters.Num() = 1;
				Choices[Index].DBMBSFilters[0].Key = "locale";
				Choices[Index].DBMBSFilters[0].Value = 'AAFilterPage'.Default.Countries[Index - 1];
			}
		}
	}
	*/
	return Choices;
}
