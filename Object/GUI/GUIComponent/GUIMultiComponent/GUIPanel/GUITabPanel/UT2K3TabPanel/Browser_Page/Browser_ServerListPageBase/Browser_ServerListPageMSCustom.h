// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMS.h"
#include "Browser_ServerListPageMSCustom.generated.h"

class UGUISplitter;
class UGUIComboBox;

UCLASS(Config = Game)
class AA29_API UBrowser_ServerListPageMSCustom : public UBrowser_ServerListPageMS
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageMSCustom();

	UPROPERTY()				UGUISplitter*		GameTypeSplit;						//var GUISplitter GameTypeSplit;
	UPROPERTY()				UGUIComboBox*		GameTypeCombo;						//var GUIComboBox GameTypeCombo;
	UPROPERTY()				UGUISplitter*		MainSplit;							//var GUISplitter MainSplit;
	UPROPERTY()				bool				CustomInitialized;					//var bool CustomInitialized;
	UPROPERTY(config)		FString				LastGameType;						//var config FString LastGameType;

	void ChangeGameType(UGUIComponent* Sender);
	FString MyParseDescStr(FString DescStr, int32 Index);
	bool IsStandardGameType(FString Desc);
	FString FindGameTypeName(FString GameType);
	void PopulateGameTypes();
	void InitComponent(UGUIController* C, UGUIComponent* O);
};
