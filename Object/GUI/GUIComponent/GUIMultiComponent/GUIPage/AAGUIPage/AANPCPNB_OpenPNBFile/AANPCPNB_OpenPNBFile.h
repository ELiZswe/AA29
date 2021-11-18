// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AANPCPNB_OpenPNBFile.generated.h"

class UGUIButton;
class UGUILabel;
class UGUIListBox;

/**
 * 
 */
UCLASS()
class AA29_API UAANPCPNB_OpenPNBFile : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAANPCPNB_OpenPNBFile();

	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnCancel;				//var() automated XInterface.GUIButton guibtnCancel;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilTitle;					//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)		UGUIListBox*	guilbAvailableFiles;		//var() automated XInterface.GUIListBox guilbAvailableFiles;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnOpen;					//var() automated XInterface.GUIButton guibtnOpen;
	UPROPERTY()					bool			fCloseRequested;			//var bool fCloseRequested;
	UPROPERTY()					bool			bPlayerHUD;					//var bool bPlayerHUD;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
};
