// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_Rifle_Range/EL_Rifle_Range.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_DrillInstructor/NPC_DrillInstructor.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_TowerObserver/NPC_TowerObserver.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"

AEL_Rifle_Range::AEL_Rifle_Range()
{

}

/*
State EyeTracking
{
	Function InstructorTurnToFacePlayer()
	{
		FVector Dir = FVector(0,0,0);
		FRotator RDir = FRotator(0,0,0);
		Dir=(Player.Location - PawnInstructorTwo.Location);
		RDir=rotator(Dir);
		if (Cast<AAgentController>(PawnInstructorTwo.Controller).infront(Player.Location,PawnInstructorTwo) < 0.7)
		{
			AgentController(PawnInstructorTwo.Controller).DesiredRotation=RDir;
			PawnInstructorTwo.DesiredRotation=RDir;
		}
	}
Begin:
	Sleep(0.05);
	if (InstructorMoved)
	{
		InstructorTurnToFacePlayer();
	}
	pawnInstructor.EyeTrack();
	pawnTower1.EyeTrack();
	JL"Loop"
;
}
*/

/*
State fadeoutstate
{
Begin:
	fadeoutTimer=(GetWorld()->GetTimeSeconds() + 2);
	FadeOut(1,true);
	Sleep(0.1);
	if (fadeoutTimer > GetWorld()->GetTimeSeconds())
	{
		JL"Loop"
;
	}
	FadeIn(1,true);
	pawnInstructor.bHidden=true;
	PawnInstructorTwo.bHidden=false;
	InstructorMoved=true;
	PawnInstructorTwo.LoopAnim("DrillIdle",1,0);
	GotoState("EyeTracking","Begin");
}
*/

void AEL_Rifle_Range::PreInit()
{
	/*
	pawnInstructor = Cast<ANPC_DrillInstructor>(CaptureEvent("pawnInstructor"));
	PawnInstructorTwo = Cast<ANPC_DrillInstructor>(CaptureEvent("PawnInstructorTwo"));
	pawnTower1 = Cast<NPC_TowerObserver>(CaptureEvent("pawnTower1"));
	TranslateInstructor = Cast<ATriggerVolume>(CaptureEvent("TranslateInstructor"));
	InstructorStart = Cast<ATriggerVolume>(CaptureEvent("InstructorStart"));
	TranslatePosition = Cast<AAGP_Location>(CaptureEvent("TranslatePosition"));
	locDrillStart = Cast<AAGP_Location>(CaptureEvent("locDrillStart"));
	pawnInstructor.bHidden = false;
	PawnInstructorTwo.bHidden = true;
	PawnInstructorTwo.SetPhysics(PHYS_Falling);
	*/
}

bool AEL_Rifle_Range::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "TranslateInstructor":
		return TranslateInstructorPosition(Trigger, Instigator);
	case "InstructorStart":
		return InstructorStartTrigger(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_Rifle_Range::InstructorStartTrigger(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	bInstructorTranslate = false;
	pawnInstructor.bHidden = false;
	PawnInstructorTwo.bHidden = true;
	PawnInstructorTwo.StopLIPSincAnim();
	*/
	return true;
}

bool AEL_Rifle_Range::TranslateInstructorPosition(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	bInstructorTranslate = true;
	ChangeState("fadeoutstate");
	*/
	return true;
}

void AEL_Rifle_Range::Init()
{
}

void AEL_Rifle_Range::PostInit()
{
}

void AEL_Rifle_Range::PostPostInit()
{
	//GotoState("EyeTracking", "Begin");
}
