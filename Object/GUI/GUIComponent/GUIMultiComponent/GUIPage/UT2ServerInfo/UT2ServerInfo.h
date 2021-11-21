// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "UT2ServerInfo.generated.h"

class UGUITabControl;

UCLASS(Config = Game)
class AA29_API UUT2ServerInfo : public UGUIPage
{
	GENERATED_BODY()
public:
	UUT2ServerInfo();

	UPROPERTY(EditAnywhere, config, Category = "MidGame")				TArray<FString> PanelClass;					//var(MidGame) config TArray<FString> PanelClass;
	UPROPERTY(EditAnywhere, Category = "MidGame")						TArray<FString> PanelCaption;				//var(MidGame) localized TArray<FString> PanelCaption;
	UPROPERTY(EditAnywhere, Category = "MidGame")						TArray<FString> PanelHint;					//var(MidGame) localized TArray<FString> PanelHint;
	UPROPERTY(EditAnywhere, Category = "MidGame")						UGUITabControl* TabC;						//var(MidGame) editconst noexport GUITabControl TabC;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClicked(UGUIComponent* Sender);
	void ChangeHint(FString NewHint);
	void SetTitle();
	bool NotifyLevelChange();
};
