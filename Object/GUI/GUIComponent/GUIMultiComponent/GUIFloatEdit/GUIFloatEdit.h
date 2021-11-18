// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIFloatEdit.generated.h"

class UGUISpinnerButton;
class UGUIEditBox;
class UGUILabel;
class UGUIController;
class UGUIComponent;

UCLASS()
class AA29_API UGUIFloatEdit : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIFloatEdit();

	UPROPERTY(EditAnywhere)			bool				bReadOnly;				//var() bool bReadOnly;
	UPROPERTY(EditAnywhere)			float				Step;					//var() float Step;
	UPROPERTY(EditAnywhere)			float				MaxValue;				//var() float MaxValue;
	UPROPERTY(EditAnywhere)			float				MinValue;				//var() float MinValue;
	UPROPERTY(EditAnywhere)			bool				bLeftJustified;			//var() bool bLeftJustified;
	UPROPERTY(EditAnywhere)			FString				Value;					//var() string Value;
	UPROPERTY(EditAnywhere)			UGUISpinnerButton*	MySpinner;				//var() GUISpinnerButton MySpinner;
	UPROPERTY(EditAnywhere)			UGUIEditBox*		MyEditBox;				//var() GUIEditBox MyEditBox;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetHint(FString NewHint);
	void CalcMaxLen();
	void SetValue(float V);
	bool SpinnerPlusClick(UGUIComponent* Sender);
	bool SpinnerMinusClick(UGUIComponent* Sender);
	bool EditKeyEvent(uint8& Key, uint8& State, float Delta);
	void CheckValue();
	void EditOnChange(UGUIComponent* Sender);
	void SetReadOnly(bool B);
	void SetFriendlyLabel(UGUILabel* NewLabel);
	void ValidateValue();

};
