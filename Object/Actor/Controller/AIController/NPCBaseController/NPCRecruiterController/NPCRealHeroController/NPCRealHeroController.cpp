// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"

ANPCRealHeroController::ANPCRealHeroController()
{

}

/*
State PawnStartsAsDummy
{
	Function float infront(Vector vec, Pawn Who)
	{
		FVector LookDir = FVector(0,0,0);
		FVector AimDir = FVector(0,0,0);
		LookDir= Vector(Who.Rotation);
		LookDir=Normal(LookDir);
		AimDir=(vec - Who.Location);
		AimDir=Normal(AimDir);
		return (LookDir Dot AimDir);
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
		if (AGP_Pawn(Pawn).bEyeTrack)
		{
			AGP_Pawn(Pawn).EyeTrack();
		}
	}
	Event SeePlayer(Pawn Seen)
	{
		if (VSize((Pawn.Location - Seen.Location)) <= fpPlayerDetectionRange)
		{
			if (infront(Seen.Location,Pawn) < 0.7)
			{
				Pawn.RotationRate.Yaw=0;
				DesiredRotation=rotator((Seen.Location - Pawn.Location));
				FocalPoint=(Pawn.Location + (float(512) *  Vector(DesiredRotation)));
				bRotateToDesired=true;
			}
		}
		else
		{
			if (VSize((Pawn.Location - Seen.Location)) > (fpPlayerDetectionRange * 1.5))
			{
				DesiredRotation=rotInitialRotation;
				FocalPoint=(Pawn.Location + (float(512) *  Vector(DesiredRotation)));
				bRotateToDesired=true;
				Focus=None;
			}
		}
		if ((AGP_Pawn(Seen) != None) && AGP_Pawn(Seen).IsHumanControlled())
		{
			if (CanPawnSeeMe(Seen))
			{
				NotifyPlayerPawnWatchingMe(Seen);
			}
		}
	}
}
*/

