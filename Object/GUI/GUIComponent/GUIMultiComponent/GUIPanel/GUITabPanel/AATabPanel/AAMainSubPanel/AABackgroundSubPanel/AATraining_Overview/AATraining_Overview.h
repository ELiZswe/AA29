// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AATraining_Overview.generated.h"

class UGUIContentBox;
class UNMLContent;

UCLASS()
class AA29_API UAATraining_Overview : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAATraining_Overview();

	UPROPERTY(EditAnywhere)			UGUIContentBox*		guicbPanel;			//var() automated GUIContentBox guicbPanel;
	UPROPERTY()						UNMLContent*		MyNML;				//var NMLContent MyNML;
	UPROPERTY()						FString				DefaultPage;		//var FString DefaultPage;
	UPROPERTY()						bool				bHasLeftPage;		//var bool bHasLeftPage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);
	void TrainingNMLPreParser(FString& TrainingNML);
	void GreyOutImages(FString& NMLChunk, FString aTag, bool bDoGreyOut);
};
