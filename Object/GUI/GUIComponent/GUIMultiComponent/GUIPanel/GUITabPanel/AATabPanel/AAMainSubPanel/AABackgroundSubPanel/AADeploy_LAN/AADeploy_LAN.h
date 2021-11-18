// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_LAN.generated.h"

class UAABrowser_ServersPlayersRulesPan;
class UAABrowser_UpdateJoinAndPBPanel;
class UGUILabel;
class UGUIEditBox;
class UGUIImage;
/**
 * 
 */
UCLASS()
class AA29_API UAADeploy_LAN : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_LAN();


	UPROPERTY(EditAnywhere)			UAABrowser_ServersPlayersRulesPan*	ServersPlayersRulesPanel;				//var() automated AABrowser_ServersPlayersRulesPan ServersPlayersRulesPanel;
	UPROPERTY(EditAnywhere)			UAABrowser_UpdateJoinAndPBPanel*	UpdateJoinAndPBPanel;					//var() automated AABrowser_UpdateJoinAndPBPanel UpdateJoinAndPBPanel;
	UPROPERTY(EditAnywhere)			UGUIImage*							PlayerNameBackgroundBorder;				//var() automated XInterface.GUIImage PlayerNameBackgroundBorder;
	UPROPERTY(EditAnywhere)			UGUILabel*							PlayerNameLabel;						//var() automated XInterface.GUILabel PlayerNameLabel;
	UPROPERTY(EditAnywhere)			UGUIEditBox*						PlayerNameEditBox;						//var() automated XInterface.GUIEditBox PlayerNameEditBox;
	UPROPERTY(EditAnywhere)			UGUILabel*							ServerCount;							//var() automated XInterface.GUILabel ServerCount;
	UPROPERTY()						bool								bIsLAN;									//var bool bIsLAN;

	void ShowPanel(bool bShow);
	void InternalOnTimer(UGUIComponent* Sender);
	void InternalOnPunkBusterChanged(bool PunkBusterEnabled);
	void InternalOnUpdateServerList();
	void InternalOnJoinServer();
	void InternalOnRecievedServer(int32 Index);
	void UpdateServerList();
	void InternalOnPlayerNameDeactivate();
	void SaveLANPlayerName();


};
