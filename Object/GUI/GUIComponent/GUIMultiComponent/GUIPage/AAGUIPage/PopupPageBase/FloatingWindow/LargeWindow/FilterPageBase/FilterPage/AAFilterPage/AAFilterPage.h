// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/FilterPage.h"
#include "AAFilterPage.generated.h"

class UGUIImage;
class UGUIButton;
class UBrowserFilters;
class UmoCheckBox;
class UAAServerBrowser;
class UmoNumericEdit;
class UmoComboBox;
class UmoEditBox;
class UAABrowser_ServerListPageBase;

UCLASS(Config = Game)
class AA29_API UAAFilterPage : public UFilterPage
{
	GENERATED_BODY()
public:
	UAAFilterPage();

	UPROPERTY(EditAnywhere)				UGUIImage* i_OptionsFiltersBorder;				//var() automated XInterface.GUIImage i_OptionsFiltersBorder;
	UPROPERTY(EditAnywhere)				UGUIImage* i_ServerNameFiltersBorder;			//var() automated XInterface.GUIImage i_ServerNameFiltersBorder;
	UPROPERTY(EditAnywhere)				UGUIImage* i_PlayerNameFiltersBorder;			//var() automated XInterface.GUIImage i_PlayerNameFiltersBorder;
	UPROPERTY(EditAnywhere)				UGUIButton* bSaveFilter;						//var() automated XInterface.GUIButton bSaveFilter;
	UPROPERTY(EditAnywhere)				UGUIButton* bCancel;							//var() automated XInterface.GUIButton bCancel;
	UPROPERTY()							UBrowserFilters* FM;							//var BrowserFilters FM;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_FilterByOptions;				//var() automated XInterface.moCheckBox ch_FilterByOptions;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_FilterByServerName;				//var() automated XInterface.moCheckBox ch_FilterByServerName;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_FilterByPlayerName;				//var() automated XInterface.moCheckBox ch_FilterByPlayerName;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Full;							//var() automated XInterface.moCheckBox ch_Full;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Empty;							//var() automated XInterface.moCheckBox ch_Empty;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Official;						//var() automated XInterface.moCheckBox ch_Official;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Leased;							//var() automated XInterface.moCheckBox ch_Leased;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Password;						//var() automated XInterface.moCheckBox ch_Password;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_MILES;							//var() automated XInterface.moCheckBox ch_MILES;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Cheats;							//var() automated XInterface.moCheckBox ch_Cheats;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_PunkBuster;						//var() automated XInterface.moCheckBox ch_PunkBuster;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Tournament;						//var() automated XInterface.moCheckBox ch_Tournament;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_FilterHonorByMinMax;			//var() automated XInterface.moCheckBox ch_FilterHonorByMinMax;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_FilterHonorByAverage;			//var() automated XInterface.moCheckBox ch_FilterHonorByAverage;
	UPROPERTY(EditAnywhere)				UmoNumericEdit* nu_MinHonor;					//var() automated XInterface.moNumericEdit nu_MinHonor;
	UPROPERTY(EditAnywhere)				UmoNumericEdit* nu_MaxHonor;					//var() automated XInterface.moNumericEdit nu_MaxHonor;
	UPROPERTY(EditAnywhere)				UmoComboBox* co_Map;							//var() automated XInterface.moComboBox co_Map;
	UPROPERTY(EditAnywhere)				UmoComboBox* co_Country;						//var() automated XInterface.moComboBox co_Country;
	UPROPERTY(EditAnywhere)				UmoNumericEdit* nu_AverageHonor;				//var() automated XInterface.moNumericEdit nu_AverageHonor;
	UPROPERTY(EditAnywhere)				UmoComboBox* co_Tour;							//var() automated XInterface.moComboBox co_Tour;
	UPROPERTY(EditAnywhere)				UmoEditBox* ed_ServerName;						//var() automated XInterface.moEditBox ed_ServerName;
	UPROPERTY(EditAnywhere)				UmoEditBox* ed_PlayerName;						//var() automated XInterface.moEditBox ed_PlayerName;
	UPROPERTY()							TArray<FString> Countries;						//var localized TArray<FString> Countries;
	UPROPERTY(EditAnywhere,config)		FString sFilterBy;								//var() config FString sFilterBy;
	UPROPERTY(EditAnywhere, config)		bool bFilterHideFull;							//var() config bool bFilterHideFull;
	UPROPERTY(EditAnywhere, config)		bool bFilterHideEmpty;							//var() config bool bFilterHideEmpty;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowOfficial;						//var() config bool bFilterShowOfficial;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowLeased;							//var() config bool bFilterShowLeased;
	UPROPERTY(EditAnywhere, config)		bool bFilterHidePassword;						//var() config bool bFilterHidePassword;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowMiles;							//var() config bool bFilterShowMiles;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowCheat;							//var() config bool bFilterShowCheat;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowTournament;						//var() config bool bFilterShowTournament;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowPB;								//var() config bool bFilterShowPB;
	UPROPERTY(EditAnywhere, config)		FString sFilterHonorBy;							//var() config FString sFilterHonorBy;
	UPROPERTY(EditAnywhere, config)		int32 nFilterMinHonor;							//var() config int32 nFilterMinHonor;
	UPROPERTY(EditAnywhere, config)		int32 nFilterMaxHonor;							//var() config int32 nFilterMaxHonor;
	UPROPERTY(EditAnywhere, config)		int32 nFilterAverageHonor;						//var() config int32 nFilterAverageHonor;
	UPROPERTY(EditAnywhere, config)		FString sFilterMap;								//var() config FString sFilterMap;
	UPROPERTY(EditAnywhere, config)		FString sFilterCountry;							//var() config FString sFilterCountry;
	UPROPERTY(EditAnywhere, config)		FString sFilterTour;							//var() config FString sFilterTour;
	UPROPERTY(EditAnywhere, config)		FString sFilterServerName;						//var() config FString sFilterServerName;
	UPROPERTY(EditAnywhere, config)		FString sFilterPlayerName;						//var() config FString sFilterPlayerName;
	UPROPERTY(EditAnywhere, config)		FString sPassword;								//var() config FString sPassword;
	UPROPERTY()							UAAServerBrowser* Browser;						//var AAServerBrowser Browser;
	UPROPERTY()							UAABrowser_ServerListPageBase* BrowserPage;		//var AABrowser_ServerListPageBase BrowserPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadMapFilter(UGUIComponent* Sender, FString S);
	void LoadTourFilter();
	void LoadCountryFilter();
	void ActivateFilterHonorByMinMax();
	void ActivateFilterHonorByAverage();
	void ActivateFilterByOptions();
	void DisableOptionsFilters();
	void ActivateFilterByServerName();
	void ActivateFilterByPlayerName();
	void InternalOnChange(UGUIComponent* Sender);
	void SwapMinMaxHonorValues();
	void InternalOnMinMaxDeactivate();
	void SaveUserSelections();
	bool InternalOnClick(UGUIComponent* guicSender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	int32 GetTourIndexByName(FString TourName);
	void BuildFilterList();
	void SaveSettings();
	void ResetClicked();
	void ResetFilterToShowStandardServers();
};
