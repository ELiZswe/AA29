// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_WeaponInduceJamRandom/Dir_WeaponInduceJamRandom.h"

UDir_WeaponInduceJamRandom::UDir_WeaponInduceJamRandom()
{
	_nNumParamsDefined = 2;
}

void UDir_WeaponInduceJamRandom::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJamRandom::DirectionStart()");
	}
	if (bOnceOnly)
	{
		if (!bJammed)
		{
			if ((FRand() * float(iRandNum)) < 1)
			{
				AGP_Pawn(_HumanController.Pawn).InduceJam();
				bJammed = true;
			}
		}
	}
	else
	{
		if ((FRand() * float(iRandNum)) < 1)
		{
			AGP_Pawn(_HumanController.Pawn).InduceJam();
		}
	}
	*/
}

void UDir_WeaponInduceJamRandom::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJamRandom::DirectionFinish()");
	}
	*/
}

bool UDir_WeaponInduceJamRandom::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJamRandom::ProcessParams()");
	}
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	iRandNum = int(GetParam(0));
	bOnceOnly = bool(GetParam(1));
	*/
	return true;
}
