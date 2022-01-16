// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_Fade/Dir_Fade.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_Fade::UDir_Fade()
{
	_nNumParamsDefined = 3;
}

void UDir_Fade::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_Fade::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_Fade::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		_HumanController.DoFade(_bFadeIn, _bFadeBlack, _bFadeTime);
	}
	*/
}

bool UDir_Fade::ProcessParams()
{
	/*
	_bFadeIn = bool(GetParam(0));
	_bFadeBlack = bool(GetParam(1));
	_bFadeTime = float(GetParam(2));
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
