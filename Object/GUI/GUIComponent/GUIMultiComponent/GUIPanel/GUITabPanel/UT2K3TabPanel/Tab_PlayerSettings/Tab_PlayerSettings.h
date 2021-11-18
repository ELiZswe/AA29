// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_PlayerSettings.generated.h"

class ASpinnyWeap;

UCLASS()
class AA29_API UTab_PlayerSettings : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_PlayerSettings();

	UPROPERTY()			TArray<FString>			HandNames;				//var localized FString HandNames[4];
	UPROPERTY()			TArray<FString>			TeamNames;				//var localized FString TeamNames[2];
	UPROPERTY()			bool					bUnlocked;				//var config bool bUnlocked;
	UPROPERTY()			bool					bChanged;				//var bool bChanged;
	UPROPERTY()			ASpinnyWeap*			SpinnyDude;				//var SpinnyWeap SpinnyDude;
	UPROPERTY()			FVector					SpinnyDudeOffset;		//var Vector SpinnyDudeOffset;
	UPROPERTY()			bool					bRenderDude;			//var bool bRenderDude;
	UPROPERTY()			FString					ShowBioCaption;			//var localized FString ShowBioCaption;
	UPROPERTY()			FString					Show3DViewCaption;		//var localized FString Show3DViewCaption;
	UPROPERTY()			FString					OriginalTeam;			//var FString OriginalTeam;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void UpdateSpinnyDude();
	bool InternalDraw(UCanvas* Canvas);
	bool Playlist(UGUIComponent* Sender);
	bool Toggle3DView(UGUIComponent* Sender);
	bool NextAnim(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void TeamChange(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalApply(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
};
