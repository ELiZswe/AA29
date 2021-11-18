// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUINumericEdit.generated.h"

class UGUIEditBox;
class UGUISpinnerButton;

UCLASS()
class AA29_API UGUINumericEdit : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUINumericEdit();

	UPROPERTY(EditAnywhere)						UGUIEditBox*			MyEditBox;					//var() automated GUIEditBox MyEditBox;
	UPROPERTY(EditAnywhere)						UGUISpinnerButton*		MySpinner;					//var() automated GUISpinnerButton MySpinner;
	UPROPERTY(EditAnywhere)						FString					Value;						//var() FString Value;
	UPROPERTY(EditAnywhere)						bool					bLeftJustified;				//var() bool bLeftJustified;
	UPROPERTY(EditAnywhere)						int32					MinValue;					//var() int32 MinValue;
	UPROPERTY(EditAnywhere)						int32					MaxValue;					//var() int32 MaxValue;
	UPROPERTY(EditAnywhere)						int32					Step;						//var() int32 Step;
	UPROPERTY(EditAnywhere)						bool					bReadOnly;					//var() bool bReadOnly;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CalcMaxLen();
	void SetValue(int32 V);
	bool SpinnerPlusClick(UGUIComponent* Sender);
	bool SpinnerMinusClick(UGUIComponent* Sender);
	bool EditKeyEvent(uint8& Key, uint8& State, float Delta);
	void EditOnChange(UGUIComponent* Sender);
	void SetHint(FString NewHint);
	void SetReadOnly(bool B);
	void CheckValue();
	void SetFriendlyLabel(UGUILabel* NewLabel);
	void ValidateValue();

};
