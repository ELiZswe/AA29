// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AASupportContentSubPanel.generated.h"

class UGUIContentBox;
class UGUIComponent;

UCLASS()
class AA29_API UAASupportContentSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAASupportContentSubPanel();

	UPROPERTY(EditAnywhere)			UGUIContentBox* cob_Panel;						//var() automated GUIContentBox cob_Panel;
	UPROPERTY()						UGUIComponent* selected;						//var XInterface.GUIComponent selected;
	UPROPERTY()						FString SupportFile;							//var FString SupportFile;
	UPROPERTY()						FString ContentPackage;							//var FString ContentPackage;
	UPROPERTY()						FString ContentPackageGroup;					//var FString ContentPackageGroup;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
	void LoadContent();
};
