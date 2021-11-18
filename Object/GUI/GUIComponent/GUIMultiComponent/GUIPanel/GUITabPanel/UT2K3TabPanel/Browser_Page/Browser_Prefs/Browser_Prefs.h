// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Page.h"
#include "Browser_Prefs.generated.h"

class UGUITitleBar;

UCLASS()
class AA29_API UBrowser_Prefs : public UBrowser_Page
{
	GENERATED_BODY()
public:
	UBrowser_Prefs();

	UPROPERTY()					UGUITitleBar*		StatusBar;				//var GUITitleBar StatusBar;
	UPROPERTY()					TArray<FString>		ViewStatsStrings;		//var localized FString ViewStatsStrings[3];
	UPROPERTY()					TArray<FString>		MutatorModeStrings;		//var localized FString MutatorModeStrings[4];
	UPROPERTY()					TArray<FString>		WeaponStayStrings;		//var localized FString WeaponStayStrings[3];
	UPROPERTY()					TArray<FString>		TranslocatorStrings;	//var localized FString TranslocatorStrings[3];
	UPROPERTY()					bool				bIsInitialised;			//var bool bIsInitialised;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool BackClick(UGUIComponent* Sender);
	void UpdateMutatorVisibility();
	bool InternalShowIconKey(UGUIComponent* Sender);
	void MyOnLoadINI(UGUIComponent* Sender, FString S);
	void MyOnChange(UGUIComponent* Sender);
};
