// All the original content belonged to the US Army

#include "Attch_FlightCrewPara.h"

AAttch_FlightCrewPara::AAttch_FlightCrewPara()
{
	AttachBone = "RuckSack";
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_parachute.m_flightcrew_parachute'"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m_flightcrew_parachute.m_flightcrew_parachute'"), NULL, LOAD_None, NULL);
}

FName AAttch_FlightCrewPara::GetAttachBoneFor(AInventory* Inv)
{
	return "RuckSack";
}
