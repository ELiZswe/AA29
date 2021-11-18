// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestPageBase.h"
#include "VignetteTest.generated.h"

class AUT2SP_LadderLoading;

UCLASS()
class AA29_API UVignetteTest : public UTestPageBase
{
	GENERATED_BODY()
public:
	UVignetteTest();

	UPROPERTY()				AUT2SP_LadderLoading*		Vig;					//var UT2SP_LadderLoading Vig;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Timer();
	void MyOnClose(bool bCancelled);
	bool MyOnDraw(UCanvas* Canvas);
};
