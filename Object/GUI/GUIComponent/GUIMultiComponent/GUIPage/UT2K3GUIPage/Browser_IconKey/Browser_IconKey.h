// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "Browser_IconKey.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UBrowser_IconKey : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UBrowser_IconKey();

	bool InternalOnClick(UGUIComponent* Sender);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
