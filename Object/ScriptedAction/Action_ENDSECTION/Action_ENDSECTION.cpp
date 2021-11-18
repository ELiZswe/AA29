// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_ENDSECTION/Action_ENDSECTION.h"

UAction_ENDSECTION::UAction_ENDSECTION()
{
	ActionString = "end section";
}

void UAction_ENDSECTION::ProceedToNextAction(UScriptedController* C)
{
	/*
	if (C.IterationCounter > 0)
	{
		C.ActionNum = C.IterationSectionStart;
		C.IterationCounter--;
	}
	else
	{
		C.ActionNum += 1;
		C.IterationSectionStart = -1;
	}
	*/
}
bool UAction_ENDSECTION::EndsSection()
{
	return true;
}