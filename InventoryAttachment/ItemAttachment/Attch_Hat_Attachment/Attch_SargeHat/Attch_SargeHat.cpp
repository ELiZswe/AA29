// All the original content belonged to the US Army


#include "Attch_SargeHat.h"

AAttch_SargeHat::AAttch_SargeHat()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-drill/m-sarge_hat.m-sarge_hat"), NULL, LOAD_None, NULL);
}