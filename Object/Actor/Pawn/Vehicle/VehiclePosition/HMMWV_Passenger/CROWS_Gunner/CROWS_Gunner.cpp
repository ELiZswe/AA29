// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"

ACROWS_Gunner::ACROWS_Gunner()
{
	GunCameraBone = "B_Weapon";
	//HudClass = class'AGP_Vehicles.CROWS_Hud';
	ZoomLevel0 = 85;
	ZoomLevel1 = 45;
	ZoomLevel2 = 22.5;
	ZoomLevel4 = 11.25;
	ZoomLevel8 = 5.625;
	ZoomLevel12 = 3.75;
	CurrentZoom = 80;
	LaserRechargeCallbackName = "LaserRechargingTimer";
	//ZoomSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_zoom';
	//StartUpSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_power_up';
	//LaseSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_lasing';
	//AnimManagerClass = class'AGP_Vehicles.HMMWVCrowsAnimManager';
	//SeatBeltOnMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_L_on';
	//SeatBeltOffMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_L_off';
	//GunClass = class'AGP_Vehicles.CROWS_Base';
	TPCamWorldOffset = FVector(0, 0, 5);
	DesiredTPCamDistance = 3;
	//bSpecialHUD = true;
}

void ACROWS_Gunner::SpecialCalcCROWSView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Coords CamBoneCoords;
	local Object.Vector X;
	local Object.Vector Y;
	local Object.Vector Z;
	GetAxes(PC.Rotation, X, Y, Z);
	CamBoneCoords = Gun.GetBoneCoords(CROWS_Base(Gun).CameraViewBone);
	CameraLocation = CamBoneCoords.Origin;
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	CameraRotation = CameraLocation - Gun.GetBoneCoords(CROWS_Base(Gun).CameraBaseBone).Origin;
	*/
}

bool ACROWS_Gunner::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC == None || PC.ViewTarget != Self)
	{
		return false;
	}
	PC.bBehindView = False;
	if (bFromBehind)
	{
		SpecialCalcBehindView(PC, ViewActor, CameraLocation, CameraRotation);
	}
	else
	{
		if (bInCROWS)
		{
			SpecialCalcCROWSView(PC, ViewActor, CameraLocation, CameraRotation);
		}
		else
		{
			SpecialCalcFirstPersonView(PC, ViewActor, CameraLocation, CameraRotation);
		}
	}
	LastCameraCalcTime = Level.TimeSeconds;
	*/
	return true;
}

void ACROWS_Gunner::AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone)
{
	/*
	AttachToVehicle(VehiclePawn, WeaponBone);
	if (Level.NetMode != 3)
	{
		if (Gun != None)
		{
			VehicleBase.AttachToBone(Gun, WeaponBone);
			Gun.SetBase(VehicleBase);
		}
	}
	*/
}

void ACROWS_Gunner::SpecialCalcBehindView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Vector CamLookAt;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local Object.Vector OffsetVector;
	local Actor HitActor;
	local Object.Vector X;
	local Object.Vector Y;
	local Object.Vector Z;
	if (Driver != None && bDrawDriverInTP)
	{
		Driver.bOwnerNoSee = False;
	}
	if (DesiredTPCamDistance < TPCamDistance)
	{
		TPCamDistance = FMax(DesiredTPCamDistance, TPCamDistance - CameraSpeed * Level.TimeSeconds - LastCameraCalcTime);
	}
	else
	{
		if (DesiredTPCamDistance > TPCamDistance)
		{
			TPCamDistance = FMin(DesiredTPCamDistance, TPCamDistance + CameraSpeed * Level.TimeSeconds - LastCameraCalcTime);
		}
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = Self;
	CamLookAt = GetCameraLocationStart() + TPCamLookat >> Rotation + TPCamWorldOffset;
	OffsetVector = vect(0 0 0);
	OffsetVector.X = -1 * TPCamDistance;
	CameraLocation = CamLookAt + OffsetVector >> PC.Rotation;
	HitActor = Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, True, vect(40 40 40));
	if (HitActor != None && HitActor.bWorldGeometry || HitActor == GetVehicleBase() || Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, False, vect(40 40 40)) != None)
	{
		CameraLocation = HitLocation;
	}
	CameraRotation = Normalize(PC.Rotation + PC.ShakeRot);
	*/
}

bool ACROWS_Gunner::Using(AActor* Other)
{
	/*
	if (HMMWVAnimManager(AnimManager) != None && HMMWVAnimManager(AnimManager).bBusyAnimating)
	{
		return false;
	}
	if (bInCROWS)
	{
		ServerActivateCrows();
		return true;
	}
	*/
	return false;
}

void ACROWS_Gunner::ActivateCrows()
{
	ServerActivateCrows();
}

void ACROWS_Gunner::ServerActivateCrows()
{
	/*
	bInCROWS = !bInCROWS;
	CROWS_Base(Gun).bActive = bInCROWS;
	if (bInCROWS)
	{
		BeginCrows();
	}
	else
	{
		FinishCrows();
	}
	*/
}

void ACROWS_Gunner::ChargeWeapon()
{
	/*
	CROWS_Base(Gun).ChargeWeapon();
	CROWS_Base(Gun).PlayingServoLR = None;
	CROWS_Base(Gun).PlayingServoUD = None;
	CROWS_Base(Gun).MinSustain = CROWS_Base(Gun).Default.MinSustain;
	*/
}

void ACROWS_Gunner::ClientBeginCrows()
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	CROWS_Base(Gun).HideGun(True);
	PC.DoFade(True, True, GetSoundDuration(StartUpSound));
	if (PC != None)
	{
		PC.myHUD.bHideHUD = true;
		if (myHUD == None)
		{
			myHUD = Spawn(HudClass);
			myHUD.PlayerOwner = PC;
		}
		PCHUD = PC.myHUD;
		PC.myHUD = myHUD;
		myHUD.AmmoType = CROWS_Base(Gun).Default.AmmoType;
		myHUD.AmmoIconTexture = CROWS_Base(Gun).Default.HUDAmmoIcon;
		myHUD.MaxAmmo = CROWS_Base(Gun).Default.Ammo;
	}
	CurrentZoom = ZoomLevel1;
	ValidateView();
	*/
}

void ACROWS_Gunner::ClientFinishCrows()
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (PC != None)
	{
		PC.myHUD = PCHUD;
		PC.myHUD.bHideHUD = False;
	}
	CROWS_Base(Gun).bCharged = False;
	CurrentZoom = PC.DefaultFOV;
	ValidateView();
	CROWS_Base(Gun).HideGun(False);
	*/
}

void ACROWS_Gunner::BeginCrows()
{
	/*
	local PlayerController PC;
	local float StartUpSoundDuration;
	ClientBeginCrows();
	PC = PlayerController(Controller);
	PC.SetRotation(Gun.Rotation);
	StartUpSoundDuration = GetSoundDuration(StartUpSound);
	PlaySound(StartUpSound, , 2, , 64);
	if (HMMWVAnimManager(AnimManager) != None)
	{
		HMMWVAnimManager(AnimManager).PlayActionAnim();
	}
	SetCustomTimer(StartUpSoundDuration, False, 'ChargeWeapon');
	CROWS_Base(Gun).PlayingServoLR = CROWS_Base(Gun).ServoSusLR;
	CROWS_Base(Gun).PlayingServoUD = CROWS_Base(Gun).ServoSusUD;
	CROWS_Base(Gun).MinSustain = 5;
	SetCustomTimer(2, False, LaserRechargeCallbackName);
	*/
}

void ACROWS_Gunner::FinishCrows()
{
	/*
	local PlayerController PC;
	PC = PlayerController(Controller);
	if (HMMWVAnimManager(AnimManager) != None)
	{
		HMMWVAnimManager(AnimManager).PlayIdleAnim();
	}
	ClientFinishCrows();
	CurrentZoom = PC.DefaultFOV;
	ValidateView();
	*/
}

void ACROWS_Gunner::UnPossessed()
{
	/*
	if (bInCROWS)
	{
		ActivateCrows();
	}
	UnPossessed();
	*/
}

void ACROWS_Gunner::ValidateView()
{
	/*
	if (PlayerController(Controller) != None)
	{
		PlayerController(Controller).SetFOV(CurrentZoom);
	}
	if (myHUD != None)
	{
		myHUD.SetFOV(CurrentZoom);
	}
	*/
}

void ACROWS_Gunner::DrawHUD(UCanvas* C)
{
	//myHUD.DrawHUD(C);
}

void ACROWS_Gunner::ZoomIn()
{
	/*
	if (!bInCROWS)
	{
		Return;
	}
	if (CurrentZoom != ZoomLevel12)
	{
		PlaySound(ZoomSound, , 1);
	}
	if (CurrentZoom == ZoomLevel1)
	{
		CurrentZoom = ZoomLevel2;
	}
	else
	{
		if (CurrentZoom == ZoomLevel2)
		{
			CurrentZoom = ZoomLevel4;
		}
		else
		{
			if (CurrentZoom == ZoomLevel4)
			{
				CurrentZoom = ZoomLevel8;
			}
			else
			{
				if (CurrentZoom == ZoomLevel8)
				{
					CurrentZoom = ZoomLevel12;
				}
			}
		}
	}
	ValidateView();
	*/
}

void ACROWS_Gunner::ZoomOut()
{
	/*
	if (!bInCROWS)
	{
		Return;
	}
	if (CurrentZoom != ZoomLevel1)
	{
		PlaySound(ZoomSound, , 1);
	}
	if (CurrentZoom == ZoomLevel12)
	{
		CurrentZoom = ZoomLevel8;
	}
	else
	{
		if (CurrentZoom == ZoomLevel8)
		{
			CurrentZoom = ZoomLevel4;
		}
		else
		{
			if (CurrentZoom == ZoomLevel4)
			{
				CurrentZoom = ZoomLevel2;
			}
			else
			{
				if (CurrentZoom == ZoomLevel2)
				{
					CurrentZoom = ZoomLevel1;
				}
			}
		}
	}
	ValidateView();
	*/
}

void ACROWS_Gunner::CROWSZeroRange()
{
	/*
	if (!bInCROWS)
	{
		Return;
	}
	if (CurrentZoom != ZoomLevel1)
	{
		PlaySound(ZoomSound, , 1);
		CurrentZoom = ZoomLevel1;
	}
	LaseDistance = 0;
	myHUD.SetLaseDistance(LaseDistance);
	CROWS_Base(Gun).SetLaseDistance(LaseDistance);
	ValidateView();
	*/
}

void ACROWS_Gunner::DoLase()
{
	/*
	local Object.Vector StartTrace;
	local Object.Vector EndTrace;
	local Object.Vector X;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local Object.Vector diff;
	local Actor HitActor;
	local Material HitMaterial;
	local Actor.BoneInfo HitBone;
	local Object.Coords CamBoneCoords;
	local Object.Vector CameraLocation;
	local Object.Rotator CameraRotation;
	if (!bInCROWS)
	{
		Return;
	}
	if (!bLaserRecharging && !myHUD.bIsLasing)
	{
		Gun.CalcWeaponFire();
		CamBoneCoords = Gun.GetBoneCoords(CROWS_Base(Gun).CameraViewBone);
		CameraLocation = CamBoneCoords.Origin;
		CameraRotation = QuatToRotator(QuatProduct(QuatFromRotator(rot(32768 16384 - 16384)), QuatFromRotator(Gun.GetBoneRotation(CROWS_Base(Gun).CameraViewBone))));
		StartTrace = CameraLocation;
		X = Vector(CameraRotation);
		LaseDistance = 160000;
		EndTrace = StartTrace + LaseDistance * X;
		bBlockZeroExtentTraces = False;
		bUseCollisionStaticMesh = true;
		HitActor = BoneTrace(HitLocation, HitNormal, EndTrace, StartTrace, HitMaterial, HitBone, True);
		bUseCollisionStaticMesh = False;
		bBlockZeroExtentTraces = true;
		diff = HitLocation - StartTrace;
		LaseDistance = VSize(diff);
		myHUD.bIsLasing = true;
		SetCustomTimer(1, False, 'LaseCallback');
		PlaySound(LaseSound, 0, 1);
	}
	*/
}

void ACROWS_Gunner::LaseCallback()
{
	/*
	myHUD.SetLaseDistance(LaseDistance / 52.5);
	CROWS_Base(Gun).SetLaseDistance(LaseDistance);
	myHUD.bIsLasing = False;
	myHUD.DrawLased();
	bLaserRecharging = true;
	myHUD.bPlayProgressBar = true;
	SetCustomTimer(2, False, LaserRechargeCallbackName);
	*/
}

void ACROWS_Gunner::LaserRechargingTimer()
{
	bLaserRecharging = false;
}

void ACROWS_Gunner::Tick(float DeltaTime)
{
	/*
	local Object.Rotator GunRotation;
	if (Role < 4 || Level.NetMode == 0)
	{
		GunRotation = CROWS_Base(Gun).Instigator.Rotation;
		GunRotation.Yaw = GunRotation.Yaw - VehicleBase.Rotation.Yaw;
		CROWS_Base(Gun).Instigator.SetRotation(GunRotation);
	}
	*/
	Super::Tick(DeltaTime);
}

void ACROWS_Gunner::AltFire(float F)
{
	DoLase();
}
