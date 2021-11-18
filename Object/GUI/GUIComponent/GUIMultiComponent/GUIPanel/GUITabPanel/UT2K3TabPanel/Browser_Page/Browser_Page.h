// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Browser_Page.generated.h"

class UServerBrowser;

UCLASS()
class AA29_API UBrowser_Page : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UBrowser_Page();

	UPROPERTY()		UServerBrowser*	Browser;						//var ServerBrowser Browser;
	UPROPERTY()		FString			StartQueryString;				//var localized FString StartQueryString;
	UPROPERTY()		FString			AuthFailString;					//var localized FString AuthFailString;
	UPROPERTY()		FString			ConnFailString;					//var localized FString ConnFailString;
	UPROPERTY()		FString			ConnTimeoutString;				//var localized FString ConnTimeoutString;
	UPROPERTY()		FString			QueryCompleteString;			//var localized FString QueryCompleteString;
	UPROPERTY()		FString			RefreshCompleteString;			//var localized FString RefreshCompleteString;
	UPROPERTY()		FString			ReadyString;					//var localized FString ReadyString;
	UPROPERTY()		FString			PageCaption;					//var localized FString PageCaption;

	void OnCloseBrowser();
};
