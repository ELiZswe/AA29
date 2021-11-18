// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_Overview.generated.h"

class UGUIContentBox;
class UNMLContent;

UCLASS()
class AA29_API UAADeploy_Overview : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_Overview();

	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;				//var() automated GUIContentBox guicbPanel;
	UPROPERTY()						FString				DefaultPage;			//var FString DefaultPage;
	UPROPERTY()						UNMLContent*		MyNML;					//var NMLContent MyNML;
	UPROPERTY()						bool				bHasLeftPage;			//var bool bHasLeftPage;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);

};
