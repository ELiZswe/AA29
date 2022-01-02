// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/CivilianController/CivilianController.h"

ACivilianController::ACivilianController()
{

}

/*
State Dummy_Idle
{
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
Begin:
	StopMovement();
}
*/

/*
State Wander_Around
{
	Function PickWanderTarget()
	{
		APathNode* tempPath = nullptr;
		int32 i = 0;
		int32 OldTarget = 0;
		OldTarget=nWanderTargetID;
		do
		{
			nWanderTargetID=int((FMath::FRand() * float(aWanderTargets.Length)));
		}
		until ((nWanderTargetID != OldTarget));
		nNumRoutePoints=-1;
		tempPath=PathNode(FindPathToward(aWanderTargets[nWanderTargetID]));
		if (tempPath == nullptr)
		{
			GotoState("Dummy_Idle");
		}
		nRouteNum=0;
		for (i=0; i<62; i++)
		{
			if (RouteCache[i] != nullptr)
			{
				nNumRoutePoints ++;
			}
		}
		if ((nNumRoutePoints > 0) && (tempPath != nullptr))
		{
			GotoState("Wander_Around","WanderTo");
		}
	}
Begin:
	Sleep(2);
	JL"WanderTo"
;
	LookLeft();
	FinishRotation();
	LookRight();
	FinishRotation();
	LookRight();
	FinishRotation();
	LookLeft();
	FinishRotation();
	if (CheckDistance(RouteCache[nRouteNum].Location,500))
	{
		MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum],,,true);
	}
	else
	{
		MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum]);
	}
	if (RouteCache[nRouteNum].IsA("NPCDoorEntryPathNode"))
	{
		if ((FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])) != nullptr) && FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])).bClosed)
		{
			StopMovement();
			if (OpenDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
				}
			}
		}
	}
	if (nRouteNum < nNumRoutePoints)
	{
		nRouteNum ++;
		if ((FMath::FRand() * float(100)) > float(50))
		{
			JL"Pause"
;
		}
		else
		{
			if ((FMath::FRand() * float(100)) > float(50))
			{
				JL"LookAround"
;
			}
			else
			{
				JL"WanderTo"
;
			}
		}
	}
	PickWanderTarget();
	PickWanderTarget();
}
*/

/*
State LiveGrenade
{
}
*/

/*
State Cowering
{
Begin:
	GotoState("Hide");
}
*/

/*
State Hidden
{
Begin:
	Crouch();
	Pawn.PlayWaiting();
	Pawn.LoopAnim("SurrenderKneesLoop",1,0,15);
}
*/

/*
State Hide
{
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function FindHidingSpot()
	{
		ANPCPathNode* hidingSpot = nullptr;
		ANPCPathNode* tempPath = nullptr;
		AActor* traceHit = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		int32 i = 0;
		APathNode* bestSpot = nullptr;
		float hidingDist = 0;
		float newdist = 0;
		FVector diff = FVector(0,0,0);
		int32 coverChecked = 0;
		int32 searchRadius = 0;
		if (aDangerLocations.Length == 0)
		{
			return;
		}
		hidingDist=-1;
		Stand();
		if (aDangerLocations.Length == 0)
		{
			GotoState("Dummy_Idle");
		}
		coverChecked=0;
		searchRadius=500;
		if (searchRadius < 4000)
		{
			ForEach Pawn.RadiusActors(class'AGP.NPCPathNode',hidingSpot,float(searchRadius))
			{
				if (hidingSpot.npcbcUsingHallway != nullptr)
				{
					continue;
				}
				if (((NPCDuckAndCoverPathNode(hidingSpot) == nullptr) && (NPCCoverPositionPathNode(hidingSpot) == nullptr)) || (NPCFirePositionPathNode(hidingSpot) != nullptr))
				{
					continue;
				}
				coverChecked ++;
				StartTrace=hidingSpot.Location;
				EndTrace=aDangerLocations[0].Location;
				traceHit=Pawn.Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
				if ((traceHit != nullptr) && (! traceHit.IsA("AGP_Character")))
				{
					diff=(Pawn.Location - hidingSpot.Location);
					diff.Z=0;
					newdist=VSize(diff);
					if ((hidingDist < 0) || (newdist < hidingDist))
					{
						hidingDist=newdist;
						bestSpot=hidingSpot;
					}
				}
			}
			if (bestSpot != nullptr)
			{
			}
			searchRadius += 500;
		}
		if (bestSpot != nullptr)
		{
			CoverNode=bestSpot;
			tempPath=NPCPathNode(FindPathToward(bestSpot));
			NPCPathNode(bestSpot).npcbcUsingHallway=Self;
			if (tempPath == nullptr)
			{
				GotoState("Dummy_Idle");
			}
			nNumRoutePoints=-1;
			nRouteNum=0;
			for (i=0; i<62; i++)
			{
				if (RouteCache[i] != nullptr)
				{
					nNumRoutePoints ++;
				}
			}
			if ((nNumRoutePoints > 0) && (tempPath != nullptr))
			{
				GotoState("Hide","MoveToCover");
			}
		}
		else
		{
			GotoState("Dummy_Idle");
		}
	}
Begin:
	StopMovement();
	FindHidingSpot();
	MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum]);
	if (RouteCache[nRouteNum].IsA("NPCDoorEntryPathNode"))
	{
		if ((FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])) != nullptr) && FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])).bClosed)
		{
			StopMovement();
			if (OpenDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
				}
			}
		}
	}
	if (nRouteNum < nNumRoutePoints)
	{
		nRouteNum ++;
		if (! ValidateCover())
		{
			FindHidingSpot();
		}
		JL"MoveToCover"
;
	}
	GotoState("Hidden");
}
*/

/*
void ACivilianController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
	if (Level.TimeSeconds <= 0)
	{
		SetCustomTimer(1, false, "StartUp");
	}
	else
	{
		StartUp();
	}
}
*/

void ACivilianController::Start()
{
	bStart = true;
}

void ACivilianController::StartUp()
{
	FindWanderTargets();
	/*
	if (aWanderTargets.Length == 0)
	{
		GotoState("Dummy_Idle");
	}
	Disable("SeeMonster");
	Enable("HearNoise");
	Enable("SeePlayer");
	GotoState("Wander_Around");
	*/
}

void ACivilianController::FindWanderTargets()
{
	ANPCPathNode* p = nullptr;
	/*
	ForEach AllActors(class'AGP.NPCPathNode', p, "WanderTarget")
	{
		aWanderTargets.insert(aWanderTargets.Length, 1);
		aWanderTargets[(aWanderTargets.Length - 1)] = p;
	}
	*/

}

void ACivilianController::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
}

void ACivilianController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
}

void ACivilianController::NotifyBuzzedByBullet(AActor* aShooter)
{
	/*
	if (aDangerLocations.Length == 0)
	{
		aDangerLocations.insert(aDangerLocations.Length, 1);
	}
	aDangerLocations[0] = aShooter;
	if (GetStateName() != "Hide")
	{
		GotoState("Hide");
	}
	*/
}

void ACivilianController::NotifyHeardBulletImpactNoise(AActor* NoiseMaker, FVector vImpactLocation)
{
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	/*
	StartTrace = Pawn.EyePosition();
	EndTrace = NoiseMaker.Location;
	traceHit = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if ((traceHit == NoiseMaker) || traceHit.IsA("AGP_Character"))
	{
		if (aDangerLocations.Length == 0)
		{
			aDangerLocations.insert(aDangerLocations.Length, 1);
		}
		aDangerLocations[0] = NoiseMaker;
		if (GetStateName() != "Hide")
		{
			GotoState("Hide");
		}
	}
	*/
}

void ACivilianController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
}

void ACivilianController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void ACivilianController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
}

void ACivilianController::NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
{
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	/*
	StartTrace = Pawn.EyePosition();
	EndTrace = twpGrenade.Location;
	traceHit = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if (traceHit == twpGrenade)
	{
		if (aDangerLocations.Length == 0)
		{
			aDangerLocations.insert(aDangerLocations.Length, 1);
		}
		aDangerLocations[0] = twpGrenade;
		GotoState("Hide");
	}
	*/
}

void ACivilianController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
}

void ACivilianController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
}

void ACivilianController::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
}

void ACivilianController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
	float fpAngleToPlayer = 0;
	float fViewingDistance = 0;
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	fViewingDistance = 2700;
	/*
	if (!CheckDistance(pawnSeen.Location, fViewingDistance))
	{
		return;
	}
	fpAngleToPlayer = float((Pawn.Rotation - Normalize(rotator((pawnSeen.Location - Pawn.Location)))).Yaw);
	fpAngleToPlayer = Abs(fpAngleToPlayer);
	if ((fpAngleToPlayer > float(40960)) || (fpAngleToPlayer < float(24576)))
	{
		GOTO JL00A5;
	}
JL00A5:
	StartTrace = Pawn.EyePosition();
	EndTrace = pawnSeen.EyePosition();
	traceHit = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if (traceHit != pawnSeen)
	{
		return;
	}
	if (aDangerLocations.Length == 0)
	{
		aDangerLocations.insert(aDangerLocations.Length, 1);
	}
	aDangerLocations[0] = pawnSeen;
	GotoState("Hide");
	*/
}

void ACivilianController::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	/*
	if (NoiseMaker.IsA("ThrowWeaponPickup"))
	{
		return;
	}
	StartTrace = Pawn.EyePosition();
	EndTrace = NoiseMaker.Location;
	traceHit = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if ((traceHit != None) && ((traceHit == NoiseMaker) || traceHit.IsA("AGP_Character")))
	{
		if (NoiseMaker.IsA("AGP_Weapon"))
		{
			if (aDangerLocations.Length == 0)
			{
				aDangerLocations.insert(aDangerLocations.Length, 1);
			}
			aDangerLocations[0] = NoiseMaker;
			if (GetStateName() != "Hide")
			{
				GotoState("Hide");
			}
		}
		else
		{
			if (CheckDistance(NoiseMaker.Location, 1000))
			{
				if (aDangerLocations.Length == 0)
				{
					aDangerLocations.insert(aDangerLocations.Length, 1);
				}
				aDangerLocations[0] = NoiseMaker;
				if (GetStateName() != "Hide")
				{
					GotoState("Hide");
				}
			}
		}
	}
	*/
}

bool ACivilianController::CheckDistance(FVector Location, float dist)
{
	FVector diff = FVector(0, 0, 0);
	/*
	diff = (Pawn.Location - Location);
	diff.Z = 0;
	if (VSize(diff) < dist)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool ACivilianController::ValidateCover()
{
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	/*
	if (aDangerLocations.Length == 0)
	{
		return true;
	}
	if (aDangerLocations[0] == None)
	{
		aDangerLocations.remove(0, 1);
		return true;
	}
	EndTrace = aDangerLocations[0].Location;
	StartTrace = CoverNode.Location;
	traceHit = Pawn.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if ((traceHit != None) && (!traceHit.IsA("AGP_Character")))
	{
		return true;
	}
	*/
	return false;
}
