// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAGameMenu_CommandPost.generated.h"

class UGUITabControl;
class UGUIButton;
class UGUIPanel;

UCLASS()
class AA29_API UAAGameMenu_CommandPost : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAGameMenu_CommandPost();

	UPROPERTY(EditAnywhere)			UGUITabControl*		guitcCommandPostPanels;			//var() automated XInterface.GUITabControl guitcCommandPostPanels;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnClose;					//var() automated XInterface.GUIButton guibtnClose;
	UPROPERTY(EditAnywhere)			UGUILabel*			guilTitle;						//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY()						bool				fCloseRequested;				//var bool fCloseRequested;
	UPROPERTY()						int32				iMaxPanels;						//var int32 iMaxPanels;
	UPROPERTY()						TArray<FString>		PanelClasses;					//var FString PanelClasses[6];
	UPROPERTY()						TArray<FString>		PanelCaptions;					//var localized FString PanelCaptions[6];
	UPROPERTY()						TArray<FString>		PanelHints;						//var localized FString PanelHints[6];
	UPROPERTY()						TArray<UGUIPanel*>	aaguipPanels;					//var XInterface.GUIPanel aaguipPanels[6];
	UPROPERTY()						bool				bPlayerHUD;						//var bool bPlayerHUD;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool IsAdmin();
	void OnOpen();
	void NotifyCommandPostPage(FString sPanelName, FString sParam1, FString sParam2, FString sParam3);
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void SwitchPanel(int32 NewPanel);
	void HandleParameters(FString Param1, FString Param2);
};
