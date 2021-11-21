// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIStateButtonGroup.generated.h"

class UGUIStateButton;

UCLASS()
class AA29_API UGUIStateButtonGroup : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIStateButtonGroup();

	UPROPERTY(EditAnywhere)			TArray<UGUIStateButton*>	Buttons;			//var() editconstarray editconst TArray<GUIStateButton> Buttons;
	UPROPERTY()						UGUIStateButton*			SelectedButton;		//var GUIStateButton SelectedButton;

	void OnSelectionChanged(int32 NewIndex);
	void AddButton(UGUIStateButton* Button);
	void Clear();
	bool ButtonClick(UGUIComponent* Sender);
	void SetSelection(UGUIStateButton* B);
	UGUIStateButton* GetSelection();
	FString GetSelectionExtra();
};
