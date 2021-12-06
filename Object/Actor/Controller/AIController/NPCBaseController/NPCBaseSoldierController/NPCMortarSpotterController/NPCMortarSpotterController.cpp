// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"

ANPCMortarSpotterController::ANPCMortarSpotterController()
{

}

/*
State MoveToFirstSpotterPosition extends MoveToNewCamperPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		if (pnCurrentLocation != None)
		{
			return NPCFirePositionPathNode(pnCurrentLocation);
		}
		else
		{
			return Super::FindNextFiringPosition(fpMaxDistance,bCanJumpToGetThere);
		}
	}
}
State ProvidingSuppressiveFire
{
Begin:
	GotoState('ManningSpotterPosition');
}
State AssaultLocation
{
Begin:
	GotoState('ManningSpotterPosition');
}
State MoveToNewCamperPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		int32 iPathNode = 0;
		local NPCFirePositionPathNode npcfppnClosest;
		float fpClosestFiringPositionDistance = 0;
		float fpCurrentFiringPositionDistance = 0;
		fpMaxDistance=100000;
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Length; iPathNode++)
		{
			if (! anpcfppnFiringPositions[iPathNode].IsA('NPCCamperFirePositionPathNode'))
			{
			}
			if (! NPCCamperFirePositionPathNode(anpcfppnFiringPositions[iPathNode]).bSpotterPosition)
			{
			}
			if (pnCurrentLocation == anpcfppnFiringPositions[iPathNode])
			{
			}
			if (Abs((Pawn.Location.Z - anpcfppnFiringPositions[iPathNode].Location.Z)) > anpcfppnFiringPositions[iPathNode].fpMaxVerticalDeltaToFind)
			{
			}
			if (npcfppnLastFirePosition == anpcfppnFiringPositions[iPathNode])
			{
			}
			if ((anpcfppnFiringPositions[iPathNode].cControllerUsingNode != None) && (anpcfppnFiringPositions[iPathNode].cControllerUsingNode != Self))
			{
			}
			if ((string(anpcfppnFiringPositions[iPathNode].Tag) != string(Tag)) && (string(anpcfppnFiringPositions[iPathNode].Tag) != sNPCWaypointTag))
			{
			}
			if (VSize((anpcfppnFiringPositions[iPathNode].Location - Pawn.Location)) > fpMaxDistance)
			{
			}
			if (! LineOfSightTo(anpcfppnFiringPositions[iPathNode]))
			{
			}
			fpCurrentFiringPositionDistance=VSize((Pawn.Location - anpcfppnFiringPositions[iPathNode].Location));
			if ((fpMaxDistance > 0) && (fpCurrentFiringPositionDistance > fpMaxDistance))
			{
			}
			if ((fpCurrentFiringPositionDistance < fpClosestFiringPositionDistance) || (npcfppnClosest == None))
			{
				fpClosestFiringPositionDistance=fpCurrentFiringPositionDistance;
				npcfppnClosest=anpcfppnFiringPositions[iPathNode];
			}
		}
		if (npcfppnClosest != None)
		{
			npcfppnLastFirePosition=NPCFirePositionPathNode(pnCurrentLocation);
		}
		return npcfppnClosest;
	}
	Function ArrivedAtFiringPosition()
	{
		NPCChangeState('ManningSpotterPosition');
	}
}
State ManningSpotterPosition
{
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Function EndState()
	{
		Pawn.bIgnoresFog=false;
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		fpTimeToEndLastInterrupt=(Level.TimeSeconds + float(30));
	}
	Function NPCChangeState(FName nmState, FName nmLabel)
	{
		if ((Pawn == None) && (nmState != 'Dead'))
		{
			return;
		}
		sLastAttemptedStateChange=string(nmState);
		if (nmState == 'SearchForTarget')
		{
			return;
		}
		Global.NPCBaseSoldierController(nmState,nmLabel);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((agpwWeaponHeard.Instigator != None) && (agpwWeaponHeard.Instigator.Controller != None)) && (! agpwWeaponHeard.Instigator.Controller.IsA('HumanController')))
		{
			return;
		}
		vLastValidNoiseHeard=agpwWeaponHeard.Location;
		GotoState(GetStateName(),'LookTowardsSound');
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
		if (pawnHeard.IsA('CROWS_HMMWV') || (VSize((pawnHeard.Location - Pawn.Location)) < float(1000)))
		{
			vLastValidNoiseHeard=pawnHeard.Location;
			GotoState(GetStateName(),'LookTowardsSound');
		}
	}
	Function DetermineFiringPositionLookDirection(bool bLookLeft)
	{
		FRotator rotLookDirection = FRotator(0,0,0);
		rotLookDirection=pnCurrentLocation.Rotation;
		if (bLookLeft)
		{
			(rotLookDirection.Yaw -= int(pnCurrentLocation.fpVisionConeAngle));
		}
		else
		{
			(rotLookDirection.Yaw += int(pnCurrentLocation.fpVisionConeAngle));
		}
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(rotLookDirection)));
	}
	Function int32 GetSearchRotationRate()
	{
		return 2048;
	}
	Function DetermineFiringPositionFromDirection(bool bLookLeft, Rotator rotLookDirection)
	{
		if (bLookLeft)
		{
			(rotLookDirection.Yaw -= int(pnCurrentLocation.fpVisionConeAngle));
		}
		else
		{
			(rotLookDirection.Yaw += int(pnCurrentLocation.fpVisionConeAngle));
		}
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(rotLookDirection)));
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((Vehicle(pawnSeen) != None) && Vehicle(pawnSeen).bIsHelicopter)
		{
			return;
		}
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))
		{
			Super::NotifyPlayerPawnInSight(pawnSeen);
		}
		else
		{
			if (((Level.TimeSeconds - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
			{
				return;
			}
			CallInFireMission(pawnSeen);
		}
	}
Begin:
	Pawn.bIgnoresFog=true;
	if (bSmokeAssaultLocation)
	{
		Log("Spotter at " $ string(pnCurrentLocation) $ " calling in smoke mission");
		CallInFireMission(None,true);
		bSmokeAssaultLocation=false;
		Crouch();
		FocalPoint=vAssaultLocation;
		bRotateToDesired=true;
		FinishRotation();
		Sleep(5);
	}
	if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCCamperFirePositionPathNode'))
	{
		Pawn.SightRadius=75000;
	}
	if (pnCurrentLocation == None)
	{
		Crouch();
		JL'CheckBinoculars'
;
	}
	if (NPCFirePositionPathNode(pnCurrentLocation) != None)
	{
		if (NPCFirePositionPathNode(pnCurrentLocation).bCrouchHere || bHasBinoculars)
		{
			Crouch();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bProneHere)
			{
				Prone();
			}
		}
	}
	if (bHasBinoculars)
	{
		NPCLog("Want to put binoculars " $ string(AGP_Pawn(Pawn)._InvBinoculars) $ " in hand");
		if (! ((Pawn.Weapon != None) && Pawn.Weapon.IsA('Item_Binoculars')))
		{
			NPCLog("Trying to put binoculars " $ string(AGP_Pawn(Pawn)._InvBinoculars) $ " in hand");
			AGP_Pawn(Pawn).SetWalking(true);
			AGP_Pawn(Pawn).GetBinoculars();
			Sleep(1.5);
			NPCLog("Binoculars should be in hand: " $ string(AGP_Pawn(Pawn).getHandsInventory()) $ " Weapon: " $ string(Pawn.Weapon));
		}
	}
	Sleep(0);
	NPCLog("Searching from " $ string(pnCurrentLocation));
	AGP_Pawn(Pawn).NPCSetWeaponZoom(true);
	if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode'))
	{
		Focus=None;
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		bRotateToDesired=true;
		FinishRotation();
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionLookDirection(true);
		bRotateToDesired=true;
		FinishRotation();
		AGP_Pawn(Pawn).NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((FRand() * 1.5));
		AGP_Pawn(Pawn).NPCSetWeaponZoom(true);
		FinishAnim();
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		AGP_Pawn(Pawn).NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((0.5 + (FRand() * 1.5)));
		AGP_Pawn(Pawn).NPCSetWeaponZoom(true);
		FinishAnim();
		DetermineFiringPositionLookDirection(false);
		bRotateToDesired=true;
		FinishRotation();
		AGP_Pawn(Pawn).NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((1 + (FRand() * 1.5)));
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		Sleep(1);
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	else
	{
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		if (pnCurrentLocation != None)
		{
			FaceNodeDirection();
			bRotateToDesired=true;
			FinishRotation();
		}
		if (FRand() > 0.5)
		{
			LookLeft();
			FinishRotation();
			Sleep(1);
			LookRight();
			FinishRotation();
			Sleep(1);
			LookRight();
			FinishRotation();
			Sleep(1);
		}
		else
		{
			LookRight();
			FinishRotation();
			Sleep(1);
			LookLeft();
			FinishRotation();
			Sleep(1);
			LookLeft();
			FinishRotation();
			Sleep(1);
		}
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	AGP_Pawn(Pawn).NPCSetWeaponZoom(false);
	FinishAnim();
	Sleep((FRand() * 3.5));
	if (NPCPlayerStartMortarSpotter(StartSpot).bSmokeAssaultLocation)
	{
		if (((Level.TimeSeconds - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
		{
			Log("Too recent a time since last fire mission for smoke/area assault: " $ string((Level.TimeSeconds - fpTimeLastFireMission)));
			JL'LookAround'
;
		}
		if (FRand() > 0.5)
		{
			Log("Calling new smoke mission");
			JL'Begin'
;
		}
		else
		{
			Log("Calling area strike for assault");
			CallInFireMission(None,false,true);
		}
	}
	JL'LookAround'
;
	AGP_Pawn(Pawn).NPCSetWeaponZoom(true);
	FinishAnim();
	Focus=None;
	FocalPoint=vCurrentFireMissionLocation;
	bRotateToDesired=true;
	FinishRotation();
	AGP_Pawn(Pawn).NPCSetWeaponZoom(true);
	FinishAnim();
	if (! bWatchingFireMission)
	{
		JL'LookAround'
;
	}
	Sleep(2);
	JL'LookAtAreaTarget'
;
	Focus=None;
	FocalPoint=vLastValidNoiseHeard;
	bRotateToDesired=true;
	FinishRotation();
	Sleep(3.5);
	JL'LookAround'
;
}
State SearchForTarget
{
	Function bool CanPopAndShoot()
	{
		return false;
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
		if (pawnHeard.IsA('CROWS_HMMWV') || (VSize((pawnHeard.Location - Pawn.Location)) < float(1000)))
		{
			vLastValidNoiseHeard=pawnHeard.Location;
			GotoState('ManningSpotterPosition','LookTowardsSound');
		}
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))
		{
			Super::NotifyPlayerPawnInSight(pawnSeen);
			return;
		}
		if (((Level.TimeSeconds - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
		{
			return;
		}
		if (! CallInFireMission(pawnSeen))
		{
			Super::NotifyPlayerPawnInSight(pawnSeen);
		}
	}
}
*/
