// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/ScriptObject.h"

UScriptObject::UScriptObject()
{


}

void UScriptObject::Destroyed()
{
	//_sParameters.Remove(0, _sParameter.Max());
}

void UScriptObject::Notify()
{
}

void UScriptObject::update()
{
}

void UScriptObject::SetDebug(bool Debug)
{
	_bDebug = Debug;
}

int32 UScriptObject::GetNumParams()
{
	return _sParameters.Max();
}

int32 UScriptObject::GetNumParamsDefined()
{
	return _nNumParamsDefined;
}

FString UScriptObject::GetParam(int32 Index)
{
	int32 Len;
	Len = _sParameters.Max();
	if (Index >= 0 && Index < Len)
	{
		return _sParameters[Index];
	}
	else
	{
		return "";
	}
}
void UScriptObject::SetParamString(FString szParams)
{
	/*
	local string sParamList;
	local int loc;
	local int Counter;
	sParamList = szParams;
	Counter = 0;
	loc = InStr(sParamList, ";");
	if (loc != -1)
	{
		_sParameters[Counter] = Left(sParamList, loc);
		sParamList = Right(sParamList, Len(sParamList) - loc - 1);
		loc = InStr(sParamList, ";");
		Counter++;
	}
	if (Len(sParamList) > 0)
	{
		if (_bDebug)
		{
			Log("Direction::SetParamString() found last/lone parameter: " $ sParamList);
		}
		_sParameters[Counter] = sParamList;
	}
	*/
}
