// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "GUIVertImageList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIVertImageList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UGUIVertImageList();

	UPROPERTY(EditAnywhere)							UMaterialInstance*			LockedMat;					//var() Material LockedMat;
	UPROPERTY(EditAnywhere)							TArray<FImageListElem>		SelectedElements;			//var() editconstarray editconst array<ImageListElem> SelectedElements;
	UPROPERTY(EditAnywhere)							TArray<FImageListElem>		Elements;					//var() editconstarray editconst array<ImageListElem> Elements;
	UPROPERTY(EditAnywhere)							int32						VertBorder;					//var() int VertBorder;
	UPROPERTY(EditAnywhere)							int32						HorzBorder;					//var() int HorzBorder;
	UPROPERTY(EditAnywhere)							int32						NoVisibleCols;				//var() int NoVisibleCols;
	UPROPERTY(EditAnywhere)							int32						NoVisibleRows;				//var() int NoVisibleRows;
	UPROPERTY(EditAnywhere)							float						ImageScale;					//var() float ImageScale;
	UPROPERTY(EditAnywhere)							EeCellStyle					CellStyle;					//var() GUI.eCellStyle CellStyle;

	int32 CalculateIndex(bool bRequireValidIndex);
	bool InternalOnClick(UGUIComponent* Sender);
	void SetIndex(int32 NewIndex);
	bool Up();
	bool Down();
	bool MoveRight();
	bool MoveLeft();
	void home();
	void End();
	void PgUp();
	void PgDn();
	void MakeVisible(float Perc);
	void SetTopItem(int32 Item);
	void Add(UMaterialInstance* Image, int32 Item, int32 Locked);
	void AddImage(FImageListElem NewElem, int32 Locked);
	void Replace(int32 i, UMaterialInstance* NewImage, int32 NewItem, int32 Locked);
	void Insert(int32 i, UMaterialInstance* NewImage, int32 NewItem, int32 Locked);
	void InsertElement(int32 i, FImageListElem NewElem, int32 Locked);
	void Swap(int32 IndexA, int32 IndexB);
	void LoadFrom(UGUIVertImageList* Source, bool bClearFirst);
	void Remove(int32 i, int32 Count);
	int32 RemoveSilent(int32 i, int32 Count);
	void RemoveElement(FImageListElem elem, int32 Count);
	void Clear();
	void Get(bool bGuarantee);
	int32 GetItem();
	void GetImageAtIndex(int32 i);
	void getItemAtIndex(int32 i);
	int32 GetItemIntAtIndex(int32 i);
	void GetAtIndex(int32 i, UMaterialInstance*& Image, int32& Item, int32& Locked);
	bool IndexLocked(int32 i);
	bool IsLocked();
	void ClearPendingElements();
	void GetPendingElements(bool bGuarantee);
	void SetImageAtIndex(int32 i, UMaterialInstance* NewImage);
	void SetItemAtIndex(int32 i, int32 NewItem);
	void RemoveImage(UMaterialInstance* Image);
	void RemoveItem(int32 Item);
	int32 FindImage(UMaterialInstance* Image);
	int32 FindItem(int32 Item);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	bool InternalOnDragDrop(UGUIComponent* Sender);

};
