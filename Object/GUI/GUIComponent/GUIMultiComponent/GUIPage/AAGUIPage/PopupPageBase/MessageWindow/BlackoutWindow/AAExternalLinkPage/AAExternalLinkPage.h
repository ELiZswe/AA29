// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/BlackoutWindow.h"
#include "AAExternalLinkPage.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAAExternalLinkPage : public UBlackoutWindow
{
	GENERATED_BODY()
public:
	UAAExternalLinkPage();

	UPROPERTY(EditAnywhere)				UGUIButton*		YesButton;				//var() automated XInterface.GUIButton YesButton;
	UPROPERTY(EditAnywhere)				UGUIButton*		NoButton;				//var() automated XInterface.GUIButton NoButton;
	UPROPERTY(EditAnywhere)				UGUILabel*		LinkDesc;				//var() automated XInterface.GUILabel LinkDesc;
	UPROPERTY(EditAnywhere)				UGUILabel*		URLDesc;				//var() automated XInterface.GUILabel URLDesc;
	UPROPERTY(EditAnywhere)				FString			LinkURL;				//var FString LinkURL;

	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void HandleParameters(FString Param1, FString Param2);
	bool LaunchURL(UGUIComponent* Sender);
};
