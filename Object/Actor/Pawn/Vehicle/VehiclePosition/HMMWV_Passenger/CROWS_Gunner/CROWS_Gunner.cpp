// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/CROWS_Hud/CROWS_Hud.h"
#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVCrowsAnimManager/HMMWVCrowsAnimManager.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/AnimManager/HMMWVAnimManager/HMMWVAnimManager.h"

ACROWS_Gunner::ACROWS_Gunner()
{
	GunCameraBone = "B_Weapon";
	//HudClass = ACROWS_Hud::StaticClass();
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
	//AnimManagerClass = AHMMWVCrowsAnimManager::StaticClass();
	//SeatBeltOnMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_L_on';
	//SeatBeltOffMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Seatbelt_L_off';
	//GunClass = ACROWS_Base::StaticClass();
	TPCamWorldOffset = FVector(0, 0, 5);
	DesiredTPCamDistance = 3;
	//bSpecialHUD = true;
}

void ACROWS_Gunner::SpecialCalcCROWSView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FCoords CamBoneCoords = FCoords({});
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	GetAxes(PC.Rotation, X, Y, Z);
	CamBoneCoords = Gun.GetBoneCoords(Cast<ACROWS_Base>(Gun).CameraViewBone);
	CameraLocation = CamBoneCoords.Origin;
	CameraLocation = CameraLocation + PC.ShakeOffset.X * X + PC.ShakeOffset.Y * Y + PC.ShakeOffset.Z * Z;
	CameraRotation = CameraLocation - Gun.GetBoneCoords(Cast<ACROWS_Base>(Gun).CameraBaseBone).Origin;
	*/
}

bool ACROWS_Gunner::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr || PC.ViewTarget != Self)
	{
		return false;
	}
	PC.bBehindView = false;
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
	LastCameraCalcTime = GetWorld()->GetTimeSeconds();
	*/
	return true;
}

void ACROWS_Gunner::AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone)
{
	Super::AttachToVehicle(VehiclePawn, WeaponBone);
	if (GetNetMode() != ENetMode::NM_Client)
	{
		if (Gun != nullptr)
		{
			//VehicleBase->AttachToBone(Gun, WeaponBone);
			//Gun->SetBase(VehicleBase);
		}
	}
}

void ACROWS_Gunner::SpecialCalcBehindView(APlayerController* PC, AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FVector CamLookAt = FVector(0,0,0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector OffsetVector = FVector(0, 0, 0);
	AActor* HitActor = nullptr;
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	if (Driver != nullptr && bDrawDriverInTP)
	{
		Driver.bOwnerNoSee = false;
	}
	if (DesiredTPCamDistance < TPCamDistance)
	{
		TPCamDistance = FMax(DesiredTPCamDistance, TPCamDistance - CameraSpeed * GetWorld()->GetTimeSeconds() - LastCameraCalcTime);
	}
	else
	{
		if (DesiredTPCamDistance > TPCamDistance)
		{
			TPCamDistance = FMin(DesiredTPCamDistance, TPCamDistance + CameraSpeed * GetWorld()->GetTimeSeconds() - LastCameraCalcTime);
		}
	}
	GetAxes(PC.Rotation, X, Y, Z);
	ViewActor = this;
	CamLookAt = GetCameraLocationStart() + TPCamLookat >> Rotation + TPCamWorldOffset;
	OffsetVector = FVector(0,0,0);
	OffsetVector.X = -1 * TPCamDistance;
	CameraLocation = CamLookAt + OffsetVector >> PC.Rotation;
	HitActor = Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, true, FVector(40 40 40));
	if (HitActor != nullptr && HitActor.bWorldGeometry || HitActor == GetVehicleBase() || Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, false, FVector(40 40 40)) != nullptr)
	{
		CameraLocation = HitLocation;
	}
	CameraRotation = Normalize(PC.Rotation + PC.ShakeRot);
	*/
}

bool ACROWS_Gunner::Using(AActor* Other)
{
	/*
	if (Cast<AHMMWVAnimManager>(AnimManager) != nullptr && HMMWVAnimManager(AnimManager).bBusyAnimating)
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
	bInCROWS = !bInCROWS;
	Cast<ACROWS_Base>(Gun)->bActive = bInCROWS;
	if (bInCROWS)
	{
		BeginCrows();
	}
	else
	{
		FinishCrows();
	}
}

void ACROWS_Gunner::ChargeWeapon()
{
	Cast<ACROWS_Base>(Gun)->ChargeWeapon();
	Cast<ACROWS_Base>(Gun)->PlayingServoLR = nullptr;
	Cast<ACROWS_Base>(Gun)->PlayingServoUD = nullptr;
	//Cast<ACROWS_Base>(Gun)->MinSustain = Cast<ACROWS_Base>(Gun)->Default->MinSustain;
}

void ACROWS_Gunner::ClientBeginCrows()
{
	APlayerController* PC = nullptr;
	/*
	PC = Cast<APlayerController>(Controller);
	Cast<ACROWS_Base>(Gun)->HideGun(true);
	PC.DoFade(true, true, GetSoundDuration(StartUpSound));
	if (PC != nullptr)
	{
		PC.myHUD.bHideHUD = true;
		if (myHUD == nullptr)
		{
			myHUD = Spawn(HudClass);
			myHUD.PlayerOwner = PC;
		}
		PCHUD = PC.myHUD;
		PC.myHUD = myHUD;
		myHUD.AmmoType = Cast<ACROWS_Base>(Gun)->Default.AmmoType;
		myHUD.AmmoIconTexture = Cast<ACROWS_Base>(Gun)->Default.HUDAmmoIcon;
		myHUD.MaxAmmo = Cast<ACROWS_Base>(Gun)->Default.Ammo;
	}
	CurrentZoom = ZoomLevel1;
	ValidateView();
	*/
}

void ACROWS_Gunner::ClientFinishCrows()
{
	APlayerController* PC = nullptr;
	/*
	PC = Cast<APlayerController>(Controller);
	if (PC != nullptr)
	{
		PC.myHUD = PCHUD;
		PC.myHUD.bHideHUD = false;
	}
	Cast<ACROWS_Base>(Gun)->bCharged = false;
	CurrentZoom = PC.DefaultFOV;
	ValidateView();
	Cast<ACROWS_Base>(Gun)->HideGun(false);
	*/
}

void ACROWS_Gunner::BeginCrows()
{
	APlayerController* PC = nullptr;
	float StartUpSoundDuration = 0;
	ClientBeginCrows();
	/*
	PC = Cast<APlayerController>(Controller);
	PC.SetRotation(Gun.Rotation);
	StartUpSoundDuration = GetSoundDuration(StartUpSound);
	PlaySound(StartUpSound, , 2, , 64);
	if (Cast<AHMMWVAnimManager>(AnimManager) != nullptr)
	{
		HMMWVAnimManager(AnimManager).PlayActionAnim();
	}
	SetCustomTimer(StartUpSoundDuration, false, 'ChargeWeapon');
	Cast<ACROWS_Base>(Gun)->PlayingServoLR = Cast<ACROWS_Base>(Gun)->ServoSusLR;
	Cast<ACROWS_Base>(Gun)->PlayingServoUD = Cast<ACROWS_Base>(Gun)->ServoSusUD;
	Cast<ACROWS_Base>(Gun)->MinSustain = 5;
	SetCustomTimer(2, false, LaserRechargeCallbackName);
	*/
}

void ACROWS_Gunner::FinishCrows()
{
	APlayerController* PC = nullptr;
	/*
	PC = Cast<APlayerController>(Controller);
	if (Cast<AHMMWVAnimManager>(AnimManager) != nullptr)
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
	if (bInCROWS)
	{
		ActivateCrows();
	}
	Super::UnPossessed();
}

void ACROWS_Gunner::ValidateView()
{
	/*
	if (Cast<APlayerController>(Controller) != nullptr)
	{
		Cast<APlayerController>(Controller).SetFOV(CurrentZoom);
	}
	if (myHUD != nullptr)
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
	if (!bInCROWS)
	{
		return;
	}
	if (CurrentZoom != ZoomLevel12)
	{
		//PlaySound(ZoomSound, , 1);
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
}

void ACROWS_Gunner::ZoomOut()
{
	if (!bInCROWS)
	{
		return;
	}
	if (CurrentZoom != ZoomLevel1)
	{
		//PlaySound(ZoomSound, , 1);
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
}

void ACROWS_Gunner::CROWSZeroRange()
{
	if (!bInCROWS)
	{
		return;
	}
	if (CurrentZoom != ZoomLevel1)
	{
		//PlaySound(ZoomSound, , 1);
		CurrentZoom = ZoomLevel1;
	}
	LaseDistance = 0;
	myHUD->SetLaseDistance(LaseDistance);
	Cast<ACROWS_Base>(Gun)->SetLaseDistance(LaseDistance);
	ValidateView();
}

void ACROWS_Gunner::DoLase()
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector diff = FVector(0, 0, 0);
	AActor* HitActor = nullptr;
	UMaterialInstance* HitMaterial = nullptr;
	FBoneInfo HitBone = FBoneInfo({});
	FCoords CamBoneCoords = FCoords({});
	FVector CameraLocation = FVector(0,0,0);
	FRotator CameraRotation = FRotator(0,0,0);
	if (!bInCROWS)
	{
		return;
	}
	/*
	if (!bLaserRecharging && !myHUD.bIsLasing)
	{
		Gun.CalcWeaponFire();
		CamBoneCoords = Gun.GetBoneCoords(Cast<ACROWS_Base>(Gun).CameraViewBone);
		CameraLocation = CamBoneCoords.Origin;
		CameraRotation = QuatToRotator(QuatProduct(QuatFromRotator(FRotator(32768 16384 - 16384)), QuatFromRotator(Gun.GetBoneRotation(Cast<ACROWS_Base>(Gun).CameraViewBone))));
		StartTrace = CameraLocation;
		X = Vector(CameraRotation);
		LaseDistance = 160000;
		EndTrace = StartTrace + LaseDistance * X;
		bBlockZeroExtentTraces = false;
		bUseCollisionStaticMesh = true;
		HitActor = BoneTrace(HitLocation, HitNormal, EndTrace, StartTrace, HitMaterial, HitBone, true);
		bUseCollisionStaticMesh = false;
		bBlockZeroExtentTraces = true;
		diff = HitLocation - StartTrace;
		LaseDistance = VSize(diff);
		myHUD.bIsLasing = true;
		SetCustomTimer(1, false, 'LaseCallback');
		PlaySound(LaseSound, 0, 1);
	}
	*/
}

void ACROWS_Gunner::LaseCallback()
{
	/*
	myHUD.SetLaseDistance(LaseDistance / 52.5);
	Cast<ACROWS_Base>(Gun)->SetLaseDistance(LaseDistance);
	myHUD.bIsLasing = false;
	myHUD.DrawLased();
	bLaserRecharging = true;
	myHUD.bPlayProgressBar = true;
	SetCustomTimer(2, false, LaserRechargeCallbackName);
	*/
}

void ACROWS_Gunner::LaserRechargingTimer()
{
	bLaserRecharging = false;
}

void ACROWS_Gunner::Tick(float DeltaTime)
{
	FRotator GunRotation = FRotator(0,0,0);
	/*
	if (Role < 4 || GetWorld()->GetNetMode() == 0)
	{
		GunRotation = Cast<ACROWS_Base>(Gun)->Instigator.Rotation;
		GunRotation.Yaw = GunRotation.Yaw - VehicleBase.Rotation.Yaw;
		Cast<ACROWS_Base>(Gun)->Instigator.SetRotation(GunRotation);
	}
	*/
	Super::Tick(DeltaTime);
}

void ACROWS_Gunner::AltFire(float F)
{
	DoLase();
}
