// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/KVehicleFactory/KVehicleFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/KVehicle/KVehicle.h"

AKVehicleFactory::AKVehicleFactory()
{

}

void AKVehicleFactory::Trigger(AActor* Other, APawn* EventInstigator)
{
	AKVehicle* CreatedVehicle = nullptr;
	if (VehicleCount >= MaxVehicleCount)
	{
		return;
	}
	if (KVehicleClass != nullptr)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		CreatedVehicle = GetWorld()->SpawnActor<AKVehicle>(AKVehicle::StaticClass(), GetActorLocation(), GetActorRotation(), SpawnParams);
		if (CreatedVehicle != nullptr)
		{
			VehicleCount++;
			CreatedVehicle->ParentFactory = this;
		}
	}
}
