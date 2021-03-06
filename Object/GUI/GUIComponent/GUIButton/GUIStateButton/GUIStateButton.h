// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "GUIStateButton.generated.h"

UCLASS()
class UGUIStateButton : public UGUIButton
{
	GENERATED_BODY()
public:
	UGUIStateButton();

	UPROPERTY(EditAnywhere)			FString		SelectedStyleName;		//var() FString SelectedStyleName;
	UPROPERTY()						FString		ExtraData;				//var FString ExtraData;

	void SetSelected(bool bSelected);
};
