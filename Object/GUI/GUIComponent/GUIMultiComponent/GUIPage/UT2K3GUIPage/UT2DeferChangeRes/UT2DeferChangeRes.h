// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2DeferChangeRes.generated.h"

class UGUIComponent;
UCLASS()
class UUT2DeferChangeRes : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2DeferChangeRes();
	
	bool InternalOnClick(UGUIComponent* Sender);
};
