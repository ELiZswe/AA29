// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/CROWS_GunnerSeat/CROWS_GunnerSeat.h"

ACROWS_GunnerSeat::ACROWS_GunnerSeat()
{
	DriveAnim = "SF_Humvee_Passenger_Idle";
}

bool ACROWS_GunnerSeat::PlaceExitingDriver()
{
	/*
	local Object.Vector tryPlace;
	local Object.Vector Extent;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local Object.Vector ZOffset;
	Extent = Driver.Default.CollisionRadius * vect(1 1 0);
	Extent.Z = Driver.Default.CollisionHeight;
	ZOffset = Driver.Default.CollisionHeight * vect(0 0 0.5);
	tryPlace = VehicleBase.Location + VehicleBase.ExitPositions[3] >> VehicleBase.Rotation;
	if (VehicleBase.Trace(HitLocation, HitNormal, tryPlace, VehicleBase.Location + ZOffset, False, Extent) != None || !Driver.SetLocation(tryPlace))
	{
		Return PlaceExitingDriver();
	}
	*/
	return true;
}

void ACROWS_GunnerSeat::ToggleGunView()
{
	//VehicleBase.ServerChangePosition(True, Driver);
}

void ACROWS_GunnerSeat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (Driver != None && HumanController(Controller) != None)
	{
		if (bPower)
		{
			ToggleGunView();
		}
	}
	*/
}
