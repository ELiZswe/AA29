// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/ChevySuburbanFactory/ChevySuburbanFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/ChevySuburban/ChevySuburban.h"

AChevySuburbanFactory::AChevySuburbanFactory()
{
	VehicleClass = AChevySuburban::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/suburban.suburban'"), NULL, LOAD_None, NULL);
}
