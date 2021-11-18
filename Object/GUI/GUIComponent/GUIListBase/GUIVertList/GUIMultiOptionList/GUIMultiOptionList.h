// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "GUIMultiOptionList.generated.h"

class UGUIMenuOption;
class UGUIStyles;
class UGUIMultiOptionList;

/**
 * 
 */
UCLASS()
class AA29_API UGUIMultiOptionList : public UGUIVertList
{
	GENERATED_BODY()
public:
	UGUIMultiOptionList();

	UPROPERTY(EditAnywhere, Category = "Style")				UGUIStyles* ItemStyle;						//var(Style) GUIStyles ItemStyle;
	UPROPERTY(EditAnywhere, Category = "Style")				FString ItemStyleName;						//var(Style) string ItemStyleName;
	UPROPERTY(EditAnywhere)									bool bVerticalLayout;						//var() bool bVerticalLayout;
	UPROPERTY(EditAnywhere)									int32 ItemsPerColumn;						//var() editconst int ItemsPerColumn;
	UPROPERTY(EditAnywhere)									int32 NumColumns;							//var() int NumColumns;
	UPROPERTY(EditAnywhere)									float ColumnWidth;							//var() float ColumnWidth;
	UPROPERTY(EditAnywhere)									float ItemPadding;							//var() float ItemPadding;
	UPROPERTY(EditAnywhere)									float ItemScaling;							//var() float ItemScaling;
	UPROPERTY(EditAnywhere)									UGUIMenuOption* Elements;					//var() editconstarray editconst array<GUIMenuOption> Elements;

	void OnCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender);
	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	int32 CalculateIndex(bool bRequireValidIndex);
	bool ElementVisible(int32 idx);
	bool InternalOnClick(UGUIComponent* Sender);
	void GenerateMenuOption(FString NewOptionClass, UGUIMenuOption* NewComp, FString Caption);
	UGUIMenuOption* addItem(FString NewOptionClass, UGUIMenuOption* NewComp, FString Caption, bool bUnique);
	UGUIMenuOption* ReplaceItem(int32 idx, FString NewOptionClass, UGUIMenuOption* NewComp, FString Caption, bool bUnique);
	UGUIMenuOption* InsertItem(int32 idx, FString NewOptionClass, UGUIMenuOption* NewComp, FString Caption, bool bUnique);
	void RemoveItem(int32 idx);
	void Clear();
	bool ValidIndex(int32 idx);
	void Get();
	void GetItem(int32 idx);
	int32 Find(FString Caption);
	int32 FindComp(UGUIMenuOption* Comp);
	void InternalOnChange(UGUIComponent* Sender);
	void ShowList();
	void HideList();
	int32 SetIndex(int32 NewIndex);
	void SetFocus(UGUIComponent* Who);
	void LoseFocus(UGUIComponent* Sender);
	void ScrollAlignThumb();
	void MakeVisible(float Perc);
	void SetTopItem(int32 Item);
	void InternalOnAdjustTop(UGUIComponent* Sender);
	void WheelDown();
	void PgUp();
	void PgDn();
	bool Up();
	bool Down();
	bool MoveRight();
	bool MoveLeft();
	bool NextControl(UGUIComponent* Sender);
	bool PrevControl(UGUIComponent* Sender);
	bool CanFocusElement(UGUIMenuOption* elem);
	void CenterMouse();
};
