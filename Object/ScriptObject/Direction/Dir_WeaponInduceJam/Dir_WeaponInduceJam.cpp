// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_WeaponInduceJam/Dir_WeaponInduceJam.h"

UDir_WeaponInduceJam::UDir_WeaponInduceJam()
{

}

void UDir_WeaponInduceJam::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJam::DirectionStart()");
	}
	AGP_Pawn(_HumanController.Pawn).InduceJam();
	*/
}

void UDir_WeaponInduceJam::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJam::DirectionFinish()");
	}
	*/
}

bool UDir_WeaponInduceJam::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_WeaponInduceJam::ProcessParams()");
	}
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
