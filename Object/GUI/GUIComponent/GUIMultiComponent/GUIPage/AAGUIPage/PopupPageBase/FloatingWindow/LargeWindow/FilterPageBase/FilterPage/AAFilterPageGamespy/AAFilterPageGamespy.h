// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/FilterPage.h"
#include "AAFilterPageGamespy.generated.h"

class UGUIImage;
class UGUIMultiOptionListBox;
class UGUIMultiOptionList;
class UGUIButton;
class UBrowserFilters;
class UmoCheckBox;
class UmoNumericEdit;
class UmoComboBox;
class UAAServerBrowser;
class UAABrowser_ServerListPageBase;

UCLASS(Config = Game)
class AA29_API UAAFilterPageGamespy : public UFilterPage
{
	GENERATED_BODY()
public:
	UAAFilterPageGamespy();

	UPROPERTY(EditAnywhere)				UGUIImage* i_Background;							//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)				UGUIButton* b_Create;								//var() automated XInterface.GUIButton b_Create;
	UPROPERTY(EditAnywhere)				UGUIButton* b_Remove;								//var() automated XInterface.GUIButton b_Remove;
	UPROPERTY(EditAnywhere)				UGUIButton* b_Edit;									//var() automated XInterface.GUIButton b_Edit;
	UPROPERTY(EditAnywhere)				UGUIButton* b_OK;									//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)				UGUIButton* b_Cancel;								//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)				UGUIMultiOptionListBox* lb_Filters;					//var() automated XInterface.GUIMultiOptionListBox lb_Filters;
	UPROPERTY(EditAnywhere)				UGUIMultiOptionList* li_Filters;					//var XInterface.GUIMultiOptionList li_Filters;
	UPROPERTY(EditAnywhere)				UGUIButton* bSaveFilter;							//var() automated XInterface.GUIButton bSaveFilter;
	UPROPERTY(EditAnywhere)				UGUIButton* bCancel;								//var() automated XInterface.GUIButton bCancel;
	UPROPERTY(EditAnywhere)				UBrowserFilters* FM;								//var BrowserFilters FM;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Full;								//var() automated XInterface.moCheckBox ch_Full;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Empty;								//var() automated XInterface.moCheckBox ch_Empty;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Official;							//var() automated XInterface.moCheckBox ch_Official;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Leased;								//var() automated XInterface.moCheckBox ch_Leased;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Password;							//var() automated XInterface.moCheckBox ch_Password;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_MILES;								//var() automated XInterface.moCheckBox ch_MILES;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Cheats;								//var() automated XInterface.moCheckBox ch_Cheats;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_PunkBuster;							//var() automated XInterface.moCheckBox ch_PunkBuster;
	UPROPERTY(EditAnywhere)				UmoCheckBox* ch_Tournament;							//var() automated XInterface.moCheckBox ch_Tournament;
	UPROPERTY(EditAnywhere)				UmoNumericEdit* nu_MinHonor;						//var() automated XInterface.moNumericEdit nu_MinHonor;
	UPROPERTY(EditAnywhere)				UmoNumericEdit* nu_MaxHonor;						//var() automated XInterface.moNumericEdit nu_MaxHonor;
	UPROPERTY(EditAnywhere)				UmoComboBox* co_Map;								//var() automated XInterface.moComboBox co_Map;
	UPROPERTY(EditAnywhere, config)		bool bFilterHideFull;								//var() config bool bFilterHideFull;
	UPROPERTY(EditAnywhere, config)		bool bFilterHideEmpty;								//var() config bool bFilterHideEmpty;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowOfficial;							//var() config bool bFilterShowOfficial;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowLeased;								//var() config bool bFilterShowLeased;
	UPROPERTY(EditAnywhere, config)		bool bFilterHidePassword;							//var() config bool bFilterHidePassword;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowMiles;								//var() config bool bFilterShowMiles;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowCheat;								//var() config bool bFilterShowCheat;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowTournament;							//var() config bool bFilterShowTournament;
	UPROPERTY(EditAnywhere, config)		bool bFilterShowPB;									//var() config bool bFilterShowPB;
	UPROPERTY(EditAnywhere, config)		int32 nFilterMinHonor;								//var() config int32 nFilterMinHonor;
	UPROPERTY(EditAnywhere, config)		int32 nFilterMaxHonor;								//var() config int32 nFilterMaxHonor;
	UPROPERTY(EditAnywhere, config)		FString sFilterMap;									//var() config FString sFilterMap;
	UPROPERTY(EditAnywhere, config)		FString sPassword;									//var() config FString sPassword;
	UPROPERTY()							UAAServerBrowser* Browser;							//var AAServerBrowser Browser;
	UPROPERTY()							UAABrowser_ServerListPageBase* BrowserPage;			//var AABrowser_ServerListPageBase BrowserPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadMapFilter(UGUIComponent* Sender, FString S);
	void SwapMinMaxHonorValues();
	void InternalOnChange(UGUIComponent* Sender);
	void InternalOnMinMaxDeactivate();
	void SaveUserSelections();
	bool InternalOnClick(UGUIComponent* guicSender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void BuildFilterString();
	FString NeedAnd(FString sFilter);
	void SaveSettings();
	void ResetClicked();
	void ResetFilterToShowStandardServers();
};
