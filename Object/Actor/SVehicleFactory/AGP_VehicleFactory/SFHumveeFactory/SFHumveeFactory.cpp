// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/SFHumveeFactory/SFHumveeFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/SFHumvee/SFHumvee.h"

ASFHumveeFactory::ASFHumveeFactory()
{
	VehicleClass = ASFHumvee::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/SFHumvee.SFHumvee'"), NULL, LOAD_None, NULL);
}
