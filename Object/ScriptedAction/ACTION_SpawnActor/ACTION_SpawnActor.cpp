// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_SpawnActor/ACTION_SpawnActor.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_SpawnActor::UACTION_SpawnActor()
{
	ActionString = "Spawn actor";
}

bool UACTION_SpawnActor::InitActionFor(AScriptedController* C)
{
	FVector loc = FVector(0,0,0);
	FRotator Rot =FRotator(0,0,0);
	AActor* A = nullptr;
	/*
	if (bOffsetFromScriptedPawn)
	{
		loc = C.Pawn.Location + LocationOffset;
		Rot = C.Pawn.Rotation + RotationOffset;
	}
	else
	{
		loc = C.SequenceScript.Location + LocationOffset;
		Rot = C.SequenceScript.Rotation + RotationOffset;
	}
	A = C.Spawn(ActorClass, , , loc, Rot);
	A.Instigator = C.Pawn;
	if (ActorTag != "None")
	{
		A.Tag = ActorTag;
	}
	*/
	return false;
}

FString UACTION_SpawnActor::GetActionString()
{
	//return ActionString @ ActorClass;
	return "";    //FAKE    /ELiZ
}
