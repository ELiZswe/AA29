// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_Rifle_Range/EL_Rifle_Range.h"

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
		if (AgentController(PawnInstructorTwo.Controller).infront(Player.Location,PawnInstructorTwo) < 0.7)
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
	JL'Loop'
;
}
State fadeoutstate
{
Begin:
	fadeoutTimer=(Level.TimeSeconds + 2);
	FadeOut(1,true);
	Sleep(0.1);
	if (fadeoutTimer > Level.TimeSeconds)
	{
		JL'Loop'
;
	}
	FadeIn(1,true);
	pawnInstructor.bHidden=true;
	PawnInstructorTwo.bHidden=false;
	InstructorMoved=true;
	PawnInstructorTwo.LoopAnim('DrillIdle',1,0);
	GotoState('EyeTracking','Begin');
}
*/
