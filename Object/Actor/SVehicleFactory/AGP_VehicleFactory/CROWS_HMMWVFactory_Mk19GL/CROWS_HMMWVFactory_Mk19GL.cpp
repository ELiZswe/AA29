// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/CROWS_HMMWVFactory_Mk19GL/CROWS_HMMWVFactory_Mk19GL.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_Mk19GL/CROWS_HMMWV_Mk19GL.h"

ACROWS_HMMWVFactory_Mk19GL::ACROWS_HMMWVFactory_Mk19GL()
{
	VehicleClass = ACROWS_HMMWV_Mk19GL::StaticClass();
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/HMMWV1114.HMMWV1114'"), NULL, LOAD_None, NULL);
}
