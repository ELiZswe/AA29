// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2SP_LadderEventPage.generated.h"

class UGUILabel;
class UGUIImage;
class UGUIButton;

UCLASS()
class AA29_API UUT2SP_LadderEventPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2SP_LadderEventPage();

	UPROPERTY()					UGUILabel*			lblTitle;			//var GUILabel lblTitle;
	UPROPERTY()					UGUILabel*			lblCaption;			//var GUILabel lblCaption;
	UPROPERTY()					UGUIImage*			gImage;				//var GUIImage gImage;
	UPROPERTY()					UGUIButton*			btnOK;				//var GUIButton btnOK;
	UPROPERTY()					UGUIButton*			btnMap;				//var GUIButton btnMap;
	UPROPERTY()					FString				TutorialName;		//var FString TutorialName;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void SetTutorialName(FString tutname);
};
