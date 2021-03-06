// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/CROWS_HMMWVFactory/CROWS_HMMWVFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"

ACROWS_HMMWVFactory::ACROWS_HMMWVFactory()
{
	VehicleClass = ACROWS_HMMWV::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/HMMWV1114.HMMWV1114'"), NULL, LOAD_None, NULL);
}
