// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AAGUIPanelHideable.generated.h"

class UGUIButton;
class UGUIComponent;

UCLASS()
class AA29_API UAAGUIPanelHideable : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAAGUIPanelHideable();

	UPROPERTY()							bool			LeftSideHidden;			//var bool LeftSideHidden;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_Show;					//var() XInterface.GUIButton b_Show;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_Hide;					//var() XInterface.GUIButton b_Hide;
	UPROPERTY(EditAnywhere)				UGUIComponent*	rightside;				//var() UGUIComponent* rightside;
	UPROPERTY(EditAnywhere)				UGUIComponent*	leftside;				//var() UGUIComponent* leftside;

	void OnHide();
	void OnExpand();
	void OnShow();
	void OnContract();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetVisibility(bool bIsVisible);
	bool InternalOnClick(UGUIComponent* Sender);

};
