// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AABrowser_PlayerServerSearchPane.generated.h"

class UGUIButton;
class UGUIComboBox;
class UmoCheckBox;
class UGUILabel;
class UGUIImage;

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_PlayerServerSearchPane : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAABrowser_PlayerServerSearchPane();

	UPROPERTY(EditAnywhere)							FString			ServerNameSearchHistory;			//var config string ServerNameSearchHistory;
	UPROPERTY(EditAnywhere)							FString			PlayerNameSearchHistory;			//var config string PlayerNameSearchHistory;
	UPROPERTY(EditAnywhere)							UGUIButton*		Search;								//var() XInterface.GUIButton Search;
	UPROPERTY(EditAnywhere)							UGUIComboBox*	SearchText;							//var() XInterface.GUIComboBox SearchText;
	UPROPERTY()										UmoCheckBox*	CurrentSearchType;					//var XInterface.moCheckBox CurrentSearchType;
	UPROPERTY(EditAnywhere)							UmoCheckBox*	ServerSearchType;					//var() XInterface.moCheckBox ServerSearchType;
	UPROPERTY(EditAnywhere)							UmoCheckBox*	PlayerSearchType;					//var() XInterface.moCheckBox PlayerSearchType;
	UPROPERTY(EditAnywhere)							UGUILabel*		SearchBy;							//var() XInterface.GUILabel SearchBy;
	UPROPERTY(EditAnywhere)							UGUIImage*		BackgroundBorder;					//var() XInterface.GUIImage BackgroundBorder;


	void OnSearch(FFilterItem filter);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetSearchHistoryText();
	void InternalOnSearchTypeChanged();
	void MakeFilter();
	bool InternalOnClick(UGUIComponent* Sender);
	bool IsInSearchHistory(FString SearchString);
	void UpdateAndSaveSearchHistories();
	void InternalOnChange(UGUIComponent* Sender);
	void testonly_GetPlayerSearchType();
	void testonly_GetServerSearchType();
	void testonly_GetSearchText();
	void testonly_GetSearch();
};
