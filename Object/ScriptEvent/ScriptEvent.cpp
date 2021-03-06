// All the original content belonged to the US Army

#include "AA29/Object/ScriptEvent/ScriptEvent.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"

UScriptEvent::UScriptEvent()
{

}

//const kCT_Or = 2;
//const kCT_And = 1;
//const kCT_Normal = 0;

void UScriptEvent::Destroyed()
{
	/*
	int32 Counter = 0;
	_ParentScreenplay = nullptr;
	for (Counter = 0; Counter < Conditions.Num(); Counter++)
	{
		Conditions[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Directions.Num(); Counter++)
	{
		Directions[Counter].Destroyed();
	}
	Conditions.RemoveAt(0, Conditions.Num());
	Directions.RemoveAt(0, Directions.Num());
	*/
}

void UScriptEvent::EventStart()
{
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::EventStart()");
	}
	if (_bRunOnceGlobal)
	{
		if (!_bRanOnce)
		{
			_bFinished = false;
			ConditionsStart();
		}
	}
	else
	{
		_bFinished = false;
		ConditionsStart();
	}
	*/
}

void UScriptEvent::EventFinish()
{
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::EventFinish()");
	}
	_bFinished = true;
	ConditionsFinish();
	DirectionsFinish();
	*/
}

void UScriptEvent::ConditionsStart()
{
	int32 Size = 0;
	int32 cur = 0;
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::ConditionsStart()");
	}
	Size = Conditions.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Conditions[cur].Start();
	}
	*/
}

void UScriptEvent::ConditionsFinish()
{
	int32 Size = 0;
	int32 cur = 0;
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::ConditionsFinish()");
	}
	Size = Conditions.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Conditions[cur].Finish();
	}
	*/
}

void UScriptEvent::ConditionFinished(UCondition* con)
{
	/*
	int32 Size = 0;
	int32 cur = 0;
	if (_bDebug)
	{
		Log("ScriptEvent::ConditionFinished()");
	}
	if (_iType == 1)
	{
		Size = Conditions.Num();
		for (cur = 0; cur < Size; cur++)
		{
			if (!Conditions[cur].IsTrue())
			{
				return;
			}
		}
	}
	if (_bRunOnceGlobal)
	{
		ConditionsFinish();
		_bRanOnce = true;
	}
	else
	{
		if (_bRunOncePerScene)
		{
			ConditionsFinish();
		}
	}
	RunDirections();
	*/
}

void UScriptEvent::DirectionsFinish()
{
	int32 Size = 0;
	int32 cur = 0;
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::DirectionsFinish()");
	}
	Size = Directions.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Directions[cur].Finish();
	}
	*/
}

void UScriptEvent::RunDirections()
{
	int32 Size = 0;
	int32 D = 0;
	/*
	if (_bDebug)
	{
		Log("ScriptEvent::RunDirections()");
	}
	Size = Directions.Num();
	for (D = 0; D < Size; D++)
	{
		if (!_bFinished)
		{
			Directions[D].Start();
		}
	}
	*/
}

bool UScriptEvent::AddCondition(UCondition* con)
{
	/*
	int32 Size = 0;
	Size = Conditions.Num();
	if (_iType == 0)
	{
		if (Size > 0)
		{
			Log("ERROR Event::AddCondition - cannot add more than 1 condition if kCT_Normal");
			return false;
		}
	}
	Conditions[Size] = con;
	Conditions[Size].SetParentEvent(this);
	*/
	return true;
}

bool UScriptEvent::AddDirection(UDirection* Dir)
{
	/*
	int32 Size = 0;
	Size = Directions.Num();
	Directions[Size] = Dir;
	Directions[Size].SetParentScreenplay(_ParentScreenplay);
	return true;
	*/
	return false;   //FAKE   /ELiZ
}

bool UScriptEvent::SetConditionAnd()
{
	/*
	if (_iType == 0)
	{
		_iType = 1;
		return true;
	}
	else
	{
		Log("ERROR Event::SetConditionAnd() - CHANGING CONDITION TYPE!");
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool UScriptEvent::SetConditionOr()
{
	/*
	if (_iType == 0)
	{
		_iType = 2;
		return true;
	}
	else
	{
		Log("ERROR Event::SetConditionOr() - CHANGING CONDITION TYPE!");
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

void UScriptEvent::SetRunOnceGlobal(bool Status)
{
	//_bRunOnceGlobal = Status;
}

void UScriptEvent::SetRunOncePerScene(bool Status)
{
	//_bRunOncePerScene = Status;
}

void UScriptEvent::SetParentScreenplay(AScreenplay* Parent)
{
	//_ParentScreenplay = Parent;
}

void UScriptEvent::SetDebug(bool Debug)
{
	/*
	int32 Size = 0;
	int32 cur = 0;
	_bDebug = Debug;
	Size = Conditions.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Conditions[cur].SetDebug(Debug);
	}
	Size = Directions.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Directions[cur].SetDebug(Debug);
	}
	*/
}

void UScriptEvent::DumpEvent()
{
	/*
	int32 Size = 0;
	int32 cur = 0;
	Size = Conditions.Num();
	if (_bDebug)
	{
		Log("    Conditions: " + FString::FromInt(Size));
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    Conditions[" + FString::FromInt(cur) + "] is a " + FString::FromInt(Conditions[cur].Class));
		}
	}
	Size = Directions.Num();
	if (_bDebug)
	{
		Log("    Directions: " + FString::FromInt(Size));
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    Directions[" + FString::FromInt(cur) + "] is a " + FString::FromInt(Directions[cur].Class));
		}
	}
	*/
}

