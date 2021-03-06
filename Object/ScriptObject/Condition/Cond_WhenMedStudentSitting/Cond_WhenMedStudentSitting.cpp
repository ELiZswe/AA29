// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenMedStudentSitting/Cond_WhenMedStudentSitting.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

UCond_WhenMedStudentSitting::UCond_WhenMedStudentSitting()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UCond_WhenMedStudentSitting::Destroyed()
{
	Super::Destroyed();
	//Controller = nullptr;
}

void UCond_WhenMedStudentSitting::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenMedStudentSitting::ConditionStart()");
	}
	if (Controller.IsSeated() == bSitting)
	{
		Notify();
	}
	*/
}

void UCond_WhenMedStudentSitting::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenMedStudentSitting::ConditionFinish()");
	}
	*/
}

bool UCond_WhenMedStudentSitting::ProcessParams()
{
	/*
	bSitting = bool(GetParam(0));
	Controller = Cast<AStudentController>(_ParentScreenplay.GetHumanController());
	if (Controller == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenMedStudentSitting::ProcessParams() - Controller is None");
		}
		return false;
	}
	*/
	return true;
}
