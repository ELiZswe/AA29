// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/VehicleWeaponFPOverlay/VehicleWeaponFPOverlay.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "Engine/Canvas.h"

AVehicleWeaponFPOverlay::AVehicleWeaponFPOverlay()
{
	WeaponFOV = 50;
	CameraOffset = FVector(-5, 0, 0);
	//bHidden = true;
	//RemoteRole = 0;
}

void AVehicleWeaponFPOverlay::RenderOverlays(UCanvas* C, bool bNoPurposeBool)
{
	FVector CamLoc = FVector(0,0,0);
	FRotator CamRot = FRotator(0,0,0);
	/*
	C.GetCameraLocation(CamLoc, CamRot);
	SetActorLocation(CamLoc + CameraOffset >> CamRot);
	SetActorRotation(CamRot);
	C.DrawActor(this, false, False, WeaponFOV);
	*/
}

void AVehicleWeaponFPOverlay::PostBeginPlay()
{
	Super::PostBeginPlay();
	//Log(Self + " spawned");
}
void AVehicleWeaponFPOverlay::Destroyed()
{
	Weapon = nullptr;
	//Log(Self + " destroyed");
	Super::Destroyed();
}
