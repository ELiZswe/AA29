// All the original content belonged to the US Army


#include "NPCBaseSoldierController.h"

ANPCBaseSoldierController::ANPCBaseSoldierController()
{

}

/*
State LookAtDeadTeammate
{
	Function NPCSayManDown()
	{
		if (npcaiccCombatController == None)
		{
			NPCSay(4,true,true);
		}
	}
	Function NPCSayAlertOnAttack()
	{
		if (npcaiccCombatController == None)
		{
			NPCSay(18,true,true);
		}
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'End'
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
	if (Enemy == None)
	{
		NPCLog("Returning to SearchForTarget");
		GotoState('SearchForTarget');
	}
	else
	{
		Focus=Enemy;
		bRotateToDesired=true;
		FinishRotation();
		GotoState('Targeting');
	}
}
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
		NPCChangeState('SearchForTarget');
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		if ((Focus != None) && Focus.IsA('Weapon'))
		{
			NPCLog("AICC told about weapon sound " $ string(Focus));
			if (npcaiccCombatController != None)
			{
				if (npcaiccCombatController.ReportHeardGunfire(Self,Focus.Location))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
			}
			return;
		}
		if ((npcaiccCombatController != None) && (Focus != None))
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
State Targeting
{
	Function bool NeedToTurn()
	{
		if (Enemy == None)
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
		StopCustomTimer('LostSightOfEnemyTimer');
		AGP_Pawn(Pawn).ResetLean();
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == None)
		{
			return;
		}
		if (actorColliding != None)
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
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		if (pnDNCTempPathNode != None)
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
		NPCLog("NotifyEnemyNotVisible() entered for pawn " $ string(Enemy));
		if ((Enemy != None) && (Enemy.Health <= 0))
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
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
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
			if (npcaiccCombatController != None)
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
			if (pnCurrentPathNode.IsA('NPCFirePositionPathNode'))
			{
				NPCLog("Current firing position is too scary, move to new one");
				Stand();
				NPCChangeState('MoveToNewFiringPosition');
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
						GotoState('FindCoverThenFight');
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
		if (Enemy == None)
		{
			if ((Vehicle(pawnLastEnemy) != None) && Vehicle(pawnLastEnemy).bIsHelicopter)
			{
				NPCChangeState('ReturnToPatrol');
				return;
			}
			sTargetingStatus="Lost contact, enemy gone, switching to searching";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState('SearchForTarget');
			return;
		}
		else
		{
			if (! LineOfSightTo(Enemy))
			{
				if ((Vehicle(Enemy) != None) && Vehicle(Enemy).bIsHelicopter)
				{
					NPCChangeState(GetLastStateName());
					return;
				}
				if (iNPCCurrentOrders == 9)
				{
					NPCChangeState('AssaultLocation');
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
					NPCChangeState('SearchForTarget');
					return;
				}
			}
			else
			{
				StopCustomTimer('LostSightOfEnemyTimer');
				NPCChangeState('Targeting','AimAtTarget');
				return;
			}
		}
		SetCustomTimer(0.5,false,'LostSightOfEnemyTimer');
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
			if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("SeePlayer");
			}
			if ((npcaiccCombatController != None) && (pawnSeen != None))
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
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
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
			NPCChangeState('SearchForTarget','TurnToNoise');
		}
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		Global.agpobj(fpLoudness,pawnHeard);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		int32 iDifference = 0;
		if (((agpwWeaponHeard.Instigator != None) && (agpwWeaponHeard.Instigator.Controller != None)) && (! agpwWeaponHeard.Instigator.Controller.IsA('HumanController')))
		{
			return;
		}
		if ((Enemy != None) && (agpwWeaponHeard == Enemy.Weapon))
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
			NPCChangeState('SearchForTarget','TurnToNoise');
		}
	}
	Function bool ShouldLean()
	{
		FVector LookDir = FVector(0,0,0);
		FVector AimDir = FVector(0,0,0);
		float fpAngleRadians = 0;
		if (Enemy == None)
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
	if (Pawn == None)
	{
		JL'HandlePawnDeath'
;
	}
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	UnslingWeapon();
	Sleep(0.1);
	StopMovement();
	fpTargetingStartTime=((Level.TimeSeconds + 4) + (FRand() * 3));
	if (Pawn == None)
	{
		JL'HandlePawnDeath'
;
	}
	Sleep(0.1);
	sTargetingStatus="Adjusting posture";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((Enemy == None) || ((Enemy != None) && (! LineOfSightTo(Enemy))))
	{
		if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode'))
		{
			NPCLog("in fire position, adjusting posture for firing");
			if (NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Length > 0)
			{
				npcdacpnActiveDuckAndCoverNode=NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode[Rand(NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Length)];
				pnDNCTempPathNode=None;
				if (pnDNCTempPathNode != npcdacpnActiveDuckAndCoverNode)
				{
					pnDNCTempPathNode=PathNode(FindPathToward(npcdacpnActiveDuckAndCoverNode,true));
					if (pnDNCTempPathNode != None)
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
	if (((Enemy == None) || ((Enemy != None) && (! LineOfSightTo(Enemy)))) || IsInCover())
	{
		if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode'))
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
			NPCLog("Not in firing position, using pawn preference for crouching");
			if ((FRand() * 100) < fNPCLikesToCrouch)
			{
				Crouch();
				Sleep(0.25);
			}
		}
	}
	fpTargetingStartTime=((Level.TimeSeconds + 3) + (FRand() * 3));
	if (Pawn == None)
	{
		JL'HandlePawnDeath'
;
	}
	sTargetingStatus="Turning to target";
	SaveTargetingStatusHistory(sTargetingStatus);
	StopMovement();
	if (Enemy != None)
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
	if (Pawn == None)
	{
		JL'HandlePawnDeath'
;
	}
	if (Pawn.Weapon == None)
	{
		NPCChangeState('FindCover');
	}
	if ((Enemy != None) && (! IsLocationInFront(Enemy.Location)))
	{
		Sleep(0.1);
		JL'TurnToEnemy'
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
				NPCChangeState('AssaultLocation');
				JL'End'
;
			}
			NPCChangeState('MoveToNewFiringPosition');
			JL'End'
;
		}
	}
	if (AGP_Weapon(Pawn.Weapon) != None)
	{
		AGP_Weapon(Pawn.Weapon).ForceTempRaiseWeapon();
	}
	if (! Pawn.Weapon.IsZoomed())
	{
		AGP_Weapon(Pawn.Weapon).ServerZoom(true);
	}
	if (Pawn.Weapon.IsInState('BusyZooming'))
	{
		Sleep(0.1);
	}
	Walk();
	AGP_Pawn(Pawn).ChangeAnimation();
	if (Enemy != None)
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
		NPCChangeState('SearchForTarget');
		JL'End'
;
	}
	if (NPCFirePositionPathNode(pnCurrentLocation) != None)
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
	if ((((VSize((Pawn.Location - vLastTarget)) < float(800)) && (iNPCCurrentOrders != 9)) && (Pawn.Weapon != None)) && (! Pawn.Weapon.IsA('RocketWeapon')))
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
		if ((Enemy != None) && Enemy.IsA('Vehicle'))
		{
			if ((Pawn.Weapon != None) && (! Pawn.Weapon.IsA('RocketWeapon')))
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
	if (Pawn.Weapon == None)
	{
		NPCChangeState('FindCover');
		JL'End'
;
	}
	sTargetingStatus="Aiming sleep: " $ string(fpAimTime);
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(fpAimTime);
	iRoundsFiredSinceCameOutOfCover=0;
	if ((Pawn.Weapon != None) && Pawn.Weapon.IsA('ThrowWeapon'))
	{
		sTargetingStatus="ShootTarget, with grenade in hand, swapping";
		SaveTargetingStatusHistory(sTargetingStatus);
		AGP_Pawn(Pawn).SwapHands();
		Sleep(0.75);
		JL'ShootTarget'
;
	}
	sTargetingStatus="ShootTarget, testing pawn and then enemy";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (Pawn == None)
	{
		JL'HandlePawnDeath'
;
	}
	if (Pawn.Weapon == None)
	{
		NPCChangeState('FindCover');
	}
	if (AGP_Weapon(Pawn.Weapon).IsInState('BusyTempLowering'))
	{
		sTargetingStatus="ShootTarget, Waiting for weapon up: " $ string(Pawn.Weapon.GetStateName());
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL'ShootTarget'
;
	}
	if (NeedToTurn())
	{
		if (Enemy == None)
		{
			NPCChangeState('SearchForTarget');
			JL'End'
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
		JL'TurnToEnemy'
;
	}
	if (Enemy != None)
	{
		if (Focus != Enemy)
		{
			Focus=Enemy;
			Sleep(0.25);
		}
	}
	if (((Enemy != None) && (VSize((Pawn.Location - Enemy.Location)) <= float(1650))) && (! Enemy.IsA('Vehicle')))
	{
		sTargetingStatus="Close range enemy, testing to see if NPC has Rocket";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((((Pawn != None) && (Pawn.Weapon != None)) && Pawn.Weapon.IsA('RocketWeapon')) && (agpwSecondary != None))
		{
			Sleep(0.1);
			sTargetingStatus="RPG in hand, too close, switching";
			SaveTargetingStatusHistory(sTargetingStatus);
			AICCMessageSwitchWeapons(true);
			JL'End'
;
		}
	}
	if (((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode')) && (! pnCurrentLocation.IsA('NPCCamperFirePositionPathNode')))
	{
		sTargetingStatus="At non-camper firing position, testing leave time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("At non-camper fire position - been here for " $ string((Level.TimeSeconds - fpTargetingStartTime)) $ " seconds");
		if (((fpTargetingStartTime != 0) && (Level.TimeSeconds >= fpTargetingStartTime)) && ((Level.TimeSeconds - fpTimeEnteredCover) > 5))
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot && (FRand() <= 0.75))
			{
				NPCChangeState('ManningPopAndShootFirePosition');
				JL'End'
;
			}
			else
			{
				if (iNPCCurrentOrders == 9)
				{
					sTargetingStatus="Time to resume assault";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCLog("Signaling we should move to closer assault firing position");
					NPCChangeState('AssaultLocation');
					JL'RealEnd'
;
				}
				sTargetingStatus="Time to leave";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCLog("Signaling we should move to new firing position");
				NPCChangeState('MoveToNewFiringPosition');
				JL'End'
;
			}
		}
	}
	if (IsConcerned() && (! IsInCover()))
	{
		sTargetingStatus="Nervous in open";
		SaveTargetingStatusHistory(sTargetingStatus);
		actThreat=Enemy;
		if ((pnCurrentLocation != None) && (! pnCurrentLocation.IsA('NPCFirePositionPathNode')))
		{
			sTargetingStatus="Nervous in open, finding cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NPC is nervous and not in fighting position, trying to find cover");
			NPCChangeState('FindCoverThenFight');
			JL'End'
;
		}
	}
	if ((Enemy != None) && IsVisionBlockedBySmokeGrenade(Enemy.Location))
	{
		sTargetingStatus="Vision Blocked by smoke";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("LostEnemy");
		}
		if (npcaiccCombatController != None)
		{
			if (npcaiccCombatController.ReportLostContact(Self,Enemy))
			{
				sTargetingStatus="Smoke blocked, AICC ordering change";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(Self);
				JL'End'
;
			}
		}
		sTargetingStatus="Smoke blocking our view, going to SearchForTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Smoke blocking target view - going to search for target");
		NPCChangeState('SearchForTarget');
		JL'End'
;
	}
	if (ShouldThrowGrenade())
	{
		sTargetingStatus="Want to throw grenade";
		SaveTargetingStatusHistory(sTargetingStatus);
		vGrenadeTarget=Enemy.Location;
		NPCChangeState('ThrowingGrenade');
		JL'End'
;
	}
	else
	{
		if (! SafeToFire())
		{
			sTargetingStatus="Not safe to fire!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.1);
			JL'AimAtTarget'
;
		}
		if ((Enemy != None) && (GetAngleToLocation(Enemy.Location) < 0.9))
		{
			sTargetingStatus="Valid enemy, he's now to our back";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Angle to enemy: " $ string(GetAngleToLocation(Enemy.Location)));
			JL'TurnToEnemy'
;
		}
		if ((((Enemy == None) && (Pawn != None)) && (Pawn.Weapon != None)) && Pawn.Weapon.IsA('RocketWeapon'))
		{
			NPCChangeState('SearchForTarget');
			JL'End'
;
		}
		if (AGP_Weapon(Pawn.Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Pawn.Weapon.GotoState('BusyFixingJam');
			AGP_Weapon(Pawn.Weapon).bIsJammed=false;
			if (Pawn.Weapon.IsInState('BusyFixingJam'))
			{
				Sleep(0.1);
			}
		}
		if (AGP_Weapon(Pawn.Weapon).IsInState('BusyRaisingWeapon'))
		{
			Sleep(0.25);
		}
		if ((Enemy != None) && (VSize((Pawn.Location - Enemy.Location)) > Level.DistanceFogStart))
		{
			if ((FRand() > 0.5) && ((Pawn.Weapon != None) && (! Pawn.Weapon.IsA('RocketWeapon'))))
			{
				vTargetToSuppressLocation=Enemy.Location;
				NPCChangeState('ProvidingSuppressiveFire');
			}
			else
			{
				fpTimeSinceUntilTargetLost=Level.TimeSeconds;
				NPCChangeState('SearchForTarget');
				Log("Lost sight by fog distance, switching to search for target");
			}
			JL'End'
;
		}
		sTargetingStatus="Firing";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((Enemy != None) && (! LineOfSightTo(Enemy)))
		{
			sTargetingStatus="Lost sight after shot";
			SaveTargetingStatusHistory(sTargetingStatus);
			NotifyEnemyNotVisible();
			JL'WatchForTarget'
;
		}
		if ((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None))
		{
			NPCLog("Current ammo count for weapon: " $ string(Pawn.Weapon) $ " is: " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
		}
		if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			sTargetingStatus="need to reload";
			SaveTargetingStatusHistory(sTargetingStatus);
			if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("WeaponJam");
			}
			if (npcaiccCombatController != None)
			{
				sTargetingStatus="Reported reload need to AICC";
				SaveTargetingStatusHistory(sTargetingStatus);
				AICCMessageReload();
			}
			else
			{
				NPCChangeState('ReloadWeapon');
			}
			JL'End'
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
			if ((NPCFirePositionPathNode(pnCurrentLocation) != None) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
			{
				NPCChangeState('ManningPopAndShootFirePosition');
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
			JL'AimAtTarget'
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
			JL'ShootTarget'
;
		}
	}
	if ((Enemy != None) && (Enemy.Health <= 0))
	{
		sTargetingStatus="Enemy dead/lost";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Enemy now down");
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("EnemyKilled");
		}
		if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
		{
			NPCChangeState('ManningPopAndShootFirePosition');
			JL'End'
;
		}
		if (npcaiccCombatController != None)
		{
			if (npcaiccCombatController.ReportKilledEnemy(Self,Enemy))
			{
				sTargetingStatus="Enemy dead, reporting to AICC";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(Self);
				JL'End'
;
			}
		}
		sTargetingStatus="No AICC or it didn't handle it, enemy dead";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (IsInCover())
		{
			NPCChangeState('SearchForTarget');
		}
		else
		{
			if (iNPCCurrentOrders == 9)
			{
				NPCChangeState('AssaultLocation');
				JL'RealEnd'
;
			}
			NPCChangeState('FindCoverThenFight');
		}
		JL'End'
;
	}
	if (Pawn.Weapon != None)
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
	if ((Pawn.Weapon != None) && (Pawn.Weapon.weaponType == 4))
	{
		sTargetingStatus="Sniper going back to AimAtTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL'AimAtTarget'
;
	}
	sTargetingStatus="Returning to ShootTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	JL'ShootTarget'
;
	Focus=None;
	sTargetingStatus="WatchForTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	fpWatchingForLostTargetTime=((Level.TimeSeconds + (FRand() * 5)) + 3);
	sTargetingStatus="Watching for lost target";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (Level.TimeSeconds >= fpWatchingForLostTargetTime)
	{
		if ((Vehicle(Enemy) != None) && Vehicle(Enemy).bIsHelicopter)
		{
			NPCChangeState(GetLastStateName());
			JL'End'
;
		}
		if (iNPCCurrentOrders == 9)
		{
			sTargetingStatus="Time to resume assault after losing contact";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Signaling we should move to closer assault firing position after losing contact");
			NPCChangeState('AssaultLocation');
			JL'RealEnd'
;
		}
		if (npcaiccCombatController.ReportLostContact(Self,Enemy))
		{
			sTargetingStatus="Lost contact, performing AICC action";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (! ((sLastCombatAction ~= "DoNothing") || (sLastCombatAction ~= "Ignore")))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
				JL'End'
;
			}
			else
			{
				sTargetingStatus="Lost contact, ignoring bad AICC action, switching to searching state";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState('SearchForTarget');
				JL'End'
;
			}
		}
		else
		{
			sTargetingStatus="Lost contact, performing No AICC action, switching to searching state";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState('SearchForTarget');
			JL'End'
;
		}
	}
	if ((Enemy != None) && LineOfSightTo(Enemy))
	{
		sTargetingStatus="LOS to enemy, trying ShootTarget again";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL'AimAtTarget'
;
	}
	sTargetingStatus="Still watching for target to reappear in: " $ string((fpWatchingForLostTargetTime - Level.TimeSeconds));
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(0.6);
	JL'KeepWatching'
;
	if ((npcdacpnActiveDuckAndCoverNode != None) && (npcdacpnActiveDuckAndCoverNode.npcpnPrimaryFiringPosition != None))
	{
		sTargetingStatus="Ending duck and cover in targeting, moving back";
		SaveTargetingStatusHistory(sTargetingStatus);
		pnDNCTempPathNode=None;
		if (pnDNCTempPathNode != npcdacpnActiveDuckAndCoverNode)
		{
			pnDNCTempPathNode=PathNode(FindPathToward(npcdacpnActiveDuckAndCoverNode.npcpnPrimaryFiringPosition,true));
			if (pnDNCTempPathNode != None)
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
	if ((Pawn != None) && (Pawn.Health > 0))
	{
		sTargetingStatus="Pawn still alive at end of targeting, forcing to new order";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (iNPCCurrentOrders == 9)
		{
			NPCChangeState('AssaultLocation');
		}
		else
		{
			NPCChangeState('FindCoverThenFight');
		}
	}
}
State ReloadWeapon
{
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
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
		if (((Pawn != None) && (Pawn.Weapon != None)) && (Pawn.Weapon.GetCurrentAmmoType() != None))
		{
			if ((((Pawn.Weapon.GetCurrentAmmoType().AmmoAmount > 0) && (Enemy != None)) && LineOfSightTo(Enemy)) && (VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)))
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
		if ((Pawn != None) && (Pawn.Weapon != None))
		{
			NPCLog("ammo type: " $ string(Pawn.Weapon.GetCurrentAmmoType()));
		}
		return false;
	}
Begin:
	Sleep(0);
	AGP_Pawn(Pawn).ResetLean();
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if ((Pawn.Weapon != None) && Pawn.Weapon.IsA('RocketWeapon'))
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
			AGP_Pawn(Pawn).GotoState('BusyReloading');
			NPCLog(string(Self) $ " Put RPG into reload state");
			if (AGP_Pawn(Pawn).IsInState('BusyReloading'))
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
			if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			sTargetingStatus="RPG reloaded";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.5);
			NPCChangeState('Targeting','AimAtTarget');
			JL'End'
;
		}
		else
		{
			NPCLog("Out of ammo for RPG");
			if ((((AGP_Pawn(Pawn).getShoulderInventory() != None) && AGP_Pawn(Pawn).getShoulderInventory().IsA('Weapon')) && (AGP_Weapon(AGP_Pawn(Pawn).getShoulderInventory()).GetCurrentAmmoType() != None)) && (AGP_Weapon(AGP_Pawn(Pawn).getShoulderInventory()).GetCurrentAmmoType().AmmoAmount > 0))
			{
				AICCMessageSwitchWeapons();
				JL'End'
;
			}
			else
			{
				if ((npcaiccCombatController != None) && npcaiccCombatController.ReportOutOfAmmo(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					JL'End'
;
				}
				AICCMessageFallBack();
			}
			JL'End'
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
			if (AGP_Pawn(Pawn).IsInState('BusyReloading'))
			{
				Sleep(0.1);
			}
			Sleep(0.5);
			if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
			{
				AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			if (npcaiccCombatController != None)
			{
				NPCChangeState('Targeting','AdjustPosture');
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
				JL'End'
;
			}
			else
			{
				NPCChangeState('Targeting','AdjustPosture');
			}
		}
		else
		{
			if (((((((Pawn != None) && (Pawn.Weapon != None)) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount > 0)) && (Enemy != None)) && LineOfSightTo(Enemy)) && (VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)))
			{
				NPCChangeState('Targeting','TurnToEnemy');
				JL'End'
;
			}
			NPCChangeState('RetreatFromBattle');
			if (npcaiccCombatController != None)
			{
				if (npcaiccCombatController.ReportOutOfAmmo(Self))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
					JL'End'
;
				}
			}
			JL'End'
;
		}
	}
	NPCChangeState(GetLastStateName());
}
State FiringM203
{
}
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
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
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
		if (Enemy != None)
		{
			NPCLog("Returning from throwing grenade to targeting");
			NPCChangeState('Targeting');
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
				NPCChangeState('SearchForTarget');
			}
		}
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDiedEnd'
;
	}
	StopMovement();
	AGP_Pawn(Pawn).ResetLean();
	if (AGP_Pawn(Pawn)._InvGrenades[iDesiredGrenadeIndex] == 0)
	{
		NPCLog("Ack - out of this grenade!");
		JL'End'
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
	if (AGP_Pawn(Pawn).DesiredGrenade == None)
	{
		NPCLog("No desired grenade found!");
		JL'End'
;
	}
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("Found grenade " $ string(AGP_Pawn(Pawn).DesiredGrenade) $ " to swap in place of current weapon: " $ string(Pawn.Weapon));
	NPCLog("Hands inventory now contains: " $ string(AGP_Pawn(Pawn).getHandsInventory()));
	AGP_Pawn(Pawn).SwapHands();
	if (agpwPrimary != None)
	{
		Sleep(agpwPrimary.GetAnimDuration('Drop'));
	}
	if (agpwSecondary != None)
	{
		Sleep(agpwSecondary.GetAnimDuration('Select'));
	}
	Sleep(1);
	NPCLog("Hands inventory contains after swap: " $ string(AGP_Pawn(Pawn).getHandsInventory()));
	NPCLog("Weapon swapping done - weapon in hand is now: " $ string(Pawn.Weapon));
	if (! Pawn.Weapon.IsA('ThrowWeapon'))
	{
		NPCLog("Apparently the weapon in hand is no longer a throw weapon: " $ string(Pawn.Weapon));
		JL'End'
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
	if (npcaiccCombatController == None)
	{
		NPCSay(22,true,true);
	}
	Sleep(2.5);
	if (NPCFirePositionPathNode(pnCurrentPathNode) != None)
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
	Sleep(agpwPrimary.GetAnimDuration('Drop'));
	if (agpwSecondary != None)
	{
		Sleep(agpwSecondary.GetAnimDuration('Select'));
	}
	Sleep(0.5);
	sTargetingStatus="Primary weapon should be in hand now";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (FRand() > 0.8)
	{
		Sleep(((FRand() * 5) + 2.5));
		JL'Begin'
;
	}
	PostGrenadeThrowTask();
	if (iNPCCurrentOrders == 9)
	{
		NPCChangeState('AssaultLocation');
	}
	else
	{
		if ((Enemy != None) && LineOfSightTo(Enemy))
		{
			NPCChangeState('Targeting','ShootTarget');
		}
		else
		{
			NPCChangeState('FindCoverThenFight');
		}
	}
}
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
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4))) && (VSize((Pawn.Location - pawnSeen.Location)) < float(1000)))
		{
			Enemy=pawnSeen;
			pawnLastPawnSeen=pawnSeen;
			NPCChangeState('Targeting','TurnToEnemy');
		}
	}
	Function NPCCoverPositionPathNode FindCoverPathNode(bool bFindFarthestPointFromThreat)
	{
		local NPCFirePositionPathNode npcfpn;
		npcfpn=Global.vAdjustedPathNodeLocation(2500);
		if ((npcfpn == None) || (! npcfpn.bIsCover))
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
		return 'SearchForTarget';
	}
	Function FName GetCoverState()
	{
		return 'SearchForTarget';
	}
	Function InCoverAction()
	{
		NPCLog("Found cover, going to search for target");
		if ((((Pawn != None) && (Pawn.Weapon != None)) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			NPCChangeState('ReloadWeapon');
			return;
		}
		UnslingWeapon();
		StopMovement();
		Crouch();
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(15)) + (FRand() * 15));
		if ((Enemy != None) && LineOfSightTo(Enemy))
		{
			Focus=Enemy;
		}
		else
		{
			if ((pawnLastEnemy != None) && LineOfSightTo(pawnLastEnemy))
			{
				Enemy=pawnLastEnemy;
				Focus=pawnLastEnemy;
			}
		}
		if (Enemy != None)
		{
			NPCChangeState('Targeting','TurnToEnemy');
		}
	}
	Function bool FinalCoverAction()
	{
		if ((Enemy == None) && Pawn.LineOfSightTo(Enemy))
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
			if (AGP_Pawn(Pawn).DesiredGrenade != None)
			{
				Crouch();
				AGP_Pawn(Pawn).SwapHands();
				Sleep(1.5);
				if (Pawn.Weapon.IsA('ThrowWeapon'))
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
		if ((Pawn.Weapon != None) && (! Pawn.Weapon.IsA('RocketWeapon')))
		{
			for (iRoundsFiredSinceCameOutOfCover=0; iRoundsFiredSinceCameOutOfCover<20; iRoundsFiredSinceCameOutOfCover++)
			{
				if (FRand() > 0.9)
				{
				}
				if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
				{
				}
				FireWeapon();
				Sleep(0.1);
			}
		}
	}
	JL'Begin'
;
}
State SearchForTarget
{
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == None)
		{
			return;
		}
		if (actorColliding.IsA('Mover') && (! Mover(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
		}
		if (actorColliding != None)
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
		if (((pnCurrentLocation != None) && (NPCFirePositionPathNode(pnCurrentLocation) != None)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
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
		if (npcaiccCombatController == None)
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
			if (npcaiccCombatController == None)
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
		if (twpGrenade == None)
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
				NPCChangeState(GetStateName(),'DuckFromGrenade');
				return;
			}
			vPawnLoc=Pawn.Location;
			(vPawnLoc.Z += Pawn.ProneEyeHeight);
			traceHit=Trace(HitLocation,HitNormal,twpGrenade.Location,vPawnLoc,true);
			if (traceHit != twpGrenade)
			{
				NPCLog("Proning to avoid grenade");
				NPCChangeState(GetStateName(),'ProneFromGrenade');
				return;
			}
			Global.agpwSecondary(twpGrenade);
		}
		else
		{
			Global.agpwSecondary(twpGrenade);
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
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
			if ((((Pawn != None) && (Pawn.Weapon != None)) && Pawn.Weapon.IsA('RocketWeapon')) && (nameSecondaryWeapon != None))
			{
				AICCMessageSwitchWeapons();
			}
		}
		NotifyHeardPlayerNoise(fpLoudness,pawnHeard);
		vLastTarget=pawnHeard.Location;
		NPCChangeState('SearchForTarget','TurnToNoise');
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((agpwWeaponHeard.Instigator != None) && (agpwWeaponHeard.Instigator.Controller != None)) && (! agpwWeaponHeard.Instigator.Controller.IsA('HumanController')))
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
			if ((((Pawn != None) && (Pawn.Weapon != None)) && Pawn.Weapon.IsA('RocketWeapon')) && (nameSecondaryWeapon != None))
			{
				AICCMessageSwitchWeapons();
			}
		}
		Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		vLastTarget=agpwWeaponHeard.Location;
		NPCChangeState('SearchForTarget','TurnToNoise');
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (VSize((Pawn.Location - pawnSeen.Location)) < float(1312))
		{
			if ((((Pawn != None) && (Pawn.Weapon != None)) && Pawn.Weapon.IsA('RocketWeapon')) && (nameSecondaryWeapon != None))
			{
				AICCMessageSwitchWeapons();
			}
		}
		if (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 2))
		{
			Enemy=pawnSeen;
			NPCChangeState('Targeting','TurnToEnemy');
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
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("BulletWhip");
		}
		if (IsInCover())
		{
			if (((Level.TimeSeconds - fpTimeEnteredCover) > 4.5) && (((Level.TimeSeconds - fpTimeEnteredCover) / fpMaxIgnoreTime) > FRand()))
			{
				if (npcaiccCombatController != None)
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
			NPCChangeState('FindCoverThenFight');
			return;
		}
		if (IsSuppressed())
		{
			if (pnCurrentPathNode.IsA('NPCFirePositionPathNode') && bFindAlamoFirePosition)
			{
				NPCLog("Current firing position is too scary, move to new one");
				NPCChangeState('MoveToNewFiringPosition');
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
		if ((Pawn.Weapon != None) && (Pawn.Weapon.weaponType == 4))
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
				NPCChangeState('ReturnToPatrol');
			}
			else
			{
				if (iNPCCurrentOrders == 5)
				{
					JL'Begin'
;
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL'Begin'
;
					}
					else
					{
						NPCChangeState('MoveToNewFiringPosition');
					}
				}
			}
			JL'End'
;
		}
	}
	if (npcioiLastTarget != None)
	{
		Sleep((FRand() * 5));
		NPCChangeState('Targeting');
		JL'End'
;
	}
	if (npcaiccCombatController == None)
	{
		SetEndTime();
	}
	if (Enemy != None)
	{
		vLastTarget=Enemy.Location;
		JL'TurnToNoise'
;
	}
	NPCLog("Starting search mode");
	JL'AdjustPosture'
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if ((((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode')) && (! NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)) && (Level.TimeSeconds > fpTimeLastBuzzed))
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
				if (Pawn._InvHands.IsA('Item_Binoculars'))
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	NPCLog("Searching from " $ string(pnCurrentLocation));
	if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode'))
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
	if (IsInState('CrazyIvan'))
	{
		if (Level.TimeSeconds > fpTimeToLeaveFiringPosition)
		{
			if (npcaiccCombatController != None)
			{
				NPCLog("Post Crazy Ivan completed reporting action complete");
				if (GetLastStateName() == 'WalkingPatrol')
				{
					NPCChangeState('ReturnToPatrol');
				}
				else
				{
					NPCChangeState(GetLastStateName());
				}
				if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
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
			JL'End'
;
		}
		else
		{
			JL'LookAround'
;
		}
	}
	if (((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode')) || bFindAlamoFirePosition)
	{
		if (NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot && CanPopAndShoot())
		{
			if (Level.TimeSeconds < fpTimeToLeaveFiringPosition)
			{
				sTargetingStatus="Manning popandshoot with time left " $ string((fpTimeToLeaveFiringPosition - Level.TimeSeconds));
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState('ManningPopAndShootFirePosition');
				JL'End'
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
				NPCChangeState('ReturnToPatrol');
			}
			else
			{
				if (iNPCCurrentOrders == 5)
				{
					NPCChangeState('MoveToNewFiringPosition');
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						if (iTotalRoundsFiredAtAmbushLocation > 0)
						{
							iTotalRoundsFiredAtAmbushLocation=0;
							NPCChangeState('MoveToNewCamperPosition');
						}
						else
						{
							fpTimeToLeaveFiringPosition=(Level.TimeSeconds + float(10));
							JL'LookAround'
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
				NPCChangeState('AssaultLocation');
				JL'End'
;
			}
			if (npcaiccCombatController != None)
			{
				fpTimeToLeaveFiringPosition=(Level.TimeSeconds + (FRand() * 8));
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					NPCChangeState('MoveToNewFiringPosition');
					npcaiccCombatController.ProcessCombatAction(Self);
					NPCLog("Time expired at firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL'End'
;
				}
				else
				{
					NPCLog("Time expired at firing position, combat controller didn't handle, moving to new fire position");
					NPCChangeState('MoveToNewFiringPosition');
					JL'End'
;
				}
			}
		}
		else
		{
			JL'AdjustPosture'
;
		}
	}
	else
	{
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != None)
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
					NPCChangeState('AssaultLocation');
					JL'End'
;
				}
				if (iNPCCurrentOrders == 0)
				{
					NPCChangeState('ReturnToPatrol');
					JL'End'
;
				}
				if (npcaiccCombatController.ReportActionComplete(Self))
				{
					NPCChangeState('MoveToNewFiringPosition');
					npcaiccCombatController.ProcessCombatAction(Self);
					NPCLog("Time expired at non firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL'End'
;
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL'LookAround'
;
					}
					else
					{
						NPCLog("Time expired at non-firing position, combat controller didn't handle, moving to new fire position");
						if (iNPCCurrentOrders == 0)
						{
							NPCChangeState('ReturnToPatrol');
						}
						else
						{
							NPCChangeState('MoveToNewFiringPosition');
						}
						JL'End'
;
					}
				}
			}
			JL'LookAround'
;
		}
		if (iNPCCurrentOrders == 0)
		{
			NPCChangeState('ReturnToPatrol');
		}
		else
		{
			if (iNPCCurrentOrders == 5)
			{
				NPCChangeState('MoveToNewFiringPosition');
			}
			else
			{
				if (iNPCCurrentOrders == 2)
				{
					NPCChangeState('MoveToNewCamperPosition');
				}
				else
				{
					NPCChangeState('MoveToNewFiringPosition');
				}
			}
		}
	}
	JL'End'
;
	NPCLog("Ducking from grenade");
	Crouch();
	Sleep(5);
	JL'Begin'
;
	NPCLog("Going prone from grenade");
	Crouch();
	Sleep(5);
	JL'Begin'
;
}
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
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
			Sleep(PlayCustomAnimation('StartledLg'));
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
	JL'LookAround'
;
}
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
State WalkingPatrol
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
		if (npcioi.bIsShootableTarget)
		{
			npcioiLastTarget=npcioi;
			NPCLog("Item of interest is a targetable item and associated pawn being used as target");
			Enemy=npcioi.pawnTargetToShoot;
			NPCChangeState('Targeting');
		}
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == None)
		{
			return;
		}
		if (actorColliding.IsA('Mover') && (! Mover(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState('WalkingPatrol','NextTravelNode');
		}
		if (actorColliding != None)
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
		if (NPCFirePositionPathNode(pnCurrentPathNode) != None)
		{
			return false;
		}
		return true;
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (npcaiccCombatController != None)
		{
			if (npcaiccCombatController.IsBodyNearLocation(AGP_Pawn(Pawn)))
			{
				if (FRand() > 0.5)
				{
					NPCChangeState('SearchForTarget');
				}
				else
				{
					NPCChangeState('FindCoverThenFight');
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
		if ((pnCurrentPathNode != None) && pnCurrentPathNode.IsA('NPCFirePositionPathNode'))
		{
			NPCChangeState('ManningFirePosition');
		}
		NPCLog("Pathnode: Enemy " $ string(Enemy) $ ", focus: " $ string(Focus));
		if ((Enemy == None) && (AGP_Pawn(Focus) == None))
		{
			iMostRecentContactIndex=GetHighestThreatContactIndex();
			if ((iMostRecentContactIndex != -1) && ((Level.TimeSeconds - arcContactHistory[iMostRecentContactIndex].fpTimeSeen) < 30))
			{
				SetDesiredTarget(arcContactHistory[iMostRecentContactIndex].pawnContact);
				return;
			}
			if ((Pawn.Weapon != None) && (GetConfidenceLevel() > float(-10)))
			{
				NPCLog("No enemy, no focus, no reason for weapon");
			}
		}
	}
}
State StuckByBadPath
{
	Function BeginState()
	{
		GotoState('SearchForTarget');
	}
}
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
			NPCChangeState('Targeting','TurnToEnemy');
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
Begin:
	Sleep(0);
	if (((pnCurrentLocation != None) && (NPCFirePositionPathNode(pnCurrentLocation) != None)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
	{
		NPCChangeState('ManningPopAndShootFirePosition');
	}
	fpTimeEnteredCover=Level.TimeSeconds;
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(15)) + (FRand() * 15));
	if (Enemy == None)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != None)
	{
		NPCLog("ManningFirePosition - Begin entered at pathnode: " $ string(pnCurrentLocation.Tag));
		if (Enemy == None)
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
	if ((Enemy != None) && LineOfSightTo(Enemy))
	{
		NPCChangeState('Targeting','AimAtTarget');
		JL'End'
;
	}
	if ((pnCurrentLocation == None) || (NPCFirePositionPathNode(pnCurrentLocation) == None))
	{
		NPCChangeState('SearchForTarget');
		JL'End'
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
	if ((Enemy != None) || (pawnLastEnemy != None))
	{
		if (Enemy == None)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState('Targeting','TurnToEnemy');
		JL'End'
;
	}
	NPCChangeState('SearchForTarget');
	if (npcaiccCombatController != None)
	{
		if (npcaiccCombatController.ReportActionComplete(Self))
		{
			npcaiccCombatController.ProcessCombatAction(Self);
		}
	}
}
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
			NPCChangeState('Targeting','TurnToEnemy');
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
Begin:
	Sleep(0);
	fpTimeEnteredCover=Level.TimeSeconds;
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if (GetLastStateName() != 'SearchForTarget')
	{
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + float(10)) + (FRand() * 15));
	}
	if (Enemy == None)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != None)
	{
		NPCLog("ManningPopAndShootFirePosition - Begin entered at pathnode: " $ string(pnCurrentLocation.Tag));
		if (Enemy == None)
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
	if (Enemy == None)
	{
		Sleep(((FRand() * 0.5) + 0.25));
		Crouch();
		Sleep((5 + (FRand() * 5)));
	}
	if ((Enemy != None) && LineOfSightTo(Enemy))
	{
		NPCChangeState('Targeting','AimAtTarget');
		JL'End'
;
	}
	NPCLog("ManningFirePosition - Changing posture");
	if ((Enemy != None) || (pawnLastEnemy != None))
	{
		if (Enemy == None)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState('Targeting','TurnToEnemy');
		JL'End'
;
	}
	NPCChangeState('SearchForTarget');
}
State MoveToNewFiringPosition
{
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == None)
		{
			return;
		}
		if (actorColliding.IsA('Mover') && (! Mover(actorColliding).bNotADoor))
		{
			if (Mover(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
		}
		if (actorColliding != None)
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
			NPCChangeState('Targeting','TurnToEnemy');
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
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function ArrivedAtFiringPosition()
	{
		NPCChangeState('ManningFirePosition');
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
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		if (Wall.IsA('Mover'))
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
				NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	NPCLog("MoveToNewFiringPosition - StartMoving entered");
	pnCurrentPathNode=FindNextFiringPosition(1500);
	if ((pnCurrentPathNode == None) && (npcfppnLastFirePosition != None))
	{
		npcfppnLastFirePosition=None;
		pnCurrentPathNode=FindNextFiringPosition(1500);
	}
	else
	{
		if (pnCurrentPathNode == pnCurrentLocation)
		{
			ArrivedAtFiringPosition();
			JL'End'
;
		}
	}
	JL'HavePath'
;
	Sleep(1.5);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if (pnCurrentPathNode != None)
	{
		NPCLog("MoveToNewFiringPosition - Found new firing position: " $ string(pnCurrentPathNode));
		pnCurrentNodeLeadingToPathNode=None;
		if (true)
		{
			if (Pawn == None)
			{
				JL'PawnDeadEnd'
;
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCLog("MoveToNewFiringPosition - Moving to node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != None) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
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
					JL'Begin'
;
				}
				if (pnCurrentNodeLeadingToPathNode.IsA('NPCDoorEntryPathNode'))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						StopMovement();
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
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
					if (pnCurrentNodeLeadingToPathNode.IsA('NPCLadderPathNode'))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
								if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
		if (pnCurrentPathNode != None)
		{
			JL'HavePath'
;
		}
		else
		{
			UpdatePathNodeBonuses(pnCurrentPathNode);
			NPCChangeState('FindCover');
			JL'End'
;
		}
	}
	if (bFindAlamoFirePosition)
	{
		bFindAlamoFirePosition=false;
	}
	UpdatePathNodeBonuses(pnCurrentPathNode);
	if ((Enemy != None) && LineOfSightTo(Enemy))
	{
		Focus=Enemy;
	}
	else
	{
		if ((pawnLastEnemy != None) && LineOfSightTo(pawnLastEnemy))
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
	if (Focus != None)
	{
		Enemy=Pawn(Focus);
		NPCChangeState('Targeting');
	}
}
State MoveToNewCamperPosition extends MoveToNewFiringPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		int32 iPathNode = 0;
		local NPCFirePositionPathNode npcfppnClosest;
		float fpClosestFiringPositionDistance = 0;
		float fpCurrentFiringPositionDistance = 0;
		if (Pawn == None)
		{
			return None;
		}
		fpMaxDistance=500;
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Length; iPathNode++)
		{
			if (! anpcfppnFiringPositions[iPathNode].IsA('NPCCamperFirePositionPathNode'))
			{
			}
			NPCLog("Testing camper firing position: " $ string(anpcfppnFiringPositions[iPathNode].Tag));
			if (pnCurrentLocation == anpcfppnFiringPositions[iPathNode])
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
				NPCLog("Camper node too far away: " $ string(VSize((anpcfppnFiringPositions[iPathNode].Location - Pawn.Location))) $ " max allowed: " $ string(fpMaxDistance));
			}
			else
			{
				if (Abs((Pawn.Location.Z - anpcfppnFiringPositions[iPathNode].Location.Z)) > anpcfppnFiringPositions[iPathNode].fpMaxVerticalDeltaToFind)
				{
					if (FindPathToward(anpcfppnFiringPositions[iPathNode]) == None)
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
						if ((fpCurrentFiringPositionDistance < fpClosestFiringPositionDistance) || (npcfppnClosest == None))
						{
							fpClosestFiringPositionDistance=fpCurrentFiringPositionDistance;
							npcfppnClosest=anpcfppnFiringPositions[iPathNode];
						}
					}
				}
			}
		}
		NPCLog("Closest camper position: " $ string(npcfppnClosest));
		if (npcfppnClosest != None)
		{
			npcfppnLastFirePosition=NPCFirePositionPathNode(pnCurrentLocation);
		}
		return npcfppnClosest;
	}
}
State MoveToNewHarassPosition extends MoveToNewFiringPosition
{
	Function NPCFirePositionPathNode FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
	{
		if (Pawn == None)
		{
			return None;
		}
		return FastHarassFindNextFiringPosition();
	}
}
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
		return 'ManningFirePosition';
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
		if (Pawn == None)
		{
			return None;
		}
		NPCLog("Trying to find alamo node");
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (! N.IsA('NPCAlamoFirePositionPathNode'))
			{
			}
			pnIterator=NPCAlamoFirePositionPathNode(N);
			NPCLog("Found possible alamo node to run to: \"" $ string(pnIterator.Tag) $ "\" vs. NPC tag \"" $ sNPCWaypointTag $ "\"");
			if (string(pnIterator.Tag) ~= sNPCWaypointTag)
			{
				NPCLog("Found possible alamo node, using flag: " $ string(pnIterator.npcbcUsingNode));
				if ((pnIterator.npcbcUsingNode != None) && (pnIterator.npcbcUsingNode != Self))
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
		if (pnPotentialFallback != None)
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if (IsInCover())
	{
		if ((AGP_Pawn(Pawn)._InvGrenades[Pawn.1] > 0) && (FRand() < fpChanceOfThrowingFragOnFallback))
		{
			StopMovement();
			NPCLog("Dropping smoke and running");
			AGP_Pawn(Pawn).DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
			if (AGP_Pawn(Pawn).DesiredGrenade != None)
			{
				Crouch();
				AGP_Pawn(Pawn).SwapHands();
				Sleep(1.5);
				if (Pawn.Weapon.IsA('ThrowWeapon'))
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
			if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
			{
			}
			FireWeapon();
			Sleep(0.1);
		}
	}
	Stand();
	Run();
	WantsToRun();
	JL'StartMoving'
;
}
State LiveGrenade
{
	Event ReceiveWarning(Pawn shooter, float projSpeed, Vector FireDir)
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (((actThreat == None) && (npcaiccCombatController != None)) && (Level.TimeSeconds > fpTimeToEndLastInterrupt))
		{
			AICCMessageScanForEnemy();
			if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
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
		if (npcaiccCombatController == None)
		{
			NPCSay(22,true,false);
		}
		if (npcaiccCombatController == None)
		{
			NPCSay(28,true,false);
		}
		if (npcaiccCombatController == None)
		{
			NPCSay(4,true,false);
		}
		if (twpLastGrenadeHeard != None)
		{
			NPCLog("Grenade distance: " $ string(VSize((twpLastGrenadeHeard.Location - Pawn.Location))));
		}
	}
}
State InCover
{
	Function ThreatEnded()
	{
		if (GetConfidenceLevel() > float((-40 + 5)))
		{
			NPCChangeState('SearchForTarget');
		}
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if (actThreat != None)
	{
		Focus=actThreat;
		Pawn.RotationRate.Yaw=int(fpTurnRate);
		bRotateToDesired=true;
		FinishRotation();
	}
}
State AdvanceOnEnemyLocation
{
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (LineOfSightTo(pawnSeen) && (VSize((Pawn.Location - pawnSeen.Location)) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			StopMovement();
			NPCChangeState('Targeting','TurnToEnemy');
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
		if (pnCurrentPathNode != None)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA('Mover') && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('AdvanceOnEnemyLocation','OpeningDoor');
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
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
			NPCChangeState('Targeting');
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if (! AdjustAround(Pawn(Other)))
		{
			BackupAfterBump(Pawn(Other));
			NPCChangeState('PursueEnemy','ContinueNavigation');
			return true;
		}
		return true;
	}
	Function NPCPathNode FindClosestFirePositionToTarget(Vector vLastTarget)
	{
		local NPCPathNode pnBestFirePosition;
		float fpDistanceFromBestToTarget = 0;
		local Actor traceHit;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector vNodeEyeHeightLocation = FVector(0,0,0);
		int32 iPathNode = 0;
		if (Pawn == None)
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
			if (pnBestFirePosition == None)
			{
				vNodeEyeHeightLocation=anpcfppnFiringPositions[iPathNode].Location;
				vNodeEyeHeightLocation.Z += float(100);
				traceHit=anpcfppnFiringPositions[iPathNode].Trace(HitLocation,HitNormal,vLastTarget,vNodeEyeHeightLocation,true);
				if (bDebugPath && bDebugCombat)
				{
					NPCPathLog("No Previous Advance Fire position, potential new one: " $ string(anpcfppnFiringPositions[iPathNode]) $ " Trace towards target hit: " $ string(traceHit) $ ", distance: " $ string(VSize((anpcfppnFiringPositions[iPathNode].Location - vLastTarget))));
				}
				if ((traceHit != None) && traceHit.IsA('AGP_Pawn'))
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
						if ((traceHit != None) && traceHit.IsA('AGP_Pawn'))
						{
							NPCPathLog("Somewhat closer Advance firing position found, testing it for usefulness");
							pnBestFirePosition=anpcfppnFiringPositions[iPathNode];
							fpDistanceFromBestToTarget=VSize((pnBestFirePosition.Location - vLastTarget));
						}
					}
				}
			}
		}
		if (pnBestFirePosition == None)
		{
			pnBestFirePosition=pnCurrentLocation;
		}
		NPCPathLog("Found Advance firing position location: " $ string(pnBestFirePosition));
		return pnBestFirePosition;
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	NPCLog("****************");
	NPCLog("AdvanceOnEnemyLocation entered");
	NPCLog("Trying to advance on last known position of enemy");
	UnslingWeapon();
	pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
	if (pnCurrentPathNode == pnCurrentLocation)
	{
		if ((Enemy != None) && LineOfSightTo(Enemy))
		{
			NPCChangeState('Targeting');
		}
		else
		{
			NPCChangeState('SearchForTarget','TurnToNoise');
		}
		JL'End'
;
	}
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	RequestSuppressiveFire(vLastTarget);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0.1);
	Pawn.RotationRate.Yaw=int((fpTurnRate + float(2500)));
	FocalPoint=vLastTarget;
	bRotateToDesired=true;
	FinishRotation();
	JL'ContinueNavigation'
;
	Sleep(1.5);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if (pnCurrentPathNode == None)
	{
		NPCChangeState('FindCoverThenFight');
	}
	else
	{
		Run();
		if (true)
		{
			if (((Pawn == None) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState('None');
				JL'End'
;
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCPathLog("Advance path location: " $ string(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != None) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				if ((LineOfSightTo(pnCurrentPathNode) && (pnCurrentPathNode.cControllerUsingNode != None)) && (pnCurrentPathNode.cControllerUsingNode != Self))
				{
					pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
					if (pnCurrentPathNode == None)
					{
						NPCChangeState('FindCoverThenFight');
						JL'End'
;
					}
				}
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(None);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,,(! ShouldRun()));
				if (pnCurrentNodeLeadingToPathNode.IsA('NPCDoorEntryPathNode'))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
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
					if (pnCurrentNodeLeadingToPathNode.IsA('NPCLadderPathNode'))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
								if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
	if (pnCurrentPathNode != None)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	if ((Enemy != None) && LineOfSightTo(Enemy))
	{
		NPCChangeState('Targeting');
	}
	else
	{
		NPCChangeState('SearchForTarget','TurnToNoise');
	}
}
State AssaultLocation
{
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (Pawn.bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function EndState()
	{
		if (pnCurrentPathNode != None)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA('Mover') && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('AssaultLocation','OpeningDoor');
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other == Enemy) || Other.IsA('HumanController'))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState('Targeting','TurnToEnemy');
			return true;
		}
		if (Pawn(Other) == None)
		{
			NPCChangeState('AssaultLocation');
			return true;
		}
		if ((Pawn(Other) != None) && (VSize(Pawn(Other).Velocity) < 2))
		{
			if (NPCBaseSoldierController(Pawn(Other).Controller) != None)
			{
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState('AssaultLocation');
			}
		}
		if (! AdjustAround(Pawn(Other)))
		{
			NPCChangeState('AssaultLocation');
			if (NPCBaseSoldierController(Pawn(Other).Controller) != None)
			{
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState('AssaultLocation');
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
			sTargetingStatus="Assaulting, but see player pawn in sight at range " $ string(VSize((Pawn.Location - pawnSeen.Location)));
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NotifyPlayerPawnInSight() targeting enemy pawn we were pursuing");
			StopMovement();
			pawnLastPawnSeen=pawnSeen;
			Enemy=pawnSeen;
			Focus=pawnSeen;
			if (VSize((Pawn.Location - pawnSeen.Location)) < float(1500))
			{
				NPCChangeState('Targeting','TurnToEnemy');
			}
			else
			{
				NPCChangeState('FindCoverThenFight');
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
		if (pnLastNode == None)
		{
			return PathNode(FindPathToward(pnCurrentPathNode,true));
		}
		for (i=0; i<61; i++)
		{
			if ((RouteCache[i] == pnLastNode) && (RouteCache[(i + 1)] != None))
			{
				return PathNode(RouteCache[(i + 1)]);
			}
			if (RouteCache[i] == None)
			{
				return PathNode(FindPathToward(pnCurrentPathNode,true));
			}
		}
		return PathNode(FindPathToward(pnCurrentPathNode,true));
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	LocateAssaultLocation();
	Sleep(0.25);
	NPCLog("****************");
	NPCLog("Assault Location entered");
	NPCLog("Trying to assault location  " $ string(vAssaultLocation));
	if (pnCurrentPathNode != None)
	{
		pnCurrentPathNode.npcbcUsingNode=None;
	}
	ResetRouteCache();
	pnCurrentNodeLeadingToPathNode=FindCloserAssaultFirePositionToTarget(vAssaultLocation);
	if ((pnCurrentPathNode == pnCurrentNodeLeadingToPathNode) || (pnCurrentNodeLeadingToPathNode == None))
	{
		if (pnCurrentNodeLeadingToPathNode == None)
		{
			Log("Failed to get new closer assault location");
		}
		sTargetingStatus="path to assault location could not be found";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep((2.5 * (FRand() * 5)));
		pnCurrentNodeLeadingToPathNode=FindCloserAssaultFirePositionToTarget(vAssaultLocation,true,true);
		if ((pnCurrentPathNode == pnCurrentNodeLeadingToPathNode) || (pnCurrentNodeLeadingToPathNode == None))
		{
			NPCLog("Really failed to get path for assault, giving up and targeting");
			sTargetingStatus="Really path to assault location could not be found, looking for some cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			iNPCCurrentOrders=3;
			fpTargetingStartTime=0;
			NPCChangeState('MoveToNewFiringPosition');
			SetCustomTimer(((FRand() * 10) + 5),false,'ReturnToAssault');
			JL'End'
;
		}
	}
	Sleep(0.25);
	pnCurrentPathNode=NPCPathNode(pnCurrentNodeLeadingToPathNode);
	if (pnCurrentPathNode != None)
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
			NPCChangeState('ThrowingGrenade');
		}
	}
	Sleep(1.5);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if (pnCurrentPathNode == None)
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
			if (((Pawn == None) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState('None');
				JL'End'
;
			}
			NPCPathLog("Advance path location: " $ string(actorNextPathLocation) $ " converted to pathnode: " $ string(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " $ string(pnCurrentPathNode) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != None) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
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
					NPCChangeState('AssaultLocation');
					JL'End'
;
				}
				sTargetingStatus="AssaultLocation - Done moving to new node";
				SaveTargetingStatusHistory(sTargetingStatus);
				if (pnCurrentNodeLeadingToPathNode.IsA('NPCDoorEntryPathNode'))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA('NPCLadderPathNode'))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
								if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
					if (NPCFirePositionPathNode(pnCurrentPathNode) != None)
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
	if (pnCurrentPathNode != None)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	if (VSize((vAssaultLocation - Pawn.Location)) <= float(550))
	{
		iNPCCurrentOrders=3;
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * float(10)));
		NPCChangeState('SearchForTarget','LookAround');
		JL'End'
;
	}
	if (FRand() < 0.5)
	{
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((Level.TimeSeconds + 2.5) + (FRand() * float(10)));
		NPCChangeState('SearchForTarget','LookAround');
	}
	else
	{
		sTargetingStatus="Assault Location, switching to non-requested providing suppressive fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((pawnLastEnemy != None) && LineOfSightTo(pawnLastEnemy))
		{
			vTargetToSuppressLocation=pawnLastEnemy.Location;
		}
		else
		{
			if ((pawnLastPawnSeen != None) && LineOfSightTo(pawnLastPawnSeen))
			{
				vTargetToSuppressLocation=pawnLastPawnSeen.Location;
			}
			else
			{
				vTargetToSuppressLocation=vAssaultLocation;
			}
		}
		NPCChangeState('ProvidingSuppressiveFire');
	}
}
State PursueEnemy
{
	Function EndState()
	{
		if (pnCurrentPathNode != None)
		{
			pnCurrentPathNode.DebugNavMarker(false);
		}
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		NPCPathLog("Hit wall, normal: " $ string(HitNormal));
		if (Wall.IsA('Mover') && (! Mover(Wall).bNotADoor))
		{
			if (Mover(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn.Location,Mover(Wall));
			GotoState('PursueEnemy','OpeningDoor');
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
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
			NPCChangeState('PursueEnemy');
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other == Enemy) || Other.IsA('HumanController'))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState('Targeting','TurnToEnemy');
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
			NPCLog("NotifyPlayerPawnInSight() targeting enemy pawn we were pursuing");
			StopMovement();
			Enemy=pawnSeen;
			Focus=pawnSeen;
			NPCChangeState('Targeting','TurnToEnemy');
			return;
		}
		NotifyPlayerPawnInSight(pawnSeen);
		Enemy=None;
		EvaluateTarget(pawnSeen,false);
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0.1);
	Pawn.RotationRate.Yaw=int(fpTurnRate);
	FocalPoint=(Pawn.Location + (float(512) *  Vector(Normalize(rotator((vLastTarget - Pawn.Location))))));
	bRotateToDesired=true;
	FinishRotation();
	JL'ContinueNavigation'
;
	Sleep(1.5);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if (pnCurrentPathNode == None)
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
			if (((Pawn == None) || (Pawn.Health < 0)) || (! bStart))
			{
				NPCChangeState('None');
				JL'End'
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
			if ((pnCurrentNodeLeadingToPathNode != None) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
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
				if (pnCurrentNodeLeadingToPathNode.IsA('NPCDoorEntryPathNode'))
				{
					if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						AGP_Pawn(Pawn).GuardWeapon3p(6);
						if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						Pawn.UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode.IsA('NPCLadderPathNode'))
					{
						if (NPCLadderPathNode(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
								if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
				if (((Enemy != None) && LineOfSightTo(Enemy)) && pnCurrentNodeLeadingToPathNode.IsA('NPCFirePositionPathNode'))
				{
					NPCLog("Can see enemy, reporting contact from firing position");
					if ((npcaiccCombatController != None) && npcaiccCombatController.ReportContact(Self,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
					{
						npcaiccCombatController.ProcessCombatAction(Self);
						UpdatePathNodeBonuses(NPCPathNode(pnCurrentNodeLeadingToPathNode));
						JL'End'
;
					}
				}
				JL'LookAround'
;
			}
			else
			{
				if (((pnCurrentPathNode != None) && (pnCurrentNodeLeadingToPathNode == None)) && (! LineOfSightTo(pnCurrentPathNode)))
				{
					fpTimeToEndLastInterrupt=Level.TimeSeconds;
					if (pnCurrentPathNode != None)
					{
						pnCurrentPathNode.DebugNavMarker(false);
					}
					NPCChangeState('MoveToNewFiringPosition');
					JL'End'
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
	if (pnCurrentPathNode != None)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	NPCChangeState('SearchForTarget','LookAround');
}
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
			NPCChangeState('Targeting','TurnToEnemy');
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	ChangeOrders(400);
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	if (! IsInState('FiringBlindly'))
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
	if ((pnCurrentPathNode != None) && pnCurrentPathNode.IsA('NPCFirePositionPathNode'))
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
		NPCLog("Not in firing position, using pawn preference for crouching");
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
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == None))
	{
		JL'CheckTimeLeft'
;
	}
	if (! IsLocationInFront(vTargetToSuppressLocation))
	{
		sTargetingStatus="Suppressivefire - rotating to target";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL'TurnToTarget'
;
	}
	if (IsInState('FiringBlindly'))
	{
		(fpTimeToEndSuppressionFire += 1);
		JL'AimAtTarget'
;
	}
	JL'AimAtTarget'
;
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	NPCLog("Scanning for targets in suppression mode");
	sTargetingStatus="Suppressivefire scanning area";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((pnCurrentLocation != None) && pnCurrentLocation.IsA('NPCFirePositionPathNode'))
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	iRoundsFiredSinceCameOutOfCover=0;
	TurnToAreaTarget();
	FinishRotation();
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == None))
	{
		JL'CheckTimeLeft'
;
	}
	if (! IsLocationInFront(vTargetToSuppressLocation))
	{
		sTargetingStatus="Suppressivefire - almost fired, now turning in aiming at taret";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL'AimAtTarget'
;
	}
	if (! IsInState('FiringBlindly'))
	{
		if (((NPCFirePositionPathNode(pnCurrentLocation) != None) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileProne)) && Pawn.bIsProne)
		{
			Crouch();
			Sleep(0.5);
		}
		if (((NPCFirePositionPathNode(pnCurrentLocation) != None) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileCrouched)) && Pawn.bIsCrouched)
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
	if (IsInState('FiringBlindly'))
	{
		fpAimTime=0.1;
		if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Crouch();
			Sleep(0.75);
			Sleep(PlayCustomAnimation('CrhFwUpBlndFrStart'));
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
					Sleep(PlayCustomAnimation('CrhLtBlndFrStart'));
				}
				else
				{
					Sleep(PlayCustomAnimation('StndLtBlndFrStart'));
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
						Sleep(PlayCustomAnimation('CrhRtBlndFrStart'));
					}
					else
					{
						Sleep(PlayCustomAnimation('StndRtBlndFrStart'));
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Sleep(0);
	if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0))
	{
		NPCLog("Need to reload weapon");
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("WeaponJam");
		}
		AICCMessageReload();
		JL'End'
;
	}
	if ((Level.TimeSeconds > fpTimeToEndSuppressionFire) || (Pawn.Weapon == None))
	{
		sTargetingStatus="Suppressivefire - end of suppressive fire by time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Suppression Time Ended");
		if (iNPCCurrentOrders == 9)
		{
			NPCChangeState('AssaultLocation');
			JL'End'
;
		}
		if (IsInState('FiringBlindly'))
		{
			if (! IsInCover())
			{
				NPCChangeState('FindCoverThenFight');
			}
			else
			{
				NPCChangeState('SearchForTarget');
			}
		}
		else
		{
			NPCChangeState('SearchForTarget');
		}
		if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
		{
			AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != None)
		{
			if (npcaiccCombatController.ReportActionComplete(Self))
			{
				npcaiccCombatController.ProcessCombatAction(Self);
			}
		}
		JL'End'
;
	}
	if (SafeToFire() || IsInState('FiringBlindly'))
	{
		sTargetingStatus="Suppressivefire - safe to fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((Pawn.Weapon != None) && AGP_Weapon(Pawn.Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Pawn.Weapon.GotoState('BusyFixingJam');
			AGP_Weapon(Pawn.Weapon).bIsJammed=false;
			if (Pawn.Weapon.IsInState('BusyFixingJam'))
			{
				Sleep(0.1);
			}
		}
		if (! Pawn.Weapon.IsZoomed())
		{
			SaveTargetingStatusHistory("Forcing weapon into zoomed mode");
			AGP_Weapon(Pawn.Weapon).ServerZoom(true);
		}
		if (Pawn.Weapon.IsInState('BusyZooming'))
		{
			Sleep(0.1);
		}
		sTargetingStatus="Suppressivefire shooting weapon";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None)) && (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((Pawn.Weapon != None) && (Pawn.Weapon.GetCurrentAmmoType() != None))
		{
			NPCLog("Just fired, current ammo count for weapon: " $ string(Pawn.Weapon) $ " is: " $ string(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount));
		}
		if (IsInCover())
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				if (IsInState('FiringBlindly'))
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
				if (IsInState('FiringBlindly'))
				{
					Pawn.bIsFiringBlindlyLeft=false;
					Pawn.bIsFiringBlindlyRight=false;
					if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
					{
						Sleep(PlayCustomAnimation('CrhFwUpBlndFrEnd'));
						Pawn.ChangeAnimation();
					}
					else
					{
						if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)
						{
							if (Pawn.bIsCrouched)
							{
								Sleep(PlayCustomAnimation('CrhLtBlndFrEnd'));
							}
							else
							{
								Sleep(PlayCustomAnimation('StndLtBlndFrEnd'));
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
									Sleep(PlayCustomAnimation('CrhRtBlndFrEnd'));
								}
								else
								{
									Sleep(PlayCustomAnimation('StndRtBlndFrEnd'));
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
				JL'AimAtTarget'
;
			}
		}
		else
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				if (IsInState('FiringBlindly'))
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
				JL'ShootTarget'
;
			}
		}
		if ((Pawn.Weapon != None) && (Pawn.Weapon.weaponType == 4))
		{
			NPCLog("Advanced Marksman weapon, must aim again after shot: " $ string(Pawn.Weapon));
			JL'AimAtTarget'
;
		}
	}
	else
	{
		if (IsInFiringNode())
		{
			sTargetingStatus="Suppressivefire - can't hit target area, switching to searchfortarget";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState('SearchForTarget');
		}
		else
		{
			sTargetingStatus="Suppressivefire - moving to new firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState('MoveToNewFiringPosition');
		}
		JL'End'
;
	}
	Sleep(0.15);
	JL'ShootTarget'
;
	if (IsInState('FiringBlindly'))
	{
		Pawn.bIsFiringBlindlyLeft=false;
		Pawn.bIsFiringBlindlyRight=false;
		if (NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Sleep(PlayCustomAnimation('CrhFwUpBlndFrEnd'));
			Pawn.ChangeAnimation();
		}
		else
		{
			if (NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)
			{
				if (Pawn.bIsCrouched)
				{
					Sleep(PlayCustomAnimation('CrhLtBlndFrEnd'));
				}
				else
				{
					Sleep(PlayCustomAnimation('StndLtBlndFrEnd'));
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
						Sleep(PlayCustomAnimation('CrhRtBlndFrEnd'));
					}
					else
					{
						Sleep(PlayCustomAnimation('StndRtBlndFrEnd'));
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
State RetreatFromBattle extends MoveToAlamoPosition
{
	Function ArrivedAtFiringPosition()
	{
	}
}
State FlashBanged
{
	Function RequestSuppressiveFire(Vector vTargetArea)
	{
	}
	Function SuppressiveFireRequested(NPCBaseSoldierController npcbscRequestingFire, Vector vTargetArea)
	{
	}
	Function FlashBangEffectEnded()
	{
		Log(string(Self) $ "." $ string(GetStateName()) $ ".FlashBangEffectEnded()");
		if (IsInCover())
		{
			GotoState('SearchForTarget');
		}
		else
		{
			GotoState('FindCoverThenFight');
		}
	}
	Function float PrepForFlashing()
	{
		if ((Pawn.Weapon != None) && Pawn.Weapon.IsA('RocketWeapon'))
		{
			Pawn.Weapon.Velocity=(Velocity * 1.15);
			Pawn.Weapon.DropFrom(Pawn.GetBoneCoords('WeaponBone').Origin);
			Pawn.Weapon=None;
			UnslingWeapon();
			return 1;
		}
	}
	Function NPCFlashedAudioYell()
	{
		if (npcaiccCombatController != None)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Warning");
		}
	}
}
State Surrender
{
	Function InitialSurrenderActions()
	{
		NPCLog("NPC Surrendered by dropping weapons");
		if (npcaiccCombatController == None)
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
			PlayCustomAnimation('PrnKillMiles');
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				PlayCustomAnimation('CrhKillMiles');
			}
			else
			{
				PlayCustomAnimation('StdKillMilesB');
			}
		}
		HumanController(User.Controller).ClientMessage("You have taken this soldier into custody");
		bInCustody=true;
		Pawn.HUDText="Enemy Soldier In Custody";
		return true;
	}
}
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
			if (npcaiccCombatController != None)
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
State Collapse
{
	Function PlayPainAnimation()
	{
	}
	Function FName GetNoCoverState()
	{
		return 'Cowering';
	}
	Function FName GetCoverState()
	{
		return 'InCover';
	}
	Function InCoverAction()
	{
		NPCLog("InCoverAction() - default action - stop and crouch");
		StopMovement();
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	PlayPainAnimation();
	pnCoverNode=FindCoverPathNode(false);
	if (pnCoverNode == None)
	{
		NPCLog("Couldn't find farthest, looking for escape path");
		pnCoverNode=FindEscapePathNode();
	}
	if (pnCoverNode == None)
	{
		NPCLog("No cover node found, just dropping to ground and going to cower");
		NPCChangeState(GetNoCoverState());
		JL'End'
;
	}
	Walk();
	Prone();
	if (true)
	{
		if (Pawn == None)
		{
			JL'PawnDeadEnd'
;
		}
		pnCurrentNodeOnPathToCover=PathNode(FindPathToward(pnCoverNode,false));
		if ((pnCurrentNodeOnPathToCover != None) && (pnCurrentNodeOnPathToCover != pnCoverNode))
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
State TauntEnemy
{
	Function float PlayTauntAnimation()
	{
		if ((! Pawn.bIsProne) && Pawn.bIsCrouched)
		{
			if (FRand() > 0.5)
			{
				return PlayCustomAnimation('SgnNegLg');
			}
			else
			{
				return PlayCustomAnimation('Alarm_E');
			}
		}
		else
		{
			return 0;
		}
	}
	Function PlayTauntAudio()
	{
		if (npcaiccCombatController != None)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Taunt");
		}
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	PlayTauntAudio();
	Sleep(PlayTauntAnimation());
	if ((AGP_Pawn(Pawn) != None) && (AGP_Pawn(Pawn).MyDebug_InterruptIcon != None))
	{
		AGP_Pawn(Pawn).MyDebug_InterruptIcon.UpdateAction("ActionComplete");
	}
	if (npcaiccCombatController != None)
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
State RushEnemy
{
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	NPCLog("RushEnemy Entered for " $ string(Enemy));
	Stand();
	Run();
	if (true)
	{
		if (Pawn == None)
		{
			JL'PawnDeadEnd'
;
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(Enemy));
		if (((Enemy != None) && LineOfSightTo(Enemy)) && ((VSize((Pawn.Location - Enemy.Location)) < (fpNPCWeaponEffectiveRange / 4)) || (pnCurrentNodeOnPathToCover == None)))
		{
			NPCLog("CQB Range to target, engaging");
			UpdatePathNodeBonuses(NPCPathNode(pnCurrentNodeOnPathToCover));
			if (npcaiccCombatController != None)
			{
				if (npcaiccCombatController.ReportContact(Self,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
				{
					npcaiccCombatController.ProcessCombatAction(Self);
				}
			}
			NPCChangeState('Targeting');
			JL'End'
;
		}
		if (pnCurrentNodeOnPathToCover == None)
		{
			NPCLog("Unable to find path towards target");
			NPCChangeState('FindCoverThenFight');
			JL'End'
;
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover.IsA('NPCDoorEntryPathNode'))
		{
			if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)).bClosed)
			{
				StopMovement();
				AGP_Pawn(Pawn).GuardWeapon3p(6);
				if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
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
			if (pnCurrentNodeOnPathToCover.IsA('NPCLadderPathNode'))
			{
				if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
						if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
			if ((AGP_Pawn(aShooter) != None) && AGP_Pawn(aShooter).IsHumanControlled())
			{
				Enemy=Pawn(aShooter);
				NPCChangeState('FindCoverThenFight');
			}
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (VSize((vSoundLocation - Pawn.Location)) < float(500))
		{
			Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
		if (VSize((pawnHeard.Location - Pawn.Location)) < float(500))
		{
			Global.agpobj(fpLoudness,pawnHeard);
		}
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((Other != None) && (! Other.IsA('Pawn')))
		{
			return true;
		}
		if ((Pawn(Other).Controller != None) && Pawn(Other).Controller.IsA('NPCBaseSoldierController'))
		{
			if (((! Pawn(Other).Controller.IsInState('Targeting')) && (! Pawn(Other).Controller.IsInState('HeadToTravelLocation'))) && (! Pawn(Other).Controller.IsInState('ExitVehicleWaitForMoveOrder')))
			{
				NPCBaseSoldierController(Pawn(Other).Controller).npcpnTravelLocation=npcpnTravelLocation;
				NPCBaseSoldierController(Pawn(Other).Controller).fpHeadToLocationStartDelay=(0.75 + FRand());
				NPCBaseSoldierController(Pawn(Other).Controller).NPCChangeState('HeadToTravelLocation');
			}
			NPCBaseController(Pawn(Other).Controller).GotoState('MoveBackAfterBump');
		}
		else
		{
			if ((Pawn(Other).Controller != None) && Pawn(Other).Controller.IsA('HumanController'))
			{
				Enemy=Pawn(Other);
				NPCChangeState('Targeting','TurnToEnemy');
			}
		}
		return true;
	}
	Event WeaponCollision(Actor actorColliding)
	{
		if (actorColliding == None)
		{
			return;
		}
		if (actorColliding.IsA('Mover') && (! Mover(actorColliding).bNotADoor))
		{
			if (Mover(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn.Location,Mover(actorColliding));
			NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
		}
		if (actorColliding != None)
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
			NPCChangeState('Targeting','TurnToEnemy');
		}
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		if (Wall.IsA('Mover'))
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
				NPCChangeState(GetStateName(),'PauseAfterBumpOnWayToPath');
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if (npcpnTravelLocation == None)
	{
		NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - Unable to find path towards target");
		if (GetLastStateName() == 'WalkingPatrol')
		{
			NPCChangeState('ReturnToPatrol');
		}
		else
		{
			NPCChangeState('FindCoverThenFight');
		}
		JL'End'
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
		NPCChangeState('SearchForTargets');
		JL'End'
;
	}
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - Sleeping for " $ string(fpHeadToLocationStartDelay));
	Sleep(fpHeadToLocationStartDelay);
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation entered for " $ string(vTravelLocation));
	Stand();
	Run();
	JL'GotoTravelLocation'
;
	Sleep(1.5);
	if (true)
	{
		if (Pawn == None)
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - No pawn, aborting");
			JL'PawnDeadEnd'
;
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(npcpnTravelLocation,true));
		NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation - node on way to travel location: " $ string(npcpnTravelLocation) $ " via " $ string(pnCurrentNodeOnPathToCover));
		if (bDebugPath)
		{
			DebugDumpRoute();
		}
		if (pnCurrentNodeOnPathToCover == None)
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation unable to find path towards target for travel location");
			if (GetLastStateName() == 'WalkingPatrol')
			{
				NPCChangeState('ReturnToPatrol');
			}
			else
			{
				NPCChangeState('FindCoverThenFight');
			}
			JL'End'
;
		}
		if ((((pnCurrentNodeOnPathToCover == npcpnTravelLocation) && npcpnTravelLocation.IsA('NPCCoverPositionPathNode')) && (npcpnTravelLocation.cControllerUsingNode != None)) && (npcpnTravelLocation.cControllerUsingNode != Self))
		{
			NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation last node filled");
			NPCChangeState('FindCoverThenFight');
			JL'End'
;
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover.IsA('NPCDoorEntryPathNode'))
		{
			if ((FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)) != None) && FindDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)).bClosed)
			{
				AGP_Pawn(Pawn).GuardWeapon3p(6);
				StopMovement();
				if (OpenDoor(NPCDoorEntryPathNode(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
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
			if (pnCurrentNodeOnPathToCover.IsA('NPCLadderPathNode'))
			{
				if (NPCLadderPathNode(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume')))
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
						if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA('LadderVolume'))
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
			if (GetLastStateName() != 'ExitVehicleWaitForMoveOrder')
			{
				vLastTarget=vTravelLocation;
				NPCChangeState('SearchForTarget','TurnToNoise');
			}
			else
			{
				if (FRand() > 0.5)
				{
					NPCChangeState('FindCoverThenFight');
				}
				else
				{
					NPCChangeState('MoveToNewFiringPosition');
				}
			}
			JL'End'
;
		}
		else
		{
			if (ShouldFindCoverNow())
			{
				NPCChangeState('FindCoverThenFight');
				JL'End'
;
			}
		}
	}
	NPCPathLog(string(Self) $ "." $ string(Tag) $ ".HeadToTravelLocation finished trying to move - which we should never get here");
}
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
			if (Pawn.Weapon != None)
			{
				ShoulderWeapon();
			}
		}
	}
	Function PrepPostIdleAnimationPlay()
	{
	}
}
State PostExitVehicleActions
{
	Function EndState()
	{
	}
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	StopMovement();
	Stand();
	Sleep(1);
	if (IsA('NPCNCOController'))
	{
		if (npcaiccCombatController != None)
		{
			npcaiccCombatController.PlayEventAudio(Self,"Attacking");
		}
		npcpnTravelLocation=FindHeadToObjective();
		SignalSoldiersShouldMoveOut(0,0);
	}
	Run();
	HeadToObjective(float((NPCBasePreCrewedVehicleController(vVehicleCarryingNPC.Controller).anpcbscVehicleSoldiers.Length + 4)));
}
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
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function NotifyEnemyGrenadeClose(ThrowWeaponPickup twpGrenade)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
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
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	if (vVehicleCarryingNPC.Health <= 0)
	{
		Pawn.KilledBy(None);
		JL'None'
;
	}
	GotoState('ExitVehicleWaitForMoveOrder');
}
State ExitVehicleWaitForMoveOrder
{
Begin:
	Sleep(0);
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
;
	}
	Run();
	MoveTo((Pawn.Location + (((FRand() * float(200)) + float(650)) *  Vector((Normalize(Rotation) * fpExitingVehicleDepartureAngle)))),None,false);
	StopMovement();
	if (iNPCCurrentOrders == 9)
	{
		SetCustomTimer(((FRand() * 5) + 5),false,'ReturnToAssault');
		LocateAssaultLocation();
		FocalPoint=vAssaultLocation;
		bRotateToDesired=true;
		FinishRotation();
	}
	Crouch();
	if (Pawn == None)
	{
		JL'PawnDeadEnd'
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
	JL'LookAround'
;
}
State SwapWeapons
{
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
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
	if ((Pawn.Weapon == agpwPrimary) && (agpwSecondary == None))
	{
		JL'End'
;
	}
	if ((Pawn.Weapon == agpwSecondary) && (agpwPrimary == None))
	{
		JL'End'
;
	}
	if (Pawn.Weapon == agpwPrimary)
	{
		AGP_Pawn(Pawn).SwapHands();
		sTargetingStatus="Swap hands done, pausing";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(agpwPrimary.GetAnimDuration('Drop'));
		if (agpwSecondary != None)
		{
			Sleep(agpwSecondary.GetAnimDuration('Select'));
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
			if (agpwSecondary != None)
			{
				Sleep(agpwSecondary.GetAnimDuration('Drop'));
			}
			Sleep(agpwPrimary.GetAnimDuration('Select'));
			Sleep(0.5);
		}
	}
	sTargetingStatus="Swap hands complete";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (GetLastStateName() == 'Targeting')
	{
		fpTimeEnteredCover=Level.TimeSeconds;
		fpTargetingStartTime=Level.TimeSeconds;
		iRoundsFiredSinceCameOutOfCover=0;
		NPCChangeState('Targeting','ShootTarget');
	}
	else
	{
		NPCChangeState(GetLastStateName());
	}
}
*/
