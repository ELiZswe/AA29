// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moEditBox.generated.h"

class UGUIEditBox;

UCLASS()
class AA29_API UmoEditBox : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoEditBox();

	UPROPERTY(EditAnywhere, Category = "Option")						bool				bMaskText;				//var(Option) bool bMaskText;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bReadOnly;				//var(Option) bool bReadOnly;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUIEditBox*		MyEditBox;				//var(Option) editconst noexport GUIEditBox MyEditBox;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	FString GetText();
	void SetText(FString NewText);
	void ReadOnly(bool B);
	void SetReadOnly(bool B);
	void IntOnly(bool B);
	void FloatOnly(bool B);
	void MaskText(bool B);
};
