// All the original content belonged to the US Army


#include "Attch_Green_Beret.h"

AAttch_Green_Beret::AAttch_Green_Beret()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-green_beret.m-green_beret"), NULL, LOAD_None, NULL);
}