// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATeamGamePanel.h"
#include "AAScorePanel.generated.h"

class UAAGUITabControl;
class UGUIImage;
class UGUIButton;
class USettings_Tabs;

UCLASS()
class AA29_API UAAScorePanel : public UAATeamGamePanel
{
	GENERATED_BODY()
public:
	UAAScorePanel();

	UPROPERTY(EditAnywhere)				UAAGUITabControl*	c_Tabs;				//var() automated AAGUITabControl c_Tabs;
	UPROPERTY(EditAnywhere)				UGUIImage*			i_Background;		//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)				TArray<FString>		PanelClasses;		//var TArray<FString> PanelClasses;
	UPROPERTY(EditAnywhere)				TArray<FString>		PanelCaptions;		//var localized TArray<FString> PanelCaptions;
	UPROPERTY(EditAnywhere)				TArray<FString>		PanelHints;			//var localized TArray<FString> PanelHints;
	UPROPERTY(EditAnywhere)				bool				bApplyImmediately;	//var() config bool bApplyImmediately;
	UPROPERTY(EditAnywhere)				float				SavedPitch;			//var() editconst noexport float SavedPitch;
	UPROPERTY(EditAnywhere)				FString				PageCaption;		//var() FString PageCaption;
	UPROPERTY(EditAnywhere)				UGUIButton*			SizingButton;		//var() XInterface.GUIButton SizingButton;
	UPROPERTY(EditAnywhere)				USettings_Tabs*		ActivePanel;		//var() Settings_Tabs ActivePanel;
	UPROPERTY(EditAnywhere)				FString				InvalidStats;		//var localized FString InvalidStats;
	UPROPERTY(EditAnywhere)				int32				LastTeamID;			//var int32 LastTeamID;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Param1, FString Param2);
	bool GetRestoreParams(FString& Param1, FString& Param2);
	bool ButtonClicked(UGUIComponent* Sender);
	bool InternalOnPreDraw(UCanvas* C);
	FString Lower(FString Text);
};
