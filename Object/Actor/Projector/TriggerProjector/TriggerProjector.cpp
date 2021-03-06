// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/TriggerProjector/TriggerProjector.h"

ATriggerProjector::ATriggerProjector()
{
	bStartOn = true;
	//bProjectOnUnlit = true;
	//bDynamicAttach = true;
	//bStatic = false;
}

void ATriggerProjector::BeginPlay()
{
	if (!bStartOn)
	{
		TurnOff();
	}
}

void ATriggerProjector::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bOnceOnly && bTriggeredOnce)
	{
		return;
	}
	if (bOnceOnly)
	{
		bTriggeredOnce = true;
	}
	if (bIsOn)
	{
		TurnOff();
	}
	else
	{
		TurnOn();
	}
}

void ATriggerProjector::TurnOn()
{
	//AttachProjector();
	bIsOn = true;
	//Log("TRIGGERPROJECTOR::TURNON()");
}

void ATriggerProjector::TurnOff()
{
	//DetachProjector(true);
	bIsOn = false;
	//Log("TRIGGERPROJECTOR::TURNOFF()");
}
