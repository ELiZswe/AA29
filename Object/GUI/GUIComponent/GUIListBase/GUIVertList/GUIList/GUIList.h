// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "AA29/AA29.h"
#include "GUIList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UGUIList();

	UPROPERTY(EditAnywhere)						FColor BonusPackColor;									//var() Object.Color BonusPackColor;
	UPROPERTY(EditAnywhere)						FColor Official2004Color;								//var() Object.Color Official2004Color;
	UPROPERTY(EditAnywhere)						FColor OfficialColor;									//var() Object.Color OfficialColor;
	UPROPERTY(EditAnywhere)						TArray<FGUIListElem> SelectedElements;					//var() editconstarray editconst array<GUIListElem> SelectedElements;
	UPROPERTY(EditAnywhere)						TArray<FGUIListElem> Elements;							//var() editconstarray editconst array<GUIListElem> Elements;
	UPROPERTY(EditAnywhere)						EeTextAlign TextAlign;									//var() GUI.eTextAlign TextAlign;

	void SortList();
	void Sort();
	void CompareItem(FGUIListElem ElemA, FGUIListElem ElemB);
	void Add(FString NewItem, UObject* obj, FString str, bool bSection);
	void AddElement(FGUIListElem NewElem);
	void Replace(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort);
	void Insert(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort, bool bSection);
	void InsertElement(int32 i, FGUIListElem NewElem, bool bNoSort);
	void Swap(int32 IndexA, int32 IndexB);
	void LoadFrom(UGUIList* Source, bool bClearFirst);
	void Remove(int32 i, int32 Count, bool bNoSort);
	int32 RemoveSilent(int32 i, int32 Count);
	void RemoveElement(FGUIListElem elem, int32 Count, bool bNoSort);
	void Clear();
	void SelectedText();
	void Get(bool bGuarantee);
	void GetObject();
	void GetExtra();
	void IsSection();
	void getItemAtIndex(int32 i);
	void GetObjectAtIndex(int32 i);
	void GetExtraAtIndex(int32 i);
	void GetAtIndex(int32 i, FString& ItemStr, UObject*& ExtraObj, FString& ExtraStr);
	void SetItemAtIndex(int32 i, FString NewItem);
	void SetObjectAtIndex(int32 i, UObject* NewObject);
	void SetExtraAtIndex(int32 i, FString NewExtra);
	void RemoveItem(FString Item);
	void RemoveObject(UObject* obj);
	void RemoveExtra(FString str);
	void Find(FString Text, bool bExact, bool bExtra);
	void FindExtra(FString Text, bool bExact);
	void FindItemObject(UObject* obj);
	int32 FindIndex(FString Test, bool bExact, bool bExtra, UObject* TestObject);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	bool InternalOnDragDrop(UGUIComponent* Sender);
	void ClearPendingElements();
	void GetPendingElements(bool bGuarantee);
};
