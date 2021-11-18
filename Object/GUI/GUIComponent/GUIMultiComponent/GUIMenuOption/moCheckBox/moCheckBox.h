// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moCheckBox.generated.h"

class UGUICheckBoxButton;

UCLASS()
class AA29_API UmoCheckBox : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoCheckBox();

	UPROPERTY(EditAnywhere, Category = "Option")						FString					CheckStyleName;				//var(Option) FString CheckStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUICheckBoxButton*		MyCheckBox;					//var(Option) editconst noexport GUICheckBoxButton MyCheckBox;
	UPROPERTY(EditAnywhere, Category = "Option")						bool					bChecked;					//var(Option) editconst noexport deprecated bool bChecked;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner); 
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void ResetComponent();
	bool IsChecked();
	bool Checked(bool C);
	void ButtonChecked(UGUIComponent* Sender);
	bool InternalClick(UGUIComponent* Sender);
};
