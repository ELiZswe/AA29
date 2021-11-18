// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIComboBox.generated.h"

class UGUIListBox;
class UGUIScrollButtonBase;
class UGUIEditBox;
class UGUIList;
class UGUILabel;

UCLASS()
class AA29_API UGUIComboBox : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIComboBox();

	UPROPERTY(EditAnywhere)				UGUIListBox*			MyListBox;						//var() GUIListBox MyListBox;
	UPROPERTY(EditAnywhere)				UGUIScrollButtonBase*	MyShowListBtn;					//var() GUIScrollButtonBase MyShowListBtn;
	UPROPERTY(EditAnywhere)				UGUIEditBox*			Edit;							//var() GUIEditBox Edit;
	UPROPERTY(EditAnywhere)				UGUIList*				List;							//var() editconst GUIList List;
	UPROPERTY(EditAnywhere)				FString					TextStr;						//var() editconst string TextStr;
	UPROPERTY(EditAnywhere)				int32					Index;							//var() editconst int Index;
	UPROPERTY(EditAnywhere)				int32					MaxVisibleItems;				//var() int MaxVisibleItems;
	UPROPERTY(EditAnywhere)				bool					bShowListOnFocus;				//var() bool bShowListOnFocus;
	UPROPERTY(EditAnywhere)				bool					bIgnoreChangeWhenTyping;		//var() bool bIgnoreChangeWhenTyping;
	UPROPERTY(EditAnywhere)				bool					bValueReadOnly;					//var() bool bValueReadOnly;
	UPROPERTY(EditAnywhere)				bool					bReadOnly;						//var() bool bReadOnly;

	void OnShowList();
	void OnHideList();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetHint(FString NewHint);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void InternalListDeActivate();
	void InternalOnInvalidate(UGUIComponent* Who);
	void InternalEditPressed(UGUIComponent* Sender, bool bRepeat);
	bool InternalListClick(UGUIComponent* Sender);
	void InternalOnSaveINI(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void HideListBox();
	void SetVisibility(bool bIsVisible);
	bool ShowListBox(UGUIComponent* Sender);
	void ItemChanged(UGUIComponent* Sender);
	void TextChanged(UGUIComponent* Sender);
	void SetText(FString NewText, bool bListItemsOnly);
	void SetExtra(FString NewExtra, bool bListItemsOnly);
	void Get();
	void GetText();
	void GetObject();
	FString GetExtra();
	void SetIndex(int32 i);
	void GetIndex();
	void addItem(FString Item, UObject* Extra, FString str);
	void RemoveItem(int32 Item, int32 Count);
	void GetItem(int32 Index);
	void GetItemObject(int32 Index);
	void Find(FString Text, bool bExact, bool bExtra);
	void FindExtra(FString Text, bool bExact);
	void FindIndex(FString Test, bool bExact, bool bExtra, UObject* obj);
	void ItemCount();
	void ReadOnly(bool B);
	void InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat);
	void Clear();
	void CenterMouse();
	void SetFriendlyLabel(UGUILabel* NewLabel);
	void LoseFocus(UGUIComponent* Sender);
	bool FocusFirst(UGUIComponent* Sender);
	bool FocusLast(UGUIComponent* Sender);

};
