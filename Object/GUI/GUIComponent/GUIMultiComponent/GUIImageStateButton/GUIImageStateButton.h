// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIImageStateButton.generated.h"

class UGUILabel;
class UGUIGFXButton;

UCLASS()
class AA29_API UGUIImageStateButton : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIImageStateButton();

	UPROPERTY(EditAnywhere)			UGUILabel*				Label;						//var() XInterface.GUILabel Label;
	UPROPERTY(EditAnywhere)			UGUIGFXButton*			ImageButton;				//var() XInterface.GUIGFXButton ImageButton;
	UPROPERTY()						FString					ExtraData;					//var string ExtraData;
	UPROPERTY(EditAnywhere)			UMaterialInstance*		Image;						//var() Material Image;
	UPROPERTY(EditAnywhere)			FString					Caption;					//var() localized string Caption;
	UPROPERTY(EditAnywhere)			float					LabelHeight;				//var() float LabelHeight;
	UPROPERTY(EditAnywhere)			FString					ImageSelStyleName;			//var() string ImageSelStyleName;
	UPROPERTY(EditAnywhere)			FString					ImageStyleName;				//var() string ImageStyleName;
	UPROPERTY(EditAnywhere)			FString					LabelSelStyleName;			//var() string LabelSelStyleName;
	UPROPERTY(EditAnywhere)			FString					LabelStyleName;				//var() string LabelStyleName;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetSelected(bool bSelected);
	bool InternalOnPreDraw(UCanvas* Canvas);
	bool ButtonClick(UGUIComponent* Sender);
};
