// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2QuitPage.generated.h"

class UGUIComponent;
UCLASS()
class UUT2QuitPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2QuitPage();

	bool InternalOnClick(UGUIComponent* Sender);
};
