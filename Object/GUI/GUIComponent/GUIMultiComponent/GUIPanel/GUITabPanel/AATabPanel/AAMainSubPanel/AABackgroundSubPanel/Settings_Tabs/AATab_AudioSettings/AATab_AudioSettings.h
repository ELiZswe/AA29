// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_AudioSettings.generated.h"

class UmoSlider;
class UmoComboBox;
class UmoCheckBox;
class UmoButton;
class UGUIImageButton;
class UGUILabel;

UCLASS()
class AA29_API UAATab_AudioSettings : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_AudioSettings();

	UPROPERTY()						TArray<FString>		AudioModes;								//var localized FString AudioModes[4];
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_MusicVol;							//var() automated XInterface.moSlider sl_MusicVol;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_EffectsVol;							//var() automated XInterface.moSlider sl_EffectsVol;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_VoiceVol;							//var() automated XInterface.moSlider sl_VoiceVol;
	UPROPERTY(EditAnywhere)			UmoSlider*			sl_TTS;									//var() automated XInterface.moSlider sl_TTS;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Mode;								//var() automated XInterface.moComboBox co_Mode;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_MessageBeep;							//var() automated XInterface.moCheckBox ch_MessageBeep;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_TTSIRC;								//var() automated XInterface.moCheckBox ch_TTSIRC;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_OnlyTeamTTS;							//var() automated XInterface.moCheckBox ch_OnlyTeamTTS;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_MatureTaunts;						//var() automated XInterface.moCheckBox ch_MatureTaunts;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_LowDetail;							//var() automated XInterface.moCheckBox ch_LowDetail;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_Default;								//var() automated XInterface.moCheckBox ch_Default;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_TTS;									//var() automated XInterface.moCheckBox ch_TTS;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_VoiceChat;							//var() automated XInterface.moCheckBox ch_VoiceChat;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		mchkbDisableESSIntroduction;			//var() automated XInterface.moCheckBox mchkbDisableESSIntroduction;
	UPROPERTY(EditAnywhere)			UmoButton*			b_VoiceChat;							//var() automated XInterface.moButton b_VoiceChat;
	UPROPERTY(EditAnywhere)			UGUIImageButton*	ib_Dolby;								//var() automated GUIImageButton ib_Dolby;
	UPROPERTY(EditAnywhere)			UGUIImageButton*	ib_EAX;									//var() automated GUIImageButton ib_EAX;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_Dolby;								//var() automated XInterface.GUILabel l_Dolby;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_EAX;									//var() automated XInterface.GUILabel l_EAX;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_TTS;									//var() automated XInterface.GUILabel l_TTS;
	UPROPERTY()						float				fMusic;									//var float fMusic;
	UPROPERTY()						float				fEffects;								//var float fEffects;
	UPROPERTY()						float				fTTS;									//var float fTTS;
	UPROPERTY()						int32				iVoice;									//var int32 iVoice;
	UPROPERTY()						int32				iMode;									//var int32 iMode;
	UPROPERTY()						int32				iVoiceMode;								//var int32 iVoiceMode;
	UPROPERTY()						int32				iCommo;									//var int32 iCommo;
	UPROPERTY()						FString				sCommo;									//var FString sCommo;
	UPROPERTY()						bool				bRev;									//var bool bRev;
	UPROPERTY()						bool				bBeep;									//var bool bBeep;
	UPROPERTY()						bool				bAuto;									//var bool bAuto;
	UPROPERTY()						bool				bMature;								//var bool bMature;
	UPROPERTY()						bool				bLow;									//var bool bLow;
	UPROPERTY()						bool				bCompat;								//var bool bCompat;
	UPROPERTY()						bool				b3DSound;								//var bool b3DSound;
	UPROPERTY()						bool				bEAX;									//var bool bEAX;
	UPROPERTY()						bool				bDefault;								//var bool bDefault;
	UPROPERTY()						bool				bTTS;									//var bool bTTS;
	UPROPERTY()						bool				bTTSIRC;								//var bool bTTSIRC;
	UPROPERTY()						bool				bOnlyTeamTTS;							//var bool bOnlyTeamTTS;
	UPROPERTY()						bool				bVoiceChat;								//var bool bVoiceChat;
	UPROPERTY()						bool				guicbPbDisableESSIntroductionanel;		//var bool bDisableESSIntroduction;
	UPROPERTY()						FString				VoiceChatConfigMenu;					//var config FString VoiceChatConfigMenu;
	UPROPERTY()						FString				sCannotChangeAudioDetails;				//var localized FString sCannotChangeAudioDetails;
	UPROPERTY()						FString				sCannotChangeAudioTitle;				//var localized FString sCannotChangeAudioTitle;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ResetClicked();
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	void SaveSettings();
	bool ButtonClick(UGUIComponent* Sender);
};
