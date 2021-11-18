// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AANPCPNB_SavePNBFile.generated.h"

class UGUIButton;
class UGUILabel;
class UmoEditBox;

UCLASS()
class AA29_API UAANPCPNB_SavePNBFile : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAANPCPNB_SavePNBFile();

	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnCancel;			//var() automated XInterface.GUIButton guibtnCancel;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilTitle;				//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)		UmoEditBox*		mebSaveFileName;		//var() automated XInterface.moEditBox mebSaveFileName;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnSave;				//var() automated XInterface.GUIButton guibtnSave;
	UPROPERTY()					bool			fCloseRequested;		//var bool fCloseRequested;
	UPROPERTY()					bool			bPlayerHUD;				//var bool bPlayerHUD;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
};
