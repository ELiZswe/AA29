// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/MyEnums.h"
#include "MultiSelectList.generated.h"

class UGUIList;
UCLASS()
class UMultiSelectList : public UGUIList
{
	GENERATED_BODY()
public:
	UMultiSelectList();

	UPROPERTY(EditAnywhere)						TArray<FMultiSelectListElem> MElements;							//var array<MultiSelectListElem> MElements;

	void Add(FString NewItem, UObject* obj, FString str, bool bSection);
	void Replace(int32 Index, FString NewItem, UObject* obj, FString str, bool bNoSort);
	void Insert(int32 Index, FString NewItem, UObject* obj, FString str, bool bNoSort, bool bSection);
	void Swap(int32 IndexA, int32 IndexB);
	void LoadFrom(UGUIList* Source, bool bClearFirst);
	int32 Remove(int32 i, int32 Count, bool bNoSort);
	void Clear();
	FString Get(bool bGuarantee);
	UObject* GetObject();
	bool IsSection();
	FString GetExtra();
	FString getItemAtIndex(int32 i);
	UObject* GetObjectAtIndex(int32 i);
	FString GetExtraAtIndex(int32 i);
	void GetAtIndex(int32 i, FString& ItemStr, UObject*& ExtraObj, FString& ExtraStr);
	TArray<FString> GetPendingItems(bool bGuarantee);
	TArray<FGUIListElem> GetPendingElements(bool bGuarantee);
	void SetItemAtIndex(int32 i, FString NewItem);
	void SetObjectAtIndex(int32 i, UObject* NewObject);
	void SetExtraAtIndex(int32 i, FString NewExtra);
	void RemoveItem(FString Item);
	void RemoveObject(UObject* obj);
	void RemoveExtra(FString str);
	FString Find(FString Text, bool bExact, bool bExtra);
	int32 FindIndex(FString Test, bool bExact, bool bExtra, UObject* TestObject);
	int32 SetIndex(int32 NewIndex);
};
