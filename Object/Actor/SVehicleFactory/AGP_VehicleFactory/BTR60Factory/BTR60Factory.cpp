// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/BTR60Factory/BTR60Factory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR60P/BTR60P.h"

ABTR60Factory::ABTR60Factory()
{
	VehicleClass = ABTR60P::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/btr60.btr60'"), NULL, LOAD_None, NULL);
}
