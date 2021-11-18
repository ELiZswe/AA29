// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV_PlanB/CROWS_HMMWV_PlanB.h"

ACROWS_HMMWV_PlanB::ACROWS_HMMWV_PlanB()
{
	CameraBone = "CameraBone";
	WheelSoftness = 0.02;
	WheelPenScale = 1.2;
	WheelPenOffset = 0.01;
	WheelInertia = 0.1;
	//	\\WheelLongFrictionFunc = ;
	WheelLongSlip = 0.001;
	//	\\WheelLatSlipFunc = ;
	WheelLongFrictionScale = 1.1;
	WheelLatFrictionScale = 1.35;
	WheelHandbrakeSlip = 0.01;
	WheelHandbrakeFriction = 0.1;
	WheelSuspensionTravel = 8;
	WheelSuspensionOffset = -3;
	WheelSuspensionMaxRenderTravel = 7;
	FTScale = 0.03;
	ChassisTorqueScale = 0.4;
	MinBrakeFriction = 4;
	//	\\MaxSteerAngleCurve = ;
	//	\\TorqueCurve = ;

	GearRatios = { -0.49, 0.41, 0.67, 1.06, 2 };

	TransRatio = 0.15;
	ChangeUpPoint = 3400;
	ChangeDownPoint = 1000;
	LSDFactor = 1;
	EngineBrakeFactor = 0.0001;
	EngineBrakeRPMScale = 0.1;
	MaxBrakeTorque = 150;
	SteerSpeed = 160;
	TurnDamping = 35;
	StopThreshold = 100;
	HandbrakeThresh = 4000;
	EngineInertia = 0.1;
	IdleRPM = 500;
	EngineRPMSoundRange = 9000;
	SteerBoneName = "B_SteeringWheel";
	//SteerBoneAxis = 2;
	SteerBoneMaxAngle = -90;
	RevMeterScale = 4000;
	bMakeBrakeLights = true;
	BrakeLightOffset = { FVector(-100, 23, 7), FVector(-100, -23, 7) };
	//AirTurnTorque = 35;
	bAllowCOMAdjust = true;
	COMAdjustScale = 0.00032;
	//	\\PositionTypes = ;
	//Min = 99;
	StartUpForce = "PRVStartUp";
	ShutDownForce = "PRVShutDown";
	DamagedEffectScale = 1;
	DamagedEffectOffset = FVector(60, 10, 10);
	//	\\HeadlightCoronaOffset = ;
	//Max = 65;
	HeadlightProjectorOffset = FVector(90, 0, 7);
	//HeadlightProjectorRotation = (Pitch = -1000, Yaw = 0, Roll = 0);
	HeadlightProjectorScale = 0.3;
	//	\\Wheels = ;
	//DamageBones = 5;
	//bDrawDriverInTP = true;
	//bDrawMeshInFP = true;
	//bHasHandbrake = true;
	//DriverBone = "B_Sitbone_LF";
	//DrivePos = (X = 2, Y = 0, Z = 48);
	//DriveAnim = "vehhmvdrv";
	//DriverPosOffset = (X = 0, Y = 0, Z = 8);
	//ExitPositions(0) = (X = 0, Y = -165, Z = 100);
	//ExitPositions(1) = (X = 0, Y = 165, Z = 100);
	//ExitPositions(2) = (X = 0, Y = -165, Z = -100);
	//ExitPositions(3) = (X = 0, Y = 165, Z = -100);
	//EntryRadius = 160;
	//DriverDamageMult = 0.8;
	//VehiclePositionString = "in a HMMWV";
	//VehicleNameString = "HMMWV";
	//MaxDesireability = 0.4;
	//ObjectiveGetOutDist = 1500;
	//GroundSpeed = 940;
	//HealthMax = 300;
	//Health = 300;
	//bReplicateAnimations = true;
	//Mesh = SkeletalMesh'A_AAO_Vehicles.HMMWV1114_test1_whole';
	//DrawScale = 1.13;
	//SoundVolume = 180;
	//CollisionRadius = 100;
	//CollisionHeight = 40;
	//KParams = KarmaParamsRBFull'AGP_Vehicles.CROWS_HMMWV_PlanB.KParams0';
}


void ACROWS_HMMWV_PlanB::PostNetBeginPlay()
{
	Super::PostNetBeginPlay();
	FixBoneRotations();
	//ActiveWeapon = Default.ActiveWeapon;
}

void ACROWS_HMMWV_PlanB::FixBoneRotations()
{
	/*
	local int32 i;
	SetBoneRotation(DriverBone, rot(0 - 16384 16384), 0, 1);
	for (i = 0; i < PositionTypes.Length; i++)
	{
		SetBoneRotation(PositionTypes[i].PositionBone, rot(0 - 16384 16384), 0, 1);
	}
	*/
}

void ACROWS_HMMWV_PlanB::ClientKDriverEnter(APlayerController* PC)
{
	Super::ClientKDriverEnter(PC);
	/*
	if (PC != None)
	{
		PC.SetViewTarget(Self);
	}
	PC.bBehindView = true;
	*/
}

void ACROWS_HMMWV_PlanB::ClientKDriverLeave(APlayerController* PC)
{
	Super::ClientKDriverLeave(PC);
	/*
	if (PC != None && PC.ViewTarget == Self)
	{
		PC.SetViewTarget(Driver);
	}
	*/
}

void ACROWS_HMMWV_PlanB::FindEntryVehicle(APawn* p)
{
	//return Self;
}

bool ACROWS_HMMWV_PlanB::UsedBy(APawn* User)
{
	return true;
}

void ACROWS_HMMWV_PlanB::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	if (Driver != None)
	{
		Driver.bOwnerNoSee = true;
	}
	ViewActor = Driver;
	CameraLocation = Driver.GetBoneCoords(CameraBone).Origin;
	CameraRotation = Driver.GetBoneRotation(CameraBone);
	CameraRotation = PC.Rotation;
	*/
}

bool ACROWS_HMMWV_PlanB::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC == None || PC.ViewTarget != Self)
	{
		return false;
	}
	PC.bBehindView = false;
	SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
	LastCameraCalcTime = Level.TimeSeconds;
	*/
	return true;
}

void ACROWS_HMMWV_PlanB::Seatbelt()
{
	bDriverWearingSeatbelt = true;
}

void ACROWS_HMMWV_PlanB::ShiftDriveGears()
{
}

void ACROWS_HMMWV_PlanB::ShiftHiLoGears()
{
}

void ACROWS_HMMWV_PlanB::LookRearViewLeft()
{
}

void ACROWS_HMMWV_PlanB::LookRearViewRight()
{
}

void ACROWS_HMMWV_PlanB::Horn()
{
}

void ACROWS_HMMWV_PlanB::ToggleCalcView()
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	bSpecialCalcView = !bSpecialCalcView;
	PC.bBehindView = true;
	*/
}

void ACROWS_HMMWV_PlanB::CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale)
{
	/*
	local Object.Vector X;
	local Object.Vector Y;
	local Object.Vector Z;
	GetAxes(Rotation, X, Y, Z);
	if (Driver != None && Driver.IsHeadShot(loc, ray, AdditionalScale))
	{
		Return Driver;
	}
	Return None;
	*/
}

void ACROWS_HMMWV_PlanB::SetActiveWeapon(int32 i)
{
}
/*
void ACROWS_HMMWV_PlanB::StaticPrecache(LevelInfo L)
{
	Super::StaticPrecache(L);
}
*/
void ACROWS_HMMWV_PlanB::UpdatePrecacheStaticMeshes()
{
	Super::UpdatePrecacheStaticMeshes();
}

void ACROWS_HMMWV_PlanB::UpdatePrecacheMaterials()
{
	Super::UpdatePrecacheMaterials();
}

void ACROWS_HMMWV_PlanB::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	local int32 i;
	DisplayVehicleDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Stopwatch: " $ StopwatchTime);
	YPos += YL;
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Gear: " $ Gear $ "    CarMPH: " $ CarMPH);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineRPM: " $ EngineRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("IdleRPM: " $ IdleRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineInertia: " $ EngineInertia);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText(DebugInfo);
	YPos += YL;
	Canvas.SetDrawColor(0, 255, 0);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("-------------Wheels-------------:");
	YPos += YL;
	for (i = 0; i < Wheels.Length; i++)
	{
		Canvas.SetPos(0, YPos);
		Canvas.DrawText(Wheels[i].Name);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("SpinVel: " $ Wheels[i].SpinVel);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("DriveForce: " $ Wheels[i].DriveForce);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("LongSlip: " $ Wheels[i].LongSlip);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("LatSlip: " $ Wheels[i].LatSlip);
		YPos += YL;
	}
	*/
}
/*
void ACROWS_HMMWV_PlanB::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	DisplayVehicleDebug(Canvas, YL, YPos);
}
*/