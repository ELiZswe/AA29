// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M985_HEMTTFactory/M985_HEMTTFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M985_HEMTT/M985_HEMTT.h"

AM985_HEMTTFactory::AM985_HEMTTFactory()
{
	VehicleClass = AM985_HEMTT::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M985_Cargo_HEMTT.M985_Cargo_HEMTT'"), NULL, LOAD_None, NULL);

}
