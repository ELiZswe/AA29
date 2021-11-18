// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/MessageWindow.h"
#include "AAFavoritesOperationModalDialog.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAAFavoritesOperationModalDialog : public UMessageWindow
{
	GENERATED_BODY()
public:
	UAAFavoritesOperationModalDialog();

	UPROPERTY(EditAnywhere)			UGUILabel* l_Text;					//var() automated XInterface.GUILabel l_Text;
	UPROPERTY(EditAnywhere)			UGUILabel* l_Text2;					//var() automated XInterface.GUILabel l_Text2;
	UPROPERTY()						float MinimumAppearanceDuration;	//var float MinimumAppearanceDuration;
	UPROPERTY()						float AppearanceDuration;			//var float AppearanceDuration;
	UPROPERTY()						bool CloseRequested;				//var bool CloseRequested;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Close;				//var() automated XInterface.GUIButton b_Close;

	void HandleParameters(FString Param1, FString Param2);
	void InternalOnOpen();
	void InternalOnTimer(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnCanClose(bool Cancelled);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);

};
