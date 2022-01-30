// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/NPCAssaultLocation/NPCAssaultLocation.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/BMP1_APC/BMP1_APC.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR80APC/BTR80APC.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_ISoldier/NPC_ISoldier.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCNCOController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCOfficerController/NPCOfficerController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/T62A/T62A.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCBasePreCrewedVehicleControlle::ANPCBasePreCrewedVehicleControlle()
{

}


static const int32 ORDER_PATROL_AND_UNLOAD = 101;
static const int32 ORDER_UNLOAD = 100;
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
	Function ConfigureCoAx()
	{
		FCoords cBoneLocation = FCoords({});
		cBoneLocation = agpvVehicle.GetActiveWeaponSystem().GetBoneCoords("Muzzle_Bone");
		wpnCoaxRPK = Spawn(class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Weapon_T62_Coax",Class'Class')),agpvVehicle);
		wpnCoaxRPK.ThirdPersonActor = Spawn(wpnCoaxRPK.AttachmentClass,agpvVehicle.GetActiveWeaponSystem());
		wpnCoaxRPK.SetOwner(agpvVehicle);
		wpnCoaxRPK.GiveAmmo(nullptr);
		if (iCoAxRounds < 500)
		{
			iCoAxRounds = 500;
		}
		NPCLog("Rounds for coax: " $ string(iCoAxRounds));
		wpnCoaxRPK.GetCurrentAmmoType().AmmoAmount = iCoAxRounds;
		wpnCoaxRPK.ThirdPersonActor.Instigator = agpvVehicle;
		agpvVehicle.GetActiveWeaponSystem().AttachToBone(wpnCoaxRPK.ThirdPersonActor,"Muzzle_Bone");
	}
	Function EndState()
	{
	}
Begin:
	if (VehicleTag != "None")
	{
		agpvVehicle = Spawn(VehicleClass,,VehicleTag,Location,Rotation);
	}
	else
	{
		agpvVehicle = Spawn(VehicleClass,,,Location,Rotation);
	}
	NPCLog("Vehicle spawned: " $ string(agpvVehicle) $ " for pawn: " $ string(Pawn));
	if (bHasCoAxMachineGun)
	{
		ConfigureCoAx();
	}
	agpvVehicle.PeripheralVision = -99;
	sVehicleType = agpvVehicle.VehicleNameString;
	agpvVehicle.bDrawDriverInTP = DrawDriverInTP;
	agpvVehicle.TryToDrive(Pawn);
	NPCLog("Vehicle tried to drive it with pawn: " $ string(Pawn));
	agpPawnNPC.SetAnimAction("BH_Pilot");
	Sleep(3);
	if (iStartingPathNodeIndex > 0)
	{
		iCurrentDrivingPathNodeIndex = (iStartingPathNodeIndex - 1);
	}
	if (fpDelayedInitialOrderExecutionTime > 0)
	{
		SetCustomTimer(fpDelayedInitialOrderExecutionTime,false,"DelayedExecuteOrder");
	}
	else
	{
		if (ConvoyTag != "None")
		{
			if (!bConvoyLeader)
			{
				GotoState("TestFollow");
			}
		}
		if (iNPCCurrentOrders == 100)
		{
			UnloadPassengers();
		}
		else
		{
			if ((!bTriggerStart) && (((iNPCCurrentOrders == 0) || (iNPCCurrentOrders == 101)) || (iNPCCurrentOrders == 9)))
			{
				GotoState("DrivingPatrol");
			}
			else
			{
				if (iNPCCurrentOrders == 1)
				{
					GotoState("Guarding");
				}
			}
		}
	}
}
*/

/*
State TestHunt
{
	Event NotifyPlayerPawnInSight(APawn * pawnSeen)
	{
		StartCoaxFiring(true);
		SetCustomTimer((2.25 + FMath::FRand()),false,"SeePlayerTimer");
		TempEnemy = pawnSeen;
		Disable("SeePlayer");
	}
	Function BeginState()
	{
		if (!Pawn->isA(AT62A::StaticClass()))
		{
		}
		SetEnemy();
	}
	Function SetEnemy()
	{
		AHumanController* H = nullptr;
		ForEach AllActors(AHumanController::StaticClass(),H)
		{
			Enemy = H.Pawn;
			GOTO JL0028;
JL0028:
		}
	}
	Function NavigationPoint GetBestNode()
	{
		ANavigationPoint* NP = nullptr;
		ANavigationPoint* ClosestNavPoint = nullptr;
		AActor* HitActor = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		for (NP = Level.NavigationPointList; NP != nullptr; NP = NP.nextNavigationPoint)
		{
			if (ClosestNavPoint != nullptr)
			{
				HitActor = Trace(HitLocation,HitNormal,Enemy.Location,NP.Location,true);
				NPCLog(string(this) $ " GetBestNode HitActor: " $ string(HitActor));
				if ((HitActor == Enemy) && (VSize((Enemy.Location - HitLocation)) < float(1500)))
				{
					if (VSize((Enemy.Location - ClosestNavPoint.Location)) > VSize((Enemy.Location - NP.Location)))
					{
						ClosestNavPoint = NP;
					}
				}
			}
			else
			{
				HitActor = Trace(HitLocation,HitNormal,Enemy.Location,NP.Location,true);
				NPCLog(string(this) $ " GetBestNode HitActor: " $ string(HitActor));
				if ((HitActor == Enemy) && (VSize((Enemy.Location - HitLocation)) < float(1500)))
				{
					ClosestNavPoint = NP;
				}
			}
		}
		return ClosestNavPoint;
	}
Begin:
	Sleep(2);
	pnCurrentRoadPathNode = nullptr;
	pnTravelNode = nullptr;
	pnCurrentRoadPathNode = RoadPathNode(GetBestNode());
	if (pnCurrentRoadPathNode == nullptr)
	{
		MoveTimer = -1;
		agpvVehicle.Throttle = 0;
		agpvVehicle.Steering = 0;
		agpvVehicle.Rise = 0;
		Pawn.bRotateToDesired = false;
		Sleep(5);
		JL"Begin"
;
	}
	pnTravelNode = RoadPathNode(FindPathTo(pnCurrentRoadPathNode.Location));
	if (pnTravelNode == nullptr)
	{
		Sleep(5);
		JL"Begin"
;
	}
	else
	{
		agpvVehicle.DesiredSpeed = pnCurrentRoadPathNode.fpDesiredSpeed;
		agpvVehicle.MaxDesiredSpeed = pnCurrentRoadPathNode.fpMaxDesiredSpeed;
		MoveTo(pnTravelNode.Location,,true);
		if ((pnTravelNode != pnCurrentRoadPathNode) && (VSize((Pawn.Location - pnCurrentRoadPathNode.Location)) > (Pawn.CollisionRadius * 1.25)))
		{
			JL"BeginNoDelay"
;
		}
		else
		{
			MoveTimer = -1;
			agpvVehicle.Throttle = 0;
			agpvVehicle.Steering = 0;
			agpvVehicle.Rise = 0;
			Pawn.bRotateToDesired = false;
			Sleep(5);
		}
	}
}
*/

/*
State TestFollow
{
	Event PreRanInto(AActor * Other)
	{
		GotoState("TestFollow","StoppedWaiting");
	}
	Function SetConvoyLeader()
	{
		ANPCBasePreCrewedVehicleControlle* V = nullptr;
		ForEach AllActors(class'AGP.NPCBasePreCrewedVehicleController',V)
		{
			if ((V.ConvoyTag == ConvoyTag) && V.bConvoyLeader)
			{
				ConvoyLeader = Vehicle(V.Pawn);
			}
		}
	}
	Function FollowVehicle()
	{
		AVehicle* t = nullptr;
		if (!Pawn->isA(AT62A::StaticClass()))
		{
			ForEach AllActors(AVehicle::StaticClass(),t)
			{
				if (t->isA(AT62A::StaticClass()))
				{
					MyFollowVehicle = t;
				}
			}
		}
	}
Begin:
	Sleep(1.5);
	SetConvoyLeader();
	if (ConvoyLeader == nullptr)
	{
		JL"Begin"
;
	}
	agpvVehicle.DesiredSpeed = 250;
	agpvVehicle.MaxDesiredSpeed = 350;
	agpvVehicle.GroundSpeed = ConvoyLeader.GroundSpeed;
	if (VSize((ConvoyLeader.Location - Pawn.Location)) > float(1024))
	{
		if (VSize((ConvoyLeader.Location - Pawn.Location)) > float(3000))
		{
			pnTravelNode = RoadPathNode(FindPathTo(ConvoyLeader.Location));
			if (pnTravelNode == nullptr)
			{
				NPCLog(string(Pawn) $ " following NO PATH!!!!!!!!! :)");
			}
			else
			{
				NPCLog(string(Pawn) $ " following FOUND PATH: " $ string(pnTravelNode));
				SetCustomTimer(2.5,true,"Turret_Scan");
				MoveTo(pnTravelNode.Location);
				StopCustomTimer("Turret_Scan");
			}
			Sleep(0);
			JL"Following"
;
		}
		SetCustomTimer(2.5,true,"Turret_Scan");
		MoveTo((Pawn.Location + (Normal((ConvoyLeader.Location - Pawn.Location)) * float(64))));
		StopCustomTimer("Turret_Scan");
		Sleep(0);
		JL"Following"
;
	}
	else
	{
		(agpvVehicle.DesiredSpeed *= 0.75);
		(agpvVehicle.MaxDesiredSpeed *= 0.75);
		Sleep(1);
		JL"Following"
;
	}
	MoveTimer = -1;
	agpvVehicle.bDriving = false;
	agpvVehicle.Throttle = 0;
	agpvVehicle.Steering = 0;
	agpvVehicle.Rise = 0;
	Pawn.bRotateToDesired = false;
}
*/

/*
State Guarding
{
	Function BeginState()
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn * instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		if ((((Enemy == nullptr) || (Enemy.Health <= 0)) || (!LineOfSightTo(Enemy))) && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Enemy = instigatedBy;
			NotifyPlayerPawnInSight(Enemy);
		}
		Super::NotifyTakeDamage(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function Turret_Scan()
	{
		if (ScanOffset_Yaw == 40000)
		{
			ScanOffset_Yaw = -40000;
		}
		else
		{
			ScanOffset_Yaw = 40000;
		}
	}
	Function EnemyNotVisibleTimer()
	{
		Pawn.StopWeaponFiring();
		Enemy = nullptr;
		Enable("SeePlayer");
		GotoState("Guarding","Waiting");
	}
	Function SeePlayerTimer()
	{
		Enemy = TempEnemy;
		Focus = Enemy;
		StartCoaxFiring(true);
		GotoState("Guarding","Firing");
		Enable("EnemyNotVisible");
	}
	Event NotifyPlayerPawnInSight(APawn * pawnSeen)
	{
		if (pawnSeen->IsA(AVehicle::StaticClass()) || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			Disable("SeePlayer");
			Enemy = pawnSeen;
			Focus = Enemy;
			GotoState("Guarding","Firing");
			Enable("EnemyNotVisible");
		}
	}
	Function EnemyNotVisible()
	{
		StartCoaxFiring(false);
		Pawn.StopWeaponFiring();
		SetCustomTimer(3,false,"EnemyNotVisibleTimer");
		Disable("EnemyNotVisible");
	}
Begin:
	Sleep((FMath::FRand() + 1));
	if ((((Enemy == nullptr) || (Enemy.Health <= 0)) || ((Enemy.IsHumanControlled() && (!Enemy.bCollideWorld)) && (!Enemy->IsA(AVehicle::StaticClass())))) || (VSize((Enemy.Location - Pawn.Location)) > fpNPCWeaponEffectiveRange))
	{
		Enable("SeePlayer");
		Pawn.StopWeaponFiring();
		JL"Waiting"
;
	}
	Pawn.NPC_Fire(0,Enemy);
	Sleep(5);
	JL"Firing"
;
	Enable("SeePlayer");
	Pawn.StopWeaponFiring();
	Sleep(1);
	JL"Waiting"
;
	MoveTimer = -1;
	if (Pawn != nullptr)
	{
		Vehicle(Pawn).bDriving = false;
		Vehicle(Pawn).Throttle = 0;
		Vehicle(Pawn).Steering = 0;
		Vehicle(Pawn).Rise = 0;
		Pawn.bRotateToDesired = false;
	}
	if (GetLastStateName() != "UnloadSquad")
	{
		SetCustomTimer(9.5,true,"Turret_Scan");
		SetCustomTimer(0.7,true,"Turret_Check_SeePlayer");
		Focus = nullptr;
		Enemy = nullptr;
		EnemyNotVisibleTimer();
	}
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
				agpvVehicle.Throttle = 0;
				agpvVehicle.Steering = 0;
				agpvVehicle.Rise = 0;
				Pawn.bRotateToDesired = false;
				Enemy = V;
				Focus = Enemy;
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
		Enemy = TempEnemy;
		Focus = Enemy;
		StartCoaxFiring(true);
		Pawn.NPC_Fire(0,Enemy);
		Enable("EnemyNotVisible");
	}
	Event NotifyPlayerPawnInSight(APawn * pawnSeen)
	{
		if (pawnSeen->IsA(AVehicle::StaticClass()) || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			StopCustomTimer("Turret_Scan");
			StopCustomTimer("Turret_Check_SeePlayer");
			SetCustomTimer((0.25 + FMath::FRand()),false,"SeePlayerTimer");
			TempEnemy = pawnSeen;
			Disable("SeePlayer");
		}
	}
	Event PreRanInto(AActor * Other)
	{
		agpvVehicle.Throttle = 0;
		agpvVehicle.Steering = 0;
		agpvVehicle.Rise = 0;
		Pawn.bRotateToDesired = false;
		GotoState("Guarding");
	}
Begin:
	SetCustomTimer(3,true,"Timer_CheckEmptyVehicleLocations");
	pnTravelNode = RoadPathNode(FindPathTo(ForcedDestination.Location));
	if (pnTravelNode == nullptr)
	{
		GotoState("Guarding");
	}
	agpvVehicle.DesiredSpeed = pnTravelNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed = pnTravelNode.fpMaxDesiredSpeed;
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
		Enemy = nullptr;
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
		for (TempController = Level.ControllerList; TempController != nullptr; TempController = TempController.nextController)
		{
			if (((TempController.Pawn != nullptr) && (TempController != Self)) && TempController->isA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
			{
				Vehicle(Pawn).OtherVehicles.insert(Cast<AVehicle>(Pawn).OtherVehicles.Num(),1);
				Vehicle(Pawn).OtherVehicles[(Cast<AVehicle>(Pawn).OtherVehicles.Num() - 1)] = TempController.Pawn;
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
			for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
			{
				if (N->isA(ARoadPathNode::StaticClass()))
				{
					TestNode = RoadPathNode(N);
					if (CurrentClosest == nullptr)
					{
						CurrentClosest = TestNode;
					}
					else
					{
						if (VSize((CurrentClosest.Location - vLocation)) > VSize((TestNode.Location - vLocation)))
						{
							CurrentClosest = TestNode;
						}
					}
				}
			}
			if (CurrentClosest != nullptr)
			{
				ClosestRoadNode = CurrentClosest;
			}
			ForcedDestination = ClosestRoadNode;
			GotoState("MoveToLocation");
			return;
		}
	}
	Function SeePlayerTimer()
	{
		if ((iNPCCurrentOrders == 9) || (iNPCCurrentOrders == 101))
		{
			Enemy = TempEnemy;
			Focus = Enemy;
			StartCoaxFiring(true);
			Enable("EnemyNotVisible");
		}
		else
		{
			Global.afmifActiveRounds();
		}
	}
	Event NotifyPlayerPawnInSight(APawn * pawnSeen)
	{
		if (pawnSeen->IsA(AVehicle::StaticClass()) || (EvaluateEnemyThreat(pawnSeen,false) > 2))
		{
			if ((((pnTravelNode != nullptr) && pnTravelNode.bSafeToUnloadNPCs) && (anpcpsSquadPlayerStarts.Num() > 0)) && (VSize(Pawn.Velocity) > 0))
			{
				return;
			}
			SetCustomTimer((2.25 + FMath::FRand()),false,"SeePlayerTimer");
			TempEnemy = pawnSeen;
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
	Event bool NotifyBump(AActor * Other)
	{
		NPCLog("Vehicle bumped into something (vehicle?): " $ string(Other));
		if (!Other->IsA(AProjectile::StaticClass()))
		{
			agpvVehicle.ServerPlayHorn(0);
			if (Other->IsA(AVehicle::StaticClass()))
			{
				agpvVehicle.DesiredSpeed = 0;
				agpvVehicle.MaxDesiredSpeed = 0;
			}
		}
		return false;
	}
	Event PreRanInto(AActor * Other)
	{
		actActorInTheWay = Other;
		agpvVehicle.Throttle = 0;
		agpvVehicle.Steering = 0;
		agpvVehicle.Rise = 0;
		Pawn.bRotateToDesired = false;
		bRouteBlocked = true;
		GotoState("DrivingPatrol","StoppedWaiting");
	}
	Event WarnAboutToRunOverTeammate(AController * ctrlTeammate)
	{
		if (((Cast<ANPCBaseController>(ctrlTeammate) != nullptr) && (Cast<ANPCBaseController>(ctrlTeammate).Pawn != nullptr)) && (Cast<ANPCBaseController>(ctrlTeammate).iNPCTeamID == iNPCTeamID))
		{
			actActorInTheWay = NPCBaseController(ctrlTeammate).Pawn;
			agpvVehicle.Throttle = 0;
			agpvVehicle.Steering = 0;
			agpvVehicle.Rise = 0;
			Pawn.bRotateToDesired = false;
			bRouteBlocked = true;
			GotoState("DrivingPatrol","StoppedWaiting");
		}
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
			Dir = Normal(X);
		}
		else
		{
			Dir = Normal((X * float(-1)));
		}
		HitActor = Trace(HitLocation,HitNormal,(Pawn.Location + (float(512) * Dir)),Pawn.Location,false,Pawn.GetCollisionExtent());
		if (HitActor != nullptr)
		{
			return false;
		}
		ForcedDestinationLocation = (Pawn.Location + (float(512) * Dir));
		return true;
	}
	Function DestinationOccupied()
	{
		Pawn.bAbortMoveIfGoalOccupied = false;
	}
	Function DetermineNextPathNode()
	{
		if (bUseAlternatePath)
		{
			if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != nullptr) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchAsc) && bAscendingNodeDirection)
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1) > iCurrentDrivingPathNodeIndex) && bAutoReversePath)
				{
					bAscendingNodeDirection = false;
				}
				iCurrentDrivingPathNodeIndex = (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
			}
			else
			{
				if (((avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex] != nullptr) && avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].bPathBranchDesc) && (!bAscendingNodeDirection))
				{
					iCurrentDrivingPathNodeIndex = (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].iBranchIndex - 1);
				}
			}
		}
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() - 1))
			{
				iCurrentDrivingPathNodeIndex++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() > 0)
					{
						if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() == 1)
						{
							MoveTimer = -1;
							agpvVehicle.Throttle = 0;
							agpvVehicle.Steering = 0;
							agpvVehicle.Rise = 0;
							Pawn.bRotateToDesired = false;
							bAutoReversePath = false;
							GotoState("Guarding");
							return;
						}
						NPCLog("Reversing direction back to descending");
						bAscendingNodeDirection = false;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex = 0;
					iActivePatrolPath = Rand(avppDrivingPathsForPatrols.Num());
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
				iCurrentDrivingPathNodeIndex--;
			}
			else
			{
				NPCLog("Descending path hit when on first node, see about reverse or wrap");
				iActivePatrolPath = Rand(avppDrivingPathsForPatrols.Num());
				NPCLog("Picking random path set: " $ string(iActivePatrolPath));
				if (bAutoReversePath)
				{
					if (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection = true;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex = (avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() - 1);
				}
			}
			NPCLog("Descending pathnodes - new index: " $ string(iCurrentPathNodeIndex));
		}
		FindNextDrivingPatrolPathNode();
	}
	Function NotifyTakeDamage(int32 Damage, APawn * instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		if ((Enemy == nullptr) && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Enemy = instigatedBy;
			NotifyPlayerPawnInSight(Enemy);
			if (Cast<AVehicle>(Pawn).bNPCDriverCanUseSmoke)
			{
				if (agpvVehicle.Throttle > 0)
				{
					Vehicle(Pawn).StartSmokeGenerator();
				}
				else
				{
					MyGrenadeClass = class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
					MyGrenade = Spawn(MyGrenadeClass,Pawn,,Pawn.Location);
					MyGrenade.Instigator = Pawn;
					MyGrenade._bTossNotThrow = true;
					MyGrenade.Fire(0);
					MyGrenade.ServerThrow();
				}
			}
		}
		Super::NotifyTakeDamage(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	Function EndState()
	{
		if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
		{
			pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
		}
		Enable("PreRanInto");
	}
Begin:
	if (iNPCCurrentOrders == 9)
	{
		LocateAssaultLocation();
	}
	Focus = nullptr;
	Enable("PreRanInto");
	NPCLog("DrivingPatrol.Begin entered");
	Pawn.StopWeaponFiring();
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
	if (pnCurrentRoadPathNode == nullptr)
	{
		NPCLog("No path node to move to!");
		GotoState("None");
		JL"End"
;
	}
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("*****************************");
	NPCLog("Heading to next major patrol node: " $ string(pnCurrentRoadPathNode) $ " Tag: " $ string(pnCurrentRoadPathNode.Tag));
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		iActivePatrolPath = Rand(avppDrivingPathsForPatrols.Num());
		bUseAlternatePath = (FMath::FRand() > 0.5);
		NPCLog("Alternate Driving path: " $ string(bUseAlternatePath));
	}
	NPCLog("Heading for " $ string(pnCurrentRoadPathNode.Tag) $ " At " $ string(Pawn.Location.X) $ "," $ string(Pawn.Location.Y) $ "," $ string(Pawn.Location.Z) $ " moving to driving node: " $ string(pnCurrentRoadPathNode.Tag) $ " at " $ string(pnCurrentRoadPathNode.Location.X) $ "," $ string(pnCurrentRoadPathNode.Location.Y) $ "," $ string(pnCurrentRoadPathNode.Location.Z) $ "  Distance: " $ string(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	agpvVehicle.DesiredSpeed = pnCurrentRoadPathNode.fpDesiredSpeed;
	agpvVehicle.MaxDesiredSpeed = pnCurrentRoadPathNode.fpMaxDesiredSpeed;
	NPCLog("Speed: " $ string(agpvVehicle.DesiredSpeed) $ ", max speed: " $ string(agpvVehicle.MaxDesiredSpeed));
	agpvVehicle.TurnInPlaceThreshold = 0.77;
	if (((iNPCCurrentOrders == 9) || (iNPCCurrentOrders == 101)) && bSmokeOnAssault)
	{
		if (Cast<AVehicle>(Pawn).bNPCDriverCanUseSmoke)
		{
			Vehicle(Pawn).StartSmokeGenerator();
		}
	}
	if (!bPatrol_NoPathfinding)
	{
		pnTravelNode = RoadPathNode(FindPathTo(pnCurrentRoadPathNode.Location));
	}
	if (pnTravelNode == nullptr)
	{
		pnTravelNode = pnCurrentRoadPathNode;
	}
	RouteGoal = pnTravelNode;
	DebugMarkNextNode(pnTravelNode);
	NPCLog(string(Pawn) $ " Travel node: " $ string(pnTravelNode) $ " while heading to " $ string(pnCurrentRoadPathNode));
	DebugDumpRoute();
	SetCustomTimer(2.5,true,"Turret_Scan");
	SetCustomTimer(0.2,true,"Turret_Check_SeePlayer");
	Sleep(0);
	if ((VSize((agpvVehicle.Location - pnTravelNode.Location)) + float(250)) > (agpvVehicle.CollisionRadius * 3))
	{
		if (agpvVehicle->isA(AAGP_TreadCraft::StaticClass()))
		{
			NPCLog("Angle to next travel node: " $ string(GetAngleToLocation(pnTravelNode.Location)) $ " angle: " $ string(((GetAngleToLocation(pnTravelNode.Location) / 6.28) * 360)));
			agpvVehicle.bTurnInPlace = false;
			if ((GetAngleToLocation(pnTravelNode.Location) < 0) && (GetAngleToLocation(pnTravelNode.Location) > agpvVehicle.TurnInPlaceThreshold))
			{
				MoveTimer = -1;
				agpvVehicle.DesiredSpeed = 0;
				agpvVehicle.MaxDesiredSpeed = 0;
				agpvVehicle.Throttle = 0;
				agpvVehicle.Steering = 0;
				agpvVehicle.Rise = 0;
				agpvVehicle.bTurnInPlace = true;
				FocalPoint = pnTravelNode.Location;
				bRotateToDesired = true;
				FinishRotation();
				Focus = nullptr;
				agpvVehicle.bTurnInPlace = false;
				agpvVehicle.DesiredSpeed = pnCurrentRoadPathNode.fpDesiredSpeed;
				agpvVehicle.MaxDesiredSpeed = pnCurrentRoadPathNode.fpMaxDesiredSpeed;
			}
		}
		agpvVehicle.DesiredSpeed = pnCurrentRoadPathNode.fpDesiredSpeed;
		agpvVehicle.MaxDesiredSpeed = pnCurrentRoadPathNode.fpMaxDesiredSpeed;
		pnTravelNode.ExtraCost = 10000;
		MoveTo(pnTravelNode.Location,,true);
		pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
		NPCLog("Finished Movetoward for travel node: " $ string(pnTravelNode) $ " while heading to " $ string(pnCurrentRoadPathNode.Tag) $ " distance now: " $ string(VSize((agpvVehicle.Location - pnCurrentRoadPathNode.Location))) $ " collision radius: " $ string(agpvVehicle.CollisionRadius));
		NPCLog("Distance to travel node " $ string(VSize((agpvVehicle.Location - pnTravelNode.Location))));
		if (VSize((agpvVehicle.Location - pnTravelNode.Location)) > (agpvVehicle.CollisionRadius * 3))
		{
			JL"GetCloser"
;
		}
	}
	else
	{
		if (((pnCurrentRoadPathNode != pnTravelNode) && (RouteCache[1] != nullptr)) && (RouteCache[1] != pnTravelNode))
		{
			pnTravelNode = RoadPathNode(RouteCache[1]);
			pnTravelNode.ExtraCost = 10000;
			MoveTo(pnTravelNode.Location,,true);
			pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
		}
	}
	StopCustomTimer("Turret_Scan");
	StopCustomTimer("Turret_Check_SeePlayer");
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
	}
	if (iNPCCurrentOrders == 9)
	{
		NPCLog(string(agpvVehicle) $ " Assault vehicle distance to target: " $ string(VSize((vAssaultLocation - agpvVehicle.Location))) $ " current node is firing: " $ string(pnTravelNode.bFiringNode));
		if ((VSize((vAssaultLocation - agpvVehicle.Location)) < (fpNPCWeaponEffectiveRange / 2)) && pnTravelNode.bFiringNode)
		{
			agpvVehicle.Throttle = 0;
			agpvVehicle.Steering = 0;
			agpvVehicle.Rise = 0;
			Pawn.bRotateToDesired = false;
			GotoState("Guarding");
			JL"End"
;
		}
	}
	if (pnCurrentRoadPathNode.bStopHere && (VSize((Pawn.Location - pnCurrentRoadPathNode.Location)) <= (Pawn.CollisionRadius * 5.25)))
	{
		agpvVehicle.Throttle = 0;
		agpvVehicle.Steering = 0;
		agpvVehicle.Rise = 0;
		Pawn.bRotateToDesired = false;
		JL"StoppedWaiting"
;
	}
	if (pnCurrentRoadPathNode != pnTravelNode)
	{
		NPCLog("Still not really at location " $ string(pnCurrentRoadPathNode.Tag) $ ", trying again to move there, distance: " $ string(VSize((agpvVehicle.Location - pnCurrentRoadPathNode.Location))));
		JL"NextTravelNode"
;
	}
	NPCLog("Done with current node " $ string(pnCurrentRoadPathNode) $ " - about to move on");
	NPCLog("*****************************");
	NPCLog("");
	NPCLog("");
	NPCLog("");
	NPCLog("");
	DetermineNextPathNode();
	JL"MoveOn"
;
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
	}
	MoveTimer = -1;
	agpvVehicle.Throttle = 0;
	agpvVehicle.Steering = 0;
	agpvVehicle.Rise = 0;
	Pawn.bRotateToDesired = false;
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
	}
	StopCustomTimer("Turret_Scan");
	StopCustomTimer("Turret_Check_SeePlayer");
	if (Enemy != nullptr)
	{
		Focus = Enemy;
	}
	Sleep((FMath::FRand() + 1));
	if ((((Enemy == nullptr) || (Enemy.Health <= 0)) || ((Enemy.IsHumanControlled() && (!Enemy.bCollideWorld)) && (!Enemy->IsA(AVehicle::StaticClass())))) || (VSize((Enemy.Location - Pawn.Location)) > fpNPCWeaponEffectiveRange))
	{
		Enable("SeePlayer");
		Pawn.StopWeaponFiring();
		JL"MoveOn"
;
	}
	Pawn.NPC_Fire(0,Enemy);
	JL"Firing"
;
	NPCLog("Stopped Waiting entered");
	if ((pnTravelNode != nullptr) && (pnTravelNode.ExtraCost != pnTravelNode.Default.ExtraCost))
	{
		pnTravelNode.ExtraCost = pnTravelNode.Default.ExtraCost;
	}
	if (((iNPCCurrentOrders == 101) && pnTravelNode.bSafeToUnloadNPCs) && (!bRouteBlocked))
	{
		if (VSize((Pawn.Location - pnTravelNode.Location)) > float(500))
		{
			JL"GetCloser"
;
		}
		GotoState("UnloadSquad","Unloading");
		JL"End"
;
	}
	if (bRouteBlocked)
	{
		Disable("PreRanInto");
		if ((actActorInTheWay != nullptr) && actActorInTheWay->isA(ANPC_ISoldier::StaticClass()))
		{
			if ((((Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actActorInTheWay).Controller) != nullptr) && (Cast<AAGP_Pawn>(actActorInTheWay).Health > 0)) && (VSize(Cast<AAGP_Pawn>(actActorInTheWay).Velocity) < 1)) && (!NPCBaseSoldierController(Cast<AAGP_Pawn>(actActorInTheWay).Controller).IsInState("LiveGrenade")))
			{
				Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actActorInTheWay).Controller).GotoState("LiveGrenade");
			}
			Sleep((2.5 + FMath::FRand()));
			bRouteBlocked = false;
			actActorInTheWay = nullptr;
			Enable("PreRanInto");
			JL"GetCloser"
;
		}
		agpvVehicle.DesiredSpeed = 350;
		agpvVehicle.MaxDesiredSpeed = 450;
		MoveTo(GetAvoidanceLocation(),,true);
		Sleep((3 + float(Rand(3))));
		bRouteBlocked = false;
		Enable("PreRanInto");
		GotoState("DrivingPatrol","Begin");
	}
	else
	{
		GotoState("Guarding");
	}
}
*/

/*
State UnloadSquad
{
	Function NotifyTakeDamage(int32 Damage, APawn * instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
		if (Enemy == nullptr)
		{
			NotifyPlayerPawnInSight(instigatedBy);
		}
		if (bUnloadIfDamaged && (VSize(Velocity) > 20))
		{
			if (agpvVehicle.Health > 0)
			{
				GotoState("UnloadSquad","Unloading");
			}
		}
	}
	Function FiringTimer()
	{
		if (Enemy != nullptr)
		{
			SetActorRotation(rotator((Pawn.Location - Enemy.Location)));
			Focus = pnTravelNode;
			LastSeenPos = Enemy.Location;
			Pawn.NPC_Fire(0,Enemy);
		}
	}
	Event NotifyPlayerPawnInSight(APawn * pawnSeen)
	{
		if (Enemy != nullptr)
		{
		}
		SetCustomTimer(0.33,true,"FiringTimer");
		SetActorRotation(rotator((Pawn.Location - pawnSeen.Location)));
		Focus = pnTravelNode;
		LastSeenPos = pawnSeen.Location;
		Enemy = pawnSeen;
		StartCoaxFiring(true);
		Disable("SeePlayer");
		Enable("EnemyNotVisible");
	}
	Function EnemyNotVisible()
	{
		StartCoaxFiring(false);
		StopCustomTimer("FiringTimer");
		Pawn.StopWeaponFiring();
		SetCustomTimer(3,false,"EnemyNotVisibleTimer");
		Disable("EnemyNotVisible");
	}
	Function RoadPathNode FindNearestUnloadPoint()
	{
		ANavigationPoint* N = nullptr;
		ARoadPathNode* npcrpnClosest = nullptr;
		float fpClosestUnloadPoint = 0;
		int32 iSet = 0;
		int32 iNode = 0;
		bool bUseNamedNode = false;
		FString sNamedNode = "";
		sNamedNode = string(nameUnloadLocation);
		if (Len(sNamedNode) > 0)
		{
			bUseNamedNode = true;
		}
		for (iSet = 0; iSet < avppDrivingPathsForPatrols.Num(); iSet++)
		{
			for (iNode = 0; iNode < avppDrivingPathsForPatrols[iSet].apnDrivingPathNodesForPatrol.Num(); iNode++)
			{
				if (avppDrivingPathsForPatrols[iSet].apnDrivingPathNodesForPatrol[iNode].bSafeToUnloadNPCs)
				{
					return avppDrivingPathsForPatrols[iSet].apnDrivingPathNodesForPatrol[iNode];
				}
			}
		}
		for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
		{
			if (!N->isA(ARoadPathNode::StaticClass()))
			{
			}
			if (bUseNamedNode)
			{
				if (string(N.Tag) ~= sNamedNode)
				{
					return RoadPathNode(N);
				}
			}
			if (Cast<ARoadPathNode>(N).bSafeToUnloadNPCs)
			{
				if (npcrpnClosest == nullptr)
				{
					NPCLog("Found close unload pathnode: " $ string(N));
					npcrpnClosest = RoadPathNode(N);
					fpClosestUnloadPoint = VSize((Pawn.Location - npcrpnClosest.Location));
				}
				else
				{
					if (fpClosestUnloadPoint > VSize((Pawn.Location - RoadPathNode(N).Location)))
					{
						NPCLog("Found closer unload pathnode: " $ string(N));
						npcrpnClosest = RoadPathNode(N);
						fpClosestUnloadPoint = VSize((Pawn.Location - npcrpnClosest.Location));
					}
				}
			}
		}
		return npcrpnClosest;
	}
	Function OrderSoldiersToMoveOut()
	{
		int32 iSoldier = 0;
		if (anpcbscVehicleSoldiers.Num() == 0)
		{
			return;
		}
		for (iSoldier = 0; iSoldier < anpcbscVehicleSoldiers.Num(); iSoldier++)
		{
			if ((anpcbscVehicleSoldiers[iSoldier] != nullptr) && (anpcbscVehicleSoldiers[iSoldier]->isA(ANPCNCOController::StaticClass()) || anpcbscVehicleSoldiers[iSoldier]->isA(ANPCOfficerController::StaticClass())))
			{
				anpcbscVehicleSoldiers[iSoldier].MoveOutAfterExitingVehicle();
				return;
			}
		}
		for (iSoldier = 0; iSoldier < anpcbscVehicleSoldiers.Num(); iSoldier++)
		{
			anpcbscVehicleSoldiers[iSoldier].MoveOutAfterExitingVehicle();
		}
	}
Begin:
	if (fpMinDelayBeforeMovingOut > 0)
	{
		Sleep(fpMinDelayBeforeMovingOut);
	}
	npcrpnUnloadPoint = FindNearestUnloadPoint();
	NPCLog("Found unloading point to use of: " $ string(npcrpnUnloadPoint));
	if (npcrpnUnloadPoint != nullptr)
	{
		if (Cast<AVehicle>(Pawn).bNPCDriverCanUseSmoke)
		{
			Vehicle(Pawn).StartSmokeGenerator();
		}
		pnTravelNode = RoadPathNode(FindPathTo(npcrpnUnloadPoint.Location));
		if (pnTravelNode == nullptr)
		{
			pnTravelNode = npcrpnUnloadPoint;
		}
		DebugMarkNextNode(pnTravelNode);
		NPCLog("Travel node for unloading: " $ string(pnTravelNode) $ " while heading to " $ string(npcrpnUnloadPoint));
		DebugDumpRoute();
		SetCustomTimer(2.5,true,"Turret_Scan");
		SetCustomTimer(0.2,true,"Turret_Check_SeePlayer");
		agpvVehicle.DesiredSpeed = pnTravelNode.fpDesiredSpeed;
		agpvVehicle.MaxDesiredSpeed = pnTravelNode.fpMaxDesiredSpeed;
		MoveTo(pnTravelNode.Location,,true);
		NPCLog("Finished Movetoward for unload for travel node: " $ string(pnTravelNode) $ " while heading to " $ string(npcrpnUnloadPoint) $ " distance now: " $ string(VSize((Pawn.Location - npcrpnUnloadPoint.Location))) $ " collision radius: " $ string(Pawn.CollisionRadius));
		if ((pnTravelNode != npcrpnUnloadPoint) && (VSize((Pawn.Location - npcrpnUnloadPoint.Location)) > (Pawn.CollisionRadius * 1.25)))
		{
			JL"NextTravelNode"
;
		}
	}
	if (!bFireWhileUnloading)
	{
		StopCustomTimer("Turret_Scan");
		StopCustomTimer("Turret_Check_SeePlayer");
	}
	else
	{
		SetCustomTimer(2.5,true,"Turret_Scan");
		SetCustomTimer(0.2,true,"Turret_Check_SeePlayer");
	}
	agpvVehicle.Throttle = 0;
	agpvVehicle.Steering = 0;
	agpvVehicle.Rise = 0;
	Pawn.bRotateToDesired = false;
	if (VSize(agpvVehicle.Velocity) > 1)
	{
		Sleep(0.25);
	}
	MyGrenadeClass = class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
	twpSmokeGrenadeClass = class<ThrowWeaponPickup>(DynamicLoadObject("AGP_Inventory.PickupT_M83_Smoke",Class'Class'));
	MyGrenade = Spawn(MyGrenadeClass,Pawn,,Pawn.Location);
	if (Pawn->isA(ABMP1_APC::StaticClass()))
	{
		MyGrenade._PickupPtr = Spawn(twpSmokeGrenadeClass,Pawn,,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,32768,0)))) * float(250))),Pawn.Rotation);
	}
	else
	{
		MyGrenade._PickupPtr = Spawn(twpSmokeGrenadeClass,Pawn,,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,16384,0)))) * float(230))),Pawn.Rotation);
	}
	MyGrenade._PickupPtr.bAlwaysRelevant = true;
	MyGrenade.BlowUp();
	Sleep((8.5 + (FMath::FRand() * 3)));
	for (iPassengerIndex = 0; iPassengerIndex < anpcpsSquadPlayerStarts.Num(); iPassengerIndex++)
	{
		if (anpcpsSquadPlayerStarts[iPassengerIndex] == nullptr)
		{
		}
		if (Pawn.Health > 0)
		{
			if (Pawn->isA(ABMP1_APC::StaticClass()))
			{
				npcbscSpawnedPassenger = Cast<ANPCBaseSoldierController>(anpcpsSquadPlayerStarts[iPassengerIndex].CreateNPC(true,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,32768,0)))) * float(250))),(Pawn.Rotation + FRotator(0,32768,0)),false));
				NPCLog("Spawned passenger " $ string(npcbscSpawnedPassenger) $ " at " $ string(((Pawn.Location + FVector(0,0,20)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,32768,0)))) * float(250)))));
			}
			else
			{
				if (Pawn->isA(ABTR80APC::StaticClass()))
				{
					npcbscSpawnedPassenger = Cast<ANPCBaseSoldierController>(anpcpsSquadPlayerStarts[iPassengerIndex].CreateNPC(true,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,16384,0)))) * float(230))),(Pawn.Rotation + FRotator(0,16384,0)),false));
					NPCLog("Spawned BTR passenger " $ string(npcbscSpawnedPassenger) $ " at " $ string(((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,16384,0)))) * float(225)))));
				}
				else
				{
					npcbscSpawnedPassenger = Cast<ANPCBaseSoldierController>(anpcpsSquadPlayerStarts[iPassengerIndex].CreateNPC(true,(Pawn.Location + (Vector(Normalize((Pawn.Rotation + FRotator(0,16384,0)))) * float(50))),Pawn.Rotation,false));
				}
			}
			anpcpsSquadPlayerStarts[iPassengerIndex] = nullptr;
			anpcbscVehicleSoldiers.insert(0,1);
			anpcbscVehicleSoldiers[0] = npcbscSpawnedPassenger;
			npcbscSpawnedPassenger.fpExitingVehicleDepartureAngle = ((float(iPassengerIndex) * 0.25) + 0.4);
			npcbscSpawnedPassenger.ExitSquadVehicle(Cast<AVehicle>(Pawn));
			Sleep((2 + (FMath::FRand() * 2)));
		}
		if (((iPassengerIndex > 0) && ((float(iPassengerIndex) % 2) == 0)) && (iPassengerIndex < (anpcpsSquadPlayerStarts.Num() - 1)))
		{
			MyGrenade = Spawn(MyGrenadeClass,Pawn,,Pawn.Location);
			if (Pawn->isA(ABMP1_APC::StaticClass()))
			{
				MyGrenade._PickupPtr = Spawn(twpSmokeGrenadeClass,Pawn,,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,32768,0)))) * float(250))),Pawn.Rotation);
			}
			else
			{
				MyGrenade._PickupPtr = Spawn(twpSmokeGrenadeClass,Pawn,,((Pawn.Location + FVector(0,0,25)) + (Vector(Normalize((Pawn.Rotation + FRotator(0,16384,0)))) * float(230))),Pawn.Rotation);
			}
			MyGrenade._PickupPtr.bAlwaysRelevant = true;
			MyGrenade.BlowUp();
		}
	}
	Sleep((fpMinDelayBeforeMovingOut + (FMath::FRand() * 3)));
	Vehicle(Pawn).StopSmokeGenerator();
	OrderSoldiersToMoveOut();
	Sleep(10);
	GotoState(namePostUnloadState);
}
*/

void ANPCBasePreCrewedVehicleControlle::AdjustStateByConfidenceLevel()
{
}

void ANPCBasePreCrewedVehicleControlle::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	if (YL < 8)
	{
		YL = 10;
	}
	(YPos += YL);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Coax aim error: " $ string(fpCoAxAimError) $ " Angle to target: " $ string(fpCoAxAngleToTarget) $ " Angle to last seen pawn: " $ string(fpAngleToLastSeenPawn) $ " Raw: " $ string(fpRawAngleToLastSeenPawn) $ " AngleUU: " $ string(fpAngleToPlayerUU) $ " Cone Angle: " $ string(fpTurretMaxVisionCone) $ "  Turret rotation: " $ string(agpvVehicle.GetWeaponAim().Yaw));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current Enemy: " $ string(Enemy) $ " Current focus: " $ string(Focus));
	*/
}

void ANPCBasePreCrewedVehicleControlle::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* Canvas, float& YL, float& YPos, FColor NewColor)
{
	/*
	Super::DisplayDebugNoSpam(AGPHUD, Canvas, YL, YPos, NewColor);
	if (YL < 8)
	{
		YL = 10;
	}
	(YPos += YL);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Coax aim error: " $ string(fpCoAxAimError) $ " Angle to target: " $ string(fpCoAxAngleToTarget) $ "  Turret rotation: " $ string(agpvVehicle.GetWeaponAim().Yaw));
	(YPos += YL);
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Angle to last seen pawn: " $ string(fpAngleToLastSeenPawn) $ " Raw: " $ string(fpRawAngleToLastSeenPawn) $ " AngleUU: " $ string(fpAngleToPlayerUU));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current Enemy: " $ string(Enemy) $ " Current focus: " $ string(Focus));
	*/
}

void ANPCBasePreCrewedVehicleControlle::Start()
{
	InitVehicle();
}

void ANPCBasePreCrewedVehicleControlle::InitVehicle()
{
	bStart = true;
	//GotoState("InitializeVehicle");
}

APathNode* ANPCBasePreCrewedVehicleControlle::GetPathnodeByTagString(FString sTag)
{
	ANavigationPoint* N = nullptr;

	if (sTag.Len() > 0)
	{
		for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
		{
			/*
			if (N->IsA(ARoadPathNode::StaticClass()) && (sTag == string(N.Tag)))
			{
				return Cast<APathNode>(N);
			}
			*/
		}
	}
	return nullptr;
}

void ANPCBasePreCrewedVehicleControlle::PreloadPathNodeList()
{
	int32 iNode = 0;
	int32 iPatrolPathSet = 0;
	APathNode* pnFound = nullptr;
	/*
	for (iNode = 0; iNode < 99; iNode++)
	{
		pnFound = GetPathnodeByTagString(sNPCWaypointTag $ "-" $ string((iNode + 1)));
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
		NPCPathLog("Found path node for " $ sNPCWaypointTag $ "-" $ string((iNode + 1)));
	}
	for (iPatrolPathSet = 0; iPatrolPathSet < 26; iPatrolPathSet++)
	{
		for (iNode = 0; iNode < 99; iNode++)
		{
			pnFound = GetPathnodeByTagString(sNPCWaypointTag $ "-" $ string((iNode + 1)) $ Chr((65 + iPatrolPathSet)));
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
			NPCPathLog("Found path node for " $ sNPCWaypointTag $ "-" $ string((iNode + 1)) $ Chr((65 + iPatrolPathSet)));
		}
		if (iNode > 0)
		{
			NPCPathLog("Patrol path[" $ string(iPatrolPathSet) $ " has " $ string(avppDrivingPathsForPatrols[0].apnDrivingPathNodesForPatrol.Num()) $ " nodes");
		}
	}
	for (iPatrolPathSet = 0; iPatrolPathSet < avppDrivingPathsForPatrols.Num(); iPatrolPathSet++)
	{
		for (iNode = 0; iNode < avppDrivingPathsForPatrols[iPatrolPathSet].apnDrivingPathNodesForPatrol.Num(); iNode++)
		{
			NPCPathLog("Pathset[" $ string(iPatrolPathSet) $ "][" $ string(iNode) $ "] - " $ string(avppDrivingPathsForPatrols[iPatrolPathSet].apnDrivingPathNodesForPatrol[iNode].Tag));
		}
	}
	*/
}

void ANPCBasePreCrewedVehicleControlle::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
}

void ANPCBasePreCrewedVehicleControlle::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void ANPCBasePreCrewedVehicleControlle::NotifyEnemyVehicleSpotted(FVector vLocation)
{
}

ARoadPathNode* ANPCBasePreCrewedVehicleControlle::FindNextDrivingPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " $ string((iCurrentDrivingPathNodeIndex + 1)));
	if (avppDrivingPathsForPatrols.Num() == 0)
	{
		NPCPathLog("FindNextDrivingPatrolPathNode() - No patrol paths have been defined");
		return nullptr;
	}
	if (iCurrentDrivingPathNodeIndex < avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol.Num())
	{
		NPCPathLog("Found pathnode: " $ string(avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].Tag));
		pnCurrentRoadPathNode = avppDrivingPathsForPatrols[iActivePatrolPath].apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
		return pnCurrentRoadPathNode;
	}
	NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
	*/
	return nullptr;
}

/*
void ANPCBasePreCrewedVehicleControlle::Possess(APawn* aPawn)
{
	NPCLog(string(this) $ " Possess() entered for " $ string(aPawn));
	if (aPawn != nullptr)
	{
		if (aPawn->IsA("AAGP_Pawn::StaticClass()"))
		{
			NPCLog("Possess() entered for Vehicle");
			Super::Possess(aPawn);
			NPCLog("Possess of pawn " $ string(aPawn) $ " with mesh: " $ string(aPawn.Mesh));
			agpPawnNPC = Cast<AAGP_Pawn>(aPawn);
			aPawn.Controller = this;
			bGodMode = true;
			agpPawnNPC.SetCollision(false, false, false);
			agpPawnNPC.bCollideWorld = false;
			priFromNPCPawn = agpPawnNPC.PlayerReplicationInfo;
			NPCLog("PRI for pawn " $ string(agpPawnNPC) $ " is " $ string(agpPawnNPC.PlayerReplicationInfo));
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
void ANPCBasePreCrewedVehicleControlle::ANPCBasePreCrewedVehicleControlle::UnPossess()
{
	if (Pawn->IsA("AAGP_Pawn::StaticClass()"))
	{
		NPCLog("Current pawn is AGP_Pawn, we're doing nothing there");
	}
}
*/

void ANPCBasePreCrewedVehicleControlle::DelayedExecuteOrder()
{
	/*
	if (ConvoyTag != "None")
	{
		if (!bConvoyLeader)
		{
			GotoState("TestFollow");
		}
	}
	if (iNPCCurrentOrders == 100)
	{
		UnloadPassengers();
	}
	else
	{
		if ((!bTriggerStart) && (((iNPCCurrentOrders == 0) || (iNPCCurrentOrders == 101)) || (iNPCCurrentOrders == 9)))
		{
			GotoState("DrivingPatrol");
		}
		else
		{
			if (iNPCCurrentOrders == 1)
			{
				GotoState("Guarding");
			}
		}
	}
	*/
}

void ANPCBasePreCrewedVehicleControlle::NotifyTrigger(AActor* Other, APawn* EventInstigator)
{
	if (bTriggerStart && (GetStateName() == "InitializeVehicle"))
	{
		//GotoState("DrivingPatrol");
	}
}

void ANPCBasePreCrewedVehicleControlle::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
}

void ANPCBasePreCrewedVehicleControlle::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
}

void ANPCBasePreCrewedVehicleControlle::SeePlayer(APawn* Seen)
{
	/*
	if (agpvVehicle == nullptr)
	{
		return;
	}
	if (agpvVehicle.Health <= 0)
	{
		return;
	}
	fpDistanceToLastSeenPawn = VSize((Seen.Location - agpvVehicle.Location));
	fpRawAngleToLastSeenPawn = (Normal(Vector(agpvVehicle.GetWeaponAim())) Dot Normal((Pawn.Location - Seen.Location)));
	fpAngleToPlayerUU = (Acos(fpRawAngleToLastSeenPawn) * 182);
	fpTurretRotation = float(agpvVehicle.GetWeaponAim().Yaw);
	if ((Seen.IsHumanControlled() && (!Seen.bCollideWorld)) && (!Seen->IsA(AVehicle::StaticClass())))
	{
		return;
	}
	if (CanSeePlayer(agpvVehicle.GetWeaponAim(), Seen))
	{
		return;
	}
	else
	{
		CanSeePlayer(Pawn.Rotation, Seen);
	}
	*/
}

bool ANPCBasePreCrewedVehicleControlle::CanSeePlayer(FRotator rotView, APawn* Seen)
{
	bool bPawnNoticed = false;
	float fpDistanceToSeenPawn = 0;
	float fpNPCFuzzyViewingDistance = 0;
	float fpNPCAlwaysNoticesDistance = 0;
	float fpChanceOfLookingLeftRight = 0;
	float fpAngleToPlayer = 0;
	/*
	DebugLog(DEBUG_AIVehicle, "Seeplayer for pawn: " $ string(Seen) $ " NPC's pawn: " $ string(Pawn));
	fpAngleToPlayer = (Acos(fpRawAngleToLastSeenPawn) * 182);
	DebugLog(DEBUG_AIVehicle, "Saw player: " $ string(Seen) $ " NPC pawn health: " $ string(Pawn.Health));
	DebugLog(DEBUG_AIVehicle, "Seen humancontrolled: " $ string(Seen.IsHumanControlled()) $ ", collide with world: " $ string(Seen.bCollideWorld) $ " is a vehicle: " $ string(Seen->IsA(AVehicle::StaticClass())));
	if (!Seen->IsA(AVehicle::StaticClass()))
	{
		if ((fpRawAngleToLastSeenPawn < 0) && (FMath::FRand() < 0.33))
		{
			return false;
		}
	}
	fpTurretMaxVisionCone = (fpNPCVisionConeAngle + (FMath::FRand() * float(1024)));
	if (fpTurretMaxVisionCone > GetMaxVisionCone())
	{
		fpTurretMaxVisionCone = GetMaxVisionCone();
	}
	fpChanceOfLookingLeftRight = FMath::FRand();
	if (fpChanceOfLookingLeftRight > 0.7)
	{
		(rotView.Yaw += 8192);
	}
	else
	{
		if (fpChanceOfLookingLeftRight < 0.3)
		{
			(rotView.Yaw -= 8192);
		}
	}
	if (rotView.Yaw < 0)
	{
		(rotView.Yaw += 65535);
	}
	else
	{
		if (rotView.Yaw > 65535)
		{
			(rotView.Yaw -= 65535);
		}
	}
	fpAngleToPlayer = (Normal(Vector(rotView)) Dot Normal((agpvVehicle.Location - Seen.Location)));
	fpAngleToPlayer = (Acos(fpAngleToPlayer) * 182);
	fpDistanceToSeenPawn = VSize((Seen.Location - agpvVehicle.Location));
	if (fpAngleToPlayer > fpTurretMaxVisionCone)
	{
		return false;
	}
	NPCLog("Pawn in vision cone! Distance to pawn from NPC: " $ string(VSize((Seen.Location - agpvVehicle.Location))));
	bPawnNoticed = false;
	if (((Level.DistanceFogStart * 0.75) < fpNPCMaxVisualRange) && (!bIgnoreFogDistance))
	{
		if (!Level.bIndoorZone)
		{
			fpNPCFuzzyViewingDistance = (Level.DistanceFogStart * 0.75);
		}
		fpNPCFuzzyViewingDistance = ((fpNPCFuzzyViewingDistance * fpNodeVisionRangeModifier) + (FMath::FRand() * (fpNPCMaxVisualRange * 0.1)));
	}
	else
	{
		fpNPCFuzzyViewingDistance = ((fpNPCMaxVisualRange * fpNodeVisionRangeModifier) + (FMath::FRand() * (fpNPCMaxVisualRange * 0.1)));
	}
	if (Enemy == Seen)
	{
		(fpNPCFuzzyViewingDistance += (FMath::FRand() * (fpNPCMaxVisualRange * 0.2)));
		if (fpDistanceToSeenPawn < fpNPCFuzzyViewingDistance)
		{
			bPawnNoticed = true;
		}
	}
	if (Seen->IsA(AVehicle::StaticClass()))
	{
		if ((fpDistanceToSeenPawn < Level.DistanceFogStart) && (fpNPCMaxVisualRange < Level.DistanceFogStart))
		{
			fpNPCFuzzyViewingDistance = (fpNPCMaxVisualRange * 2.5);
		}
		if (fpNPCFuzzyViewingDistance < float(12500))
		{
			fpNPCFuzzyViewingDistance = 12500;
		}
		if (fpNPCFuzzyViewingDistance > Level.DistanceFogStart)
		{
			fpNPCFuzzyViewingDistance = Level.DistanceFogStart;
		}
		bPawnNoticed = true;
	}
	if ((fpDistanceToSeenPawn < fpNPCFuzzyViewingDistance) && (!bPawnNoticed))
	{
		if (Seen.bIsCrouched)
		{
			(fpNPCFuzzyViewingDistance *= 0.9);
		}
		else
		{
			if (Seen.bIsProne)
			{
				(fpNPCFuzzyViewingDistance *= 0.75);
			}
		}
		fpNPCAlwaysNoticesDistance = (fpNPCFuzzyViewingDistance * 0.8);
		if (fpDistanceToSeenPawn < fpNPCAlwaysNoticesDistance)
		{
			bPawnNoticed = true;
		}
		else
		{
			if ((FMath::FRand() * 0.7) > (fpDistanceToSeenPawn / fpNPCFuzzyViewingDistance))
			{
				bPawnNoticed = false;
			}
			else
			{
				bPawnNoticed = true;
			}
		}
	}
	NPCLog("CanSeePlayer() Pawn noticed (in range and cone): " $ string(Seen) $ " Noticed? " $ string(bPawnNoticed));
	if (bPawnNoticed)
	{
		NotifyPlayerPawnInSight(Seen);
		if (aLastActorSeen == nullptr)
		{
			if (CanPawnSeeMe(Seen))
			{
				NotifyPlayerPawnWatchingMe(Seen);
			}
			aLastActorSeen = Seen;
		}
		fpTimeLastSeen = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if ((Enemy != nullptr) && (!bPawnNoticed))
		{
			EnemyNotVisible();
		}
	}
	*/
	return bPawnNoticed;
}

void ANPCBasePreCrewedVehicleControlle::WarnAboutToRunOverTeammate(AController* ctrlTeammate)
{
}

void ANPCBasePreCrewedVehicleControlle::SeePlayerTimer()
{
	Enemy = TempEnemy;
	Focus = Enemy;
	StartCoaxFiring(true);
	//GotoState("DrivingPatrol", "Stopped");
	//Enable("EnemyNotVisible");
}

void ANPCBasePreCrewedVehicleControlle::Turret_Scan()
{
	if (ScanOffset_Yaw == 6000)
	{
		ScanOffset_Yaw = -6000;
	}
	else
	{
		ScanOffset_Yaw = 6000;
	}
}

void ANPCBasePreCrewedVehicleControlle::EnemyNotVisibleTimer()
{
	/*
	Pawn.StopWeaponFiring();
	Enemy = nullptr;
	Enable("SeePlayer");
	if ((iNPCCurrentOrders == 1) || (iNPCCurrentOrders == 100))
	{
		return;
	}
	else
	{
		if ((iNPCCurrentOrders == 0) || (iNPCCurrentOrders == 101))
		{
			GotoState("DrivingPatrol", "MoveOn");
			return;
		}
	}
	*/
}

void ANPCBasePreCrewedVehicleControlle::CannotAimAtEnemy()
{
	/*
	Pawn.StopWeaponFiring();
	SetCustomTimer(3, false, "EnemyNotVisibleTimer");
	Enemy = nullptr;
	GotoState("DrivingPatrol", "MoveOn");
	*/
}

void ANPCBasePreCrewedVehicleControlle::CoaxFiringTimer()
{
	/*
	if ((Enemy != nullptr) && (Enemy->Health > 0))
	{
		if (iTotalCoaxRoundsBurstFired < 30)
		{
			FireCoaxWeapon();
		}
		else
		{
			StartCoaxFiring(false);
			//SetCustomTimer(2.5, false, "CoaxDelay");
		}
	}
	*/
}

void ANPCBasePreCrewedVehicleControlle::CoaxDelay()
{
	StartCoaxFiring(true);
}

void ANPCBasePreCrewedVehicleControlle::StartCoaxFiring(bool abStart)
{
	if ((wpnCoaxRPK != nullptr) && (iCoAxRounds > 0))
	{
		iTotalCoaxRoundsBurstFired = 0;
		if (abStart)
		{
			//SetCustomTimer(0.2, true, "CoaxFiringTimer");
		}
		else
		{
			//StopCustomTimer("CoaxFiringTimer");
		}
	}
}

void ANPCBasePreCrewedVehicleControlle::ChangeOrders(int32 iNewOrders)
{
}

void ANPCBasePreCrewedVehicleControlle::FireCoaxWeapon()
{
	FRotator Aim = FRotator(0, 0, 0);
	FRotator r1 = FRotator(0, 0, 0);
	FVector vStartShot = FVector(0, 0, 0);
	FVector vEndShot = FVector(0, 0, 0);
	FVector vDesiredEndShot = FVector(0, 0, 0);
	float fpAimingSkill = 0;
	FCoords cWeaponBoneLocation = FCoords({});
	/*
	if (iCoAxRounds == 0)
	{
		return;
	}
	if (agpvVehicle == nullptr)
	{
		return;
	}
	if (Enemy == nullptr)
	{
		return;
	}
	cWeaponBoneLocation = agpvVehicle.GetActiveWeaponSystem().GetBoneCoords("Muzzle_Bone");
	vStartShot = (wpnCoaxRPK.Location + FVector(150, 0, 0));
	if (Enemy->IsA(ACROWS_HMMWV::StaticClass()))
	{
		if (Cast<AVehicle>(Enemy).Weapon != nullptr)
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
		(vEndShot.Z -= float(20));
		if (bDebugCombat)
		{
			NPCLog("Using pawn location to get direction vector");
		}
	}
	vDesiredEndShot = vEndShot;
	fpAimingSkill = (fpNPCWeaponAccuracy / 100);
	if (VSize((agpvVehicle.Location - vEndShot)) > float(1500))
	{
		fpAimingSkill = (fpAimingSkill - (0.1 * ((VSize((agpvVehicle.Location - vEndShot)) - float(1500)) / 5000)));
	}
	if (fpAimingSkill < 0)
	{
		fpAimingSkill = 0;
	}
	(fpAimingSkill += ((float(iTotalCoaxRoundsBurstFired) / 30) * 0.02));
	if (fpAimingSkill > 1)
	{
		fpAimingSkill = 1;
	}
	fpCoAxAimError = (((VSize((vStartShot - vEndShot)) / float(5000)) * float(100)) * (1 - fpAimingSkill));
	if (FMath::FRand() < 0.97)
	{
		if (FMath::FRand() > 0.5)
		{
			(vEndShot.X += (fpCoAxAimError * (2 * FMath::FRand())));
		}
		else
		{
			(vEndShot.X -= (fpCoAxAimError * (2 * FMath::FRand())));
		}
	}
	if (FMath::FRand() < 0.97)
	{
		if (FMath::FRand() > 0.5)
		{
			(vEndShot.Y += (fpCoAxAimError * FMath::FRand()));
		}
		else
		{
			(vEndShot.Y -= (fpCoAxAimError * FMath::FRand()));
		}
	}
	(vEndShot.Z += (float(iTotalCoaxRoundsBurstFired) * 1.5));
	if (bDebugCombat)
	{
		NPCLog("Using enemy target location: " $ string(vEndShot.X) $ "," $ string(vEndShot.Y) $ "," $ string(vEndShot.Z));
	}
	r1 = rotator((vEndShot - vStartShot));
	fpCoAxAngleToTarget = (Normal(Vector(r1)) Dot Normal(Vector(agpvVehicle.GetWeaponAim())));
	if (Abs(fpCoAxAngleToTarget) > 0.707)
	{
		if (bDebugCombat)
		{
			Log("no shot - bad angle: " $ string(fpCoAxAngleToTarget));
		}
		return;
	}
	if (bDebugCombat)
	{
		NPCLog("Pitch: (P/R/Y): " $ string(Aim.Pitch) $ ", " $ string(Aim.Roll) $ ", " $ string(Aim.Yaw));
	}
	wpnCoaxRPK.GetCurrentAmmoType().AmmoAmount = 500;
	wpnCoaxRPK.rotCoaxWeaponAim = r1;
	wpnCoaxRPK.ServerFire();
	iCoAxRounds--;
	iTotalCoaxRoundsBurstFired++;
	*/
}

void ANPCBasePreCrewedVehicleControlle::ForceMoveTo(FName DestinationTag)
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

void ANPCBasePreCrewedVehicleControlle::Timer_CheckEmptyVehicleLocations()
{
}

FVector ANPCBasePreCrewedVehicleControlle::GetAvoidanceLocation()
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

void ANPCBasePreCrewedVehicleControlle::UnloadPassengers()
{
	if (agpvVehicle == nullptr)
	{
		iNPCCurrentOrders = 100;
	}
	else
	{
		//GotoState("UnloadSquad");
	}
}

void ANPCBasePreCrewedVehicleControlle::LocateAssaultLocation()
{
	ANPCAssaultLocation* npcalIterator = nullptr;
	/*
	ForEach AllActors(ANPCAssaultLocation::StaticClass(), npcalIterator, nameAssaultLocationTag)
	{
		vAssaultLocation = npcalIterator.Location;
		NPCLog("Found assault location: " $ string(npcalIterator));
		return;
	}
	*/
	NPCLog("WARNING: No assault location defined despite assault orders");
}

void ANPCBasePreCrewedVehicleControlle::DebugDumpRoute()
{
	int32 i = 0;
	NPCLog("******************************");
	//NPCLog("Vehicle Route goal: " $ string(RouteGoal) $ ", distance: " $ string(RouteDist));
	for (i = 0; i < 62; i++)
	{
		if (RouteCache[i] != nullptr)
		{
			//NPCLog("Route[ " $ string(i) $ "] => " $ string(RouteCache[i]) $ ": " $ string(RouteCache[i].Tag));
		}
	}
	NPCLog("******************************");
}

void ANPCBasePreCrewedVehicleControlle::NPCLog(FString sLogText)
{
	/*
	if ((agpvVehicle != nullptr) && (agpvVehicle.Driver != nullptr))
	{
		if (bDebugMode)
		{
			NPCPrivateLog(string(GetWorld()->GetTimeSeconds()) $ " - " $ string(this) $ "." $ string(GetStateName()) $ " - " $ string(agpvVehicle.Driver) $ " " $ sLogText);
		}
	}
	else
	{
		if (Pawn != nullptr)
		{
			if (bDebugMode)
			{
				NPCPrivateLog(string(GetWorld()->GetTimeSeconds()) $ " - " $ string(this) $ "." $ string(GetStateName()) $ " - " $ string(Pawn.Name) $ " " $ sLogText);
			}
		}
		else
		{
			NPCPrivateLog(string(GetWorld()->GetTimeSeconds()) $ " - " $ string(this) $ "." $ string(GetStateName()) $ " - " $ sLogText);
		}
	}
	*/
}

void ANPCBasePreCrewedVehicleControlle::DebugMarkNextNode(APathNode* pnNext)
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
