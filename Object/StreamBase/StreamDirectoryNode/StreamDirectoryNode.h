// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "StreamDirectoryNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UStreamDirectoryNode : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamDirectoryNode();

	UPROPERTY(EditAnywhere)									bool bInitialized;								//var() bool bInitialized;
	UPROPERTY(EditAnywhere)									bool bExpanded;									//var() bool bExpanded;
	UPROPERTY(EditAnywhere)									FString DirectoryName;							//var() editconst string DirectoryName;
	UPROPERTY(EditAnywhere)									FString MyPath;									//var() editconst string MyPath;
	UPROPERTY(EditAnywhere)									int32 ChildRenderCost;							//var() int ChildRenderCost;
	UPROPERTY(EditAnywhere)									int32 NodeRenderCost;							//var() int NodeRenderCost;
	UPROPERTY(EditAnywhere)									TArray<FString> Contents;						//var() editconst array<String> Contents;
	UPROPERTY(EditAnywhere)									TArray<UStreamDirectoryNode*> Children;			//var() editconst array<StreamDirectoryNode> Children;
	UPROPERTY(EditAnywhere)									UStreamDirectoryNode* Parent;					//var() StreamDirectoryNode Parent;

	void InitializeNode();
	void RefreshNodeContents();
	void Clear(bool bPropagate);
	FString GetIndent();
	void GetNodePrefix(bool bNoPrefix);
	void NodeText(int32 VisibleIndex, bool bNoPrefix);
	void FindVisibleNode(int32& idx);
	int32 FindVisibleNodeIndex(FString Path);
	int32 cost();
	void UpdateCost(bool bFullUpdate);
	void Toggle();
	void Expand(bool bFullUpdate);
	void Collapse(bool bFullUpdate);
	bool ChangeDirectory(FString Path, UStreamDirectoryNode*& Node, bool bRefreshContents);
	bool ExpandPath(FString Path);
	UStreamDirectoryNode* AddChild(FString ChildName);
	bool AddContent(FString ContentName);
	bool RemoveChild(UStreamDirectoryNode* Child);
	bool RemoveChildAt(int32 i);
	void RemoveContent(FString Path);
	bool RemoveContentAt(int32 i);
	void FindFileIndex(FString Filename);
	bool SetName(FString InName);
	bool SetParent(UStreamDirectoryNode* InParent);
	bool SetPath(FString InPath);
	bool Initialized();
	bool isEmpty();
	bool IsOpen();
	FString GetName();
	FString GetPath();
	void FindChildByPath(FString& Path);
	UStreamDirectoryNode* FindChild(FString ChildName, bool bDeepSearch);
	int32 FindChildIndex(FString ChildName);
	void HasChildren();
	void Valid(int32 i);
	void ValidFile(int32 i);
	void CreateChild(FString ChildName);
	void StripPathComponent(FString& Path);
	void HandleDebugExec(FString Command, FString Param);
};
