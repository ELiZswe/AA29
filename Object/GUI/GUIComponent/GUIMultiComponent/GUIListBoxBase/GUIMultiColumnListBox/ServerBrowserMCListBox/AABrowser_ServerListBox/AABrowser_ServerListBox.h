// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AABrowser_ServerListBox.generated.h"

class UGUIListBase;
class UGUIController;
class UGUIComponent;
class UGUIContextMenu;

UCLASS()
class UAABrowser_ServerListBox : public UServerBrowserMCListBox
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListBox();

	UPROPERTY()								FString						PingTooltipText;				//var localized string PingTooltipText;
	UPROPERTY()								int32						ContextChoiceToActionIndex;		//var int ContextChoiceToActionIndex;
	UPROPERTY()								int32						OPENIPIDX;						//var int OPENIPIDX;
	UPROPERTY()								int32						COPYIDX;						//var int COPYIDX;
	UPROPERTY()								int32						REMOVEFAVIDX;					//var int REMOVEFAVIDX;
	UPROPERTY()								int32						ADDFAVIDX;						//var int ADDFAVIDX;
	UPROPERTY()								int32						REFRESHIDX;						//var int REFRESHIDX;
	UPROPERTY()								int32						REPINGIDX;						//var int REPINGIDX;
	UPROPERTY()								int32						JOINASADMINIDX;					//var int JOINASADMINIDX;
	UPROPERTY()								int32						JOINASPLAYERADMIN;				//var int JOINASPLAYERADMIN;
	UPROPERTY()								int32						SPECIDX;						//var int SPECIDX;
	UPROPERTY()								int32						JOINIDX;						//var int JOINIDX;
	UPROPERTY()								TArray<FString>				ContextItems;					//var array<String> ContextItems;
	UPROPERTY(EditAnywhere)					FString						OpenIPPage;						//var() config string OpenIPPage;

	void OnUpdateServerList();
	void OnUpdateServerRulesAndPlayerList(int32 ServerIndex);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat);
	void InternalOnMouseReleased(UGUIComponent* Sender);
	void SetToolTipText(FString NewToolTipText);
	bool PreDrawHint(UCanvas* C);
	bool PreDrawIconsHint(UCanvas* C);
	bool PreDrawPingHint(UCanvas* C);
	bool DrawHint(UCanvas* C);
	bool DrawIconsHint(UCanvas* C);
	bool DrawPingHint(UCanvas* C);
	bool MousingOverIcons();
	bool MousingOverPing();
	bool ShouldAddContextChoice(int32 ContextIndex, FGameSpyServerItem ServerItem);
	bool InternalOnOpen(UGUIContextMenu* Sender);
	void OpenFavoritesOperationDialog(FString Action, FString Message);
	void InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message);
	void InternalOnClick(UGUIContextMenu* Sender, int32 Index);
	void InternalOnCloseGetAdminPassword(bool bCancelled);
	void InternalOnCloseGetPlayerAdminPassword(bool bCancelled);
	void InitBaseList(UGUIListBase* LocalList);

};
