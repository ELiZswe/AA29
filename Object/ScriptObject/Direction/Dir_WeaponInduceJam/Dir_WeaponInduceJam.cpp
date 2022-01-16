// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_WeaponInduceJam/Dir_WeaponInduceJam.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	Cast<AAGP_Pawn>(_HumanController.Pawn).InduceJam();
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
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
