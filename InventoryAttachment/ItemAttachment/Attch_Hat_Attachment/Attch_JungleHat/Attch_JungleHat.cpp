// All the original content belonged to the US Army


#include "Attch_JungleHat.h"

AAttch_JungleHat::AAttch_JungleHat()
{
	ArcticStaticMesh    = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet.m-helmet"), NULL, LOAD_None, NULL);
	SFBoonieStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_boonie.m_hat_boonie"), NULL, LOAD_None, NULL);
	GuerrillaHelmetMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-USguerrilla_Helmet.m-USguerrilla_Helmet"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-jungle_hat.m-jungle_hat"), NULL, LOAD_None, NULL);
}