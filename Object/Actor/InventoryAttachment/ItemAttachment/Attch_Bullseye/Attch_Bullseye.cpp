// All the original content belonged to the US Army


#include "Attch_Bullseye.h"

AAttch_Bullseye::AAttch_Bullseye()
{
	AttachBone            = "RuckSack";
	//DisableOtherAttachment = { Attch_MedicRuck,Attch_RPGBackpack, Attch_FlightCrewPara };
	EnemyStaticMesh       = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh    = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target"), NULL, LOAD_None, NULL);
	EnemyAttachmentClass  = AAttch_Bullseye::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target"), NULL, LOAD_None, NULL);
}