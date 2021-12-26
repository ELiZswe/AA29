// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"

ANPCBaseSoldierController::ANPCBaseSoldierController()
{
	fpGrenadePitch = 16384;
}

static const int32 MAX_TARGET_STATUS_HISTORY = 10;
static const int32 NPCS_TO_TRACK = 10;
static const int32 BOP_MAJOR_ADVANTAGE = 0;
static const int32 BOP_MINOR_ADVANTAGE = 1;
static const int32 BOP_NO_ADVANTAGE = 2;
static const int32 BOP_MINOR_DISADVANTAGE = 3;
static const int32 BOP_MAJOR_DISADVANTAGE = 4;


/*
State LookAtDeadTeammate
{
	Function NPCSayManDown()
	{
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(4,true,true);
		}
	}
	Function NPCSayAlertOnAttack()
	{
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(18,true,true);
		}
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"End"
;
	}
	NPCLog("Teammate killed, looking in direction of body for killer");
	Crouch();
	Pawn.RotationRate.Yaw=int((fpTurnRate + float(4000)));
	FocalPoint=vDeadTeammateLocation;
	bRotateToDesired=true;
	FinishRotation();
	NPCSayManDown();
	UnslingWeapon();
	Sleep(((0.75 + FRand()) + (5 * (1 - (fNPCExperience / 100)))));
	NPCLog("Finished staring at body");
	IncreaseNervousness(11);
	NPCSayAlertOnAttack();
	if (Enemy == nullptr)
	{
		NPCLog("Returning to SearchForTarget");
		GotoState("SearchForTarget");
	}
	else
	{
		Focus=Enemy;
		bRotateToDesired=true;
		FinishRotation();
		GotoState("Targeting");
	}
}
*/

/*
State HeardPlayer
{
	Function bool PerformPreLook()
	{
		UnslingWeapon();
		return false;
	}
	Function PerformFinishedLooking()
	{
		NPCLog("Done turning towards sound, starting search for target");
		NPCChangeState("SearchForTarget");
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		if ((Focus != nullptr) && Focus.IsA("Weapon"))
		{
			NPCLog("AICC told about weapon sound " $ string(Focus));
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportHeardGunfire(Self,Focus.Location))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
			}
			return;
		}
		if ((npcaiccCombatController != nullptr) && (Focus != nullptr))
		{
			if (npcaiccCombatController.ReportHeardNoise(Self,Focus.Location))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
				NPCLog("AICC told about sound " $ string(Focus.Tag));
				return;
			}
		}
	}
}
*/

/*
State Targeting
{
	Function bool NeedToTurn()
	{
		if (Enemy == nullptr)
		{
			return true;
		}
		if (Enemy != Focus)
		{
			Focus=Enemy;
			return true;
		}
		if (GetAngleToLocation(Enemy.Location) < 0.9)
		{
			return true;
		}
		return false;
	}
	Function EndState()
	{
		StopCustomTimer("LostSightOfEnemyTimer");
		AGP_Pawn(Pawn).ResetLean();
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		return true;
	}
	Function float GetMaxVisionCone()
	{
		return 12000;
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		if (pnDNCTempPathNode != nullptr)
		{
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyEnemyNotVisible()
	{
		NPCLog("Lost target, going to search mode");
		Focus=None;
		Global.fpTerrainAvoidanceAltitudeBump();
		if (fpTimeSinceUntilTargetLost > 0)
		{
			return;
		}
		NPCLog("NotifyEnemyNotVisible() entered for APawn* " $ string(Enemy));
		if ((Enemy != nullptr) && (Enemy.Health <= 0))
		{
			fpTimeSinceUntilTargetLost=Level.TimeSeconds;
		}
		else
		{
			fpTimeSinceUntilTargetLost=((Level.TimeSeconds + 1.5) + (FRand() * 5));
		}
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		float fpMaxIgnoreTime = 0;
		if (GetConfidenceLevel() >= float(70))
		{
			fpMaxIgnoreTime=15;
		}
		else
		{
			fpMaxIgnoreTime=10;
		}
		if (! IsInCover())
		{
			(fpMaxIgnoreTime /= 2.5);
		}
		npcioiLastTarget=None;
		NotifyBuzzedByBullet(aShooter);
		if (iNPCTacticalOrders == 200)
		{
			NPCLog("Soldier buzzed in hold fire mode, changing to controlled fire");
			ChangeOrders(300);
		}
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("BulletWhip");
		}
		if (! IsInCover())
		{
			if ((! Pawn.bIsProne) && (! Pawn.bIsCrouched))
			{
				Crouch();
			}
		}
		if (((Level.TimeSeconds - fpTargetingStartTime) > 2) && (((Level.TimeSeconds - fpTargetingStartTime) / fpMaxIgnoreTime) > FRand()))
		{
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportUnderFire(Self,aShooter))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					return;
				}
			}
		}
		if (IsSuppressed())
		{
			if (pnCurrentPathNode.IsA("NPCFirePositionPathNode"))
			{
				NPCLog("Current firing position is too scary, move to new one");
				Stand();
				NPCChangeState("MoveToNewFiringPosition");
				return;
			}
		}
		if (Pawn.bIsProne || Pawn.bIsCrouched)
		{
			if (! IsInCover())
			{
				if (iRoundsFiredSinceCameOutOfCover > 0)
				{
					if (FRand() > 0.6)
					{
						GotoState("FindCoverThenFight");
						return;
					}
				}
			}
			return;
		}
		NPCLog("Buzzed while scanning and standing - now crouching");
		Crouch();
	}
	Function LostSightOfEnemyTimer()
	{
		sTargetingStatus="Lost contact timer ended";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (Enemy == nullptr)
		{
			if ((Vehicle(pawnLastEnemy) != nullptr) && Vehicle(pawnLastEnemy).bIsHelicopter)
			{
				NPCChangeState("ReturnToPatrol");
				return;
			}
			sTargetingStatus="Lost contact, enemy gone, switching to searching";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState("SearchForTarget");
			return;
		}
		else
		{
			if (! LineOfSightTo(Enemy))
			{
				if ((Vehicle(Enemy) != nullptr) && Vehicle(Enemy).bIsHelicopter)
				{
					NPCChangeState(GetLastStateName());
					return;
				}
				if (iNPCCurrentOrders == 9)
				{
					NPCChangeState("AssaultLocation");
					return;
				}
				if (npcaiccCombatController.ReportLostContact(Self,Enemy))
				{
					NPCLog(string(Self) $ "." $ string(GetStateName()) $ ".LostSightOfEnemyTimer() Lost contact, command set to " $ sNextAICCAction);
					sTargetingStatus="Lost contact, performing AICC action: '" $ sNextAICCAction $ "'";
					SaveTargetingStatusHistory(sTargetingStatus);
					npcaiccCombatController.ProcessCombatAction(Self);
					return;
				}
				else
				{
					sTargetingStatus="No AICC action, switching to searching";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCChangeState("SearchForTarget");
					return;
				}
			}
			else
			{
				StopCustomTimer("LostSightOfEnemyTimer");
				NPCChangeState("Targeting","AimAtTarget");
				return;
			}
		}
		SetCustomTimer(0.5,false,"LostSightOfEnemyTimer");
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (fpTimeSinceUntilTargetLost > 0)
		{
			fpTimeSinceUntilTargetLost=0;
			if (Enemy == pawnSeen)
			{
				return;
			}
		}
		if (pawnSeen != Enemy)
		{
			Global.amrtMortarData(pawnSeen);
		}
		else
		{
			fpTimeSinceUntilTargetLost=0;
			fpTimeSinceLastEnemySighting=Level.TimeSeconds;
			if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("SeePlayer");
			}
			if ((npcaiccCombatController != nullptr) && (pawnSeen != nullptr))
			{
				NotifyPlayerPawnInSight(pawnSeen);
				npcaiccCombatController.ReportContact(Self,npcaiccCombatController.0,pawnSeen,int(EvaluateEnemyThreat(pawnSeen)));
			}
			else
			{
				Global.amrtMortarData(pawnSeen);
			}
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard == Enemy)
		{
			return;
		}
		if (! LineOfSightTo(pawnHeard))
		{
			return;
		}
		NPCLog("NotifyHeardPlayerNoise() entered");
		if ((VSize((pawnHeard.Location - vLastTarget)) < float(250)) && (pawnHeard != Enemy))
		{
			NPCLog("Overriding targeting based on newly heard sound that's really close:" $ string(pawnHeard));
			vLastTarget=pawnHeard.Location;
			NPCChangeState("SearchForTarget","TurnToNoise");
		}
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		Global.agpobj(fpLoudness,pawnHeard);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
		int32 iDifference = 0;
		if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (! agpwWeaponHeard.Instigator.Controller.IsA("HumanController")))
		{
			return;
		}
		if ((Enemy != nullptr) && (agpwWeaponHeard == Enemy.Weapon))
		{
			return;
		}
		if (! LineOfSightTo(agpwWeaponHeard.Instigator))
		{
			return;
		}
		Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		iDifference=int(Abs(float((rotator((Pawn.Location - agpwWeaponHeard.Location)).Yaw - Pawn.Rotation.Yaw))));
		NPCLog("Heard weapon difference from: " $ string(iDifference));
		if ((VSize((Pawn.Location - vSoundLocation)) < float(250)) && (float(iDifference) > fpNodeVisionConeAngle))
		{
			NPCLog("Heard close weapon noise out of vision cone");
			vLastTarget=agpwWeaponHeard.Location;
			NPCChangeState("SearchForTarget","TurnToNoise");
		}
	}
	Function bool ShouldLean()
	{
		FVector LookDir = FVector(0,0,0);
		FVector AimDir = FVector(0,0,0);
		float fpAngleRadians = 0;
		if (Enemy == nullptr)
		{
			return false;
		}
		LookDir= Vector(pnCurrentLocation.Rotation);
		LookDir=Normal(LookDir);
		AimDir=(Enemy.Location - pnCurrentLocation.Location);
		AimDir=Normal(AimDir);
		fpAngleRadians=(LookDir Dot AimDir);
		if (fpAngleRadians < 0.707)
		{
			return true;
		}
		return false;
	}
Begin:
	Sleep(0);
	fpTimeSinceUntilTargetLost=0;
	fpTargetingStartTime=((Level.TimeSeconds + 3) + (FRand() * 3));
	if (Pawn == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	UnslingWeapon();
	Sleep(0.1);
	StopMovement();
	fpTargetingStartTime=((Level.TimeSeconds + 4) + (FRand() * 3));
	if (Pawn == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	Sleep(0.1);
	sTargetingStatus="Adjusting posture";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((Enemy == nullptr) || ((Enemy != nullptr) && (! LineOfSightTo(Enemy))))
	{
		if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
		{
			NPCLog("in fire position, adjusting posture for firing");
			if (NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Length > 0)
			{
				npcdacpnActiveDuckAndCoverNode=NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode[Rand(NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Length)];
				pnDNCTempPathNode=None;
				if (pnDNCTempPathNode != npcdacpnActiveDuckAndCoverNode)
				{
					pnDNCTempPathNode=PathNode(FindPathToward(npcdacpnActiveDuckAndCoverNode,true));
					if (pnDNCTempPathNode != nullptr)
					{
						MoveToward(pnDNCTempPathNode,Enemy,,true,true);
					}
					else
					{
					}
				}
				pnDNCTempPathNode=None;
			}
			else
			{
				npcdacpnActiveDuckAndCoverNode=None;
			}
		}
	}
	if (((Enemy == nullptr) || ((Enemy != nullptr) && (! LineOfSightTo(Enemy)))) || IsInCover())
	{
		if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bShootWhileProne)
			{
				if (! Pawn.bIsProne)
				{
					Prone();
					Sleep(0.5);
				}
			}
			else
			{
				if (NPCFirePositionPathNode(pnCurrentLocation).bShootWhileCrouched)
				{
					if (! Pawn.bIsCrouched)
					{
						Crouch();
						Sleep(0.25);
					}
				}
				else
				{
					if (Pawn.bIsCrouched)
					{
						Stand();
						Sleep(0.25);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Stand();
							Sleep(0.5);
						}
					}
				}
			}
		}
		else
		{
			NPCLog("Not in firing position, using APawn* preference for crouching");
			if ((FRand() * 100) < fNPCLikesToCrouch)
			{
				Crouch();
				Sleep(0.25);
			}
		}
	}
	fpTargetingStartTime=((Level.TimeSeconds + 3) + (FRand() * 3));
	if (Pawn == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	sTargetingStatus="Turning to target";
	SaveTargetingStatusHistory(sTargetingStatus);
	StopMovement();
	if (Enemy != nullptr)
	{
		iDefaultYawTurnRate=Pawn.RotationRate.Yaw;
		(Pawn.RotationRate.Yaw += 10000);
		FocalPoint=Enemy.Location;
		Focus=None;
		bRotateToDesired=true;
		FinishRotation();
		Pawn.RotationRate.Yaw=iDefaultYawTurnRate;
		Focus=Enemy;
		bRotateToDesired=true;
		FinishRotation();
		Sleep(0.1);
	}
	if (Pawn == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	if (Pawn.Weapon == nullptr)
	{
		NPCChangeState("FindCover");
	}
	if ((Enemy != nullptr) && (! IsLocationInFront(Enemy.Location)))
	{
		Sleep(0.1);
		JL"TurnToEnemy"
;
	}
	sTargetingStatus="Starting aim process";
	SaveTargetingStatusHistory(sTargetingStatus);
	StopMovement();
	if (! SafeToFire())
	{
		sTargetingStatus="Not safe to fire, pausing";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep((FRand() * 0.75));
		if (! SafeToFire())
		{
			sTargetingStatus="Stil not safe to fire, moving to new firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Not safe to fire, going to switch positions");
			if (iNPCCurrentOrders == 9)
			{
				NPCChangeState("AssaultLocation");
				JL"End"
;
			}
			NPCChangeState("MoveToNewFiringPosition");
			JL"End"
;
		}
	}
	if (AGP_Weapon(Pawn.Weapon) != nullptr)
	{
		AGP_Weapon(Pawn.Weapon).ForceTempRaiseWeapon();
	}
	if (! Pawn.Weapon.IsZoomed())
	{
		AGP_Weapon(Pawn.Weapon).ServerZoom(true);
	}
	if (Pawn.Weapon.IsInState("BusyZooming"))
	{
		Sleep(0.1);
	}
	Walk();
	AGP_Pawn(Pawn).ChangeAnimation();
	if (Enemy != nullptr)
	{
		vLastTarget=Enemy.Location;
		pawnLastEnemy=Enemy;
		Focus=Enemy;
		FinishRotation();
		Sleep(0.1);
	}
	else
	{
		sTargetingStatus="No enemy, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.05);
		NPCChangeState("SearchForTarget");
		JL"End"
;
	}
	if (NPCFirePositionPathNode(pnCurrentLocation) != nullptr)
	{
		if (ShouldLean())
		{
			sTargetingStatus="Leaning at firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (NPCFirePositionPathNode(pnCurrentLocation).bShouldLeanLeftToShoot)
			{
				AGP_Pawn(Pawn).LeanLeft();
			}
			else
			{
				if (NPCFirePositionPathNode(pnCurrentLocation).bShouldLeanRightToShoot)
				{
					AGP_Pawn(Pawn).LeanLeft();
				}
			}
			sTargetingStatus="Finished leaning at firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
		}
	}
	NPCLog("Aiming at target");
	sTargetingStatus="Calculating aim time";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (iNPCCurrentOrders == 8)
	{
		fpMaxAimTime=0.55;
		fpAimTime=((FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			fpMaxAimTime=0.85;
			fpAimTime=((FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
		}
		else
		{
			if ((iNPCCurrentOrders == 3) || (iNPCCurrentOrders == 9))
			{
				fpMaxAimTime=1.25;
				fpAimTime=((FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
			}
			else
			{
				fpMaxAimTime=1.75;
				fpAimTime=((FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
			}
		}
	}
	if ((((VSize((Pawn.Location - vLastTarget)) < float(800)) && (iNPCCurrentOrders != 9)) && (Pawn.Weapon != nullptr)) && (! Pawn.Weapon.IsA("RocketWeapon")))
	{
		if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
		{
			sTargetingStatus="Activating shoot from hip";
			SaveTargetingStatusHistory(sTargetingStatus);
			Pawn.bIsHipShooting=true;
			Pawn.ChangeAnimation();
			sTargetingStatus="Finished activating shoot from hip";
			SaveTargetingStatusHistory(sTargetingStatus);
		}
		fpAimTime=((FRand() * 0.15) + 0.1);
	}
	else
	{
		(fpAimTime += ((FRand() * 0.5) * (VSize((Pawn.Location - vLastTarget)) / float(5000))));
		Pawn.bIsHipShooting=false;
		sTargetingStatus="Using non shoot from hip aiming";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
		{
			Pawn.ChangeAnimation();
		}
		if ((Enemy != nullptr) && Enemy.IsA("Vehicle"))
		{
			if ((Pawn.Weapon != nullptr) && (! Pawn.Weapon.IsA("RocketWeapon")))
			{
				fpAimTime=((FRand() * 1) + 0.5);
			}
			else
			{
				if (FRand() > 0.8)
				{
					fpAimTime=0.5;
				}
			}
		}
	}
	if (Pawn.Weapon == nullptr)
	{
		NPCChangeState("FindCover");
		JL"End"
;
	}
	sTargetingStatus="Aiming sleep: " $ string(fpAimTime);
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(fpAimTime);
	iRoundsFiredSinceCameOutOfCover=0;
	if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("ThrowWeapon"))
	{
		sTargetingStatus="ShootTarget, with grenade in hand, swapping";
		SaveTargetingStatusHistory(sTargetingStatus);
		AGP_Pawn(Pawn).SwapHands();
		Sleep(0.75);
		JL"ShootTarget"
;
	}
	sTargetingStatus="ShootTarget, testing APawn* and then enemy";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (Pawn == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	if (Pawn.Weapon == nullptr)
	{
		NPCChangeState("FindCover");
	}
	if (AGP_Weapon(Pawn.Weapon).IsInState("BusyTempLowering"))
	{
		sTargetingStatus="ShootTarget, Waiting for weapon up: " $ string(Pawn.Weapon.GetStateName());
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL"ShootTarget"
;
	}
	if (NeedToTurn())
	{
		if (Enemy == nullptr)
		{
			NPCChangeState("SearchForTarget");
			JL"End"
;
		}
		sTargetingStatus="Need to turn to target, angle " $ string(GetAngleToLocation(Enemy.Location));
		SaveTargetingStatusHistory(sTargetingStatus);
		Focus=Enemy;
		FocalPoint=Enemy.Location;
		bRotateToDesired=true;
		FinishRotation();
		Sleep(0.25);
		Focus=Enemy;
		JL"TurnToEnemy"
;
	}
	if (Enemy != nullptr)
	{
		if (Focus != Enemy)
		{
			Focus=Enemy;
			Sleep(0.25);
		}
	}
	if (((Enemy != nullptr) && (VSize((Pawn.Location - Enemy.Location)) <= float(1650))) && (! Enemy.IsA("Vehicle")))
	{
		sTargetingStatus="Close range enemy, testing to see if NPC has Rocket";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon")) && (agpwSecondary != nullptr))
		{
			Sleep(0.1);
			sTargetingStatus="RPG in hand, too close, switching";
			SaveTargetingStatusHistory(sTargetingStatus);
			AICCMessageSwitchWeapons(true);
			JL"End"
;
		}
	}
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode")) && (! pnCurrentLocation.IsA("NPCCamperFirePositionPathNode")))
	{
		sTargetingStatus="At non-camper firing position, testing leave time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("At non-camper fire position - been here for " $ string((Level.TimeSeconds - fpTargetingStartTime)) $ " seconds");
		if (((fpTargetingStartTime != 0) && (Level.TimeSeconds >= fpTargetingStartTime)) && ((Level.TimeSeconds - fpTimeEnteredCover) > 5))
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot && (FRand() <= 0.75))
			{
				NPCChangeState("ManningPopAndShootFirePosition");
				JL"End"
;
			}
			else
			{
				if (iNPCCurrentOrders == 9)
				{
					sTargetingStatus="Time to resume assault";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCLog("Signaling we should move to closer assault firing position");
					NPCChangeState("AssaultLocation");
					JL"RealEnd"
;
				}
				sTargetingStatus="Time to leave";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCLog("Signaling we should move to new firing position");
				NPCChangeState("MoveToNewFiringPosition");
				JL"End"
;
			}
		}
	}
	if (IsConcerned() && (! IsInCover()))
	{
		sTargetingStatus="Nervous in open";
		SaveTargetingStatusHistory(sTargetingStatus);
		actThreat=Enemy;
		if ((pnCurrentLocation != nullptr) && (! pnCurrentLocation.IsA("NPCFirePositionPathNode")))
		{
			sTargetingStatus="Nervous in open, finding cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NPC is nervous and not in fighting position, trying to find cover");
			NPCChangeState("FindCoverThenFight");
			JL"End"
;
		}
	}
	if ((Enemy != nullptr) && IsVisionBlockedBySmokeGrenade(Enemy.Location))
	{
		sTargetingStatus="Vision Blocked by smoke";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("LostEnemy");
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportLostContact(Self,Enemy))
			{
				sTargetingStatus="Smoke blocked, AICC ordering change";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(Self);
				JL"End"
;
			}
		}
		sTargetingStatus="Smoke blocking our view, going to SearchForTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Smoke blocking target view - going to search for target");
		NPCChangeState("SearchForTarget");
		JL"End"
;
	}
	if (ShouldThrowGrenade())
	{
		sTargetingStatus="Want to throw grenade";
		SaveTargetingStatusHistory(sTargetingStatus);
		vGrenadeTarget=Enemy.Location;
		NPCChangeState("ThrowingGrenade");
		JL"End"
;
	}
	else
	{
		if (! SafeToFire())
		{
			sTargetingStatus="Not safe to fire!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.1);
			JL"AimAtTarget"
;
		}
		if ((Enemy != nullptr) && (GetAngleToLocation(Enemy.Location) < 0.9))
		{
			sTargetingStatus="Valid enemy, he's now to our back";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Angle to enemy: " $ string(GetAngleToLocation(Enemy.Location)));
			JL"TurnToEnemy"
;
		}
		if ((((Enemy == nullptr) && (Pawn != nullptr)) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon"))
		{
			NPCChangeState("SearchForTarget");
			JL"End"
;
		}
		if (AGP_Weapon(Pawn.Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Pawn.Weapon.GotoState("BusyFixingJam");
			AGP_Weapon(Pawn.Weapon).bIsJammed=false;
			if (Pawn.Weapon.IsInState("BusyFixingJam"))
			{
				Sleep(0.1);
			}
		}
		if (AGP_Weapon(Pawn.Weapon).IsInState("BusyRaisingWeapon"))
		{
			Sleep(0.25);
		}
		if ((Enemy != nullptr) && (VSize((Pawn.Location - Enemy.Location)) > Level.DistanceFogStart))
		{
			if ((FRand() > 0.5) && ((Pawn.Weapon != nullptr) && (! Pawn.Weapon.IsA("RocketWeapon"))))
			{
				vTargetToSuppressLocation=Enemy.Location;
				NPCChangeState("ProvidingSuppressiveFire");
			}
			else
			{
				fpTimeSinceUntilTargetLost=Level.TimeSeconds;
				NPCChangeState("SearchForTarget");
				Log("Lost sight by fog distance, switching to search for target");
			}
			JL"End"
;
		}
		sTargetingStatus="Firing";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((Enemy != nullptr) && (! LineOfSightTo(Enemy)))
		{
			sTargetingStatus="Lost sight after shot";
			SaveTargetingStatusHistory(sTargetingStatus);
			NotifyEnemyNotVisible();
			JL"WatchForTarget"
;
		}
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr))
		{
			NPCLog("Current ammo count for weapon: " $ string(Pawn.Weapon) $ " is: " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
		}
		if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			sTargetingStatus="need to reload";
			SaveTargetingStatusHistory(sTargetingStatus);
			if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("WeaponJam");
			}
			if (npcaiccCombatController != nullptr)
			{
				sTargetingStatus="Reported reload need to AICC";
				SaveTargetingStatusHistory(sTargetingStatus);
				AICCMessageReload();
			}
			else
			{
				NPCChangeState("ReloadWeapon");
			}
			JL"End"
;
		}
	}
	if (IsInCover())
	{
		sTargetingStatus="In Cover, adjusting rate";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (iNPCTacticalOrders == 300)
		{
			iMinRoundsToFireBeforeDucking=2;
			iMaxRoundsToFireBeforeDucking=5;
		}
		else
		{
			iMinRoundsToFireBeforeDucking=5;
			iMaxRoundsToFireBeforeDucking=10;
		}
		if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FRand() * float(iMaxRoundsToFireBeforeDucking))))
		{
			sTargetingStatus="We've fired enough to duck";
			SaveTargetingStatusHistory(sTargetingStatus);
			iRoundsFiredSinceCameOutOfCover=0;
			AGP_Pawn(Pawn).ResetLean();
			AGP_Pawn(Pawn).ChangeAnimation();
			NPCLog("Going to ducking after firing " $ string(iRoundsFiredSinceCameOutOfCover) $ " rounds");
			if ((NPCFirePositionPathNode(pnCurrentLocation) != nullptr) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
			{
				NPCChangeState("ManningPopAndShootFirePosition");
			}
			if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
			{
				sTargetingStatus="In Cover, waiting between bursts";
				SaveTargetingStatusHistory(sTargetingStatus);
				Crouch();
				if (LineOfSightTo(Enemy))
				{
					Sleep((0.25 + FRand()));
				}
				else
				{
					Sleep((FRand() * 10));
					Stand();
				}
			}
			sTargetingStatus="after firing burst and ready to shoot again";
			SaveTargetingStatusHistory(sTargetingStatus);
			JL"AimAtTarget"
;
		}
	}
	else
	{
		if (iNPCTacticalOrders == 300)
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				iMinRoundsToFireBeforeDucking=int((2 + (FRand() * 2)));
				iMaxRoundsToFireBeforeDucking=int((5 + (FRand() * 5)));
			}
		}
		else
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				iMinRoundsToFireBeforeDucking=int((5 + (FRand() * 2)));
				iMaxRoundsToFireBeforeDucking=int((float(10) + (FRand() * 5)));
			}
		}
		if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FRand() * float(iMaxRoundsToFireBeforeDucking))))
		{
			iRoundsFiredSinceCameOutOfCover=0;
			Sleep(FClamp((FRand() + 0.4),0.4,0.9));
			sTargetingStatus="Goto ShootTarget after burst sleep";
			SaveTargetingStatusHistory(sTargetingStatus);
			JL"ShootTarget"
;
		}
	}
	if ((Enemy != nullptr) && (Enemy.Health <= 0))
	{
		sTargetingStatus="Enemy dead/lost";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Enemy now down");
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("EnemyKilled");
		}
		if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
		{
			NPCChangeState("ManningPopAndShootFirePosition");
			JL"End"
;
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportKilledEnemy(Self,Enemy))
			{
				sTargetingStatus="Enemy dead, reporting to AICC";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(Self);
				JL"End"
;
			}
		}
		sTargetingStatus="No AICC or it didn't handle it, enemy dead";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (IsInCover())
		{
			NPCChangeState("SearchForTarget");
		}
		else
		{
			if (iNPCCurrentOrders == 9)
			{
				NPCChangeState("AssaultLocation");
				JL"RealEnd"
;
			}
			NPCChangeState("FindCoverThenFight");
		}
		JL"End"
;
	}
	if (Pawn.Weapon != nullptr)
	{
		sTargetingStatus="Pause between rounds fired";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((0.1 / Pawn.Weapon.FireAdjust) > 0.08)
		{
			Sleep((0.1 / Pawn.Weapon.FireAdjust));
		}
		else
		{
			Sleep(0.08);
		}
	}
	else
	{
		Sleep(0.1);
	}
	if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.weaponType == 4))
	{
		sTargetingStatus="Sniper going back to AimAtTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL"AimAtTarget"
;
	}
	sTargetingStatus="Returning to ShootTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	JL"ShootTarget"
;
	Focus=None;
	sTargetingStatus="WatchForTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	fpWatchingForLostTargetTime=((Level.TimeSeconds + (FRand() * 5)) + 3);
	sTargetingStatus="Watching for lost target";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (Level.TimeSeconds >= fpWatchingForLostTargetTime)
	{
		if ((Vehicle(Enemy) != nullptr) && Vehicle(Enemy).bIsHelicopter)
		{
			NPCChangeState(GetLastStateName());
			JL"End"
;
		}
		if (iNPCCurrentOrders == 9)
		{
			sTargetingStatus="Time to resume assault after losing contact";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Signaling we should move to closer assault firing position after losing contact");
			NPCChangeState("AssaultLocation");
			JL"RealEnd"
;
		}
		if (npcaiccCombatController.ReportLostContact(Self,Enemy))
		{
			sTargetingStatus="Lost contact, performing AICC action";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (! ((sLastCombatAction ~= "DoNothing") || (sLastCombatAction ~= "Ignore")))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
				JL"End"
;
			}
			else
			{
				sTargetingStatus="Lost contact, ignoring bad AICC action, switching to searching state";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState("SearchForTarget");
				JL"End"
;
			}
		}
		else
		{
			sTargetingStatus="Lost contact, performing No AICC action, switching to searching state";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState("SearchForTarget");
			JL"End"
;
		}
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		sTargetingStatus="LOS to enemy, trying ShootTarget again";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL"AimAtTarget"
;
	}
	sTargetingStatus="Still watching for target to reappear in: " $ string((fpWatchingForLostTargetTime - Level.TimeSeconds));
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(0.6);
	JL"KeepWatching"
;
	if ((npcdacpnActiveDuckAndCoverNode != nullptr) && (npcdacpnActiveDuckAndCoverNode.npcpnPrimaryFiringPosition != nullptr))
	{
		sTargetingStatus="Ending duck and cover in targeting, moving back";
		SaveTargetingStatusHistory(sTargetingStatus);
		pnDNCTempPathNode=None;
		if (pnDNCTempPathNode != npcdacpnActiveDuckAndCoverNode)
		{
			pnDNCTempPathNode=PathNode(FindPathToward(npcdacpnActiveDuckAndCoverNode.npcpnPrimaryFiringPosition,true));
			if (pnDNCTempPathNode != nullptr)
			{
				MoveToward(pnDNCTempPathNode,Enemy,,true,true);
			}
			else
			{
			}
		}
		pnDNCTempPathNode=None;
		sTargetingStatus="Finished moving back from duck and cover in targeting";
		SaveTargetingStatusHistory(sTargetingStatus);
		npcdacpnActiveDuckAndCoverNode=None;
	}
	NPCLog("End of Targeting initialization");
	sTargetingStatus="Done with Targeting latent code";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((Pawn != nullptr) && (Pawn.Health > 0))
	{
		sTargetingStatus="Pawn still alive at end of targeting, forcing to new order";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (iNPCCurrentOrders == 9)
		{
			NPCChangeState("AssaultLocation");
		}
		else
		{
			NPCChangeState("FindCoverThenFight");
		}
	}
}
*/

/*
State ReloadWeapon
{
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Function bool ReloadCurrentWeapon()
	{
		int32 iClip = 0;
		int32 iFullestClipIndex = 0;
		int32 iFullestClipCount = 0;
		sTargetingStatus="Reloading current weapon";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr))
		{
			if ((((Pawn.Weapon.GetCurrentAmmoType().AmmoAmount > 0) && (Enemy != nullptr)) && LineOfSightTo(Enemy)) && (VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)))
			{
				return false;
			}
			if (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount > 0)
			{
				if (Pawn.Weapon == agpwPrimary)
				{
					aiPrimaryAmmoClips.insert (0,1);
					aiPrimaryAmmoClips[0]=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
				}
				else
				{
					aiSecondaryAmmoClips.insert (0,1);
					aiSecondaryAmmoClips[0]=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
				}
			}
			if (Pawn.Weapon == agpwPrimary)
			{
				for (iClip=0; iClip<aiPrimaryAmmoClips.Length; iClip++)
				{
					if (aiPrimaryAmmoClips[iClip] > iFullestClipCount)
					{
						iFullestClipCount=aiPrimaryAmmoClips[iClip];
						iFullestClipIndex=iClip;
					}
				}
			}
			else
			{
				for (iClip=0; iClip<aiSecondaryAmmoClips.Length; iClip++)
				{
					if (aiSecondaryAmmoClips[iClip] > iFullestClipCount)
					{
						iFullestClipCount=aiSecondaryAmmoClips[iClip];
						iFullestClipIndex=iClip;
					}
				}
			}
			if (iFullestClipCount > 0)
			{
				if (Pawn.Weapon == agpwPrimary)
				{
					Pawn.Weapon.GetCurrentAmmoType().AmmoAmount=aiPrimaryAmmoClips[iFullestClipIndex];
					aiPrimaryAmmoClips.remove (iFullestClipIndex,1);
				}
				else
				{
					Pawn.Weapon.GetCurrentAmmoType().AmmoAmount=aiSecondaryAmmoClips[iFullestClipIndex];
					aiSecondaryAmmoClips.remove (iFullestClipIndex,1);
				}
				return true;
			}
		}
		NPCLog("No ammo or no weapon for reloading");
		NPCLog("Weapon: " $ string(Pawn.Weapon));
		if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
		{
			NPCLog("ammo type: " $ string(Pawn.Weapon.GetCurrentAmmoType()));
		}
		return false;
	}
Begin:
	Sleep(0);
	AGP_Pawn(Pawn).ResetLean();
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon"))
	{
		NPCLog("Rocket weapon: " $ string(Pawn.Weapon) $ " with " $ string(iRPGCount) $ " RPGs");
		if (iRPGCount > 0)
		{
			Stand();
			Sleep(0.25);
			sTargetingStatus="Reloading RPG";
			SaveTargetingStatusHistory(sTargetingStatus);
			iRPGCount --;
			if (Level.NetMode == NM_DedicatedServer)
			{
			}
			Pawn.Weapon.Reload();
			AGP_Pawn(Pawn).GotoState("BusyReloading");
			NPCLog(string(Self) $ " Put RPG into reload state");
			if (AGP_Pawn(Pawn).IsInState("BusyReloading"))
			{
				Sleep(0.1);
			}
			sTargetingStatus="Reloading handling of RPG done";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep((2 - ((fNPCExperience / 100) * 1.7)));
			NPCLog(string(Self) $ " Done sleeping after reloading RPG");
			if (Level.NetMode == NM_DedicatedServer)
			{
			}
			if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			sTargetingStatus="RPG reloaded";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.5);
			NPCChangeState("Targeting","AimAtTarget");
			JL"End"
;
		}
		else
		{
			NPCLog("Out of ammo for RPG");
			if ((((AGP_Pawn(Pawn).getShoulderInventory() != nullptr) && AGP_Pawn(Pawn).getShoulderInventory().IsA("Weapon")) && (AGP_Weapon(AGP_Pawn(Pawn).getShoulderInventory()).GetCurrentAmmoType() != nullptr)) && (AGP_Weapon(AGP_Pawn(Pawn).getShoulderInventory()).GetCurrentAmmoType().AmmoAmount > 0))
			{
				AICCMessageSwitchWeapons();
				JL"End"
;
			}
			else
			{
				if ((npcaiccCombatController != nullptr) && npcaiccCombatController.ReportOutOfAmmo(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					JL"End"
;
				}
				AICCMessageFallBack();
			}
			JL"End"
;
		}
	}
	else
	{
		if (ReloadCurrentWeapon())
		{
			if (! Pawn.bIsProne)
			{
				Crouch();
			}
			AGP_Pawn(Pawn).NPC_Reload();
			if (AGP_Pawn(Pawn).IsInState("BusyReloading"))
			{
				Sleep(0.1);
			}
			Sleep(0.5);
			if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			if (npcaiccCombatController != nullptr)
			{
				NPCChangeState("Targeting","AdjustPosture");
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
				JL"End"
;
			}
			else
			{
				NPCChangeState("Targeting","AdjustPosture");
			}
		}
		else
		{
			if (((((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount > 0)) && (Enemy != nullptr)) && LineOfSightTo(Enemy)) && (VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)))
			{
				NPCChangeState("Targeting","TurnToEnemy");
				JL"End"
;
			}
			NPCChangeState("RetreatFromBattle");
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportOutOfAmmo(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					JL"End"
;
				}
			}
			JL"End"
;
		}
	}
	NPCChangeState(GetLastStateName());
}
*/

/*
State FiringM203
{
}
*/

/*
State ThrowingGrenade
{
	Function SetDesiredTarget(Actor aTarget)
	{
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnEnemy)
	{
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function EndState()
	{
		NPCLog("Leaving ThrowingGrenade");
	}
	Function SetThrowPitch()
	{
		FRotator Rot = FRotator(0,0,0);
		float fpDistance = 0;
		float fpVariation = 0;
		fpDistance=VSize((Pawn.Location - vGrenadeTarget));
		Rot=Pawn.Rotation;
		if ((fpDistance != 0) && (fpDistance <= float(3272)))
		{
			if (FRand() > 0.5)
			{
				fpVariation=(FRand() * (6 - (fNPCExperience / 20)));
			}
			else
			{
				fpVariation=((FRand() * (6 - (fNPCExperience / 20))) - 1);
			}
			if ((fpDistance + fpVariation) > float(1500))
			{
				(fpDistance += fpVariation);
			}
			if (fpDistance < float(262))
			{
				fpDistance=262;
			}
			fpGrenadePitch=(8192 * (fpDistance / 1960));
			if (fpGrenadePitch > float(8192))
			{
				fpGrenadePitch=8192;
			}
		}
		else
		{
			fpGrenadePitch=8192;
		}
		Log("Grenade Target distance: " $ string((fpDistance / 55)) $ "m, pitch: " $ string(fpGrenadePitch));
		Rot.Pitch=int(fpGrenadePitch);
		Pawn.SetViewRotation(Rot);
		SetRotation(Rot);
	}
	Function RestorePawnPitch()
	{
		FRotator Rot = FRotator(0,0,0);
		Rot=Rotation;
		Rot.Pitch=0;
		SetRotation(Rot);
	}
	Function PostGrenadeThrowTask()
	{
		int32 iLastThreatIndex = 0;
		if (Enemy != nullptr)
		{
			NPCLog("Returning from throwing grenade to targeting");
			NPCChangeState("Targeting");
		}
		else
		{
			iLastThreatIndex=GetHighestThreatContactIndex();
			if ((iLastThreatIndex != -1) && ((Level.TimeSeconds - arcContactHistory[iLastThreatIndex].fpTimeSeen) < 30))
			{
				SetDesiredTarget(arcContactHistory[iLastThreatIndex].pawnContact);
				return;
			}
			else
			{
				NPCLog("Returning from throwing grenade to search for target");
				NPCChangeState("SearchForTarget");
			}
		}
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDiedEnd"
;
	}
	StopMovement();
	AGP_Pawn(Pawn).ResetLean();
	if (AGP_Pawn(Pawn)._InvGrenades[iDesiredGrenadeIndex] == 0)
	{
		NPCLog("Ack - out of this grenade!");
		JL"End"
;
	}
	AGP_Pawn(Pawn).DesiredGrenade=None;
	switch(iDesiredGrenadeIndex)
	{
		case Pawn.0:
		AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_RGD5_Frag",Class'Class'));
		break;
		case Pawn.1:
		AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
		break;
		case Pawn.2:
		AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun",Class'Class'));
		break;
		case Pawn.3:
		AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M14_Incendiary",Class'Class'));
		break;
		case Pawn.5:
		AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Demo_DoorBreacher",Class'Class'));
		break;
		default:
	}
	if (AGP_Pawn(Pawn).DesiredGrenade == nullptr)
	{
		NPCLog("No desired grenade found!");
		JL"End"
;
	}
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("Found grenade " $ string(AGP_Pawn(Pawn).DesiredGrenade) $ " to swap in place of current weapon: " $ string(Pawn.Weapon));
	NPCLog("Hands inventory now contains: " $ string(AGP_Pawn(Pawn).getHandsInventory()));
	AGP_Pawn(Pawn).SwapHands();
	if (agpwPrimary != nullptr)
	{
		Sleep(agpwPrimary.GetAnimDuration("Drop"));
	}
	if (agpwSecondary != nullptr)
	{
		Sleep(agpwSecondary.GetAnimDuration("Select"));
	}
	Sleep(1);
	NPCLog("Hands inventory contains after swap: " $ string(AGP_Pawn(Pawn).getHandsInventory()));
	NPCLog("Weapon swapping done - weapon in hand is now: " $ string(Pawn.Weapon));
	if (! Pawn.Weapon.IsA("ThrowWeapon"))
	{
		NPCLog("Apparently the weapon in hand is no longer a throw weapon: " $ string(Pawn.Weapon));
		JL"End"
;
	}
	NPCLog("Put throw weapon (grenade) into hand: " $ string(Pawn.Weapon));
	NPCLog("Trying to turn towards last known location for grenade toss");
	FocalPoint=vGrenadeTarget;
	bRotateToDesired=true;
	FinishRotation();
	Sleep(0.5);
	Stand();
	Sleep(0.5);
	NPCLog("Weapon is now in state " $ string(Pawn.Weapon.GetStateName()));
	NPCLog("Pulling pin on " $ string(Pawn.Weapon));
	Pawn.Weapon.Instigator=Pawn;
	Pawn.Weapon.Fire(0);
	Sleep(0.5);
	NPCLog("Weapon is now in state " $ string(Pawn.Weapon.GetStateName()));
	ThrowWeapon(Pawn.Weapon)._bTossNotThrow=false;
	NPCLog("Throwing grenade here: " $ string(Pawn.Weapon) $ " weapon is in state: " $ string(Pawn.Weapon.GetStateName()));
	SetThrowPitch();
	sTargetingStatus="Throwing grenade at pitch " $ string(Pawn.GetViewRotation().Pitch);
	SaveTargetingStatusHistory(sTargetingStatus);
	NPCLog("Pitch right before grenade throw (PRY): " $ string(Pawn.GetViewRotation().Pitch) $ "," $ string(Pawn.GetViewRotation().Roll) $ "," $ string(Pawn.GetViewRotation().Yaw));
	Pawn.Weapon.Instigator=Pawn;
	Pawn.Weapon.Fire(0);
	ThrowWeapon(Pawn.Weapon).ServerThrow();
	if (npcaiccCombatController == nullptr)
	{
		NPCSay(22,true,true);
	}
	Sleep(2.5);
	if (NPCFirePositionPathNode(pnCurrentPathNode) != nullptr)
	{
		if (NPCFirePositionPathNode(pnCurrentPathNode).bProneForCover)
		{
			Prone();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentPathNode).bCrouchForCover)
			{
				Crouch();
			}
			else
			{
				Prone();
			}
		}
	}
	else
	{
		Prone();
	}
	sTargetingStatus="Threw grenade and dropped to cover, waiting for boom";
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(4);
	RestorePawnPitch();
	NPCLog("Pitch for grenade throw after restoration (PRY): " $ string(GetViewRotation().Pitch) $ "," $ string(GetViewRotation().Roll) $ "," $ string(GetViewRotation().Yaw));
	NPCLog("Bringing primary weapon back into hand after throwing");
	sTargetingStatus="Bringing up previous weapon";
	SaveTargetingStatusHistory(sTargetingStatus);
	Crouch();
	Sleep(0.25);
	AGP_Pawn(Pawn).SwapHands();
	Sleep(agpwPrimary.GetAnimDuration("Drop"));
	if (agpwSecondary != nullptr)
	{
		Sleep(agpwSecondary.GetAnimDuration("Select"));
	}
	Sleep(0.5);
	sTargetingStatus="Primary weapon should be in hand now";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (FRand() > 0.8)
	{
		Sleep(((FRand() * 5) + 2.5));
		JL"Begin"
;
	}
	PostGrenadeThrowTask();
	if (iNPCCurrentOrders == 9)
	{
		NPCChangeState("AssaultLocation");
	}
	else
	{
		if ((Enemy != nullptr) && LineOfSightTo(Enemy))
		{
			NPCChangeState("Targeting","ShootTarget");
		}
		else
		{
			NPCChangeState("FindCoverThenFight");
		}
	}
}
*/

/*
State FindCoverThenFight extends FindCover
{
	Function NotifyEnemyNotVisible()
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (Pawn.bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))) && (VSize((Pawn.Location - pawnSeen.Location)) < float(1000)))
		{
			Enemy=pawnSeen;
			pawnLastPawnSeen=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Function NPCCoverPositionPathNode FindCoverPathNode(bool bFindFarthestPointFromThreat)
	{
		local NPCFirePositionPathNode npcfpn;
		npcfpn=Global.vAdjustedPathNodeLocation(2500);
		if ((npcfpn == nullptr) || (! npcfpn.bIsCover))
		{
			return Global.ReloadSound(bFindFarthestPointFromThreat);
		}
		else
		{
			return npcfpn;
		}
	}
	Function bool ShouldRun()
	{
		return true;
	}
	Function InLastNodeBeforeCover()
	{
	}
	Function FName GetNoCoverState()
	{
		return "SearchForTarget";
	}
	Function FName GetCoverState()
	{
		return "SearchForTarget";
	}
	Function InCoverAction()
	{
		NPCLog("Found cover, going to search for target");
		if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			NPCChangeState("ReloadWeapon");
			return;
		}
		UnslingWeapon();
		StopMovement();
		Crouch();
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(15)) + (FRand() * 15));
		if ((Enemy != nullptr) && LineOfSightTo(Enemy))
		{
			Focus=Enemy;
		}
		else
		{
			if ((pawnLastEnemy != nullptr) && LineOfSightTo(pawnLastEnemy))
			{
				Enemy=pawnLastEnemy;
				Focus=pawnLastEnemy;
			}
		}
		if (Enemy != nullptr)
		{
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Function bool FinalCoverAction()
	{
		if ((Enemy == nullptr) && Pawn.LineOfSightTo(Enemy))
		{
			DesiredRotation=rotator((Enemy.Location - Pawn.Location));
			Focus=Enemy;
			FocalPoint=Enemy.Location;
		}
		else
		{
			DesiredRotation=pnCoverNode.Rotation;
			Focus=None;
			FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCoverNode.Rotation)));
		}
		bRotateToDesired=true;
		return true;
	}
Begin:
	if (IsInCover())
	{
		if ((AGP_Pawn(Pawn)._InvGrenades[Pawn.1] > 0) && (FRand() < fpChanceOfThrowingFragOnFallback))
		{
			StopMovement();
			NPCLog("Dropping smoke and running");
			AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
			if (AGP_Pawn(Pawn).DesiredGrenade != nullptr)
			{
				Crouch();
				AGP_Pawn(Pawn).SwapHands();
				Sleep(1.5);
				if (Pawn.Weapon.IsA("ThrowWeapon"))
				{
					Pawn.Weapon.Instigator=Pawn;
					Pawn.Weapon.Fire(0);
					Sleep(0.75);
					ThrowWeapon(Pawn.Weapon)._bTossNotThrow=true;
					Pawn.Weapon.Fire(0);
					ThrowWeapon(Pawn.Weapon).ServerThrow();
					Sleep(3.5);
					AGP_Pawn(Pawn).SwapHands();
				}
			}
		}
	}
	if (FRand() < fpChanceOfShootingOnFallback)
	{
		Pawn.RotationRate.Yaw=int((fpTurnRate + float(2500)));
		FocalPoint=vTargetToSuppressLocation;
		bRotateToDesired=true;
		FinishRotation();
		UnslingWeapon();
		StopMovement();
		fpAimTime=0;
		if ((Pawn.Weapon != nullptr) && (! Pawn.Weapon.IsA("RocketWeapon")))
		{
			for (iRoundsFiredSinceCameOutOfCover=0; iRoundsFiredSinceCameOutOfCover<20; iRoundsFiredSinceCameOutOfCover++)
			{
				if (FRand() > 0.9)
				{
				}
				if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
				{
				}
				FireWeapon();
				Sleep(0.1);
			}
		}
	}
	JL"Begin"
;
}
*/

/*
State SearchForTarget
{
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding.IsA("Mover") && (! Mover(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Function SetEndTime()
	{
		if (((pnCurrentLocation != nullptr) && (NPCFirePositionPathNode(pnCurrentLocation) != nullptr)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
		{
			fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * 3));
			return;
		}
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 5) + (FRand() * 3));
	}
	Function EndState()
	{
		fpTimeToLeaveFiringPosition=0;
	}
	Function PlayLostContact()
	{
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(6,true,false);
		}
		RequestCancellingSuppressiveFire(vLastTarget);
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if ((fpTimeSinceLastEnemySighting > 0) && (Level.TimeSeconds > (fpTimeSinceLastEnemySighting + 20)))
		{
			fpTimeSinceLastEnemySighting=0;
			NPCLog("Lost contact with enemy");
			if (npcaiccCombatController == nullptr)
			{
				PlayLostContact();
			}
			NotifyEnemyNotVisible();
		}
	}
	Function NotifyEnemyGrenadeClose(ThrowWeaponPickup twpGrenade)
	{
		FVector vPawnLoc = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		local Actor traceHit;
		if (twpGrenade == nullptr)
		{
			return;
		}
		if ((VSize((Pawn.Location - twpGrenade.Location)) > float(1500)) || (! LineOfSightTo(twpGrenade)))
		{
			if (VSize((Pawn.Location - twpGrenade.Location)) < fpNPCMaxVisualRange)
			{
				AddGrenadeContact(twpGrenade);
			}
			return;
		}
		if (IsInCover())
		{
			vPawnLoc=Pawn.Location;
			(vPawnLoc.Z += Pawn.CrouchEyeHeight);
			traceHit=Trace(HitLocation,HitNormal,twpGrenade.Location,vPawnLoc,true);
			if (traceHit != twpGrenade)
			{
				NPCLog("Crouching to avoid grenade");
				NPCChangeState(GetStateName(),"DuckFromGrenade");
				return;
			}
			vPawnLoc=Pawn.Location;
			(vPawnLoc.Z += Pawn.ProneEyeHeight);
			traceHit=Trace(HitLocation,HitNormal,twpGrenade.Location,vPawnLoc,true);
			if (traceHit != twpGrenade)
			{
				NPCLog("Proning to avoid grenade");
				NPCChangeState(GetStateName(),"ProneFromGrenade");
				return;
			}
			Global.agpwSecondary(twpGrenade);
		}
		else
		{
			Global.agpwSecondary(twpGrenade);
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard == pawnLastHeard)
		{
			return;
		}
		if (! LineOfSightTo(pawnHeard))
		{
			return;
		}
		pawnLastHeard=pawnHeard;
		if (VSize((Pawn.Location - pawnHeard.Location)) < float(1312))
		{
			if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon")) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		NotifyHeardPlayerNoise(fpLoudness,pawnHeard);
		vLastTarget=pawnHeard.Location;
		NPCChangeState("SearchForTarget","TurnToNoise");
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
		if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (! agpwWeaponHeard.Instigator.Controller.IsA("HumanController")))
		{
			return;
		}
		if (VSize((Pawn.Location - vSoundLocation)) > float(200))
		{
			if (! LineOfSightTo(agpwWeaponHeard.Instigator))
			{
				return;
			}
		}
		if (VSize((Pawn.Location - vSoundLocation)) < float(1312))
		{
			if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon")) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		vLastTarget=agpwWeaponHeard.Location;
		NPCChangeState("SearchForTarget","TurnToNoise");
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (VSize((Pawn.Location - pawnSeen.Location)) < float(1312))
		{
			if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon")) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 2))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		float fpMaxIgnoreTime = 0;
		if (GetConfidenceLevel() >= float(70))
		{
			fpMaxIgnoreTime=15;
		}
		else
		{
			fpMaxIgnoreTime=10;
		}
		NotifyBuzzedByBullet(aShooter);
		if (iNPCTacticalOrders == 200)
		{
			NPCLog("Soldier buzzed in hold fire mode, changing to controlled fire");
			ChangeOrders(300);
		}
		fpTimeLastBuzzed=(Level.TimeSeconds + (FRand() * 10));
		if ((! Pawn.bIsProne) && (! Pawn.bIsCrouched))
		{
			Crouch();
		}
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("BulletWhip");
		}
		if (IsInCover())
		{
			if (((Level.TimeSeconds - fpTimeEnteredCover) > 4.5) && (((Level.TimeSeconds - fpTimeEnteredCover) / fpMaxIgnoreTime) > FRand()))
			{
				if (npcaiccCombatController != nullptr)
				{
					if (npcaiccCombatController.ReportUnderFire(Self,aShooter))
					{
						npcaiccCombatController.ProcessCombatAction(Self);
						return;
					}
				}
			}
			else
			{
				return;
			}
		}
		if (! IsInCover())
		{
			Stand();
			NPCChangeState("FindCoverThenFight");
			return;
		}
		if (IsSuppressed())
		{
			if (pnCurrentPathNode.IsA("NPCFirePositionPathNode") && bFindAlamoFirePosition)
			{
				NPCLog("Current firing position is too scary, move to new one");
				NPCChangeState("MoveToNewFiringPosition");
				return;
			}
		}
		if (Pawn.bIsProne || Pawn.bIsCrouched)
		{
			return;
		}
		NPCLog("Buzzed while scanning and standing - now crouching");
		Crouch();
	}
	Function bool CanPopAndShoot()
	{
		return true;
	}
	Function int32 GetSearchRotationRate()
	{
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.weaponType == 4))
		{
			return 1024;
		}
		else
		{
			return 4096;
		}
	}
	Function bool ShouldUseBinoculars()
	{
		FVector vStartShot = FVector(0,0,0);
		FVector vEndShot = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		local Actor traceHit;
		traceHit=Trace(HitLocation,HitNormal,vEndShot,vStartShot,true);
		return false;
	}
Begin:
	Sleep(0);
	StopMovement();
	fpTimeEnteredCover=Level.TimeSeconds;
	if (! Pawn.bNetRelevant)
	{
		if (((Level.TimeSeconds - fpTimeEnteredCover) < 5) && (! Pawn.bNetRelevant))
		{
			Sleep(1);
		}
		if (! Pawn.bNetRelevant)
		{
			if (iNPCCurrentOrders == 0)
			{
				NPCChangeState("ReturnToPatrol");
			}
			else
			{
				if (iNPCCurrentOrders == 5)
				{
					JL"Begin"
;
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL"Begin"
;
					}
					else
					{
						NPCChangeState("MoveToNewFiringPosition");
					}
				}
			}
			JL"End"
;
		}
	}
	if (npcioiLastTarget != nullptr)
	{
		Sleep((FRand() * 5));
		NPCChangeState("Targeting");
		JL"End"
;
	}
	if (npcaiccCombatController == nullptr)
	{
		SetEndTime();
	}
	if (Enemy != nullptr)
	{
		vLastTarget=Enemy.Location;
		JL"TurnToNoise"
;
	}
	NPCLog("Starting search mode");
	JL"AdjustPosture"
;
	if ((Normal( Vector(Pawn.Rotation)) Dot Normal((Pawn.Location - vLastTarget))) < 0.707)
	{
		Sleep((((1 - (fNPCExperience / 100)) * 0.5) + (FRand() * 0.25)));
	}
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	FocalPoint=vLastTarget;
	Focus=None;
	bRotateToDesired=true;
	FinishRotation();
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if ((((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode")) && (! NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)) && (Level.TimeSeconds > fpTimeLastBuzzed))
	{
		if (NPCFirePositionPathNode(pnCurrentLocation).bCrouchHere)
		{
			Crouch();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bProneHere)
			{
				Prone();
			}
			else
			{
				Stand();
			}
		}
		Sleep(0.5);
	}
	if (bHasBinoculars)
	{
		if (ShouldUseBinoculars())
		{
			if (FRand() > 0.75)
			{
				if (Pawn._InvHands.IsA("Item_Binoculars"))
				{
					AGP_Pawn(Pawn).SetZoomed(false);
					UnslingWeapon();
					Sleep(1.5);
				}
				else
				{
					ShoulderWeapon();
					Sleep(1.5);
					AGP_Pawn(Pawn).GetBinoculars();
					Sleep(1.5);
					AGP_Pawn(Pawn).SetZoomed(true);
				}
			}
		}
	}
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	NPCLog("Searching from " $ string(pnCurrentLocation));
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
	{
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionLookDirection(true);
		bRotateToDesired=true;
		FinishRotation();
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		DetermineFiringPositionLookDirection(false);
		bRotateToDesired=true;
		FinishRotation();
		Sleep((FRand() * 1.5));
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
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
		if (FRand() > 0.5)
		{
			LookLeft();
			FinishRotation();
			LookRight();
			FinishRotation();
			LookRight();
			FinishRotation();
		}
		else
		{
			LookRight();
			FinishRotation();
			LookLeft();
			FinishRotation();
			LookLeft();
			FinishRotation();
		}
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	if (IsInState("CrazyIvan"))
	{
		if (Level.TimeSeconds > fpTimeToLeaveFiringPosition)
		{
			if (npcaiccCombatController != nullptr)
			{
				NPCLog("Post Crazy Ivan completed reporting action complete");
				if (GetLastStateName() == "WalkingPatrol")
				{
					NPCChangeState("ReturnToPatrol");
				}
				else
				{
					NPCChangeState(GetLastStateName());
				}
				if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
				{
					AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
				}
				if (! npcaiccCombatController.ReportActionComplete(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					NPCLog("Post Crazy Ivan completed no specific Idle time action, returning to state " $ string(GetLastStateName()));
				}
			}
			else
			{
				NPCChangeState(GetLastStateName());
			}
			JL"End"
;
		}
		else
		{
			JL"LookAround"
;
		}
	}
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode")) || bFindAlamoFirePosition)
	{
		if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot && CanPopAndShoot())
		{
			if (Level.TimeSeconds < fpTimeToLeaveFiringPosition)
			{
				sTargetingStatus="Manning popandshoot with time left " $ string((fpTimeToLeaveFiringPosition - Level.TimeSeconds));
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState("ManningPopAndShootFirePosition");
				JL"End"
;
			}
		}
		if (Level.TimeSeconds > fpTimeToLeaveFiringPosition)
		{
			sTargetingStatus="Search for target expired manning fire position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Time expired at firing position: " $ string(pnCurrentLocation));
			if (iNPCCurrentOrders == 0)
			{
				NPCChangeState("ReturnToPatrol");
			}
			else
			{
				if (iNPCCurrentOrders == 5)
				{
					NPCChangeState("MoveToNewFiringPosition");
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						if (iTotalRoundsFiredAtAmbushLocation > 0)
						{
							iTotalRoundsFiredAtAmbushLocation=0;
							NPCChangeState("MoveToNewCamperPosition");
						}
						else
						{
							fpTimeToLeaveFiringPosition=(Level.TimeSeconds + float(10));
							JL"LookAround"
;
						}
					}
				}
			}
			if (iNPCCurrentOrders == 9)
			{
				sTargetingStatus="Time to resume assault after searching for target";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCLog("Signaling we should move to closer assault firing position after searching for target");
				NPCChangeState("AssaultLocation");
				JL"End"
;
			}
			if (npcaiccCombatController != nullptr)
			{
				fpTimeToLeaveFiringPosition=(Level.TimeSeconds + (FRand() * 8));
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					NPCChangeState("MoveToNewFiringPosition");
					npcaiccCombatController.ProcessCombatAction(Self);
					NPCLog("Time expired at firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL"End"
;
				}
				else
				{
					NPCLog("Time expired at firing position, combat controller didn't handle, moving to new fire position");
					NPCChangeState("MoveToNewFiringPosition");
					JL"End"
;
				}
			}
		}
		else
		{
			JL"AdjustPosture"
;
		}
	}
	else
	{
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != nullptr)
		{
			NPCLog("SearchForTarget will report complete " $ string(fpTimeToLeaveFiringPosition));
			if (Level.TimeSeconds > fpTimeToLeaveFiringPosition)
			{
				NPCLog("Time expired at non-firing node");
				fpTimeToLeaveFiringPosition=(Level.TimeSeconds + (FRand() * 8));
				if (iNPCCurrentOrders == 9)
				{
					sTargetingStatus="Time to resume assault after searching for target";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCLog("Signaling we should move to closer assault firing position after searching for target");
					NPCChangeState("AssaultLocation");
					JL"End"
;
				}
				if (iNPCCurrentOrders == 0)
				{
					NPCChangeState("ReturnToPatrol");
					JL"End"
;
				}
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					NPCChangeState("MoveToNewFiringPosition");
					npcaiccCombatController.ProcessCombatAction(Self);
					NPCLog("Time expired at non firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL"End"
;
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL"LookAround"
;
					}
					else
					{
						NPCLog("Time expired at non-firing position, combat controller didn't handle, moving to new fire position");
						if (iNPCCurrentOrders == 0)
						{
							NPCChangeState("ReturnToPatrol");
						}
						else
						{
							NPCChangeState("MoveToNewFiringPosition");
						}
						JL"End"
;
					}
				}
			}
			JL"LookAround"
;
		}
		if (iNPCCurrentOrders == 0)
		{
			NPCChangeState("ReturnToPatrol");
		}
		else
		{
			if (iNPCCurrentOrders == 5)
			{
				NPCChangeState("MoveToNewFiringPosition");
			}
			else
			{
				if (iNPCCurrentOrders == 2)
				{
					NPCChangeState("MoveToNewCamperPosition");
				}
				else
				{
					NPCChangeState("MoveToNewFiringPosition");
				}
			}
		}
	}
	JL"End"
;
	NPCLog("Ducking from grenade");
	Crouch();
	Sleep(5);
	JL"Begin"
;
	NPCLog("Going prone from grenade");
	Crouch();
	Sleep(5);
	JL"Begin"
;
}
*/

/*
State CrazyIvan extends SearchForTarget
{
	Function SetEndTime()
	{
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 4) + (FRand() * 2));
	}
	Function int32 GetSearchRotationRate()
	{
		return int((fpTurnRate + float(8192)));
	}
	Function int32 GetLookRotationRate()
	{
		return int((fpTurnRate + float(8192)));
	}
	Function float PlayAlertAnimation()
	{
		return 0;
	}
Begin:
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	UnslingWeapon();
	NPCLog("Starting Crazy Ivan");
	StopMovement();
	if (Pawn.bIsProne)
	{
		Crouch();
	}
	else
	{
		if (! Pawn.bIsCrouched)
		{
			Sleep(PlayCustomAnimation("StartledLg"));
		}
	}
	Pawn.RotationRate.Yaw=int((fpTurnRate + float(16384)));
	if (FRand() > 0.5)
	{
		LookLeft(32767);
		FinishRotation();
	}
	else
	{
		LookRight(32768);
		FinishRotation();
	}
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	Sleep(PlayAlertAnimation());
	SetEndTime();
	JL"LookAround"
;
}
*/

/*
State ArrivedAtRestStop
{
	Function PrepRestStopArrival()
	{
		if (NPCRestStopPathNode(pnCurrentLocation).npcassNPCAnimationToPerform.bShoulderWeaponFirst)
		{
			ShoulderWeapon();
		}
	}
	Function PrepRestStopDeparture()
	{
		UnslingWeapon();
	}
}
*/

/*
State WalkingPatrol
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
		if (npcioi.bIsShootableTarget)
		{
			npcioiLastTarget=npcioi;
			NPCLog("Item of interest is a targetable item and associated APawn* being used as target");
			Enemy=npcioi.pawnTargetToShoot;
			NPCChangeState("Targeting");
		}
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding.IsA("Mover") && (! Mover(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState("WalkingPatrol","NextTravelNode");
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Function bool EndActionIdleAnimation()
	{
		UnslingWeapon();
		return true;
	}
	Function bool PrepActionForIdleAnimation()
	{
		if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].bShoulderWeaponFirst)
		{
			ShoulderWeapon();
		}
		return true;
	}
	Function bool ShouldMoveToNextPathNode()
	{
		if (NPCFirePositionPathNode(pnCurrentPathNode) != nullptr)
		{
			return false;
		}
		return true;
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.IsBodyNearLocation(AGP_Pawn(Pawn)))
			{
				if (FRand() > 0.5)
				{
					NPCChangeState("SearchForTarget");
				}
				else
				{
					NPCChangeState("FindCoverThenFight");
				}
			}
		}
	}
	Function ArrivedAtPathnode()
	{
		int32 iMostRecentContactIndex = 0;
		if (bSupportItemOfInterestSearch)
		{
			Super::ArrivedAtPathnode();
		}
		pnCurrentLocation=pnCurrentPathNode;
		NPCLog("Arrived at pathnode: " $ string(pnCurrentPathNode.Tag));
		if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsA("NPCFirePositionPathNode"))
		{
			NPCChangeState("ManningFirePosition");
		}
		NPCLog("Pathnode: Enemy " $ string(Enemy) $ ", focus: " $ string(Focus));
		if ((Enemy == nullptr) && (AGP_Pawn(Focus) == nullptr))
		{
			iMostRecentContactIndex=GetHighestThreatContactIndex();
			if ((iMostRecentContactIndex != -1) && ((Level.TimeSeconds - arcContactHistory[iMostRecentContactIndex].fpTimeSeen) < 30))
			{
				SetDesiredTarget(arcContactHistory[iMostRecentContactIndex].pawnContact);
				return;
			}
			if ((Pawn.Weapon != nullptr) && (GetConfidenceLevel() > float(-10)))
			{
				NPCLog("No enemy, no focus, no reason for weapon");
			}
		}
	}
}
*/

/*
State StuckByBadPath
{
	Function BeginState()
	{
		GotoState("SearchForTarget");
	}
}
*/

/*
State ManningFirePosition
{
	Function NotifyEnemyGrenadeClose(ThrowWeaponPickup twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
Begin:
	Sleep(0);
	if (((pnCurrentLocation != nullptr) && (NPCFirePositionPathNode(pnCurrentLocation) != nullptr)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
	{
		NPCChangeState("ManningPopAndShootFirePosition");
	}
	fpTimeEnteredCover=Level.TimeSeconds;
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(15)) + (FRand() * 15));
	if (Enemy == nullptr)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != nullptr)
	{
		NPCLog("ManningFirePosition - Begin entered at pathnode: " $ string(pnCurrentLocation.Tag));
		if (Enemy == nullptr)
		{
			DesiredRotation=pnCurrentLocation.Rotation;
			Focus=None;
			FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		}
		else
		{
			Focus=Enemy;
			FocalPoint=Enemy.Location;
		}
		bRotateToDesired=true;
		FinishRotation();
	}
	Sleep(0);
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting","AimAtTarget");
		JL"End"
;
	}
	if ((pnCurrentLocation == nullptr) || (NPCFirePositionPathNode(pnCurrentLocation) == nullptr))
	{
		NPCChangeState("SearchForTarget");
		JL"End"
;
	}
	NPCLog("ManningFirePosition - Changing posture");
	if (NPCFirePositionPathNode(pnCurrentLocation).bCrouchHere)
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
	Sleep((FRand() * 1.5));
	if (FRand() > 0.5)
	{
		if (! NPCFirePositionPathNode(pnCurrentLocation).bCrouchHere)
		{
			Stand();
			Sleep((FRand() * 1.5));
		}
	}
	if ((Enemy != nullptr) || (pawnLastEnemy != nullptr))
	{
		if (Enemy == nullptr)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState("Targeting","TurnToEnemy");
		JL"End"
;
	}
	NPCChangeState("SearchForTarget");
	if (npcaiccCombatController != nullptr)
	{
		if (npcaiccCombatController.ReportActionComplete(Self))
		{
			npcaiccCombatController.ProcessCombatAction(Self);
		}
	}
}
*/

/*
State ManningPopAndShootFirePosition
{
	Function NotifyEnemyGrenadeClose(ThrowWeaponPickup twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
Begin:
	Sleep(0);
	fpTimeEnteredCover=Level.TimeSeconds;
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (GetLastStateName() != "SearchForTarget")
	{
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(10)) + (FRand() * 15));
	}
	if (Enemy == nullptr)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != nullptr)
	{
		NPCLog("ManningPopAndShootFirePosition - Begin entered at pathnode: " $ string(pnCurrentLocation.Tag));
		if (Enemy == nullptr)
		{
			DesiredRotation=pnCurrentLocation.Rotation;
			Focus=None;
			FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		}
		else
		{
			Focus=Enemy;
			FocalPoint=Enemy.Location;
		}
		bRotateToDesired=true;
		FinishRotation();
	}
	Sleep(0);
	Crouch();
	Sleep((5 + (FRand() * 5)));
	Stand();
	if (Enemy == nullptr)
	{
		Sleep(((FRand() * 0.5) + 0.25));
		Crouch();
		Sleep((5 + (FRand() * 5)));
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting","AimAtTarget");
		JL"End"
;
	}
	NPCLog("ManningFirePosition - Changing posture");
	if ((Enemy != nullptr) || (pawnLastEnemy != nullptr))
	{
		if (Enemy == nullptr)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState("Targeting","TurnToEnemy");
		JL"End"
;
	}
	NPCChangeState("SearchForTarget");
}
*/

/*
State MoveToNewFiringPosition
{
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding.IsA("Mover") && (! Mover(actorColliding).bNotADoor))
		{
			if (Mover(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		sTargetingStatus="MoveToNewFiringPosition - saw player " $ string(pawnSeen);
		SaveTargetingStatusHistory(sTargetingStatus);
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 3))
		{
			sTargetingStatus="MoveToNewFiringPosition - saw player who is now enemy";
			SaveTargetingStatusHistory(sTargetingStatus);
			Enemy=pawnSeen;
			StopMovement();
			NPCChangeState("Targeting","TurnToEnemy");
		}
		else
		{
			Run();
		}
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (Pawn.bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Function ArrivedAtFiringPosition()
	{
		NPCChangeState("ManningFirePosition");
	}
	Function bool ShouldRun()
	{
		if (Pawn.bIsProne || Pawn.bIsCrouched)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		return Global.vAdjustedPathNodeLocation(fpMaxDistance,false);
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		if (Wall.IsA("Mover"))
		{
			if (Mover(Wall).bNotADoor)
			{
				NPCPathLog(string(Self) $ "." $ string(Tag) $ " hit a non-door mover: " $ string(Wall) $ " Normal: " $ string(HitNormal) $ " at location " $ string(Pawn.Location));
				return false;
			}
			else
			{
				if (Mover(Wall).bInterpolating)
				{
					return false;
				}
				OpenDoorFromHere(Pawn.Location,Mover(Wall));
				NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
				return true;
			}
			return false;
		}
		else
		{
			return Global.pos(HitNormal,Wall);
		}
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	NPCLog("MoveToNewFiringPosition - Begin entered, adjusting posture to crouch for move");
	if (! IsInCover())
	{
		Stand();
	}
	else
	{
		WantsToCrouch();
		Crouch();
	}
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	NPCLog("MoveToNewFiringPosition - StartMoving entered");
	pnCurrentPathNode=FindNextFiringPosition(1500);
	if ((pnCurrentPathNode == nullptr) && (npcfppnLastFirePosition != nullptr))
	{
		npcfppnLastFirePosition=None;
		pnCurrentPathNode=FindNextFiringPosition(1500);
	}
	else
	{
		if (pnCurrentPathNode == pnCurrentLocation)
		{
			ArrivedAtFiringPosition();
			JL"End"
;
		}
	}
	JL"HavePath"
;
	Sleep(1.5);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (pnCurrentPathNode != nullptr)
	{
		NPCLog("MoveToNewFiringPosition - Found new firing position: " $ string(pnCurrentPathNode));
		pnCurrentNodeLeadingToPathNode=None;
		if (true)
		{
			if (Pawn == nullptr)
			{
				JL"PawnDeadEnd"
;
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCLog("MoveToNewFiringPosition - Moving to node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(None);
				if (ShouldRun())
				{
					Run();
				}
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (VSize((pnCurrentNodeLeadingToPathNode.Location - Pawn.Location)) > float(150))
				{
					NPCLog(string(Self) $ "." $ string(Tag) $ " Stuck moving to new firing position!");
					StopMovement();
					Sleep(2);
					JL"Begin"
;
				}
				if (pnCurrentNodeLeadingToPathNode.IsA("NPCDoorEntryPathNode"))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						StopMovement();
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
								NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA("NPCLadderPathNode"))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
								{
									AGP_Pawn(Pawn).EndClimbLadder(None);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
			}
			else
			{
				NPCLog("MoveToNewFiringPosition - No more nodes found on the way - moving to last node");
				DebugMarkNextNode(pnCurrentPathNode);
				if (ShouldRun())
				{
					Run();
				}
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
				fpTargetingStartTime=0;
			}
			else
			{
			}
		}
	}
	else
	{
		fpTargetingStartTime=0;
		pnCurrentPathNode=FindNextFiringPosition(5000);
		if (pnCurrentPathNode != nullptr)
		{
			JL"HavePath"
;
		}
		else
		{
			UpdatePathNodeBonuses(pnCurrentPathNode);
			NPCChangeState("FindCover");
			JL"End"
;
		}
	}
	if (bFindAlamoFirePosition)
	{
		bFindAlamoFirePosition=false;
	}
	UpdatePathNodeBonuses(pnCurrentPathNode);
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		Focus=Enemy;
	}
	else
	{
		if ((pawnLastEnemy != nullptr) && LineOfSightTo(pawnLastEnemy))
		{
			Focus=pawnLastEnemy;
		}
		else
		{
			DesiredRotation=pnCurrentPathNode.Rotation;
			Focus=None;
			FocalPoint=(Pawn.Location + (float(1024) *  Vector(pnCurrentPathNode.Rotation)));
		}
	}
	bRotateToDesired=true;
	FinishRotation();
	NPCLog("MoveToNewFiringPosition - Done moving to fire position, going to man it now");
	bInCover=true;
	ArrivedAtFiringPosition();
	if (Focus != nullptr)
	{
		Enemy=Pawn(Focus);
		NPCChangeState("Targeting");
	}
}
*/

/*
State MoveToNewCamperPosition extends MoveToNewFiringPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		int32 iPathNode = 0;
		local NPCFirePositionPathNode npcfppnClosest;
		float fpClosestFiringPositionDistance = 0;
		float fpCurrentFiringPositionDistance = 0;
		if (Pawn == nullptr)
		{
			return None;
		}
		fpMaxDistance=500;
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Length; iPathNode++)
		{
			if (! anpcfppnFiringPositions[iPathNode].IsA("NPCCamperFirePositionPathNode"))
			{
			}
			NPCLog("Testing camper firing position: " $ string(anpcfppnFiringPositions[iPathNode].Tag));
			if (pnCurrentLocation == anpcfppnFiringPositions[iPathNode])
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
				NPCLog("Camper node too far away: " $ string(VSize((anpcfppnFiringPositions[iPathNode].Location - Pawn.Location))) $ " max allowed: " $ string(fpMaxDistance));
			}
			else
			{
				if (Abs((Pawn.Location.Z - anpcfppnFiringPositions[iPathNode].Location.Z)) > anpcfppnFiringPositions[iPathNode].fpMaxVerticalDeltaToFind)
				{
					if (FindPathToward(anpcfppnFiringPositions[iPathNode]) == nullptr)
					{
					}
				}
				else
				{
					if (! LineOfSightTo(anpcfppnFiringPositions[iPathNode]))
					{
						NPCLog("No LOS to camper node, ignoring it");
					}
					else
					{
						NPCLog("Testing node anpcfppnFiringPositions[ " $ string(iPathNode) $ "] for closest camper position: " $ string(anpcfppnFiringPositions[iPathNode].Tag));
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
				}
			}
		}
		NPCLog("Closest camper position: " $ string(npcfppnClosest));
		if (npcfppnClosest != nullptr)
		{
			npcfppnLastFirePosition=NPCFirePositionPathNode(pnCurrentLocation);
		}
		return npcfppnClosest;
	}
}
*/

/*
State MoveToNewHarassPosition extends MoveToNewFiringPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		if (Pawn == nullptr)
		{
			return None;
		}
		return FastHarassFindNextFiringPosition();
	}
}
*/

/*
State MoveToAlamoPosition extends MoveToNewFiringPosition
{
	Function PerformGrenadeReaction()
	{
	}
	Function SetDesiredTarget(Actor aTarget)
	{
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (Pawn.bIsCrouched)
		{
			Run();
		}
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnEnemy)
	{
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function AdjustStateByConfidenceLevel()
	{
	}
	Function float IncreaseNervousness(NPCBaseController.EMentalStateAdjustor msa)
	{
	}
	Function ArrivedAtFiringPosition()
	{
		UnslingWeapon();
		Super::ArrivedAtFiringPosition();
	}
	Function FName GetCoverState()
	{
		return "ManningFirePosition";
	}
	Function bool ShouldRun()
	{
		return true;
	}
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		local NPCAlamoFirePositionPathNode pnIterator;
		local NPCAlamoFirePositionPathNode pnPotentialFallback;
		local NavigationPoint N;
		if (Pawn == nullptr)
		{
			return None;
		}
		NPCLog("Trying to find alamo node");
		N=Level.NavigationPointList;
		if (N != nullptr)
		{
			if (! N.IsA("NPCAlamoFirePositionPathNode"))
			{
			}
			pnIterator=NPCAlamoFirePositionPathNode(N);
			NPCLog("Found possible alamo node to run to: \"" $ string(pnIterator.Tag) $ "\" vs. NPC tag \"" $ sNPCWaypointTag $ "\"");
			if (string(pnIterator.Tag) ~= sNPCWaypointTag)
			{
				NPCLog("Found possible alamo node, using flag: " $ string(pnIterator.npcbcUsingNode));
				if ((pnIterator.npcbcUsingNode != nullptr) && (pnIterator.npcbcUsingNode != Self))
				{
					NPCLog("alamo location " $ string(pnIterator.Tag) $ " is in use!");
					pnPotentialFallback=pnIterator;
				}
				else
				{
					pnIterator.npcbcUsingNode=Self;
					pnIterator.bInUse=true;
					pnCurrentPathNode=pnIterator;
					NPCLog("Found alamo firing position: " $ string(pnIterator));
					return pnIterator;
				}
			}
			N=N.nextNavigationPoint;
		}
		if (pnPotentialFallback != nullptr)
		{
			pnCurrentPathNode=pnPotentialFallback;
			return pnPotentialFallback;
		}
		NPCLog("No alamo node found!");
		pnCurrentPathNode=Super::FindNextFiringPosition();
		return NPCFirePositionPathNode(pnCurrentPathNode);
	}
	Function BeginState()
	{
	}
Begin:
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (IsInCover())
	{
		if ((AGP_Pawn(Pawn)._InvGrenades[Pawn.1] > 0) && (FRand() < fpChanceOfThrowingFragOnFallback))
		{
			StopMovement();
			NPCLog("Dropping smoke and running");
			AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
			if (AGP_Pawn(Pawn).DesiredGrenade != nullptr)
			{
				Crouch();
				AGP_Pawn(Pawn).SwapHands();
				Sleep(1.5);
				if (Pawn.Weapon.IsA("ThrowWeapon"))
				{
					Pawn.Weapon.Instigator=Pawn;
					Pawn.Weapon.Fire(0);
					Sleep(0.75);
					ThrowWeapon(Pawn.Weapon)._bTossNotThrow=true;
					Pawn.Weapon.Fire(0);
					ThrowWeapon(Pawn.Weapon).ServerThrow();
					Sleep(3.5);
					AGP_Pawn(Pawn).SwapHands();
				}
			}
		}
	}
	if (FRand() < fpChanceOfShootingOnFallback)
	{
		Pawn.RotationRate.Yaw=int((fpTurnRate + float(2500)));
		FocalPoint=vTargetToSuppressLocation;
		bRotateToDesired=true;
		FinishRotation();
		UnslingWeapon();
		StopMovement();
		fpAimTime=0;
		for (iRoundsFiredSinceCameOutOfCover=0; iRoundsFiredSinceCameOutOfCover<20; iRoundsFiredSinceCameOutOfCover++)
		{
			if (FRand() > 0.9)
			{
			}
			if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
			{
			}
			FireWeapon();
			Sleep(0.1);
		}
	}
	Stand();
	Run();
	WantsToRun();
	JL"StartMoving"
;
}
*/

/*
State LiveGrenade
{
	Event ReceiveWarning(Pawn shooter, float projSpeed, FVector FireDir)
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (((actThreat == nullptr) && (npcaiccCombatController != nullptr)) && (Level.TimeSeconds > fpTimeToEndLastInterrupt))
		{
			AICCMessageScanForEnemy();
			if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			if (npcaiccCombatController.ReportActionComplete(Self))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
	}
	Function InCoverAction()
	{
		Super::InCoverAction();
		UnslingWeapon();
		fpTimeToEndLastInterrupt=(Level.TimeSeconds + (FRand() * float(10)));
	}
	Function bool ShouldRun()
	{
		return true;
	}
	Function PerformGrenadeReaction()
	{
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(22,true,false);
		}
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(28,true,false);
		}
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(4,true,false);
		}
		if (twpLastGrenadeHeard != nullptr)
		{
			NPCLog("Grenade distance: " $ string(VSize((twpLastGrenadeHeard.Location - Pawn.Location))));
		}
	}
}
*/

/*
State InCover
{
	Function ThreatEnded()
	{
		if (GetConfidenceLevel() > float((-40 + 5)))
		{
			NPCChangeState("SearchForTarget");
		}
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (actThreat != nullptr)
	{
		Focus=actThreat;
		Pawn.RotationRate.Yaw=int(fpTurnRate);
		bRotateToDesired=true;
		FinishRotation();
	}
}
*/

/*
State AdvanceOnEnemyLocation
{
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			StopMovement();
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Function NotifyEnemyNotVisible()
	{
		if (! LineOfSightTo(Enemy))
		{
			NPCLog("NotifyEnemyNotVisible() with no LOS, allowing normal handling");
			Global.fpTerrainAvoidanceAltitudeBump();
		}
		else
		{
			NPCLog("NotifyEnemyNotVisible() with LOS but we're still heading to advance location so ignoring");
		}
	}
	Function EndState()
	{
		if (pnCurrentPathNode != nullptr)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("AdvanceOnEnemyLocation","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard == pawnLastHeard)
		{
			return;
		}
		if (! LineOfSightTo(pawnHeard))
		{
			return;
		}
		pawnLastHeard=pawnHeard;
		if (VSize((pawnHeard.Location - vLastTarget)) > float(250))
		{
			NPCLog("Overriding advance based on newly heard sound:" $ string(pawnHeard));
			vLastTarget=pawnHeard.Location;
			pawnLastHeard=pawnHeard;
			NPCChangeState("Targeting");
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if (! AdjustAround(Pawn(Other)))
		{
			BackupAfterBump(Pawn(Other));
			NPCChangeState("PursueEnemy","ContinueNavigation");
			return true;
		}
		return true;
	}
	Function NPCPathNode FindClosestFirePositionToTarget(FVector vLastTarget)
	{
		local NPCPathNode pnBestFirePosition;
		float fpDistanceFromBestToTarget = 0;
		local Actor traceHit;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector vNodeEyeHeightLocation = FVector(0,0,0);
		int32 iPathNode = 0;
		if (Pawn == nullptr)
		{
			return None;
		}
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Length; iPathNode++)
		{
			if (anpcfppnFiringPositions[iPathNode] == pnCurrentLocation)
			{
			}
			if (VSize((anpcfppnFiringPositions[iPathNode].Location - Pawn.Location)) > float(2500))
			{
			}
			if (VSize((vLastTarget - Pawn.Location)) < VSize((anpcfppnFiringPositions[iPathNode].Location - vLastTarget)))
			{
			}
			NPCPathLog("Found possible fire position to move to: " $ string(anpcfppnFiringPositions[iPathNode].Tag));
			if (pnBestFirePosition == nullptr)
			{
				vNodeEyeHeightLocation=anpcfppnFiringPositions[iPathNode].Location;
				vNodeEyeHeightLocation.Z += float(100);
				traceHit=anpcfppnFiringPositions[iPathNode].Trace(HitLocation,HitNormal,vLastTarget,vNodeEyeHeightLocation,true);
				if (bDebugPath && bDebugCombat)
				{
					NPCPathLog("No Previous Advance Fire position, potential new one: " $ string(anpcfppnFiringPositions[iPathNode]) $ " Trace towards target hit: " $ string(traceHit) $ ", distance: " $ string(VSize((anpcfppnFiringPositions[iPathNode].Location - vLastTarget))));
				}
				if ((traceHit != nullptr) && traceHit.IsA("AGP_Pawn"))
				{
					pnBestFirePosition=anpcfppnFiringPositions[iPathNode];
				}
				else
				{
				}
			}
			else
			{
				else
				{
					if (VSize((pnBestFirePosition.Location - vLastTarget)) < VSize((anpcfppnFiringPositions[iPathNode].Location - vLastTarget)))
					{
						NPCLog("Testing Advance  firing position " $ string(anpcfppnFiringPositions[iPathNode]) $ " for LOS to target");
						vNodeEyeHeightLocation=anpcfppnFiringPositions[iPathNode].Location;
						vNodeEyeHeightLocation.Z += float(100);
						traceHit=anpcfppnFiringPositions[iPathNode].Trace(HitLocation,HitNormal,vLastTarget,vNodeEyeHeightLocation,true);
						if (bDebugPath && bDebugCombat)
						{
							NPCPathLog("Testing new \"Best\" Advance Fire position: " $ string(anpcfppnFiringPositions[iPathNode]) $ " Trace towards target hit: " $ string(traceHit) $ ", distance: " $ string(VSize((anpcfppnFiringPositions[iPathNode].Location - vLastTarget))));
						}
						if ((traceHit != nullptr) && traceHit.IsA("AGP_Pawn"))
						{
							NPCPathLog("Somewhat closer Advance firing position found, testing it for usefulness");
							pnBestFirePosition=anpcfppnFiringPositions[iPathNode];
							fpDistanceFromBestToTarget=VSize((pnBestFirePosition.Location - vLastTarget));
						}
					}
				}
			}
		}
		if (pnBestFirePosition == nullptr)
		{
			pnBestFirePosition=pnCurrentLocation;
		}
		NPCPathLog("Found Advance firing position location: " $ string(pnBestFirePosition));
		return pnBestFirePosition;
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	NPCLog("****************");
	NPCLog("AdvanceOnEnemyLocation entered");
	NPCLog("Trying to advance on last known position of enemy");
	UnslingWeapon();
	pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
	if (pnCurrentPathNode == pnCurrentLocation)
	{
		if ((Enemy != nullptr) && LineOfSightTo(Enemy))
		{
			NPCChangeState("Targeting");
		}
		else
		{
			NPCChangeState("SearchForTarget","TurnToNoise");
		}
		JL"End"
;
	}
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	RequestSuppressiveFire(vLastTarget);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0.1);
	Pawn.RotationRate.Yaw=int((fpTurnRate + float(2500)));
	FocalPoint=vLastTarget;
	bRotateToDesired=true;
	FinishRotation();
	JL"ContinueNavigation"
;
	Sleep(1.5);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (pnCurrentPathNode == nullptr)
	{
		NPCChangeState("FindCoverThenFight");
	}
	else
	{
		Run();
		if (true)
		{
			if (((Pawn == nullptr) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End"
;
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCPathLog("Advance path location: " $ string(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				if ((LineOfSightTo(pnCurrentPathNode) && (pnCurrentPathNode.cControllerUsingNode != nullptr)) && (pnCurrentPathNode.cControllerUsingNode != Self))
				{
					pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
					if (pnCurrentPathNode == nullptr)
					{
						NPCChangeState("FindCoverThenFight");
						JL"End"
;
					}
				}
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,,(! ShouldRun()));
				if (pnCurrentNodeLeadingToPathNode.IsA("NPCDoorEntryPathNode"))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
								NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA("NPCLadderPathNode"))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
								{
									AGP_Pawn(Pawn).EndClimbLadder(None);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
			}
			else
			{
				NPCPathLog("No more nodes found for advance - moving to last node: " $ string(pnCurrentPathNode.Tag));
				DebugMarkNextNode(pnCurrentPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
				pnCurrentPathNode.DebugNavMarker(false);
				FocalPoint=vLastTarget;
				bRotateToDesired=true;
				FinishRotation();
				UpdatePathNodeBonuses(pnCurrentPathNode);
				fpTimeToEndLastInterrupt=(Level.TimeSeconds + float(10));
			}
			else
			{
			}
		}
	}
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting");
	}
	else
	{
		NPCChangeState("SearchForTarget","TurnToNoise");
	}
}
*/

/*
State AssaultLocation
{
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (Pawn.bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
	}
	Function EndState()
	{
		if (pnCurrentPathNode != nullptr)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("AssaultLocation","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other == Enemy) || Other.IsA("HumanController"))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState("Targeting","TurnToEnemy");
			return true;
		}
		if (Pawn(Other) == nullptr)
		{
			NPCChangeState("AssaultLocation");
			return true;
		}
		if ((Pawn(Other) != nullptr) && (VSize(Pawn(Other).Velocity) < 2))
		{
			if (NPCBaseSoldierController(Pawn(Other).Controller) != nullptr)
			{
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState("AssaultLocation");
			}
		}
		if (! AdjustAround(Pawn(Other)))
		{
			NPCChangeState("AssaultLocation");
			if (NPCBaseSoldierController(Pawn(Other).Controller) != nullptr)
			{
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState("AssaultLocation");
			}
			return true;
		}
		return true;
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((((pawnLastPawnSeen != pawnSeen) && (FRand() > 0.95)) && ((Level.TimeSeconds - fpTimeSinceLastSawEnemyOnAssault) > float(10))) || (((VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)) && (VSize((Pawn.Location - pawnSeen.Location)) < float(1500))) && (FRand() > 0.98)))
		{
			fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * 3));
			fpTimeSinceLastSawEnemyOnAssault=fpTimeToLeaveFiringPosition;
			sTargetingStatus="Assaulting, but see player APawn* in sight at range " $ string(VSize((Pawn.Location - pawnSeen.Location)));
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NotifyPlayerPawnInSight() targeting enemy APawn* we were pursuing");
			StopMovement();
			pawnLastPawnSeen=pawnSeen;
			Enemy=pawnSeen;
			Focus=pawnSeen;
			if (VSize((Pawn.Location - pawnSeen.Location)) < float(1500))
			{
				NPCChangeState("Targeting","TurnToEnemy");
			}
			else
			{
				NPCChangeState("FindCoverThenFight");
			}
			return;
		}
		else
		{
			pawnLastPawnSeen=pawnSeen;
		}
	}
	Function PathNode GetPathNodeFromRoute(PathNode pnLastNode)
	{
		int32 i = 0;
		if (pnLastNode == nullptr)
		{
			return PathNode(FindPathToward(pnCurrentPathNode,true));
		}
		for (i=0; i<61; i++)
		{
			if ((RouteCache[i] == pnLastNode) && (RouteCache[(i + 1)] != nullptr))
			{
				return PathNode(RouteCache[(i + 1)]);
			}
			if (RouteCache[i] == nullptr)
			{
				return PathNode(FindPathToward(pnCurrentPathNode,true));
			}
		}
		return PathNode(FindPathToward(pnCurrentPathNode,true));
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	LocateAssaultLocation();
	Sleep(0.25);
	NPCLog("****************");
	NPCLog("Assault Location entered");
	NPCLog("Trying to assault location  " $ string(vAssaultLocation));
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.npcbcUsingNode=None;
	}
	ResetRouteCache();
	pnCurrentNodeLeadingToPathNode=FindCloserAssaultFirePositionToTarget(vAssaultLocation);
	if ((pnCurrentPathNode == pnCurrentNodeLeadingToPathNode) || (pnCurrentNodeLeadingToPathNode == nullptr))
	{
		if (pnCurrentNodeLeadingToPathNode == nullptr)
		{
			Log("Failed to get new closer assault location");
		}
		sTargetingStatus="path to assault location could not be found";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep((2.5 * (FRand() * 5)));
		pnCurrentNodeLeadingToPathNode=FindCloserAssaultFirePositionToTarget(vAssaultLocation,true,true);
		if ((pnCurrentPathNode == pnCurrentNodeLeadingToPathNode) || (pnCurrentNodeLeadingToPathNode == nullptr))
		{
			NPCLog("Really failed to get path for assault, giving up and targeting");
			sTargetingStatus="Really path to assault location could not be found, looking for some cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			iNPCCurrentOrders=3;
			fpTargetingStartTime=0;
			NPCChangeState("MoveToNewFiringPosition");
			SetCustomTimer(((FRand() * 10) + 5),false,"ReturnToAssault");
			JL"End"
;
		}
	}
	Sleep(0.25);
	pnCurrentPathNode=NPCPathNode(pnCurrentNodeLeadingToPathNode);
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.npcbcUsingNode=Self;
	}
	pnCurrentLocation=None;
	NPCLog("Closest fire position to target: " $ string(pnCurrentPathNode));
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	if (FRand() > 0.75)
	{
		RequestSuppressiveFire(vAssaultLocation);
	}
	if (FRand() > 0.7)
	{
		if (ThrowSmokeGrenade())
		{
			vGrenadeTarget=vAssaultLocation;
			NPCChangeState("ThrowingGrenade");
		}
	}
	Sleep(1.5);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (pnCurrentPathNode == nullptr)
	{
		Log(string(Self) $ "." $ string(Pawn) $ "Assault failing due to no next fire position");
		sTargetingStatus="AssaultLocation - no paths available";
		SaveTargetingStatusHistory(sTargetingStatus);
		StopMovement();
		Prone();
	}
	else
	{
		Stand();
		Run();
		if (true)
		{
			actorNextPathLocation=GetPathNodeFromRoute(pnCurrentPathNode);
			pnCurrentNodeLeadingToPathNode=PathNode(actorNextPathLocation);
			if (((Pawn == nullptr) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End"
;
			}
			NPCPathLog("Advance path location: " $ string(actorNextPathLocation) $ " converted to pathnode: " $ string(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				fpTimeToEndLastInterrupt=(Level.TimeSeconds + float(20));
				sTargetingStatus="AssaultLocation - Moving to new node";
				SaveTargetingStatusHistory(sTargetingStatus);
				Stand();
				Run();
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (VSize((Pawn.Location - pnCurrentNodeLeadingToPathNode.Location)) > float(250))
				{
					sTargetingStatus="AssaultLocation - Failed to get to target node, resetting assualt location";
					StopMovement();
					Sleep(0.25);
					NPCChangeState("AssaultLocation");
					JL"End"
;
				}
				sTargetingStatus="AssaultLocation - Done moving to new node";
				SaveTargetingStatusHistory(sTargetingStatus);
				if (pnCurrentNodeLeadingToPathNode.IsA("NPCDoorEntryPathNode"))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA("NPCLadderPathNode"))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
								{
									AGP_Pawn(Pawn).EndClimbLadder(None);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
			}
			else
			{
				else
				{
					sTargetingStatus="AssaultLocation - Moving to final node";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCPathLog("No more nodes found for advance - moving to last node: " $ string(pnCurrentPathNode.Tag));
					DebugMarkNextNode(pnCurrentPathNode);
					UpdatePathNodeBonuses(None);
					Stand();
					Run();
					MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
					pnCurrentPathNode.DebugNavMarker(false);
					sTargetingStatus="AssaultLocation - Done moving to final node";
					SaveTargetingStatusHistory(sTargetingStatus);
					StopMovement();
					if (NPCFirePositionPathNode(pnCurrentPathNode) != nullptr)
					{
						if (NPCFirePositionPathNode(pnCurrentPathNode).bCrouchForCover)
						{
							Crouch();
						}
						else
						{
							if (NPCFirePositionPathNode(pnCurrentPathNode).bProneForCover)
							{
								Prone();
							}
							else
							{
								Crouch();
							}
						}
					}
					else
					{
						Crouch();
					}
					Sleep((0.25 + (FRand() * 1.25)));
					sTargetingStatus="AssaultLocation - Rotating towards assault location";
					SaveTargetingStatusHistory(sTargetingStatus);
					FocalPoint=vAssaultLocation;
					bRotateToDesired=true;
					Focus=None;
					FinishRotation();
					Sleep(0.25);
					pnCurrentLocation=pnCurrentPathNode;
				}
			}
			else
			{
			}
		}
		UpdatePathNodeBonuses(pnCurrentPathNode);
	}
	sTargetingStatus="AssaultLocation - In node, ready to search for targets";
	SaveTargetingStatusHistory(sTargetingStatus);
	fpTimeToEndLastInterrupt=Level.TimeSeconds;
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	if (VSize((vAssaultLocation - Pawn.Location)) <= float(550))
	{
		iNPCCurrentOrders=3;
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * float(10)));
		NPCChangeState("SearchForTarget","LookAround");
		JL"End"
;
	}
	if (FRand() < 0.5)
	{
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * float(10)));
		NPCChangeState("SearchForTarget","LookAround");
	}
	else
	{
		sTargetingStatus="Assault Location, switching to non-requested providing suppressive fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((pawnLastEnemy != nullptr) && LineOfSightTo(pawnLastEnemy))
		{
			vTargetToSuppressLocation=pawnLastEnemy.Location;
		}
		else
		{
			if ((pawnLastPawnSeen != nullptr) && LineOfSightTo(pawnLastPawnSeen))
			{
				vTargetToSuppressLocation=pawnLastPawnSeen.Location;
			}
			else
			{
				vTargetToSuppressLocation=vAssaultLocation;
			}
		}
		NPCChangeState("ProvidingSuppressiveFire");
	}
}
*/

/*
State PursueEnemy
{
	Function EndState()
	{
		if (pnCurrentPathNode != nullptr)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA("Mover") && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState("PursueEnemy","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (pawnHeard == Enemy)
		{
			return;
		}
		if (! LineOfSightTo(pawnHeard))
		{
			return;
		}
		if (VSize((pawnHeard.Location - vLastTarget)) > float(250))
		{
			NPCLog("Overriding advance based on newly heard sound:" $ string(pawnHeard));
			vLastTarget=pawnHeard.Location;
			Enemy=pawnHeard;
			NPCChangeState("PursueEnemy");
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other == Enemy) || Other.IsA("HumanController"))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState("Targeting","TurnToEnemy");
			return true;
		}
		if (! AdjustAround(Pawn(Other)))
		{
			BackupAfterBump(Pawn(Other));
			return true;
		}
		return true;
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((Enemy == pawnSeen) || (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 2)))
		{
			NPCLog("NotifyPlayerPawnInSight() targeting enemy APawn* we were pursuing");
			StopMovement();
			Enemy=pawnSeen;
			Focus=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
			return;
		}
		NotifyPlayerPawnInSight(pawnSeen);
		Enemy=None;
		EvaluateTarget(pawnSeen,false);
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	iNPCCurrentOrders=3;
	NPCLog("****************");
	NPCLog("PursueTarget entered");
	NPCLog("Trying to pursue enemy starting at last known position of enemy");
	pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	RequestSuppressiveFire(vLastTarget);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0.1);
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	FocalPoint=(Pawn.Location + (float(512) *  Vector(Normalize(rotator((vLastTarget - Pawn.Location))))));
	bRotateToDesired=true;
	FinishRotation();
	JL"ContinueNavigation"
;
	Sleep(1.5);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (pnCurrentPathNode == nullptr)
	{
		StopMovement();
		Prone();
	}
	else
	{
		Walk();
		fpTimeSinceLastSearchedWhilePursuing=((Level.TimeSeconds + 2) + (FRand() * 3));
		if (true)
		{
			if (((Pawn == nullptr) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End"
;
			}
			actorNextPathLocation=FindPathToward(pnCurrentPathNode,true);
			pnCurrentNodeLeadingToPathNode=PathNode(actorNextPathLocation);
			NPCPathLog("Advance path location: " $ string(actorNextPathLocation) $ " converted to pathnode: " $ string(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				if (fpTimeSinceLastSearchedWhilePursuing > Level.TimeSeconds)
				{
					Focus=None;
					FocalPoint=vLastTarget;
					bRotateToDesired=true;
					FinishRotation();
					Sleep(0.5);
					fpTimeSinceLastSearchedWhilePursuing=((Level.TimeSeconds + 2) + (FRand() * 3));
				}
				fpTimeToEndLastInterrupt=(Level.TimeSeconds + float(20));
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (pnCurrentNodeLeadingToPathNode.IsA("NPCDoorEntryPathNode"))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA("NPCLadderPathNode"))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
								{
									AGP_Pawn(Pawn).EndClimbLadder(None);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
				if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && pnCurrentNodeLeadingToPathNode.IsA("NPCFirePositionPathNode"))
				{
					NPCLog("Can see enemy, reporting contact from firing position");
					if ((npcaiccCombatController != nullptr) && npcaiccCombatController.ReportContact(Self,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
					{
						npcaiccCombatController.ProcessCombatAction(Self);
						UpdatePathNodeBonuses(NPCPathNode(pnCurrentNodeLeadingToPathNode));
						JL"End"
;
					}
				}
				JL"LookAround"
;
			}
			else
			{
				if (((pnCurrentPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode == nullptr)) && (! LineOfSightTo(pnCurrentPathNode)))
				{
					fpTimeToEndLastInterrupt=Level.TimeSeconds;
					if (pnCurrentPathNode != nullptr)
					{
						pnCurrentPathNode.DebugNavMarker(false);
					}
					NPCChangeState("MoveToNewFiringPosition");
					JL"End"
;
				}
				Walk();
				Crouch();
				Focus=pnCurrentPathNode;
				bRotateToDesired=true;
				FinishRotation();
				NPCPathLog("No more nodes found for advance - moving to last node: " $ string(pnCurrentPathNode.Tag));
				DebugMarkNextNode(pnCurrentPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
				pnCurrentPathNode.DebugNavMarker(false);
				FocalPoint=(Pawn.Location + (float(512) *  Vector(Normalize(rotator((vLastTarget - Pawn.Location))))));
				bRotateToDesired=true;
				FinishRotation();
			}
			else
			{
			}
		}
		UpdatePathNodeBonuses(pnCurrentPathNode);
	}
	fpTimeToEndLastInterrupt=Level.TimeSeconds;
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	NPCChangeState("SearchForTarget","LookAround");
}
*/

/*
State ProvidingSuppressiveFire
{
	Function NotifyEnemyNotVisible()
	{
	}
	Function EndState()
	{
		Pawn.bIsFiringBlindlyOverHead=false;
		Pawn.bIsFiringBlindlyLeft=false;
		Pawn.bIsFiringBlindlyRight=false;
		Pawn.ChangeAnimation();
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))
		{
			sTargetingStatus="Suppressivefire - close to seen pawn, switching to targeting";
			SaveTargetingStatusHistory(sTargetingStatus);
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Function AICCActionComplete()
	{
	}
	Function TurnToAreaTarget()
	{
		Pawn.RotationRate.Yaw=int((fpTurnRate + float(2500)));
		FocalPoint=vTargetToSuppressLocation;
		bRotateToDesired=true;
	}
	Function PreShootAction()
	{
	}
	Function PostShootAction()
	{
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	ChangeOrders(400);
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	if (! IsInState("FiringBlindly"))
	{
		if (iNPCCurrentOrders == 9)
		{
			fpTimeToEndSuppressionFire=((Level.TimeSeconds + 5) + (FRand() * 5));
		}
		else
		{
			fpTimeToEndSuppressionFire=((Level.TimeSeconds + float(20)) + (FRand() * float(15)));
		}
	}
	UnslingWeapon();
	StopMovement();
	if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsA("NPCFirePositionPathNode"))
	{
		NPCLog("in fire position, adjusting posture for firing");
		if (NPCFirePositionPathNode(pnCurrentPathNode).bShootWhileProne)
		{
			if (! Pawn.bIsProne)
			{
				Prone();
				Sleep(2);
				(fpTimeToEndSuppressionFire += 2);
			}
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentPathNode).bShootWhileCrouched)
			{
				if (! Pawn.bIsCrouched)
				{
					Crouch();
					Sleep(1);
					(fpTimeToEndSuppressionFire += 1);
				}
			}
			else
			{
				if (Pawn.bIsCrouched)
				{
					Stand();
					Sleep(1);
					(fpTimeToEndSuppressionFire += 1);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Stand();
						Sleep(2);
						(fpTimeToEndSuppressionFire += 2);
					}
				}
			}
		}
	}
	else
	{
		NPCLog("Not in firing position, using APawn* preference for crouching");
		if (iNPCCurrentOrders == 9)
		{
			Crouch();
		}
		else
		{
			if ((FRand() * 100) < fNPCLikesToCrouch)
			{
				Crouch();
			}
		}
	}
	TurnToAreaTarget();
	FinishRotation();
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == nullptr))
	{
		JL"CheckTimeLeft"
;
	}
	if (! IsLocationInFront(vTargetToSuppressLocation))
	{
		sTargetingStatus="Suppressivefire - rotating to target";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL"TurnToTarget"
;
	}
	if (IsInState("FiringBlindly"))
	{
		(fpTimeToEndSuppressionFire += 1);
		JL"AimAtTarget"
;
	}
	JL"AimAtTarget"
;
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	NPCLog("Scanning for targets in suppression mode");
	sTargetingStatus="Suppressivefire scanning area";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
	{
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionFromDirection(true,rotator((vTargetToSuppressLocation - Pawn.Location)));
		bRotateToDesired=true;
		FinishRotation();
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(rotator((vTargetToSuppressLocation - Pawn.Location)))));
		bRotateToDesired=true;
		FinishRotation();
		DetermineFiringPositionFromDirection(false,rotator((vTargetToSuppressLocation - Pawn.Location)));
		bRotateToDesired=true;
		FinishRotation();
		Sleep((FRand() * 1.5));
		FocalPoint=(Pawn.Location + (float(1024) *  Vector(rotator((vTargetToSuppressLocation - Pawn.Location)))));
		bRotateToDesired=true;
		FinishRotation();
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	else
	{
		Pawn.RotationRate.Yaw=GetSearchRotationRate();
		if (FRand() > 0.5)
		{
			LookLeft();
			FinishRotation();
			LookRight();
			FinishRotation();
			LookRight();
			FinishRotation();
		}
		else
		{
			LookRight();
			FinishRotation();
			LookLeft();
			FinishRotation();
			LookLeft();
			FinishRotation();
		}
		Pawn.RotationRate.Yaw=int(fpTurnRate);
	}
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	iRoundsFiredSinceCameOutOfCover=0;
	TurnToAreaTarget();
	FinishRotation();
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == nullptr))
	{
		JL"CheckTimeLeft"
;
	}
	if (! IsLocationInFront(vTargetToSuppressLocation))
	{
		sTargetingStatus="Suppressivefire - almost fired, now turning in aiming at taret";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL"AimAtTarget"
;
	}
	if (! IsInState("FiringBlindly"))
	{
		if (((NPCFirePositionPathNode(pnCurrentLocation) != nullptr) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileProne)) && Pawn.bIsProne)
		{
			Crouch();
			Sleep(0.5);
		}
		if (((NPCFirePositionPathNode(pnCurrentLocation) != nullptr) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileCrouched)) && Pawn.bIsCrouched)
		{
			Stand();
			Sleep(0.25);
		}
	}
	else
	{
		Stand();
		Sleep(0.25);
	}
	NPCLog("Aiming at area target");
	if (IsInState("FiringBlindly"))
	{
		fpAimTime=0.1;
		if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Crouch();
			Sleep(0.75);
			Sleep(PlayCustomAnimation("CrhFwUpBlndFrStart"));
			Pawn.bIsFiringBlindlyOverHead=true;
			Pawn.ChangeAnimation();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)
			{
				NPCLog("Enabling blind firing animation left");
				LookRight();
				FinishRotation();
				if (Pawn.bIsCrouched)
				{
					Sleep(PlayCustomAnimation("CrhLtBlndFrStart"));
				}
				else
				{
					Sleep(PlayCustomAnimation("StndLtBlndFrStart"));
				}
				Pawn.bIsFiringBlindlyLeft=true;
				Pawn.ChangeAnimation();
			}
			else
			{
				if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireRight)
				{
					NPCLog("Enabling blind firing animation right");
					LookLeft();
					FinishRotation();
					if (Pawn.bIsCrouched)
					{
						Sleep(PlayCustomAnimation("CrhRtBlndFrStart"));
					}
					else
					{
						Sleep(PlayCustomAnimation("StndRtBlndFrStart"));
					}
					Pawn.bIsFiringBlindlyRight=true;
					Pawn.ChangeAnimation();
				}
			}
		}
	}
	else
	{
		Pawn.ChangeAnimation();
		fpAimTime=((FRand() + 1.25) - ((fNPCExperience / 100) * 1.05));
		(fpAimTime += ((FRand() * 0.5) * (VSize((Pawn.Location - vTargetToSuppressLocation)) / float(5000))));
	}
	sTargetingStatus="Suppressivefire - shooting at target";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
	{
		NPCLog("Need to reload weapon");
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("WeaponJam");
		}
		AICCMessageReload();
		JL"End"
;
	}
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == nullptr))
	{
		sTargetingStatus="Suppressivefire - end of suppressive fire by time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Suppression Time Ended");
		if (iNPCCurrentOrders == 9)
		{
			NPCChangeState("AssaultLocation");
			JL"End"
;
		}
		if (IsInState("FiringBlindly"))
		{
			if (! IsInCover())
			{
				NPCChangeState("FindCoverThenFight");
			}
			else
			{
				NPCChangeState("SearchForTarget");
			}
		}
		else
		{
			NPCChangeState("SearchForTarget");
		}
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportActionComplete(Self))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
		JL"End"
;
	}
	if (SafeToFire() || IsInState("FiringBlindly"))
	{
		sTargetingStatus="Suppressivefire - safe to fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((Pawn.Weapon != nullptr) && AGP_Weapon(Pawn.Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Pawn.Weapon.GotoState("BusyFixingJam");
			AGP_Weapon(Pawn.Weapon).bIsJammed=false;
			if (Pawn.Weapon.IsInState("BusyFixingJam"))
			{
				Sleep(0.1);
			}
		}
		if (! Pawn.Weapon.IsZoomed())
		{
			SaveTargetingStatusHistory("Forcing weapon into zoomed mode");
			AGP_Weapon(Pawn.Weapon).ServerZoom(true);
		}
		if (Pawn.Weapon.IsInState("BusyZooming"))
		{
			Sleep(0.1);
		}
		sTargetingStatus="Suppressivefire shooting weapon";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr))
		{
			NPCLog("Just fired, current ammo count for weapon: " $ string(Pawn.Weapon) $ " is: " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
		}
		if (IsInCover())
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				if (IsInState("FiringBlindly"))
				{
					iMinRoundsToFireBeforeDucking=8;
					iMaxRoundsToFireBeforeDucking=13;
				}
				else
				{
					if (iNPCTacticalOrders == 300)
					{
						iMinRoundsToFireBeforeDucking=2;
						iMaxRoundsToFireBeforeDucking=5;
					}
					else
					{
						iMinRoundsToFireBeforeDucking=5;
						iMaxRoundsToFireBeforeDucking=10;
					}
				}
				NPCLog("InCover Min Rounds to duck: " $ string(iMinRoundsToFireBeforeDucking) $ " max: " $ string(iMaxRoundsToFireBeforeDucking));
			}
			if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FRand() * float(iMaxRoundsToFireBeforeDucking))))
			{
				iRoundsFiredSinceCameOutOfCover=0;
				if (IsInState("FiringBlindly"))
				{
					Pawn.bIsFiringBlindlyLeft=false;
					Pawn.bIsFiringBlindlyRight=false;
					if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
					{
						Sleep(PlayCustomAnimation("CrhFwUpBlndFrEnd"));
						Pawn.ChangeAnimation();
					}
					else
					{
						if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)
						{
							if (Pawn.bIsCrouched)
							{
								Sleep(PlayCustomAnimation("CrhLtBlndFrEnd"));
							}
							else
							{
								Sleep(PlayCustomAnimation("StndLtBlndFrEnd"));
							}
							Pawn.ChangeAnimation();
							LookLeft();
							FinishRotation();
						}
						else
						{
							if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireRight)
							{
								if (Pawn.bIsCrouched)
								{
									Sleep(PlayCustomAnimation("CrhRtBlndFrEnd"));
								}
								else
								{
									Sleep(PlayCustomAnimation("StndRtBlndFrEnd"));
								}
								Pawn.ChangeAnimation();
								LookRight();
								FinishRotation();
							}
						}
					}
				}
				AGP_Pawn(Pawn).ResetLean();
				NPCLog("Going to ducking after firing " $ string(iRoundsFiredSinceCameOutOfCover) $ " rounds");
				if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
				{
					if (IsInCover())
					{
						Crouch();
						Sleep((FRand() * 4));
						Stand();
					}
					else
					{
						Crouch();
						Sleep((FRand() * 2));
						Stand();
					}
				}
				JL"AimAtTarget"
;
			}
		}
		else
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				if (IsInState("FiringBlindly"))
				{
					iMinRoundsToFireBeforeDucking=8;
					iMaxRoundsToFireBeforeDucking=13;
				}
				else
				{
					if (iNPCTacticalOrders == 300)
					{
						iMinRoundsToFireBeforeDucking=int((2 + (FRand() * 2)));
						iMaxRoundsToFireBeforeDucking=int((5 + (FRand() * 5)));
					}
					else
					{
						iMinRoundsToFireBeforeDucking=int((5 + (FRand() * 2)));
						iMaxRoundsToFireBeforeDucking=int((float(10) + (FRand() * 5)));
					}
				}
				NPCLog("InOpen Min Rounds to duck: " $ string(iMinRoundsToFireBeforeDucking) $ " max: " $ string(iMaxRoundsToFireBeforeDucking));
			}
			if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FRand() * float(iMaxRoundsToFireBeforeDucking))))
			{
				iRoundsFiredSinceCameOutOfCover=0;
				Sleep(FClamp((FRand() + 0.4),0.4,0.9));
				JL"ShootTarget"
;
			}
		}
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.weaponType == 4))
		{
			NPCLog("Advanced Marksman weapon, must aim again after shot: " $ string(Pawn.Weapon));
			JL"AimAtTarget"
;
		}
	}
	else
	{
		if (IsInFiringNode())
		{
			sTargetingStatus="Suppressivefire - can't hit target area, switching to searchfortarget";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState("SearchForTarget");
		}
		else
		{
			sTargetingStatus="Suppressivefire - moving to new firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState("MoveToNewFiringPosition");
		}
		JL"End"
;
	}
	Sleep(0.15);
	JL"ShootTarget"
;
	if (IsInState("FiringBlindly"))
	{
		Pawn.bIsFiringBlindlyLeft=false;
		Pawn.bIsFiringBlindlyRight=false;
		if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Sleep(PlayCustomAnimation("CrhFwUpBlndFrEnd"));
			Pawn.ChangeAnimation();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)
			{
				if (Pawn.bIsCrouched)
				{
					Sleep(PlayCustomAnimation("CrhLtBlndFrEnd"));
				}
				else
				{
					Sleep(PlayCustomAnimation("StndLtBlndFrEnd"));
				}
				Pawn.ChangeAnimation();
				LookLeft();
				FinishRotation();
			}
			else
			{
				if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireRight)
				{
					if (Pawn.bIsCrouched)
					{
						Sleep(PlayCustomAnimation("CrhRtBlndFrEnd"));
					}
					else
					{
						Sleep(PlayCustomAnimation("StndRtBlndFrEnd"));
					}
					Pawn.ChangeAnimation();
					LookRight();
					FinishRotation();
				}
			}
		}
	}
	NPCLog("End of area Targeting initialization");
}
*/

/*
State RetreatFromBattle extends MoveToAlamoPosition
{
	Function ArrivedAtFiringPosition()
	{
	}
}
*/

/*
State FlashBanged
{
	Function RequestSuppressiveFire(FVector vTargetArea)
	{
	}
	Function SuppressiveFireRequested(NPCBaseSoldierController npcbscRequestingFire, FVector vTargetArea)
	{
	}
	Function FlashBangEffectEnded()
	{
		Log(string(Self) $ "." $ string(GetStateName()) $ ".FlashBangEffectEnded()");
		if (IsInCover())
		{
			GotoState("SearchForTarget");
		}
		else
		{
			GotoState("FindCoverThenFight");
		}
	}
	Function float PrepForFlashing()
	{
		if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon"))
		{
			Pawn.Weapon.Velocity=(Velocity * 1.15);
			Pawn.Weapon.DropFrom(Pawn.GetBoneCoords("WeaponBone").Origin);
			Pawn.Weapon=None;
			UnslingWeapon();
			return 1;
		}
	}
	Function NPCFlashedAudioYell()
	{
		if (npcaiccCombatController != nullptr)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Warning");
		}
	}
}
*/

/*
State Surrender
{
	Function InitialSurrenderActions()
	{
		NPCLog("NPC Surrendered by dropping weapons");
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(1,true,true);
		}
		Stand();
	}
	Function bool UsedBy(Pawn User)
	{
		if (bInCustody)
		{
			HumanController(User.Controller).ClientMessage("This soldier has already been taken into custody");
			return true;
		}
		if (Pawn.bIsProne)
		{
			PlayCustomAnimation("PrnKillMiles");
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				PlayCustomAnimation("CrhKillMiles");
			}
			else
			{
				PlayCustomAnimation("StdKillMilesB");
			}
		}
		HumanController(User.Controller).ClientMessage("You have taken this soldier into custody");
		bInCustody=true;
		Pawn.HUDText="Enemy Soldier In Custody";
		return true;
	}
}
*/

/*
State Cowering
{
	Function BeginState()
	{
		NPCLog("");
		NPCLog("");
		NPCLog("");
		NPCLog("ENTERING COWERING");
		NPCLog("Pawn is cowering at current location");
	}
	Function PlayCowerAnimation()
	{
		ShoulderWeapon();
		Crouch();
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if ((Level.TimeSeconds > fpTimeToEndCowering) && (GetConfidenceLevel() > float(-40)))
		{
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
			}
			UnslingWeapon();
			NPCChangeState(GetLastStateName());
		}
	}
}
*/

/*
State Collapse
{
	Function PlayPainAnimation()
	{
	}
	Function FName GetNoCoverState()
	{
		return "Cowering";
	}
	Function FName GetCoverState()
	{
		return "InCover";
	}
	Function InCoverAction()
	{
		NPCLog("InCoverAction() - default action - stop and crouch");
		StopMovement();
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	PlayPainAnimation();
	pnCoverNode=FindCoverPathNode(false);
	if (pnCoverNode == nullptr)
	{
		NPCLog("Couldn't find farthest, looking for escape path");
		pnCoverNode=FindEscapePathNode();
	}
	if (pnCoverNode == nullptr)
	{
		NPCLog("No cover node found, just dropping to ground and going to cower");
		NPCChangeState(GetNoCoverState());
		JL"End"
;
	}
	Walk();
	Prone();
	if (true)
	{
		if (Pawn == nullptr)
		{
			JL"PawnDeadEnd"
;
		}
		pnCurrentNodeOnPathToCover=PathNode(FindPathToward(pnCoverNode,false));
		if ((pnCurrentNodeOnPathToCover != nullptr) && (pnCurrentNodeOnPathToCover != pnCoverNode))
		{
			MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,true);
		}
		else
		{
			MoveToward(pnCoverNode,pnCoverNode,,false,true);
		}
		else
		{
		}
	}
	UpdatePathNodeBonuses(pnCoverNode);
	InCoverAction();
	NPCLog("Changing to cover state of: " $ string(GetCoverState()));
	NPCChangeState(GetCoverState());
}
*/

/*
State FiringBlindly extends ProvidingSuppressiveFire
{
	Function int32 GetLookRotationRate()
	{
		return 12384;
	}
	Function bool SafeToFire()
	{
		return true;
	}
	Function Timer()
	{
		DetermineBalanceOfPower();
	}
}
*/

/*
State TauntEnemy
{
	Function float PlayTauntAnimation()
	{
		if ((! Pawn.bIsProne) && Pawn.bIsCrouched)
		{
			if (FRand() > 0.5)
			{
				return PlayCustomAnimation("SgnNegLg");
			}
			else
			{
				return PlayCustomAnimation("Alarm_E");
			}
		}
		else
		{
			return 0;
		}
	}
	Function PlayTauntAudio()
	{
		if (npcaiccCombatController != nullptr)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Taunt");
		}
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	PlayTauntAudio();
	Sleep(PlayTauntAnimation());
	if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
	}
	if (npcaiccCombatController != nullptr)
	{
		NPCChangeState(GetLastStateName());
		if (npcaiccCombatController.ReportActionComplete(Self))
		{
			npcaiccCombatController.ProcessCombatAction(Self);
		}
	}
	else
	{
		NPCChangeState(GetLastStateName());
	}
}
*/

/*
State RushEnemy
{
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	NPCLog("RushEnemy Entered for " $ string(Enemy));
	Stand();
	Run();
	if (true)
	{
		if (Pawn == nullptr)
		{
			JL"PawnDeadEnd"
;
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(Enemy));
		if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && ((VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)) || (pnCurrentNodeOnPathToCover == nullptr)))
		{
			NPCLog("CQB Range to target, engaging");
			UpdatePathNodeBonuses(NPCPathNode(pnCurrentNodeOnPathToCover));
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportContact(Self,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
			}
			NPCChangeState("Targeting");
			JL"End"
;
		}
		if (pnCurrentNodeOnPathToCover == nullptr)
		{
			NPCLog("Unable to find path towards target");
			NPCChangeState("FindCoverThenFight");
			JL"End"
;
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover.IsA("NPCDoorEntryPathNode"))
		{
			if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)).bClosed)
			{
				StopMovement();
				AGP_Pawn(Pawn).GuardWeapon3p(6);
				if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
					{
						Sleep(mLastDoorOpened.MoveTime);
						NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
					}
				}
				Pawn.UpperBodyAnimComplete();
				Run();
			}
		}
		else
		{
			if (pnCurrentNodeOnPathToCover.IsA("NPCLadderPathNode"))
			{
				if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
					{
						StopMovement();
						lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
						AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
						Sleep(0.25);
					}
				}
				else
				{
					if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderBase)
					{
						if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
						{
							AGP_Pawn(Pawn).EndClimbLadder(None);
						}
						else
						{
							lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
							AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
						}
					}
				}
			}
		}
	}
}
*/

/*
State HeadToTravelLocation
{
	Function NotifyAnotherPawnDied(NPCBaseController npcpc)
	{
	}
	Function NotifyAnotherPawnTookDamage(Pawn pInstigator, NPCBaseController anpcbcDamaged)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (LineOfSightTo(aShooter) && (VSize((aShooter.Location - Pawn.Location)) < float(1000)))
		{
			if ((AGP_Pawn(aShooter) != nullptr) && AGP_Pawn(aShooter).IsHumanControlled())
			{
				Enemy=Pawn(aShooter);
				NPCChangeState("FindCoverThenFight");
			}
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, FVector vSoundLocation)
	{
		if (VSize((vSoundLocation - Pawn.Location)) < float(500))
		{
			Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (VSize((pawnHeard.Location - Pawn.Location)) < float(500))
		{
			Global.agpobj(fpLoudness,pawnHeard);
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other != nullptr) && (! Other.IsA("Pawn")))
		{
			return true;
		}
		if ((Pawn(Other).Controller != nullptr) && Pawn(Other).Controller.IsA("NPCBaseSoldierController"))
		{
			if (((! Pawn(Other).Controller.IsInState("Targeting")) && (! Pawn(Other).Controller.IsInState("HeadToTravelLocation"))) && (! Pawn(Other).Controller.IsInState("ExitVehicleWaitForMoveOrder")))
			{
				NPCBaseSoldierController(Pawn(Other).Controller).npcpnTravelLocation=npcpnTravelLocation;
				NPCBaseSoldierController(Pawn(Other).Controller).fpHeadToLocationStartDelay=(0.75 + FRand());
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState("HeadToTravelLocation");
			}
			NPCBaseController(Pawn(Other).Controller).GotoState("MoveBackAfterBump");
		}
		else
		{
			if ((Pawn(Other).Controller != nullptr) && Pawn(Other).Controller.IsA("HumanController"))
			{
				Enemy=Pawn(Other);
				NPCChangeState("Targeting","TurnToEnemy");
			}
		}
		return true;
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding.IsA("Mover") && (! Mover(actorColliding).bNotADoor))
		{
			if (Mover(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
		}
		if (actorColliding != nullptr)
		{
			AGP_Pawn(Pawn).GuardWeapon3p(6);
		}
		else
		{
			Pawn.UpperBodyAnimComplete();
		}
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		if (Wall.IsA("Mover"))
		{
			if (Mover(Wall).bNotADoor)
			{
				NPCPathLog(string(Self) $ "." $ string(Tag) $ " hit a non-door mover: " $ string(Wall) $ " Normal: " $ string(HitNormal) $ " at location " $ string(Pawn.Location));
				return false;
			}
			else
			{
				if (Mover(Wall).bInterpolating)
				{
					return false;
				}
				OpenDoorFromHere(Pawn.Location,Mover(Wall));
				NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
				return true;
			}
			return false;
		}
		else
		{
			return Global.pos(HitNormal,Wall);
		}
	}
	Function bool ShouldFindCoverNow()
	{
		float fpChanceOfFindingCover = 0;
		fpChanceOfFindingCover=FRand();
		switch(iHeadToLocationCoverOption)
		{
			case 0:
			if (VSize((Pawn.Location - npcpnTravelLocation.Location)) <= float(2500))
			{
				return true;
			}
			return false;
			case 1:
			if (VSize((Pawn.Location - npcpnTravelLocation.Location)) <= float(2000))
			{
				return true;
			}
			return false;
			case 2:
			if (VSize((Pawn.Location - npcpnTravelLocation.Location)) <= float(1500))
			{
				return true;
			}
			return false;
			case 3:
			if (VSize((Pawn.Location - npcpnTravelLocation.Location)) <= float(1000))
			{
				return true;
			}
			return false;
			case 4:
			if (VSize((Pawn.Location - npcpnTravelLocation.Location)) <= float(500))
			{
				return true;
			}
			return false;
			case 5:
			if ((iHeadToLocationCoverOption == 5) && (VSize((Pawn.Location - npcpnTravelLocation.Location)) < float(500)))
			{
				return true;
			}
			return false;
			default:
			if ((iHeadToLocationCoverOption == 5) && (VSize((Pawn.Location - npcpnTravelLocation.Location)) < float(500)))
			{
				return true;
			}
			return false;
			return false;
		}
	}
Begin:
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation entered");
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (npcpnTravelLocation == nullptr)
	{
		NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - Unable to find path towards target");
		if (GetLastStateName() == "WalkingPatrol")
		{
			NPCChangeState("ReturnToPatrol");
		}
		else
		{
			NPCChangeState("FindCoverThenFight");
		}
		JL"End"
;
	}
	if ((VSize((npcpnTravelLocation.Location - Pawn.Location)) < float(500)) && LineOfSightTo(npcpnTravelLocation))
	{
		NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - Close enough already");
		Pawn.RotationRate.Yaw=int((fpTurnRate + float(2000)));
		Focus=None;
		FocalPoint=npcpnTravelLocation.Location;
		bRotateToDesired=true;
		FinishRotation();
		NPCChangeState("SearchForTargets");
		JL"End"
;
	}
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - Sleeping for " $ string(fpHeadToLocationStartDelay));
	Sleep(fpHeadToLocationStartDelay);
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation entered for " $ string(vTravelLocation));
	Stand();
	Run();
	JL"GotoTravelLocation"
;
	Sleep(1.5);
	if (true)
	{
		if (Pawn == nullptr)
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - No pawn, aborting");
			JL"PawnDeadEnd"
;
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(npcpnTravelLocation,true));
		NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - node on way to travel location: " $ string(npcpnTravelLocation) $ " via " $ string(pnCurrentNodeOnPathToCover));
		if (bDebugPath)
		{
			DebugDumpRoute();
		}
		if (pnCurrentNodeOnPathToCover == nullptr)
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation unable to find path towards target for travel location");
			if (GetLastStateName() == "WalkingPatrol")
			{
				NPCChangeState("ReturnToPatrol");
			}
			else
			{
				NPCChangeState("FindCoverThenFight");
			}
			JL"End"
;
		}
		if ((((pnCurrentNodeOnPathToCover == npcpnTravelLocation) && npcpnTravelLocation.IsA("NPCCoverPositionPathNode")) && (npcpnTravelLocation.cControllerUsingNode != nullptr)) && (npcpnTravelLocation.cControllerUsingNode != Self))
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation last node filled");
			NPCChangeState("FindCoverThenFight");
			JL"End"
;
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover.IsA("NPCDoorEntryPathNode"))
		{
			if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)) != nullptr) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)).bClosed)
			{
				AGP_Pawn(Pawn).GuardWeapon3p(6);
				StopMovement();
				if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
					{
						Sleep(mLastDoorOpened.MoveTime);
						NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
					}
				}
				Pawn.UpperBodyAnimComplete();
			}
		}
		else
		{
			if (pnCurrentNodeOnPathToCover.IsA("NPCLadderPathNode"))
			{
				if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume")))
					{
						StopMovement();
						lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
						AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
						Sleep(0.25);
					}
				}
				else
				{
					if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderBase)
					{
						if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume.IsA("LadderVolume"))
						{
							AGP_Pawn(Pawn).EndClimbLadder(None);
						}
						else
						{
							lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
							AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
						}
					}
				}
			}
		}
		if (pnCurrentNodeOnPathToCover == npcpnTravelLocation)
		{
			if (GetLastStateName() != "ExitVehicleWaitForMoveOrder")
			{
				vLastTarget=vTravelLocation;
				NPCChangeState("SearchForTarget","TurnToNoise");
			}
			else
			{
				if (FRand() > 0.5)
				{
					NPCChangeState("FindCoverThenFight");
				}
				else
				{
					NPCChangeState("MoveToNewFiringPosition");
				}
			}
			JL"End"
;
		}
		else
		{
			if (ShouldFindCoverNow())
			{
				NPCChangeState("FindCoverThenFight");
				JL"End"
;
			}
		}
	}
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation finished trying to move - which we should never get here");
}
*/

/*
State GuardMode
{
	Function EndState()
	{
		UnslingWeapon();
	}
	Function PrepIdleAnimationPlay()
	{
		if (anpcassNPCIdleAnimations[iCurrentIdleAnimIndex].bShoulderWeaponFirst)
		{
			if (Pawn.Weapon != nullptr)
			{
				ShoulderWeapon();
			}
		}
	}
	Function PrepPostIdleAnimationPlay()
	{
	}
}
*/

/*
State PostExitVehicleActions
{
	Function EndState()
	{
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	StopMovement();
	Stand();
	Sleep(1);
	if (IsA("NPCNCOController"))
	{
		if (npcaiccCombatController != nullptr)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Attacking");
		}
		npcpnTravelLocation=FindHeadToObjective();
		SignalSoldiersShouldMoveOut(0,0);
	}
	Run();
	HeadToObjective(float((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers.Length + 4)));
}
*/

/*
State ExitVehicleNow
{
	Function KilledBy(Pawn EventInstigator)
	{
	}
	Function Touch(Actor Other)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function NotifyEnemyGrenadeClose(ThrowWeaponPickup twpGrenade)
	{
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
		return false;
	}
	Event bool NotifyBump(Actor Other)
	{
		return true;
	}
	Function float GetDepartureAngleMultipler()
	{
		float fpAngleMultiplier = 0;
		int32 iTries = 0;
		fpAngleMultiplier=1;
		for (iTries=0; iTries<10; iTries++)
		{
			if ((fpAngleMultiplier >= 0.2) && (fpAngleMultiplier < 0.6))
			{
			}
			else
			{
				fpAngleMultiplier=FRand();
			}
		}
		return fpAngleMultiplier;
	}
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (vVehicleCarryingNPC.Health <= 0)
	{
		Pawn.KilledBy(None);
		JL"None"
;
	}
	GotoState("ExitVehicleWaitForMoveOrder");
}
*/

/*
State ExitVehicleWaitForMoveOrder
{
Begin:
	Sleep(0);
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Run();
	MoveTo((Pawn.Location + (((FRand() * float(200)) + float(650)) *  Vector((Normalize(Rotation) * fpExitingVehicleDepartureAngle)))),None,false);
	StopMovement();
	if (iNPCCurrentOrders == 9)
	{
		SetCustomTimer(((FRand() * 5) + 5),false,"ReturnToAssault");
		LocateAssaultLocation();
		FocalPoint=vAssaultLocation;
		bRotateToDesired=true;
		FinishRotation();
	}
	Crouch();
	if (Pawn == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	NPCLog("Searching from " $ string(pnCurrentLocation));
	Pawn.RotationRate.Yaw=GetSearchRotationRate();
	if (FRand() > 0.5)
	{
		LookLeft();
		FinishRotation();
		Sleep((1 + FRand()));
		LookRight();
		FinishRotation();
		Sleep((1 + FRand()));
	}
	else
	{
		LookRight();
		FinishRotation();
		Sleep((1 + FRand()));
		LookLeft();
		FinishRotation();
		Sleep((1 + FRand()));
	}
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	JL"LookAround"
;
}
*/

/*
State SwapWeapons
{
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(FVector HitNormal, Actor Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
Begin:
	Sleep(0);
	sTargetingStatus="Swap hands start";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((Pawn.Weapon == agpwPrimary) && (agpwSecondary == nullptr))
	{
		JL"End"
;
	}
	if ((Pawn.Weapon == agpwSecondary) && (agpwPrimary == nullptr))
	{
		JL"End"
;
	}
	if (Pawn.Weapon == agpwPrimary)
	{
		AGP_Pawn(Pawn).SwapHands();
		sTargetingStatus="Swap hands done, pausing";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(agpwPrimary.GetAnimDuration("Drop"));
		if (agpwSecondary != nullptr)
		{
			Sleep(agpwSecondary.GetAnimDuration("Select"));
		}
		Sleep(0.5);
	}
	else
	{
		if (Pawn.Weapon == agpwSecondary)
		{
			AGP_Pawn(Pawn).SwapHands();
			sTargetingStatus="Swap hands done, pausing";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (agpwSecondary != nullptr)
			{
				Sleep(agpwSecondary.GetAnimDuration("Drop"));
			}
			Sleep(agpwPrimary.GetAnimDuration("Select"));
			Sleep(0.5);
		}
	}
	sTargetingStatus="Swap hands complete";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (GetLastStateName() == "Targeting")
	{
		fpTimeEnteredCover=Level.TimeSeconds;
		fpTargetingStartTime=Level.TimeSeconds;
		iRoundsFiredSinceCameOutOfCover=0;
		NPCChangeState("Targeting","ShootTarget");
	}
	else
	{
		NPCChangeState(GetLastStateName());
	}
}
*/

//native final Function NPCFirePositionPathNode FastHarassFindNextFiringPosition(float fpMaxDistance);
ANPCFirePositionPathNode* ANPCBaseSoldierController::FastHarassFindNextFiringPosition(float fpMaxDistance)
{
	return nullptr;   //FAKE   /EliZ
}

//native final Function NPCFirePositionPathNode FastFindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere);
ANPCFirePositionPathNode* ANPCBaseSoldierController::FastFindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
{
	return nullptr;   //FAKE   /EliZ
}

//native final Function FastPreloadDuckAndCoverNodes();
void ANPCBaseSoldierController::FastPreloadDuckAndCoverNodes()
{
}

//native final Function float GetThreatAnalysisForTeam();
float ANPCBaseSoldierController::GetThreatAnalysisForTeam()
{
	return 0;   //FAKE   /EliZ
}

//native final Function NPCPathNode FindCloserAssaultFirePositionToTarget(FVector vLastTarget, bool bIgnoreInUse, bool bIgnoreLongDistance, bool bDoSightCheck);
ANPCPathNode* ANPCBaseSoldierController::FindCloserAssaultFirePositionToTarget(FVector avLastTarget, bool bIgnoreInUse, bool bIgnoreLongDistance, bool bDoSightCheck)
{
	return nullptr;   //FAKE   /EliZ
}

void ANPCBaseSoldierController::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* Canvas, float& YL, float& YPos, FColor NewColor)
{
	FString t = "";
	float XL = 0;
	float fpVisionCone = 0;
	int32 iContactIndex = 0;
	int32 iNode = 0;
	int32 iStatusHistory = 0;
	/*
	Canvas.Style = ERenderStyle.STY_Normal;
	Canvas.StrLen("TEST", XL, YL);
	YPos = (YPos + YL);
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(NewColor.R, NewColor.G, NewColor.B);
	t = GetDebugName();
	if (bDeleteMe)
	{
		t = t $ " DELETED (bDeleteMe == true)";
	}
	Canvas.DrawText(t, false);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetDrawColor(255, 255, 0);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText(string(Self) $ "." $ string(Tag) $ ", NavTag: " $ sNPCWaypointTag $ "  upper body anim: " $ string(AGP_Pawn(Pawn).UpperBodyAnim) $ " Last AICC: " $ sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last AICC: " $ sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("State: \"" $ string(GetStateName()) $ "\" Last State Change: " $ sLastAttemptedStateChange $ " Last AICC: " $ sLastAICCMessage);
	if (Pawn != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Ground Speed: " $ string(Pawn.GroundSpeed) $ " run speed: " $ string(AGP_Pawn(Pawn).fRunSpeed) $ " Penalty: " $ string(AGP_Pawn(Pawn).fSpeedPenalty) $ " AdvancedTactics: " $ string(bAdvancedTactics) $ "  Shoot from hip: " $ string(Pawn.bIsHipShooting) $ " BlindFire L/R: " $ string(Pawn.bIsFiringBlindlyLeft) $ "," $ string(Pawn.bIsFiringBlindlyRight));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Iswalking: " $ string(Pawn.bIsWalking) $ " Crouched: " $ string(Pawn.bIsCrouched) $ "  Sprint: " $ string(Pawn.bIsSprinting) $ " Wants sprint: " $ string(Pawn.bWantsToSprint) $ " Is prone: " $ string(Pawn.bIsProne));
	}
	if (Enemy != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		if (fpTimeSinceUntilTargetLost > 0)
		{
			Canvas.DrawText("Current target: " $ string(Enemy) $ ", contact out of sight, considered lost in: " $ string((fpTimeSinceUntilTargetLost - Level.TimeSeconds)) $ " distance: " $ string(VSize((Enemy.Location - Pawn.Location))));
		}
		else
		{
			Canvas.DrawText("Current target: " $ string(Enemy) $ " distance: " $ string(VSize((Enemy.Location - Pawn.Location))) $ "         Angle: " $ string(GetAngleToLocation(Enemy.Location)));
		}
	}
	Canvas.SetDrawColor(255, 0, 255);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Target status: " $ sTargetingStatus);
	Canvas.SetDrawColor(255, 0, 200);
	for (iStatusHistory = 0; iStatusHistory < 10; iStatusHistory++)
	{
		if (Len(asTargetingStatus[iStatusHistory]) > 0)
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("TS History: " $ asTargetingStatus[iStatusHistory]);
		}
	}
	Canvas.SetDrawColor(255, 255, 0);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Confidence: " $ string(GetConfidenceLevel()) $ "  Current focus: " $ string(Focus) $ "  Last APawn* seen: " $ string(pawnDebugLastSeenPawn));
	if (IsInState("FiringBlindly"))
	{
		Canvas.SetDrawColor(255, 128, 255);
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Blind fire ends in: " $ string((fpTimeToEndSuppressionFire - Level.TimeSeconds)) $ "  Rounds since out of cover: " $ string(iRoundsFiredSinceCameOutOfCover));
		Canvas.SetDrawColor(255, 255, 0);
	}
	else
	{
		if (IsInState("ProvidingSuppressiveFire"))
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("Suppression Fire Ending in : " $ string((fpTimeToEndSuppressionFire - Level.TimeSeconds)) $ "   Rounds since out of cover: " $ string(iRoundsFiredSinceCameOutOfCover));
		}
	}
	if (Pawn != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("RPGs Left: " $ string(iRPGCount) $ " Frag Grenades: " $ string(AGP_Pawn(Pawn)._InvGrenades[Pawn.0]));
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr))
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("Ammo type: " $ string(Pawn.Weapon.GetCurrentAmmoType()) $ ", left for " $ string(Pawn.Weapon) $ ": " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
		}
	}
	if (IsInState("FlashBanged"))
	{
		fpVisionCone = (GetMaxVisionCone() - ((GetMaxVisionCone() * ((fpFlashBangedEndTime - Level.TimeSeconds) / fpFlashBangDuration)) * fpFlashBangedVisualIntensity));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Flashbang duration: " $ string(fpFlashBangDuration) $ ", Time Left: " $ string((fpFlashBangedEndTime - Level.TimeSeconds)) $ ", Intensity: " $ string(fpFlashBangedVisualIntensity));
	}
	else
	{
		fpVisionCone = GetMaxVisionCone();
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " $ string(Pawn.Health));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Vision Cone: " $ string(fpVisionCone));
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCamperFirePositionPathNode"))
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Vision Range: " $ string(fpNPCMaxVisualRange) $ "  Camper node ambush range: " $ string(NPCCamperFirePositionPathNode(pnCurrentLocation).fpAmbushRange) $ "  Vision range modified: " $ string((NPCCamperFirePositionPathNode(pnCurrentLocation).fpVisionRangeModifier * fpNPCMaxVisualRange)));
	}
	else
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Vision Range: " $ string(fpNPCMaxVisualRange));
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Sound Heard: " $ string(aLastActorHeard));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("WeaponRange: " $ string(fpNPCWeaponEffectiveRange) $ " CQB Range: " $ string((fpNPCWeaponEffectiveRange / 4)));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Eval Target Dist: " $ string(fpDistanceToLastEvaluatedTarget) $ "  Skill: " $ string(fpNPCWeaponAccuracy));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Shot Acc: " $ string(fpLastShotAccuracy) $ ", Last Shot Aim Time: " $ string(fpAimTime) $ ", distance from target: " $ string(fpLastShotDistanceFromTarget));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Leaving fire/cover position in: " $ string((fpTimeToLeaveFiringPosition - Level.TimeSeconds)) $ " (Last FPPN: " $ string(npcfppnLastFirePosition) $ ")   Rounds fired (primary):" $ string(iTotalRoundsFiredAtAmbushLocation));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current path node location: " $ string(pnCurrentLocation));
	if (IsInState("Cowering"))
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Cowering Ending in : " $ string((fpTimeToEndCowering - Level.TimeSeconds)));
	}
	Canvas.SetDrawColor(255, 128, 255);
	for (iContactIndex = 0; iContactIndex < 20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(0, YPos);
		if (arcContactHistory[iContactIndex].pawnContact == Enemy)
		{
			Canvas.SetDrawColor(255, 255, 0);
		}
		else
		{
			Canvas.SetDrawColor(255, 128, 255);
		}
		Canvas.DrawText("Contact: " $ string(arcContactHistory[iContactIndex].pawnContact) $ " Closure Rate: " $ string(arcContactHistory[iContactIndex].fpClosureRate) $ ", Lost Contact: " $ string(arcContactHistory[iContactIndex].bContactLost) $ ", Threat: " $ string(arcContactHistory[iContactIndex].fpThreatLevel) $ ", Age: " $ string((Level.TimeSeconds - arcContactHistory[iContactIndex].fpTimeSeen)) $ ", Range: " $ string(VSize((Pawn.Location - arcContactHistory[iContactIndex].pawnContact.Location))));
	}
	Canvas.SetDrawColor(255, 255, 128);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (npcaiccCombatController != nullptr)
	{
		Canvas.DrawText("Current order: " $ GetVerboseOrders(iNPCCurrentOrders) $ "  Last Combat Action: " $ sLastCombatAction $ " Last Event Processed: " $ npcaiccCombatController.asEvents[iLastInterruptEventPriority] $ " Last Interrupt: " $ npcaiccCombatController.asEvents[iLastInterrupt] $ " Time before action ends: " $ string((Level.TimeSeconds - fpTimeToEndLastInterrupt)));
	}
	else
	{
		Canvas.DrawText("Current order: " $ GetVerboseOrders(iNPCCurrentOrders));
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(255, 128, 255);
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController.DisplayDebug(Canvas, YL, YPos);
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (pnCurrentPathNode != nullptr)
	{
		Canvas.DrawText("Current node: " $ string(pnCurrentPathNode) $ " (tag: " $ string(pnCurrentPathNode.Tag) $ ")");
	}
	else
	{
		Canvas.DrawText("Current node: AI In The Open");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Balance of Power: " $ GetVerboseBalanceOfPower(iBalanceOfPowerState));
	for (iNode = 0; iNode < 62; iNode++)
	{
		if (RouteCache[iNode] == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("RouteCache[ " $ string(iNode) $ "] " $ string(RouteCache[iNode].Location.X) $ ", " $ string(RouteCache[iNode].Location.Y) $ ", " $ string(RouteCache[iNode].Location.Z));
	}
	*/
}

void ANPCBaseSoldierController::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	float fpVisionCone = 0;
	int32 iContactIndex = 0;
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(0, 128, 255);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText(string(Self) $ "." $ string(Tag) $ " in state: " $ string(GetStateName()) $ " last attempted state change: " $ sLastAttemptedStateChange $ " Last AICC: " $ sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current target: " $ string(Enemy) $ " confidence: " $ string(GetConfidenceLevel()) $ " Last Seen pawn: " $ string(pawnDebugLastSeenPawn) $ " RPGs Left: " $ string(iRPGCount));
	if (IsInState("FlashBanged"))
	{
		fpVisionCone = (GetMaxVisionCone() - ((GetMaxVisionCone() * ((fpFlashBangedEndTime - Level.TimeSeconds) / fpFlashBangDuration)) * fpFlashBangedVisualIntensity));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Flashbang duration: " $ string(fpFlashBangDuration) $ ", Time Left: " $ string((fpFlashBangedEndTime - Level.TimeSeconds)) $ ", Intensity: " $ string(fpFlashBangedVisualIntensity));
	}
	else
	{
		fpVisionCone = GetMaxVisionCone();
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " $ string(Pawn.Health) $ " Vision cone: " $ string(fpVisionCone) $ ", Vision Range: " $ string(fpNPCMaxVisualRange) $ ", Last sound: " $ string(aLastActorHeard) $ " Wpn rng: " $ string(fpNPCWeaponEffectiveRange) $ " Eval Tgt Dist: " $ string(fpDistanceToLastEvaluatedTarget));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last shot acc: " $ string(fpLastShotAccuracy) $ ", Last Shot Aim Time: " $ string(fpAimTime));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr))
	{
		Canvas.DrawText("Primary reloads: " $ string(iPrimaryWeaponReloads) $ ", current clip: " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
	}
	else
	{
		Canvas.DrawText("OUT OF AMMO!");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Leaving fire/cover position in: " $ string((fpTimeToLeaveFiringPosition - Level.TimeSeconds)) $ " (Last FPPN: " $ string(npcfppnLastFirePosition) $ ")   Rounds fired (primary):" $ string(iTotalRoundsFiredAtAmbushLocation));
	Canvas.SetDrawColor(255, 128, 255);
	for (iContactIndex = 0; iContactIndex < 20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(50, YPos);
		Canvas.DrawText("Contact: " $ string(arcContactHistory[iContactIndex].pawnContact) $ " Closure Rate: " $ string(arcContactHistory[iContactIndex].fpClosureRate) $ ", Lost Contact: " $ string(arcContactHistory[iContactIndex].bContactLost) $ ", Threat: " $ string(arcContactHistory[iContactIndex].fpThreatLevel) $ ", Age: " $ string((Level.TimeSeconds - arcContactHistory[iContactIndex].fpTimeSeen)) $ ", Range: " $ string(VSize((Pawn.Location - arcContactHistory[iContactIndex].pawnContact.Location))));
	}
	Canvas.SetDrawColor(0, 128, 255);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current order: " $ GetVerboseOrders(iNPCCurrentOrders));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController.DisplayDebug(Canvas, YL, YPos);
	}
	*/
}

FString ANPCBaseSoldierController::GetVerboseBalanceOfPower(int32 BalanceOfPower)
{
	switch (BalanceOfPower)
	{
	case 0:
		return "BOP_MAJOR_ADVANTAGE";
	case 1:
		return "BOP_MINOR_ADVANTAGE";
	case 2:
		return "BOP_NO_ADVANTAGE";
	case 3:
		return "BOP_MINOR_DISADVANTAGE";
	case 4:
		return "BOP_MAJOR_DISADVANTAGE";
	default:
		return FString::FromInt(BalanceOfPower);
	}
}

FString ANPCBaseSoldierController::GetVerboseOrders(int32 CurrentOrders)
{
	switch (CurrentOrders)
	{
	case 0:
		return "ORDER_PATROL";
	case 1:
		return "ORDER_GUARD";
	case 2:
		return "ORDER_AMBUSH";
	case 3:
		return "ORDER_HUNT";
	case 4:
		return "ORDER_DEFEND";
	case 5:
		return "ORDER_HARASS";
	case 6:
		return "ORDER_FLEE";
	case 7:
		return "ORDER_SURRENDER";
	case 8:
		return "ORDER_RUSH";
	case 9:
		return "ORDER_ASSAULT";
	default:
		return FString::FromInt(CurrentOrders);
	}
}

void ANPCBaseSoldierController::NPCLog(FString sLogText)
{
	/*
	if (Pawn != nullptr)
	{
		if (bDebugMode)
		{
			NPCPrivateLog(string(Level.TimeSeconds) $ " - " $ string(Self) $ "." $ string(Tag) $ "." $ string(GetStateName()) $ " (Order: " $ GetVerboseOrders(iNPCCurrentOrders) $ ") - " $ string(Pawn.Name) $ " " $ sLogText);
		}
	}
	else
	{
		NPCPrivateLog(string(Level.TimeSeconds) $ " - " $ string(Self) $ "." $ string(Tag) $ "." $ string(GetStateName()) $ " (Order: " $ GetVerboseOrders(iNPCCurrentOrders) $ ") - " $ sLogText);
	}
	*/
}

void ANPCBaseSoldierController::PreloadPathNodeList()
{
	FastPreloadDuckAndCoverNodes();
	//Super::PreloadPathNodeList();
}

void ANPCBaseSoldierController::InitializePawn()
{
	//Super::InitializePawn();
	//InitializeWeapons();
}

void ANPCBaseSoldierController::InitializeWeapons()
{
	int32 iClip = 0;
	int32 iInvItem = 0;
	/*
	local Actor Item;
	Pawn.bCanJump = false;
	if (iRPGCount == 0)
	{
		for (iInvItem = 0; iInvItem < iFragGrenadeCount; iInvItem++)
		{
			Pawn.CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M67_Frag", Class'Class')));
			Pawn._InvGrenades[Pawn.0] ++;
		}
		for (iInvItem = 0; iInvItem < iFlashGrenadeCount; iInvItem++)
		{
			Pawn.CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun", Class'Class')));
			Pawn._InvGrenades[Pawn.2] ++;
		}
	}
	for (iInvItem = 0; iInvItem < iSmokeGrenadeCount; iInvItem++)
	{
		Pawn.CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke", Class'Class')));
		Pawn._InvGrenades[Pawn.1] ++;
	}
	if (namePrimaryWeapon != nullptr)
	{
		if (Pawn.FindInventoryType(namePrimaryWeapon) == nullptr)
		{
			if (string(namePrimaryWeapon) ~= "AGP_Inventory.Weapon_RPG7_rocket")
			{
				agpwPrimary = Spawn(class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Weapon_NPC_RPG7_rocket", Class'Class')));
			}
			else
			{
				agpwPrimary = Spawn(namePrimaryWeapon);
			}
			if (agpwPrimary != nullptr)
			{
				agpwPrimary.bAlreadyLoadedMods = true;
				agpwPrimary._cScopeClass = nullptr;
				agpwPrimary.GiveTo(Pawn);
				agpwPrimary.PickupFunction(Pawn);
				Pawn.Weapon = agpwPrimary;
				agpwPrimary.bGuerrillaWeapon = true;
				NPCLog("Pawn " $ string(Pawn) $ " now has weapon " $ string(Pawn.Weapon));
			}
		}
	}
	if (nameSecondaryWeapon != nullptr)
	{
		if (Pawn.FindInventoryType(nameSecondaryWeapon) == nullptr)
		{
			agpwSecondary = Spawn(nameSecondaryWeapon);
			if (agpwSecondary != nullptr)
			{
				NPCLog("Pawn's secondary weapon is " $ string(agpwSecondary));
				if (agpwSecondary.IsA("PistolWeapon"))
				{
					agpwSecondary.bAlreadyLoadedMods = true;
					agpwSecondary._cScopeClass = nullptr;
					agpwSecondary.GiveTo(Pawn);
					agpwSecondary.PickupFunction(Pawn);
				}
				else
				{
					agpwSecondary.bAlreadyLoadedMods = true;
					agpwSecondary._cScopeClass = nullptr;
					agpwSecondary.GiveTo(Pawn);
					agpwSecondary.PickupFunction(Pawn);
				}
				agpwSecondary.bGuerrillaWeapon = true;
			}
		}
	}
	if (iRPGCount > 0)
	{
		for (iInvItem = 0; iInvItem < 1; iInvItem++)
		{
			NPCLog("Trying to create RPG: " $ string(iInvItem) $ " using class \"AGP_Inventory.Ammo_RPG7_PG7B\"");
			Item = AGP_Pawn(Pawn).CreateInventoryFromName("AGP_Inventory.Ammo_RPG7_PG7B", true);
		}
	}
	for (iClip = 0; iClip < iPrimaryWeaponReloads; iClip++)
	{
		aiPrimaryAmmoClips.insert(0, 1);
		if (AGP_Pawn(Pawn).getHandsInventory() != nullptr)
		{
			aiPrimaryAmmoClips[0] = agpwPrimary.PickupAmmoCount;
		}
	}
	if (agpwSecondary != nullptr)
	{
		for (iClip = 0; iClip < iPrimaryWeaponReloads; iClip++)
		{
			aiSecondaryAmmoClips.insert(0, 1);
			aiSecondaryAmmoClips[0] = agpwSecondary.PickupAmmoCount;
		}
	}
	if (bHasBinoculars)
	{
		AGP_Pawn(Pawn).CreateInventoryFromName("AGP_Inventory.Item_BinocM22_A", true);
	}
	AGP_Pawn(Pawn)._InvHolster = nullptr;
	AGP_Pawn(Pawn)._InvHip = nullptr;
	AGP_Pawn(Pawn)._InvAltShoulder = nullptr;
	if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.weaponType == 4)) && (Pawn.SightRadius < float(66000)))
	{
		Pawn.SightRadius = 66000;
	}
	bUsingPrimaryWeapon = true;
	*/
}

void ANPCBaseSoldierController::UpdatePathNodeBonuses(ANPCPathNode* npcpn)
{
	float fpVisionScale = 0;
	float fpAdjustedVisionCone = 0;
	float fpAdjustedVisualRange = 0;
	/*
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCoverPositionPathNode"))
	{
		pnCurrentLocation.ExtraCost = pnCurrentLocation.Default.ExtraCost;
	}
	Super::UpdatePathNodeBonuses(npcpn);
	if (NPCCoverPositionPathNode(npcpn) != nullptr)
	{
		npcpn.ExtraCost = 99999;
	}
	if (AGP_Pawn(Pawn).VisionDistActor == nullptr)
	{
		return;
	}
	fpAdjustedVisionCone = fpNPCVisionConeAngle;
	fpAdjustedVisualRange = fpNPCMaxVisualRange;
	if (npcpn != nullptr)
	{
		if (npcpn.IsA("NPCFirePositionPathNode"))
		{
			if (npcpn.IsA("NPCCamperFirePositionPathNode"))
			{
				fpAdjustedVisualRange = NPCCamperFirePositionPathNode(npcpn).fpAmbushRange;
			}
			else
			{
				(fpAdjustedVisualRange *= NPCFirePositionPathNode(npcpn).fpVisionRangeModifier);
			}
			fpAdjustedVisionCone = NPCFirePositionPathNode(npcpn).fpVisionConeAngle;
		}
	}
	fpVisionScale = (Sin(((((fpAdjustedVisionCone / 2) / float(65536)) * 2) * 3.1214)) * fpAdjustedVisualRange);
	AGP_Pawn(Pawn).VisionDistActor.SetDrawScale3D(MakeVect(fpVisionScale, fpNPCMaxVisualRange, fpVisionScale));
	*/
}

int32 ANPCBaseSoldierController::GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus)
{
	return 0;
}

void ANPCBaseSoldierController::CalculateLeadershipBonus()
{
	fpCurrentLeadershipBonus = 0;
	/*
	if (npcaiccCombatController != nullptr)
	{
		(fpCurrentLeadershipBonus += npcaiccCombatController.GetLeadershipBonus(Self));
	}
	*/
}

float ANPCBaseSoldierController::GetConfidenceLevel()
{
	//int32 iCalculatedConfidence = 0;
	//iCalculatedConfidence = int(((fpConfidence + fpNodeMentalStateBonus) + fpCurrentLeadershipBonus));
	//return float(iCalculatedConfidence);
	return 0;    //FAKE   /EliZ
}

void ANPCBaseSoldierController::AdjustStateByConfidenceLevel()
{
	/*
	if (!bFindAlamoFirePosition)
	{
		Super::AdjustStateByConfidenceLevel();
	}
	else
	{
		if (IsInPain())
		{
			if (!IsInState("Cowering"))
			{
				NPCChangeState("Cowering");
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::SetConfidenceLevel(float fpNewConfidence)
{
	/*
	if (npcaiccCombatController != nullptr)
	{
		if ((((((((!IsSuppressed()) && (fpNewConfidence <= float(-40))) && (fpNewConfidence > float(-60))) || (((!IsInPanic()) && (fpNewConfidence < float(-60))) && (fpNewConfidence > float(-90)))) || (((!IsBrave()) && (fpNewConfidence >= float(70))) && (fpNewConfidence < float(90)))) || ((!IsReckless()) && (fpNewConfidence >= float(90)))) || (((!IsConcerned()) && (fpNewConfidence >= float(-40))) && (fpNewConfidence < float(-10)))) || (((!IsNormal()) && (fpNewConfidence >= float(-10))) && (fpNewConfidence < float(70))))
		{
			npcaiccCombatController.ReportMentalStateChange(Self);
		}
	}
	Super::SetConfidenceLevel(fpNewConfidence);
	if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_MentalStateIcon != nullptr))
	{
		AGP_Pawn(Pawn).MyDebug_MentalStateIcon.UpdateMentalState(Self);
	}
	*/
}

void ANPCBaseSoldierController::NPCChangeState(FName nmState, FName nmLabel)
{
	/*
	if ((Pawn == nullptr) && (nmState != "Dead"))
	{
		return;
	}
	sLastAttemptedStateChange = string(nmState);
	NPCLog("Wants to change state to " $ string(nmState) $ " from state " $ string(GetStateName()) $ " with orders " $ string(iNPCCurrentOrders));
	if ((nmState == "FlashBanged") || (nmState == "Dead"))
	{
		Super::NPCChangeState(nmState, nmLabel);
		return;
	}
	if ((IsInPanic() || IsInPain()) && (nmState != "Cowering"))
	{
		NPCLog("NPCChangeState() aborting due to panic: " $ string(IsInPanic()) $ " pain " $ string(IsInPain()) $ " and target state not Cowering: " $ string(nmState));
		return;
	}
	if (bFindAlamoFirePosition && (nmState != "MoveToAlamoPosition"))
	{
		return;
	}
	switch (iNPCCurrentOrders)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		if (nmState == "ReturnToPatrol")
		{
			if (IsInFiringNode())
			{
				nmState = "MoveToNewFiringPosition";
			}
			else
			{
				if (IsInState("FindCoverThenFight"))
				{
					return;
				}
				nmState = "FindCoverThenFight";
			}
		}
		GOTO JL04FC;
	case 4:
		if (nmState == "ReturnToPatrol")
		{
			if (IsInFiringNode())
			{
				nmState = "MoveToNewFiringPosition";
			}
			else
			{
				if (IsInState("FindCoverThenFight"))
				{
					return;
				}
				nmState = "FindCoverThenFight";
			}
		}
		GOTO JL04FC;
	case 5:
		if (nmState == "ReturnToPatrol")
		{
			if (IsInFiringNode())
			{
				nmState = "MoveToNewFiringPosition";
			}
			else
			{
				if (IsInState("FindCoverThenFight"))
				{
					return;
				}
				nmState = "FindCoverThenFight";
			}
		}
		GOTO JL04FC;
	case 6:
		if (((((((((((nmState == "MoveToAlamoPosition") || (nmState == "MoveToNewFiringPosition")) || (nmState == "ManningFirePosition")) || (nmState == "Surrender")) || (nmState == "Targeting")) || (nmState == "SearchForTarget")) || (nmState == "MoveToNewCamperPosition")) || (nmState == "ProvidingSuppressiveFire")) || (nmState == "AdvanceOnEnemyLocation")) || (nmState == "PursueEnemy")) || (nmState == "RetreatFromBattle"))
		{
			Super::NPCChangeState(nmState, nmLabel);
			return;
		}
		NPCLog("Ignoring state " $ string(nmState) $ " due to being in ORDER_FLEE mode");
		return;
	case 7:
		if (Pawn.Health > 0)
		{
			NPCLog("Ignoring all state changes for a surrendered NPC who's alive");
			return;
		}
		GOTO JL04FC;
	case 8:
		GOTO JL04FC;
	case 9:
		if (nmState == "ProvidingSuppressiveFire")
		{
			if ((pnCurrentPathNode == nullptr) || (VSize((Pawn.Location - pnCurrentPathNode.Location)) > float(100)))
			{
				return;
			}
		}
		if ((GetStateName() == "AssaultLocation") && (nmState == "FindCoverThenFight"))
		{
			GOTO JL04FC;
		}
		if (((((((((nmState != "ManningPopAndShootFirePosition") && (nmState != "SearchForTarget")) && (nmState != "Targeting")) && (nmState != "LiveGrenade")) && (nmState != "ThrowingGrenade")) && (nmState != "ReloadWeapon")) && (nmState != "ProvidingSuppressiveFire")) && (nmState != "ThrowingGrenade")) && (nmState != "SwapWeapons"))
		{
			nmState = "AssaultLocation";
		}
		GOTO JL04FC;
	default:
		return;
	JL04FC:
	}
	NPCLog("Changing state to " $ string(nmState));
	Super::NPCChangeState(nmState, nmLabel);
	*/
}

void ANPCBaseSoldierController::Reset()
{
	/*
	Super::Reset();
	Enemy = nullptr;
	bFindAlamoFirePosition = false;
	fpTimeSinceLastGrenade = 0;
	*/
}

/*
void ANPCBaseSoldierController::Possess(APawn* aPawn)
{
	//Super::Possess(aPawn);
}
*/

void ANPCBaseSoldierController::Start()
{
	/*
	Super::Start();
	Disable("SeeMonster");
	if (((iRPGCount > 0) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.IsA("RocketWeapon"))
	{
		Pawn.Weapon.Reload();
		if (Level.NetMode == NM_DedicatedServer)
	}
	{
	}
	*/
}

void ANPCBaseSoldierController::ExitSquadVehicle(AVehicle* vehicleToExit)
{
	vVehicleCarryingNPC = vehicleToExit;
	//GotoState("ExitVehicleNow");
}

/*
void ANPCBaseSoldierController::GameHasEnded()
{
	//Super::GameHasEnded();
}
*/

bool ANPCBaseSoldierController::IsInCover()
{
	/*
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCoverPositionPathNode")) && (VSize((pnCurrentLocation.Location - Pawn.Location)) < float(150)))
	{
		if (pnCurrentLocation.IsA("NPCFirePositionPathNode"))
		{
			return NPCFirePositionPathNode(pnCurrentLocation).bIsCover;
		}
		return true;
	}
	*/
	return false;
}

bool ANPCBaseSoldierController::IsInFiringNode()
{
	/*
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation.IsA("NPCFirePositionPathNode"))
	{
		return true;
	}
	*/
	return false;
}

bool ANPCBaseSoldierController::IsInCamperNode()
{
	/*
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation.IsA("NPCCamperFirePositionPathNode"))
	{
		return true;
	}
	*/
	return false;
}

bool ANPCBaseSoldierController::IsInAlamoNode()
{
	/*
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation.IsA("NPCAlamoFirePositionPathNode"))
	{
		return true;
	}
	*/
	return false;
}

int32 ANPCBaseSoldierController::GetSearchRotationRate()
{
	/*
	if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.weaponType == 4))
	{
		return 512;
	}
	else
	{
		return int((fpTurnRate + float(2048)));
	}
	*/
	return 0;    //FAKE  /EliZ
}

void ANPCBaseSoldierController::DetermineFiringPositionLookDirection(bool bLookLeft)
{
	/*
	FRotator rotLookDirection = FRotator(0, 0, 0);
	rotLookDirection = pnCurrentLocation.Rotation;
	if (bLookLeft)
	{
		(rotLookDirection.Yaw -= int((pnCurrentLocation.fpVisionConeAngle / 2)));
	}
	else
	{
		(rotLookDirection.Yaw += int((pnCurrentLocation.fpVisionConeAngle / 2)));
	}
	FocalPoint = (Pawn.Location + (float(1024) * Vector(rotLookDirection)));
	*/
}

void ANPCBaseSoldierController::DetermineFiringPositionFromDirection(bool bLookLeft, FRotator rotLookDirection)
{
	/*
	if (bLookLeft)
	{
		(rotLookDirection.Yaw -= int((pnCurrentLocation.fpVisionConeAngle / 2)));
	}
	else
	{
		(rotLookDirection.Yaw += int((pnCurrentLocation.fpVisionConeAngle / 2)));
	}
	FocalPoint = (Pawn.Location + (float(1024) * Vector(rotLookDirection)));
	*/
}

void ANPCBaseSoldierController::FaceNodeDirection()
{
	//FocalPoint = (Pawn.Location + (float(1024) * Vector(pnCurrentLocation.Rotation)));
}

void ANPCBaseSoldierController::MoveToAlamoFirePosition()
{
	bFindAlamoFirePosition = true;
	//NPCChangeState("MoveToAlamoPosition", "PopSmokeFirst");
}

void ANPCBaseSoldierController::ForceGrenadeToss()
{
	bThrowGrenadeForNextShoot = true;
}

void ANPCBaseSoldierController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
	/*
	if (LineOfSightTo(npcpc.Pawn) || (VSize((npcpc.Pawn.Location - Location)) <= fpNPCHearingRadius))
	{
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("FriendDied");
		}
		vDeadTeammateLocation = npcpc.Pawn.Location;
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportFriendDied(Self))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
				return;
			}
		}
		GotoState("LookAtDeadTeammate");
	}
	*/
}

void ANPCBaseSoldierController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
	bool bIsSquadMate = false;
	/*
	if (pInstigator == nullptr)
	{
		return;
	}
	if (pInstigator.Controller == nullptr)
	{
		return;
	}
	if (pInstigator.Controller.IsA("NPCBaseController"))
	{
		return;
	}
	if (LineOfSightTo(anpcbcDamaged.Pawn) || (VSize((anpcbcDamaged.Location - Location)) <= fpNPCHearingRadius))
	{
		if (float(anpcbcDamaged.iSquadID) ~= float(iSquadID))
		{
			bIsSquadMate = true;
		}
		if (GetConfidenceLevel() >= 0)
		{
			if (bIsSquadMate || (Enemy == nullptr))
			{
				SetDesiredTarget(pInstigator);
			}
		}
		else
		{
			if (GetConfidenceLevel() >= float(-40))
			{
				if ((Enemy == nullptr) || (EvaluateEnemyThreat(pInstigator) > EvaluateEnemyThreat(Enemy)))
				{
					DecrementConfidenceLevel();
					SetDesiredTarget(pInstigator);
				}
			}
			else
			{
				if (GetConfidenceLevel() > float(-60))
				{
					DecrementConfidenceLevel();
					NPCChangeState("LiveGrenade");
				}
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::SelectTarget()
{
}

void ANPCBaseSoldierController::PlayHitDamageAudio()
{
	//NPCSay(0, true, false);
}

void ANPCBaseSoldierController::NotifyBuzzedByBullet(AActor* aShooter)
{
	/*
	if (VSize((aShooter.Location - Pawn.Location)) > fpNPCMaxVisualRange)
	{
		NPCChangeState("FindCoverThenFight");
		return;
	}
	Super::NotifyBuzzedByBullet(aShooter);
	if (iNPCTacticalOrders == 200)
	{
		NPCLog("Soldier buzzed in hold fire mode, changing to controlled fire");
		ChangeOrders(300);
	}
	NPCLog("Soldier buzzed, moving to cover");
	Stand();
	NPCChangeState("FindCoverThenFight");
	if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("BulletWhip");
	}
	if (npcaiccCombatController != nullptr)
	{
		if (npcaiccCombatController.ReportUnderFire(Self, aShooter))
		{
			npcaiccCombatController.ProcessCombatAction(Self);
		}
	}
	*/
}

void ANPCBaseSoldierController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	/*
	Super::NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	if (Pawn.Health <= 0)
	{
		return;
	}
	if (Damage > 5)
	{
		NPCLog("Soldier hit, moving to cover");
		NPCChangeState("FindCoverThenFight");
		PlayHitDamageAudio();
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportWounded(Self, npcaiccCombatController.0, instigatedBy, int(EvaluateEnemyThreat(instigatedBy))))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
	}
	if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("Injured");
	}
	*/
}

void ANPCBaseSoldierController::PlayEnemySpottedAudio()
{
	//NPCSay(3, true, true);
}

void ANPCBaseSoldierController::SetDesiredTarget(AActor* aTarget)
{
	/*
	if (aTarget.IsA("Pawn"))
	{
		NPCLog("Enemy APawn* seen setting focus/enemy to it: " $ string(aTarget));
		if (Enemy != Pawn(aTarget))
		{
			fpTargetingStartTime = (Level.TimeSeconds + float(60));
			if (npcaiccCombatController == nullptr)
			{
				PlayEnemySpottedAudio();
			}
			Enemy = Pawn(aTarget);
			Focus = Pawn(aTarget);
			AGP_Pawn(Pawn).bEyeTrack = true;
			if (!IsInState("Targeting"))
			{
				NPCChangeState("Targeting", "TurnToEnemy");
			}
		}
		else
		{
			if (!IsInState("Targeting"))
			{
				NPCChangeState("Targeting", "ShootTarget");
			}
		}
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("SeePlayer");
		}
		if ((npcaiccCombatController != nullptr) && (Enemy != nullptr))
		{
			NPCLog("Want to change to targeting state, but letting AICC potentially override us");
			pawnLastEnemy = Enemy;
			if (npcaiccCombatController.ReportContact(Self, npcaiccCombatController.0, Enemy, int(EvaluateEnemyThreat(Enemy))))
			{
				NPCLog("SetDesiredTarget AICC response: " $ sNextAICCAction);
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::SelectWeapon()
{
}

void ANPCBaseSoldierController::UnslingWeapon()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (AGP_Pawn(Pawn).Weapon == nullptr)
	{
		AGP_Pawn(Pawn).SwapHands();
	}
	*/
}

void ANPCBaseSoldierController::ShoulderWeapon()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (AGP_Pawn(Pawn).Weapon != nullptr)
	{
		AGP_Pawn(Pawn).Weapon.PutDown();
	}
	*/
}

bool ANPCBaseSoldierController::IsCombatOver()
{
	return false;
}

void ANPCBaseSoldierController::Timer()
{
	/*
	Super::Timer();
	if (Pawn == nullptr)
	{
		return;
	}
	DetermineBalanceOfPower();
	if ((fpTimeSinceUntilTargetLost > 0) && (Level.TimeSeconds > fpTimeSinceUntilTargetLost))
	{
		fpTimeSinceUntilTargetLost = 0;
		AGP_Pawn(Pawn).ResetLean();
		AGP_Pawn(Pawn).bEyeTrack = false;
		LostHistoryContact(Enemy);
		if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("LostEnemy");
		}
		if (npcaiccCombatController != nullptr)
		{
			if ((GetStateName() == "PursueEnemy") && (!IsInCover()))
			{
				NPCChangeState("PursueEnemy");
				return;
			}
			if (Focus == Enemy)
			{
				Focus = nullptr;
			}
			pawnLastEnemy = Enemy;
			Enemy = nullptr;
			if (npcaiccCombatController.ReportLostContact(Self, Enemy))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
			else
			{
				if (IsInState("Targeting"))
				{
					NPCChangeState("SearchForTarget");
				}
			}
			return;
		}
		if (ShouldThrowGrenade())
		{
			if (pawnLastEnemy != nullptr)
			{
				vGrenadeTarget = pawnLastEnemy.Location;
			}
			NPCLog("Lost Target, changing to throw grenade");
			AGP_Pawn(Pawn).SwapHands();
			NPCChangeState("ThrowingGrenade");
			return;
		}
		else
		{
			if (((FRand() > 0.5) && (iNPCCurrentOrders != 2)) && (iNPCCurrentOrders != 9))
			{
				NPCLog("Trying to advance on enemy location");
				NPCChangeState("PursueEnemy");
				return;
			}
			else
			{
				NPCLog("Lost enemy contact, returning to searching for targets");
				NPCChangeState("SearchForTarget");
			}
		}
	}
	*/
}

bool ANPCBaseSoldierController::IsTargetDead()
{
	/*
	if (Enemy != nullptr)
	{
		if (Enemy.Health > 0)
		{
			return false;
		}
	}
	*/
	return true;
}

void ANPCBaseSoldierController::CheckForLostTarget()
{
}

void ANPCBaseSoldierController::NotifyLostTarget()
{
}

void ANPCBaseSoldierController::NotifyOutOfAmmo()
{
}

void ANPCBaseSoldierController::NotifyWeaponJammed()
{
}

void ANPCBaseSoldierController::NotifyTargetDead()
{
}

void ANPCBaseSoldierController::NotifyCombatOver()
{
}

void ANPCBaseSoldierController::NotifyEnemyNotVisible()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (fpTimeSinceUntilTargetLost > 0)
	{
		return;
	}
	NPCLog("NotifyEnemyNotVisible() entered for APawn* " $ string(Enemy));
	if ((Enemy != nullptr) && (Enemy.Health <= 0))
	{
		fpTimeSinceUntilTargetLost = Level.TimeSeconds;
	}
	else
	{
		fpTimeSinceUntilTargetLost = ((Level.TimeSeconds + 1.5) + (FRand() * 2.5));
	}
	*/
}

void ANPCBaseSoldierController::NotifyPlayerPawnInSight(APawn* pawnSeen)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	Super::NotifyPlayerPawnInSight(pawnSeen);
	fpTimeSinceUntilTargetLost = 0;
	NPCLog("NotifyPlayerPawnInSight() saw: " $ string(pawnSeen));
	EvaluateTarget(pawnSeen, false);
	*/
}

void ANPCBaseSoldierController::EvaluateTarget(APawn* pawnSeen, bool bWatchingUs)
{
	int32 iNewTargetThreatRating = 0;
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	pawnLastPawnSeen = pawnSeen;
	DetermineBalanceOfPower();
	if (true)
	{
		if (iNPCTacticalOrders == 100)
		{
			NPCLog("Ignoring target due to orders");
			return;
		}
		fpDistanceToLastEvaluatedTarget = VSize((pawnSeen.Location - Pawn.Location));
		if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.weaponType == 4))
		{
			fpNPCWeaponEffectiveRange = 44000;
		}
		if ((iNPCTacticalOrders == 200) || (iNPCTacticalOrders == 300))
		{
			if (VSize((pawnSeen.Location - Pawn.Location)) >= fpNPCWeaponEffectiveRange)
			{
				NPCLog("Holdfire/controlled fire - APawn* too far away to shoot: " $ string(VSize((pawnSeen.Location - Pawn.Location))) $ " vs. " $ string(fpNPCWeaponEffectiveRange));
				return;
			}
		}
		if (iNPCCurrentOrders == 2)
		{
			if ((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCamperFirePositionPathNode"))
			{
				if (VSize((pawnSeen.Location - Pawn.Location)) >= NPCCamperFirePositionPathNode(pnCurrentLocation).fpAmbushRange)
				{
					NPCLog("Pawn out of range");
					return;
				}
			}
		}
		if (pawnSeen.IsA("Vehicle"))
		{
			NPCLog("Saw vehicle: " $ string(pawnSeen));
			if ((Vehicle(pawnSeen).bIsHelicopter && (AGP_Pawn(Enemy) != nullptr)) && (Vehicle(Enemy) != nullptr))
			{
				SetDesiredTarget(Enemy);
				return;
			}
			if (pawnSeen.IsA("CROWS_HMMWV"))
			{
				if ((Vehicle(pawnSeen).NumPassengers() == 1) && (Vehicle(pawnSeen).Driver != nullptr))
				{
					if (((Enemy != nullptr) && (Enemy != pawnSeen)) && (Enemy != Vehicle(pawnSeen).Driver))
					{
						SetDesiredTarget(Enemy);
						Log("Skipping HMMWV - driver only isn't as big a threat as existing enemy");
						return;
					}
				}
				if (pawnSeen.Health == 0)
				{
					Log("Skipping HMMWV - that's dead");
					return;
				}
			}
			if ((Vehicle(pawnSeen).bSusceptibleToSmallArms || Pawn.Weapon.IsA("RocketWeapon")) || pawnSeen.IsA("CROWS_HMMWV"))
			{
				NPCLog("Reporting vehicle target to combat controller: " $ string(pawnSeen));
				if (npcaiccCombatController != nullptr)
				{
					SetDesiredTarget(pawnSeen);
					if (npcaiccCombatController.ReportVehicleContact(Self, npcaiccCombatController.0, pawnSeen, int(EvaluateEnemyThreat(pawnSeen))))
					{
						npcaiccCombatController.ProcessCombatAction(Self);
					}
					return;
				}
				else
				{
					SetDesiredTarget(pawnSeen);
				}
			}
			return;
		}
		iNewTargetThreatRating = int(EvaluateEnemyThreat(pawnSeen, bWatchingUs));
		NPCLog("Evaluating new target: " $ string(pawnSeen));
		NPCLog("Current enemy is " $ string(Enemy));
		NPCLog("Target threat is: " $ string(iNewTargetThreatRating));
		NPCLog("Current enemy threat is: " $ string(EvaluateEnemyThreat(Enemy)));
		if (iNewTargetThreatRating == 0)
		{
			return;
		}
		if (((Enemy == nullptr) || (EvaluateEnemyThreat(Enemy) <= float(iNewTargetThreatRating))) || (fpDistanceToLastEvaluatedTarget < (fpNPCWeaponEffectiveRange / 4)))
		{
			SetDesiredTarget(pawnSeen);
		}
	}
	*/
}

void ANPCBaseSoldierController::NotifyPlayerPawnWatchingMe(APawn* pawnEnemy)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (Enemy == pawnEnemy)
	{
		NPCLog("Saw current target: " $ string(Enemy));
		if ((!IsInState("Targeting")) && (VSize((Pawn.Location - pawnEnemy.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			EvaluateTarget(pawnEnemy, true);
		}
		return;
	}
	Super::NotifyPlayerPawnWatchingMe(pawnEnemy);
	NPCLog("Pawn saw enemy");
	EvaluateTarget(pawnEnemy, true);
	*/
}

bool ANPCBaseSoldierController::SafeToFire()
{
	/*
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	local Actor traceHit;
	if (Pawn == nullptr)
	{
		return false;
	}
	vStartShot = Pawn.EyePosition();
	if (IsInState("ProvidingSuppressiveFire"))
	{
		if (NPCFirePositionPathNode(pnCurrentPathNode) != nullptr)
		{
			if (NPCFirePositionPathNode(pnCurrentPathNode).bPopAndShoot || (!(NPCFirePositionPathNode(pnCurrentPathNode).bShootWhileCrouched && NPCFirePositionPathNode(pnCurrentPathNode).bShootWhileProne)))
			{
				(vStartShot += MakeVect(0, 0, 100));
			}
		}
		vEndShot = vTargetToSuppressLocation;
		traceHit = Trace(HitLocation, HitNormal, vEndShot, vStartShot, true);
		if (iNPCCurrentOrders == 9)
		{
			if (VSize((HitLocation - vEndShot)) > float(1500))
			{
				return false;
			}
		}
		else
		{
			if (VSize((HitLocation - vEndShot)) > float(100))
			{
				return false;
			}
		}
		(vEndShot.Z += Pawn.CrouchEyeHeight);
	}
	else
	{
		if (Enemy == nullptr)
		{
			vEndShot = vLastTarget;
		}
		else
		{
			vEndShot = Enemy.Location;
		}
		if (bDebugCombat)
		{
			NPCLog("Using APawn* location to get direction vector");
		}
		if (((Enemy != nullptr) && (!Enemy.bIsProne)) && (!Enemy.bIsCrouched))
		{
			(vEndShot.Z += Pawn.CrouchEyeHeight);
		}
		else
		{
			if ((Enemy != nullptr) && Enemy.bIsCrouched)
			{
				(vEndShot.Z += (Pawn.CrouchEyeHeight / 2));
			}
			else
			{
				if (Enemy != nullptr)
				{
					vEndShot = Enemy.EyePosition();
				}
				else
				{
					(vEndShot.Z += (Pawn.CrouchEyeHeight / 2));
				}
			}
		}
	}
	traceHit = Trace(HitLocation, HitNormal, vEndShot, vStartShot, true);
	if (bDebugCombat)
	{
		NPCLog("SafeToFire() - tracehit result: " $ string(traceHit));
	}
	if ((((traceHit != nullptr) && traceHit.IsA("AGP_Pawn")) && (AGP_Pawn(traceHit).Controller != nullptr)) && AGP_Pawn(traceHit).Controller.IsA("NPCBaseController"))
	{
		if (bDebugCombat)
		{
			NPCLog("SafeToFire() NOT SAFE!!!");
		}
		return false;
	}
	if (((((traceHit != nullptr) && traceHit.IsA("AuxCollisionCylinder")) && (AGP_Pawn(AuxCollisionCylinder(traceHit).Owner) != nullptr)) && (AGP_Pawn(AuxCollisionCylinder(traceHit).Owner).Controller != nullptr)) && AGP_Pawn(AuxCollisionCylinder(traceHit).Owner).Controller.IsA("NPCBaseController"))
	{
		if (bDebugCombat)
		{
			NPCLog("SafeToFire() not safe, won't fire");
		}
		return false;
	}
	if (bDebugCombat)
	{
		NPCLog("SafeToFire() appears to be safe");
	}
	*/
	return true;
}

void ANPCBaseSoldierController::FireWeapon()
{
	FRotator Aim = FRotator(0, 0, 0);
	float aimerror = 0;
	FVector d1 = FVector(0, 0, 0);
	FRotator r1 = FRotator(0, 0, 0);
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	FVector vDesiredEndShot = FVector(0, 0, 0);
	float fpRPGTimeToTarget = 0;
	float fpAimingSkill = 0;
	/*
	if ((Pawn == nullptr) || (Pawn.Weapon == nullptr))
	{
		return;
	}
	if (Pawn.bIsCrouched)
	{
		vStartShot = Pawn.Location;
		(vStartShot.Z += Pawn.CrouchEyeHeight);
	}
	else
	{
		if (Pawn.bIsProne)
		{
			vStartShot = Pawn.Location;
			(vStartShot.Z += float(20));
		}
		else
		{
			if (Pawn.bIsHipShooting)
			{
				vStartShot = Pawn.Location;
				(vStartShot.Z += Pawn.CrouchEyeHeight);
			}
			else
			{
				vStartShot = Pawn.EyePosition();
			}
		}
	}
	if (IsInState("ProvidingSuppressiveFire") || (Enemy == nullptr))
	{
		vEndShot = vTargetToSuppressLocation;
		(vEndShot.Z -= float(40));
	}
	else
	{
		if (Enemy.IsA("CROWS_HMMWV"))
		{
			if (Vehicle(Enemy).Weapon != nullptr)
			{
				vEndShot = Vehicle(Enemy).Weapon.Location;
			}
			else
			{
				vEndShot = Enemy.Location;
				(vEndShot.Z += float(50));
			}
		}
		else
		{
			vEndShot = Enemy.EyePosition();
			if (bDebugCombat)
			{
				NPCLog("Using APawn* location to get direction vector");
			}
			if ((!Enemy.bIsProne) && (!Enemy.bIsCrouched))
			{
				(vEndShot.Z -= float(40));
			}
			else
			{
				if (Enemy.bIsCrouched)
				{
					(vEndShot.Z -= float(40));
				}
				else
				{
					vEndShot = Enemy.EyePosition();
				}
			}
		}
		vDesiredEndShot = vEndShot;
		if (Pawn.Weapon.IsA("RocketWeapon"))
		{
			fpRPGTimeToTarget = (VSize((vEndShot - vStartShot)) / float(1900));
			NPCLog("Rocketeer target moving at " $ string(VSize(Enemy.Velocity)) $ " initial aimpoint: " $ string(vEndShot));
			(vEndShot += ((fpRPGTimeToTarget * VSize(Enemy.Velocity)) * Vector(Normalize(rotator(Enemy.Velocity)))));
			NPCLog("Adjusted aimpoint: " $ string(vEndShot));
		}
	}
	fpAimingSkill = (fpNPCWeaponAccuracy / 100);
	if (Pawn.bIsHipShooting)
	{
		fpAimingSkill = (fpAimingSkill * 0.5);
	}
	else
	{
		if ((!Pawn.bIsCrouched) && (!Pawn.bIsProne))
		{
			fpAimingSkill = (fpAimingSkill * 0.8);
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				fpAimingSkill = (fpAimingSkill * 0.9);
			}
		}
	}
	if (fpAimingSkill > 0.2)
	{
		(fpAimingSkill -= (0.2 * (fpAimTime / fpMaxAimTime)));
	}
	if (Pawn.Weapon.weaponType == 4)
	{
		(fpAimingSkill += ((1 - fpAimingSkill) / 2));
	}
	if (IsInPanic())
	{
		fpAimingSkill = (fpAimingSkill * 0.5);
	}
	else
	{
		if (IsInPain())
		{
			fpAimingSkill = (fpAimingSkill * 0.65);
		}
		else
		{
			if (IsSuppressed())
			{
				fpAimingSkill = (fpAimingSkill * 0.85);
			}
			else
			{
				if (IsReckless())
				{
					fpAimingSkill = (fpAimingSkill * 0.7);
				}
			}
		}
	}
	if (VSize((Pawn.Location - vEndShot)) > fpNPCWeaponEffectiveRange)
	{
		fpAimingSkill = (fpAimingSkill - (0.1 * ((VSize((Pawn.Location - vEndShot)) - fpNPCWeaponEffectiveRange) / 2500)));
	}
	if (fpAimingSkill < 0)
	{
		fpAimingSkill = 0;
	}
	aimerror = (((VSize((Pawn.Location - vEndShot)) / float(2500)) * float(200)) * (1 - fpAimingSkill));
	if (VSize((Pawn.Location - vEndShot)) < float(75))
	{
		aimerror = (FRand() * 5);
	}
	else
	{
		if (VSize((Pawn.Location - vEndShot)) < float(150))
		{
			aimerror = (FRand() * 8);
		}
		else
		{
			if (VSize((Pawn.Location - vEndShot)) < float(200))
			{
				aimerror = (FRand() * float(10));
			}
		}
	}
	fpLastShotAccuracy = aimerror;
	if (FRand() < 0.97)
	{
		if (FRand() > 0.5)
		{
			(vEndShot.X += (aimerror / (float(-4) + FRand())));
		}
		else
		{
			(vEndShot.X += (aimerror / (4 + FRand())));
		}
		if (Pawn.bIsCrouched)
		{
			(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 0.2));
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 0.75));
			}
			else
			{
				(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 1.5));
			}
		}
	}
	if (FRand() < 0.97)
	{
		if (FRand() > 0.5)
		{
			(vEndShot.Y += (aimerror / (-4 + FRand())));
		}
		else
		{
			(vEndShot.Y += (aimerror / (4 + FRand())));
		}
	}
	if ((FRand() < 0.98) || (iRoundsFiredSinceCameOutOfCover == 0))
	{
		if (FRand() > 0.5)
		{
			(vEndShot.Z += (aimerror / (-4.5 + FRand())));
		}
		else
		{
			(vEndShot.Z += (aimerror / (4.5 + FRand())));
		}
		if (Pawn.bIsCrouched)
		{
			(vEndShot.Z += (float(iRoundsFiredSinceCameOutOfCover) * 0.75));
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				(vEndShot.Z += (float(iRoundsFiredSinceCameOutOfCover) * 1.5));
			}
			else
			{
				(vEndShot.Z += (float(iRoundsFiredSinceCameOutOfCover) * 2.5));
			}
		}
	}
	fpLastShotDistanceFromTarget = VSize((vDesiredEndShot - vEndShot));
	if (bDebugCombat)
	{
		NPCLog("Using enemy target location: " $ string(vEndShot.X) $ "," $ string(vEndShot.Y) $ "," $ string(vEndShot.Z));
	}
	d1 = (vEndShot - vStartShot);
	r1 = rotator(d1);
	Pawn.SetViewRotation(r1);
	if (bDebugCombat)
	{
		NPCLog("Pitch: (P/R/Y): " $ string(Aim.Pitch) $ ", " $ string(Aim.Roll) $ ", " $ string(Aim.Yaw));
	}
	Pawn.MakeNoise(1);
	if (AGP_Pawn(Pawn).IsHeDead())
	{
		if (bDebugCombat)
		{
			NPCLog("Dead guy wants to shoot - being overridden");
		}
		return;
	}
	if (Pawn.Weapon.IsA("RocketWeapon"))
	{
		AGP_Weapon(Pawn.Weapon).dEnemy = Enemy;
		Pawn.Weapon.NPC_ProjectileFire();
	}
	else
	{
		if ((FRand() < 0.8) || (Pawn.Weapon.weaponType == 4))
		{
			Pawn.Weapon.NPC_Fire(1, None);
		}
	}
	iTotalRoundsFiredAtAmbushLocation++;
	*/
}

bool ANPCBaseSoldierController::ShouldThrowGrenade(bool bForceThrow)
{
	int32 iStartingGrenadesOfCurrentType = 0;
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	FVector vCeiling = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	/*
	local Actor traceHit;
	if (Pawn == nullptr)
	{
		return false;
	}
	if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon"))
	{
		return false;
	}
	if (((Enemy != nullptr) && (VSize((Pawn.Location - Enemy.Location)) < float(750))) || (VSize((Pawn.Location - Enemy.Location)) > float(3300)))
	{
		return false;
	}
	vStartShot = Pawn.EyePosition();
	iStartingGrenadesOfCurrentType = iFragGrenadeCount;
	iDesiredGrenadeIndex = Pawn.0;
	NPCLog("Grenades available for current mental state: " $ string(iStartingGrenadesOfCurrentType));
	if (iStartingGrenadesOfCurrentType == 0)
	{
		NPCLog("Out of grenades of desired type");
		return false;
	}
	if (bThrowGrenadeForNextShoot)
	{
		NPCLog("Console override - throwing grenade");
		bThrowGrenadeForNextShoot = false;
		return true;
	}
	if (((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsA("NPCFirePositionPathNode")) && (!NPCFirePositionPathNode(pnCurrentPathNode).bCanUseGrenades))
	{
		return false;
	}
	if ((Level.TimeSeconds - fpTimeSinceLastGrenade) < (float(10) + (FRand() * float(10))))
	{
		return false;
	}
	vCeiling = Pawn.Location;
	(vCeiling.Z += float(500));
	traceHit = Trace(HitLocation, HitNormal, vCeiling, Pawn.Location, true);
	if (VSize((HitLocation - Pawn.Location)) < float(50))
	{
		NPCLog("Can't throw, ceiling too low.");
		return false;
	}
	NPCLog("It's been long enough time won't stop grenade toss");
	if (Enemy == nullptr)
	{
		vEndShot = vTargetToSuppressLocation;
		vGrenadeTarget = vTargetToSuppressLocation;
		if (!CheckGrenadeTargetArea(vEndShot))
		{
			return false;
		}
		traceHit = Trace(HitLocation, HitNormal, vEndShot, (vStartShot + MakeVect(0, 0, 50)), true);
		if (traceHit != nullptr)
		{
			NPCLog("Barrier blocking grenade at distance: " $ string(VSize((Pawn.Location - HitLocation))));
			if (VSize((Pawn.Location - HitLocation)) < float(1312))
			{
				NPCLog("Can't throw frag due to something blocking throw");
				return false;
			}
		}
		NPCLog("Enemy target lost - last enemy health: " $ string(pawnLastEnemy.Health) $ ", threat: " $ string(EvaluateEnemyThreat(pawnLastEnemy, true)));
		if (((((FRand() > 0.5) || (npcaiccCombatController != nullptr)) && (pawnLastEnemy != nullptr)) && (pawnLastEnemy.Health >= 50)) && (EvaluateEnemyThreat(pawnLastEnemy, true) >= 2))
		{
			NPCLog("We want to throw one at lost target!");
			fpTimeSinceLastGrenade = Level.TimeSeconds;
			return true;
		}
	}
	else
	{
		vEndShot = Enemy.Location;
		if (!CheckGrenadeTargetArea(vEndShot))
		{
			return false;
		}
		traceHit = Trace(HitLocation, HitNormal, vEndShot, vStartShot, true);
		if (traceHit != nullptr)
		{
			NPCLog("Barrier blocking grenade at distance: " $ string(VSize((Pawn.Location - HitLocation))));
			if (VSize((Pawn.Location - HitLocation)) < float(1500))
			{
				return false;
			}
		}
		vGrenadeTarget = Enemy.Location;
		if ((VSize((Pawn.Location - Enemy.Location)) > float(1312)) || (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCFirePositionPathNode")) && NPCFirePositionPathNode(pnCurrentLocation).bIsCover))
		{
			NPCLog("In cover firing with grenades enabled position or far enough away grenade won't kill self");
			if ((npcaiccCombatController != nullptr) || ((FRand() + 0.1) > (1 - float((AGP_Pawn(Pawn)._InvGrenades[Pawn.0] / iStartingGrenadesOfCurrentType)))))
			{
				NPCLog("Want to throw grenade at visible target");
				fpTimeSinceLastGrenade = Level.TimeSeconds;
				return true;
			}
		}
	}
	if (bForceThrow)
	{
		fpTimeSinceLastGrenade = Level.TimeSeconds;
		return true;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool ANPCBaseSoldierController::CheckGrenadeTargetArea(FVector vTargetArea)
{
	/*
	local Controller ctrlrIterator;
	if (VSize((Pawn.Location - vTargetArea)) < float(1500))
	{
		return false;
	}
	ctrlrIterator = Level.ControllerList;
	if (ctrlrIterator != nullptr)
	{
		if (ctrlrIterator.IsA("NPCBaseSoldierController"))
		{
			if ((ctrlrIterator.Pawn != nullptr) && (VSize((vTargetArea - ctrlrIterator.Pawn.Location)) < float(1500)))
			{
				return false;
			}
		}
		ctrlrIterator = ctrlrIterator.nextController;
	}
	*/
	return true;
}

bool ANPCBaseSoldierController::ThrowSmokeGrenade(bool bForceThrow)
{
	int32 iStartingGrenadesOfCurrentType = 0;
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	/*
	if (Pawn == nullptr)
	{
		return false;
	}
	if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon"))
	{
		return false;
	}
	vStartShot = Pawn.EyePosition();
	iStartingGrenadesOfCurrentType = iSmokeGrenadeCount;
	iDesiredGrenadeIndex = Pawn.1;
	NPCLog("Smoke Grenades available: " $ string(iStartingGrenadesOfCurrentType));
	if (iStartingGrenadesOfCurrentType == 0)
	{
		return false;
	}
	if (bThrowGrenadeForNextShoot)
	{
		NPCLog("Console override - throwing grenade");
		bThrowGrenadeForNextShoot = false;
		return true;
	}
	if (((pnCurrentPathNode != nullptr) && pnCurrentPathNode.IsA("NPCFirePositionPathNode")) && (!NPCFirePositionPathNode(pnCurrentPathNode).bCanUseGrenades))
	{
		return false;
	}
	if ((Level.TimeSeconds - fpTimeSinceLastGrenade) < 20)
	{
		return false;
	}
	NPCLog("It's been long enough time won't stop grenade toss");
	if (Enemy == nullptr)
	{
		return true;
	}
	else
	{
		vEndShot = Enemy.Location;
		if ((VSize((Pawn.Location - Enemy.Location)) >= float(500)) || (pnCurrentLocation.IsA("NPCFirePositionPathNode") && NPCFirePositionPathNode(pnCurrentLocation).bIsCover))
		{
			NPCLog("In cover firing with grenades enabled position or far enough away grenade won't kill self");
			if ((npcaiccCombatController != nullptr) || ((FRand() + 0.1) > (1 - float((AGP_Pawn(Pawn)._InvGrenades[Pawn.1] / iStartingGrenadesOfCurrentType)))))
			{
				NPCLog("Want to throw smoke grenade at visible target");
				fpTimeSinceLastGrenade = Level.TimeSeconds;
				return true;
			}
		}
	}
	*/
	if (bForceThrow)
	{
		//fpTimeSinceLastGrenade = Level.TimeSeconds;
		return true;
	}

	return false;     //FAKE   /EliZ
}

int32 ANPCBaseSoldierController::SetGrenadeTypeByMentalState()
{
	/*
	NPCLog("confidence before throwing grenade: " $ string(GetConfidenceLevel()));
	if ((GetConfidenceLevel() <= float(-40)) && (AGP_Pawn(Pawn)._InvGrenades[Pawn.1] >= 0))
	{
		iDesiredGrenadeIndex = Pawn.1;
		return iSmokeGrenadeCount;
	}
	else
	{
		if (((GetConfidenceLevel() > float(-40)) && (AGP_Pawn(Pawn)._InvGrenades[Pawn.0] >= 0)) && (!pnCurrentPathNode.IsA("NPCDoorEntryPathNode")))
		{
			iDesiredGrenadeIndex = Pawn.0;
			return iFragGrenadeCount;
		}
		else
		{
			if (((GetConfidenceLevel() > float(-40)) && (AGP_Pawn(Pawn)._InvGrenades[Pawn.2] >= 0)) && pnCurrentPathNode.IsA("NPCDoorEntryPathNode"))
			{
				iDesiredGrenadeIndex = Pawn.2;
				return iFlashGrenadeCount;
			}
		}
	}
	*/
	return 0;
}

void ANPCBaseSoldierController::NotifyHeardBulletImpactNoise(AActor* NoiseMaker, FVector vImpactLocation)
{
	float fpDistanceToWeapon = 0;
	/*
	if (IsInState("WalkingPatrol"))
	{
		NPCChangeState("FindCover");
		return;
	}
	if (IsInState("Targeting"))
	{
		return;
	}
	if ((!Pawn.bIsCrouched) && (!Pawn.bIsProne))
	{
		Crouch();
	}
	fpDistanceToWeapon = VSize((NoiseMaker.Location - Pawn.Location));
	if (((fpDistanceToWeapon > fpNPCWeaponEffectiveRange) || (fpDistanceToWeapon > fpNPCMaxVisualRange)) || (fpDistanceToWeapon > fpNPCHearingRadius))
	{
		NPCChangeState("FindCoverThenFight");
	}
	else
	{
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportHeardGunfire(Self, NoiseMaker.Location))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (!agpwWeaponHeard.Instigator.Controller.IsA("HumanController")))
	{
		return;
	}
	if (VSize((Pawn.Location - vSoundLocation)) > float(200))
	{
		if (!LineOfSightTo(agpwWeaponHeard.Instigator))
		{
			return;
		}
	}
	if (VSize((Pawn.Location - vSoundLocation)) < float(2500))
	{
		NPCLog("Turning towards APawn* that was heard: " $ string(agpwWeaponHeard));
		Crouch();
		Focus = agpwWeaponHeard;
		FocalPoint = (Pawn.Location + (float(512) * Vector(Normalize(rotator((agpwWeaponHeard.Location - Pawn.Location))))));
		if (VSize((Pawn.Location - vSoundLocation)) < float(500))
		{
			IncreaseNervousness(1);
		}
		NPCChangeState("HeardPlayer");
	}
	*/
}

void ANPCBaseSoldierController::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
	float fpMaxDistance = 0;
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (!LineOfSightTo(pawnHeard))
	{
		return;
	}
	if (pawnHeard.IsA("CROWS_HMMWV"))
	{
		fpTimeLastPawnHeard = Level.TimeSeconds;
		Focus = pawnHeard;
		FocalPoint = (Pawn.Location + (float(512) * Vector(Normalize(rotator((pawnHeard.Location - Pawn.Location))))));
		if (VSize((Pawn.Location - pawnHeard.Location)) < float(500))
		{
			IncreaseNervousness(1);
		}
		NPCChangeState("HeardPlayer");
		return;
	}
	if (Vehicle(pawnHeard) == nullptr)
	{
		fpMaxDistance = 1250;
	}
	else
	{
		fpMaxDistance = 5500;
	}
	if (VSize((Pawn.Location - pawnHeard.Location)) < fpMaxDistance)
	{
		fpTimeLastPawnHeard = Level.TimeSeconds;
		Focus = pawnHeard;
		FocalPoint = (Pawn.Location + (float(512) * Vector(Normalize(rotator((pawnHeard.Location - Pawn.Location))))));
		if (VSize((Pawn.Location - pawnHeard.Location)) < float(500))
		{
			IncreaseNervousness(1);
		}
		NPCChangeState("HeardPlayer");
	}
	*/
}

void ANPCBaseSoldierController::RecoverFromBadStateCode()
{
	/*
	bBadStateCode = false;
	NPCLog("RecoverFromBadStateCode() entered, going to SearchForTarget");
	NPCChangeState("SearchForTarget");
	*/
}

float ANPCBaseSoldierController::GetGrenadePitch()
{
	return fpGrenadePitch;
}

void ANPCBaseSoldierController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (twpGrenade == nullptr)
	{
		return;
	}
	NPCLog(string(Self) $ " Grenade seen by soldier: " $ string(twpGrenade));
	Super::NotifyEnemyGrenadeClose(twpGrenade);
	if (!twpGrenade.IsA("PickupT_M83_Smoke"))
	{
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportGrenadeContact(Self, twpGrenade.Location))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
	}
	if ((AGP_Pawn(Pawn) != nullptr) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != nullptr))
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("SeeGrenade");
	}
	*/
}

ANPCFirePositionPathNode* ANPCBaseSoldierController::FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
{
	/*
	if (Pawn == nullptr)
	{
		return None;
	}
	return FastFindNextFiringPosition(fpMaxDistance, bCanJumpToGetThere);
	*/
	return nullptr;    //FAKE   /ELiZ
}

ANPCPathNode* ANPCBaseSoldierController::FindClosestFirePositionToTarget(FVector avLastTarget)
{
	ANPCFirePositionPathNode* npcfppnIterator = nullptr;
	ANPCPathNode* pnIterator = nullptr;
	ANPCPathNode* pnBestFirePosition = nullptr;
	float fpDistanceFromBestToTarget = 0;
	AActor* traceHit = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector vNodeEyeHeightLocation = FVector(0, 0, 0);
	ANavigationPoint* N = nullptr;
	/*
	if (Pawn == nullptr)
	{
		return None;
	}
	N = Level.NavigationPointList;
	if (N != nullptr)
	{
		if (!N.IsA("NPCFirePositionPathNode"))
		{
		}
		npcfppnIterator = NPCFirePositionPathNode(N);
		NPCPathLog("Found possible fire position to move to: " $ string(npcfppnIterator.Tag));
		if (npcfppnIterator == pnCurrentLocation)
		{
		}
		if (pnBestFirePosition == nullptr)
		{
			vNodeEyeHeightLocation = npcfppnIterator.Location;
			(vNodeEyeHeightLocation.Z += float(100));
			traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, vNodeEyeHeightLocation, true);
			if (bDebugPath && bDebugCombat)
			{
				NPCPathLog("No Previous Fire position, potential new one: " $ string(npcfppnIterator) $ " Trace towards target hit: " $ string(traceHit) $ ", distance: " $ string(VSize((npcfppnIterator.Location - vLastTarget))));
			}
			if ((traceHit != nullptr) && traceHit.IsA("AGP_Pawn"))
			{
				pnBestFirePosition = npcfppnIterator;
			}
			else
			{
			}
		}
		else
		{
		else
		{
			if (VSize((pnBestFirePosition.Location - vLastTarget)) > VSize((npcfppnIterator.Location - vLastTarget)))
			{
				if (VSize((Pawn.Location - vLastTarget)) < VSize((npcfppnIterator.Location - vLastTarget)))
				{
				}
				NPCLog("Testing firing position " $ string(npcfppnIterator) $ " for LOS to target");
				vNodeEyeHeightLocation = npcfppnIterator.Location;
				(vNodeEyeHeightLocation.Z += float(100));
				traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, vNodeEyeHeightLocation, true);
				if (bDebugPath && bDebugCombat)
				{
					NPCPathLog("Testing new \"Best\" Fire position: " $ string(npcfppnIterator) $ " Trace towards target hit: " $ string(traceHit) $ ", distance: " $ string(VSize((npcfppnIterator.Location - vLastTarget))));
				}
				if ((traceHit != nullptr) && traceHit.IsA("AGP_Pawn"))
				{
					NPCPathLog("Somewhat closer firing position found, testing it for usefulness");
					pnBestFirePosition = npcfppnIterator;
					fpDistanceFromBestToTarget = VSize((pnBestFirePosition.Location - vLastTarget));
				}
			}
			else
			{
		else
		{
			if (VSize((Pawn.Location - vLastTarget)) < VSize((npcfppnIterator.Location - vLastTarget)))
			{
			}
			traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, pnBestFirePosition.Location, true);
			if ((traceHit == nullptr) || ((traceHit != nullptr) && traceHit.IsA("AGP_Pawn")))
			{
				pnBestFirePosition = npcfppnIterator;
			}
		}
			}
		}
		}
		N = N.nextNavigationPoint;
	}
	if ((fpDistanceFromBestToTarget > VSize((Pawn.Location - vLastTarget))) || (pnBestFirePosition == nullptr))
	{
		N = Level.NavigationPointList;
		if (N != nullptr)
		{
			if (!N.IsA("NPCPathNode"))
			{
			}
			pnIterator = NPCPathNode(N);
			if (pnBestFirePosition == nullptr)
			{
				pnBestFirePosition = pnIterator;
			}
			else
			{
				if (VSize((pnBestFirePosition.Location - vLastTarget)) > VSize((pnBestFirePosition.Location - vLastTarget)))
				{
					if (VSize((Pawn.Location - vLastTarget)) < VSize((pnBestFirePosition.Location - vLastTarget)))
					{
					}
					NPCPathLog("Somewhat closer firing position found, testing it for usefulness");
					pnBestFirePosition = pnIterator;
				}
			}
			N = N.nextNavigationPoint;
		}
	}
	NPCPathLog("Found firing position location: " $ string(pnBestFirePosition));
	*/
	return pnBestFirePosition;
}

void ANPCBaseSoldierController::RequestSuppressiveFire(FVector vTargetArea)
{
	/*
	local NPCBaseSoldierController npcbscIterator;
	local DebugNPCTargetArea dnpcta;
	local Controller ctrlIterator;
	if (Pawn == nullptr)
	{
		return;
	}
	if (bDebugCombat)
	{
		dnpcta = Spawn(class'AGP.DebugNPCTargetArea');
		dnpcta.SetLocation(vTargetArea);
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if ((Pawn.Weapon != nullptr) && (Pawn.Weapon.weaponType == 4))
	{
		return;
	}
	NPCLog("Requesting suppressive fire from squad mates");
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (!ctrlIterator.IsA("NPCBaseSoldierController"))
		{
		}
		npcbscIterator = NPCBaseSoldierController(ctrlIterator);
		if ((((npcbscIterator != Self) && (npcbscIterator.Pawn != nullptr)) && (npcbscIterator.Pawn.Health > 25)) && (!npcbscIterator.IsInState("FlashBanged")))
		{
			npcbscIterator.SuppressiveFireRequested(Self, vTargetArea);
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	*/
}

void ANPCBaseSoldierController::RequestCancellingSuppressiveFire(FVector vTargetArea)
{
	/*
	local NPCBaseSoldierController npcbscIterator;
	local Controller ctrlIterator;
	if (Pawn == nullptr)
	{
		return;
	}
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (!ctrlIterator.IsA("NPCBaseSoldierController"))
		{
		}
		npcbscIterator = NPCBaseSoldierController(ctrlIterator);
		if (((npcbscIterator != Self) && (npcbscIterator.Pawn != nullptr)) && npcbscIterator.IsInState("ProvidingSuppressiveFire"))
		{
			npcbscIterator.SuppressiveFireCancelled(Self, vTargetArea);
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	*/
}

void ANPCBaseSoldierController::SuppressiveFireRequested(ANPCBaseSoldierController* npcbscRequestingFire, FVector vTargetArea)
{
	FVector vHitLocation = FVector(0, 0, 0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vTraceEnd = FVector(0, 0, 0);
	FVector vTraceStart = FVector(0, 0, 0);
	/*
	local Actor traceHit;
	if (Pawn == nullptr)
	{
		return;
	}
	if ((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon"))
	{
		return;
	}
	if (VSize((Pawn.Location - vTargetArea)) > fpNPCMaxVisualRange)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	vTraceStart = Pawn.Location;
	vTraceEnd = vTargetArea;
	(vTraceStart.Z += float(90));
	(vTraceEnd.Z += float(90));
	traceHit = Trace(vHitLocation, vHitNormal, vTargetArea, Pawn.Location, true);
	if (iNPCCurrentOrders != 9)
	{
		if (VSize((vHitLocation - vTargetArea)) > float(150))
		{
			return;
		}
	}
	else
	{
		if (VSize((vHitLocation - vTargetArea)) > float(1500))
		{
			return;
		}
	}
	if (VSize((Pawn.Location - vHitLocation)) < float(150))
	{
		if (iNPCCurrentOrders != 9)
		{
			return;
		}
		NPCChangeState("MoveToNewFiringPosition");
		return;
	}
	vTargetToSuppressLocation = vTargetArea;
	NPCChangeState("ProvidingSuppressiveFire");
	*/
}

void ANPCBaseSoldierController::SuppressiveFireCancelled(ANPCBaseSoldierController* npcbscRequestingFire, FVector vTargetArea)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	NPCLog("Suppressive fire cancel requested by " $ string(npcbscRequestingFire));
	if (VSize((vTargetToSuppressLocation - vTargetArea)) < float(512))
	{
		if (npcaiccCombatController == nullptr)
		{
			NPCSay(7, true, true);
		}
		NPCChangeState("FindCoverThenFight");
	}
	*/
}

void ANPCBaseSoldierController::ResetRouteCache()
{
	int32 i = 0;
	//RouteCache.SetNum(62);
	/*
	for (i = 0; i < 61; i++)
	{
		RouteCache[i] = nullptr;
	}
	*/
}

void ANPCBaseSoldierController::LocateAssaultLocation()
{
	/*
	local NPCAssaultLocation npcalIterator;
	ForEach AllActors(class'AGP.NPCAssaultLocation', npcalIterator, nameAssaultLocationTag)
	{
		vLastTarget = npcalIterator.Location;
		vAssaultLocation = vLastTarget;
		NPCLog("Found assault location: " $ string(npcalIterator));
		return;
	}
	NPCLog("WARNING: No assault location defined despite assault orders");
	*/
}

void ANPCBaseSoldierController::ReturnToAssault()
{
	//NPCChangeState("AssaultLocation");
}

void ANPCBaseSoldierController::AlertSquadMatesOfDamage(APawn* pawnInstigator)
{
	/*
	local Controller ctrlIterator;
	if (Pawn == nullptr)
	{
		return;
	}
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (ctrlIterator == Self)
		{
		}
		if (!ctrlIterator.IsA("NPCBaseSoldierController"))
		{
		}
		NPCBaseSoldierController(ctrlIterator).SquadMateHit(Self, pawnInstigator);
		ctrlIterator = ctrlIterator.nextController;
	}
	*/
}

void ANPCBaseSoldierController::SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (((pawnInstigator != nullptr) && (pawnInstigator.Controller != nullptr)) && pawnInstigator.Controller.IsA("NPCBaseController"))
	{
		return;
	}
	if ((float(npcbscHitNPC.iSquadID) ~= float(iSquadID)) || (VSize((npcbscHitNPC.Pawn.Location - Pawn.Location)) < float(1500)))
	{
		NPCLog("Friendly hit");
		if (Enemy == nullptr)
		{
			if (LineOfSightTo(pawnInstigator))
			{
				if (npcaiccCombatController == nullptr)
				{
					NPCSay(3, true, true);
				}
				SetDesiredTarget(pawnInstigator);
				return;
			}
			else
			{
				Enemy = pawnInstigator;
				pawnLastHeard = pawnInstigator;
				vLastTarget = pawnInstigator.Location;
				NPCChangeState("AdvanceOnEnemyLocation");
			}
		}
	}
	*/
}

bool ANPCBaseSoldierController::IsVisionBlockedBySmokeGrenade(FVector vTargetLocation)
{
	int32 iGrenadeIndex = 0;
	FRotator rotGrenade = FRotator(0, 0, 0);
	float fpAngle = 0;
	float fpSmokeTimeRemaining = 0;
	float fpTargetRange = 0;
	float fpTargetAngle = 0;
	/*
	fpTargetRange = VSize((vTargetLocation - Pawn.Location));
	fpTargetAngle = float(rotator((vTargetLocation - Pawn.Location)).Yaw);
	if (Pawn == nullptr)
	{
		return true;
	}
	NPCLog("IsVisionBlockedBySmokeGrenade() - target range: " $ string(fpTargetRange) $ ", target angle: " $ string(fpTargetAngle));
	for (iGrenadeIndex = 0; iGrenadeIndex < 10; iGrenadeIndex++)
	{
		if ((agtcGrenadeThreats[iGrenadeIndex].twpGrenade != nullptr) && agtcGrenadeThreats[iGrenadeIndex].twpGrenade.IsA("PickupT_M83_Smoke"))
		{
			NPCLog("Smoke grenade at distance: " $ string(VSize((agtcGrenadeThreats[iGrenadeIndex].twpGrenade.Location - Pawn.Location))) $ " is still alive");
			if (!agtcGrenadeThreats[iGrenadeIndex].twpGrenade._bBlewUpProcessed)
			{
			}
			if (VSize((agtcGrenadeThreats[iGrenadeIndex].twpGrenade.Location - Pawn.Location)) < fpTargetRange)
			{
				NPCLog("Grenade " $ string(agtcGrenadeThreats[iGrenadeIndex].twpGrenade) $ " is closer than target distance");
				if (IsLocationInFront(agtcGrenadeThreats[iGrenadeIndex].twpGrenade.Location) && IsLocationInFront(vTargetLocation))
				{
					NPCLog("Grenade " $ string(agtcGrenadeThreats[iGrenadeIndex].twpGrenade) $ " and target are both in front of us");
					rotGrenade = rotator((agtcGrenadeThreats[iGrenadeIndex].twpGrenade.Location - Pawn.Location));
					NPCLog("Angle to smoke grenade: " $ string(rotGrenade.Yaw));
					NPCLog("Angle to enemy pawn: " $ string(fpTargetAngle));
					if (float(rotGrenade.Yaw) > fpTargetAngle)
					{
						fpAngle = (float(rotGrenade.Yaw) - fpTargetAngle);
					}
					else
					{
						fpAngle = (fpTargetAngle - float(rotGrenade.Yaw));
					}
					NPCLog("Difference: " $ string(fpAngle));
					if (fpAngle > float(32768))
					{
						fpAngle -= float(32768);
					}
					NPCLog("Adjusted difference: " $ string(fpAngle));
					if (fpAngle < float(8192))
					{
						if (Level.TimeSeconds > (agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen + (agtcGrenadeThreats[iGrenadeIndex].twpGrenade._EffectDuration * 0.75)))
						{
							fpSmokeTimeRemaining = ((agtcGrenadeThreats[iGrenadeIndex].fpTimeSeen + agtcGrenadeThreats[iGrenadeIndex].twpGrenade._EffectDuration) - Level.TimeSeconds);
							if ((fpSmokeTimeRemaining / 4) < FRand())
							{
								NPCLog("Smoke grenade dispersing enough to not affect shot");
							}
						}
						else
						{
							NPCLog("Smoke grenade preventing shot");
							return true;
						}
						NPCLog("Smoke grenade at rotation " $ string(rotator((agtcGrenadeThreats[iGrenadeIndex].twpGrenade.Location - Pawn.Location))) $ " angle: " $ string(fpAngle) $ " not blocking");
					}
					NPCLog("Both smoke grenade and target not in front of NPC");
				}
			}
		}
	}
	*/
	return false;
}

void ANPCBaseSoldierController::SurrenderedThrowDownWeapon()
{
	//AGP_Pawn(Pawn).DropWeaponsAfterDeath();
}

int32 ANPCBaseSoldierController::DetermineBalanceOfPower()
{
	int32 iContactIndex = 0;
	int32 iAdvancingEnemy = 0;
	int32 iRetreatingEnemy = 0;
	float fpTeamThreatRating = 0;
	float fpAdvancingThreatRate = 0;
	float fpRetreatingThreatRating = 0;
	float fpBOPValue = 0;
	/*
	if (Pawn == nullptr)
	{
		return 0;
	}
	for (iContactIndex = 0; iContactIndex < 20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact != nullptr)
		{
			if (arcContactHistory[iContactIndex].fpClosureRate > 0)
			{
				iAdvancingEnemy++;
				fpAdvancingThreatRate += arcContactHistory[iContactIndex].fpThreatLevel;
			}
			else
			{
				fpRetreatingThreatRating += arcContactHistory[iContactIndex].fpThreatLevel;
				iRetreatingEnemy++;
			}
		}
	}
	fpTeamThreatRating = EvaluateEnemyThreat(Pawn);
	if (npcaiccCombatController != nullptr)
	{
		fpTeamThreatRating = GetThreatAnalysisForTeam();
	}
	if ((fpAdvancingThreatRate + fpRetreatingThreatRating) != 0)
	{
		fpBOPValue = ((fpTeamThreatRating / (fpAdvancingThreatRate + fpRetreatingThreatRating)) - 1);
	}
	else
	{
		fpBOPValue = 0;
	}
	fpBOPMajorAdvantageThreshold = 0.5;
	fpBOPMinorAdvantageThreshold = 0.11;
	fpBOPMinorDisadvantageThreshold = -0.09;
	fpBOPMajorDisadvantageThreshold = -0.5;
	if (fpBOPValue >= fpBOPMajorAdvantageThreshold)
	{
		iBalanceOfPowerState = 0;
	}
	else
	{
		if (fpBOPValue >= fpBOPMinorAdvantageThreshold)
		{
			iBalanceOfPowerState = 1;
		}
		else
		{
			if (fpBOPValue >= fpBOPMinorDisadvantageThreshold)
			{
				iBalanceOfPowerState = 2;
			}
			else
			{
				if (fpBOPValue >= fpBOPMajorDisadvantageThreshold)
				{
					iBalanceOfPowerState = 3;
				}
				else
				{
					iBalanceOfPowerState = 4;
				}
			}
		}
	}
	*/
	return iBalanceOfPowerState;
}

void ANPCBaseSoldierController::NotifyNPCSeen(APawn* Seen)
{
}

float ANPCBaseSoldierController::EvaluateEnemyThreat(APawn* pawnToEvaluate, bool bWatchingMe, float fpClosureRate)
{
	float fpThreat = 0;
	float fpDistance = 0;
	/*
	if (Pawn == nullptr)
	{
		return 0;
	}
	if (pawnToEvaluate == nullptr)
	{
		return 0;
	}
	if (pawnToEvaluate.IsA("Vehicle"))
	{
		if (Vehicle(pawnToEvaluate).bIsHelicopter)
		{
			fpThreat = 8;
		}
		else
		{
			fpThreat = 50;
		}
	}
	else
	{
		fpThreat = Super::EvaluateEnemyThreat(pawnToEvaluate, bWatchingMe, fpClosureRate);
	}
	if (fpNPCWeaponEffectiveRange > 0)
	{
		fpDistance = VSize((Pawn.Location - pawnToEvaluate.Location));
		if (fpDistance > fpNPCWeaponEffectiveRange)
		{
			(fpThreat -= (fpThreat * 0.25));
		}
		else
		{
			if ((fpDistance / fpNPCWeaponEffectiveRange) > 0.5)
			{
				(fpThreat -= (fpThreat * 0.1));
			}
		}
	}
	*/
	return fpThreat;
}

void ANPCBaseSoldierController::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
	float fpChance = 0;
	/*
	NPCLog("NPC getting warning from: " $ string(shooter));
	if (Pawn == nullptr)
	{
		return;
	}
	if (Pawn.Health <= 0)
	{
		return;
	}
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation.IsA("NPCCoverPositionPathNode")) && NPCCoverPositionPathNode(pnCurrentLocation).bSafeFromVehiclesImpact)
	{
		return;
	}
	fpChance = FRand();
	NPCSay(1, true, true);
	if (shooter.Controller.IsA("NPCBaseController"))
	{
		NPCLog("Friendly vehicle going to run us over: " $ string(shooter));
		actThreat = shooter;
		GotoState("LiveGrenade");
		return;
	}
	if (fpChance < 0.69)
	{
		actThreat = shooter;
		GotoState("LiveGrenade");
	}
	else
	{
		if (((fpChance > 0.66) && (fpChance < float(90))) && (Pawn.Weapon != nullptr))
		{
			SetDesiredTarget(shooter);
		}
		else
		{
			Prone();
			Pawn.bWantsToRollLeft = true;
			Pawn.bWantsToRollRight = false;
		}
	}
	*/
}

void ANPCBaseSoldierController::MoveOutAfterExitingVehicle()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	GotoState("PostExitVehicleActions");
	*/
}

ANPCPathNode* ANPCBaseSoldierController::FindHeadToObjective()
{
	/*
	local AGP_Objective AO;
	local TArray<AGP_Objective> aagpoFoundObjectives;
	local StaticMeshActor smaIterator;
	if (Pawn == nullptr)
	{
		return None;
	}
	ForEach AllActors(Class'StaticMeshActor', smaIterator, "ReinforcementGoal")
	{
		DebugLog(DEBUG_AI, "Found reinforcement goal location: " $ string(smaIterator));
		return LocateClosestNodeToLocation(smaIterator.Location);
	}
	DebugLog(DEBUG_AI, "Didn't find tagged reinforcement goal, searching for objectives");
	ForEach AllActors(class'AGP.AGP_Objective', AO)
	{
		if (AO.bInstantWin)
		{
			DebugLog(DEBUG_AI, string(Self) $ ".FindHeadToObjective() " $ string(Tag) $ " Found instant win objective, using it: " $ string(AO));
			aagpoFoundObjectives.insert(0, 1);
			aagpoFoundObjectives[0] = AO;
			continue;
		}
		if (((AO.bRequiredToWin && (!AO.bDisabled)) && (AO.AccomplishedBy != 0)) && (!AO.bInactive))
		{
			DebugLog(DEBUG_AI, string(Self) $ ".FindHeadToObjective() " $ string(Tag) $ " Found objective: " $ string(AO));
			aagpoFoundObjectives.insert(0, 1);
			aagpoFoundObjectives[0] = AO;
		}
	}
	if (aagpoFoundObjectives.Length == 0)
	{
		return LocateClosestNodeToLocation(AO.Location);
	}
	else
	{
		return LocateClosestNodeToLocation(aagpoFoundObjectives[Rand(aagpoFoundObjectives.Length)].Location);
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

ANPCPathNode* ANPCBaseSoldierController::FindHeadToNearestObjective()
{
	AAGP_Objective* AO = nullptr;
	AAGP_Objective* AONearest = nullptr;
	/*
	if (Pawn == nullptr)
	{
		return None;
	}
	ForEach AllActors(class'AGP.AGP_Objective', AO)
	{
		if (((AO.bRequiredToWin && (!AO.bDisabled)) && (AO.AccomplishedBy != 0)) && (!AO.bInactive))
		{
			DebugLog(DEBUG_AI, string(Self) $ ".FindHeadToNearestObjective() " $ string(Tag) $ " Found objective: " $ string(AO));
			if (AONearest == nullptr)
			{
				AONearest = AO;
				continue;
			}
			if (VSize((Pawn.Location - AONearest.Location)) > VSize((Pawn.Location - AO.Location)))
			{
				AONearest = AO;
				continue;
			}
		}
	}
	if (AONearest != nullptr)
	{
		return LocateClosestNodeToLocation(AONearest.Location);
	}
	else
	{
		return None;
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

void ANPCBaseSoldierController::HeadToObjective(float fpDelayTime, bool bHeadToNearestObjective)
{
	/*
	fpHeadToLocationStartDelay = (fpDelayTime * 1.5);
	if (iNPCCurrentOrders == 9)
	{
		NPCChangeState("AssaultLocation");
		return;
	}
	if (npcpnTravelLocation == nullptr)
	{
		if (bHeadToNearestObjective)
		{
			npcpnTravelLocation = FindHeadToNearestObjective();
			DebugLog(DEBUG_AI, "Nearest node to nearest objective: " $ string(npcpnTravelLocation));
		}
		else
		{
			npcpnTravelLocation = FindHeadToObjective();
			DebugLog(DEBUG_AI, "Nearest node to objective: " $ string(npcpnTravelLocation));
		}
	}
	if (npcpnTravelLocation == nullptr)
	{
		DebugLog(DEBUG_AI, string(Self) $ " didn't find any objectives, finding cover then fighting");
		NPCChangeState("FindCoverThenFight");
		return;
	}
	AICCHeadToLocation(npcpnTravelLocation.Location, npcpnTravelLocation);
	*/
}

void ANPCBaseSoldierController::SignalSoldiersShouldMoveOut(float fpMinDistance, int32 iSoldiersSent)
{
	int32 iSoldier = 0;
	int32 iSoldierToSend = 0;
	float fpClosestFound = 0;
	/*
	if (iSoldiersSent == NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers.Length)
	{
		return;
	}
	fpClosestFound = 0;
	for (iSoldier = 0; iSoldier < NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers.Length; iSoldier++)
	{
		if ((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldier] != Self) && (NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldier] != nullptr))
		{
			if (((VSize((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldier].Pawn.Location - npcpnTravelLocation.Location)) < fpClosestFound) || (fpClosestFound == 0)) && (VSize((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldier].Pawn.Location - npcpnTravelLocation.Location)) >= fpMinDistance))
			{
				iSoldierToSend = iSoldier;
				fpClosestFound = VSize((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldier].Pawn.Location - npcpnTravelLocation.Location));
			}
		}
	}
	if ((iSoldierToSend >= 0) && (NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend] != nullptr))
	{
		if (npcaiccCombatController != nullptr)
		{
			if (FRand() > 0.6)
			{
				if (FRand() > 0.5)
				{
					npcaiccCombatController.PlayEventAudio(NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend], "Taunt");
				}
				else
				{
					npcaiccCombatController.PlayEventAudio(NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend], "Attacking");
				}
			}
		}
		NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend].Run();
		NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend].npcpnTravelLocation = npcpnTravelLocation;
		NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend].iHeadToLocationCoverOption = iSoldiersSent;
		NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend].HeadToObjective(float(iSoldiersSent));
		NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers[iSoldierToSend] = nullptr;
		SignalSoldiersShouldMoveOut(fpClosestFound, (++iSoldiersSent));
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageSuppressEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		if (IsInState("Targeting"))
		{
			return;
		}
		else
		{
			AICCMessageEngageEnemy();
			return;
		}
	}
	sLastAICCMessage = "Suppress";
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 6) + (FRand() * 4));
		break;
	case 1:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 5) + (FRand() * 4));
		break;
	case 2:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 4) + (FRand() * 4));
		break;
	case 3:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 3) + (FRand() * 2));
		break;
	case 4:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 2) + (FRand() * 2));
		break;
	default:
	}
	(fpTimeToEndSuppressionFire += float(10));
	if (Enemy != nullptr)
	{
		SuppressiveFireRequested(Self, Enemy.Location);
	}
	else
	{
		SuppressiveFireRequested(Self, vLastTarget);
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageScanForEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && IsInState("Targeting"))
	{
		return;
	}
	sLastAICCMessage = "ScanForEnemy";
	Enemy = nullptr;
	fpTimeToLeaveFiringPosition = ((Level.TimeSeconds + 5) + (FRand() * 3));
	if (IsInState("SearchForTarget"))
	{
		return;
	}
	NPCChangeState("SearchForTarget");
	*/
}

void ANPCBaseSoldierController::AICCMessageEngageEnemy()
{
	int32 iHighestThreatIndex = 0;
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	NPCLog("AICCMessageEngageEnemy() entered");
	sLastAICCMessage = "EngageEnemy";
	if ((Enemy != nullptr) && IsInState("Targeting"))
	{
		return;
	}
	if (Enemy == nullptr)
	{
		iHighestThreatIndex = GetHighestThreatContactIndex(true);
		if (iHighestThreatIndex == -1)
		{
			NPCLog("AICCMessageEngageEnemy - but no enemy set or in history that's in LOS");
			AICCMessageScanForEnemy();
			return;
		}
		Enemy = arcContactHistory[iHighestThreatIndex].pawnContact;
		NPCLog("Found historical contact still in sight, using that for engagement");
	}
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 6) + (FRand() * 4));
		break;
	case 1:
		fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 4));
		break;
	case 2:
		fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 4) + (FRand() * 4));
		break;
	case 3:
		fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 3) + (FRand() * 2));
		break;
	case 4:
		fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 2) + (FRand() * 2));
		break;
	default:
	}
	fpTargetingStartTime = fpTimeToEndLastInterrupt;
	NPCLog("AICCMessageEngageEnemy() - Changing to Targeting");
	if (Enemy == nullptr)
	{
		NPCChangeState("SearchForTarget");
		return;
	}
	if (LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting");
	}
	else
	{
		NPCChangeState("SearchForTarget");
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageThrowFrag()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	sLastAICCMessage = "ThrowFrag";
	NPCLog("AICCMessageThrowFrag() entered");
	vTargetToSuppressLocation = vLastTarget;
	if (Enemy == nullptr)
	{
		Enemy = pawnLastEnemy;
	}
	if (Enemy != nullptr)
	{
		vGrenadeTarget = Enemy.Location;
	}
	if (ShouldThrowGrenade())
	{
		NPCChangeState("ThrowingGrenade");
		return;
	}
	AICCMessageEngageEnemy();
	*/
}

void ANPCBaseSoldierController::AICCMessageThrowSmoke()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	sLastAICCMessage = "ThrowSmoke";
	if ((Enemy != nullptr) && ThrowSmokeGrenade())
	{
		vGrenadeTarget = Enemy.Location;
		NPCChangeState("ThrowingGrenade");
		return;
	}
	AICCMessageEngageEnemy();
	*/
}

void ANPCBaseSoldierController::AICCMessageAdvance()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if (IsInState("AdvanceOnEnemyLocation"))
	{
		return;
	}
	sLastAICCMessage = "Advance";
	NPCLog("AICCMessageAdvance() entered");
	fpTimeToEndLastInterrupt = (Level.TimeSeconds + float(60));
	switch (iBalanceOfPowerState)
	{
	case 0:
		bAdvancedTactics = false;
		break;
	case 1:
		bAdvancedTactics = false;
		break;
	case 2:
		break;
	case 3:
		AICCMessageEngageEnemy();
		return;
	case 4:
		AICCMessageEngageEnemy();
		return;
	default:
	}
	if (Enemy == nullptr)
	{
		Enemy = pawnLastEnemy;
	}
	if (Enemy != nullptr)
	{
		vLastTarget = Enemy.Location;
		pawnLastHeard = Enemy;
		NPCChangeState("AdvanceOnEnemyLocation");
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageSwitchWeapons(bool bIgnoreBOP)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	sLastAICCMessage = "SwitchWeapons";
	NPCLog("AICCMessageSwitchWeapons() entered");
	if (!bIgnoreBOP)
	{
		switch (iBalanceOfPowerState)
		{
		case 0:
		case 1:
			break;
		case 2:
			if (!IsInCover())
			{
				AICCMessageSeekCover();
				return;
			}
			break;
		case 3:
			if (!IsInCover())
			{
				AICCMessageSeekCover();
				return;
			}
			break;
		case 4:
			AICCMessageBreakOut();
			return;
		default:
		}
	}
	if (((agpwPrimary != nullptr) && agpwPrimary.IsA("PistolWeapon")) || ((agpwSecondary != nullptr) && agpwSecondary.IsA("PistolWeapon")))
	{
		if (!IsInCover())
		{
			AICCMessageSeekCover();
		}
		else
		{
			npcaiccCombatController.ReportActionFailed(Self);
		}
		return;
	}
	if (((Pawn != nullptr) && (agpwPrimary != nullptr)) && (agpwSecondary != nullptr))
	{
		NPCLog(" Primary Weapon change from " $ string(Pawn.Weapon) $ " (primary weapon \"" $ string(namePrimaryWeapon) $ "\" and secondary: \"" $ string(nameSecondaryWeapon) $ "\"");
		NPCChangeState("SwapWeapons");
	}
	else
	{
		NPCLog(" No alternate weapon found, trying reload or run away");
		if ((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			AICCMessageReload();
		}
		else
		{
			if (!IsInCover())
			{
				AICCMessageSeekCover();
			}
			else
			{
				npcaiccCombatController.ReportActionFailed(Self);
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::AICCMessagePursueEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	if (IsInState("PursueEnemy"))
	{
		return;
	}
	sLastAICCMessage = "PursueEnemy";
	fpTimeToEndLastInterrupt = (Level.TimeSeconds + float(60));
	NPCLog("AICCMessagePursueEnemy() entered");
	if (Enemy == nullptr)
	{
		Enemy = pawnLastEnemy;
	}
	if (Enemy != nullptr)
	{
		iNPCTacticalOrders = 300;
		vLastTarget = Enemy.Location;
		NPCChangeState("PursueEnemy");
	}
	else
	{
		npcaiccCombatController.ReportActionFailed(Self);
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageBreakOut()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	sLastAICCMessage = "BreakOut";
	Enemy = nullptr;
	MoveToAlamoFirePosition();
	*/
}

void ANPCBaseSoldierController::AICCMessageFallBack()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	sLastAICCMessage = "FallBack";
	if (Enemy != nullptr)
	{
		vTargetToSuppressLocation = Enemy.Location;
	}
	else
	{
		if (pawnLastEnemy != nullptr)
		{
			vTargetToSuppressLocation = pawnLastEnemy.Location;
		}
	}
	Enemy = nullptr;
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpChanceOfShootingOnFallback = 0.85;
		fpChanceOfThrowingFragOnFallback = 0.5;
		break;
	case 1:
		fpChanceOfShootingOnFallback = 0.7;
		fpChanceOfThrowingFragOnFallback = 0.25;
		break;
	case 2:
		fpChanceOfShootingOnFallback = 0.5;
		fpChanceOfThrowingFragOnFallback = 0;
		break;
	case 3:
		fpChanceOfShootingOnFallback = 0.2;
		fpChanceOfThrowingFragOnFallback = 0;
		break;
	case 4:
		fpChanceOfShootingOnFallback = 0;
		fpChanceOfThrowingFragOnFallback = 0;
		break;
	default:
	}
	NPCChangeState("FindCoverThenFight", "PopSmokeFirst");
	*/
}

void ANPCBaseSoldierController::AICCMessageFlankEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	npcaiccCombatController.ReportActionFailed(Self);
	*/
}

void ANPCBaseSoldierController::AICCMessageShiftPosition()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		NPCChangeState("MoveToNewCamperPosition");
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			NPCChangeState("MoveToNewHarassPosition");
		}
		else
		{
			NPCChangeState("MoveToNewFiringPosition");
		}
	}
	fpTimeToEndLastInterrupt = ((Level.TimeSeconds + float(10)) + (FRand() * 10));
	*/
}

void ANPCBaseSoldierController::AICCMessageRushEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	if (Enemy != nullptr)
	{
		NPCChangeState("RushEnemy");
	}
	else
	{
		NPCChangeState("SearchForTarget");
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageTauntEnemy()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	sLastAICCMessage = "Collapse";
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("TauntEnemy");
	}
	else
	{
		npcaiccCombatController.ReportActionFailed(Self);
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageSeekCover()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if ((((Enemy != nullptr) && LineOfSightTo(Enemy)) && (pnCurrentLocation != nullptr)) && pnCurrentLocation.IsA("NPCFirePositionPathNode"))
	{
		NPCChangeState("Targeting", "TurnToEnemy");
		return;
	}
	sLastAICCMessage = "SeekCover";
	Run();
	if (IsInState("Targeting"))
	{
		NPCChangeState("MoveToNewFiringPosition");
	}
	else
	{
		pawnLastEnemy = Enemy;
		Enemy = nullptr;
		NPCChangeState("FindCover");
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageRequestMortar()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController.AddSupportRequestToQueue(Self, 1, vLastTarget, pawnLastEnemy);
	}
	*/
}

void ANPCBaseSoldierController::AICCMessageDuckAndCover()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	sLastAICCMessage = "DuckAndCover";
	npcaiccCombatController.ReportActionFailed(Self);
	*/
}

void ANPCBaseSoldierController::AICCMessageCollapse()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	sLastAICCMessage = "Collapse";
	Enemy = nullptr;
	NPCChangeState("Collapse");
	*/
}

void ANPCBaseSoldierController::AICCMessageCrazyIvan()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	sLastAICCMessage = "CrazyIvan";
	NPCChangeState("CrazyIvan", "SpinAround");
	*/
}

void ANPCBaseSoldierController::AICCMessageSurrender()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	Enemy = nullptr;
	Log("Surrender order received");
	NPCChangeState("Surrender");
	*/
}

void ANPCBaseSoldierController::AICCMessageFireBlindly()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		AICCMessageEngageEnemy();
		return;
	}
	if (((((Pawn.Weapon != nullptr) && Pawn.Weapon.IsA("RocketWeapon")) || (pnCurrentLocation == nullptr)) || (NPCFirePositionPathNode(pnCurrentLocation) == nullptr)) || (((((pnCurrentLocation != nullptr) && (NPCFirePositionPathNode(pnCurrentLocation) != nullptr)) && (!NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)) && (!NPCFirePositionPathNode(pnCurrentLocation).bBlindFireRight)) && (!NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)))
	{
		AICCMessageEngageEnemy();
		return;
	}
	pawnLastEnemy = Enemy;
	Enemy = nullptr;
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 6) + (FRand() * 4));
		break;
	case 1:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 5) + (FRand() * 4));
		break;
	case 2:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 4) + (FRand() * 4));
		break;
	case 3:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 3) + (FRand() * 2));
		break;
	case 4:
		fpTimeToEndSuppressionFire = ((Level.TimeSeconds + 2) + (FRand() * 2));
		break;
	default:
	}
	(fpTimeToEndSuppressionFire += float(10));
	fpTargetingStartTime = 0;
	fpTimeToEndLastInterrupt = (Level.TimeSeconds + float(40));
	if (IsInState("FiringBlindly"))
	{
		return;
	}
	NPCChangeState("FiringBlindly");
	*/
}

void ANPCBaseSoldierController::AICCMessageCower()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	pawnLastEnemy = Enemy;
	Enemy = nullptr;
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpTimeToEndCowering = ((Level.TimeSeconds + 3) + (FRand() * 3));
		break;
	case 1:
		fpTimeToEndCowering = ((Level.TimeSeconds + 4) + (FRand() * 3));
		break;
	case 2:
		fpTimeToEndCowering = ((Level.TimeSeconds + 5) + (FRand() * 3));
		break;
	case 3:
		fpTimeToEndCowering = ((Level.TimeSeconds + 6) + (FRand() * 3));
		break;
	case 4:
		fpTimeToEndCowering = ((Level.TimeSeconds + 7) + (FRand() * 3));
		break;
	default:
	}
	if (IsInState("Cowering"))
	{
		return;
	}
	NPCChangeState("Cowering");
	*/
}

void ANPCBaseSoldierController::AICCMessageReload()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (((((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType() != nullptr)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount != 0)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount >= (Pawn.Weapon.PickupAmmoCount / 2)))
	{
		NPCLog("Ignoring AICC reload command due to plenty of ammo in weapon");
		return;
	}
	if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && (VSize((Pawn.Location - Enemy.Location)) < float(250)))
	{
		if (!IsInCover())
		{
			NPCLog("AI not in cover but needs to reload and enemy very close, running to cover");
			NPCChangeState("FindCoverThenFight");
			return;
		}
	}
	NPCLog("AICC reload command with " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount) $ " rounds in weapon");
	NPCChangeState("ReloadWeapon");
	*/
}

void ANPCBaseSoldierController::AICCReturnToPreviousState()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	NPCChangeState(GetLastStateName());
	*/
}

void ANPCBaseSoldierController::AICCLiveGrenade()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	fpTimeToEndLastInterrupt = (Level.TimeSeconds + float(20));
	Run();
	NPCChangeState("LiveGrenade");
	*/
}

void ANPCBaseSoldierController::AICCActionComplete()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (IsInState("SearchForTarget") || IsInState("MoveToNewFiringPosition"))
	{
		return;
	}
	if (IsInCover())
	{
		NPCChangeState("SearchForTarget");
	}
	else
	{
		NPCChangeState("MoveToNewFiringPosition");
	}
	*/
}

void ANPCBaseSoldierController::AICCResumePreviousState()
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 0)
	{
		NPCChangeState("ReturnToPatrol");
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			NPCChangeState("MoveToNewFiringPosition");
		}
		else
		{
			if (iNPCCurrentOrders == 2)
			{
				NPCChangeState("MoveToNewCamperPosition");
			}
			else
			{
				NPCChangeState(GetLastStateName());
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::AICCReturnToPatrol()
{
	//NPCChangeState("ReturnToPatrol");
}

void ANPCBaseSoldierController::AICCHeadToLocation(FVector vLocation, ANPCPathNode* npcpn)
{
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	npcpnTravelLocation = npcpn;
	vTravelLocation = vLocation;
	NPCChangeState("HeadToTravelLocation");
	*/
}

void ANPCBaseSoldierController::Destroyed()
{
	/*
	anpcfppnFiringPositions.remove(0, anpcfppnFiringPositions.Length);
	if (agpwPrimary != nullptr)
	{
		agpwPrimary.Destroy();
	}
	if (agpwSecondary != nullptr)
	{
		agpwSecondary.Destroy();
	}
	Super::Destroyed();
	*/
}

void ANPCBaseSoldierController::SaveTargetingStatusHistory(FString sStatus)
{
	int32 iHistoryIndex = 0;
	/*
	for (iHistoryIndex = (10 - 1); iHistoryIndex > 0; iHistoryIndex--)
	{
		asTargetingStatus[iHistoryIndex] = asTargetingStatus[(iHistoryIndex - 1)];
	}
	asTargetingStatus[0] = sStatus;
	*/
}
