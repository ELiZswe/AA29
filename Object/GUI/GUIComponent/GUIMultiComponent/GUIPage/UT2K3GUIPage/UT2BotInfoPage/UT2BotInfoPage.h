// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2BotInfoPage.generated.h"

class UGUIImage;
class UGUILabel;
class UGUIProgressBar;

UCLASS()
class AA29_API UUT2BotInfoPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2BotInfoPage();

	UPROPERTY()				FString						NoInformation;			//var localized FString NoInformation;
	UPROPERTY()				UGUIImage*					BotPortrait;			//var GUIImage BotPortrait;
	UPROPERTY()				UGUILabel*					botname;				//var GUILabel botname;
	UPROPERTY()				UGUILabel*					BotRace;				//var GUILabel BotRace;
	UPROPERTY()				TArray<UGUIProgressBar*>	Bars;					//var TArray<GUIProgressBar> Bars;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool OkClick(UGUIComponent* Sender);
};
