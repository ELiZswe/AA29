// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M1083_FMTVFactory/M1083_FMTVFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M1083_FMTV/M1083_FMTV.h"

AM1083_FMTVFactory::AM1083_FMTVFactory()
{
	VehicleClass = AM1083_FMTV::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1083_MTV.M1083_MTV'"), NULL, LOAD_None, NULL);
}
