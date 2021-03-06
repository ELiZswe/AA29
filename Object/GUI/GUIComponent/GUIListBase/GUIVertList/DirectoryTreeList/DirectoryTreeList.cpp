// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/DirectoryTreeList/DirectoryTreeList.h"
#include "AA29/Object/StreamBase/StreamDirectoryNode/StreamDirectoryNode.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "Engine/Canvas.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

UDirectoryTreeList::UDirectoryTreeList()
{
	bSimpleFileBrowsing = true;
	//__OnDrawItem__Delegate = "DirectoryTreeList.InternalOnDrawItem";
	//__OnEndDrag__Delegate = "DirectoryTreeList.InternalOnEndDrag";
}

void UDirectoryTreeList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	CreateRoot();
	SetCurrent(root);
}

void UDirectoryTreeList::CreateRoot()
{
	if (root != nullptr)
	{
		return;
	}
	//root = new (this) UStreamDirectoryNode::StaticClass();
	root->SetName("root");
	root->InitializeNode();
}

void UDirectoryTreeList::SetCurrent(UStreamDirectoryNode* Node)
{
	FString Path="";
	if (Node == nullptr)
	{
		Node = root;
	}
	Current = Node;
	
	Path = Current->GetPath();
	if (Path == "")
	{
		Path = "*";
	}
	if (FileManager != nullptr)
	{
		FileManager->ChangeDirectory(Path);
	}
}

bool UDirectoryTreeList::InternalOnClick(UGUIComponent* Sender)
{
	return Super::InternalOnClick(Sender);
}

void UDirectoryTreeList::InternalOnDrawItem(UCanvas* C, int32 Item, float X, float Y, float XL, float YL, bool bIsSelected, bool bIsPending)
{
	FString Text = "";
	bool bIsDrop = false;
	Text = VisibleNodeText(Item);
	bIsDrop = Top + Item == DropIndex;
	if (bIsSelected || bIsPending && !bIsDrop)
	{
		if (SelectedStyle != nullptr)
		{
			if (SelectedStyle->Images[(int32)MenuState] != nullptr)
			{
				SelectedStyle->Draw(C, MenuState, X, Y, XL, YL);
			}
			else
			{
				//C->SetPos(X, Y);
				//C->DrawTile(Controller->DefaultPens[0], XL, YL, 0, 0, 32, 32);
			}
		}
		else
		{
			if (MenuState == EMenuState::MSAT_Focused || MenuState == EMenuState::MSAT_Pressed)
			{
				//C->SetPos(X, Y);
				if (SelectedImage == nullptr)
				{
					//C->DrawTile(Controller->DefaultPens[0], XL, YL, 0, 0, 32, 32);
				}
				else
				{
					//C->SetDrawColor(SelectedBKColor.R, SelectedBKColor.G, SelectedBKColor.B, SelectedBKColor.A);
					//C->DrawTileStretched(SelectedImage, XL, YL);
				}
			}
		}
	}
	if (bIsPending && OutlineStyle != nullptr)
	{
		if (OutlineStyle->Images[(int32)MenuState] != nullptr)
		{
			if (bIsDrop)
			{
				OutlineStyle->Draw(C, MenuState, X + 1, Y + 1, XL - 2, YL - 2);
			}
			else
			{
				OutlineStyle->Draw(C, MenuState, X, Y, XL, YL);
				if (DropState == EDropState::DRP_Source)
				{
					OutlineStyle->Draw(C, MenuState, Controller->MouseX - MouseOffset[0], Controller->MouseY - MouseOffset[1] + Y - ClientBounds[1], MouseOffset[2] + MouseOffset[0], ItemHeight);
				}
			}
		}
	}
	if (bIsSelected && SelectedStyle != nullptr)
	{
		SelectedStyle->DrawText(C, MenuState, X, Y, XL, YL, ETextAlign::TXTA_Left, Text, FontScale);
	}
	else
	{
		Style->DrawText(C, MenuState, X, Y, XL, YL, ETextAlign::TXTA_Left, Text, FontScale);
	}
}

int32 UDirectoryTreeList::FindVisibleItemIndex(FString Path)
{
	return Current->FindVisibleNodeIndex(Path);
}

FString UDirectoryTreeList::Get(bool bFullPath)
{
	FString Path = "";
	FString File = "";
	if (IsValid())
	{
		if (bFullPath)
		{
			File = Current->NodeText(Index, true);
			Path = Current->GetPath();
			if (Path == "" || File == "." || File == "..")
			{
				return "";
			}
			return Path + File;
		}
		return Current->NodeText(Index, true);
	}
	return "";
}

TArray<FString> UDirectoryTreeList::GetPendingItems(bool bGuarantee)
{
	int32 i = 0;
	TArray<FString> items = {};
	FString str = "";
	if (DropState == EDropState::DRP_Source && Controller->DropSource == this || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				str = getItemAtIndex(SelectedItems[i]);
				if (str != "")
				{
					items[items.Num()] = str;
				}
			}
		}
		if (items.Num() == 0 && IsValid())
		{
			str = getItemAtIndex(Index);
			if (str != "")
			{
				items[0] = str;
			}
		}
	}
	return items;
}

FString UDirectoryTreeList::getItemAtIndex(int32 idx)
{
	FString Path = "";
	FString File = "";
	UStreamDirectoryNode* Node = nullptr;
	if (IsValidIndex(idx))
	{
		Node = VisibleNode(idx);
		File = Node->NodeText(idx, true);
		Path = Node->GetPath();
		if (Path == "" || File == "." || File == "..")
		{
			return "";
		}
		/*
		if (UStreamBase::StaticClass().HasExtension(File))
		{
			return Path + File;
		}
		else
		{
			return Path;
		}
		*/
	}
	return "";
}

FString UDirectoryTreeList::GetCurrentNode()
{
	return Current->GetName();
}

FString UDirectoryTreeList::GetCurrentNodePath()
{
	return Current->GetPath();
}

FString UDirectoryTreeList::GetPath()
{
	return GetPathAt(Index);
}

FString UDirectoryTreeList::GetPathAt(int32 idx)
{
	UStreamDirectoryNode* Node = nullptr;
	if (IsValidIndex(idx))
	{
		Node = VisibleNode(idx);
		if (Node != nullptr)
		{
			return Node->GetPath();
		}
	}
	return "";
}

bool UDirectoryTreeList::ChDir(FString Path)
{
	UStreamDirectoryNode* Node = nullptr;
	if (Current->ChangeDirectory(Path, Node,false) || root->ChangeDirectory(Path, Node, true))
	{
		SetCurrent(Node);
		UpdateItemCount(false);
		SetTopItem(0);
		SetIndex(-1);
		return true;
	}
	return false;
}

bool UDirectoryTreeList::ExpandNode(FString Path)
{
	UStreamDirectoryNode* Node = nullptr;
	if (Path == "")
	{
		return false;
	}
	Node = FindNode(Path);
	if (Node != nullptr)
	{
		Node->Toggle();
		UpdateItemCount(true);
		return true;
	}
	//Log("ExpandNode() Error: node not found '" + Path + "'", 'MusicPlayer');
	return false;
}

UStreamDirectoryNode* UDirectoryTreeList::VisibleNode(int32 VisibleItemIndex)
{
	return Current->FindVisibleNode(VisibleItemIndex);
}

FString UDirectoryTreeList::VisibleNodeText(int32 VisibleItemIndex)
{
	return Current->NodeText(VisibleItemIndex,false);
}

void UDirectoryTreeList::UpdateItemCount(bool bFullUpdate)
{
	Current->UpdateCost(bFullUpdate);
	ItemCount = Current->cost();
}

bool UDirectoryTreeList::AddNode(UStreamDirectoryNode* Parent, FString InName, bool bIsFile)
{
	if (Parent == nullptr)
	{
		if (InName.Right(1) != ":" && InName.Right(2) != ":\\")
		{
			return false;
		}
		Parent = root;
	}
	if (bIsFile)
	{
		return Parent->AddContent(InName);
	}
	return Parent->AddChild(InName) != nullptr;
}

bool UDirectoryTreeList::RemoveNode(UStreamDirectoryNode* Parent, UStreamDirectoryNode* Child)
{
	if (Parent == nullptr)
	{
		Parent = root;
	}
	return Parent->RemoveChild(Child);
}

bool UDirectoryTreeList::RemoveFile(UStreamDirectoryNode* Parent, FString InFileName)
{
	if (Parent == nullptr)
	{
		Parent = root;
	}
	return Parent->RemoveContent(InFileName);
}

UStreamDirectoryNode* UDirectoryTreeList::FindNode(FString Path)
{
	return root->FindChildByPath(Path);
}

void UDirectoryTreeList::MakeVisible(float Perc)
{
	UpdateItemCount(false);
	SetTopItem(ItemCount - ItemsPerPage * Perc);
}

void UDirectoryTreeList::SetTopItem(int32 Item)
{
	Super::SetTopItem(Item);
}

bool UDirectoryTreeList::IsValid()
{
	UpdateItemCount(false);
	return Super::IsValid();
}

bool UDirectoryTreeList::IsValidIndex(int32 i)
{
	UpdateItemCount(false);
	return Super::IsValidIndex(i);
}

void UDirectoryTreeList::Clear()
{
	root->Clear(true);
	UpdateItemCount(false);
	Super::Clear();
}

bool UDirectoryTreeList::HandleDebugExec(FString Command, FString Params)
{
	if (Command == "selected")
	{
		//Log("Selected item:" + Get(), 'MusicPlayer');
		return true;
	}
	if (Command == "selectedpath")
	{
		//Log("Selected path:" + GetPath(), 'MusicPlayer');
		return true;
	}
	if (Command == "visiblenode")
	{
		//Log("Visible Node" @ Params + " '" + VisibleNodeText(Params) + "'", 'MusicPlayer');
		return true;
	}
	return Current->HandleDebugExec(Command, Params);
}

void UDirectoryTreeList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	if (bAccepted && Accepting != nullptr)
	{
		bRepeatClick = false;
	}
	if (Accepting == nullptr)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}
