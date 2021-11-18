// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUI.h"
#include "GUIUserModInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIUserModInfo : public UGUI
{
	GENERATED_BODY()
public:
	UGUIUserModInfo();

	UPROPERTY()											FString ModCmdLine;								//var localized string ModCmdLine;
	UPROPERTY()											FString ModLogo;								//var localized string ModLogo;
	UPROPERTY()											FString ModInfo;								//var localized string ModInfo;
	UPROPERTY()											FString modname;								//var localized string modname;
};
