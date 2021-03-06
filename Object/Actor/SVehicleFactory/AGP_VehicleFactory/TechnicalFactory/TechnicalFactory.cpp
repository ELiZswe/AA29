// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/TechnicalFactory/TechnicalFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/Technical/Technical.h"

ATechnicalFactory::ATechnicalFactory()
{
	VehicleClass = ATechnical::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/Technical.Technical'"), NULL, LOAD_None, NULL);
}
