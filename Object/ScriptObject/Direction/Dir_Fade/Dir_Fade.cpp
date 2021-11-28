// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_Fade/Dir_Fade.h"

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
	if (_HumanController != None)
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
