// All the original content belonged to the US Army

#include "AA29/Object/Interactions/Interaction/DemoController/DemoController.h"

UDemoController::UDemoController()
{
	SavedDemos.SetNum(32);
	SavedDemos = { "AA_Demo_01" };
	DemoPlayTriggerTime = 300;
	bRequiresTick = true;
}

//native Function bool PlayDemo(FString DemoName);
bool UDemoController::PlayDemo(FString DemoName)
{
	return false;     //FAKE   /ELiZ
}

void UDemoController::Initialized()
{
	SaveConfig();
	DemoModeTriggerTime = float(DemoPlayTriggerTime);
}

void UDemoController::ViewportInitialized()
{
}

void UDemoController::NotifyDemoCompleted()
{
	if (bDemoStarted)
	{
		StartRandomDemo();
	}
	else
	{
		//ViewportOwner.Actor.ConsoleCommand("open entry");
	}
}

void UDemoController::ResetDemoTriggerTime()
{
	if (bDemoStarted)
	{
		/*
		if (ViewportOwner.Actor.Level == ViewportOwner.Actor.GetEntryLevel())
		{
			ViewportOwner.Actor.ClientCloseMenu(true);
			ViewportOwner.Actor.ClientOpenMenu("AGP_Interface.AAMainMenu");
		}
		else
		{
			ViewportOwner.Actor.ConsoleCommand("open entry");
		}
		*/
	}
	bNoDemosFound = false;
	DemoTimer = 0;
	bDemoStarted = false;
}

void UDemoController::StartRandomDemo()
{
	int32 i = 0;
	int32 tryCount = 0;
	tryCount = 1024;
	/*
	do
	{
		i = int((FMath::FRand() * float(32)));
		tryCount--;
		if (tryCount < 0)
		{
			Log("No demos available at this time", "Demos");
			bNoDemosFound = true;
			bDemoStarted = false;
			return;
		}
	}
	until(((SavedDemos[i] != "") && FOpen("..\\Demos\\" + SavedDemos[i] + ".dem")));
	FClose();
	if (!PlayDemo(SavedDemos[i]))
	{
		ResetDemoTriggerTime();
	}
	*/
}

void UDemoController::Tick(float DeltaTime)
{
	if (bNoDemosFound)
	{
		return;
	}
	/*
	if (((DemoTimer > DemoModeTriggerTime) && (!bDemoStarted)) && (ViewportOwner.Actor.GetNetMode() != ENetMode::NM_Client))
	{
		bDemoStarted = true;
		StartRandomDemo();
	}
	else
	{
		(DemoTimer += DeltaTime);
	}
	*/
}
