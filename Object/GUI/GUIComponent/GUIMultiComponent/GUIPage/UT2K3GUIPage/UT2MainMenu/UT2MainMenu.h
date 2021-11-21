// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2MainMenu : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2MainMenu();

	UPROPERTY()				bool		AllowClose;				//var bool AllowClose;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnClose(bool bCanceled);
	bool MyKeyEvent(uint8& Key, uint8& State, float Delta);
	bool CanClose(bool bCanceled);
	bool ButtonClick(UGUIComponent* Sender);
};
