// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/CROWS_HMMWVFactory_50Cal/CROWS_HMMWVFactory_50Cal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_50Cal/CROWS_HMMWV_50Cal.h"

ACROWS_HMMWVFactory_50Cal::ACROWS_HMMWVFactory_50Cal()
{
	VehicleClass = ACROWS_HMMWV_50Cal::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/HMMWV1114.HMMWV1114'"), NULL, LOAD_None, NULL);
}
