// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_USMortarTeamFDC/AGP_USMortarTeamFDC.h"
#include "AA29/Object/Actor/AGP_USMortarTeam/AGP_USMortarTeam.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_120mmMortar/Proj_120mmMortar.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmSmokeMortar/Proj_60mmSmokeMortar.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmTrainingMortar/Proj_60mmTrainingMortar.h"

static const int32 FDCSTEP_WAITINGFORORDER = 0;
static const int32 FDCSTEP_PROCESSINGORDER = 1;

// Sets default values
AAGP_USMortarTeamFDC::AAGP_USMortarTeamFDC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	fpBusyRating = 0.25;

	asndFDCNumbers = {
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOne.BHOne'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTwo.BHTwo'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHThree.BHThree'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSix.BHSix'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSeven.BHSeven'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHEight.BHEight'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHNine.BHNine'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL)
	};
	asndFONumbers = {
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHOne.BHOne'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHTwo.BHTwo'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHThree.BHThree'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSix.BHSix'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHSeven.BHSeven'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHEight.BHEight'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHNine.BHNine'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/BHZero.BHZero'"), NULL, LOAD_None, NULL)
	};

	sndRadioPopIn						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/Radio_Pop_In.Radio_Pop_In'"), NULL, LOAD_None, NULL);
	sndRadioPopOut						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_AircraftRadio/blackhawk/Radio_Pop_Out.Radio_Pop_Out'"), NULL, LOAD_None, NULL);
	sndPause							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/Generic/Pause.Pause'"), NULL, LOAD_None, NULL);
	sndFDCSuppressPolar					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCSuppressPolar.FDCSuppressPolar'"), NULL, LOAD_None, NULL);
	sndFDCSmokePolar					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCSmokePolar.FDCSmokePolar'"), NULL, LOAD_None, NULL);
	sndFDCSuppressGrid					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCSuppressGrid.FDCSuppressGrid'"), NULL, LOAD_None, NULL);
	sndFDCSmokeGrid						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCSmokeGrid.FDCSmokeGrid'"), NULL, LOAD_None, NULL);
	sndFDCFireMissionOnWay				= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCFireMissionOnWay.FDCFireMissionOnWay'"), NULL, LOAD_None, NULL);
	sndFDCPolarFiring					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCPolarFiring.FDCPolarFiring'"), NULL, LOAD_None, NULL);
	sndFDCGridFiring					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCGridFiring.FDCGridFiring'"), NULL, LOAD_None, NULL);
	sndFDCFireMissionCompleteNoRounds	= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCFireMissionCompleteNoRounds.FDCFireMissionCompleteNoRounds'"), NULL, LOAD_None, NULL);
	sndFDCFireMissionComplete			= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCFireMissionComplete.FDCFireMissionComplete'"), NULL, LOAD_None, NULL);
	sndFDCRepeat						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCRepeat.FDCRepeat'"), NULL, LOAD_None, NULL);
	sndFDCStandby						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCStandBy.FDCStandBy'"), NULL, LOAD_None, NULL);
	sndFDCAtYourCommand					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCAtYourCommand.FDCAtYourCommand'"), NULL, LOAD_None, NULL);
	sndFDCCheckedFire					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCCheckedFire.FDCCheckedFire'"), NULL, LOAD_None, NULL);
	sndFDCDistance						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCDistance.FDCDistance'"), NULL, LOAD_None, NULL);
	sndReadyOver						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCReadyOver.FDCReadyOver'"), NULL, LOAD_None, NULL);
	sndFDCOver							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCOver.FDCOver'"), NULL, LOAD_None, NULL);
	sndFDCTargetInfantry				= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCTargetInfantry.FDCTargetInfantry'"), NULL, LOAD_None, NULL);
	sndFDCTargetInfantryDangerClose		= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCTargetInfantryDangerClose.FDCTargetInfantryDangerClose'"), NULL, LOAD_None, NULL);
	sndFDCTargetVehicle					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCTargetVehicle.FDCTargetVehicle'"), NULL, LOAD_None, NULL);
	sndFDCTargetVehicleDangerClose		= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCTargetVehicleDangerClose.FDCTargetVehicleDangerClose'"), NULL, LOAD_None, NULL);
	sndFDCMeters						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCMeters.FDCMeters'"), NULL, LOAD_None, NULL);
	sndFDCRounds						= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCRounds.FDCRounds'"), NULL, LOAD_None, NULL);
	sndFDCGun							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCGun.FDCGun'"), NULL, LOAD_None, NULL);
	sndFDCGuns							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCGuns.FDCGuns'"), NULL, LOAD_None, NULL);
	sndFDCFireMissionCancelled			= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCFireMissionCancelled.FDCFireMissionCancelled'"), NULL, LOAD_None, NULL);
	sndFDCBy							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCBy.FDCBy'"), NULL, LOAD_None, NULL);
	sndFDCAdjustFire					= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCAdjustFire.FDCAdjustFire'"), NULL, LOAD_None, NULL);
	sndFDCLeft							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCLeft.FDCLeft'"), NULL, LOAD_None, NULL);
	sndFDCRight							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCRight.FDCRight'"), NULL, LOAD_None, NULL);
	sndFDCAdd							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCAdd.FDCAdd'"), NULL, LOAD_None, NULL);
	sndFDCDrop							= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCDrop.FDCDrop'"), NULL, LOAD_None, NULL);
	sndFDCRecordAsTarget				= LoadObject<USoundBase>(NULL, TEXT("SoundWave'/Game/AmericasArmy/Sounds/S_AA2_SpotterCalls/FDC/FDCRecordAsTarget.FDCRecordAsTarget'"), NULL, LOAD_None, NULL);
	
	sMortarTeamCallSign = "Gunslinger";
	sSpotterCallSign = "Foxtrot One Three";
	//bProp = true;
	//bHidden = true;
}

void AAGP_USMortarTeamFDC::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAGP_USMortarTeamFDC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGP_USMortarTeamFDC::Reset()
{
	//Log("Resetting fire mission FDC");
	iTotalRoundsFired = 0;
	iCurrentMissionStep = 0;
	iRoundsFired = 0;
	bFireMissionInProgress = false;
	bpMortarRoundClass = nullptr;
	//StopCustomTimer("BadCallRadioConfirmationRequest");
	//StopCustomTimer("RadioConfirmationRequest");
	//StopCustomTimer("AcknowledgeExecuteFireMission");
	//StopCustomTimer("FireMissionAimingTimer");
	//StopCustomTimer("CheckFireResponse");
	//StopCustomTimer("FireMissionInAirTimerTube1");
	//StopCustomTimer("FireMissionInAirTimerTube2");
	//StopCustomTimer("CancelFireMissionResponse");
	//StopCustomTimer("EndFireMissionResponse");
	//StopCustomTimer("RadioRepeatMissionConfirmation");
	//StopCustomTimer("RespondToAdjustAim");
	//StopCustomTimer("GridRadioConfirmationRequest");
	//StopCustomTimer("AcknowledgeExecuteFireMission");
	//StopCustomTimer("FireMissionAimingTimer");
	//StopCustomTimer("CheckFireResponse");
	//bFireMissionCanBeRepeated = false;
}

void AAGP_USMortarTeamFDC::StartPolarFireMission(FString sMissionTypeRequest, FString sTargetType_)
{
	float fpDirection = 0;
	bool bGoodFormat = false;
	/*
	if (iCurrentMissionStep == 1 || bFireMissionInProgress)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	fpLeftRight = 0;
	fpFartherCloser = 0;
	Log("Mission Type Request: """ + sMissionTypeRequest + """");
	bGoodFormat = ValidateMissionArguments(sMissionTypeRequest, sTargetType);
	Log("Converted mission type: " + sMissionType);
	ConfigureFireMission(sMissionTypeRequest, sTargetType);
	Log("Found mortar team: " + agpusmtMortarTeam);
	fpDirection = rotTargDirection.Yaw / 65535 * 360;
	if (fpDirection < 0)
	{
		fpDirection += 360;
	}
	fpDirection *= 17.799999;
	iRoundsFired = 0;
	TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", " + sMissionType + " Polar");
	TransmitRadioRequest("Direction " + fpDirection + ", distance " + fpDistanceToTarget / 55 + " ");
	bGridMission = false;
	if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
	{
		TransmitRadioRequest("Target is " + sTargetType + ", Danger Close, At my command, over");
	}
	else
	{
		TransmitRadioRequest("Target is " + sTargetType + ", Area, At my command, over");
	}
	if (!bGoodFormat)
	{
		SetCustomTimer(3 + FMath::FRand() * 1.5, false, 'BadCallRadioConfirmationRequest');
	}
	else
	{
		SetCustomTimer(3 + FMath::FRand() * 1.5, false, 'RadioConfirmationRequest');
	}
	iCurrentMissionStep = 1;
	*/
}

void AAGP_USMortarTeamFDC::StartGridFireMission(FString sMissionTypeRequest, FString sTargetType_)
{
	float fpDirection = 0;
	bool bGoodFormat = false;
	/*
	if (iCurrentMissionStep == 1 || bFireMissionInProgress)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	fpLeftRight = 0;
	fpFartherCloser = 0;
	Log("Mission Type Request: """ + sMissionTypeRequest + """");
	bGoodFormat = ValidateMissionArguments(sMissionTypeRequest, sTargetType);
	Log("Converted mission type: " + sMissionType);
	ConfigureFireMission(sMissionTypeRequest, sTargetType);
	Log("Found mortar team: " + agpusmtMortarTeam + " target type: " + sTargetType + " mission type: " + sMissionType + " mortar type " + bpMortarRoundClass);
	fpDirection = rotTargDirection.Yaw / 65535 * 360;
	if (fpDirection < 0)
	{
		fpDirection += 360;
	}
	fpDirection *= 17.799999;
	iRoundsFired = 0;
	bGridMission = true;
	TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", " + sMissionType + " Grid ");
	TransmitRadioRequest(" " + iGridX + " " + iGridY);
	if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
	{
		TransmitRadioRequest("Target is " + sTargetType + ", Danger Close, At my command, over");
	}
	else
	{
		TransmitRadioRequest("Target is " + sTargetType + ", Area, At my command, over");
	}
	if (!bGoodFormat)
	{
		SetCustomTimer(fpBusyRating * FMath::FRand() * 5 + 3 + FMath::FRand() * 1.5, false, 'BadCallRadioConfirmationRequest');
	}
	else
	{
		SetCustomTimer(fpBusyRating * FMath::FRand() * 5 + 3 + FMath::FRand() * 1.5, false, 'GridRadioConfirmationRequest');
	}
	iCurrentMissionStep = 1;
	*/
}
bool AAGP_USMortarTeamFDC::ValidateMissionArguments(FString sMissionTypeRequest, FString sTargetType_)
{
	/*
	if (sMissionTypeRequest ~= "SMOKE")
	{
		sMissionType = "Immediate Smoke";
	}
	else
	{
		if (sMissionTypeRequest ~= "SUPPRESS")
		{
			sMissionType = "Immediate Suppression";
		}
		else
		{
			if (sMissionTypeRequest ~= "TRAINING")
			{
				sMissionType = "Immediate Suppression Training";
			}
			else
			{
				return false;
			}
		}
	}
	if (!sTargetType ~= "Vehicles" && !sTargetType ~= "Infantry")
	{
		return false;
	}
	*/
	return true;
}
void AAGP_USMortarTeamFDC::ConfigureFireMission(FString sMissionTypeRequest, FString sTargetType_)
{
	AAGP_USMortarTeam* agpusmtIterator = nullptr;
	agpusmtMortarTeam = nullptr;
	bpMortarRoundClass = nullptr;
	/*
	ForEach('AGP_USMortarTeam', agpusmtIterator)
	{
		if (agpusmtIterator.iTeamID != iTeamID)
		{
		}
		else
		{
			if (sMissionTypeRequest ~= "SMOKE")
			{
				bpMortarRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_60mmSmokeMortar", Class'Class'));
				if (agpusmtIterator.iCurrentSmokeRoundsAvailable > 0)
				{
					agpusmtMortarTeam = agpusmtIterator;
					fpBaseReloadTime = 4;
					iMaxRoundsPerMission = agpusmtMortarTeam.iMaxSmokeRoundsPerMission;
					sMissionType = "Immediate Smoke";
				}
				else
				{
				}
			else
			{
				if (sMissionTypeRequest ~= "TRAINING")
				{
					bpMortarRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_60mmTrainingMortar", Class'Class'));
					if (GetNetMode() == ENetMode::NM_Standalone || agpusmtIterator.iCurrentHERoundsAvailable > 0)
					{
						agpusmtMortarTeam = agpusmtIterator;
						fpBaseReloadTime = 8;
						iMaxRoundsPerMission = agpusmtMortarTeam.iMaxHERoundsPerMission;
						sMissionType = "Immediate Suppression Training";
					}
					else
					{
					}
				else
				{
					if (sMissionTypeRequest ~= "SUPPRESS")
					{
						if (sTargetType ~= "Vehicles")
						{
							bpMortarRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_120mmMortar", Class'Class'));
							if (agpusmtIterator.iCurrentVehicleRoundsAvailable > 0)
							{
								agpusmtMortarTeam = agpusmtIterator;
								sMissionType = "Immediate Suppression";
								fpBaseReloadTime = 8;
								iMaxRoundsPerMission = agpusmtMortarTeam.iMaxVehicleRoundsPerMission;
							}
						}
						else
						{
							if (sTargetType ~= "Infantry")
							{
								bpMortarRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_60mmMortar", Class'Class'));
								Log("Infantry fire mission, current HE rounds available: " + agpusmtIterator.iCurrentHERoundsAvailable);
								if (agpusmtIterator.iCurrentHERoundsAvailable > 0)
								{
									agpusmtMortarTeam = agpusmtIterator;
									sMissionType = "Immediate Suppression";
									fpBaseReloadTime = 4;
									iMaxRoundsPerMission = agpusmtMortarTeam.iMaxHERoundsPerMission;
								}
							}
						}
					}
				}
							else
							{
							}
				}
			}
			}
		}
	}
	*/
}

void AAGP_USMortarTeamFDC::TransmitRadioRequest(FString sMsg)
{
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->TeamSay(sMsg);
	}
	else
	{
		Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->ClientMessage(Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->UserName + " radios: " + sMsg);
	}
}

void AAGP_USMortarTeamFDC::TransmitRadioResponse(FString sMsg, bool bTransmitBeep)
{
	APlayerController* pcIterator = nullptr;
	/*
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (bTransmitBeep)
		{
			ForEach DynamicActors(Class'PlayerController', pcIterator)
			{
				if (pcIterator.Pawn != nullptr && pcIterator.Pawn->IsA(AAGP_Pawn::StaticClass()) || Vehicle(pcIterator.Pawn) != nullptr && Vehicle(pcIterator.Pawn).Driver != nullptr && Vehicle(pcIterator.Pawn).Driver->IsA(AAGP_Pawn::StaticClass()))
				{
					CommoHandler(Level.Game.BroadcastHandler).BroadcastLocalized(None, pcIterator, 'CommoEventRadio', 'CommoEventRadio'.Default.MsgStatic, Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo, None, None);
				}
			}
		}
		CommoHandler(Level.Game.BroadcastHandler).BroadcastTeamByIndex(Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo.Team.TeamIndex, sMortarTeamCallSign + " radios: " + sMsg, 'Radio');
	}
	else
	{
		Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->ClientMessage(sMortarTeamCallSign + " radios: " + sMsg);
	}
	*/
}

void AAGP_USMortarTeamFDC::BadCallRadioConfirmationRequest()
{
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ".  Say again, over", true);
	iCurrentMissionStep = 0;
}

void AAGP_USMortarTeamFDC::GridRadioConfirmationRequest()
{
	FString sGunsToUse;
	if (agpusmtMortarTeam == nullptr)
	{
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ".  No assets available, over", true);
		return;
	}
	/*
	TransmitAudioRadioMessage(sndRadioPopIn);
	if (sMissionType ~= "SMOKE")
	{
		TransmitAudioRadioMessage(sndFDCSmokeGrid);
	}
	else
	{
		TransmitAudioRadioMessage(sndFDCSuppressGrid);
	}
	TransmitAudioRadioNumber(iGridX, true);
	TransmitAudioRadioMessage(sndFDCBy);
	TransmitAudioRadioNumber(iGridY, true);
	TransmitAudioRadioMessage(sndPause);
	if (sTargetType ~= "Infantry")
	{
		if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
		{
			TransmitAudioRadioMessage(sndFDCTargetInfantryDangerClose);
		}
		else
		{
			TransmitAudioRadioMessage(sndFDCTargetInfantry);
		}
	}
	else
	{
		if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
		{
			TransmitAudioRadioMessage(sndFDCTargetVehicleDangerClose);
		}
		else
		{
			TransmitAudioRadioMessage(sndFDCTargetVehicle);
		}
	}
	TransmitAudioRadioNumber(iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes, true);
	TransmitAudioRadioMessage(sndFDCRounds);
	TransmitAudioRadioNumber(agpusmtMortarTeam.iNumberOfTubes, true);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + " Roger " + sMissionType + " Grid ", true);
	TransmitRadioResponse("" + iGridX + " " + iGridY);
	sGunsToUse = "" + agpusmtMortarTeam.iNumberOfTubes + " gun";
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		TransmitAudioRadioMessage(sndFDCGuns);
		sGunsToUse = sGunsToUse + "s";
	}
	else
	{
		TransmitAudioRadioMessage(sndFDCGun);
	}
	TransmitAudioRadioMessage(sndFDCAtYourCommand);
	if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
	{
		TransmitRadioResponse("Target is " + sTargetType + ", Danger Close, " + iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes + " rounds, " + sGunsToUse + ",  At your command, over");
	}
	else
	{
		TransmitRadioResponse("Target is " + sTargetType + ", " + iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes + " rounds, Area, " + sGunsToUse + ",  At your command, over");
	}
	TransmitRadioResponse("Ready, Over");
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::RadioConfirmationRequest()
{
	float fpDirection = 0;
	FString sGunsToUse = "";
	USoundBase* sndFDCGunsToUse = nullptr;
	if (agpusmtMortarTeam == nullptr)
	{
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ".  No assets available, over", true);
		return;
	}
	/*
	fpDirection = rotTargDirection.Yaw / 65535 * 360;
	if (fpDirection < 0)
	{
		fpDirection += 360;
	}
	fpDirection *= 17.799999;
	TransmitAudioRadioMessage(sndRadioPopIn);
	if (sMissionType ~= "SMOKE")
	{
		TransmitAudioRadioMessage(sndFDCSmokePolar);
	}
	else
	{
		TransmitAudioRadioMessage(sndFDCSuppressPolar);
	}
	TransmitAudioRadioNumber(fpDirection, true);
	TransmitAudioRadioMessage(sndFDCDistance);
	TransmitAudioRadioNumber(fpDistanceToTarget / 55, true);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + " Roger " + sMissionType + " Polar ", true);
	TransmitRadioResponse("Direction " + fpDirection + ", distance " + fpDistanceToTarget / 55);
	sGunsToUse = "" + agpusmtMortarTeam.iNumberOfTubes + " gun";
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		sGunsToUse = sGunsToUse + "s";
		sndFDCGunsToUse = sndFDCGuns;
	}
	else
	{
		sndFDCGunsToUse = sndFDCGun;
	}
	if (fpDistanceToTarget / 55 < 600 && !bSmokeMission)
	{
		if (sTargetType ~= "Infantry")
		{
			TransmitAudioRadioMessage(sndFDCTargetInfantryDangerClose);
		}
		else
		{
			TransmitAudioRadioMessage(sndFDCTargetVehicleDangerClose);
		}
		TransmitAudioRadioNumber(iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes, true);
		TransmitAudioRadioMessage(sndFDCRounds);
		TransmitAudioRadioNumber(agpusmtMortarTeam.iNumberOfTubes, true);
		TransmitAudioRadioMessage(sndFDCGunsToUse);
		TransmitAudioRadioMessage(sndFDCAtYourCommand);
		TransmitRadioResponse("Target is " + sTargetType + ", Danger Close, " + iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes + " rounds, " + sGunsToUse + ",  At your command, over");
	}
	else
	{
		if (sTargetType ~= "Infantry")
		{
			TransmitAudioRadioMessage(sndFDCTargetInfantry);
		}
		else
		{
			TransmitAudioRadioMessage(sndFDCTargetVehicle);
		}
		TransmitAudioRadioNumber(iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes, true);
		TransmitAudioRadioMessage(sndFDCRounds);
		TransmitAudioRadioNumber(agpusmtMortarTeam.iNumberOfTubes, true);
		TransmitAudioRadioMessage(sndFDCGunsToUse);
		TransmitAudioRadioMessage(sndFDCAtYourCommand);
		TransmitRadioResponse("Target is " + sTargetType + ", " + iMaxRoundsPerMission / agpusmtMortarTeam.iNumberOfTubes + " rounds, Area, " + sGunsToUse + ",  At your command, over");
	}
	TransmitAudioRadioMessage(sndRadioPopOut);
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::ExecuteAttack()
{
	float fpTimeToFire = 0;
	/*
	if (iCurrentMissionStep == 1 || bFireMissionInProgress)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	bFireMissionInProgress = true;
	fpTimeToFire = 5 + 3 * FMath::FRand();
	TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", Fire, over");
	SetCustomTimer(fpTimeToFire, false, 'AcknowledgeExecuteFireMission');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::AcknowledgeExecuteFireMission()
{
	/*
	TransmitAudioRadioMessage(sndRadioPopIn);
	if (bGridMission)
	{
		TransmitAudioRadioMessage(sndFDCGridFiring);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + " Roger " + sMissionType + " Grid Firing, over", true);
	}
	else
	{
		TransmitAudioRadioMessage(sndFDCPolarFiring);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + " Roger " + sMissionType + " Polar Firing, over", true);
	}
	TransmitAudioRadioMessage(sndRadioPopOut);
	SetCustomTimer(FMath::FRand() + 2.5, false, 'FireMissionAimingTimer');
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::CheckFire(bool bDisableFOAudio)
{
	/*
	if (iCurrentMissionStep == 1)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	if (!bDisableFOAudio)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndRadioPopOut);
	}
	if (!bDisableFOAudio)
	{
		TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", Check Fire, Check Fire, over");
	}
	bFireMissionInProgress = false;
	bFireMissionCanBeRepeated = true;
	SetCustomTimer(1.5 + FMath::FRand(), false, 'CheckFireResponse');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::CheckFireResponse()
{
	/*
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndFDCCheckedFire);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Checked Fire, over", true);
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::FireMissionAimingTimer()
{
	float fpAimDelay = 0;
	/*
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndFDCFireMissionOnWay);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission on the way, zero guns, over", true);
	fpAimDelay = 5 + 10 * FMath::FRand();
	SetCustomTimer(fpAimDelay, false, 'FireMissionInAirTimerTube1');
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		SetCustomTimer(fpAimDelay + 2.25, false, 'FireMissionInAirTimerTube2');
	}
	*/
}
void AAGP_USMortarTeamFDC::CancelFireMission()
{
	/*
	if (iCurrentMissionStep == 1)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", Cancel at my command, over");
	SetCustomTimer(2 + 4 * FMath::FRand(), false, 'CancelFireMissionResponse');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::CancelFireMissionResponse()
{
	FString sGunsAvailable = "";
	/*
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		sGunsAvailable = "guns";
	}
	else
	{
		sGunsAvailable = "gun";
	}
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission cancelled, " + agpusmtMortarTeam.iNumberOfTubes @ sGunsAvailable + ", over", true);
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::EndFireMission()
{
	/*
	if (iCurrentMissionStep == 1)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	TransmitRadioRequest(sMortarTeamCallSign + ", This is " + sFOName + ", record as target, end of mission, target suppressed, over.");
	SetCustomTimer(2 + 4 * FMath::FRand(), false, 'EndFireMissionResponse');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::EndFireMissionResponse()
{
	FString sGunsAvailable = "";
	/*
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		sGunsAvailable = "guns";
	}
	else
	{
		sGunsAvailable = "gun";
	}
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioRequest(sFOName + ", This is " + sMortarTeamCallSign + ", roger record as target, end of mission, target suppressed, over.");
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::FireMissionInAirTimerTube1()
{
	/*
	if (!bFireMissionInProgress)
	{
		return;
	}
	if (bGridMission)
	{
		LaunchGridRound();
	}
	else
	{
		LaunchRound();
	}
	if (bpMortarRoundClass->IsA(AProj_60mmSmokeMortar::StaticClass()) && agpusmtMortarTeam.iCurrentSmokeRoundsAvailable <= 0)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCFireMissionCompleteNoRounds);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission complete, No Rounds Remaining, over", true);
		iCurrentMissionStep = 0;
		bFireMissionInProgress = false;
		bFireMissionCanBeRepeated = false;
		return;
	}
	else
	{
		if (bpMortarRoundClass->IsA(AProj_60mmMortar::StaticClass()) || bpMortarRoundClass->IsA(AProj_60mmTrainingMortar::StaticClass()) && agpusmtMortarTeam.iCurrentHERoundsAvailable <= 0)
		{
			TransmitAudioRadioMessage(sndRadioPopIn);
			TransmitAudioRadioMessage(sndFDCFireMissionCompleteNoRounds);
			TransmitAudioRadioMessage(sndRadioPopOut);
			TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission complete, No Rounds Remaining, over", true);
			iCurrentMissionStep = 0;
			bFireMissionInProgress = false;
			bFireMissionCanBeRepeated = false;
			return;
		}
		else
		{
			if (bpMortarRoundClass->IsA(AProj_120mmMortar::StaticClass()) && agpusmtMortarTeam.iCurrentVehicleRoundsAvailable <= 0)
			{
				TransmitAudioRadioMessage(sndRadioPopIn);
				TransmitAudioRadioMessage(sndFDCFireMissionCompleteNoRounds);
				TransmitAudioRadioMessage(sndRadioPopOut);
				TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission complete, No Rounds Remaining, over", true);
				iCurrentMissionStep = 0;
				bFireMissionInProgress = false;
				bFireMissionCanBeRepeated = false;
				return;
			}
		}
	}
	if (iRoundsFired++ < iMaxRoundsPerMission && bFireMissionInProgress)
	{
		SetCustomTimer(5.25 + 1 * FMath::FRand(), false, 'FireMissionInAirTimerTube1');
	}
	else
	{
		bFireMissionInProgress = false;
		bFireMissionCanBeRepeated = true;
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCFireMissionComplete);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", fire mission complete, over.", true);
		iCurrentMissionStep = 0;
	}
	*/
}
void AAGP_USMortarTeamFDC::FireMissionInAirTimerTube2()
{
	/*
	if (!bFireMissionInProgress)
	{
		return;
	}
	if (bGridMission)
	{
		LaunchGridRound();
	}
	else
	{
		LaunchRound();
	}
	if (iRoundsFired++ < iMaxRoundsPerMission && bFireMissionInProgress)
	{
		SetCustomTimer(5.25 + 1 * FMath::FRand(), false, 'FireMissionInAirTimerTube2');
	}
	*/
}
void AAGP_USMortarTeamFDC::RepeatMission()
{
	/*
	if (!bFireMissionCanBeRepeated)
	{
		return;
	}
	if (iCurrentMissionStep == 1)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	TransmitRadioRequest(sMortarTeamCallSign + ", this is " + sFOName + ", Repeat, over.");
	SetCustomTimer(1.5 + 1.5 * FMath::FRand(), false, 'RadioRepeatMissionConfirmation');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::RadioRepeatMissionConfirmation()
{
	float fpAimDelay = 0;
	/*
	fpAimDelay = 5 + 2.5 * FMath::FRand();
	bFireMissionInProgress = true;
	iRoundsFired = 0;
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndFDCRepeat);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Roger Repeat, over", true);
	SetCustomTimer(fpAimDelay, false, 'FireMissionInAirTimerTube1');
	if (agpusmtMortarTeam.iNumberOfTubes > 1)
	{
		SetCustomTimer(fpAimDelay + 2.25, false, 'FireMissionInAirTimerTube2');
	}
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::AdjustFireMissionAim(FString sAdjustCmd, int32 iLeftRightMeters, int32 iFowardBackMeters)
{
	/*
	if (iCurrentMissionStep == 1)
	{
		TransmitAudioRadioMessage(sndRadioPopIn);
		TransmitAudioRadioMessage(sndFDCStandby);
		TransmitAudioRadioMessage(sndRadioPopOut);
		TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Stand By, over");
		return;
	}
	sLastAdjustCommand = sAdjustCmd;
	fpFartherCloser += iFowardBackMeters * 55;
	fpLeftRight += iLeftRightMeters * 55;
	if (iLeftRightMeters != 0)
	{
		iLastAdjustAmount = iLeftRightMeters;
	}
	else
	{
		iLastAdjustAmount = iFowardBackMeters;
	}
	if (iLastAdjustAmount < 0)
	{
		iLastAdjustAmount *= -1;
	}
	TransmitRadioRequest(sMortarTeamCallSign + "This is " + sFOName + " Adjust Fire " + sLastAdjustCommand + " " + iLastAdjustAmount + ", over");
	SetCustomTimer(FMath::FRand() * 2 + 1.5, false, 'RespondToAdjustAim');
	iCurrentMissionStep = 1;
	*/
}
void AAGP_USMortarTeamFDC::RespondToAdjustAim()
{
	/*
	TransmitAudioRadioMessage(sndRadioPopIn);
	TransmitAudioRadioMessage(sndFDCAdjustFire);
	if (sLastAdjustCommand ~= "LEFT")
	{
		TransmitAudioRadioMessage(sndFDCLeft);
	}
	else
	{
		if (sLastAdjustCommand ~= "RIGHT")
		{
			TransmitAudioRadioMessage(sndFDCRight);
		}
		else
		{
			if (sLastAdjustCommand ~= "ADD")
			{
				TransmitAudioRadioMessage(sndFDCAdd);
			}
			else
			{
				if (sLastAdjustCommand ~= "DROP")
				{
					TransmitAudioRadioMessage(sndFDCDrop);
				}
			}
		}
	}
	TransmitAudioRadioNumber(iLastAdjustAmount, true);
	TransmitAudioRadioMessage(sndFDCMeters);
	TransmitAudioRadioMessage(sndFDCOver);
	TransmitAudioRadioMessage(sndRadioPopOut);
	TransmitRadioResponse(sFOName + ", this is " + sMortarTeamCallSign + ", Roger Adjust Fire " + sLastAdjustCommand + " " + iLastAdjustAmount + ", over", true);
	iCurrentMissionStep = 0;
	*/
}
void AAGP_USMortarTeamFDC::LaunchGridRound()
{
	ABaseProjectile* bpMortarRound = nullptr;
	FVector vTarget = FVector(0,0,0);
	FVector vShiftOffset = FVector(0, 0, 0);
	/*
	vTarget = vTargetArea;
	vShiftOffset.X = fpLeftRight;
	vShiftOffset.Y = fpFartherCloser;
	Log("Original location: " + vTarget.X + "," + vTarget.Y + "," + vTarget.Z);
	Log("Shift Offset vector: " + vShiftOffset.X + "," + vShiftOffset.Y + "," + vShiftOffset.Z);
	vShiftOffset.Y *= -1;
	vTarget += vShiftOffset;
	if (FMath::FRand() >= 0.5)
	{
		vTarget.X += 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	else
	{
		vTarget.X -= 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	if (FMath::FRand() >= 0.5)
	{
		vTarget.Y += 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	else
	{
		vTarget.Y -= 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	vTarget.Z += 2250;
	Log("Shifted/Randomized location: " + vTarget.X + "," + vTarget.Y + "," + vTarget.Z + ", distance delta: " + VSize(vTarget - vTargetArea));
	if (bpMortarRoundClass->IsA(AProj_60mmSmokeMortar::StaticClass()))
	{
		agpusmtMortarTeam.iCurrentSmokeRoundsAvailable--;
	}
	else
	{
		if (bpMortarRoundClass->IsA(AProj_120mmMortar::StaticClass()))
		{
			agpusmtMortarTeam.iCurrentVehicleRoundsAvailable--;
		}
		else
		{
			if (GetNetMode() != ENetMode::NM_Standalone)
			{
				agpusmtMortarTeam.iCurrentHERoundsAvailable--;
			}
		}
	}
	bpMortarRound = Spawn(bpMortarRoundClass, Owner, , vTarget, FVector(0 0 - 1));
	iTotalRoundsFired++;
	if (Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo.Team != nullptr)
	{
		bpMortarRound.idTeamOwner = Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		bpMortarRound.idTeamOwner = 0;
	}
	bpMortarRound.Instigator = Cast<APawn>(GetOwner());
	bpMortarRound.InstigatorController = Cast<AAGP_Pawn>(GetOwner())->Controller;
	*/
}
void AAGP_USMortarTeamFDC::LaunchRound()
{
	float fpRange = 0;
	FRotator rotAimDirection = FRotator(0,0,0);
	FRotator rotRightAngle = FRotator(0, 0, 0);
	ABaseProjectile* bpMortarRound = nullptr;
	FVector vTarget = FVector(0, 0, 0);
	FVector VOffset = FVector(0, 0, 0);
	FVector vShiftOffset = FVector(0,0,0);
	fpRange = fpDistanceToTarget;
	if (FMath::FRand() > 0.5)
	{
		fpRange += FMath::FRand() * 1000;
	}
	else
	{
		fpRange -= FMath::FRand() * 1000;
	}
	/*
	rotAimDirection = rotTargDirection;
	rotAimDirection.Pitch = 0;
	rotAimDirection.Roll = 0;
	rotRightAngle = rotAimDirection;
	if (fpLeftRight > 0)
	{
		rotRightAngle.Yaw += 16384;
		if (rotRightAngle.Yaw > 65535)
		{
			rotRightAngle.Yaw -= 65535;
		}
	}
	else
	{
		rotRightAngle.Yaw -= 16384;
		if (rotRightAngle.Yaw < 0)
		{
			rotRightAngle.Yaw += 65535;
		}
	}
	if (rotRightAngle.Yaw > 65535)
	{
		rotRightAngle.Yaw -= 65535;
	}
	Log("Aiming direction: " + rotAimDirection.Yaw + " Right angle " + rotRightAngle.Yaw);
	VOffset = FVector(1, 0, 0) << rotAimDirection * fpRange + fpFartherCloser;
	VOffset.Y *= -1;
	Log("Rotation for targeting (Y/P/R): " + rotAimDirection.Yaw + "," + rotAimDirection.Pitch + "," + rotAimDirection.Roll);
	Log("Offset vector: " + VOffset.X + "," + VOffset.Y + "," + VOffset.Z);
	vShiftOffset = FVector(1, 0, 0) << rotRightAngle * Abs(fpLeftRight);
	Log("Shift Offset vector: " + vShiftOffset.X + "," + vShiftOffset.Y + "," + vShiftOffset.Z);
	vTarget = vSpotterLocation + VOffset + vShiftOffset;
	if (FMath::FRand() >= 0.5)
	{
		vTarget.X += 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	else
	{
		vTarget.X -= 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	if (FMath::FRand() >= 0.5)
	{
		vTarget.Y += 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	else
	{
		vTarget.Y -= 1 - agpusmtMortarTeam.fpSkillLevel / 100 * 50 + FMath::FRand() * 3750;
	}
	vTarget.Z += 2250;
	Log("Pawn Location: " + Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->Pawn.Location.X + "," + Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->Pawn.Location.Y + ", " + Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->Pawn.Location.Z + "  Mortar spawn location: " + vTarget.X + "," + vTarget.Y + "," + vTarget.Z);
	if (bpMortarRoundClass->IsA(AProj_60mmSmokeMortar::StaticClass()))
	{
		agpusmtMortarTeam.iCurrentSmokeRoundsAvailable--;
	}
	else
	{
		if (bpMortarRoundClass->IsA(AProj_120mmMortar::StaticClass()))
		{
			agpusmtMortarTeam.iCurrentVehicleRoundsAvailable--;
		}
		else
		{
			if (GetNetMode() != ENetMode::NM_Standalone)
			{
				agpusmtMortarTeam.iCurrentHERoundsAvailable--;
			}
		}
	}
	bpMortarRound = Spawn(bpMortarRoundClass, Owner, , vTarget, FVector(0 0 - 1));
	iTotalRoundsFired++;
	if (Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo.Team != nullptr)
	{
		bpMortarRound.idTeamOwner = Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->PlayerReplicationInfo.Team.TeamIndex;
	}
	bpMortarRound.Instigator = Cast<APawn>(GetOwner());
	bpMortarRound.InstigatorController = Cast<AAGP_Pawn>(GetOwner())->Controller;
	*/
}
void AAGP_USMortarTeamFDC::PlayNextQueuedSoundTimer()
{
	/*
	if (asndQueue.Num() > 0)
	{
		asndQueue.RemoveAt(0, 1);
	}
	if (asndQueue.Num() > 0)
	{
		Log("Playing queued sound: " + asndQueue[0]);
		PlayAudioRadioMessage(asndQueue[0]);
	}
	*/
}
void AAGP_USMortarTeamFDC::TransmitAudioRadioMessage(USoundBase* sndAudioMessage)
{
	/*
	asndQueue.insert(asndQueue.Num(), 1);
	asndQueue[asndQueue.Num() - 1] = sndAudioMessage;
	if (asndQueue.Num() > 1)
	{
		Log("Added sound " + sndAudioMessage + " to queue");
		return;
	}
	PlayAudioRadioMessage(asndQueue[0]);
	*/
}

void AAGP_USMortarTeamFDC::PlayAudioRadioMessage(USoundBase* sndAudioMessage)
{
	/*
	Cast<AHumanController>(Cast<AAGP_Pawn>(GetOwner())->Controller)->ClientPlaySound(sndAudioMessage);
	Log("Will play audio next at " + GetSoundDuration(sndAudioMessage));
	SetCustomTimer(GetSoundDuration(sndAudioMessage), false, 'PlayNextQueuedSoundTimer');
	*/
}

void AAGP_USMortarTeamFDC::TransmitAudioRadioNumber(int32 iNumber, bool bFDCNumber)
{
	FString sNumber = "";
	int32 iDigit = 0;
	int32 iDigitIndex = 0;
	sNumber = FString::FromInt(iNumber);
	/*
	for (iDigit = 0; iDigit < Len(sNumber); iDigit++)
	{
		iDigitIndex = Mid(sNumber, iDigit, 1);
		if (bFDCNumber)
		{
			TransmitAudioRadioMessage(asndFDCNumbers[iDigitIndex]);
		}
		else
		{
			TransmitAudioRadioMessage(asndFONumbers[iDigitIndex]);
		}
	}
	*/
}

