// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "PopupPageBase.generated.h"

class UFloatingImage;

UCLASS(Config = Game)
class AA29_API UPopupPageBase : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UPopupPageBase();

	UPROPERTY(EditAnywhere)									UFloatingImage* i_FrameBG;		//var() automated XInterface.FloatingImage i_FrameBG;
	UPROPERTY()												bool bFading;					//var bool bFading;
	UPROPERTY()												bool bClosing;					//var bool bClosing;
	UPROPERTY(EditAnywhere, Category = "Fade", config)		float FadeTime;					//var(Fade) config float FadeTime;
	UPROPERTY(EditAnywhere, Category = "Fade")				float CurFadeTime;				//var(Fade) float CurFadeTime;
	UPROPERTY(EditAnywhere, Category = "Fade")				uint8 CurFade;					//var(Fade) uint8 CurFade;
	UPROPERTY(EditAnywhere, Category = "Fade")				uint8 DesiredFade;				//var(Fade) uint8 DesiredFade;

	void FadedIn();
	void FadedOut();
	void Opened(UGUIComponent* Sender);
	bool InternalOnPreDraw(UCanvas* C);
	void FadeIn();
	void FadeOut();
};
