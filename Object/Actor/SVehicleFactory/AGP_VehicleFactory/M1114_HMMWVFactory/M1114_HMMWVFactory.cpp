// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M1114_HMMWVFactory/M1114_HMMWVFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV.h"

AM1114_HMMWVFactory::AM1114_HMMWVFactory()
{
	VehicleClass = AM1114_HMMWV::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1114_HMMWV.M1114_HMMWV'"), NULL, LOAD_None, NULL);
}
