// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/SFHumvee/SFHumveeLoaded/SFHumveeLoaded.h"

ASFHumveeLoaded::ASFHumveeLoaded()
{
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/humvee_loaded.humvee_loaded'"), NULL, LOAD_None, NULL);
}