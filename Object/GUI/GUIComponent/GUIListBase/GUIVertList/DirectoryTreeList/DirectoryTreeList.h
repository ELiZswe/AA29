// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "DirectoryTreeList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDirectoryTreeList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UDirectoryTreeList();

	UPROPERTY()														bool bSimpleFileBrowsing;									//var() config bool bSimpleFileBrowsing;
	//UPROPERTY()														UStreamDirectoryNode* Current;									//var() editconst StreamDirectoryNode Current;
	//UPROPERTY()														UStreamDirectoryNode* root;									//var() editconst StreamDirectoryNode root;
	//UPROPERTY()														UStreamInterface* FileManager;									//var() editconst StreamInterface FileManager;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CreateRoot();
	//void SetCurrent(UStreamDirectoryNode* Node);
	void InternalOnClick(UGUIComponent* Sender);
	void InternalOnDrawItem(UCanvas* C, int32 Item, float X, float Y, float XL, float YL, bool bIsSelected, bool bIsPending);
	void FindVisibleItemIndex(FString Path);
	void Get(bool bFullPath);
	void GetPendingItems(bool bGuarantee);
	void getItemAtIndex(int32 idx);
	void GetCurrentNode();
	void GetCurrentNodePath();
	void GetPath();
	void GetPathAt(int32 idx);
	void ChDir(FString Path);
	void ExpandNode(FString Path);
	void VisibleNode(int32 VisibleItemIndex);
	void VisibleNodeText(int32 VisibleItemIndex);
	void UpdateItemCount(bool bFullUpdate);
	//void AddNode(UStreamDirectoryNode* Parent, FString InName, bool bIsFile);
	//void RemoveNode(UStreamDirectoryNode* Parent, UStreamDirectoryNode* Child);
	//void RemoveFile(UStreamDirectoryNode* Parent, FString InFileName);
	void FindNode(FString Path);
	void MakeVisible(float Perc);
	void SetTopItem(int32 Item);
	void IsValid();
	void IsValidIndex(int32 i);
	void Clear();
	void HandleDebugExec(FString Command, FString Params);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
};
