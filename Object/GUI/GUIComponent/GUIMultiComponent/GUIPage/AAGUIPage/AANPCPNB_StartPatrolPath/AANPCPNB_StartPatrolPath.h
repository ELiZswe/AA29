// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AANPCPNB_StartPatrolPath.generated.h"

class UGUIButton;
class UGUILabel;
class UmoEditBox;

UCLASS()
class AA29_API UAANPCPNB_StartPatrolPath : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAANPCPNB_StartPatrolPath();

	UPROPERTY(EditAnywhere)		UGUIButton* guibtnCancel;				//var() automated XInterface.GUIButton guibtnCancel;
	UPROPERTY(EditAnywhere)		UGUILabel* guilTitle;					//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)		UmoEditBox* mebPatrolPathName;			//var() automated XInterface.moEditBox mebPatrolPathName;
	UPROPERTY(EditAnywhere)		UGUIButton* guibtnStartPatrolPath;		//var() automated XInterface.GUIButton guibtnStartPatrolPath;
	UPROPERTY()					bool		fCloseRequested;			//var bool fCloseRequested;
	UPROPERTY()					bool		bPlayerHUD;					//var bool bPlayerHUD;
		
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
};
