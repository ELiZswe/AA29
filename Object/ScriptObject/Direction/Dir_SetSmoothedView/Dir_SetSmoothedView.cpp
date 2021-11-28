// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetSmoothedView/Dir_SetSmoothedView.h"

UDir_SetSmoothedView::UDir_SetSmoothedView()
{
	_nNumParamsDefined = 1;
}

void UDir_SetSmoothedView::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetSmoothedView::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetSmoothedView::DirectionStart()");
	}
	*/
}

void UDir_SetSmoothedView::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetSmoothedView::DirectionFinish()");
	}
	*/
}

bool UDir_SetSmoothedView::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_bSmooth = bool(GetParam(0));
	*/
	return true;
}