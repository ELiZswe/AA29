// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/StrykerFactory/StrykerFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/stryker/stryker.h"

AStrykerFactory::AStrykerFactory()
{
	VehicleClass = Astryker::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/stryker.stryker'"), NULL, LOAD_None, NULL);
}
