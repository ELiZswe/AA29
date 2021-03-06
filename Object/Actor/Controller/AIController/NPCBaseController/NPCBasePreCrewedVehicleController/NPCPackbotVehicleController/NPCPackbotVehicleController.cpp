// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCPackbotVehicleController/NPCPackbotVehicleController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"

ANPCPackbotVehicleController::ANPCPackbotVehicleController()
{
	nameArmPositions = {
		"First_To_Second",
		"Second_To_Third",
		"Third_To_Fourth",
		"Fourth_To_Fifth",
		"Fifth_To_Second",
		"Second_To_First",
		"First_To_Third",
		"Third_To_First"
	};
	bProp = true;
}

/*
State NoVehicle
{
	Function BeginState()
	{
		NPCLog("NPC " + FString::FromInt(Tag) + " could not find a vehicle!");
	}
}
*/

/*
State InitializeVehicle
{
Begin:
	Log("Initialize Vehicle for class " + FString::FromInt(VehicleClass));
	Pawn.SetCollision(false,false,false);
	if (VehicleTag != "None")
	{
		agpvVehicle=Spawn(class<Vehicle>(DynamicLoadObject("AGP_Vehicles.Packbot",Class'Class')),,VehicleTag,Location,Rotation,true,true);
	}
	else
	{
		agpvVehicle=Spawn(class<Vehicle>(DynamicLoadObject("AGP_Vehicles.Packbot",Class'Class')),,,Location,Rotation,true,true);
	}
	agpvVehicle.Health=999999;
	bGodMode=true;
	NPCLog("Vehicle spawned: " + FString::FromInt(agpvVehicle) + " for pawn: " + FString::FromInt(Pawn) + " from class: " + FString::FromInt(VehicleClass));
	agpvVehicle.PeripheralVision=-99;
	sVehicleType=agpvVehicle.VehicleNameString;
	agpvVehicle.bDrawDriverInTP=DrawDriverInTP;
	agpvVehicle.TryToDrive(Pawn);
	agpvVehicle.PlayAnim("Second_To_First");
	NPCLog("Vehicle tried to drive it with pawn: " + FString::FromInt(Pawn));
	agpPawnNPC.SetAnimAction("BH_Pilot");
	Sleep(3);
	if (iStartingPathNodeIndex > 0)
	{
		iCurrentDrivingPathNodeIndex=(iStartingPathNodeIndex - 1);
	}
	GotoState("DrivingPatrol");
}
*/

/*
State MoveToLocation
{
	Function BeginState()
	{
		Enable("PreRanInto");
	}
	Function Timer_CheckEmptyVehicleLocations()
	{
		AVehicle* V = nullptr;
		ForEach AllActors(AVehicle::StaticClass(),V)
		{
			if (((((V != Pawn) && V->IsA(ACROWS_HMMWV::StaticClass())) && (V.Health > 0)) && (VSize((V.Location - Pawn.Location)) < float(5000))) && LineOfSightTo(V))
			{
				StopCustomTimer("Turret_Scan");
				StopCustomTimer("Turret_Check_SeePlayer");
				agpvVehicle.Throttle=0;
				agpvVehicle.Steering=0;
				agpvVehicle.Rise=0;
				Pawn.bRotateToDesired=false;
				Enemy=V;
				Focus=Enemy;
				Pawn.NPC_Fire(0,Enemy);
				StopCustomTimer("Timer_CheckEmptyVehicleLocations");
				GotoState("MoveToLocation","AttackingEmptyVehicle");
			}
		}
	}
	Function EnemyNotVisible()
	{
		StartCoaxFiring(false);
		Pawn.StopWeaponFiring();
		SetCustomTimer(3,false,"EnemyNotVisibleTimer");
		Disable("EnemyNotVisible");
	}
	Function EnemyNotVisibleTimer()
	{
		Pawn.StopWeaponFiring();
		Enable("SeePlayer");
	}
	Function SeePlayerTimer()
	{
		Enemy=TempEnemy;
		Focus=Enemy;
		StartCoaxFiring(true);
		Pawn.NPC_Fire(0,Enemy);
		Enable("EnemyNotVisible");
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (pawnSeen->IsA(AVehicle::StaticClass()) || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			StopCustomTimer("Turret_Scan");
			StopCustomTimer("Turret_Check_SeePlayer");
			SetCustomTimer((0.25 + FMath::FRand()),false,"SeePlayerTimer");
			TempEnemy=pawnSeen;
			Disable("SeePlayer");
		}
	}
	Event PreRanInto(AActor* Other)
	{
		agpvVehicle.Throttle=0;
		agpvVehicle.Steering=0;
		agpvVehicle.Rise=0;
		Pawn.bRotateToDesired=false;
		GotoState("Guarding");
	}
Begin:
	SetCustomTimer(3,true,"Timer_CheckEmptyVehicleLocations");
	pnTravelNode=RoadPathNode(FindPathTo(ForcedDestination.Location));
	if (pnTravelNode == nullptr)
	{
		GotoState("Guarding");
	}
	agpvVehicle.DesiredSpeed=pnTravelNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed=pnTravelNode.fpMaxDesiredSpeed;
	MoveTo(pnTravelNode->GetActorLocation(),,true);
	if (VSize((Pawn.Location - ForcedDestination.Location)) < float(256))
	{
		GotoState("Guarding");
	}
	else
	{
		Sleep(0);
		JL"Begin"
;
	}
	if (Enemy.Health <= 0)
	{
		Enemy=nullptr;
		Pawn.StopWeaponFiring();
		Enable("SeePlayer");
		Disable("EnemyNotVisible");
		JL"Begin"
;
	}
	else
	{
		Sleep(0.5);
		JL"AttackingEmptyVehicle"
;
	}
}
*/

/*
State DrivingPatrol
{
	Function BeginState()
	{
		AController* TempController = nullptr;
		Enable("PreRanInto");
		for (TempController=Level.ControllerList; TempController!=nullptr; TempController=TempController.nextController)
		{
			if (((TempController.Pawn != nullptr) && (TempController != Self)) && TempController->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
			{
				Vehicle(Pawn).OtherVehicles.insert (Cast<AVehicle>(Pawn).OtherVehicles.Num(),1);
				Vehicle(Pawn).OtherVehicles[(Cast<AVehicle>(Pawn).OtherVehicles.Num() - 1)]=TempController.Pawn;
			}
		}
	}
	Function NotifyEnemyVehicleSpotted(Vector vLocation)
	{
		ARoadPathNode* ClosestRoadNode = nullptr;
		ARoadPathNode* CurrentClosest = nullptr;
		ARoadPathNode* TestNode = nullptr;
		ANavigationPoint* N = nullptr;
		if (Enemy == nullptr)
		{
			for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
			{
				if (N->IsA(ARoadPathNode::StaticClass()))
				{
					TestNode=RoadPathNode(N);
					if (CurrentClosest == nullptr)
					{
						CurrentClosest=TestNode;
					}
					else
					{
						if (VSize((CurrentClosest.Location - vLocation)) > VSize((TestNode.Location - vLocation)))
						{
							CurrentClosest=TestNode;
						}
					}
				}
			}
			if (CurrentClosest != nullptr)
			{
				ClosestRoadNode=CurrentClosest;
			}
			ForcedDestination=ClosestRoadNode;
			GotoState("MoveToLocation");
			return;
		}
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if (pawnSeen->IsA(AVehicle::StaticClass()) || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			SetCustomTimer((2.25 + FMath::FRand()),false,"SeePlayerTimer");
			TempEnemy=pawnSeen;
			Disable("SeePlayer");
		}
	}
	Function EnemyNotVisible()
	{
		StartCoaxFiring(false);
		Pawn.StopWeaponFiring();
		SetCustomTimer(3,false,"EnemyNotVisibleTimer");
		Disable("EnemyNotVisible");
	}
	Event bool NotifyBump(AActor* Other)
	{
		NPCLog("Vehicle bumped into something (vehicle?): " + FString::FromInt(Other));
		if (! Other->IsA(AProjectile::StaticClass()))
		{
			agpvVehicle.ServerPlayHorn(0);
			if (Other->IsA(AVehicle::StaticClass()))
			{
				agpvVehicle.DesiredSpeed=0;
				agpvVehicle.MaxDesiredSpeed=0;
			}
		}
		return false;
	}
	Event PreRanInto(AActor* Other)
	{
		agpvVehicle.Throttle=0;
		agpvVehicle.Steering=0;
		agpvVehicle.Rise=0;
		Pawn.bRotateToDesired=false;
		bRouteBlocked=true;
		GotoState("DrivingPatrol","StoppedWaiting");
	}
	Function bool GetFireDestination()
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector Dir = FVector(0,0,0);
		AActor* HitActor = nullptr;
		GetAxes(Pawn.Rotation,X,Y,Z);
		if (FMath::FRand() < 0.5)
		{
			Dir=Normal(X);
		}
		else
		{
			Dir=Normal((X * float(-1)));
		}
		HitActor=Trace(HitLocation,HitNormal,(Pawn.Location + (float(512) * Dir)),Pawn->GetActorLocation(),false,Pawn.GetCollisionExtent());
		if (HitActor != nullptr)
		{
			return false;
		}
		ForcedDestinationLocation=(Pawn.Location + (float(512) * Dir));
		return true;
	}
	Function DestinationOccupied()
	{
		Pawn.bAbortMoveIfGoalOccupied=false;
	}
	Function DetermineNextPathNode()
	{
		if (bUseAlternatePath)
		{
			if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != nullptr) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchAsc) && bAscendingNodeDirection)
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1) > iCurrentDrivingPathNodeIndex) && bAutoReversePath)
				{
					bAscendingNodeDirection=false;
				}
				iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
			}
			else
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != nullptr) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchDesc) && (! bAscendingNodeDirection))
				{
					iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
				}
			}
		}
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() - 1))
			{
				iCurrentDrivingPathNodeIndex ++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() > 0)
					{
						if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() == 1)
						{
							MoveTimer=-1;
							agpvVehicle.Throttle=0;
							agpvVehicle.Steering=0;
							agpvVehicle.Rise=0;
							Pawn.bRotateToDesired=false;
							bAutoReversePath=false;
							GotoState("Guarding");
							return;
						}
						NPCLog("Reversing direction back to descending");
						bAscendingNodeDirection=false;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=0;
					iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Num());
					NPCLog("Picking random path set: " + FString::FromInt(iActivePatrolPath));
				}
			}
			NPCLog("");
			NPCLog("");
			NPCLog("Ascending pathnodes - new index: " + FString::FromInt(iCurrentPathNodeIndex) + " node: " + FString::FromInt(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentPathNodeIndex].Tag));
		}
		else
		{
			if (iCurrentDrivingPathNodeIndex > 0)
			{
				iCurrentDrivingPathNodeIndex --;
			}
			else
			{
				NPCLog("Descending path hit when on first node, see about reverse or wrap");
				iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Num());
				NPCLog("Picking random path set: " + FString::FromInt(iActivePatrolPath));
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection=true;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() - 1);
				}
			}
			NPCLog("Descending pathnodes - new index: " + FString::FromInt(iCurrentPathNodeIndex));
		}
		FindNextDrivingPatrolPathNode();
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		if ((Enemy == nullptr) && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Enemy=instigatedBy;
			NotifyPlayerPawnInSight(Enemy);
			if (Cast<AVehicle>(Pawn).bNPCDriverCanUseSmoke)
			{
				if (agpvVehicle.Throttle > 0)
				{
					Vehicle(Pawn).StartSmokeGenerator();
				}
				else
				{
					MyGrenadeClass=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
					MyGrenade=Spawn(MyGrenadeClass,Pawn,,Pawn.Location);
					MyGrenade.Instigator=Pawn;
					MyGrenade._bTossNotThrow=true;
					MyGrenade.Fire(0);
					MyGrenade.ServerThrow();
				}
			}
		}
		NotifyTakeDamage(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function EndState()
	{
		if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
		{
			pnTravelNode.ExtraCost=pnTravelNode.Default.ExtraCost;
		}
		Enable("PreRanInto");
	}
	Function bool CloseEnoughToNavPoint(ARoadPathNode* rpn)
	{
		FVector vLocPN = FVector(0,0,0);
		FVector vLocPawn = FVector(0,0,0);
		vLocPawn=Pawn.Location;
		vLocPawn.Z=0;
		vLocPN=rpn.Location;
		vLocPN.Z=0;
		if (VSize((vLocPawn - vLocPN)) < float(50))
		{
			return true;
		}
		return false;
	}
Begin:
	ArmMovementTimer();
	Focus=nullptr;
	Enable("PreRanInto");
	NPCLog("DrivingPatrol.Begin entered");
	FindNextDrivingPatrolPathNode();
	if (pnCurrentRoadPathNode == nullptr)
	{
		NPCLog("No path node to move to!");
		GotoState("None");
		JL"End"
;
	}
	if (VSize((Pawn.Location - pnCurrentRoadPathNode.Location)) < Pawn.CollisionRadius)
	{
		DetermineNextPathNode();
	}
	NPCLog("");
	NPCLog("");
	NPCLog("*****************************");
	NPCLog("Heading to next major patrol node: " + FString::FromInt(pnCurrentRoadPathNode) + " Tag: " + FString::FromInt(pnCurrentRoadPathNode.Tag));
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Num());
		bUseAlternatePath=(FMath::FRand() > 0.5);
		NPCLog("Alternate Driving path: " + FString::FromInt(bUseAlternatePath));
	}
	NPCLog("Heading for " + FString::FromInt(pnCurrentRoadPathNode.Tag) + " At " + FString::FromInt(Pawn.Location.X) + "," + FString::FromInt(Pawn.Location.Y) + "," + FString::FromInt(Pawn.Location.Z) + " moving to driving node: " + FString::FromInt(pnCurrentRoadPathNode.Tag) + " at " + FString::FromInt(pnCurrentRoadPathNode.Location.X) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Y) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Z) + "  Distance: " + FString::FromInt(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	agpvVehicle.DesiredSpeed=pnCurrentRoadPathNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed=pnCurrentRoadPathNode.fpMaxDesiredSpeed;
	NPCLog("Speed: " + FString::FromInt(agpvVehicle.DesiredSpeed) + ", max speed: " + FString::FromInt(agpvVehicle.MaxDesiredSpeed));
	if (! bPatrol_NoPathfinding)
	{
		pnTravelNode=RoadPathNode(FindPathTo(pnCurrentRoadPathNode.Location));
	}
	if (pnTravelNode == nullptr)
	{
		pnTravelNode=pnCurrentRoadPathNode;
	}
	RouteGoal=pnTravelNode;
	DebugMarkNextNode(pnTravelNode);
	NPCLog(string(Pawn) + " Travel node: " + FString::FromInt(pnTravelNode) + " while heading to " + FString::FromInt(pnCurrentRoadPathNode));
	DebugDumpRoute();
	if (VSize(Velocity) == 0)
	{
		agpvVehicle.Throttle=0.25;
		agpvVehicle.DesiredSpeed=125;
	}
	else
	{
		agpvVehicle.Throttle=0.25;
		agpvVehicle.DesiredSpeed=125;
	}
	agpvVehicle.MaxDesiredSpeed=125;
	agpvVehicle.bTurnInPlace=true;
	MoveToward(pnTravelNode,,,false,false);
	if (! CloseEnoughToNavPoint(pnTravelNode))
	{
		JL"KeepMoving"
;
	}
	if (pnCurrentRoadPathNode != pnTravelNode)
	{
		JL"NextTravelNode"
;
	}
	NPCLog("Done with current node " + FString::FromInt(pnCurrentRoadPathNode) + " - about to move on");
	NPCLog("*****************************");
	NPCLog("");
	NPCLog("");
	DetermineNextPathNode();
	JL"MoveOn"
;
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost=pnTravelNode.Default.ExtraCost;
	}
	MoveTimer=-1;
	agpvVehicle.Throttle=0;
	agpvVehicle.Steering=0;
	agpvVehicle.Rise=0;
	Pawn.bRotateToDesired=false;
	NPCLog("Stopped Waiting");
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost=pnTravelNode.Default.ExtraCost;
	}
	if (bRouteBlocked)
	{
		Disable("PreRanInto");
		agpvVehicle.DesiredSpeed=350;
		agpvVehicle.MaxDesiredSpeed=450;
		MoveTo(GetAvoidanceLocation(),,true);
		Sleep((3 + float(Rand(3))));
		bRouteBlocked=false;
		Enable("PreRanInto");
		GotoState("DrivingPatrol","Begin");
	}
	else
	{
		GotoState("Guarding");
	}
}
*/

void ANPCPackbotVehicleController::AdjustStateByConfidenceLevel()
{
}

void ANPCPackbotVehicleController::DisplayDebug(UCanvas* C, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(C, YL, YPos);
	if (YL < 8)
	{
		YL = 10;
	}
	(YPos += YL);
	C.SetDrawColor(255, 255, 255);
	C.SetPos(4, YPos);
	C.DrawText("Coax aim error: " + FString::FromInt(fpCoAxAimError) + " Angle to target: " + FString::FromInt(fpCoAxAngleToTarget) + " Angle to last seen pawn: " + FString::FromInt(fpAngleToLastSeenPawn) + " Raw: " + FString::FromInt(fpRawAngleToLastSeenPawn) + " AngleUU: " + FString::FromInt(fpAngleToPlayerUU) + " Cone Angle: " + FString::FromInt(fpTurretMaxVisionCone) + "  Turret rotation: " + FString::FromInt(agpvVehicle.GetWeaponAim().Yaw));
	(YPos += YL);
	C.SetPos(4, YPos);
	C.DrawText("Current Enemy: " + FString::FromInt(Enemy) + " Current focus: " + FString::FromInt(Focus));
	*/
}

void ANPCPackbotVehicleController::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* C, float& YL, float& YPos, FColor NewColor)
{
	Super::DisplayDebugNoSpam(AGPHUD, C, YL, YPos, NewColor);
	/*
	if (YL < 8)
	{
		YL = 10;
	}
	(YPos += YL);
	C.SetDrawColor(255, 255, 255);
	C.SetPos(4, YPos);
	C.DrawText("Coax aim error: " + FString::FromInt(fpCoAxAimError) + " Angle to target: " + FString::FromInt(fpCoAxAngleToTarget) + "  Turret rotation: " + FString::FromInt(agpvVehicle.GetWeaponAim().Yaw));
	(YPos += YL);
	C.SetDrawColor(255, 255, 255);
	C.SetPos(4, YPos);
	C.DrawText("Angle to last seen pawn: " + FString::FromInt(fpAngleToLastSeenPawn) + " Raw: " + FString::FromInt(fpRawAngleToLastSeenPawn) + " AngleUU: " + FString::FromInt(fpAngleToPlayerUU));
	(YPos += YL);
	C.SetPos(4, YPos);
	C.DrawText("Current Enemy: " + FString::FromInt(Enemy) + " Current focus: " + FString::FromInt(Focus));
	*/
}

void ANPCPackbotVehicleController::Start()
{
	InitVehicle();
}

void ANPCPackbotVehicleController::InitVehicle()
{
	bStart = true;
	//GotoState("InitializeVehicle");
}

APathNode* ANPCPackbotVehicleController::GetPathnodeByTagString(FString sTag)
{
	ANavigationPoint* N = nullptr;
	if (sTag.Len() > 0)
	{
		for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
		{
			/*
			if (N->IsA(ARoadPathNode::StaticClass()) && (sTag == FString::FromInt(N.Tag)))
			{
				return PathNode(N);
			}
			*/
		}
	}
	return nullptr;
}

void ANPCPackbotVehicleController::PreloadPathNodeList()
{
	int32 iNode = 0;
	int32 iPatrolPathSet = 0;
	APathNode* pnFound = nullptr;
	/*
	for (iNode = 0; iNode < 99; iNode++)
	{
		pnFound = GetPathnodeByTagString(sNPCWaypointTag + "-" + FString::FromInt((iNode + 1)));
		if (pnFound == nullptr)
		{
		}
		if (iNode == 0)
		{
			avppDrivingPathsForPatrols.insert(avppDrivingPathsForPatrols.Num(), 1);
		}
		avppDrivingPathsForPatrols[(avppDrivingPathsForPatrols.Num() - 1)].apnDrivingPathNodesForPatrol.insert(iNode, 1);
		avppDrivingPathsForPatrols[(avppDrivingPathsForPatrols.Num() - 1)].apnDrivingPathNodesForPatrol[iNode] = RoadPathNode(pnFound);
		if (bDebugPath)
		{
			pnFound.bHidden = false;
		}
		NPCPathLog("Found path node for " + sNPCWaypointTag + "-" + FString::FromInt((iNode + 1)));
	}
	for (iPatrolPathSet = 0; iPatrolPathSet < 26; iPatrolPathSet++)
	{
		for (iNode = 0; iNode < 99; iNode++)
		{
			pnFound = GetPathnodeByTagString(sNPCWaypointTag + "-" + FString::FromInt((iNode + 1)) + Chr((65 + iPatrolPathSet)));
			if (pnFound == nullptr)
			{
			}
			if (iNode == 0)
			{
				avppDrivingPathsForPatrols.insert(avppDrivingPathsForPatrols.Num(), 1);
			}
			avppDrivingPathsForPatrols[(avppDrivingPathsForPatrols.Num() - 1)].apnDrivingPathNodesForPatrol.insert(iNode, 1);
			avppDrivingPathsForPatrols[(avppDrivingPathsForPatrols.Num() - 1)].apnDrivingPathNodesForPatrol[iNode] = RoadPathNode(pnFound);
			if (bDebugPath)
			{
				pnFound.bHidden = false;
			}
			NPCPathLog("Found path node for " + sNPCWaypointTag + "-" + FString::FromInt((iNode + 1)) + Chr((65 + iPatrolPathSet)));
		}
		if (iNode > 0)
		{
			NPCPathLog("Patrol path[" + FString::FromInt(iPatrolPathSet) + " has " + FString::FromInt(avppDrivingPathsForPatrols[0].apnDrivingPathNodesForPatrol.Num()) + " nodes");
		}
	}
	for (iPatrolPathSet = 0; iPatrolPathSet < avppDrivingPathsForPatrols.Num(); iPatrolPathSet++)
	{
		for (iNode = 0; iNode < avppDrivingPathsForPatrols[iPatrolPathSet].apnDrivingPathNodesForPatrol.Num(); iNode++)
		{
			NPCPathLog("Pathset[" + FString::FromInt(iPatrolPathSet) + "][" + FString::FromInt(iNode) + "] - " + FString::FromInt(avppDrivingPathsForPatrols[iPatrolPathSet].apnDrivingPathNodesForPatrol[iNode].Tag));
		}
	}
	*/
}

void ANPCPackbotVehicleController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
}

void ANPCPackbotVehicleController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void ANPCPackbotVehicleController::NotifyEnemyVehicleSpotted(FVector vLocation)
{
	//Log(string(this) + " received report of vehicle at " + FString::FromInt(vLocation));
}

ARoadPathNode* ANPCPackbotVehicleController::FindNextDrivingPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " + FString::FromInt((iCurrentDrivingPathNodeIndex + 1)));
	if (avppDrivingPathsForPatrols.Num() == 0)
	{
		NPCPathLog("FindNextDrivingPatrolPathNode() - No patrol paths have been defined");
		return nullptr;
	}
	if (iCurrentDrivingPathNodeIndex < avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num())
	{
		NPCPathLog("Found pathnode: " + FString::FromInt(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].Tag));
		//pnCurrentRoadPathNode = avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
		return pnCurrentRoadPathNode;
	}
	NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
	*/
	return nullptr;
}

/*
void ANPCPackbotVehicleController::Possess(APawn* aPawn)
{
	NPCLog(string(this) + " Possess() entered for " + FString::FromInt(aPawn));
	if (aPawn != nullptr)
	{
		if (aPawn->IsA("AAGP_Pawn::StaticClass()"))
		{
			NPCLog("Possess() entered for Vehicle");
			Possess(aPawn);
			NPCLog("Possess of pawn " + FString::FromInt(aPawn) + " with mesh: " + FString::FromInt(aPawn.Mesh));
			agpPawnNPC = Cast<AAGP_Pawn>(aPawn);
			aPawn.Controller = this;
			bGodMode = true;
			agpPawnNPC.SetCollision(false, false, false);
			agpPawnNPC.bCollideWorld = false;
			priFromNPCPawn = agpPawnNPC.PlayerReplicationInfo;
			NPCLog("PRI for pawn " + FString::FromInt(agpPawnNPC) + " is " + FString::FromInt(agpPawnNPC.PlayerReplicationInfo));
		}
		else
		{
			if (aPawn->IsA(AVehicle::StaticClass()))
			{
				Possess(aPawn);
				aPawn.PossessedBy(this);
				aPawn.Controller = this;
				aPawn.PlayerReplicationInfo = priFromNPCPawn;
				Pawn = aPawn;
			}
		}
	}
}
*/

/*
void ANPCPackbotVehicleController::UnPossess()
{
	if (Pawn->IsA("AAGP_Pawn::StaticClass()"))
	{
		NPCLog("Current pawn is AGP_Pawn, we're doing nothing there");
	}
}
*/

void ANPCPackbotVehicleController::NotifyTrigger(AActor* Other, APawn* EventInstigator)
{
	if (bTriggerStart && (GetStateName() == "InitializeVehicle"))
	{
		//GotoState("DrivingPatrol");
	}
}

void ANPCPackbotVehicleController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
}

void ANPCPackbotVehicleController::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
}

void ANPCPackbotVehicleController::ChangeOrders(int32 iNewOrders)
{
}

void ANPCPackbotVehicleController::ForceMoveTo(FName DestinationTag)
{
	ARoadPathNode* N = nullptr;
	/*
	ForEach AllActors(ARoadPathNode::StaticClass(), N)
	{
		if (N.Tag == DestinationTag)
		{
			ForcedDestination = N;
			GotoState("MoveToLocation");
		}
	}
	*/
}

void ANPCPackbotVehicleController::Timer_CheckEmptyVehicleLocations()
{
}

void ANPCPackbotVehicleController::ArmMovementTimer()
{
	float fpAnimDur = 0;
	/*
	fpAnimDur = Pawn.GetAnimDuration(nameArmPositions[iCurrentArmPosition]);
	(fpAnimDur += (FMath::FRand() * 3));
	agpvVehicle.PlayAnim(nameArmPositions[iCurrentArmPosition]);
	if (iCurrentArmPosition < (nameArmPositions.Num() - 1))
	{
		iCurrentArmPosition++;
	}
	else
	{
		iCurrentArmPosition = 0;
	}
	SetCustomTimer(fpAnimDur, false, "ArmMovementTimer");
	*/
}

float ANPCPackbotVehicleController::DirectionToGoal(FVector vLocGoal)
{
	float fpDirection = 0;
	float fpAngle = 0;
	FVector vRight = FVector(0, 0, 0);
	/*
	fpAngle = GetAngleToLocation(vLocGoal);
	vRight = Vector(agpvVehicle.Rotation);
	vRight = Normal((vRight Cross FVector(0, 0, 1)));
	fpDirection = (vRight Dot Normal((agpvVehicle.Location - vLocGoal)));
	Log("fpAngle: " + FString::FromInt(fpAngle) + " Direction: " + FString::FromInt(fpDirection));
	if (fpAngle == 1)
	{
		return 0;
	}
	if (fpAngle == -1)
	{
		return 180;
	}
	if ((fpDirection < 0) && (fpAngle > 0))
	{
		return (-Acos(fpAngle));
	}
	if ((fpDirection < 0) && (fpAngle <= 0))
	{
		return ((-Acos(fpAngle)) - float(90));
	}
	if ((fpDirection > 0) && (fpAngle > 0))
	{
		return Acos(fpAngle);
	}
	if ((fpDirection > 0) && (fpAngle < 0))
	{
		return (90 + Acos(fpAngle));
	}
	*/
	return 0;
}

FVector ANPCPackbotVehicleController::GetAvoidanceLocation()
{
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector AvoidanceLocation = FVector(0, 0, 0);
	/*
	GetAxes(Pawn.Rotation, X, Y, Z);
	AvoidanceLocation = (Pawn.Location + (Y * float(1024)));
	*/
	return AvoidanceLocation;
}

void ANPCPackbotVehicleController::DebugDumpRoute()
{
	int32 i = 0;
	NPCLog("******************************");
	NPCLog("Vehicle Route goal: " + RouteGoal->GetHumanReadableName() + ", distance: " + FString::FromInt(RouteDist));
	for (i = 0; i < 62; i++)
	{
		if (RouteCache[i] != nullptr)
		{
			//NPCLog("Route[ " + FString::FromInt(i) + "] => " + RouteCache[i]->GetHumanReadableName() + ": " + RouteCache[i]->Tags);
		}
	}
	NPCLog("******************************");
}

void ANPCPackbotVehicleController::NPCLog(FString sLogText)
{
	if ((agpvVehicle != nullptr) && (agpvVehicle->Driver != nullptr))
	{
		if (bDebugMode)
		{
			//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + FString::FromInt(agpvVehicle->Driver) + " " + sLogText);
		}
	}
	else
	{
		if (GetPawn() != nullptr)
		{
			if (bDebugMode)
			{
				//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + FString::FromInt(Pawn.Name) + " " + sLogText);
			}
		}
		else
		{
			if (bDebugMode)
			{
				//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + sLogText);
			}
		}
	}
}

void ANPCPackbotVehicleController::DebugMarkNextNode(APathNode* pnNext)
{
	if (bDebugPath)
	{
		if (rpnLastDebuggedNavPoint != nullptr)
		{
			rpnLastDebuggedNavPoint->DebugNavMarker(false,false);
			rpnLastDebuggedNavPoint = nullptr;
		}
		if (pnNext->IsA(ANPCRoadPathNode::StaticClass()))
		{
			Cast<ANPCRoadPathNode>(pnNext)->DebugNavMarker(true,false);
			rpnLastDebuggedNavPoint = Cast<ANPCRoadPathNode>(pnNext);
		}
	}
}
