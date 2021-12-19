// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AATreeAndExclusiveListPanel/AATreeAndExclusiveListPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/AAGUIExclusiveMultiOptionList/AAGUIExclusiveMultiOptionList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUITreeListBox/GUITreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"

UAATreeAndExclusiveListPanel::UAATreeAndExclusiveListPanel()
{
	UAAGUIExclusiveMultiOptionList* Exclusive = NewObject<UAAGUIExclusiveMultiOptionList>(UAAGUIExclusiveMultiOptionList::StaticClass());
	//Exclusive->OnItemSelection = AATreeAndExclusiveListPanel.InternalOnItemSelection;
	//Exclusive->OnItemDeselection = AATreeAndExclusiveListPanel.InternalOnItemDeselection;
	//Exclusive->OnCreateComponent=AATreeAndExclusiveListPanel.InternalOnCreateExclusiveListComponent;
	//Exclusive->OnAdjustTop = Exclusive.InternalOnAdjustTop;
	Exclusive->StyleName = "TreeAndExclusiveList";
	Exclusive->WinTop = 0.105;
	Exclusive->WinLeft = 0.5;
	Exclusive->WinWidth = 0.5;
	Exclusive->WinHeight = 0.86;
	Exclusive->bBoundToParent = true;
	Exclusive->bScaleToParent = true;
	//Exclusive->OnClick=Exclusive.InternalOnClick;
	//Exclusive->OnRightClick=Exclusive.InternalOnRightClick;
	//Exclusive->OnMousePressed=Exclusive.InternalOnMousePressed;
	//Exclusive->OnMouseRelease=Exclusive.InternalOnMouseRelease;
	//Exclusive->OnKeyEvent=Exclusive.InternalOnKeyEvent;
	//Exclusive->OnBeginDrag=Exclusive.InternalOnBeginDrag;
	//Exclusive->OnEndDrag=Exclusive.InternalOnEndDrag;
	//Exclusive->OnDragDrop=Exclusive.InternalOnDragDrop;
	//Exclusive->OnDragEnter=Exclusive.InternalOnDragEnter;
	//Exclusive->OnDragLeave=Exclusive.InternalOnDragLeave;
	//Exclusive->OnDragOver=Exclusive.InternalOnDragOver;
	UGUIButton* TreeHeaderButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TreeHeaderButton->StyleName = "AAGUITreeListCategory";
	TreeHeaderButton->WinWidth = 0.5;
	TreeHeaderButton->WinHeight = 0.07;
	TreeHeaderButton->bBoundToParent = true;
	//TreeHeaderButton->OnKeyEvent=TreeHeaderButton.InternalOnKeyEvent;
	UGUIButton* ExclusiveListHeaderButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ExclusiveListHeaderButton->StyleName = "AAGUITreeListCategory";
	ExclusiveListHeaderButton->WinLeft = 0.5;
	ExclusiveListHeaderButton->WinWidth = 0.5;
	ExclusiveListHeaderButton->WinHeight = 0.07;
	ExclusiveListHeaderButton->bBoundToParent = true;
	//ExclusiveListHeaderButton->OnKeyEvent=ExclusiveListHeaderButton.InternalOnKeyEvent;
	UGUITreeListBox* tree = NewObject<UGUITreeListBox>(UGUITreeListBox::StaticClass());
	tree->DefaultListClass = "AGP_Interface.AAGuiTreeList";
	//tree->OnCreateComponent=tree.InternalOnCreateComponent;
	tree->StyleName = "TreeAndExclusiveList";
	tree->WinTop = 0.07;
	tree->WinWidth = 0.5;
	tree->WinHeight = 0.93;
	tree->bBoundToParent = true;
	tree->bScaleToParent = true;
	//tree->OnChange=AATreeAndExclusiveListPanel.InternalOnChange;
	UGUIGFXButton* ScrollUpButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	ScrollUpButton->Graphic = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_scroll_u_Mat.t_ui_mbs_scroll_u_Mat'"), NULL, LOAD_None, NULL);
	ScrollUpButton->Position = EIconPosition::ICP_Scaled;
	ScrollUpButton->WinTop = 0.07;
	ScrollUpButton->WinLeft = 0.5;
	ScrollUpButton->WinWidth = 0.5;
	ScrollUpButton->WinHeight = 0.035;
	ScrollUpButton->bRepeatClick = true;
	//ScrollUpButton->OnClick=AATreeAndExclusiveListPanel.InternalOnScrollUp;
	//ScrollUpButton->OnKeyEvent=ScrollUpButton.InternalOnKeyEvent;
	UGUIGFXButton* ScrollDownButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	ScrollDownButton->Graphic = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MBS/t_ui_mbs_scroll_dow_Mat.t_ui_mbs_scroll_dow_Mat'"), NULL, LOAD_None, NULL);
	ScrollDownButton->Position = EIconPosition::ICP_Scaled;
	ScrollDownButton->WinTop = 0.965;
	ScrollDownButton->WinLeft = 0.5;
	ScrollDownButton->WinWidth = 0.5;
	ScrollDownButton->WinHeight = 0.035;
	ScrollDownButton->bRepeatClick = true;
	//ScrollDownButton->OnClick=AATreeAndExclusiveListPanel.InternalOnScrollDown;
	//ScrollDownButton->OnKeyEvent=ScrollDownButton.InternalOnKeyEvent;

	TreeBox = tree;
	ExclusiveList = Exclusive;
	TreeHeader = TreeHeaderButton;
	ExclusiveListHeader = ExclusiveListHeaderButton;
	ScrollUp = ScrollUpButton;
	ScrollDown = ScrollDownButton;
}

int32 UAATreeAndExclusiveListPanel::NumItemsInTree()
{
	return 0;
}

bool UAATreeAndExclusiveListPanel::GetItemForTreeAtIndex(UGUITreeNode*& TreeNode, int32 Index)
{
	return false;
}

int32 UAATreeAndExclusiveListPanel::NumItemsInExclusiveList(int32 TreeIndex)
{
	return 0;
}

bool UAATreeAndExclusiveListPanel::GetItemForExclusiveList(FString& Label, int32 TreeIndex, int32 ChoiceIndex)
{
	return false;
}

bool UAATreeAndExclusiveListPanel::IsExclusiveListChoice(int32 TreeIndex, int32 ChoiceIndex)
{
	return false;
}

void UAATreeAndExclusiveListPanel::InternalOnExclusiveItemSelection(int32 TreeIndex, int32 ItemIndex)
{
}

void UAATreeAndExclusiveListPanel::InternalOnExclusiveItemDeselection(int32 TreeIndex, int32 ItemIndex)
{
}

void UAATreeAndExclusiveListPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	ScrollUp.DisableMe();
	ScrollDown.DisableMe();
	*/
}

void UAATreeAndExclusiveListPanel::SetVisibility(bool bShow)
{
	/*
	SetVisibility(bShow);
	if (bShow)
	{
		TreeList.Clear();
		InitTree();
	}
	*/
}

void UAATreeAndExclusiveListPanel::SetTreeHeader(FString Header)
{
	//TreeHeader.Caption = Header;
}

void UAATreeAndExclusiveListPanel::SetExclusiveListHeader(FString Header)
{
	//ExclusiveListHeader.Caption = Header;
}

void UAATreeAndExclusiveListPanel::RebuildExclusiveList()
{
	//InternalOnChange(TreeBox);
}

void UAATreeAndExclusiveListPanel::InitTree()
{
	/*
	local int32 Index;
	local GUI.GUITreeNode TreeNode;
	local int32 InsertIndex;
	local int32 ParentIndex;
	local array<int> ChildIndexes;
	local int32 ChildIndex;
	TreeList = TreeBox.List;
	for (Index = 0; Index < NumItemsInTree(); Index++)
	{
		if (GetItemForTreeAtIndex(TreeNode, Index))
		{
			InsertIndex = TreeList.AddElement(TreeNode);
			ParentIndex = TreeList.FindIndex(TreeNode.ParentCaption);
			ChildIndexes = TreeList.GetChildIndexList(ParentIndex);
			ChildIndex = 0;
			if (ChildIndex < ChildIndexes.Length - 1)
			{
				TreeList.Swap(ChildIndexes[ChildIndex], ChildIndexes[ChildIndex + 1]);
				++ChildIndex;
			}
			TreeList.Expand(InsertIndex);
			TreeList.SetIndex(1);
		}
	}
	*/
}

int32 UAATreeAndExclusiveListPanel::TreeIndexToDataIndex(int32 TreeIndex)
{
	/*
	local array<int> ItemIndexList;
	local int32 DataIndex;
	ItemIndexList = TreeList.GetIndexList();
	if (DataIndex < ItemIndexList.Length)
	{
		if (TreeIndex == ItemIndexList[DataIndex])
		{
			return DataIndex;
		}
		else
		{
			if (TreeIndex < ItemIndexList[DataIndex])
			{
				return -1;
			}
		}
		++DataIndex;
	}
	*/
	return -1;
}

void UAATreeAndExclusiveListPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local int32 Index;
	local string Label;
	local int32 DataIndex;
	local UGUIMenuOption* NewItem;
	local int32 ItemsInExclusiveList;
	local bool NonDefaultChoice;
	Switch(Sender)
	{
			case TreeBox:
				if (TreeList.ValidSelection())
				{
					ExclusiveList.Clear();
					DataIndex = TreeIndexToDataIndex(TreeList.Index);
					ItemsInExclusiveList = NumItemsInExclusiveList(DataIndex);
					Index = 0;
					if (Index < ItemsInExclusiveList)
					{
						if (GetItemForExclusiveList(Label, DataIndex, Index))
						{
							if (Left(Label, 4) == "--- ")
							{
								Log("Creating non-checkbox menu item for separator text: " $ Label);
								bOverrideMenuComponent = True;
								Label = Mid(Label, 4, Len(Label) - 8);
								NewItem = ExclusiveList.addItem("AGP_Interface.moMultilineCheckbox", None, Label);
								bOverrideMenuComponent = False;
								break;
							}
							NewItem = ExclusiveList.addItem("AGP_Interface.moMultilineCheckbox", None, Label);
							if (IsExclusiveListChoice(DataIndex, Index))
							{
								NonDefaultChoice = True;
								moCheckBox(NewItem).Checked(True);
							}
						}
					}
					++Index;
				}
				if (Left(Label, 4) == "--- ")
				{
					if (!NonDefaultChoice && ExclusiveList.Elements.Length > 0)
					{
						moCheckBox(ExclusiveList.GetItem(0)).Checked(True);
					}
				}
				if (ExclusiveList.ItemsPerPage > 0 && ExclusiveList.ItemCount > ExclusiveList.ItemsPerPage)
				{
					ScrollUp.EnableMe();
					ScrollDown.EnableMe();
				}
				else
				{
					ScrollUp.DisableMe();
					ScrollDown.DisableMe();
				}
	}
		else
		{
		ExclusiveList.Clear();
		}
		GOTO JL02A3;
		default:
		JL02A3:
			Return;
	*/
}

void UAATreeAndExclusiveListPanel::InternalOnItemSelection(UGUIMenuOption* MenuOption)
{
	/*
	local int32 DataIndex;
	local int32 ItemIndex;
	DataIndex = TreeIndexToDataIndex(TreeList.Index);
	ItemIndex = ExclusiveList.FindComp(MenuOption);
	InternalOnExclusiveItemSelection(DataIndex, ItemIndex);
	*/
}

void UAATreeAndExclusiveListPanel::InternalOnItemDeselection(UGUIMenuOption* MenuOption)
{
	/*
	local int32 DataIndex;
	local int32 ItemIndex;
	DataIndex = TreeIndexToDataIndex(TreeList.Index);
	ItemIndex = ExclusiveList.FindComp(MenuOption);
	InternalOnExclusiveItemDeselection(DataIndex, ItemIndex);
	*/
}

bool UAATreeAndExclusiveListPanel::InternalOnScrollUp(UGUIComponent* Sender)
{
	//ExclusiveList.SetTopItem(ExclusiveList.Top - 1);
	return true;
}

bool UAATreeAndExclusiveListPanel::InternalOnScrollDown(UGUIComponent* Sender)
{
	//ExclusiveList.SetTopItem(ExclusiveList.Top + 1);
	return true;
}

void UAATreeAndExclusiveListPanel::InternalOnCreateExclusiveListComponent(UGUIComponent* NewComponent, UGUIComponent* Sender)
{
	/*
	local UGUIMenuOption* NewComp;
	NewComp = GUIMenuOption(NewComponent);
	if (None == NewComp)
	{
		Return;
	}
	NewComp.bFlipped = True;
	NewComp.ComponentJustification = 0;
	NewComp.LabelJustification = 2;
	NewComp.bAutoSizeCaption = False;
	NewComp.FontScale = 0;
	if (!bOverrideMenuComponent)
	{
		NewComp.ComponentClassName = "AGP_Interface.AAGUIExclusiveMultiOptionListItem";
		NewComp.StyleName = "AAGUITreeListItem";
	}
	else
	{
		NewComp.ComponentClassName = "AGP_Interface.AAGUIExclusiveMultiOptionListItemSeparator";
		NewComp.StyleName = "AAGUITreeSeparatorListItem";
	}
	*/
}