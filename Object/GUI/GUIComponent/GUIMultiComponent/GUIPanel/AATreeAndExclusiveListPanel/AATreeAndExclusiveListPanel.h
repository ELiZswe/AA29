// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AATreeAndExclusiveListPanel.generated.h"

class UGUIGFXButton;
class UGUIButton;
class UAAGUIExclusiveMultiOptionList;
class UGUITreeList;
class UGUITreeListBox;
class UGUIMenuOption;
class UGUITreeNode;

UCLASS()
class AA29_API UAATreeAndExclusiveListPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAATreeAndExclusiveListPanel();



	UPROPERTY()							bool							bOverrideMenuComponent;		//var bool bOverrideMenuComponent;
	UPROPERTY(EditAnywhere)				UGUIGFXButton*					ScrollDown;					//var() XInterface.GUIGFXButton ScrollDown;
	UPROPERTY(EditAnywhere)				UGUIGFXButton*					ScrollUp;					//var() XInterface.GUIGFXButton ScrollUp;
	UPROPERTY(EditAnywhere)				UGUIButton*						ExclusiveListHeader;		//var() XInterface.GUIButton ExclusiveListHeader;
	UPROPERTY(EditAnywhere)				UGUIButton*						TreeHeader;					//var() XInterface.GUIButton TreeHeader;
	UPROPERTY(EditAnywhere)				UAAGUIExclusiveMultiOptionList*	ExclusiveList;				//var() AAGUIExclusiveMultiOptionList ExclusiveList;
	UPROPERTY()							UGUITreeList*					TreeList;					//var XInterface.GUITreeList TreeList;
	UPROPERTY(EditAnywhere)				UGUITreeListBox*				TreeBox;					//var() XInterface.GUITreeListBox TreeBox;

	int32 NumItemsInTree();
	bool GetItemForTreeAtIndex(UGUITreeNode*& TreeNode, int32 Index);
	int32 NumItemsInExclusiveList(int32 TreeIndex);
	bool GetItemForExclusiveList(FString& Label, int32 TreeIndex, int32 ChoiceIndex);
	bool IsExclusiveListChoice(int32 TreeIndex, int32 ChoiceIndex);
	void InternalOnExclusiveItemSelection(int32 TreeIndex, int32 ItemIndex);
	void InternalOnExclusiveItemDeselection(int32 TreeIndex, int32 ItemIndex);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetVisibility(bool bShow);
	void SetTreeHeader(FString Header);
	void SetExclusiveListHeader(FString Header);
	void RebuildExclusiveList();
	void InitTree();
	int32 TreeIndexToDataIndex(int32 TreeIndex);
	void InternalOnChange(UGUIComponent* Sender);
	void InternalOnItemSelection(UGUIMenuOption* MenuOption);
	void InternalOnItemDeselection(UGUIMenuOption* MenuOption);
	bool InternalOnScrollUp(UGUIComponent* Sender);
	bool InternalOnScrollDown(UGUIComponent* Sender);
	void InternalOnCreateExclusiveListComponent(UGUIComponent* NewComponent, UGUIComponent* Sender);
};
