// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/VehicleWeaponFPOverlay/VehicleWeaponFPOverlay.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"

AVehicleWeaponFPOverlay::AVehicleWeaponFPOverlay()
{
	WeaponFOV = 50;
	CameraOffset = FVector(-5, 0, 0);
	//bHidden = true;
	//RemoteRole = 0;
}

void AVehicleWeaponFPOverlay::RenderOverlays(UCanvas* C, bool bNoPurposeBool)
{
	/*
	local Object.Vector CamLoc;
	local Object.Rotator CamRot;
	C.GetCameraLocation(CamLoc, CamRot);
	SetLocation(CamLoc + CameraOffset >> CamRot);
	SetRotation(CamRot);
	C.DrawActor(Self, False, False, WeaponFOV);
	*/
}

void AVehicleWeaponFPOverlay::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	Log(Self $ " spawned");
	*/
}
void AVehicleWeaponFPOverlay::Destroyed()
{
	/*
	Weapon = nullptr;
	Log(Self $ " destroyed");
	Destroyed();
	*/
}
