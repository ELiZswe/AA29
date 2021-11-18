// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIPage : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIPage();

	UPROPERTY(EditAnywhere)						bool					bRenderWorld;					//var() bool bRenderWorld;
	UPROPERTY(EditAnywhere)						bool					bPauseIfPossible;				//var() bool bPauseIfPossible;
	UPROPERTY(EditAnywhere)						bool					bCheckResolution;				//var() bool bCheckResolution;
	UPROPERTY(EditAnywhere)						bool					bCaptureInput;					//var() bool bCaptureInput;
	UPROPERTY(EditAnywhere)						bool					bRequire640x480;				//var() bool bRequire640x480;
	UPROPERTY(EditAnywhere)						bool					bPersistent;					//var() bool bPersistent;
	UPROPERTY(EditAnywhere)						bool					bDisconnectOnOpen;				//var() bool bDisconnectOnOpen;
	UPROPERTY(EditAnywhere)						bool					bAllowedAsLast;					//var() bool bAllowedAsLast;
	UPROPERTY(EditAnywhere)						bool					bRestorable;					//var() bool bRestorable;
	UPROPERTY(EditAnywhere)						UMaterialInstance*		ParentPage;						//var() editconst noexport GUIPage ParentPage;
	UPROPERTY(EditAnywhere)						UMaterialInstance*		Background;						//var() Material Background;
	UPROPERTY(EditAnywhere)						FColor					BackgroundColor;				//var() Color BackgroundColor;
	UPROPERTY(EditAnywhere)						FColor					InactiveFadeColor;				//var() Color InactiveFadeColor;
	UPROPERTY(EditAnywhere)						USoundBase*				OpenSound;						//var() Sound OpenSound;
	UPROPERTY(EditAnywhere)						USoundBase*				CloseSound;						//var() Sound CloseSound;
	UPROPERTY(EditAnywhere)						TArray<UGUIComponent*>	Timers;							//var() const editconstarray editconst noexport TArray<GUIComponent> Timers;
	UPROPERTY(EditAnywhere)						EMenuRenderStyle		BackgroundRStyle;				//var() GUI.EMenuRenderStyle BackgroundRStyle;

	void NotifyCommandPostPage(FString sPanelName, FString sParam1, FString sParam2, FString sParam3);
	void NotifyStatsPage(FString sStatRequested, FString sValue);
	void OnOpen();
	void OnReOpen();
	void OnClose(bool bCancelled);
	bool OnCanClose(bool bCancelled);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void PlayOpenSound();
	void PlayCloseSound();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void CheckResolution(bool Closing, UGUIController* InController);
	void ChangeHint(FString NewHint);
	void SetFocus(UGUIComponent* Who);
	void HandleParameters(FString Param1, FString Param2);
	bool GetRestoreParams(FString& Param1, FString& Param2);
	void HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2);
	FString GetDataString();
	void SetDataString(FString str);
	bool NotifyLevelChange();
	void Free();
	bool IsOpen();
	bool AllowOpen(FString MenuClass);
};
