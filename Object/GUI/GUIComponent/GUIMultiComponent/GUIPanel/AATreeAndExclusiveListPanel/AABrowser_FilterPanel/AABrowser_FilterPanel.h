// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AATreeAndExclusiveListPanel/AATreeAndExclusiveListPanel.h"
#include "AABrowser_FilterPanel.generated.h"

class UMBSFilters;
class UGUITreeNode;

UCLASS()
class AA29_API UAABrowser_FilterPanel : public UAATreeAndExclusiveListPanel
{
	GENERATED_BODY()
public:
	UAABrowser_FilterPanel();

	UPROPERTY()							UMBSFilters*		Filters;			//var MBSFilters Filters;

	void OnFiltersChanged();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetFilterSet(int32 FilterSetIndex);
	void ClearFilterSet();
	void ShowFilterSummary();
	void PutIntoDeploymentMode(FString sDeploymentModeMap);
	void GetGameSpyFilterString();
	void GetDBMBSFilterList();
	void NumItemsInTree();
	bool GetItemForTreeAtIndex(UGUITreeNode*& TreeNode, int32 Index);
	void NumItemsInExclusiveList(int32 TreeIndex);
	bool GetItemForExclusiveList(FString& Label, int32 TreeIndex, int32 Index);
	void IsExclusiveListChoice(int32 TreeIndex, int32 ChoiceIndex);
	void InternalOnExclusiveItemSelection(int32 TreeIndex, int32 ChoiceIndex);
	void InternalOnExclusiveItemDeselection(int32 TreeIndex, int32 ChoiceIndex);
	TArray<FString> GetMapNames(TArray<int32> SelectedTours);
	TArray<FFilterChoice> InternalOnGenerateChoices(FString CategoryName, FString FilterName);
};
