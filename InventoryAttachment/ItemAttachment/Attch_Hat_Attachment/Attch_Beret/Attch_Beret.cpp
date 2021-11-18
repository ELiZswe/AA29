// All the original content belonged to the US Army


#include "Attch_Beret.h"

AAttch_Beret::AAttch_Beret()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-Beret.m-Beret"), NULL, LOAD_None, NULL);
}