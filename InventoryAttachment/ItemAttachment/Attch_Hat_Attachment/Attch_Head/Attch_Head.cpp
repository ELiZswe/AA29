// All the original content belonged to the US Army


#include "Attch_Head.h"

AAttch_Head::AAttch_Head()
{
	SFBDUStaticMesh      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_bdu.m_hat_bdu"), NULL, LOAD_None, NULL);
	SFBoonieStaticMesh   = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_boonie.m_hat_boonie"), NULL, LOAD_None, NULL);
	SFStaticMesh         = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-helmet_sf.m-helmet_sf"), NULL, LOAD_None, NULL);
	MILESStaticMesh      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet_miles.m-helmet_miles"), NULL, LOAD_None, NULL);
	ScarfStaticMesh      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-scarfB.m-scarfB"), NULL, LOAD_None, NULL);
	CapStaticMesh        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-opfor_cap.m-opfor_cap"), NULL, LOAD_None, NULL);
	GuerrillaHelmetMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-USguerrilla_Helmet.m-USguerrilla_Helmet"), NULL, LOAD_None, NULL);
	ACUHelmet            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_michhelmet1a.m_atta_us-soldier_michhelmet1a"), NULL, LOAD_None, NULL);
	ArcticMichHelmet     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_michhelmet1b.m_atta_us-soldier_michhelmet1b"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh   = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet.m-helmet"), NULL, LOAD_None, NULL);
}