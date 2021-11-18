// All the original content belonged to the US Army


#include "Attch_Eyes.h"

AAttch_Eyes::AAttch_Eyes()
{
	ACUGogglesUp       = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1up.m_atta_us-soldier_goggles_ess1up"), NULL, LOAD_None, NULL);
	ACUGogglesDown     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1down.m_atta_us-soldier_goggles_ess1down"), NULL, LOAD_None, NULL);
	GogglesDown        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-goggles_down.m-goggles_down"), NULL, LOAD_None, NULL);
	GogglesUp          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-goggles_up.m-goggles_up"), NULL, LOAD_None, NULL);
	OakleysBlue        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_blue.m-oakleys_blue"), NULL, LOAD_None, NULL);
	OakleysGreen       = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_green.m-oakleys_green"), NULL, LOAD_None, NULL);
	OakleysGrey        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_grey.m-oakleys_grey"), NULL, LOAD_None, NULL);
	OakleysRed         = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_red.m-oakleys_red"), NULL, LOAD_None, NULL);
	SFGogglesDown      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1down.m_atta_us-soldier_goggles_ess1down"), NULL, LOAD_None, NULL);
	SFGogglesUpBDU     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1up.m_atta_us-soldier_goggles_ess1up"), NULL, LOAD_None, NULL);
	SFGogglesUpCap     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us_soldier_goggles_ess1_cap_up.m_atta_us_soldier_goggles_ess1_cap_up"), NULL, LOAD_None, NULL);
	SFGogglesUpBoonie  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us_soldier_goggles_ess1_boonie_up.m_atta_us_soldier_goggles_ess1_boonie_up"), NULL, LOAD_None, NULL);
	AttachBone         = "BN_HeadEnd";
}