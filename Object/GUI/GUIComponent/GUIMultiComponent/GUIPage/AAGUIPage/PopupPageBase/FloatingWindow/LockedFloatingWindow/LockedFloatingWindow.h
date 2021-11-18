// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "LockedFloatingWindow.generated.h"

class UGUISectionBackground;
class UGUIButton;

UCLASS()
class AA29_API ULockedFloatingWindow : public UFloatingWindow
{
	GENERATED_BODY()
public:
	ULockedFloatingWindow();

	UPROPERTY(EditAnywhere)		UGUISectionBackground*	sb_Main;		//var() automated XInterface.GUISectionBackground sb_Main;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Cancel;		//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_OK;			//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		FString					SubCaption;		//var() localized FString SubCaption;
	UPROPERTY(EditAnywhere)		TArray<float>			EdgeBorder;		//var() float EdgeBorder[4];

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	void AlignButtons();

};
