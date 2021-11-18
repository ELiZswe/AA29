// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AANPCPNB_FiringNodeOptions.generated.h"

class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAANPCPNB_FiringNodeOptions : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAANPCPNB_FiringNodeOptions();


	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnClose;				//var() automated XInterface.GUIButton guibtnClose;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilTitle;					//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY()					bool			fCloseRequested;			//var bool fCloseRequested;
	UPROPERTY()					bool			bPlayerHUD;					//var bool bPlayerHUD;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);

};
