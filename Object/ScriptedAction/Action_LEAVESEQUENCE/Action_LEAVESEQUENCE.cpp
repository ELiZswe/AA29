// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_LEAVESEQUENCE/Action_LEAVESEQUENCE.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

UAction_LEAVESEQUENCE::UAction_LEAVESEQUENCE()
{
	ActionString = "leave sequence";
}

AScriptedSequence* UAction_LEAVESEQUENCE::GetScript(AScriptedSequence* S)
{
	return nullptr;
}
