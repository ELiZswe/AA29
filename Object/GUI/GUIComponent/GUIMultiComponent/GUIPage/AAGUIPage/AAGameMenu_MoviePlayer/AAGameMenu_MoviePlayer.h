// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAGameMenu_MoviePlayer.generated.h"

class UGUIImage;
class UGUIButton;
class UGUIImageButton;
class UGUILabel;
class UGUISlider;

UCLASS()
class AA29_API UAAGameMenu_MoviePlayer : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAGameMenu_MoviePlayer();


	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgMoviePlayerTexture;		//var() automated XInterface.GUIImage guiimgMoviePlayerTexture;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnClose;					//var() automated XInterface.GUIButton guibtnClose;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnRewindMovie;				//var() automated XInterface.GUIButton guibtnRewindMovie;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnFastForwardMovie;			//var() automated XInterface.GUIButton guibtnFastForwardMovie;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnPlayMovie;				//var() automated XInterface.GUIButton guibtnPlayMovie;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnStopMovie;				//var() automated XInterface.GUIButton guibtnStopMovie;
	UPROPERTY(EditAnywhere)			UGUIButton*			guibtnPauseMovie;				//var() automated XInterface.GUIButton guibtnPauseMovie;
	UPROPERTY(EditAnywhere)			UGUIImageButton*	guibtnVolumeIcon;				//var() automated GUIImageButton guibtnVolumeIcon;
	UPROPERTY(EditAnywhere)			UGUILabel*			guilTitle;						//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)			UGUILabel*			guilCaption;					//var() automated XInterface.GUILabel guilCaption;
	UPROPERTY(EditAnywhere)			UGUILabel*			guilCounter;					//var() automated XInterface.GUILabel guilCounter;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgTitleBar;					//var() automated XInterface.GUIImage guiimgTitleBar;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgBackground;				//var() automated XInterface.GUIImage guiimgBackground;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgCaptionBackground;		//var() automated XInterface.GUIImage guiimgCaptionBackground;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgBorderTop;				//var() automated XInterface.GUIImage guiimgBorderTop;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgBorderBottom;				//var() automated XInterface.GUIImage guiimgBorderBottom;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgBorderLeft;				//var() automated XInterface.GUIImage guiimgBorderLeft;
	UPROPERTY(EditAnywhere)			UGUIImage*			guiimgBorderRight;				//var() automated XInterface.GUIImage guiimgBorderRight;
	UPROPERTY()						bool				bPauseButtonPressed;			//var bool bPauseButtonPressed;
	UPROPERTY()						bool				bPlayerHUD;						//var bool bPlayerHUD;
	UPROPERTY()						bool				bIsMuted;						//var bool bIsMuted;
	UPROPERTY()						bool				bHasBeenPlayedOnce;				//var bool bHasBeenPlayedOnce;
	UPROPERTY()						bool				bIsInterview;					//var bool bIsInterview;
	UPROPERTY()						float				fpMovieVolume;					//var float fpMovieVolume;
	UPROPERTY()						float				fpSavedMovieVolume;				//var float fpSavedMovieVolume;
	UPROPERTY()						float				fMovieTime;						//var float fMovieTime;
	UPROPERTY()						UMaterialInstance*	texVolumeIcon;					//var Texture texVolumeIcon;
	UPROPERTY()						UMaterialInstance*	texVolumeIconMute;				//var Texture texVolumeIconMute;
	UPROPERTY()						UMaterialInstance*	MovieToPlay;					//var MovieTexture MovieToPlay;
	UPROPERTY(EditAnywhere)			UGUISlider*			guisVolume;						//var() automated XInterface.GUISlider guisVolume;
	UPROPERTY(EditAnywhere)			UGUISlider*			guisScrubber;					//var() automated XInterface.GUISlider guisScrubber;
	UPROPERTY()						float				iLastTimeFFPressed;				//var float iLastTimeFFPressed;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void ScrubberOnMousePressed(UGUIComponent* Sender, bool bRepeat);
	void ScrubberOnMouseReleased(UGUIComponent* Sender);
	FString SecondsToString(float Seconds);
	void Timer();
	void HandleParameters(FString Param1, FString Param2);
};
