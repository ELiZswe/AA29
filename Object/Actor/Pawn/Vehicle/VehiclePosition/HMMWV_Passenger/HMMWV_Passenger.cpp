// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"

AHMMWV_Passenger::AHMMWV_Passenger()
{
	//AnimManagerClass = class'AGP_Vehicles.HMMWVPassengerAnimManager';
	//SeatBeltOnMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_R_on';
	//SeatBeltOffMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_R_off';
	CameraBone = "CameraBone";
	bPCRelativeFPRotation = false;
	DriverBone = "B_Sitbone_LF";
	DriveAnim = "IdleSeated";
	bPlayDrivingAnimations = false;
	bCustomAttach = true;
	DriverPosOffset = FVector(0, 0, 20);
	//SeatbeltSound = Sound'S_AAO_Vehicles.HMMWV.S_vehi_HMMWV_Seatbelt';
	//LandMovementState = "PlayerDriving";
	//iTraceDistance = 512;
	//iShortTraceDistance = 512;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
}


void AHMMWV_Passenger::PostBeginPlay()
{
	/*
	PostBeginPlay();
	AnimManager = Spawn(AnimManagerClass);
	HMMWVAnimManager(AnimManager).Vehicle = Self;
	SetCustomTimer(0.5, False, 'MakeMeASeatbelt');
	*/
}

void AHMMWV_Passenger::MakeMeASeatbelt()
{
	/*
	local Actor AttachActor;
	local name AttachBone;
	Seatbelt = Spawn(Class'BodyPanel');
	Seatbelt.SetDrawType(8);
	Seatbelt.SetStaticMesh(SeatBeltOffMesh);
	Seatbelt.SetOwner(Self);
	GetDriverAttachmentBone(AttachActor, AttachBone);
	AttachActor.AttachToBone(Seatbelt, AttachBone);
	Seatbelt.RelRotation = rot(0 - 16384 0);
	Seatbelt.SetRelativeRotation(rot(0 - 16384 0));
	*/
}

void AHMMWV_Passenger::Destroyed()
{
	/*
	Destroyed();
	if (AnimManager != None)
	{
		AnimManager.Destroy();
	}
	if (Role == 4 && Seatbelt != None)
	{
		Seatbelt.Destroy();
	}
	*/
}
void AHMMWV_Passenger::LeanLeft(bool bFullLeft)
{
}

void AHMMWV_Passenger::LeanRight(bool bFullRight)
{
}

void AHMMWV_Passenger::KDriverEnter(APawn* p)
{
	/*
	p.bSetPCRotOnPossess = False;
	KDriverEnter(p);
	HMMWVAnimManager(AnimManager).BindToPawn(p);
	*/
}

void AHMMWV_Passenger::KDriverLeave(bool bForceLeave)
{
	/*
	HMMWVAnimManager(AnimManager).ReleasePawn();
	Return KDriverLeave(bForceLeave);
	*/
}
void AHMMWV_Passenger::SetDriverHiddenAttachments()
{
	/*
	if (Driver != None)
	{
		Driver.HiddenAttachmentClasses[0] = Class'Attch_MedicRuck';
		Driver.HiddenAttachmentClasses[1] = Class'WeaponAttachment';
		Driver.HiddenAttachmentClasses[2] = Class'Attch_ParaRuck';
		Driver.HiddenAttachmentClasses[3] = Class'Attch_RuckSackChute';
		Driver.HiddenAttachmentClasses[4] = Class'Attch_RPGBackpack';
		Driver.HiddenAttachmentClasses[5] = Class'Attch_ReserveChute';
		Driver.HiddenAttachmentClasses[6] = Class'Attch_Parachute';
		Driver.HiddenAttachmentClasses[7] = class<ItemAttachment>(DynamicLoadObject("AGP_Armory.Attch_CLUpack", Class'Class'));
	}
	*/
}

void AHMMWV_Passenger::ServerSetSeatbelt()
{
	//Seatbelt.SetStaticMesh(SeatBeltOnMesh);
	//ServerSetSeatbelt();
}

void AHMMWV_Passenger::ServerRemoveSeatbelt()
{
	//Seatbelt.SetStaticMesh(SeatBeltOffMesh);
	//ServerRemoveSeatbelt();
}

void AHMMWV_Passenger::SpecialCalcFirstPersonView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Quat FowardLookQuat;
	local Object.Quat ControllerLookQuat;
	local Object.Vector TmpCameraLocation;
	local Object.Rotator TmpCameraRotation;
	local AGP.HumanController HC;
	if (CROWS_HMMWV(VehicleBase) != None)
	{
		CROWS_HMMWV(VehicleBase).UpdateAttachedActorLocations();
	}
	HC = HumanController(PC);
	if (Driver == None)
	{
		Return;
	}
	Driver.bOwnerNoSee = true;
	ViewActor = Driver;
	TmpCameraLocation = Driver.GetBoneCoords(CameraBone).Origin;
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(rot(16384 16384 0)), FowardLookQuat);
	if (PC.bTrackIREnabled)
	{
		PC.SetRotation(PC.Rotation + MakeRot(-PC.fpTrackIRPitch - PC.fpTrackIRLastPitch, -PC.fpTrackIRYaw - PC.fpTrackIRLastYaw, 0));
	}
	ControllerLookQuat = QuatFromRotator(PC.Rotation);
	TmpCameraRotation = QuatToRotator(QuatProduct(ControllerLookQuat, FowardLookQuat));
	CameraLocation = TmpCameraLocation;
	CameraRotation = TmpCameraRotation;
	HC.LastViewLocation = CameraLocation;
	HC.LastViewRotation = CameraRotation;
	*/
}

void AHMMWV_Passenger::SpecialSetFirstPersonViewRotation(APlayerController* PC, FRotator CameraRotation)
{
	/*
	local Object.Quat FowardLookQuat;
	local Object.Quat ControllerLookQuat;
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(rot(16384 16384 0)), FowardLookQuat);
	ControllerLookQuat = QuatProduct(QuatFromRotator(CameraRotation), QuatInvert(FowardLookQuat));
	PC.SetRotation(QuatToRotator(ControllerLookQuat));
	*/
}

bool AHMMWV_Passenger::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC == None || PC.ViewTarget != Self)
	{
		Return False;
	}
	PC.bBehindView = False;
	Driver.Velocity = vect(0 0 0);
	SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
	LastCameraCalcTime = Level.TimeSeconds;
	*/

	return true;
}