// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/VT_PlayerController/VT_PlayerController.h"

AVT_PlayerController::AVT_PlayerController()
{

}

void AVT_PlayerController::SetMasterScriptEventLab()
{
	/*
	local FSTS_EventLab lab;
	ForEach DynamicActors(class'FSTS.FSTS_EventLab', lab)
	{
		SetEventLab(lab);
		SingleScript = lab;
		GOTO JL002A;
	JL002A:
	}
	*/
}

void AVT_PlayerController::DrillSergeantUsed(AActor* Sarge)
{
	/*
	if ((FSTS_NPC_DrillSergeant(Sarge) == nullptr) && (NPC_DrillInstructor(Sarge) == nullptr))
	{
		return;
	}
	SingleScript.DrillSergeantUsed(AGP_Character(Sarge));
	*/
}

void AVT_PlayerController::ShowMenu()
{
	/*
	if (myHUD.IsMoviePlaying())
	{
		myHUD.StopMovie();
	}
	else
	{
		Super::ShowMenu();
	}
	*/
}

