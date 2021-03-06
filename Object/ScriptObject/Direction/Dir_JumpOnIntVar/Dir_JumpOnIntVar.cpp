// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_JumpOnIntVar/Dir_JumpOnIntVar.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/Actor/AGP_IntVar/AGP_IntVar.h"

UDir_JumpOnIntVar::UDir_JumpOnIntVar()
{
	bSupportsMP = true;
	_nNumParamsDefined = 4;
}

void UDir_JumpOnIntVar::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
}

void UDir_JumpOnIntVar::DirectionStart()
{
	int32 Value = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Dir_JumpOnIntVar::DirectionStart()"));
	}
	if (_IntVar == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR: Dir_JumpOnIntVar::DirectionStart() - _IntVar == nullptr"));
		return;
	}
	if (_ParentScreenplay == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR: Dir_JumpOnIntVar::DirectionStart() - _ParentScreenplay == nullptr"));
		return;
	}
	Value = _IntVar->GetValue();
	if ((Value >= _Min) && (Value <= _Max))
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Dir_JumpOnIntVar::DirectionStart() in range, jumping."));
		}
		_ParentScreenplay->SceneJump(_JumpScene);
	}
	else
	{
		if (_bDebug)
		{
			//((Log("Dir_JumpOnIntVar::DirectionStart() not in range.  Wanted " + FString::FromInt(_Min) + "<x<" + FString::FromInt(_Max) + " got " + FString::FromInt(Value));
		}
	}
}

void UDir_JumpOnIntVar::DirectionFinish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Dir_JumpOnIntVar::DirectionFinish()"));
	}
}

bool UDir_JumpOnIntVar::ProcessParams()
{
	if (_bDebug)
	{
		//Log("Dir_JumpOnIntVar::ProcessParams()");
	}
	/*
	_IntVar = Cast<AAGP_IntVar>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_Min = int(GetParam(1));
	_Max = int(GetParam(2));
	_JumpScene = FString::FromInt(GetParam(3));
	*/
	return true;
}
