// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moNumericEdit.generated.h"

class UGUINumericEdit;

UCLASS()
class AA29_API UmoNumericEdit : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoNumericEdit();

	UPROPERTY(EditAnywhere, Category = "Option")						int32				MinValue;				//var(Option) int32 MinValue;
	UPROPERTY(EditAnywhere, Category = "Option")						int32				MaxValue;				//var(Option) int32 MaxValue;
	UPROPERTY(EditAnywhere, Category = "Option")						int32				Step;					//var(Option) int32 Step;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUINumericEdit*	MyNumericEdit;			//var(Option) editconst noexport GUINumericEdit MyNumericEdit;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void SetValue(int32 V);
	int32 GetValue();
	void Setup(int32 NewMin, int32 NewMax, int32 NewStep);
	void SetReadOnly(bool B);
	
};
