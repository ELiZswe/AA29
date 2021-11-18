// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGenericMessageBox.h"
#include "AAVideoChangeOK.generated.h"

class UGUIButton;

UCLASS()
class AA29_API UAAVideoChangeOK : public UAAGenericMessageBox
{
	GENERATED_BODY()
public:
	UAAVideoChangeOK();


	UPROPERTY()				int32			Count;					//var() transient noexport int32 Count;
	UPROPERTY()				FString			RevertString;			//var() transient noexport FString RevertString;
	UPROPERTY()				FString			RestoreText;			//var() localized FString RestoreText;
	UPROPERTY()				FString			SecondText;				//var() localized FString SecondText;
	UPROPERTY()				FString			SecondsText;			//var() localized FString SecondsText;
	UPROPERTY()				FString			OverrideResNotice;		//var() FString OverrideResNotice;
	UPROPERTY()				UGUIButton*		b_Cancel;				//var() automated XInterface.GUIButton b_Cancel;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void Execute(FString DesiredRes);
	void ToggleFullScreen();
	void ChangeResolution(FString DesiredRes);
	void SetDevice(FString NewRenderDevice);
	void DeferChangeOnClose(bool bCancelled);
	void StartTimer();
	void Timer();
	bool InternalOnClick(UGUIComponent* Sender);
};
