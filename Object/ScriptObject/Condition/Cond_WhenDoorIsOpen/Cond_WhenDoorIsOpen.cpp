// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenDoorIsOpen/Cond_WhenDoorIsOpen.h"

UCond_WhenDoorIsOpen::UCond_WhenDoorIsOpen()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UCond_WhenDoorIsOpen::Destroyed()
{
	Super::Destroyed();
	//DoorTrigger = nullptr;
}
void UCond_WhenDoorIsOpen::ConditionStart()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenDoorIsOpen::ConditionStart()"));
	}

	//if (DoorTrigger.IsOpen() == bOpen)
	//{
	//	Notify();
	//}
}
void UCond_WhenDoorIsOpen::ConditionFinish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenDoorIsOpen::ConditionFinish()"));
	}
}
bool UCond_WhenDoorIsOpen::ProcessParams()
{
	
	//DoorTrigger = DoorTrigger(_ParentScreenplay.GetActorByTag(GetParam(0)));
	//bOpen = GetParam(1);
	//if (DoorTrigger == nullptr)
	//{
	//	if (_bDebug)
	//	{
	//		//Log("Cond_WhenDoorIsOpen::ProcessParams() - could not find DoorTrigger with tag " $ GetParam(0));
	//	}
	//	return false;
	//}
	return true;
}
