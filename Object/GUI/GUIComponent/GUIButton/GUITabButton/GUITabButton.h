// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "GUITabButton.generated.h"

class UGUITabPanel;

class UGUIComponent;
UCLASS()
class UGUITabButton : public UGUIButton
{
	GENERATED_BODY()
public:
	UGUITabButton();

	UPROPERTY()					bool			bForceFlash;						//var bool bForceFlash;
	UPROPERTY()					bool			bActive;							//var bool bActive;
	UPROPERTY()					UGUITabPanel*	MyPanel;							//var GUITabPanel MyPanel;

	void SetFocus(UGUIComponent* Who);
	bool ChangeActiveState(bool IsActive, bool bFocusPanel);
	bool CanShowPanel();
};
