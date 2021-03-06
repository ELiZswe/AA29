// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AAGUIController.generated.h"

class AHttpLink;
class UFloatingWindow;
class UGUIComponent;
class UGUIPage;
class UInteraction;

UCLASS()
class UAAGUIController : public UGUIController
{
	GENERATED_BODY()
public:
	UAAGUIController();

	UPROPERTY()				bool			bPlayedSplashMovieOnce;			//var bool bPlayedSplashMovieOnce;
	UPROPERTY()				bool			bReceivedNewTours;				//var bool bReceivedNewTours;
	UPROPERTY()				int32			Port;							//var int Port;
	UPROPERTY()				FString			Server;							//var string Server;
	UPROPERTY()				AHttpLink*		GlobalNMLQueue;					//var IpDrv.HttpLink GlobalNMLQueue;
	UPROPERTY()				bool			bWaitForConsole;				//var bool bWaitForConsole;
	UPROPERTY()				FString			RememberAuthFailMessage;		//var string RememberAuthFailMessage;
	UPROPERTY()				bool			bLoggedIn;						//var bool bLoggedIn;
	UPROPERTY()				bool			bFilterNoSniper;				//var bool bFilterNoSniper;
	UPROPERTY()				bool			bFilterMilesOnly;				//var bool bFilterMilesOnly;
	UPROPERTY()				bool			bFilterNoBlood;					//var bool bFilterNoBlood;
	UPROPERTY()				bool			bFilterLanguage;				//var bool bFilterLanguage;
	UPROPERTY()				bool			bHideMouseCursor;				//var bool bHideMouseCursor;
	UPROPERTY()				TArray<FString> MainMenuPanelOptions;			//var TArray<FString> MainMenuPanelOptions;

	void LaunchURL(FString URL);
	void ReturnToMainMenu();
	bool SetFocusTo(UFloatingWindow* Menu);
	void ReceivedToursText(FString Filename, FString TextChunk);
	void InitializeController();
	void PrecachePlayerRecords();
	UGUIPage* CreateMenu(FString NewMenuName);
	bool OpenMenu(FString NewMenuName, FString Param1, FString Param2);
	void Validate();
	FString GetEntryPage();
	FString GetLoginPage();
	FString GetPreLoginPage();
	FString GetPostLoginPage();
	FString GetMainMenuPage();
	FString GetQuitPage();
	FString GetExitPage();
	FString GetLogoutPage();
	UGUIComponent* AddComponentClass(FString ClassName);
	void PurgeComponentClasses();
	void ValidatePanels();
	FString GetPersonnelJacketPanel();
	FString GetRecordBriefPanel();
	FString GetTrainingPanel();
	FString GetDeploymentPanel();
	FString GetMultiplayerPanel();
	FString GetServerBrowserPanel();
	FString GetRealHeroesPanel();
	FString GetExplorePanel();
	FString GetWeaponsPanel();
	FString GetSettingsPanel();
	FString GetSupportPanel();
	FString GetParentalControlsPanel();
	FString GetCreditsPanel();
	FString GetExitPanel();
	FString GetQuitPanel();
	bool LoggedIn();
	void EnableMenus(bool bEnable);
	FString URLDivider();
	void OpenExternalLink(FString RealURL, FString Description, FString DisplayURL);
	void ReplaceExternalLink(FString RealURL, FString Description, FString DisplayURL);
	void InteractionChanged(UInteraction* Changed, bool bOpen);
	FString LoadTextFromFile(FString Filename);
	void NotifyDCDSDownload(FString AssetName);
	void NotifyLevelChange();

};
