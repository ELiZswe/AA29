// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "DirectoryTreeList.generated.h"

class UStreamDirectoryNode;
class UStreamInterface;

class UGUIComponent;
class UGUIController;
UCLASS()
class UDirectoryTreeList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UDirectoryTreeList();

	UPROPERTY(EditAnywhere)			bool bSimpleFileBrowsing;					//var() config bool bSimpleFileBrowsing;
	UPROPERTY(EditAnywhere)			UStreamDirectoryNode* Current;				//var() editconst StreamDirectoryNode Current;
	UPROPERTY(EditAnywhere)			UStreamDirectoryNode* root;					//var() editconst StreamDirectoryNode root;
	UPROPERTY(EditAnywhere)			UStreamInterface* FileManager;				//var() editconst StreamInterface FileManager;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CreateRoot();
	void SetCurrent(UStreamDirectoryNode* Node);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnDrawItem(UCanvas* C, int32 Item, float X, float Y, float XL, float YL, bool bIsSelected, bool bIsPending);
	int32 FindVisibleItemIndex(FString Path);
	FString Get(bool bFullPath);
	TArray<FString> GetPendingItems(bool bGuarantee);
	FString getItemAtIndex(int32 idx);
	FString GetCurrentNode();
	FString GetCurrentNodePath();
	FString GetPath();
	FString GetPathAt(int32 idx);
	bool ChDir(FString Path);
	bool ExpandNode(FString Path);
	UStreamDirectoryNode* VisibleNode(int32 VisibleItemIndex);
	FString VisibleNodeText(int32 VisibleItemIndex);
	void UpdateItemCount(bool bFullUpdate);
	bool AddNode(UStreamDirectoryNode* Parent, FString InName, bool bIsFile);
	bool RemoveNode(UStreamDirectoryNode* Parent, UStreamDirectoryNode* Child);
	bool RemoveFile(UStreamDirectoryNode* Parent, FString InFileName);
	UStreamDirectoryNode* FindNode(FString Path);
	void MakeVisible(float Perc);
	void SetTopItem(int32 Item);
	bool IsValid();
	bool IsValidIndex(int32 i);
	void Clear();
	bool HandleDebugExec(FString Command, FString Params);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
};
