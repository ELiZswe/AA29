// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "Tab_SPProfileNew.generated.h"

class UGUIEditBox;
class UGUIComboBox;
class UGUICharacterListTeam;
class UGUIImageList;

UCLASS()
class AA29_API UTab_SPProfileNew : public UTab_SPPanelBase
{
	GENERATED_BODY()
public:
	UTab_SPProfileNew();

	UPROPERTY()			UGUIEditBox* ePlayerName;				//var GUIEditBox ePlayerName;
	UPROPERTY()			UGUIEditBox* eTeamName;					//var GUIEditBox eTeamName;
	UPROPERTY()			UGUIComboBox* cDifficulty;				//var GUIComboBox cDifficulty;
	UPROPERTY()			UGUICharacterListTeam* clPlayerSkins;	//var GUICharacterListTeam clPlayerSkins;
	UPROPERTY()			UGUIImageList* iTeamSymbols;			//var GUIImageList iTeamSymbols;
	UPROPERTY()			FString DefaultName;					//var localized FString DefaultName;
	UPROPERTY()			FString DefaultTeamName;				//var localized FString DefaultTeamName;
	UPROPERTY()			FString DefaultCharacter;				//var FString DefaultCharacter;
	UPROPERTY()			FString TeamSymbolPrefix;				//var FString TeamSymbolPrefix;
	UPROPERTY()			int32 DefaultTeamSymbol;				//var int32 DefaultTeamSymbol;
	UPROPERTY()			int32 CurrentTeamSymbolNum;				//var int32 CurrentTeamSymbolNum;
	UPROPERTY()			FString Err_ProfileExists;				//var localized FString Err_ProfileExists;
	UPROPERTY()			FString Err_CantCreateProfile;			//var localized FString Err_CantCreateProfile;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	void InitPanel();
	bool PlayerOnClick(UGUIComponent* Sender);
	FString GetTeamSymbolName(int32 idx);
	FString CurrentTeamSymbolName();
	void LoadSymbols();
	void ClearStats();
	bool CreateClick(UGUIComponent* Sender);
	bool PrevSkin(UGUIComponent* Sender);
	bool NextSkin(UGUIComponent* Sender);
	bool PrevSymbol(UGUIComponent* Sender);
	bool NextSymbol(UGUIComponent* Sender);
	bool BackClick(UGUIComponent* Sender);
	bool DefaultsClick(UGUIComponent* Sender);

};
