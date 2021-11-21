// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2AdminMenu.generated.h"

class UGUITabControl;
class UTab_AdminPlayerList;

UCLASS()
class AA29_API UUT2AdminMenu : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2AdminMenu();

	UPROPERTY()				UGUITabControl*				TabC;				//var GUITabControl TabC;
	UPROPERTY()				UTab_AdminPlayerList*		PlayerList;			//var Tab_AdminPlayerList PlayerList;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Param1, FString Param2);
	bool ButtonClicked(UGUIComponent* Sender);
};
