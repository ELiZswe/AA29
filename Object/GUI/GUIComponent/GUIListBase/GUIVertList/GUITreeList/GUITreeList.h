// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "GUITreeList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUITreeList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UGUITreeList();

	UPROPERTY(EditAnywhere)							bool						bGroupItems;					//var() bool bGroupItems;
	UPROPERTY(EditAnywhere)							bool						bAllowDuplicateCaption;			//var() bool bAllowDuplicateCaption;
	UPROPERTY(EditAnywhere)							bool						bAllowParentSelection;			//var() bool bAllowParentSelection;
	UPROPERTY(EditAnywhere)							float						SelectedPrefixWidth;			//var() const editconst float SelectedPrefixWidth;
	UPROPERTY(EditAnywhere)							float						PrefixWidth;					//var() const editconst float PrefixWidth;
	UPROPERTY(EditAnywhere)							int32						VisibleCount;					//var() const editconst int VisibleCount;
	UPROPERTY(EditAnywhere)							TArray<FGUITreeNode>		SelectedElements;				//var() editconstarray editconst array<GUITreeNode> SelectedElements;
	UPROPERTY(EditAnywhere)							TArray<FGUITreeNode>		Elements;						//var() editconstarray editconst array<GUITreeNode> Elements;
	UPROPERTY(EditAnywhere)							EeTextAlign					HorzBorder;						//var() GUI.eTextAlign TextAlign;

	void UpdateVisibleCount();
	void SortList();
	void CompareItem(FGUITreeNode ElemA, FGUITreeNode ElemB);
	int32 addItem(FString Caption, FString Value, FString ParentCaption, bool bEnabled, FString ExtraInfo);
	void AddElement(FGUITreeNode Node);
	void Replace(int32 i, FString NewItem, FString NewValue, FString ParentCaption, bool bNoSort, FString ExtraInfo);
	void InsertItem(int32 idx, FString Caption, FString Value, FString ParentCaption, int32 Level, bool bEnabled, FString ExtraInfo);
	int32 HardInsert(int32 idx, FString Caption, FString Value, FString ParentCaption, int32 Level, bool bEnabled, FString ExtraInfo);
	void LoadFrom(UGUITreeList* Source, bool bClearFirst);
	int32 RemoveSilent(FString Caption);
	int32 RemoveItem(FString Caption);
	int32 RemoveItemAt(int32 idx, bool bNoSort, bool bSkipCleanup);
	int32 RemoveElement(FGUITreeNode Node, int32 Count, bool bNoSort);
	void Clear();
	bool Swap(int32 IndexA, int32 IndexB);
	void HardSwap(int32 IndexA, int32 IndexB);
	void GetCaption();
	void GetParentCaption();
	void GetValue();
	void GetLevel();
	void GetExtra();
	void GetCaptionAtIndex(int32 i);
	void GetParentCaptionAtIndex(int32 idx);
	void GetValueAtIndex(int32 i);
	void GetLevelAtIndex(int32 i);
	void GetExtraAtIndex(int32 idx);
	bool GetElementAtIndex(int32 i, FGUITreeNode& Node);
	bool GetAtIndex(int32 i, FString& Caption, FString& Value, FString& ParentCaption, int32& Level, uint8& bEnabled, FString& ExtraInfo);
	TArray<int32> GetIndexList();
	TArray<int32> GetChildIndexList(int32 idx, bool bNoRecurse);
	bool ValidSelection();
	bool ValidSelectionAt(int32 idx);
	bool HasChildren(int32 ParentIndex);
	bool IsExpanded(int32 ParentIndex);
	void SetCaptionAtIndex(int32 i, FString NewCaption);
	void SetValueAtIndex(int32 i, FString NewValue);
	void SetLevelAtIndex(int32 i, int32 NewLevel);
	bool Expand(int32 idx, bool bRecursive);
	bool Collapse(int32 idx);
	void ToggleExpand(int32 idx, bool bRecursive);
	bool IsToggleClick(int32 idx);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalDblClick(UGUIComponent* Sender);
	int32 FindIndex(FString Caption, bool bExact);
	int32 FindFullIndex(FString Caption, FString Value, FString ParentCaption);
	int32 FindParentIndex(int32 ChildIndex);
	int32 FindNextAvailableRootIndex(int32 Target);
	int32 FindAvailableChildIndex(int32 ParentIndex);
	int32 FindIndexByValue(FString Value, bool bExact);
	int32 FindElement(FString Caption, FString Value, int32 Level, bool bCaseSensitive);
	int32 FindVisibleIndex(int32 idx, int32 Distance);
	int32 CalculateIndex(bool bRequireValidIndex);
	void Sort();
	int32 SetIndex(int32 NewIndex);
	void SetTopItem(int32 Item);
	bool Up();
	bool Down();
	void End();
	void PgUp();
	void PgDn();
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	bool InternalOnDragDrop(UGUIComponent* Sender);
	void ClearPendingElements();
	void GetPendingElements(bool bGuarantee);
};
