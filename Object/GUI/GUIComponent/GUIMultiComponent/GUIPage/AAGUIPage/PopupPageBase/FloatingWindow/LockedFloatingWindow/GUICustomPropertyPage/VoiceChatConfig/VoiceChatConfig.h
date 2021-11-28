// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUICustomPropertyPage.h"
#include "VoiceChatConfig.generated.h"

//class AVoiceChatReplicationInfo;
class UmoEditBox;
class UGUIButton;
class UmoSlider;
class UmoCheckBox;
class UmoComboBox;

UCLASS()
class AA29_API UVoiceChatConfig : public UGUICustomPropertyPage
{
	GENERATED_BODY()
public:
	UVoiceChatConfig();

	UPROPERTY(EditAnywhere)		UmoEditBox*						ed_ChatPassword;		//var() automated XInterface.moEditBox ed_ChatPassword;
	UPROPERTY(EditAnywhere)		UGUIButton*						b_QuickBinds;			//var() automated XInterface.GUIButton b_QuickBinds;
	UPROPERTY(EditAnywhere)		UmoEditBox*						ed_Active;				//var() automated XInterface.moEditBox ed_Active;
	UPROPERTY(EditAnywhere)		UmoSlider*						sl_VoiceVol;			//var() automated XInterface.moSlider sl_VoiceVol;
	UPROPERTY(EditAnywhere)		UmoCheckBox*					ch_AJPublic;			//var() automated XInterface.moCheckBox ch_AJPublic;
	UPROPERTY(EditAnywhere)		UmoCheckBox*					ch_AJLocal;				//var() automated XInterface.moCheckBox ch_AJLocal;
	UPROPERTY(EditAnywhere)		UmoCheckBox*					ch_AJTeam;				//var() automated XInterface.moCheckBox ch_AJTeam;
	UPROPERTY(EditAnywhere)		UmoCheckBox*					ch_AutoSpeak;			//var() automated XInterface.moCheckBox ch_AutoSpeak;
	UPROPERTY(EditAnywhere)		UmoComboBox*					co_Quality;				//var() automated XInterface.moComboBox co_Quality;
	UPROPERTY(EditAnywhere)		UmoComboBox*					co_LANQuality;			//var() automated XInterface.moComboBox co_LANQuality;
	UPROPERTY()					bool							bAJPublic;				//var bool bAJPublic;
	UPROPERTY()					bool							bAJLocal;				//var bool bAJLocal;
	UPROPERTY()					bool							bAJTeam;				//var bool bAJTeam;
	UPROPERTY()					bool							bAutoSpeak;				//var bool bAutoSpeak;
	UPROPERTY()					FString							sPwd;					//var FString sPwd;
	UPROPERTY()					FString							sCodec;					//var FString sCodec;
	UPROPERTY()					FString							sLANCodec;				//var FString sLANCodec;
	UPROPERTY()					FString							sActive;				//var FString sActive;
	UPROPERTY()					FString							QuickBindMenu;			//var FString QuickBindMenu;
	UPROPERTY()					float							fVoice;					//var float fVoice;
	//UPROPERTY()					AVoiceChatReplicationInfo*		VoiceChatClass;			//var class<VoiceChatReplicationInfo> VoiceChatClass;
	UPROPERTY()					FString							VoiceChatClassName;		//var FString VoiceChatClassName;
	UPROPERTY()					TArray<FString>					InstalledCodecs;		//var TArray<FString> InstalledCodecs;
	UPROPERTY()					FString							KeyNameCaption;			//var localized FString KeyNameCaption;
	UPROPERTY()					FString							ResetCaption;			//var localized FString ResetCaption;
	UPROPERTY()					FString							ResetHint;				//var localized FString ResetHint;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool ResetClick(UGUIComponent* Sender);
};
