// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestPageBase.h"
#include "ListTest.generated.h"

class UGUIScrollText;

class UGUIComponent;
class UGUIController;
UCLASS()
class UListTest : public UTestPageBase
{
	GENERATED_BODY()
public:
	UListTest();

	UPROPERTY()						UGUIScrollText*		tScroll;				//var GUIScrollText tScroll;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool AddClick(UGUIComponent* Sender);

};
