// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCPackbotVehicleController/NPCPackbotVehicleController.h"

ANPCPackbotVehicleController::ANPCPackbotVehicleController()
{

}

/*
State NoVehicle
{
	Function BeginState()
	{
		NPCLog("NPC " $ string(Tag) $ " could not find a vehicle!");
	}
}
*/

/*
State InitializeVehicle
{
Begin:
	Log("Initialize Vehicle for class " $ string(VehicleClass));
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
	NPCLog("Vehicle spawned: " $ string(agpvVehicle) $ " for pawn: " $ string(Pawn) $ " from class: " $ string(VehicleClass));
	agpvVehicle.PeripheralVision=-99;
	sVehicleType=agpvVehicle.VehicleNameString;
	agpvVehicle.bDrawDriverInTP=DrawDriverInTP;
	agpvVehicle.TryToDrive(Pawn);
	agpvVehicle.PlayAnim("Second_To_First");
	NPCLog("Vehicle tried to drive it with pawn: " $ string(Pawn));
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
		local Vehicle V;
		ForEach AllActors(Class'Vehicle',V)
		{
			if (((((V != Pawn) && V.IsA("CROWS_HMMWV")) && (V.Health > 0)) && (VSize((V.Location - Pawn.Location)) < float(5000))) && LineOfSightTo(V))
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
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (pawnSeen.IsA("Vehicle") || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			StopCustomTimer("Turret_Scan");
			StopCustomTimer("Turret_Check_SeePlayer");
			SetCustomTimer((0.25 + FRand()),false,"SeePlayerTimer");
			TempEnemy=pawnSeen;
			Disable("SeePlayer");
		}
	}
	Event PreRanInto(Actor Other)
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
	if (pnTravelNode == None)
	{
		GotoState("Guarding");
	}
	agpvVehicle.DesiredSpeed=pnTravelNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed=pnTravelNode.fpMaxDesiredSpeed;
	MoveTo(pnTravelNode.Location,,true);
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
		Enemy=None;
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
		local Controller TempController;
		Enable("PreRanInto");
		TempController=Level.ControllerList;
		if (TempController != None)
		{
			if (((TempController.Pawn != None) && (TempController != Self)) && TempController.IsA("NPCBasePreCrewedVehicleController"))
			{
				Vehicle(Pawn).OtherVehicles.insert (Vehicle(Pawn).OtherVehicles.Length,1);
				Vehicle(Pawn).OtherVehicles[(Vehicle(Pawn).OtherVehicles.Length - 1)]=TempController.Pawn;
			}
			TempController=TempController.nextController;
		}
	}
	Function NotifyEnemyVehicleSpotted(Vector vLocation)
	{
		local RoadPathNode ClosestRoadNode;
		local RoadPathNode CurrentClosest;
		local RoadPathNode TestNode;
		local NavigationPoint N;
		if (Enemy == None)
		{
			N=Level.NavigationPointList;
			if (N != None)
			{
				if (N.IsA("RoadPathNode"))
				{
					TestNode=RoadPathNode(N);
					if (CurrentClosest == None)
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
				N=N.nextNavigationPoint;
			}
			if (CurrentClosest != None)
			{
				ClosestRoadNode=CurrentClosest;
			}
			ForcedDestination=ClosestRoadNode;
			GotoState("MoveToLocation");
			return;
		}
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if (pawnSeen.IsA("Vehicle") || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			SetCustomTimer((2.25 + FRand()),false,"SeePlayerTimer");
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
	Event bool NotifyBump(Actor Other)
	{
		NPCLog("Vehicle bumped into something (vehicle?): " $ string(Other));
		if (! Other.IsA("Projectile"))
		{
			agpvVehicle.ServerPlayHorn(0);
			if (Other.IsA("Vehicle"))
			{
				agpvVehicle.DesiredSpeed=0;
				agpvVehicle.MaxDesiredSpeed=0;
			}
		}
		return false;
	}
	Event PreRanInto(Actor Other)
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
		local Actor HitActor;
		GetAxes(Pawn.Rotation,X,Y,Z);
		if (FRand() < 0.5)
		{
			Dir=Normal(X);
		}
		else
		{
			Dir=Normal((X * float(-1)));
		}
		HitActor=Trace(HitLocation,HitNormal,(Pawn.Location + (float(512) * Dir)),Pawn.Location,false,Pawn.GetCollisionExtent());
		if (HitActor != None)
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
			if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != None) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchAsc) && bAscendingNodeDirection)
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1) > iCurrentDrivingPathNodeIndex) && bAutoReversePath)
				{
					bAscendingNodeDirection=false;
				}
				iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
			}
			else
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != None) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchDesc) && (! bAscendingNodeDirection))
				{
					iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
				}
			}
		}
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Length - 1))
			{
				iCurrentDrivingPathNodeIndex ++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Length > 0)
					{
						if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Length == 1)
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
					iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Length);
					NPCLog("Picking random path set: " $ string(iActivePatrolPath));
				}
			}
			NPCLog("");
			NPCLog("");
			NPCLog("Ascending pathnodes - new index: " $ string(iCurrentPathNodeIndex) $ " node: " $ string(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentPathNodeIndex].Tag));
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
				iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Length);
				NPCLog("Picking random path set: " $ string(iActivePatrolPath));
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Length > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection=true;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Length - 1);
				}
			}
			NPCLog("Descending pathnodes - new index: " $ string(iCurrentPathNodeIndex));
		}
		FindNextDrivingPatrolPathNode();
	}
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		if ((Enemy == None) && instigatedBy.Controller.IsA("HumanController"))
		{
			Enemy=instigatedBy;
			NotifyPlayerPawnInSight(Enemy);
			if (Vehicle(Pawn).bNPCDriverCanUseSmoke)
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
		if ((pnTravelNode != None) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
		{
			pnTravelNode.ExtraCost=pnTravelNode.Default.ExtraCost;
		}
		Enable("PreRanInto");
	}
	Function bool CloseEnoughToNavPoint(RoadPathNode rpn)
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
	Focus=None;
	Enable("PreRanInto");
	NPCLog("DrivingPatrol.Begin entered");
	FindNextDrivingPatrolPathNode();
	if (pnCurrentRoadPathNode == None)
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
	NPCLog("Heading to next major patrol node: " $ string(pnCurrentRoadPathNode) $ " Tag: " $ string(pnCurrentRoadPathNode.Tag));
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		iActivePatrolPath=Rand(avppDrivingPathsForPatrols.Length);
		bUseAlternatePath=(FRand() > 0.5);
		NPCLog("Alternate Driving path: " $ string(bUseAlternatePath));
	}
	NPCLog("Heading for " $ string(pnCurrentRoadPathNode.Tag) $ " At " $ string(Pawn.Location.X) $ "," $ string(Pawn.Location.Y) $ "," $ string(Pawn.Location.Z) $ " moving to driving node: " $ string(pnCurrentRoadPathNode.Tag) $ " at " $ string(pnCurrentRoadPathNode.Location.X) $ "," $ string(pnCurrentRoadPathNode.Location.Y) $ "," $ string(pnCurrentRoadPathNode.Location.Z) $ "  Distance: " $ string(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	agpvVehicle.DesiredSpeed=pnCurrentRoadPathNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed=pnCurrentRoadPathNode.fpMaxDesiredSpeed;
	NPCLog("Speed: " $ string(agpvVehicle.DesiredSpeed) $ ", max speed: " $ string(agpvVehicle.MaxDesiredSpeed));
	if (! bPatrol_NoPathfinding)
	{
		pnTravelNode=RoadPathNode(FindPathTo(pnCurrentRoadPathNode.Location));
	}
	if (pnTravelNode == None)
	{
		pnTravelNode=pnCurrentRoadPathNode;
	}
	RouteGoal=pnTravelNode;
	DebugMarkNextNode(pnTravelNode);
	NPCLog(string(Pawn) $ " Travel node: " $ string(pnTravelNode) $ " while heading to " $ string(pnCurrentRoadPathNode));
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
	NPCLog("Done with current node " $ string(pnCurrentRoadPathNode) $ " - about to move on");
	NPCLog("*****************************");
	NPCLog("");
	NPCLog("");
	DetermineNextPathNode();
	JL"MoveOn"
;
	if ((pnTravelNode != None) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost=pnTravelNode.Default.ExtraCost;
	}
	MoveTimer=-1;
	agpvVehicle.Throttle=0;
	agpvVehicle.Steering=0;
	agpvVehicle.Rise=0;
	Pawn.bRotateToDesired=false;
	NPCLog("Stopped Waiting");
	if ((pnTravelNode != None) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
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

