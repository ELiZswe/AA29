// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/DirectoryTreeList/DirectoryTreeList.h"

UDirectoryTreeList::UDirectoryTreeList()
{
	bSimpleFileBrowsing = true;
	//__OnDrawItem__Delegate = "DirectoryTreeList.InternalOnDrawItem";
	//__OnEndDrag__Delegate = "DirectoryTreeList.InternalOnEndDrag";
}


void UDirectoryTreeList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	CreateRoot();
	SetCurrent(root);
	*/
}
void UDirectoryTreeList::CreateRoot()
{
	/*
	if (root != None)
	{
		Return;
	}
	root = new (Self) class'StreamDirectoryNode';
	root.SetName("root");
	root.InitializeNode();
	*/
}
/*
void UDirectoryTreeList::SetCurrent(UStreamDirectoryNode* Node)
{
	local string Path;
	if (Node == None)
	{
		Node = root;
	}
	Current = Node;
	Path = Current.GetPath();
	if (Path == "")
	{
		Path = "*";
	}
	if (FileManager != None)
	{
		FileManager.ChangeDirectory(Path);
	}
}
*/
void UDirectoryTreeList::InternalOnClick(UGUIComponent* Sender)
{
	return Super::InternalOnClick(Sender);
}
void UDirectoryTreeList::InternalOnDrawItem(UCanvas* C, int32 Item, float X, float Y, float XL, float YL, bool bIsSelected, bool bIsPending)
{
	/*
	local string Text;
	local bool bIsDrop;
	Text = VisibleNodeText(Item);
	bIsDrop = Top + Item == DropIndex;
	if (bIsSelected || bIsPending && !bIsDrop)
	{
		if (SelectedStyle != None)
		{
			if (SelectedStyle.Images[MenuState] != None)
			{
				SelectedStyle.Draw(C, MenuState, X, Y, XL, YL);
			}
			else
			{
				C.SetPos(X, Y);
				C.DrawTile(Controller.DefaultPens[0], XL, YL, 0, 0, 32, 32);
			}
		}
		else
		{
			if (MenuState == 2 || MenuState == 3)
			{
				C.SetPos(X, Y);
				if (SelectedImage == None)
				{
					C.DrawTile(Controller.DefaultPens[0], XL, YL, 0, 0, 32, 32);
				}
				else
				{
					C.SetDrawColor(SelectedBKColor.R, SelectedBKColor.G, SelectedBKColor.B, SelectedBKColor.A);
					C.DrawTileStretched(SelectedImage, XL, YL);
				}
			}
		}
	}
	if (bIsPending && OutlineStyle != None)
	{
		if (OutlineStyle.Images[MenuState] != None)
		{
			if (bIsDrop)
			{
				OutlineStyle.Draw(C, MenuState, X + 1, Y + 1, XL - 2, YL - 2);
			}
			else
			{
				OutlineStyle.Draw(C, MenuState, X, Y, XL, YL);
				if (DropState == 1)
				{
					OutlineStyle.Draw(C, MenuState, Controller.MouseX - MouseOffset[0], Controller.MouseY - MouseOffset[1] + Y - ClientBounds[1], MouseOffset[2] + MouseOffset[0], ItemHeight);
				}
			}
		}
	}
	if (bIsSelected && SelectedStyle != None)
	{
		SelectedStyle.DrawText(C, MenuState, X, Y, XL, YL, 0, Text, FontScale);
	}
	else
	{
		Style.DrawText(C, MenuState, X, Y, XL, YL, 0, Text, FontScale);
	}
	*/
}
void UDirectoryTreeList::FindVisibleItemIndex(FString Path)
{
	//return Current.FindVisibleNodeIndex(Path);
}
void UDirectoryTreeList::Get(bool bFullPath)
{
	/*
	local string Path;
	local string File;
	if (IsValid())
	{
		if (bFullPath)
		{
			File = Current.NodeText(Index, true);
			Path = Current.GetPath();
			if (Path == "" || File == "." || File == "..")
			{
				Return "";
			}
			Return Path $ File;
		}
		Return Current.NodeText(Index, true);
	}
	Return "";
	*/
}
void UDirectoryTreeList::GetPendingItems(bool bGuarantee)
{
	/*
	local int i;
	local array<String> items;
	local string str;
	if (DropState == 1 && Controller.DropSource == Self || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				str = getItemAtIndex(SelectedItems[i]);
				if (str != "")
				{
					items[items.Length] = str;
				}
			}
		}
		if (items.Length == 0 && IsValid())
		{
			str = getItemAtIndex(Index);
			if (str != "")
			{
				items[0] = str;
			}
		}
	}
	Return items;
	*/
}
void UDirectoryTreeList::getItemAtIndex(int32 idx)
{
	/*
	local string Path;
	local string File;
	local StreamDirectoryNode Node;
	if (IsValidIndex(idx))
	{
		Node = VisibleNode(idx);
		File = Node.NodeText(idx, true);
		Path = Node.GetPath();
		if (Path == "" || File == "." || File == "..")
		{
			Return "";
		}
		if (Class'StreamBase'.HasExtension(File))
		{
			Return Path $ File;
		}
		else
		{
			Return Path;
		}
	}
	Return "";
	*/
}
void UDirectoryTreeList::GetCurrentNode()
{
	/*
	Return Current.GetName();
	*/
}
void UDirectoryTreeList::GetCurrentNodePath()
{
	/*
	Return Current.GetPath();
	*/
}
void UDirectoryTreeList::GetPath()
{
	/*
	Return GetPathAt(Index);
	*/
}
void UDirectoryTreeList::GetPathAt(int32 idx)
{
	/*
	local StreamDirectoryNode Node;
	if (IsValidIndex(idx))
	{
		Node = VisibleNode(idx);
		if (Node != None)
		{
			Return Node.GetPath();
		}
	}
	Return "";
	*/
}
void UDirectoryTreeList::ChDir(FString Path)
{
	/*
	local StreamDirectoryNode Node;
	if (Current.ChangeDirectory(Path, Node) || root.ChangeDirectory(Path, Node, true))
	{
		SetCurrent(Node);
		UpdateItemCount();
		SetTopItem(0);
		SetIndex(-1);
		Return True;
	}
	Return False;
	*/
}
void UDirectoryTreeList::ExpandNode(FString Path)
{
	/*
	local StreamDirectoryNode Node;
	if (Path == "")
	{
		Return False;
	}
	Node = FindNode(Path);
	if (Node != None)
	{
		Node.Toggle();
		UpdateItemCount(True);
		Return True;
	}
	Log("ExpandNode() Error: node not found '" $ Path $ "'", 'MusicPlayer');
	Return False;
	*/
}
void UDirectoryTreeList::VisibleNode(int32 VisibleItemIndex)
{
	/*
	Return Current.FindVisibleNode(VisibleItemIndex);
	*/
}
void UDirectoryTreeList::VisibleNodeText(int32 VisibleItemIndex)
{
	/*
	Return Current.NodeText(VisibleItemIndex);
	*/
}
void UDirectoryTreeList::UpdateItemCount(bool bFullUpdate)
{
	/*
	Current.UpdateCost(bFullUpdate);
	ItemCount = Current.cost();
	*/
}
/*
void UDirectoryTreeList::AddNode(UStreamDirectoryNode* Parent, FString InName, bool bIsFile)
{
	if (Parent == None)
	{
		if (Right(InName, 1) != ":" && Right(InName, 2) != ":\")
		{
			Return False;
		}
		Parent = root;
	}
	if (bIsFile)
	{
		Return Parent.AddContent(InName);
	}
	Return Parent.AddChild(InName) != None;
	
}
*/
/*
void UDirectoryTreeList::RemoveNode(UStreamDirectoryNode* Parent, UStreamDirectoryNode* Child)
{
	if (Parent == None)
	{
		Parent = root;
	}
	Return Parent.RemoveChild(Child);
}
*/
/*
void UDirectoryTreeList::RemoveFile(UStreamDirectoryNode* Parent, FString InFileName)
{
	if (Parent == None)
	{
		Parent = root;
	}
	Return Parent.RemoveContent(InFileName);
}
*/
void UDirectoryTreeList::FindNode(FString Path)
{
	/*
	Return root.FindChildByPath(Path);
	*/
}
void UDirectoryTreeList::MakeVisible(float Perc)
{
	/*
	UpdateItemCount();
	SetTopItem(ItemCount - ItemsPerPage * Perc);
	*/
}
void UDirectoryTreeList::SetTopItem(int32 Item)
{
	Super::SetTopItem(Item);
}
void UDirectoryTreeList::IsValid()
{
	/*
	UpdateItemCount();
	Return Super::IsValid();
	*/
}
void UDirectoryTreeList::IsValidIndex(int32 i)
{
	/*
	UpdateItemCount();
	Return IsValidIndex(i);
	*/
}
void UDirectoryTreeList::Clear()
{
	/*
	root.Clear(True);
	UpdateItemCount();
	Super::Clear();
	*/
}
void UDirectoryTreeList::HandleDebugExec(FString Command, FString Params)
{
	/*
	Switch(Command)
	{
			case "selected":
				Log("Selected item:" $ Get(), 'MusicPlayer');
				Return True;
			case "selectedpath":
				Log("Selected path:" $ GetPath(), 'MusicPlayer');
				Return True;
			case "visiblenode":
				Log("Visible Node" @ Params $ " '" $ VisibleNodeText(Params) $ "'", 'MusicPlayer');
				Return True;
			default:
				Return Current.HandleDebugExec(Command, Params);
	}
	*/
}
void UDirectoryTreeList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	if (bAccepted && Accepting != None)
	{
		bRepeatClick = False;
	}
	if (Accepting == None)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}