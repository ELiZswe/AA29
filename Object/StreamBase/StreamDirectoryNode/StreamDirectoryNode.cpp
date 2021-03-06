// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamDirectoryNode/StreamDirectoryNode.h"

UStreamDirectoryNode::UStreamDirectoryNode()
{
	NodeRenderCost = 1;
}

void UStreamDirectoryNode::InitializeNode()
{
	if (Initialized())
	{
		return;
	}
	Clear(false);
	bInitialized = true;
	if (Parent == nullptr || MyPath == "" || MyPath == "..")
	{
		return;
	}
	/*
	if (Outer.bSimpleFileBrowsing)
	{
		AddChild("..").InitializeNode();
	}
	RefreshNodeContents();
	*/
}

void UStreamDirectoryNode::RefreshNodeContents()
{
	int32 i = 0;
	TArray<FString> Directories = {};
	TArray<FString> Files = {};
	/*
	if (Outer.FileManager == nullptr)
	{
		Log("Cannot refresh node '" + MyPath + "' contents - File Manager not set.", 'MusicPlayer');
		return;
	}
	if (HasChildren())
	{
		for (i = Children.Num() - 1; i >= 0; i--)
		{
			if (Children[i].GetPath() != "..")
			{
				Children.RemoveAt(i, 1);
			}
		}
	}
	Contents.RemoveAt(0, Contents.Num());
	Outer.FileManager.GetDirectoryContents(Directories, MyPath, 1);
	for (i = 0; i < Directories.Num(); i++)
	{
		AddChild(Directories[i]);
	}
	Outer.FileManager.GetDirectoryContents(Files, MyPath, 4);
	Outer.FileManager.GetDirectoryContents(Files, MyPath, 5);
	for (i = 0; i < Files.Num(); i++)
	{
		AddContent(Files[i]);
	}
	UpdateCost();
	*/
}

void UStreamDirectoryNode::Clear(bool bPropagate)
{
	int32 i = 0;
	if (HasChildren() && bPropagate)
	{
		for (i = 0; i < Children.Num(); i++)
		{
			Children[i]->Clear(bPropagate);
		}
	}
	//Children.RemoveAt(0, Children.Num());
	//Contents.RemoveAt(0, Contents.Num());
	UpdateCost(false);
	bInitialized = false;
}

FString UStreamDirectoryNode::GetIndent()
{
	FString Indent="";
	/*
	if (Outer.bSimpleFileBrowsing)
	{
		return "";
	}
	if (Parent != nullptr)
	{
		Indent = Parent.GetIndent() + " ";
	}
	*/
	return Indent;
}
FString UStreamDirectoryNode::GetNodePrefix(bool bNoPrefix)
{
	if (bNoPrefix)
	{
		return "";
	}
	if (isEmpty())
	{
		return GetIndent() + ". ";
	}
	if (!IsOpen())
	{
		return GetIndent() + "+ ";
	}
	return GetIndent() + "- ";
}

FString UStreamDirectoryNode::NodeText(int32 VisibleIndex, bool bNoPrefix)
{
	UStreamDirectoryNode* Node = nullptr;
	/*
	if (!IsOpen())
	{
		return GetNodePrefix(bNoPrefix) + DirectoryName;
	}
	Node = FindVisibleNode(VisibleIndex);
	if (Node == this)
	{
		if (VisibleIndex >= 0 && VisibleIndex < Contents.Num())
		{
			return Contents[VisibleIndex];
		}
		return GetNodePrefix(bNoPrefix) + DirectoryName;
	}
	return Node.NodeText(VisibleIndex, bNoPrefix);
	*/
	return "FAKE";     //FAKE   /EliZ
}

UStreamDirectoryNode* UStreamDirectoryNode::FindVisibleNode(int32 &idx)
{
	int32 Count = 0;
	int32 i = 0;
	/*
	if (!IsOpen())
	{
		return this;
	}
	InitializeNode();
	if (idx > 0)
	{
		Count = Children[0].cost();
		if (HasChildren())
		{
			if (Count <= idx && ++i < Children.Num())
			{
				Count += Children[i].cost();
			}
		}
		if (i == Children.Num() || !HasChildren())
		{
			idx -= Count;
			return this;
		}
		idx = Count - idx;
	}
	return Children[i].FindVisibleNode(idx);
	*/
	return nullptr;    //FAKE   /ELiZ
}

int32 UStreamDirectoryNode::FindVisibleNodeIndex(FString Path)
{
	int32 VisibleIndex = 0;
	int32 i = 0;
	FString MyComponent = "";
	if (Path == "")
	{
		return 1;
	}
	InitializeNode();
	/*
	MyComponent = StripPathComponent(Path);
	if (MyComponent == "")
	{
		MyComponent = Path;
	}
	VisibleIndex = 1;
	for (i = 0; i < Children.Num(); i++)
	{
		if (CompareNames(MyComponent, Children[i].GetName()))
		{
			return VisibleIndex + Children[i].FindVisibleNodeIndex(Path);
		}
		VisibleIndex += Children[i].cost();
	}
	for (i = 0; i < Contents.Num(); i++)
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
	int32 i = 0;
	NodeRenderCost = 0;
	ChildRenderCost = 0;
	/*
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
		for (i = 0; i < Children.Num(); i++)
		{
			if (bFullUpdate)
			{
				Children[i].UpdateCost(bFullUpdate);
			}
			ChildRenderCost += Children[i].cost();
		}
		NodeRenderCost += Contents.Num();
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
	int32 i = 0;
	FString MyComponent = "";
	InitializeNode();
	if (Path == "" || Path == ".")
	{
		if (bRefreshContents && Initialized())
		{
			RefreshNodeContents();
		}
		if (isEmpty())
		{
			Node = nullptr;
			return false;
		}
		Expand(false);
		Node = this;
		return true;
	}
	if (Path == "..")
	{
		if (Parent == nullptr)
		{
			Expand(false);
			Node = this;
			return true;
		}
		Collapse(false);
		//return Parent.ChangeDirectory("", Node, bRefreshContents);
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
		/*
		if (Children[i].ChangeDirectory(Path, Node, bRefreshContents))
		{
			Collapse();
			return true;
		}
		*/
	}
	Node = nullptr;
	return false;
}

bool UStreamDirectoryNode::ExpandPath(FString Path)
{
	int32 i = 0;
	int32 idx;
	FString S;
	InitializeNode();
	if (Path == "")
	{
		Expand(false);
		return true;
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
			for (i = 0; i < Children.Num(); i++)
			{
				if (Children[i] != Children[idx])
				{
					Children[i]->Collapse(false);
				}
			}
			if (Path != "")
			{
				Children[idx]->ExpandPath(Path);
			}
		}
		Expand(false);
		return true;
	}
	return false;
}

UStreamDirectoryNode* UStreamDirectoryNode::AddChild(FString ChildName)
{
	UStreamDirectoryNode* Child=nullptr;
	int32 i = 0;
	FString S = "";

	/*
	if (ChildName == "")
	{
		return nullptr;
	}
	for (InitializeNode(); i < Children.Num(); i++)
	{
		S = Children[i].GetName();
		if (CompareNames(S, ChildName))
		{
			return Children[i];
		}
		if (ChildName < S)
		{
		}
	}
	Child = CreateChild(ChildName);
	if (Child == nullptr)
	{
		Log(GetName() @ "failed to successfully create child '" + ChildName + "'", 'MusicPlayer');
		return nullptr;
	}
	Children.insert(i, 1);
	Children[i] = Child;
	UpdateCost();
	*/
	return Child;
}
bool UStreamDirectoryNode::AddContent(FString ContentName)
{
	int32 i = 0;
	FString S = "";
	if (ContentName == "")
	{
		return false;
	}
	InitializeNode();
	/*
	S = StripPathComponent(ContentName);
	if (S != "")
	{
		i = FindChildIndex(S);
		if (Valid(i))
		{
			return Children[i].AddContent(ContentName);
		}
		return false;
	}
	i = FindFileIndex(ContentName);
	if (i == -1)
	{
		Contents[Contents.Num()] = ContentName;
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
	if (Valid(i))
	{
		//Children.RemoveAt(i, 1);
		UpdateCost(true);
		return true;
	}
	return false;
}

bool UStreamDirectoryNode::RemoveContent(FString Path)
{
	FString S = "";
	int32 i = 0;
	InitializeNode();
	/*
	S = StripPathComponent(Path);
	if (S != "")
	{
		i = FindChildIndex(S);
		if (Valid(i))
		{
			return Children[i].RemoveContent(Path);
		}
		return false;
	}
	i = FindFileIndex(Path);
	*/
	return RemoveContentAt(i);
}

bool UStreamDirectoryNode::RemoveContentAt(int32 i)
{
	if (ValidFile(i))
	{
		//Contents.RemoveAt(i, 1);
		UpdateCost(true);
		return true;
	}
	return false;
}

int32 UStreamDirectoryNode::FindFileIndex(FString Filename)
{
	int32 i = 0;
	if (Filename == "")
	{
		return - 1;
	}
	InitializeNode();
	for (i = 0; i < Contents.Num(); i++)
	{
		if (CompareNames(Contents[i], Filename))
		{
			return i;
		}
	}
	return - 1;
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
	if (MyPath != "")
	{
		return false;
	}
	if (DirectoryName == "..")
	{
		MyPath = DirectoryName;
		return true;
	}
	//MyPath = InPath + DirectoryName + GetPathSeparator();
	return true;
}

bool UStreamDirectoryNode::Initialized()
{
	return bInitialized;
}

bool UStreamDirectoryNode::isEmpty()
{
	//return Initialized() && !HasChildren() && Contents.Num() == 0;
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

UStreamDirectoryNode* UStreamDirectoryNode::FindChildByPath(FString& Path)
{
	FString ChildName = "";
	int32 i = 0;
	InitializeNode();
	if (Path == "")
	{
		return this;
	}
	/*
	ChildName = StripPathComponent(Path);
	if (ChildName == "")
	{
		return this;
	}
	i = FindChildIndex(ChildName);
	if (Valid(i))
	{
		return Children[i].FindChildByPath(Path);
	}
	*/
	return nullptr;
}

UStreamDirectoryNode* UStreamDirectoryNode::FindChild(FString ChildName, bool bDeepSearch)
{
	int32 i = 0;
	UStreamDirectoryNode* Node = nullptr;
	InitializeNode();
	/*
	for (i = 0; i < Children.Num(); i++)
	{
		if (CompareNames(Children[i].GetName(), ChildName))
		{
			return Children[i];
		}
		if (bDeepSearch)
		{
			Node = Children[i].FindChild(ChildName, bDeepSearch);
			if (Node != nullptr)
			{
				return Node;
			}
		}
	}
	*/
	return nullptr;
}

int32 UStreamDirectoryNode::FindChildIndex(FString ChildName)
{
	int32 i = 0;
	if (ChildName == "")
	{
		return - 1;
	}
	InitializeNode();
	/*
	if (Right(ChildName, 1) == GetPathSeparator())
	{
		ChildName = Left(ChildName, Len(ChildName) - 1);
	}
	for (i = 0; i < Children.Num(); i++)
	{
		if (CompareNames(Children[i].GetName(), ChildName))
		{
			return i;
		}
	}
	*/
	return - 1;
}

bool UStreamDirectoryNode::HasChildren()
{
	/*
	if (Outer.bSimpleFileBrowsing)
	{
		return Children.Num() > 1;
	}
	return Children.Num() > 0;
	*/
	return false;    //FAKE   /EliZ
}

bool UStreamDirectoryNode::Valid(int32 i)
{
	//return i >= 0 && i < Children.Num()&& Children[i] != nullptr;
	return false;   //FAKE   /EliZ
}

bool UStreamDirectoryNode::ValidFile(int32 i)
{
	//return i >= 0 && i < Contents.Num();
	return false;   //FAKE   /EliZ
}

UStreamDirectoryNode* UStreamDirectoryNode::CreateChild(FString ChildName)
{
	UStreamDirectoryNode* Child = nullptr;
	if (ChildName == "")
	{
		return nullptr;
	}
	/*
	Child = new (Outer) UStreamDirectoryNode::StaticClass();
	Assert(Child != nullptr);
	Child.SetParent(this);
	Child.SetName(ChildName);
	Child.SetPath(MyPath);
	*/
	return Child;
}

FString UStreamDirectoryNode::StripPathComponent(FString &Path)
{
	FString S = "";
	int32 i = 0;
	if (Path == "")
	{
		return "";
	}
	/*
	i = InStr(Path, GetPathSeparator());
	if (i == -1)
	{
		return "";
	}
	S = Left(Path, i);
	Path = Mid(Path, i + 1);
	*/
	return S;
}

bool UStreamDirectoryNode::HandleDebugExec(FString Command, FString Param)
{
	int32 i = 0;
	UStreamDirectoryNode* Node = nullptr;
	/*
	switch(Command)
	{
		case "cwd":
			Log("Current Directory:" + GetPath(), 'MusicPlayer');
			return true;
		case "dumpcwd":
			Log("Dumping directory contents for" @ GetName(), 'MusicPlayer');
			i = 0;
			if (i < Children.Num())
			{
				Log(" Child " + i @ "'" + Children[i].GetName() + "'", 'MusicPlayer');
				i++;
				break;
			}
			for (i = 0; i < Contents.Num(); i++)
			{
				Log(" Content " + i @ "'" + Contents[i] + "'", 'MusicPlayer');
			}
			return true;
		case "cost":
			if (Param == "")
			{
				Node = this;
			}
			else
			{
				Node = FindChild(Param);
				if (Node == nullptr)
				{
					Log("Couldn't find child '" + Param + "' in directory" @ GetName(), 'MusicPlayer');
					return true;
				}
			}
			Log("Cost for directory '" + Node.GetName() + "': " + Node.cost() @ "Open:" + Node.IsOpen() @ "Initialized:" + Node.Initialized(), 'MusicPlayer');
			return true;
		default:
			return false;
	}
	*/
	return false;     //FAKE   /EliZ
}
