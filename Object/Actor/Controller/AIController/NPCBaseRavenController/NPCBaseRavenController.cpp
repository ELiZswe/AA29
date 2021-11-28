// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/NPCBaseRavenController/NPCBaseRavenController.h"

ANPCBaseRavenController::ANPCBaseRavenController()
{
	sCallSign = "Alpha-Bravo-Charlie 1-2-3";
	fpMaxSpeed = 500;
	fpMaxBackwardSpeed = -200;
	bSlowerZAcquire = false;
	bProp = true;
}

/*
* State NoVehicle
{
	Function BeginState ()
	{
		NPCLog("NPC " $ Tag $ " could not find a vehicle!");
	}
}
State InitializeVehicle
{
	Function CopyPredefinedWaypoints ()
	{
		local int iPreDefPN;
		if (auavfpwpWaypoints.Length > 0)
		{
			auavfpwpWaypoints.remove (0,auavfpwpWaypoints.Length);
		}
		Log("Vehicle Path Nodes: " $ apnFlyingPathNodesForPatrol.Length);
		if (apnFlyingPathNodesForPatrol.Length > 0)
		{
			auavfpwpWaypoints.insert (0,apnFlyingPathNodesForPatrol.Length);
			for (iPreDefPN=0; iPreDefPN<apnFlyingPathNodesForPatrol.Length; iPreDefPN++)
			{
				auavfpwpWaypoints[iPreDefPN].vLocation=apnFlyingPathNodesForPatrol[iPreDefPN].Location;
				auavfpwpWaypoints[iPreDefPN].fpSpeed=850;
				auavfpwpWaypoints[iPreDefPN].fpAltitude=2000;
				Log("Copied vehicle pathnode " $ iPreDefPN $ " into waypoint list at loc " $ auavfpwpWaypoints[iPreDefPN].vLocation);
			}
		}
	}
}
State Failure
{
}
State MechanicalFailure
{
}
State HoverMode
{
}
State TestPitch
{
}
State HeadForWaypoint
{
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
		Log("Take damage while navigating, adjust altitude (time since last adjust: " $ Abs(Level.TimeSeconds - fpLastGroundFireAdjust));
		if (Abs(Level.TimeSeconds - fpLastGroundFireAdjust) < 10)
		{
			Return;
		}
		if (fpGroundFireAvoidanceAltitudeBump <= 0)
		{
			fpGroundFireAvoidanceAltitudeBump=500;
		}
		else
		{
			fpGroundFireAvoidanceAltitudeBump=-500;
		}
		Log("TakeDamage adjusted altitude bump now: " $ fpGroundFireAvoidanceAltitudeBump);
		fpLastGroundFireAdjust=Level.TimeSeconds;
	}
	Function GetDistanceToWaypoint2D ()
	{
		local Object.Vector vAdjustedVehicleLocation;
		vAdjustedVehicleLocation=agpvVehicle.Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		Return VSize(vAdjustedVehicleLocation - vAdjustedPathNodeLocation);
	}
	Function GonePast ()
	{
		local Object.Vector vDirectionToGoal;
		local Object.Vector vCurrentRotation;
		vDirectionToGoal=Normal(agpvVehicle.Location - vAdjustedPathNodeLocation);
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
		if (vDirectionToGoal Dot vCurrentRotation < 0)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	}
}
State CircleArea
{
}
State TurnRight
{
}
State TurnLeft
{
}
State StraightFlight
{
}
State HeadForLandingZone
{
	Event Bool NotifyHitWall (Object.Vector HitNormal, Actor Wall)
	{
		if (Wall.IsA('TerrainInfo'))
		{
			Log("NotifyHitWall for Helicopter on terrain");
			GotoState('LandedMode');
		}
		Return False;
	}
	Function AdjustThrottleToDesiredSpeed ()
	{
		local float fpSpeedRatio;
		if (agpvVehicle.DesiredSpeed == 0)
		{
			StopMovement();
		}
		if (agpvVehicle.DesiredSpeed > 0)
		{
			fpSpeedRatio=agpvVehicle.DesiredSpeed / fpMaxSpeed * -1;
			sDebugCyclicPitch="Moving forward adjusting by " $ fpSpeedRatio;
		}
		else
		{
			fpSpeedRatio=agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed;
			sDebugCyclicPitch="Moving backward adjusting by " $ fpSpeedRatio;
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	}
	Function GetDistanceToWaypoint2D ()
	{
		local Object.Vector vAdjustedVehicleLocation;
		vAdjustedVehicleLocation=agpvVehicle.Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		Return VSize(vAdjustedVehicleLocation - vAdjustedPathNodeLocation);
	}
	Function GonePast ()
	{
		local Object.Vector vDirectionToGoal;
		local Object.Vector vCurrentRotation;
		vDirectionToGoal=Normal(agpvVehicle.Location - vAdjustedPathNodeLocation);
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
		if (vDirectionToGoal Dot vCurrentRotation < 0)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	}
	Function StopMovement ()
	{
		if (VSize(agpvVehicle.Velocity) > 1)
		{
			if (agpvVehicle.Rotation.Pitch > 32768 || agpvVehicle.Rotation.Pitch < 0)
			{
				agpvVehicle.fpHelicopterCyclicPitch=VSize(agpvVehicle.Velocity) * -0.01;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=VSize(agpvVehicle.Velocity) * 0.01;
			}
			sDebugNavInfo="Trying to stop, pitch " $ agpvVehicle.Rotation.Pitch $ " Collective: " $ agpvVehicle.fpHelicopterCyclicPitch;
			Return False;
		}
		else
		{
			agpvVehicle.fpHelicopterCyclicPitch=0;
		}
		Return True;
	}
	Function TurnedEnough (optional float fpAngle)
	{
		local Object.Rotator rotDesiredRotation;
		local Object.Rotator rotCurrentRotation;
		local Object.Vector vDesiredRotation;
		local Object.Vector vCurrentRotation;
		rotDesiredRotation=DesiredRotation;
		rotDesiredRotation.Pitch=0;
		vDesiredRotation=Normal( Vector(rotDesiredRotation));
		rotCurrentRotation=agpvVehicle.Rotation;
		rotCurrentRotation.Pitch=0;
		vCurrentRotation=Normal( Vector(rotCurrentRotation));
		sDebugNavInfo="Turning to LZ direction " $ vDesiredRotation Dot vCurrentRotation;
		if (vDesiredRotation Dot vCurrentRotation > 0.96 + fpAngle)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	}
}
State ManualControl
{
}
State TakeOffMode
{
	Function AscendToAltitude (float fpTargetHeight)
	{
		local float fpCurrentAltitude;
		local float fpMaxAscentSpeed;
		fpMaxAscentSpeed=200;
		fpCurrentAltitude=GetRealAltitude();
		if (Abs(fpCurrentAltitude - fpTargetHeight) < 20)
		{
			if (agpvVehicle.Velocity.Z > 2)
			{
				agpvVehicle.fpHelicopterCollective=0;
				Return False;
			}
			else
			{
				Return True;
			}
		}
		if (fpCurrentAltitude >= fpTargetHeight - 250)
		{
			if (agpvVehicle.Velocity.Z > 5)
			{
				if (agpvVehicle.Velocity.Z > 25)
				{
					agpvVehicle.fpHelicopterCollective=-0.001 * agpvVehicle.Velocity.Z - 25;
				}
				else
				{
					agpvVehicle.fpHelicopterCollective=-0.01;
				}
				sDebugCollective="Altitude above or at target height, still moving up";
				Return False;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0.001;
				sDebugCollective="Altitude above or at target height, not moving (done) ";
				Return True;
			}
		}
		if (agpvVehicle.Velocity.Z > 50)
		{
			if (Abs(fpTargetHeight - fpCurrentAltitude) < 200 && agpvVehicle.Velocity.Z > 10)
			{
				agpvVehicle.fpHelicopterCollective -= 0.001;
				sDebugCollective="Moving up and close, speed " $ agpvVehicle.Velocity.Z $ ", slowing rate, collective at " $ agpvVehicle.fpHelicopterCollective;
			}
			else
			{
				if (agpvVehicle.Velocity.Z < fpMaxAscentSpeed)
				{
					agpvVehicle.fpHelicopterCollective += 0.005;
				}
				sDebugCollective="Moving up but not close, speed " $ agpvVehicle.Velocity.Z $ ", slowing rate, collective at " $ agpvVehicle.fpHelicopterCollective;
			}
		}
		else
		{
			agpvVehicle.fpHelicopterCollective=0.05;
			sDebugCollective="Not moving up, increasing collective, now " $ agpvVehicle.fpHelicopterCollective;
		}
		Return False;
	}
}
State HelicopterShotDown
{
	Event Touch (Actor Other)
	{
		agpvVehicle.SpawnDestructionEffects();
		GotoState('Dead');
	}
	Event Landed (Object.Vector HitNormal)
	{
		Log("Landed event for Helicopter");
		agpvVehicle.SpawnDestructionEffects();
		GotoState('Dead');
		Return;
	}
	Event Bool NotifyHitWall (Object.Vector HitNormal, Actor Wall)
	{
		Log("NotifyHitWall for Helicopter on terrain");
		agpvVehicle.SpawnDestructionEffects();
		GotoState('Dead');
		Return False;
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
}
State Dead
{
	Function SwapInDestroyedMesh ()
	{
		local Object.Vector vLoc;
		local Object.Rotator Rot;
		Rot=agpvVehicle.Rotation;
		vLoc=agpvVehicle.Location;
		agpvVehicle.SetDrawType(8);
		agpvVehicle.SetPhysics(0);
		agpvVehicle.SetStaticMesh(StaticMesh(DynamicLoadObject("M_AA2_Vehicles.blackhawk.veh_blackhawk_fullcrashed",Class'StaticMesh')));
		agpvVehicle.SetCollision(False,False,False);
		agpvVehicle.bWorldGeometry=True;
		agpvVehicle.bCollideWorld=False;
		agpvVehicle.SetRotation(Rot + MakeRot(0,0,4096));
		agpvVehicle.SetLocation(vLoc + MakeVect(0,0,- 50));
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
}
*/

/*
void ANPCBaseRavenController::DisplayDebug(UCanvas Canvas, float& YL, float& YPos)
{
		YL=10;
		if (Pawn.IsA('Vehicle'))
		{
			Pawn.DisplayDebug(Canvas,YL,YPos);
			YPos += YL;
			YPos += YL;
			Canvas.SetDrawColor(255,255,255);
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Current Location: " $ Vehicle(Pawn).Location $ " Current State: " $ GetStateName());
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Collective: " $ Vehicle(Pawn).fpHelicopterCollective $ "  Cyclic Pitch: " $ Vehicle(Pawn).fpHelicopterCyclicPitch $ "  Desired Speed " $ agpvVehicle.DesiredSpeed);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Rotation: " $ Vehicle(Pawn).Rotation $ "  Desired Rotation: " $ DesiredRotation $ " Alt: " $ GetRealAltitude() $ "  GF Bump: " $ fpGroundFireAvoidanceAltitudeBump);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Velocity: " $ Vehicle(Pawn).Velocity $ " (Speed: " $ VSize(agpvVehicle.Velocity) $ ")");
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Next Waypoint: " $ pnCurrentFlyingPathNode $ " Distance to waypoint: " $ VSize(agpvVehicle.Location - vAdjustedPathNodeLocation) $ " Ratio to destination: " $ VSize(agpvVehicle.Location - vAdjustedPathNodeLocation) / 5500);
			YPos += YL;
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Navigation Status: " $ sDebugNavInfo);
			YPos += YL;
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Mode: " $ sDebugNavMode);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Cyclic Status: " $ sDebugCyclicPitch);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Collective Status: " $ sDebugCollective);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Collective Status2: " $ sDebugCollective2);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Altitude Status: " $ sDebugAltitude);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Currently Over: " $ sDebugAltitude2);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Crash Status: " $ sDebugCrashStatus);
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Forward altitude: " $ sDebugFwdAltitude);
			YPos += YL;
			YPos += YL;
			Canvas.SetPos(4,YPos);
			Canvas.DrawText("Torque: " $ Vehicle(Pawn).HUDOverlayOffset $ "   Force: " $ Vehicle(Pawn).FlagOffset);
		}
}
*/

void ANPCBaseRavenController::Land(FVector vLoc)
{
	vLocationLandingZone = vLoc;
	//GotoState('HeadForLandingZone');
}

void ANPCBaseRavenController::NextWaypoint()
{
	bFollowPatrol = false;
	//GotoState('HeadForWaypoint');
}

void ANPCBaseRavenController::TakeOff()
{
	//GotoState('TakeOffMode');
}

void ANPCBaseRavenController::Hover()
{
	//GotoState('HoverMode');
}

void ANPCBaseRavenController::Start()
{
	//GotoState('InitializeVehicle');
}

void ANPCBaseRavenController::Patrol()
{
	bFollowPatrol = true;
	//GotoState('HeadForWaypoint');
}

void ANPCBaseRavenController::GetPathnodeByTagString(FString sTag)
{
	/*
		local NavigationPoint N;
		if (Len(sTag) > 0)
		{
			N=Level.NavigationPointList;
			if (N != None)
			{
				if (N.IsA('FlyingPathNode') && sTag == N.Tag)
				{
					Return PathNode(N);
				}
				N=N.nextNavigationPoint;
			}
		}
		Return None;
	*/
}

void ANPCBaseRavenController::PreloadPathNodeList()
{
	/*
		local int iNode;
		local PathNode pnFound;
		bDebugMode=True;
		bDebugPath=True;
		for (iNode=0; iNode<=99; iNode++)
		{
			pnFound=GetPathnodeByTagString(sNPCWaypointTag $ "-" $ iNode + 1);
			if (pnFound == None)
			{
			}
			apnFlyingPathNodesForPatrol.insert (iNode,1);
			apnFlyingPathNodesForPatrol[iNode]=FlyingPathNode(pnFound);
			if (bDebugPath)
			{
				pnFound.bHidden=False;
			}
			Log("Found path node for " $ sNPCWaypointTag $ "-" $ iNode + 1 $ " -> " $ pnFound.Tag $ " total found " $ apnFlyingPathNodesForPatrol.Length);
		}
	*/
}

void ANPCBaseRavenController::FindNextDrivingPatrolPathNode()
{
	/*
		NPCPathLog("Searching for next navpoint to move to: " $ iCurrentDrivingPathNodeIndex + 1);
		if (apnFlyingPathNodesForPatrol.Length == 0)
		{
			NPCPathLog("FindNextDrivingPatrolPathNode() - No patrol paths have been defined");
			Return None;
		}
		if (iCurrentDrivingPathNodeIndex < apnFlyingPathNodesForPatrol.Length)
		{
			NPCPathLog("Found pathnode: " $ apnFlyingPathNodesForPatrol[iCurrentDrivingPathNodeIndex].Tag);
			pnCurrentFlyingPathNode=apnFlyingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
			Return pnCurrentFlyingPathNode;
		}
		NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
		Return None;
	*/
}

void ANPCBaseRavenController::InitVehicle()
{
	bDebugMode = true;
	bStart = true;
	/*
		if (VehicleTag != 'None')
		{
			agpvVehicle=Spawn(VehicleClass,,VehicleTag,Location,Rotation);
		}
		else
		{
			agpvVehicle=Spawn(VehicleClass,,,Location,Rotation);
		}
		Log("UAV Vehicle spawned: " $ agpvVehicle);
		agpvVehicle.PeripheralVision=-99;
		sVehicleType=agpvVehicle.VehicleNameString;
	*/
}

/*
void ANPCBaseRavenController::Possess (APawn* aPawn)
{
	if (aPawn.IsA('Vehicle'))
	{
		Log("Possessing UAV: " $ aPawn);
		Possess(aPawn);
	}
}
*/

/*
void ANPCBaseRavenController::UnPossess()
{
if (Pawn.IsA('AGP_Pawn'))
	{
		NPCLog("Current pawn is AGP_Pawn (driver leaving vehicle), so we're doing nothing there");
	}
}
*/

void ANPCBaseRavenController::WatchForMechanicalFailuresTimer()
{
	/*
		if (fpEngineFailureChance > 0 && FRand() > 1 - fpEngineFailureChance)
		{
			if (fpMechanicalFailureTimer == 0)
			{
				fpMechanicalFailureTimer=Level.TimeSeconds + 30 + FRand() * 120;
				Log("Mechanical failure scheduled for " $ fpMechanicalFailureTimer);
			}
			else
			{
				if (Level.TimeSeconds >= fpMechanicalFailureTimer && fpMechanicalFailureTimer > 0)
				{
					fpMechanicalFailureTimer=0;
					fpEngineFailureChance=0;
					GotoState('MechanicalFailure');
				}
			}
		}
	*/
}

void ANPCBaseRavenController::LocationToGrid(FVector vLoc)
{
	/*
		local string sResult;
		local float fpScale;
		local int iGridX;
		local int iGridY;
		local FVector vTopLeft;
		fpScale=Level.RadarMapSize * 2 / 100;
		vTopLeft.X=Level.RadarMapOffset.X - Level.RadarMapSize;
		vTopLeft.Y=Level.RadarMapOffset.Y - Level.RadarMapSize;
		vTopLeft.Z=0;
		iGridX=vLoc.X - vTopLeft.X / fpScale;
		iGridX += Level.Game.GameReplicationInfo.iSpotterBaseGridX;
		iGridY=vLoc.Y - vTopLeft.Y / fpScale;
		iGridY += Level.Game.GameReplicationInfo.iSpotterBaseGridY;
		sResult="" $ iGridX $ " by " $ iGridY;
		Return sResult;
	*/
}

void ANPCBaseRavenController::AdjustPitchForPositionHold()
{
	/*
		if (agpvVehicle.Velocity.X <= -1)
		{
			agpvVehicle.fpHelicopterCyclicPitch -= 0.01;
			sDebugCyclicPitch="Adjusting pitch to slow backward movement: " $ agpvVehicle.fpHelicopterCyclicPitch;
		}
		else
		{
			if (agpvVehicle.Velocity.X >= 1)
			{
				agpvVehicle.fpHelicopterCyclicPitch += 0.01;
				sDebugCyclicPitch="Adjusting pitch to slow forward movement: " $ agpvVehicle.fpHelicopterCyclicPitch;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=0;
				sDebugCyclicPitch="Pitch hold ok: " $ agpvVehicle.fpHelicopterCyclicPitch;
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustRollForPositionHold()
{
	/*
		if (agpvVehicle.Velocity.Y < -1)
		{
			agpvVehicle.fpHelicopterCyclicRoll += 0.01;
		}
		else
		{
			if (agpvVehicle.Velocity.Y > 1)
			{
				agpvVehicle.fpHelicopterCyclicRoll -= 0.01;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicRoll=0;
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustForAltitudeHold()
{
	/*
		if (agpvVehicle.Velocity.Z <= -2.5)
		{
			agpvVehicle.fpHelicopterCollective=0.01 * Abs(agpvVehicle.Velocity.Z);
			sDebugCollective="Hold Altitude (velocity " $ agpvVehicle.Velocity.Z $ "), raising collective to " $ agpvVehicle.fpHelicopterCollective;
		}
		else
		{
			if (agpvVehicle.Velocity.Z >= 2.5)
			{
				agpvVehicle.fpHelicopterCollective=-0.001 * Abs(agpvVehicle.Velocity.Z);
				sDebugCollective="Hold Altitude (velocity " $ agpvVehicle.Velocity.Z $ "), lowering collective to " $ agpvVehicle.fpHelicopterCollective;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0;
				sDebugCollective="Hold Altitude (velocity " $ agpvVehicle.Velocity.Z $ "), holding collective at " $ agpvVehicle.fpHelicopterCollective;
			}
		}
	*/
}

void ANPCBaseRavenController::GetForwardRealAltitude()
{
	/*
		local Actor actTraceHit;
		local FVector vHitLocation;
		local FVector vHitNormal;
		local FVector vEndTrace;
		local FVector vStartTrace;
		local FRotator rotCleaned;
		vStartTrace=Pawn.Location;
		rotCleaned=Pawn.Rotation;
		rotCleaned.Pitch=0;
		rotCleaned.Roll=0;
		vStartTrace +=  Vector(rotCleaned) * 2000 + VSize(agpvVehicle.Velocity);
		vEndTrace=vStartTrace;
		vEndTrace.Z -= 10000;
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,True);
		if (actTraceHit == None)
		{
			if (dnpcnDebugTerrainRadarMarker != None)
			{
				dnpcnDebugTerrainRadarMarker.bHidden=True;
			}
			sDebugFwdAltitude="Trace hit nothing";
			Return -1;
		}
		if (actTraceHit.IsA('LevelInfo'))
		{
			if (dnpcnDebugTerrainRadarMarker != None)
			{
				dnpcnDebugTerrainRadarMarker.bHidden=True;
			}
			sDebugFwdAltitude="Trace hit levelinfo";
			Return 0;
		}
		sDebugFwdAltitude="Trace hit " $ actTraceHit $ " distance " $ vStartTrace.Z - vHitLocation.Z;
		if (dnpcnDebugTerrainRadarMarker != None)
		{
			dnpcnDebugTerrainRadarMarker.bHidden=False;
			vHitLocation.Z += 100;
			dnpcnDebugTerrainRadarMarker.SetLocation(vHitLocation);
		}
		Return vStartTrace.Z - vHitLocation.Z;
	*/
}

void ANPCBaseRavenController::GetRealAltitude()
{
	/*
		local Actor actTraceHit;
		local FVector vHitLocation;
		local FVector vHitNormal;
		local FVector vEndTrace;
		local FVector vStartTrace;
		vStartTrace=Pawn.GetBoneCoords('Pilot').Origin;
		sDebugAltitude="Pawn Location: " $ Pawn.Location $ " Pilot origin: " $ vStartTrace $ "  Distance " $ VSize(Pawn.Location - vStartTrace);
		vEndTrace=vStartTrace;
		vEndTrace.Z -= 10000;
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,True);
		sDebugAltitude2="Trace hit " $ actTraceHit;
		if (actTraceHit == None)
		{
			Return fpRealAltitude;
		}
		if (actTraceHit.IsA('LevelInfo'))
		{
			Return fpRealAltitude;
		}
		fpRealAltitude=vStartTrace.Z - vHitLocation.Z;
		Return fpRealAltitude;
	*/
}

void ANPCBaseRavenController::HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding)
{
	/*
		local float fpCurrentRealAltitude;
		local float fpVertVelocity;
		local float fpDistFromAltitude;
		local float fpMaxUUAboveVariation;
		local float fpMaxUUBelowVariation;
		if (! bDisableVarianceForLanding)
		{
			fpMaxUUAboveVariation=25;
			fpMaxUUBelowVariation=25;
		}
		fpCurrentRealAltitude=GetRealAltitude();
		if (fpCurrentRealAltitude == -1 || fpCurrentRealAltitude == 0)
		{
			Return;
		}
		fpDistFromAltitude=Abs(fpCurrentRealAltitude - fpDesiredAltitude);
		fpVertVelocity=agpvVehicle.Velocity.Z;
		if (fpCurrentRealAltitude > fpDesiredAltitude && fpDistFromAltitude > fpMaxUUAboveVariation)
		{
			if (fpVertVelocity > 5)
			{
				sDebugCollective2="Ascending from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
				AdjustForAltitudeHold();
			}
			else
			{
				if (fpDistFromAltitude < 250)
				{
					if (fpVertVelocity < -10)
					{
						sDebugCollective2="< 250, velocity too fast from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
						agpvVehicle.fpHelicopterCollective=0.05;
					}
					else
					{
						sDebugCollective2="velocity OK, maintaining collective from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
					}
				}
				else
				{
					if (fpVertVelocity > -15)
					{
						sDebugCollective2="Velocity slow from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
						agpvVehicle.fpHelicopterCollective -= 0.005;
					}
					else
					{
						if (fpVertVelocity <= -50)
						{
							sDebugCollective2="velocity too fast from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
							if (agpvVehicle.fpHelicopterCollective < 0)
							{
								agpvVehicle.fpHelicopterCollective=0;
							}
							else
							{
								if (agpvVehicle.fpHelicopterCollective < 0.25)
								{
									agpvVehicle.fpHelicopterCollective += 0.001;
								}
							}
						}
					}
				}
				sDebugCollective="Descending collective " $ agpvVehicle.fpHelicopterCollective $ " Desired Alt: " $ fpDesiredAltitude $ "  Alt: " $ fpCurrentRealAltitude $ " Dist: " $ fpDistFromAltitude $ " Vel: " $ fpVertVelocity;
			}
		}
		else
		{
			if (fpCurrentRealAltitude < fpDesiredAltitude && fpDistFromAltitude > fpMaxUUBelowVariation)
			{
				if (fpVertVelocity < 0)
				{
					sDebugCollective2="Trying to stop descent from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
					AdjustForAltitudeHold();
				}
				else
				{
					if (fpDistFromAltitude < 250)
					{
						if (fpVertVelocity > 20)
						{
							sDebugCollective2="Close, velocity too fast from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
							agpvVehicle.fpHelicopterCollective -= 0.001;
						}
						else
						{
							sDebugCollective2="Close, good velocity from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
							if (fpVertVelocity < 5)
							{
								agpvVehicle.fpHelicopterCollective += 0.001;
							}
							else
							{
								agpvVehicle.fpHelicopterCollective=0.002;
							}
						}
					}
					else
					{
						if (agpvVehicle.fpHelicopterCollective < 0.25)
						{
							sDebugCollective2="Not close, collective < .25 from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
							if (agpvVehicle.fpHelicopterCollective < 0)
							{
								agpvVehicle.fpHelicopterCollective=0;
							}
							agpvVehicle.fpHelicopterCollective += 0.001;
						}
						else
						{
							sDebugCollective2="Not close, collective < .25 from " $ fpCurrentRealAltitude $ " to " $ fpDesiredAltitude;
							agpvVehicle.fpHelicopterCollective=0.01;
						}
					}
				}
				sDebugCollective="Ascending, collective " $ agpvVehicle.fpHelicopterCollective $ " Desired Alt: " $ fpDesiredAltitude $ "  Alt: " $ fpCurrentRealAltitude $ " Dist: " $ fpDistFromAltitude $ " Vel: " $ fpVertVelocity;
			}
			else
			{
				AdjustForAltitudeHold();
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustForDesiredSpeed()
{
	/*
		if (agpvVehicle.Velocity.Z < agpvVehicle.DesiredSpeed)
		{
			agpvVehicle.fpHelicopterCyclicPitch += 0.1;
		}
		else
		{
			if (agpvVehicle.Velocity.Z > agpvVehicle.DesiredSpeed)
			{
				agpvVehicle.fpHelicopterCyclicPitch=-0.01;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=0;
			}
		}
	*/
}

void ANPCBaseRavenController::AdjustToDesiredHeight()
{
	/*
		if (agpvVehicle.Velocity.Z < agpvVehicle.DesiredSpeed)
		{
			agpvVehicle.fpHelicopterCyclicPitch += 0.1;
		}
		else
		{
			if (agpvVehicle.Velocity.Z > agpvVehicle.DesiredSpeed)
			{
				agpvVehicle.fpHelicopterCyclicPitch=-0.01;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=0;
			}
		}
	*/
}

void ANPCBaseRavenController::TurnedEnough(float fpAngle)
{
	/*
		local FVector vDesiredRotation;
		local FVector vCurrentRotation;
		vDesiredRotation=Normal( Vector(DesiredRotation));
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
		if (vDesiredRotation Dot vCurrentRotation > 0.96 + fpAngle)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	*/
}

void ANPCBaseRavenController::AdjustThrottleToDesiredSpeed()
{
	/*
		local float fpSpeedRatio;
		if (agpvVehicle.DesiredSpeed == 0)
		{
			StopMovement();
		}
		if (agpvVehicle.DesiredSpeed > 0)
		{
			fpSpeedRatio=agpvVehicle.DesiredSpeed / fpMaxSpeed * -1;
			sDebugCyclicPitch="Moving forward adjusting by " $ fpSpeedRatio;
		}
		else
		{
			fpSpeedRatio=agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed;
			sDebugCyclicPitch="Moving backward adjusting by " $ fpSpeedRatio;
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	*/
}

void ANPCBaseRavenController::StopMovement()
{
	/*
		if (VSize(agpvVehicle.Velocity) > 1)
		{
			if (agpvVehicle.Rotation.Pitch > 32768 || agpvVehicle.Rotation.Pitch < 0)
			{
				agpvVehicle.fpHelicopterCyclicPitch=VSize(agpvVehicle.Velocity) * -0.01;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=VSize(agpvVehicle.Velocity) * 0.01;
			}
			sDebugNavInfo="Trying to stop, pitch " $ agpvVehicle.Rotation.Pitch $ " Collective: " $ agpvVehicle.fpHelicopterCyclicPitch;
			Return False;
		}
		else
		{
			agpvVehicle.fpHelicopterCyclicPitch=0;
		}
		Return True;
	*/
}

void ANPCBaseRavenController::DescendToAltitude(float fpTargetHeight)
{
	/*
		local float fpCurrentAltitude;
		local float fpMaxDescentSpeed;
		fpMaxDescentSpeed=-250;
		fpCurrentAltitude=GetRealAltitude();
		if (Abs(fpCurrentAltitude - fpTargetHeight) < 50)
		{
			if (agpvVehicle.Velocity.Z > 0)
			{
				agpvVehicle.fpHelicopterCollective=0;
				Return False;
			}
			else
			{
				if (agpvVehicle.Velocity.Z < -3)
				{
					agpvVehicle.fpHelicopterCollective=0.01;
					Return False;
				}
				else
				{
					agpvVehicle.fpHelicopterCollective=0.001;
					Return True;
				}
			}
		}
		if (fpCurrentAltitude <= fpTargetHeight + 50)
		{
			if (agpvVehicle.Velocity.Z < -5)
			{
				agpvVehicle.fpHelicopterCollective=0.01 * agpvVehicle.Velocity.Z * -1;
				sDebugCollective="Altitude below or at target height, still moving down";
				Return False;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0.001;
				sDebugCollective="Altitude below or at target height, not moving (done) ";
				Return True;
			}
		}
		if (agpvVehicle.Velocity.Z < fpMaxDescentSpeed)
		{
			if (Abs(fpTargetHeight - fpCurrentAltitude) < 200)
			{
				agpvVehicle.fpHelicopterCollective += 0.2;
				sDebugCollective="Moving down and close, speed " $ agpvVehicle.Velocity.Z $ ", slowing rate, collective at " $ agpvVehicle.fpHelicopterCollective;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective += 0.02;
				sDebugCollective="Moving down but not close, speed " $ agpvVehicle.Velocity.Z $ ", slowing rate, collective at " $ agpvVehicle.fpHelicopterCollective;
			}
		}
		else
		{
			if (agpvVehicle.Velocity.Z > fpMaxDescentSpeed)
			{
				agpvVehicle.fpHelicopterCollective=-0.01;
				sDebugCollective="Not moving down, reducing collective, now " $ agpvVehicle.fpHelicopterCollective;
			}
		}
		Return False;
	*/
}

void ANPCBaseRavenController::DetermineNextPathNode()
{
	/*
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < apnFlyingPathNodesForPatrol.Length - 1)
			{
				iCurrentDrivingPathNodeIndex ++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (apnFlyingPathNodesForPatrol.Length > 0)
					{
						if (apnFlyingPathNodesForPatrol.Length == 1)
						{
							MoveTimer=-1;
							agpvVehicle.Throttle=0;
							agpvVehicle.Steering=0;
							agpvVehicle.fpHelicopterCollective=0;
							Pawn.bRotateToDesired=False;
							bAutoReversePath=False;
							GotoState('None');
							Return;
						}
						NPCLog("Reversing direction back to descending");
						bAscendingNodeDirection=False;
						DetermineNextPathNode();
						Return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=0;
				}
			}
			NPCLog("");
			NPCLog("");
			NPCLog("Ascending pathnodes - new index: " $ iCurrentPathNodeIndex $ " node: " $ apnFlyingPathNodesForPatrol[iCurrentPathNodeIndex].Tag);
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
					if (apnFlyingPathNodesForPatrol.Length > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection=True;
						DetermineNextPathNode();
						Return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=apnFlyingPathNodesForPatrol.Length - 1;
				}
			}
			NPCLog("Descending pathnodes - new index: " $ iCurrentPathNodeIndex);
		}
		FindNextDrivingPatrolPathNode();
	*/
}

void ANPCBaseRavenController::DebugDumpRoute()
{
	/*
		local int i;
		NPCLog("******************************");
		NPCLog("Vehicle Route goal: " $ RouteGoal $ ", distance: " $ RouteDist);
		for (i=0; i<62; i++)
		{
			if (RouteCache[i] != None)
			{
				NPCLog("Route[ " $ i $ "] => " $ RouteCache[i] $ ": " $ RouteCache[i].Tag);
			}
		}
		NPCLog("******************************");
	*/
}

void ANPCBaseRavenController::NPCPathLog(FString sLogText)
{
	//Log(Level.TimeSeconds $ " - " $ Self $ "." $ "." $ Tag $ "." $ sNPCWaypointTag $ sLogText);
}

void ANPCBaseRavenController::NPCLog(FString sLogText)
{
	/*
		if (agpvVehicle != None && agpvVehicle.Driver != None)
		{
			Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ agpvVehicle.Driver $ " " $ sLogText);
		}
		else
		{
			if (Pawn != None)
			{
				Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
			}
			else
			{
				Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ sLogText);
			}
		}
	*/
}

void ANPCBaseRavenController::EnableDebugTerrainRadarTrace()
{
	/*
		if (dnpcnDebugTerrainRadarMarker == None)
		{
			dnpcnDebugTerrainRadarMarker=Spawn('DebugNPCNavigation');
			dnpcnDebugTerrainRadarMarker.SetCollision(False,False,False);
			dnpcnDebugTerrainRadarMarker.bHidden=False;
		}
	*/
}

void ANPCBaseRavenController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	/*
		Log(Self $ ".NotifyTakeDamage() - New Health: " $ Pawn.Health);
		if (Pawn.Health <= 0)
		{
			GotoState('HelicopterShotDown');
		}
	*/
}

