// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIListBase.generated.h"

class UGUIScrollBarBase;
class UGUIStyles;

UCLASS()
class AA29_API UGUIListBase : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIListBase();

	UPROPERTY(EditAnywhere)							TArray<UGUIComponent*> LinkedObjects;	//var() editconstarray array<GUIComponent> LinkedObjects;
	UPROPERTY(EditAnywhere)							int32 MightRemove;						//var() editconst int MightRemove;
	UPROPERTY(EditAnywhere)							int32 DropIndex;						//var() editconst int DropIndex;
	UPROPERTY(EditAnywhere)							int32 LastPressY;						//var() editconst int LastPressY;
	UPROPERTY(EditAnywhere)							int32 LastPressX;						//var() editconst int LastPressX;
	UPROPERTY(EditAnywhere)							int32 LastSelected;						//var() editconst int LastSelected;
	UPROPERTY(EditAnywhere)							TArray<int32> SelectedItems;			//var() editconst array<int> SelectedItems;
	UPROPERTY(EditAnywhere)							int32 ItemCount;						//var() editconst int ItemCount;
	UPROPERTY(EditAnywhere)							float ItemWidth;						//var() const editconst float ItemWidth;
	UPROPERTY(EditAnywhere)							float ItemHeight;						//var() const editconst float ItemHeight;
	UPROPERTY(EditAnywhere)							int32 ItemsPerPage;						//var() const editconst int ItemsPerPage;
	UPROPERTY(EditAnywhere)							int32 Index;							//var() editconst int Index;
	UPROPERTY(EditAnywhere)							int32 Top;								//var() editconst int Top;
	UPROPERTY(EditAnywhere)							FColor SelectedBKColor;					//var() Object.Color SelectedBKColor;
	UPROPERTY(EditAnywhere)							UMaterialInstance* SelectedImage;		//var() Material SelectedImage;
	UPROPERTY(EditAnywhere)							ETextAlign SectionJustification;		//var() GUI.eTextAlign SectionJustification;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles* OutlineStyle;				//var(Style) GUIStyles OutlineStyle;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles* SectionStyle;				//var(Style) GUIStyles SectionStyle;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles* SelectedStyle;				//var(Style) GUIStyles SelectedStyle;
	UPROPERTY(EditAnywhere, Category = "Style")		FString OutlineStyleName;				//var(Style) string OutlineStyleName;
	UPROPERTY(EditAnywhere, Category = "Style")		FString SectionStyleName;				//var(Style) string SectionStyleName;
	UPROPERTY(EditAnywhere, Category = "Style")		FString SelectedStyleName;				//var(Style) string SelectedStyleName;
	UPROPERTY(EditAnywhere)							UGUIScrollBarBase* MyScrollBar;			//var() GUIScrollBarBase MyScrollBar;
	UPROPERTY(EditAnywhere)							bool bAllowEmptyItems;					//var() bool bAllowEmptyItems;
	UPROPERTY(EditAnywhere)							bool bMultiSelect;						//var() bool bMultiSelect;
	UPROPERTY(EditAnywhere)							bool bInitializeList;					//var() bool bInitializeList;
	UPROPERTY(EditAnywhere)							bool bNotify;							//var() bool bNotify;
	UPROPERTY(EditAnywhere)							bool bVisibleWhenEmpty;					//var() bool bVisibleWhenEmpty;
	UPROPERTY(EditAnywhere)							bool bDrawSelectionBorder;				//var() bool bDrawSelectionBorder;
	UPROPERTY(EditAnywhere)							bool bHotTrackSound;					//var() bool bHotTrackSound;
	UPROPERTY(EditAnywhere)							bool bHotTrack;							//var() bool bHotTrack;
	UPROPERTY(EditAnywhere)							bool bSorted;							//var() bool bSorted;

	void OnScrollBy(UGUIComponent* Sender);
	void OnDrawItem(UCanvas* Canvas, int32 Item, float X, float Y, float W, float HT, bool bSelected, bool bPending);
	void OnAdjustTop(UGUIComponent* Sender);
	void OnTrack(UGUIComponent* Sender, int32 LastIndex);
	void CheckLinkedObjects(UGUIListBase* List);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Sort();
	int32 SilentSetIndex(int32 NewIndex);
	int32 CalculateIndex(bool bRequireValidIndex);
	int32 SetIndex(int32 NewIndex);
	void IndexChanged(UGUIComponent* Sender);
	void ClearPendingElements();
	void Clear();
	void MakeVisible(float Perc);
	void SetTopItem(int32 Item);
	int32 AddLinkObject(UGUIComponent* NewObj, bool bNoCheck);
	void InitLinkObjects(TArray<UGUIComponent*> NewObj, bool bNoCheck);
	void EnableLinkedObjects();
	void DisableLinkedObjects();
	bool IsValid();
	bool IsValidIndex(int32 i);
	FString AdditionalDebugString();
	FString getItemAtIndex(int32 idx);
	TArray<FString> GetPendingItems(bool bGuarantee);
	bool InternalOnKeyEvent(uint8& Key, uint8& KeyState, float Delta);
	bool Up();
	bool Down();
	bool MoveRight();
	bool MoveLeft();
	void WheelUp();
	void WheelDown();
	void PgUp();
	void PgDn();
	void home();
	void End();
	void InternalOnMousePressed(UGUIComponent* Sender, bool IsRepeat);
	void InternalOnMouseRelease(UGUIComponent* Sender);
	bool InternalOnBeginDrag(UGUIComponent* Sender);
	void CheckDragSelect();
	bool InternalOnRightClick(UGUIComponent* Sender);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	bool InternalOnDragDrop(UGUIComponent* Sender);
	void InternalOnDragOver(UGUIComponent* Sender);
	void InternalOnDragEnter(UGUIComponent* Sender);
	void InternalOnDragLeave(UGUIComponent* Sender);
	bool IsMultiSelect();
	void SetOutlineAlpha(int32 NewAlpha);

};
