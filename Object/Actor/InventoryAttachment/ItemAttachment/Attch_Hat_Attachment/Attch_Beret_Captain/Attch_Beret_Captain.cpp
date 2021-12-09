// All the original content belonged to the US Army


#include "Attch_Beret_Captain.h"

AAttch_Beret_Captain::AAttch_Beret_Captain()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-green_beret_captain.m-green_beret_captain"), NULL, LOAD_None, NULL);
}