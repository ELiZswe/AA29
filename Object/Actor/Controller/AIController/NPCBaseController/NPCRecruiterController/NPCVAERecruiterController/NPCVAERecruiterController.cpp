// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCVAERecruiterController/NPCVAERecruiterController.h"

ANPCVAERecruiterController::ANPCVAERecruiterController()
{

}

/*
State HandOutLanyard
{
	Function EndState()
	{
		PlayCustomAnimation("LanyardIdle",true);
	}
	Function RemoveBlockingNPC()
	{
		local AGP_Pawn agppIterator;
		if (nameVAEBlockingNPC != "None")
		{
			ForEach DynamicActors(class'AGP.AGP_Pawn',agppIterator,nameVAEBlockingNPC)
			{
				Log("Destroying NPC");
				agppIterator.Destroy();
			}
		}
	}
Begin:
	scPlayer.Focus=Pawn;
	scPlayer.bRotateToDesired=true;
	scPlayer.FinishRotation();
	RemoveBlockingNPC();
	ivaelLanyard=Spawn(class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.Item_VAELanyard",Class'Class')));
	Pawn.AttachToBone(ivaelLanyard,"RHandObject");
	ivaelLanyard.SetDrawScale(0.75);
	ivaelLanyard.SetRelativeLocation(MakeVect(-3.5,-0.75,-1.5));
	ivaelLanyard.SetRelativeRotation(MakeRot(-2048,4096,0));
	Sleep(0.5);
	Pawn.StopLIPSincAnim();
	if ((anameUserActivatedAudio.Length > iAudioIndex) && (anameUserActivatedAudio[iAudioIndex] != "None"))
	{
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex],1,256,1);
	}
	Pawn.AnimBlendParams(1,1,0.1,0);
	Pawn.PlayAnim("LanyardHandoff",1,2,1);
	Sleep(4.5);
	ivaelLanyard.bHidden=false;
	if (bDebug)
	{
		Sleep(3.5);
		Pawn.StopAnimating();
		scPlayer.ClientMessage("NPC Animation paused for attachment adjustment");
		JL"End"
;
	}
	Sleep(4.1);
	ivaelLanyard.Destroy();
	scPlayer.LockPlayer(false,false);
	scPlayer.Focus=None;
	scPlayer.bRotateToDesired=false;
	Sleep(1.93);
	Pawn.StopAnimating(true);
	bRotateToDesired=false;
	Focus=None;
	AGP_Pawn(Pawn).AnimLoopAction="LanyardIdle";
	Pawn.PlayWaiting();
}
*/

/*
State ReceiveLanyard
{
	Function EndState()
	{
		PlayCustomAnimation("LanyardIdle",true);
	}
	Function RemoveBlockingNPC()
	{
		local AGP_Pawn agppIterator;
		if (nameVAEBlockingNPC != "None")
		{
			ForEach DynamicActors(class'AGP.AGP_Pawn',agppIterator,nameVAEBlockingNPC)
			{
				Log("On lanyard return, destroying NPC: " $ string(nameVAEBlockingNPC));
				agppIterator.Destroy();
			}
		}
	}
Begin:
	scPlayer.Focus=Pawn;
	scPlayer.bRotateToDesired=true;
	scPlayer.FinishRotation();
	RemoveBlockingNPC();
	ivaelLanyard=Spawn(class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.Item_VAELanyard",Class'Class')));
	Pawn.AttachToBone(ivaelLanyard,"RHandObject");
	ivaelLanyard.SetDrawScale(0.75);
	ivaelLanyard.SetRelativeLocation(MakeVect(-3.5,-0.75,-1.5));
	ivaelLanyard.SetRelativeRotation(MakeRot(-2048,4096,0));
	Sleep(0.5);
	Pawn.StopLIPSincAnim();
	if ((anameUserActivatedAudio.Length > iAudioIndex) && (anameUserActivatedAudio[iAudioIndex] != "None"))
	{
		Pawn.PlayLIPSincAnim(anameUserActivatedAudio[iAudioIndex],1,256,1);
	}
	Pawn.AnimBlendParams(1,1,0.1,0);
	Pawn.PlayAnim("LanyardReturn",1,2,1);
	Sleep(2.3);
	ivaelLanyard.bHidden=false;
	Sleep(3.7);
	ivaelLanyard.Destroy();
	scPlayer.LockPlayer(false,false);
	scPlayer.Focus=None;
	scPlayer.bRotateToDesired=false;
	Sleep(1.2);
	Pawn.StopAnimating(true);
	bRotateToDesired=false;
	Focus=None;
	AGP_Pawn(Pawn).AnimLoopAction="LanyardIdle";
	Pawn.PlayWaiting();
}
*/

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
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		Super::NotifyPlayerPawnInSight(pawnSeen);
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

