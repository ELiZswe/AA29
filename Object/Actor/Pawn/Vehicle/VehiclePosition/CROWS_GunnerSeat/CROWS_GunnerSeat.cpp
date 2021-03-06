// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/CROWS_GunnerSeat/CROWS_GunnerSeat.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"

ACROWS_GunnerSeat::ACROWS_GunnerSeat()
{
	DriveAnim = "SF_Humvee_Passenger_Idle";
}

bool ACROWS_GunnerSeat::PlaceExitingDriver()
{
	FVector tryPlace = FVector(0, 0, 0);
	FVector Extent = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ZOffset = FVector(0, 0, 0);
	/*
	Extent = Driver.Default.CollisionRadius * FVector(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * FVector(0 0 0.5);
	tryPlace = VehicleBase.Location + VehicleBase.ExitPositions[3] >> VehicleBase.Rotation;
	if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, false, Extent) != nullptr || !Driver.SetLocation(tryPlace))
	{
		return PlaceExitingDriver();
	}
	*/
	return true;
}

void ACROWS_GunnerSeat::ToggleGunView()
{
	VehicleBase->ServerChangePosition(true, Driver);
}

void ACROWS_GunnerSeat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Driver != nullptr && Cast<AHumanController>(Controller) != nullptr)
	{
		if (bPower)
		{
			ToggleGunView();
		}
	}
}
