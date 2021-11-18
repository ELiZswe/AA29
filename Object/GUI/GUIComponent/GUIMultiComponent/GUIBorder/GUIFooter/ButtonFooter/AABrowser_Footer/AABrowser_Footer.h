// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/ButtonFooter.h"
#include "AABrowser_Footer.generated.h"

class UGUITitleBar;
class UGUIButton;
class UmoCheckBox;
class UAAServerBrowser;
class UAABrowser_Page;


UCLASS()
class AA29_API UAABrowser_Footer : public UButtonFooter
{
	GENERATED_BODY()
public:
	UAABrowser_Footer();

	UPROPERTY(EditAnywhere)				UAAServerBrowser*	p_Anchor;				//var AAServerBrowser p_Anchor;
	UPROPERTY(EditAnywhere)				UmoCheckBox*		ch_PunkBuster;			//var() XInterface.moCheckBox ch_PunkBuster;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_IconKey;				//var() XInterface.GUIButton b_IconKey;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_Filter;				//var() XInterface.GUIButton b_Filter;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_Refresh;				//var() XInterface.GUIButton b_Refresh;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_Back;					//var() XInterface.GUIButton b_Back;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_Spectate;				//var() XInterface.GUIButton b_Spectate;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_Join;					//var() XInterface.GUIButton b_Join;
	UPROPERTY(EditAnywhere)				UGUITitleBar*		t_StatusBar;			//var() XInterface.GUITitleBar t_StatusBar;


	bool InternalOnClick(UGUIComponent* Sender);
	void UpdateActiveButtons(UAABrowser_Page* CurrentPanel);
	void UpdateButtonState(UGUIButton* But, bool Active);
	void PositionButtons(UCanvas* C);
	float GetButtonLeft();

};
