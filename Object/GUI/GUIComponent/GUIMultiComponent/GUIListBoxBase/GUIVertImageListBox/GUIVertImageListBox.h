// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIVertImageListBox.generated.h"

class UGUIVertImageList;
class UGUIListBase;
class UGUIContextMenu;

UCLASS()
class AA29_API UGUIVertImageListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIVertImageListBox();


	UPROPERTY(EditAnywhere)									int32 VertBorder;							//var() int VertBorder;
	UPROPERTY(EditAnywhere)									int32 HorzBorder;							//var() int HorzBorder;
	UPROPERTY(EditAnywhere)									int32 NoVisibleCols;						//var() int NoVisibleCols;
	UPROPERTY(EditAnywhere)									int32 NoVisibleRows;						//var() int NoVisibleRows;
	UPROPERTY(EditAnywhere)									float ImageScale;							//var() float ImageScale;
	UPROPERTY(EditAnywhere)									EeCellStyle CellStyle;						//var() GUI.eCellStyle CellStyle;
	UPROPERTY()												UGUIVertImageList* List;					//var GUIVertImageList List;

	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	int32 ItemCount();
	void AddImage(UMaterialInstance* Image, int32 Item);
	bool MyOpen(UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner);
	bool MyClose(UGUIContextMenu* Sender);
	void Clear();
};
