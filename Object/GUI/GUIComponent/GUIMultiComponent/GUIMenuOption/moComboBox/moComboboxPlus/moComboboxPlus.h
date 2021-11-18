// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "moComboboxPlus.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UmoComboboxPlus : public UmoComboBox
{
	GENERATED_BODY()
public:
	UmoComboboxPlus();

	UPROPERTY()						FString				ExtraCompClass;				//var FString ExtraCompClass;
	UPROPERTY()						UGUIComponent*		ExtraComp;					//var GUIComponent ExtraComp;
	UPROPERTY()						float				ExtraCompSize;				//var float ExtraCompSize;
	UPROPERTY()						TArray<FString>		ExtraData;					//var TArray<FString> ExtraData;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void InternalOnChange(UGUIComponent* Sender);
	void SetExtraValue(int32 i, FString Data);
	void UpdateExtraValue(int32 i);
	void addItem(FString Item, UObject* Extra, FString str);
	void RemoveItem(int32 Item, int32 Count);
	bool InternalOnPreDraw(UCanvas* C);

};
