// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moSlider.generated.h"

class UGUISlider;

UCLASS()
class AA29_API UmoSlider : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoSlider();

	UPROPERTY(EditAnywhere, Category = "Option")						float				MaxValue;						//var(Option) float MaxValue;
	UPROPERTY(EditAnywhere, Category = "Option")						float				MinValue;						//var(Option) float MinValue;
	UPROPERTY(EditAnywhere, Category = "Option")						float				Value;							//var(Option) float Value;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bIntSlider;						//var(Option) bool bIntSlider;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				SliderStyleName;				//var(Option) FString SliderStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				SliderCaptionStyleName;			//var(Option) FString SliderCaptionStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				SliderBarStyleName;				//var(Option) FString SliderBarStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUISlider*			MySlider;						//var(Option) editconst noexport GUISlider MySlider;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void Adjust(float Amount);
	void SetValue(float NewV);
	float GetValue();
	void Setup(float MinV, float MaxV, bool bInt);
	void InternalOnChange(UGUIComponent* Sender);
	void SetReadOnly(bool B);
};
