// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamDirectoryNode/StreamDirectoryNode.h"

UStreamDirectoryNode::UStreamDirectoryNode()
{
	NodeRenderCost = 1;
}


void UStreamDirectoryNode::InitializeNode()
{
	/*
	if (Initialized())
	{
		Return;
	}
	Clear();
	bInitialized = true;
	if (Parent == None || MyPath == "" || MyPath == "..")
	{
		Return;
	}
	if (Outer.bSimpleFileBrowsing)
	{
		AddChild("..").InitializeNode();
	}
	RefreshNodeContents();
	*/
}
void UStreamDirectoryNode::RefreshNodeContents()
{
	/*
	local int i;
	local array<String> Directories;
	local array<String> Files;
	if (Outer.FileManager == None)
	{
		Log("Cannot refresh node '" $ MyPath $ "' contents - File Manager not set.", 'MusicPlayer');
		Return;
	}
	if (HasChildren())
	{
		for (i = Children.Length - 1; i >= 0; i--)
		{
			if (Children[i].GetPath() != "..")
			{
				Children.remove(i, 1);
			}
		}
	}
	Contents.remove(0, Contents.Length);
	Outer.FileManager.GetDirectoryContents(Directories, MyPath, 1);
	for (i = 0; i < Directories.Length; i++)
	{
		AddChild(Directories[i]);
	}
	Outer.FileManager.GetDirectoryContents(Files, MyPath, 4);
	Outer.FileManager.GetDirectoryContents(Files, MyPath, 5);
	for (i = 0; i < Files.Length; i++)
	{
		AddContent(Files[i]);
	}
	UpdateCost();
	*/
}
void UStreamDirectoryNode::Clear(bool bPropagate)
{
	/*
	local int i;
	if (HasChildren() && bPropagate)
	{
		for (i = 0; i < Children.Length; i++)
		{
			Children[i].Clear(bPropagate);
		}
	}
	Children.remove(0, Children.Length);
	Contents.remove(0, Contents.Length);
	UpdateCost();
	bInitialized = False;
	*/
}
FString UStreamDirectoryNode::GetIndent()
{
	FString Indent="";
	/*
	if (Outer.bSimpleFileBrowsing)
	{
		Return "";
	}
	if (Parent != None)
	{
		Indent = Parent.GetIndent() $ " ";
	}
	*/
	return Indent;
}
void UStreamDirectoryNode::GetNodePrefix(bool bNoPrefix)
{
	/*
	if (bNoPrefix)
	{
		Return "";
	}
	if (isEmpty())
	{
		Return GetIndent() $ ". ";
	}
	if (!IsOpen())
	{
		Return GetIndent() $ "+ ";
	}
	Return GetIndent() $ "- ";
	*/
}
void UStreamDirectoryNode::NodeText(int32 VisibleIndex, bool bNoPrefix)
{
	/*
	local StreamDirectoryNode Node;
	if (!IsOpen())
	{
		Return GetNodePrefix(bNoPrefix) $ DirectoryName;
	}
	Node = FindVisibleNode(VisibleIndex);
	if (Node == Self)
	{
		if (VisibleIndex >= 0 && VisibleIndex < Contents.Length)
		{
			Return Contents[VisibleIndex];
		}
		Return GetNodePrefix(bNoPrefix) $ DirectoryName;
	}
	Return Node.NodeText(VisibleIndex, bNoPrefix);
	*/
}
void UStreamDirectoryNode::FindVisibleNode(int32 &idx)
{
	/*
	local int Count;
	local int i;
	if (!IsOpen())
	{
		Return Self;
	}
	InitializeNode();
	if (idx > 0)
	{
		Count = Children[0].cost();
		if (HasChildren())
		{
			if (Count <= idx && ++i < Children.Length)
			{
				Count += Children[i].cost();
			}
		}
		if (i == Children.Length || !HasChildren())
		{
			idx -= Count;
			Return Self;
		}
		idx = Count - idx;
	}
	Return Children[i].FindVisibleNode(idx);
	*/
}
int32 UStreamDirectoryNode::FindVisibleNodeIndex(FString Path)
{
	int32 VisibleIndex = 0;
	/*
	local int i;
	
	local string MyComponent;
	if (Path == "")
	{
		Return 1;
	}
	InitializeNode();
	MyComponent = StripPathComponent(Path);
	if (MyComponent == "")
	{
		MyComponent = Path;
	}
	VisibleIndex = 1;
	for (i = 0; i < Children.Length; i++)
	{
		if (CompareNames(MyComponent, Children[i].GetName()))
		{
			Return VisibleIndex + Children[i].FindVisibleNodeIndex(Path);
		}
		VisibleIndex += Children[i].cost();
	}
	for (i = 0; i < Contents.Length; i++)
	{
		if (CompareNames(MyComponent, Contents[i]))
		{
		}
		VisibleIndex++;
	}
	*/
	return VisibleIndex;
}
int32 UStreamDirectoryNode::cost()
{
	return NodeRenderCost + ChildRenderCost;
}
void UStreamDirectoryNode::UpdateCost(bool bFullUpdate)
{
	/*
	local int i;
	NodeRenderCost = 0;
	ChildRenderCost = 0;
	if (!IsOpen())
	{
		NodeRenderCost = 1;
	}
	else
	{
		if (!Outer.bSimpleFileBrowsing)
		{
			NodeRenderCost = 1;
		}
		for (i = 0; i < Children.Length; i++)
		{
			if (bFullUpdate)
			{
				Children[i].UpdateCost(bFullUpdate);
			}
			ChildRenderCost += Children[i].cost();
		}
		NodeRenderCost += Contents.Length;
	}
	*/
}
void UStreamDirectoryNode::Toggle()
{
	if (IsOpen())
	{
		Collapse(false);
	}
	else
	{
		Expand(false);
	}
}
void UStreamDirectoryNode::Expand(bool bFullUpdate)
{
	InitializeNode();
	bExpanded = true;
	UpdateCost(bFullUpdate);
}
void UStreamDirectoryNode::Collapse(bool bFullUpdate)
{
	InitializeNode();
	bExpanded = false;
	UpdateCost(bFullUpdate);
}
bool UStreamDirectoryNode::ChangeDirectory(FString Path,UStreamDirectoryNode* &Node, bool bRefreshContents)
{
	/*
	local int i;
	local string MyComponent;
	InitializeNode();
	if (Path == "" || Path == ".")
	{
		if (bRefreshContents && Initialized())
		{
			RefreshNodeContents();
		}
		if (isEmpty())
		{
			Node = None;
			Return False;
		}
		Expand();
		Node = Self;
		Return True;
	}
	if (Path == "..")
	{
		if (Parent == None)
		{
			Expand();
			Node = Self;
			Return True;
		}
		Collapse();
		Return Parent.ChangeDirectory("", Node, bRefreshContents);
	}
	MyComponent = StripPathComponent(Path);
	if (MyComponent == "")
	{
		MyComponent = Path;
		Path = "";
	}
	i = FindChildIndex(MyComponent);
	if (Valid(i))
	{
		if (Children[i].ChangeDirectory(Path, Node, bRefreshContents))
		{
			Collapse();
			Return True;
		}
	}
	*/
	Node = nullptr;
	return false;
}
bool UStreamDirectoryNode::ExpandPath(FString Path)
{
	/*
	local int i;
	local int idx;
	local string S;
	InitializeNode();
	if (Path == "")
	{
		Expand();
		Return True;
	}
	S = StripPathComponent(Path);
	if (S == "")
	{
		S = Path;
	}
	if (S != "")
	{
		idx = FindChildIndex(S);
		if (Valid(idx))
		{
			for (i = 0; i < Children.Length; i++)
			{
				if (Children[i] != Children[idx])
				{
					Children[i].Collapse();
				}
			}
			if (Path != "")
			{
				Children[idx].ExpandPath(Path);
			}
		}
		Expand();
		Return True;
	}
	*/
	return false;
}
UStreamDirectoryNode* UStreamDirectoryNode::AddChild(FString ChildName)
{
	UStreamDirectoryNode* Child=nullptr;
	/*
	local int i;
	local string S;
	
	if (ChildName == "")
	{
		Return None;
	}
	for (InitializeNode(); i < Children.Length; i++)
	{
		S = Children[i].GetName();
		if (CompareNames(S, ChildName))
		{
			Return Children[i];
		}
		if (ChildName < S)
		{
		}
	}
	Child = CreateChild(ChildName);
	if (Child == None)
	{
		Log(GetName() @ "failed to successfully create child '" $ ChildName $ "'", 'MusicPlayer');
		Return None;
	}
	Children.insert(i, 1);
	Children[i] = Child;
	UpdateCost();
	*/
	return Child;
}
bool UStreamDirectoryNode::AddContent(FString ContentName)
{
	/*
	local int i;
	local string S;
	if (ContentName == "")
	{
		Return False;
	}
	InitializeNode();
	S = StripPathComponent(ContentName);
	if (S != "")
	{
		i = FindChildIndex(S);
		if (Valid(i))
		{
			Return Children[i].AddContent(ContentName);
		}
		Return False;
	}
	i = FindFileIndex(ContentName);
	if (i == -1)
	{
		Contents[Contents.Length] = ContentName;
	}
	*/
	return true;
}
bool UStreamDirectoryNode::RemoveChild(UStreamDirectoryNode* Child)
{
	int i=0;
	if (Child == nullptr)
	{
		return false;
	}
	InitializeNode();

	//i = FindChildIndex(Child.GetName());

	return RemoveChildAt(i);
}
bool UStreamDirectoryNode::RemoveChildAt(int32 i)
{
	/*
	if (Valid(i))
	{
		Children.remove(i, 1);
		UpdateCost(True);
		Return True;
	}
	*/
	return false;
}
void UStreamDirectoryNode::RemoveContent(FString Path)
{
	/*
	local string S;
	local int i;
	InitializeNode();
	S = StripPathComponent(Path);
	if (S != "")
	{
		i = FindChildIndex(S);
		if (Valid(i))
		{
			Return Children[i].RemoveContent(Path);
		}
		Return False;
	}
	i = FindFileIndex(Path);
	Return RemoveContentAt(i);
	*/
}
bool UStreamDirectoryNode::RemoveContentAt(int32 i)
{
	/*
	if (ValidFile(i))
	{
		Contents.remove(i, 1);
		UpdateCost(True);
		Return True;
	}
	*/
	return false;
}
void UStreamDirectoryNode::FindFileIndex(FString Filename)
{
	/*
	local int i;
	if (Filename == "")
	{
		Return - 1;
	}
	InitializeNode();
	for (i = 0; i < Contents.Length; i++)
	{
		if (CompareNames(Contents[i], Filename))
		{
			Return i;
		}
	}
	Return - 1;
	*/
}
bool UStreamDirectoryNode::SetName(FString InName)
{
	if (InName == "")
	{
		return false;
	}
	DirectoryName = InName;
	return true;
}
bool UStreamDirectoryNode::SetParent(UStreamDirectoryNode* InParent)
{
	if (InParent == nullptr || Parent != nullptr)
	{
		return false;
	}
	Parent = InParent;
	return true;
}
bool UStreamDirectoryNode::SetPath(FString InPath)
{
	/*
	if (MyPath != "")
	{
		Return False;
	}
	if (DirectoryName == "..")
	{
		MyPath = DirectoryName;
		Return True;
	}
	MyPath = InPath $ DirectoryName $ GetPathSeparator();
	*/
	return true;
}
bool UStreamDirectoryNode::Initialized()
{
	return bInitialized;
}
bool UStreamDirectoryNode::isEmpty()
{
	//return Initialized() && !HasChildren() && Contents.Length == 0;
	return false;    //FAKE   /ELiZ
}
bool UStreamDirectoryNode::IsOpen()
{
	return bExpanded;
}
FString UStreamDirectoryNode::GetName()
{
	return DirectoryName;
}
FString UStreamDirectoryNode::GetPath()
{
	return MyPath;
}
void UStreamDirectoryNode::FindChildByPath(FString &Path)
{
	/*
	local string ChildName;
	local int i;
	InitializeNode();
	if (Path == "")
	{
		Return Self;
	}
	ChildName = StripPathComponent(Path);
	if (ChildName == "")
	{
		Return Self;
	}
	i = FindChildIndex(ChildName);
	if (Valid(i))
	{
		Return Children[i].FindChildByPath(Path);
	}
	Return None;
	*/
}
UStreamDirectoryNode* UStreamDirectoryNode::FindChild(FString ChildName, bool bDeepSearch)
{
	/*
	local int i;
	local StreamDirectoryNode Node;
	InitializeNode();
	for (i = 0; i < Children.Length; i++)
	{
		if (CompareNames(Children[i].GetName(), ChildName))
		{
			Return Children[i];
		}
		if (bDeepSearch)
		{
			Node = Children[i].FindChild(ChildName, bDeepSearch);
			if (Node != None)
			{
				Return Node;
			}
		}
	}
	*/
	return nullptr;
}
int32 UStreamDirectoryNode::FindChildIndex(FString ChildName)
{
	/*
	local int i;
	if (ChildName == "")
	{
		Return - 1;
	}
	InitializeNode();
	if (Right(ChildName, 1) == GetPathSeparator())
	{
		ChildName = Left(ChildName, Len(ChildName) - 1);
	}
	for (i = 0; i < Children.Length; i++)
	{
		if (CompareNames(Children[i].GetName(), ChildName))
		{
			Return i;
		}
	}
	*/
	return - 1;
}
void UStreamDirectoryNode::HasChildren()
{
	/*
	if (Outer.bSimpleFileBrowsing)
	{
		Return Children.Length > 1;
	}
	Return Children.Length > 0;
	*/
}
void UStreamDirectoryNode::Valid(int32 i)
{
	//Return i >= 0 && i < Children.Length&& Children[i] != None;
}
void UStreamDirectoryNode::ValidFile(int32 i)
{
	//Return i >= 0 && i < Contents.Length;
}
void UStreamDirectoryNode::CreateChild(FString ChildName)
{
	/*
	local StreamDirectoryNode Child;
	if (ChildName == "")
	{
		Return None;
	}
	Child = new (Outer) class'StreamDirectoryNode';
	Assert(Child != None);
	Child.SetParent(Self);
	Child.SetName(ChildName);
	Child.SetPath(MyPath);
	Return Child;
	*/
}
void UStreamDirectoryNode::StripPathComponent(FString &Path)
{
	/*
	local string S;
	local int i;
	if (Path == "")
	{
		Return "";
	}
	i = InStr(Path, GetPathSeparator());
	if (i == -1)
	{
		Return "";
	}
	S = Left(Path, i);
	Path = Mid(Path, i + 1);
	Return S;
	*/
}
void UStreamDirectoryNode::HandleDebugExec(FString Command, FString Param)
{
	/*
	local int i;
	local StreamDirectoryNode Node;
	Switch(Command)
	{
			case "cwd":
				Log("Current Directory:" $ GetPath(), 'MusicPlayer');
				Return True;
			case "dumpcwd":
				Log("Dumping directory contents for" @ GetName(), 'MusicPlayer');
				i = 0;
				if (i < Children.Length)
				{
					Log(" Child " $ i @ "'" $ Children[i].GetName() $ "'", 'MusicPlayer');
					i++;
					break;
				}
				for (i = 0; i < Contents.Length; i++)
				{
					Log(" Content " $ i @ "'" $ Contents[i] $ "'", 'MusicPlayer');
				}
				Return True;
			case "cost":
				if (Param == "")
				{
					Node = Self;
				}
				else
				{
					Node = FindChild(Param);
					if (Node == None)
					{
						Log("Couldn't find child '" $ Param $ "' in directory" @ GetName(), 'MusicPlayer');
						Return True;
					}
				}
				Log("Cost for directory '" $ Node.GetName() $ "': " $ Node.cost() @ "Open:" $ Node.IsOpen() @ "Initialized:" $ Node.Initialized(), 'MusicPlayer');
				Return True;
			default:
				Return False;
		}
	*/
}