// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2PerformWarn.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2PerformWarn : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2PerformWarn();

	bool InternalOnClick(UGUIComponent* Sender);
};
