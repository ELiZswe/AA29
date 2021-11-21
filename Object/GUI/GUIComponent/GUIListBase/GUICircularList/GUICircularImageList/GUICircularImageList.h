// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularList.h"
#include "GUICircularImageList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUICircularImageList : public UGUICircularList
{
	GENERATED_BODY()
public:
	UGUICircularImageList();

	UPROPERTY()		TArray<FGUIListElem> Elements;			//	var() editconstarray editconst TArray<GUIListElem> Elements;


	void Add(UMaterialInstance* img, FString str);
	void Replace(int32 i, UMaterialInstance* img, FString str);
	void Insert(int32 i, UMaterialInstance* img, FString str);
	void Swap(int32 IndexA, int32 IndexB);
	void LoadFrom(UGUICircularImageList* Source, bool bClearFirst);
	int32 RemoveSilent(int32 i, int32 Count);
	int32 Remove(int32 i, int32 Count);
	int32 RemoveElement(FGUIListElem elem, int32 Count);
	void Clear();
	FString Get(bool bGuarantee);
	UMaterialInstance* GetImage(bool bGuarantee);
	FString getItemAtIndex(int32 i);
	UMaterialInstance* GetImageAtIndex(int32 i);
	void GetAtIndex(int32 i, FString& ItemStr, UObject*& img, FString& ExtraStr);
	TArray<FString> GetPendingItems(bool bGuarantee);
	TArray<FGUIListElem> GetPendingElements(bool bGuarantee);
	void SetItemAtIndex(int32 i, FString NewItem);
	void SetImageAtIndex(int32 i, UMaterialInstance* img);
	void RemoveItem(FString Item);
	void RemoveImage(UMaterialInstance* img);
	int32 FindIndex(UMaterialInstance* img, FString Test);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	bool InternalOnDragDrop(UGUIComponent* Sender);
};
