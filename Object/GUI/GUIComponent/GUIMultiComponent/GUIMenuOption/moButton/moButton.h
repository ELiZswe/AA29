// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "moButton.generated.h"

class UGUIButton;

UCLASS()
class AA29_API UmoButton : public UGUIMenuOption
{
	GENERATED_BODY()
public:
	UmoButton();

	UPROPERTY(EditAnywhere, Category = "Option")						FString				Value;				//var(Option) FString Value;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				ButtonCaption;				//var(Option) localized FString ButtonCaption;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				MenuTitle;				//var(Option) localized FString MenuTitle;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				MenuClass;				//var(Option) FString MenuClass;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				ButtonStyleName;				//var(Option) FString ButtonStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUIButton*			MyButton;				//var(Option) editconst noexport GUIButton MyButton;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void SetValue(FString NewValue);
	void ResetComponent();
	bool InternalOnClick(UGUIComponent* Sender);
	void PageClosed(bool bCancelled);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);

};
