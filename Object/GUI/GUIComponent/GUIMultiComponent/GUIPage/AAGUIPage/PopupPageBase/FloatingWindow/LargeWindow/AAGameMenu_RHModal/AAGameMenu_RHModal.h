// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAGameMenu_RHModal.generated.h"

class UGUIButton;
class UGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_RHModal : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAGameMenu_RHModal();

	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnPlayNow;			//var() automated XInterface.GUIButton guibtnPlayNow;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnWatchInterview;	//var() automated XInterface.GUIButton guibtnWatchInterview;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnWatchMOS;			//var() automated XInterface.GUIButton guibtnWatchMOS;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnClose;			//var() automated XInterface.GUIButton guibtnClose;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilblHeader;			//var() automated XInterface.GUILabel guilblHeader;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilblMyName;			//var() automated XInterface.GUILabel guilblMyName;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilblChooseOption;		//var() automated XInterface.GUILabel guilblChooseOption;
	UPROPERTY(EditAnywhere)		UGUIImage*		guiimgBackground;		//var() automated XInterface.GUIImage guiimgBackground;
	UPROPERTY(EditAnywhere)		UGUIImage*		guiimgBGFade;			//var() automated XInterface.GUIImage guiimgBGFade;
	UPROPERTY()					FString			InterviewMovie;			//var FString InterviewMovie;
	UPROPERTY()					FString			MOSMovie;				//var FString MOSMovie;
	UPROPERTY()					bool			bPlayerHUD;				//var bool bPlayerHUD;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
	void SilenceRealHeroes();
	void AddSystemMenu();
	bool SystemMenuPreDraw(UCanvas* Canvas);
	bool XButtonClicked(UGUIComponent* Sender);
};
