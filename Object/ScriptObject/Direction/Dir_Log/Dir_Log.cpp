// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_Log/Dir_Log.h"

UDir_Log::UDir_Log()
{
	_nNumParamsDefined = 1;
}

void UDir_Log::Destroyed()
{
	Super::Destroyed();
}

void UDir_Log::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_Log::DirectionStart()");
	}
	Log("Dir_Log::DirectionStart(): LogMessage: " @ LogMessage);
	*/
}

bool UDir_Log::ProcessParams()
{
	//LogMessage = GetParam(0);
	return true;
}

