// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moFloatEdit.generated.h"

class UGUIFloatEdit;

UCLASS()
class AA29_API UmoFloatEdit : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoFloatEdit();

	UPROPERTY(EditAnywhere, Category = "Option")						float				MinValue;				//var(Option) float MinValue;
	UPROPERTY(EditAnywhere, Category = "Option")						float				MaxValue;				//var(Option) float MaxValue;
	UPROPERTY(EditAnywhere, Category = "Option")						float				Step;					//var(Option) float Step;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUIFloatEdit*		MyNumericEdit;			//var(Option) editconst noexport GUIFloatEdit MyNumericEdit;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void SetValue(float V);
	float GetValue();
	void Setup(float NewMin, float NewMax, float NewStep);
	void SetReadOnly(bool B);

};
