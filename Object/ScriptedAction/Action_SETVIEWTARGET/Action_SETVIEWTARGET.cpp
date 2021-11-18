// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_SETVIEWTARGET/Action_SETVIEWTARGET.h"

UAction_SETVIEWTARGET::UAction_SETVIEWTARGET()
{
	ActionString = "set viewtarget";
	bValidForTrigger = false;

}



bool UAction_SETVIEWTARGET::InitActionFor(UScriptedController* C)
{
	/*
	if (ViewTargetTag == 'Enemy')
	{
		C.ScriptedFocus = C.Enemy;
	}
	else
	{
		if (ViewTargetTag == 'None')
		{
			C.ScriptedFocus = None;
		}
		else
		{
			if (ViewTarget == None && ViewTargetTag != 'None')
			{
				ForEach C.AllActors(Class'Actor', ViewTarget, ViewTargetTag)
				{
				}
			}
			if (ViewTarget == None)
			{
				C.bBroken = true;
			}
			C.ScriptedFocus = ViewTarget;
		}
	}
	*/
	return false;
}
FString UAction_SETVIEWTARGET::GetActionString()
{
	//return ActionString @ ViewTarget @ ViewTargetTag;
	return "";    //FAKE    /ELiZ
}