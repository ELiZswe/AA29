// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2SettingsPage.generated.h"

class UTab_WeaponPref;
class UTab_PlayerSettings;
class UTab_NetworkSettings;

UCLASS()
class AA29_API UUT2SettingsPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2SettingsPage();

	UPROPERTY()					FString					VideoTabLabel;				//var localized FString VideoTabLabel;
	UPROPERTY()					FString					VideoTabHint;				//var localized FString VideoTabHint;
	UPROPERTY()					FString					DetailsTabLabel;			//var localized FString DetailsTabLabel;
	UPROPERTY()					FString					DetailsTabHint;				//var localized FString DetailsTabHint;
	UPROPERTY()					FString					AudioTabLabel;				//var localized FString AudioTabLabel;
	UPROPERTY()					FString					AudioTabHint;				//var localized FString AudioTabHint;
	UPROPERTY()					FString					PlayerTabLabel;				//var localized FString PlayerTabLabel;
	UPROPERTY()					FString					PlayerTabHint;				//var localized FString PlayerTabHint;
	UPROPERTY()					FString					NetworkTabLabel;			//var localized FString NetworkTabLabel;
	UPROPERTY()					FString					NetworkTabHint;				//var localized FString NetworkTabHint;
	UPROPERTY()					FString					ControlsTabLabel;			//var localized FString ControlsTabLabel;
	UPROPERTY()					FString					ControlsTabHint;			//var localized FString ControlsTabHint;
	UPROPERTY()					FString					IForceTabLabel;				//var localized FString IForceTabLabel;
	UPROPERTY()					FString					IForceTabHint;				//var localized FString IForceTabHint;
	UPROPERTY()					FString					WeaponsTabLabel;			//var localized FString WeaponsTabLabel;
	UPROPERTY()					FString					WeaponsTabHint;				//var localized FString WeaponsTabHint;
	UPROPERTY()					FString					GameTabLabel;				//var localized FString GameTabLabel;
	UPROPERTY()					FString					GameTabHint;				//var localized FString GameTabHint;
	UPROPERTY()					FString					HudTabLabel;				//var localized FString HudTabLabel;
	UPROPERTY()					FString					HudTabHint;					//var localized FString HudTabHint;
	UPROPERTY()					FString					SpeechBinderTabLabel;		//var localized FString SpeechBinderTabLabel;
	UPROPERTY()					FString					SpeechBinderTabHint;		//var localized FString SpeechBinderTabHint;
	UPROPERTY()					UTab_WeaponPref*		pWeaponPref;				//var Tab_WeaponPref pWeaponPref;
	UPROPERTY()					UTab_PlayerSettings*	pPlayer;					//var Tab_PlayerSettings pPlayer;
	UPROPERTY()					UTab_NetworkSettings*	pNetwork;					//var Tab_NetworkSettings pNetwork;
	UPROPERTY()					float					SavedPitch;					//var float SavedPitch;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void TabChange(UGUIComponent* Sender);
	void ChangeHint(FString NewHint);
	void InternalOnReOpen();
	bool ButtonClicked(UGUIComponent* Sender);
	bool InternalOnCanClose(bool bCanceled);
	bool NotifyLevelChange();
	void InternalOnClose(bool bCanceled);
};
