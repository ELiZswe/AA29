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
	Function BeginState ()
	{
		NPCLog("NPC " $ Tag $ " could not find a vehicle!");
	}
}
State InitializeVehicle
{
	Function AttachHelmet (Pawn pawnCrewMember)
	{
		local Actor actAttachment;
		actAttachment=Spawn(class<Actor>(DynamicLoadObject("AGP_Inventory.Attch_FlightCrewHelmetBH",Class'Class')));
		actAttachment.SetDrawScale(1.13);
		pawnCrewMember.AttachToBone(actAttachment,'BN_HeadEnd');
		actAttachment.SetRelativeRotation(MakeRot(0,32768,16384));
	}
	Function AttachForwardWounded ()
	{
		anpchwpForwardWounded=Spawn('NPCHelicopterWoundedPassenger',,,Location,Rotation,True,True);
		agpvVehicle.AttachToBone(anpchwpForwardWounded,'CrewChief');
		anpchwpForwardWounded.SetRelativeLocation(MakeVect(30,0,-10));
		anpchwpForwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	}
	Function AttachRearwardWounded ()
	{
		anpchwpRearwardWounded=Spawn('NPCHelicopterWoundedPassenger',,,Location,Rotation,True,True);
		agpvVehicle.AttachToBone(anpchwpRearwardWounded,'Player');
		anpchwpRearwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	}
	Function AttachCoPilot ()
	{
		agpCoPilot=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,Location,Rotation,True,True);
		agpCoPilot.HUDText="Co-Pilot";
		agpCoPilot.SetCollision(False,False,False);
		agpCoPilot.AnimSequence='BH_Pilot';
		agpCoPilot.bCollideWorld=False;
		agpCoPilot.PrePivot.Z=0;
		agpCoPilot.SetPhysics(0);
		agpvVehicle.AttachToBone(agpCoPilot,'CoPilot');
		AttachHelmet(agpCoPilot);
	}
	Function AttachCrewLoadMaster ()
	{
		agpCrewLoadMaster=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,Location,Rotation,True,True);
		agpCrewLoadMaster.HUDText="Loadmaster";
		agpCrewLoadMaster.SetCollision(False,False,False);
		agpCrewLoadMaster.PrePivot.Z=0;
		agpCrewLoadMaster.SetPhysics(0);
		agpCrewLoadMaster.AnimSequence='BH_CrewIdle';
		agpvVehicle.AttachToBone(agpCrewLoadMaster,'Player');
		AttachHelmet(agpCrewLoadMaster);
	}
	Function AttachCrewChief ()
	{
		agpCrewChief=Spawn(class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,Location,Rotation,True,True);
		agpCrewChief.HUDText="Crew Chief";
		agpCrewChief.SetCollision(False,False,False);
		agpCrewChief.PrePivot.Z=0;
		agpCrewChief.SetPhysics(0);
		agpCrewChief.AnimSequence='BH_CrewIdle';
		agpvVehicle.AttachToBone(agpCrewChief,'CrewChief');
		agpCrewChief.SetCollision(False,True,True);
		AttachHelmet(agpCrewChief);
	}
}
State Failure
{
}
State MechanicalFailure
{
	Function TransmitMayday ()
	{
		TransmitRadioMessage("Mayday, Mayday, Mayday.  " $ sCallSign $ " is going down, location " $ LocationToGrid(Pawn.Location));
	}
}
State Repairing
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
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
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
		local Object.Vector vDesiredRotation;
		local Object.Vector vCurrentRotation;
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
	}
}
State HeadForLandingZone
{
	Function PZRespondToSmokeCall ()
	{
		local string sPlayerName;
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign $ "', this is " $ sPlayerName $ ", roger, that's us.  Standing by. Over");
		npcaiccEnemyCombatController.NotifyHelicopterLanding(vLocationLandingZone);
	}
	Function PZInSight ()
	{
		local string sPlayerName;
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndCallGreenSmoke);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', call green smoke.  Over.");
		SetCustomTimer(2 + Rand(2),False,'PZRespondToSmokeCall');
	}
	Function PZBadPZRadioCall ()
	{
		local string sPlayerName;
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndBadPZ);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', negative on PZ location, cannot locate valid PZ.  Smoke again at valid PZ location");
		GotoState(GetLastStateName());
	}
	Function PZOnWayRadioCall ()
	{
		local int iTimeEstimate;
		local string sPlayerName;
		iTimeEstimate=VSize(Pawn.Location - vLocationLandingZone) / 850 + Rand(15);
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndPZOnWayPartOne);
		TransmitAudioRadioNumber(iPlayersToPickupCount,False);
		TransmitAudioRadioMessage(sndPZOnWayPartTwo);
		TransmitAudioLocationRadioMessage(vLocationLandingZone);
		TransmitAudioRadioMessage(sndPZOnWayPartThree);
		TransmitAudioRadioNumber(iTimeEstimate,False);
		TransmitAudioRadioMessage(sndPZOnWayPartFour);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ "', you have " $ iPlayersToPickupCount $ " pax at PZ " $ LocationToGrid(vLocationLandingZone) $ ".  On station in " $ iTimeEstimate $ " seconds.  Over.");
		SetCustomTimer(iTimeEstimate,False,'PZInSight');
	}
	Function PZRequestPickupCall ()
	{
		local PlayerController pctrlIterator;
		local string sPlayerName;
		iPlayersToPickupCount=0;
		ForEach DynamicActors(Class'PlayerController',pctrlIterator)
		{
			if (pctrlIterator.PlayerReplicationInfo != None && pctrlIterator.PlayerReplicationInfo.Team != None && pctrlIterator.PlayerReplicationInfo.Team.TeamIndex == humctlrPlayerCallingForPickup.PlayerReplicationInfo.Team.TeamIndex)
			{
				iPlayersToPickupCount ++;
			}
		}
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign $ "', this is " $ sPlayerName $ ".  Request pickup for " $ iPlayersToPickupCount $ " pax at PZ " $ LocationToGrid(vLocationLandingZone) $ ".  PZ is secure.  Over");
		if (bBadPickupZone)
		{
			SetCustomTimer(2 + Rand(3),False,'PZBadPZRadioCall');
		}
		else
		{
			SetCustomTimer(2 + Rand(3),False,'PZOnWayRadioCall');
		}
	}
	Event Bool NotifyHitWall (Object.Vector HitNormal, Actor Wall)
	{
		if (Wall.IsA('TerrainInfo'))
		{
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
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		local string sPlayerName;
		sPlayerName="Alpha-Tango One";
		iDamageSinceLandingStarted += Damage;
		if (Pawn.Health <= 0)
		{
			TransmitRadioMessage("Mayday, Mayday, Mayday.  " $ sCallSign $ " is going down, location " $ LocationToGrid(Pawn.Location));
			GotoState('HelicopterShotDown');
		}
		else
		{
			if (iDamageSinceLandingStarted > 300 || Pawn.Health < 100)
			{
				if (instigatedBy != None && instigatedBy.IsA('Vehicle'))
				{
					TransmitAudioRadioMessage(sndRadioPopIn);
					TransmitAudioRadioMessage(sndPZNotSecureVehicleFire);
					TransmitAudioLocationRadioMessage(instigatedBy.Location,True);
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
						TransmitAudioLocationRadioMessage(instigatedBy.Location,True);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sPlayerName $ ", this is " $ sCallSign $ ", PZ is not secure, we're taking fire, enemy location " $ LocationToGrid(instigatedBy.Location) $ ", aborting pickup.");
					}
					else
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndPZNotSecureGeneric);
						TransmitAudioLocationRadioMessage(instigatedBy.Location,True);
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
				if (Level.TimeSeconds - fpTimeSinceLastTakingFireMessage > 30)
				{
					if (instigatedBy != None && instigatedBy.IsA('Vehicle'))
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
}
State LandedMode
{
	Function UsedBy (Pawn User)
	{
		HumanController(User.Controller).ClientMessage("Trying to attach to Player bone");
		User.ShouldCrouch(True);
		User.SetCollision(False,False,False);
		User.PrePivot.Z=0;
		User.SetPhysics(0);
		User.LoopAnim('BH_CrewIdle');
		agpvVehicle.AttachToBone(User,'Player');
		Return True;
	}
	Function Hover ()
	{
		HoldSpecificAltitude(1000,True);
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
		GotoState('Dead');
	}
	Event Landed (Object.Vector HitNormal)
	{
		GotoState('Dead');
		Return;
	}
	Event Bool NotifyHitWall (Object.Vector HitNormal, Actor Wall)
	{
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
State DummyHelicopter
{
	Function TurnedEnough (optional float fpAngle)
	{
		local Object.Vector vDesiredRotation;
		local Object.Vector vCurrentRotation;
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
	}
	Function GetRealAltitude ()
	{
		local Actor actTraceHit;
		local Object.Vector vHitLocation;
		local Object.Vector vHitNormal;
		local Object.Vector vEndTrace;
		local Object.Vector vStartTrace;
		vStartTrace=Pawn.GetBoneCoords('Pilot').Origin;
		sDebugAltitude="Pawn Location: " $ Pawn.Location $ " Pilot origin: " $ vStartTrace $ "  Distance " $ VSize(Pawn.Location - vStartTrace);
		vEndTrace=vStartTrace;
		vEndTrace.Z -= 10000;
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,True);
		sDebugAltitude2="Trace hit " $ actTraceHit;
		if (actTraceHit == None)
		{
			Return -1;
		}
		Return vStartTrace.Z - vHitLocation.Z;
	}
	Function Patrol ()
	{
	}
	Function Land (Object.Vector vLoc, Controller ctrlOwner)
	{
	}
	Function NextWaypoint ()
	{
	}
	Function Hover ()
	{
	}
	Function TakeOff ()
	{
	}
	Function NotifyTakeDamage (int Damage, Pawn instigatedBy, Object.Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
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
