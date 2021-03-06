// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M1114_HMMWV_DesertFactory/M1114_HMMWV_DesertFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1114_HMMWV/M1114_HMMWV_Desert/M1114_HMMWV_Desert.h"

AM1114_HMMWV_DesertFactory::AM1114_HMMWV_DesertFactory()
{
	VehicleClass = AM1114_HMMWV_Desert::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1114_HMMWV_Desert.M1114_HMMWV_Desert'"), NULL, LOAD_None, NULL);

}
