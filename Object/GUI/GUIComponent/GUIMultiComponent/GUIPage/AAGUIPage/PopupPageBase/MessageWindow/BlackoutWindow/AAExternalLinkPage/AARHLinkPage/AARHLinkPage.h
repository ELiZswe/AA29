// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExternalLinkPage/AAExternalLinkPage.h"
#include "AARHLinkPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAARHLinkPage : public UAAExternalLinkPage
{
	GENERATED_BODY()
public:
	UAARHLinkPage();

	void HandleParameters(FString Param1, FString Param2);
	bool InternalOnClick(UGUIComponent* Sender);
};
