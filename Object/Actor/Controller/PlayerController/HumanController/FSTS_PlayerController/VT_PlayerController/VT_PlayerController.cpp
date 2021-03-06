// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/VT_PlayerController/VT_PlayerController.h"
#include "AA29/Object/Actor/EventLab/FSTS_EventLab/FSTS_EventLab.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_DrillInstructor/NPC_DrillInstructor.h"

AVT_PlayerController::AVT_PlayerController()
{

}

void AVT_PlayerController::SetMasterScriptEventLab()
{
	AFSTS_EventLab* lab = nullptr;
	/*
	ForEach DynamicActors(AFSTS_EventLab::StaticClass(), lab)
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
	if ((Cast<AFSTS_NPC_DrillSergeant>(Sarge) == nullptr) && (Cast<ANPC_DrillInstructor>(Sarge) == nullptr))
	{
		return;
	}
	SingleScript->DrillSergeantUsed(Cast<AAGP_Character>(Sarge));
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

