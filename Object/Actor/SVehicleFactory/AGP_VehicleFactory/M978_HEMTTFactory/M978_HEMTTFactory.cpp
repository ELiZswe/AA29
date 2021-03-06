// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/M978_HEMTTFactory/M978_HEMTTFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/M978_HEMTT/M978_HEMTT.h"

AM978_HEMTTFactory::AM978_HEMTTFactory()
{
	VehicleClass = AM978_HEMTT::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M978_Fuel_HEMTT.M978_Fuel_HEMTT'"), NULL, LOAD_None, NULL);
}
