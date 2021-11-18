// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIImageStateButtonGroup.generated.h"

class UGUIImageStateButton;

UCLASS()
class AA29_API UGUIImageStateButtonGroup : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIImageStateButtonGroup();




	UPROPERTY()					UGUIImageStateButton*							SelectedButton;				//var GUIImageStateButton SelectedButton;
	UPROPERTY(EditAnywhere)		TArray<UGUIImageStateButton*>					Buttons;					//var() editconstarray editconst array<GUIImageStateButton> Buttons;


	void OnSelectionChanged(int32 NewIndex);
	void AddButton(UGUIImageStateButton* Button);
	void Clear();
	bool ButtonClick(UGUIComponent* Sender);
	void SetSelection(UGUIImageStateButton* B);
	UGUIImageStateButton* GetSelection();
	void GetSelectionExtra();

};
