// All the original content belonged to the US Army


#include "AA29/Object/ScriptEvent/ScriptEvent.h"

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
	_ParentScreenplay = None;
	for (Counter = 0; Counter < Conditions.Length; Counter++)
	{
		Conditions[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Directions.Length; Counter++)
	{
		Directions[Counter].Destroyed();
	}
	Conditions.remove(0, Conditions.Length);
	Directions.remove(0, Directions.Length);
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
	Size = Conditions.Length;
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
	Size = Conditions.Length;
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
		Size = Conditions.Length;
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
	Size = Directions.Length;
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
	Size = Directions.Length;
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
	Size = Conditions.Length;
	if (_iType == 0)
	{
		if (Size > 0)
		{
			Log("ERROR Event::AddCondition - cannot add more than 1 condition if kCT_Normal");
			return false;
		}
	}
	Conditions[Size] = con;
	Conditions[Size].SetParentEvent(Self);
	*/
	return true;
}

bool UScriptEvent::AddDirection(UDirection* Dir)
{
	/*
	int32 Size = 0;
	Size = Directions.Length;
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
	Size = Conditions.Length;
	for (cur = 0; cur < Size; cur++)
	{
		Conditions[cur].SetDebug(Debug);
	}
	Size = Directions.Length;
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
	Size = Conditions.Length;
	if (_bDebug)
	{
		Log("    Conditions: " $ string(Size));
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    Conditions[" $ string(cur) $ "] is a " $ string(Conditions[cur].Class));
		}
	}
	Size = Directions.Length;
	if (_bDebug)
	{
		Log("    Directions: " $ string(Size));
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    Directions[" $ string(cur) $ "] is a " $ string(Directions[cur].Class));
		}
	}
	*/
}

