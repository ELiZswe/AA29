// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moComboBox.generated.h"

class UGUIComboBox;

UCLASS()
class AA29_API UmoComboBox : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoComboBox();

	UPROPERTY(EditAnywhere, Category = "Option")						bool			bReadOnly;					//var(Option) bool bReadOnly;
	UPROPERTY(EditAnywhere, Category = "Option")						bool			bAlwaysNotify;				//var(Option) bool bAlwaysNotify;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUIComboBox*	MyComboBox;					//var(Option) editconst noexport GUIComboBox MyComboBox;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	int32 ItemCount();
	void SetIndex(int32 i);
	void SilentSetIndex(int32 i);
	int32 GetIndex();
	int32 FindIndex(FString Test, bool bExact, bool bExtra, UObject* obj);
	FString Find(FString Test, bool bExact, bool bExtra);
	int32 FindExtra(FString Test, bool bExact);
	void addItem(FString Item, UObject* Extra, FString str);
	void RemoveItem(int32 Item, int32 Count);
	FString GetItem(int32 Index);
	UObject* GetItemObject(int32 Index);
	FString GetText();
	UObject* GetObject();
	FString GetExtra();
	void SetText(FString NewText, bool bListItemsOnly);
	void SetExtra(FString NewExtra, bool bListItemsOnly);
	void ReadOnly(bool B);
	void SetReadOnly(bool B);
	void ResetComponent();
	bool FocusFirst(UGUIComponent* Sender);
	void Sort();
	
};
