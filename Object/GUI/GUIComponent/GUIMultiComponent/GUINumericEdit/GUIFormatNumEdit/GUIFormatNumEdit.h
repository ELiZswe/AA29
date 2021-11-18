// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUINumericEdit/GUINumericEdit.h"
#include "GUIFormatNumEdit.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIFormatNumEdit : public UGUINumericEdit
{
	GENERATED_BODY()
public:
	UGUIFormatNumEdit();

	UPROPERTY()						bool				bUnformated;						//var bool bUnformated;

	FString FormatValue(int32 NewValue);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CalcMaxLen();
	void EditOnChange(UGUIComponent* Sender);
	void ValidateValue();
	void ValueToFormat();
	void FormatToValue();
	void SetValue(int32 V);
	bool SpinnerPlusClick(UGUIComponent* Sender);
	bool SpinnerMinusClick(UGUIComponent* Sender);

};
