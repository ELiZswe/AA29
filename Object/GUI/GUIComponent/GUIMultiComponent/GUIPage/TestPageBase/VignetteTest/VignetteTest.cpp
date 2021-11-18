// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/VignetteTest/VignetteTest.h"

UVignetteTest::UVignetteTest()
{
	StyleName = "Page";
	WinHeight = 1;
}

void UVignetteTest::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	Vig = PlayerOwner().Spawn(class'XInterface.UT2SP_LadderLoading');
	if (Vig != None)
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
	if (Vig != None)
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