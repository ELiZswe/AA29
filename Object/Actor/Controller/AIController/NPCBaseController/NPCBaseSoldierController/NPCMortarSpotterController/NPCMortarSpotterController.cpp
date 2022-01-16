// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPCMortarSpotterController::ANPCMortarSpotterController()
{
	bHasBinoculars = true;
}

/*
State MoveToFirstSpotterPosition extends MoveToNewCamperPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		if (pnCurrentLocation != nullptr)
		{
			return NPCFirePositionPathNode(pnCurrentLocation);
		}
		else
		{
			return Super::FindNextFiringPosition(fpMaxDistance,bCanJumpToGetThere);
		}
	}
}
*/

/*
State ProvidingSuppressiveFire
{
Begin:
	GotoState("ManningSpotterPosition");
}
*/

/*
State AssaultLocation
{
Begin:
	GotoState("ManningSpotterPosition");
}
*/

/*
State MoveToNewCamperPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		int32 iPathNode = 0;
		ANPCFirePositionPathNode* npcfppnClosest = nullptr;
		float fpClosestFiringPositionDistance = 0;
		float fpCurrentFiringPositionDistance = 0;
		fpMaxDistance=100000;
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Num(); iPathNode++)
		{
			if (! anpcfppnFiringPositions[iPathNode].IsA("NPCCamperFirePositionPathNode"))
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
			if ((anpcfppnFiringPositions[iPathNode].cControllerUsingNode != nullptr) && (anpcfppnFiringPositions[iPathNode].cControllerUsingNode != Self))
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
			if ((fpCurrentFiringPositionDistance < fpClosestFiringPositionDistance) || (npcfppnClosest == nullptr))
			{
				fpClosestFiringPositionDistance=fpCurrentFiringPositionDistance;
				npcfppnClosest=anpcfppnFiringPositions[iPathNode];
			}
		}
		if (npcfppnClosest != nullptr)
		{
			npcfppnLastFirePosition=NPCFirePositionPathNode(pnCurrentLocation);
		}
		return npcfppnClosest;
	}
	Function ArrivedAtFiringPosition()
	{
		NPCChangeState("ManningSpotterPosition");
	}
}
*/

/*
State ManningSpotterPosition
{
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
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
		fpTimeToEndLastInterrupt=(GetWorld()->GetTimeSeconds() + float(30));
	}
	Function NPCChangeState(FName nmState, FName nmLabel)
	{
		if ((Pawn == nullptr) && (nmState != "Dead"))
		{
			return;
		}
		sLastAttemptedStateChange=string(nmState);
		if (nmState == "SearchForTarget")
		{
			return;
		}
		Global.NPCBaseSoldierController(nmState,nmLabel);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (! agpwWeaponHeard.Instigator.Controller.IsA("HumanController")))
		{
			return;
		}
		vLastValidNoiseHeard=agpwWeaponHeard.Location;
		GotoState(GetStateName(),"LookTowardsSound");
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard.IsA("CROWS_HMMWV") || (VSize((pawnHeard.Location - Pawn.Location)) < float(1000)))
		{
			vLastValidNoiseHeard=pawnHeard.Location;
			GotoState(GetStateName(),"LookTowardsSound");
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
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if ((Vehicle(pawnSeen) != nullptr) && Vehicle(pawnSeen).bIsHelicopter)
		{
			return;
		}
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))
		{
			Super::NotifyPlayerPawnInSight(pawnSeen);
		}
		else
		{
			if (((GetWorld()->GetTimeSeconds() - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
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
		CallInFireMission(nullptr,true);
		bSmokeAssaultLocation=false;
		Crouch();
		FocalPoint=vAssaultLocation;
		bRotateToDesired=true;
		FinishRotation();
		Sleep(5);
	}
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCamperFirePositionPathNode"))
	{
		Pawn.SightRadius=75000;
	}
	if (pnCurrentLocation == nullptr)
	{
		Crouch();
		JL"CheckBinoculars"
;
	}
	if (NPCFirePositionPathNode(pnCurrentLocation) != nullptr)
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
		NPCLog("Want to put binoculars " $ string(Cast<AAGP_Pawn>(Pawn)->_InvBinoculars) $ " in hand");
		if (! ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("Item_Binoculars")))
		{
			NPCLog("Trying to put binoculars " $ string(Cast<AAGP_Pawn>(Pawn)->_InvBinoculars) $ " in hand");
			Cast<AAGP_Pawn>(Pawn)->SetWalking(true);
			Cast<AAGP_Pawn>(Pawn)->GetBinoculars();
			Sleep(1.5);
			NPCLog("Binoculars should be in hand: " $ string(Cast<AAGP_Pawn>(Pawn)->getHandsInventory()) $ " Weapon: " $ string(Pawn.Weapon));
		}
	}
	Sleep(0);
	NPCLog("Searching from " $ string(pnCurrentLocation));
	Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(true);
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
	{
		Focus=nullptr;
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		bRotateToDesired=true;
		FinishRotation();
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionLookDirection(true);
		bRotateToDesired=true;
		FinishRotation();
		Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((FMath::FRand() * 1.5));
		Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(true);
		FinishAnim();
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((0.5 + (FMath::FRand() * 1.5)));
		Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(true);
		FinishAnim();
		DetermineFiringPositionLookDirection(false);
		bRotateToDesired=true;
		FinishRotation();
		Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(false);
		FinishAnim();
		Sleep((1 + (FMath::FRand() * 1.5)));
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		Sleep(1);
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	else
	{
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		if (pnCurrentLocation != nullptr)
		{
			FaceNodeDirection();
			bRotateToDesired=true;
			FinishRotation();
		}
		if (FMath::FRand() > 0.5)
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
	Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(false);
	FinishAnim();
	Sleep((FMath::FRand() * 3.5));
	if (NPCPlayerStartMortarSpotter(StartSpot).bSmokeAssaultLocation)
	{
		if (((GetWorld()->GetTimeSeconds() - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
		{
			Log("Too recent a time since last fire mission for smoke/area assault: " $ string((GetWorld()->GetTimeSeconds() - fpTimeLastFireMission)));
			JL"LookAround"
;
		}
		if (FMath::FRand() > 0.5)
		{
			Log("Calling new smoke mission");
			JL"Begin"
;
		}
		else
		{
			Log("Calling area strike for assault");
			CallInFireMission(nullptr,false,true);
		}
	}
	JL"LookAround"
;
	Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(true);
	FinishAnim();
	Focus=nullptr;
	FocalPoint=vCurrentFireMissionLocation;
	bRotateToDesired=true;
	FinishRotation();
	Cast<AAGP_Pawn>(Pawn)->NPCSetWeaponZoom(true);
	FinishAnim();
	if (! bWatchingFireMission)
	{
		JL"LookAround"
;
	}
	Sleep(2);
	JL"LookAtAreaTarget"
;
	Focus=nullptr;
	FocalPoint=vLastValidNoiseHeard;
	bRotateToDesired=true;
	FinishRotation();
	Sleep(3.5);
	JL"LookAround"
;
}
*/

/*
State SearchForTarget
{
	Function bool CanPopAndShoot()
	{
		return false;
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard.IsA("CROWS_HMMWV") || (VSize((pawnHeard.Location - Pawn.Location)) < float(1000)))
		{
			vLastValidNoiseHeard=pawnHeard.Location;
			GotoState("ManningSpotterPosition","LookTowardsSound");
		}
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))
		{
			Super::NotifyPlayerPawnInSight(pawnSeen);
			return;
		}
		if (((GetWorld()->GetTimeSeconds() - fpTimeLastFireMission) < 20) && (fpTimeLastFireMission > 0))
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

void ANPCMortarSpotterController::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

void ANPCMortarSpotterController::Start()
{
	/*
	Super::Start();
	DebugLog(DEBUG_AIMortar, "Current location preset value: " $ string(pnCurrentLocation));
	LocateAssaultLocation();
	if (pnCurrentLocation != nullptr)
	{
		NPCChangeState("ManningSpotterPosition");
	}
	else
	{
		NPCChangeState("MoveToFirstSpotterPosition");
	}
	*/
}

void ANPCMortarSpotterController::FireMissionComplete(FVector vLocation)
{
	int32 iMission = 0;
	/*
	for (iMission = 0; iMission < afmrFireMissions.Num(); iMission++)
	{
		if (afmrFireMissions[iMission].vLocation == vLocation)
		{
			bWatchingFireMission = false;
			afmrFireMissions.remove(iMission, 1);
			return;
		}
	}
	*/
}

void ANPCMortarSpotterController::FireMissionInProgress(FVector vLocation)
{
	int32 iMission = 0;
	/*
	for (iMission = 0; iMission < afmrFireMissions.Num(); iMission++)
	{
		if (afmrFireMissions[iMission].vLocation == vLocation)
		{
			bWatchingFireMission = true;
			vCurrentFireMissionLocation = afmrFireMissions[iMission].vLocation;
			afmrFireMissions[iMission].bMissionFiring = true;
			return;
		}
	}
	*/
}

void ANPCMortarSpotterController::AddFireMissionRequest(FVector vLocation, APawn* pawnTarget)
{
	/*
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController.PlayEventAudio(Self, "EnemySpotted");
	}
	afmrFireMissions.insert(afmrFireMissions.Num(), 1);
	afmrFireMissions[(afmrFireMissions.Num() - 1)].vLocation = vLocation;
	afmrFireMissions[(afmrFireMissions.Num() - 1)].fpTime = GetWorld()->GetTimeSeconds();
	afmrFireMissions[(afmrFireMissions.Num() - 1)].pawnTarget = pawnTarget;
	*/
}

bool ANPCMortarSpotterController::IsValidFireMissionRequest(FVector vLocation, APawn* pawnSeen)
{
	int32 iMission = 0;
	int32 iFireMissionsInArea = 0;
	/*
	if (npcaiccCombatController == nullptr)
	{
		return false;
	}
	for (iMission = 0; iMission < npcaiccCombatController.asfrqFireMissions.Num(); iMission++)
	{
		if (VSize((vLocation - npcaiccCombatController.asfrqFireMissions[iMission].vTargetArea)) < float(5000))
		{
			if ((++iFireMissionsInArea) == 2)
			{
				return false;
			}
		}
	}
	for (iMission = 0; iMission < afmrFireMissions.Num(); iMission++)
	{
		if (VSize((afmrFireMissions[iMission].vLocation - vLocation)) < float(5000))
		{
			return false;
		}
	}
	*/
	return true;
}

bool ANPCMortarSpotterController::CallInFireMission(APawn* pawnSeen, bool bSmokeMission, bool bHEAssaultLocation)
{
	float fpDistanceToTarget = 0;
	float fpTimeToTarget = 0;
	FVector vRandomOffset = FVector(0, 0, 0);
	FVector vTargetLocation = FVector(0, 0, 0);
	FVector vEstimatedLocation = FVector(0, 0, 0);
	FVector vVelocityOffset = FVector(0, 0, 0);
	float fpMinRangeUU = 0;
	float fpMaxRangeUU = 0;
	FVector vDesiredTargetLocation = FVector(0, 0, 0);
	AController* ctrlIterator = nullptr;
	if (((pawnSeen == nullptr) && (!bSmokeMission)) && (!bHEAssaultLocation))
	{
		return false;
	}
	fpMaxRangeUU = 75000;
	fpMinRangeUU = 500;
	/*
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCamperFirePositionPathNode")) && NPCCamperFirePositionPathNode(pnCurrentLocation).bSpotterPosition)
	{
		pawnLastConsidered = pawnSeen;
		if ((((pawnSeen == nullptr) || NPCPlayerStartMortarSpotter(StartSpot).bSmokeAssaultLocation) && bSmokeMission) || bHEAssaultLocation)
		{
			vDesiredTargetLocation = vAssaultLocation;
			fpDistanceToTarget = VSize((Pawn.Location - vDesiredTargetLocation));
		}
		else
		{
			vDesiredTargetLocation = pawnSeen.Location;
			fpDistanceToTarget = VSize((Pawn.Location - pawnSeen.Location));
		}
		DebugLog(DEBUG_AIMortar, "At valid spotter position actual range: " $ string(fpDistanceToTarget) $ " (min: " $ string(fpMinRangeUU) $ ", max: " $ string(fpMaxRangeUU));
		if ((fpDistanceToTarget > fpMinRangeUU) && (fpDistanceToTarget < fpMaxRangeUU))
		{
			if ((!bSmokeMission) && (!IsValidFireMissionRequest(pawnSeen.Location, pawnSeen)))
			{
				return true;
			}
			pawnLastTargeted = pawnSeen;
			vRandomOffset = Normal(VRand());
			vRandomOffset.Z = 0;
			vRandomOffset *= (float(2500) * (1 - (fpMortarRequestSkill / 100)));
			DebugLog(DEBUG_AIMortar, "Scaled by skill Random vector: " $ string(vRandomOffset.X) $ ", " $ string(vRandomOffset.Y) $ ", " $ string(vRandomOffset.Z));
			vTargetLocation = (vDesiredTargetLocation + vRandomOffset);
			DebugLog(DEBUG_AIMortar, "Mortar target estimated at " $ string(vTargetLocation) $ " dist from real location: " $ string((VSize((vTargetLocation - vDesiredTargetLocation)) / 55)) $ "m");
			if (npcaiccCombatController != nullptr)
			{
				fpTimeToTarget = npcaiccCombatController.LookupMortarFlightTime((fpDistanceToTarget / 50));
				if ((!bSmokeMission) && (!bHEAssaultLocation))
				{
					vVelocityOffset = (pawnSeen.Velocity * (fpTimeToTarget + float((npcaiccCombatController.10 / 2))));
					vEstimatedLocation = (vTargetLocation + vVelocityOffset);
				}
				else
				{
					vEstimatedLocation = (vTargetLocation - (float(550) * Vector(Normalize(rotator((vTargetLocation - Pawn.Location))))));
				}
				for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
				{
					if (!ctrlIterator.IsA("NPCBaseSoldierController"))
					{
					}
					if (ctrlIterator.Pawn == nullptr)
					{
					}
					if (VSize((ctrlIterator.Pawn.Location - vEstimatedLocation)) < float(550))
					{
						Log("Aborting mortar strike, friendly NPC's too close");
						return true;
					}
				}
			}
			else
			{
				vEstimatedLocation = vTargetLocation;
				fpTimeToTarget = 0;
			}
			if (npcaiccCombatController != nullptr)
			{
				if (!npcaiccCombatController.AddSupportRequestToQueue(Self, 1, vEstimatedLocation, pawnSeen, bSmokeMission))
				{
					fpTimeLastFireMission = GetWorld()->GetTimeSeconds();
					NPCChangeState("MoveToAlamoPosition");
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}
