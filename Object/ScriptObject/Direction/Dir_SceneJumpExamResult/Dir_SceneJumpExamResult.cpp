// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SceneJumpExamResult/Dir_SceneJumpExamResult.h"
#include "AA29/Object/Actor/MedExam/MedExam.h"

UDir_SceneJumpExamResult::UDir_SceneJumpExamResult()
{
	bSupportsMP = true;
	_nNumParamsDefined = 4;
}

void UDir_SceneJumpExamResult::Destroyed()
{
	Super::Destroyed();
	MedExam = nullptr;
}

void UDir_SceneJumpExamResult::DirectionStart()
{
	/*
	float Score = 0;
	if (_bDebug)
	{
		Log("Dir_SceneJumpExamResult::DirectionStart()");
	}
	if (MedExam != nullptr)
	{
		Score = float(int((MedExam.ScoreTest() * float(100))));
		if ((Score >= float(LowPercentage)) && (Score <= float(HighPercentage)))
		{
			_ParentScreenplay.SceneJump(Scene);
		}
	}
	*/
}

void UDir_SceneJumpExamResult::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneJumpExamResult::DirectionFinish()");
	}
	*/
}

bool UDir_SceneJumpExamResult::ProcessParams()
{
	/*
	MedExam = Cast<AMedExam>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (MedExam == nullptr)
	{
		Log("Dir_SceneJumpExamResult::ProcessParams(): Error: MedExam is None");
		return false;
	}
	Scene = FString::FromInt(GetParam(1));
	LowPercentage = int(GetParam(2));
	HighPercentage = int(GetParam(3));
	*/
	return true;
}
