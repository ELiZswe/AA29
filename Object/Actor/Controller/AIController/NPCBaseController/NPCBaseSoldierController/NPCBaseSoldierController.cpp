// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/DebugNPCTargetArea/DebugNPCTargetArea.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCAlamoFirePositionPathNode/NPCAlamoFirePositionPathNode.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCDuckAndCoverPathNode/NPCDuckAndCoverPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"
#include "AA29/Object/Actor/Keypoint/NPCItemOfInterest/NPCItemOfInterest.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/NPCAssaultLocation/NPCAssaultLocation.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/DebugIcon/DebugIcon_MentalState/DebugIcon_MentalState.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCCamperFirePositionPathNode/NPCCamperFirePositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCCoverPositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCDoorEntryPathNode/NPCDoorEntryPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCLadderPathNode/NPCLadderPathNode.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCRestStopPathNode/NPCRestStopPathNode.h"

ANPCBaseSoldierController::ANPCBaseSoldierController()
{
	anpcNPCTracking.SetNum(10);
	asTargetingStatus.SetNum(10);
	fpGrenadePitch = 16384;
}

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
	if (GetPawn() == nullptr)
	{
		JL"End";
	}
	NPCLog("Teammate killed, looking in direction of body for killer");
	Crouch();
	GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(4000)));
	FocalPoint=vDeadTeammateLocation;
	bRotateToDesired=true;
	FinishRotation();
	NPCSayManDown();
	UnslingWeapon();
	Sleep(((0.75 + FMath::FRand()) + (5 * (1 - (fNPCExperience / 100)))));
	NPCLog("Finished staring at body");
	IncreaseNervousness(11);
	NPCSayAlertOnAttack();
	if (Enemy == nullptr)
	{
		NPCLog("Returning to SearchForTarget");
		ChangeState("SearchForTarget");
	}
	else
	{
		Focus=Enemy;
		bRotateToDesired=true;
		FinishRotation();
		ChangeState("Targeting");
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
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		if ((Focus != nullptr) && Focus->IsA(AWeapon::StaticClass()))
		{
			NPCLog("AICC told about weapon sound " + FString::FromInt(Focus));
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportHeardGunfire(this,Focus->GetActorLocation()))
				{
					npcaiccCombatController.ProcessCombatAction(this);
				}
			}
			return;
		}
		if ((npcaiccCombatController != nullptr) && (Focus != nullptr))
		{
			if (npcaiccCombatController.ReportHeardNoise(this,Focus->GetActorLocation()))
			{
				npcaiccCombatController.ProcessCombatAction(this);
				NPCLog("AICC told about sound " + FString::FromInt(Focus.Tag));
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
		if (GetAngleToLocation(Enemy->GetActorLocation()) < 0.9)
		{
			return true;
		}
		return false;
	}
	Function EndState()
	{
		StopCustomTimer("LostSightOfEnemyTimer");
		Cast<AAGP_Pawn>(GetPawn())->ResetLean();
	}
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
		}
		else
		{
			GetPawn()->UpperBodyAnimComplete();
		}
	}
	Event bool NotifyBump(AActor* Other)
	{
		return true;
	}
	Function float GetMaxVisionCone()
	{
		return 12000;
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
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
		Focus=nullptr;
		Global.fpTerrainAvoidanceAltitudeBump();
		if (fpTimeSinceUntilTargetLost > 0)
		{
			return;
		}
		NPCLog("NotifyEnemyNotVisible() entered for pawn " + FString::FromInt(Enemy));
		if ((Enemy != nullptr) && (Enemy.Health <= 0))
		{
			fpTimeSinceUntilTargetLost=GetWorld()->GetTimeSeconds();
		}
		else
		{
			fpTimeSinceUntilTargetLost=((GetWorld()->GetTimeSeconds() + 1.5) + (FMath::FRand() * 5));
		}
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
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
		npcioiLastTarget=nullptr;
		NotifyBuzzedByBullet(aShooter);
		if (iNPCTacticalOrders == 200)
		{
			NPCLog("Soldier buzzed in hold fire mode, changing to controlled fire");
			ChangeOrders(300);
		}
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("BulletWhip");
		}
		if (! IsInCover())
		{
			if ((! Pawn.bIsProne) && (! Pawn.bIsCrouched))
			{
				Crouch();
			}
		}
		if (((GetWorld()->GetTimeSeconds() - fpTargetingStartTime) > 2) && (((GetWorld()->GetTimeSeconds() - fpTargetingStartTime) / fpMaxIgnoreTime) > FMath::FRand()))
		{
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportUnderFire(this,aShooter))
				{
					npcaiccCombatController.ProcessCombatAction(this);
					return;
				}
			}
		}
		if (IsSuppressed())
		{
			if (pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass()))
			{
				NPCLog("Current firing position is too scary, move to new one");
				Stand();
				NPCChangeState("MoveToNewFiringPosition");
				return;
			}
		}
		if (GetPawn()->bIsProne || Pawn.bIsCrouched)
		{
			if (! IsInCover())
			{
				if (iRoundsFiredSinceCameOutOfCover > 0)
				{
					if (FMath::FRand() > 0.6)
					{
						ChangeState("FindCoverThenFight");
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
			if ((Cast<AVehicle>(pawnLastEnemy) != nullptr) && Vehicle(pawnLastEnemy).bIsHelicopter)
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
				if ((Cast<AVehicle>(Enemy) != nullptr) && Vehicle(Enemy).bIsHelicopter)
				{
					NPCChangeState(GetLastStateName());
					return;
				}
				if (iNPCCurrentOrders == 9)
				{
					NPCChangeState("AssaultLocation");
					return;
				}
				if (npcaiccCombatController.ReportLostContact(this,Enemy))
				{
					NPCLog(string(this) + "." + FString::FromInt(GetStateName()) + ".LostSightOfEnemyTimer() Lost contact, command set to " + sNextAICCAction);
					sTargetingStatus="Lost contact, performing AICC action: '" + sNextAICCAction + "'";
					SaveTargetingStatusHistory(sTargetingStatus);
					npcaiccCombatController.ProcessCombatAction(this);
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
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
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
			fpTimeSinceLastEnemySighting=GetWorld()->GetTimeSeconds();
			if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
			{
				Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("SeePlayer");
			}
			if ((npcaiccCombatController != nullptr) && (pawnSeen != nullptr))
			{
				NotifyPlayerPawnInSight(pawnSeen);
				npcaiccCombatController.ReportContact(this,npcaiccCombatController.0,pawnSeen,int(EvaluateEnemyThreat(pawnSeen)));
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
		if ((VSize((pawnHeard->GetActorLocation() - vLastTarget)) < float(250)) && (pawnHeard != Enemy))
		{
			NPCLog("Overriding targeting based on newly heard sound that's really close:" + FString::FromInt(pawnHeard));
			vLastTarget=pawnHeard->GetActorLocation();
			NPCChangeState("SearchForTarget","TurnToNoise");
		}
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("HeardPlayer");
		}
		Global.agpobj(fpLoudness,pawnHeard);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		int32 iDifference = 0;
		if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (! agpwWeaponHeard.Instigator.Controller->IsA(AHumanController::StaticClass())))
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
		iDifference=int(FMath::Abs(float((rotator((GetPawn()->GetActorLocation() - agpwWeaponHeard->GetActorLocation())).Yaw - Pawn.Rotation.Yaw))));
		NPCLog("Heard weapon difference from: " + FString::FromInt(iDifference));
		if ((VSize((GetPawn()->GetActorLocation() - vSoundLocation)) < float(250)) && (float(iDifference) > fpNodeVisionConeAngle))
		{
			NPCLog("Heard close weapon noise out of vision cone");
			vLastTarget=agpwWeaponHeard->GetActorLocation();
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
		AimDir=(Enemy->GetActorLocation() - pnCurrentLocation->GetActorLocation());
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
	fpTargetingStartTime=((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 3));
	if (GetPawn() == nullptr)
	{
		JL"HandlePawnDeath";
	}
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	UnslingWeapon();
	Sleep(0.1);
	StopMovement();
	fpTargetingStartTime=((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 3));
	if (GetPawn() == nullptr)
	{
		JL"HandlePawnDeath"
;
	}
	Sleep(0.1);
	sTargetingStatus="Adjusting posture";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((Enemy == nullptr) || ((Enemy != nullptr) && (! LineOfSightTo(Enemy))))
	{
		if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			NPCLog("in fire position, adjusting posture for firing");
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Num() > 0)
			{
				npcdacpnActiveDuckAndCoverNode=NPCFirePositionPathNode(pnCurrentLocation).anpcdacpnDuckAndCoverNode[Rand(Cast<ANPCFirePositionPathNode>(pnCurrentLocation).anpcdacpnDuckAndCoverNode.Num())];
				pnDNCTempPathNode=nullptr;
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
				pnDNCTempPathNode=nullptr;
			}
			else
			{
				npcdacpnActiveDuckAndCoverNode=nullptr;
			}
		}
	}
	if (((Enemy == nullptr) || ((Enemy != nullptr) && (! LineOfSightTo(Enemy)))) || IsInCover())
	{
		if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bShootWhileProne)
			{
				if (! Pawn.bIsProne)
				{
					Prone();
					Sleep(0.5);
				}
			}
			else
			{
				if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bShootWhileCrouched)
				{
					if (! Pawn.bIsCrouched)
					{
						Crouch();
						Sleep(0.25);
					}
				}
				else
				{
					if (GetPawn()->bIsCrouched)
					{
						Stand();
						Sleep(0.25);
					}
					else
					{
						if (GetPawn()->bIsProne)
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
			if ((FMath::FRand() * 100) < fNPCLikesToCrouch)
			{
				Crouch();
				Sleep(0.25);
			}
		}
	}
	fpTargetingStartTime=((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 3));
	if (GetPawn() == nullptr)
	{
		JL"HandlePawnDeath";
	}
	sTargetingStatus="Turning to target";
	SaveTargetingStatusHistory(sTargetingStatus);
	StopMovement();
	if (Enemy != nullptr)
	{
		iDefaultYawTurnRate=Pawn.RotationRate.Yaw;
		(GetPawn()->RotationRate.Yaw += 10000);
		FocalPoint=Enemy->GetActorLocation();
		Focus=nullptr;
		bRotateToDesired=true;
		FinishRotation();
		GetPawn()->RotationRate.Yaw=iDefaultYawTurnRate;
		Focus=Enemy;
		bRotateToDesired=true;
		FinishRotation();
		Sleep(0.1);
	}
	if (GetPawn() == nullptr)
	{
		JL"HandlePawnDeath";
	}
	if (GetPawn()->Weapon == nullptr)
	{
		NPCChangeState("FindCover");
	}
	if ((Enemy != nullptr) && (! IsLocationInFront(Enemy->GetActorLocation())))
	{
		Sleep(0.1);
		JL"TurnToEnemy";
	}
	sTargetingStatus="Starting aim process";
	SaveTargetingStatusHistory(sTargetingStatus);
	StopMovement();
	if (! SafeToFire())
	{
		sTargetingStatus="Not safe to fire, pausing";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep((FMath::FRand() * 0.75));
		if (! SafeToFire())
		{
			sTargetingStatus="Stil not safe to fire, moving to new firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Not safe to fire, going to switch positions");
			if (iNPCCurrentOrders == 9)
			{
				NPCChangeState("AssaultLocation");
				JL"End";
			}
			NPCChangeState("MoveToNewFiringPosition");
			JL"End";
		}
	}
	if (Cast<AAGP_Weapon>(GetPawn()->Weapon) != nullptr)
	{
		Cast<AAGP_Weapon>(GetPawn()->Weapon).ForceTempRaiseWeapon();
	}
	if (! Pawn.Weapon.IsZoomed())
	{
		Cast<AAGP_Weapon>(GetPawn()->Weapon).ServerZoom(true);
	}
	if (GetPawn()->Weapon.IsInState("BusyZooming"))
	{
		Sleep(0.1);
	}
	Walk();
	Cast<AAGP_Pawn>(GetPawn())->ChangeAnimation();
	if (Enemy != nullptr)
	{
		vLastTarget=Enemy->GetActorLocation();
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
		JL"End";
	}
	if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr)
	{
		if (ShouldLean())
		{
			sTargetingStatus="Leaning at firing position";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bShouldLeanLeftToShoot)
			{
				Cast<AAGP_Pawn>(GetPawn())->LeanLeft();
			}
			else
			{
				if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bShouldLeanRightToShoot)
				{
					Cast<AAGP_Pawn>(GetPawn())->LeanLeft();
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
		fpAimTime=((FMath::FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			fpMaxAimTime=0.85;
			fpAimTime=((FMath::FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
		}
		else
		{
			if ((iNPCCurrentOrders == 3) || (iNPCCurrentOrders == 9))
			{
				fpMaxAimTime=1.25;
				fpAimTime=((FMath::FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
			}
			else
			{
				fpMaxAimTime=1.75;
				fpAimTime=((FMath::FRand() + fpMaxAimTime) - ((fNPCExperience / 100) * (fpMaxAimTime - 0.05)));
			}
		}
	}
	if ((((VSize((GetPawn()->GetActorLocation() - vLastTarget)) < float(800)) && (iNPCCurrentOrders != 9)) && (GetPawn()->Weapon != nullptr)) && (! Pawn.Weapon->IsA(ARocketWeapon::StaticClass())))
	{
		if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
		{
			sTargetingStatus="Activating shoot from hip";
			SaveTargetingStatusHistory(sTargetingStatus);
			GetPawn()->bIsHipShooting=true;
			GetPawn()->ChangeAnimation();
			sTargetingStatus="Finished activating shoot from hip";
			SaveTargetingStatusHistory(sTargetingStatus);
		}
		fpAimTime=((FMath::FRand() * 0.15) + 0.1);
	}
	else
	{
		(fpAimTime += ((FMath::FRand() * 0.5) * (VSize((GetPawn()->GetActorLocation() - vLastTarget)) / float(5000))));
		GetPawn()->bIsHipShooting=false;
		sTargetingStatus="Using non shoot from hip aiming";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
		{
			GetPawn()->ChangeAnimation();
		}
		if ((Enemy != nullptr) && Enemy->IsA(AVehicle::StaticClass()))
		{
			if ((GetPawn()->Weapon != nullptr) && (! Pawn.Weapon->IsA(ARocketWeapon::StaticClass())))
			{
				fpAimTime=((FMath::FRand() * 1) + 0.5);
			}
			else
			{
				if (FMath::FRand() > 0.8)
				{
					fpAimTime=0.5;
				}
			}
		}
	}
	if (GetPawn()->Weapon == nullptr)
	{
		NPCChangeState("FindCover");
		JL"End";
	}
	sTargetingStatus="Aiming sleep: " + FString::FromInt(fpAimTime);
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(fpAimTime);
	iRoundsFiredSinceCameOutOfCover=0;
	if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(AThrowWeapon::StaticClass()))
	{
		sTargetingStatus="ShootTarget, with grenade in hand, swapping";
		SaveTargetingStatusHistory(sTargetingStatus);
		Cast<AAGP_Pawn>(GetPawn())->SwapHands();
		Sleep(0.75);
		JL"ShootTarget";
	}
	sTargetingStatus="ShootTarget, testing pawn and then enemy";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (GetPawn() == nullptr)
	{
		JL"HandlePawnDeath";
	}
	if (GetPawn()->Weapon == nullptr)
	{
		NPCChangeState("FindCover");
	}
	if (Cast<AAGP_Weapon>(GetPawn()->Weapon).IsInState("BusyTempLowering"))
	{
		sTargetingStatus="ShootTarget, Waiting for weapon up: " + FString::FromInt(GetPawn()->Weapon.GetStateName());
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL"ShootTarget";
	}
	if (NeedToTurn())
	{
		if (Enemy == nullptr)
		{
			NPCChangeState("SearchForTarget");
			JL"End";
		}
		sTargetingStatus="Need to turn to target, angle " + FString::FromInt(GetAngleToLocation(Enemy->GetActorLocation()));
		SaveTargetingStatusHistory(sTargetingStatus);
		Focus=Enemy;
		FocalPoint=Enemy->GetActorLocation();
		bRotateToDesired=true;
		FinishRotation();
		Sleep(0.25);
		Focus=Enemy;
		JL"TurnToEnemy";
	}
	if (Enemy != nullptr)
	{
		if (Focus != Enemy)
		{
			Focus=Enemy;
			Sleep(0.25);
		}
	}
	if (((Enemy != nullptr) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) <= float(1650))) && (! Enemy->IsA(AVehicle::StaticClass())))
	{
		sTargetingStatus="Close range enemy, testing to see if NPC has Rocket";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) && (agpwSecondary != nullptr))
		{
			Sleep(0.1);
			sTargetingStatus="RPG in hand, too close, switching";
			SaveTargetingStatusHistory(sTargetingStatus);
			AICCMessageSwitchWeapons(true);
			JL"End";
		}
	}
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass())) && (! pnCurrentLocation->IsA(ANPCCamperFirePositionPathNode::StaticClass())))
	{
		sTargetingStatus="At non-camper firing position, testing leave time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("At non-camper fire position - been here for " + FString::FromInt((GetWorld()->GetTimeSeconds() - fpTargetingStartTime)) + " seconds");
		if (((fpTargetingStartTime != 0) && (GetWorld()->GetTimeSeconds() >= fpTargetingStartTime)) && ((GetWorld()->GetTimeSeconds() - fpTimeEnteredCover) > 5))
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bPopAndShoot && (FMath::FRand() <= 0.75))
			{
				NPCChangeState("ManningPopAndShootFirePosition");
				JL"End";
			}
			else
			{
				if (iNPCCurrentOrders == 9)
				{
					sTargetingStatus="Time to resume assault";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCLog("Signaling we should move to closer assault firing position");
					NPCChangeState("AssaultLocation");
					JL"RealEnd";
				}
				sTargetingStatus="Time to leave";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCLog("Signaling we should move to new firing position");
				NPCChangeState("MoveToNewFiringPosition");
				JL"End";
			}
		}
	}
	if (IsConcerned() && (! IsInCover()))
	{
		sTargetingStatus="Nervous in open";
		SaveTargetingStatusHistory(sTargetingStatus);
		actThreat=Enemy;
		if ((pnCurrentLocation != nullptr) && (! pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass())))
		{
			sTargetingStatus="Nervous in open, finding cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NPC is nervous and not in fighting position, trying to find cover");
			NPCChangeState("FindCoverThenFight");
			JL"End";
		}
	}
	if ((Enemy != nullptr) && IsVisionBlockedBySmokeGrenade(Enemy->GetActorLocation()))
	{
		sTargetingStatus="Vision Blocked by smoke";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("LostEnemy");
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportLostContact(this,Enemy))
			{
				sTargetingStatus="Smoke blocked, AICC ordering change";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(this);
				JL"End";
			}
		}
		sTargetingStatus="Smoke blocking our view, going to SearchForTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Smoke blocking target view - going to search for target");
		NPCChangeState("SearchForTarget");
		JL"End";
	}
	if (ShouldThrowGrenade())
	{
		sTargetingStatus="Want to throw grenade";
		SaveTargetingStatusHistory(sTargetingStatus);
		vGrenadeTarget=Enemy->GetActorLocation();
		NPCChangeState("ThrowingGrenade");
		JL"End";
	}
	else
	{
		if (! SafeToFire())
		{
			sTargetingStatus="Not safe to fire!";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.1);
			JL"AimAtTarget";
		}
		if ((Enemy != nullptr) && (GetAngleToLocation(Enemy->GetActorLocation()) < 0.9))
		{
			sTargetingStatus="Valid enemy, he's now to our back";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Angle to enemy: " + FString::FromInt(GetAngleToLocation(Enemy->GetActorLocation())));
			JL"TurnToEnemy";
		}
		if ((((Enemy == nullptr) && (GetPawn() != nullptr)) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
		{
			NPCChangeState("SearchForTarget");
			JL"End";
		}
		if (Cast<AAGP_Weapon>(GetPawn()->Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			GetPawn()->Weapon.GotoState("BusyFixingJam");
			Cast<AAGP_Weapon>(GetPawn()->Weapon).bIsJammed=false;
			if (GetPawn()->Weapon.IsInState("BusyFixingJam"))
			{
				Sleep(0.1);
			}
		}
		if (Cast<AAGP_Weapon>(GetPawn()->Weapon).IsInState("BusyRaisingWeapon"))
		{
			Sleep(0.25);
		}
		if ((Enemy != nullptr) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) > Level.DistanceFogStart))
		{
			if ((FMath::FRand() > 0.5) && ((GetPawn()->Weapon != nullptr) && (! Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))))
			{
				vTargetToSuppressLocation=Enemy->GetActorLocation();
				NPCChangeState("ProvidingSuppressiveFire");
			}
			else
			{
				fpTimeSinceUntilTargetLost=GetWorld()->GetTimeSeconds();
				NPCChangeState("SearchForTarget");
				Log("Lost sight by fog distance, switching to search for target");
			}
			JL"End";
		}
		sTargetingStatus="Firing";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((Enemy != nullptr) && (! LineOfSightTo(Enemy)))
		{
			sTargetingStatus="Lost sight after shot";
			SaveTargetingStatusHistory(sTargetingStatus);
			NotifyEnemyNotVisible();
			JL"WatchForTarget";
		}
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr))
		{
			NPCLog("Current ammo count for weapon: " + FString::FromInt(GetPawn()->Weapon) + " is: " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount));
		}
		if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			sTargetingStatus="need to reload";
			SaveTargetingStatusHistory(sTargetingStatus);
			if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
			{
				Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("WeaponJam");
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
			JL"End";
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
		if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FMath::FRand() * float(iMaxRoundsToFireBeforeDucking))))
		{
			sTargetingStatus="We've fired enough to duck";
			SaveTargetingStatusHistory(sTargetingStatus);
			iRoundsFiredSinceCameOutOfCover=0;
			Cast<AAGP_Pawn>(GetPawn())->ResetLean();
			Cast<AAGP_Pawn>(GetPawn())->ChangeAnimation();
			NPCLog("Going to ducking after firing " + FString::FromInt(iRoundsFiredSinceCameOutOfCover) + " rounds");
			if ((Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
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
					Sleep((0.25 + FMath::FRand()));
				}
				else
				{
					Sleep((FMath::FRand() * 10));
					Stand();
				}
			}
			sTargetingStatus="after firing burst and ready to shoot again";
			SaveTargetingStatusHistory(sTargetingStatus);
			JL"AimAtTarget";
		}
	}
	else
	{
		if (iNPCTacticalOrders == 300)
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				iMinRoundsToFireBeforeDucking=int((2 + (FMath::FRand() * 2)));
				iMaxRoundsToFireBeforeDucking=int((5 + (FMath::FRand() * 5)));
			}
		}
		else
		{
			if (iRoundsFiredSinceCameOutOfCover == 0)
			{
				iMinRoundsToFireBeforeDucking=int((5 + (FMath::FRand() * 2)));
				iMaxRoundsToFireBeforeDucking=int((float(10) + (FMath::FRand() * 5)));
			}
		}
		if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FMath::FRand() * float(iMaxRoundsToFireBeforeDucking))))
		{
			iRoundsFiredSinceCameOutOfCover=0;
			Sleep(FClamp((FMath::FRand() + 0.4),0.4,0.9));
			sTargetingStatus="Goto ShootTarget after burst sleep";
			SaveTargetingStatusHistory(sTargetingStatus);
			JL"ShootTarget";
		}
	}
	if ((Enemy != nullptr) && (Enemy.Health <= 0))
	{
		sTargetingStatus="Enemy dead/lost";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Enemy now down");
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("EnemyKilled");
		}
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bPopAndShoot)
		{
			NPCChangeState("ManningPopAndShootFirePosition");
			JL"End";
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportKilledEnemy(this,Enemy))
			{
				sTargetingStatus="Enemy dead, reporting to AICC";
				SaveTargetingStatusHistory(sTargetingStatus);
				npcaiccCombatController.ProcessCombatAction(this);
				JL"End";
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
				JL"RealEnd";
			}
			NPCChangeState("FindCoverThenFight");
		}
		JL"End";
	}
	if (GetPawn()->Weapon != nullptr)
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
	if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.weaponType == 4))
	{
		sTargetingStatus="Sniper going back to AimAtTarget";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL"AimAtTarget";
	}
	sTargetingStatus="Returning to ShootTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	JL"ShootTarget";
	Focus=nullptr;
	sTargetingStatus="WatchForTarget";
	SaveTargetingStatusHistory(sTargetingStatus);
	fpWatchingForLostTargetTime=((GetWorld()->GetTimeSeconds() + (FMath::FRand() * 5)) + 3);
	sTargetingStatus="Watching for lost target";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (GetWorld()->GetTimeSeconds() >= fpWatchingForLostTargetTime)
	{
		if ((Cast<AVehicle>(Enemy) != nullptr) && Vehicle(Enemy).bIsHelicopter)
		{
			NPCChangeState(GetLastStateName());
			JL"End";
		}
		if (iNPCCurrentOrders == 9)
		{
			sTargetingStatus="Time to resume assault after losing contact";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Signaling we should move to closer assault firing position after losing contact");
			NPCChangeState("AssaultLocation");
			JL"RealEnd";
		}
		if (npcaiccCombatController.ReportLostContact(this,Enemy))
		{
			sTargetingStatus="Lost contact, performing AICC action";
			SaveTargetingStatusHistory(sTargetingStatus);
			if (! ((sLastCombatAction ~= "DoNothing") || (sLastCombatAction ~= "Ignore")))
			{
				npcaiccCombatController.ProcessCombatAction(this);
				JL"End";
			}
			else
			{
				sTargetingStatus="Lost contact, ignoring bad AICC action, switching to searching state";
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState("SearchForTarget");
				JL"End";
			}
		}
		else
		{
			sTargetingStatus="Lost contact, performing No AICC action, switching to searching state";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCChangeState("SearchForTarget");
			JL"End";
		}
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		sTargetingStatus="LOS to enemy, trying ShootTarget again";
		SaveTargetingStatusHistory(sTargetingStatus);
		JL"AimAtTarget";
	}
	sTargetingStatus="Still watching for target to reappear in: " + FString::FromInt((fpWatchingForLostTargetTime - GetWorld()->GetTimeSeconds()));
	SaveTargetingStatusHistory(sTargetingStatus);
	Sleep(0.6);
	JL"KeepWatching";
	if ((npcdacpnActiveDuckAndCoverNode != nullptr) && (npcdacpnActiveDuckAndCoverNode.npcpnPrimaryFiringPosition != nullptr))
	{
		sTargetingStatus="Ending duck and cover in targeting, moving back";
		SaveTargetingStatusHistory(sTargetingStatus);
		pnDNCTempPathNode=nullptr;
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
		pnDNCTempPathNode=nullptr;
		sTargetingStatus="Finished moving back from duck and cover in targeting";
		SaveTargetingStatusHistory(sTargetingStatus);
		npcdacpnActiveDuckAndCoverNode=nullptr;
	}
	NPCLog("End of Targeting initialization");
	sTargetingStatus="Done with Targeting latent code";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((GetPawn() != nullptr) && (GetPawn()->Health > 0))
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
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
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
		if (((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr))
		{
			if ((((GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount > 0) && (Enemy != nullptr)) && LineOfSightTo(Enemy)) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
			{
				return false;
			}
			if (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount > 0)
			{
				if (GetPawn()->Weapon == agpwPrimary)
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
			if (GetPawn()->Weapon == agpwPrimary)
			{
				for (iClip=0; iClip<aiPrimaryAmmoClips.Num(); iClip++)
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
				for (iClip=0; iClip<aiSecondaryAmmoClips.Num(); iClip++)
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
				if (GetPawn()->Weapon == agpwPrimary)
				{
					GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount=aiPrimaryAmmoClips[iFullestClipIndex];
					aiPrimaryAmmoClips->Remove(iFullestClipIndex,1);
				}
				else
				{
					GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount=aiSecondaryAmmoClips[iFullestClipIndex];
					aiSecondaryAmmoClips->Remove(iFullestClipIndex,1);
				}
				return true;
			}
		}
		NPCLog("No ammo or no weapon for reloading");
		NPCLog("Weapon: " + FString::FromInt(GetPawn()->Weapon));
		if ((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr))
		{
			NPCLog("ammo type: " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType()));
		}
		return false;
	}
Begin:
	Sleep(0);
	Cast<AAGP_Pawn>(GetPawn())->ResetLean();
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		NPCLog("Rocket weapon: " + FString::FromInt(GetPawn()->Weapon) + " with " + FString::FromInt(iRPGCount) + " RPGs");
		if (iRPGCount > 0)
		{
			Stand();
			Sleep(0.25);
			sTargetingStatus="Reloading RPG";
			SaveTargetingStatusHistory(sTargetingStatus);
			iRPGCount --;
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
			}
			GetPawn()->Weapon.Reload();
			Cast<AAGP_Pawn>(GetPawn())->GotoState("BusyReloading");
			NPCLog(string(this) + " Put RPG into reload state");
			if (Cast<AAGP_Pawn>(GetPawn())->IsInState("BusyReloading"))
			{
				Sleep(0.1);
			}
			sTargetingStatus="Reloading handling of RPG done";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep((2 - ((fNPCExperience / 100) * 1.7)));
			NPCLog(string(this) + " Done sleeping after reloading RPG");
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
			}
			if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
			{
				Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			sTargetingStatus="RPG reloaded";
			SaveTargetingStatusHistory(sTargetingStatus);
			Sleep(0.5);
			NPCChangeState("Targeting","AimAtTarget");
			JL"End";
		}
		else
		{
			NPCLog("Out of ammo for RPG");
			if ((((Cast<AAGP_Pawn>(GetPawn())->getShoulderInventory() != nullptr) && Cast<AAGP_Pawn>(GetPawn())->getShoulderInventory()->IsA(AWeapon::StaticClass())) && (Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->getShoulderInventory()).GetCurrentAmmoType() != nullptr)) && (Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->getShoulderInventory()).GetCurrentAmmoType().AmmoAmount > 0))
			{
				AICCMessageSwitchWeapons();
				JL"End";
			}
			else
			{
				if ((npcaiccCombatController != nullptr) && npcaiccCombatController.ReportOutOfAmmo(this))
				{
					npcaiccCombatController.ProcessCombatAction(this);
					JL"End";
				}
				AICCMessageFallBack();
			}
			JL"End";
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
			Cast<AAGP_Pawn>(GetPawn())->NPC_Reload();
			if (Cast<AAGP_Pawn>(GetPawn())->IsInState("BusyReloading"))
			{
				Sleep(0.1);
			}
			Sleep(0.5);
			if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
			{
				Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			if (npcaiccCombatController != nullptr)
			{
				NPCChangeState("Targeting","AdjustPosture");
				if (npcaiccCombatController.ReportActionComplete(this))
				{
					npcaiccCombatController.ProcessCombatAction(this);
				}
				JL"End";
			}
			else
			{
				NPCChangeState("Targeting","AdjustPosture");
			}
		}
		else
		{
			if (((((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount > 0)) && (Enemy != nullptr)) && LineOfSightTo(Enemy)) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
			{
				NPCChangeState("Targeting","TurnToEnemy");
				JL"End";
			}
			NPCChangeState("RetreatFromBattle");
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportOutOfAmmo(this))
				{
					npcaiccCombatController.ProcessCombatAction(this);
					JL"End";
				}
			}
			JL"End";
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
	Function SetDesiredTarget(AActor* aTarget)
	{
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnEnemy)
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
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
		fpDistance=VSize((GetPawn()->GetActorLocation() - vGrenadeTarget));
		Rot=Pawn.Rotation;
		if ((fpDistance != 0) && (fpDistance <= float(3272)))
		{
			if (FMath::FRand() > 0.5)
			{
				fpVariation=(FMath::FRand() * (6 - (fNPCExperience / 20)));
			}
			else
			{
				fpVariation=((FMath::FRand() * (6 - (fNPCExperience / 20))) - 1);
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
		Log("Grenade Target distance: " + FString::FromInt((fpDistance / 55)) + "m, pitch: " + FString::FromInt(fpGrenadePitch));
		Rot.Pitch=int(fpGrenadePitch);
		GetPawn()->SetViewRotation(Rot);
		SetActorRotation(Rot);
	}
	Function RestorePawnPitch()
	{
		FRotator Rot = FRotator(0,0,0);
		Rot=Rotation;
		Rot.Pitch=0;
		SetActorRotation(Rot);
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
			if ((iLastThreatIndex != -1) && ((GetWorld()->GetTimeSeconds() - arcContactHistory[iLastThreatIndex].fpTimeSeen) < 30))
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDiedEnd";
	}
	StopMovement();
	Cast<AAGP_Pawn>(GetPawn())->ResetLean();
	if (Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[iDesiredGrenadeIndex] == 0)
	{
		NPCLog("Ack - out of this grenade!");
		JL"End";
	}
	Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=nullptr;
	switch(iDesiredGrenadeIndex)
	{
		case Pawn.0:
		Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_RGD5_Frag",Class'Class'));
		break;
		case Pawn.1:
		Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
		break;
		case Pawn.2:
		Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun",Class'Class'));
		break;
		case Pawn.3:
		Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M14_Incendiary",Class'Class'));
		break;
		case Pawn.5:
		Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Demo_DoorBreacher",Class'Class'));
		break;
		default:
	}
	if (Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade == nullptr)
	{
		NPCLog("No desired grenade found!");
		JL"End";
	}
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("Found grenade " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade) + " to swap in place of current weapon: " + FString::FromInt(GetPawn()->Weapon));
	NPCLog("Hands inventory now contains: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->getHandsInventory()));
	Cast<AAGP_Pawn>(GetPawn())->SwapHands();
	if (agpwPrimary != nullptr)
	{
		Sleep(agpwPrimary.GetAnimDuration("Drop"));
	}
	if (agpwSecondary != nullptr)
	{
		Sleep(agpwSecondary.GetAnimDuration("Select"));
	}
	Sleep(1);
	NPCLog("Hands inventory contains after swap: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->getHandsInventory()));
	NPCLog("Weapon swapping done - weapon in hand is now: " + FString::FromInt(GetPawn()->Weapon));
	if (! Pawn.Weapon->IsA(AThrowWeapon::StaticClass()))
	{
		NPCLog("Apparently the weapon in hand is no longer a throw weapon: " + FString::FromInt(GetPawn()->Weapon));
		JL"End";
	}
	NPCLog("Put throw weapon (grenade) into hand: " + FString::FromInt(GetPawn()->Weapon));
	NPCLog("Trying to turn towards last known location for grenade toss");
	FocalPoint=vGrenadeTarget;
	bRotateToDesired=true;
	FinishRotation();
	Sleep(0.5);
	Stand();
	Sleep(0.5);
	NPCLog("Weapon is now in state " + FString::FromInt(GetPawn()->Weapon.GetStateName()));
	NPCLog("Pulling pin on " + FString::FromInt(GetPawn()->Weapon));
	GetPawn()->Weapon.Instigator=Pawn;
	GetPawn()->Weapon.Fire(0);
	Sleep(0.5);
	NPCLog("Weapon is now in state " + FString::FromInt(GetPawn()->Weapon.GetStateName()));
	ThrowWeapon(GetPawn()->Weapon)._bTossNotThrow=false;
	NPCLog("Throwing grenade here: " + FString::FromInt(GetPawn()->Weapon) + " weapon is in state: " + FString::FromInt(GetPawn()->Weapon.GetStateName()));
	SetThrowPitch();
	sTargetingStatus="Throwing grenade at pitch " + FString::FromInt(GetPawn()->GetViewRotation().Pitch);
	SaveTargetingStatusHistory(sTargetingStatus);
	NPCLog("Pitch right before grenade throw (PRY): " + FString::FromInt(GetPawn()->GetViewRotation().Pitch) + "," + FString::FromInt(GetPawn()->GetViewRotation().Roll) + "," + FString::FromInt(GetPawn()->GetViewRotation().Yaw));
	GetPawn()->Weapon.Instigator=Pawn;
	GetPawn()->Weapon.Fire(0);
	ThrowWeapon(GetPawn()->Weapon).ServerThrow();
	if (npcaiccCombatController == nullptr)
	{
		NPCSay(22,true,true);
	}
	Sleep(2.5);
	if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode) != nullptr)
	{
		if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bProneForCover)
		{
			Prone();
		}
		else
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bCrouchForCover)
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
	NPCLog("Pitch for grenade throw after restoration (PRY): " + FString::FromInt(GetViewRotation().Pitch) + "," + FString::FromInt(GetViewRotation().Roll) + "," + FString::FromInt(GetViewRotation().Yaw));
	NPCLog("Bringing primary weapon back into hand after throwing");
	sTargetingStatus="Bringing up previous weapon";
	SaveTargetingStatusHistory(sTargetingStatus);
	Crouch();
	Sleep(0.25);
	Cast<AAGP_Pawn>(GetPawn())->SwapHands();
	Sleep(agpwPrimary.GetAnimDuration("Drop"));
	if (agpwSecondary != nullptr)
	{
		Sleep(agpwSecondary.GetAnimDuration("Select"));
	}
	Sleep(0.5);
	sTargetingStatus="Primary weapon should be in hand now";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (FMath::FRand() > 0.8)
	{
		Sleep(((FMath::FRand() * 5) + 2.5));
		JL"Begin";
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
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (GetPawn()->bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if ((LineOfSightTo(pawnSeen) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4))) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < float(1000)))
		{
			Enemy=pawnSeen;
			pawnLastPawnSeen=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Function NPCCoverPositionPathNode FindCoverPathNode(bool bFindFarthestPointFromThreat)
	{
		ANPCFirePositionPathNode* npcfpn = nullptr;
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
		if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount == 0))
		{
			NPCChangeState("ReloadWeapon");
			return;
		}
		UnslingWeapon();
		StopMovement();
		Crouch();
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + float(15)) + (FMath::FRand() * 15));
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
			DesiredRotation=rotator((Enemy->GetActorLocation() - Pawn->GetActorLocation()));
			Focus=Enemy;
			FocalPoint=Enemy->GetActorLocation();
		}
		else
		{
			DesiredRotation=pnCoverNode.Rotation;
			Focus=nullptr;
			FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(pnCoverNode.Rotation)));
		}
		bRotateToDesired=true;
		return true;
	}
Begin:
	if (IsInCover())
	{
		if ((Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.1] > 0) && (FMath::FRand() < fpChanceOfThrowingFragOnFallback))
		{
			StopMovement();
			NPCLog("Dropping smoke and running");
			Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
			if (Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade != nullptr)
			{
				Crouch();
				Cast<AAGP_Pawn>(GetPawn())->SwapHands();
				Sleep(1.5);
				if (GetPawn()->Weapon->IsA(AThrowWeapon::StaticClass()))
				{
					GetPawn()->Weapon.Instigator=Pawn;
					GetPawn()->Weapon.Fire(0);
					Sleep(0.75);
					ThrowWeapon(GetPawn()->Weapon)._bTossNotThrow=true;
					GetPawn()->Weapon.Fire(0);
					ThrowWeapon(GetPawn()->Weapon).ServerThrow();
					Sleep(3.5);
					Cast<AAGP_Pawn>(GetPawn())->SwapHands();
				}
			}
		}
	}
	if (FMath::FRand() < fpChanceOfShootingOnFallback)
	{
		GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(2500)));
		FocalPoint=vTargetToSuppressLocation;
		bRotateToDesired=true;
		FinishRotation();
		UnslingWeapon();
		StopMovement();
		fpAimTime=0;
		if ((GetPawn()->Weapon != nullptr) && (! Pawn.Weapon->IsA(ARocketWeapon::StaticClass())))
		{
			for (iRoundsFiredSinceCameOutOfCover=0; iRoundsFiredSinceCameOutOfCover<20; iRoundsFiredSinceCameOutOfCover++)
			{
				if (FMath::FRand() > 0.9)
				{
				}
				if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount == 0))
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
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding->IsA(AMover::StaticClass()) && (! Cast<AMover>(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(actorColliding));
		}
		if (actorColliding != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
		}
		else
		{
			GetPawn()->UpperBodyAnimComplete();
		}
	}
	Function SetEndTime()
	{
		if (((pnCurrentLocation != nullptr) && (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
		{
			fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 2.5) + (FMath::FRand() * 3));
			return;
		}
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 3));
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
		if ((fpTimeSinceLastEnemySighting > 0) && (GetWorld()->GetTimeSeconds() > (fpTimeSinceLastEnemySighting + 20)))
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
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
		FVector vPawnLoc = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		AActor* traceHit = nullptr;
		if (twpGrenade == nullptr)
		{
			return;
		}
		if ((VSize((GetPawn()->GetActorLocation() - twpGrenade->GetActorLocation())) > float(1500)) || (! LineOfSightTo(twpGrenade)))
		{
			if (VSize((GetPawn()->GetActorLocation() - twpGrenade->GetActorLocation())) < fpNPCMaxVisualRange)
			{
				AddGrenadeContact(twpGrenade);
			}
			return;
		}
		if (IsInCover())
		{
			vPawnLoc=Pawn->GetActorLocation();
			(vPawnLoc.Z += Pawn.CrouchEyeHeight);
			traceHit=Trace(HitLocation,HitNormal,twpGrenade->GetActorLocation(),vPawnLoc,true);
			if (traceHit != twpGrenade)
			{
				NPCLog("Crouching to avoid grenade");
				NPCChangeState(GetStateName(),"DuckFromGrenade");
				return;
			}
			vPawnLoc=Pawn->GetActorLocation();
			(vPawnLoc.Z += Pawn.ProneEyeHeight);
			traceHit=Trace(HitLocation,HitNormal,twpGrenade->GetActorLocation(),vPawnLoc,true);
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
		if (VSize((GetPawn()->GetActorLocation() - pawnHeard->GetActorLocation())) < float(1312))
		{
			if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		NotifyHeardPlayerNoise(fpLoudness,pawnHeard);
		vLastTarget=pawnHeard->GetActorLocation();
		NPCChangeState("SearchForTarget","TurnToNoise");
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (! agpwWeaponHeard.Instigator.Controller->IsA(AHumanController::StaticClass())))
		{
			return;
		}
		if (VSize((GetPawn()->GetActorLocation() - vSoundLocation)) > float(200))
		{
			if (! LineOfSightTo(agpwWeaponHeard.Instigator))
			{
				return;
			}
		}
		if (VSize((GetPawn()->GetActorLocation() - vSoundLocation)) < float(1312))
		{
			if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		vLastTarget=agpwWeaponHeard->GetActorLocation();
		NPCChangeState("SearchForTarget","TurnToNoise");
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < float(1312))
		{
			if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) && (nameSecondaryWeapon != nullptr))
			{
				AICCMessageSwitchWeapons();
			}
		}
		if (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 2))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
		else
		{
			Global.amrtMortarData(pawnSeen);
		}
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
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
		fpTimeLastBuzzed=(GetWorld()->GetTimeSeconds() + (FMath::FRand() * 10));
		if ((! Pawn.bIsProne) && (! Pawn.bIsCrouched))
		{
			Crouch();
		}
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("BulletWhip");
		}
		if (IsInCover())
		{
			if (((GetWorld()->GetTimeSeconds() - fpTimeEnteredCover) > 4.5) && (((GetWorld()->GetTimeSeconds() - fpTimeEnteredCover) / fpMaxIgnoreTime) > FMath::FRand()))
			{
				if (npcaiccCombatController != nullptr)
				{
					if (npcaiccCombatController.ReportUnderFire(this,aShooter))
					{
						npcaiccCombatController.ProcessCombatAction(this);
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
			if (pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass()) && bFindAlamoFirePosition)
			{
				NPCLog("Current firing position is too scary, move to new one");
				NPCChangeState("MoveToNewFiringPosition");
				return;
			}
		}
		if (GetPawn()->bIsProne || Pawn.bIsCrouched)
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
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.weaponType == 4))
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
		AActor* traceHit = nullptr;
		traceHit=Trace(HitLocation,HitNormal,vEndShot,vStartShot,true);
		return false;
	}
Begin:
	Sleep(0);
	StopMovement();
	fpTimeEnteredCover=GetWorld()->GetTimeSeconds();
	if (! Pawn.bNetRelevant)
	{
		if (((GetWorld()->GetTimeSeconds() - fpTimeEnteredCover) < 5) && (! Pawn.bNetRelevant))
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
					JL"Begin";
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL"Begin";
					}
					else
					{
						NPCChangeState("MoveToNewFiringPosition");
					}
				}
			}
			JL"End";
		}
	}
	if (npcioiLastTarget != nullptr)
	{
		Sleep((FMath::FRand() * 5));
		NPCChangeState("Targeting");
		JL"End";
	}
	if (npcaiccCombatController == nullptr)
	{
		SetEndTime();
	}
	if (Enemy != nullptr)
	{
		vLastTarget=Enemy->GetActorLocation();
		JL"TurnToNoise"
;
	}
	NPCLog("Starting search mode");
	JL"AdjustPosture";
	if ((Normal( Vector(GetPawn()->Rotation)) Dot Normal((GetPawn()->GetActorLocation() - vLastTarget))) < 0.707)
	{
		Sleep((((1 - (fNPCExperience / 100)) * 0.5) + (FMath::FRand() * 0.25)));
	}
	GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	FocalPoint=vLastTarget;
	Focus=nullptr;
	bRotateToDesired=true;
	FinishRotation();
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	if ((((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass())) && (! NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)) && (GetWorld()->GetTimeSeconds() > fpTimeLastBuzzed))
	{
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bCrouchHere)
		{
			Crouch();
		}
		else
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bProneHere)
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
			if (FMath::FRand() > 0.75)
			{
				if (GetPawn()->_InvHands->IsA(AItem_Binoculars::StaticClass()))
				{
					Cast<AAGP_Pawn>(GetPawn())->SetZoomed(false);
					UnslingWeapon();
					Sleep(1.5);
				}
				else
				{
					ShoulderWeapon();
					Sleep(1.5);
					Cast<AAGP_Pawn>(GetPawn())->GetBinoculars();
					Sleep(1.5);
					Cast<AAGP_Pawn>(GetPawn())->SetZoomed(true);
				}
			}
		}
	}
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	NPCLog("Searching from " + FString::FromInt(pnCurrentLocation));
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		GetPawn()->RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionLookDirection(true);
		bRotateToDesired=true;
		FinishRotation();
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		DetermineFiringPositionLookDirection(false);
		bRotateToDesired=true;
		FinishRotation();
		Sleep((FMath::FRand() * 1.5));
		FaceNodeDirection();
		bRotateToDesired=true;
		FinishRotation();
		GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	}
	else
	{
		GetPawn()->RotationRate.Yaw=GetSearchRotationRate();
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
		GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	}
	if (IsInState("CrazyIvan"))
	{
		if (GetWorld()->GetTimeSeconds() > fpTimeToLeaveFiringPosition)
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
				if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
				{
					Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
				}
				if (! npcaiccCombatController.ReportActionComplete(this))
				{
					npcaiccCombatController.ProcessCombatAction(this);
					NPCLog("Post Crazy Ivan completed no specific Idle time action, returning to state " + FString::FromInt(GetLastStateName()));
				}
			}
			else
			{
				NPCChangeState(GetLastStateName());
			}
			JL"End";
		}
		else
		{
			JL"LookAround";
		}
	}
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass())) || bFindAlamoFirePosition)
	{
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bPopAndShoot && CanPopAndShoot())
		{
			if (GetWorld()->GetTimeSeconds() < fpTimeToLeaveFiringPosition)
			{
				sTargetingStatus="Manning popandshoot with time left " + FString::FromInt((fpTimeToLeaveFiringPosition - GetWorld()->GetTimeSeconds()));
				SaveTargetingStatusHistory(sTargetingStatus);
				NPCChangeState("ManningPopAndShootFirePosition");
				JL"End";
			}
		}
		if (GetWorld()->GetTimeSeconds() > fpTimeToLeaveFiringPosition)
		{
			sTargetingStatus="Search for target expired manning fire position";
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("Time expired at firing position: " + FString::FromInt(pnCurrentLocation));
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
							fpTimeToLeaveFiringPosition=(GetWorld()->GetTimeSeconds() + float(10));
							JL"LookAround";
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
				JL"End";
			}
			if (npcaiccCombatController != nullptr)
			{
				fpTimeToLeaveFiringPosition=(GetWorld()->GetTimeSeconds() + (FMath::FRand() * 8));
				if (npcaiccCombatController.ReportActionComplete(this))
				{
					NPCChangeState("MoveToNewFiringPosition");
					npcaiccCombatController.ProcessCombatAction(this);
					NPCLog("Time expired at firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL"End";
				}
				else
				{
					NPCLog("Time expired at firing position, combat controller didn't handle, moving to new fire position");
					NPCChangeState("MoveToNewFiringPosition");
					JL"End";
				}
			}
		}
		else
		{
			JL"AdjustPosture";
		}
	}
	else
	{
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != nullptr)
		{
			NPCLog("SearchForTarget will report complete " + FString::FromInt(fpTimeToLeaveFiringPosition));
			if (GetWorld()->GetTimeSeconds() > fpTimeToLeaveFiringPosition)
			{
				NPCLog("Time expired at non-firing node");
				fpTimeToLeaveFiringPosition=(GetWorld()->GetTimeSeconds() + (FMath::FRand() * 8));
				if (iNPCCurrentOrders == 9)
				{
					sTargetingStatus="Time to resume assault after searching for target";
					SaveTargetingStatusHistory(sTargetingStatus);
					NPCLog("Signaling we should move to closer assault firing position after searching for target");
					NPCChangeState("AssaultLocation");
					JL"End";
				}
				if (iNPCCurrentOrders == 0)
				{
					NPCChangeState("ReturnToPatrol");
					JL"End";
				}
				if (npcaiccCombatController.ReportActionComplete(this))
				{
					NPCChangeState("MoveToNewFiringPosition");
					npcaiccCombatController.ProcessCombatAction(this);
					NPCLog("Time expired at non firing position, combat controller handling situation");
					fpTimeToLeaveFiringPosition=0;
					JL"End";
				}
				else
				{
					if (iNPCCurrentOrders == 2)
					{
						JL"LookAround";
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
						JL"End";
					}
				}
			}
			JL"LookAround";
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
	JL"End";
	NPCLog("Ducking from grenade");
	Crouch();
	Sleep(5);
	JL"Begin";
	NPCLog("Going prone from grenade");
	Crouch();
	Sleep(5);
	JL"Begin";
}
*/

/*
State CrazyIvan extends SearchForTarget
{
	Function SetEndTime()
	{
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 2));
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	UnslingWeapon();
	NPCLog("Starting Crazy Ivan");
	StopMovement();
	if (GetPawn()->bIsProne)
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
	GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(16384)));
	if (FMath::FRand() > 0.5)
	{
		LookLeft(32767);
		FinishRotation();
	}
	else
	{
		LookRight(32768);
		FinishRotation();
	}
	GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	Sleep(PlayAlertAnimation());
	SetEndTime();
	JL"LookAround";
}
*/

/*
State ArrivedAtRestStop
{
	Function PrepRestStopArrival()
	{
		if (Cast<ANPCRestStopPathNode>(pnCurrentLocation).npcassNPCAnimationToPerform.bShoulderWeaponFirst)
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
		if (npcioi.bIsShootableTarget)
		{
			npcioiLastTarget=npcioi;
			NPCLog("Item of interest is a targetable item and associated pawn being used as target");
			Enemy=npcioi.pawnTargetToShoot;
			NPCChangeState("Targeting");
		}
	}
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding->IsA(AMover::StaticClass()) && (! Cast<AMover>(actorColliding).bNotADoor))
		{
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(actorColliding));
			NPCChangeState("WalkingPatrol","NextTravelNode");
		}
		if (actorColliding != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
		}
		else
		{
			GetPawn()->UpperBodyAnimComplete();
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
		if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode) != nullptr)
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
			if (npcaiccCombatController.IsBodyNearLocation(Cast<AAGP_Pawn>(GetPawn())))
			{
				if (FMath::FRand() > 0.5)
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
		NPCLog("Arrived at pathnode: " + FString::FromInt(pnCurrentPathNode.Tag));
		if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			NPCChangeState("ManningFirePosition");
		}
		NPCLog("Pathnode: Enemy " + FString::FromInt(Enemy) + ", focus: " + FString::FromInt(Focus));
		if ((Enemy == nullptr) && (Cast<AAGP_Pawn>(Focus) == nullptr))
		{
			iMostRecentContactIndex=GetHighestThreatContactIndex();
			if ((iMostRecentContactIndex != -1) && ((GetWorld()->GetTimeSeconds() - arcContactHistory[iMostRecentContactIndex].fpTimeSeen) < 30))
			{
				SetDesiredTarget(arcContactHistory[iMostRecentContactIndex].pawnContact);
				return;
			}
			if ((GetPawn()->Weapon != nullptr) && (GetConfidenceLevel() > float(-10)))
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
		ChangeState("SearchForTarget");
	}
}
*/

/*
State ManningFirePosition
{
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
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
	if (((pnCurrentLocation != nullptr) && (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr)) && NPCFirePositionPathNode(pnCurrentLocation).bPopAndShoot)
	{
		NPCChangeState("ManningPopAndShootFirePosition");
	}
	fpTimeEnteredCover=GetWorld()->GetTimeSeconds();
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + float(15)) + (FMath::FRand() * 15));
	if (Enemy == nullptr)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != nullptr)
	{
		NPCLog("ManningFirePosition - Begin entered at pathnode: " + FString::FromInt(pnCurrentLocation.Tag));
		if (Enemy == nullptr)
		{
			DesiredRotation=pnCurrentLocation.Rotation;
			Focus=nullptr;
			FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		}
		else
		{
			Focus=Enemy;
			FocalPoint=Enemy->GetActorLocation();
		}
		bRotateToDesired=true;
		FinishRotation();
	}
	Sleep(0);
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting","AimAtTarget");
		JL"End";
	}
	if ((pnCurrentLocation == nullptr) || (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) == nullptr))
	{
		NPCChangeState("SearchForTarget");
		JL"End";
	}
	NPCLog("ManningFirePosition - Changing posture");
	if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bCrouchHere)
	{
		Crouch();
	}
	else
	{
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bProneHere)
		{
			Prone();
		}
	}
	Sleep((FMath::FRand() * 1.5));
	if (FMath::FRand() > 0.5)
	{
		if (! NPCFirePositionPathNode(pnCurrentLocation).bCrouchHere)
		{
			Stand();
			Sleep((FMath::FRand() * 1.5));
		}
	}
	if ((Enemy != nullptr) || (pawnLastEnemy != nullptr))
	{
		if (Enemy == nullptr)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState("Targeting","TurnToEnemy");
		JL"End";
	}
	NPCChangeState("SearchForTarget");
	if (npcaiccCombatController != nullptr)
	{
		if (npcaiccCombatController.ReportActionComplete(this))
		{
			npcaiccCombatController.ProcessCombatAction(this);
		}
	}
}
*/

/*
State ManningPopAndShootFirePosition
{
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
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
	fpTimeEnteredCover=GetWorld()->GetTimeSeconds();
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	if (GetLastStateName() != "SearchForTarget")
	{
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + float(10)) + (FMath::FRand() * 15));
	}
	if (Enemy == nullptr)
	{
		Enemy=pawnLastEnemy;
	}
	if (pnCurrentLocation != nullptr)
	{
		NPCLog("ManningPopAndShootFirePosition - Begin entered at pathnode: " + FString::FromInt(pnCurrentLocation.Tag));
		if (Enemy == nullptr)
		{
			DesiredRotation=pnCurrentLocation.Rotation;
			Focus=nullptr;
			FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(pnCurrentLocation.Rotation)));
		}
		else
		{
			Focus=Enemy;
			FocalPoint=Enemy->GetActorLocation();
		}
		bRotateToDesired=true;
		FinishRotation();
	}
	Sleep(0);
	Crouch();
	Sleep((5 + (FMath::FRand() * 5)));
	Stand();
	if (Enemy == nullptr)
	{
		Sleep(((FMath::FRand() * 0.5) + 0.25));
		Crouch();
		Sleep((5 + (FMath::FRand() * 5)));
	}
	if ((Enemy != nullptr) && LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting","AimAtTarget");
		JL"End";
	}
	NPCLog("ManningFirePosition - Changing posture");
	if ((Enemy != nullptr) || (pawnLastEnemy != nullptr))
	{
		if (Enemy == nullptr)
		{
			Enemy=pawnLastEnemy;
		}
		NPCChangeState("Targeting","TurnToEnemy");
		JL"End";
	}
	NPCChangeState("SearchForTarget");
}
*/

/*
State MoveToNewFiringPosition
{
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding->IsA(AMover::StaticClass()) && (! Cast<AMover>(actorColliding).bNotADoor))
		{
			if (Cast<AMover>(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(actorColliding));
			NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
		}
		if (actorColliding != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
		}
		else
		{
			GetPawn()->UpperBodyAnimComplete();
		}
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		sTargetingStatus="MoveToNewFiringPosition - saw player " + FString::FromInt(pawnSeen);
		SaveTargetingStatusHistory(sTargetingStatus);
		if (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 3))
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
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (GetPawn()->bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function ArrivedAtFiringPosition()
	{
		NPCChangeState("ManningFirePosition");
	}
	Function bool ShouldRun()
	{
		if (GetPawn()->bIsProne || Pawn.bIsCrouched)
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
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall->IsA(AMover::StaticClass()))
		{
			if (Cast<AMover>(Wall).bNotADoor)
			{
				NPCPathLog(string(this) + "." + FString::FromInt(Tag) + " hit a non-door mover: " + FString::FromInt(Wall) + " Normal: " + FString::FromInt(HitNormal) + " at location " + FString::FromInt(Pawn->GetActorLocation()));
				return false;
			}
			else
			{
				if (Cast<AMover>(Wall).bInterpolating)
				{
					return false;
				}
				OpenDoorFromHere(Pawn->GetActorLocation(),Mover(Wall));
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	NPCLog("MoveToNewFiringPosition - StartMoving entered");
	pnCurrentPathNode=FindNextFiringPosition(1500);
	if ((pnCurrentPathNode == nullptr) && (npcfppnLastFirePosition != nullptr))
	{
		npcfppnLastFirePosition=nullptr;
		pnCurrentPathNode=FindNextFiringPosition(1500);
	}
	else
	{
		if (pnCurrentPathNode == pnCurrentLocation)
		{
			ArrivedAtFiringPosition();
			JL"End";
		}
	}
	JL"HavePath";
	Sleep(1.5);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	if (pnCurrentPathNode != nullptr)
	{
		NPCLog("MoveToNewFiringPosition - Found new firing position: " + FString::FromInt(pnCurrentPathNode));
		pnCurrentNodeLeadingToPathNode=nullptr;
		if (true)
		{
			if (GetPawn() == nullptr)
			{
				JL"PawnDeadEnd";
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCLog("MoveToNewFiringPosition - Moving to node " + FString::FromInt(pnCurrentPathNode) + " via " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(nullptr);
				if (ShouldRun())
				{
					Run();
				}
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (VSize((pnCurrentNodeLeadingToPathNode->GetActorLocation() - Pawn->GetActorLocation())) > float(150))
				{
					NPCLog(string(this) + "." + FString::FromInt(Tag) + " Stuck moving to new firing position!");
					StopMovement();
					Sleep(2);
					JL"Begin";
				}
				if (pnCurrentNodeLeadingToPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
				{
					if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
						StopMovement();
						if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
								NPCLog("Door done moving (probably): " + FString::FromInt(mLastDoorOpened));
							}
						}
						GetPawn()->UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode->IsA(ANPCLadderPathNode::StaticClass()))
					{
						if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
								{
									Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
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
			JL"HavePath";
		}
		else
		{
			UpdatePathNodeBonuses(pnCurrentPathNode);
			NPCChangeState("FindCover");
			JL"End";
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
			Focus=nullptr;
			FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(pnCurrentPathNode.Rotation)));
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
		ANPCFirePositionPathNode* npcfppnClosest = nullptr;
		float fpClosestFiringPositionDistance = 0;
		float fpCurrentFiringPositionDistance = 0;
		if (GetPawn() == nullptr)
		{
			return nullptr;
		}
		fpMaxDistance=500;
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Num(); iPathNode++)
		{
			if (! anpcfppnFiringPositions[iPathNode]->IsA(ANPCCamperFirePositionPathNode::StaticClass()))
			{
			}
			NPCLog("Testing camper firing position: " + FString::FromInt(anpcfppnFiringPositions[iPathNode].Tag));
			if (pnCurrentLocation == anpcfppnFiringPositions[iPathNode])
			{
			}
			if (npcfppnLastFirePosition == anpcfppnFiringPositions[iPathNode])
			{
			}
			if ((anpcfppnFiringPositions[iPathNode].cControllerUsingNode != nullptr) && (anpcfppnFiringPositions[iPathNode].cControllerUsingNode != Self))
			{
			}
			if ((string(anpcfppnFiringPositions[iPathNode].Tag) != FString::FromInt(Tag)) && (string(anpcfppnFiringPositions[iPathNode].Tag) != sNPCWaypointTag))
			{
			}
			if (VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - Pawn->GetActorLocation())) > fpMaxDistance)
			{
				NPCLog("Camper node too far away: " + FString::FromInt(VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - Pawn->GetActorLocation()))) + " max allowed: " + FString::FromInt(fpMaxDistance));
			}
			else
			{
				if (FMath::Abs((GetPawn()->Location.Z - anpcfppnFiringPositions[iPathNode].Location.Z)) > anpcfppnFiringPositions[iPathNode].fpMaxVerticalDeltaToFind)
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
						NPCLog("Testing node anpcfppnFiringPositions[ " + FString::FromInt(iPathNode) + "] for closest camper position: " + FString::FromInt(anpcfppnFiringPositions[iPathNode].Tag));
						fpCurrentFiringPositionDistance=VSize((GetPawn()->GetActorLocation() - anpcfppnFiringPositions[iPathNode]->GetActorLocation()));
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
		NPCLog("Closest camper position: " + FString::FromInt(npcfppnClosest));
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
		if (GetPawn() == nullptr)
		{
			return nullptr;
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
	Function SetDesiredTarget(AActor* aTarget)
	{
	}
	Function NotifyEnemyNotVisible()
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (GetPawn()->bIsCrouched)
		{
			Run();
		}
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnEnemy)
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
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
		ANPCAlamoFirePositionPathNode* pnIterator = nullptr;
		ANPCAlamoFirePositionPathNode* pnPotentialFallback = nullptr;
		ANavigationPoint* N = nullptr;
		if (GetPawn() == nullptr)
		{
			return nullptr;
		}
		NPCLog("Trying to find alamo node");
		for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
		{
			if (! N->IsA(ANPCAlamoFirePositionPathNode::StaticClass()))
			{
			}
			pnIterator=NPCAlamoFirePositionPathNode(N);
			NPCLog("Found possible alamo node to run to: \"" + FString::FromInt(pnIterator.Tag) + "\" vs. NPC tag \"" + sNPCWaypointTag + "\"");
			if (string(pnIterator.Tag) ~= sNPCWaypointTag)
			{
				NPCLog("Found possible alamo node, using flag: " + FString::FromInt(pnIterator.npcbcUsingNode));
				if ((pnIterator.npcbcUsingNode != nullptr) && (pnIterator.npcbcUsingNode != Self))
				{
					NPCLog("alamo location " + FString::FromInt(pnIterator.Tag) + " is in use!");
					pnPotentialFallback=pnIterator;
				}
				else
				{
					pnIterator.npcbcUsingNode=Self;
					pnIterator.bInUse=true;
					pnCurrentPathNode=pnIterator;
					NPCLog("Found alamo firing position: " + FString::FromInt(pnIterator));
					return pnIterator;
				}
			}
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	if (IsInCover())
	{
		if ((Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.1] > 0) && (FMath::FRand() < fpChanceOfThrowingFragOnFallback))
		{
			StopMovement();
			NPCLog("Dropping smoke and running");
			Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
			if (Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade != nullptr)
			{
				Crouch();
				Cast<AAGP_Pawn>(GetPawn())->SwapHands();
				Sleep(1.5);
				if (GetPawn()->Weapon->IsA(AThrowWeapon::StaticClass()))
				{
					GetPawn()->Weapon.Instigator=Pawn;
					GetPawn()->Weapon.Fire(0);
					Sleep(0.75);
					ThrowWeapon(GetPawn()->Weapon)._bTossNotThrow=true;
					GetPawn()->Weapon.Fire(0);
					ThrowWeapon(GetPawn()->Weapon).ServerThrow();
					Sleep(3.5);
					Cast<AAGP_Pawn>(GetPawn())->SwapHands();
				}
			}
		}
	}
	if (FMath::FRand() < fpChanceOfShootingOnFallback)
	{
		GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(2500)));
		FocalPoint=vTargetToSuppressLocation;
		bRotateToDesired=true;
		FinishRotation();
		UnslingWeapon();
		StopMovement();
		fpAimTime=0;
		for (iRoundsFiredSinceCameOutOfCover=0; iRoundsFiredSinceCameOutOfCover<20; iRoundsFiredSinceCameOutOfCover++)
		{
			if (FMath::FRand() > 0.9)
			{
			}
			if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount == 0))
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
	Event ReceiveWarning(APawn* shooter, float projSpeed, Vector FireDir)
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (((actThreat == nullptr) && (npcaiccCombatController != nullptr)) && (GetWorld()->GetTimeSeconds() > fpTimeToEndLastInterrupt))
		{
			AICCMessageScanForEnemy();
			if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
			{
				Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
			}
			if (npcaiccCombatController.ReportActionComplete(this))
			{
				npcaiccCombatController.ProcessCombatAction(this);
			}
		}
	}
	Function InCoverAction()
	{
		Super::InCoverAction();
		UnslingWeapon();
		fpTimeToEndLastInterrupt=(GetWorld()->GetTimeSeconds() + (FMath::FRand() * float(10)));
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
			NPCLog("Grenade distance: " + FString::FromInt(VSize((twpLastGrenadeHeard->GetActorLocation() - Pawn->GetActorLocation()))));
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	if (actThreat != nullptr)
	{
		Focus=actThreat;
		GetPawn()->RotationRate.Yaw=int(fpTurnRate);
		bRotateToDesired=true;
		FinishRotation();
	}
}
*/

/*
State AdvanceOnEnemyLocation
{
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		fpTimeSinceUntilTargetLost=0;
		if (LineOfSightTo(pawnSeen) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
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
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		NPCPathLog("Hit wall, normal: " + FString::FromInt(HitNormal));
		if (Wall->IsA(AMover::StaticClass()) && (! Cast<AMover>(Wall).bNotADoor))
		{
			if (Cast<AMover>(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(Wall));
			ChangeState("AdvanceOnEnemyLocation","OpeningDoor");
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
		if (VSize((pawnHeard->GetActorLocation() - vLastTarget)) > float(250))
		{
			NPCLog("Overriding advance based on newly heard sound:" + FString::FromInt(pawnHeard));
			vLastTarget=pawnHeard->GetActorLocation();
			pawnLastHeard=pawnHeard;
			NPCChangeState("Targeting");
		}
	}
	Event bool NotifyBump(AActor* Other)
	{
		if (! AdjustAround(Cast<APawn>(Other)))
		{
			BackupAfterBump(Cast<APawn>(Other));
			NPCChangeState("PursueEnemy","ContinueNavigation");
			return true;
		}
		return true;
	}
	Function NPCPathNode FindClosestFirePositionToTarget(Vector vLastTarget)
	{
		ANPCPathNode* pnBestFirePosition = nullptr;
		float fpDistanceFromBestToTarget = 0;
		AActor* traceHit = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector vNodeEyeHeightLocation = FVector(0,0,0);
		int32 iPathNode = 0;
		if (GetPawn() == nullptr)
		{
			return nullptr;
		}
		for (iPathNode=0; iPathNode<anpcfppnFiringPositions.Num(); iPathNode++)
		{
			if (anpcfppnFiringPositions[iPathNode] == pnCurrentLocation)
			{
			}
			if (VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - Pawn->GetActorLocation())) > float(2500))
			{
			}
			if (VSize((vLastTarget - Pawn->GetActorLocation())) < VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - vLastTarget)))
			{
			}
			NPCPathLog("Found possible fire position to move to: " + FString::FromInt(anpcfppnFiringPositions[iPathNode].Tag));
			if (pnBestFirePosition == nullptr)
			{
				vNodeEyeHeightLocation=anpcfppnFiringPositions[iPathNode]->GetActorLocation();
				vNodeEyeHeightLocation.Z += float(100);
				traceHit=anpcfppnFiringPositions[iPathNode].Trace(HitLocation,HitNormal,vLastTarget,vNodeEyeHeightLocation,true);
				if (bDebugPath && bDebugCombat)
				{
					NPCPathLog("No Previous Advance Fire position, potential new one: " + FString::FromInt(anpcfppnFiringPositions[iPathNode]) + " Trace towards target hit: " + FString::FromInt(traceHit) + ", distance: " + FString::FromInt(VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - vLastTarget))));
				}
				if ((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()"))
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
					if (VSize((pnBestFirePosition->GetActorLocation() - vLastTarget)) < VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - vLastTarget)))
					{
						NPCLog("Testing Advance  firing position " + FString::FromInt(anpcfppnFiringPositions[iPathNode]) + " for LOS to target");
						vNodeEyeHeightLocation=anpcfppnFiringPositions[iPathNode]->GetActorLocation();
						vNodeEyeHeightLocation.Z += float(100);
						traceHit=anpcfppnFiringPositions[iPathNode].Trace(HitLocation,HitNormal,vLastTarget,vNodeEyeHeightLocation,true);
						if (bDebugPath && bDebugCombat)
						{
							NPCPathLog("Testing new \"Best\" Advance Fire position: " + FString::FromInt(anpcfppnFiringPositions[iPathNode]) + " Trace towards target hit: " + FString::FromInt(traceHit) + ", distance: " + FString::FromInt(VSize((anpcfppnFiringPositions[iPathNode]->GetActorLocation() - vLastTarget))));
						}
						if ((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()"))
						{
							NPCPathLog("Somewhat closer Advance firing position found, testing it for usefulness");
							pnBestFirePosition=anpcfppnFiringPositions[iPathNode];
							fpDistanceFromBestToTarget=VSize((pnBestFirePosition->GetActorLocation() - vLastTarget));
						}
					}
				}
			}
		}
		if (pnBestFirePosition == nullptr)
		{
			pnBestFirePosition=pnCurrentLocation;
		}
		NPCPathLog("Found Advance firing position location: " + FString::FromInt(pnBestFirePosition));
		return pnBestFirePosition;
	}
Begin:
	Sleep(0);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
		JL"End";
	}
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	RequestSuppressiveFire(vLastTarget);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0.1);
	GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(2500)));
	FocalPoint=vLastTarget;
	bRotateToDesired=true;
	FinishRotation();
	JL"ContinueNavigation";
	Sleep(1.5);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
			if (((GetPawn() == nullptr) || (GetPawn()->Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End";
			}
			pnCurrentNodeLeadingToPathNode=PathNode(FindPathToward(pnCurrentPathNode,true));
			NPCPathLog("Advance path location: " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " + FString::FromInt(pnCurrentPathNode) + " via " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				if ((LineOfSightTo(pnCurrentPathNode) && (pnCurrentPathNode.cControllerUsingNode != nullptr)) && (pnCurrentPathNode.cControllerUsingNode != Self))
				{
					pnCurrentPathNode=FindClosestFirePositionToTarget(vLastTarget);
					if (pnCurrentPathNode == nullptr)
					{
						NPCChangeState("FindCoverThenFight");
						JL"End";
					}
				}
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(nullptr);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,,(! ShouldRun()));
				if (pnCurrentNodeLeadingToPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
				{
					if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
						if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
								NPCLog("Door done moving (probably): " + FString::FromInt(mLastDoorOpened));
							}
						}
						GetPawn()->UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode->IsA(ANPCLadderPathNode::StaticClass()))
					{
						if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
								{
									Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
			}
			else
			{
				NPCPathLog("No more nodes found for advance - moving to last node: " + FString::FromInt(pnCurrentPathNode.Tag));
				DebugMarkNextNode(pnCurrentPathNode);
				UpdatePathNodeBonuses(nullptr);
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
				pnCurrentPathNode.DebugNavMarker(false);
				FocalPoint=vLastTarget;
				bRotateToDesired=true;
				FinishRotation();
				UpdatePathNodeBonuses(pnCurrentPathNode);
				fpTimeToEndLastInterrupt=(GetWorld()->GetTimeSeconds() + float(10));
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
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (GetPawn()->bIsCrouched)
		{
			Run();
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
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
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		NPCPathLog("Hit wall, normal: " + FString::FromInt(HitNormal));
		if (Wall->IsA(AMover::StaticClass()) && (! Cast<AMover>(Wall).bNotADoor))
		{
			if (Cast<AMover>(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(Wall));
			ChangeState("AssaultLocation","OpeningDoor");
			return true;
		}
		return Global.pos(HitNormal,Wall);
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
		if ((Other == Enemy) || Other->IsA(AHumanController::StaticClass()))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState("Targeting","TurnToEnemy");
			return true;
		}
		if (Cast<APawn>(Other) == nullptr)
		{
			NPCChangeState("AssaultLocation");
			return true;
		}
		if ((Cast<APawn>(Other) != nullptr) && (VSize(Cast<APawn>(Other).Velocity) < 2))
		{
			if (Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller) != nullptr)
			{
				Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller).NPCChangeState("AssaultLocation");
			}
		}
		if (! AdjustAround(Cast<APawn>(Other)))
		{
			NPCChangeState("AssaultLocation");
			if (Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller) != nullptr)
			{
				Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller).NPCChangeState("AssaultLocation");
			}
			return true;
		}
		return true;
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if ((((pawnLastPawnSeen != pawnSeen) && (FMath::FRand() > 0.95)) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastSawEnemyOnAssault) > float(10))) || (((VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < float(1500))) && (FMath::FRand() > 0.98)))
		{
			fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 2.5) + (FMath::FRand() * 3));
			fpTimeSinceLastSawEnemyOnAssault=fpTimeToLeaveFiringPosition;
			sTargetingStatus="Assaulting, but see player pawn in sight at range " + FString::FromInt(VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())));
			SaveTargetingStatusHistory(sTargetingStatus);
			NPCLog("NotifyPlayerPawnInSight() targeting enemy pawn we were pursuing");
			StopMovement();
			pawnLastPawnSeen=pawnSeen;
			Enemy=pawnSeen;
			Focus=pawnSeen;
			if (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < float(1500))
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
	Function PathNode GetPathNodeFromRoute(APathNode* pnLastNode)
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	LocateAssaultLocation();
	Sleep(0.25);
	NPCLog("****************");
	NPCLog("Assault Location entered");
	NPCLog("Trying to assault location  " + FString::FromInt(vAssaultLocation));
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.npcbcUsingNode=nullptr;
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
		Sleep((2.5 * (FMath::FRand() * 5)));
		pnCurrentNodeLeadingToPathNode=FindCloserAssaultFirePositionToTarget(vAssaultLocation,true,true);
		if ((pnCurrentPathNode == pnCurrentNodeLeadingToPathNode) || (pnCurrentNodeLeadingToPathNode == nullptr))
		{
			NPCLog("Really failed to get path for assault, giving up and targeting");
			sTargetingStatus="Really path to assault location could not be found, looking for some cover";
			SaveTargetingStatusHistory(sTargetingStatus);
			iNPCCurrentOrders=3;
			fpTargetingStartTime=0;
			NPCChangeState("MoveToNewFiringPosition");
			SetCustomTimer(((FMath::FRand() * 10) + 5),false,"ReturnToAssault");
			JL"End";
		}
	}
	Sleep(0.25);
	pnCurrentPathNode=NPCPathNode(pnCurrentNodeLeadingToPathNode);
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.npcbcUsingNode=Self;
	}
	pnCurrentLocation=nullptr;
	NPCLog("Closest fire position to target: " + FString::FromInt(pnCurrentPathNode));
	if (bDebugPath && bDebugCombat)
	{
		pnCurrentPathNode.DebugNavMarker(true,true);
	}
	if (FMath::FRand() > 0.75)
	{
		RequestSuppressiveFire(vAssaultLocation);
	}
	if (FMath::FRand() > 0.7)
	{
		if (ThrowSmokeGrenade())
		{
			vGrenadeTarget=vAssaultLocation;
			NPCChangeState("ThrowingGrenade");
		}
	}
	Sleep(1.5);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	if (pnCurrentPathNode == nullptr)
	{
		Log(string(this) + "." + FString::FromInt(GetPawn()) + "Assault failing due to no next fire position");
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
			if (((GetPawn() == nullptr) || (GetPawn()->Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End";
			}
			NPCPathLog("Advance path location: " + FString::FromInt(actorNextPathLocation) + " converted to pathnode: " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " + FString::FromInt(pnCurrentPathNode) + " via " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				fpTimeToEndLastInterrupt=(GetWorld()->GetTimeSeconds() + float(20));
				sTargetingStatus="AssaultLocation - Moving to new node";
				SaveTargetingStatusHistory(sTargetingStatus);
				Stand();
				Run();
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(nullptr);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (VSize((GetPawn()->GetActorLocation() - pnCurrentNodeLeadingToPathNode->GetActorLocation())) > float(250))
				{
					sTargetingStatus="AssaultLocation - Failed to get to target node, resetting assualt location";
					StopMovement();
					Sleep(0.25);
					NPCChangeState("AssaultLocation");
					JL"End";
				}
				sTargetingStatus="AssaultLocation - Done moving to new node";
				SaveTargetingStatusHistory(sTargetingStatus);
				if (pnCurrentNodeLeadingToPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
				{
					if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
						if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						GetPawn()->UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode->IsA(ANPCLadderPathNode::StaticClass()))
					{
						if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
								{
									Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
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
					NPCPathLog("No more nodes found for advance - moving to last node: " + FString::FromInt(pnCurrentPathNode.Tag));
					DebugMarkNextNode(pnCurrentPathNode);
					UpdatePathNodeBonuses(nullptr);
					Stand();
					Run();
					MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
					pnCurrentPathNode.DebugNavMarker(false);
					sTargetingStatus="AssaultLocation - Done moving to final node";
					SaveTargetingStatusHistory(sTargetingStatus);
					StopMovement();
					if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode) != nullptr)
					{
						if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bCrouchForCover)
						{
							Crouch();
						}
						else
						{
							if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bProneForCover)
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
					Sleep((0.25 + (FMath::FRand() * 1.25)));
					sTargetingStatus="AssaultLocation - Rotating towards assault location";
					SaveTargetingStatusHistory(sTargetingStatus);
					FocalPoint=vAssaultLocation;
					bRotateToDesired=true;
					Focus=nullptr;
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
	fpTimeToEndLastInterrupt=GetWorld()->GetTimeSeconds();
	if (pnCurrentPathNode != nullptr)
	{
		pnCurrentPathNode.DebugNavMarker(false);
	}
	if (VSize((vAssaultLocation - Pawn->GetActorLocation())) <= float(550))
	{
		iNPCCurrentOrders=3;
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 2.5) + (FMath::FRand() * float(10)));
		NPCChangeState("SearchForTarget","LookAround");
		JL"End";
	}
	if (FMath::FRand() < 0.5)
	{
		sTargetingStatus="Assault Location, switching to search for target";
		SaveTargetingStatusHistory(sTargetingStatus);
		fpTimeToLeaveFiringPosition=((GetWorld()->GetTimeSeconds() + 2.5) + (FMath::FRand() * float(10)));
		NPCChangeState("SearchForTarget","LookAround");
	}
	else
	{
		sTargetingStatus="Assault Location, switching to non-requested providing suppressive fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((pawnLastEnemy != nullptr) && LineOfSightTo(pawnLastEnemy))
		{
			vTargetToSuppressLocation=pawnLastEnemy->GetActorLocation();
		}
		else
		{
			if ((pawnLastPawnSeen != nullptr) && LineOfSightTo(pawnLastPawnSeen))
			{
				vTargetToSuppressLocation=pawnLastPawnSeen->GetActorLocation();
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
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		NPCPathLog("Hit wall, normal: " + FString::FromInt(HitNormal));
		if (Wall->IsA(AMover::StaticClass()) && (! Cast<AMover>(Wall).bNotADoor))
		{
			if (Cast<AMover>(Wall).bInterpolating)
			{
				return false;
			}
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(Wall));
			ChangeState("PursueEnemy","OpeningDoor");
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
		if (VSize((pawnHeard->GetActorLocation() - vLastTarget)) > float(250))
		{
			NPCLog("Overriding advance based on newly heard sound:" + FString::FromInt(pawnHeard));
			vLastTarget=pawnHeard->GetActorLocation();
			Enemy=pawnHeard;
			NPCChangeState("PursueEnemy");
		}
	}
	Event bool NotifyBump(AActor* Other)
	{
		if ((Other == Enemy) || Other->IsA(AHumanController::StaticClass()))
		{
			StopMovement();
			Enemy=Pawn(Other);
			NPCChangeState("Targeting","TurnToEnemy");
			return true;
		}
		if (! AdjustAround(Cast<APawn>(Other)))
		{
			BackupAfterBump(Cast<APawn>(Other));
			return true;
		}
		return true;
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if ((Enemy == pawnSeen) || (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 2)))
		{
			NPCLog("NotifyPlayerPawnInSight() targeting enemy pawn we were pursuing");
			StopMovement();
			Enemy=pawnSeen;
			Focus=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
			return;
		}
		NotifyPlayerPawnInSight(pawnSeen);
		Enemy=nullptr;
		EvaluateTarget(pawnSeen,false);
	}
Begin:
	Sleep(0);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0.1);
	GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	FocalPoint=(GetPawn()->GetActorLocation() + (float(512) *  Vector(Normalize(rotator((vLastTarget - Pawn->GetActorLocation()))))));
	bRotateToDesired=true;
	FinishRotation();
	JL"ContinueNavigation";
	Sleep(1.5);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
		fpTimeSinceLastSearchedWhilePursuing=((GetWorld()->GetTimeSeconds() + 2) + (FMath::FRand() * 3));
		if (true)
		{
			if (((GetPawn() == nullptr) || (GetPawn()->Health < 0)) || (! bStart))
			{
				NPCChangeState("None");
				JL"End";
			}
			actorNextPathLocation=FindPathToward(pnCurrentPathNode,true);
			pnCurrentNodeLeadingToPathNode=PathNode(actorNextPathLocation);
			NPCPathLog("Advance path location: " + FString::FromInt(actorNextPathLocation) + " converted to pathnode: " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if (bDebugPath)
			{
				DebugDumpRoute();
			}
			NPCPathLog("Advancing towards enemy via node " + FString::FromInt(pnCurrentPathNode) + " via " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
			if ((pnCurrentNodeLeadingToPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
			{
				if (fpTimeSinceLastSearchedWhilePursuing > GetWorld()->GetTimeSeconds())
				{
					Focus=nullptr;
					FocalPoint=vLastTarget;
					bRotateToDesired=true;
					FinishRotation();
					Sleep(0.5);
					fpTimeSinceLastSearchedWhilePursuing=((GetWorld()->GetTimeSeconds() + 2) + (FMath::FRand() * 3));
				}
				fpTimeToEndLastInterrupt=(GetWorld()->GetTimeSeconds() + float(20));
				DebugMarkNextNode(pnCurrentNodeLeadingToPathNode);
				UpdatePathNodeBonuses(nullptr);
				MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
				if (pnCurrentNodeLeadingToPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
				{
					if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)).bClosed)
					{
						StopMovement();
						Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
						if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeLeadingToPathNode)))
						{
							Sleep(0.1);
							if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
							{
								Sleep(mLastDoorOpened.MoveTime);
							}
						}
						GetPawn()->UpperBodyAnimComplete();
					}
				}
				else
				{
					if (pnCurrentNodeLeadingToPathNode->IsA(ANPCLadderPathNode::StaticClass()))
					{
						if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderTop)
						{
							if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
							{
								StopMovement();
								lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
								Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								Sleep(0.25);
							}
						}
						else
						{
							if (Cast<ANPCLadderPathNode>(pnCurrentNodeLeadingToPathNode).bNearLadderBase)
							{
								if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
								{
									Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
								}
								else
								{
									lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeLeadingToPathNode);
									Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
								}
							}
						}
					}
				}
				if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && pnCurrentNodeLeadingToPathNode->IsA(ANPCFirePositionPathNode::StaticClass()))
				{
					NPCLog("Can see enemy, reporting contact from firing position");
					if ((npcaiccCombatController != nullptr) && npcaiccCombatController.ReportContact(this,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
					{
						npcaiccCombatController.ProcessCombatAction(this);
						UpdatePathNodeBonuses(Cast<ANPCPathNode>(pnCurrentNodeLeadingToPathNode));
						JL"End";
					}
				}
				JL"LookAround";
			}
			else
			{
				if (((pnCurrentPathNode != nullptr) && (pnCurrentNodeLeadingToPathNode == nullptr)) && (! LineOfSightTo(pnCurrentPathNode)))
				{
					fpTimeToEndLastInterrupt=GetWorld()->GetTimeSeconds();
					if (pnCurrentPathNode != nullptr)
					{
						pnCurrentPathNode.DebugNavMarker(false);
					}
					NPCChangeState("MoveToNewFiringPosition");
					JL"End";
				}
				Walk();
				Crouch();
				Focus=pnCurrentPathNode;
				bRotateToDesired=true;
				FinishRotation();
				NPCPathLog("No more nodes found for advance - moving to last node: " + FString::FromInt(pnCurrentPathNode.Tag));
				DebugMarkNextNode(pnCurrentPathNode);
				UpdatePathNodeBonuses(nullptr);
				MoveToward(pnCurrentPathNode,pnCurrentPathNode,,false,(! ShouldRun()));
				pnCurrentPathNode.DebugNavMarker(false);
				FocalPoint=(GetPawn()->GetActorLocation() + (float(512) *  Vector(Normalize(rotator((vLastTarget - Pawn->GetActorLocation()))))));
				bRotateToDesired=true;
				FinishRotation();
			}
			else
			{
			}
		}
		UpdatePathNodeBonuses(pnCurrentPathNode);
	}
	fpTimeToEndLastInterrupt=GetWorld()->GetTimeSeconds();
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
		GetPawn()->bIsFiringBlindlyOverHead=false;
		GetPawn()->bIsFiringBlindlyLeft=false;
		GetPawn()->bIsFiringBlindlyRight=false;
		GetPawn()->ChangeAnimation();
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4))
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
		GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(2500)));
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	ChangeOrders(400);
	NPCLog("Found target, aiming and preparing to shoot");
	iRoundsFiredSinceCameOutOfCover=0;
	fpTimeSinceLastEnemySighting=0;
	if (! IsInState("FiringBlindly"))
	{
		if (iNPCCurrentOrders == 9)
		{
			fpTimeToEndSuppressionFire=((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 5));
		}
		else
		{
			fpTimeToEndSuppressionFire=((GetWorld()->GetTimeSeconds() + float(20)) + (FMath::FRand() * float(15)));
		}
	}
	UnslingWeapon();
	StopMovement();
	if ((pnCurrentPathNode != nullptr) && pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		NPCLog("in fire position, adjusting posture for firing");
		if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bShootWhileProne)
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
			if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bShootWhileCrouched)
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
				if (GetPawn()->bIsCrouched)
				{
					Stand();
					Sleep(1);
					(fpTimeToEndSuppressionFire += 1);
				}
				else
				{
					if (GetPawn()->bIsProne)
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
			if ((FMath::FRand() * 100) < fNPCLikesToCrouch)
			{
				Crouch();
			}
		}
	}
	TurnToAreaTarget();
	FinishRotation();
	if ((GetWorld()->GetTimeSeconds() > fpTimeToEndSuppressionFire) || (GetPawn()->Weapon == nullptr))
	{
		JL"CheckTimeLeft";
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
		JL"AimAtTarget";
	}
	JL"AimAtTarget";
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	NPCLog("Scanning for targets in suppression mode");
	sTargetingStatus="Suppressivefire scanning area";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		GetPawn()->RotationRate.Yaw=GetSearchRotationRate();
		DetermineFiringPositionFromDirection(true,rotator((vTargetToSuppressLocation - Pawn->GetActorLocation())));
		bRotateToDesired=true;
		FinishRotation();
		FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(rotator((vTargetToSuppressLocation - Pawn->GetActorLocation())))));
		bRotateToDesired=true;
		FinishRotation();
		DetermineFiringPositionFromDirection(false,rotator((vTargetToSuppressLocation - Pawn->GetActorLocation())));
		bRotateToDesired=true;
		FinishRotation();
		Sleep((FMath::FRand() * 1.5));
		FocalPoint=(GetPawn()->GetActorLocation() + (float(1024) *  Vector(rotator((vTargetToSuppressLocation - Pawn->GetActorLocation())))));
		bRotateToDesired=true;
		FinishRotation();
		GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	}
	else
	{
		GetPawn()->RotationRate.Yaw=GetSearchRotationRate();
		if (FMath::FRand() > 0.5)
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
		GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	}
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	Sleep(0);
	iRoundsFiredSinceCameOutOfCover=0;
	TurnToAreaTarget();
	FinishRotation();
	if ((GetWorld()->GetTimeSeconds() > fpTimeToEndSuppressionFire) || (GetPawn()->Weapon == nullptr))
	{
		JL"CheckTimeLeft";
	}
	if (! IsLocationInFront(vTargetToSuppressLocation))
	{
		sTargetingStatus="Suppressivefire - almost fired, now turning in aiming at taret";
		SaveTargetingStatusHistory(sTargetingStatus);
		Sleep(0.25);
		JL"AimAtTarget";
	}
	if (! IsInState("FiringBlindly"))
	{
		if (((Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileProne)) && Pawn.bIsProne)
		{
			Crouch();
			Sleep(0.5);
		}
		if (((Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr) && (! NPCFirePositionPathNode(pnCurrentLocation).bShootWhileCrouched)) && Pawn.bIsCrouched)
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
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Crouch();
			Sleep(0.75);
			Sleep(PlayCustomAnimation("CrhFwUpBlndFrStart"));
			GetPawn()->bIsFiringBlindlyOverHead=true;
			GetPawn()->ChangeAnimation();
		}
		else
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireLeft)
			{
				NPCLog("Enabling blind firing animation left");
				LookRight();
				FinishRotation();
				if (GetPawn()->bIsCrouched)
				{
					Sleep(PlayCustomAnimation("CrhLtBlndFrStart"));
				}
				else
				{
					Sleep(PlayCustomAnimation("StndLtBlndFrStart"));
				}
				GetPawn()->bIsFiringBlindlyLeft=true;
				GetPawn()->ChangeAnimation();
			}
			else
			{
				if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireRight)
				{
					NPCLog("Enabling blind firing animation right");
					LookLeft();
					FinishRotation();
					if (GetPawn()->bIsCrouched)
					{
						Sleep(PlayCustomAnimation("CrhRtBlndFrStart"));
					}
					else
					{
						Sleep(PlayCustomAnimation("StndRtBlndFrStart"));
					}
					GetPawn()->bIsFiringBlindlyRight=true;
					GetPawn()->ChangeAnimation();
				}
			}
		}
	}
	else
	{
		GetPawn()->ChangeAnimation();
		fpAimTime=((FMath::FRand() + 1.25) - ((fNPCExperience / 100) * 1.05));
		(fpAimTime += ((FMath::FRand() * 0.5) * (VSize((GetPawn()->GetActorLocation() - vTargetToSuppressLocation)) / float(5000))));
	}
	sTargetingStatus="Suppressivefire - shooting at target";
	SaveTargetingStatusHistory(sTargetingStatus);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount == 0))
	{
		NPCLog("Need to reload weapon");
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("WeaponJam");
		}
		AICCMessageReload();
		JL"End";
	}
	if ((GetWorld()->GetTimeSeconds() > fpTimeToEndSuppressionFire) || (GetPawn()->Weapon == nullptr))
	{
		sTargetingStatus="Suppressivefire - end of suppressive fire by time";
		SaveTargetingStatusHistory(sTargetingStatus);
		NPCLog("Suppression Time Ended");
		if (iNPCCurrentOrders == 9)
		{
			NPCChangeState("AssaultLocation");
			JL"End";
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
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
		}
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportActionComplete(this))
			{
				npcaiccCombatController.ProcessCombatAction(this);
			}
		}
		JL"End";
	}
	if (SafeToFire() || IsInState("FiringBlindly"))
	{
		sTargetingStatus="Suppressivefire - safe to fire";
		SaveTargetingStatusHistory(sTargetingStatus);
		if ((GetPawn()->Weapon != nullptr) && Cast<AAGP_Weapon>(GetPawn()->Weapon).IsJammed())
		{
			sTargetingStatus="Jammed!";
			SaveTargetingStatusHistory(sTargetingStatus);
			GetPawn()->Weapon.GotoState("BusyFixingJam");
			Cast<AAGP_Weapon>(GetPawn()->Weapon).bIsJammed=false;
			if (GetPawn()->Weapon.IsInState("BusyFixingJam"))
			{
				Sleep(0.1);
			}
		}
		if (! Pawn.Weapon.IsZoomed())
		{
			SaveTargetingStatusHistory("Forcing weapon into zoomed mode");
			Cast<AAGP_Weapon>(GetPawn()->Weapon).ServerZoom(true);
		}
		if (GetPawn()->Weapon.IsInState("BusyZooming"))
		{
			Sleep(0.1);
		}
		sTargetingStatus="Suppressivefire shooting weapon";
		SaveTargetingStatusHistory(sTargetingStatus);
		if (((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount >= 0))
		{
			FireWeapon();
		}
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr))
		{
			NPCLog("Just fired, current ammo count for weapon: " + FString::FromInt(GetPawn()->Weapon) + " is: " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount));
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
				NPCLog("InCover Min Rounds to duck: " + FString::FromInt(iMinRoundsToFireBeforeDucking) + " max: " + FString::FromInt(iMaxRoundsToFireBeforeDucking));
			}
			if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FMath::FRand() * float(iMaxRoundsToFireBeforeDucking))))
			{
				iRoundsFiredSinceCameOutOfCover=0;
				if (IsInState("FiringBlindly"))
				{
					GetPawn()->bIsFiringBlindlyLeft=false;
					GetPawn()->bIsFiringBlindlyRight=false;
					if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bIsFiringBlindlyOverHead)
					{
						Sleep(PlayCustomAnimation("CrhFwUpBlndFrEnd"));
						GetPawn()->ChangeAnimation();
					}
					else
					{
						if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireLeft)
						{
							if (GetPawn()->bIsCrouched)
							{
								Sleep(PlayCustomAnimation("CrhLtBlndFrEnd"));
							}
							else
							{
								Sleep(PlayCustomAnimation("StndLtBlndFrEnd"));
							}
							GetPawn()->ChangeAnimation();
							LookLeft();
							FinishRotation();
						}
						else
						{
							if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireRight)
							{
								if (GetPawn()->bIsCrouched)
								{
									Sleep(PlayCustomAnimation("CrhRtBlndFrEnd"));
								}
								else
								{
									Sleep(PlayCustomAnimation("StndRtBlndFrEnd"));
								}
								GetPawn()->ChangeAnimation();
								LookRight();
								FinishRotation();
							}
						}
					}
				}
				Cast<AAGP_Pawn>(GetPawn())->ResetLean();
				NPCLog("Going to ducking after firing " + FString::FromInt(iRoundsFiredSinceCameOutOfCover) + " rounds");
				if ((! Pawn.bIsCrouched) && (! Pawn.bIsProne))
				{
					if (IsInCover())
					{
						Crouch();
						Sleep((FMath::FRand() * 4));
						Stand();
					}
					else
					{
						Crouch();
						Sleep((FMath::FRand() * 2));
						Stand();
					}
				}
				JL"AimAtTarget";
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
						iMinRoundsToFireBeforeDucking=int((2 + (FMath::FRand() * 2)));
						iMaxRoundsToFireBeforeDucking=int((5 + (FMath::FRand() * 5)));
					}
					else
					{
						iMinRoundsToFireBeforeDucking=int((5 + (FMath::FRand() * 2)));
						iMaxRoundsToFireBeforeDucking=int((float(10) + (FMath::FRand() * 5)));
					}
				}
				NPCLog("InOpen Min Rounds to duck: " + FString::FromInt(iMinRoundsToFireBeforeDucking) + " max: " + FString::FromInt(iMaxRoundsToFireBeforeDucking));
			}
			if (float(iRoundsFiredSinceCameOutOfCover ++) > (float(iMinRoundsToFireBeforeDucking) + (FMath::FRand() * float(iMaxRoundsToFireBeforeDucking))))
			{
				iRoundsFiredSinceCameOutOfCover=0;
				Sleep(FClamp((FMath::FRand() + 0.4),0.4,0.9));
				JL"ShootTarget";
			}
		}
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.weaponType == 4))
		{
			NPCLog("Advanced Marksman weapon, must aim again after shot: " + FString::FromInt(GetPawn()->Weapon));
			JL"AimAtTarget";
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
		JL"End";
	}
	Sleep(0.15);
	JL"ShootTarget";
	if (IsInState("FiringBlindly"))
	{
		GetPawn()->bIsFiringBlindlyLeft=false;
		GetPawn()->bIsFiringBlindlyRight=false;
		if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bIsFiringBlindlyOverHead)
		{
			Sleep(PlayCustomAnimation("CrhFwUpBlndFrEnd"));
			GetPawn()->ChangeAnimation();
		}
		else
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireLeft)
			{
				if (GetPawn()->bIsCrouched)
				{
					Sleep(PlayCustomAnimation("CrhLtBlndFrEnd"));
				}
				else
				{
					Sleep(PlayCustomAnimation("StndLtBlndFrEnd"));
				}
				GetPawn()->ChangeAnimation();
				LookLeft();
				FinishRotation();
			}
			else
			{
				if (Cast<ANPCFirePositionPathNode>(pnCurrentLocation).bBlindFireRight)
				{
					if (GetPawn()->bIsCrouched)
					{
						Sleep(PlayCustomAnimation("CrhRtBlndFrEnd"));
					}
					else
					{
						Sleep(PlayCustomAnimation("StndRtBlndFrEnd"));
					}
					GetPawn()->ChangeAnimation();
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
	Function RequestSuppressiveFire(Vector vTargetArea)
	{
	}
	Function SuppressiveFireRequested(ANPCBaseSoldierController* npcbscRequestingFire, Vector vTargetArea)
	{
	}
	Function FlashBangEffectEnded()
	{
		Log(string(this) + "." + FString::FromInt(GetStateName()) + ".FlashBangEffectEnded()");
		if (IsInCover())
		{
			ChangeState("SearchForTarget");
		}
		else
		{
			ChangeState("FindCoverThenFight");
		}
	}
	Function float PrepForFlashing()
	{
		if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
		{
			GetPawn()->Weapon.Velocity=(Velocity * 1.15);
			GetPawn()->Weapon.DropFrom(GetPawn()->GetBoneCoords("WeaponBone").Origin);
			GetPawn()->Weapon=nullptr;
			UnslingWeapon();
			return 1;
		}
	}
	Function NPCFlashedAudioYell()
	{
		if (npcaiccCombatController != nullptr)
		{
			npcaiccCombatController.PlayEventAudio(this,"Warning");
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
	Function bool UsedBy(APawn* User)
	{
		if (bInCustody)
		{
			Cast<AHumanController>(User.Controller).ClientMessage("This soldier has already been taken into custody");
			return true;
		}
		if (GetPawn()->bIsProne)
		{
			PlayCustomAnimation("PrnKillMiles");
		}
		else
		{
			if (GetPawn()->bIsCrouched)
			{
				PlayCustomAnimation("CrhKillMiles");
			}
			else
			{
				PlayCustomAnimation("StdKillMilesB");
			}
		}
		Cast<AHumanController>(User.Controller).ClientMessage("You have taken this soldier into custody");
		bInCustody=true;
		GetPawn()->HUDText="Enemy Soldier In Custody";
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
		if ((GetWorld()->GetTimeSeconds() > fpTimeToEndCowering) && (GetConfidenceLevel() > float(-40)))
		{
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportActionComplete(this))
				{
					npcaiccCombatController.ProcessCombatAction(this);
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
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
		JL"End";
	}
	Walk();
	Prone();
	if (true)
	{
		if (GetPawn() == nullptr)
		{
			JL"PawnDeadEnd";
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
	NPCLog("Changing to cover state of: " + FString::FromInt(GetCoverState()));
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
			if (FMath::FRand() > 0.5)
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
			npcaiccCombatController.PlayEventAudio(this,"Taunt");
		}
	}
Begin:
	Sleep(0);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	PlayTauntAudio();
	Sleep(PlayTauntAnimation());
	if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
	{
		Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("ActionComplete");
	}
	if (npcaiccCombatController != nullptr)
	{
		NPCChangeState(GetLastStateName());
		if (npcaiccCombatController.ReportActionComplete(this))
		{
			npcaiccCombatController.ProcessCombatAction(this);
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
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	NPCLog("RushEnemy Entered for " + FString::FromInt(Enemy));
	Stand();
	Run();
	if (true)
	{
		if (GetPawn() == nullptr)
		{
			JL"PawnDeadEnd";
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(Enemy));
		if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && ((VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)) || (pnCurrentNodeOnPathToCover == nullptr)))
		{
			NPCLog("CQB Range to target, engaging");
			UpdatePathNodeBonuses(Cast<ANPCPathNode>(pnCurrentNodeOnPathToCover));
			if (npcaiccCombatController != nullptr)
			{
				if (npcaiccCombatController.ReportContact(this,npcaiccCombatController.0,Enemy,int(EvaluateEnemyThreat(Enemy))))
				{
					npcaiccCombatController.ProcessCombatAction(this);
				}
			}
			NPCChangeState("Targeting");
			JL"End";
		}
		if (pnCurrentNodeOnPathToCover == nullptr)
		{
			NPCLog("Unable to find path towards target");
			NPCChangeState("FindCoverThenFight");
			JL"End";
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover->IsA(ANPCDoorEntryPathNode::StaticClass()))
		{
			if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)).bClosed)
			{
				StopMovement();
				Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
				if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
					{
						Sleep(mLastDoorOpened.MoveTime);
						NPCLog("Door done moving (probably): " + FString::FromInt(mLastDoorOpened));
					}
				}
				GetPawn()->UpperBodyAnimComplete();
				Run();
			}
		}
		else
		{
			if (pnCurrentNodeOnPathToCover->IsA(ANPCLadderPathNode::StaticClass()))
			{
				if (Cast<ANPCLadderPathNode>(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
					{
						StopMovement();
						lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
						Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
						Sleep(0.25);
					}
				}
				else
				{
					if (Cast<ANPCLadderPathNode>(pnCurrentNodeOnPathToCover).bNearLadderBase)
					{
						if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
						{
							Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
						}
						else
						{
							lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
							Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
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
	Function NotifyAnotherPawnDied(ANPCBaseController* npcpc)
	{
	}
	Function NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (LineOfSightTo(aShooter) && (VSize((aShooter->GetActorLocation() - Pawn->GetActorLocation())) < float(1000)))
		{
			if ((Cast<AAGP_Pawn>(aShooter) != nullptr) && Cast<AAGP_Pawn>(aShooter).IsHumanControlled())
			{
				Enemy=Pawn(aShooter);
				NPCChangeState("FindCoverThenFight");
			}
		}
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (VSize((vSoundLocation - Pawn->GetActorLocation())) < float(500))
		{
			Global.iSound(fpLoudness,agpwWeaponHeard,vSoundLocation);
		}
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
		if (VSize((pawnHeard->GetActorLocation() - Pawn->GetActorLocation())) < float(500))
		{
			Global.agpobj(fpLoudness,pawnHeard);
		}
	}
	Event bool NotifyBump(AActor* Other)
	{
		if ((Other != nullptr) && (! Other->IsA(APawn::StaticClass())))
		{
			return true;
		}
		if ((Cast<APawn>(Other).Controller != nullptr) && Pawn(Other).Controller->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			if (((! Pawn(Other).Controller.IsInState("Targeting")) && (! Pawn(Other).Controller.IsInState("HeadToTravelLocation"))) && (! Pawn(Other).Controller.IsInState("ExitVehicleWaitForMoveOrder")))
			{
				Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller).npcpnTravelLocation=npcpnTravelLocation;
				Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller).fpHeadToLocationStartDelay=(0.75 + FMath::FRand());
				Cast<ANPCBaseSoldierController>(Cast<APawn>(Other).Controller).NPCChangeState("HeadToTravelLocation");
			}
			NPCBaseController(Cast<APawn>(Other).Controller).GotoState("MoveBackAfterBump");
		}
		else
		{
			if ((Cast<APawn>(Other).Controller != nullptr) && Pawn(Other).Controller->IsA(AHumanController::StaticClass()))
			{
				Enemy=Pawn(Other);
				NPCChangeState("Targeting","TurnToEnemy");
			}
		}
		return true;
	}
	Event WeaponCollision(AActor* actorColliding)
	{
		if (actorColliding == nullptr)
		{
			return;
		}
		if (actorColliding->IsA(AMover::StaticClass()) && (! Cast<AMover>(actorColliding).bNotADoor))
		{
			if (Cast<AMover>(actorColliding).bInterpolating)
			{
				return;
			}
			OpenDoorFromHere(Pawn->GetActorLocation(),Mover(actorColliding));
			NPCChangeState(GetStateName(),"PauseAfterBumpOnWayToPath");
		}
		if (actorColliding != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
		}
		else
		{
			GetPawn()->UpperBodyAnimComplete();
		}
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (LineOfSightTo(pawnSeen) && (VSize((GetPawn()->GetActorLocation() - pawnSeen->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
		{
			Enemy=pawnSeen;
			NPCChangeState("Targeting","TurnToEnemy");
		}
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall->IsA(AMover::StaticClass()))
		{
			if (Cast<AMover>(Wall).bNotADoor)
			{
				NPCPathLog(string(this) + "." + FString::FromInt(Tag) + " hit a non-door mover: " + FString::FromInt(Wall) + " Normal: " + FString::FromInt(HitNormal) + " at location " + FString::FromInt(Pawn->GetActorLocation()));
				return false;
			}
			else
			{
				if (Cast<AMover>(Wall).bInterpolating)
				{
					return false;
				}
				OpenDoorFromHere(Pawn->GetActorLocation(),Mover(Wall));
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
		fpChanceOfFindingCover=FMath::FRand();
		switch(iHeadToLocationCoverOption)
		{
			case 0:
			if (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) <= float(2500))
			{
				return true;
			}
			return false;
			case 1:
			if (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) <= float(2000))
			{
				return true;
			}
			return false;
			case 2:
			if (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) <= float(1500))
			{
				return true;
			}
			return false;
			case 3:
			if (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) <= float(1000))
			{
				return true;
			}
			return false;
			case 4:
			if (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) <= float(500))
			{
				return true;
			}
			return false;
			case 5:
			if ((iHeadToLocationCoverOption == 5) && (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) < float(500)))
			{
				return true;
			}
			return false;
			default:
			if ((iHeadToLocationCoverOption == 5) && (VSize((GetPawn()->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) < float(500)))
			{
				return true;
			}
			return false;
			return false;
		}
	}
Begin:
	NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation entered");
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd";
	}
	if (npcpnTravelLocation == nullptr)
	{
		NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation - Unable to find path towards target");
		if (GetLastStateName() == "WalkingPatrol")
		{
			NPCChangeState("ReturnToPatrol");
		}
		else
		{
			NPCChangeState("FindCoverThenFight");
		}
		JL"End";
	}
	if ((VSize((npcpnTravelLocation->GetActorLocation() - Pawn->GetActorLocation())) < float(500)) && LineOfSightTo(npcpnTravelLocation))
	{
		NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation - Close enough already");
		GetPawn()->RotationRate.Yaw=int((fpTurnRate + float(2000)));
		Focus=nullptr;
		FocalPoint=npcpnTravelLocation->GetActorLocation();
		bRotateToDesired=true;
		FinishRotation();
		NPCChangeState("SearchForTargets");
		JL"End";
	}
	NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation - Sleeping for " + FString::FromInt(fpHeadToLocationStartDelay));
	Sleep(fpHeadToLocationStartDelay);
	NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation entered for " + FString::FromInt(vTravelLocation));
	Stand();
	Run();
	JL"GotoTravelLocation";
	Sleep(1.5);
	if (true)
	{
		if (GetPawn() == nullptr)
		{
			NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation - No pawn, aborting");
			JL"PawnDeadEnd";
		}
		pnCurrentNodeOnPathToCover=NPCPathNode(FindPathToward(npcpnTravelLocation,true));
		NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation - node on way to travel location: " + FString::FromInt(npcpnTravelLocation) + " via " + FString::FromInt(pnCurrentNodeOnPathToCover));
		if (bDebugPath)
		{
			DebugDumpRoute();
		}
		if (pnCurrentNodeOnPathToCover == nullptr)
		{
			NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation unable to find path towards target for travel location");
			if (GetLastStateName() == "WalkingPatrol")
			{
				NPCChangeState("ReturnToPatrol");
			}
			else
			{
				NPCChangeState("FindCoverThenFight");
			}
			JL"End";
		}
		if ((((pnCurrentNodeOnPathToCover == npcpnTravelLocation) && npcpnTravelLocation->IsA(ANPCCoverPositionPathNode::StaticClass())) && (npcpnTravelLocation.cControllerUsingNode != nullptr)) && (npcpnTravelLocation.cControllerUsingNode != Self))
		{
			NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation last node filled");
			NPCChangeState("FindCoverThenFight");
			JL"End";
		}
		MoveToward(pnCurrentNodeOnPathToCover,pnCurrentNodeOnPathToCover,,false,false);
		if (pnCurrentNodeOnPathToCover->IsA(ANPCDoorEntryPathNode::StaticClass()))
		{
			if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)).bClosed)
			{
				Cast<AAGP_Pawn>(GetPawn())->GuardWeapon3p(6);
				StopMovement();
				if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnCurrentNodeOnPathToCover)))
				{
					Sleep(0.1);
					if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
					{
						Sleep(mLastDoorOpened.MoveTime);
						NPCLog("Door done moving (probably): " + FString::FromInt(mLastDoorOpened));
					}
				}
				GetPawn()->UpperBodyAnimComplete();
			}
		}
		else
		{
			if (pnCurrentNodeOnPathToCover->IsA(ANPCLadderPathNode::StaticClass()))
			{
				if (Cast<ANPCLadderPathNode>(pnCurrentNodeOnPathToCover).bNearLadderTop)
				{
					if (! ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
					{
						StopMovement();
						lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
						Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
						Sleep(0.25);
					}
				}
				else
				{
					if (Cast<ANPCLadderPathNode>(pnCurrentNodeOnPathToCover).bNearLadderBase)
					{
						if ((GetPawn()->PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
						{
							Cast<AAGP_Pawn>(GetPawn())->EndClimbLadder(nullptr);
						}
						else
						{
							lvLadderEntry=GetNearbyLadderVolume(pnCurrentNodeOnPathToCover);
							Cast<AAGP_Pawn>(GetPawn())->ClimbLadder(lvLadderEntry);
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
				if (FMath::FRand() > 0.5)
				{
					NPCChangeState("FindCoverThenFight");
				}
				else
				{
					NPCChangeState("MoveToNewFiringPosition");
				}
			}
			JL"End";
		}
		else
		{
			if (ShouldFindCoverNow())
			{
				NPCChangeState("FindCoverThenFight");
				JL"End";
			}
		}
	}
	NPCPathLog(string(this) + "." + FString::FromInt(Tag) + ".HeadToTravelLocation finished trying to move - which we should never get here");
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
			if (GetPawn()->Weapon != nullptr)
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
	if (GetPawn() == nullptr)
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
			npcaiccCombatController.PlayEventAudio(this,"Attacking");
		}
		npcpnTravelLocation=FindHeadToObjective();
		SignalSoldiersShouldMoveOut(0,0);
	}
	Run();
	HeadToObjective(float((Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers.Num() + 4)));
}
*/

/*
State ExitVehicleNow
{
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function Touch(AActor* Other)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		return false;
	}
	Event bool NotifyBump(AActor* Other)
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
				fpAngleMultiplier=FMath::FRand();
			}
		}
		return fpAngleMultiplier;
	}
Begin:
	Sleep(0);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	if (vVehicleCarryingNPC.Health <= 0)
	{
		GetPawn()->KilledBy(nullptr);
		JL"None"
;
	}
	ChangeState("ExitVehicleWaitForMoveOrder");
}
*/

/*
State ExitVehicleWaitForMoveOrder
{
Begin:
	Sleep(0);
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Run();
	MoveTo((GetPawn()->GetActorLocation() + (((FMath::FRand() * float(200)) + float(650)) *  Vector((Normalize(Rotation) * fpExitingVehicleDepartureAngle)))),nullptr,false);
	StopMovement();
	if (iNPCCurrentOrders == 9)
	{
		SetCustomTimer(((FMath::FRand() * 5) + 5),false,"ReturnToAssault");
		LocateAssaultLocation();
		FocalPoint=vAssaultLocation;
		bRotateToDesired=true;
		FinishRotation();
	}
	Crouch();
	if (GetPawn() == nullptr)
	{
		JL"PawnDeadEnd"
;
	}
	Sleep(0);
	NPCLog("Searching from " + FString::FromInt(pnCurrentLocation));
	GetPawn()->RotationRate.Yaw=GetSearchRotationRate();
	if (FMath::FRand() > 0.5)
	{
		LookLeft();
		FinishRotation();
		Sleep((1 + FMath::FRand()));
		LookRight();
		FinishRotation();
		Sleep((1 + FMath::FRand()));
	}
	else
	{
		LookRight();
		FinishRotation();
		Sleep((1 + FMath::FRand()));
		LookLeft();
		FinishRotation();
		Sleep((1 + FMath::FRand()));
	}
	GetPawn()->RotationRate.Yaw=int(fpTurnRate);
	JL"LookAround"
;
}
*/

/*
State SwapWeapons
{
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
Begin:
	Sleep(0);
	sTargetingStatus="Swap hands start";
	SaveTargetingStatusHistory(sTargetingStatus);
	if ((GetPawn()->Weapon == agpwPrimary) && (agpwSecondary == nullptr))
	{
		JL"End"
;
	}
	if ((GetPawn()->Weapon == agpwSecondary) && (agpwPrimary == nullptr))
	{
		JL"End"
;
	}
	if (GetPawn()->Weapon == agpwPrimary)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHands();
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
		if (GetPawn()->Weapon == agpwSecondary)
		{
			Cast<AAGP_Pawn>(GetPawn())->SwapHands();
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
		fpTimeEnteredCover=GetWorld()->GetTimeSeconds();
		fpTargetingStartTime=GetWorld()->GetTimeSeconds();
		iRoundsFiredSinceCameOutOfCover=0;
		NPCChangeState("Targeting","ShootTarget");
	}
	else
	{
		NPCChangeState(GetLastStateName());
	}
}
*/

static const int32 MAX_TARGET_STATUS_HISTORY = 10;
static const int32 NPCS_TO_TRACK = 10;
static const int32 BOP_MAJOR_ADVANTAGE = 0;
static const int32 BOP_MINOR_ADVANTAGE = 1;
static const int32 BOP_NO_ADVANTAGE = 2;
static const int32 BOP_MINOR_DISADVANTAGE = 3;
static const int32 BOP_MAJOR_DISADVANTAGE = 4;

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
		t = t + " DELETED (bDeleteMe == true)";
	}
	Canvas.DrawText(t, false);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetDrawColor(255, 255, 0);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText(string(this) + "." + FString::FromInt(Tag) + ", NavTag: " + sNPCWaypointTag + "  upper body anim: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->UpperBodyAnim) + " Last AICC: " + sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last AICC: " + sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("State: \"" + FString::FromInt(GetStateName()) + "\" Last State Change: " + sLastAttemptedStateChange + " Last AICC: " + sLastAICCMessage);
	if (GetPawn() != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Ground Speed: " + FString::FromInt(GetPawn()->GroundSpeed) + " run speed: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->fRunSpeed) + " Penalty: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->fSpeedPenalty) + " AdvancedTactics: " + FString::FromInt(bAdvancedTactics) + "  Shoot from hip: " + FString::FromInt(GetPawn()->bIsHipShooting) + " BlindFire L/R: " + FString::FromInt(GetPawn()->bIsFiringBlindlyLeft) + "," + FString::FromInt(GetPawn()->bIsFiringBlindlyRight));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Iswalking: " + FString::FromInt(GetPawn()->bIsWalking) + " Crouched: " + FString::FromInt(GetPawn()->bIsCrouched) + "  Sprint: " + FString::FromInt(GetPawn()->bIsSprinting) + " Wants sprint: " + FString::FromInt(GetPawn()->bWantsToSprint) + " Is prone: " + FString::FromInt(GetPawn()->bIsProne));
	}
	if (Enemy != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		if (fpTimeSinceUntilTargetLost > 0)
		{
			Canvas.DrawText("Current target: " + FString::FromInt(Enemy) + ", contact out of sight, considered lost in: " + FString::FromInt((fpTimeSinceUntilTargetLost - GetWorld()->GetTimeSeconds())) + " distance: " + FString::FromInt(VSize((Enemy->GetActorLocation() - Pawn->GetActorLocation()))));
		}
		else
		{
			Canvas.DrawText("Current target: " + FString::FromInt(Enemy) + " distance: " + FString::FromInt(VSize((Enemy->GetActorLocation() - Pawn->GetActorLocation()))) + "         Angle: " + FString::FromInt(GetAngleToLocation(Enemy->GetActorLocation())));
		}
	}
	Canvas.SetDrawColor(255, 0, 255);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Target status: " + sTargetingStatus);
	Canvas.SetDrawColor(255, 0, 200);
	for (iStatusHistory = 0; iStatusHistory < 10; iStatusHistory++)
	{
		if (Len(asTargetingStatus[iStatusHistory]) > 0)
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("TS History: " + asTargetingStatus[iStatusHistory]);
		}
	}
	Canvas.SetDrawColor(255, 255, 0);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Confidence: " + FString::FromInt(GetConfidenceLevel()) + "  Current focus: " + FString::FromInt(Focus) + "  Last APawn* seen: " + FString::FromInt(pawnDebugLastSeenPawn));
	if (IsInState("FiringBlindly"))
	{
		Canvas.SetDrawColor(255, 128, 255);
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Blind fire ends in: " + FString::FromInt((fpTimeToEndSuppressionFire - GetWorld()->GetTimeSeconds())) + "  Rounds since out of cover: " + FString::FromInt(iRoundsFiredSinceCameOutOfCover));
		Canvas.SetDrawColor(255, 255, 0);
	}
	else
	{
		if (IsInState("ProvidingSuppressiveFire"))
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("Suppression Fire Ending in : " + FString::FromInt((fpTimeToEndSuppressionFire - GetWorld()->GetTimeSeconds())) + "   Rounds since out of cover: " + FString::FromInt(iRoundsFiredSinceCameOutOfCover));
		}
	}
	if (GetPawn() != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("RPGs Left: " + FString::FromInt(iRPGCount) + " Frag Grenades: " + FString::FromInt(Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.0]));
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr))
		{
			YPos += YL;
			Canvas.SetPos(4, YPos);
			Canvas.DrawText("Ammo type: " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType()) + ", left for " + FString::FromInt(GetPawn()->Weapon) + ": " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount));
		}
	}
	if (IsInState("FlashBanged"))
	{
		fpVisionCone = (GetMaxVisionCone() - ((GetMaxVisionCone() * ((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds()) / fpFlashBangDuration)) * fpFlashBangedVisualIntensity));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Flashbang duration: " + FString::FromInt(fpFlashBangDuration) + ", Time Left: " + FString::FromInt((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds())) + ", Intensity: " + FString::FromInt(fpFlashBangedVisualIntensity));
	}
	else
	{
		fpVisionCone = GetMaxVisionCone();
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " + FString::FromInt(GetPawn()->Health));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Vision Cone: " + FString::FromInt(fpVisionCone));
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCCamperFirePositionPathNode::StaticClass()))
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Vision Range: " + FString::FromInt(fpNPCMaxVisualRange) + "  Camper node ambush range: " + FString::FromInt(Cast<ANPCCamperFirePositionPathNode>(pnCurrentLocation).fpAmbushRange) + "  Vision range modified: " + FString::FromInt((Cast<ANPCCamperFirePositionPathNode>(pnCurrentLocation).fpVisionRangeModifier * fpNPCMaxVisualRange)));
	}
	else
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Vision Range: " + FString::FromInt(fpNPCMaxVisualRange));
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Sound Heard: " + FString::FromInt(aLastActorHeard));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("WeaponRange: " + FString::FromInt(fpNPCWeaponEffectiveRange) + " CQB Range: " + FString::FromInt((fpNPCWeaponEffectiveRange / 4)));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Eval Target Dist: " + FString::FromInt(fpDistanceToLastEvaluatedTarget) + "  Skill: " + FString::FromInt(fpNPCWeaponAccuracy));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Shot Acc: " + FString::FromInt(fpLastShotAccuracy) + ", Last Shot Aim Time: " + FString::FromInt(fpAimTime) + ", distance from target: " + FString::FromInt(fpLastShotDistanceFromTarget));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Leaving fire/cover position in: " + FString::FromInt((fpTimeToLeaveFiringPosition - GetWorld()->GetTimeSeconds())) + " (Last FPPN: " + FString::FromInt(npcfppnLastFirePosition) + ")   Rounds fired (primary):" + FString::FromInt(iTotalRoundsFiredAtAmbushLocation));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current path node location: " + FString::FromInt(pnCurrentLocation));
	if (IsInState("Cowering"))
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Cowering Ending in : " + FString::FromInt((fpTimeToEndCowering - GetWorld()->GetTimeSeconds())));
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
		Canvas.DrawText("Contact: " + FString::FromInt(arcContactHistory[iContactIndex].pawnContact) + " Closure Rate: " + FString::FromInt(arcContactHistory[iContactIndex].fpClosureRate) + ", Lost Contact: " + FString::FromInt(arcContactHistory[iContactIndex].bContactLost) + ", Threat: " + FString::FromInt(arcContactHistory[iContactIndex].fpThreatLevel) + ", Age: " + FString::FromInt((GetWorld()->GetTimeSeconds() - arcContactHistory[iContactIndex].fpTimeSeen)) + ", Range: " + FString::FromInt(VSize((GetPawn()->GetActorLocation() - arcContactHistory[iContactIndex].pawnContact->GetActorLocation()))));
	}
	Canvas.SetDrawColor(255, 255, 128);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (npcaiccCombatController != nullptr)
	{
		Canvas.DrawText("Current order: " + GetVerboseOrders(iNPCCurrentOrders) + "  Last Combat Action: " + sLastCombatAction + " Last Event Processed: " + npcaiccCombatController.asEvents[iLastInterruptEventPriority] + " Last Interrupt: " + npcaiccCombatController.asEvents[iLastInterrupt] + " Time before action ends: " + FString::FromInt((GetWorld()->GetTimeSeconds() - fpTimeToEndLastInterrupt)));
	}
	else
	{
		Canvas.DrawText("Current order: " + GetVerboseOrders(iNPCCurrentOrders));
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
		Canvas.DrawText("Current node: " + FString::FromInt(pnCurrentPathNode) + " (tag: " + FString::FromInt(pnCurrentPathNode.Tag) + ")");
	}
	else
	{
		Canvas.DrawText("Current node: AI In The Open");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Balance of Power: " + GetVerboseBalanceOfPower(iBalanceOfPowerState));
	for (iNode = 0; iNode < 62; iNode++)
	{
		if (RouteCache[iNode] == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("RouteCache[ " + FString::FromInt(iNode) + "] " + FString::FromInt(RouteCache[iNode].Location.X) + ", " + FString::FromInt(RouteCache[iNode].Location.Y) + ", " + FString::FromInt(RouteCache[iNode].Location.Z));
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
	Canvas.DrawText(string(this) + "." + FString::FromInt(Tag) + " in state: " + FString::FromInt(GetStateName()) + " last attempted state change: " + sLastAttemptedStateChange + " Last AICC: " + sLastAICCMessage);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current target: " + FString::FromInt(Enemy) + " confidence: " + FString::FromInt(GetConfidenceLevel()) + " Last Seen pawn: " + FString::FromInt(pawnDebugLastSeenPawn) + " RPGs Left: " + FString::FromInt(iRPGCount));
	if (IsInState("FlashBanged"))
	{
		fpVisionCone = (GetMaxVisionCone() - ((GetMaxVisionCone() * ((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds()) / fpFlashBangDuration)) * fpFlashBangedVisualIntensity));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Flashbang duration: " + FString::FromInt(fpFlashBangDuration) + ", Time Left: " + FString::FromInt((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds())) + ", Intensity: " + FString::FromInt(fpFlashBangedVisualIntensity));
	}
	else
	{
		fpVisionCone = GetMaxVisionCone();
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " + FString::FromInt(GetPawn()->Health) + " Vision cone: " + FString::FromInt(fpVisionCone) + ", Vision Range: " + FString::FromInt(fpNPCMaxVisualRange) + ", Last sound: " + FString::FromInt(aLastActorHeard) + " Wpn rng: " + FString::FromInt(fpNPCWeaponEffectiveRange) + " Eval Tgt Dist: " + FString::FromInt(fpDistanceToLastEvaluatedTarget));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last shot acc: " + FString::FromInt(fpLastShotAccuracy) + ", Last Shot Aim Time: " + FString::FromInt(fpAimTime));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr))
	{
		Canvas.DrawText("Primary reloads: " + FString::FromInt(iPrimaryWeaponReloads) + ", current clip: " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount));
	}
	else
	{
		Canvas.DrawText("OUT OF AMMO!");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Leaving fire/cover position in: " + FString::FromInt((fpTimeToLeaveFiringPosition - GetWorld()->GetTimeSeconds())) + " (Last FPPN: " + FString::FromInt(npcfppnLastFirePosition) + ")   Rounds fired (primary):" + FString::FromInt(iTotalRoundsFiredAtAmbushLocation));
	Canvas.SetDrawColor(255, 128, 255);
	for (iContactIndex = 0; iContactIndex < 20; iContactIndex++)
	{
		if (arcContactHistory[iContactIndex].pawnContact == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(50, YPos);
		Canvas.DrawText("Contact: " + FString::FromInt(arcContactHistory[iContactIndex].pawnContact) + " Closure Rate: " + FString::FromInt(arcContactHistory[iContactIndex].fpClosureRate) + ", Lost Contact: " + FString::FromInt(arcContactHistory[iContactIndex].bContactLost) + ", Threat: " + FString::FromInt(arcContactHistory[iContactIndex].fpThreatLevel) + ", Age: " + FString::FromInt((GetWorld()->GetTimeSeconds() - arcContactHistory[iContactIndex].fpTimeSeen)) + ", Range: " + FString::FromInt(VSize((GetPawn()->GetActorLocation() - arcContactHistory[iContactIndex].pawnContact->GetActorLocation()))));
	}
	Canvas.SetDrawColor(0, 128, 255);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current order: " + GetVerboseOrders(iNPCCurrentOrders));
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
	if (GetPawn() != nullptr)
	{
		if (bDebugMode)
		{
			//NPCPrivateLog(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(Tag) + "." + FString::FromInt(GetStateName()) + " (Order: " + GetVerboseOrders(iNPCCurrentOrders) + ") - " + FString::FromInt(GetPawn()->Name) + " " + sLogText);
		}
	}
	else
	{
		//NPCPrivateLog(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(Tag) + "." + FString::FromInt(GetStateName()) + " (Order: " + GetVerboseOrders(iNPCCurrentOrders) + ") - " + sLogText);
	}
}

void ANPCBaseSoldierController::PreloadPathNodeList()
{
	FastPreloadDuckAndCoverNodes();
	Super::PreloadPathNodeList();
}

void ANPCBaseSoldierController::InitializePawn()
{
	Super::InitializePawn();
	InitializeWeapons();
}

void ANPCBaseSoldierController::InitializeWeapons()
{
	int32 iClip = 0;
	int32 iInvItem = 0;
	AActor* Item = nullptr;
	/*
	GetPawn()->bCanJump = false;
	if (iRPGCount == 0)
	{
		for (iInvItem = 0; iInvItem < iFragGrenadeCount; iInvItem++)
		{
			GetPawn()->CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M67_Frag", Class'Class')));
			GetPawn()->_InvGrenades[Pawn.0] ++;
		}
		for (iInvItem = 0; iInvItem < iFlashGrenadeCount; iInvItem++)
		{
			GetPawn()->CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun", Class'Class')));
			GetPawn()->_InvGrenades[Pawn.2] ++;
		}
	}
	for (iInvItem = 0; iInvItem < iSmokeGrenadeCount; iInvItem++)
	{
		GetPawn()->CreateVirtualInventory(class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke", Class'Class')));
		GetPawn()->_InvGrenades[Pawn.1] ++;
	}
	if (namePrimaryWeapon != nullptr)
	{
		if (GetPawn()->FindInventoryType(namePrimaryWeapon) == nullptr)
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
				agpwPrimary.GiveTo(GetPawn());
				agpwPrimary.PickupFunction(GetPawn());
				GetPawn()->Weapon = agpwPrimary;
				agpwPrimary.bGuerrillaWeapon = true;
				NPCLog("Pawn " + FString::FromInt(GetPawn()) + " now has weapon " + FString::FromInt(GetPawn()->Weapon));
			}
		}
	}
	if (nameSecondaryWeapon != nullptr)
	{
		if (GetPawn()->FindInventoryType(nameSecondaryWeapon) == nullptr)
		{
			agpwSecondary = Spawn(nameSecondaryWeapon);
			if (agpwSecondary != nullptr)
			{
				NPCLog("Pawn's secondary weapon is " + FString::FromInt(agpwSecondary));
				if (agpwSecondary->IsA(APistolWeapon::StaticClass()))
				{
					agpwSecondary.bAlreadyLoadedMods = true;
					agpwSecondary._cScopeClass = nullptr;
					agpwSecondary.GiveTo(GetPawn());
					agpwSecondary.PickupFunction(GetPawn());
				}
				else
				{
					agpwSecondary.bAlreadyLoadedMods = true;
					agpwSecondary._cScopeClass = nullptr;
					agpwSecondary.GiveTo(GetPawn());
					agpwSecondary.PickupFunction(GetPawn());
				}
				agpwSecondary.bGuerrillaWeapon = true;
			}
		}
	}
	if (iRPGCount > 0)
	{
		for (iInvItem = 0; iInvItem < 1; iInvItem++)
		{
			NPCLog("Trying to create RPG: " + FString::FromInt(iInvItem) + " using class \"AGP_Inventory.Ammo_RPG7_PG7B\"");
			Item = Cast<AAGP_Pawn>(GetPawn())->CreateInventoryFromName("AGP_Inventory.Ammo_RPG7_PG7B", true);
		}
	}
	for (iClip = 0; iClip < iPrimaryWeaponReloads; iClip++)
	{
		aiPrimaryAmmoClips.insert(0, 1);
		if (Cast<AAGP_Pawn>(GetPawn())->getHandsInventory() != nullptr)
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
		Cast<AAGP_Pawn>(GetPawn())->CreateInventoryFromName("AGP_Inventory.Item_BinocM22_A", true);
	}
	Cast<AAGP_Pawn>(GetPawn())->_InvHolster = nullptr;
	Cast<AAGP_Pawn>(GetPawn())->_InvHip = nullptr;
	Cast<AAGP_Pawn>(GetPawn())->_InvAltShoulder = nullptr;
	if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.weaponType == 4)) && (GetPawn()->SightRadius < float(66000)))
	{
		GetPawn()->SightRadius = 66000;
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
	if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCCoverPositionPathNode::StaticClass()))
	{
		pnCurrentLocation.ExtraCost = pnCurrentLocation.Default.ExtraCost;
	}
	Super::UpdatePathNodeBonuses(npcpn);
	if (Cast<ANPCCoverPositionPathNode>(npcpn) != nullptr)
	{
		npcpn.ExtraCost = 99999;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->VisionDistActor == nullptr)
	{
		return;
	}
	fpAdjustedVisionCone = fpNPCVisionConeAngle;
	fpAdjustedVisualRange = fpNPCMaxVisualRange;
	if (npcpn != nullptr)
	{
		if (npcpn->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			if (npcpn->IsA(ANPCCamperFirePositionPathNode::StaticClass()))
			{
				fpAdjustedVisualRange = Cast<ANPCCamperFirePositionPathNode>(npcpn).fpAmbushRange;
			}
			else
			{
				(fpAdjustedVisualRange *= NPCFirePositionPathNode(npcpn).fpVisionRangeModifier);
			}
			fpAdjustedVisionCone = NPCFirePositionPathNode(npcpn).fpVisionConeAngle;
		}
	}
	fpVisionScale = (Sin(((((fpAdjustedVisionCone / 2) / float(65536)) * 2) * 3.1214)) * fpAdjustedVisualRange);
	Cast<AAGP_Pawn>(GetPawn())->VisionDistActor.SetDrawScale3D(FVector(fpVisionScale, fpNPCMaxVisualRange, fpVisionScale));
	*/
}

int32 ANPCBaseSoldierController::GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus)
{
	return 0;
}

void ANPCBaseSoldierController::CalculateLeadershipBonus()
{
	fpCurrentLeadershipBonus = 0;
	if (npcaiccCombatController != nullptr)
	{
		(fpCurrentLeadershipBonus += npcaiccCombatController->GetLeadershipBonus(this));
	}
}

float ANPCBaseSoldierController::GetConfidenceLevel()
{
	int32 iCalculatedConfidence = 0;
	iCalculatedConfidence = int(((fpConfidence + fpNodeMentalStateBonus) + fpCurrentLeadershipBonus));
	return float(iCalculatedConfidence);
}

void ANPCBaseSoldierController::AdjustStateByConfidenceLevel()
{
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
				NPCChangeState("Cowering","");
			}
		}
	}
}

void ANPCBaseSoldierController::SetConfidenceLevel(float fpNewConfidence)
{
	if (npcaiccCombatController != nullptr)
	{
		if ((((((((!IsSuppressed()) && (fpNewConfidence <= float(-40))) && (fpNewConfidence > float(-60))) || (((!IsInPanic()) && (fpNewConfidence < float(-60))) && (fpNewConfidence > float(-90)))) || (((!IsBrave()) && (fpNewConfidence >= float(70))) && (fpNewConfidence < float(90)))) || ((!IsReckless()) && (fpNewConfidence >= float(90)))) || (((!IsConcerned()) && (fpNewConfidence >= float(-40))) && (fpNewConfidence < float(-10)))) || (((!IsNormal()) && (fpNewConfidence >= float(-10))) && (fpNewConfidence < float(70))))
		{
			npcaiccCombatController->ReportMentalStateChange(this);
		}
	}
	Super::SetConfidenceLevel(fpNewConfidence);
	if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_MentalStateIcon != nullptr))
	{
		Cast<AAGP_Pawn>(GetPawn())->MyDebug_MentalStateIcon->UpdateMentalState(this);
	}
}

void ANPCBaseSoldierController::NPCChangeState(FName nmState, FName nmLabel)
{
	/*
	if ((GetPawn() == nullptr) && (nmState != "Dead"))
	{
		return;
	}
	sLastAttemptedStateChange = FString::FromInt(nmState);
	NPCLog("Wants to change state to " + FString::FromInt(nmState) + " from state " + FString::FromInt(GetStateName()) + " with orders " + FString::FromInt(iNPCCurrentOrders));
	if ((nmState == "FlashBanged") || (nmState == "Dead"))
	{
		Super::NPCChangeState(nmState, nmLabel);
		return;
	}
	if ((IsInPanic() || IsInPain()) && (nmState != "Cowering"))
	{
		NPCLog("NPCChangeState() aborting due to panic: " + FString::FromInt(IsInPanic()) + " pain " + FString::FromInt(IsInPain()) + " and target state not Cowering: " + FString::FromInt(nmState));
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
		NPCLog("Ignoring state " + FString::FromInt(nmState) + " due to being in ORDER_FLEE mode");
		return;
	case 7:
		if (GetPawn()->Health > 0)
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
			if ((pnCurrentPathNode == nullptr) || (VSize((GetPawn()->GetActorLocation() - pnCurrentPathNode->GetActorLocation())) > float(100)))
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
	NPCLog("Changing state to " + FString::FromInt(nmState));
	Super::NPCChangeState(nmState, nmLabel);
	*/
}

void ANPCBaseSoldierController::Reset()
{
	Super::Reset();
	Enemy = nullptr;
	bFindAlamoFirePosition = false;
	fpTimeSinceLastGrenade = 0;
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
	if (((iRPGCount > 0) && (GetPawn()->Weapon != nullptr)) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		GetPawn()->Weapon.Reload();
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	}
	{
	}
	*/
}

void ANPCBaseSoldierController::ExitSquadVehicle(AVehicle* vehicleToExit)
{
	vVehicleCarryingNPC = vehicleToExit;
	ChangeState("ExitVehicleNow");
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
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCCoverPositionPathNode::StaticClass())) && (VSize((pnCurrentLocation->GetActorLocation() - Pawn->GetActorLocation())) < float(150)))
	{
		if (pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
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
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		return true;
	}
	return false;
}

bool ANPCBaseSoldierController::IsInCamperNode()
{
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation->IsA(ANPCCamperFirePositionPathNode::StaticClass()))
	{
		return true;
	}
	return false;
}

bool ANPCBaseSoldierController::IsInAlamoNode()
{
	if (pnCurrentLocation == nullptr)
	{
		return false;
	}
	if (pnCurrentLocation->IsA(ANPCAlamoFirePositionPathNode::StaticClass()))
	{
		return true;
	}
	return false;
}

int32 ANPCBaseSoldierController::GetSearchRotationRate()
{
	/*
	if (((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.weaponType == 4))
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
	FocalPoint = (GetPawn()->GetActorLocation() + (float(1024) * Vector(rotLookDirection)));
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
	FocalPoint = (GetPawn()->GetActorLocation() + (float(1024) * Vector(rotLookDirection)));
	*/
}

void ANPCBaseSoldierController::FaceNodeDirection()
{
	//FocalPoint = (GetPawn()->GetActorLocation() + (float(1024) * Vector(pnCurrentLocation.Rotation)));
}

void ANPCBaseSoldierController::MoveToAlamoFirePosition()
{
	bFindAlamoFirePosition = true;
	NPCChangeState("MoveToAlamoPosition", "PopSmokeFirst");
}

void ANPCBaseSoldierController::ForceGrenadeToss()
{
	bThrowGrenadeForNextShoot = true;
}

void ANPCBaseSoldierController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
	/*
	if (LineOfSightTo(npcpc.Pawn) || (VSize((npcpc.Pawn->GetActorLocation() - Location)) <= fpNPCHearingRadius))
	{
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("FriendDied");
		}
		vDeadTeammateLocation = npcpc.Pawn->GetActorLocation();
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportFriendDied(this))
			{
				npcaiccCombatController.ProcessCombatAction(this);
				return;
			}
		}
		ChangeState("LookAtDeadTeammate");
	}
	*/
}

void ANPCBaseSoldierController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
	bool bIsSquadMate = false;
	if (pInstigator == nullptr)
	{
		return;
	}
	if (pInstigator->Controller == nullptr)
	{
		return;
	}
	if (pInstigator->Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return;
	}
	/*
	if (LineOfSightTo(anpcbcDamaged.Pawn) || (VSize((anpcbcDamaged->GetActorLocation() - Location)) <= fpNPCHearingRadius))
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
	NPCSay(0, true, false);
}

void ANPCBaseSoldierController::NotifyBuzzedByBullet(AActor* aShooter)
{
	/*
	if (VSize((aShooter->GetActorLocation() - Pawn->GetActorLocation())) > fpNPCMaxVisualRange)
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
	if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
	{
		Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("BulletWhip");
	}
	if (npcaiccCombatController != nullptr)
	{
		if (npcaiccCombatController.ReportUnderFire(this, aShooter))
		{
			npcaiccCombatController.ProcessCombatAction(this);
		}
	}
	*/
}

void ANPCBaseSoldierController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	Super::NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	/*
	if (GetPawn()->Health <= 0)
	{
		return;
	}
	*/
	if (Damage > 5)
	{
		NPCLog("Soldier hit, moving to cover");
		NPCChangeState("FindCoverThenFight","");
		PlayHitDamageAudio();
		if (npcaiccCombatController != nullptr)
		{
			/*
			if (npcaiccCombatController->ReportWounded(this, npcaiccCombatController.0, instigatedBy, int(EvaluateEnemyThreat(instigatedBy))))
			{
				npcaiccCombatController->ProcessCombatAction(this);
			}
			*/
		}
	}
	if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
	{
		//Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon->UpdateAction("Injured");
	}
}

void ANPCBaseSoldierController::PlayEnemySpottedAudio()
{
	NPCSay(3, true, true);
}

void ANPCBaseSoldierController::SetDesiredTarget(AActor* aTarget)
{
	if (aTarget->IsA(APawn::StaticClass()))
	{
		//NPCLog("Enemy APawn* seen setting focus/enemy to it: " + FString::FromInt(aTarget));
		if (Enemy != Cast<APawn>(aTarget))
		{
			fpTargetingStartTime = (GetWorld()->GetTimeSeconds() + float(60));
			if (npcaiccCombatController == nullptr)
			{
				PlayEnemySpottedAudio();
			}
			Enemy = Cast<APawn>(aTarget);
			Focus = Cast<APawn>(aTarget);
			Cast<AAGP_Pawn>(GetPawn())->bEyeTrack = true;
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
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			//Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon->UpdateAction("SeePlayer");
		}
		if ((npcaiccCombatController != nullptr) && (Enemy != nullptr))
		{
			NPCLog("Want to change to targeting state, but letting AICC potentially override us");
			pawnLastEnemy = Enemy;
			/*
			if (npcaiccCombatController->ReportContact(this, npcaiccCombatController.0, Enemy, int(EvaluateEnemyThreat(Enemy))))
			{
				NPCLog("SetDesiredTarget AICC response: " + sNextAICCAction);
				npcaiccCombatController->ProcessCombatAction(this);
			}
			*/
		}
	}
}

void ANPCBaseSoldierController::SelectWeapon()
{
}

void ANPCBaseSoldierController::UnslingWeapon()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon == nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHands();
	}
}

void ANPCBaseSoldierController::ShoulderWeapon()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->PutDown();
	}
}

bool ANPCBaseSoldierController::IsCombatOver()
{
	return false;
}

void ANPCBaseSoldierController::Timer()
{
	Super::Timer();
	if (GetPawn() == nullptr)
	{
		return;
	}
	DetermineBalanceOfPower();
	if ((fpTimeSinceUntilTargetLost > 0) && (GetWorld()->GetTimeSeconds() > fpTimeSinceUntilTargetLost))
	{
		fpTimeSinceUntilTargetLost = 0;
		Cast<AAGP_Pawn>(GetPawn())->ResetLean();
		Cast<AAGP_Pawn>(GetPawn())->bEyeTrack = false;
		LostHistoryContact(Enemy);
		if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
		{
			//Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon->UpdateAction("LostEnemy");
		}
		if (npcaiccCombatController != nullptr)
		{
			if ((GetStateName() == "PursueEnemy") && (!IsInCover()))
			{
				NPCChangeState("PursueEnemy","");
				return;
			}
			if (Focus == Enemy)
			{
				Focus = nullptr;
			}
			pawnLastEnemy = Enemy;
			Enemy = nullptr;
			if (npcaiccCombatController->ReportLostContact(this, Enemy))
			{
				npcaiccCombatController->ProcessCombatAction(this);
			}
			else
			{
				if (IsInState("Targeting"))
				{
					NPCChangeState("SearchForTarget","");
				}
			}
			return;
		}
		if (ShouldThrowGrenade(false))
		{
			if (pawnLastEnemy != nullptr)
			{
				vGrenadeTarget = pawnLastEnemy->GetActorLocation();
			}
			NPCLog("Lost Target, changing to throw grenade");
			Cast<AAGP_Pawn>(GetPawn())->SwapHands();
			NPCChangeState("ThrowingGrenade","");
			return;
		}
		else
		{
			if (((FMath::FRand() > 0.5) && (iNPCCurrentOrders != 2)) && (iNPCCurrentOrders != 9))
			{
				NPCLog("Trying to advance on enemy location");
				NPCChangeState("PursueEnemy","");
				return;
			}
			else
			{
				NPCLog("Lost enemy contact, returning to searching for targets");
				NPCChangeState("SearchForTarget","");
			}
		}
	}
}

bool ANPCBaseSoldierController::IsTargetDead()
{
	if (Enemy != nullptr)
	{
		/*
		if (Enemy.Health > 0)
		{
			return false;
		}
		*/
	}
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
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (fpTimeSinceUntilTargetLost > 0)
	{
		return;
	}
	//NPCLog("NotifyEnemyNotVisible() entered for APawn* " + FString::FromInt(Enemy));
	/*
	if ((Enemy != nullptr) && (Enemy->Health <= 0))
	{
		fpTimeSinceUntilTargetLost = GetWorld()->GetTimeSeconds();
	}
	else
	{
		fpTimeSinceUntilTargetLost = ((GetWorld()->GetTimeSeconds() + 1.5) + (FMath::FRand() * 2.5));
	}
	*/
}

void ANPCBaseSoldierController::NotifyPlayerPawnInSight(APawn* pawnSeen)
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	Super::NotifyPlayerPawnInSight(pawnSeen);
	fpTimeSinceUntilTargetLost = 0;
	//NPCLog("NotifyPlayerPawnInSight() saw: " + FString::FromInt(pawnSeen));
	EvaluateTarget(pawnSeen, false);
}

void ANPCBaseSoldierController::EvaluateTarget(APawn* pawnSeen, bool bWatchingUs)
{
	int32 iNewTargetThreatRating = 0;
	if (GetPawn() == nullptr)
	{
		return;
	}
	pawnLastPawnSeen = pawnSeen;
	DetermineBalanceOfPower();
	/*
	* Do While?
	if (true)
	{
		if (iNPCTacticalOrders == 100)
		{
			NPCLog("Ignoring target due to orders");
			return;
		}
		fpDistanceToLastEvaluatedTarget = VSize((pawnSeen->GetActorLocation() - Pawn->GetActorLocation()));
		if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon.weaponType == 4))
		{
			fpNPCWeaponEffectiveRange = 44000;
		}
		if ((iNPCTacticalOrders == 200) || (iNPCTacticalOrders == 300))
		{
			if (VSize((pawnSeen->GetActorLocation() - Pawn->GetActorLocation())) >= fpNPCWeaponEffectiveRange)
			{
				NPCLog("Holdfire/controlled fire - APawn* too far away to shoot: " + FString::FromInt(VSize((pawnSeen->GetActorLocation() - Pawn->GetActorLocation()))) + " vs. " + FString::FromInt(fpNPCWeaponEffectiveRange));
				return;
			}
		}
		if (iNPCCurrentOrders == 2)
		{
			if ((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCCamperFirePositionPathNode::StaticClass()))
			{
				if (VSize((pawnSeen->GetActorLocation() - Pawn->GetActorLocation())) >= Cast<ANPCCamperFirePositionPathNode>(pnCurrentLocation).fpAmbushRange)
				{
					NPCLog("Pawn out of range");
					return;
				}
			}
		}
		if (pawnSeen->IsA(AVehicle::StaticClass()))
		{
			NPCLog("Saw vehicle: " + FString::FromInt(pawnSeen));
			if ((Cast<AVehicle>(pawnSeen).bIsHelicopter && (Cast<AAGP_Pawn>(Enemy) != nullptr)) && (Cast<AVehicle>(Enemy) != nullptr))
			{
				SetDesiredTarget(Enemy);
				return;
			}
			if (pawnSeen->IsA(ACROWS_HMMWV::StaticClass()))
			{
				if ((Cast<AVehicle>(pawnSeen).NumPassengers() == 1) && (Cast<AVehicle>(pawnSeen).Driver != nullptr))
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
			if ((Cast<AVehicle>(pawnSeen).bSusceptibleToSmallArms || Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) || pawnSeen->IsA(ACROWS_HMMWV::StaticClass()))
			{
				NPCLog("Reporting vehicle target to combat controller: " + FString::FromInt(pawnSeen));
				if (npcaiccCombatController != nullptr)
				{
					SetDesiredTarget(pawnSeen);
					if (npcaiccCombatController.ReportVehicleContact(this, npcaiccCombatController.0, pawnSeen, int(EvaluateEnemyThreat(pawnSeen))))
					{
						npcaiccCombatController.ProcessCombatAction(this);
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
		NPCLog("Evaluating new target: " + FString::FromInt(pawnSeen));
		NPCLog("Current enemy is " + FString::FromInt(Enemy));
		NPCLog("Target threat is: " + FString::FromInt(iNewTargetThreatRating));
		NPCLog("Current enemy threat is: " + FString::FromInt(EvaluateEnemyThreat(Enemy)));
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
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (Enemy == pawnEnemy)
	{
		//NPCLog("Saw current target: " + FString::FromInt(Enemy));
		/*
		if ((!IsInState("Targeting")) && (VSize((GetPawn()->GetActorLocation() - pawnEnemy->GetActorLocation())) < (fpNPCWeaponEffectiveRange / 4)))
		{
			EvaluateTarget(pawnEnemy, true);
		}
		*/
		return;
	}
	Super::NotifyPlayerPawnWatchingMe(pawnEnemy);
	NPCLog("Pawn saw enemy");
	EvaluateTarget(pawnEnemy, true);
}

bool ANPCBaseSoldierController::SafeToFire()
{
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	AActor* traceHit = nullptr;
	if (GetPawn() == nullptr)
	{
		return false;
	}
	/*
	vStartShot = Pawn.EyePosition();
	if (IsInState("ProvidingSuppressiveFire"))
	{
		if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode) != nullptr)
		{
			if (Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bPopAndShoot || (!(Cast<ANPCFirePositionPathNode>(pnCurrentPathNode).bShootWhileCrouched && NPCFirePositionPathNode(pnCurrentPathNode).bShootWhileProne)))
			{
				(vStartShot += FVector(0, 0, 100));
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
			vEndShot = Enemy->GetActorLocation();
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
				(vEndShot.Z += (GetPawn()->CrouchEyeHeight / 2));
			}
			else
			{
				if (Enemy != nullptr)
				{
					vEndShot = Enemy.EyePosition();
				}
				else
				{
					(vEndShot.Z += (GetPawn()->CrouchEyeHeight / 2));
				}
			}
		}
	}
	traceHit = Trace(HitLocation, HitNormal, vEndShot, vStartShot, true);
	if (bDebugCombat)
	{
		NPCLog("SafeToFire() - tracehit result: " + FString::FromInt(traceHit));
	}
	if ((((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()")) && (Cast<AAGP_Pawn>(traceHit).Controller != nullptr)) && Cast<AAGP_Pawn>(traceHit).Controller->IsA(ANPCBaseController::StaticClass()))
	{
		if (bDebugCombat)
		{
			NPCLog("SafeToFire() NOT SAFE!!!");
		}
		return false;
	}
	if (((((traceHit != nullptr) && traceHit->IsA(AAuxCollisionCylinder::StaticClass())) && (Cast<AAGP_Pawn>(Cast<AAuxCollisionCylinder>(traceHit).Owner) != nullptr)) && (Cast<AAGP_Pawn>(Cast<AAuxCollisionCylinder>(traceHit).Owner).Controller != nullptr)) && Cast<AAGP_Pawn>(Cast<AAuxCollisionCylinder>(traceHit).Owner).Controller->IsA(ANPCBaseController::StaticClass()))
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
	if ((GetPawn() == nullptr) || (GetPawn()->Weapon == nullptr))
	{
		return;
	}
	if (GetPawn()->bIsCrouched)
	{
		vStartShot = Pawn->GetActorLocation();
		(vStartShot.Z += Pawn.CrouchEyeHeight);
	}
	else
	{
		if (GetPawn()->bIsProne)
		{
			vStartShot = Pawn->GetActorLocation();
			(vStartShot.Z += float(20));
		}
		else
		{
			if (GetPawn()->bIsHipShooting)
			{
				vStartShot = Pawn->GetActorLocation();
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
		if (Enemy->IsA(ACROWS_HMMWV::StaticClass()))
		{
			if (Cast<AVehicle>(Enemy).Weapon != nullptr)
			{
				vEndShot = Vehicle(Enemy).Weapon->GetActorLocation();
			}
			else
			{
				vEndShot = Enemy->GetActorLocation();
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
		if (GetPawn()->Weapon->IsA(ARocketWeapon::StaticClass()))
		{
			fpRPGTimeToTarget = (VSize((vEndShot - vStartShot)) / float(1900));
			NPCLog("Rocketeer target moving at " + FString::FromInt(VSize(Enemy.Velocity)) + " initial aimpoint: " + FString::FromInt(vEndShot));
			(vEndShot += ((fpRPGTimeToTarget * VSize(Enemy.Velocity)) * Vector(Normalize(rotator(Enemy.Velocity)))));
			NPCLog("Adjusted aimpoint: " + FString::FromInt(vEndShot));
		}
	}
	fpAimingSkill = (fpNPCWeaponAccuracy / 100);
	if (GetPawn()->bIsHipShooting)
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
			if (GetPawn()->bIsCrouched)
			{
				fpAimingSkill = (fpAimingSkill * 0.9);
			}
		}
	}
	if (fpAimingSkill > 0.2)
	{
		(fpAimingSkill -= (0.2 * (fpAimTime / fpMaxAimTime)));
	}
	if (GetPawn()->Weapon.weaponType == 4)
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
	if (VSize((GetPawn()->GetActorLocation() - vEndShot)) > fpNPCWeaponEffectiveRange)
	{
		fpAimingSkill = (fpAimingSkill - (0.1 * ((VSize((GetPawn()->GetActorLocation() - vEndShot)) - fpNPCWeaponEffectiveRange) / 2500)));
	}
	if (fpAimingSkill < 0)
	{
		fpAimingSkill = 0;
	}
	aimerror = (((VSize((GetPawn()->GetActorLocation() - vEndShot)) / float(2500)) * float(200)) * (1 - fpAimingSkill));
	if (VSize((GetPawn()->GetActorLocation() - vEndShot)) < float(75))
	{
		aimerror = (FMath::FRand() * 5);
	}
	else
	{
		if (VSize((GetPawn()->GetActorLocation() - vEndShot)) < float(150))
		{
			aimerror = (FMath::FRand() * 8);
		}
		else
		{
			if (VSize((GetPawn()->GetActorLocation() - vEndShot)) < float(200))
			{
				aimerror = (FMath::FRand() * float(10));
			}
		}
	}
	fpLastShotAccuracy = aimerror;
	if (FMath::FRand() < 0.97)
	{
		if (FMath::FRand() > 0.5)
		{
			(vEndShot.X += (aimerror / (float(-4) + FMath::FRand())));
		}
		else
		{
			(vEndShot.X += (aimerror / (4 + FMath::FRand())));
		}
		if (GetPawn()->bIsCrouched)
		{
			(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 0.2));
		}
		else
		{
			if (GetPawn()->bIsCrouched)
			{
				(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 0.75));
			}
			else
			{
				(vEndShot.X += (float(iRoundsFiredSinceCameOutOfCover) * 1.5));
			}
		}
	}
	if (FMath::FRand() < 0.97)
	{
		if (FMath::FRand() > 0.5)
		{
			(vEndShot.Y += (aimerror / (-4 + FMath::FRand())));
		}
		else
		{
			(vEndShot.Y += (aimerror / (4 + FMath::FRand())));
		}
	}
	if ((FMath::FRand() < 0.98) || (iRoundsFiredSinceCameOutOfCover == 0))
	{
		if (FMath::FRand() > 0.5)
		{
			(vEndShot.Z += (aimerror / (-4.5 + FMath::FRand())));
		}
		else
		{
			(vEndShot.Z += (aimerror / (4.5 + FMath::FRand())));
		}
		if (GetPawn()->bIsCrouched)
		{
			(vEndShot.Z += (float(iRoundsFiredSinceCameOutOfCover) * 0.75));
		}
		else
		{
			if (GetPawn()->bIsCrouched)
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
		NPCLog("Using enemy target location: " + FString::FromInt(vEndShot.X) + "," + FString::FromInt(vEndShot.Y) + "," + FString::FromInt(vEndShot.Z));
	}
	d1 = (vEndShot - vStartShot);
	r1 = rotator(d1);
	GetPawn()->SetViewRotation(r1);
	if (bDebugCombat)
	{
		NPCLog("Pitch: (P/R/Y): " + FString::FromInt(Aim.Pitch) + ", " + FString::FromInt(Aim.Roll) + ", " + FString::FromInt(Aim.Yaw));
	}
	GetPawn()->MakeNoise(1);
	if (Cast<AAGP_Pawn>(GetPawn())->IsHeDead())
	{
		if (bDebugCombat)
		{
			NPCLog("Dead guy wants to shoot - being overridden");
		}
		return;
	}
	if (GetPawn()->Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		Cast<AAGP_Weapon>(GetPawn()->Weapon).dEnemy = Enemy;
		GetPawn()->Weapon.NPC_ProjectileFire();
	}
	else
	{
		if ((FMath::FRand() < 0.8) || (GetPawn()->Weapon.weaponType == 4))
		{
			GetPawn()->Weapon.NPC_Fire(1, None);
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
	AActor* traceHit = nullptr;
	if (GetPawn() == nullptr)
	{
		return false;
	}
	/*
	if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		return false;
	}
	if (((Enemy != nullptr) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) < float(750))) || (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) > float(3300)))
	{
		return false;
	}
	vStartShot = Pawn.EyePosition();
	iStartingGrenadesOfCurrentType = iFragGrenadeCount;
	iDesiredGrenadeIndex = Pawn.0;
	NPCLog("Grenades available for current mental state: " + FString::FromInt(iStartingGrenadesOfCurrentType));
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
	if (((pnCurrentPathNode != nullptr) && pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass())) && (!NPCFirePositionPathNode(pnCurrentPathNode).bCanUseGrenades))
	{
		return false;
	}
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastGrenade) < (float(10) + (FMath::FRand() * float(10))))
	{
		return false;
	}
	vCeiling = Pawn->GetActorLocation();
	(vCeiling.Z += float(500));
	traceHit = Trace(HitLocation, HitNormal, vCeiling, Pawn->GetActorLocation(), true);
	if (VSize((HitLocation - Pawn->GetActorLocation())) < float(50))
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
		traceHit = Trace(HitLocation, HitNormal, vEndShot, (vStartShot + FVector(0, 0, 50)), true);
		if (traceHit != nullptr)
		{
			NPCLog("Barrier blocking grenade at distance: " + FString::FromInt(VSize((GetPawn()->GetActorLocation() - HitLocation))));
			if (VSize((GetPawn()->GetActorLocation() - HitLocation)) < float(1312))
			{
				NPCLog("Can't throw frag due to something blocking throw");
				return false;
			}
		}
		NPCLog("Enemy target lost - last enemy health: " + FString::FromInt(pawnLastEnemy.Health) + ", threat: " + FString::FromInt(EvaluateEnemyThreat(pawnLastEnemy, true)));
		if (((((FMath::FRand() > 0.5) || (npcaiccCombatController != nullptr)) && (pawnLastEnemy != nullptr)) && (pawnLastEnemy.Health >= 50)) && (EvaluateEnemyThreat(pawnLastEnemy, true) >= 2))
		{
			NPCLog("We want to throw one at lost target!");
			fpTimeSinceLastGrenade = GetWorld()->GetTimeSeconds();
			return true;
		}
	}
	else
	{
		vEndShot = Enemy->GetActorLocation();
		if (!CheckGrenadeTargetArea(vEndShot))
		{
			return false;
		}
		traceHit = Trace(HitLocation, HitNormal, vEndShot, vStartShot, true);
		if (traceHit != nullptr)
		{
			NPCLog("Barrier blocking grenade at distance: " + FString::FromInt(VSize((GetPawn()->GetActorLocation() - HitLocation))));
			if (VSize((GetPawn()->GetActorLocation() - HitLocation)) < float(1500))
			{
				return false;
			}
		}
		vGrenadeTarget = Enemy->GetActorLocation();
		if ((VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) > float(1312)) || (((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass())) && NPCFirePositionPathNode(pnCurrentLocation).bIsCover))
		{
			NPCLog("In cover firing with grenades enabled position or far enough away grenade won't kill self");
			if ((npcaiccCombatController != nullptr) || ((FMath::FRand() + 0.1) > (1 - float((Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.0] / iStartingGrenadesOfCurrentType)))))
			{
				NPCLog("Want to throw grenade at visible target");
				fpTimeSinceLastGrenade = GetWorld()->GetTimeSeconds();
				return true;
			}
		}
	}
	if (bForceThrow)
	{
		fpTimeSinceLastGrenade = GetWorld()->GetTimeSeconds();
		return true;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool ANPCBaseSoldierController::CheckGrenadeTargetArea(FVector vTargetArea)
{
	AController* ctrlrIterator = nullptr;
	/*
	if (VSize((GetPawn()->GetActorLocation() - vTargetArea)) < float(1500))
	{
		return false;
	}
	for (ctrlrIterator = Level.ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator.nextController)
	{
		if (ctrlrIterator->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			if ((ctrlrIterator.Pawn != nullptr) && (VSize((vTargetArea - ctrlrIterator.Pawn->GetActorLocation())) < float(1500)))
			{
				return false;
			}
		}
	}
	*/
	return true;
}

bool ANPCBaseSoldierController::ThrowSmokeGrenade(bool bForceThrow)
{
	int32 iStartingGrenadesOfCurrentType = 0;
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	if (GetPawn() == nullptr)
	{
		return false;
	}
	/*
	if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		return false;
	}
	vStartShot = Pawn.EyePosition();
	iStartingGrenadesOfCurrentType = iSmokeGrenadeCount;
	iDesiredGrenadeIndex = Pawn.1;
	NPCLog("Smoke Grenades available: " + FString::FromInt(iStartingGrenadesOfCurrentType));
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
	if (((pnCurrentPathNode != nullptr) && pnCurrentPathNode->IsA(ANPCFirePositionPathNode::StaticClass())) && (!NPCFirePositionPathNode(pnCurrentPathNode).bCanUseGrenades))
	{
		return false;
	}
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastGrenade) < 20)
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
		vEndShot = Enemy->GetActorLocation();
		if ((VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) >= float(500)) || (pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()) && NPCFirePositionPathNode(pnCurrentLocation).bIsCover))
		{
			NPCLog("In cover firing with grenades enabled position or far enough away grenade won't kill self");
			if ((npcaiccCombatController != nullptr) || ((FMath::FRand() + 0.1) > (1 - float((Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.1] / iStartingGrenadesOfCurrentType)))))
			{
				NPCLog("Want to throw smoke grenade at visible target");
				fpTimeSinceLastGrenade = GetWorld()->GetTimeSeconds();
				return true;
			}
		}
	}
	*/
	if (bForceThrow)
	{
		fpTimeSinceLastGrenade = GetWorld()->GetTimeSeconds();
		return true;
	}

	return false;     //FAKE   /EliZ
}

int32 ANPCBaseSoldierController::SetGrenadeTypeByMentalState()
{
	/*
	NPCLog("confidence before throwing grenade: " + FString::FromInt(GetConfidenceLevel()));
	if ((GetConfidenceLevel() <= float(-40)) && (Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.1] >= 0))
	{
		iDesiredGrenadeIndex = Pawn.1;
		return iSmokeGrenadeCount;
	}
	else
	{
		if (((GetConfidenceLevel() > float(-40)) && (Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.0] >= 0)) && (!pnCurrentPathNode->IsA(ANPCDoorEntryPathNode::StaticClass())))
		{
			iDesiredGrenadeIndex = Pawn.0;
			return iFragGrenadeCount;
		}
		else
		{
			if (((GetConfidenceLevel() > float(-40)) && (Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Pawn.2] >= 0)) && pnCurrentPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
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
	if (IsInState("WalkingPatrol"))
	{
		NPCChangeState("FindCover","");
		return;
	}
	if (IsInState("Targeting"))
	{
		return;
	}
	/*
	if ((!Pawn.bIsCrouched) && (!Pawn.bIsProne))
	{
		Crouch();
	}
	fpDistanceToWeapon = VSize((NoiseMaker->GetActorLocation() - Pawn->GetActorLocation()));
	if (((fpDistanceToWeapon > fpNPCWeaponEffectiveRange) || (fpDistanceToWeapon > fpNPCMaxVisualRange)) || (fpDistanceToWeapon > fpNPCHearingRadius))
	{
		NPCChangeState("FindCoverThenFight");
	}
	else
	{
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportHeardGunfire(this, NoiseMaker->GetActorLocation()))
			{
				npcaiccCombatController.ProcessCombatAction(this);
			}
		}
	}
	*/
}

void ANPCBaseSoldierController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	if (((agpwWeaponHeard.Instigator != nullptr) && (agpwWeaponHeard.Instigator.Controller != nullptr)) && (!agpwWeaponHeard.Instigator.Controller->IsA(AHumanController::StaticClass())))
	{
		return;
	}
	if (VSize((GetPawn()->GetActorLocation() - vSoundLocation)) > float(200))
	{
		if (!LineOfSightTo(agpwWeaponHeard.Instigator))
		{
			return;
		}
	}
	if (VSize((GetPawn()->GetActorLocation() - vSoundLocation)) < float(2500))
	{
		NPCLog("Turning towards APawn* that was heard: " + FString::FromInt(agpwWeaponHeard));
		Crouch();
		Focus = agpwWeaponHeard;
		FocalPoint = (GetPawn()->GetActorLocation() + (float(512) * Vector(Normalize(rotator((agpwWeaponHeard->GetActorLocation() - Pawn->GetActorLocation()))))));
		if (VSize((GetPawn()->GetActorLocation() - vSoundLocation)) < float(500))
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
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (!LineOfSightTo(pawnHeard))
	{
		return;
	}
	if (pawnHeard->IsA(ACROWS_HMMWV::StaticClass()))
	{
		fpTimeLastPawnHeard = GetWorld()->GetTimeSeconds();
		Focus = pawnHeard;
		//FocalPoint = (GetPawn()->GetActorLocation() + (float(512) * Vector(Normalize(rotator((pawnHeard->GetActorLocation() - Pawn->GetActorLocation()))))));
		//if (VSize((GetPawn()->GetActorLocation() - pawnHeard->GetActorLocation())) < float(500))
		//{
		//	IncreaseNervousness(1);
		//}
		NPCChangeState("HeardPlayer","");
		return;
	}
	if (Cast<AVehicle>(pawnHeard) == nullptr)
	{
		fpMaxDistance = 1250;
	}
	else
	{
		fpMaxDistance = 5500;
	}
	/*
	if (VSize((GetPawn()->GetActorLocation() - pawnHeard->GetActorLocation())) < fpMaxDistance)
	{
		fpTimeLastPawnHeard = GetWorld()->GetTimeSeconds();
		Focus = pawnHeard;
		FocalPoint = (GetPawn()->GetActorLocation() + (float(512) * Vector(Normalize(rotator((pawnHeard->GetActorLocation() - Pawn->GetActorLocation()))))));
		if (VSize((GetPawn()->GetActorLocation() - pawnHeard->GetActorLocation())) < float(500))
		{
			IncreaseNervousness(1);
		}
		NPCChangeState("HeardPlayer");
	}
	*/
}

void ANPCBaseSoldierController::RecoverFromBadStateCode()
{
	//bBadStateCode = false;
	NPCLog("RecoverFromBadStateCode() entered, going to SearchForTarget");
	NPCChangeState("SearchForTarget","");
}

float ANPCBaseSoldierController::GetGrenadePitch()
{
	return fpGrenadePitch;
}

void ANPCBaseSoldierController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (twpGrenade == nullptr)
	{
		return;
	}
	/*
	NPCLog(string(this) + " Grenade seen by soldier: " + FString::FromInt(twpGrenade));
	Super::NotifyEnemyGrenadeClose(twpGrenade);
	if (!twpGrenade->IsA(APickupT_M83_Smoke::StaticClass()))
	{
		if (npcaiccCombatController != nullptr)
		{
			if (npcaiccCombatController.ReportGrenadeContact(this, twpGrenade->GetActorLocation()))
			{
				npcaiccCombatController.ProcessCombatAction(this);
			}
		}
	}
	if ((Cast<AAGP_Pawn>(GetPawn()) != nullptr) && (Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon != nullptr))
	{
		Cast<AAGP_Pawn>(GetPawn())->MyDebug_InterruptIcon.UpdateAction("SeeGrenade");
	}
	*/
}

ANPCFirePositionPathNode* ANPCBaseSoldierController::FindNextFiringPosition(float fpMaxDistance, bool bCanJumpToGetThere)
{
	if (GetPawn() == nullptr)
	{
		return nullptr;
	}
	return FastFindNextFiringPosition(fpMaxDistance, bCanJumpToGetThere);
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
	if (GetPawn() == nullptr)
	{
		return nullptr;
	}
	for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
	{
		if (!N->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
		}
		npcfppnIterator = NPCFirePositionPathNode(N);
		NPCPathLog("Found possible fire position to move to: " + FString::FromInt(npcfppnIterator.Tag));
		if (npcfppnIterator == pnCurrentLocation)
		{
		}
		if (pnBestFirePosition == nullptr)
		{
			vNodeEyeHeightLocation = npcfppnIterator->GetActorLocation();
			vNodeEyeHeightLocation.Z += float(100);
			traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, vNodeEyeHeightLocation, true);
			if (bDebugPath && bDebugCombat)
			{
				NPCPathLog("No Previous Fire position, potential new one: " + FString::FromInt(npcfppnIterator) + " Trace towards target hit: " + FString::FromInt(traceHit) + ", distance: " + FString::FromInt(VSize((npcfppnIterator->GetActorLocation() - vLastTarget))));
			}
			if ((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()"))
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
			if (VSize((pnBestFirePosition->GetActorLocation() - vLastTarget)) > VSize((npcfppnIterator->GetActorLocation() - vLastTarget)))
			{
				if (VSize((GetPawn()->GetActorLocation() - vLastTarget)) < VSize((npcfppnIterator->GetActorLocation() - vLastTarget)))
				{
				}
				NPCLog("Testing firing position " + FString::FromInt(npcfppnIterator) + " for LOS to target");
				vNodeEyeHeightLocation = npcfppnIterator->GetActorLocation();
				vNodeEyeHeightLocation.Z += float(100);
				traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, vNodeEyeHeightLocation, true);
				if (bDebugPath && bDebugCombat)
				{
					NPCPathLog("Testing new \"Best\" Fire position: " + FString::FromInt(npcfppnIterator) + " Trace towards target hit: " + FString::FromInt(traceHit) + ", distance: " + FString::FromInt(VSize((npcfppnIterator->GetActorLocation() - vLastTarget))));
				}
				if ((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()"))
				{
					NPCPathLog("Somewhat closer firing position found, testing it for usefulness");
					pnBestFirePosition = npcfppnIterator;
					fpDistanceFromBestToTarget = VSize((pnBestFirePosition->GetActorLocation() - vLastTarget));
				}
			}
			else
			{
		else
		{
			if (VSize((GetPawn()->GetActorLocation() - vLastTarget)) < VSize((npcfppnIterator->GetActorLocation() - vLastTarget)))
			{
			}
			traceHit = npcfppnIterator.Trace(HitLocation, HitNormal, vLastTarget, pnBestFirePosition->GetActorLocation(), true);
			if ((traceHit == nullptr) || ((traceHit != nullptr) && traceHit->IsA("AAGP_Pawn::StaticClass()")))
			{
				pnBestFirePosition = npcfppnIterator;
			}
		}
			}
		}
		}
	}
	if ((fpDistanceFromBestToTarget > VSize((GetPawn()->GetActorLocation() - vLastTarget))) || (pnBestFirePosition == nullptr))
	{
		for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
		{
			if (!N->IsA(ANPCPathNode::StaticClass()))
			{
			}
			pnIterator = NPCPathNode(N);
			if (pnBestFirePosition == nullptr)
			{
				pnBestFirePosition = pnIterator;
			}
			else
			{
				if (VSize((pnBestFirePosition->GetActorLocation() - vLastTarget)) > VSize((pnBestFirePosition->GetActorLocation() - vLastTarget)))
				{
					if (VSize((GetPawn()->GetActorLocation() - vLastTarget)) < VSize((pnBestFirePosition->GetActorLocation() - vLastTarget)))
					{
					}
					NPCPathLog("Somewhat closer firing position found, testing it for usefulness");
					pnBestFirePosition = pnIterator;
				}
			}
		}
	}
	NPCPathLog("Found firing position location: " + FString::FromInt(pnBestFirePosition));
	*/
	return pnBestFirePosition;
}

void ANPCBaseSoldierController::RequestSuppressiveFire(FVector vTargetArea)
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	ADebugNPCTargetArea* dnpcta = nullptr;
	AController* ctrlIterator = nullptr;
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (bDebugCombat)
	{
		//dnpcta = Spawn(ADebugNPCTargetArea::StaticClass());
		//dnpcta->SetLocation(vTargetArea);
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	/*
	if ((GetPawn()->Weapon != nullptr) && (GetPawn()->Weapon->weaponType == 4))
	{
		return;
	}
	NPCLog("Requesting suppressive fire from squad mates");
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(ANPCBaseSoldierController::StaticClass()))
		{
		}
		npcbscIterator = Cast<ANPCBaseSoldierController>(ctrlIterator);
		if ((((npcbscIterator != Self) && (npcbscIterator.Pawn != nullptr)) && (npcbscIterator.Pawn.Health > 25)) && (!npcbscIterator.IsInState("FlashBanged")))
		{
			npcbscIterator.SuppressiveFireRequested(this, vTargetArea);
		}
	}
	*/
}

void ANPCBaseSoldierController::RequestCancellingSuppressiveFire(FVector vTargetArea)
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	AController* ctrlIterator = nullptr;
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(ANPCBaseSoldierController::StaticClass()))
		{
		}
		npcbscIterator = Cast<ANPCBaseSoldierController>(ctrlIterator);
		if (((npcbscIterator != Self) && (npcbscIterator.Pawn != nullptr)) && npcbscIterator.IsInState("ProvidingSuppressiveFire"))
		{
			npcbscIterator.SuppressiveFireCancelled(this, vTargetArea);
		}
	}
	*/
}

void ANPCBaseSoldierController::SuppressiveFireRequested(ANPCBaseSoldierController* npcbscRequestingFire, FVector vTargetArea)
{
	FVector vHitLocation = FVector(0, 0, 0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vTraceEnd = FVector(0, 0, 0);
	FVector vTraceStart = FVector(0, 0, 0);
	AActor* traceHit = nullptr;
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	if ((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass()))
	{
		return;
	}
	if (VSize((GetPawn()->GetActorLocation() - vTargetArea)) > fpNPCMaxVisualRange)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	vTraceStart = Pawn->GetActorLocation();
	vTraceEnd = vTargetArea;
	(vTraceStart.Z += float(90));
	(vTraceEnd.Z += float(90));
	traceHit = Trace(vHitLocation, vHitNormal, vTargetArea, Pawn->GetActorLocation(), true);
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
	if (VSize((GetPawn()->GetActorLocation() - vHitLocation)) < float(150))
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
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	NPCLog("Suppressive fire cancel requested by " + FString::FromInt(npcbscRequestingFire));
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
	RouteCache.SetNum(62);
	for (i = 0; i < 61; i++)
	{
		RouteCache[i] = nullptr;
	}
}

void ANPCBaseSoldierController::LocateAssaultLocation()
{
	ANPCAssaultLocation* npcalIterator = nullptr;
	/*
	ForEach AllActors(ANPCAssaultLocation::StaticClass(), npcalIterator, nameAssaultLocationTag)
	{
		vLastTarget = npcalIterator->GetActorLocation();
		vAssaultLocation = vLastTarget;
		NPCLog("Found assault location: " + FString::FromInt(npcalIterator));
		return;
	}
	*/
	NPCLog("WARNING: No assault location defined despite assault orders");
}

void ANPCBaseSoldierController::ReturnToAssault()
{
	NPCChangeState("AssaultLocation","");
}

void ANPCBaseSoldierController::AlertSquadMatesOfDamage(APawn* pawnInstigator)
{
	AController* ctrlIterator = nullptr;
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (ctrlIterator == this)
		{
		}
		if (!ctrlIterator->IsA(ANPCBaseSoldierController::StaticClass()))
		{
		}
		Cast<ANPCBaseSoldierController>(ctrlIterator).SquadMateHit(this, pawnInstigator);
	}
	*/
}

void ANPCBaseSoldierController::SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator)
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (((pawnInstigator != nullptr) && (pawnInstigator->Controller != nullptr)) && pawnInstigator->Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return;
	}
	/*
	if ((float(npcbscHitNPC.iSquadID) ~= float(iSquadID)) || (VSize((npcbscHitNPC.Pawn->GetActorLocation() - Pawn->GetActorLocation())) < float(1500)))
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
				vLastTarget = pawnInstigator->GetActorLocation();
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
	//fpTargetRange = VSize((vTargetLocation - Pawn->GetActorLocation()));
	//fpTargetAngle = float(rotator((vTargetLocation - Pawn->GetActorLocation())).Yaw);
	if (GetPawn() == nullptr)
	{
		return true;
	}
	/*
	NPCLog("IsVisionBlockedBySmokeGrenade() - target range: " + FString::FromInt(fpTargetRange) + ", target angle: " + FString::FromInt(fpTargetAngle));
	for (iGrenadeIndex = 0; iGrenadeIndex < 10; iGrenadeIndex++)
	{
		if ((agtcGrenadeThreats[iGrenadeIndex]->twpGrenade != nullptr) && agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->IsA(APickupT_M83_Smoke::StaticClass()))
		{
			NPCLog("Smoke grenade at distance: " + FString::FromInt(VSize((agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->GetActorLocation() - Pawn->GetActorLocation()))) + " is still alive");
			if (!agtcGrenadeThreats[iGrenadeIndex]->twpGrenade._bBlewUpProcessed)
			{
			}
			if (VSize((agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->GetActorLocation() - Pawn->GetActorLocation())) < fpTargetRange)
			{
				NPCLog("Grenade " + FString::FromInt(agtcGrenadeThreats[iGrenadeIndex]->twpGrenade) + " is closer than target distance");
				if (IsLocationInFront(agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->GetActorLocation()) && IsLocationInFront(vTargetLocation))
				{
					NPCLog("Grenade " + FString::FromInt(agtcGrenadeThreats[iGrenadeIndex]->twpGrenade) + " and target are both in front of us");
					rotGrenade = rotator((agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->GetActorLocation() - Pawn->GetActorLocation()));
					NPCLog("Angle to smoke grenade: " + FString::FromInt(rotGrenade.Yaw));
					NPCLog("Angle to enemy pawn: " + FString::FromInt(fpTargetAngle));
					if (float(rotGrenade.Yaw) > fpTargetAngle)
					{
						fpAngle = (float(rotGrenade.Yaw) - fpTargetAngle);
					}
					else
					{
						fpAngle = (fpTargetAngle - float(rotGrenade.Yaw));
					}
					NPCLog("Difference: " + FString::FromInt(fpAngle));
					if (fpAngle > float(32768))
					{
						fpAngle -= float(32768);
					}
					NPCLog("Adjusted difference: " + FString::FromInt(fpAngle));
					if (fpAngle < float(8192))
					{
						if (GetWorld()->GetTimeSeconds() > (agtcGrenadeThreats[iGrenadeIndex]->fpTimeSeen + (agtcGrenadeThreats[iGrenadeIndex]->twpGrenade._EffectDuration * 0.75)))
						{
							fpSmokeTimeRemaining = ((agtcGrenadeThreats[iGrenadeIndex]->fpTimeSeen + agtcGrenadeThreats[iGrenadeIndex]->twpGrenade._EffectDuration) - GetWorld()->GetTimeSeconds());
							if ((fpSmokeTimeRemaining / 4) < FMath::FRand())
							{
								NPCLog("Smoke grenade dispersing enough to not affect shot");
							}
						}
						else
						{
							NPCLog("Smoke grenade preventing shot");
							return true;
						}
						NPCLog("Smoke grenade at rotation " + FString::FromInt(rotator((agtcGrenadeThreats[iGrenadeIndex]->twpGrenade->GetActorLocation() - Pawn->GetActorLocation()))) + " angle: " + FString::FromInt(fpAngle) + " not blocking");
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
	Cast<AAGP_Pawn>(GetPawn())->DropWeaponsAfterDeath();
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
	if (GetPawn() == nullptr)
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
	fpTeamThreatRating = EvaluateEnemyThreat(GetPawn(),false,0);
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
	return iBalanceOfPowerState;
}

void ANPCBaseSoldierController::NotifyNPCSeen(APawn* Seen)
{
}

float ANPCBaseSoldierController::EvaluateEnemyThreat(APawn* pawnToEvaluate, bool bWatchingMe, float fpClosureRate)
{
	float fpThreat = 0;
	float fpDistance = 0;
	if (GetPawn() == nullptr)
	{
		return 0;
	}
	if (pawnToEvaluate == nullptr)
	{
		return 0;
	}
	if (pawnToEvaluate->IsA(AVehicle::StaticClass()))
	{
		if (Cast<AVehicle>(pawnToEvaluate)->bIsHelicopter)
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
		//fpDistance = VSize((GetPawn()->GetActorLocation() - pawnToEvaluate->GetActorLocation()));
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
	return fpThreat;
}

void ANPCBaseSoldierController::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
	float fpChance = 0;
	//NPCLog("NPC getting warning from: " + shooter);
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	if (GetPawn()->Health <= 0)
	{
		return;
	}
	*/
	if (((pnCurrentLocation != nullptr) && pnCurrentLocation->IsA(ANPCCoverPositionPathNode::StaticClass())) && Cast<ANPCCoverPositionPathNode>(pnCurrentLocation)->bSafeFromVehiclesImpact)
	{
		return;
	}
	fpChance = FMath::FRand();
	NPCSay(1, true, true);
	if (shooter->Controller->IsA(ANPCBaseController::StaticClass()))
	{
		//NPCLog("Friendly vehicle going to run us over: " + shooter);
		actThreat = shooter;
		ChangeState("LiveGrenade");
		return;
	}
	if (fpChance < 0.69)
	{
		actThreat = shooter;
		ChangeState("LiveGrenade");
	}
	else
	{
		/*
		if (((fpChance > 0.66) && (fpChance < float(90))) && (GetPawn()->Weapon != nullptr))
		{
			SetDesiredTarget(shooter);
		}
		else
		{
			Prone();
			GetPawn()->bWantsToRollLeft = true;
			GetPawn()->bWantsToRollRight = false;
		}
		*/
	}
}

void ANPCBaseSoldierController::MoveOutAfterExitingVehicle()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	ChangeState("PostExitVehicleActions");
}

ANPCPathNode* ANPCBaseSoldierController::FindHeadToObjective()
{
	AAGP_Objective* AO = nullptr;
	TArray<AAGP_Objective*> aagpoFoundObjectives = {};
	UStaticMesh* smaIterator = nullptr;
	if (GetPawn() == nullptr)
	{
		return nullptr;
	}
	/*
	ForEach AllActors(Class'StaticMeshActor', smaIterator, "ReinforcementGoal")
	{
		DebugLog(DEBUG_AI, "Found reinforcement goal location: " + FString::FromInt(smaIterator));
		return LocateClosestNodeToLocation(smaIterator->GetActorLocation());
	}
	DebugLog(DEBUG_AI, "Didn't find tagged reinforcement goal, searching for objectives");
	ForEach AllActors(AAGP_Objective::StaticClass(), AO)
	{
		if (AO.bInstantWin)
		{
			DebugLog(DEBUG_AI, FString::FromInt(this) + ".FindHeadToObjective() " + FString::FromInt(Tag) + " Found instant win objective, using it: " + FString::FromInt(AO));
			aagpoFoundObjectives.insert(0, 1);
			aagpoFoundObjectives[0] = AO;
			continue;
		}
		if (((AO.bRequiredToWin && (!AO.bDisabled)) && (AO.AccomplishedBy != 0)) && (!AO.bInactive))
		{
			DebugLog(DEBUG_AI, FString::FromInt(this) + ".FindHeadToObjective() " + FString::FromInt(Tag) + " Found objective: " + FString::FromInt(AO));
			aagpoFoundObjectives.insert(0, 1);
			aagpoFoundObjectives[0] = AO;
		}
	}
	*/
	if (aagpoFoundObjectives.Num() == 0)
	{
		return LocateClosestNodeToLocation(AO->GetActorLocation());
	}
	else
	{
		//return LocateClosestNodeToLocation(aagpoFoundObjectives[Rand(aagpoFoundObjectives.Num())]->GetActorLocation());
	}
	return nullptr;    //FAKE   /ELiZ
}

ANPCPathNode* ANPCBaseSoldierController::FindHeadToNearestObjective()
{
	AAGP_Objective* AO = nullptr;
	AAGP_Objective* AONearest = nullptr;
	if (GetPawn() == nullptr)
	{
		return nullptr;
	}
	/*
	ForEach AllActors(AAGP_Objective::StaticClass(), AO)
	{
		if (((AO.bRequiredToWin && (!AO.bDisabled)) && (AO.AccomplishedBy != 0)) && (!AO.bInactive))
		{
			DebugLog(DEBUG_AI, FString::FromInt(this) + ".FindHeadToNearestObjective() " + FString::FromInt(Tag) + " Found objective: " + FString::FromInt(AO));
			if (AONearest == nullptr)
			{
				AONearest = AO;
				continue;
			}
			if (VSize((GetPawn()->GetActorLocation() - AONearest->GetActorLocation())) > VSize((GetPawn()->GetActorLocation() - AO->GetActorLocation())))
			{
				AONearest = AO;
				continue;
			}
		}
	}
	*/
	if (AONearest != nullptr)
	{
		return LocateClosestNodeToLocation(AONearest->GetActorLocation());
	}
	else
	{
		return nullptr;
	}
	return nullptr;    //FAKE   /ELiZ
}

void ANPCBaseSoldierController::HeadToObjective(float fpDelayTime, bool bHeadToNearestObjective)
{
	fpHeadToLocationStartDelay = (fpDelayTime * 1.5);
	if (iNPCCurrentOrders == 9)
	{
		NPCChangeState("AssaultLocation","");
		return;
	}
	if (npcpnTravelLocation == nullptr)
	{
		if (bHeadToNearestObjective)
		{
			npcpnTravelLocation = FindHeadToNearestObjective();
			//DebugLog(DEBUG_AI, "Nearest node to nearest objective: " + FString::FromInt(npcpnTravelLocation));
		}
		else
		{
			npcpnTravelLocation = FindHeadToObjective();
			//DebugLog(DEBUG_AI, "Nearest node to objective: " + FString::FromInt(npcpnTravelLocation));
		}
	}
	if (npcpnTravelLocation == nullptr)
	{
		//DebugLog(DEBUG_AI, FString::FromInt(this) + " didn't find any objectives, finding cover then fighting");
		NPCChangeState("FindCoverThenFight","");
		return;
	}
	AICCHeadToLocation(npcpnTravelLocation->GetActorLocation(), npcpnTravelLocation);
}

void ANPCBaseSoldierController::SignalSoldiersShouldMoveOut(float fpMinDistance, int32 iSoldiersSent)
{
	int32 iSoldier = 0;
	int32 iSoldierToSend = 0;
	float fpClosestFound = 0;
	if (iSoldiersSent == Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers.Num())
	{
		return;
	}
	fpClosestFound = 0;
	for (iSoldier = 0; iSoldier < Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers.Num(); iSoldier++)
	{
		if ((Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldier] != this) && (Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldier] != nullptr))
		{
			/*
			if (((VSize((Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldier].Pawn->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) < fpClosestFound) || (fpClosestFound == 0)) && (VSize((Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldier].Pawn->GetActorLocation() - npcpnTravelLocation->GetActorLocation())) >= fpMinDistance))
			{
				iSoldierToSend = iSoldier;
				fpClosestFound = VSize((Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldier].Pawn->GetActorLocation() - npcpnTravelLocation->GetActorLocation()));
			}
			*/
		}
	}
	if ((iSoldierToSend >= 0) && (Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend] != nullptr))
	{
		if (npcaiccCombatController != nullptr)
		{
			if (FMath::FRand() > 0.6)
			{
				if (FMath::FRand() > 0.5)
				{
					npcaiccCombatController->PlayEventAudio(Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend], "Taunt");
				}
				else
				{
					npcaiccCombatController->PlayEventAudio(Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend], "Attacking");
				}
			}
		}
		Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend]->Run(false);
		Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend]->npcpnTravelLocation = npcpnTravelLocation;
		Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend]->iHeadToLocationCoverOption = iSoldiersSent;
		Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend]->HeadToObjective(float(iSoldiersSent),false);
		Cast<ANPCBasePreCrewedVehicleControlle>(vVehicleCarryingNPC->Controller)->anpcbscVehicleSoldiers[iSoldierToSend] = nullptr;
		SignalSoldiersShouldMoveOut(fpClosestFound, (++iSoldiersSent));
	}
}

void ANPCBaseSoldierController::AICCMessageSuppressEnemy()
{
	if (GetPawn() == nullptr)
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
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 6) + (FMath::FRand() * 4));
		break;
	case 1:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 4));
		break;
	case 2:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 4));
		break;
	case 3:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 2));
		break;
	case 4:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 2) + (FMath::FRand() * 2));
		break;
	default:
		break;
	}
	(fpTimeToEndSuppressionFire += float(10));
	if (Enemy != nullptr)
	{
		SuppressiveFireRequested(this, Enemy->GetActorLocation());
	}
	else
	{
		SuppressiveFireRequested(this, vLastTarget);
	}
}

void ANPCBaseSoldierController::AICCMessageScanForEnemy()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && IsInState("Targeting"))
	{
		return;
	}
	sLastAICCMessage = "ScanForEnemy";
	Enemy = nullptr;
	fpTimeToLeaveFiringPosition = ((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 3));
	if (IsInState("SearchForTarget"))
	{
		return;
	}
	NPCChangeState("SearchForTarget","");
}

void ANPCBaseSoldierController::AICCMessageEngageEnemy()
{
	int32 iHighestThreatIndex = 0;
	if (GetPawn() == nullptr)
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
		fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + 6) + (FMath::FRand() * 4));
		break;
	case 1:
		fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 4));
		break;
	case 2:
		fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 4));
		break;
	case 3:
		fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 2));
		break;
	case 4:
		fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + 2) + (FMath::FRand() * 2));
		break;
	default:
		break;
	}
	fpTargetingStartTime = fpTimeToEndLastInterrupt;
	NPCLog("AICCMessageEngageEnemy() - Changing to Targeting");
	if (Enemy == nullptr)
	{
		NPCChangeState("SearchForTarget","");
		return;
	}
	if (LineOfSightTo(Enemy))
	{
		NPCChangeState("Targeting","");
	}
	else
	{
		NPCChangeState("SearchForTarget","");
	}
}

void ANPCBaseSoldierController::AICCMessageThrowFrag()
{
	if (GetPawn() == nullptr)
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
		vGrenadeTarget = Enemy->GetActorLocation();
	}
	if (ShouldThrowGrenade(false))
	{
		NPCChangeState("ThrowingGrenade","");
		return;
	}
	AICCMessageEngageEnemy();
}

void ANPCBaseSoldierController::AICCMessageThrowSmoke()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	sLastAICCMessage = "ThrowSmoke";
	if ((Enemy != nullptr) && ThrowSmokeGrenade(false))
	{
		vGrenadeTarget = Enemy->GetActorLocation();
		NPCChangeState("ThrowingGrenade","");
		return;
	}
	AICCMessageEngageEnemy();
}

void ANPCBaseSoldierController::AICCMessageAdvance()
{
	if (GetPawn() == nullptr)
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
	fpTimeToEndLastInterrupt = (GetWorld()->GetTimeSeconds() + float(60));
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
		break;
	}
	if (Enemy == nullptr)
	{
		Enemy = pawnLastEnemy;
	}
	if (Enemy != nullptr)
	{
		vLastTarget = Enemy->GetActorLocation();
		pawnLastHeard = Enemy;
		NPCChangeState("AdvanceOnEnemyLocation","");
	}
}

void ANPCBaseSoldierController::AICCMessageSwitchWeapons(bool bIgnoreBOP)
{
	if (GetPawn() == nullptr)
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
			break;
		}
	}
	if (((agpwPrimary != nullptr) && agpwPrimary->IsA(APistolWeapon::StaticClass())) || ((agpwSecondary != nullptr) && agpwSecondary->IsA(APistolWeapon::StaticClass())))
	{
		if (!IsInCover())
		{
			AICCMessageSeekCover();
		}
		else
		{
			npcaiccCombatController->ReportActionFailed(this);
		}
		return;
	}
	if (((GetPawn() != nullptr) && (agpwPrimary != nullptr)) && (agpwSecondary != nullptr))
	{
		//NPCLog(" Primary Weapon change from " + FString::FromInt(GetPawn()->Weapon) + " (primary weapon \"" + FString::FromInt(namePrimaryWeapon) + "\" and secondary: \"" + FString::FromInt(nameSecondaryWeapon) + "\"");
		NPCChangeState("SwapWeapons","");
	}
	else
	{
		NPCLog(" No alternate weapon found, trying reload or run away");
		/*
		if ((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon->GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon->GetCurrentAmmoType()->AmmoAmount == 0))
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
				npcaiccCombatController->ReportActionFailed(this);
			}
		}
		*/
	}
}

void ANPCBaseSoldierController::AICCMessagePursueEnemy()
{
	if (GetPawn() == nullptr)
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
	fpTimeToEndLastInterrupt = (GetWorld()->GetTimeSeconds() + float(60));
	NPCLog("AICCMessagePursueEnemy() entered");
	if (Enemy == nullptr)
	{
		Enemy = pawnLastEnemy;
	}
	if (Enemy != nullptr)
	{
		iNPCTacticalOrders = 300;
		vLastTarget = Enemy->GetActorLocation();
		NPCChangeState("PursueEnemy","");
	}
	else
	{
		npcaiccCombatController->ReportActionFailed(this);
	}
}

void ANPCBaseSoldierController::AICCMessageBreakOut()
{
	if (GetPawn() == nullptr)
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
}

void ANPCBaseSoldierController::AICCMessageFallBack()
{
	if (GetPawn() == nullptr)
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
		vTargetToSuppressLocation = Enemy->GetActorLocation();
	}
	else
	{
		if (pawnLastEnemy != nullptr)
		{
			vTargetToSuppressLocation = pawnLastEnemy->GetActorLocation();
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
		break;
	}
	NPCChangeState("FindCoverThenFight", "PopSmokeFirst");
}

void ANPCBaseSoldierController::AICCMessageFlankEnemy()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	npcaiccCombatController->ReportActionFailed(this);
}

void ANPCBaseSoldierController::AICCMessageShiftPosition()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		NPCChangeState("MoveToNewCamperPosition","");
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			NPCChangeState("MoveToNewHarassPosition","");
		}
		else
		{
			NPCChangeState("MoveToNewFiringPosition","");
		}
	}
	fpTimeToEndLastInterrupt = ((GetWorld()->GetTimeSeconds() + float(10)) + (FMath::FRand() * 10));
}

void ANPCBaseSoldierController::AICCMessageRushEnemy()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if ((iNPCCurrentOrders == 2) || (iNPCCurrentOrders == 5))
	{
		return;
	}
	if (Enemy != nullptr)
	{
		NPCChangeState("RushEnemy","");
	}
	else
	{
		NPCChangeState("SearchForTarget","");
	}
}

void ANPCBaseSoldierController::AICCMessageTauntEnemy()
{
	if (GetPawn() == nullptr)
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
		NPCChangeState("TauntEnemy","");
	}
	else
	{
		npcaiccCombatController->ReportActionFailed(this);
	}
}

void ANPCBaseSoldierController::AICCMessageSeekCover()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 2)
	{
		return;
	}
	if ((((Enemy != nullptr) && LineOfSightTo(Enemy)) && (pnCurrentLocation != nullptr)) && pnCurrentLocation->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		NPCChangeState("Targeting", "TurnToEnemy");
		return;
	}
	sLastAICCMessage = "SeekCover";
	Run(false);
	if (IsInState("Targeting"))
	{
		NPCChangeState("MoveToNewFiringPosition","");
	}
	else
	{
		pawnLastEnemy = Enemy;
		Enemy = nullptr;
		NPCChangeState("FindCover","");
	}
}

void ANPCBaseSoldierController::AICCMessageRequestMortar()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController->AddSupportRequestToQueue(this, 1, vLastTarget, pawnLastEnemy,false);
	}
}

void ANPCBaseSoldierController::AICCMessageDuckAndCover()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	sLastAICCMessage = "DuckAndCover";
	npcaiccCombatController->ReportActionFailed(this);
}

void ANPCBaseSoldierController::AICCMessageCollapse()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	sLastAICCMessage = "Collapse";
	Enemy = nullptr;
	NPCChangeState("Collapse","");
}

void ANPCBaseSoldierController::AICCMessageCrazyIvan()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	sLastAICCMessage = "CrazyIvan";
	NPCChangeState("CrazyIvan", "SpinAround");
}

void ANPCBaseSoldierController::AICCMessageSurrender()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	Enemy = nullptr;
	//Log("Surrender order received");
	NPCChangeState("Surrender","");
}

void ANPCBaseSoldierController::AICCMessageFireBlindly()
{
	if (GetPawn() == nullptr)
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
	/*
	if (((((GetPawn()->Weapon != nullptr) && Pawn.Weapon->IsA(ARocketWeapon::StaticClass())) || (pnCurrentLocation == nullptr)) || (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) == nullptr)) || (((((pnCurrentLocation != nullptr) && (Cast<ANPCFirePositionPathNode>(pnCurrentLocation) != nullptr)) && (!NPCFirePositionPathNode(pnCurrentLocation).bBlindFireLeft)) && (!NPCFirePositionPathNode(pnCurrentLocation).bBlindFireRight)) && (!NPCFirePositionPathNode(pnCurrentLocation).bIsFiringBlindlyOverHead)))
	{
		AICCMessageEngageEnemy();
		return;
	}
	pawnLastEnemy = Enemy;
	Enemy = nullptr;
	switch (iBalanceOfPowerState)
	{
	case 0:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 6) + (FMath::FRand() * 4));
		break;
	case 1:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 4));
		break;
	case 2:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 4));
		break;
	case 3:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 2));
		break;
	case 4:
		fpTimeToEndSuppressionFire = ((GetWorld()->GetTimeSeconds() + 2) + (FMath::FRand() * 2));
		break;
	default:
	}
	(fpTimeToEndSuppressionFire += float(10));
	fpTargetingStartTime = 0;
	fpTimeToEndLastInterrupt = (GetWorld()->GetTimeSeconds() + float(40));
	if (IsInState("FiringBlindly"))
	{
		return;
	}
	NPCChangeState("FiringBlindly");
	*/
}

void ANPCBaseSoldierController::AICCMessageCower()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	pawnLastEnemy = Enemy;
	Enemy = nullptr;
	switch (iBalanceOfPowerState)
	{
		case 0:
			fpTimeToEndCowering = ((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 3));
			break;
		case 1:
			fpTimeToEndCowering = ((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 3));
			break;
		case 2:
			fpTimeToEndCowering = ((GetWorld()->GetTimeSeconds() + 5) + (FMath::FRand() * 3));
			break;
		case 3:
			fpTimeToEndCowering = ((GetWorld()->GetTimeSeconds() + 6) + (FMath::FRand() * 3));
			break;
		case 4:
			fpTimeToEndCowering = ((GetWorld()->GetTimeSeconds() + 7) + (FMath::FRand() * 3));
			break;
		default:
			break;
	}
	if (IsInState("Cowering"))
	{
		return;
	}
	NPCChangeState("Cowering","");
}

void ANPCBaseSoldierController::AICCMessageReload()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	/*
	if (((((GetPawn() != nullptr) && (GetPawn()->Weapon != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType() != nullptr)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount != 0)) && (GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount >= (GetPawn()->Weapon.PickupAmmoCount / 2)))
	{
		NPCLog("Ignoring AICC reload command due to plenty of ammo in weapon");
		return;
	}
	if (((Enemy != nullptr) && LineOfSightTo(Enemy)) && (VSize((GetPawn()->GetActorLocation() - Enemy->GetActorLocation())) < float(250)))
	{
		if (!IsInCover())
		{
			NPCLog("AI not in cover but needs to reload and enemy very close, running to cover");
			NPCChangeState("FindCoverThenFight");
			return;
		}
	}
	NPCLog("AICC reload command with " + FString::FromInt(GetPawn()->Weapon.GetCurrentAmmoType().AmmoAmount) + " rounds in weapon");
	NPCChangeState("ReloadWeapon");
	*/
}

void ANPCBaseSoldierController::AICCReturnToPreviousState()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	//NPCChangeState(GetLastStateName());
}

void ANPCBaseSoldierController::AICCLiveGrenade()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	fpTimeToEndLastInterrupt = (GetWorld()->GetTimeSeconds() + float(20));
	Run(false);
	NPCChangeState("LiveGrenade","");
}

void ANPCBaseSoldierController::AICCActionComplete()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (IsInState("SearchForTarget") || IsInState("MoveToNewFiringPosition"))
	{
		return;
	}
	if (IsInCover())
	{
		NPCChangeState("SearchForTarget","");
	}
	else
	{
		NPCChangeState("MoveToNewFiringPosition","");
	}
}

void ANPCBaseSoldierController::AICCResumePreviousState()
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	if (iNPCCurrentOrders == 0)
	{
		NPCChangeState("ReturnToPatrol","");
	}
	else
	{
		if (iNPCCurrentOrders == 5)
		{
			NPCChangeState("MoveToNewFiringPosition","");
		}
		else
		{
			if (iNPCCurrentOrders == 2)
			{
				NPCChangeState("MoveToNewCamperPosition","");
			}
			else
			{
				//NPCChangeState(GetLastStateName(),"");
			}
		}
	}
}

void ANPCBaseSoldierController::AICCReturnToPatrol()
{
	NPCChangeState("ReturnToPatrol","");
}

void ANPCBaseSoldierController::AICCHeadToLocation(FVector vLocation, ANPCPathNode* npcpn)
{
	if (GetPawn() == nullptr)
	{
		return;
	}
	npcpnTravelLocation = npcpn;
	vTravelLocation = vLocation;
	NPCChangeState("HeadToTravelLocation","");
}

void ANPCBaseSoldierController::Destroyed()
{
	anpcfppnFiringPositions.RemoveAt(0, anpcfppnFiringPositions.Num());
	if (agpwPrimary != nullptr)
	{
		agpwPrimary->Destroy();
	}
	if (agpwSecondary != nullptr)
	{
		agpwSecondary->Destroy();
	}
	Super::Destroyed();
}

void ANPCBaseSoldierController::SaveTargetingStatusHistory(FString sStatus)
{
	int32 iHistoryIndex = 0;
	for (iHistoryIndex = (10 - 1); iHistoryIndex > 0; iHistoryIndex--)
	{
		asTargetingStatus[iHistoryIndex] = asTargetingStatus[(iHistoryIndex - 1)];
	}
	asTargetingStatus[0] = sStatus;
}
