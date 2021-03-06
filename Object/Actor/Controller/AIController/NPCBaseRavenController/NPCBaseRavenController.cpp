// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseRavenController/NPCBaseRavenController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/DebugNavigation/DebugNPCNavigation/DebugNPCNavigation.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/FlyingPathNode/FlyingPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Info/TerrainInfo/TerrainInfo.h"

ANPCBaseRavenController::ANPCBaseRavenController()
{
	sCallSign = "Alpha-Bravo-Charlie 1-2-3";
	fpMaxSpeed = 500;
	fpMaxBackwardSpeed = -200;
	bSlowerZAcquire = false;
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
	Function CopyPredefinedWaypoints()
	{
		int32 iPreDefPN = 0;
		if (auavfpwpWaypoints.Num() > 0)
		{
			auavfpwpWaypoints->Remove(0,auavfpwpWaypoints.Num());
		}
		Log("Vehicle Path Nodes: " + FString::FromInt(apnFlyingPathNodesForPatrol.Num()));
		if (apnFlyingPathNodesForPatrol.Num() > 0)
		{
			auavfpwpWaypoints.insert (0,apnFlyingPathNodesForPatrol.Num());
			for (iPreDefPN=0; iPreDefPN<apnFlyingPathNodesForPatrol.Num(); iPreDefPN++)
			{
				auavfpwpWaypoints[iPreDefPN].vLocation=apnFlyingPathNodesForPatrol[iPreDefPN].Location;
				auavfpwpWaypoints[iPreDefPN].fpSpeed=850;
				auavfpwpWaypoints[iPreDefPN].fpAltitude=2000;
				Log("Copied vehicle pathnode " + FString::FromInt(iPreDefPN) + " into waypoint list at loc " + FString::FromInt(auavfpwpWaypoints[iPreDefPN].vLocation));
			}
		}
	}
Begin:
	Log(string(GetStateName()) + " Begin entered for vehicle: " + FString::FromInt(agpvVehicle));
	agpvVehicle->PeripheralVision=-99;
	sVehicleType=agpvVehicle->VehicleNameString;
	agpvVehicle->bDrawDriverInTP=false;
	agpvVehicle->Driver=Pawn;
	agpvVehicle->Throttle=0;
	agpvVehicle->Steering=0;
	agpvVehicle->fpHelicopterCollective=0.5;
	agpvVehicle->SetCollision(false,false,false);
	agpvVehicle->Driver=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,Location,Rotation,true,true);
	agpvVehicle->Driver.bHidden=true;
	agpvVehicle->Driver.SetCollision(false,false,false);
	Log(string(GetStateName()) + " Pilot (driver) spawned: " + FString::FromInt(agpvVehicle->Driver));
	if (iStartingPathNodeIndex > 0)
	{
		iCurrentDrivingPathNodeIndex=(iStartingPathNodeIndex - 1);
	}
	CopyPredefinedWaypoints();
	Log(string(GetStateName()) + " waypoints copied");
	fpMinAltitude=2000;
	ChangeState("CircleArea");
}
*/

/*
State Failure
{
}
*/

/*
State MechanicalFailure
{
Begin:
	agpvVehicle->HelicopterEngineSmoke(true);
	sDebugNavInfo="Starting to emergency land";
	agpvVehicle->fpHelicopterCollective=0;
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	agpvVehicle->DesiredSpeed=0;
	agpvVehicle->HelicopterEngineSmoke(true);
	sDebugNavInfo="Descending - Height " + FString::FromInt(GetRealAltitude());
	if (! DescendToAltitude(30))
	{
		Sleep(0.04);
		JL"ContinueDescent";
	}
	sDebugAltitude2="Finished descending, altitude: " + FString::FromInt(GetRealAltitude());
	agpvVehicle->fpHelicopterCollective=0;
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " + FString::FromInt(GetRealAltitude());
	Sleep(0.04);
}
*/

/*
State HoverMode
{
Begin:
	vHoverStartLocation=agpvVehicle->Location;
	DesiredRotation.Pitch=0;
	DesiredRotation.Roll=0;
	Log("Hover entered");
	agpvVehicle->DesiredSpeed=0;
	if (fpMinAltitude < float(1500))
	{
		fpMinAltitude=1500;
	}
	Log("Current altitude on starting hover: " + FString::FromInt(GetRealAltitude()));
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	GetForwardRealAltitude();
	HoldSpecificAltitude(fpMinAltitude);
	Sleep(0.04);
	JL"AdjustControls"
;
}
*/

/*
State TestPitch
{
Begin:
	agpvVehicle->DesiredSpeed=0;
	agpvVehicle->MaxDesiredSpeed=0;
	if (bDebugPitchDirectionUp)
	{
		if (agpvVehicle->fpHelicopterCyclicPitch < 1)
		{
			(agpvVehicle->fpHelicopterCyclicPitch += 0.05);
		}
		else
		{
			bDebugPitchDirectionUp=false;
		}
	}
	else
	{
		if (agpvVehicle->fpHelicopterCyclicPitch > -1)
		{
			(agpvVehicle->fpHelicopterCyclicPitch -= 0.05);
		}
		else
		{
			bDebugPitchDirectionUp=true;
		}
	}
	sDebugNavInfo="TestPitch cyclic pitch: " + FString::FromInt(agpvVehicle->fpHelicopterCyclicPitch) + "Desired speed: " + FString::FromInt(agpvVehicle->DesiredSpeed);
	AdjustForAltitudeHold();
	Sleep(0.04);
	JL"AdjustControls"
;
}
*/

/*
State HeadForWaypoint
{
	Function bool GonePast()
	{
		FVector vDirectionToGoal = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDirectionToGoal=Normal((agpvVehicle->Location - vAdjustedPathNodeLocation));
		vCurrentRotation=Normal( Vector(agpvVehicle->Rotation));
		if ((vDirectionToGoal Dot vCurrentRotation) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Function float GetDistanceToWaypoint2D()
	{
		FVector vAdjustedVehicleLocation = FVector(0,0,0);
		vAdjustedVehicleLocation=agpvVehicle->Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		return VSize((vAdjustedVehicleLocation - vAdjustedPathNodeLocation));
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
		Log("Take damage while navigating, adjust altitude (time since last adjust: " + FString::FromInt(FMath::Abs((GetWorld()->GetTimeSeconds() - fpLastGroundFireAdjust))));
		if (FMath::Abs((GetWorld()->GetTimeSeconds() - fpLastGroundFireAdjust)) < float(10))
		{
			return;
		}
		if (fpGroundFireAvoidanceAltitudeBump <= 0)
		{
			fpGroundFireAvoidanceAltitudeBump=500;
		}
		else
		{
			fpGroundFireAvoidanceAltitudeBump=-500;
		}
		Log("TakeDamage adjusted altitude bump now: " + FString::FromInt(fpGroundFireAvoidanceAltitudeBump));
		fpLastGroundFireAdjust=GetWorld()->GetTimeSeconds();
	}
Begin:
	sDebugNavInfo="Getting next waypoint";
	fpGroundFireAvoidanceAltitudeBump=0;
	DetermineNextPathNode();
	FindNextDrivingPatrolPathNode();
	if (pnCurrentFlyingPathNode == nullptr)
	{
		NPCLog("No path node to move to!");
		ChangeState("None");
		JL"End";
	}
	vAdjustedPathNodeLocation=pnCurrentFlyingPathNode.Location;
	vAdjustedPathNodeLocation.Z=agpvVehicle->Location.Z;
	if (vAdjustedPathNodeLocation.Z < float(4500))
	{
		fpMinAltitude=4500;
	}
	else
	{
		fpMinAltitude=vAdjustedPathNodeLocation.Z;
	}
	fpGroundFireAvoidanceAltitudeBump=0;
	fpTerrainAvoidanceAltitudeBump=0;
	DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle->Location));
	Log("Rotation calculated to be " + FString::FromInt(DesiredRotation));
	if (iDesiredTravelSpeed == 0)
	{
		iDesiredTravelSpeed=850;
	}
	agpvVehicle->DesiredSpeed=float(iDesiredTravelSpeed);
	sDebugNavMode="StartMovingToWaypoint";
	if ((! TurnedEnough(0.02)) && (GetDistanceToWaypoint2D() > float(100)))
	{
		DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle->Location));
	}
	if ((GetForwardRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
	{
		(fpTerrainAvoidanceAltitudeBump += float(20));
	}
	else
	{
		if (fpTerrainAvoidanceAltitudeBump > 0)
		{
			(fpTerrainAvoidanceAltitudeBump -= float(20));
		}
	}
	AdjustThrottleToDesiredSpeed();
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	if (GetDistanceToWaypoint2D() < float(3500))
	{
		sDebugNavInfo="Slowing close to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
		if (GetDistanceToWaypoint2D() < float(1500))
		{
			if (bFollowPatrol)
			{
				JL"PrepNextWaypoint";
			}
			if ((VSize(agpvVehicle->Velocity) > float(150)) && (GetDistanceToWaypoint2D() > float(1000)))
			{
				agpvVehicle->DesiredSpeed=150;
			}
			else
			{
				if (GonePast())
				{
					JL"PrepNextWaypoint";
				}
			}
		}
	}
	else
	{
		sDebugNavInfo="Heading to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
	}
	sDebugNavMode="Traveling onward";
	Sleep(0.04);
	JL"StartMovingToWaypoint";
	sDebugNavMode="Prepping for next waypoint";
	if (bFollowPatrol)
	{
		JL"NextWaypoint";
	}
	else
	{
		ChangeState("HoverMode");
	}
}
*/

/*
State CircleArea
{
Begin:
	Log(string(GetStateName()) + " entered");
	iDesiredTravelSpeed=500;
	agpvVehicle->DesiredSpeed=float(iDesiredTravelSpeed);
	DesiredRotation=Pawn.Rotation;
	(DesiredRotation.Yaw += 2048);
	agpvVehicle->UAVSetVerticalVelocity(0);
	agpvVehicle->UAVSetHorizontalVelocity(100);
	agpvVehicle->UAVSetRudder(5);
	agpvVehicle->UAVSetElevator(0);
	if ((FMath::Abs(float((DesiredRotation.Yaw - Pawn.Rotation.Yaw))) < float(256)) || (FMath::Abs(float((DesiredRotation.Yaw - Pawn.Rotation.Yaw))) > float((65535 - 256))))
	{
		(DesiredRotation.Yaw += 2048);
	}
	if (DesiredRotation.Yaw > 65535)
	{
		(DesiredRotation.Yaw -= 65535);
	}
	sDebugNavMode="Circling Area - Desired rotation: " + FString::FromInt(DesiredRotation.Yaw);
	if ((GetForwardRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
	{
		(fpTerrainAvoidanceAltitudeBump += float(20));
	}
	else
	{
		if (fpTerrainAvoidanceAltitudeBump > 0)
		{
			(fpTerrainAvoidanceAltitudeBump -= float(20));
		}
	}
	AdjustThrottleToDesiredSpeed();
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	Sleep(0.04);
	JL"KeepCircling";
	sDebugNavMode="Going to idle";
}
*/

/*
State TurnRight
{
Begin:
	(DesiredRotation.Yaw += 2048);
	if (TurnedEnough(0.02))
	{
		ChangeState("StraightFlight");
	}
	sDebugNavMode="Turning Right";
	if ((GetForwardRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
	{
		(fpTerrainAvoidanceAltitudeBump += float(20));
	}
	else
	{
		if (fpTerrainAvoidanceAltitudeBump > 0)
		{
			(fpTerrainAvoidanceAltitudeBump -= float(20));
		}
	}
	AdjustThrottleToDesiredSpeed();
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	Sleep(0.04);
	JL"KeepTurning";
}
*/

/*
State TurnLeft
{
Begin:
	(DesiredRotation.Yaw -= 2048);
	if (DesiredRotation.Yaw < 0)
	{
		(DesiredRotation.Yaw += 65535);
	}
	if (TurnedEnough(0.02))
	{
		ChangeState("StraightFlight");
	}
	sDebugNavMode="Turning Left";
	if ((GetForwardRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
	{
		(fpTerrainAvoidanceAltitudeBump += float(20));
	}
	else
	{
		if (fpTerrainAvoidanceAltitudeBump > 0)
		{
			(fpTerrainAvoidanceAltitudeBump -= float(20));
		}
	}
	AdjustThrottleToDesiredSpeed();
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	Sleep(0.04);
	JL"KeepTurning"
;
}
*/

/*
State StraightFlight
{
Begin:
	iDesiredTravelSpeed=500;
	(DesiredRotation.Yaw += 2048);
	sDebugNavMode="Straight Flight";
	if ((GetForwardRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
	{
		(fpTerrainAvoidanceAltitudeBump += float(20));
	}
	else
	{
		if (fpTerrainAvoidanceAltitudeBump > 0)
		{
			(fpTerrainAvoidanceAltitudeBump -= float(20));
		}
	}
	AdjustThrottleToDesiredSpeed();
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	Sleep(0.04);
	JL"KeepGoing"
;
}
*/

/*
State HeadForLandingZone
{
	Function bool TurnedEnough(float fpAngle)
	{
		FRotator rotDesiredRotation = FRotator(0,0,0);
		FRotator rotCurrentRotation = FRotator(0,0,0);
		FVector vDesiredRotation = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		rotDesiredRotation=DesiredRotation;
		rotDesiredRotation.Pitch=0;
		vDesiredRotation=Normal( Vector(rotDesiredRotation));
		rotCurrentRotation=agpvVehicle->Rotation;
		rotCurrentRotation.Pitch=0;
		vCurrentRotation=Normal( Vector(rotCurrentRotation));
		sDebugNavInfo="Turning to LZ direction " + FString::FromInt((vDesiredRotation Dot vCurrentRotation));
		if ((vDesiredRotation Dot vCurrentRotation) > (0.96 + fpAngle))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Function bool StopMovement()
	{
		if (VSize(agpvVehicle->Velocity) > 1)
		{
			if ((agpvVehicle->Rotation.Pitch > 32768) || (agpvVehicle->Rotation.Pitch < 0))
			{
				agpvVehicle->fpHelicopterCyclicPitch=(VSize(agpvVehicle->Velocity) * -0.01);
			}
			else
			{
				agpvVehicle->fpHelicopterCyclicPitch=(VSize(agpvVehicle->Velocity) * 0.01);
			}
			sDebugNavInfo="Trying to stop, pitch " + FString::FromInt(agpvVehicle->Rotation.Pitch) + " Collective: " + FString::FromInt(agpvVehicle->fpHelicopterCyclicPitch);
			return false;
		}
		else
		{
			agpvVehicle->fpHelicopterCyclicPitch=0;
		}
		return true;
	}
	Function bool GonePast()
	{
		FVector vDirectionToGoal = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDirectionToGoal=Normal((agpvVehicle->Location - vAdjustedPathNodeLocation));
		vCurrentRotation=Normal( Vector(agpvVehicle->Rotation));
		if ((vDirectionToGoal Dot vCurrentRotation) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Function float GetDistanceToWaypoint2D()
	{
		FVector vAdjustedVehicleLocation = FVector(0,0,0);
		vAdjustedVehicleLocation=agpvVehicle->Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		return VSize((vAdjustedVehicleLocation - vAdjustedPathNodeLocation));
	}
	Function AdjustThrottleToDesiredSpeed()
	{
		float fpSpeedRatio = 0;
		if (agpvVehicle->DesiredSpeed == 0)
		{
			StopMovement();
		}
		if (agpvVehicle->DesiredSpeed > 0)
		{
			fpSpeedRatio=((agpvVehicle->DesiredSpeed / fpMaxSpeed) * -1);
			sDebugCyclicPitch="Moving forward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		else
		{
			fpSpeedRatio=(agpvVehicle->DesiredSpeed / fpMaxBackwardSpeed);
			sDebugCyclicPitch="Moving backward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		agpvVehicle->fpHelicopterCyclicPitch=fpSpeedRatio;
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall->IsA(ATerrainInfo::StaticClass()))
		{
			Log("NotifyHitWall for Helicopter on terrain");
			ChangeState("LandedMode");
		}
		return false;
	}
Begin:
	sDebugNavInfo="";
	agpvVehicle->fpHelicopterCollective=0;
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	vAdjustedPathNodeLocation=vLocationLandingZone;
	if ((vAdjustedPathNodeLocation.Z + float(500)) < agpvVehicle->Location.Z)
	{
		vAdjustedPathNodeLocation.Z=agpvVehicle->Location.Z;
	}
	else
	{
		(vAdjustedPathNodeLocation.Z += float(500));
	}
	fpMinAltitude=1500;
	DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle->Location));
	Log("Rotation calculated to be " + FString::FromInt(DesiredRotation));
	AdjustForAltitudeHold();
	if (TurnedEnough(0.03))
	{
		Log("Finished turning to waypoint, now starting to move to it");
		if (iDesiredTravelSpeed == 0)
		{
			iDesiredTravelSpeed=850;
		}
		agpvVehicle->DesiredSpeed=float(iDesiredTravelSpeed);
		JL"StartMovingToLZ";
	}
	Sleep(0.04);
	JL"FinishTurnWhileHovering";
	if ((! TurnedEnough(0.02)) && (GetDistanceToWaypoint2D() > float(100)))
	{
		DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle->Location));
	}
	AdjustThrottleToDesiredSpeed();
	if (GetDistanceToWaypoint2D() < float(3500))
	{
		sDebugNavInfo="Slowing close to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
		if (GetDistanceToWaypoint2D() < float(400))
		{
			if ((VSize(agpvVehicle->Velocity) > float(50)) && (GetDistanceToWaypoint2D() > float(200)))
			{
				agpvVehicle->DesiredSpeed=10;
			}
			else
			{
				if ((VSize(agpvVehicle->Velocity) < float(10)) || GonePast())
				{
					agpvVehicle->DesiredSpeed=0;
					JL"PrepLanding";
				}
			}
		}
		else
		{
			if (GetDistanceToWaypoint2D() < float(750))
			{
				if (VSize(agpvVehicle->Velocity) > float(100))
				{
					agpvVehicle->DesiredSpeed=75;
				}
			}
			else
			{
				if (GetDistanceToWaypoint2D() < float(100))
				{
					if (VSize(agpvVehicle->Velocity) > float(125))
					{
						agpvVehicle->DesiredSpeed=125;
					}
				}
				else
				{
					if (GetDistanceToWaypoint2D() < float(2000))
					{
						if (VSize(agpvVehicle->Velocity) > float(150))
						{
							agpvVehicle->DesiredSpeed=150;
						}
					}
					else
					{
						if (GetDistanceToWaypoint2D() < float(3500))
						{
							if (VSize(agpvVehicle->Velocity) > float(200))
							{
								agpvVehicle->DesiredSpeed=200;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		sDebugNavInfo="Heading to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
	}
	AdjustForAltitudeHold();
	Sleep(0.04);
	JL"StartMovingToLZ";
	sDebugNavInfo="Starting to land";
	agpvVehicle->fpHelicopterCollective=0;
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	agpvVehicle->DesiredSpeed=0;
	sDebugNavInfo="Descending - Height " + FString::FromInt(GetRealAltitude());
	agpvVehicle->SetPhysics(PHYS_Falling);
	agpvVehicle->fpHelicopterCollective=0;
	agpvVehicle->fpHelicopterCyclicPitch=0;
	agpvVehicle->fpHelicopterCyclicRoll=0;
	agpvVehicle->SetCollision(true,true,true);
	agpvVehicle->bBlockZeroExtentTraces=true;
}
*/

/*
State ManualControl
{
Begin:
	agpvVehicle->Throttle=0;
	agpvVehicle->Steering=0;
	DesiredRotation=agpvVehicle->Rotation;
}
*/

/*
State TakeOffMode
{
	Function bool AscendToAltitude(float fpTargetHeight)
	{
		float fpCurrentAltitude = 0;
		float fpMaxAscentSpeed = 0;
		fpMaxAscentSpeed=200;
		fpCurrentAltitude=GetRealAltitude();
		if (FMath::Abs((fpCurrentAltitude - fpTargetHeight)) < float(20))
		{
			if (agpvVehicle->Velocity.Z > 2)
			{
				agpvVehicle->fpHelicopterCollective=0;
				return false;
			}
			else
			{
				return true;
			}
		}
		if (fpCurrentAltitude >= (fpTargetHeight - float(250)))
		{
			if (agpvVehicle->Velocity.Z > 5)
			{
				if (agpvVehicle->Velocity.Z > float(25))
				{
					agpvVehicle->fpHelicopterCollective=(-0.001 * (agpvVehicle->Velocity.Z - float(25)));
				}
				else
				{
					agpvVehicle->fpHelicopterCollective=-0.01;
				}
				sDebugCollective="Altitude above or at target height, still moving up";
				return false;
			}
			else
			{
				agpvVehicle->fpHelicopterCollective=0.001;
				sDebugCollective="Altitude above or at target height, not moving (done) ";
				return true;
			}
		}
		if (agpvVehicle->Velocity.Z > float(50))
		{
			if ((FMath::Abs((fpTargetHeight - fpCurrentAltitude)) < float(200)) && (agpvVehicle->Velocity.Z > float(10)))
			{
				(agpvVehicle->fpHelicopterCollective -= 0.001);
				sDebugCollective="Moving up and close, speed " + FString::FromInt(agpvVehicle->Velocity.Z) + ", slowing rate, collective at " + FString::FromInt(agpvVehicle->fpHelicopterCollective);
			}
			else
			{
				if (agpvVehicle->Velocity.Z < fpMaxAscentSpeed)
				{
					(agpvVehicle->fpHelicopterCollective += 0.005);
				}
				sDebugCollective="Moving up but not close, speed " + FString::FromInt(agpvVehicle->Velocity.Z) + ", slowing rate, collective at " + FString::FromInt(agpvVehicle->fpHelicopterCollective);
			}
		}
		else
		{
			agpvVehicle->fpHelicopterCollective=0.05;
			sDebugCollective="Not moving up, increasing collective, now " + FString::FromInt(agpvVehicle->fpHelicopterCollective);
		}
		return false;
	}
Begin:
	if (! AscendToAltitude(1000))
	{
		Sleep(0.04);
		JL"Climb";
	}
	if (bResumePathAfterFailure)
	{
		bResumePathAfterFailure=false;
		bFollowPatrol=true;
		ChangeState("HeadForWaypoint","FinishTurnWhileHovering");
	}
	ChangeState("HoverMode");
}
*/

/*
State HelicopterShotDown
{
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		Log("NotifyHitWall for Helicopter on terrain");
		agpvVehicle->SpawnDestructionEffects();
		ChangeState("Dead");
		return false;
	}
	Event Landed(Vector HitNormal)
	{
		Log("Landed event for Helicopter");
		agpvVehicle->SpawnDestructionEffects();
		ChangeState("Dead");
	}
	Event Touch(AActor* Other)
	{
		agpvVehicle->SpawnDestructionEffects();
		ChangeState("Dead");
	}
Begin:
	agpvVehicle->HelicopterEngineSmoke(true);
	if ((Normal( Vector(Pawn.Rotation)) Dot Normal( Vector(DesiredRotation))) > 0.25)
	{
		(DesiredRotation.Yaw += 16384);
		if (DesiredRotation.Yaw > 65535)
		{
			(DesiredRotation.Yaw -= 65535);
		}
	}
	sDebugCrashStatus="altitude: " + FString::FromInt(GetRealAltitude());
	if (GetRealAltitude() <= float(90))
	{
		Log("About to hit ground: " + FString::FromInt(GetRealAltitude()));
		Sleep(0.2);
		agpvVehicle->SpawnDestructionEffects();
		ChangeState("Dead");
	}
	if (Velocity.Z > float(-200))
	{
		if (agpvVehicle->fpHelicopterCollective > -0.5)
		{
			agpvVehicle->fpHelicopterCollective=-0.05;
		}
	}
	Sleep(0.04);
	JL"KeepFalling";
}
*/

/*
State Dead
{
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
	}
	Function SwapInDestroyedMesh()
	{
		FVector vLoc = FVector(0,0,0);
		FRotator Rot = FRotator(0,0,0);
		Rot=agpvVehicle->Rotation;
		vLoc=agpvVehicle->Location;
		agpvVehicle->SetDrawType(DT_StaticMesh);
		agpvVehicle->SetPhysics(PHYS_None);
		agpvVehicle->SetStaticMesh(StaticMesh(DynamicLoadObject("M_AA2_Vehicles.blackhawk.veh_blackhawk_fullcrashed",Class'StaticMesh')));
		agpvVehicle->SetCollision(false,false,false);
		agpvVehicle->bWorldGeometry=true;
		agpvVehicle->bCollideWorld=false;
		agpvVehicle->SetRotation((Rot + FRotator(0,0,4096)));
		agpvVehicle->SetLocation((vLoc + FVector(0,0,float((- 50)))));
	}
Begin:
	agpvVehicle->HelicopterEngineSmoke(false);
	Log("Raven controller cleaning up vehicle pawn to swap in destroyed mesh");
	GetPawn()->Destroy();
	Log("Dead helicopter, swapping in crashed mesh, exploding");
	SwapInDestroyedMesh();
	if (agpvVehicle != nullptr)
	{
		agpvVehicle->HelicopterEngineSmoke(true);
		Sleep(15);
	}
}
*/

void ANPCBaseRavenController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	YL=10;
	if (Pawn->IsA(AVehicle::StaticClass()))
	{
		GetPawn()->DisplayDebug(Canvas,YL,YPos);
		YPos += YL;
		YPos += YL;
		Canvas.SetDrawColor(255,255,255);
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Current Location: " + Vehicle(Pawn).Location + " Current State: " + GetStateName());
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Collective: " + Vehicle(Pawn).fpHelicopterCollective + "  Cyclic Pitch: " + Vehicle(Pawn).fpHelicopterCyclicPitch + "  Desired Speed " + agpvVehicle->DesiredSpeed);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Rotation: " + Vehicle(Pawn).Rotation + "  Desired Rotation: " + DesiredRotation + " Alt: " + GetRealAltitude() + "  GF Bump: " + fpGroundFireAvoidanceAltitudeBump);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Velocity: " + Vehicle(Pawn).Velocity + " (Speed: " + VSize(agpvVehicle->Velocity) + ")");
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Next Waypoint: " + pnCurrentFlyingPathNode + " Distance to waypoint: " + VSize(agpvVehicle->Location - vAdjustedPathNodeLocation) + " Ratio to destination: " + VSize(agpvVehicle->Location - vAdjustedPathNodeLocation) / 5500);
		YPos += YL;
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Navigation Status: " + sDebugNavInfo);
		YPos += YL;
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Mode: " + sDebugNavMode);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Cyclic Status: " + sDebugCyclicPitch);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Collective Status: " + sDebugCollective);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Collective Status2: " + sDebugCollective2);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Altitude Status: " + sDebugAltitude);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Currently Over: " + sDebugAltitude2);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Crash Status: " + sDebugCrashStatus);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Forward altitude: " + sDebugFwdAltitude);
		YPos += YL;
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Torque: " + Vehicle(Pawn).HUDOverlayOffset + "   Force: " + Vehicle(Pawn).FlagOffset);
	}
	*/
}

void ANPCBaseRavenController::Land(FVector vLoc)
{
	vLocationLandingZone = vLoc;
	//ChangeState('HeadForLandingZone');
}

void ANPCBaseRavenController::NextWaypoint()
{
	bFollowPatrol = false;
	//ChangeState('HeadForWaypoint');
}

void ANPCBaseRavenController::TakeOff()
{
	//ChangeState('TakeOffMode');
}

void ANPCBaseRavenController::Hover()
{
	//ChangeState('HoverMode');
}

void ANPCBaseRavenController::Start()
{
	//ChangeState('InitializeVehicle');
}

void ANPCBaseRavenController::Patrol()
{
	bFollowPatrol = true;
	//ChangeState('HeadForWaypoint');
}

APathNode* ANPCBaseRavenController::GetPathnodeByTagString(FString sTag)
{
	ANavigationPoint* N = nullptr;
	if (sTag.Len() > 0)
	{
		for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
		{
			/*
			if (N->IsA(AFlyingPathNode::StaticClass()) && (sTag == FString::FromInt(N.Tag)))
			{
				return PathNode(N);
			}
			*/
		}
	}
	return nullptr;
}

void ANPCBaseRavenController::PreloadPathNodeList()
{
	int32 iNode = 0;
	APathNode* pnFound = nullptr;
	bDebugMode = true;
	bDebugPath = true;
	/*
	for (iNode=0; iNode<=99; iNode++)
	{
		pnFound=GetPathnodeByTagString(sNPCWaypointTag + "-" + iNode + 1);
		if (pnFound == nullptr)
		{
		}
		apnFlyingPathNodesForPatrol.insert (iNode,1);
		apnFlyingPathNodesForPatrol[iNode]=FlyingPathNode(pnFound);
		if (bDebugPath)
		{
			pnFound.bHidden=false;
		}
		Log("Found path node for " + sNPCWaypointTag + "-" + iNode + 1 + " -> " + pnFound.Tag + " total found " + apnFlyingPathNodesForPatrol.Num());
	}
	*/
}

AFlyingPathNode* ANPCBaseRavenController::FindNextDrivingPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " + iCurrentDrivingPathNodeIndex + 1);
	if (apnFlyingPathNodesForPatrol.Num() == 0)
	{
		NPCPathLog("FindNextDrivingPatrolPathNode() - No patrol paths have been defined");
		return nullptr;
	}
	if (iCurrentDrivingPathNodeIndex < apnFlyingPathNodesForPatrol.Num())
	{
		NPCPathLog("Found pathnode: " + apnFlyingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].Tag);
		pnCurrentFlyingPathNode=apnFlyingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
		return pnCurrentFlyingPathNode;
	}
	NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
	*/
	return nullptr;
}

void ANPCBaseRavenController::InitVehicle()
{
	bDebugMode = true;
	bStart = true;
	/*
		if (VehicleTag != "None")
		{
			agpvVehicle=Spawn(VehicleClass,,VehicleTag,Location,Rotation);
		}
		else
		{
			agpvVehicle=Spawn(VehicleClass,,,Location,Rotation);
		}
		Log("UAV Vehicle spawned: " + agpvVehicle);
		agpvVehicle->PeripheralVision=-99;
		sVehicleType=agpvVehicle->VehicleNameString;
	*/
}

/*
void ANPCBaseRavenController::Possess(APawn* aPawn)
{
	if (aPawn->IsA(AVehicle::StaticClass()))
	{
		Log("Possessing UAV: " + aPawn);
		Possess(aPawn);
	}
}
*/

/*
void ANPCBaseRavenController::UnPossess()
{
if (Pawn->IsA(AAGP_Pawn::StaticClass()))
	{
		NPCLog("Current pawn is AGP_Pawn (driver leaving vehicle), so we're doing nothing there");
	}
}
*/

void ANPCBaseRavenController::WatchForMechanicalFailuresTimer()
{
	/*
		if (fpEngineFailureChance > 0 && FMath::FRand() > 1 - fpEngineFailureChance)
		{
			if (fpMechanicalFailureTimer == 0)
			{
				fpMechanicalFailureTimer=GetWorld()->GetTimeSeconds() + 30 + FMath::FRand() * 120;
				Log("Mechanical failure scheduled for " + fpMechanicalFailureTimer);
			}
			else
			{
				if (GetWorld()->GetTimeSeconds() >= fpMechanicalFailureTimer && fpMechanicalFailureTimer > 0)
				{
					fpMechanicalFailureTimer=0;
					fpEngineFailureChance=0;
					ChangeState('MechanicalFailure');
				}
			}
		}
	*/
}

FString ANPCBaseRavenController::LocationToGrid(FVector vLoc)
{
	FString sResult = "";
	float fpScale = 0;
	int32 iGridX = 0;
	int32 iGridY = 0;
	FVector vTopLeft = FVector(0,0,0);
	/*
	fpScale=Level.RadarMapSize * 2 / 100;
	vTopLeft.X=Level.RadarMapOffset.X - Level.RadarMapSize;
	vTopLeft.Y=Level.RadarMapOffset.Y - Level.RadarMapSize;
	vTopLeft.Z=0;
	iGridX=vLoc.X - vTopLeft.X / fpScale;
	iGridX += Level.Game.GameReplicationInfo.iSpotterBaseGridX;
	iGridY=vLoc.Y - vTopLeft.Y / fpScale;
	iGridY += Level.Game.GameReplicationInfo.iSpotterBaseGridY;
	sResult="" + iGridX + " by " + iGridY;
	*/
	return sResult;
}

void ANPCBaseRavenController::AdjustPitchForPositionHold()
{
	/*
		if (agpvVehicle->Velocity.X <= -1)
		{
			agpvVehicle->fpHelicopterCyclicPitch -= 0.01;
			sDebugCyclicPitch="Adjusting pitch to slow backward movement: " + agpvVehicle->fpHelicopterCyclicPitch;
		}
		else
		{
			if (agpvVehicle->Velocity.X >= 1)
			{
				agpvVehicle->fpHelicopterCyclicPitch += 0.01;
				sDebugCyclicPitch="Adjusting pitch to slow forward movement: " + agpvVehicle->fpHelicopterCyclicPitch;
			}
			else
			{
				agpvVehicle->fpHelicopterCyclicPitch=0;
				sDebugCyclicPitch="Pitch hold ok: " + agpvVehicle->fpHelicopterCyclicPitch;
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustRollForPositionHold()
{
	/*
		if (agpvVehicle->Velocity.Y < -1)
		{
			agpvVehicle->fpHelicopterCyclicRoll += 0.01;
		}
		else
		{
			if (agpvVehicle->Velocity.Y > 1)
			{
				agpvVehicle->fpHelicopterCyclicRoll -= 0.01;
			}
			else
			{
				agpvVehicle->fpHelicopterCyclicRoll=0;
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustForAltitudeHold()
{
	/*
		if (agpvVehicle->Velocity.Z <= -2.5)
		{
			agpvVehicle->fpHelicopterCollective=0.01 * Abs(agpvVehicle->Velocity.Z);
			sDebugCollective="Hold Altitude (velocity " + agpvVehicle->Velocity.Z + "), raising collective to " + agpvVehicle->fpHelicopterCollective;
		}
		else
		{
			if (agpvVehicle->Velocity.Z >= 2.5)
			{
				agpvVehicle->fpHelicopterCollective=-0.001 * Abs(agpvVehicle->Velocity.Z);
				sDebugCollective="Hold Altitude (velocity " + agpvVehicle->Velocity.Z + "), lowering collective to " + agpvVehicle->fpHelicopterCollective;
			}
			else
			{
				agpvVehicle->fpHelicopterCollective=0;
				sDebugCollective="Hold Altitude (velocity " + agpvVehicle->Velocity.Z + "), holding collective at " + agpvVehicle->fpHelicopterCollective;
			}
		}
	*/
}

float ANPCBaseRavenController::GetForwardRealAltitude()
{
	AActor* actTraceHit = nullptr;
	FVector vHitLocation = FVector(0,0,0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vEndTrace = FVector(0, 0, 0);
	FVector vStartTrace = FVector(0, 0, 0);
	FRotator rotCleaned = FRotator(0, 0, 0);
	/*
	vStartTrace=Pawn.Location;
	rotCleaned=Pawn.Rotation;
	rotCleaned.Pitch=0;
	rotCleaned.Roll=0;
	vStartTrace +=  Vector(rotCleaned) * 2000 + VSize(agpvVehicle->Velocity);
	vEndTrace=vStartTrace;
	vEndTrace.Z -= 10000;
	actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,true);
	if (actTraceHit == nullptr)
	{
		if (dnpcnDebugTerrainRadarMarker != nullptr)
		{
			dnpcnDebugTerrainRadarMarker.bHidden=true;
		}
		sDebugFwdAltitude="Trace hit nothing";
		return -1;
	}
	if (actTraceHit->IsA(ALevelInfo::StaticClass()))
	{
		if (dnpcnDebugTerrainRadarMarker != nullptr)
		{
			dnpcnDebugTerrainRadarMarker.bHidden=true;
		}
		sDebugFwdAltitude="Trace hit levelinfo";
		return 0;
	}
	sDebugFwdAltitude="Trace hit " + actTraceHit + " distance " + vStartTrace.Z - vHitLocation.Z;
	if (dnpcnDebugTerrainRadarMarker != nullptr)
	{
		dnpcnDebugTerrainRadarMarker.bHidden=false;
		vHitLocation.Z += 100;
		dnpcnDebugTerrainRadarMarker.SetLocation(vHitLocation);
	}
	return vStartTrace.Z - vHitLocation.Z;
	*/
	return 0;    //FAKE   /ELiZ
}

float ANPCBaseRavenController::GetRealAltitude()
{
	AActor* actTraceHit = nullptr;
	FVector vHitLocation = FVector(0, 0, 0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vEndTrace = FVector(0, 0, 0);
	FVector vStartTrace = FVector(0,0,0);
	/*
	vStartTrace=Pawn.GetBoneCoords('Pilot').Origin;
	sDebugAltitude="Pawn Location: " + Pawn.Location + " Pilot origin: " + vStartTrace + "  Distance " + VSize(Pawn.Location - vStartTrace);
	vEndTrace=vStartTrace;
	vEndTrace.Z -= 10000;
	actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,true);
	sDebugAltitude2="Trace hit " + actTraceHit;
	if (actTraceHit == nullptr)
	{
		return fpRealAltitude;
	}
	if (actTraceHit->IsA(ALevelInfo::StaticClass()))
	{
		return fpRealAltitude;
	}
	fpRealAltitude=vStartTrace.Z - vHitLocation.Z;
	*/
	return fpRealAltitude;
}

void ANPCBaseRavenController::HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding)
{
	float fpCurrentRealAltitude = 0;
	float fpVertVelocity = 0;
	float fpDistFromAltitude = 0;
	float fpMaxUUAboveVariation = 0;
	float fpMaxUUBelowVariation = 0;
	if (! bDisableVarianceForLanding)
	{
		fpMaxUUAboveVariation=25;
		fpMaxUUBelowVariation=25;
	}
	fpCurrentRealAltitude=GetRealAltitude();
	if (fpCurrentRealAltitude == -1 || fpCurrentRealAltitude == 0)
	{
		return;
	}
	fpDistFromAltitude=FMath::Abs(fpCurrentRealAltitude - fpDesiredAltitude);
	fpVertVelocity=agpvVehicle->Velocity.Z;
	if (fpCurrentRealAltitude > fpDesiredAltitude && fpDistFromAltitude > fpMaxUUAboveVariation)
	{
		if (fpVertVelocity > 5)
		{
			sDebugCollective2="Ascending from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
			AdjustForAltitudeHold();
		}
		else
		{
			if (fpDistFromAltitude < 250)
			{
				if (fpVertVelocity < -10)
				{
					sDebugCollective2="< 250, velocity too fast from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
					agpvVehicle->fpHelicopterCollective=0.05;
				}
				else
				{
					sDebugCollective2="velocity OK, maintaining collective from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
				}
			}
			else
			{
				if (fpVertVelocity > -15)
				{
					sDebugCollective2="Velocity slow from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
					agpvVehicle->fpHelicopterCollective -= 0.005;
				}
				else
				{
					if (fpVertVelocity <= -50)
					{
						sDebugCollective2="velocity too fast from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						if (agpvVehicle->fpHelicopterCollective < 0)
						{
							agpvVehicle->fpHelicopterCollective=0;
						}
						else
						{
							if (agpvVehicle->fpHelicopterCollective < 0.25)
							{
								agpvVehicle->fpHelicopterCollective += 0.001;
							}
						}
					}
				}
			}
			sDebugCollective="Descending collective " + FString::SanitizeFloat(agpvVehicle->fpHelicopterCollective) + " Desired Alt: " + FString::SanitizeFloat(fpDesiredAltitude) + "  Alt: " + FString::SanitizeFloat(fpCurrentRealAltitude) + " Dist: " + FString::SanitizeFloat(fpDistFromAltitude) + " Vel: " + FString::SanitizeFloat(fpVertVelocity);
		}
	}
	else
	{
		if (fpCurrentRealAltitude < fpDesiredAltitude && fpDistFromAltitude > fpMaxUUBelowVariation)
		{
			if (fpVertVelocity < 0)
			{
				sDebugCollective2="Trying to stop descent from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
				AdjustForAltitudeHold();
			}
			else
			{
				if (fpDistFromAltitude < 250)
				{
					if (fpVertVelocity > 20)
					{
						sDebugCollective2="Close, velocity too fast from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						agpvVehicle->fpHelicopterCollective -= 0.001;
					}
					else
					{
						sDebugCollective2="Close, good velocity from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						if (fpVertVelocity < 5)
						{
							agpvVehicle->fpHelicopterCollective += 0.001;
						}
						else
						{
							agpvVehicle->fpHelicopterCollective=0.002;
						}
					}
				}
				else
				{
					if (agpvVehicle->fpHelicopterCollective < 0.25)
					{
						sDebugCollective2="Not close, collective < .25 from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						if (agpvVehicle->fpHelicopterCollective < 0)
						{
							agpvVehicle->fpHelicopterCollective=0;
						}
						agpvVehicle->fpHelicopterCollective += 0.001;
					}
					else
					{
						sDebugCollective2="Not close, collective < .25 from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						agpvVehicle->fpHelicopterCollective=0.01;
					}
				}
			}
			sDebugCollective="Ascending, collective " + FString::SanitizeFloat(agpvVehicle->fpHelicopterCollective) + " Desired Alt: " + FString::SanitizeFloat(fpDesiredAltitude) + "  Alt: " + FString::SanitizeFloat(fpCurrentRealAltitude) + " Dist: " + FString::SanitizeFloat(fpDistFromAltitude) + " Vel: " + FString::SanitizeFloat(fpVertVelocity);
		}
		else
		{
			AdjustForAltitudeHold();
		}
	}
}

void ANPCBaseRavenController::AdjustForDesiredSpeed()
{
	if (agpvVehicle->Velocity.Z < agpvVehicle->DesiredSpeed)
	{
		agpvVehicle->fpHelicopterCyclicPitch += 0.1;
	}
	else
	{
		if (agpvVehicle->Velocity.Z > agpvVehicle->DesiredSpeed)
		{
			agpvVehicle->fpHelicopterCyclicPitch=-0.01;
		}
		else
		{
			agpvVehicle->fpHelicopterCyclicPitch=0;
		}
	}
}

void ANPCBaseRavenController::AdjustToDesiredHeight()
{
	if (agpvVehicle->Velocity.Z < agpvVehicle->DesiredSpeed)
	{
		agpvVehicle->fpHelicopterCyclicPitch += 0.1;
	}
	else
	{
		if (agpvVehicle->Velocity.Z > agpvVehicle->DesiredSpeed)
		{
			agpvVehicle->fpHelicopterCyclicPitch=-0.01;
		}
		else
		{
			agpvVehicle->fpHelicopterCyclicPitch=0;
		}
	}
}

bool ANPCBaseRavenController::TurnedEnough(float fpAngle)
{
	FVector vDesiredRotation = FVector(0,0,0);
	FVector vCurrentRotation = FVector(0,0,0);
	/*
	vDesiredRotation=Normal( Vector(DesiredRotation));
	vCurrentRotation=Normal( Vector(agpvVehicle->Rotation));
	if (vDesiredRotation Dot vCurrentRotation > 0.96 + fpAngle)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void ANPCBaseRavenController::AdjustThrottleToDesiredSpeed()
{
	float fpSpeedRatio = 0;
	if (agpvVehicle->DesiredSpeed == 0)
	{
		StopMovement();
	}
	if (agpvVehicle->DesiredSpeed > 0)
	{
		fpSpeedRatio=agpvVehicle->DesiredSpeed / fpMaxSpeed * -1;
		sDebugCyclicPitch="Moving forward adjusting by " + FString::SanitizeFloat(fpSpeedRatio);
	}
	else
	{
		fpSpeedRatio=agpvVehicle->DesiredSpeed / fpMaxBackwardSpeed;
		sDebugCyclicPitch="Moving backward adjusting by " + FString::SanitizeFloat(fpSpeedRatio);
	}
	agpvVehicle->fpHelicopterCyclicPitch=fpSpeedRatio;
}

void ANPCBaseRavenController::StopMovement()
{
	/*
	if (VSize(agpvVehicle->Velocity) > 1)
	{
		if (agpvVehicle->Rotation.Pitch > 32768 || agpvVehicle->Rotation.Pitch < 0)
		{
			agpvVehicle->fpHelicopterCyclicPitch=VSize(agpvVehicle->Velocity) * -0.01;
		}
		else
		{
			agpvVehicle->fpHelicopterCyclicPitch=VSize(agpvVehicle->Velocity) * 0.01;
		}
		//sDebugNavInfo="Trying to stop, pitch " + agpvVehicle->Rotation.Pitch + " Collective: " + agpvVehicle->fpHelicopterCyclicPitch;
		return false;
	}
	else
	{
		agpvVehicle->fpHelicopterCyclicPitch=0;
	}
	*/
	//return true;
}

bool ANPCBaseRavenController::DescendToAltitude(float fpTargetHeight)
{
	float fpCurrentAltitude = 0;
	float fpMaxDescentSpeed = 0;
	fpMaxDescentSpeed=-250;
	fpCurrentAltitude=GetRealAltitude();
	if (FMath::Abs(fpCurrentAltitude - fpTargetHeight) < 50)
	{
		if (agpvVehicle->Velocity.Z > 0)
		{
			agpvVehicle->fpHelicopterCollective=0;
			return false;
		}
		else
		{
			if (agpvVehicle->Velocity.Z < -3)
			{
				agpvVehicle->fpHelicopterCollective=0.01;
				return false;
			}
			else
			{
				agpvVehicle->fpHelicopterCollective=0.001;
				return true;
			}
		}
	}
	if (fpCurrentAltitude <= fpTargetHeight + 50)
	{
		if (agpvVehicle->Velocity.Z < -5)
		{
			agpvVehicle->fpHelicopterCollective=0.01 * agpvVehicle->Velocity.Z * -1;
			sDebugCollective="Altitude below or at target height, still moving down";
			return false;
		}
		else
		{
			agpvVehicle->fpHelicopterCollective=0.001;
			sDebugCollective="Altitude below or at target height, not moving (done) ";
			return true;
		}
	}
	if (agpvVehicle->Velocity.Z < fpMaxDescentSpeed)
	{
		if (FMath::Abs(fpTargetHeight - fpCurrentAltitude) < 200)
		{
			agpvVehicle->fpHelicopterCollective += 0.2;
			//sDebugCollective="Moving down and close, speed " + agpvVehicle->Velocity.Z + ", slowing rate, collective at " + agpvVehicle->fpHelicopterCollective;
		}
		else
		{
			agpvVehicle->fpHelicopterCollective += 0.02;
			//sDebugCollective="Moving down but not close, speed " + agpvVehicle->Velocity.Z + ", slowing rate, collective at " + agpvVehicle->fpHelicopterCollective;
		}
	}
	else
	{
		if (agpvVehicle->Velocity.Z > fpMaxDescentSpeed)
		{
			agpvVehicle->fpHelicopterCollective=-0.01;
			//sDebugCollective="Not moving down, reducing collective, now " + agpvVehicle->fpHelicopterCollective;
		}
	}
	return false;
}

void ANPCBaseRavenController::DetermineNextPathNode()
{
	if (bAscendingNodeDirection)
	{
		if (iCurrentDrivingPathNodeIndex < apnFlyingPathNodesForPatrol.Num() - 1)
		{
			iCurrentDrivingPathNodeIndex ++;
		}
		else
		{
			if (bAutoReversePath)
			{
				if (apnFlyingPathNodesForPatrol.Num() > 0)
				{
					if (apnFlyingPathNodesForPatrol.Num() == 1)
					{
						MoveTimer=-1;
						agpvVehicle->Throttle=0;
						agpvVehicle->Steering=0;
						agpvVehicle->fpHelicopterCollective=0;
						//GetPawn()->bRotateToDesired=false;
						bAutoReversePath=false;
						ChangeState("None");
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
			}
		}
		NPCLog("");
		NPCLog("");
		//NPCLog("Ascending pathnodes - new index: " + iCurrentPathNodeIndex + " node: " + apnFlyingPathNodesForPatrol[iCurrentPathNodeIndex].Tag);
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
			if (bAutoReversePath)
			{
				if (apnFlyingPathNodesForPatrol.Num() > 0)
				{
					NPCLog("Reversing direction back to ascending");
					bAscendingNodeDirection=true;
					DetermineNextPathNode();
					return;
				}
			}
			else
			{
				iCurrentDrivingPathNodeIndex=apnFlyingPathNodesForPatrol.Num() - 1;
			}
		}
		NPCLog("Descending pathnodes - new index: " + iCurrentPathNodeIndex);
	}
	FindNextDrivingPatrolPathNode();
}

void ANPCBaseRavenController::DebugDumpRoute()
{
	int32 i = 0;
	NPCLog("******************************");
	//NPCLog("Vehicle Route goal: " + RouteGoal + ", distance: " + RouteDist);
	for (i=0; i<62; i++)
	{
		if (RouteCache[i] != nullptr)
		{
			//NPCLog("Route[ " + i + "] => " + RouteCache[i] + ": " + RouteCache[i].Tag);
		}
	}
	NPCLog("******************************");
}

void ANPCBaseRavenController::NPCPathLog(FString sLogText)
{
	//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + "." + Tag + "." + sNPCWaypointTag + sLogText);
}

void ANPCBaseRavenController::NPCLog(FString sLogText)
{
	if (agpvVehicle != nullptr && agpvVehicle->Driver != nullptr)
	{
		//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + agpvVehicle->Driver + " " + sLogText);
	}
	else
	{
		if (GetPawn() != nullptr)
		{
			//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + Pawn.Name + " " + sLogText);
		}
		else
		{
			//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + sLogText);
		}
	}
}

void ANPCBaseRavenController::EnableDebugTerrainRadarTrace()
{
	if (dnpcnDebugTerrainRadarMarker == nullptr)
	{
		//dnpcnDebugTerrainRadarMarker=Spawn('DebugNPCNavigation');
		//dnpcnDebugTerrainRadarMarker->SetCollision(false,false,false);
		//dnpcnDebugTerrainRadarMarker->bHidden=false;
	}
}

void ANPCBaseRavenController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	/*
	Log(Self + ".NotifyTakeDamage() - New Health: " + Pawn.Health);
	if (Pawn.Health <= 0)
	{
		ChangeState('HelicopterShotDown');
	}
	*/
}

