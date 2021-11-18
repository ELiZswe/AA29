// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Condition.h"

UCondition::UCondition()
{

}


void UCondition::Destroyed()
{
	Super::Destroyed();
	//_ParentEvent = nullptr;
	//_ParentScreenplay = nullptr;
}
void UCondition::ConditionStart()
{
}
void UCondition::ConditionFinish()
{
}
bool UCondition::ProcessParams()
{
	return false;
}
void UCondition::Start()
{
	_bValid = true;
	_bTrue = false;
	ConditionStart();
}
void UCondition::Finish()
{
	_bValid = false;
	_bTrue = false;
	ConditionFinish();
}
void UCondition::Notify()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Condition::Notify()"));
	}
	_bTrue = false;
	if (_bValid)
	{
		//if (_ParentEvent != nullptr)
		//{
		//	if (_bDebug)
		//	{
		//		//Log("Condition::Notify() calling _ParentEvent.ConditionFinished()");
		//	}
		//	_bTrue = true;
		//	_ParentEvent.ConditionFinished(this);
		//}
		//else
		//{
		//	if (_bDebug)
		//	{
		//		//Log("Condition::Notify() _ParentEvent == None");
		//	}
		//}
	}
	else
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Condition::Notify() - not valid"));
		}
	}
}

/*
void UCondition::SetParentEvent(ScriptEvent Parent)
{
	_ParentEvent = Parent;
}
void UCondition::SetParentScreenplay(Screenplay Parent)
{
	_ParentScreenplay = Parent;
}
*/
bool UCondition::IsTrue()
{
	return _bTrue;
}