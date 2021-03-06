// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"
#include "AA29/Object/Actor/AnimManager/AnimManager.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_MedicRuck/Attch_MedicRuck.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ParaRuck/Attch_ParaRuck.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ReserveChute/Attch_ReserveChute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_RPGBackpack/Attch_RPGBackpack.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_RuckSackChute/Attch_RuckSackChute.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVPassengerAnimManager/HMMWVPassengerAnimManager.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"

AHMMWV_Passenger::AHMMWV_Passenger()
{
	//AnimManagerClass = AHMMWVPassengerAnimManager::StaticClass();
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
	Super::PostBeginPlay();
	AnimManager=Spawn(AnimManagerClass);
	HMMWVAnimManager(AnimManager).Vehicle=Self;
	SetCustomTimer(0.5,false,"MakeMeASeatbelt");
	*/
}

void AHMMWV_Passenger::MakeMeASeatbelt()
{
	AActor* AttachActor = nullptr;
	FName AttachBone = "";
	/*
	Seatbelt=Spawn(ABodyPanel::StaticClass());
	Seatbelt.SetDrawType(DT_StaticMesh);
	Seatbelt.SetStaticMesh(SeatBeltOffMesh);
	Seatbelt.SetOwner(this);
	GetDriverAttachmentBone(AttachActor,AttachBone);
	AttachActor.AttachToBone(Seatbelt,AttachBone);
	Seatbelt.RelRotation=FRotator(0,-16384,0);
	Seatbelt.SetRelativeRotation(FRotator(0,-16384,0));
	*/
}

void AHMMWV_Passenger::Destroyed()
{
	/*
	Super::Destroyed();
	if (AnimManager != nullptr)
	{
		AnimManager.Destroy();
	}
	if ((GetRemoteRole() == ENetRole::ROLE_MAX) && (Seatbelt != nullptr))
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
	p.bSetPCRotOnPossess = false;
	KDriverEnter(p);
	HMMWVAnimManager(AnimManager).BindToPawn(p);
	*/
}

bool AHMMWV_Passenger::KDriverLeave(bool bForceLeave)
{
	Cast<AHMMWVAnimManager>(AnimManager)->ReleasePawn();
	return Super::KDriverLeave(bForceLeave);
}

void AHMMWV_Passenger::SetDriverHiddenAttachments()
{
	/*
	if (Driver != nullptr)
	{
		Driver.HiddenAttachmentClasses[0] = AAttch_MedicRuck::StaticClass();
		Driver.HiddenAttachmentClasses[1] = AWeaponAttachment::StaticClass();
		Driver.HiddenAttachmentClasses[2] = AAttch_ParaRuck::StaticClass();
		Driver.HiddenAttachmentClasses[3] = AAttch_RuckSackChute::StaticClass();
		Driver.HiddenAttachmentClasses[4] = AAttch_RPGBackpack::StaticClass();
		Driver.HiddenAttachmentClasses[5] = AAttch_ReserveChute::StaticClass();
		Driver.HiddenAttachmentClasses[6] = AAttch_Parachute::StaticClass();
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
	FQuat FowardLookQuat = FQuat(0, 0, 0,0);
	FQuat ControllerLookQuat = FQuat(0, 0, 0,0);
	FVector TmpCameraLocation = FVector(0,0,0);
	FRotator TmpCameraRotation = FRotator(0,0,0);
	AHumanController* HC = nullptr;
	if (Cast<ACROWS_HMMWV>(VehicleBase) != nullptr)
	{
		Cast<ACROWS_HMMWV>(VehicleBase)->UpdateAttachedActorLocations();
	}
	HC = Cast<AHumanController>(PC);
	if (Driver == nullptr)
	{
		return;
	}
	/*
	Driver->bOwnerNoSee = true;
	ViewActor = Driver;
	TmpCameraLocation = Driver.GetBoneCoords(CameraBone).Origin;
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(FRotator(16384 16384 0)), FowardLookQuat);
	if (PC.bTrackIREnabled)
	{
		PC.SetRotation(PC.Rotation + FRotator(-PC.fpTrackIRPitch - PC.fpTrackIRLastPitch, -PC.fpTrackIRYaw - PC.fpTrackIRLastYaw, 0));
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
	FQuat FowardLookQuat = FQuat(0,0,0,0);
	FQuat ControllerLookQuat = FQuat(0, 0, 0, 0);
	/*
	FowardLookQuat = QuatFromRotator(Driver.GetBoneRotation(CameraBone));
	FowardLookQuat = QuatProduct(QuatFromRotator(FRotator(16384 16384 0)), FowardLookQuat);
	ControllerLookQuat = QuatProduct(QuatFromRotator(CameraRotation), QuatInvert(FowardLookQuat));
	PC.SetRotation(QuatToRotator(ControllerLookQuat));
	*/
}

bool AHMMWV_Passenger::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	APlayerController* PC = nullptr;
	/*
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr || PC.ViewTarget != Self)
	{
		return false;
	}
	PC.bBehindView = false;
	Driver.Velocity = FVector(0,0,0);
	SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
	LastCameraCalcTime = GetWorld()->GetTimeSeconds();
	*/

	return true;
}
