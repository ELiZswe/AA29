// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "GUIGFXButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIGFXButton : public UGUIButton
{
	GENERATED_BODY()
public:
	UGUIGFXButton();

	UPROPERTY()														bool bChecked;								//var bool bChecked;
	UPROPERTY(EditAnywhere)											bool bClientBound;							//var() bool bClientBound;
	UPROPERTY(EditAnywhere)											bool bCheckBox;								//var() bool bCheckBox;
	UPROPERTY(EditAnywhere)											EIconPosition Position;						//var() GUI.eIconPosition Position;
	UPROPERTY(EditAnywhere)											UMaterialInstance* Graphic;					//var() Material Graphic;
	UPROPERTY(EditAnywhere)											int32 ImageIndex;							//var() int ImageIndex;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetChecked(bool bNewChecked);
	bool InternalOnClick(UGUIComponent* Sender);
};
