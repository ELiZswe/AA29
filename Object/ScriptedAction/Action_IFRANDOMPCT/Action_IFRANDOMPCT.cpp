// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_IFRANDOMPCT/Action_IFRANDOMPCT.h"

UAction_IFRANDOMPCT::UAction_IFRANDOMPCT()
{

}

void UAction_IFRANDOMPCT::ProceedToNextAction(UScriptedController* C)
{
	/*
	C.ActionNum += 1;
	if (FRand() > Probability)
	{
		ProceedToSectionEnd(C);
	}
	*/
}

bool UAction_IFRANDOMPCT::StartsSection()
{
	return true;
}