// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestPageBase.h"
#include "JoeTest.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UJoeTest : public UTestPageBase
{
	GENERATED_BODY()
public:
	UJoeTest();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool OnClick1(UGUIComponent* Sender);
	bool OnClick2(UGUIComponent* Sender);

};
