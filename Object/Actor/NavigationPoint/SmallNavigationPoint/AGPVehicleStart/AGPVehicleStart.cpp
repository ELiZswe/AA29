// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/AGPVehicleStart/AGPVehicleStart.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AAGPVehicleStart::AAGPVehicleStart()
{
	VehicleNumber = -1;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagVehicle.S_PSTagVehicle'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
}

void AAGPVehicleStart::Reset()
{
	Super::Reset();
	bEnabled = false;
}

void AAGPVehicleStart::CreateVehicle()
{
	AVehicle* vNewVehicle = nullptr;
	/*
	vNewVehicle = Spawn(VehicleSpawnClass, , , Location, Rotation);
	vNewVehicle.Tag = Tag;
	vNewVehicle.VehicleNumber = VehicleNumber;
	if (vNewVehicle.VehicleReplicationInfo != nullptr)
	{
		vNewVehicle.VehicleReplicationInfo.SetVehicleNumber(VehicleNumber);
	}
	*/
}
