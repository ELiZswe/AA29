// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/TestPanelBase/TestPanelBase.h"
#include "JoeTestPanelA.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UJoeTestPanelA : public UTestPanelBase
{
	GENERATED_BODY()
public:
	UJoeTestPanelA();

	void InitPanel();
};
