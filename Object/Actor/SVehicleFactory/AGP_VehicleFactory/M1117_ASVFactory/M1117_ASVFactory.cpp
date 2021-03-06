// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M1117_ASVFactory/M1117_ASVFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1117_ASV/M1117_ASV.h"

AM1117_ASVFactory::AM1117_ASVFactory()
{
	VehicleClass = AM1117_ASV::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1117_ASV.M1117_ASV'"), NULL, LOAD_None, NULL);
}
