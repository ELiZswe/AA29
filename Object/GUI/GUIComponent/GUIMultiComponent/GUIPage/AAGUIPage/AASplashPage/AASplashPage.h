// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AASplashPage.generated.h"

class UBackgroundImage;
class UGUIImage;
class UAAGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAASplashPage : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAASplashPage();

	UPROPERTY(EditAnywhere)			UBackgroundImage*	i_Background;				//var() automated XInterface.BackgroundImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImage*			iAALogo;					//var() automated XInterface.GUIImage iAALogo;
	UPROPERTY(EditAnywhere)			UAAGUILabel*		lVersion;					//var() automated AAGUILabel lVersion;
	UPROPERTY(EditAnywhere)			UAAGUILabel*		lDisclaimer;				//var() automated AAGUILabel lDisclaimer;
	UPROPERTY(EditAnywhere)			UGUIImage*			iArmyStar;					//var() automated XInterface.GUIImage iArmyStar;
	UPROPERTY(EditAnywhere)			UGUIImage*			iESRBLogo;					//var() automated XInterface.GUIImage iESRBLogo;
	UPROPERTY()						bool				bAllowClose;				//var bool bAllowClose;
	UPROPERTY()						float				fDisplayTime;				//var float fDisplayTime;
	UPROPERTY()						float				fElapsedTime;				//var float fElapsedTime;
	UPROPERTY()						FString				EntryPage;					//var FString EntryPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Timer();
	bool internalKeyEvent(uint8& Key, uint8& State, float Delta);
	bool CanClose(bool bCancelled);
	void InternalOnOpen();
	void InternalOnClose(bool bCanceled);
};
