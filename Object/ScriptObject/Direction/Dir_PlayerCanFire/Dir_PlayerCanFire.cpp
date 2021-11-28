// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_PlayerCanFire/Dir_PlayerCanFire.h"

UDir_PlayerCanFire::UDir_PlayerCanFire()
{
	_bDebug = true;
	_nNumParamsDefined = 1;
}

void UDir_PlayerCanFire::Destroyed()
{
	Super::Destroyed();
}

void UDir_PlayerCanFire::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_PlayerCanFire::DirectionStart()");
	}
	_ParentScreenplay.GetHumanController().SetCanFire(bCanFire);
	*/
}

void UDir_PlayerCanFire::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_PlayerCanFire::DirectionFinish()");
	}
	*/
}

bool UDir_PlayerCanFire::ProcessParams()
{
	//bCanFire = bool(GetParam(0));
	return true;
}
