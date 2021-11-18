// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "IRC_NewNick.generated.h"

class UGUILabel;
class UIRC_System;
class UmoEditBox;

UCLASS()
class AA29_API UIRC_NewNick : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UIRC_NewNick();

	UPROPERTY()				UmoEditBox*		MyNewNick;					//var moEditBox MyNewNick;
	UPROPERTY()				UIRC_System*	SystemPage;					//var IRC_System SystemPage;
	UPROPERTY()				UGUILabel*		NewNickPrompt;				//var GUILabel NewNickPrompt;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);

};
