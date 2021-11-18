// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AAGUIController.generated.h"

class AHttpLink;
UCLASS()
class AA29_API UAAGUIController : public UGUIController
{
	GENERATED_BODY()
public:
	UAAGUIController();

	UPROPERTY()											bool bPlayedSplashMovieOnce;						//var bool bPlayedSplashMovieOnce;
	UPROPERTY()											bool bReceivedNewTours;								//var bool bReceivedNewTours;
	UPROPERTY()											int32 Port;											//var int Port;
	UPROPERTY()											FString Server;										//var string Server;
	UPROPERTY()											AHttpLink* GlobalNMLQueue;							//var IpDrv.HttpLink GlobalNMLQueue;
	UPROPERTY()											bool bWaitForConsole;								//var bool bWaitForConsole;
	UPROPERTY()											FString RememberAuthFailMessage;					//var string RememberAuthFailMessage;
	UPROPERTY()											bool bLoggedIn;										//var bool bLoggedIn;
	UPROPERTY()											bool bFilterNoSniper;								//var bool bFilterNoSniper;
	UPROPERTY()											bool bFilterMilesOnly;								//var bool bFilterMilesOnly;
	UPROPERTY()											bool bFilterNoBlood;								//var bool bFilterNoBlood;
	UPROPERTY()											bool bFilterLanguage;								//var bool bFilterLanguage;
	UPROPERTY()											bool bHideMouseCursor;								//var bool bHideMouseCursor;
	UPROPERTY()											TArray<FString> MainMenuPanelOptions;				//var array<String> MainMenuPanelOptions;

	void LaunchURL(FString URL);
	void ReturnToMainMenu();
	//void SetFocusTo(FloatingWindow Menu);
	void ReceivedToursText(FString Filename, FString TextChunk);
	void InitializeController();
	void PrecachePlayerRecords();
	//UGUIPage* CreateMenu(FString NewMenuName);
	bool OpenMenu(FString NewMenuName, FString Param1, FString Param2);
	void Validate();
	void GetEntryPage();
	void GetLoginPage();
	void GetPreLoginPage();
	void GetPostLoginPage();
	void GetMainMenuPage();
	void GetQuitPage();
	void GetExitPage();
	void GetLogoutPage();
	void AddComponentClass(FString ClassName);
	void PurgeComponentClasses();
	void ValidatePanels();
	void GetPersonnelJacketPanel();
	void GetRecordBriefPanel();
	void GetTrainingPanel();
	void GetDeploymentPanel();
	void GetMultiplayerPanel();
	void GetServerBrowserPanel();
	void GetRealHeroesPanel();
	void GetExplorePanel();
	void GetWeaponsPanel();
	void GetSettingsPanel();
	void GetSupportPanel();
	void GetParentalControlsPanel();
	void GetCreditsPanel();
	void GetExitPanel();
	void GetQuitPanel();
	bool LoggedIn();
	void EnableMenus(bool bEnable);
	FString URLDivider();
	void OpenExternalLink(FString RealURL, FString Description, FString DisplayURL);
	void ReplaceExternalLink(FString RealURL, FString Description, FString DisplayURL);
	void InteractionChanged(UInteraction* Changed, bool bOpen);
	void LoadTextFromFile(FString Filename);
	void NotifyDCDSDownload(FString AssetName);
	void NotifyLevelChange();

};
