// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2DemoQuitPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2DemoQuitPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2DemoQuitPage();

	UPROPERTY()				int32		TimeLeft;			//var int32 TimeLeft;
	UPROPERTY()				bool		bClickedBuy;		//var bool bClickedBuy;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Timer();
	bool OnBuyClicked(UGUIComponent* Sender);
	bool OnQuitClicked(UGUIComponent* Sender);
};
