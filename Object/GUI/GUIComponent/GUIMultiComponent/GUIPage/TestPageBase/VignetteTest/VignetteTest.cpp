// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/VignetteTest/VignetteTest.h"
#include "AA29/Object/Actor/Vignette/UT2LoadingPageBase/UT2SP_LadderLoading/UT2SP_LadderLoading.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

UVignetteTest::UVignetteTest()
{
	StyleName = "Page";
	WinHeight = 1;
}

void UVignetteTest::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	Vig = PlayerOwner().Spawn(AUT2SP_LadderLoading::StaticClass());
	if (Vig != nullptr)
	{
		Log("Vignette Created");
		Vig.Init();
		__OnDraw__Delegate = MyOnDraw;
		SetTimer(60, false);
		return;
	}
	Controller.CloseMenu();
	*/
}

void UVignetteTest::Timer()
{
	//Controller.CloseMenu();
}

void UVignetteTest::MyOnClose(bool bCancelled)
{
	/*
	if (Vig != nullptr)
	{
		Log("Destroying the Vignette");
		Vig.Destroy();
	}
	*/
}

bool UVignetteTest::MyOnDraw(UCanvas* Canvas)
{
	//Vig.DrawVignette(Canvas, 1);
	return true;
}
