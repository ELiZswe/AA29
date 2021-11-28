// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "GUIImageButton.generated.h"

UCLASS()
class AA29_API UGUIImageButton : public UGUIImage
{
	GENERATED_BODY()
public:
	UGUIImageButton();

	UPROPERTY(EditAnywhere)										FString link;						//var() localized string link;
	UPROPERTY(EditAnywhere)										FString Caption;					//var() localized string Caption;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
