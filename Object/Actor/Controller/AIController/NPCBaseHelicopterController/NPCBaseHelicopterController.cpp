// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"

ANPCBaseHelicopterController::ANPCBaseHelicopterController()
{
	sCallSign = "Bravo Hotel Zero One";
		fpMaxSpeed = 500;
		fpMaxBackwardSpeed = -200;
		DrawDriverInTP = true;
		//sndRadioPopIn = Sound'S_AA2_AircraftRadio.blackhawk.Radio_Pop_In'
		//sndRadioPopOut = Sound'S_AA2_AircraftRadio.blackhawk.Radio_Pop_Out'
		//sndOver = Sound'S_AA2_AircraftRadio.blackhawk.BHOver'
		//sndHelicopterBGNoise = Sound'S_AA2_AircraftRadio.blackhawk.Helicopter_Loop'
		//sndBy = Sound'S_AA2_AircraftRadio.blackhawk.BHBy'
		//sndByA = Sound'S_AA2_AircraftRadio.blackhawk.BHBy'
		//asndNumbers(0) = Sound'S_AA2_AircraftRadio.blackhawk.BHZero'
		//asndNumbers(1) = Sound'S_AA2_AircraftRadio.blackhawk.BHOne'
		//asndNumbers(2) = Sound'S_AA2_AircraftRadio.blackhawk.BHTwo'
		//asndNumbers(3) = Sound'S_AA2_AircraftRadio.blackhawk.BHThree'
		//asndNumbers(4) = Sound'S_AA2_AircraftRadio.blackhawk.BHFour'
		//asndNumbers(5) = Sound'S_AA2_AircraftRadio.blackhawk.BHFive'
		//asndNumbers(6) = Sound'S_AA2_AircraftRadio.blackhawk.BHSix'
		//asndNumbers(7) = Sound'S_AA2_AircraftRadio.blackhawk.BHSeven'
		//asndNumbers(8) = Sound'S_AA2_AircraftRadio.blackhawk.BHEight'
		//asndNumbers(9) = Sound'S_AA2_AircraftRadio.blackhawk.BHNine'
		//asndNumbersAgitated(0) = Sound'S_AA2_AircraftRadio.blackhawk.BHZeroA'
		//asndNumbersAgitated(1) = Sound'S_AA2_AircraftRadio.blackhawk.BHOneA'
		//asndNumbersAgitated(2) = Sound'S_AA2_AircraftRadio.blackhawk.BHTwoA'
		//asndNumbersAgitated(3) = Sound'S_AA2_AircraftRadio.blackhawk.BHThreeA'
		//asndNumbersAgitated(4) = Sound'S_AA2_AircraftRadio.blackhawk.BHFourA'
		//asndNumbersAgitated(5) = Sound'S_AA2_AircraftRadio.blackhawk.BHFiveA'
		//asndNumbersAgitated(6) = Sound'S_AA2_AircraftRadio.blackhawk.BHSixA'
		//asndNumbersAgitated(7) = Sound'S_AA2_AircraftRadio.blackhawk.BHSevenA'
		//asndNumbersAgitated(8) = Sound'S_AA2_AircraftRadio.blackhawk.BHEightA'
		//asndNumbersAgitated(9) = Sound'S_AA2_AircraftRadio.blackhawk.BHNineA'
		//sndBMPSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHBMPSpotted'
		//sndBTRSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHBTRSpotted'
		//sndInfantrySpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHInfantrySpotted'
		//sndTankSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHTankSpotted'
		//sndT62Spotted = Sound'S_AA2_AircraftRadio.blackhawk.BHT62Spotted'
		//sndMortarTeamSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHMortarTeamSpotted'
		//sndCarSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHCarSpotted'
		//sndHelicopterSpotted = Sound'S_AA2_AircraftRadio.blackhawk.BHHelicopterSpotted'
		//sndMayday = Sound'S_AA2_AircraftRadio.blackhawk.BHMayday'
		//sndRepairing = Sound'S_AA2_AircraftRadio.blackhawk.BHOnGroundRepairing'
		//sndRepairsComplete = Sound'S_AA2_AircraftRadio.blackhawk.BHRepairsComplete'
		//sndPZOnWayPartOne = Sound'S_AA2_AircraftRadio.blackhawk.BHPZAckYouHave'
		//sndPZOnWayPartTwo = Sound'S_AA2_AircraftRadio.blackhawk.BHPZAckPaxAtPZ'
		//sndPZOnWayPartThree = Sound'S_AA2_AircraftRadio.blackhawk.BHPZAckOnStationIn'
		//sndPZOnWayPartFour = Sound'S_AA2_AircraftRadio.blackhawk.BHPZAckSecondsOver'
		//sndCallGreenSmoke = Sound'S_AA2_AircraftRadio.blackhawk.BHCallGreenSmoke'
		//sndBadPZ = Sound'S_AA2_AircraftRadio.blackhawk.BHPZAckAbortingPickupOver'
		//sndPZNotSecureInfantryFire = Sound'S_AA2_AircraftRadio.blackhawk.BHPZNotSecureInfantryFire'
		//sndPZNotSecureVehicleFire = Sound'S_AA2_AircraftRadio.blackhawk.BHPZNotSecureVehicleFire'
		//sndPZNotSecureGeneric = Sound'S_AA2_AircraftRadio.blackhawk.BHPZNotSecureGeneric'
		//sndTakingInfantryFire = Sound'S_AA2_AircraftRadio.blackhawk.BHTakingInfantryFire'
		//sndTakingVehicleFire = Sound'S_AA2_AircraftRadio.blackhawk.BHTakingVehicleFire'
		//sndTakingGenericFire = Sound'S_AA2_AircraftRadio.blackhawk.BHTakingGenericFire'
		bSlowerZAcquire = false;
		bProp = true;

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
	Function AttachCrewChief()
	{
		agpCrewChief=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,Location,Rotation,true,true);
		agpCrewChief.HUDText="Crew Chief";
		agpCrewChief.SetCollision(false,false,false);
		agpCrewChief.PrePivot.Z=0;
		agpCrewChief.SetPhysics(PHYS_None);
		agpCrewChief.AnimSequence="BH_CrewIdle";
		agpvVehicle.AttachToBone(agpCrewChief,"CrewChief");
		agpCrewChief.SetCollision(false,true,true);
		AttachHelmet(agpCrewChief);
	}
	Function AttachCrewLoadMaster()
	{
		agpCrewLoadMaster=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,Location,Rotation,true,true);
		agpCrewLoadMaster.HUDText="Loadmaster";
		agpCrewLoadMaster.SetCollision(false,false,false);
		agpCrewLoadMaster.PrePivot.Z=0;
		agpCrewLoadMaster.SetPhysics(PHYS_None);
		agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
		agpvVehicle.AttachToBone(agpCrewLoadMaster,"Player");
		AttachHelmet(agpCrewLoadMaster);
	}
	Function AttachCoPilot()
	{
		agpCoPilot=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,Location,Rotation,true,true);
		agpCoPilot.HUDText="Co-Pilot";
		agpCoPilot.SetCollision(false,false,false);
		agpCoPilot.AnimSequence="BH_Pilot";
		agpCoPilot.bCollideWorld=false;
		agpCoPilot.PrePivot.Z=0;
		agpCoPilot.SetPhysics(PHYS_None);
		agpvVehicle.AttachToBone(agpCoPilot,"CoPilot");
		AttachHelmet(agpCoPilot);
	}
	Function AttachRearwardWounded()
	{
		anpchwpRearwardWounded=Spawn(class'AGP.NPCHelicopterWoundedPassenger',,,Location,Rotation,true,true);
		agpvVehicle.AttachToBone(anpchwpRearwardWounded,"Player");
		anpchwpRearwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	}
	Function AttachForwardWounded()
	{
		anpchwpForwardWounded=Spawn(class'AGP.NPCHelicopterWoundedPassenger',,,Location,Rotation,true,true);
		agpvVehicle.AttachToBone(anpchwpForwardWounded,"CrewChief");
		anpchwpForwardWounded.SetRelativeLocation(MakeVect(30,0,-10));
		anpchwpForwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	}
	Function AttachHelmet(Pawn pawnCrewMember)
	{
		local Actor actAttachment;
		actAttachment=Spawn(class<Actor>(DynamicLoadObject("AGP_Inventory.Attch_FlightCrewHelmetBH",Class'Class')));
		actAttachment.SetDrawScale(1.13);
		pawnCrewMember.AttachToBone(actAttachment,"BN_HeadEnd");
		actAttachment.SetRelativeRotation(MakeRot(0,32768,16384));
	}
Begin:
	agpvVehicle.PeripheralVision=-99;
	sVehicleType=agpvVehicle.VehicleNameString;
	agpvVehicle.bDrawDriverInTP=DrawDriverInTP;
	agpvVehicle.Throttle=0;
	agpvVehicle.Steering=0;
	agpvVehicle.fpHelicopterCollective=1;
	agpvVehicle.SetCollision(false,false,false);
	if (agpvVehicle.TryToDrive(Pawn))
	{
		if (agpvVehicle.Driver == None)
		{
			if (agpvVehicle.Driver == None)
			{
				Pawn.Destroy();
				agpvVehicle.Destroy();
				GotoState("Failure");
			}
		}
		agpvVehicle.Driver.SetAnimAction("BH_Pilot");
		agpvVehicle.Driver.bHidden=false;
		agpvVehicle.AttachDriver(agpvVehicle.Driver);
		AttachHelmet(agpvVehicle.Driver);
		if (bIncludeCrewchief)
		{
			AttachCrewChief();
			Sleep(0);
		}
		else
		{
			if (bIncludeForwardWounded)
			{
				AttachForwardWounded();
				Sleep(0);
			}
		}
		if (bIncludeRearwardWounded)
		{
			AttachRearwardWounded();
		}
		else
		{
			if (bIncludeLoadMaster)
			{
				AttachCrewLoadMaster();
			}
		}
		if (bIncludeCoPilot)
		{
			Sleep(0);
			AttachCoPilot();
		}
		agpvVehicle.SetCollision(true,true,true);
	}
	else
	{
		GotoState("Failure");
	}
	if (agpvVehicle.Driver == None)
	{
		Pawn.Destroy();
		agpvVehicle.Destroy();
		GotoState("Failure");
	}
	fpMechanicalFailureTimer=(FRand() * 10);
	SetCustomTimer(1,true,"WatchForMechanicalFailuresTimer");
	Enable("SeeMonster");
	if (iStartingPathNodeIndex > 0)
	{
		iCurrentDrivingPathNodeIndex=(iStartingPathNodeIndex - 1);
	}
	if (bDummyHelicopter)
	{
		GotoState("DummyHelicopter");
	}
	else
	{
		if (iNPCPrimaryOrders == 0)
		{
			Patrol();
		}
		else
		{
			GotoState("HoverMode");
		}
	}
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
	Function TransmitMayday()
	{
		TransmitRadioMessage("Mayday, Mayday, Mayday.  " $ sCallSign $ " is going down, location " $ LocationToGrid(Pawn.Location));
	}
Begin:
	agpvVehicle.HelicopterEngineSmoke(true);
	TransmitMayday();
	sDebugNavInfo="Starting to emergency land";
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.DesiredSpeed=0;
	agpCrewLoadMaster.AnimSequence="CivSitCalmB";
	agpCrewChief.AnimSequence="CivSitCalmB";
	Sleep(0.75);
	agpvVehicle.HelicopterEngineSmoke(true);
	sDebugNavInfo="Descending - Height " $ string(GetRealAltitude());
	if (! DescendToAltitude(30))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	sDebugAltitude2="Finished descending, altitude: " $ string(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " $ string(GetRealAltitude());
	Sleep(0.04);
	GotoState("Repairing");
}
*/

/*
State Repairing
{
Begin:
	TransmitRadioMessage(sCallSign $ " is on the ground, attempting repairs.");
	agpvVehicle.HelicopterForceRotorMaxToIdleSpeed();
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.fpHelicopterCollective=0;
	agpCrewLoadMaster.DesiredRotation=(agpvVehicle.Rotation + MakeRot(0,16384,0));
	agpCrewLoadMaster.AnimSequence="DocCrhFiddle";
	Sleep(0.5);
	agpCrewChief.DesiredRotation=(agpvVehicle.Rotation + MakeRot(0,-16384,0));
	agpCrewChief.AnimSequence="DocCrhFiddle";
	fpRepairTime=((Level.TimeSeconds + (FRand() * float(120))) + 60);
	if (Level.TimeSeconds < fpRepairTime)
	{
		agpvVehicle.HelicopterEngineSmoke(true);
		Sleep(15);
	}
	agpvVehicle.HelicopterEngineSmoke(false);
	TransmitRadioMessage(sCallSign $ " repairs complete, resuming patrol");
	agpCrewChief.DesiredRotation=(agpvVehicle.Rotation + MakeRot(0,16384,0));
	agpCrewChief.AnimSequence="BH_CrewIdle";
	Sleep(0.25);
	agpCrewLoadMaster.DesiredRotation=(agpvVehicle.Rotation + MakeRot(0,-16384,0));
	agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	bResumePathAfterFailure=true;
	agpvVehicle.HelicopterRestoreRotorMaxSpeed();
	GotoState("TakeOffMode");
}
*/

/*
State HoverMode
{
Begin:
	vHoverStartLocation=agpvVehicle.Location;
	DesiredRotation.Pitch=0;
	DesiredRotation.Roll=0;
	agpvVehicle.DesiredSpeed=0;
	if (fpMinAltitude < float(1000))
	{
		fpMinAltitude=1000;
	}
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
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
	agpvVehicle.DesiredSpeed=0;
	agpvVehicle.MaxDesiredSpeed=0;
	if (bDebugPitchDirectionUp)
	{
		if (agpvVehicle.fpHelicopterCyclicPitch < 1)
		{
			(agpvVehicle.fpHelicopterCyclicPitch += 0.05);
		}
		else
		{
			bDebugPitchDirectionUp=false;
		}
	}
	else
	{
		if (agpvVehicle.fpHelicopterCyclicPitch > -1)
		{
			(agpvVehicle.fpHelicopterCyclicPitch -= 0.05);
		}
		else
		{
			bDebugPitchDirectionUp=true;
		}
	}
	sDebugNavInfo="TestPitch cyclic pitch: " $ string(agpvVehicle.fpHelicopterCyclicPitch) $ "Desired speed: " $ string(agpvVehicle.DesiredSpeed);
	AdjustForAltitudeHold();
	Sleep(0.04);
	JL"AdjustControls"
;
}
*/

/*
State HeadForWaypoint
{
	Function bool TurnedEnough(float fpAngle)
	{
		FVector vDesiredRotation = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDesiredRotation=Normal( Vector(DesiredRotation));
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
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
		if (VSize(agpvVehicle.Velocity) > 1)
		{
			if ((agpvVehicle.Rotation.Pitch > 32768) || (agpvVehicle.Rotation.Pitch < 0))
			{
				agpvVehicle.fpHelicopterCyclicPitch=(VSize(agpvVehicle.Velocity) * -0.01);
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=(VSize(agpvVehicle.Velocity) * 0.01);
			}
			sDebugNavInfo="Trying to stop, pitch " $ string(agpvVehicle.Rotation.Pitch) $ " Collective: " $ string(agpvVehicle.fpHelicopterCyclicPitch);
			return false;
		}
		else
		{
			agpvVehicle.fpHelicopterCyclicPitch=0;
		}
		return true;
	}
	Function bool GonePast()
	{
		FVector vDirectionToGoal = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDirectionToGoal=Normal((agpvVehicle.Location - vAdjustedPathNodeLocation));
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
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
		vAdjustedVehicleLocation=agpvVehicle.Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		return VSize((vAdjustedVehicleLocation - vAdjustedPathNodeLocation));
	}
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
		if (Abs((Level.TimeSeconds - fpLastGroundFireAdjust)) < float(10))
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
		fpLastGroundFireAdjust=Level.TimeSeconds;
	}
	Function AdjustThrottleToDesiredSpeed()
	{
		float fpSpeedRatio = 0;
		if (agpvVehicle.DesiredSpeed == 0)
		{
			StopMovement();
		}
		if (agpvVehicle.DesiredSpeed > 0)
		{
			fpSpeedRatio=((agpvVehicle.DesiredSpeed / fpMaxSpeed) * -1);
			sDebugCyclicPitch="Moving forward adjusting by " $ string(fpSpeedRatio);
		}
		else
		{
			fpSpeedRatio=(agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed);
			sDebugCyclicPitch="Moving backward adjusting by " $ string(fpSpeedRatio);
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	}
Begin:
	sDebugNavInfo="Getting next waypoint";
	fpGroundFireAvoidanceAltitudeBump=0;
	DetermineNextPathNode();
	FindNextDrivingPatrolPathNode();
	if (pnCurrentFlyingPathNode == None)
	{
		NPCLog("No path node to move to!");
		GotoState("None");
		JL"End"
;
	}
	vAdjustedPathNodeLocation=pnCurrentFlyingPathNode.Location;
	vAdjustedPathNodeLocation.Z=agpvVehicle.Location.Z;
	if (((vAdjustedPathNodeLocation.Z / 2) < float(1000)) || (vAdjustedPathNodeLocation.Z < float(500)))
	{
		fpMinAltitude=1000;
	}
	else
	{
		fpMinAltitude=(vAdjustedPathNodeLocation.Z / 2);
	}
	fpGroundFireAvoidanceAltitudeBump=0;
	fpTerrainAvoidanceAltitudeBump=0;
	DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle.Location));
	sDebugNavMode="FinishTurnWhileHovering";
	HoldSpecificAltitude(((fpMinAltitude + fpTerrainAvoidanceAltitudeBump) + fpGroundFireAvoidanceAltitudeBump));
	if ((GetRealAltitude() + fpTerrainAvoidanceAltitudeBump) < fpMinAltitude)
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
	if (TurnedEnough(-0.3))
	{
		sDebugNavInfo="Finished turning to waypoint";
		if (iDesiredTravelSpeed == 0)
		{
			iDesiredTravelSpeed=850;
		}
		agpvVehicle.DesiredSpeed=float(iDesiredTravelSpeed);
		JL"StartMovingToWaypoint"
;
	}
	Sleep(0.04);
	JL"FinishTurnWhileHovering"
;
	sDebugNavMode="StartMovingToWaypoint";
	if ((! TurnedEnough(0.02)) && (GetDistanceToWaypoint2D() > float(100)))
	{
		DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle.Location));
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
		sDebugNavInfo="Slowing close to waypoint Distance: " $ string(GetDistanceToWaypoint2D());
		if (GetDistanceToWaypoint2D() < float(400))
		{
			if (bFollowPatrol)
			{
				JL"PrepNextWaypoint"
;
			}
			if ((VSize(agpvVehicle.Velocity) > float(50)) && (GetDistanceToWaypoint2D() > float(200)))
			{
				agpvVehicle.DesiredSpeed=10;
			}
			else
			{
				if ((VSize(agpvVehicle.Velocity) < float(10)) || GonePast())
				{
					agpvVehicle.DesiredSpeed=0;
					JL"PrepNextWaypoint"
;
				}
			}
		}
		else
		{
			if (GetDistanceToWaypoint2D() < float(750))
			{
				if (VSize(agpvVehicle.Velocity) > float(100))
				{
					agpvVehicle.DesiredSpeed=75;
				}
			}
			else
			{
				if (GetDistanceToWaypoint2D() < float(100))
				{
					if (VSize(agpvVehicle.Velocity) > float(125))
					{
						agpvVehicle.DesiredSpeed=125;
					}
				}
				else
				{
					if (GetDistanceToWaypoint2D() < float(2000))
					{
						if (bFollowPatrol)
						{
							Sleep(0.04);
							JL"StartMovingToWaypoint"
;
						}
						if (VSize(agpvVehicle.Velocity) > float(150))
						{
							agpvVehicle.DesiredSpeed=150;
						}
					}
					else
					{
						if (GetDistanceToWaypoint2D() < float(3500))
						{
							if (VSize(agpvVehicle.Velocity) > float(200))
							{
								agpvVehicle.DesiredSpeed=200;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		sDebugNavInfo="Heading to waypoint Distance: " $ string(GetDistanceToWaypoint2D());
	}
	sDebugNavMode="Traveling onward";
	Sleep(0.04);
	JL"StartMovingToWaypoint"
;
	sDebugNavMode="Prepping for next waypoint";
	if (bFollowPatrol)
	{
		JL"NextWaypoint"
;
	}
	else
	{
		GotoState("HoverMode");
	}
}
*/

/*
State HeadForLandingZone
{
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		(iDamageSinceLandingStarted += Damage);
		if (Pawn.Health <= 0)
		{
			TransmitRadioMessage("Mayday, Mayday, Mayday.  " $ sCallSign $ " is going down, location " $ LocationToGrid(Pawn.Location));
			GotoState("HelicopterShotDown");
		}
		else
		{
			if ((iDamageSinceLandingStarted > 300) || (float(Pawn.Health) < 100))
			{
				if ((instigatedBy != None) && instigatedBy.IsA("Vehicle"))
				{
					TransmitAudioRadioMessage(sndRadioPopIn);
					TransmitAudioRadioMessage(sndPZNotSecureVehicleFire);
					TransmitAudioLocationRadioMessage(instigatedBy.Location,true);
					TransmitAudioRadioMessage(sndOver);
					TransmitAudioRadioMessage(sndRadioPopOut);
					TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire from " $ Vehicle(instigatedBy).VehicleNameString $ ", enemy location at " $ LocationToGrid(instigatedBy.Location) $ ", aborting pickup.");
				}
				else
				{
					if (instigatedBy != None)
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndPZNotSecureInfantryFire);
						TransmitAudioLocationRadioMessage(instigatedBy.Location,true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire, enemy location " $ LocationToGrid(instigatedBy.Location) $ ", aborting pickup.");
					}
					else
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndPZNotSecureGeneric);
						TransmitAudioLocationRadioMessage(instigatedBy.Location,true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire, current location " $ LocationToGrid(Pawn.Location) $ ", aborting pickup.");
					}
				}
				fpTimeSinceLastTakingFireMessage=Level.TimeSeconds;
				Patrol();
			}
			else
			{
				if ((Level.TimeSeconds - fpTimeSinceLastTakingFireMessage) > 30)
				{
					if ((instigatedBy != None) && instigatedBy.IsA("Vehicle"))
					{
						TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire from " $ Vehicle(instigatedBy).VehicleNameString $ ", enemy location at " $ LocationToGrid(instigatedBy.Location) $ ".");
					}
					else
					{
						if (instigatedBy != None)
						{
							TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire, enemy location " $ LocationToGrid(instigatedBy.Location) $ ".");
						}
						else
						{
							TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire, current location " $ LocationToGrid(Pawn.Location) $ ".");
						}
					}
					fpTimeSinceLastTakingFireMessage=Level.TimeSeconds;
				}
			}
		}
	}
	Function bool TurnedEnough(float fpAngle)
	{
		FRotator rotDesiredRotation = FRotator(0,0,0);
		FRotator rotCurrentRotation = FRotator(0,0,0);
		FVector vDesiredRotation = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		rotDesiredRotation=DesiredRotation;
		rotDesiredRotation.Pitch=0;
		vDesiredRotation=Normal( Vector(rotDesiredRotation));
		rotCurrentRotation=agpvVehicle.Rotation;
		rotCurrentRotation.Pitch=0;
		vCurrentRotation=Normal( Vector(rotCurrentRotation));
		sDebugNavInfo="Turning to LZ direction " $ string((vDesiredRotation Dot vCurrentRotation));
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
		if (VSize(agpvVehicle.Velocity) > 1)
		{
			if ((agpvVehicle.Rotation.Pitch > 32768) || (agpvVehicle.Rotation.Pitch < 0))
			{
				agpvVehicle.fpHelicopterCyclicPitch=(VSize(agpvVehicle.Velocity) * -0.01);
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=(VSize(agpvVehicle.Velocity) * 0.01);
			}
			sDebugNavInfo="Trying to stop, pitch " $ string(agpvVehicle.Rotation.Pitch) $ " Collective: " $ string(agpvVehicle.fpHelicopterCyclicPitch);
			return false;
		}
		else
		{
			agpvVehicle.fpHelicopterCyclicPitch=0;
		}
		return true;
	}
	Function bool GonePast()
	{
		FVector vDirectionToGoal = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDirectionToGoal=Normal((agpvVehicle.Location - vAdjustedPathNodeLocation));
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
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
		vAdjustedVehicleLocation=agpvVehicle.Location;
		vAdjustedVehicleLocation.Z=vAdjustedPathNodeLocation.Z;
		return VSize((vAdjustedVehicleLocation - vAdjustedPathNodeLocation));
	}
	Function AdjustThrottleToDesiredSpeed()
	{
		float fpSpeedRatio = 0;
		if (agpvVehicle.DesiredSpeed == 0)
		{
			StopMovement();
		}
		if (agpvVehicle.DesiredSpeed > 0)
		{
			fpSpeedRatio=((agpvVehicle.DesiredSpeed / fpMaxSpeed) * -1);
			sDebugCyclicPitch="Moving forward adjusting by " $ string(fpSpeedRatio);
		}
		else
		{
			fpSpeedRatio=(agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed);
			sDebugCyclicPitch="Moving backward adjusting by " $ string(fpSpeedRatio);
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		if (Wall.IsA("TerrainInfo"))
		{
			GotoState("LandedMode");
		}
		return false;
	}
	Function PZRequestPickupCall()
	{
		local PlayerController pctrlIterator;
		FString sPlayerName = "";
		iPlayersToPickupCount=0;
		ForEach DynamicActors(Class'PlayerController',pctrlIterator)
		{
			if (((pctrlIterator.PlayerReplicationInfo != None) && (pctrlIterator.PlayerReplicationInfo.Team != None)) && (pctrlIterator.PlayerReplicationInfo.Team.TeamIndex == humctlrPlayerCallingForPickup.PlayerReplicationInfo.Team.TeamIndex))
			{
				iPlayersToPickupCount ++;
			}
		}
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign $ "', this is " $ sPlayerName $ ".  Request pickup for " $ string(iPlayersToPickupCount) $ " pax at PZ " $ LocationToGrid(vLocationLandingZone) $ ".  PZ is secure.  Over");
		if (bBadPickupZone)
		{
			SetCustomTimer((2 + float(Rand(3))),false,"PZBadPZRadioCall");
		}
		else
		{
			SetCustomTimer((2 + float(Rand(3))),false,"PZOnWayRadioCall");
		}
	}
	Function PZOnWayRadioCall()
	{
		int32 iTimeEstimate = 0;
		FString sPlayerName = "";
		iTimeEstimate=(int((VSize((Pawn.Location - vLocationLandingZone)) / float(850))) + Rand(15));
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndPZOnWayPartOne);
		TransmitAudioRadioNumber(iPlayersToPickupCount,false);
		TransmitAudioRadioMessage(sndPZOnWayPartTwo);
		TransmitAudioLocationRadioMessage(vLocationLandingZone);
		TransmitAudioRadioMessage(sndPZOnWayPartThree);
		TransmitAudioRadioNumber(iTimeEstimate,false);
		TransmitAudioRadioMessage(sndPZOnWayPartFour);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', you have " $ string(iPlayersToPickupCount) $ " pax at PZ " $ LocationToGrid(vLocationLandingZone) $ ".  On station in " $ string(iTimeEstimate) $ " seconds.  Over.");
		SetCustomTimer(float(iTimeEstimate),false,"PZInSight");
	}
	Function PZBadPZRadioCall()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndBadPZ);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', negative on PZ location, cannot locate valid PZ.  Smoke again at valid PZ location");
		GotoState(GetLastStateName());
	}
	Function PZInSight()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndCallGreenSmoke);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', call green smoke.  Over.");
		SetCustomTimer((2 + float(Rand(2))),false,"PZRespondToSmokeCall");
	}
	Function PZRespondToSmokeCall()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign $ "', this is " $ sPlayerName $ ", roger, that's us.  Standing by. Over");
		npcaiccEnemyCombatController.NotifyHelicopterLanding(vLocationLandingZone);
	}
Begin:
	PZRequestPickupCall();
	iDamageSinceLandingStarted=0;
	sDebugNavInfo="";
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	vAdjustedPathNodeLocation=vLocationLandingZone;
	if ((vAdjustedPathNodeLocation.Z + float(500)) < agpvVehicle.Location.Z)
	{
		vAdjustedPathNodeLocation.Z=agpvVehicle.Location.Z;
	}
	else
	{
		(vAdjustedPathNodeLocation.Z += float(500));
	}
	DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle.Location));
	AdjustForAltitudeHold();
	if (TurnedEnough(0.03))
	{
		if (iDesiredTravelSpeed == 0)
		{
			iDesiredTravelSpeed=850;
		}
		agpvVehicle.DesiredSpeed=float(iDesiredTravelSpeed);
		JL"StartMovingToLZ"
;
	}
	Sleep(0.04);
	JL"FinishTurnWhileHovering"
;
	if ((! TurnedEnough(0.02)) && (GetDistanceToWaypoint2D() > float(100)))
	{
		DesiredRotation=rotator((vAdjustedPathNodeLocation - agpvVehicle.Location));
	}
	AdjustThrottleToDesiredSpeed();
	if (GetDistanceToWaypoint2D() < float(3500))
	{
		sDebugNavInfo="Slowing close to waypoint Distance: " $ string(GetDistanceToWaypoint2D());
		if (GetDistanceToWaypoint2D() < float(400))
		{
			if ((VSize(agpvVehicle.Velocity) > float(50)) && (GetDistanceToWaypoint2D() > float(200)))
			{
				agpvVehicle.DesiredSpeed=10;
			}
			else
			{
				if ((VSize(agpvVehicle.Velocity) < float(10)) || GonePast())
				{
					agpvVehicle.DesiredSpeed=0;
					JL"PrepLanding"
;
				}
			}
		}
		else
		{
			if (GetDistanceToWaypoint2D() < float(750))
			{
				if (VSize(agpvVehicle.Velocity) > float(100))
				{
					agpvVehicle.DesiredSpeed=75;
				}
			}
			else
			{
				if (GetDistanceToWaypoint2D() < float(100))
				{
					if (VSize(agpvVehicle.Velocity) > float(125))
					{
						agpvVehicle.DesiredSpeed=125;
					}
				}
				else
				{
					if (GetDistanceToWaypoint2D() < float(2000))
					{
						if (VSize(agpvVehicle.Velocity) > float(150))
						{
							agpvVehicle.DesiredSpeed=150;
						}
					}
					else
					{
						if (GetDistanceToWaypoint2D() < float(3500))
						{
							if (VSize(agpvVehicle.Velocity) > float(200))
							{
								agpvVehicle.DesiredSpeed=200;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		sDebugNavInfo="Heading to waypoint Distance: " $ string(GetDistanceToWaypoint2D());
	}
	AdjustForAltitudeHold();
	Sleep(0.04);
	JL"StartMovingToLZ"
;
	sDebugNavInfo="Starting to land";
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.DesiredSpeed=0;
	agpCrewLoadMaster.AnimSequence="BH_Crew_GoIntro";
	Sleep(0.75);
	agpCrewLoadMaster.AnimSequence="BH_Crew_GoLoop";
	sDebugNavInfo="Descending - Height " $ string(GetRealAltitude());
	if (! DescendToAltitude(60))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	sDebugAltitude2="Finished descending, altitude: " $ string(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " $ string(GetRealAltitude());
	Sleep(0.04);
	JL"HoldLandHover"
;
}
*/

/*
State LandedMode
{
	Function Hover()
	{
		HoldSpecificAltitude(1000,true);
	}
	Function bool UsedBy(Pawn User)
	{
		HumanController(User.Controller).ClientMessage("Trying to attach to Player bone");
		User.ShouldCrouch(true);
		User.SetCollision(false,false,false);
		User.PrePivot.Z=0;
		User.SetPhysics(PHYS_None);
		User.LoopAnim("BH_CrewIdle");
		agpvVehicle.AttachToBone(User,"Player");
		return true;
	}
Begin:
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.SetCollision(true,true,true);
	agpvVehicle.bBlockZeroExtentTraces=true;
}
*/

/*
State ManualControl
{
Begin:
	agpvVehicle.Throttle=0;
	agpvVehicle.Steering=0;
	DesiredRotation=agpvVehicle.Rotation;
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
		if (Abs((fpCurrentAltitude - fpTargetHeight)) < float(20))
		{
			if (agpvVehicle.Velocity.Z > 2)
			{
				agpvVehicle.fpHelicopterCollective=0;
				return false;
			}
			else
			{
				return true;
			}
		}
		if (fpCurrentAltitude >= (fpTargetHeight - float(250)))
		{
			if (agpvVehicle.Velocity.Z > 5)
			{
				if (agpvVehicle.Velocity.Z > float(25))
				{
					agpvVehicle.fpHelicopterCollective=(-0.001 * (agpvVehicle.Velocity.Z - float(25)));
				}
				else
				{
					agpvVehicle.fpHelicopterCollective=-0.01;
				}
				sDebugCollective="Altitude above or at target height, still moving up";
				return false;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0.001;
				sDebugCollective="Altitude above or at target height, not moving (done) ";
				return true;
			}
		}
		if (agpvVehicle.Velocity.Z > float(50))
		{
			if ((Abs((fpTargetHeight - fpCurrentAltitude)) < float(200)) && (agpvVehicle.Velocity.Z > float(10)))
			{
				(agpvVehicle.fpHelicopterCollective -= 0.001);
				sDebugCollective="Moving up and close, speed " $ string(agpvVehicle.Velocity.Z) $ ", slowing rate, collective at " $ string(agpvVehicle.fpHelicopterCollective);
			}
			else
			{
				if (agpvVehicle.Velocity.Z < fpMaxAscentSpeed)
				{
					(agpvVehicle.fpHelicopterCollective += 0.005);
				}
				sDebugCollective="Moving up but not close, speed " $ string(agpvVehicle.Velocity.Z) $ ", slowing rate, collective at " $ string(agpvVehicle.fpHelicopterCollective);
			}
		}
		else
		{
			agpvVehicle.fpHelicopterCollective=0.05;
			sDebugCollective="Not moving up, increasing collective, now " $ string(agpvVehicle.fpHelicopterCollective);
		}
		return false;
	}
Begin:
	if (! AscendToAltitude(1000))
	{
		Sleep(0.04);
		JL"Climb"
;
	}
	if (bResumePathAfterFailure)
	{
		bResumePathAfterFailure=false;
		bFollowPatrol=true;
		GotoState("HeadForWaypoint","FinishTurnWhileHovering");
	}
	GotoState("HoverMode");
}
*/

/*
State HelicopterShotDown
{
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		GotoState("Dead");
		return false;
	}
	Event Landed(Vector HitNormal)
	{
		GotoState("Dead");
	}
	Event Touch(Actor Other)
	{
		GotoState("Dead");
	}
Begin:
	agpvVehicle.HelicopterEngineSmoke(true);
	if ((Normal( Vector(Pawn.Rotation)) Dot Normal( Vector(DesiredRotation))) > 0.25)
	{
		(DesiredRotation.Yaw += 16384);
		if (DesiredRotation.Yaw > 65535)
		{
			(DesiredRotation.Yaw -= 65535);
		}
	}
	sDebugCrashStatus="altitude: " $ string(GetRealAltitude());
	if (GetRealAltitude() <= float(90))
	{
		Sleep(0.2);
		agpvVehicle.SpawnDestructionEffects();
		GotoState("Dead");
	}
	if (Velocity.Z > float(-200))
	{
		if (agpvVehicle.fpHelicopterCollective > -0.5)
		{
			agpvVehicle.fpHelicopterCollective=-0.05;
		}
	}
	Sleep(0.04);
	JL"KeepFalling"
;
}
*/

/*
State Dead
{
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Function SwapInDestroyedMesh()
	{
		FVector vLoc = FVector(0,0,0);
		FRotator Rot = FRotator(0,0,0);
		Rot=agpvVehicle.Rotation;
		vLoc=agpvVehicle.Location;
		agpvVehicle.SetDrawType(DT_StaticMesh);
		agpvVehicle.SetPhysics(PHYS_None);
		agpvVehicle.SetStaticMesh(StaticMesh(DynamicLoadObject("M_AA2_Vehicles.blackhawk.veh_blackhawk_fullcrashed",Class'StaticMesh')));
		agpvVehicle.SetCollision(false,false,false);
		agpvVehicle.bWorldGeometry=true;
		agpvVehicle.bCollideWorld=false;
		agpvVehicle.SetRotation((Rot + MakeRot(0,0,4096)));
		agpvVehicle.SetLocation((vLoc + MakeVect(0,0,float((- 50)))));
	}
Begin:
	agpvVehicle.HelicopterEngineSmoke(false);
	agpvVehicle.KDriverLeave(false);
	CleanupCrew();
	Pawn.Destroy();
	agpvVehicle.GotoState("VehicleDestroyed");
}
*/

/*
State DummyHelicopter
{
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Function TakeOff()
	{
	}
	Function Hover()
	{
	}
	Function NextWaypoint()
	{
	}
	Function Land(Vector vLoc, Controller ctrlOwner)
	{
	}
	Function Patrol()
	{
	}
	Function float GetRealAltitude()
	{
		local Actor actTraceHit;
		FVector vHitLocation = FVector(0,0,0);
		FVector vHitNormal = FVector(0,0,0);
		FVector vEndTrace = FVector(0,0,0);
		FVector vStartTrace = FVector(0,0,0);
		vStartTrace=Pawn.GetBoneCoords("Pilot").Origin;
		sDebugAltitude="Pawn Location: " $ string(Pawn.Location) $ " Pilot origin: " $ string(vStartTrace) $ "  Distance " $ string(VSize((Pawn.Location - vStartTrace)));
		vEndTrace=vStartTrace;
		(vEndTrace.Z -= float(10000));
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,true);
		sDebugAltitude2="Trace hit " $ string(actTraceHit);
		if (actTraceHit == None)
		{
			return -1;
		}
		return (vStartTrace.Z - vHitLocation.Z);
	}
	Function bool TurnedEnough(float fpAngle)
	{
		FVector vDesiredRotation = FVector(0,0,0);
		FVector vCurrentRotation = FVector(0,0,0);
		vDesiredRotation=Normal( Vector(DesiredRotation));
		vCurrentRotation=Normal( Vector(agpvVehicle.Rotation));
		if ((vDesiredRotation Dot vCurrentRotation) > (0.96 + fpAngle))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
Begin:
	bGodMode=true;
	DesiredRotation=rotDummyRotation;
	if (! TurnedEnough(0.03))
	{
		AdjustForAltitudeHold();
		Sleep(0.04);
		JL"FinishTurnWhileHovering"
;
	}
	agpvVehicle.Driver.SetAnimAction("BH_Pilot");
	agpvVehicle.Driver.bForceAnimUpdate=true;
	agpvVehicle.SetCollision(true,true,true);
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.DesiredSpeed=0;
	sDebugNavInfo="Descending - Height " $ string(GetRealAltitude());
	if (! DescendToAltitude(60))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	if (agpCrewLoadMaster != None)
	{
		agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	}
	sDebugAltitude2="Finished descending, altitude: " $ string(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " $ string(GetRealAltitude());
	Sleep(0.04);
	JL"HoldLandHover"
;
}
*/

/*

void ANPCBaseHelicopterController::DisplayDebug(UCanvas Canvas, float& YL, float& YPos)
{
		YL=10;
		if (Pawn.IsA('Vehicle'))
		{
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

void ANPCBaseHelicopterController::Land(FVector vLoc, AController* ctrlOwner)
{
	/*
		local BlackHawkPickupZoneVolume bhpzvIterator;
		local BlackHawkPickupZoneVolume bhpzvClosest;
		local FVector vVolCenter2D;
		local FVector vClosestVolCenter2D;
		local FVector vSmokeLoc2D;
		local float fpRangeToPZFromSmoke;
		local float fpClosestRangeToPZFromSmoke;
		vSmokeLoc2D=vLoc;
		vSmokeLoc2D.Z=0;
		ForEach AllActors('BlackHawkPickupZoneVolume',bhpzvIterator)
		{
			vVolCenter2D=bhpzvIterator.Location;
			vVolCenter2D.Z=0;
			vVolCenter2D.X += bhpzvIterator.CollisionRadius / 2;
			vVolCenter2D.Y += bhpzvIterator.CollisionRadius / 2;
			fpRangeToPZFromSmoke=VSize(vVolCenter2D - vSmokeLoc2D);
			if (fpRangeToPZFromSmoke > fpMaxDistanceSmokeFromPZ)
			{
			}
			else
			{
				if (fpRangeToPZFromSmoke < fpClosestRangeToPZFromSmoke || bhpzvClosest == None)
				{
					bhpzvClosest=bhpzvIterator;
					vClosestVolCenter2D=vVolCenter2D;
					fpClosestRangeToPZFromSmoke=fpRangeToPZFromSmoke;
				}
			}
		}
		bBadPickupZone=False;
		if (bhpzvClosest != None)
		{
			vLoc=vClosestVolCenter2D;
			vLoc.Z=bhpzvClosest.Location.Z;
		}
		else
		{
			if (bRequirePZVolume)
			{
				bBadPickupZone=True;
			}
		}
		vLocationLandingZone=vLoc;
		humctlrPlayerCallingForPickup=HumanController(ctrlOwner);
		GotoState('HeadForLandingZone');
	*/
}
void ANPCBaseHelicopterController::NextWaypoint()
{
	/*
		bFollowPatrol=False;
		GotoState('HeadForWaypoint');
	*/
}
void ANPCBaseHelicopterController::TakeOff()
{
	/*
		GotoState('TakeOffMode');
	*/
}
void ANPCBaseHelicopterController::Hover()
{
	/*
		GotoState('HoverMode');
	*/
}
void ANPCBaseHelicopterController::Start()
{
	/*
		GotoState('InitializeVehicle');
	*/
}
void ANPCBaseHelicopterController::Patrol()
{
	/*
		bFollowPatrol=True;
		GotoState('HeadForWaypoint');
	*/
}
void ANPCBaseHelicopterController::SignalPoppingSmoke()
{
}
void ANPCBaseHelicopterController::InitVehicle()
{
	/*
		bStart=True;
		if (VehicleTag != 'None')
		{
			agpvVehicle=Spawn(VehicleClass,,VehicleTag,Location,rotDummyRotation);
		}
		else
		{
			agpvVehicle=Spawn(VehicleClass,,,Location,rotDummyRotation);
		}
		agpvVehicle.PeripheralVision=-99;
		sVehicleType=agpvVehicle.VehicleNameString;
	*/
}
void ANPCBaseHelicopterController::GetPathnodeByTagString(FString sTag)
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
void ANPCBaseHelicopterController::PreloadPathNodeList()
{
	/*
		local int iNode;
		local PathNode pnFound;
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
			else
			{
				pnFound.bHidden=True;
			}
		}
	*/
}
void ANPCBaseHelicopterController::FindNextDrivingPatrolPathNode()
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
/*
void ANPCBaseHelicopterController::Possess(APawn* aPawn)
{
		NPCLog(Self $ " Possess() entered for " $ aPawn);
		if (aPawn != None)
		{
			if (aPawn.IsA('AGP_Pawn'))
			{
				NPCLog("Possess() entered for Vehicle's driver");
				Possess(aPawn);
				NPCLog("Possess of driver pawn " $ aPawn $ " with mesh: " $ aPawn.Mesh);
				agpPawnNPC=AGP_Pawn(aPawn);
				aPawn.Controller=Self;
				bGodMode=True;
				agpPawnNPC.SetCollision(False,False,False);
				agpPawnNPC.bCollideWorld=False;
				priFromNPCPawn=agpPawnNPC.PlayerReplicationInfo;
				NPCLog("PRI for pawn " $ agpPawnNPC $ " is " $ agpPawnNPC.PlayerReplicationInfo);
			}
			else
			{
				if (aPawn.IsA('Vehicle'))
				{
					Possess(aPawn);
					aPawn.PossessedBy(Self);
					aPawn.Controller=Self;
					aPawn.PlayerReplicationInfo=priFromNPCPawn;
					Pawn=aPawn;
				}
			}
		}
}
*/
void ANPCBaseHelicopterController::AttachPlayer(APawn* pawnPlayer)
{
}
/*
void ANPCBaseHelicopterController::UnPossess()
{
		if (Pawn.IsA('AGP_Pawn'))
		{
			NPCLog("Current pawn is AGP_Pawn (driver leaving vehicle), so we're doing nothing there");
		}
}
*/

void ANPCBaseHelicopterController::WatchForMechanicalFailuresTimer()
{
	/*
		if (fpEngineFailureChance > 0 && FRand() > 1 - fpEngineFailureChance)
		{
			if (fpMechanicalFailureTimer == 0)
			{
				fpMechanicalFailureTimer=Level.TimeSeconds + 30 + FRand() * 120;
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
void ANPCBaseHelicopterController::TransmitAudioRadioMessage(USoundBase* sndAudioMessage)
{
	/*
		asndQueue.insert (asndQueue.Length,1);
		asndQueue[asndQueue.Length - 1]=sndAudioMessage;
		if (asndQueue.Length > 1)
		{
			Return;
		}
		PlayAudioRadioMessage(asndQueue[0]);
	*/
}
void ANPCBaseHelicopterController::PlayAudioRadioMessage(USoundBase* sndAudioMessage)
{
	/*
		local PlayerController pcIterator;
		ForEach DynamicActors(Class'PlayerController',pcIterator)
		{
			if (pcIterator.Pawn != None && pcIterator.Pawn.IsA('AGP_Pawn') || Vehicle(pcIterator.Pawn) != None && Vehicle(pcIterator.Pawn).Driver != None && Vehicle(pcIterator.Pawn).Driver.IsA('AGP_Pawn'))
			{
				if (sndAudioMessage == sndRadioPopIn)
				{
					pcIterator.Pawn.AmbientSound=sndHelicopterBGNoise;
				}
				else
				{
					if (sndAudioMessage == sndRadioPopOut)
					{
						pcIterator.Pawn.AmbientSound=None;
					}
				}
				pcIterator.ClientPlaySound(sndAudioMessage);
			}
		}
		SetCustomTimer(GetSoundDuration(sndAudioMessage),False,'PlayNextQueuedSoundTimer');
	*/
}
void ANPCBaseHelicopterController::PlayNextQueuedSoundTimer()
{
	/*
		if (asndQueue.Length > 0)
		{
			asndQueue.remove (0,1);
		}
		if (asndQueue.Length > 0)
		{
			PlayAudioRadioMessage(asndQueue[0]);
		}
	*/
}
void ANPCBaseHelicopterController::TransmitRadioMessage(FString sMsg)
{
	/*
		local PlayerController pcIterator;
		if (Level.NetMode == 1)
		{
			ForEach DynamicActors(Class'PlayerController',pcIterator)
			{
				if (pcIterator.Pawn != None && pcIterator.Pawn.IsA('AGP_Pawn') || Vehicle(pcIterator.Pawn) != None && Vehicle(pcIterator.Pawn).Driver != None && Vehicle(pcIterator.Pawn).Driver.IsA('AGP_Pawn'))
				{
					CommoHandler(Level.Game.BroadcastHandler).BroadcastLocalized(None,pcIterator,'CommoEventRadio','CommoEventRadio'.Default.MsgStatic,HumanController(pcIterator).PlayerReplicationInfo,None,None);
				}
			}
			CommoHandler(Level.Game.BroadcastHandler).BroadcastTeamByIndex(0,sCallSign $ " radios: " $ sMsg,'Radio');
		}
		else
		{
			ForEach DynamicActors(Class'PlayerController',pcIterator)
			{
				if (HumanController(pcIterator) != None)
				{
					HumanController(pcIterator).ClientMessage(sCallSign $ " radios: " $ sMsg);
				}
				else
				{
				}
			}
		}
	*/
}
void ANPCBaseHelicopterController::TransmitAudioLocationRadioMessage(FVector vLoc, bool bAgitated)
{
	/*
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
		TransmitAudioRadioNumber(iGridX,bAgitated);
		if (bAgitated)
		{
			TransmitAudioRadioMessage(sndByA);
		}
		else
		{
			TransmitAudioRadioMessage(sndBy);
		}
		TransmitAudioRadioNumber(iGridY,bAgitated);
	*/
}
void ANPCBaseHelicopterController::TransmitAudioRadioNumber(int32 iNumber, bool bAgitated)
{
	/*
		local string sNumber;
		local int iDigit;
		local int iDigitIndex;
		sNumber=iNumber;
		for (iDigit=0; iDigit<Len(sNumber); iDigit++)
		{
			iDigitIndex=Mid(sNumber,iDigit,1);
			if (bAgitated)
			{
				TransmitAudioRadioMessage(asndNumbersAgitated[iDigitIndex]);
			}
			else
			{
				TransmitAudioRadioMessage(asndNumbers[iDigitIndex]);
			}
		}
	*/
}
void ANPCBaseHelicopterController::LocationToGrid(FVector vLoc)
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
		sResult="grid reference " $ iGridX $ " by " $ iGridY;
		Return sResult;
	*/
}
void ANPCBaseHelicopterController::AdjustPitchForPositionHold()
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
void ANPCBaseHelicopterController::AdjustRollForPositionHold()
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
void ANPCBaseHelicopterController::AdjustForAltitudeHold()
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
void ANPCBaseHelicopterController::GetForwardRealAltitude()
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
void ANPCBaseHelicopterController::GetRealAltitude()
{
	/*
		local Actor actTraceHit;
		local FVector vHitLocation;
		local FVector vHitNormal;
		local FVector vEndTrace;
		local FVector vStartTrace;
		vStartTrace=Pawn.GetBoneCoords('Pilot').Origin;
		sDebugAltitude="Pawn Location: " $ Pawn.Location $ " Pilot origin: " $ vStartTrace $ "  Distance " $ VSize(Pawn.Location - vStartTrace);
		vStartTrace.Z -= 50;
		vEndTrace=vStartTrace;
		vEndTrace.Z -= 10000;
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,True);
		sDebugAltitude2="Trace hit " $ actTraceHit;
		if (actTraceHit == None)
		{
			Return -1;
		}
		if (actTraceHit.IsA('LevelInfo'))
		{
			Return 0;
		}
		Return vStartTrace.Z - vHitLocation.Z;
	*/
}
void ANPCBaseHelicopterController::HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding)
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
void ANPCBaseHelicopterController::AdjustForDesiredSpeed()
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
void ANPCBaseHelicopterController::AdjustToDesiredHeight()
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
void ANPCBaseHelicopterController::DescendToAltitude(float fpTargetHeight)
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
void ANPCBaseHelicopterController::SeeMonster(APawn* Seen)
{
	/*
		if (fpTimeSinceLastContactReport == 0 || Level.TimeSeconds - fpTimeSinceLastContactReport > 45 && pawnLastSeen != Seen)
		{
			if (pawnLastSeen != None && VSize(pawnLastSeen.Location - Seen.Location) < 5000 && Level.TimeSeconds - fpTimeSinceLastContactReport < 60)
			{
				Return;
			}
			if (Seen.IsA('Vehicle'))
			{
				TransmitAudioRadioMessage(sndRadioPopIn);
				if (Vehicle(Seen).VehicleNameString ~= "T-62A")
				{
					TransmitAudioRadioMessage(sndT62Spotted);
				}
				else
				{
					if (Vehicle(Seen).VehicleNameString ~= "BMP-1")
					{
						TransmitAudioRadioMessage(sndBMPSpotted);
					}
					else
					{
						if (Vehicle(Seen).VehicleNameString ~= "BTR-80" || Vehicle(Seen).VehicleNameString ~= "BTR-60")
						{
							TransmitAudioRadioMessage(sndBTRSpotted);
						}
						else
						{
							TransmitAudioRadioMessage(sndTankSpotted);
						}
					}
				}
				TransmitAudioLocationRadioMessage(Seen.Location);
				TransmitAudioRadioMessage(sndOver);
				TransmitAudioRadioMessage(sndRadioPopOut);
				TransmitRadioMessage(sCallSign $ " enemy " $ Vehicle(Seen).VehicleNameString $ " spotted, location " $ LocationToGrid(Seen.Location));
			}
			else
			{
				if (Seen.Controller != None)
				{
					if (Seen.Controller.IsA('NPCMortarSpotterController'))
					{
						TransmitRadioMessage(sCallSign $ " enemy mortar spotter located, " $ LocationToGrid(Seen.Location));
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndMortarTeamSpotted);
						TransmitAudioLocationRadioMessage(Seen.Location);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitAudioRadioMessage(sndOver);
					}
					else
					{
						if (Seen.Controller.IsA('NPCBaseSoldierController'))
						{
							TransmitRadioMessage(sCallSign $ " enemy infantry spotted, location " $ LocationToGrid(Seen.Location));
							TransmitAudioRadioMessage(sndRadioPopIn);
							TransmitAudioRadioMessage(sndInfantrySpotted);
							TransmitAudioLocationRadioMessage(Seen.Location);
							TransmitAudioRadioMessage(sndOver);
							TransmitAudioRadioMessage(sndRadioPopOut);
						}
						else
						{
							Return;
						}
					}
				}
				else
				{
					Return;
				}
			}
			fpTimeSinceLastContactReport=Level.TimeSeconds;
			pawnLastSeen=Seen;
		}
	*/
}
void ANPCBaseHelicopterController::DetermineNextPathNode()
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
void ANPCBaseHelicopterController::DebugDumpRoute()
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
void ANPCBaseHelicopterController::NPCPathLog(FString sLogText)
{
	/*
		if (bDebugPath)
		{
			Log(Level.TimeSeconds $ " - " $ Self $ "." $ "." $ Tag $ "." $ sNPCWaypointTag $ sLogText);
		}
	*/
}
void ANPCBaseHelicopterController::NPCLog(FString sLogText)
{
	/*
		if (agpvVehicle != None && agpvVehicle.Driver != None)
		{
			if (bDebugMode)
			{
				Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ agpvVehicle.Driver $ " " $ sLogText);
			}
		}
		else
		{
			if (Pawn != None)
			{
				if (bDebugMode)
				{
					Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ Pawn.Name $ " " $ sLogText);
				}
			}
			else
			{
				if (bDebugMode)
				{
					Log(Level.TimeSeconds $ " - " $ Self $ "." $ Tag $ "." $ sNPCWaypointTag $ "." $ GetStateName() $ " - " $ sLogText);
				}
			}
		}
	*/
}
void ANPCBaseHelicopterController::Destroyed()
{
	/*
		CleanupCrew();
		agpvVehicle.Driver.Destroy();
		agpvVehicle.Destroy();
		RemoveController();
	*/
}
void ANPCBaseHelicopterController::CleanupCrew()
{
	/*
		if (agpCrewChief != None)
		{
			agpCrewChief.Destroy();
		}
		if (agpCrewLoadMaster != None)
		{
			agpCrewLoadMaster.Destroy();
		}
		if (agpCoPilot != None)
		{
			agpCoPilot.Destroy();
		}
		if (anpchwpRearwardWounded != None)
		{
			anpchwpRearwardWounded.Destroy();
		}
		if (anpchwpForwardWounded != None)
		{
			anpchwpForwardWounded.Destroy();
		}
	*/
}
void ANPCBaseHelicopterController::EnableDebugTerrainRadarTrace()
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
void ANPCBaseHelicopterController::NotifyTakeDamage(int32 Damage32, APawn* instigatedBy, FVector HitLocation, UaDamageType DamageType, FBoneInfo Bone)
{
	/*
		if (Pawn.Health <= 0)
		{
			TransmitRadioMessage("Mayday, Mayday, Mayday.  " $ sCallSign $ " is going down, location " $ LocationToGrid(Pawn.Location));
			GotoState('HelicopterShotDown');
		}
		else
		{
			if (Level.TimeSeconds - fpTimeSinceLastTakingFireMessage > 30 || fpTimeSinceLastTakingFireMessage == 0)
			{
				if (instigatedBy != None && instigatedBy.IsA('Vehicle'))
				{
					TransmitAudioRadioMessage(sndRadioPopIn);
					TransmitAudioRadioMessage(sndTakingVehicleFire);
					TransmitAudioLocationRadioMessage(instigatedBy.Location,True);
					TransmitAudioRadioMessage(sndOver);
					TransmitAudioRadioMessage(sndRadioPopOut);
					TransmitRadioMessage(sCallSign $ " is taking fire from " $ Vehicle(instigatedBy).VehicleNameString $ ", enemy location at " $ LocationToGrid(instigatedBy.Location));
				}
				else
				{
					if (instigatedBy != None)
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndTakingInfantryFire);
						TransmitAudioLocationRadioMessage(instigatedBy.Location,True);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sCallSign $ " is taking fire, enemy location " $ LocationToGrid(instigatedBy.Location));
					}
					else
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndTakingGenericFire);
						TransmitAudioLocationRadioMessage(Pawn.Location,True);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sCallSign $ " is taking fire, current location " $ LocationToGrid(Pawn.Location));
					}
				}
				fpTimeSinceLastTakingFireMessage=Level.TimeSeconds;
			}
		}
	*/
}
