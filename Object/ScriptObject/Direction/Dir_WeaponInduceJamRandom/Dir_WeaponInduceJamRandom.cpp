// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_WeaponInduceJamRandom/Dir_WeaponInduceJamRandom.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
			if ((FMath::FRand() * float(iRandNum)) < 1)
			{
				Cast<AAGP_Pawn>(_HumanController.Pawn).InduceJam();
				bJammed = true;
			}
		}
	}
	else
	{
		if ((FMath::FRand() * float(iRandNum)) < 1)
		{
			Cast<AAGP_Pawn>(_HumanController.Pawn).InduceJam();
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
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	iRandNum = int(GetParam(0));
	bOnceOnly = bool(GetParam(1));
	*/
	return true;
}
