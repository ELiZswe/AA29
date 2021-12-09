// All the original content belonged to the US Army


#include "Attch_MedicRuck.h"

AAttch_MedicRuck::AAttch_MedicRuck()
{
	AttachBone          = "RuckSack";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-medicpack1a.m-medicpack1a"), NULL, LOAD_None, NULL);
}