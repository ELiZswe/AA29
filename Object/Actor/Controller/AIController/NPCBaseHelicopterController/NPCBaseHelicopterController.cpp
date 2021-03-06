// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/DebugNavigation/DebugNPCNavigation/DebugNPCNavigation.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/FlyingPathNode/FlyingPathNode.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/NPCHelicopterWoundedPassenger/NPCHelicopterWoundedPassenger.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Brush/Volume/BlackHawkPickupZoneVolume/BlackHawkPickupZoneVolume.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"
#include "AA29/Object/Actor/Info/TerrainInfo/TerrainInfo.h"

ANPCBaseHelicopterController::ANPCBaseHelicopterController()
{
	asndNumbersAgitated.SetNum(10);
	asndNumbers.SetNum(10);
	sCallSign				= "Bravo Hotel Zero One";
	fpMaxSpeed				= 500;
	fpMaxBackwardSpeed		= -200;
	DrawDriverInTP			= true;
	sndRadioPopIn			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/Radio_Pop_In_Cue.Radio_Pop_In_Cue'"), NULL, LOAD_None, NULL);
	sndRadioPopOut			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/Radio_Pop_Out_Cue.Radio_Pop_Out_Cue'"), NULL, LOAD_None, NULL);
	sndOver					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOver_Cue.BHOver_Cue'"), NULL, LOAD_None, NULL);
	sndHelicopterBGNoise	= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/Helicopter_Loop_Cue.Helicopter_Loop_Cue'"), NULL, LOAD_None, NULL);
	sndBy					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHBy_Cue.BHBy_Cue'"), NULL, LOAD_None, NULL);
	sndByA					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHBy_Cue.BHBy_Cue'"), NULL, LOAD_None, NULL);
	asndNumbers = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero_Cue.BHZero_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOne_Cue.BHOne_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTwo_Cue.BHTwo_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHThree_Cue.BHThree_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHFour_Cue.BHFour_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHFive_Cue.BHFive_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSix_Cue.BHSix_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSeven_Cue.BHSeven_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHEight_Cue.BHEight_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHNine_Cue.BHNine_Cue'"), NULL, LOAD_None, NULL)
	};
	asndNumbersAgitated = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZeroA_Cue.BHZeroA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOneA_Cue.BHOneA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTwoA_Cue.BHTwoA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHThreeA_Cue.BHThreeA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHFourA_Cue.BHFourA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHFiveA_Cue.BHFiveA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSixA_Cue.BHSixA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSevenA_Cue.BHSevenA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHEightA_Cue.BHEightA_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHNineA_Cue.BHNineA_Cue'"), NULL, LOAD_None, NULL)
	};
	sndBMPSpotted				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHBMPSpotted_Cue.BHBMPSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndBTRSpotted				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHBTRSpotted_Cue.BHBTRSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndInfantrySpotted			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHInfantrySpotted_Cue.BHInfantrySpotted_Cue'"), NULL, LOAD_None, NULL);
	sndTankSpotted				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTankSpotted_Cue.BHTankSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndT62Spotted				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHT62Spotted_Cue.BHT62Spotted_Cue'"), NULL, LOAD_None, NULL);
	sndMortarTeamSpotted		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHMortarTeamSpotted_Cue.BHMortarTeamSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndCarSpotted				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHCarSpotted_Cue.BHCarSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndHelicopterSpotted		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHHelicopterSpotted_Cue.BHHelicopterSpotted_Cue'"), NULL, LOAD_None, NULL);
	sndMayday					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHMayday_Cue.BHMayday_Cue'"), NULL, LOAD_None, NULL);
	sndRepairing				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOnGroundRepairing_Cue.BHOnGroundRepairing_Cue'"), NULL, LOAD_None, NULL);
	sndRepairsComplete			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHRepairsComplete_Cue.BHRepairsComplete_Cue'"), NULL, LOAD_None, NULL);
	sndPZOnWayPartOne			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZAckYouHave_Cue.BHPZAckYouHave_Cue'"), NULL, LOAD_None, NULL);
	sndPZOnWayPartTwo			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZAckPaxAtPZ_Cue.BHPZAckPaxAtPZ_Cue'"), NULL, LOAD_None, NULL);
	sndPZOnWayPartThree			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZAckOnStationIn_Cue.BHPZAckOnStationIn_Cue'"), NULL, LOAD_None, NULL);
	sndPZOnWayPartFour			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZAckSecondsOver_Cue.BHPZAckSecondsOver_Cue'"), NULL, LOAD_None, NULL);
	sndCallGreenSmoke			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHCallGreenSmoke_Cue.BHCallGreenSmoke_Cue'"), NULL, LOAD_None, NULL);
	sndBadPZ					= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZAckAbortingPickupOver_Cue.BHPZAckAbortingPickupOver_Cue'"), NULL, LOAD_None, NULL);
	sndPZNotSecureInfantryFire	= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZNotSecureInfantryFire_Cue.BHPZNotSecureInfantryFire_Cue'"), NULL, LOAD_None, NULL);
	sndPZNotSecureVehicleFire	= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZNotSecureVehicleFire_Cue.BHPZNotSecureVehicleFire_Cue'"), NULL, LOAD_None, NULL);
	sndPZNotSecureGeneric		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHPZNotSecureGeneric_Cue.BHPZNotSecureGeneric_Cue'"), NULL, LOAD_None, NULL);
	sndTakingInfantryFire		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTakingInfantryFire_Cue.BHTakingInfantryFire_Cue'"), NULL, LOAD_None, NULL);
	sndTakingVehicleFire		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTakingVehicleFire_Cue.BHTakingVehicleFire_Cue'"), NULL, LOAD_None, NULL);
	sndTakingGenericFire		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTakingGenericFire_Cue.BHTakingGenericFire_Cue'"), NULL, LOAD_None, NULL);
	bSlowerZAcquire				= false;
	bProp						= true;
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
		anpchwpRearwardWounded=Spawn(ANPCHelicopterWoundedPassenger::StaticClass(),,,Location,Rotation,true,true);
		agpvVehicle.AttachToBone(anpchwpRearwardWounded,"Player");
		anpchwpRearwardWounded.SetRelativeRotation(FRotator(0,16384,0));
	}
	Function AttachForwardWounded()
	{
		anpchwpForwardWounded=Spawn(ANPCHelicopterWoundedPassenger::StaticClass(),,,Location,Rotation,true,true);
		agpvVehicle.AttachToBone(anpchwpForwardWounded,"CrewChief");
		anpchwpForwardWounded.SetRelativeLocation(FVector(30,0,-10));
		anpchwpForwardWounded.SetRelativeRotation(FRotator(0,16384,0));
	}
	Function AttachHelmet(APawn* pawnCrewMember)
	{
		AActor* actAttachment = nullptr;
		actAttachment=Spawn(class<Actor>(DynamicLoadObject("AGP_Inventory.Attch_FlightCrewHelmetBH",Class'Class')));
		actAttachment.SetDrawScale(1.13);
		pawnCrewMember.AttachToBone(actAttachment,"BN_HeadEnd");
		actAttachment.SetRelativeRotation(FRotator(0,32768,16384));
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
		if (agpvVehicle->Driver == nullptr)
		{
			if (agpvVehicle->Driver == nullptr)
			{
				Pawn.Destroy();
				agpvVehicle.Destroy();
				GotoState("Failure");
			}
		}
		agpvVehicle->Driver->SetAnimAction("BH_Pilot");
		agpvVehicle->Driver->bHidden=false;
		agpvVehicle.AttachDriver(agpvVehicle->Driver);
		AttachHelmet(agpvVehicle->Driver);
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
	if (agpvVehicle->Driver == nullptr)
	{
		Pawn.Destroy();
		agpvVehicle.Destroy();
		GotoState("Failure");
	}
	fpMechanicalFailureTimer=(FMath::FRand() * 10);
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
		TransmitRadioMessage("Mayday, Mayday, Mayday.  " + sCallSign + " is going down, location " + LocationToGrid(Pawn.Location));
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
	sDebugNavInfo="Descending - Height " + FString::FromInt(GetRealAltitude());
	if (! DescendToAltitude(30))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	sDebugAltitude2="Finished descending, altitude: " + FString::FromInt(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " + FString::FromInt(GetRealAltitude());
	Sleep(0.04);
	GotoState("Repairing");
}
*/

/*
State Repairing
{
Begin:
	TransmitRadioMessage(sCallSign + " is on the ground, attempting repairs.");
	agpvVehicle.HelicopterForceRotorMaxToIdleSpeed();
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.fpHelicopterCollective=0;
	agpCrewLoadMaster.DesiredRotation=(agpvVehicle.Rotation + FRotator(0,16384,0));
	agpCrewLoadMaster.AnimSequence="DocCrhFiddle";
	Sleep(0.5);
	agpCrewChief.DesiredRotation=(agpvVehicle.Rotation + FRotator(0,-16384,0));
	agpCrewChief.AnimSequence="DocCrhFiddle";
	fpRepairTime=((GetWorld()->GetTimeSeconds() + (FMath::FRand() * float(120))) + 60);
	if (GetWorld()->GetTimeSeconds() < fpRepairTime)
	{
		agpvVehicle.HelicopterEngineSmoke(true);
		Sleep(15);
	}
	agpvVehicle.HelicopterEngineSmoke(false);
	TransmitRadioMessage(sCallSign + " repairs complete, resuming patrol");
	agpCrewChief.DesiredRotation=(agpvVehicle.Rotation + FRotator(0,16384,0));
	agpCrewChief.AnimSequence="BH_CrewIdle";
	Sleep(0.25);
	agpCrewLoadMaster.DesiredRotation=(agpvVehicle.Rotation + FRotator(0,-16384,0));
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
	sDebugNavInfo="TestPitch cyclic pitch: " + FString::FromInt(agpvVehicle.fpHelicopterCyclicPitch) + "Desired speed: " + FString::FromInt(agpvVehicle.DesiredSpeed);
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
			sDebugNavInfo="Trying to stop, pitch " + FString::FromInt(agpvVehicle.Rotation.Pitch) + " Collective: " + FString::FromInt(agpvVehicle.fpHelicopterCyclicPitch);
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
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
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
		fpLastGroundFireAdjust=GetWorld()->GetTimeSeconds();
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
			sDebugCyclicPitch="Moving forward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		else
		{
			fpSpeedRatio=(agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed);
			sDebugCyclicPitch="Moving backward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	}
Begin:
	sDebugNavInfo="Getting next waypoint";
	fpGroundFireAvoidanceAltitudeBump=0;
	DetermineNextPathNode();
	FindNextDrivingPatrolPathNode();
	if (pnCurrentFlyingPathNode == nullptr)
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
		sDebugNavInfo="Slowing close to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
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
		sDebugNavInfo="Heading to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
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
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		(iDamageSinceLandingStarted += Damage);
		if (Pawn.Health <= 0)
		{
			TransmitRadioMessage("Mayday, Mayday, Mayday.  " + sCallSign + " is going down, location " + LocationToGrid(Pawn.Location));
			GotoState("HelicopterShotDown");
		}
		else
		{
			if ((iDamageSinceLandingStarted > 300) || (float(Pawn.Health) < 100))
			{
				if ((instigatedBy != nullptr) && instigatedBy->IsA(AVehicle::StaticClass()))
				{
					TransmitAudioRadioMessage(sndRadioPopIn);
					TransmitAudioRadioMessage(sndPZNotSecureVehicleFire);
					TransmitAudioLocationRadioMessage(instigatedBy->GetActorLocation(),true);
					TransmitAudioRadioMessage(sndOver);
					TransmitAudioRadioMessage(sndRadioPopOut);
					TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire from " + Vehicle(instigatedBy).VehicleNameString + ", enemy location at " + LocationToGrid(instigatedBy.Location) + ", aborting pickup.");
				}
				else
				{
					if (instigatedBy != nullptr)
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndPZNotSecureInfantryFire);
						TransmitAudioLocationRadioMessage(instigatedBy->GetActorLocation(),true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire, enemy location " + LocationToGrid(instigatedBy.Location) + ", aborting pickup.");
					}
					else
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndPZNotSecureGeneric);
						TransmitAudioLocationRadioMessage(instigatedBy->GetActorLocation(),true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire, current location " + LocationToGrid(Pawn.Location) + ", aborting pickup.");
					}
				}
				fpTimeSinceLastTakingFireMessage=GetWorld()->GetTimeSeconds();
				Patrol();
			}
			else
			{
				if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastTakingFireMessage) > 30)
				{
					if ((instigatedBy != nullptr) && instigatedBy->IsA(AVehicle::StaticClass()))
					{
						TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire from " + Vehicle(instigatedBy).VehicleNameString + ", enemy location at " + LocationToGrid(instigatedBy.Location) + ".");
					}
					else
					{
						if (instigatedBy != nullptr)
						{
							TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire, enemy location " + LocationToGrid(instigatedBy.Location) + ".");
						}
						else
						{
							TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + ", PZ is not secure, we're taking fire, current location " + LocationToGrid(Pawn.Location) + ".");
						}
					}
					fpTimeSinceLastTakingFireMessage=GetWorld()->GetTimeSeconds();
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
			sDebugNavInfo="Trying to stop, pitch " + FString::FromInt(agpvVehicle.Rotation.Pitch) + " Collective: " + FString::FromInt(agpvVehicle.fpHelicopterCyclicPitch);
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
			sDebugCyclicPitch="Moving forward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		else
		{
			fpSpeedRatio=(agpvVehicle.DesiredSpeed / fpMaxBackwardSpeed);
			sDebugCyclicPitch="Moving backward adjusting by " + FString::FromInt(fpSpeedRatio);
		}
		agpvVehicle.fpHelicopterCyclicPitch=fpSpeedRatio;
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if (Wall->IsA(ATerrainInfo::StaticClass()))
		{
			GotoState("LandedMode");
		}
		return false;
	}
	Function PZRequestPickupCall()
	{
		APlayerController* pctrlIterator = nullptr;
		FString sPlayerName = "";
		iPlayersToPickupCount=0;
		ForEach DynamicActors(Class'PlayerController',pctrlIterator)
		{
			if (((pctrlIterator.PlayerReplicationInfo != nullptr) && (pctrlIterator.PlayerReplicationInfo.Team != nullptr)) && (pctrlIterator.PlayerReplicationInfo.Team.TeamIndex == humctlrPlayerCallingForPickup.PlayerReplicationInfo.Team.TeamIndex))
			{
				iPlayersToPickupCount ++;
			}
		}
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign + "', this is " + sPlayerName + ".  Request pickup for " + FString::FromInt(iPlayersToPickupCount) + " pax at PZ " + LocationToGrid(vLocationLandingZone) + ".  PZ is secure.  Over");
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
		TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + "', you have " + FString::FromInt(iPlayersToPickupCount) + " pax at PZ " + LocationToGrid(vLocationLandingZone) + ".  On station in " + FString::FromInt(iTimeEstimate) + " seconds.  Over.");
		SetCustomTimer(float(iTimeEstimate),false,"PZInSight");
	}
	Function PZBadPZRadioCall()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndBadPZ);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + "', negative on PZ location, cannot locate valid PZ.  Smoke again at valid PZ location");
		GotoState(GetLastStateName());
	}
	Function PZInSight()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndCallGreenSmoke);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioMessage(sPlayerName + ", this is " + sCallSign + "', call green smoke.  Over.");
		SetCustomTimer((2 + float(Rand(2))),false,"PZRespondToSmokeCall");
	}
	Function PZRespondToSmokeCall()
	{
		FString sPlayerName = "";
		sPlayerName="Alpha-Tango One";
		TransmitRadioMessage(sCallSign + "', this is " + sPlayerName + ", roger, that's us.  Standing by. Over");
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
		sDebugNavInfo="Slowing close to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
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
		sDebugNavInfo="Heading to waypoint Distance: " + FString::FromInt(GetDistanceToWaypoint2D());
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
	sDebugNavInfo="Descending - Height " + FString::FromInt(GetRealAltitude());
	if (! DescendToAltitude(60))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	sDebugAltitude2="Finished descending, altitude: " + FString::FromInt(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " + FString::FromInt(GetRealAltitude());
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
	Function bool UsedBy(APawn* User)
	{
		Cast<AHumanController>(User.Controller).ClientMessage("Trying to attach to Player bone");
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
		if (FMath::Abs((fpCurrentAltitude - fpTargetHeight)) < float(20))
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
			if ((FMath::Abs((fpTargetHeight - fpCurrentAltitude)) < float(200)) && (agpvVehicle.Velocity.Z > float(10)))
			{
				(agpvVehicle.fpHelicopterCollective -= 0.001);
				sDebugCollective="Moving up and close, speed " + FString::FromInt(agpvVehicle.Velocity.Z) + ", slowing rate, collective at " + FString::FromInt(agpvVehicle.fpHelicopterCollective);
			}
			else
			{
				if (agpvVehicle.Velocity.Z < fpMaxAscentSpeed)
				{
					(agpvVehicle.fpHelicopterCollective += 0.005);
				}
				sDebugCollective="Moving up but not close, speed " + FString::FromInt(agpvVehicle.Velocity.Z) + ", slowing rate, collective at " + FString::FromInt(agpvVehicle.fpHelicopterCollective);
			}
		}
		else
		{
			agpvVehicle.fpHelicopterCollective=0.05;
			sDebugCollective="Not moving up, increasing collective, now " + FString::FromInt(agpvVehicle.fpHelicopterCollective);
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
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		GotoState("Dead");
		return false;
	}
	Event Landed(Vector HitNormal)
	{
		GotoState("Dead");
	}
	Event Touch(AActor* Other)
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
	sDebugCrashStatus="altitude: " + FString::FromInt(GetRealAltitude());
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
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
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
		agpvVehicle.SetRotation((Rot + FRotator(0,0,4096)));
		agpvVehicle.SetLocation((vLoc + FVector(0,0,float((- 50)))));
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
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
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
	Function Land(Vector vLoc, AController* ctrlOwner)
	{
	}
	Function Patrol()
	{
	}
	Function float GetRealAltitude()
	{
		AActor* actTraceHit = nullptr;
		FVector vHitLocation = FVector(0,0,0);
		FVector vHitNormal = FVector(0,0,0);
		FVector vEndTrace = FVector(0,0,0);
		FVector vStartTrace = FVector(0,0,0);
		vStartTrace=Pawn.GetBoneCoords("Pilot").Origin;
		sDebugAltitude="Pawn Location: " + FString::FromInt(Pawn.Location) + " Pilot origin: " + FString::FromInt(vStartTrace) + "  Distance " + FString::FromInt(VSize((Pawn.Location - vStartTrace)));
		vEndTrace=vStartTrace;
		(vEndTrace.Z -= float(10000));
		actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,true);
		sDebugAltitude2="Trace hit " + FString::FromInt(actTraceHit);
		if (actTraceHit == nullptr)
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
	agpvVehicle->Driver->SetAnimAction("BH_Pilot");
	agpvVehicle->Driver->bForceAnimUpdate=true;
	agpvVehicle.SetCollision(true,true,true);
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	agpvVehicle.DesiredSpeed=0;
	sDebugNavInfo="Descending - Height " + FString::FromInt(GetRealAltitude());
	if (! DescendToAltitude(60))
	{
		Sleep(0.04);
		JL"ContinueDescent"
;
	}
	if (agpCrewLoadMaster != nullptr)
	{
		agpCrewLoadMaster.AnimSequence="BH_CrewIdle";
	}
	sDebugAltitude2="Finished descending, altitude: " + FString::FromInt(GetRealAltitude());
	agpvVehicle.fpHelicopterCollective=0;
	agpvVehicle.fpHelicopterCyclicPitch=0;
	agpvVehicle.fpHelicopterCyclicRoll=0;
	HoldSpecificAltitude(60,true);
	sDebugNavInfo="Hovering at LZ, Height " + FString::FromInt(GetRealAltitude());
	Sleep(0.04);
	JL"HoldLandHover"
;
}
*/

void ANPCBaseHelicopterController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	YL=10;
	if (Pawn->IsA(AVehicle::StaticClass()))
	{
		YPos += YL;
		YPos += YL;
		Canvas.SetDrawColor(255,255,255);
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Current Location: " + Vehicle(Pawn).Location + " Current State: " + GetStateName());
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Collective: " + Vehicle(Pawn).fpHelicopterCollective + "  Cyclic Pitch: " + Vehicle(Pawn).fpHelicopterCyclicPitch + "  Desired Speed " + agpvVehicle.DesiredSpeed);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Rotation: " + Vehicle(Pawn).Rotation + "  Desired Rotation: " + DesiredRotation + " Alt: " + GetRealAltitude() + "  GF Bump: " + fpGroundFireAvoidanceAltitudeBump);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Velocity: " + Vehicle(Pawn).Velocity + " (Speed: " + VSize(agpvVehicle.Velocity) + ")");
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.DrawText("Next Waypoint: " + pnCurrentFlyingPathNode + " Distance to waypoint: " + VSize(agpvVehicle.Location - vAdjustedPathNodeLocation) + " Ratio to destination: " + VSize(agpvVehicle.Location - vAdjustedPathNodeLocation) / 5500);
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

void ANPCBaseHelicopterController::Land(FVector vLoc, AController* ctrlOwner)
{
	ABlackHawkPickupZoneVolume* bhpzvIterator = nullptr;
	ABlackHawkPickupZoneVolume* bhpzvClosest = nullptr;
	FVector vVolCenter2D = FVector(0,0,0);
	FVector vClosestVolCenter2D = FVector(0,0,0);
	FVector vSmokeLoc2D = FVector(0,0,0);
	float fpRangeToPZFromSmoke = 0;
	float fpClosestRangeToPZFromSmoke = 0;
	vSmokeLoc2D = vLoc;
	vSmokeLoc2D.Z = 0;
	/*
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
				if (fpRangeToPZFromSmoke < fpClosestRangeToPZFromSmoke || bhpzvClosest == nullptr)
				{
					bhpzvClosest=bhpzvIterator;
					vClosestVolCenter2D=vVolCenter2D;
					fpClosestRangeToPZFromSmoke=fpRangeToPZFromSmoke;
				}
			}
		}
		bBadPickupZone=false;
		if (bhpzvClosest != nullptr)
		{
			vLoc=vClosestVolCenter2D;
			vLoc.Z=bhpzvClosest.Location.Z;
		}
		else
		{
			if (bRequirePZVolume)
			{
				bBadPickupZone=true;
			}
		}
		vLocationLandingZone=vLoc;
		humctlrPlayerCallingForPickup=Cast<AHumanController>(ctrlOwner);
		GotoState('HeadForLandingZone');
	*/
}
void ANPCBaseHelicopterController::NextWaypoint()
{
	/*
		bFollowPatrol=false;
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
		bFollowPatrol=true;
		GotoState('HeadForWaypoint');
	*/
}
void ANPCBaseHelicopterController::SignalPoppingSmoke()
{
}
void ANPCBaseHelicopterController::InitVehicle()
{
	/*
		bStart=true;
		if (VehicleTag != "None")
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

APathNode* ANPCBaseHelicopterController::GetPathnodeByTagString(FString sTag)
{
	ANavigationPoint* N = nullptr;
	if (sTag.Len() > 0)
	{
		for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
		{
			/*
			if (N->IsA("FlyingPathNode") && (sTag == FString::FromInt(N.Tag)))
			{
				return PathNode(N);
			}
			*/
		}
	}
	return nullptr;
}

void ANPCBaseHelicopterController::PreloadPathNodeList()
{
	int32 iNode = 0;
	APathNode* pnFound = nullptr;
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
		else
		{
			pnFound.bHidden=true;
		}
	}
	*/
}

AFlyingPathNode* ANPCBaseHelicopterController::FindNextDrivingPatrolPathNode()
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
/*
void ANPCBaseHelicopterController::Possess(APawn* aPawn)
{
		NPCLog(Self + " Possess() entered for " + aPawn);
		if (aPawn != nullptr)
		{
			if (aPawn->IsA(AAGP_Pawn::StaticClass()))
			{
				NPCLog("Possess() entered for Vehicle's driver");
				Possess(aPawn);
				NPCLog("Possess of driver pawn " + aPawn + " with mesh: " + aPawn.Mesh);
				agpPawnNPC=Cast<AAGP_Pawn>(aPawn);
				aPawn.Controller=Self;
				bGodMode=true;
				agpPawnNPC.SetCollision(false,false,false);
				agpPawnNPC.bCollideWorld=false;
				priFromNPCPawn=agpPawnNPC.PlayerReplicationInfo;
				NPCLog("PRI for pawn " + agpPawnNPC + " is " + agpPawnNPC.PlayerReplicationInfo);
			}
			else
			{
				if (aPawn->IsA(AVehicle::StaticClass()))
				{
					Possess(aPawn);
					aPawn.PossessedBy(this);
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
		if (Pawn->IsA(AAGP_Pawn::StaticClass()))
		{
			NPCLog("Current pawn is AGP_Pawn (driver leaving vehicle), so we're doing nothing there");
		}
}
*/

void ANPCBaseHelicopterController::WatchForMechanicalFailuresTimer()
{
	/*
		if (fpEngineFailureChance > 0 && FMath::FRand() > 1 - fpEngineFailureChance)
		{
			if (fpMechanicalFailureTimer == 0)
			{
				fpMechanicalFailureTimer=GetWorld()->GetTimeSeconds() + 30 + FMath::FRand() * 120;
			}
			else
			{
				if (GetWorld()->GetTimeSeconds() >= fpMechanicalFailureTimer && fpMechanicalFailureTimer > 0)
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
		asndQueue.insert (asndQueue.Num(),1);
		asndQueue[asndQueue.Num() - 1]=sndAudioMessage;
		if (asndQueue.Num() > 1)
		{
			return;
		}
		PlayAudioRadioMessage(asndQueue[0]);
	*/
}

void ANPCBaseHelicopterController::PlayAudioRadioMessage(USoundBase* sndAudioMessage)
{
	APlayerController* pcIterator = nullptr;
	/*
	ForEach DynamicActors(Class'PlayerController',pcIterator)
	{
		if (pcIterator.Pawn != nullptr && pcIterator.Pawn->IsA(AAGP_Pawn::StaticClass()) || Vehicle(pcIterator.Pawn) != nullptr && Vehicle(pcIterator.Pawn).Driver != nullptr && Vehicle(pcIterator.Pawn).Driver->IsA(AAGP_Pawn::StaticClass()))
		{
			if (sndAudioMessage == sndRadioPopIn)
			{
				pcIterator.Pawn.AmbientSound=sndHelicopterBGNoise;
			}
			else
			{
				if (sndAudioMessage == sndRadioPopOut)
				{
					pcIterator.Pawn.AmbientSound=nullptr;
				}
			}
			pcIterator.ClientPlaySound(sndAudioMessage);
		}
	}
	SetCustomTimer(GetSoundDuration(sndAudioMessage),false,'PlayNextQueuedSoundTimer');
	*/
}
void ANPCBaseHelicopterController::PlayNextQueuedSoundTimer()
{
	/*
		if (asndQueue.Num() > 0)
		{
			asndQueue->Remove(0,1);
		}
		if (asndQueue.Num() > 0)
		{
			PlayAudioRadioMessage(asndQueue[0]);
		}
	*/
}
void ANPCBaseHelicopterController::TransmitRadioMessage(FString sMsg)
{
	APlayerController* pcIterator = nullptr;
	/*
	if (GetWorld()->GetNetMode() == 1)
	{
		ForEach DynamicActors(Class'PlayerController',pcIterator)
		{
			if (pcIterator.Pawn != nullptr && pcIterator.Pawn->IsA(AAGP_Pawn::StaticClass()) || Vehicle(pcIterator.Pawn) != nullptr && Vehicle(pcIterator.Pawn).Driver != nullptr && Vehicle(pcIterator.Pawn).Driver->IsA(AAGP_Pawn::StaticClass()))
			{
				CommoHandler(Level.Game.BroadcastHandler).BroadcastLocalized(None,pcIterator,'CommoEventRadio','CommoEventRadio'.Default.MsgStatic,HumanController(pcIterator).PlayerReplicationInfo,None,None);
			}
		}
		CommoHandler(Level.Game.BroadcastHandler).BroadcastTeamByIndex(0,sCallSign + " radios: " + sMsg,'Radio');
	}
	else
	{
		ForEach DynamicActors(Class'PlayerController',pcIterator)
		{
			if (Cast<AHumanController>(pcIterator) != nullptr)
			{
				Cast<AHumanController>(pcIterator).ClientMessage(sCallSign + " radios: " + sMsg);
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
	FString sNumber = "";
	int32 iDigit = 0;
	int32 iDigitIndex = 0;
	sNumber = FString::FromInt(iNumber);
	for (iDigit=0; iDigit<sNumber.Len(); iDigit++)
	{
		//iDigitIndex=Mid(sNumber,iDigit,1);
		if (bAgitated)
		{
			TransmitAudioRadioMessage(asndNumbersAgitated[iDigitIndex]);
		}
		else
		{
			TransmitAudioRadioMessage(asndNumbers[iDigitIndex]);
		}
	}
}

FString ANPCBaseHelicopterController::LocationToGrid(FVector vLoc)
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
	sResult="grid reference " + iGridX + " by " + iGridY;
	*/
	return sResult;
}

void ANPCBaseHelicopterController::AdjustPitchForPositionHold()
{
	/*
		if (agpvVehicle.Velocity.X <= -1)
		{
			agpvVehicle.fpHelicopterCyclicPitch -= 0.01;
			sDebugCyclicPitch="Adjusting pitch to slow backward movement: " + agpvVehicle.fpHelicopterCyclicPitch;
		}
		else
		{
			if (agpvVehicle.Velocity.X >= 1)
			{
				agpvVehicle.fpHelicopterCyclicPitch += 0.01;
				sDebugCyclicPitch="Adjusting pitch to slow forward movement: " + agpvVehicle.fpHelicopterCyclicPitch;
			}
			else
			{
				agpvVehicle.fpHelicopterCyclicPitch=0;
				sDebugCyclicPitch="Pitch hold ok: " + agpvVehicle.fpHelicopterCyclicPitch;
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
			sDebugCollective="Hold Altitude (velocity " + agpvVehicle.Velocity.Z + "), raising collective to " + agpvVehicle.fpHelicopterCollective;
		}
		else
		{
			if (agpvVehicle.Velocity.Z >= 2.5)
			{
				agpvVehicle.fpHelicopterCollective=-0.001 * Abs(agpvVehicle.Velocity.Z);
				sDebugCollective="Hold Altitude (velocity " + agpvVehicle.Velocity.Z + "), lowering collective to " + agpvVehicle.fpHelicopterCollective;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0;
				sDebugCollective="Hold Altitude (velocity " + agpvVehicle.Velocity.Z + "), holding collective at " + agpvVehicle.fpHelicopterCollective;
			}
		}
	*/
}

float ANPCBaseHelicopterController::GetForwardRealAltitude()
{
	AActor* actTraceHit = nullptr;
	FVector vHitLocation = FVector(0, 0, 0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vEndTrace = FVector(0, 0, 0);
	FVector vStartTrace = FVector(0,0,0);
	FRotator rotCleaned = FRotator(0, 0, 0);
	/*
		vStartTrace=Pawn.Location;
		rotCleaned=Pawn.Rotation;
		rotCleaned.Pitch=0;
		rotCleaned.Roll=0;
		vStartTrace +=  Vector(rotCleaned) * 2000 + VSize(agpvVehicle.Velocity);
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
	return 0;    //FAKE   /EliZ
}

float ANPCBaseHelicopterController::GetRealAltitude()
{
	AActor* actTraceHit = nullptr;
	FVector vHitLocation = FVector(0,0,0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vEndTrace = FVector(0, 0, 0);
	FVector vStartTrace = FVector(0, 0, 0);
	/*
	vStartTrace=Pawn.GetBoneCoords('Pilot').Origin;
	sDebugAltitude="Pawn Location: " + Pawn.Location + " Pilot origin: " + vStartTrace + "  Distance " + VSize(Pawn.Location - vStartTrace);
	vStartTrace.Z -= 50;
	vEndTrace=vStartTrace;
	vEndTrace.Z -= 10000;
	actTraceHit=Pawn.Trace(vHitLocation,vHitNormal,vEndTrace,vStartTrace,true);
	sDebugAltitude2="Trace hit " + actTraceHit;
	if (actTraceHit == nullptr)
	{
		return -1;
	}
	if (actTraceHit->IsA(ALevelInfo::StaticClass()))
	{
		return 0;
	}
	return vStartTrace.Z - vHitLocation.Z;
	*/
	return 0;    //FAKE   ELiZ
}

void ANPCBaseHelicopterController::HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding)
{
	float fpCurrentRealAltitude = 0;
	float fpVertVelocity = 0;
	float fpDistFromAltitude = 0;
	float fpMaxUUAboveVariation = 0;
	float fpMaxUUBelowVariation = 0;
	/*
	if (! bDisableVarianceForLanding)
	{
		fpMaxUUAboveVariation=25;
		fpMaxUUBelowVariation=25;
	}
	fpCurrentRealAltitude=GetRealAltitude();
	fpDistFromAltitude=FMath::Abs(fpCurrentRealAltitude - fpDesiredAltitude);
	fpVertVelocity=agpvVehicle.Velocity.Z;
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
					agpvVehicle.fpHelicopterCollective=0.05;
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
					agpvVehicle.fpHelicopterCollective -= 0.005;
				}
				else
				{
					if (fpVertVelocity <= -50)
					{
						sDebugCollective2="velocity too fast from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
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
			sDebugCollective="Descending collective " + agpvVehicle.fpHelicopterCollective + " Desired Alt: " + fpDesiredAltitude + "  Alt: " + FString::SanitizeFloat(fpCurrentRealAltitude) + " Dist: " + fpDistFromAltitude + " Vel: " + fpVertVelocity;
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
						agpvVehicle.fpHelicopterCollective -= 0.001;
					}
					else
					{
						sDebugCollective2="Close, good velocity from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
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
						sDebugCollective2="Not close, collective < .25 from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						if (agpvVehicle.fpHelicopterCollective < 0)
						{
							agpvVehicle.fpHelicopterCollective=0;
						}
						agpvVehicle.fpHelicopterCollective += 0.001;
					}
					else
					{
						sDebugCollective2="Not close, collective < .25 from " + FString::SanitizeFloat(fpCurrentRealAltitude) + " to " + FString::SanitizeFloat(fpDesiredAltitude);
						agpvVehicle.fpHelicopterCollective=0.01;
					}
				}
			}
			sDebugCollective="Ascending, collective " + agpvVehicle.fpHelicopterCollective + " Desired Alt: " + fpDesiredAltitude + "  Alt: " + FString::SanitizeFloat(fpCurrentRealAltitude) + " Dist: " + fpDistFromAltitude + " Vel: " + fpVertVelocity;
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

bool ANPCBaseHelicopterController::DescendToAltitude(float fpTargetHeight)
{
	float fpCurrentAltitude = 0;
	float fpMaxDescentSpeed = 0;
	fpMaxDescentSpeed = -250;
	/*
	fpCurrentAltitude=GetRealAltitude();
	if (FMath::Abs(fpCurrentAltitude - fpTargetHeight) < 50)
	{
		if (agpvVehicle.Velocity.Z > 0)
		{
			agpvVehicle.fpHelicopterCollective=0;
			return false;
		}
		else
		{
			if (agpvVehicle.Velocity.Z < -3)
			{
				agpvVehicle.fpHelicopterCollective=0.01;
				return false;
			}
			else
			{
				agpvVehicle.fpHelicopterCollective=0.001;
				return true;
			}
		}
	}
	if (fpCurrentAltitude <= fpTargetHeight + 50)
	{
		if (agpvVehicle.Velocity.Z < -5)
		{
			agpvVehicle.fpHelicopterCollective=0.01 * agpvVehicle.Velocity.Z * -1;
			sDebugCollective="Altitude below or at target height, still moving down";
			return false;
		}
		else
		{
			agpvVehicle.fpHelicopterCollective=0.001;
			sDebugCollective="Altitude below or at target height, not moving (done) ";
			return true;
		}
	}
	if (agpvVehicle.Velocity.Z < fpMaxDescentSpeed)
	{
		if (FMath::Abs(fpTargetHeight - fpCurrentAltitude) < 200)
		{
			agpvVehicle.fpHelicopterCollective += 0.2;
			sDebugCollective="Moving down and close, speed " + agpvVehicle.Velocity.Z + ", slowing rate, collective at " + agpvVehicle.fpHelicopterCollective;
		}
		else
		{
			agpvVehicle.fpHelicopterCollective += 0.02;
			sDebugCollective="Moving down but not close, speed " + agpvVehicle.Velocity.Z + ", slowing rate, collective at " + agpvVehicle.fpHelicopterCollective;
		}
	}
	else
	{
		if (agpvVehicle.Velocity.Z > fpMaxDescentSpeed)
		{
			agpvVehicle.fpHelicopterCollective=-0.01;
			sDebugCollective="Not moving down, reducing collective, now " + agpvVehicle.fpHelicopterCollective;
		}
	}
	*/
	return false;
}
void ANPCBaseHelicopterController::SeeMonster(APawn* Seen)
{
	/*
		if (fpTimeSinceLastContactReport == 0 || GetWorld()->GetTimeSeconds() - fpTimeSinceLastContactReport > 45 && pawnLastSeen != Seen)
		{
			if (pawnLastSeen != nullptr && VSize(pawnLastSeen.Location - Seen.Location) < 5000 && GetWorld()->GetTimeSeconds() - fpTimeSinceLastContactReport < 60)
			{
				return;
			}
			if (Seen->IsA(AVehicle::StaticClass()))
			{
				TransmitAudioRadioMessage(sndRadioPopIn);
				if (Cast<AVehicle>(Seen).VehicleNameString ~= "T-62A")
				{
					TransmitAudioRadioMessage(sndT62Spotted);
				}
				else
				{
					if (Cast<AVehicle>(Seen).VehicleNameString ~= "BMP-1")
					{
						TransmitAudioRadioMessage(sndBMPSpotted);
					}
					else
					{
						if (Cast<AVehicle>(Seen).VehicleNameString ~= "BTR-80" || Vehicle(Seen).VehicleNameString ~= "BTR-60")
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
				TransmitRadioMessage(sCallSign + " enemy " + Vehicle(Seen).VehicleNameString + " spotted, location " + LocationToGrid(Seen.Location));
			}
			else
			{
				if (Seen.Controller != nullptr)
				{
					if (Seen.Controller->IsA(ANPCMortarSpotterController::StaticClass()))
					{
						TransmitRadioMessage(sCallSign + " enemy mortar spotter located, " + LocationToGrid(Seen.Location));
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndMortarTeamSpotted);
						TransmitAudioLocationRadioMessage(Seen.Location);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitAudioRadioMessage(sndOver);
					}
					else
					{
						if (Seen.Controller->IsA(ANPCBaseSoldierController::StaticClass()))
						{
							TransmitRadioMessage(sCallSign + " enemy infantry spotted, location " + LocationToGrid(Seen.Location));
							TransmitAudioRadioMessage(sndRadioPopIn);
							TransmitAudioRadioMessage(sndInfantrySpotted);
							TransmitAudioLocationRadioMessage(Seen.Location);
							TransmitAudioRadioMessage(sndOver);
							TransmitAudioRadioMessage(sndRadioPopOut);
						}
						else
						{
							return;
						}
					}
				}
				else
				{
					return;
				}
			}
			fpTimeSinceLastContactReport=GetWorld()->GetTimeSeconds();
			pawnLastSeen=Seen;
		}
	*/
}
void ANPCBaseHelicopterController::DetermineNextPathNode()
{
	/*
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
							agpvVehicle.Throttle=0;
							agpvVehicle.Steering=0;
							agpvVehicle.fpHelicopterCollective=0;
							Pawn.bRotateToDesired=false;
							bAutoReversePath=false;
							GotoState("None");
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
			NPCLog("Ascending pathnodes - new index: " + iCurrentPathNodeIndex + " node: " + apnFlyingPathNodesForPatrol[iCurrentPathNodeIndex].Tag);
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
	*/
}
void ANPCBaseHelicopterController::DebugDumpRoute()
{
	/*
		int32 i = 0;
		NPCLog("******************************");
		NPCLog("Vehicle Route goal: " + RouteGoal + ", distance: " + RouteDist);
		for (i=0; i<62; i++)
		{
			if (RouteCache[i] != nullptr)
			{
				NPCLog("Route[ " + i + "] => " + RouteCache[i] + ": " + RouteCache[i].Tag);
			}
		}
		NPCLog("******************************");
	*/
}
void ANPCBaseHelicopterController::NPCPathLog(FString sLogText)
{
	if (bDebugPath)
	{
		//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + "." + Tag + "." + sNPCWaypointTag + sLogText);
	}
}

void ANPCBaseHelicopterController::NPCLog(FString sLogText)
{
	if (agpvVehicle != nullptr && agpvVehicle->Driver != nullptr)
	{
		if (bDebugMode)
		{
			//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + agpvVehicle->Driver + " " + sLogText);
		}
	}
	else
	{
		if (GetPawn() != nullptr)
		{
			if (bDebugMode)
			{
				//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + Pawn.Name + " " + sLogText);
			}
		}
		else
		{
			if (bDebugMode)
			{
				//Log(GetWorld()->GetTimeSeconds() + " - " + this + "." + Tag + "." + sNPCWaypointTag + "." + GetStateName() + " - " + sLogText);
			}
		}
	}
}

void ANPCBaseHelicopterController::Destroyed()
{
	/*
		CleanupCrew();
		agpvVehicle->Driver->Destroy();
		agpvVehicle.Destroy();
		RemoveController();
	*/
}
void ANPCBaseHelicopterController::CleanupCrew()
{
	/*
		if (agpCrewChief != nullptr)
		{
			agpCrewChief.Destroy();
		}
		if (agpCrewLoadMaster != nullptr)
		{
			agpCrewLoadMaster.Destroy();
		}
		if (agpCoPilot != nullptr)
		{
			agpCoPilot.Destroy();
		}
		if (anpchwpRearwardWounded != nullptr)
		{
			anpchwpRearwardWounded.Destroy();
		}
		if (anpchwpForwardWounded != nullptr)
		{
			anpchwpForwardWounded.Destroy();
		}
	*/
}
void ANPCBaseHelicopterController::EnableDebugTerrainRadarTrace()
{
	/*
		if (dnpcnDebugTerrainRadarMarker == nullptr)
		{
			dnpcnDebugTerrainRadarMarker=Spawn('DebugNPCNavigation');
			dnpcnDebugTerrainRadarMarker.SetCollision(false,false,false);
			dnpcnDebugTerrainRadarMarker.bHidden=false;
		}
	*/
}
void ANPCBaseHelicopterController::NotifyTakeDamage(int32 Damage32, APawn* instigatedBy, FVector HitLocation, UaDamageType DamageType, FBoneInfo Bone)
{
	/*
		if (Pawn.Health <= 0)
		{
			TransmitRadioMessage("Mayday, Mayday, Mayday.  " + sCallSign + " is going down, location " + LocationToGrid(Pawn.Location));
			GotoState('HelicopterShotDown');
		}
		else
		{
			if (GetWorld()->GetTimeSeconds() - fpTimeSinceLastTakingFireMessage > 30 || fpTimeSinceLastTakingFireMessage == 0)
			{
				if (instigatedBy != nullptr && instigatedBy->IsA(AVehicle::StaticClass()))
				{
					TransmitAudioRadioMessage(sndRadioPopIn);
					TransmitAudioRadioMessage(sndTakingVehicleFire);
					TransmitAudioLocationRadioMessage(instigatedBy->GetActorLocation(),true);
					TransmitAudioRadioMessage(sndOver);
					TransmitAudioRadioMessage(sndRadioPopOut);
					TransmitRadioMessage(sCallSign + " is taking fire from " + Vehicle(instigatedBy).VehicleNameString + ", enemy location at " + LocationToGrid(instigatedBy.Location));
				}
				else
				{
					if (instigatedBy != nullptr)
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndTakingInfantryFire);
						TransmitAudioLocationRadioMessage(instigatedBy->GetActorLocation(),true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sCallSign + " is taking fire, enemy location " + LocationToGrid(instigatedBy.Location));
					}
					else
					{
						TransmitAudioRadioMessage(sndRadioPopIn);
						TransmitAudioRadioMessage(sndTakingGenericFire);
						TransmitAudioLocationRadioMessage(Pawn->GetActorLocation(),true);
						TransmitAudioRadioMessage(sndOver);
						TransmitAudioRadioMessage(sndRadioPopOut);
						TransmitRadioMessage(sCallSign + " is taking fire, current location " + LocationToGrid(Pawn.Location));
					}
				}
				fpTimeSinceLastTakingFireMessage=GetWorld()->GetTimeSeconds();
			}
		}
	*/
}
